#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_GlobalFunction.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_GlobalFunction.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_GlobalFunction);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetNoOfDigit);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_UlongToU16String);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_true);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_false);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZoneOffset_SUCESS);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetTimezoneOfCurrentCountry_SWITCH_CASE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetSubtAndAudioByCountry_SWITCH_CASE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZoneBySITimeZone_SWITCH_CASE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetSICountry_SWITCH_CASE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_HexUlongToU8String_WHILE_TEST);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_HexUlongToU16String_WHILE_TEST);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_UlongToU8String_WHILE_TEST);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_U8StringToU16String_COPY_TEST);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_U8StringToUlong_LEN_IS_2);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_U8StringToUlong_LEN_IS_1);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_IF);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_ELSEIF1);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_ELSEIF2);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_RETURN);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_TRUE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_FALSE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_IF);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_ELSE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek_IF);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek__NOT_LEAPYERA);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetNoOfHexDigit_WHILE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetClockTimezoneByTimezone);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetMenuLanguage);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetMenuLanguage_DTG);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZone_DTG);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetTimeZone_IF1);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetTimeZone_ELSEIF);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetSICountry_SWITCH_CASE);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_UTC2Seconds);
CPPTEST_TEST(TestSuite_MApp_GlobalFunction_test_MApp_SetSILanguage_TEST_SWITCH);
CPPTEST_TEST_SUITE_END();


void TestSuite_MApp_GlobalFunction_test_MApp_GetNoOfDigit();
void TestSuite_MApp_GlobalFunction_test_MApp_UlongToU16String();
void TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_true();
void TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_false();
void TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZoneOffset_SUCESS();
void TestSuite_MApp_GlobalFunction_test_MApp_SetTimezoneOfCurrentCountry_SWITCH_CASE();
void TestSuite_MApp_GlobalFunction_test_MApp_SetSubtAndAudioByCountry_SWITCH_CASE();
void TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZoneBySITimeZone_SWITCH_CASE();
void TestSuite_MApp_GlobalFunction_test_MApp_GetSICountry_SWITCH_CASE();
void TestSuite_MApp_GlobalFunction_test_MApp_HexUlongToU8String_WHILE_TEST();
void TestSuite_MApp_GlobalFunction_test_MApp_HexUlongToU16String_WHILE_TEST();
void TestSuite_MApp_GlobalFunction_test_MApp_UlongToU8String_WHILE_TEST();
void TestSuite_MApp_GlobalFunction_test_MApp_U8StringToU16String_COPY_TEST();
void TestSuite_MApp_GlobalFunction_test_MApp_U8StringToUlong_LEN_IS_2();
void TestSuite_MApp_GlobalFunction_test_MApp_U8StringToUlong_LEN_IS_1();
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_IF();
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_ELSEIF1();
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_ELSEIF2();
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_RETURN();
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_TRUE();
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_FALSE();
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_IF();
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_ELSE();
void TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek_IF();
void TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek__NOT_LEAPYERA();
void TestSuite_MApp_GlobalFunction_test_MApp_GetNoOfHexDigit_WHILE();
void TestSuite_MApp_GlobalFunction_test_MApp_SetClockTimezoneByTimezone();
void TestSuite_MApp_GlobalFunction_test_MApp_GetMenuLanguage();
void TestSuite_MApp_GlobalFunction_test_MApp_GetMenuLanguage_DTG();
void TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZone_DTG();
void TestSuite_MApp_GlobalFunction_test_MApp_SetTimeZone_IF1();
void TestSuite_MApp_GlobalFunction_test_MApp_SetTimeZone_ELSEIF();
void TestSuite_MApp_GlobalFunction_test_MApp_SetSICountry_SWITCH_CASE();
void TestSuite_MApp_GlobalFunction_test_MApp_UTC2Seconds();
void TestSuite_MApp_GlobalFunction_test_MApp_SetSILanguage_TEST_SWITCH();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_GlobalFunction);

void TestSuite_MApp_GlobalFunction_setUp()
{
}

void TestSuite_MApp_GlobalFunction_tearDown()
{
}

#include "msAPI_Global.h"


/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetNoOfDigit */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetNoOfDigit(U32) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetNoOfDigit()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Data) */
    U32 _u32Data  = 0ul;

    {
    	_u32Data  = 9ul;
        /* Tested function call */
        U8 _return  = MApp_GetNoOfDigit(_u32Data);
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
    }

    {
    	_u32Data  = 99ul;
        /* Tested function call */
        U8 _return  = MApp_GetNoOfDigit(_u32Data);
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _return ) );
    }

    {
    	_u32Data  = 99999ul;
        /* Tested function call */
        U8 _return  = MApp_GetNoOfDigit(_u32Data);
        CPPTEST_ASSERT_UINTEGER_EQUAL(5, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetNoOfDigit */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UlongToU16String */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UlongToU16String(U32, U16 *, S8) */
void TestSuite_MApp_GlobalFunction_test_MApp_UlongToU16String()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ulValue) */
    U32 _ulValue  = 0ul;
    /* Initializing argument 2 (pArrOutput) */
    U16 au16ArrOutput[10]  = {0,0,0,0,0,0,0,0,0,0};

    /* Initializing argument 3 (NoOfDigit) */
    S8 _NoOfDigit  = 0;

    {
    	_ulValue = 0;
    	_NoOfDigit  = 1;
        /* Tested function call */
        MApp_UlongToU16String(_ulValue, au16ArrOutput, _NoOfDigit);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL('0', ( au16ArrOutput[0] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(  0, ( au16ArrOutput[1] ) );
    }

    {
    	_ulValue = 11;
    	_NoOfDigit  = 2;
        /* Tested function call */
        MApp_UlongToU16String(_ulValue, au16ArrOutput, _NoOfDigit);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL('1', ( au16ArrOutput[0] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL('1', ( au16ArrOutput[1] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(  0, ( au16ArrOutput[2] ) );
    }

    {
     	_ulValue = 22;
     	_NoOfDigit  = 1;
         /* Tested function call */
         MApp_UlongToU16String(_ulValue, au16ArrOutput, _NoOfDigit);
         /* Post-condition check */
         CPPTEST_ASSERT_UINTEGER_EQUAL('2', ( au16ArrOutput[0] ) );
         CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( au16ArrOutput[1] ) );
     }

    {
      	_ulValue = 12345678;
      	_NoOfDigit  = 8;
          /* Tested function call */
          MApp_UlongToU16String(_ulValue, au16ArrOutput, _NoOfDigit);
          /* Post-condition check */
          CPPTEST_ASSERT_UINTEGER_EQUAL('1', ( au16ArrOutput[0] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('2', ( au16ArrOutput[1] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('3', ( au16ArrOutput[2] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('4', ( au16ArrOutput[3] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('5', ( au16ArrOutput[4] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('6', ( au16ArrOutput[5] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('7', ( au16ArrOutput[6] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL('8', ( au16ArrOutput[7] ) );
          CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( au16ArrOutput[8] ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UlongToU16String */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_IsSrcHasSignal_true */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_IsSrcHasSignal(SCALER_WIN) */
void TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    BOOLEAN _return;

    { // VGA
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_VGA;
    	_return = IsSrcTypeAnalog(SYS_INPUT_SOURCE_TYPE(_eWindow));
    	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

        /* Tested function call */
         _return  = MApp_IsSrcHasSignal(_eWindow);
        /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    { // DTV
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DTV;
    	_return = IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(_eWindow));
    	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

        /* Tested function call */
         _return  = MApp_IsSrcHasSignal(_eWindow);
        /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

    { // DMP
     	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_STORAGE;
     	_return = IsSrcTypeStorage(SYS_INPUT_SOURCE_TYPE(_eWindow));
     	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

         /* Tested function call */
          _return  = MApp_IsSrcHasSignal(_eWindow);
         /* Post-condition check */
          CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
     }

    { // VD
     	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_TV;
     	_return = IsSrcTypeDigitalVD(SYS_INPUT_SOURCE_TYPE(_eWindow));
     	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));

         /* Tested function call */
          _return  = MApp_IsSrcHasSignal(_eWindow);
         /* Post-condition check */
          CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
     }
}
/* CPPTEST_TEST_CASE_END test_MApp_IsSrcHasSignal_true */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_IsSrcHasSignal_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_IsSrcHasSignal(SCALER_WIN) */
void TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    BOOLEAN _return;

    { // VGA
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_VGA;
        /* Tested function call */
        _return  = MApp_IsSrcHasSignal(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

    { // DTV
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_DTV;
        /* Tested function call */
         _return  = MApp_IsSrcHasSignal(_eWindow);
        /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

    { // VD
    	stSystemInfo[_eWindow].enInputSourceType = INPUT_SOURCE_TV;
         /* Tested function call */
        _return  = MApp_IsSrcHasSignal(_eWindow);
         /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
     }
}
/* CPPTEST_TEST_CASE_END test_MApp_IsSrcHasSignal_false */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetTimeZoneOffset_SUCESS */
/* CPPTEST_TEST_CASE_CONTEXT S32 MApp_GetTimeZoneOffset(U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZoneOffset_SUCESS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8TimeZone) */
    U8 _u8TimeZone  = 24;
    {
        /* Tested function call */
        S32 _return  = MApp_GetTimeZoneOffset(_u8TimeZone);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetTimeZoneOffset_SUCESS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetTimezoneOfCurrentCountry_SWITCH_CASE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetTimezoneOfCurrentCountry(U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetTimezoneOfCurrentCountry_SWITCH_CASE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Country) */

    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
	    U8 _u8Country  = OSD_COUNTRY_AUSTRIA;
        /* Tested function call */
        MApp_SetTimezoneOfCurrentCountry(_u8Country);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
    }
    {
   	    U8 _u8Country  = OSD_COUNTRY_BELGIUM;
           /* Tested function call */
           MApp_SetTimezoneOfCurrentCountry(_u8Country);
           /* Post-condition check */
           CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
       }
    {
       	    U8 _u8Country  = OSD_COUNTRY_BULGARIA;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_CROATIA;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_CZECH;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  =OSD_COUNTRY_DENMARK;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_FINLAND;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_FRANCE;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_GERMANY;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_GREECE;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  =  OSD_COUNTRY_HUNGARY;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_ITALY;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  =  OSD_COUNTRY_LUXEMBOURG;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
       	    U8 _u8Country  = OSD_COUNTRY_NETHERLANDS;
               /* Tested function call */
               MApp_SetTimezoneOfCurrentCountry(_u8Country);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
           }
    {
          	    U8 _u8Country  = OSD_COUNTRY_NORWAY;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
          	    U8 _u8Country  = OSD_COUNTRY_POLAND;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
          	    U8 _u8Country  = OSD_COUNTRY_PORTUGAL;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_24, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
          	    U8 _u8Country  = OSD_COUNTRY_RUMANIA;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
          	    U8 _u8Country  =OSD_COUNTRY_RUSSIA;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_30, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
          	    U8 _u8Country  = OSD_COUNTRY_SERBIA;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
          	    U8 _u8Country  = OSD_COUNTRY_SLOVENIA;
                  /* Tested function call */
                  MApp_SetTimezoneOfCurrentCountry(_u8Country);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
              }
    {
             	    U8 _u8Country  = OSD_COUNTRY_SPAIN;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_24, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_SWEDEN;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_SWITZERLAND;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_UK;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_24, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_NEWZEALAND;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_48, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_MOROCCO;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_24, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_TUNIS;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_ALGERIA;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_EGYPT;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_SOUTH_AFRICA;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
             	    U8 _u8Country  = OSD_COUNTRY_ISRAEL;
                     /* Tested function call */
                     MApp_SetTimezoneOfCurrentCountry(_u8Country);
                     /* Post-condition check */
                     CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_28, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                 }
    {
                	    U8 _u8Country  =OSD_COUNTRY_IRAN;
                        /* Tested function call */
                        MApp_SetTimezoneOfCurrentCountry(_u8Country);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_31, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                    }
    {
                	    U8 _u8Country  = OSD_COUNTRY_UNITED_ARAB_EMIRATES;
                        /* Tested function call */
                        MApp_SetTimezoneOfCurrentCountry(_u8Country);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_32, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                    }
    {
                	    U8 _u8Country  = OSD_COUNTRY_SLOVAKIA;
                        /* Tested function call */
                        MApp_SetTimezoneOfCurrentCountry(_u8Country);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_26, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                    }
    {
                   	    U8 _u8Country  = 0;
                           /* Tested function call */
                           MApp_SetTimezoneOfCurrentCountry(_u8Country);
                           /* Post-condition check */
                           CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_24, (  stGenSetting.g_Time.en_Clock_TimeZone ) );
                       }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetTimezoneOfCurrentCountry_SWITCH_CASE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetSubtAndAudioByCountry_SWITCH_CASE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetSubtAndAudioByCountry(EN_OSD_COUNTRY_SETTING) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetSubtAndAudioByCountry_SWITCH_CASE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eOSDCountrySetting) */

    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
	    EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_AUSTRALIA;
        /* Tested function call */
        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
    }
    {
    	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_AUSTRIA;
           /* Tested function call */
           MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
           /* Post-condition check */
           CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
           CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
           CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
           CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
    }
    {
        	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_BELGIUM;
               /* Tested function call */
               MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
               CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
               CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
               CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
    }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_BULGARIA;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_BULGARIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_BULGARIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_CROATIA;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_CROATIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_CROATIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_CZECH;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_CZECH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_CZECH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_DENMARK;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_DANISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_DANISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_FINLAND;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_FINNISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_SWEDISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_FINNISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_SWEDISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_FRANCE;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_GERMANY;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_GREECE;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_GREEK, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_GREEK, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_HUNGARY;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_HUNGARIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_HUNGARIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_ITALY;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ITALIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ITALIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_LUXEMBOURG;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_NETHERLANDS;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_DUTCH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_DUTCH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_NORWAY;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_NORWEGIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_NORWEGIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_POLAND;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_POLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_POLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_PORTUGAL;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_PORTUGUESE, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_PORTUGUESE, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_RUMANIA;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ROMANIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ROMANIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_RUSSIA;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_RUSSIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_RUSSIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SERBIA;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_SERBIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_SERBIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
           	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SLOVENIA;
                  /* Tested function call */
                  MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                  /* Post-condition check */
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_SLOVENIAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_SLOVENIAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                  CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
       }
    {
               	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SPAIN;
                      /* Tested function call */
                      MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                      /* Post-condition check */
                      CPPTEST_ASSERT_EQUAL( LANGUAGE_SPANISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                      CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                      CPPTEST_ASSERT_EQUAL( LANGUAGE_SPANISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                      CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
           }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SWEDEN;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_SWEDISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL(TRUE, ( stGenSetting.g_SysSetting.fEnableSubTitle  ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_SWEDISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SWITZERLAND;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_FRENCH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_GERMAN, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_UK;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_NEWZEALAND;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_MAORI, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_MOROCCO;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_TUNIS;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_ALGERIA;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_EGYPT;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SOUTH_AFRICA;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_ISRAEL;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_HEBREW, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_HEBREW, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_HEBREW, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_HEBREW, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_IRAN;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_PARSI, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_PARSI, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_PARSI, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_PARSI, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_UNITED_ARAB_EMIRATES;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ARABIC, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_SLOVAKIA;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_SLOVAK, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_SLOVAK, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  = OSD_COUNTRY_IRELAND;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_IRISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_IRISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }
    {
                 	   EN_OSD_COUNTRY_SETTING _eOSDCountrySetting  =  OSD_COUNTRY_NUMS;
                        /* Tested function call */
                        MApp_SetSubtAndAudioByCountry(_eOSDCountrySetting);
                        /* Post-condition check */
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SysSetting.SubtitleDefaultLanguage_2 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan1 ) );
                        CPPTEST_ASSERT_EQUAL( LANGUAGE_ENGLISH, (  stGenSetting.g_SoundSetting.enSoundAudioLan2 ) );
             }

}
/* CPPTEST_TEST_CASE_END test_MApp_SetSubtAndAudioByCountry_SWITCH_CASE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetTimeZoneBySITimeZone_SWITCH_CASE */
/* CPPTEST_TEST_CASE_CONTEXT EN_MENU_TIMEZONE MApp_GetTimeZoneBySITimeZone(EN_SI_TIMEZONE) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZoneBySITimeZone_SWITCH_CASE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eTimeZone) */

		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_CANARY;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_CANARY, (_return));
		}

		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_LISBON;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_LISBON, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_LONDON;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_LONDON, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_RABAT;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_RABAT, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_AMSTERDAM;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_AMSTERDAM, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BEOGRAD;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BEOGRAD, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BERLIN;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BERLIN, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BRUSSELS;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BRUSSELS, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BUDAPEST;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BUDAPEST, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_COPENHAGEN;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_COPENHAGEN, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_LIUBLJANA;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_LIUBLJANA, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_LUXEMBOURG;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_LUXEMBOURG, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_MADRID;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_MADRID, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_OSLO;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_OSLO, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_PARIS;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_PARIS, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_PRAGUE;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_PRAGUE, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BRATISLAVA;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BRATISLAVA, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BERN;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BERN, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_ROME;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_ROME, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_STOCKHOLM;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_STOCKHOLM, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_WARSAW;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_WARSAW, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_VIENNA;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_VIENNA, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_ZAGREB;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_ZAGREB, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_TUNIS;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_TUNIS, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_ALGIERS;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_ALGIERS, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_ATHENS;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_ATHENS, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BUCURESTI;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BUCURESTI, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_HELSINKI;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_HELSINKI, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_SOFIA;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_SOFIA, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_CAIRO;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_CAIRO, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_CAPE_TOWN;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_CAPE_TOWN, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_JERUSSLEM;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_JERUSSLEM, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_MOSCOW;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_MOSCOW, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_TEHERAN;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_TEHERAN, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_ABU_DHABI;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_ABU_DHABI, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_BEIJING;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_BEIJING, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_WA;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_WA, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_SA;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_SA, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_NT;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_NT, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_NSW;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_NSW, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_VIC;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_VIC, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_QLD;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_QLD, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_TAS;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_TAS, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_NZST;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_NZST, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_AZORES;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_AZORES, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_NUM;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_NUM, (_return));
		}
		{
			EN_SI_TIMEZONE _eTimeZone = SI_TIMEZONE_DUBLIN;
			/* Tested function call */
			EN_MENU_TIMEZONE _return = MApp_GetTimeZoneBySITimeZone(_eTimeZone);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(TIMEZONE_LONDON, (_return));
		}
	}
	/* CPPTEST_TEST_CASE_END test_MApp_GetTimeZoneBySITimeZone_SWITCH_CASE */

	/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetSICountry_SWITCH_CASE */
	/* CPPTEST_TEST_CASE_CONTEXT EN_SI_COUNTRY_SETTING MApp_GetSICountry(EN_OSD_COUNTRY_SETTING) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetSICountry_SWITCH_CASE()
{
		/* Pre-condition initialization */
		/* Initializing argument 1 (eTimeZone) */
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_AUSTRALIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry(_eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_AUSTRALIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_AUSTRIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_AUSTRIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_BELGIUM;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_BELGIUM, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_BULGARIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_BULGARIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_CROATIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_CROATIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_CZECH;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_CZECH, (_return));
	}
	{
			EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_DENMARK;
			/* Tested function call */
			EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(SI_COUNTRY_DENMARK, (_return));
		}
		{
			EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_FINLAND;
			/* Tested function call */
			EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(SI_COUNTRY_FINLAND, (_return));
		}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_FRANCE;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_FRANCE, (_return));
	}

	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_GERMANY;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_GERMANY, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_GREECE;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_GREECE, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_HUNGARY;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_HUNGARY, (_return));
	}
	{
			EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_ITALY;
			/* Tested function call */
			EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(SI_COUNTRY_ITALY, (_return));
		}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_IRELAND;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_IRELAND, (_return));
	}

	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_LUXEMBOURG;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_LUXEMBOURG, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_NETHERLANDS;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_NETHERLANDS, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_NORWAY;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_NORWAY, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_POLAND;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_POLAND, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_PORTUGAL;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_PORTUGAL, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_RUMANIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_RUMANIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_RUSSIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_RUSSIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SERBIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SERBIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SLOVENIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SLOVENIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SPAIN;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SPAIN, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SWEDEN;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SWEDEN, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SWITZERLAND;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SWITZERLAND, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_UK;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_UK, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_NEWZEALAND;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_NEWZEALAND, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_CHINA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_CHINA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_MOROCCO;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_MOROCCO, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_TUNIS;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_TUNIS, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_ALGERIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_ALGERIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_EGYPT;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_EGYPT, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SOUTH_AFRICA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SOUTH_AFRICA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_ISRAEL;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_ISRAEL, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_IRAN;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_IRAN, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_UNITED_ARAB_EMIRATES;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_UNITED_ARAB_EMIRATES, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SLOVAKIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_SLOVAKIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_ESTONIA;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_ESTONIA, (_return));
	}
	{
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_TURKEY;
		/* Tested function call */
		EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(SI_COUNTRY_TURKEY, (_return));
	}
	{
			EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_NUMS;
			/* Tested function call */
			EN_SI_COUNTRY_SETTING _return = MApp_GetSICountry( _eOSDCountrySetting);
			/* Post-condition check */
			CPPTEST_ASSERT_EQUAL(SI_COUNTRY_UK, (_return));
		}

}
/* CPPTEST_TEST_CASE_END test_MApp_GetSICountry_SWITCH_CASE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_HexUlongToU8String_WHILE_TEST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_HexUlongToU8String(U32, U8 *, S8) */
void TestSuite_MApp_GlobalFunction_test_MApp_HexUlongToU8String_WHILE_TEST()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ulValue) */
	U32 _ulValue;
	S8 _NoOfDigit;
    /* Initializing argument 2 (pArrOutput) */
    U8 _pArrOutput[10]  = {0,0,0,0,0,0,0,0,0,0};
    /* Initializing argument 3 (NoOfDigit) */

    {
    	_ulValue  = 0ul;
    	_NoOfDigit  = 0;
        /* Tested function call */
        MApp_HexUlongToU8String(_ulValue, _pArrOutput, _NoOfDigit);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _pArrOutput[0] ) );
    }
    {
		_ulValue = 1;
		_NoOfDigit = 1;
		/* Tested function call */
		MApp_HexUlongToU8String(_ulValue, _pArrOutput, _NoOfDigit);
		/* Post-condition check */
		CPPTEST_ASSERT_UINTEGER_EQUAL('1', (_pArrOutput[0]));
	}
    {
   		_ulValue = 10;
   		_NoOfDigit = 1;
   		/* Tested function call */
   		MApp_HexUlongToU8String(_ulValue, _pArrOutput, _NoOfDigit);
   		/* Post-condition check */
   		CPPTEST_ASSERT_UINTEGER_EQUAL('A', (_pArrOutput[0]));


   	}
    {
       		_ulValue = 10;
       		_NoOfDigit = 2;
       		/* Tested function call */
       		MApp_HexUlongToU8String(_ulValue, _pArrOutput, _NoOfDigit);
       		/* Post-condition check */
       		CPPTEST_ASSERT_UINTEGER_EQUAL('0', (_pArrOutput[0]));
       		CPPTEST_ASSERT_UINTEGER_EQUAL('A', (_pArrOutput[1]));

       	}
    {
          		_ulValue = 255;
          		_NoOfDigit = 2;
          		/* Tested function call */
          		MApp_HexUlongToU8String(_ulValue, _pArrOutput, _NoOfDigit);
          		/* Post-condition check */
          		CPPTEST_ASSERT_UINTEGER_EQUAL('F', (_pArrOutput[0]));
          		CPPTEST_ASSERT_UINTEGER_EQUAL('F', (_pArrOutput[1]));

          	}
}

/* CPPTEST_TEST_CASE_END test_MApp_HexUlongToU8String_WHILE_TEST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_HexUlongToU16String_WHILE_TEST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_HexUlongToU16String(U32, U16 *, S8) */
void TestSuite_MApp_GlobalFunction_test_MApp_HexUlongToU16String_WHILE_TEST()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ulValue) */
	U32 _ulValue;
		S8 _NoOfDigit;
	    /* Initializing argument 2 (pArrOutput) */
	    U16 _pArrOutput[10]  = {0,0,0,0,0,0,0,0,0,0};
	    /* Initializing argument 3 (NoOfDigit) */

	    {
	    	_ulValue  = 0ul;
	    	_NoOfDigit  = 0;
	        /* Tested function call */
	        MApp_HexUlongToU16String(_ulValue, _pArrOutput, _NoOfDigit);
	        /* Post-condition check */
	        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _pArrOutput[0] ) );
	    }
	    {
			_ulValue = 1;
			_NoOfDigit = 1;
			/* Tested function call */
			MApp_HexUlongToU16String(_ulValue, _pArrOutput, _NoOfDigit);
			/* Post-condition check */
			CPPTEST_ASSERT_UINTEGER_EQUAL('1', (_pArrOutput[0]));
		}
	    {
	   		_ulValue = 10;
	   		_NoOfDigit = 1;
	   		/* Tested function call */
	   		MApp_HexUlongToU8String(_ulValue, _pArrOutput, _NoOfDigit);
	   		/* Post-condition check */
	   		CPPTEST_ASSERT_UINTEGER_EQUAL('A', (_pArrOutput[0]));


	   	}
	    {
	       		_ulValue = 10;
	       		_NoOfDigit = 2;
	       		/* Tested function call */
	       		MApp_HexUlongToU16String(_ulValue, _pArrOutput, _NoOfDigit);
	       		/* Post-condition check */
	       		CPPTEST_ASSERT_UINTEGER_EQUAL('0', (_pArrOutput[0]));
	       		CPPTEST_ASSERT_UINTEGER_EQUAL('A', (_pArrOutput[1]));

	       	}
	    {
	          		_ulValue = 255;
	          		_NoOfDigit = 2;
	          		/* Tested function call */
	          		MApp_HexUlongToU16String(_ulValue, _pArrOutput, _NoOfDigit);
	          		/* Post-condition check */
	          		CPPTEST_ASSERT_UINTEGER_EQUAL('F', (_pArrOutput[0]));
	          		CPPTEST_ASSERT_UINTEGER_EQUAL('F', (_pArrOutput[1]));

	          	}
}
/* CPPTEST_TEST_CASE_END test_MApp_HexUlongToU16String_WHILE_TEST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UlongToU8String_WHILE_TEST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_UlongToU8String(U32, U8 *, S8) */
void TestSuite_MApp_GlobalFunction_test_MApp_UlongToU8String_WHILE_TEST()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ulValue) */
	 U32 _ulValue  = 0ul;
	    /* Initializing argument 2 (pArrOutput) */
	    U8 au8ArrOutput[10]  = {0,0,0,0,0,0,0,0,0,0};

	    /* Initializing argument 3 (NoOfDigit) */
	    S8 _NoOfDigit  = 0;

	    {
	    	_ulValue = 0;
	    	_NoOfDigit  = 1;
	        /* Tested function call */
	        MApp_UlongToU8String(_ulValue, au8ArrOutput, _NoOfDigit);
	        /* Post-condition check */
	        CPPTEST_ASSERT_UINTEGER_EQUAL('0', ( au8ArrOutput[0] ) );
	        CPPTEST_ASSERT_UINTEGER_EQUAL(  0, ( au8ArrOutput[1] ) );
	    }

	    {
	    	_ulValue = 11;
	    	_NoOfDigit  = 2;
	        /* Tested function call */
	        MApp_UlongToU8String(_ulValue, au8ArrOutput, _NoOfDigit);
	        /* Post-condition check */
	        CPPTEST_ASSERT_UINTEGER_EQUAL('1', ( au8ArrOutput[0] ) );
	        CPPTEST_ASSERT_UINTEGER_EQUAL('1', ( au8ArrOutput[1] ) );
	        CPPTEST_ASSERT_UINTEGER_EQUAL(  0, ( au8ArrOutput[2] ) );
	    }

	    {
	     	_ulValue = 22;
	     	_NoOfDigit  = 1;
	         /* Tested function call */
	         MApp_UlongToU8String(_ulValue, au8ArrOutput, _NoOfDigit);
	         /* Post-condition check */
	         CPPTEST_ASSERT_UINTEGER_EQUAL('2', ( au8ArrOutput[0] ) );
	         CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( au8ArrOutput[1] ) );
	     }

	    {
	      	_ulValue = 12345678;
	      	_NoOfDigit  = 8;
	          /* Tested function call */
	          MApp_UlongToU8String(_ulValue, au8ArrOutput, _NoOfDigit);
	          /* Post-condition check */
	          CPPTEST_ASSERT_UINTEGER_EQUAL('1', ( au8ArrOutput[0] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('2', ( au8ArrOutput[1] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('3', ( au8ArrOutput[2] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('4', ( au8ArrOutput[3] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('5', ( au8ArrOutput[4] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('6', ( au8ArrOutput[5] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('7', ( au8ArrOutput[6] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL('8', ( au8ArrOutput[7] ) );
	          CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( au8ArrOutput[8] ) );
	    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UlongToU8String_WHILE_TEST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_U8StringToU16String_COPY_TEST */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_U8StringToU16String(U8 *, U16 *, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_U8StringToU16String_COPY_TEST()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8Str) */
    U8 _pu8Str[5]  = {0,1,2,3,4} ;
    /* Initializing argument 2 (pu16Str) */
    U16 _pu16Str[5]  = {0,0,0,0,0} ;
    /* Initializing argument 3 (u8Strlen) */
    U8 _u8Strlen  = 5;
    {
        /* Tested function call */
        MApp_U8StringToU16String(_pu8Str, _pu16Str, _u8Strlen);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _pu16Str[0] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _pu16Str[1] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(2, ( _pu16Str[2] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(3, ( _pu16Str[3] ) );
        CPPTEST_ASSERT_UINTEGER_EQUAL(4, ( _pu16Str[4] ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_U8StringToU16String_COPY_TEST */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_U8StringToUlong_LEN_IS_2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_U8StringToUlong(U8 *, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_U8StringToUlong_LEN_IS_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputStr) */
	U8 _InputStr[2]  = {0,1} ;
	    /* Initializing argument 2 (len) */
	    U8 _len = 2;

	    {
	        /* Tested function call */
	        U32 _return  = MApp_U8StringToUlong(_InputStr, _len);
	        /* Post-condition check */
	        CPPTEST_ASSERT_UINTEGER_EQUAL(18446744073709551089,  _return );

	    }
}
/* CPPTEST_TEST_CASE_END test_MApp_U8StringToUlong_LEN_IS_2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_U8StringToUlong_LEN_IS_1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_U8StringToUlong(U8 *, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_U8StringToUlong_LEN_IS_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (InputStr) */
			U8 _InputStr[1]  = {0} ;
		    /* Initializing argument 2 (len) */
		    U8 _len = 1;

		    {
		        /* Tested function call */
		        U32 _return  = MApp_U8StringToUlong(_InputStr, _len);
		        /* Post-condition check */
		        CPPTEST_ASSERT_UINTEGER_EQUAL(0,  _return );

		    }
}
/* CPPTEST_TEST_CASE_END test_MApp_U8StringToUlong_LEN_IS_1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetLeap_IF */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetLeap(U16) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_IF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */
    U16 _u16year  = 400;
    {
        /* Tested function call */
        U8 _return  = MApp_GetLeap(_u16year);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetLeap_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetLeap_ELSEIF1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetLeap(U16) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_ELSEIF1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */
    U16 _u16year  = 100;
    {
            /* Tested function call */
            U8 _return  = MApp_GetLeap(_u16year);
            /* Post-condition check */
            CPPTEST_ASSERT_UINTEGER_EQUAL(0,  _return );
        }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetLeap_ELSEIF1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetLeap_ELSEIF2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetLeap(U16) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_ELSEIF2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */
    U16 _u16year  = 4u;
    {
        /* Tested function call */
    	 U8 _return  = MApp_GetLeap(_u16year);
    	            /* Post-condition check */
    	            CPPTEST_ASSERT_UINTEGER_EQUAL(1,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetLeap_ELSEIF2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetLeap_RETURN */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetLeap(U16) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetLeap_RETURN()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */
    U16 _u16year  = 1u;
    {
        /* Tested function call */
    	 U8 _return  = MApp_GetLeap(_u16year);
    	    	            /* Post-condition check */
    	    	            CPPTEST_ASSERT_UINTEGER_EQUAL(0,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetLeap_RETURN */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetDaysOfThisYear_IS_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_GetDaysOfThisYear(U16) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Year) */
    U16 _u16Year  = 0u;
    {
        /* Tested function call */
        U16 _return  = MApp_GetDaysOfThisYear(_u16Year);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(366,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetDaysOfThisYear_IS_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetDaysOfThisYear_IS_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_GetDaysOfThisYear(U16) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Year) */
    U16 _u16Year  = 0u;
    {
        /* Tested function call */
        U16 _return  = MApp_GetDaysOfThisYear(_u16Year);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(365,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetDaysOfThisYear_IS_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetDaysOfThisMonth_IF */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetDaysOfThisMonth(U16, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_IF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Year) */
    U16 _u16Year  = 0u;
    /* Initializing argument 2 (u8Month) */
    U8 _u8Month  = 1;
    {
        /* Tested function call */
        U8 _return  = MApp_GetDaysOfThisMonth(_u16Year, _u8Month);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(31,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetDaysOfThisMonth_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetDaysOfThisMonth_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetDaysOfThisMonth(U16, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Year) */
    U16 _u16Year  = 0u;
    /* Initializing argument 2 (u8Month) */
    U8 _u8Month  = 13;
    {
        /* Tested function call */
        U8 _return  = MApp_GetDaysOfThisMonth(_u16Year, _u8Month);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetDaysOfThisMonth_ELSE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetDayOfWeek_IF */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetDayOfWeek(U16, U8, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek_IF()
{

    {
    	 /* Pre-condition initialization */
    	    /* Initializing argument 1 (u16Year) */
    	    U16 _u16Year  = 2013;
    	    /* Initializing argument 2 (u8Month) */
    	    U8 _u8Month  = 3;
    	    /* Initializing argument 3 (u8Day) */
    	    U8 _u8Day  = 3;
        /* Tested function call */
        U8 _return  = MApp_GetDayOfWeek(_u16Year, _u8Month, _u8Day);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1,  _return );
    }
    {
       	 /* Pre-condition initialization */
       	    /* Initializing argument 1 (u16Year) */
       	    U16 _u16Year  = 2013;
       	    /* Initializing argument 2 (u8Month) */
       	    U8 _u8Month  = 4;
       	    /* Initializing argument 3 (u8Day) */
       	    U8 _u8Day  = 4;
           /* Tested function call */
           U8 _return  = MApp_GetDayOfWeek(_u16Year, _u8Month, _u8Day);
           /* Post-condition check */
           CPPTEST_ASSERT_UINTEGER_EQUAL(5,  _return );
       }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetDayOfWeek_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetDayOfWeek__NOT_LEAPYERA */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetDayOfWeek(U16, U8, U8) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek__NOT_LEAPYERA()
{
	{
	    	 /* Pre-condition initialization */
	    	    /* Initializing argument 1 (u16Year) */
	    	    U16 _u16Year  = 2013;
	    	    /* Initializing argument 2 (u8Month) */
	    	    U8 _u8Month  = 3;
	    	    /* Initializing argument 3 (u8Day) */
	    	    U8 _u8Day  = 3;
	        /* Tested function call */
	        U8 _return  = MApp_GetDayOfWeek(_u16Year, _u8Month, _u8Day);
	        /* Post-condition check */
	        CPPTEST_ASSERT_UINTEGER_EQUAL(0,  _return );
	    }
	    {
	       	 /* Pre-condition initialization */
	       	    /* Initializing argument 1 (u16Year) */
	       	    U16 _u16Year  = 2013;
	       	    /* Initializing argument 2 (u8Month) */
	       	    U8 _u8Month  = 4;
	       	    /* Initializing argument 3 (u8Day) */
	       	    U8 _u8Day  = 4;
	           /* Tested function call */
	           U8 _return  = MApp_GetDayOfWeek(_u16Year, _u8Month, _u8Day);
	           /* Post-condition check */
	           CPPTEST_ASSERT_UINTEGER_EQUAL(4,  _return );
	       }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetDayOfWeek__NOT_LEAPYERA */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetNoOfHexDigit_WHILE */
/* CPPTEST_TEST_CASE_CONTEXT U8 MApp_GetNoOfHexDigit(U32) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetNoOfHexDigit_WHILE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Data) */
    U32 _u32Data  = 0;
    {
        /* Tested function call */
        U8 _return  = MApp_GetNoOfHexDigit(_u32Data);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetNoOfHexDigit_WHILE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetClockTimezoneByTimezone */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetClockTimezoneByTimezone(EN_MENU_TIMEZONE) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetClockTimezoneByTimezone()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eTimezone) */

    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_0_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_24,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_1_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_26,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_1_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_26,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_2_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_28,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_2_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_28,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_3_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_30,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_3_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_30,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_8_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_40,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_8_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_40,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_9Point5_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_43,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_9Point5_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_43,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_10_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_44,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_10_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_44,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_12_START;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_48,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_12_END;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_48,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_AZORES;
		/* Tested function call */
		MApp_SetClockTimezoneByTimezone(_eTimezone);
		/* Post-condition check */
		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_22,
				(stGenSetting.g_Time.en_Clock_TimeZone));

	}

}
/* CPPTEST_TEST_CASE_END test_MApp_SetClockTimezoneByTimezone */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetMenuLanguage */
/* CPPTEST_TEST_CASE_CONTEXT EN_LANGUAGE MApp_GetMenuLanguage(void) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetMenuLanguage()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_SysSetting.Language = LANGUAGE_GAELIC;

    }
    {
        /* Tested function call */
        EN_LANGUAGE _return  = MApp_GetMenuLanguage();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DEFAULT_MENU_LANG, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetMenuLanguage */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetMenuLanguage_DTG */
/* CPPTEST_TEST_CASE_CONTEXT EN_LANGUAGE MApp_GetMenuLanguage_DTG(void) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetMenuLanguage_DTG()
{
	 /* Pre-condition initialization */
	    /* Initializing global variable stGenSetting */
	    {
	         stGenSetting.u8VersionCheck  = 0;
	         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
	         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
	         stGenSetting.u8VersionCheckCom  = 0;
	         stGenSetting.g_SysSetting.Language = LANGUAGE_GAELIC;

	    }
	    {
	        /* Tested function call */
	        EN_LANGUAGE _return  = MApp_GetMenuLanguage_DTG();
	        /* Post-condition check */
	        CPPTEST_ASSERT_EQUAL( DEFAULT_MENU_LANG, ( _return ) );
	    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetMenuLanguage_DTG */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_GetTimeZone_DTG */
/* CPPTEST_TEST_CASE_CONTEXT EN_MENU_TIMEZONE MApp_GetTimeZone_DTG(void) */
void TestSuite_MApp_GlobalFunction_test_MApp_GetTimeZone_DTG()
{
    /* Pre-condition initialization */
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
         stGenSetting.g_Time.enTimeZone = TIMEZONE_NUM;
    }
    {
        /* Tested function call */
        EN_MENU_TIMEZONE _return  = MApp_GetTimeZone_DTG();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TIMEZONE_GMT_0_START, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_GetTimeZone_DTG */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetTimeZone_IF1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetTimeZone(EN_MENU_TIMEZONE) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetTimeZone_IF1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eTimezone) */
    EN_MENU_TIMEZONE _eTimezone  = TIMEZONE_NUM;
    /* Initializing global variable stGenSetting */
    {
         stGenSetting.u8VersionCheck  = 0;
         stGenSetting.stMiscSetting.bRunInstallationGuide  = 0;
         stGenSetting.stMiscSetting.bDCOnOff  = EN_POWER_DC_ON;
         stGenSetting.u8VersionCheckCom  = 0;
    }
    {
        /* Tested function call */
        MApp_SetTimeZone(_eTimezone);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL( EN_Clock_TimeZone_24,stGenSetting.g_Time.en_Clock_TimeZone );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_SetTimeZone_IF1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetTimeZone_ELSEIF */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetTimeZone(EN_MENU_TIMEZONE) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetTimeZone_ELSEIF()
{
	/* Pre-condition initialization */
	/* Initializing argument 1 (eTimezone) */

	/* Initializing global variable stGenSetting */
	{
		stGenSetting.u8VersionCheck = 0;
		stGenSetting.stMiscSetting.bRunInstallationGuide = 0;
		stGenSetting.stMiscSetting.bDCOnOff = EN_POWER_DC_ON;
		stGenSetting.u8VersionCheckCom = 0;
	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_1_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_26,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_1_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_26,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_2_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_28,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_2_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_28,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_3_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_30,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_3_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_30,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_3Point5_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_31,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_3Point5_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_31,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_4_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_32,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_4_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_32,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_8_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_40,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_8_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_40,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_9Point5_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_43,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_9Point5_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_43,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_10_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_44,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_10_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_44,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_12_START;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_48,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
		EN_MENU_TIMEZONE _eTimezone = TIMEZONE_GMT_12_END;
		/* Tested function call */
		MApp_SetTimeZone(_eTimezone);
		/* Post-condition check */

		CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_48,
				stGenSetting.g_Time.en_Clock_TimeZone);

	}
	{
			EN_MENU_TIMEZONE _eTimezone = TIMEZONE_AZORES;
			/* Tested function call */
			MApp_SetTimeZone(_eTimezone);
			/* Post-condition check */

			CPPTEST_ASSERT_EQUAL(EN_Clock_TimeZone_22,
					stGenSetting.g_Time.en_Clock_TimeZone);

		}
}
/* CPPTEST_TEST_CASE_END test_MApp_SetTimeZone_ELSEIF */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetSICountry_SWITCH_CASE */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_SetSICountry(EN_OSD_COUNTRY_SETTING) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetSICountry_SWITCH_CASE()
{
    /* Pre-condition initialization */
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_AUSTRALIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_AUSTRIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_BELGIUM;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_BULGARIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_CROATIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_CZECH;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_DENMARK;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_FINLAND;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_FRANCE;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_GERMANY;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_GREECE;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_HUNGARY;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_ITALY;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_IRELAND;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_LUXEMBOURG;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_NETHERLANDS;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_NORWAY;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_POLAND;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_PORTUGAL;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_RUMANIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_RUSSIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SERBIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SLOVENIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SPAIN;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SWEDEN;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SWITZERLAND;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_UK;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_NEWZEALAND;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_CHINA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_MOROCCO;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_TUNIS;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_ALGERIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_EGYPT;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SOUTH_AFRICA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_EGYPT;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting = OSD_COUNTRY_SOUTH_AFRICA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_ISRAEL;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_IRAN;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
			/* Initializing argument 1 (eOSDCountrySetting) */
			EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_UNITED_ARAB_EMIRATES;
			/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_SLOVAKIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_ESTONIA;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
		/* Initializing argument 1 (eOSDCountrySetting) */
		EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_TURKEY;
		/* Tested function call */
		MApp_SetSICountry(_eOSDCountrySetting);
		/* Post-condition check */

	}
	{
			/* Initializing argument 1 (eOSDCountrySetting) */
			EN_OSD_COUNTRY_SETTING _eOSDCountrySetting =OSD_COUNTRY_NUMS;
			/* Tested function call */
			MApp_SetSICountry(_eOSDCountrySetting);
			/* Post-condition check */

		}

}
/* CPPTEST_TEST_CASE_END test_MApp_SetSICountry_SWITCH_CASE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_UTC2Seconds */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_MJDUTC2Seconds(U8 *) */
void TestSuite_MApp_GlobalFunction_test_MApp_UTC2Seconds()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pau8TDTData) */
    U8  _pau8TDTData[]  = {1,2,3} ;
    /* Initializing global variable _stDate */
    {
       //  _stDate.u8Hour  = 0u;
      //   _stDate.u8Min  = 0u;
        // _stDate.u8Sec  = 0;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_UTC2Seconds(_pau8TDTData);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(3723,  _return );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_UTC2Seconds */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_SetSILanguage_TEST_SWITCH */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_AddDay2StTime(U16, ST_TIME *) */
void TestSuite_MApp_GlobalFunction_test_MApp_SetSILanguage_TEST_SWITCH()
{
    /* Pre-condition initialization */
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_CZECH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_DANISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_GERMAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_ENGLISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SPANISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_GREEK;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_FRENCH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_CROATIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_ITALIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_HUNGARIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_DUTCH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_NORWEGIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_POLISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_PORTUGUESE;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_RUSSIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_ROMANIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SLOVENIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SERBIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_FINNISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SWEDISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_BULGARIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SLOVAK;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_GAELIC;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_WELSH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_IRISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_TURKISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_NETHERLANDS;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_GALLEGAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_BASQUE;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_LUXEMBOURGISH;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_ICELANDIC;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_LATVIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_ESTONIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_LITHUANIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_UKRANIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_BELARUSIAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SPANISH_CAT;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_SAMI;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_ARABIC;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_HEBREW;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_KOREAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_JAPAN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_HINDI;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_MANDARIN;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_CANTONESE;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_MAORI;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
   {
		/* Initializing argument 1 (eOSDCountrySetting) */
	   EN_LANGUAGE _eLanguage = LANGUAGE_NONE;
		/* Tested function call */
	   MApp_SetSILanguage(_eLanguage);
		/* Post-condition check */
	}
}
/* CPPTEST_TEST_CASE_END test_MApp_SetSILanguage_TEST_SWITCH */
