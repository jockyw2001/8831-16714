#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/N51FS_Bitmap.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/N51FS_Bitmap.c");

CPPTEST_TEST_SUITE(TestSuit_N51FS_Bitmap);
CPPTEST_TEST(TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord);
CPPTEST_TEST(TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0);
CPPTEST_TEST(TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0);
CPPTEST_TEST_SUITE_END();
        

void TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord();
void TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0();
void TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_N51FS_Bitmap);

void TestSuit_N51FS_Bitmap_setUp()
{
}

void TestSuit_N51FS_Bitmap_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Bitmap_MFRFree(U8, U32) */
void TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32MFR) */ 
    U32 _u32MFR  = 0ul;
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Bitmap_MFRFree(_u8fsid, _u32MFR);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Bitmap_MFRFree(U8, U32) */
void TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32MFR) */ 
    U32 _u32MFR  = 0ul;
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Bitmap_MFRFree(_u8fsid, _u32MFR);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));

    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_Bitmap_MFRFree(U8, U32) */
void TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32MFR) */ 
    U32 _u32MFR  = 0ul;
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_Bitmap_MFRFree(_u8fsid, _u32MFR);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0 */

