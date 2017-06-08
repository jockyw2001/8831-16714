#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/msAPI_Bootloader.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/msAPI_Bootloader.c");

CPPTEST_TEST_SUITE(TestSuit_msAPI_Bootloader);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_GetFlashPosOf2ndMagicNo_ifyes_ifyes);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearIspUpdate_ifno);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_msAPI_BLoader_IsIspUpdate_ifyes);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_msAPI_BLoader_SetDownloadType);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_msAPI_BLoader_SetCountry);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearDownloadInfo);
CPPTEST_TEST(TestSuit_msAPI_Bootloader_test_msAPI_BLoader_Reboot);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_msAPI_Bootloader_test_GetFlashPosOf2ndMagicNo_ifyes_ifyes();
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearIspUpdate_ifno();
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_IsIspUpdate_ifyes();
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_SetDownloadType();
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_SetCountry();
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearDownloadInfo();
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_Reboot();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_msAPI_Bootloader);

void TestSuit_msAPI_Bootloader_setUp()
{
}

void TestSuit_msAPI_Bootloader_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_GetFlashPosOf2ndMagicNo_ifyes_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT U32 GetFlashPosOf2ndMagicNo(void) */
void TestSuit_msAPI_Bootloader_test_GetFlashPosOf2ndMagicNo_ifyes_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32ImgInfoOffset */ 
    {
         u32ImgInfoOffset  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = GetFlashPosOf2ndMagicNo();
        CPPTEST_ASSERT_EQUAL(0,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 u32ImgInfoOffset", ( u32ImgInfoOffset ));
    }
}
/* CPPTEST_TEST_CASE_END test_GetFlashPosOf2ndMagicNo_ifyes_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_BLoader_ClearIspUpdate_ifno */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_BLoader_ClearIspUpdate(void) */
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearIspUpdate_ifno()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32ImgInfoOffset */ 
    {
         u32ImgInfoOffset  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_BLoader_ClearIspUpdate();
        CPPTEST_ASSERT_EQUAL(FALSE,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 u32ImgInfoOffset", ( u32ImgInfoOffset ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_BLoader_ClearIspUpdate_ifno */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_BLoader_IsIspUpdate_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_BLoader_IsIspUpdate(void) */
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_IsIspUpdate_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing global variable u32ImgInfoOffset */ 
    {
         u32ImgInfoOffset  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_BLoader_IsIspUpdate();
        CPPTEST_ASSERT_EQUAL(FALSE,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 u32ImgInfoOffset", ( u32ImgInfoOffset ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_BLoader_IsIspUpdate_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_BLoader_SetDownloadType */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_BLoader_SetDownloadType(EN_DOWNLOAD_TYPE) */
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_SetDownloadType()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DownloadType) */ 
    EN_DOWNLOAD_TYPE _u8DownloadType  = DOWNLOAD_TYPE_NONE;
    {
        /* Tested function call */
        msAPI_BLoader_SetDownloadType(_u8DownloadType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_BLoader_SetDownloadType */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_BLoader_SetCountry */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_BLoader_SetCountry(U8) */
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_SetCountry()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Country) */ 
    U8 _u8Country  = 0;
    {
        /* Tested function call */
        msAPI_BLoader_SetCountry(_u8Country);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_BLoader_SetCountry */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_BLoader_ClearDownloadInfo */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_BLoader_ClearDownloadInfo(void) */
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearDownloadInfo()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        msAPI_BLoader_ClearDownloadInfo();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_BLoader_ClearDownloadInfo */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_BLoader_Reboot */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_BLoader_Reboot(void) */
void TestSuit_msAPI_Bootloader_test_msAPI_BLoader_Reboot()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        msAPI_BLoader_Reboot();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_BLoader_Reboot */
