#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/msAPI_FCtrl.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/msAPI_FCtrl.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_FCtrl);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_CopyFileHandleInfo);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_addPartitionCount);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_GetFileHandleInfo);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_GetFileInodeInfo);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_YES);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_NO);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_IF_enId_equal_INVALID_FILE_HANDLE);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_equal_NULL);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS);//FILE_SYSTEM_TYPE_NONE
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_equal_NULL);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex_end);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_if_pFileSys_equal_NULL);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_N51FS_bResult_equal_true);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_zero);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_1);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_0_DISK_DRIVE_NUM_equal_2);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_RemoveDrivesOnDevice);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_Init_if_no_if_no_for_for);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_StartDevice_if1_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleFree_if_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_if_yes_);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetDrives_for_for);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveByIndex_if_yes_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveCountByPort_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveCountByPort_if_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_if_no_if_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_VolumeLabelGetByDriveIndex_if_yes_while_if_yes_if_yes_while_if_no);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_SetCurrentDirEntryIndex);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetCurrentDirEntryIndex);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetCurrentDirEntryIndex);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetLongNameByFileEntry);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetShortNameByFileEntry);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetSupportMode_ifno_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemSetSupportMode_ifno_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetFileSystemFormatByDriveIndex_ifyes_ifyes);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_FAT16_Format_BPB_ifno_if_ifno);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if);
CPPTEST_TEST(TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_yes();
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_no();
void TestSuite_msAPI_FCtrl_test_FCtrl_CopyFileHandleInfo();
void TestSuite_msAPI_FCtrl_test_FCtrl_addPartitionCount();
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileHandleInfo();
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileInodeInfo();
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_YES();
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_NO();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_IF_enId_equal_INVALID_FILE_HANDLE();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_equal_NULL();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_equal_NULL();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex_end();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_if_pFileSys_equal_NULL();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_N51FS_bResult_equal_true();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_zero();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_1();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_0_DISK_DRIVE_NUM_equal_2();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_RemoveDrivesOnDevice();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_Init_if_no_if_no_for_for();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_StartDevice_if1_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleFree_if_no();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_if_yes_();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetDrives_for_for();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveByIndex_if_yes_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveCountByPort_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveCountByPort_if_no();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_if_no_if_no();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_VolumeLabelGetByDriveIndex_if_yes_while_if_yes_if_yes_while_if_no();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_SetCurrentDirEntryIndex();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetCurrentDirEntryIndex();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetCurrentDirEntryIndex();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetLongNameByFileEntry();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetShortNameByFileEntry();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetSupportMode_ifno_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemSetSupportMode_ifno_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetFileSystemFormatByDriveIndex_ifyes_ifyes();
void TestSuite_msAPI_FCtrl_test_FAT16_Format_BPB_ifno_if_ifno();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if();
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_FCtrl);

void TestSuite_msAPI_FCtrl_setUp()
{
}

void TestSuite_msAPI_FCtrl_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_GetFileSystemInfo_IF_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 * FCtrl_GetFileSystemInfo(U8) */
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0xff;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 * _return  = FCtrl_GetFileSystemInfo(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(NULL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_GetFileSystemInfo_IF_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_GetFileSystemInfo_IF_no */
/* CPPTEST_TEST_CASE_CONTEXT U32 * FCtrl_GetFileSystemInfo(U8) */
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 * _return  = FCtrl_GetFileSystemInfo(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( 0,_return);
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_GetFileSystemInfo_IF_no */

/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_CopyFileHandleInfo */
/* CPPTEST_TEST_CASE_CONTEXT void FCtrl_CopyFileHandleInfo(FileHandleStruct *, U8) */

extern BOOL g_CppTest_Stub_FCtrl_GetFileHandleInfo_Return;
void TestSuite_msAPI_FCtrl_test_FCtrl_CopyFileHandleInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (handle) */ 
    FileHandleStruct * _handle  = 0 ;
    /* Initializing argument 2 (HandleNo) */ 
    U8 _HandleNo  = 0;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
    	FCtrl_CopyFileHandleInfo(_handle, _HandleNo);
        /* Post-condition check */
    	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, g_CppTest_Stub_FCtrl_GetFileHandleInfo_Return);
    	//CPPTEST_ASSERT_MEM_BUFFER_EQUAL("\000",_PartitionStatus,1);
        //CPPTEST_POST_CONDITION_PTR("FileHandleStruct * _handle ", ( _handle ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_CopyFileHandleInfo */

/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_addPartitionCount */
/* CPPTEST_TEST_CASE_CONTEXT void FCtrl_addPartitionCount(U8, U32 *) */
void TestSuite_msAPI_FCtrl_test_FCtrl_addPartitionCount()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8PartitionCount) */ 
    U8 _u8PartitionCount  = 0;
    U32 temp = 0;
    /* Initializing argument 2 (PartitionStatus) */ 
    U32 * _PartitionStatus  = &temp ;
    {
        /* Tested function call */
        FCtrl_addPartitionCount(_u8PartitionCount, _PartitionStatus);
        /* Post-condition check */
        CPPTEST_ASSERT_MEM_BUFFER_EQUAL("\000",_PartitionStatus,1);
        //CPPTEST_POST_CONDITION_PTR("U32 * _PartitionStatus ", ( _PartitionStatus ));
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_addPartitionCount */

/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_GetFileHandleInfo */
/* CPPTEST_TEST_CASE_CONTEXT FileHandleStruct * FCtrl_GetFileHandleInfo(U8) */
extern BOOL btest_FCtrl_GetFileHandleInfo_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileHandleInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleID) */ 
    U8 _u8FileHandleID  = 0;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        FileHandleStruct * _return  = FCtrl_GetFileHandleInfo(_u8FileHandleID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,btest_FCtrl_GetFileHandleInfo_CallmsAPI_FS_GetAddr);
        CPPTEST_ASSERT_UINTEGER_EQUAL( 0,_return);
        //CPPTEST_POST_CONDITION_PTR("FileHandleStruct * _return ", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_GetFileHandleInfo */

/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_GetFileInodeInfo */
/* CPPTEST_TEST_CASE_CONTEXT FileInodeStruct * FCtrl_GetFileInodeInfo(U8) */
extern BOOL btest_FCtrl_GetFileInodeInfo_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFileInodeInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8InodeID) */ 
    U8 _u8InodeID  = 0;
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        FileInodeStruct * _return  = FCtrl_GetFileInodeInfo(_u8InodeID);
        /* Post-condition check */
 //       CPPTEST_POST_CONDITION_PTR("FileInodeStruct * _return ", ( _return ));
 //       CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_GetFileInodeInfo */


/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_GetFatTableCacheInfo_IF_YES */
/* CPPTEST_TEST_CASE_CONTEXT U32 * FCtrl_GetFatTableCacheInfo(U8) */
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_YES()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = INVALID_DRIVE_INDEX;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        U32 * _return  = FCtrl_GetFatTableCacheInfo(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( 0,_return);
        //CPPTEST_POST_CONDITION_PTR("U32 * _return ", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE", ( FILE_FAT_TABLE_CACHE ));
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_GetFatTableCacheInfo_IF_YES */

/* CPPTEST_TEST_CASE_BEGIN test_FCtrl_GetFatTableCacheInfo_IF_NO */
/* CPPTEST_TEST_CASE_CONTEXT U32 * FCtrl_GetFatTableCacheInfo(U8) */
extern BOOL btest_FCtrl_GetFileInodeInfo_CallGetFatTableCacheInfo_IF_NO;
void TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_NO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    {
        /* Tested function call */
        U32 * _return  = FCtrl_GetFatTableCacheInfo(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,btest_FCtrl_GetFileInodeInfo_CallGetFatTableCacheInfo_IF_NO);
        CPPTEST_ASSERT_UINTEGER_EQUAL( 0,_return);
        //CPPTEST_POST_CONDITION_PTR("U32 * _return ", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_FAT_TABLE_CACHE", ( FILE_FAT_TABLE_CACHE ));
    }
}
/* CPPTEST_TEST_CASE_END test_FCtrl_GetFatTableCacheInfo_IF_NO */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryFirst_IF_enId_equal_INVALID_FILE_HANDLE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntryFirst(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_IF_enId_equal_INVALID_FILE_HANDLE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = INVALID_FILE_HANDLE;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryFirst(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryFirst_IF_enId_equal_INVALID_FILE_HANDLE */


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryFirst_pFSEnv_equal_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntryFirst(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_equal_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryFirst(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryFirst_pFSEnv_equal_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntryFirst(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;

    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryFirst(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT */

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */
    U8 _enId  = 0;

    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryFirst(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE,(_return));
    }
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */
    U8 _enId  = 0;

    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryFirst(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE,(_return));
    }
}

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryNext_pFSEnv_equal_NULL */
/* CPPTEST_TEST_CASE_CONTEXT EN_ENTRY_NEXT_RESULT msAPI_FCtrl_EntryNext(U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_equal_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry * _pFileToSet  = 0 ;
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = msAPI_FCtrl_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ENTRY_NEXT_RESULT_ERROR, ( _return ) );
        //CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileToSet ", ( _pFileToSet ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryNext_pFSEnv_equal_NULL */

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT()
{
	/* Pre-condition initialization */
	/* Initializing argument 1 (enId) */
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */
    FileEntry * _pFileToSet  = 0 ;
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = msAPI_FCtrl_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ENTRY_NEXT_RESULT_SUCCESS, ( _return ) );
 //       CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileToSet ", ( _pFileToSet ));
    }
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS()
{
	/* Pre-condition initialization */
	/* Initializing argument 1 (enId) */
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */
    FileEntry * _pFileToSet  = 0 ;
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = msAPI_FCtrl_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ENTRY_NEXT_RESULT_SUCCESS, ( _return ) );
 //       CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileToSet ", ( _pFileToSet ));
    }
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE()
{
	/* Pre-condition initialization */
	/* Initializing argument 1 (enId) */
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileToSet) */
    FileEntry * _pFileToSet  = 0 ;
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = msAPI_FCtrl_EntryNext(_enId, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( ENTRY_NEXT_RESULT_ERROR, ( _return ) );
 //       CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileToSet ", ( _pFileToSet ));
    }
}

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetAvailableDriveIndex */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_GetAvailableDriveIndex(void) */
//extern MSDCtrl_Drive temp;
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex()
{
    /* Pre-condition initialization */
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;


    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 1;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_GetAvailableDriveIndex();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetAvailableDriveIndex */


void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex_end()
{
    /* Pre-condition initialization */
    /* Initializing global variable DRIVE_MEMORY_ADDR */
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_GetAvailableDriveIndex();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(INVALID_DRIVE_INDEX,(_return));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        //CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        //CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_if_pFileSys_equal_NULL()
{
	S8 deviceIndex = 0;
	U8 fsid = 0;
	EN_FILE_SYSTEM_TYPE fsType = 0;
	U8* partitionBytes = NULL;
	U32 logicalBlockAddress = 0;

	BOOLEAN _return  = msAPI_FCtrl_FileSystemInitial(deviceIndex,fsid,fsType,partitionBytes,logicalBlockAddress);
	CPPTEST_ASSERT_UINTEGER_EQUAL(FALSE,(_return));
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true()//fsType==FILE_SYSTEM_TYPE_FAT
{
	S8 deviceIndex = 0;
	U8 fsid = 0;
	EN_FILE_SYSTEM_TYPE fsType = 0;
	U8* partitionBytes = NULL;
	U32 logicalBlockAddress = 0;
	fsType=FILE_SYSTEM_TYPE_FAT;

	BOOLEAN _return  = msAPI_FCtrl_FileSystemInitial(deviceIndex,fsid,fsType,partitionBytes,logicalBlockAddress);
	CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE,(_return));
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_N51FS_bResult_equal_true()//fsType==FILE_SYSTEM_TYPE_FAT
{
	S8 deviceIndex = 0;
	U8 fsid = 0;
	EN_FILE_SYSTEM_TYPE fsType = 0;
	U8* partitionBytes = NULL;
	U32 logicalBlockAddress = 0;
	fsType=FILE_SYSTEM_TYPE_N51FS;

	BOOLEAN _return  = msAPI_FCtrl_FileSystemInitial(deviceIndex,fsid,fsType,partitionBytes,logicalBlockAddress);
	CPPTEST_ASSERT_UINTEGER_EQUAL(TRUE,(_return));
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_MountDrive_drvCount_equal_zero */
/* CPPTEST_TEST_CASE_CONTEXT EN_DRIVE_INITIAL_STATUS msAPI_FCtrl_MountDrive(U8, EN_FILE_SYSTEM_TYPE, U8 *, U32, U8, U32, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_zero()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    U8 _deviceIndex  = 0;
    /* Initializing argument 2 (fsType) */ 
    EN_FILE_SYSTEM_TYPE _fsType  = FILE_SYSTEM_TYPE_NONE;
    /* Initializing argument 3 (partitionBytes) */ 
    U8 * _partitionBytes  = 0 ;
    /* Initializing argument 4 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 5 (partitionNo) */ 
    U8 _partitionNo  = 0;
    /* Initializing argument 6 (u32MBRLogicBlockAddress) */ 
    U32 _u32MBRLogicBlockAddress  = 0ul;
    /* Initializing argument 7 (u8IndexInMBR) */ 
    U8 _u8IndexInMBR  = 0;
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        EN_DRIVE_INITIAL_STATUS _return  = msAPI_FCtrl_MountDrive(_deviceIndex, _fsType, _partitionBytes, _logicalBlockAddress, _partitionNo, _u32MBRLogicBlockAddress, _u8IndexInMBR);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DRIVE_INITIAL_STATUS_NO_SLOT, ( _return ) )
  /*      CPPTEST_POST_CONDITION_PTR("U8 * _partitionBytes ", ( _partitionBytes ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_MountDrive_drvCount_equal_zero */

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */
    U8 _deviceIndex  = 0;
    /* Initializing argument 2 (fsType) */
    EN_FILE_SYSTEM_TYPE _fsType  = FILE_SYSTEM_TYPE_NONE;
    /* Initializing argument 3 (partitionBytes) */
    U8 * _partitionBytes  = 0 ;
    /* Initializing argument 4 (logicalBlockAddress) */
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 5 (partitionNo) */
    U8 _partitionNo  = 0;
    /* Initializing argument 6 (u32MBRLogicBlockAddress) */
    U32 _u32MBRLogicBlockAddress  = 0ul;
    /* Initializing argument 7 (u8IndexInMBR) */
    U8 _u8IndexInMBR  = 0;
    /* Initializing global variable drvCount */
    {
         drvCount  = 1;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        EN_DRIVE_INITIAL_STATUS _return  = msAPI_FCtrl_MountDrive(_deviceIndex, _fsType, _partitionBytes, _logicalBlockAddress, _partitionNo, _u32MBRLogicBlockAddress, _u8IndexInMBR);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DRIVE_INITIAL_STATUS_MOUNTED_ALREADY, ( _return ) )
  /*      CPPTEST_POST_CONDITION_PTR("U8 * _partitionBytes ", ( _partitionBytes ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));*/
    }
}

void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_0_DISK_DRIVE_NUM_equal_2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */
    U8 _deviceIndex  = 0;
    /* Initializing argument 2 (fsType) */
    EN_FILE_SYSTEM_TYPE _fsType  = FILE_SYSTEM_TYPE_NONE;
    /* Initializing argument 3 (partitionBytes) */
    U8 * _partitionBytes  = 0 ;
    /* Initializing argument 4 (logicalBlockAddress) */
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 5 (partitionNo) */
    U8 _partitionNo  = 0;
    /* Initializing argument 6 (u32MBRLogicBlockAddress) */
    U32 _u32MBRLogicBlockAddress  = 0ul;
    /* Initializing argument 7 (u8IndexInMBR) */
    U8 _u8IndexInMBR  = 0;
    /* Initializing global variable drvCount */
    {
         drvCount  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */
    {
         DISK_DRIVE_NUM  = 2;
    }
    {
        /* Tested function call */
        EN_DRIVE_INITIAL_STATUS _return  = msAPI_FCtrl_MountDrive(_deviceIndex, _fsType, _partitionBytes, _logicalBlockAddress, _partitionNo, _u32MBRLogicBlockAddress, _u8IndexInMBR);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( DRIVE_INITIAL_STATUS_NO_SLOT, ( _return ) )
  /*      CPPTEST_POST_CONDITION_PTR("U8 * _partitionBytes ", ( _partitionBytes ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));*/
    }
}

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_UnmountDrivesOnDevice(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    U8 _deviceIndex  = 0;
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 1;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 1;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_UnmountDrivesOnDevice(_deviceIndex);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_RemoveDrivesOnDevice */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_RemoveDrivesOnDevice(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_RemoveDrivesOnDevice()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    U8 _deviceIndex  = 0;
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_RemoveDrivesOnDevice(_deviceIndex);
        /* Post-condition check */
  //      CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
  //      CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
  //      CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_RemoveDrivesOnDevice */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_Init_if_no_if_no_for_for */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_Init(void) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_Init_if_no_if_no_for_for()
{
    /* Pre-condition initialization */
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 1ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 20;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_Init();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_Init_if_no_if_no_for_for */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_StartDevice_if1_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_StartDevice(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_StartDevice_if1_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    U8 _deviceIndex  = 0;
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_StartDevice(_deviceIndex);
        /* Post-condition check */

		CPPTEST_ASSERT_EQUAL(DEVICE_START_STATUS_STARTED_ALREADY,(_return));
  /*      CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_StartDevice_if1_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_LoadPartitionsOnDevice(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    U8 _deviceIndex  = 0;
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_LoadPartitionsOnDevice(_deviceIndex);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(0,(_return));
  /*      CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_ActiveDevice(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    U8 _deviceIndex  = 0;
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
  //  	U8 PartitionCount = 1 ;
        /* Tested function call */
       BOOLEAN _return  = msAPI_FCtrl_ActiveDevice(_deviceIndex);
        /* Post-condition check */
 /*        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_FileSystemGetByID(U8, void *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileSysID) */ 
    U8 _u8FileSysID  = 0;
    /* Initializing argument 2 (pFStruct) */ 
    void * _pFStruct  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_FileSystemGetByID(_u8FileSysID, _pFStruct);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
   /*     CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("void * _pFStruct ", ( _pFStruct ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_FileHandleCreate(void *, FileEntry *, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileSys) */ 
    void * _pFileSys  = 0 ;
    U8 tmp[2] ;//= FILE_SYSTEM_TYPE_FAT - 1;
    tmp[1] = FILE_SYSTEM_TYPE_FAT;
    _pFileSys = &tmp;
    /* Initializing argument 2 (pFileEntry) */ 
    FileEntry * _pFileEntry  = 0 ;FileEntry fileEntry;
    _pFileEntry = &fileEntry;
    /* Initializing argument 3 (u8OpenMode) */ 
    U8 _u8OpenMode  = 0;
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 1;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_FileHandleCreate(_pFileSys, _pFileEntry, _u8OpenMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,(_return));
  /*      CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("void * _pFileSys ", ( _pFileSys ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileEntry ", ( _pFileEntry ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileHandleFree_if_no */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_FileHandleFree(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleFree_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_FileHandleFree(_u8HandleNo);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileHandleFree_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryChange(U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileEntry) */ 
    FileEntry tmp;
    FileEntry * _pFileEntry  = &tmp ;
    _pFileEntry->EntryType = ENTRY_TYPE_DIR_DOTDOT;

    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryChange(_enId, _pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileEntry ", ( _pFileEntry ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryChangeToContained(U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pFileEntry) */ 
    FileEntry * _pFileEntry  = 0 ;
    FileEntry tmp;
    tmp.EntryType = ENTRY_TYPE_FILE;
    _pFileEntry = &tmp;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryChangeToContained(_enId, _pFileEntry);
        CPPTEST_ASSERT_EQUAL(0,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileEntry ", ( _pFileEntry ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_FileOpen(const FileEntry *, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry tmp;
	tmp.EntryType=ENTRY_TYPE_FILE;
    const FileEntry * _pFileEntry  = &tmp ;
    /* Initializing argument 2 (u8OpenMode) */ 
    U8 _u8OpenMode  = OPEN_MODE_FAST_FOR_READ;
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_FileOpen(_pFileEntry, _u8OpenMode);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT EN_FILE_CLOSE_RESULT msAPI_FCtrl_FileClose(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 1;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        EN_FILE_CLOSE_RESULT _return  = msAPI_FCtrl_FileClose(_u8HandleNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FILE_CLOSE_RESULT_SUCCESS,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_FileRead(U8, U32, U32) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing argument 2 (u32Buffer) */ 
    U32 _u32Buffer  = 0ul;
    /* Initializing argument 3 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_FileRead(_u8HandleNo, _u32Buffer, _u32Length);
        CPPTEST_ASSERT_EQUAL(1,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_FileRead2(U8, U32, U32) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 1;
    /* Initializing argument 2 (u32VABuffer) */ 
    U32 _u32VABuffer  = 0ul;
    /* Initializing argument 3 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_FileRead2(_u8HandleNo, _u32VABuffer, _u32Length);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileSeek_if_yes_ */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_FileSeek(U8, U32, EN_FILE_SEEK_OPTION) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_if_yes_()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 1;
    /* Initializing argument 2 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing argument 3 (option) */ 
    EN_FILE_SEEK_OPTION _option  = FILE_SEEK_SET;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_FileSeek(_u8HandleNo, _u32Length, _option);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileSeek_if_yes_ */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_FileTell(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 1;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 2;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_FileTell(_u8HandleNo);
        CPPTEST_ASSERT_EQUAL(1,(_return));

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_FileLength(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 1;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 2;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_FileLength(_u8HandleNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryChangeToRoot(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentID) */ 
    U8 _environmentID  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryChangeToRoot(_environmentID);
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_EntryGetCurrentName(U8, U32, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 0;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_EntryGetCurrentName(_enId, _MIUAddr, _charLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_ResetDrives_for_for */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_ResetDrives(void) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetDrives_for_for()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_LocalLoopIndex */ 
    {
         g_LocalLoopIndex  = 0;
    }
    /* Initializing global variable drvCount */ 
    {
         drvCount  = 0;
    }
    /* Initializing global variable g_LocalDrive */ 
    {
         g_LocalDrive.DriveIndex  = 0;
         g_LocalDrive.DeviceIndex  = 0;
         g_LocalDrive.FileSystemType  = FILE_SYSTEM_TYPE_NONE;
         g_LocalDrive.PartitionNo  = 0;
         g_LocalDrive.LBA  = 0ul;
         g_LocalDrive.u32MBRLogicBlockAddress  = 0ul;
         g_LocalDrive.u8IndexInMBR  = 0;
    }
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 1;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_ResetDrives();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 g_LocalLoopIndex", ( g_LocalLoopIndex ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 drvCount", ( drvCount ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 g_LocalDrive.DriveIndex", ( g_LocalDrive.DriveIndex ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 g_LocalDrive.DeviceIndex", ( g_LocalDrive.DeviceIndex ));
        CPPTEST_ASSERT_EQUAL( FILE_SYSTEM_TYPE_NONE, ( g_LocalDrive.FileSystemType ) )
        CPPTEST_POST_CONDITION_UINTEGER("U8 g_LocalDrive.PartitionNo", ( g_LocalDrive.PartitionNo ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 g_LocalDrive.LBA", ( g_LocalDrive.LBA ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 g_LocalDrive.u32MBRLogicBlockAddress", ( g_LocalDrive.u32MBRLogicBlockAddress ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 g_LocalDrive.u8IndexInMBR", ( g_LocalDrive.u8IndexInMBR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_ResetDrives_for_for */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetDriveByIndex_if_yes_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_GetDriveByIndex(U8, MSDCtrl_Drive *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveByIndex_if_yes_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (driveID) */ 
    U8 _driveID  = 1;
    /* Initializing argument 2 (pDrive) */ 
    MSDCtrl_Drive tmp;
    tmp.DriveIndex = 1;
    MSDCtrl_Drive * _pDrive  = &tmp ;
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 2;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_GetDriveByIndex(_driveID, _pDrive);
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetDriveByIndex_if_yes_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetDriveCountByPort_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_GetDriveCountByPort(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveCountByPort_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (port) */ 
    U8 _port  = 0;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_GetDriveCountByPort(_port);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetDriveCountByPort_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetDriveCountByPort_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_GetDriveCountByPort(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveCountByPort_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (port) */ 
    U8 _port  = 10;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_GetDriveCountByPort(_port);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0xff,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetDriveCountByPort_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntryIsCurrentNameShortNameOnly(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryIsCurrentNameShortNameOnly(_enId);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_FileDelete(FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry tmp;
	tmp.EntryType = ENTRY_TYPE_FILE;
	tmp.EnvironmentID = 0;
    FileEntry * _pFileEntry  = &tmp ;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_FileDelete(_pFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));
  //      CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
   //     CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileEntry ", ( _pFileEntry ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryGetDOTDOT(U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry tmp;
    FileEntry * _pFileToSet  = &tmp ;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryGetDOTDOT(_environmentId, _pFileToSet);
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
        /* Post-condition check */
 /*       CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileToSet ", ( _pFileToSet ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_ENVIRONMENT_NUM", ( FS_ENVIRONMENT_NUM ));*/
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryGetDOT(U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry tmp;
    FileEntry * _pFileToSet  = &tmp ;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryGetDOT(_environmentId, _pFileToSet);
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryIsCurrentRoot(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (environmentId) */ 
    U8 _environmentId  = 0;

    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryIsCurrentRoot(_environmentId);
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_if_no_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_if_no_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex(_u8DriveIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_if_no_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New(_u8DriveIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));
   //     CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
   //     CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_VolumeLabelGetByDriveIndex_if_yes_while_if_yes_if_yes_while_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_VolumeLabelGetByDriveIndex(U8, U16 *, U8, BOOLEAN *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_VolumeLabelGetByDriveIndex_if_yes_while_if_yes_if_yes_while_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing argument 2 (VolLabName) */ 
    U16 u16_VolLabName[2];
    U16 * _VolLabName  = u16_VolLabName ;
    /* Initializing argument 3 (VolLabNameLen) */ 
    U8 _VolLabNameLen  = 0;
    /* Initializing argument 4 (pbIsUnicode) */ 
    BOOLEAN tmp;
    BOOLEAN * _pbIsUnicode  = &tmp ;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_VolumeLabelGetByDriveIndex(_u8DriveIndex, _VolLabName, _VolLabNameLen, _pbIsUnicode);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(0,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U16 * _VolLabName ", ( _VolLabName ));
        CPPTEST_POST_CONDITION_PTR("BOOLEAN * _pbIsUnicode ", ( _pbIsUnicode ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_VolumeLabelGetByDriveIndex_if_yes_while_if_yes_if_yes_while_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex(_u8DriveIndex);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntrySearchByName(U8, U16 *, U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnId) */ 
    U8 _u8EnId  = 0;
    /* Initializing argument 2 (pu16FileNameToFind) */ 
    U16 tmp[1] = {0xffff};
    U16 * _pu16FileNameToFind  = tmp ;
    /* Initializing argument 3 (u8FileNameToFindLen) */ 
    U8 _u8FileNameToFindLen  = 1;
    /* Initializing argument 4 (pEntryToSet) */ 
    FileEntry * _pEntryToSet  = 0 ;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntrySearchByName(_u8EnId, _pu16FileNameToFind, _u8FileNameToFindLen, _pEntryToSet);
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U16 * _pu16FileNameToFind ", ( _pu16FileNameToFind ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntryToSet ", ( _pEntryToSet ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntrySearchByShortName(U8, U8 *, U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnId) */ 
    U8 _u8EnId  = 0;
    /* Initializing argument 2 (pu8FileNameToFind) */ 
    U8 tmp[1] = {0xffff};
    U8 * _pu8FileNameToFind  = tmp ;
    /* Initializing argument 3 (u8FileNameToFindLen) */ 
    U8 _u8FileNameToFindLen  = 1;
    /* Initializing argument 4 (pEntryToSet) */ 
    FileEntry * _pEntryToSet  = 0 ;
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntrySearchByShortName(_u8EnId, _pu8FileNameToFind, _u8FileNameToFindLen, _pEntryToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8FileNameToFind ", ( _pu8FileNameToFind ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntryToSet ", ( _pEntryToSet ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_SetCurrentDirEntryIndex */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_SetCurrentDirEntryIndex(S32) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_SetCurrentDirEntryIndex()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (s32CurrentDirEntryIndex) */ 
    S32 _s32CurrentDirEntryIndex  = 0L;
    /* Initializing global variable g_s32CurrentDirEntryIndex */ 
    {
         g_s32CurrentDirEntryIndex  = 0L;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_SetCurrentDirEntryIndex(_s32CurrentDirEntryIndex);
        CPPTEST_ASSERT_EQUAL(g_s32CurrentDirEntryIndex,(_s32CurrentDirEntryIndex));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER("S32 g_s32CurrentDirEntryIndex", ( g_s32CurrentDirEntryIndex ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_SetCurrentDirEntryIndex */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetCurrentDirEntryIndex */
/* CPPTEST_TEST_CASE_CONTEXT S32 msAPI_FCtrl_GetCurrentDirEntryIndex(void) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetCurrentDirEntryIndex()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_s32CurrentDirEntryIndex */ 
    {
         g_s32CurrentDirEntryIndex  = 0L;
    }
    {
        /* Tested function call */
        S32 _return  = msAPI_FCtrl_GetCurrentDirEntryIndex();
        CPPTEST_ASSERT_EQUAL(g_s32CurrentDirEntryIndex,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER("S32 _return", ( _return ));
        CPPTEST_POST_CONDITION_INTEGER("S32 g_s32CurrentDirEntryIndex", ( g_s32CurrentDirEntryIndex ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetCurrentDirEntryIndex */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_ResetCurrentDirEntryIndex */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_ResetCurrentDirEntryIndex(void) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetCurrentDirEntryIndex()
{
    /* Pre-condition initialization */
    /* Initializing global variable g_s32CurrentDirEntryIndex */ 
    {
         g_s32CurrentDirEntryIndex  = 0L;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_ResetCurrentDirEntryIndex();
        CPPTEST_ASSERT_EQUAL(-1,(g_s32CurrentDirEntryIndex));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_INTEGER("S32 g_s32CurrentDirEntryIndex", ( g_s32CurrentDirEntryIndex ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_ResetCurrentDirEntryIndex */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry(U8, U8 *, U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnId) */ 
    U8 _u8EnId  = 0;
    /* Initializing argument 2 (pu8FileNameToFind) */ 
    U8 tmp[1] = {0xffff};
    U8 * _pu8FileNameToFind  = tmp ;

    /* Initializing argument 3 (u8FileNameToFindLen) */ 
    U8 _u8FileNameToFindLen  = 1;
    /* Initializing argument 4 (pEntryToSet) */ 
    FileEntry * _pEntryToSet  = 0 ;
    /* Initializing global variable g_s32CurrentDirEntryIndex */ 
    {
         g_s32CurrentDirEntryIndex  = 0L;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry(_u8EnId, _pu8FileNameToFind, _u8FileNameToFindLen, _pEntryToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U8 * _pu8FileNameToFind ", ( _pu8FileNameToFind ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntryToSet ", ( _pEntryToSet ));
        CPPTEST_POST_CONDITION_INTEGER("S32 g_s32CurrentDirEntryIndex", ( g_s32CurrentDirEntryIndex ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_GetNameByFileEntry(U8, FileEntry *, U32, U8, BOOLEAN *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pEntry) */ 
    FileEntry * _pEntry  = 0 ;
    /* Initializing argument 3 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 4 (charLen) */ 
    U8 _charLen  = 0;
    /* Initializing argument 5 (bIsLongName) */ 
    BOOLEAN * _bIsLongName  = 0 ;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_GetNameByFileEntry(_enId, _pEntry, _MIUAddr, _charLen, _bIsLongName);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntry ", ( _pEntry ));
        CPPTEST_POST_CONDITION_PTR("BOOLEAN * _bIsLongName ", ( _bIsLongName ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryGetLongNameByFileEntry */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_EntryGetLongNameByFileEntry(U8, FileEntry *, U32, U8, BOOLEAN *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetLongNameByFileEntry()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pEntry) */ 
    FileEntry * _pEntry  = 0 ;
    /* Initializing argument 3 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 4 (charLen) */ 
    U8 _charLen  = 0;
    /* Initializing argument 5 (pbShortNameOnly) */ 
    BOOLEAN tmp;
    BOOLEAN * _pbShortNameOnly  = &tmp ;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_EntryGetLongNameByFileEntry(_enId, _pEntry, _MIUAddr, _charLen, _pbShortNameOnly);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntry ", ( _pEntry ));
        CPPTEST_POST_CONDITION_PTR("BOOLEAN * _pbShortNameOnly ", ( _pbShortNameOnly ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryGetLongNameByFileEntry */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryGetShortNameByFileEntry */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_EntryGetShortNameByFileEntry(U8, FileEntry *, U32, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetShortNameByFileEntry()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enId) */ 
    U8 _enId  = 0;
    /* Initializing argument 2 (pEntry) */ 
    FileEntry * _pEntry  = 0 ;
    /* Initializing argument 3 (MIUAddr) */ 
    U32 _MIUAddr  = 0ul;
    /* Initializing argument 4 (charLen) */ 
    U8 _charLen  = 0;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_EntryGetShortNameByFileEntry(_enId, _pEntry, _MIUAddr, _charLen);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntry ", ( _pEntry ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryGetShortNameByFileEntry */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_FCtrl_FileLength_LongLong(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0xFF;
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_FCtrl_FileLength_LongLong(_u8HandleNo);
        CPPTEST_ASSERT_EQUAL(1,(_return.Lo));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT LongLong msAPI_FCtrl_FileTell_LongLong(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0xff;
    }
    {
        /* Tested function call */
        LongLong _return  = msAPI_FCtrl_FileTell_LongLong(_u8HandleNo);
        CPPTEST_ASSERT_EQUAL(1,(_return.Lo));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Hi", ( _return.Hi ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return.Lo", ( _return.Lo ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_FileSeek_LongLong(U8, LongLong, EN_FILE_SEEK_OPTION) */
extern MS_BOOL g_CppTest_Stub_LL_iszero_Return;
extern MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileSeek;
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing argument 2 (u32Length) */ 
    LongLong _u32Length;
    _u32Length.Hi = 0;
    _u32Length.Lo = 0;
    /* Initializing argument 3 (option) */ 
    EN_FILE_SEEK_OPTION _option  = FILE_SEEK_SET;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_FileSeek_LongLong(_u8HandleNo, _u32Length, _option);

        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_LL_iszero_Return ));
        CPPTEST_ASSERT_EQUAL(TRUE, ( g_CppTest_Stub_msAPI_FCtrl_FileSeek ));
        CPPTEST_ASSERT_EQUAL(FALSE, (_return));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileSystemGetSupportMode_ifno_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_FileSystemGetSupportMode(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetSupportMode_ifno_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileSysID) */ 
    U8 _u8FileSysID  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 1;
    }
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_FileSystemGetSupportMode(_u8FileSysID);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileSystemGetSupportMode_ifno_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileSystemSetSupportMode_ifno_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_FCtrl_FileSystemSetSupportMode(U8, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemSetSupportMode_ifno_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileSysID) */ 
    U8 _u8FileSysID  = 0;
    /* Initializing argument 2 (mode) */ 
    U8 _mode  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 1;
    }
    {
        /* Tested function call */
        msAPI_FCtrl_FileSystemSetSupportMode(_u8FileSysID, _mode);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileSystemSetSupportMode_ifno_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_FileCreate_WithoutNameChecking(U8, U16 *, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8enid) */ 
    U8 _u8enid  = 0;
    /* Initializing argument 2 (pu16LongName) */ 
    U16 * _pu16LongName  = 0 ;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 0;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_FileCreate_WithoutNameChecking(_u8enid, _pu16LongName, _charLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(1,(_return));
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U16 * _pu16LongName ", ( _pu16LongName ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_FileCreate(U8, U16 *, U8, EN_CREATE_MODE) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8enid) */ 
    U8 _u8enid  = 0;
    /* Initializing argument 2 (pu16LongName) */ 
    U16 * _pu16LongName  = 0 ;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 1;
    /* Initializing argument 4 (createMode) */ 
    EN_CREATE_MODE _createMode  = CREATE_MODE_NEW_FORCE;
    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_FileCreate(_u8enid, _pu16LongName, _charLen, _createMode);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U16 * _pu16LongName ", ( _pu16LongName ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes */
/* CPPTEST_TEST_CASE_CONTEXT U8 msAPI_FCtrl_DirectoryOpen(FileEntry *, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pFileEntry) */ 
	FileEntry tmp;
	tmp.EntryType = ENTRY_TYPE_DIR;
    FileEntry * _pFileEntry  = &tmp ;
    /* Initializing argument 2 (u8OpenMode) */ 
    U8 _u8OpenMode  = (U8)OPEN_MODE_FAST_FOR_READ;
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }

    {
        /* Tested function call */
        U8 _return  = msAPI_FCtrl_DirectoryOpen(_pFileEntry, _u8OpenMode);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pFileEntry ", ( _pFileEntry ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_DirectoryCreate(U8, U16 *, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8enid) */ 
    U8 _u8enid  = 0;
    /* Initializing argument 2 (pu16LongName) */ 
    U16 * _pu16LongName  = 0 ;
    /* Initializing argument 3 (charLen) */ 
    U8 _charLen  = 1;
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 0;
    }
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_DirectoryCreate(_u8enid, _pu16LongName, _charLen);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U16 * _pu16LongName ", ( _pu16LongName ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 FS_FILE_HANDLE_NUM", ( FS_FILE_HANDLE_NUM ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_FCtrl_FileWrite(U8, U32, U32) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing argument 2 (u32Buffer) */ 
    U32 _u32Buffer  = 0ul;
    /* Initializing argument 3 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = msAPI_FCtrl_FileWrite(_u8HandleNo, _u32Buffer, _u32Length);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U32 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_EntryGetByHandle(U8, FileEntry *) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8HandleNo) */ 
    U8 _u8HandleNo  = 0;
    /* Initializing argument 2 (pEntryToSet) */ 
    FileEntry * _pEntryToSet  = 0 ;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_EntryGetByHandle(_u8HandleNo, _pEntryToSet);
        CPPTEST_ASSERT_EQUAL(1,(_return));
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("FileEntry * _pEntryToSet ", ( _pEntryToSet ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_HANDLE_POOL", ( FILE_HANDLE_POOL ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_INODE_POOL", ( FILE_INODE_POOL ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_GetFileSystemFormatByDriveIndex_ifyes_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT EN_FILE_SYSTEM_FORMAT msAPI_FCtrl_GetFileSystemFormatByDriveIndex(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetFileSystemFormatByDriveIndex_ifyes_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing global variable FILE_SYSTEM_MOUNTED_ADDR */ 
    {
         FILE_SYSTEM_MOUNTED_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        EN_FILE_SYSTEM_FORMAT _return  = msAPI_FCtrl_GetFileSystemFormatByDriveIndex(_u8DriveIndex);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FILE_SYSTEM_FORMAT_FAT12, ( _return ) );
        CPPTEST_POST_CONDITION_UINTEGER("U32 FILE_SYSTEM_MOUNTED_ADDR", ( FILE_SYSTEM_MOUNTED_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_GetFileSystemFormatByDriveIndex_ifyes_ifyes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT16_Format_BPB_ifno_if_ifno */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT16_Format_BPB(U8, U32, U32, U8, U32 *) */
void TestSuite_msAPI_FCtrl_test_FAT16_Format_BPB_ifno_if_ifno()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8DeviceIndex) */ 
    U8 _u8DeviceIndex  = 0;
    /* Initializing argument 2 (u32RelativeSector) */ 
    U32 _u32RelativeSector  = 0ul;
    /* Initializing argument 3 (u32TotalSec) */ 
    U32 _u32TotalSec  = 0ul;
    /* Initializing argument 4 (u8SecPerCluster) */ 
    U8 _u8SecPerCluster  = 2;
    /* Initializing argument 5 (u32FATSize) */ 
    U32 tmp = 0;
    U32 * _u32FATSize  = &tmp ;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT16_Format_BPB(_u8DeviceIndex, _u32RelativeSector, _u32TotalSec, _u8SecPerCluster, _u32FATSize);
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_PTR("U32 * _u32FATSize ", ( _u32FATSize ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_FAT16_Format_BPB_ifno_if_ifno */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_FAT16_Format(U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (driveNo) */ 
    U8 _driveNo  = 0;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_FAT16_Format(_driveNo);
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 USB_IO_TEMP_ADDR", ( USB_IO_TEMP_ADDR ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN msAPI_FCtrl_FormatPartitionByDriveIndex(EN_FORMAT_MODE, U8) */
void TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (formatMode) */ 
    EN_FORMAT_MODE _formatMode  = FORMAT_FAST;
    /* Initializing argument 2 (u8DriveIndex) */ 
    U8 _u8DriveIndex  = 0;
    /* Initializing global variable DRIVE_MEMORY_ADDR */ 
    {
         DRIVE_MEMORY_ADDR  = 0ul;
    }
    /* Initializing global variable DISK_DRIVE_NUM */ 
    {
         DISK_DRIVE_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = msAPI_FCtrl_FormatPartitionByDriveIndex(_formatMode, _u8DriveIndex);
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_POST_CONDITION_UINTEGER("U32 DRIVE_MEMORY_ADDR", ( DRIVE_MEMORY_ADDR ));
        CPPTEST_POST_CONDITION_UINTEGER("U8 DISK_DRIVE_NUM", ( DISK_DRIVE_NUM ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes */
