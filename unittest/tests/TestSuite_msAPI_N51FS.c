#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/msAPI_N51FS.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/msAPI_N51FS.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_N51FS);

CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordInfo);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentInfo);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootInfo);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsInfo);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordMIUAddress);

CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootMIUAddress);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsMIUAddress);
// CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetCurrentFileEntryMIUAddress);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentMIUAddressa);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetTemp0XDataMIUAddr);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetCurrentMFR);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetParentMFR);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_ELSE);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_SwapAttrHead_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_SwapAttrHead_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_3);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_4);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_5);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_3);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_SaveEnvironment);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_HandlePostCreate);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentFileEntry);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_WriteMFTRecord_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryFirst_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryNext_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryNext_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryNext_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_EntryNext_4);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileOpen_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileOpen_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileRead_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileRead_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileRead_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileTell_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileTell_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileClose);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileLength_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileLength_1);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileSeek_0);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2);
CPPTEST_TEST(TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3);
CPPTEST_TEST_SUITE_END();
        


void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordInfo();
void TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentInfo();
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootInfo();
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsInfo();
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordMIUAddress();


void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootMIUAddress();
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsMIUAddress();
// void TestSuite_msAPI_N51FS_test_N51FS_GetCurrentFileEntryMIUAddress();
void TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentMIUAddressa();
void TestSuite_msAPI_N51FS_test_N51FS_GetTemp0XDataMIUAddr();
void TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetCurrentMFR();
void TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetParentMFR();

void TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo();
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_ELSE();
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_1();
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_2();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_SwapAttrHead_0();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_SwapAttrHead_1();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_1();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_2();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_3();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_0();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_4();
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_5();
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_0();
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_1();
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_3();
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_2();
void TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_0();
void TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1();
void TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE();
void TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_0();
void TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_1();
void TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_0();
void TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_1();
void TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_2();
void TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_1();
void TestSuite_msAPI_N51FS_test_N51FS_SaveEnvironment();
void TestSuite_msAPI_N51FS_test_N51FS_HandlePostCreate();
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_0();
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_1();
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_2();
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentFileEntry();
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_0();
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1();
void TestSuite_msAPI_N51FS_test_N51FS_WriteMFTRecord_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_1();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5();
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6();
void TestSuite_msAPI_N51FS_test_N51FS_EntryFirst_0();
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_0();
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_1();
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_2();
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_4();
void TestSuite_msAPI_N51FS_test_N51FS_FileOpen_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileOpen_1();
void TestSuite_msAPI_N51FS_test_N51FS_FileRead_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileRead_1();
void TestSuite_msAPI_N51FS_test_N51FS_FileRead_2();
void TestSuite_msAPI_N51FS_test_N51FS_FileTell_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileTell_1();
void TestSuite_msAPI_N51FS_test_N51FS_FileClose();
void TestSuite_msAPI_N51FS_test_N51FS_FileLength_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileLength_1();
void TestSuite_msAPI_N51FS_test_N51FS_FileSeek_0();
void TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2();
void TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_N51FS);

void TestSuite_msAPI_N51FS_setUp()
{
}

void TestSuite_msAPI_N51FS_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetIndexRecordInfo */
/* CPPTEST_TEST_CASE_CONTEXT IndexRecord * N51FS_GetIndexRecordInfo(U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_GetIndexRecordInfo;
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    g_CppTest_Stub_N51FS_GetIndexRecordInfo = FALSE;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        IndexRecord * _return  = N51FS_GetIndexRecordInfo(_enid);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("IndexRecord * _return ", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_ASSERT_EQUAL(TRUE, g_CppTest_Stub_N51FS_GetIndexRecordInfo);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetIndexRecordInfo */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetEnvironmentInfo */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_Environment * N51FS_GetEnvironmentInfo(U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_GetEnvironmentInfo;
void TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    g_CppTest_Stub_N51FS_GetEnvironmentInfo = FALSE;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_Environment * _return  = N51FS_GetEnvironmentInfo(_enid);
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_PTR("N51FS_Environment * _return ", ( _return ));
        // CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_ASSERT_EQUAL(TRUE, g_CppTest_Stub_N51FS_GetEnvironmentInfo);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetEnvironmentInfo */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetIndexRootInfo */
/* CPPTEST_TEST_CASE_CONTEXT U32 * N51FS_GetIndexRootInfo(U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_N51FS_GetIndexRootInfo;
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    g_CppTest_Stub_N51FS_N51FS_GetIndexRootInfo = FALSE;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 * _return  = N51FS_GetIndexRootInfo(_enid);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("U32 * _return ", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_ASSERT_EQUAL(TRUE, g_CppTest_Stub_N51FS_N51FS_GetIndexRootInfo);
    }
}

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetIndexVarsInfo */
/* CPPTEST_TEST_CASE_CONTEXT IndexVars * N51FS_GetIndexVarsInfo(U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_GetIndexVarsInfo;
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    g_CppTest_Stub_N51FS_GetIndexVarsInfo = FALSE;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        IndexVars * _return  = N51FS_GetIndexVarsInfo(_enid);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("U32 * _return ", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
        CPPTEST_ASSERT_EQUAL(TRUE, g_CppTest_Stub_N51FS_GetIndexVarsInfo);
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetIndexVarsInfo */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetIndexRecordMIUAddress */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_GetIndexRecordMIUAddress(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordMIUAddress()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_GetIndexRecordMIUAddress(_enid);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(0x2000, ( _return ));
        CPPTEST_ASSERT_EQUAL(0x3000, ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_ENVIRONMENT_POOL", ( FILE_ENVIRONMENT_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetIndexRecordMIUAddress */

void TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootMIUAddress()
{
	U8 _enid  = 0;
	FILE_ENVIRONMENT_POOL = 0;
    U32 _return  = N51FS_GetIndexRootMIUAddress(_enid);
    CPPTEST_ASSERT_EQUAL(0x2000, ( _return ));
}

void TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsMIUAddress()
{
	U8 _enid  = 0;
	FILE_ENVIRONMENT_POOL = 0;
    U32 _return  = N51FS_GetIndexVarsMIUAddress(_enid);
    CPPTEST_ASSERT_EQUAL(0x1000, ( _return ));
    //return (FILE_ENVIRONMENT_POOL + (U32)enid*FILE_ENVIRONMENT_MEMORY_SIZE+memoffset_N51FS_IndexVars);
}
/*
void TestSuite_msAPI_N51FS_test_N51FS_GetCurrentFileEntryMIUAddress()
{
	U8 _enid  = 0;
	FILE_ENVIRONMENT_POOL = 0;
    U32 _return  = N51FS_GetCurrentFileEntryMIUAddress(_enid);
    CPPTEST_ASSERT_EQUAL(0x4000, ( _return ));
    //return (FILE_ENVIRONMENT_POOL + (U32)enid*FILE_ENVIRONMENT_MEMORY_SIZE+memoffset_N51FS_CurrentFileEntry);
}*/

void TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentMIUAddressa()
{
	U8 _enid  = 0;
	FILE_ENVIRONMENT_POOL = 0;
    U32 _return  = N51FS_GetEnvironmentMIUAddressa(_enid);
    CPPTEST_ASSERT_EQUAL(0, ( _return ));
    //return (FILE_ENVIRONMENT_POOL + (U32)enid*FILE_ENVIRONMENT_MEMORY_SIZE+memoffset_N51FS_CurrentFileEntry);
}

void TestSuite_msAPI_N51FS_test_N51FS_GetTemp0XDataMIUAddr()
{
    U32 _return  = N51FS_GetTemp0XDataMIUAddr();
    CPPTEST_ASSERT_EQUAL(0, ( _return ));
}

void TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetCurrentMFR()
{
	U8 _environmentId = 0;
	U32 _return = 1;
    _return = N51FS_DirectoryGetCurrentMFR(_environmentId);
    CPPTEST_ASSERT_EQUAL(0, ( _return ));
}

void TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetParentMFR()
{
	U8 _environmentId = 0;
	U32 _return = 1;
    _return  = N51FS_DirectoryGetParentMFR(_environmentId);
    CPPTEST_ASSERT_EQUAL(0, ( _return ));
}


/* CPPTEST_TEST_CASE_BEGIN test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_ReadMFT_LSN(U8, U32) */
extern MS_BOOL g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo;
extern MS_BOOL g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr;
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileSystemID) */ 
    U8 _fileSystemID  = 0;
    g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = FALSE;
    /* Initializing argument 2 (MFR) */ 
    U32 _MFR  = 0xFFFFFFFF;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_ReadMFT_LSN(_fileSystemID, _MFR);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
        //CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_ReadMFT_LSN_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_ReadMFT_LSN(U8, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileSystemID) */ 
    U8 _fileSystemID  = 0;
    g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = FALSE;
    /* Initializing argument 2 (MFR) */ 
    U32 _MFR  = 0x00;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_ReadMFT_LSN(_fileSystemID, _MFR);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_ReadMFT_LSN_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_ReadMFTRecord_1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_ReadMFTRecord(U8, U32, U32) */
extern MS_BOOL g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return;
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileSystemID) */ 
    U8 _fileSystemID  = 0;
    /* Initializing argument 2 (MFR) */ 
    U32 _MFR  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_ReadMFTRecord(_fileSystemID, _MFR, _destMIUAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_ReadMFTRecord_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_ReadMFTRecord_2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_ReadMFTRecord(U8, U32, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileSystemID) */ 
    U8 _fileSystemID  = 0;
    /* Initializing argument 2 (MFR) */ 
    U32 _MFR  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_ReadMFTRecord(_fileSystemID, _MFR, _destMIUAddr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_ReadMFTRecord_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_SwapAttrHead_0 */
/* CPPTEST_TEST_CASE_CONTEXT void N51FS_Attribute_SwapAttrHead(void *) */
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_SwapAttrHead_0()
{
	N51FS_ResidentAttrHead * opObj;
	N51FS_ResidentAttrHead obj;
	obj.NonResidentFlag = 0;
	opObj = &obj;
    /* Pre-condition initialization */
    /* Initializing argument 1 (pAttrHead) */ 
	void * _pAttrHead  = (void *)(opObj);
    {
        /* Tested function call */
        N51FS_Attribute_SwapAttrHead(_pAttrHead);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("void * _pAttrHead ", ( _pAttrHead ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_SwapAttrHead_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_SwapAttrHead_1 */
/* CPPTEST_TEST_CASE_CONTEXT void N51FS_Attribute_SwapAttrHead(void *) */
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_SwapAttrHead_1()
{
	N51FS_ResidentAttrHead * opObj;
	N51FS_ResidentAttrHead obj;
	obj.NonResidentFlag = 1;
	opObj = &obj;
    /* Pre-condition initialization */
    /* Initializing argument 1 (pAttrHead) */ 
	void * _pAttrHead  = (void *)(opObj);
    {
        /* Tested function call */
        N51FS_Attribute_SwapAttrHead(_pAttrHead);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("void * _pAttrHead ", ( _pAttrHead ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_SwapAttrHead_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_Find_0 */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_AttributeInfo N51FS_Attribute_Find(U8, U32, U32, EN_ATTRIBUTE_TYPE, U16 *, U32) */
extern MS_BOOL g_CppTest_Stub___N51FS_Attribute_Find_Return;
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (startMIUAddr) */ 
    U32 _startMIUAddr  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (attrType) */ 
    EN_ATTRIBUTE_TYPE _attrType  = ATTR_TYPE_STANDARD_INFORMATION;
    /* Initializing argument 5 (pu16Offset) */ 
    U16 objOffset = 0;
    U16 * _pu16Offset  = (&objOffset);
    /* Initializing argument 6 (lowestVCN) */ 
    U32 _lowestVCN  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_AttributeInfo _return  = N51FS_Attribute_Find(_fsid, _startMIUAddr, _destMIUAddr, _attrType, _pu16Offset, _lowestVCN);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_Find_0 */
/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_Find_1 */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_AttributeInfo N51FS_Attribute_Find(U8, U32, U32, EN_ATTRIBUTE_TYPE, U16 *, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (startMIUAddr) */ 
    U32 _startMIUAddr  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (attrType) */ 
    EN_ATTRIBUTE_TYPE _attrType  = ATTR_TYPE_STANDARD_INFORMATION;
    /* Initializing argument 5 (pu16Offset) */ 
    U16 objOffset = 0;
    U16 * _pu16Offset  = (&objOffset);
    /* Initializing argument 6 (lowestVCN) */ 
    U32 _lowestVCN  = 1ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_AttributeInfo _return  = N51FS_Attribute_Find(_fsid, _startMIUAddr, _destMIUAddr, _attrType, _pu16Offset, _lowestVCN);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_Find_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_Find_2 */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_AttributeInfo N51FS_Attribute_Find(U8, U32, U32, EN_ATTRIBUTE_TYPE, U16 *, U32) */
extern MS_BOOL g_CppTest_Stub_msAPI_FS_Memory_Allocate;
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (startMIUAddr) */ 
    U32 _startMIUAddr  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (attrType) */ 
    EN_ATTRIBUTE_TYPE _attrType  = ATTR_TYPE_STANDARD_INFORMATION;
    /* Initializing argument 5 (pu16Offset) */ 
    U16 objOffset = 0;
    U16 * _pu16Offset  = (&objOffset);
    /* Initializing argument 6 (lowestVCN) */ 
    U32 _lowestVCN  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_AttributeInfo _return  = N51FS_Attribute_Find(_fsid, _startMIUAddr, _destMIUAddr, _attrType, _pu16Offset, _lowestVCN);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_Find_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_Find_3 */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_AttributeInfo N51FS_Attribute_Find(U8, U32, U32, EN_ATTRIBUTE_TYPE, U16 *, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (startMIUAddr) */ 
    U32 _startMIUAddr  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (attrType) */ 
    EN_ATTRIBUTE_TYPE _attrType  = ATTR_TYPE_STANDARD_INFORMATION;
    /* Initializing argument 5 (pu16Offset) */ 
    U16 objOffset = 0;
    U16 * _pu16Offset  = (&objOffset);
    /* Initializing argument 6 (lowestVCN) */ 
    U32 _lowestVCN  = 1ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_AttributeInfo _return  = N51FS_Attribute_Find(_fsid, _startMIUAddr, _destMIUAddr, _attrType, _pu16Offset, _lowestVCN);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_Find_3 */



/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_Find_4 */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_AttributeInfo N51FS_Attribute_Find(U8, U32, U32, EN_ATTRIBUTE_TYPE, U16 *, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (startMIUAddr) */ 
    U32 _startMIUAddr  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (attrType) */ 
    EN_ATTRIBUTE_TYPE _attrType  = ATTR_TYPE_STANDARD_INFORMATION;
    /* Initializing argument 5 (pu16Offset) */ 
    U16 objOffset = 0;
    U16 * _pu16Offset  = (&objOffset);
    /* Initializing argument 6 (lowestVCN) */ 
    U32 _lowestVCN  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_AttributeInfo _return  = N51FS_Attribute_Find(_fsid, _startMIUAddr, _destMIUAddr, _attrType, _pu16Offset, _lowestVCN);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_Find_4 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_Attribute_Find_5 */
/* CPPTEST_TEST_CASE_CONTEXT N51FS_AttributeInfo N51FS_Attribute_Find(U8, U32, U32, EN_ATTRIBUTE_TYPE, U16 *, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (startMIUAddr) */ 
    U32 _startMIUAddr  = 0ul;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (attrType) */ 
    EN_ATTRIBUTE_TYPE _attrType  = ATTR_TYPE_STANDARD_INFORMATION;
    /* Initializing argument 5 (pu16Offset) */ 
    U16 objOffset = 0;
    U16 * _pu16Offset  = (&objOffset);
    /* Initializing argument 6 (lowestVCN) */ 
    U32 _lowestVCN  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_AttributeInfo _return  = N51FS_Attribute_Find(_fsid, _startMIUAddr, _destMIUAddr, _attrType, _pu16Offset, _lowestVCN);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_Attribute_Find_5 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_InitialFileSystem_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_InitialFileSystem(S8, U32, U8 *, N51FS_FileSysStruct *) */
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    S8 _deviceIndex  = 0;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (partitionBytes) */ 
    U8 objList[10];
    U8 * _partitionBytes  = 0 ;
    _partitionBytes = &objList;
    /* Initializing argument 4 (pFileSysToInitial) */ 
    N51FS_FileSysStruct obj;
    N51FS_FileSysStruct * _pFileSysToInitial  = 0 ;
    _pFileSysToInitial = &obj;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_InitialFileSystem(_deviceIndex, _logicalBlockAddress, _partitionBytes, _pFileSysToInitial);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return ));
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_InitialFileSystem_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_InitialFileSystem_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_InitialFileSystem(S8, U32, U8 *, N51FS_FileSysStruct *) */
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    S8 _deviceIndex  = 0;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (partitionBytes) */ 
    U8 objList[10];
    U8 * _partitionBytes  = 0 ;
    _partitionBytes = &objList;
    /* Initializing argument 4 (pFileSysToInitial) */ 
    N51FS_FileSysStruct obj;
    N51FS_FileSysStruct * _pFileSysToInitial  = 0 ;
    _pFileSysToInitial = &obj;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_InitialFileSystem(_deviceIndex, _logicalBlockAddress, _partitionBytes, _pFileSysToInitial);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_InitialFileSystem_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_InitialFileSystem_2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_InitialFileSystem(S8, U32, U8 *, N51FS_FileSysStruct *) */
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    S8 _deviceIndex  = 0;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (partitionBytes) */ 
    U8 objList[10];
    U8 * _partitionBytes  = 0 ;
    _partitionBytes = &objList;
    /* Initializing argument 4 (pFileSysToInitial) */ 
    N51FS_FileSysStruct obj;
    N51FS_FileSysStruct * _pFileSysToInitial  = 0 ;
    _pFileSysToInitial = &obj;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_InitialFileSystem(_deviceIndex, _logicalBlockAddress, _partitionBytes, _pFileSysToInitial);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        //CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_InitialFileSystem_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_InitialFileSystem_3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_InitialFileSystem(S8, U32, U8 *, N51FS_FileSysStruct *) */
void TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    S8 _deviceIndex  = 0;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (partitionBytes) */ 
    U8 objList[10];
    U8 * _partitionBytes  = 0 ;
    _partitionBytes = &objList;
    /* Initializing argument 4 (pFileSysToInitial) */ 
    N51FS_FileSysStruct obj;
    N51FS_FileSysStruct * _pFileSysToInitial  = 0 ;
    _pFileSysToInitial = &obj;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_InitialFileSystem(_deviceIndex, _logicalBlockAddress, _partitionBytes, _pFileSysToInitial);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        // CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_InitialFileSystem_3 */


/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetFreeSpaceInKB_0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_GetFreeSpaceInKB(U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_GetFileEntryByMFR;
extern MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileOpen;
extern MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileRead_Return;
void TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_GetFreeSpaceInKB(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_GetFileEntryByMFR ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileOpen ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetFreeSpaceInKB_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetFreeSpaceInKB_1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_GetFreeSpaceInKB(U8) */
extern MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileSeek;
void TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_GetFreeSpaceInKB(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_GetFileEntryByMFR ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileOpen ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileSeek ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileRead_Return ));
        //CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetFreeSpaceInKB_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetFreeSpaceInKB_1_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_GetFreeSpaceInKB(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = N51FS_GetFreeSpaceInKB(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_GetFileEntryByMFR ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileOpen ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileSeek ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileRead_Return ));
        //CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetFreeSpaceInKB_1_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetTotalSizeInKB_0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_GetTotalSizeInKB(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 1;
    {
        /* Tested function call */
        U32 _return  = N51FS_GetTotalSizeInKB(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetTotalSizeInKB_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetTotalSizeInKB_1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_GetTotalSizeInKB(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 1;
    {
        /* Tested function call */
        U32 _return  = N51FS_GetTotalSizeInKB(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetTotalSizeInKB_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetFileEntryByMFR_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_GetFileEntryByMFR(U8, U32, FileEntry *) */
extern MS_BOOL g_CppTest_Stub_N51FS_ReadMFTRecord_Return;
extern MS_BOOL g_CppTest_Stub_N51FS_Attribute_Find_Return;
void TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32mfr) */ 
    U32 _u32mfr  = 0ul;
    /* Initializing argument 3 (pFileToSet) */ 
    FileEntry pFileToSet;
    FileEntry * _pFileToSet  = &pFileToSet ;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_GetFileEntryByMFR(_u8fsid, _u32mfr, _pFileToSet);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetFileEntryByMFR_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetFileEntryByMFR_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_GetFileEntryByMFR(U8, U32, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 1;
    /* Initializing argument 2 (u32mfr) */ 
    U32 _u32mfr  = 0ul;
    /* Initializing argument 3 (pFileToSet) */ 
    FileEntry pFileToSet;
    FileEntry * _pFileToSet  = &pFileToSet ;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_GetFileEntryByMFR(_u8fsid, _u32mfr, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Attribute_Find_Return ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetFileEntryByMFR_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_GetFileEntryByMFR_2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_GetFileEntryByMFR(U8, U32, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 1;
    /* Initializing argument 2 (u32mfr) */ 
    U32 _u32mfr  = 0ul;
    /* Initializing argument 3 (pFileToSet) */ 
    FileEntry pFileToSet;
    FileEntry * _pFileToSet  = &pFileToSet ;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable N51FS_TEMP_4K_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BUFFER_0  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_GetFileEntryByMFR(_u8fsid, _u32mfr, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Attribute_Find_Return ));
        //CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_GetFileEntryByMFR_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileRecordFindVolumeLabel_0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_FileRecordFindVolumeLabel(U8, U16 *, U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_ReadMFTRecord_Return;
extern MS_BOOL g_CppTest_Stub_msAPI_FS_MIU_Copy_Return;
void TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing argument 2 (VolLabName) */ 
    U16 * _VolLabName  = 0 ;
    /* Initializing argument 3 (VolLabNameLen) */ 
    U8 _VolLabNameLen  = 0;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_FileRecordFindVolumeLabel(_u8DriveIndex, _VolLabName, _VolLabNameLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileRecordFindVolumeLabel_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileRecordFindVolumeLabel_1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_FileRecordFindVolumeLabel(U8, U16 *, U8) */
void TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing argument 2 (VolLabName) */ 
    U16 * _VolLabName  = 0 ;
    /* Initializing argument 3 (VolLabNameLen) */ 
    U8 _VolLabNameLen  = 0;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_FileRecordFindVolumeLabel(_u8DriveIndex, _VolLabName, _VolLabNameLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_MIU_Copy_Return ));
        //CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileRecordFindVolumeLabel_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_SaveEnvironment */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_SaveEnvironment(U8) */
extern MS_BOOL g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return;
extern MS_BOOL g_CppTest_Stub_N51FS_GetEnvironmentInfo_Return;
void TestSuite_msAPI_N51FS_test_N51FS_SaveEnvironment()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_SaveEnvironment(_enid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_GetEnvironmentInfo_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_SaveEnvironment */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_HandlePostCreate */
/* CPPTEST_TEST_CASE_CONTEXT void N51FS_HandlePostCreate(U8, U8, U32, U32, U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_File_GetHandleInfo_Return;
void TestSuite_msAPI_N51FS_test_N51FS_HandlePostCreate()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fhid) */ 
    U8 _fhid  = 0;
    /* Initializing argument 2 (fileSystemId) */ 
    U8 _fileSystemId  = 0;
    /* Initializing argument 3 (fileLengthHI) */ 
    U32 _fileLengthHI  = 0ul;
    /* Initializing argument 4 (fileLengthLo) */ 
    U32 _fileLengthLo  = 0ul;
    /* Initializing argument 5 (openMode) */ 
    U8 _openMode  = 0;
    {
        /* Tested function call */
        N51FS_HandlePostCreate(_fhid, _fileSystemId, _fileLengthHI, _fileLengthLo, _openMode);
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_File_GetHandleInfo_Return ));
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_HandlePostCreate */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryGetCurrentNameToMIU_0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_EntryGetCurrentNameToMIU(U8, U32, U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return ;
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing argument 2 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 0;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_EntryGetCurrentNameToMIU(_enid, _destMIUAddr, _charLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryGetCurrentNameToMIU_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryGetCurrentNameToMIU_1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_EntryGetCurrentNameToMIU(U8, U32, U8) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing argument 2 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 1;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_EntryGetCurrentNameToMIU(_enid, _destMIUAddr, _charLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryGetCurrentNameToMIU_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryGetCurrentNameToMIU_2 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_EntryGetCurrentNameToMIU(U8, U32, U8) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing argument 2 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 1;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_EntryGetCurrentNameToMIU(_enid, _destMIUAddr, _charLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryGetCurrentNameToMIU_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryGetCurrentFileEntry */
/* CPPTEST_TEST_CASE_CONTEXT void N51FS_EntryGetCurrentFileEntry(U8, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentFileEntry()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing argument 2 (entry) */ 
    FileEntry * _entry  = 0 ;
    /* Initializing global variable FILE_ENVIRONMENT_POOL */ 
    {
         FILE_ENVIRONMENT_POOL  = 0ul;
    }
    {
        /* Tested function call */
        N51FS_EntryGetCurrentFileEntry(_enid, _entry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryGetCurrentFileEntry */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryGetFileNameByFileEntry_0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_EntryGetFileNameByFileEntry(U8, FileEntry *, U32, U8, BOOLEAN *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing argument 2 (entry) */ 
    FileEntry * _entry  = 0 ;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (charLen) */ 
    U8 _charLen  = 0;
    /* Initializing argument 5 (bIsLongName) */ 
    BOOLEAN * _bIsLongName  = 0 ;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_EntryGetFileNameByFileEntry(_enid, _entry, _destMIUAddr, _charLen, _bIsLongName);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryGetFileNameByFileEntry_0 */


/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryGetFileNameByFileEntry_1 */
/* CPPTEST_TEST_CASE_CONTEXT U8 N51FS_EntryGetFileNameByFileEntry(U8, FileEntry *, U32, U8, BOOLEAN *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing argument 2 (entry) */ 
    FileEntry * _entry  = 0 ;
    /* Initializing argument 3 (destMIUAddr) */ 
    U32 _destMIUAddr  = 0ul;
    /* Initializing argument 4 (charLen) */ 
    U8 _charLen  = 0;
    /* Initializing argument 5 (bIsLongName) */ 
    BOOLEAN * _bIsLongName  = 0 ;
    /* Initializing global variable N51FS_TEMP_4K_FIXUP */ 
    {
         N51FS_TEMP_4K_FIXUP  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = N51FS_EntryGetFileNameByFileEntry(_enid, _entry, _destMIUAddr, _charLen, _bIsLongName);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFTRecord_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub___N51FS_Attribute_Find_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_MIU_Copy_Return ));
        //CPPTEST_ASSERT_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryGetFileNameByFileEntry_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_WriteMFTRecord_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_WriteMFTRecord(U8, U32, U32) */
extern MS_BOOL g_CppTest_Stub_N51FS_ReadMFT_LSN_Return;
extern BOOLEAN gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_N51FS_test_N51FS_WriteMFTRecord_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fileSystemID) */ 
    U8 _fileSystemID  = 0;
    /* Initializing argument 2 (MFR) */ 
    U32 _MFR  = 0ul;
    /* Initializing argument 3 (SrcMIUaddr) */ 
    U32 _SrcMIUaddr  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_WriteMFTRecord(_fileSystemID, _MFR, _SrcMIUaddr);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_ReadMFT_LSN_Return ) );
        CPPTEST_ASSERT_EQUAL(TRUE, ( gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_WriteMFTRecord_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
extern MS_BOOL g_CppTest_Stub_N51FS_Delete_Index_Search_Return;
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
extern MS_BOOL g_CppTest_Stub_N51FS_Delete_RemoveNode_Return;
extern MS_BOOL g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return;
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_Index_Search_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
extern MS_BOOL g_CppTest_Stub_N51FS_WriteMFTRecord_Return;
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_Index_Search_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_Index_Search_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_WriteMFTRecord_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_3 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_4 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_Index_Search_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_WriteMFTRecord_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_4 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_5 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_Index_Search_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_WriteMFTRecord_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_5 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileDelete_6 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileDelete(FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry objFileEntry;
    FileEntry * _pFileEntry;
    _pFileEntry = &objFileEntry;
    /* Initializing global variable pIndexHeader */ 
    {
         pIndexHeader  = 0 ;
    }
    /* Initializing global variable N51FS_TEMP_4K_BACKUP_BUFFER_0 */ 
    {
         N51FS_TEMP_4K_BACKUP_BUFFER_0  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FS_Memory_Allocate ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_Index_Search_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_WriteMFTRecord_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileDelete_6 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryFirst_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_EntryFirst(U8) */
extern MS_BOOL g_CppTest_Stub_N51FS_Index_ToFirst_Return;
void TestSuite_msAPI_N51FS_test_N51FS_EntryFirst_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_EntryFirst(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_Index_ToFirst_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryFirst_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryNext_0 */
/* CPPTEST_TEST_CASE_CONTEXT EN_ENTRY_NEXT_RESULT N51FS_EntryNext(U8, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = INVALID_FS_ENVIRONMENT_INDEX;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry * _pFileToSet;
    FileEntry objFileEntry;
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = N51FS_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryNext_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryNext_1 */
/* CPPTEST_TEST_CASE_CONTEXT EN_ENTRY_NEXT_RESULT N51FS_EntryNext(U8, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry * _pFileToSet;
    FileEntry objFileEntry;
    _pFileToSet = (&objFileEntry);
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = N51FS_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryNext_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryNext_2 */
/* CPPTEST_TEST_CASE_CONTEXT EN_ENTRY_NEXT_RESULT N51FS_EntryNext(U8, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry * _pFileToSet;
    FileEntry objFileEntry;
    _pFileToSet = (&objFileEntry);
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = N51FS_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryNext_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_EntryNext_4 */
/* CPPTEST_TEST_CASE_CONTEXT EN_ENTRY_NEXT_RESULT N51FS_EntryNext(U8, FileEntry *) */
void TestSuite_msAPI_N51FS_test_N51FS_EntryNext_4()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry * _pFileToSet;
    FileEntry objFileEntry;
    _pFileToSet = (&objFileEntry);
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = N51FS_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_EntryNext_4 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileOpen_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileOpen(U8, U32) */
extern MS_BOOL g_CppTest_Stub_N51FS_File_OpenFileRecord_Return;
void TestSuite_msAPI_N51FS_test_N51FS_FileOpen_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = INVALID_FILE_HANDLE;
    /* Initializing argument 2 (mfr) */ 
    U32 _mfr  = 0ul;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileOpen(_handleId, _mfr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileOpen_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileOpen_1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileOpen(U8, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_FileOpen_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    /* Initializing argument 2 (mfr) */ 
    U32 _mfr  = 0ul;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileOpen(_handleId, _mfr);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileOpen_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileRead_0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_FileRead(U8, U32, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_FileRead_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    /* Initializing argument 2 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 3 (len) */ 
    U32 _len  = 0ul;
    {
        /* Tested function call */
        U32 _return  = N51FS_FileRead(_handleId, _MIUAddr, _len);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0ul, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileRead_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileRead_1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_FileRead(U8, U32, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_FileRead_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    /* Initializing argument 2 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 3 (len) */ 
    U32 _len  = 1;
    {
        /* Tested function call */
        U32 _return  = N51FS_FileRead(_handleId, _MIUAddr, _len);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileRead_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileRead_2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 N51FS_FileRead(U8, U32, U32) */
void TestSuite_msAPI_N51FS_test_N51FS_FileRead_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    /* Initializing argument 2 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 3 (len) */ 
    U32 _len  = 1;
    {
        /* Tested function call */
        U32 _return  = N51FS_FileRead(_handleId, _MIUAddr, _len);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileRead_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileTell_0 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong N51FS_FileTell(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_FileTell_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = INVALID_FILE_HANDLE;
    {
        /* Tested function call */
        LongLong _return  = N51FS_FileTell(_handleId);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileTell_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileTell_1 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong N51FS_FileTell(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_FileTell_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    {
        /* Tested function call */
        LongLong _return  = N51FS_FileTell(_handleId);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_N51FS_File_GetHandleInfo_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileTell_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileClose */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileClose(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_FileClose()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileClose(_handleId);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileClose */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileLength_0 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong N51FS_FileLength(U8) */
extern MS_BOOL g_CppTest_Stub_LL_assign_Return;
void TestSuite_msAPI_N51FS_test_N51FS_FileLength_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = INVALID_FILE_HANDLE;
    {
        /* Tested function call */
        LongLong _return  = N51FS_FileLength(_handleId);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_LL_assign_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileLength_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileLength_1 */
/* CPPTEST_TEST_CASE_CONTEXT LongLong N51FS_FileLength(U8) */
void TestSuite_msAPI_N51FS_test_N51FS_FileLength_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    {
        /* Tested function call */
        LongLong _return  = N51FS_FileLength(_handleId);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_LL_assign_Return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileLength_1 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileSeek_0 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileSeek(U8, U32, EN_FILE_SEEK_OPTION) */
void TestSuite_msAPI_N51FS_test_N51FS_FileSeek_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = INVALID_FILE_HANDLE;
    /* Initializing argument 2 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing argument 3 (seekOption) */ 
    EN_FILE_SEEK_OPTION _seekOption  = FILE_SEEK_SET;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileSeek(_handleId, _u32Length, _seekOption);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileSeek_0 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileSeek_2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileSeek(U8, U32, EN_FILE_SEEK_OPTION) */
void TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    /* Initializing argument 2 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing argument 3 (seekOption) */ 
    EN_FILE_SEEK_OPTION _seekOption  = FILE_SEEK_SET;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileSeek(_handleId, _u32Length, _seekOption);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileSeek_2 */

/* CPPTEST_TEST_CASE_BEGIN test_N51FS_FileSeek_3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN N51FS_FileSeek(U8, U32, EN_FILE_SEEK_OPTION) */
void TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handleId) */ 
    U8 _handleId  = 0;
    /* Initializing argument 2 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing argument 3 (seekOption) */ 
    EN_FILE_SEEK_OPTION _seekOption  = FILE_SEEK_SET;
    {
        /* Tested function call */
        BOOLEAN _return  = N51FS_FileSeek(_handleId, _u32Length, _seekOption);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_N51FS_FileSeek_3 */
