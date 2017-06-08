#include "cpptest.h"
/*
 * core_api_N51FS_Index.c
 *
 *  Created on: 11 Oct 2013
 *      Author: muters
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"

#include "datatype.h"
#include "debug.h"

#include "msAPI_FSCommon.h"

#include "msAPI_FCtrl.h"
#include "N51FS_Index.h"
#include "msAPI_N51FS.h"
#include "msAPI_MSDCtrl.h"
#include "msAPI_FSEnv.h"
#include "msAPI_MIU.h"
#include "msAPI_N51FS.h"
#include "msAPI_Timer.h"
#include "N51FS_File.h"
#include "msAPI_FAT.h"

#define UT_MSG(x) //x

EXTERN_C_LINKAGE_START
// BOOLEAN gbTest_ConvertN51FSTimeTo1980BasedSeconds_CallLL_subtractLong = FALSE;
// BOOLEAN gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr = FALSE;
BOOLEAN gbTest_FAT_GetAddr_CallmsAPI_FS_GetAddr = FALSE;
BOOLEAN gbTest_FAT_File_GetHandleInfo_CallmsAPI_FS_GetAddr = FALSE;
BOOLEAN gbTest_FAT_File_GetInodeFromHandle_CallFAT_File_GetHandleInfo = FALSE;
BOOLEAN gbTest_FAT_File_GetInodeFromHandle_CallFCtrl_GetFileInodeInfo = FALSE;
BOOLEAN gbTest_FAT_File_GetHandleClusterChainInfo_CallmsAPI_FS_GetAddr = FALSE;
BOOLEAN gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead = FALSE;
BOOLEAN gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead_Con_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes = FALSE;
BOOLEAN gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType = FALSE;
BOOLEAN gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetMaxClusterNo = FALSE;
BOOLEAN gbTest_FAT_FATStructureGetNextCluster_CallFAT_FATStructureRead = FALSE;
BOOLEAN gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead = FALSE;
BOOLEAN gbTest_FAT_BootSectorRead_CallmsAPI_FS_GetAddr = FALSE;
BOOLEAN gbTest_FAT_FATFsinfoFetch_CallmsAPI_MSDCtrl_SectorRead = FALSE;
BOOLEAN gbTest_FAT_FATFsinfoFetch_CallmsAPI_FS_GetAddr = FALSE;
EXTERN_C_LINKAGE_END

BOOLEAN gbTest_ConvertN51FSTimeTo1980BasedSeconds_CallLL_subtractLong ;

EXTERN_C_LINKAGE LongLong LL_subtractLong(LongLong *pX, LongLong *pY);
EXTERN_C_LINKAGE LongLong CppTest_Stub_LL_subtractLong(LongLong *pX, LongLong *pY)
{
	LongLong l;
	l.Hi = 0;
	l.Lo = 0;
	if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_ConvertN51FSTimeTo1980BasedSeconds"))
	{
		if (pX->Hi == 0 && pX->Lo == 1)
		{
			gbTest_ConvertN51FSTimeTo1980BasedSeconds_CallLL_subtractLong = TRUE;
		}
	}

	return l;
}


BOOLEAN gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr ;

MS_BOOL g_CppTest_Stub_N51FS_GetIndexRecordInfo = FALSE;
MS_BOOL g_CppTest_Stub_N51FS_GetEnvironmentInfo = FALSE;
MS_BOOL g_CppTest_Stub_N51FS_N51FS_GetIndexRootInfo = FALSE;
MS_BOOL g_CppTest_Stub_N51FS_GetIndexVarsInfo = FALSE;
MS_BOOL g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = FALSE;
U8 xdata gpBuffList[8];

BOOL btest_FCtrl_GetFileHandleInfo_CallmsAPI_FS_GetAddr = FALSE;
BOOL btest_FCtrl_GetFileInodeInfo_CallmsAPI_FS_GetAddr = FALSE;
BOOL btest_FCtrl_GetFileInodeInfo_CallGetFatTableCacheInfo_IF_NO = FALSE;
MSDCtrl_Drive temp;
U8 tmp_U8;

EXTERN_C_LINKAGE U32 msAPI_FS_GetAddr(U32 addr);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_FS_GetAddr(U32 addr)
{

	if(CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0"))
	{

		U8 pBuff[0x0F];
		pBuff[0] = 0;
		pBuff[1] = 0;
		pBuff[2] = 0;
		pBuff[3] = 0;
		pBuff[4] = 0;
		pBuff[5] = 0;
		pBuff[6] = 0;
		pBuff[7] = 0;
		pBuff[8] = 0;
		pBuff[9] = 0;
		pBuff[10] = 0;
		pBuff[11] = 0;
		pBuff[12] = 0;
		pBuff[13] = 0;
		pBuff[14] = 0;
        g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
		return (&pBuff[0]);

	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_WriteMFTRecord_0"))
	{
		if(addr == msAPI_FS_GetAddr(addr))
		{
			gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr = TRUE;
		}
	}

	if(CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_GetSubNodeVCN"))
	{
		if(addr == msAPI_FS_GetAddr(addr))
		{
			gbTest_N51FS_Delete_GetSubNodeVCN_CallmsAPI_FS_GetAddr = TRUE;
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetIndexRecordInfo"))
	{
		if (addr == 0x3000)
		{
			g_CppTest_Stub_N51FS_GetIndexRecordInfo = TRUE;
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetEnvironmentInfo"))
	{
		if (addr == 0)
		{
			g_CppTest_Stub_N51FS_GetEnvironmentInfo = TRUE;
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetIndexRootInfo"))
	{
		if (addr == addr)
		{
			g_CppTest_Stub_N51FS_N51FS_GetIndexRootInfo = TRUE;
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetIndexVarsInfo"))
	{
		if (addr == addr)
		{
			g_CppTest_Stub_N51FS_GetIndexVarsInfo = TRUE;
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo"))
	{
		N51FS_MftDataRun objN51FS_MftDataRun;

		if (addr == 0x00)
		{
			objN51FS_MftDataRun.u32LCN = 0;
			objN51FS_MftDataRun.u32Len = 1;
			g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
			return (&objN51FS_MftDataRun);
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_ELSE"))
	{
		N51FS_MftDataRun objN51FS_MftDataRun;

		if (addr == 0x00)
		{
			objN51FS_MftDataRun.u32LCN = 0;
			objN51FS_MftDataRun.u32Len = 0;
			g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
			return (&objN51FS_MftDataRun);
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_1"))
	{
		U8 pBuff[10];
		pBuff[0] = 0;
		pBuff[1] = 0;
		pBuff[2] = 0;
		pBuff[3] = 0;
		pBuff[4] = 0;
		pBuff[5] = 0;
		pBuff[6] = 0;
		pBuff[7] = 0;
		pBuff[8] = 0;
		pBuff[9] = 0;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
		return (&pBuff[0]);
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_2"))
	{
		U8 pBuff[10];
		pBuff[0] = 0;
		pBuff[1] = 0;
		pBuff[2] = 0;
		pBuff[3] = 0;
		pBuff[4] = 0;
		pBuff[5] = 0x80;
		pBuff[6] = 0xF0;
		pBuff[7] = 0xF0;
		pBuff[8] = 0;
		pBuff[9] = 0;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
		return (&pBuff[0]);
	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_GetAddr_if_yes"))
	{
		if(0 == addr)
		{
			gbTest_FAT_GetAddr_CallmsAPI_FS_GetAddr = TRUE;
		}
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_File_GetHandleInfo"))
	{
		if(0 == addr)
		{
			gbTest_FAT_File_GetHandleInfo_CallmsAPI_FS_GetAddr = TRUE;
		}
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_DirEntryIterator_GetInfo"))
	{
		return 0;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_File_GetHandleClusterChainInfo"))
	{
		if(0x1000 == addr)
		{
			gbTest_FAT_File_GetHandleClusterChainInfo_CallmsAPI_FS_GetAddr = TRUE;
		}
		return addr;
	}
	
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1"))
    {
         U8 pBuff[0xFFFF];
         pBuff[0] = 0;
         pBuff[1] = 0;
         pBuff[2] = 0;
         pBuff[3] = 0;
         pBuff[4] = 0;
         pBuff[5] = 0x80;
         pBuff[6] = 0xF0;
         pBuff[7] = 0xF0;
         pBuff[8] = 0;
         pBuff[9] = 0;
         g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
         return (&pBuff[0]);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE"))
    {
         U8 pBuff[0xFFFF];
         pBuff[0] = 0;
         pBuff[1] = 0;
         pBuff[2] = 0;
         pBuff[3] = 0;
         pBuff[4] = 0;
         pBuff[5] = 0x80;
         pBuff[6] = 0xF0;
         pBuff[7] = 0xF0;
         pBuff[8] = 0;
         pBuff[9] = 0;
         g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
         return (&pBuff[0]);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_1"))
    {
         U8 pBuff[10];
         pBuff[0] = 0;
         pBuff[1] = 0;
         pBuff[2] = 0;
         pBuff[3] = 0;
         pBuff[4] = 0;
         pBuff[5] = 0x80;
         pBuff[6] = 0xF0;
         pBuff[7] = 0xF0;
         pBuff[8] = 0;
         pBuff[9] = 0;
         g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
         return (&pBuff[0]);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_2"))
    {
         U8 pBuff[10];
         pBuff[0] = 0;
         pBuff[1] = 0;
         pBuff[2] = 0;
         pBuff[3] = 0;
         pBuff[4] = 0;
         pBuff[5] = 0x80;
         pBuff[6] = 0xF0;
         pBuff[7] = 0xF0;
         pBuff[8] = 0;
         pBuff[9] = 0;
         g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
         return (&pBuff[0]);
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1"))
    {
    	 U8 xdata pdata1[0xFFFFF];
    	 pdata1[0] = 0xFF;
    	 pdata1[1] = 0xFF;
    	 pdata1[2] = ATTR_TYPE_FILE_NAME;
    	 pdata1[3] = ATTR_TYPE_FILE_NAME;
    	 pdata1[4] = ATTR_TYPE_FILE_NAME; // ATTR_TYPE_FILE_NAME=0x30,
         pdata1[5] = ATTR_TYPE_FILE_NAME;
         pdata1[6] = ATTR_TYPE_FILE_NAME;
         pdata1[7] = ATTR_TYPE_FILE_NAME;
         g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
         return (&pdata1);
    }

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL"))
	{
		if(0 == addr)
		{
			gbTest_FAT_BootSectorRead_CallmsAPI_FS_GetAddr = TRUE;
			return NULL;
		}
	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9"))
	{
		if(0 != addr)
		{
			gbTest_FAT_BootSectorRead_CallmsAPI_FS_GetAddr = TRUE;
			return &addr;
		}
	}

	printf("addr1 = %d\n", addr);
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL"))
	{
		printf("addr = %d\n", addr);
		if(0 == addr)
		{
			gbTest_FAT_FATFsinfoFetch_CallmsAPI_FS_GetAddr = TRUE;
			return NULL;
		}
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if") )
	{
		tmp_U8 = 0xFF;
		return &tmp_U8;
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FAT16_Format_BPB_ifno_if_ifno") )
			return (U32)0;

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FCtrl_GetFileSystemInfo_IF_no") )
		return (U32)0;

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FCtrl_GetFileHandleInfo"))
	{
		// if(0 == addr)
		{
			btest_FCtrl_GetFileHandleInfo_CallmsAPI_FS_GetAddr = TRUE;
			return (U32)0;
		}
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FCtrl_GetFileInodeInfo"))
	{
		if(0 == addr)
		{
			btest_FCtrl_GetFileInodeInfo_CallmsAPI_FS_GetAddr = TRUE;
			return (U32)0;
		}
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FCtrl_GetFatTableCacheInfo_IF_NO"))
	{
		if(0 == addr)
		{
			btest_FCtrl_GetFileInodeInfo_CallGetFatTableCacheInfo_IF_NO = TRUE;
			return (U32)0;
		}
	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex"))
	{
		temp.DriveIndex = INVALID_DRIVE_INDEX;
		return &temp;
	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetAvailableDriveIndex_end"))
	{
		return NULL;
	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleFree_if_no"))
	{
		temp.DriveIndex = INVALID_DRIVE_INDEX;
		return &temp;
	}

	if(CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_enter"))
	{
		U8 pBuff[10];
		pBuff[0] = 0;
		pBuff[1] = 0;
		pBuff[2] = 0;
		pBuff[3] = 0;
		pBuff[4] = 0;
		pBuff[5] = 0;
		pBuff[6] = 0;
		pBuff[7] = 0;
		pBuff[8] = 0;
		pBuff[9] = 0;
		//g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo_msAPI_FS_GetAddr = TRUE;
		return (&pBuff[0]);
	}


	return 0;
}

MS_BOOL g_CppTest_Stub_N51FS_GetEnvironmentInfo_Return = FALSE;
EXTERN_C_LINKAGE N51FS_Environment* N51FS_GetEnvironmentInfo(U8 enid);
EXTERN_C_LINKAGE N51FS_Environment* CppTest_Stub_N51FS_GetEnvironmentInfo(U8 enid)
{
	N51FS_Environment objN51FS_Environment;
	objN51FS_Environment.DeviceIndex = 0;
	objN51FS_Environment.FileSystemID = 0;
	objN51FS_Environment.EnvironmentID = 0;
	objN51FS_Environment.CurrentDirectoryMFR = 0;
	objN51FS_Environment.ParentDirectoryMFR = 0;

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetCurrentMFR"))
	{
		objN51FS_Environment.CurrentDirectoryMFR = 0ul;
    	g_CppTest_Stub_N51FS_GetEnvironmentInfo_Return = TRUE;
		return (&objN51FS_Environment);
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_DirectoryGetParentMFR"))
	{
		objN51FS_Environment.ParentDirectoryMFR = 0ul;
    	g_CppTest_Stub_N51FS_GetEnvironmentInfo_Return = TRUE;
		return (&objN51FS_Environment);
	}

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_SaveEnvironment"))
    {
    	g_CppTest_Stub_N51FS_GetEnvironmentInfo_Return = TRUE;
        return (&objN51FS_Environment);
    }
    return (&objN51FS_Environment);
}

FAT_FileSysStruct temp_FAT_FileSysStruct_variable1;
N51FS_FileSysStruct tmp;
MS_BOOL g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = FALSE;
N51FS_FileSysStruct objN51FS_FileSysStruct;

FAT_FileSysStruct bill_opN51FS_FileSysStruct;
FAT_FileSysStruct *pbill_opN51FS_FileSysStruct = &bill_opN51FS_FileSysStruct;

EXTERN_C_LINKAGE U32* FCtrl_GetFileSystemInfo(U8 fsid);
EXTERN_C_LINKAGE U32* CppTest_Stub_FCtrl_GetFileSystemInfo(U8 fsid)
{
	U32 u32Res = 0;
	memset(pbill_opN51FS_FileSysStruct, 0, sizeof(FAT_FileSysStruct));
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileClose_return_true"))
	{
		pbill_opN51FS_FileSysStruct->stBootSector.BPB_BytsPerSec = 1;
		pbill_opN51FS_FileSysStruct->stFAT.u8FATType = FAT_TYPE_FAT32;
		return (pbill_opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false"))
	{
		pbill_opN51FS_FileSysStruct->stBootSector.BPB_BytsPerSec = 1;
		pbill_opN51FS_FileSysStruct->stFAT.u8FATType = FAT_TYPE_FAT32;
		return (pbill_opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL"))
	{
		pbill_opN51FS_FileSysStruct->stBootSector.BPB_BytsPerSec = 1;
		pbill_opN51FS_FileSysStruct->stFAT.u8FATType = FAT_TYPE_FAT32;
		return (pbill_opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE"))
	{
		pbill_opN51FS_FileSysStruct->stBootSector.BPB_BytsPerSec = 1;
		return (pbill_opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0"))
	{
		FAT_FileSysStruct* opN51FS_FileSysStruct;
		FAT_FileSysStruct obj;
		opN51FS_FileSysStruct = &obj;
		opN51FS_FileSysStruct->stBootSector.BPB_SecPerClus = 0;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryWriteDirect_if_return_first_FALSE"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindEmpty_if_s32CurrentDirEntryIndex_lt_0_msAPI_MSDCtrl_SectorRead_return_FALSE"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}

	if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct_1;
		N51FS_FileSysStruct obj_1;
		obj_1.SectorsPerMFTRecord = 1;
		obj_1.SectorsPerCluster = 1;
		opN51FS_FileSysStruct_1 = &obj_1;
		return (&opN51FS_FileSysStruct_1);
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_WriteMFTRecord_0"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileSeek_if_pFATInode_eq_NULL"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileRead_if_pFATInode_eq_NULL"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL"))
	{
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo"))
	{
		{
			N51FS_FileSysStruct* opN51FS_FileSysStruct;
			N51FS_FileSysStruct obj;
			obj.SectorsPerMFTRecord = 1;
			obj.SectorsPerCluster = 1;
			opN51FS_FileSysStruct = &obj;
			g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
			return (&opN51FS_FileSysStruct);
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFT_LSN_ELSE"))
	{
		if (fsid == 0x00)
		{
			N51FS_FileSysStruct* opN51FS_FileSysStruct;
			N51FS_FileSysStruct obj;
			obj.SectorsPerMFTRecord = 0;
			obj.SectorsPerCluster = 1;
			opN51FS_FileSysStruct = &obj;
			g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
			return (&opN51FS_FileSysStruct);
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_1"))
	{
		if (fsid == 0x00)
		{
			N51FS_FileSysStruct* opN51FS_FileSysStruct;
			N51FS_FileSysStruct obj;
			obj.SectorsPerMFTRecord = 0;
			obj.SectorsPerCluster = 1;
			opN51FS_FileSysStruct = &obj;
			g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
			return (&opN51FS_FileSysStruct);
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_2"))
	{
		if (fsid == 0x00)
		{
			N51FS_FileSysStruct* opN51FS_FileSysStruct;
			N51FS_FileSysStruct obj;
			obj.SectorsPerMFTRecord = 0;
			obj.SectorsPerCluster = 1;
			opN51FS_FileSysStruct = &obj;
			g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
			return (&opN51FS_FileSysStruct);
		}
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail"))
	{
		return FILE_SYSTEM_MOUNTED_ADDR;
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no"))
	{
		return FILE_SYSTEM_MOUNTED_ADDR;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes"))
	{
		return FILE_SYSTEM_MOUNTED_ADDR;
	}
	
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1"))
    {
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 0;
		obj.BytesPerSector = 1;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE"))
    {
		N51FS_FileSysStruct* opN51FS_FileSysStruct;
		N51FS_FileSysStruct obj;
		obj.SectorsPerMFTRecord = 0;
		obj.BytesPerSector = 1024;
		obj.SectorsPerCluster = 1;
		opN51FS_FileSysStruct = &obj;
		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&opN51FS_FileSysStruct);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_0"))
    {
    	objN51FS_FileSysStruct.SectorsPerMFTRecord = 1;
    	objN51FS_FileSysStruct.BytesPerSector = 10;
    	objN51FS_FileSysStruct.SectorsPerCluster = 1;
    	objN51FS_FileSysStruct.TotalSectors = 1000;

		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;

		return (&objN51FS_FileSysStruct);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetTotalSizeInKB_1"))
    {
    	objN51FS_FileSysStruct.SectorsPerMFTRecord = 1;
    	objN51FS_FileSysStruct.BytesPerSector = 1024;
    	objN51FS_FileSysStruct.SectorsPerCluster = 1;
    	objN51FS_FileSysStruct.TotalSectors = 1000;

		g_CppTest_Stub_N51FS_ReadMFT_LSN_FCtrl_GetFileSystemInfo = TRUE;
		return (&objN51FS_FileSysStruct);
    }
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_eq_FAT_TYPE_NOT_SUPPORT"))
	{
		return FILE_SYSTEM_MOUNTED_ADDR;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetFileSystemFormatByDriveIndex_ifyes_ifyes") )
	{
		temp_FAT_FileSysStruct_variable1.stFAT.u8FATType = FAT_TYPE_FAT12;
		temp_FAT_FileSysStruct_variable1.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &temp_FAT_FileSysStruct_variable1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemSetSupportMode_ifno_ifyes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetSupportMode_ifno_ifyes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_VolumeLabelGetByDriveIndex_if_yes_while_if_yes_if_yes_while_if_no") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true") )
			return &temp_FAT_FileSysStruct_variable1;
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp;
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;

	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_if_yes_") )
	{
		BOOLEAN flag = TRUE;
			printf("\nTRUE = %d\n",flag);
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes") )
	{
		BOOLEAN flag = TRUE;
			printf("\nTRUE = %d\n",flag);
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no") )
	{
		BOOLEAN flag = TRUE;
			printf("\nTRUE = %d\n",flag);
		tmp.FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return &tmp;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_if_no_if_no") )
	{
		tmp.FileSystemType = FILE_SYSTEM_TYPE_NONE;
			return &tmp;
	}    
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_eq_0_and_if_yes") )
	{
		return &u32Res;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATGetSectorNo_if_u32ClusterNo_ne_0_and_lt_2") )
	{
		return &u32Res;
	}

	return (&u32Res);
}

extern BOOLEAN msAPI_DataStreamIO_Tell_Logic0_CallmsAPI_FCtrl_FileTell = FALSE;
EXTERN_C_LINKAGE U32 msAPI_FCtrl_FileTell(U8 u8HandleNo);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_FCtrl_FileTell(U8 u8HandleNo)
{
	if( CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_Logic0") )
	{
		msAPI_DataStreamIO_Tell_Logic0_CallmsAPI_FCtrl_FileTell = TRUE;
	}
	return 0;
}

extern BOOLEAN msAPI_DataStreamIO_Tell_LongLong_CallmsAPI_FCtrl_FileTell_LongLong = FALSE;
EXTERN_C_LINKAGE LongLong msAPI_FCtrl_FileTell_LongLong(U8 u8HandleNo);
EXTERN_C_LINKAGE LongLong CppTest_Stub_msAPI_FCtrl_FileTell_LongLong(U8 u8HandleNo)
{
	LongLong u64temp;
	if (CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Tell_LongLong_Logic0"))
	{
		msAPI_DataStreamIO_Tell_LongLong_CallmsAPI_FCtrl_FileTell_LongLong = TRUE;
	}
	u64temp.Hi = 0;
	u64temp.Lo = 0;
	return u64temp;
}

MS_BOOL g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN msAPI_MSDCtrl_SectorRead(U8 u8DeviceIndex, U32 u32StartSector, U32 u32SectorCount, U32 u32BufferAddress);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MSDCtrl_SectorRead(U8 u8DeviceIndex, U32 u32StartSector, U32 u32SectorCount, U32 u32BufferAddress)
{
	BOOLEAN flag = TRUE;
	//printf("\nTRUE = %d\n",flag);
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE") )
	{
		return FALSE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindEmpty_if_s32CurrentDirEntryIndex_lt_0_msAPI_MSDCtrl_SectorRead_return_FALSE") )
	{
		return FALSE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes") )
	{
		printf("\nTRUE = %d\n",flag);
		return flag;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATFsinfoUpdate_Increase_if_msAPI_MSDCtrl_SectorRead_return_FALSE") )
	{
		return FALSE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if") )
	{
		printf("\nTRUE = %d\n",flag);
		return flag;
	}

	g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = FALSE;
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_1"))
	{
		g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = TRUE;
		return FALSE;
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_ReadMFTRecord_2"))
	{
		g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = TRUE;
		return TRUE;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_msAPI_MSDCtrl_SectorRead_fail"))
	{
		UT_MSG(printf("deviceIndex = 0x%x\nu32StartSector = 0x%x\nu32SectorCount = 0x%x\nu32BufferAddress = 0x%x\n",
				u8DeviceIndex, u32StartSector, u32SectorCount, u32BufferAddress););
		if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 0 == u32SectorCount
			&& 0 == u32BufferAddress
			)
		{
			gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead = TRUE;

		}
		return FALSE;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_no"))
	{
		UT_MSG(printf("deviceIndex = 0x%x\nu32StartSector = 0x%x\nu32SectorCount = 0x%x\nu32BufferAddress = 0x%x\n",
				u8DeviceIndex, u32StartSector, u32SectorCount, u32BufferAddress););
		if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 0 == u32SectorCount
			&& 0 == u32BufferAddress
			)
		{
			return TRUE;
		}
		else if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 1 == u32SectorCount
			&& 0 == u32BufferAddress
			)
		{
			gbTest_FAT_FATStructureFetch_CallmsAPI_MSDCtrl_SectorRead_Con_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes = TRUE;
			return FALSE;
		}

	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureFetch_if_u8FatType_eq_FAT_TYPE_FAT12_if_msAPI_MSDCtrl_SectorRead_yes"))
	{
		UT_MSG(printf("deviceIndex = 0x%x\nu32StartSector = 0x%x\nu32SectorCount = 0x%x\nu32BufferAddress = 0x%x\n",
				u8DeviceIndex, u32StartSector, u32SectorCount, u32BufferAddress););
		if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 0 == u32SectorCount
			&& 0 == u32BufferAddress
			)
		{
			return TRUE;
		}
		else if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 1 == u32SectorCount
			&& 0 == u32BufferAddress
			)
		{
			return TRUE;
		}

	}
	
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_0"))
    {
        g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = TRUE;
        return FALSE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_1"))
    {
        g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = TRUE;
        return TRUE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_2"))
    {
        g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = TRUE;
        return TRUE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_3"))
    {
        g_CppTest_Stub_msAPI_MSDCtrl_SectorRead_Return = TRUE;
        return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if1_msAPI_MSDCtrl_SectorRead_FALSE"))
    {
    	if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 1 == u32SectorCount
			&& 0 == u32BufferAddress
			)
    	{
    		gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead = TRUE;
			return FALSE;
    	}
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if2_u8RwDataCache_eq_NULL"))
    {
    	if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 1 == u32SectorCount
			&& 0 == u32BufferAddress
			)
    	{
    		gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead = TRUE;
    		return TRUE;
    	}
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_BootSectorRead_if3_BS_jmpBoot5b05d_ne_0xE9"))
    {
    	if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 1 == u32SectorCount
			&& 0 != u32BufferAddress
			)
    	{
    		gbTest_FAT_BootSectorRead_CallmsAPI_MSDCtrl_SectorRead = TRUE;
    		return TRUE;
    	}
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if2_msAPI_MSDCtrl_SectorRead_eq_FALSE"))
    {
    	if (0 == u8DeviceIndex
			&& 0 == u32StartSector
			&& 1 == u32SectorCount
			&& 0 == u32BufferAddress
			)
    	{
    		gbTest_FAT_FATFsinfoFetch_CallmsAPI_MSDCtrl_SectorRead = TRUE;
    		return FALSE;
    	}
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATFsinfoFetch_if3_pu8RwDataCache_eq_NULL"))
    {
    	return TRUE;
    }
	return FALSE;
}

MS_BOOL g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = FALSE;
EXTERN_C_LINKAGE void msAPI_FS_MIU_Copy(U32 srcaddr, U32 dstaddr, U32 len);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FS_MIU_Copy(U32 srcaddr, U32 dstaddr, U32 len)
{
	g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = FALSE;

	if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0"))
	{
		g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = TRUE;
		return;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1"))
	{
		g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = TRUE;
		return;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_0"))
	{
		g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = TRUE;
		return;
	}

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_1"))
    {
        g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = TRUE;
        return;
    }
    
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true") )
    {   
		return;
    }
    
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ResetDrives_for_for") )
    {   
        return;
    }

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetDriveByIndex_if_yes_if_yes") )
    {   
		return;
    }
}

MS_BOOL g_CppTest_Stub___N51FS_Attribute_Find_Return = FALSE;
EXTERN_C_LINKAGE N51FS_AttributeInfo __N51FS_Attribute_Find(U32 startMIUAddr,U32 destMIUAddr,EN_ATTRIBUTE_TYPE attrType, U16* u16Offset);
EXTERN_C_LINKAGE N51FS_AttributeInfo CppTest_Stub___N51FS_Attribute_Find(U32 startMIUAddr,U32 destMIUAddr,EN_ATTRIBUTE_TYPE attrType, U16* u16Offset)
{
	N51FS_AttributeInfo info;
	g_CppTest_Stub_msAPI_FS_MIU_Copy_Return = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 0x220;
        info.Residented = FALSE;
        return (info);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_0"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 0;
        info.Residented = FALSE;
        return (info);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_1"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 0;
        info.Residented = FALSE;
        return (info);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_2"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 1;
        info.Residented = FALSE;
        return (info);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_3"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 0x300;// > 0x200
        info.Residented = FALSE;
        return (info);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_4"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 1;
        info.Residented = FALSE;
        return (info);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_5"))
    {
        g_CppTest_Stub___N51FS_Attribute_Find_Return = TRUE;

        info.Size = 1;
        info.Residented = FALSE;
        return (info);
    }
    return info;
}

FAT_FileSysStruct temp_FAT_FileSysStruct_variable;
U16 u16Filename[4];
MS_BOOL g_CppTest_Stub_msAPI_FS_Memory_Allocate = FALSE;
EXTERN_C_LINKAGE void *msAPI_FS_Memory_Allocate(U16 u16Number_of_bytes);
EXTERN_C_LINKAGE void *CppTest_Stub_msAPI_FS_Memory_Allocate(U16 u16Number_of_bytes)
{
    g_CppTest_Stub_msAPI_FS_Memory_Allocate = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_0"))
    {
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return NULL;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_1"))
    {
    	IndexHeader obj;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&obj);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2"))
    {
    	IndexHeader obj;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&obj);
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3"))
    {
    	IndexHeader obj;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&obj);
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	IndexHeader obj;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&obj);
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	IndexHeader obj;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&obj);
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	IndexHeader obj;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&obj);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_1"))
    {
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return NULL;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1"))
    {
    	U8 u8Res = 1;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&u8Res);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_2"))
    {
    	U32 u32Res = 0xF0;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&u32Res);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_4"))
    {
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return NULL;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_Attribute_Find_5"))
    {
    	U32 u32Res = 0xF0;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return (&u32Res);
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_1"))
    {
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return NULL;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_2"))
    {
    	U8 ucRes[0x0F];
    	ucRes[0x0C] = FALSE;
    	ucRes[0x0D] = FALSE;
    	ucRes[0x0E] = FALSE;
    	ucRes[0x0F] = FALSE;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;

        return &ucRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_InitialFileSystem_3"))
    {
    	U8 ucRes = 1;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;
        return &ucRes;
    }


    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_1"))
    {
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;
        return NULL;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_2"))
    {
    	U8 ucRes = 1;
    	g_CppTest_Stub_msAPI_FS_Memory_Allocate = TRUE;
        return &ucRes;
    }
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if") )
	{
		u16Filename[0] = u16Filename[1] =u16Filename[2] =u16Filename[3] = 0xffff;
		return u16Filename;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes") )
	{
		u16Filename[0] = u16Filename[1] =u16Filename[2] =u16Filename[3] = 0xffff;
		return u16Filename;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes") )
	{
		u16Filename[0] = u16Filename[1] =u16Filename[2] =u16Filename[3] = 0xffff;
		return u16Filename;
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_if_pFileSys_equal_NULL") )
		return NULL;
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true") )
	{
		return &temp_FAT_FileSysStruct_variable;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_N51FS_bResult_equal_true") )
	{
		return &temp_FAT_FileSysStruct_variable;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemGetByID_if_no_if_no_else") )
	{
		return &temp_FAT_FileSysStruct_variable;
	}    
    return NULL;
}

MS_BOOL g_CppTest_Stub_N51FS_GetFileEntryByMFR = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_GetFileEntryByMFR(U8 u8fsid, U32 u32mfr, FileEntry *pFileToSet);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_GetFileEntryByMFR(U8 u8fsid, U32 u32mfr, FileEntry *pFileToSet)
{
	g_CppTest_Stub_N51FS_GetFileEntryByMFR = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_0"))
    {
    	g_CppTest_Stub_N51FS_GetFileEntryByMFR = TRUE;
        return TRUE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1"))
    {
    	g_CppTest_Stub_N51FS_GetFileEntryByMFR = TRUE;
    	pFileToSet->FileLength.Lo = 1;
        return TRUE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE"))
    {
    	g_CppTest_Stub_N51FS_GetFileEntryByMFR = TRUE;
    	pFileToSet->FileLength.Lo = 1;
        return TRUE;
    }
    return TRUE;
}
EXTERN_C_LINKAGE_START
MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileOpen = FALSE;
extern BOOLEAN bTest_msAPI_DataStreamIO_Open_CallmsAPI_FCtrl_FileOpen = FALSE;
EXTERN_C_LINKAGE_END
EXTERN_C_LINKAGE U8 msAPI_FCtrl_FileOpen(const FileEntry* pFileEntry, U8 u8OpenMode);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_FileOpen(const FileEntry* pFileEntry, U8 u8OpenMode)
{
	g_CppTest_Stub_msAPI_FCtrl_FileOpen = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_0"))
    {
    	g_CppTest_Stub_msAPI_FCtrl_FileOpen = TRUE;

        return 0xFF; // INVALID_FILE_HANDLE
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1"))
    {
    	g_CppTest_Stub_msAPI_FCtrl_FileOpen = TRUE;

        return 0;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE"))
    {
    	g_CppTest_Stub_msAPI_FCtrl_FileOpen = TRUE;

        return 0;
    }

    if(CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Open_Logic1"))
    {
    	if ((pFileEntry == NULL) && (u8OpenMode == 0))
    	{
    		bTest_msAPI_DataStreamIO_Open_CallmsAPI_FCtrl_FileOpen = TRUE;
    	}
    }
    return 0;
}

MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileSeek = FALSE;
extern BOOLEAN bTest_msAPI_DataStreamIO_Seek_CallmsAPI_FCtrl_FileSeek = FALSE;
extern BOOLEAN msAPI_DataStreamIO_Seek_LongLong_CallmsAPI_FCtrl_FileSeek = FALSE;
EXTERN_C_LINKAGE BOOLEAN msAPI_FCtrl_FileSeek(U8 u8HandleNo, U32 u32Length, EN_FILE_SEEK_OPTION option);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_FCtrl_FileSeek(U8 u8HandleNo, U32 u32Length, EN_FILE_SEEK_OPTION option)
{
	g_CppTest_Stub_msAPI_FCtrl_FileSeek = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1"))
    {
    	g_CppTest_Stub_msAPI_FCtrl_FileSeek = TRUE;

        return TRUE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE"))
    {
    	g_CppTest_Stub_msAPI_FCtrl_FileSeek = TRUE;

        return TRUE;
    }
    
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes") )
	{
		g_CppTest_Stub_msAPI_FCtrl_FileSeek = TRUE;
		return FALSE;
	}

	if( CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_Logic0_case_E_DATA_STREAM_SEEK_SET") )
	{
		if (option == FILE_SEEK_SET)
		{
			bTest_msAPI_DataStreamIO_Seek_CallmsAPI_FCtrl_FileSeek = TRUE;
		}
	}

	if( CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Seek_LongLong_Logic0_E_DATA_STREAM_SEEK_SET") )
	{
		if (option == FILE_SEEK_SET)
		{
			msAPI_DataStreamIO_Seek_LongLong_CallmsAPI_FCtrl_FileSeek = TRUE;
		}
	}
    return FALSE;
}

extern MS_BOOL g_CppTest_Stub_N51FS_ReadMFTRecord_Return = FALSE;
EXTERN_C_LINKAGE U32 N51FS_ReadMFTRecord(U8 fileSystemID,U32 MFR,U32 destMIUAddr);
EXTERN_C_LINKAGE U32 CppTest_Stub_N51FS_ReadMFTRecord(U8 fileSystemID,U32 MFR,U32 destMIUAddr)
{
	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 1;
    }

    if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 1;
    }

    if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_0_equal_N51FS_ReadMFTRecord"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 0;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_0"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 0;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_1"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 1;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_2"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 1;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_0"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 0;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileRecordFindVolumeLabel_1"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 1;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_0"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 0;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1"))
    {
    	g_CppTest_Stub_N51FS_ReadMFTRecord_Return = TRUE;

        return 1;
    }
    return 0;
}

MS_BOOL g_CppTest_Stub_N51FS_Attribute_Find_Return = FALSE;
EXTERN_C_LINKAGE N51FS_AttributeInfo N51FS_Attribute_Find(U8 fsid,U32 startMIUAddr,U32 destMIUAddr,EN_ATTRIBUTE_TYPE attrType, U16* pu16Offset,  U32 lowestVCN);
EXTERN_C_LINKAGE N51FS_AttributeInfo CppTest_Stub_N51FS_Attribute_Find(U8 fsid,U32 startMIUAddr,U32 destMIUAddr,EN_ATTRIBUTE_TYPE attrType, U16* pu16Offset,  U32 lowestVCN)
{
	N51FS_AttributeInfo stAttrInfo;
	g_CppTest_Stub_N51FS_Attribute_Find_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_pBuff_add_u16AttrOffset_add_8_equal_0"))
    {
    	g_CppTest_Stub_N51FS_Attribute_Find_Return = TRUE;
    	stAttrInfo.Size = 1;

        return stAttrInfo;
    }

    if (CppTest_IsCurrentTestCase("TestSuit_N51FS_Bitmap_test_N51FS_Bitmap_MFRFree_if_info2eSize_equal_0"))
    {
    	g_CppTest_Stub_N51FS_Attribute_Find_Return = TRUE;

        return stAttrInfo;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_0"))
    {
    	g_CppTest_Stub_N51FS_Attribute_Find_Return = TRUE;

        return stAttrInfo;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_1"))
    {
    	g_CppTest_Stub_N51FS_Attribute_Find_Return = TRUE;
    	stAttrInfo.Size = 0;

        return stAttrInfo;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFileEntryByMFR_2"))
    {
    	g_CppTest_Stub_N51FS_Attribute_Find_Return = TRUE;
    	stAttrInfo.Size = 1;

        return stAttrInfo;
    }
    return stAttrInfo;
}

MS_BOOL g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = FALSE;
FS_EnvironmentStruct tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment = {0,0,0,0,0};
EXTERN_C_LINKAGE FS_EnvironmentStruct* msAPI_FSEnv_GetEnvironment(U8 u8HandleNo);
EXTERN_C_LINKAGE FS_EnvironmentStruct* CppTest_Stub_msAPI_FSEnv_GetEnvironment(U8 u8HandleNo)
{
	FS_EnvironmentStruct * opRes;
	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindEmpty_if_s32CurrentDirEntryIndex_lt_0_msAPI_MSDCtrl_SectorRead_return_FALSE"))
    {
    	FS_EnvironmentStruct obj;
    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectoryFreeDirEntry_if_msAPI_FSEnv_GetEnvironment_return_NULL"))
    {
        return NULL;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL"))
    {
    	FS_EnvironmentStruct obj;
    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NULL"))
    {
    	return NULL;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryNext_1"))
    {
    	FS_EnvironmentStruct obj;

    	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryNext_2"))
    {
    	FS_EnvironmentStruct obj;

    	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryNext_4"))
    {
    	FS_EnvironmentStruct obj;

    	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_SaveEnvironment"))
    {
    	FS_EnvironmentStruct obj;

    	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_0"))
    {
    	FS_EnvironmentStruct obj;

    	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetFileNameByFileEntry_1"))
    {
    	FS_EnvironmentStruct obj;

    	g_CppTest_Stub_msAPI_FSEnv_GetEnvironment_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    
	printf("\nstart = %d\n",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		printf("\nFILE_SYSTEM_TYPE_FAT = %d",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		printf("\nFILE_SYSTEM_TYPE_FAT = %d",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		printf("\nFILE_SYSTEM_TYPE_FAT = %d",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_equal_NULL") )
	{
		return 0;//TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT
	}
	if( 	CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT") || \
			CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT")
	)
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		printf("\nFILE_SYSTEM_TYPE_FAT = %d",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(		CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS") || \
			CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS")
			)
	{

		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_N51FS;
        //printf("\nFILE_SYSTEM_TYPE_N51FS = %d",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(		CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE") || \
			CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_NONE")
			)
	{

		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_NONE;
        //printf("\nFILE_SYSTEM_TYPE_N51FS = %d",tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType);
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_equal_NULL") )
	{
		return NULL;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_N51FS;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemID = 0;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes") )
	{
		tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment.u8FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return &tmp_CppTest_Stub_msAPI_FSEnv_GetEnvironment;
	}

	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryNext_if_pFS_Env_eq_NULL") )
	{
		return NULL;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectoryChange_if_pFS_Env_eq_NULL") )
	{
		return NULL;
	}


    return opRes;
}

MS_BOOL g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = FALSE;
EXTERN_C_LINKAGE N51FS_FileHandle* N51FS_File_GetHandleInfo(U8 fileHandleID);
EXTERN_C_LINKAGE N51FS_FileHandle* CppTest_Stub_N51FS_File_GetHandleInfo(U8 fileHandleID)
{
	N51FS_FileHandle * opRes;
	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2"))
    {
    	N51FS_FileHandle obj;
    	obj.DataResidented = FALSE;

    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3"))
    {
    	N51FS_FileHandle obj;
    	obj.DataResidented = TRUE;
    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileLength_0"))
    {
    	N51FS_FileHandle obj;

    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileLength_1"))
    {
    	N51FS_FileHandle obj;

    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileTell_1"))
    {
    	N51FS_FileHandle obj;

    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_HandlePostCreate"))
    {
    	N51FS_FileHandle obj;

    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileRead_1"))
    {
    	N51FS_FileHandle obj;
    	obj.DataResidented = TRUE;
    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileRead_2"))
    {
    	N51FS_FileHandle obj;
    	obj.DataResidented = FALSE;
    	obj.u8CompressFlag = FALSE;
    	g_CppTest_Stub_N51FS_File_GetHandleInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }
    return opRes;
}

MS_BOOL g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return = FALSE;
EXTERN_C_LINKAGE IndexVars* N51FS_GetIndexVarsInfo(U8 enid);
EXTERN_C_LINKAGE IndexVars* CppTest_Stub_N51FS_GetIndexVarsInfo(U8 enid)
{
	IndexVars * opRes;
	g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentNameToMIU_2"))
    {
    	IndexVars obj;

    	g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryGetCurrentFileEntry"))
    {
    	IndexVars obj;

    	g_CppTest_Stub_N51FS_GetIndexVarsInfo_Return = TRUE;

    	opRes = &obj;
        return opRes;
    }

    return opRes;
}

FAT_FileHandle bill_tmp;
EXTERN_C_LINKAGE FAT_FileHandle* FAT_File_GetHandleInfo(U8 u8FileHandleID);
EXTERN_C_LINKAGE FAT_FileHandle* CppTest_Stub_FAT_File_GetHandleInfo(U8 u8FileHandleID)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileClose_return_true"))
	{
		FILE_HANDLE_POOL = &bill_tmp;
		bill_tmp.u32FileCurrentSectorNo = 0;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE"))
	{
		FILE_HANDLE_POOL = &bill_tmp;
		bill_tmp.u32FileCurrentSectorNo = 0;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_HandlePostCreate_end"))
	{
		FILE_HANDLE_POOL = &bill_tmp;
		bill_tmp.u32FileCurrentSectorNo = 0;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0"))
	{
		FILE_HANDLE_POOL = &bill_tmp;
		bill_tmp.u32FileCurrentSectorNo = 0;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0"))
	{
		FAT_FileHandle tmp;
		FILE_HANDLE_POOL = &tmp;
		tmp.u32FileCurrentSectorNo = 0;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileWrite_if_pFATInode_eq_NULL"))
	{
		FAT_FileHandle tmp;
		FILE_HANDLE_POOL = &tmp;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileSeek_if_pFATInode_eq_NULL"))
	{
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL"))
	{
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileRead_if_pFATInode_eq_NULL"))
	{
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileOpen_if_pFATInode_eq_NULL"))
	{
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_yes"))
	{
		if(0 == u8FileHandleID)
		{
			gbTest_FAT_File_GetInodeFromHandle_CallFAT_File_GetHandleInfo = TRUE;
		}
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}

	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_no"))
	{
		if(0 == u8FileHandleID)
		{
			gbTest_FAT_File_GetInodeFromHandle_CallFAT_File_GetHandleInfo = TRUE;
		}
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}

	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL"))
	{
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32"))
	{
	bill_tmp.u32FileCurrentClusterNo = 0;
	bill_tmp.u32FileCurrentSectorNo = 0;
	bill_tmp.u16ClusterChainIndex = 0;
	FILE_HANDLE_POOL = &bill_tmp;
	return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16"))
	{
		bill_tmp.u32FileCurrentClusterNo = 0;
		bill_tmp.u32FileCurrentSectorNo = 0;
		bill_tmp.u16ClusterChainIndex = 0;
		FILE_HANDLE_POOL = &bill_tmp;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL"))
	{
		bill_tmp.u32FileCurrentClusterNo = 0;
		bill_tmp.u32FileCurrentSectorNo = 0;
		bill_tmp.u16ClusterChainIndex = 0;
		FILE_HANDLE_POOL = &bill_tmp;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed"))
	{
		bill_tmp.u32FileCurrentClusterNo = 0;
		bill_tmp.u32FileCurrentSectorNo = 0;
		bill_tmp.u16ClusterChainIndex = 0;
		FILE_HANDLE_POOL = &bill_tmp;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed"))
	{
		bill_tmp.u32FileCurrentClusterNo = 0;
		bill_tmp.u32FileCurrentSectorNo = 0;
		bill_tmp.u16ClusterChainIndex = 0;
		FILE_HANDLE_POOL = &bill_tmp;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else"))
	{
		bill_tmp.u32FileCurrentClusterNo = 0;
		bill_tmp.u32FileCurrentSectorNo = 0;
		bill_tmp.u16ClusterChainIndex = 0;
		FILE_HANDLE_POOL = &bill_tmp;
		return (FAT_FileHandle *)FILE_HANDLE_POOL;
	}

	return (FAT_FileHandle *)0;
}

FileInodeStruct tmp_FileInodeStruct;

FAT_FileInode _pFATInode;
FAT_FileInode *pFATInode;
EXTERN_C_LINKAGE FileInodeStruct *FCtrl_GetFileInodeInfo(U8 u8InodeID);
EXTERN_C_LINKAGE FileInodeStruct *CppTest_Stub_FCtrl_GetFileInodeInfo(U8 u8InodeID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true"))
	{
		pFATInode= &_pFATInode;
		pFATInode->u32FileStartClusterNo = 0;
		pFATInode->bIsClusterChainActive = TRUE;
		// printf("pFATInode = %d\n", );
		return pFATInode;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_HandlePostCreate_end"))
	{
		pFATInode= &_pFATInode;
		pFATInode->u32FileStartClusterNo = 0;
		// printf("pFATInode = %d\n", );
		return pFATInode;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0"))
	{
		pFATInode= &_pFATInode;
		pFATInode->u32FileStartClusterNo = 0;
		// printf("pFATInode = %d\n", );
		return pFATInode;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileWrite_if_pFATInode_eq_NULL"))
	{
		return NULL;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_File_GetInodeFromHandle_if_no"))
	{
		if (0xfe == u8InodeID)
		{
			gbTest_FAT_File_GetInodeFromHandle_CallFCtrl_GetFileInodeInfo = TRUE;
		}
		return (FileInodeStruct *)0;
	}
    
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno") )
    {   
		return &tmp_FileInodeStruct;
    }

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_GetNextCluster_if_pFATInode_eq_NULL") )
    {
		return NULL;
    }
	return &tmp_FileInodeStruct;    
}

EXTERN_C_LINKAGE EN_FAT_TYPE FAT_FATGetType( U8 *pu8FileType );
EXTERN_C_LINKAGE EN_FAT_TYPE CppTest_Stub_FAT_FATGetType( U8 *pu8FileType )
{
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_NOT_SUPPORT"))
	{
		if (*pu8FileType == 0)
		{
			gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType = TRUE;
		}
		return FAT_TYPE_NOT_SUPPORT;
	}

	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT32_and_if_u32FATTotalClusterNo_gt_0xFFFFFF7"))
	{
		if (*pu8FileType == 0)
		{
			gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType = TRUE;
		}
		return FAT_TYPE_FAT32;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12"))
	{
		if (*pu8FileType == 0)
		{
			gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetType = TRUE;
		}
		return FAT_TYPE_FAT16;
	}
}

EXTERN_C_LINKAGE U32 FAT_FATGetMaxClusterNo( U32 u32FATSize, EN_FAT_TYPE FATType );
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_FATGetMaxClusterNo( U32 u32FATSize, EN_FAT_TYPE FATType )
{
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureReadRoot_if_u8FATType_eq_FAT_TYPE_FAT16_or_FAT_TYPE_FAT12"))
	{
		if (FATType == FAT_TYPE_FAT16
			&& u32FATSize == 0)
		{
			gbTest_FAT_FATStructureReadRoot_CallFAT_FATGetMaxClusterNo = TRUE;
		}
		return 0;
	}
}

U32  FAT_FATStructureRead( U8 u8fsid, U32 u32DirEntryClusterNo);
U32  CppTest_Stub_FAT_FATStructureRead( U8 u8fsid, U32 u32DirEntryClusterNo)
{
	if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureGetNextCluster_if_u8FatType_ne_FAT_TYPE_NOT_SUPPORT"))
	{
		if (u8fsid == 0
			&& u32DirEntryClusterNo == 0)
		{
			gbTest_FAT_FATStructureGetNextCluster_CallFAT_FATStructureRead = TRUE;
		}
		return 0;
	}
}


MS_BOOL g_CppTest_Stub_msAPI_FCtrl_FileRead_Return = FALSE;
extern BOOLEAN bTest_msAPI_DataStreamIO_Read_CallmsAPI_FCtrl_FileRead = FALSE;
EXTERN_C_LINKAGE U32 msAPI_FCtrl_FileRead(U8 u8HandleNo, U32 u32Buffer, U32 u32Length);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_FCtrl_FileRead(U8 u8HandleNo, U32 u32Buffer, U32 u32Length)
{
	U32 u32Reg = 0;
	g_CppTest_Stub_msAPI_FCtrl_FileRead_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1"))
    {
    	u32Reg = 0x1000;
    	g_CppTest_Stub_msAPI_FCtrl_FileRead_Return = TRUE;
        return u32Reg;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_GetFreeSpaceInKB_1_ELSE"))
    {
    	u32Reg = 1;
    	g_CppTest_Stub_msAPI_FCtrl_FileRead_Return = TRUE;
        return u32Reg;
    }
    if (CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Read_Logic0"))
    {
    	bTest_msAPI_DataStreamIO_Read_CallmsAPI_FCtrl_FileRead = TRUE;
    }
    return u32Reg;
}


MS_BOOL g_CppTest_Stub_LL_iszero_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN LL_iszero(LongLong *pX);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_LL_iszero(LongLong *pX)
{
	g_CppTest_Stub_LL_iszero_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes"))
    {
    	g_CppTest_Stub_LL_iszero_Return = TRUE;

    	LongLong obj;
    	obj.Hi = 1;
    	obj.Lo = 1;
    	pX = &obj;
        return FALSE;
    }

    return FALSE;
}

EXTERN_C_LINKAGE BOOLEAN FAT_Cache_DirectoryClusterFetch(U8 u8EnvironmentId);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_Cache_DirectoryClusterFetch(U8 u8EnvironmentId)
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL"))
    {
    	return FALSE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_ReadMFT_LSN_Return = FALSE;
EXTERN_C_LINKAGE U32 N51FS_ReadMFT_LSN(U8 fileSystemID, U32 MFR);
EXTERN_C_LINKAGE U32 CppTest_Stub_N51FS_ReadMFT_LSN(U8 fileSystemID, U32 MFR)
{
	g_CppTest_Stub_N51FS_ReadMFT_LSN_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_WriteMFTRecord_0"))
    {
    	g_CppTest_Stub_N51FS_ReadMFT_LSN_Return = TRUE;
    	return TRUE;
    }

    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Delete_Index_Search_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_Index_Search(FileEntry *pFileToFind);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_Index_Search(FileEntry *pFileToFind)
{
	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_1"))
    {
    	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = TRUE;
    	return FALSE;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2"))
    {
    	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3"))
    {
    	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_Delete_Index_Search_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_RemoveNode(U8 fsid);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_RemoveNode(U8 fsid)
{
	g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveNode_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_RemoveLeaf(U8 fsid);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_RemoveLeaf(U8 fsid)
{
	g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = TRUE;
    	return FALSE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_Delete_RemoveLeaf_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_WriteMFTRecord_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_WriteMFTRecord(U8 fileSystemID,U32 MFR,U32 SrcMIUaddr);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_WriteMFTRecord(U8 fileSystemID,U32 MFR,U32 SrcMIUaddr)
{
	g_CppTest_Stub_N51FS_WriteMFTRecord_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2"))
    {
    	g_CppTest_Stub_N51FS_WriteMFTRecord_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3"))
    {
    	g_CppTest_Stub_N51FS_WriteMFTRecord_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	g_CppTest_Stub_N51FS_WriteMFTRecord_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_WriteMFTRecord_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_WriteMFTRecord_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_MarkMFTRecordUnused(U8 fsid, U32 MFR);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused(U8 fsid, U32 MFR)
{
	g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2"))
    {
    	g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_3"))
    {
    	g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = TRUE;
    	return FALSE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_Delete_MarkMFTRecordUnused_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Bitmap_ClusterFreeByMFR_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Bitmap_ClusterFreeByMFR(U8 u8fsid, U32 u32MFR);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Bitmap_ClusterFreeByMFR(U8 u8fsid, U32 u32MFR)
{
	g_CppTest_Stub_N51FS_Bitmap_ClusterFreeByMFR_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_4"))
    {
    	g_CppTest_Stub_N51FS_Bitmap_ClusterFreeByMFR_Return = TRUE;
    	return FALSE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_Bitmap_ClusterFreeByMFR_Return = TRUE;
    	return TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_Bitmap_ClusterFreeByMFR_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Bitmap_MFRFree_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Bitmap_MFRFree(U8 u8fsid, U32 u32MFR);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Bitmap_MFRFree(U8 u8fsid, U32 u32MFR)
{
	g_CppTest_Stub_N51FS_Bitmap_MFRFree_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_5"))
    {
    	g_CppTest_Stub_N51FS_Bitmap_MFRFree_Return = TRUE;
    	return FALSE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_6"))
    {
    	g_CppTest_Stub_N51FS_Bitmap_MFRFree_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Index_ToFirst_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_Index_ToFirst(U8 enid);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Index_ToFirst(U8 enid)
{
	g_CppTest_Stub_N51FS_Index_ToFirst_Return = FALSE;

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryFirst_0"))
    {
    	g_CppTest_Stub_N51FS_Index_ToFirst_Return = TRUE;
    	return TRUE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_N51FS_Index_Next_Return = FALSE;
EXTERN_C_LINKAGE EN_N51FS_INDEX_NEXT_RESULT N51FS_Index_Next(U8 enid, FileEntry* pFileToSet);
EXTERN_C_LINKAGE EN_N51FS_INDEX_NEXT_RESULT CppTest_Stub_N51FS_Index_Next(U8 enid, FileEntry* pFileToSet)
{
	g_CppTest_Stub_N51FS_Index_Next_Return = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryNext_1"))
    {
    	g_CppTest_Stub_N51FS_Index_Next_Return = TRUE;
    	return N51FS_INDEX_NEXT_RESULT_ERROR;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryNext_2"))
    {
    	g_CppTest_Stub_N51FS_Index_Next_Return = TRUE;
    	return N51FS_INDEX_NEXT_RESULT_LAST;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_EntryNext_4"))
    {
    	g_CppTest_Stub_N51FS_Index_Next_Return = TRUE;
    	return N51FS_INDEX_NEXT_RESULT_SUCCESS;
    }
    return N51FS_INDEX_NEXT_RESULT_SUCCESS;
}

MS_BOOL g_CppTest_Stub_N51FS_File_OpenFileRecord_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN N51FS_File_OpenFileRecord(U8 fhid,U32 MFR);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_File_OpenFileRecord(U8 fhid,U32 MFR)
{
	g_CppTest_Stub_N51FS_File_OpenFileRecord_Return = FALSE;
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileOpen_0"))
    {
    	g_CppTest_Stub_N51FS_File_OpenFileRecord_Return = TRUE;
    	return FALSE;
    }
    return FALSE;
}

MS_BOOL g_CppTest_Stub_LL_assign_Return = FALSE;
EXTERN_C_LINKAGE void LL_assign(LongLong* pX,U32 val);
EXTERN_C_LINKAGE void CppTest_Stub_LL_assign(LongLong* pX,U32 val)
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileLength_0"))
    {
    	g_CppTest_Stub_LL_assign_Return = TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileLength_1"))
    {
    	g_CppTest_Stub_LL_assign_Return = TRUE;
    }
    return ;
}

MS_BOOL g_CppTest_Stub_LL_greater_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN LL_greater(LongLong* pX,LongLong* pY);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_LL_greater(LongLong* pX,LongLong* pY)
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2"))
    {
    	g_CppTest_Stub_LL_greater_Return = TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3"))
    {
    	g_CppTest_Stub_LL_greater_Return = TRUE;
    }
    return TRUE;
}

MS_BOOL g_CppTest_Stub_LL_equal_Return = FALSE;
EXTERN_C_LINKAGE BOOLEAN LL_equal(LongLong* pX,LongLong* pY);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_LL_equal(LongLong* pX,LongLong* pY)
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_2"))
    {
    	g_CppTest_Stub_LL_equal_Return = TRUE;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileSeek_3"))
    {
    	g_CppTest_Stub_LL_equal_Return = TRUE;
    }
    return TRUE;
}

EXTERN_C_LINKAGE U32 FAT_FATGetSectorNo( U8 u8fsid, U32 u32ClusterNo );
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_FATGetSectorNo( U8 u8fsid, U32 u32ClusterNo )
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindVolumeLabel_if_msAPI_MSDCtrl_SectorRead_return_FALSE"))
    {
    	return 0;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindEmpty_if_s32CurrentDirEntryIndex_lt_0_msAPI_MSDCtrl_SectorRead_return_FALSE"))
    {
    	return 0;
    }
}

EXTERN_C_LINKAGE U32 FAT_GetNextCluster(FAT_FileHandle * pstFAT_FileHandle, U8 u8BPB_SecPerClus, U16 u16BytePerSec,  U8 u8FATType, U32 u32FATTotalClusterNo, U32 u32AppendLength);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_GetNextCluster(FAT_FileHandle * pstFAT_FileHandle, U8 u8BPB_SecPerClus, U16 u16BytePerSec,  U8 u8FATType, U32 u32FATTotalClusterNo, U32 u32AppendLength)
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileWrite_if_u32FileCurrentClusterNo_eq_0_and_u32StartClusterNO_eq_0"))
    {

    	return FAT_CLUSTER_NOT_USED;
    }
}

EXTERN_C_LINKAGE U32 FAT_FATTableUpdate(U8 u8fsid, U32 clusterNo, U32 u32ClusterNeeded);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_FATTableUpdate(U8 u8fsid, U32 clusterNo, U32 u32ClusterNeeded)
{
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0"))
    {
    	return 0;
    }
}


EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_Index_GotoParent(U8 fsid);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_Index_GotoParent(U8 fsid)
{
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
}

EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_Index_GotoChild(U8 fsid);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_Index_GotoChild(U8 fsid)
{

    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
}

EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_Index_GotoNextEntry(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_Index_GotoNextEntry(void)
{
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
}

EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_InsertEntry(U32 u32Offset);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_InsertEntry(U32 u32Offset)
{
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
}

EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_ReplaceSubNodeVCN(U8* u8SubNodeVCN);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_ReplaceSubNodeVCN(U8* u8SubNodeVCN)
{
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
}

EXTERN_C_LINKAGE BOOLEAN N51FS_Delete_Index_GotoPrevEntry(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_Delete_Index_GotoPrevEntry(void)
{
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_enter"))
    {
    	return 0;
    }
}




BOOLEAN N51FS_Delete_RemoveEntry(U8* pu8SubNodeVCN);
BOOLEAN CppTest_Stub_N51FS_Delete_RemoveEntry(U8* pu8SubNodeVCN)
{

    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine"))
    {
    	return 1;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_N51FS_Index_test_N51FS_Delete_Combine_left"))
    {
    	return 1;
    }
}

EXTERN_C_LINKAGE BOOLEAN FAT_PartitionTableRead( FAT_FileSysStruct *pstFileSys, U32 logicalBlockAddress,U8 *u8partitionBytes );
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_PartitionTableRead( FAT_FileSysStruct *pstFileSys, U32 logicalBlockAddress,U8 *u8partitionBytes )
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_InitialFileSystem_if_FAT_PartitionTableRead_return_false"))
	{
		return FALSE;
	}
	return FALSE;
}

EXTERN_C_LINKAGE U32* FCtrl_GetFatTableCacheInfo(U8 fsid);
EXTERN_C_LINKAGE U32* CppTest_Stub_FCtrl_GetFatTableCacheInfo(U8 fsid)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL"))
	{
		return NULL;
	}
	return NULL;
}

EXTERN_C_LINKAGE U32 msAPI_FS_ConvertStTime2Seconds ( FS_TIME *pstTime );
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_FS_ConvertStTime2Seconds ( FS_TIME *pstTime )
{
}



File_ClusterChain ClusterChain;
File_ClusterChain* pClusterChain = &ClusterChain;
EXTERN_C_LINKAGE File_ClusterChain* FAT_File_GetHandleClusterChainInfo(U8 u8FileInodeID);
EXTERN_C_LINKAGE File_ClusterChain* CppTest_Stub_FAT_File_GetHandleClusterChainInfo(U8 u8FileInodeID)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_GetRemainSectors_if_bIsClusterChainActive_is_true"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_curIndex_is_CLUSTER_CHAIN_SIZE"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else"))
	{
		memset(pClusterChain, 0, sizeof(File_ClusterChain));
		return pClusterChain;
	}

	return NULL;
}
EXTERN_C_LINKAGE BOOLEAN FAT_FAT32ClusterChainScan(U8 u8fsid, U32 u32StartClusterNo, U32 *u32LenToSet, U32 *NextClusterToSet);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FAT32ClusterChainScan(U8 u8fsid, U32 u32StartClusterNo, U32 *u32LenToSet, U32 *NextClusterToSet)
{
	    if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT32"))
	    {
	    	*u32LenToSet=0;
	    	*NextClusterToSet = 0;
			return FALSE;
		}

	return FALSE;
}
EXTERN_C_LINKAGE BOOLEAN FAT_FAT16ClusterChainScan(U8 u8fsid, U32 u32StartClusterNo, U32 *u32LenToSet, U32 *NextClusterToSet);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FAT16ClusterChainScan(U8 u8fsid, U32 u32StartClusterNo, U32 *u32LenToSet, U32 *NextClusterToSet)
{
		if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_FAT_TYPE_FAT16"))
		{
			*u32LenToSet=0;
			*NextClusterToSet = 0;
			return FALSE;
		}

	return FALSE;
}
EXTERN_C_LINKAGE BOOLEAN FAT_FAT12ClusterChainScan(U8 u8fsid, U32 u32StartClusterNo, U32 *u32LenToSet, U32 *NextClusterToSet);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FAT12ClusterChainScan(U8 u8fsid, U32 u32StartClusterNo, U32 *u32LenToSet, U32 *NextClusterToSet)
{
	    *u32LenToSet=0;
		if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_u8FatType_is_NULL"))
		{
			*NextClusterToSet = 0x0FFFFFF8;
			return FALSE;
		}
		else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed"))
		{
			*NextClusterToSet = 0x0FFFFFF8;
			return TRUE;
		}
		else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed"))
		{
			*NextClusterToSet = 0x0FFFFFF8;
			return FALSE;
		}
		else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else"))
		{
			*NextClusterToSet = 0x0FFFFFF8;
			return TRUE;
		}
	return FALSE;
}


//EXTERN_C_LINKAGE FAT_FileHandle* FAT_File_GetHandleInfo(U8 u8FileHandleID);
//EXTERN_C_LINKAGE FAT_FileHandle* CppTest_Stub_FAT_File_GetHandleInfo(U8 u8FileHandleID)
