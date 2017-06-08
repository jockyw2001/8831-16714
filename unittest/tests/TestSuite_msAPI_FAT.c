#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/n51fs/msAPI_FAT.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/n51fs/msAPI_FAT.c");

CPPTEST_TEST_SUITE(TestSuite_msAPI_FAT);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_GetAddr_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_File_GetHandleInfo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_no);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_GetMIUAddress_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_DirEntryIterator_GetInfo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_File_GetHandleClusterChainInfo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_no);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_no);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_no);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_default);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0x000);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0x002_and_u32ClusterNo_le_u32FatTotalClusterNo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0xff7);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0xff8);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_break);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0x0000);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0x0002_and_u32ClusterNo_le_u32FatTotalClusterNo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0xfff7);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0xfff8);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_break);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0x00000000);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x00000002_and_u32ClusterNo_le_u32FatTotalClusterNo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0xfffffff7);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x0ffffff8);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_break);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_default);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT12);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT16);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT32);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetType_if_NOT_SUPPORT);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_NOT_SUPPORT);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT32_and_if_u32FATTotalClusterNo_gt_0xFFFFFF7);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_eq_FAT_TYPE_NOT_SUPPORT);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_ne_FAT_TYPE_NOT_SUPPORT);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_PartitionTableRead_if_u8partitionBytes_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_PartitionTableRead_if_u8partitionBytes_ne_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if1_msAPI_MSDCtrl_SectorRead_FALSE);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if1_FileSystemID_eq_INVALID_DRIVE_INDEX);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if2_msAPI_MSDCtrl_SectorRead_eq_FALSE);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_RootDirectroyInfo_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_RootDirectroyInfo_if_no);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_eq_0_and_if_yes);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_ne_0_and_lt_2);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirEntryNext_if_pFS_Env_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirectoryChange_if_pFS_Env_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileOpen_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_GetNextCluster_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileRead_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileSeek_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirectoryGetParentClusterNo);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_EntryIsCurrentNameShortOnly);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirEntryWriteDirect_if_return_first_FALSE);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileWrite_if_pFATInode_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_InitialFileSystem_if_FAT_PartitionTableRead_return_false);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirectoryEntrySave_end);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_DirectoryEntryGetName_end);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_HandlePostCreate_end);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FileClose_return_true);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed);
CPPTEST_TEST(TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_msAPI_FAT_test_FAT_GetAddr_if_yes();
void TestSuite_msAPI_FAT_test_FAT_File_GetHandleInfo();
void TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_yes();
void TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_no();
void TestSuite_msAPI_FAT_test_FAT_GetMIUAddress_if_yes();
void TestSuite_msAPI_FAT_test_DirEntryIterator_GetInfo();
void TestSuite_msAPI_FAT_test_FAT_File_GetHandleClusterChainInfo();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_yes();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_no();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_yes();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_no();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_yes();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_no();
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_default();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0x000();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0x002_and_u32ClusterNo_le_u32FatTotalClusterNo();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0xff7();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0xff8();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_break();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0x0000();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0x0002_and_u32ClusterNo_le_u32FatTotalClusterNo();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0xfff7();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0xfff8();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_break();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0x00000000();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x00000002_and_u32ClusterNo_le_u32FatTotalClusterNo();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0xfffffff7();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x0ffffff8();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_break();
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_default();
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT12();
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT16();
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT32();
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_NOT_SUPPORT();
void TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail();
void TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no();
void TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes();
void TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_NOT_SUPPORT();
void TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT32_and_if_u32FATTotalClusterNo_gt_0xFFFFFF7();
void TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12();
void TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_eq_FAT_TYPE_NOT_SUPPORT();
void TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_ne_FAT_TYPE_NOT_SUPPORT();
void TestSuite_msAPI_FAT_test_FAT_PartitionTableRead_if_u8partitionBytes_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_PartitionTableRead_if_u8partitionBytes_ne_NULL();
void TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if1_msAPI_MSDCtrl_SectorRead_FALSE();
void TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9();
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if1_FileSystemID_eq_INVALID_DRIVE_INDEX();
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if2_msAPI_MSDCtrl_SectorRead_eq_FALSE();
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_RootDirectroyInfo_if_yes();
void TestSuite_msAPI_FAT_test_FAT_RootDirectroyInfo_if_no();
void TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_eq_0_and_if_yes();
void TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_ne_0_and_lt_2();
void TestSuite_msAPI_FAT_test_FAT_DirEntryNext_if_pFS_Env_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL();
void TestSuite_msAPI_FAT_test_FAT_DirectoryChange_if_pFS_Env_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FileOpen_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_GetNextCluster_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FileRead_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FileSeek_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_DirectoryGetParentClusterNo();
void TestSuite_msAPI_FAT_test_FAT_EntryIsCurrentNameShortOnly();
void TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NULL();
void TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL();
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE();
void TestSuite_msAPI_FAT_test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL();
void TestSuite_msAPI_FAT_test_FAT_DirEntryWriteDirect_if_return_first_FALSE();
void TestSuite_msAPI_FAT_test_FAT_FileWrite_if_pFATInode_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0();
void TestSuite_msAPI_FAT_test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE();
void TestSuite_msAPI_FAT_test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0();
void TestSuite_msAPI_FAT_test_FAT_InitialFileSystem_if_FAT_PartitionTableRead_return_false();
void TestSuite_msAPI_FAT_test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL();
void TestSuite_msAPI_FAT_test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false();
void TestSuite_msAPI_FAT_test_FAT_DirectoryEntrySave_end();
void TestSuite_msAPI_FAT_test_FAT_DirectoryEntryGetName_end();
void TestSuite_msAPI_FAT_test_FAT_HandlePostCreate_end();
void TestSuite_msAPI_FAT_test_FAT_FileClose_return_true();
void TestSuite_msAPI_FAT_test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed();
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_msAPI_FAT);

void TestSuite_msAPI_FAT_setUp()
{
}

void TestSuite_msAPI_FAT_tearDown()
{
}

#define UT_MSG(x)  //x

/* CPPTEST_TEST_CASE_BEGIN test_FAT_GetAddr_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 * FAT_GetAddr(U8, EN_FAT_XDATA_OPTION) */
extern BOOLEAN gbTest_FAT_GetAddr_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FAT_test_FAT_GetAddr_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentId) */ 
    U8 _u8EnvironmentId  = 0;
    /* Initializing argument 2 (option) */ 
    EN_FAT_XDATA_OPTION _option  = FAT_XDATA_OPTION_ENVIRONMENT;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 5;
    }
    XDataAddr[_u8EnvironmentId][_option] = 0;
    {
        /* Tested function call */
        U32 * _return  = FAT_GetAddr(_u8EnvironmentId, _option);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_GetAddr_CallmsAPI_FS_GetAddr);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_GetAddr_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_File_GetHandleInfo */
/* CPPTEST_TEST_CASE_CONTEXT FAT_FileHandle * FAT_File_GetHandleInfo(U8) */
extern BOOLEAN gbTest_FAT_File_GetHandleInfo_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FAT_test_FAT_File_GetHandleInfo()
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
        FAT_FileHandle * _return  = FAT_File_GetHandleInfo(_u8FileHandleID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_File_GetHandleInfo_CallmsAPI_FS_GetAddr);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_File_GetHandleInfo */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_File_GetInodeFromHandle_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT FAT_FileInode * FAT_File_GetInodeFromHandle(U8) */
extern BOOLEAN gbTest_FAT_File_GetInodeFromHandle_CallFAT_File_GetHandleInfo;
void TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleID) */ 
    U8 _u8FileHandleID  = 0;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    pstFAT_FileHandle->pub_fileheader.InodeID = INVALID_FILE_INODEID;
    {
         FILE_HANDLE_POOL  = pstFAT_FileHandle;
    }
    {
        /* Tested function call */
        FAT_FileInode * _return  = FAT_File_GetInodeFromHandle(_u8FileHandleID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_File_GetInodeFromHandle_CallFAT_File_GetHandleInfo);
        CPPTEST_ASSERT_EQUAL(NULL, _return );
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_File_GetInodeFromHandle_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_File_GetInodeFromHandle_if_no */
/* CPPTEST_TEST_CASE_CONTEXT FAT_FileInode * FAT_File_GetInodeFromHandle(U8) */
extern BOOLEAN gbTest_FAT_File_GetInodeFromHandle_CallFCtrl_GetFileInodeInfo;
void TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleID) */ 
    U8 _u8FileHandleID  = 0;
    /* Initializing global variable FILE_HANDLE_POOL */ 
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    pstFAT_FileHandle->pub_fileheader.InodeID = 0xfe;
    {
         FILE_HANDLE_POOL  = pstFAT_FileHandle;
    }
    {
        /* Tested function call */
        FAT_FileInode * _return  = FAT_File_GetInodeFromHandle(_u8FileHandleID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_File_GetInodeFromHandle_CallFCtrl_GetFileInodeInfo);
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_File_GetInodeFromHandle_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_GetMIUAddress_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_GetMIUAddress(U8, EN_FAT_XDATA_OPTION) */
void TestSuite_msAPI_FAT_test_FAT_GetMIUAddress_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentId) */ 
    U8 _u8EnvironmentId  = 0;
    /* Initializing argument 2 (option) */ 
    EN_FAT_XDATA_OPTION _option  = FAT_XDATA_OPTION_ENVIRONMENT;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 1;
    }
    XDataAddr[_u8EnvironmentId][_option] = 0;
    {
        /* Tested function call */
        U32 _return  = FAT_GetMIUAddress(_u8EnvironmentId, _option);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_GetMIUAddress_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_DirEntryIterator_GetInfo */
/* CPPTEST_TEST_CASE_CONTEXT DirEntryStruct * DirEntryIterator_GetInfo(void) */
void TestSuite_msAPI_FAT_test_DirEntryIterator_GetInfo()
{
    /* Pre-condition initialization */
    /* Initializing global variable FS_u32var1 */ 
    {
         FS_u32var1  = 0ul;
    }
    /* Initializing global variable FS_u16var2 */ 
    {
         FS_u16var2  = 0u;
    }
    {
        /* Tested function call */
        DirEntryStruct * _return  = DirEntryIterator_GetInfo();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_DirEntryIterator_GetInfo */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_File_GetHandleClusterChainInfo */
/* CPPTEST_TEST_CASE_CONTEXT File_ClusterChain * FAT_File_GetHandleClusterChainInfo(U8) */
extern BOOLEAN gbTest_FAT_File_GetHandleClusterChainInfo_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FAT_test_FAT_File_GetHandleClusterChainInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileInodeID) */ 
    U8 _u8FileInodeID  = 0;
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        File_ClusterChain * _return  = FAT_File_GetHandleClusterChainInfo(_u8FileInodeID);
        /* Post-condition check */
        //CPPTEST_ASSERT_EQUAL(0x1000, _return);
        //CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_File_GetHandleClusterChainInfo_CallmsAPI_FS_GetAddr);
        CPPTEST_ASSERT_EQUAL(0x400, _return);//20131204 ryan-zy.huang fixed
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, gbTest_FAT_File_GetHandleClusterChainInfo_CallmsAPI_FS_GetAddr);

    }
}
/* CPPTEST_TEST_CASE_END test_FAT_File_GetHandleClusterChainInfo */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0xffff;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_FAT12;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0xFF7, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0x00;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_FAT12;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        UT_MSG(printf("_return = 0x%x\n", _return));
        CPPTEST_ASSERT_EQUAL(0x00, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT12_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0xfffff;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_FAT16;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        UT_MSG(printf("TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_yes:_return = 0x%x\n", _return););
        CPPTEST_ASSERT_EQUAL(0xFFF7, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0ul;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_FAT16;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0x00, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT16_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0xffffffff;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_FAT32;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        UT_MSG(printf("TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_yes:_return = 0x%x\n", _return););
        CPPTEST_ASSERT_EQUAL(0xFFFFFF7, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_no */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0x00;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_FAT32;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0x00, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_FAT_TYPE_FAT32_if_no */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetMaxClusterNo_case_default */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetMaxClusterNo(U32, EN_FAT_TYPE) */
void TestSuite_msAPI_FAT_test_FAT_FATGetMaxClusterNo_case_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FATSize) */ 
    U32 _u32FATSize  = 0ul;
    /* Initializing argument 2 (FATType) */ 
    EN_FAT_TYPE _FATType  = FAT_TYPE_NOT_SUPPORT;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetMaxClusterNo(_u32FATSize, _FATType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0x00, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetMaxClusterNo_case_default */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0x000 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0x000()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT12;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0ul;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_NOT_USED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0x000 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0x002_and_u32ClusterNo_le_u32FatTotalClusterNo */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0x002_and_u32ClusterNo_le_u32FatTotalClusterNo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT12;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0x010;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x005;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_ALLOCATED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0x002_and_u32ClusterNo_le_u32FatTotalClusterNo */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0xff7 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0xff7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT12;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0xff7;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_DEFECTIVE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_eq_0xff7 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0xff8 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0xff8()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT12;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0xfff;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_FINAL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_if_u32ClusterNo_ge_0xff8 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_break */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_break()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT12;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x01;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_RESERVED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT12_break */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0x0000 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0x0000()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT16;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x0000;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_NOT_USED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0x0000 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0x0002_and_u32ClusterNo_le_u32FatTotalClusterNo */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0x0002_and_u32ClusterNo_le_u32FatTotalClusterNo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT16;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0x0010;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x0002;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_ALLOCATED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0x0002_and_u32ClusterNo_le_u32FatTotalClusterNo */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0xfff7 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0xfff7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT16;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0xfff7;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_DEFECTIVE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_eq_0xfff7 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0xfff8 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0xfff8()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT16;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0xfff8;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_FINAL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_if_u32ClusterNo_ge_0xfff8 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_break */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_break()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT16;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x0001;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_RESERVED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT16_break */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0x00000000 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0x00000000()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT32;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x00000000;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_NOT_USED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0x00000000 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x00000002_and_u32ClusterNo_le_u32FatTotalClusterNo */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x00000002_and_u32ClusterNo_le_u32FatTotalClusterNo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT32;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0x00000010;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x00000002;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_ALLOCATED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x00000002_and_u32ClusterNo_le_u32FatTotalClusterNo */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0xfffffff7 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0xfffffff7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT32;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0xfffffff7;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_DEFECTIVE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_eq_0xfffffff7 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x0ffffff8 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x0ffffff8()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT32;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x0ffffff8;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_FINAL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_if_u32ClusterNo_ge_0x0ffffff8 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_break */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_break()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_FAT32;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0x00000001;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_RESERVED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_FAT_TYPE_FAT32_break */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetClusterStatus_case_default */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetClusterStatus(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetClusterStatus_case_default()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FatType) */ 
    U8 _u8FatType  = FAT_TYPE_NOT_SUPPORT;
    /* Initializing argument 2 (u32FatTotalClusterNo) */ 
    U32 _u32FatTotalClusterNo  = 0ul;
    /* Initializing argument 3 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0ul;
    {
        /* Tested function call */
        U32 _return  = FAT_FATGetClusterStatus(_u8FatType, _u32FatTotalClusterNo, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_RESERVED, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetClusterStatus_case_default */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetType_if_FAT12 */
/* CPPTEST_TEST_CASE_CONTEXT EN_FAT_TYPE FAT_FATGetType(U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT12()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8FileType) */ 
    U8 * _pu8FileType  = "FAT12" ;
    {
        /* Tested function call */
        EN_FAT_TYPE _return  = FAT_FATGetType(_pu8FileType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FAT_TYPE_FAT12, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetType_if_FAT12 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetType_if_FAT16 */
/* CPPTEST_TEST_CASE_CONTEXT EN_FAT_TYPE FAT_FATGetType(U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT16()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8FileType) */ 
    U8 * _pu8FileType  = "FAT16" ;
    {
        /* Tested function call */
        EN_FAT_TYPE _return  = FAT_FATGetType(_pu8FileType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FAT_TYPE_FAT16, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetType_if_FAT16 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetType_if_FAT32 */
/* CPPTEST_TEST_CASE_CONTEXT EN_FAT_TYPE FAT_FATGetType(U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_FAT32()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8FileType) */ 
    U8 * _pu8FileType  = "FAT32" ;
    {
        /* Tested function call */
        EN_FAT_TYPE _return  = FAT_FATGetType(_pu8FileType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FAT_TYPE_FAT32, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetType_if_FAT32 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetType_if_NOT_SUPPORT */
/* CPPTEST_TEST_CASE_CONTEXT EN_FAT_TYPE FAT_FATGetType(U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FATGetType_if_NOT_SUPPORT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pu8FileType) */ 
    U8 * _pu8FileType  = "OTHER" ;
    {
        /* Tested function call */
        EN_FAT_TYPE _return  = FAT_FATGetType(_pu8FileType);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FAT_TYPE_NOT_SUPPORT, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetType_if_NOT_SUPPORT */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureFetch(U8, U32) */
extern BOOLEAN gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead;
void TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */
	FAT_FileSysStruct _pFAT_FileSys;
	memset(&_pFAT_FileSys, 0, sizeof(FAT_FileSysStruct));
	FAT_FileSysStruct *pFAT_FileSys = &_pFAT_FileSys;
	pFAT_FileSys->stBootSector.BPB_BytsPerSec = 1;
    U8 _fsid  = 0;
    /* Initializing argument 2 (u32FATOffsetSectorNo) */ 
    U32 _u32FATOffsetSectorNo  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }


    /* Initializing global variable USB_IO_TEMP_ADDR */
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }

    {
    	FILE_SYSTEM_MOUNTED_ADDR = pFAT_FileSys;
    }

	UT_MSG(printf("FAT_TABLE_CACHE_LEN = 0x%x\npFAT_FileSys->stBootSector.BPB_BytsPerSec = 0x%x\n", FAT_TABLE_CACHE_LEN, pFAT_FileSys->stBootSector.BPB_BytsPerSec););
    UT_MSG(printf("(U8)(FAT_TABLE_CACHE_LEN / u16BytePerSec) = 0x%x\n", (U8)(FAT_TABLE_CACHE_LEN / pFAT_FileSys->stBootSector.BPB_BytsPerSec)););
	{
        /* Tested function call */
        BOOLEAN _return  = FAT_FATStructureFetch(_fsid, _u32FATOffsetSectorNo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);

    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureFetch(U8, U32) */
extern BOOLEAN gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead_Con_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes;
void TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
	FAT_FileSysStruct _pFAT_FileSys;
	memset(&_pFAT_FileSys, 0, sizeof(FAT_FileSysStruct));
	FAT_FileSysStruct *pFAT_FileSys = &_pFAT_FileSys;
	pFAT_FileSys->stBootSector.BPB_BytsPerSec = 1;

    U8 _fsid  = 0;
    /* Initializing argument 2 (u32FATOffsetSectorNo) */ 
    U32 _u32FATOffsetSectorNo  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
    	FILE_SYSTEM_MOUNTED_ADDR = pFAT_FileSys;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATStructureFetch(_fsid, _u32FATOffsetSectorNo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead_Con_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureFetch(U8, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes()
{
    /* Pre-condition initialization */
	FAT_FileSysStruct _pFAT_FileSys;
	memset(&_pFAT_FileSys, 0, sizeof(FAT_FileSysStruct));
	FAT_FileSysStruct *pFAT_FileSys = &_pFAT_FileSys;
	pFAT_FileSys->stBootSector.BPB_BytsPerSec = 1;
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (u32FATOffsetSectorNo) */ 
    U32 _u32FATOffsetSectorNo  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
    	FILE_SYSTEM_MOUNTED_ADDR = pFAT_FileSys;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATStructureFetch(_fsid, _u32FATOffsetSectorNo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_NOT_SUPPORT */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureReadRoot(FAT_FileSysStruct *, U32) */
extern BOOLEAN gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType;
void TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_NOT_SUPPORT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFAT_FileSys) */ 
	FAT_FileSysStruct pstFAT_FileSys;
	memset(&pstFAT_FileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFAT_FileSys  = &pstFAT_FileSys ;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATStructureReadRoot(_pstFAT_FileSys, _logicalBlockAddress);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_NOT_SUPPORT */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT32_and_if_u32FATTotalClusterNo_gt_0xFFFFFF7 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureReadRoot(FAT_FileSysStruct *, U32) */

void TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT32_and_if_u32FATTotalClusterNo_gt_0xFFFFFF7()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFAT_FileSys) */ 
	FAT_FileSysStruct pstFAT_FileSys;
	memset(&pstFAT_FileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFAT_FileSys  = &pstFAT_FileSys ;
    _pstFAT_FileSys->stBootSector.BPB_SecPerClus = 1;
    _pstFAT_FileSys->stBootSector.BPB_TotSec32 = 0xFFFFFF8;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATStructureReadRoot(_pstFAT_FileSys, _logicalBlockAddress);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0xFFFFFF7, _pstFAT_FileSys->stFAT.u32FATTotalClusterNo);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT32_and_if_u32FATTotalClusterNo_gt_0xFFFFFF7 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureReadRoot(FAT_FileSysStruct *, U32) */
extern BOOLEAN gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetMaxClusterNo;
void TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFAT_FileSys) */ 
	FAT_FileSysStruct pstFAT_FileSys;
	memset(&pstFAT_FileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFAT_FileSys  = &pstFAT_FileSys ;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATStructureReadRoot(_pstFAT_FileSys, _logicalBlockAddress);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetMaxClusterNo);
        CPPTEST_ASSERT_EQUAL(0, _pstFAT_FileSys->stFAT.u32FATTotalClusterNo);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureGetNextCluster_if_u8FatType_eq_FAT_TYPE_NOT_SUPPORT */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATStructureGetNextCluster(U8, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_eq_FAT_TYPE_NOT_SUPPORT()
{
    /* Pre-condition initialization */
	FAT_FileSysStruct _pFsStruct;
	memset(&_pFsStruct, 0, sizeof(FAT_FileSysStruct));
	FAT_FileSysStruct *pFsStruct = &_pFsStruct;
	pFsStruct->stFAT.u8FATType = FAT_TYPE_NOT_SUPPORT;
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32DirEntryClusterNo) */ 
    U32 _u32DirEntryClusterNo  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
    	FILE_SYSTEM_MOUNTED_ADDR = pFsStruct;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_FATStructureGetNextCluster(_u8fsid, _u32DirEntryClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(NULL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureGetNextCluster_if_u8FatType_eq_FAT_TYPE_NOT_SUPPORT */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureGetNextCluster_if_u8FatType_ne_FAT_TYPE_NOT_SUPPORT */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATStructureGetNextCluster(U8, U32) */
extern BOOLEAN gbTest_FAT_FATStructureGetNextCluster_CallFAT_FATStructureRead;
void TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_ne_FAT_TYPE_NOT_SUPPORT()
{
    /* Pre-condition initialization */
	FAT_FileSysStruct _pFsStruct;
	memset(&_pFsStruct, 0, sizeof(FAT_FileSysStruct));
	FAT_FileSysStruct *pFsStruct = &_pFsStruct;
	pFsStruct->stFAT.u8FATType = FAT_TYPE_FAT12;
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32DirEntryClusterNo) */ 
    U32 _u32DirEntryClusterNo  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
    	FILE_SYSTEM_MOUNTED_ADDR = pFsStruct;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_FATStructureGetNextCluster(_u8fsid, _u32DirEntryClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATStructureGetNextCluster_CallFAT_FATStructureRead);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureGetNextCluster_if_u8FatType_ne_FAT_TYPE_NOT_SUPPORT */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_PartitionTableRead_if_u8partitionBytes_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_PartitionTableRead(FAT_FileSysStruct *, U32, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_PartitionTableRead_if_u8partitionBytes_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (u8partitionBytes) */ 
    U8 * _u8partitionBytes  = NULL ;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_PartitionTableRead(_pstFileSys, _logicalBlockAddress, _u8partitionBytes);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(_pstFileSys->u32RelativeSector, FAT_BOOT_SECTOR_OFFSET);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_PartitionTableRead_if_u8partitionBytes_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_PartitionTableRead_if_u8partitionBytes_ne_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_PartitionTableRead(FAT_FileSysStruct *, U32, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_PartitionTableRead_if_u8partitionBytes_ne_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (u8partitionBytes) */ 
    U8 u8partitionBytes;
    u8partitionBytes = 0;
    U8 * _u8partitionBytes  = &u8partitionBytes ;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_PartitionTableRead(_pstFileSys, _logicalBlockAddress, _u8partitionBytes);
        CPPTEST_ASSERT_BOOL_EQUAL(_pstFileSys->u32RelativeSector, 0);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_PartitionTableRead_if_u8partitionBytes_ne_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_BootSectorRead_if1_msAPI_MSDCtrl_SectorRead_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_BootSectorRead(FAT_FileSysStruct *) */
extern BOOLEAN gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead;
void TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if1_msAPI_MSDCtrl_SectorRead_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_BootSectorRead(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_BootSectorRead_if1_msAPI_MSDCtrl_SectorRead_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_BootSectorRead(FAT_FileSysStruct *) */
extern BOOLEAN gbTest_FAT_BootSectorRead_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_BootSectorRead(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_BootSectorRead_CallmsAPI_FS_GetAddr);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_BootSectorRead(FAT_FileSysStruct *) */
void TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9()
{
	printf("NULL = %d\n", NULL);
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    U8 _USB_IO_TEMP_ADDR[512] = 0;
    {
         USB_IO_TEMP_ADDR  = _USB_IO_TEMP_ADDR;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_BootSectorRead(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_BootSectorRead_CallmsAPI_FS_GetAddr);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATFsinfoFetch_if1_FileSystemID_eq_INVALID_DRIVE_INDEX */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATFsinfoFetch(FAT_FileSysStruct *) */
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if1_FileSystemID_eq_INVALID_DRIVE_INDEX()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
    FAT_FileSysStruct pstFileSys;
    memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    _pstFileSys->FileSystemID = INVALID_DRIVE_INDEX;
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATFsinfoFetch(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATFsinfoFetch_if1_FileSystemID_eq_INVALID_DRIVE_INDEX */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATFsinfoFetch_if2_msAPI_MSDCtrl_SectorRead_eq_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATFsinfoFetch(FAT_FileSysStruct *) */
extern BOOLEAN gbTest_FAT_FATFsinfoFetch_CallmsAPI_MSDCtrl_SectorRead;
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if2_msAPI_MSDCtrl_SectorRead_eq_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
    FAT_FileSysStruct pstFileSys;
    memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    _pstFileSys->FileSystemID = 0x01;
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATFsinfoFetch(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATFsinfoFetch_CallmsAPI_MSDCtrl_SectorRead);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATFsinfoFetch_if2_msAPI_MSDCtrl_SectorRead_eq_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATFsinfoFetch(FAT_FileSysStruct *) */
extern BOOLEAN gbTest_FAT_FATFsinfoFetch_CallmsAPI_FS_GetAddr;
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
    FAT_FileSysStruct pstFileSys;
    memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATFsinfoFetch(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, gbTest_FAT_FATFsinfoFetch_CallmsAPI_FS_GetAddr);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_RootDirectroyInfo_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_RootDirectroyInfo(FAT_FileSysStruct *) */
void TestSuite_msAPI_FAT_test_FAT_RootDirectroyInfo_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    _pstFileSys->stFAT.u8FATType = FAT_TYPE_FAT32;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_RootDirectroyInfo(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_RootDirectroyInfo_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_RootDirectroyInfo_if_no */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_RootDirectroyInfo(FAT_FileSysStruct *) */
void TestSuite_msAPI_FAT_test_FAT_RootDirectroyInfo_if_no()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFileSys) */ 
	FAT_FileSysStruct pstFileSys;
	memset(&pstFileSys, 0, sizeof(FAT_FileSysStruct));
    FAT_FileSysStruct * _pstFileSys  = &pstFileSys ;
    _pstFileSys->stBootSector.BPB_BytsPerSec = 1;
    _pstFileSys->stFAT.u8FATType = FAT_TYPE_FAT12;
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_RootDirectroyInfo(_pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_RootDirectroyInfo_if_no */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetSectorNo_if_u32ClusterNo_eq_0_and_if_yes */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetSectorNo(U8, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_eq_0_and_if_yes()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 0ul;

    {
        /* Tested function call */
        U32 _return  = FAT_FATGetSectorNo(_u8fsid, _u32ClusterNo);
        /* Post-condition check */
        printf("_return = %d\n", _return);
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetSectorNo_if_u32ClusterNo_eq_0_and_if_yes */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATGetSectorNo_if_u32ClusterNo_ne_0_and_lt_2 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATGetSectorNo(U8, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_ne_0_and_lt_2()
{
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32ClusterNo) */ 
    U32 _u32ClusterNo  = 1ul;

    {
        /* Tested function call */
        U32 _return  = FAT_FATGetSectorNo(_u8fsid, _u32ClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATGetSectorNo_if_u32ClusterNo_ne_0_and_lt_2 */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirEntryNext_if_pFS_Env_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT EN_ENTRY_NEXT_RESULT FAT_DirEntryNext(U8, FileEntry *) */
void TestSuite_msAPI_FAT_test_FAT_DirEntryNext_if_pFS_Env_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentID) */ 
    U8 _u8EnvironmentID  = 0;
    /* Initializing argument 2 (pFileToSet) */ 
    FileEntry * _pFileToSet  = 0 ;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        EN_ENTRY_NEXT_RESULT _return  = FAT_DirEntryNext(_u8EnvironmentID, _pFileToSet);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(ENTRY_NEXT_RESULT_ERROR, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirEntryNext_if_pFS_Env_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_DirectroyDirEntryToFirst(U8) */
void TestSuite_msAPI_FAT_test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentID) */ 
    U8 _u8EnvironmentID  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 1;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_DirectroyDirEntryToFirst(_u8EnvironmentID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirectoryChange_if_pFS_Env_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_DirectoryChange(U8, U32) */
void TestSuite_msAPI_FAT_test_FAT_DirectoryChange_if_pFS_Env_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentId) */ 
    U8 _u8EnvironmentId  = 0;
    /* Initializing argument 2 (u32DirStartClusterNo) */ 
    U32 _u32DirStartClusterNo  = 0ul;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_DirectoryChange(_u8EnvironmentId, _u32DirStartClusterNo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirectoryChange_if_pFS_Env_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FileClusterChainFetch(U8) */
void TestSuite_msAPI_FAT_test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleID) */ 
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    pstFAT_FileHandle->pub_fileheader.InodeID = 0xfe;
    {
         FILE_HANDLE_POOL  = pstFAT_FileHandle;
    }
    U8 _u8FileHandleID  = 0;

    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = pstFAT_FileHandle;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FileClusterChainFetch(_u8FileHandleID);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileOpen_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FileOpen(U8, void *, BOOLEAN) */
void TestSuite_msAPI_FAT_test_FAT_FileOpen_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleNo) */ 
    U8 _u8FileHandleNo  = 0;
    /* Initializing argument 2 (pFileEntry) */ 
    void * _pFileEntry  = 0 ;
    /* Initializing argument 3 (fastOpen) */ 
    U8 _fastOpen  = 0;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    pstFAT_FileHandle->pub_fileheader.InodeID = 0xfe;
    {
         FILE_HANDLE_POOL  = pstFAT_FileHandle;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FileOpen(_u8FileHandleNo, _pFileEntry, _fastOpen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileOpen_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_GetNextCluster_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_GetNextCluster(FAT_FileHandle *, U8, U16, U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_GetNextCluster_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFAT_FileHandle) */ 
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;

    /* Initializing argument 2 (u8BPB_SecPerClus) */ 
    U8 _u8BPB_SecPerClus  = 0;
    /* Initializing argument 3 (u16BytePerSec) */ 
    U16 _u16BytePerSec  = 0u;
    /* Initializing argument 4 (u8FATType) */ 
    U8 _u8FATType  = 0;
    /* Initializing argument 5 (u32FATTotalClusterNo) */ 
    U32 _u32FATTotalClusterNo  = 0ul;
    /* Initializing argument 6 (u32AppendLength) */ 
    U32 _u32AppendLength  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = pstFAT_FileHandle;
    }
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_GetNextCluster(pstFAT_FileHandle, _u8BPB_SecPerClus, _u16BytePerSec, _u8FATType, _u32FATTotalClusterNo, _u32AppendLength);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FAT_CLUSTER_FINAL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_GetNextCluster_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileRead_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FileRead(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FileRead_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleNo) */ 
    U8 _u8FileHandleNo  = 0;
    /* Initializing argument 2 (u32DesBufAdr) */ 
    U32 _u32DesBufAdr  = 0ul;
    /* Initializing argument 3 (u32ReadByteLength) */ 
    U32 _u32ReadByteLength  = 0ul;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    FILE_INODE_POOL  = pstFAT_FileHandle;
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_FileRead(_u8FileHandleNo, _u32DesBufAdr, _u32ReadByteLength);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileRead_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FileSeekWithoutClusterChain(U8, U32, EN_FILE_SEEK_OPTION) */
void TestSuite_msAPI_FAT_test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    FILE_INODE_POOL  = pstFAT_FileHandle;
    /* Initializing argument 1 (u8FileHandleNo) */ 
    U8 _u8FileHandleNo  = 0;
    /* Initializing argument 2 (u32Position) */ 
    U32 _u32Position  = 0ul;
    /* Initializing argument 3 (eOption) */ 
    EN_FILE_SEEK_OPTION _eOption  = FILE_SEEK_SET;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 

    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FileSeekWithoutClusterChain(_u8FileHandleNo, _u32Position, _eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileSeek_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FileSeek(U8, U32, EN_FILE_SEEK_OPTION) */
void TestSuite_msAPI_FAT_test_FAT_FileSeek_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    FAT_FileHandle _pstFAT_FileHandle;
    memset(&_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    FAT_FileHandle * pstFAT_FileHandle = &_pstFAT_FileHandle;
    FILE_INODE_POOL  = pstFAT_FileHandle;
    /* Initializing argument 1 (u8FileHandleNo) */ 
    U8 _u8FileHandleNo  = 0;
    /* Initializing argument 2 (u32Length) */ 
    U32 _u32Length  = 0ul;
    /* Initializing argument 3 (eOption) */ 
    EN_FILE_SEEK_OPTION _eOption  = FILE_SEEK_SET;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }

    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FileSeek(_u8FileHandleNo, _u32Length, _eOption);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileSeek_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirectoryGetParentClusterNo */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_DirectoryGetParentClusterNo(U8) */
void TestSuite_msAPI_FAT_test_FAT_DirectoryGetParentClusterNo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentID) */ 
    U8 _u8EnvironmentID  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_DirectoryGetParentClusterNo(_u8EnvironmentID);
        /* Post-condition check */
        printf("_return = %d\n", _return);
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirectoryGetParentClusterNo */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_EntryIsCurrentNameShortOnly */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_EntryIsCurrentNameShortOnly(U8) */
void TestSuite_msAPI_FAT_test_FAT_EntryIsCurrentNameShortOnly()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enid) */ 
    U8 _enid  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_EntryIsCurrentNameShortOnly(_enid);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_EntryIsCurrentNameShortOnly */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_SaveEnvironment(U8) */
void TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentID) */ 
    U8 _u8EnvironmentID  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_SaveEnvironment(_u8EnvironmentID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_SaveEnvironment(U8) */
void TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8EnvironmentID) */ 
    U8 _u8EnvironmentID  = 0;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_SaveEnvironment(_u8EnvironmentID);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATFsinfoUpdate_Increase(FileEntry *, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pTempFileEntry) */ 
	FileEntry pTempFileEntry;
	memset(&pTempFileEntry, 0, sizeof(FileEntry));
    FileEntry * _pTempFileEntry  = &pTempFileEntry ;
    /* Initializing argument 2 (u32deletedClusterCount) */ 
    U32 _u32deletedClusterCount  = 0ul;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FATFsinfoUpdate_Increase(_pTempFileEntry, _u32deletedClusterCount);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_DirectoryFreeDirEntry(FileEntry *) */
void TestSuite_msAPI_FAT_test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pDeleteFileEntry) */ 
	FileEntry tmp;
	memset(&tmp, 0, sizeof(FileEntry));
    FileEntry * _pDeleteFileEntry  = &tmp ;
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
        BOOLEAN _return  = FAT_DirectoryFreeDirEntry(_pDeleteFileEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(NULL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirEntryWriteDirect_if_return_first_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_DirEntryWriteDirect(U8, U32, U32, DirEntryStruct *) */
void TestSuite_msAPI_FAT_test_FAT_DirEntryWriteDirect_if_return_first_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (startCluster) */ 
    U32 _startCluster  = 1ul;
    /* Initializing argument 3 (u32Index) */ 
    U32 _u32Index  = 0ul;
    /* Initializing argument 4 (pDirEntry) */ 
    DirEntryStruct * _pDirEntry  = 0 ;
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
        BOOLEAN _return  = FAT_DirEntryWriteDirect(_u8fsid, _startCluster, _u32Index, _pDirEntry);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirEntryWriteDirect_if_return_first_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileWrite_if_pFATInode_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FileWrite(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FileWrite_if_pFATInode_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandle) */ 
    U8 _u8FileHandle  = 0;
    /* Initializing argument 2 (u32SrcBufAddr) */ 
    U32 _u32SrcBufAddr  = 0ul;
    /* Initializing argument 3 (u32BufferLen) */ 
    U32 _u32BufferLen  = 0ul;
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_FileWrite(_u8FileHandle, _u32SrcBufAddr, _u32BufferLen);
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileWrite_if_pFATInode_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0 */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FileWrite(U8, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandle) */ 
    U8 _u8FileHandle  = 0;
    /* Initializing argument 2 (u32SrcBufAddr) */ 
    U32 _u32SrcBufAddr  = 0ul;
    /* Initializing argument 3 (u32BufferLen) */ 
    U32 _u32BufferLen  = 0ul;
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_FileWrite(_u8FileHandle, _u32SrcBufAddr, _u32BufferLen);
        /* Post-condition check */

        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT U8 FAT_DirEntryFindVolumeLabel(U8, U16 *, U8) */
void TestSuite_msAPI_FAT_test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE()
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
        U8 _return  = FAT_DirEntryFindVolumeLabel(_u8DriveIndex, _VolLabName, _VolLabNameLen);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(ENTRY_CREATE_RESULT_ERROR, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0 */
/* CPPTEST_TEST_CASE_CONTEXT U8 FAT_EntryFillCluster(U8) */
void TestSuite_msAPI_FAT_test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandle) */ 
    U8 _u8FileHandle  = 0;
    /* Initializing global variable FILE_FAT_TABLE_CACHE */ 
    {
         FILE_FAT_TABLE_CACHE  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U8 _return  = FAT_EntryFillCluster(_u8FileHandle);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(ENTRY_CREATE_RESULT_FULL, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0 */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_InitialFileSystem_if_FAT_PartitionTableRead_return_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_InitialFileSystem(S8, U32, U8 *, FAT_FileSysStruct *) */
void TestSuite_msAPI_FAT_test_FAT_InitialFileSystem_if_FAT_PartitionTableRead_return_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (deviceIndex) */ 
    S8 _deviceIndex  = 0;
    /* Initializing argument 2 (logicalBlockAddress) */ 
    U32 _logicalBlockAddress  = 0ul;
    /* Initializing argument 3 (partitionBytes) */ 
    U8 * _partitionBytes  = 0 ;
    /* Initializing argument 4 (pstFileSys) */ 
    FAT_FileSysStruct stFileSys;
    FAT_FileSysStruct * _pstFileSys  = &stFileSys ;
    memset(_pstFileSys, 0, sizeof(FAT_FileSysStruct));
    /* Initializing global variable USB_IO_TEMP_ADDR2 */ 
    {
         USB_IO_TEMP_ADDR2  = 0ul;
    }
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_InitialFileSystem(_deviceIndex, _logicalBlockAddress, _partitionBytes, _pstFileSys);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_InitialFileSystem_if_FAT_PartitionTableRead_return_false */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_FATStructureRead(U8, U32) */
void TestSuite_msAPI_FAT_test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u32DirEntryClusterNo) */ 
    U32 _u32DirEntryClusterNo  = 0ul;
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
        U32 _return  = FAT_FATStructureRead(_u8fsid, _u32DirEntryClusterNo);
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FATStructureWrite(U8) */
void TestSuite_msAPI_FAT_test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
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
        BOOLEAN _return  = FAT_FATStructureWrite(_fsid);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirectoryEntrySave_end */
/* CPPTEST_TEST_CASE_CONTEXT void FAT_DirectoryEntrySave(U8, U8, DirEntryStruct *, FileEntry *, U32, U32) */
void TestSuite_msAPI_FAT_test_FAT_DirectoryEntrySave_end()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8fsid) */ 
    U8 _u8fsid  = 0;
    /* Initializing argument 2 (u8EnvironmentID) */ 
    U8 _u8EnvironmentID  = 0;
    /* Initializing argument 3 (pstTempDirEntry) */ 
    DirEntryStruct stTempDirEntry;
    DirEntryStruct * _pstTempDirEntry  = &stTempDirEntry ;
    memset(_pstTempDirEntry, 0, sizeof(DirEntryStruct));
    /* Initializing argument 4 (pFileToSet) */ 
    FileEntry FileToSet;
    FileEntry * _pFileToSet  = &FileToSet ;
    memset(_pFileToSet, 0, sizeof(FileEntry));
    /* Initializing argument 5 (currentClusterNo) */ 
    U32 _currentClusterNo  = 0ul;
    /* Initializing argument 6 (currentDirEntryOffset) */ 
    U32 _currentDirEntryOffset  = 0ul;
    /* Initializing global variable FS_ENVIRONMENT_NUM */ 
    {
         FS_ENVIRONMENT_NUM  = 0;
    }
    {
        /* Tested function call */
        FAT_DirectoryEntrySave(_u8fsid, _u8EnvironmentID, _pstTempDirEntry, _pFileToSet, _currentClusterNo, _currentDirEntryOffset);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _u8fsid);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirectoryEntrySave_end */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_DirectoryEntryGetName_end */
/* CPPTEST_TEST_CASE_CONTEXT void FAT_DirectoryEntryGetName(DirEntryStruct *, U16 *) */
void TestSuite_msAPI_FAT_test_FAT_DirectoryEntryGetName_end()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstTempDirEntry) */ 
	DirEntryStruct stTempDirEntry;
    DirEntryStruct * _pstTempDirEntry  = &stTempDirEntry ;
    memset(_pstTempDirEntry, 0, sizeof(DirEntryStruct));
    /* Initializing argument 2 (pu16FileName) */ 
    U16 u16FileName[9];
    U16 * _pu16FileName  = u16FileName ;
    {
        /* Tested function call */
        FAT_DirectoryEntryGetName(_pstTempDirEntry, _pu16FileName);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(u16FileName, _pu16FileName);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_DirectoryEntryGetName_end */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_HandlePostCreate_end */
/* CPPTEST_TEST_CASE_CONTEXT void FAT_HandlePostCreate(U8, FileEntry *, U8) */
void TestSuite_msAPI_FAT_test_FAT_HandlePostCreate_end()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleNo) */ 
    U8 _u8FileHandleNo  = 0;
    /* Initializing argument 2 (pFileEntry) */ 
    FileEntry stFileEntry;
    FileEntry * _pFileEntry  = &stFileEntry ;
    memset(_pFileEntry, 0, sizeof(FileEntry));
    /* Initializing argument 3 (u8OpenMode) */ 
    U8 _u8OpenMode  = 0;
    /* Initializing global variable FS_FILE_HANDLE_NUM */ 
    {
         FS_FILE_HANDLE_NUM  = 2;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 2ul;
    }
    {
        /* Tested function call */
        FAT_HandlePostCreate(_u8FileHandleNo, _pFileEntry, _u8OpenMode);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(0, _u8FileHandleNo);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_HandlePostCreate_end */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FileClose_return_true */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FileClose(U8) */
void TestSuite_msAPI_FAT_test_FAT_FileClose_return_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8FileHandleNo) */ 
    U8 _u8FileHandleNo  = 0;
    /* Initializing global variable USB_IO_TEMP_ADDR */ 
    {
         USB_IO_TEMP_ADDR  = 0ul;
    }
    /* Initializing global variable FILE_HANDLE_POOL */ 
    {
         FILE_HANDLE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = FAT_FileClose(_u8FileHandleNo);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FileClose_return_true */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true */
/* CPPTEST_TEST_CASE_CONTEXT U32 FAT_GetRemainSectors(FAT_FileHandle *, U8) */
void TestSuite_msAPI_FAT_test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstFAT_FileHandle) */ 
	FAT_FileHandle stFAT_FileHandle;
    FAT_FileHandle * _pstFAT_FileHandle  = &stFAT_FileHandle ;
    memset(_pstFAT_FileHandle, 0, sizeof(FAT_FileHandle));
    /* Initializing argument 2 (u8BPB_SecPerClus) */ 
    U8 _u8BPB_SecPerClus  = 0;
    /* Initializing global variable FILE_INODE_POOL */ 
    {
         FILE_INODE_POOL  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = FAT_GetRemainSectors(_pstFAT_FileHandle, _u8BPB_SecPerClus);
        /* Post-condition check */
        printf("_return = %d\n", _return);
        CPPTEST_ASSERT_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true */



/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (fsid) */ 
    U8 _fsid  = 0;
    /* Initializing argument 2 (u8FileHandleID) */ 
    U8 _u8FileHandleID  = 0;
    /* Initializing argument 3 (u32ChainStartCluster) */ 
    U32 _u32ChainStartCluster  = 0ul;
    /* Initializing argument 4 (curIndex) */ 
    U16 _curIndex  = CLUSTER_CHAIN_SIZE;
    /* Initializing argument 5 (u8FatType) */ 
    U8 _u8FatType  = 0;
    /* Initializing argument 6 (merge2Previous) */ 
    U8 * _merge2Previous  = 0 ;
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
        BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));

    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE */


/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32()
{
	 /* Pre-condition initialization */
	    /* Initializing argument 1 (fsid) */
	    U8 _fsid  = 0;
	    /* Initializing argument 2 (u8FileHandleID) */
	    U8 _u8FileHandleID  = 0;
	    /* Initializing argument 3 (u32ChainStartCluster) */
	    U32 _u32ChainStartCluster  = 0ul;
	    /* Initializing argument 4 (curIndex) */
	    U16 _curIndex  = CLUSTER_CHAIN_SIZE-2;
	    /* Initializing argument 5 (u8FatType) */
	    U8 _u8FatType  = FAT_TYPE_FAT32;
	    /* Initializing argument 6 (merge2Previous) */
	    U8 * _merge2Previous  = 0 ;
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
	        BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
	        /* Post-condition check */
	        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
	    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16()
{
	/* Pre-condition initialization */
		    /* Initializing argument 1 (fsid) */
		    U8 _fsid  = 0;
		    /* Initializing argument 2 (u8FileHandleID) */
		    U8 _u8FileHandleID  = 0;
		    /* Initializing argument 3 (u32ChainStartCluster) */
		    U32 _u32ChainStartCluster  = 0ul;
		    /* Initializing argument 4 (curIndex) */
		    U16 _curIndex  = CLUSTER_CHAIN_SIZE-2;
		    /* Initializing argument 5 (u8FatType) */
		    U8 _u8FatType  = FAT_TYPE_FAT16;
		    /* Initializing argument 6 (merge2Previous) */
		    U8 * _merge2Previous  = 0 ;
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
		        BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
		        /* Post-condition check */
		        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
		    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16 */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL()
{
	/* Pre-condition initialization */
		    /* Initializing argument 1 (fsid) */
		    U8 _fsid  = 0;
		    /* Initializing argument 2 (u8FileHandleID) */
		    U8 _u8FileHandleID  = 0;
		    /* Initializing argument 3 (u32ChainStartCluster) */
		    U32 _u32ChainStartCluster  = 0ul;
		    /* Initializing argument 4 (curIndex) */
		    U16 _curIndex  = CLUSTER_CHAIN_SIZE-2;
		    /* Initializing argument 5 (u8FatType) */
		    U8 _u8FatType  = 0;
		    /* Initializing argument 6 (merge2Previous) */
		    U8 * _merge2Previous  = 0 ;
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
		        BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
		        /* Post-condition check */
		        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
		    }
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed()
{
/* Pre-condition initialization */
			/* Initializing argument 1 (fsid) */
			U8 _fsid  = 0;
			/* Initializing argument 2 (u8FileHandleID) */
			U8 _u8FileHandleID  = 0;
			/* Initializing argument 3 (u32ChainStartCluster) */
			U32 _u32ChainStartCluster  = 0ul;
			/* Initializing argument 4 (curIndex) */
			U16 _curIndex  = 1;
			/* Initializing argument 5 (u8FatType) */
			U8 _u8FatType  = 0;
			/* Initializing argument 6 (merge2Previous) */
			U8 * _merge2Previous  = 0 ;
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
				BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
				/* Post-condition check */
				//printf("u32ChainStartCluster = %u \n",u32ChainStartCluster);
				CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
			}
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed()
{
/* Pre-condition initialization */
			/* Initializing argument 1 (fsid) */
			U8 _fsid  = 0;
			/* Initializing argument 2 (u8FileHandleID) */
			U8 _u8FileHandleID  = 0;
			/* Initializing argument 3 (u32ChainStartCluster) */
			U32 _u32ChainStartCluster  = 0ul;
			/* Initializing argument 4 (curIndex) */
			U16 _curIndex  = 1;
			/* Initializing argument 5 (u8FatType) */
			U8 _u8FatType  = 0;
			/* Initializing argument 6 (merge2Previous) */
			U8 * _merge2Previous  = 0 ;
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
				BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
				/* Post-condition check */
				//printf("u32ChainStartCluster = %u \n",u32ChainStartCluster);
				CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
			}
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed */

/* CPPTEST_TEST_CASE_BEGIN test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN FAT_FILE_AppendClusterChain(U8, U8, U32, U16, U8, U8 *) */
void TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else()
{
/* Pre-condition initialization */
			/* Initializing argument 1 (fsid) */
			U8 _fsid  = 0;
			/* Initializing argument 2 (u8FileHandleID) */
			U8 _u8FileHandleID  = 0;
			/* Initializing argument 3 (u32ChainStartCluster) */
			U32 _u32ChainStartCluster  = 0ul;
			/* Initializing argument 4 (curIndex) */
			U16 _curIndex  = 0;
			/* Initializing argument 5 (u8FatType) */
			U8 _u8FatType  = 0;
			/* Initializing argument 6 (merge2Previous) */
			U8 * _merge2Previous  = 0 ;
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
				BOOLEAN _return  = FAT_FILE_AppendClusterChain(_fsid, _u8FileHandleID, _u32ChainStartCluster, _curIndex, _u8FatType, &_merge2Previous);
				/* Post-condition check */
				//printf("u32ChainStartCluster = %u \n",u32ChainStartCluster);
				CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
			}
}
/* CPPTEST_TEST_CASE_END test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else */

