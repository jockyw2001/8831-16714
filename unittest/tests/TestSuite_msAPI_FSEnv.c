#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/msAPI_FSEnv.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/msAPI_FSEnv.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_FSEnv);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetAddr);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_UnRegister_u8CurrentDirectoryIndex);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_UnRegister_return);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_GetEnvironment_Return_NULL);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_GetEnvironment_Return_g_environment_list);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year400);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year100);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year4);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_YearNotAbove);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_between1and12);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_Notbetween1and12);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step1);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step2);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step3);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step1);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step2);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertSeconds2StTime_step1);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLocalTime_step1);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLocalTime_step2);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step1);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step2);
CPPTEST_TEST(TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step3);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetAddr();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_UnRegister_u8CurrentDirectoryIndex();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_UnRegister_return();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_GetEnvironment_Return_NULL();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_GetEnvironment_Return_g_environment_list();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year400();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year100();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year4();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_YearNotAbove();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_between1and12();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_Notbetween1and12();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step1();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step2();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step3();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step1();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step2();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertSeconds2StTime_step1();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLocalTime_step1();
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLocalTime_step2();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step1();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step2();
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step3();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_FSEnv);

void TestSuite_msAPI_FSEnv_setUp()
{
}

void TestSuite_msAPI_FSEnv_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetAddr */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FS_GetAddr(U32) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetAddr()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (addr) */ 
    U32 _addr  = 0x1111;
    {
        /* Tested function call */
        U32 _return  = msAPI_FS_GetAddr(_addr);
        /* Post-condition check */
       // CPPTEST_POST_CONDITION_UINTEGER(0x1111, ( _return ));
        CPPTEST_ASSERT_EQUAL(0x1111,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetAddr */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_UnRegister */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FSEnv_UnRegister(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_UnRegister_u8CurrentDirectoryIndex()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 4;
    }
    {
        /* Tested function call */
        msAPI_FSEnv_UnRegister(_environmentId);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
        CPPTEST_ASSERT_EQUAL(0xFF,(g_environment_list[_environmentId].u8CurrentDirectoryIndex));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_UnRegister */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_UnRegister */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FSEnv_UnRegister(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_UnRegister_return()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 4;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 4;
    }
    {
    	g_environment_list[_environmentId].u8CurrentDirectoryIndex = 0x00;
        /* Tested function call */
        msAPI_FSEnv_UnRegister(_environmentId);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
       // CPPTEST_ASSERT_EQUAL(0x00,(g_environment_list[_environmentId].u8CurrentDirectoryIndex));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_UnRegister */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_GetEnvironment */
/* CPPTEST_TEST_CASE_CONTEXT FS_EnvironmentStruct * msAPI_FSEnv_GetEnvironment(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_GetEnvironment_Return_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 4;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 4;
    }
    {
        /* Tested function call */
        FS_EnvironmentStruct * _return  = msAPI_FSEnv_GetEnvironment(_environmentId);
        /* Post-condition check */
       // CPPTEST_POST_CONDITION_PTR(NULL, ( _return ));
      //  CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_GetEnvironment */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_GetEnvironment */
/* CPPTEST_TEST_CASE_CONTEXT FS_EnvironmentStruct * msAPI_FSEnv_GetEnvironment(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_GetEnvironment_Return_g_environment_list()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 1;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 4;
    }
    {
        /* Tested function call */
    	g_environment_list[_environmentId].u8CurrentDirectoryIndex = 0x01;
        FS_EnvironmentStruct * _return  = msAPI_FSEnv_GetEnvironment(_environmentId);
        /* Post-condition check */
      //  CPPTEST_POST_CONDITION_PTR("FS_EnvironmentStruct * _return ", ( _return ));
      //s  CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
        CPPTEST_ASSERT_EQUAL(0x01,g_environment_list[_environmentId].u8CurrentDirectoryIndex);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_GetEnvironment */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetLeap */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FS_GetLeap(U16) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year400()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */ 
    U16 _u16year  = 400;
    {
        /* Tested function call */
        U8 _return  = msAPI_FS_GetLeap(_u16year);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_ASSERT_EQUAL(1,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetLeap */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetLeap */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FS_GetLeap(U16) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year100()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */ 
    U16 _u16year  = 100;
    {
        /* Tested function call */
        U8 _return  = msAPI_FS_GetLeap(_u16year);
        /* Post-condition check */
       // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_ASSERT_EQUAL(0,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetLeap */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetLeap */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FS_GetLeap(U16) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_Year4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */ 
    U16 _u16year  = 4;
    {
        /* Tested function call */
        U8 _return  = msAPI_FS_GetLeap(_u16year);
        /* Post-condition check */
       // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
          CPPTEST_ASSERT_EQUAL(1,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetLeap */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetLeap */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FS_GetLeap(U16) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLeap_YearNotAbove()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16year) */ 
    U16 _u16year  = 1;
    {
        /* Tested function call */
        U8 _return  = msAPI_FS_GetLeap(_u16year);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_ASSERT_EQUAL(0,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetLeap */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetDaysOfThisMonth */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FS_GetDaysOfThisMonth(U16, U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_between1and12()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Year) */ 
    U16 _u16Year  = 2000;
    /* Initializing argument 2 (u8Month) */ 
    U8 _u8Month  = 2;
    {
        /* Tested function call */
        U8 _return  = msAPI_FS_GetDaysOfThisMonth(_u16Year, _u8Month);
        /* Post-condition check */
       //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_ASSERT_EQUAL(29,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetDaysOfThisMonth */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetDaysOfThisMonth */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FS_GetDaysOfThisMonth(U16, U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetDaysOfThisMonth_Month_Notbetween1and12()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Year) */ 
    U16 _u16Year  = 2000;
    /* Initializing argument 2 (u8Month) */ 
    U8 _u8Month  = 13;
    {
        /* Tested function call */
        U8 _return  = msAPI_FS_GetDaysOfThisMonth(_u16Year, _u8Month);
        /* Post-condition check */
       // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_ASSERT_EQUAL(0,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetDaysOfThisMonth */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_Init */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FSEnv_Init(U32, U32) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FS_adr) */ 
    U32 _u32FS_adr  = 0x11;
    /* Initializing argument 2 (u32FS_len) */ 
    U32 _u32FS_len  = 0x12;
    /* Initializing global variable _FILE_SYSTEM_POOL_ADR */ 
    {
         _FILE_SYSTEM_POOL_ADR  = 0ul;
    }
    /* Initializing global variable _FILE_SYSTEM_POOL_LEN */ 
    {
         _FILE_SYSTEM_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR_CACHE */ 
    {
         USB_IO_TEMP_ADDR_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable DEVICE_IO_BUFFER_ADDR */ 
    {
         DEVICE_IO_BUFFER_ADDR  = 0ul;
    }
    /* Initializing global variable STORAGE_DEVICE_MEMORY_ADDR */ 
    {
         STORAGE_DEVICE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    /* Initializing global variable FILE_ENVIRONMENT_POOL_LEN */ 
    {
         FILE_ENVIRONMENT_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE_LEN */ 
    {
         FILE_FAT_TABLE_CACHE_LEN  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL_LEN */ 
    {
         FILE_INODE_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL_LEN */ 
    {
         FILE_HANDLE_POOL_LEN  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_2 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_2  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_INDEX_BUFFER_ADDR */ 
    {
         N51FS_INDEX_BUFFER_ADDR  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FS_MEMORY_MAP_END */ 
    {
         FS_MEMORY_MAP_END  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FSEnv_Init(_u32FS_adr, _u32FS_len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0x11,_u32FS_adr);
        CPPTEST_ASSERT_EQUAL(0x12,_u32FS_len);
        CPPTEST_ASSERT_EQUAL(0,_return);
      //  CPPTEST_ASSERT_EQUAL(1,FS_FILE_HANDLE_NUM);
    //    CPPTEST_ASSERT_EQUAL(1,FS_ENVIRONMENT_NUM);
      //  CPPTEST_ASSERT_EQUAL(1,DISK_DRIVE_NUM);
      /*  CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _FILE_SYSTEM_POOL_ADR", ( _FILE_SYSTEM_POOL_ADR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _FILE_SYSTEM_POOL_LEN", ( _FILE_SYSTEM_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR_CACHE", ( USB_IO_TEMP_ADDR_CACHE ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR2", ( USB_IO_TEMP_ADDR2 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DEVICE_IO_BUFFER_ADDR", ( DEVICE_IO_BUFFER_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 STORAGE_DEVICE_MEMORY_ADDR", ( STORAGE_DEVICE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL_LEN", ( FILE_ENVIRONMENT_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE", ( FILE_FAT_TABLE_CACHE ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE_LEN", ( FILE_FAT_TABLE_CACHE_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL_LEN", ( FILE_INODE_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL_LEN", ( FILE_HANDLE_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_0", ( N51FS_TEMP_4K_BACKUP_BUFFER_0 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_1", ( N51FS_TEMP_4K_BACKUP_BUFFER_1 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_2", ( N51FS_TEMP_4K_BACKUP_BUFFER_2 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BUFFER_0", ( N51FS_TEMP_4K_BUFFER_0 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BUFFER_1", ( N51FS_TEMP_4K_BUFFER_1 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_INDEX_BUFFER_ADDR", ( N51FS_INDEX_BUFFER_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_FIXUP", ( N51FS_TEMP_4K_FIXUP ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FS_MEMORY_MAP_END", ( FS_MEMORY_MAP_END ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_Init */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_Init_step2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FSEnv_Init(U32, U32) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FS_adr) */ 
    U32 _u32FS_adr  = 0x10;
    /* Initializing argument 2 (u32FS_len) */ 
    U32 _u32FS_len  = 0x1B001;
    /* Initializing global variable _FILE_SYSTEM_POOL_ADR */ 
    {
         _FILE_SYSTEM_POOL_ADR  = 0ul;
    }
    /* Initializing global variable _FILE_SYSTEM_POOL_LEN */ 
    {
         _FILE_SYSTEM_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR_CACHE */ 
    {
         USB_IO_TEMP_ADDR_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable DEVICE_IO_BUFFER_ADDR */ 
    {
         DEVICE_IO_BUFFER_ADDR  = 0ul;
    }
    /* Initializing global variable STORAGE_DEVICE_MEMORY_ADDR */ 
    {
         STORAGE_DEVICE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    /* Initializing global variable FILE_ENVIRONMENT_POOL_LEN */ 
    {
         FILE_ENVIRONMENT_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE_LEN */ 
    {
         FILE_FAT_TABLE_CACHE_LEN  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL_LEN */ 
    {
         FILE_INODE_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL_LEN */ 
    {
         FILE_HANDLE_POOL_LEN  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_2 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_2  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_INDEX_BUFFER_ADDR */ 
    {
         N51FS_INDEX_BUFFER_ADDR  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FS_MEMORY_MAP_END */ 
    {
         FS_MEMORY_MAP_END  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FSEnv_Init(_u32FS_adr, _u32FS_len);

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(6,FS_FILE_HANDLE_NUM);
        CPPTEST_ASSERT_EQUAL(4,FS_ENVIRONMENT_NUM);
        CPPTEST_ASSERT_EQUAL(16,DISK_DRIVE_NUM);


       /* CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _FILE_SYSTEM_POOL_ADR", ( _FILE_SYSTEM_POOL_ADR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _FILE_SYSTEM_POOL_LEN", ( _FILE_SYSTEM_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR_CACHE", ( USB_IO_TEMP_ADDR_CACHE ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR2", ( USB_IO_TEMP_ADDR2 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DEVICE_IO_BUFFER_ADDR", ( DEVICE_IO_BUFFER_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 STORAGE_DEVICE_MEMORY_ADDR", ( STORAGE_DEVICE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL_LEN", ( FILE_ENVIRONMENT_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE", ( FILE_FAT_TABLE_CACHE ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE_LEN", ( FILE_FAT_TABLE_CACHE_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL_LEN", ( FILE_INODE_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL_LEN", ( FILE_HANDLE_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_0", ( N51FS_TEMP_4K_BACKUP_BUFFER_0 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_1", ( N51FS_TEMP_4K_BACKUP_BUFFER_1 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_2", ( N51FS_TEMP_4K_BACKUP_BUFFER_2 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BUFFER_0", ( N51FS_TEMP_4K_BUFFER_0 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BUFFER_1", ( N51FS_TEMP_4K_BUFFER_1 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_INDEX_BUFFER_ADDR", ( N51FS_INDEX_BUFFER_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_FIXUP", ( N51FS_TEMP_4K_FIXUP ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FS_MEMORY_MAP_END", ( FS_MEMORY_MAP_END ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_Init_step2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_Init_check_step3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FSEnv_Init(U32, U32) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Init_check_step3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FS_adr) */ 
    U32 _u32FS_adr  = 0x80C2D000;
    /* Initializing argument 2 (u32FS_len) */ 
    U32 _u32FS_len  = 0x60000;
    /* Initializing global variable _FILE_SYSTEM_POOL_ADR */ 
    {
         _FILE_SYSTEM_POOL_ADR  = 0ul;
    }
    /* Initializing global variable _FILE_SYSTEM_POOL_LEN */ 
    {
         _FILE_SYSTEM_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR_CACHE */ 
    {
         USB_IO_TEMP_ADDR_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable DEVICE_IO_BUFFER_ADDR */ 
    {
         DEVICE_IO_BUFFER_ADDR  = 0ul;
    }
    /* Initializing global variable STORAGE_DEVICE_MEMORY_ADDR */ 
    {
         STORAGE_DEVICE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    /* Initializing global variable FILE_ENVIRONMENT_POOL_LEN */ 
    {
         FILE_ENVIRONMENT_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE_LEN */ 
    {
         FILE_FAT_TABLE_CACHE_LEN  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL_LEN */ 
    {
         FILE_INODE_POOL_LEN  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL_LEN */ 
    {
         FILE_HANDLE_POOL_LEN  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_2 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_2  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_1 */ 
    {
         N51FS_TEMP_4K_BUFFER_1  = 0ul;
    }
    /* Initializing global variable N51FS_INDEX_BUFFER_ADDR */ 
    {
         N51FS_INDEX_BUFFER_ADDR  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FS_MEMORY_MAP_END */ 
    {
         FS_MEMORY_MAP_END  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FSEnv_Init(_u32FS_adr, _u32FS_len);
        /* Post-condition check */
        //printf("##### num = 0x%X #####\n",XDataAddr[0][0]);
        //printf("##### FS_MEMORY_MAP_END = 0x%X #####\n",FS_MEMORY_MAP_END);
        //printf("##### _FILE_SYSTEM_POOL_ADR = 0x%X #####\n",_FILE_SYSTEM_POOL_ADR);
        //printf("##### _FILE_SYSTEM_POOL_LEN = 0x%X #####\n",_FILE_SYSTEM_POOL_LEN);

        CPPTEST_ASSERT_EQUAL(0x80C40800,XDataAddr[0][0]);// Current file System usage depends on CL 790469.
        CPPTEST_ASSERT_EQUAL(1,_return);
       // CPPTEST_ASSERT_EQUAL(1,_return);
      /*  CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _FILE_SYSTEM_POOL_ADR", ( _FILE_SYSTEM_POOL_ADR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _FILE_SYSTEM_POOL_LEN", ( _FILE_SYSTEM_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR_CACHE", ( USB_IO_TEMP_ADDR_CACHE ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR2", ( USB_IO_TEMP_ADDR2 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DEVICE_IO_BUFFER_ADDR", ( DEVICE_IO_BUFFER_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 STORAGE_DEVICE_MEMORY_ADDR", ( STORAGE_DEVICE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL_LEN", ( FILE_ENVIRONMENT_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE", ( FILE_FAT_TABLE_CACHE ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE_LEN", ( FILE_FAT_TABLE_CACHE_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL_LEN", ( FILE_INODE_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL_LEN", ( FILE_HANDLE_POOL_LEN ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_0", ( N51FS_TEMP_4K_BACKUP_BUFFER_0 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_1", ( N51FS_TEMP_4K_BACKUP_BUFFER_1 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BACKUP_BUFFER_2", ( N51FS_TEMP_4K_BACKUP_BUFFER_2 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BUFFER_0", ( N51FS_TEMP_4K_BUFFER_0 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_BUFFER_1", ( N51FS_TEMP_4K_BUFFER_1 ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_INDEX_BUFFER_ADDR", ( N51FS_INDEX_BUFFER_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 N51FS_TEMP_4K_FIXUP", ( N51FS_TEMP_4K_FIXUP ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FS_MEMORY_MAP_END", ( FS_MEMORY_MAP_END ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_Init_check_step3 */



/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_ConvertStTime2Seconds_step1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FS_ConvertStTime2Seconds(FS_TIME *) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTime) */ 
    FS_TIME * _pstTime  = 0 ;
    FS_TIME var = {1990,3,1,12,1,1};
    _pstTime = &var;
    {
        /* Tested function call */
        U32 _return  = msAPI_FS_ConvertStTime2Seconds(_pstTime);
        /* Post-condition check */
       // CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
       // CPPTEST_POST_CONDITION_PTR("FS_TIME * _pstTime ", ( _pstTime ));
        CPPTEST_ASSERT_EQUAL(320932861,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_ConvertStTime2Seconds_step1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_ConvertStTime2Seconds_step2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FS_ConvertStTime2Seconds(FS_TIME *) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertStTime2Seconds_step2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTime) */ 
    FS_TIME * _pstTime  = 0 ;
    FS_TIME var = {1990,3,1,12,1,1};
    _pstTime = &var;
    {
        /* Tested function call */
        U32 _return  = msAPI_FS_ConvertStTime2Seconds(_pstTime);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_ConvertStTime2Seconds_step2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_ConvertSeconds2StTime_step1 */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FS_ConvertSeconds2StTime(U32, FS_TIME *) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_ConvertSeconds2StTime_step1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32SystemTime) */ 
    U32 _u32SystemTime  = 31968000;
    /* Initializing argument 2 (pstTime) */ 
    FS_TIME * _pstTime  = 1 ;
    FS_TIME var = {1990,3,1,12,1,1};
    _pstTime = &var;
    {
        /* Tested function call */
        msAPI_FS_ConvertSeconds2StTime(_u32SystemTime, _pstTime);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_PTR("FS_TIME * _pstTime ", ( _pstTime ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_ConvertSeconds2StTime_step1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetLocalTime_step1 */
/* CPPTEST_TEST_CASE_CONTEXT FS_TIME msAPI_FS_GetLocalTime(void) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLocalTime_step1()
{
    /* Pre-condition initialization */
	g_u8TimeInfo_Flag = 0;
    {
        /* Tested function call */
        FS_TIME _return  = msAPI_FS_GetLocalTime();
        /* Post-condition check */
       /* CPPTEST_POST_CONDITION_UINTEGER("U16 _return.u16Year", ( _return.u16Year ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Month", ( _return.u8Month ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Day", ( _return.u8Day ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Hour", ( _return.u8Hour ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Min", ( _return.u8Min ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Sec", ( _return.u8Sec ));
        */
        CPPTEST_ASSERT_EQUAL(2008,_return.u16Year);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetLocalTime_step1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FS_GetLocalTime_step2 */
/* CPPTEST_TEST_CASE_CONTEXT FS_TIME msAPI_FS_GetLocalTime(void) */
void TestSuite_msAPI_FSEnv_test_msAPI_FS_GetLocalTime_step2()
{
    /* Pre-condition initialization */
	g_u8TimeInfo_Flag = 1;
    {
        /* Tested function call */
        FS_TIME _return  = msAPI_FS_GetLocalTime();
        /* Post-condition check */
       /* CPPTEST_POST_CONDITION_UINTEGER("U16 _return.u16Year", ( _return.u16Year ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Month", ( _return.u8Month ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Day", ( _return.u8Day ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Hour", ( _return.u8Hour ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Min", ( _return.u8Min ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return.u8Sec", ( _return.u8Sec ));
        */
        CPPTEST_ASSERT_EQUAL(1980,_return.u16Year);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FS_GetLocalTime_step2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_Register_step1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FSEnv_Register(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (driveID) */ 
    U8 _driveID  = 17;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
       //  FS_ENVIRONMENT_NUM  = 0;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
        // DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FSEnv_Register(_driveID);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0xFF,_return);
       // CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
       // CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
       // CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_Register_step1 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_Register_step2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FSEnv_Register(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (driveID) */ 
    U8 _driveID  = 15;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 4;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
        DISK_DRIVE_NUM  = 16;
    	g_environment_list[1].bIsInit = FALSE;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FSEnv_Register(_driveID);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(INVALID_FS_ENVIRONMENT_INDEX,_return);
      //  CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
      //  CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
      //  CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_Register_step2 */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FSEnv_Register_step3 */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FSEnv_Register(U8) */
void TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (driveID) */ 
    U8 _driveID  = 15;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 4;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 16;
         g_environment_list[1].bIsInit = FALSE;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FSEnv_Register(_driveID);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FSEnv_Register_step3 */
