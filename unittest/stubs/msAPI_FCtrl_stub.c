#include "cpptest.h"
/*
 * msAPI_FCtrl_stub.c
 *
 *  Created on: 17 Oct 2013
 *      Author: muters
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MsOS.h"
#include "apiAUDIO.h"
#include "apiCEC.h"
#include "apiDMX.h"
#include "apiGFX.h"
#include "apiGOP.h"
#include "apiJPEG.h"
#include "apiMHL.h"
#include "apiPNL.h"
#include "apiSWI2C.h"
#include "apiVDEC.h"
#include "drvXC_IOPort.h"
#include "apiXC.h"
#include "apiXC_Ace.h"
#include "apiXC_Adc.h"
#include "apiXC_Auto.h"
#include "apiXC_Dlc.h"
#include "apiXC_ModeParse.h"
#include "apiXC_PCMonitor.h"
#include "drvXC_HDMI_if.h"
#include "apiXC_Hdmi.h"
#include "drvAUDIO.h"
#include "drvAVD.h"
#include "drvBDMA.h"
#include "drvCPU.h"
#include "drvDDC2BI.h"
#include "drvDMD_INTERN_DVBC.h"
#include "drvDMD_INTERN_DVBT.h"
#include "drvDMD_VD_MBX.h"
#include "drvDMX_TTX.h"
#include "drvDSCMB.h"
#include "drvGPIO.h"
#include "drvGlobal.h"
#include "drvIPAUTH.h"
#include "drvIR.h"
#include "drvMBX.h"
#include "drvMIU.h"
#include "drvMMIO.h"
#include "drvMVOP.h"
#include "drvPCMCIA.h"
#include "drvPM.h"
#include "drvPWM.h"
#include "drvPWS.h"
#include "drvPQ.h"
#include "drvSAR.h"
#include "drvSEM.h"
#include "drvSERFLASH.h"
#include "drvSYS.h"
#include "drvTVEncoder.h"
#include "drvUART.h"
#include "drvUSB.h"
#include "drvVBI.h"
#include "drvVIF.h"
#include "drvXC_HDMI_if.h"
#include "hwreg_utility2.h"
#include "mapp_demux.h"
#include "mapp_eit.h"
#include "mapp_epgdb_public.h"
#include "MApp_PCMode.h"
#include "mapp_si.h"
#include "mapp_swupdate.h"
#include "msAPI_CI.h"
#include "msAPI_Font.h"
#include "msAPI_Tuning.h"
#include "msAPI_HuffmanDecode.h"
#include "msAPI_MHEG5.h"
#include "mapp_mheg5.h"
#include "msAPI_MSDCtrl.h"
#include "msAPI_Subtitle_Pub.h"
#include "msAPI_oad_process.h"
#include "msAPI_Video.h"
#include "ms_decompress.h"
#include "stdio.h"
#include "datatype.h"
#include "ZUI_tables_h.inl"
#include "SysInit.h"
#include "msAPI_Global.h"
#include "mw_usbdownload.h"
#include "msAPI_FSEnv.h"
#include "msAPI_FCtrl.h"
#include "msAPI_FAT.h"
#include "msAPI_N51FS.h"


/** User stub definition for function: MS_U8 MApi_XC_WaitInputVSync(MS_U8, MS_U16, SCALER_WIN) */
FileHandleStruct tmp_FileHandleStruct;
MS_BOOL g_CppTest_Stub_FCtrl_GetFileHandleInfo_Return = FALSE;
EXTERN_C_LINKAGE FileHandleStruct *FCtrl_GetFileHandleInfo(U8 u8FileHandleID);
EXTERN_C_LINKAGE FileHandleStruct *CppTest_Stub_FCtrl_GetFileHandleInfo(U8 u8FileHandleID)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetByHandle_ifno_ifno_ifno") )
	{
		tmp_FileHandleStruct.HandleID = 1;
		tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
		return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileWrite_ifno_ifno_ifyes") )
	{
		tmp_FileHandleStruct.HandleID = 1;
		tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
		return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes") )
	{
		tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
		return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes") )
	{
		tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
		return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FCtrl_CopyFileHandleInfo") )
    {   
        g_CppTest_Stub_FCtrl_GetFileHandleInfo_Return = TRUE;
		return 0;
    }
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes") )
	{
		tmp_FileHandleStruct.HandleID = INVALID_FILE_HANDLE;
		return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleFree_if_no") )
	{
			tmp_FileHandleStruct.HandleID = INVALID_FILE_HANDLE;
			return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes") )
	{
			tmp_FileHandleStruct.HandleID = 1;
			printf("\nstart = %d\n",tmp_FileHandleStruct.HandleID);
			return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes") )
	{
			tmp_FileHandleStruct.HandleID = 1;
			printf("\nstart = %d\n",tmp_FileHandleStruct.HandleID);
			return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_if_yes_") )
	{
			tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
			return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes") )
	{
			tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
			return &tmp_FileHandleStruct;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no") )
	{
			tmp_FileHandleStruct.FileSystemID = FILE_SYSTEM_TYPE_FAT;
			return &tmp_FileHandleStruct;
	}
}

EXTERN_C_LINKAGE BOOLEAN FAT_DirectroyDirEntryToFirst(U8 u8EnvironmentID);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_DirectroyDirEntryToFirst(U8 u8EnvironmentID)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT") )
	{
		return TRUE;
	}
}

EXTERN_C_LINKAGE BOOLEAN N51FS_EntryFirst(U8 enId);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_EntryFirst(U8 enId)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryFirst_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS") )
	{
		return TRUE;
	}
}

EN_ENTRY_NEXT_RESULT FAT_DirEntryNext(U8 enId,FileEntry* pFileToSet);
EN_ENTRY_NEXT_RESULT CppTest_Stub_FAT_DirEntryNext(U8 enId,FileEntry* pFileToSet)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_FAT") )
	{
		return ENTRY_NEXT_RESULT_SUCCESS;
	}
}

EXTERN_C_LINKAGE EN_ENTRY_NEXT_RESULT N51FS_EntryNext(U8 enId,FileEntry* pFileToSet);
EXTERN_C_LINKAGE EN_ENTRY_NEXT_RESULT CppTest_Stub_N51FS_EntryNext(U8 enId,FileEntry* pFileToSet)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryNext_pFSEnv_u8FileSystemType_equal_FILE_SYSTEM_TYPE_N51FS") )
	{
        return ENTRY_NEXT_RESULT_SUCCESS;
	}
}

EXTERN_C_LINKAGE BOOLEAN FAT_InitialFileSystem(S8 deviceIndex,U32 bootStartSector ,U8* partitionBytes,FAT_FileSysStruct *pstFileSys);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_InitialFileSystem(S8 deviceIndex,U32 bootStartSector ,U8* partitionBytes,FAT_FileSysStruct *pstFileSys)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true") )
	{
		return TRUE;
	}
/*	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true")  )
	{
		return TRUE;
	}*/
}

EXTERN_C_LINKAGE BOOLEAN FAT_FATStructureFetch( U8 fsid, U32 u32FATOffsetSectorNo);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FATStructureFetch( U8 fsid, U32 u32FATOffsetSectorNo)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureRead_if_pu8FatTable_eq_NULL"))
	{
		return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true") )
		return TRUE;
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true_if_NO") )
	{
//		printf("",);

		return FALSE;
	}
}

EXTERN_C_LINKAGE void msAPI_FS_Memory_Free(void * pMem);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FS_Memory_Free(void * pMem)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_FAT_bResult_equal_true") )
	{
		return ;
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_1") )
	{
		return ;
	}

	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_N51FS_test_N51FS_FileDelete_2") )
	{
		return ;
	}
}

EXTERN_C_LINKAGE BOOLEAN N51FS_InitialFileSystem(S8 deviceIndex,U32 partitionStartSector ,U8* partitionBytes,N51FS_FileSysStruct* pFileSysToInitial);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_InitialFileSystem(S8 deviceIndex,U32 partitionStartSector ,U8* partitionBytes,N51FS_FileSysStruct* pFileSysToInitial)
{
	BOOLEAN flag = TRUE;
	printf("\nTRUE = %d\n",flag);
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSystemInitial_fsType_equal_FILE_SYSTEM_TYPE_N51FS_bResult_equal_true") )
	{
		printf("\nTRUE = %d\n",flag);
		return flag;
	}
}

EXTERN_C_LINKAGE BOOLEAN msAPI_FCtrl_GetDriveByIndex(U8 driveID,MSDCtrl_Drive* pDrive);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_FCtrl_GetDriveByIndex(U8 driveID,MSDCtrl_Drive* pDrive)
{
	BOOLEAN flag = TRUE;
	printf("\nTRUE = %d\n",flag);
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes") )
	{
		printf("\nTRUE = %d\n",flag);
		pDrive->DeviceIndex=0;
		pDrive->PartitionNo=0;
		pDrive->FileSystemType = FILE_SYSTEM_TYPE_FAT;
		return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if") )
	{
		printf("\nTRUE = %d\n",flag);
		pDrive->DeviceIndex=0;
		pDrive->PartitionNo=0;
		return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_1") )
	{
		printf("\nTRUE = %d\n",flag);
		pDrive->DeviceIndex=0;
		pDrive->PartitionNo=0;
		return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true") )
	{
		pDrive->DeviceIndex=0;

		return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FSEnv_test_msAPI_FSEnv_Register_step1") )
	{

		return TRUE;
	}
}

EXTERN_C_LINKAGE  U8 msAPI_FCtrl_GetAvailableDriveIndex(void);
EXTERN_C_LINKAGE  U8 CppTest_Stub_msAPI_FCtrl_GetAvailableDriveIndex(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_MountDrive_drvCount_equal_0_DISK_DRIVE_NUM_equal_2"))
	{
		return INVALID_DRIVE_INDEX;
	}
}

EXTERN_C_LINKAGE EN_MSD_PORT msAPI_MSDCtrl_GetDevicePort(U8 deviceIndex);
EXTERN_C_LINKAGE EN_MSD_PORT CppTest_Stub_msAPI_MSDCtrl_GetDevicePort(U8 deviceIndex)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_UnmountDrivesOnDevice_for_if_true_if_true_if_true_if_true"))
	{
		return MSD_PORT_NUM;
	}
}

EXTERN_C_LINKAGE void msAPI_FCtrl_RemoveDrivesOnDevice(U8 deviceIndex);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FCtrl_RemoveDrivesOnDevice(U8 deviceIndex)
{

}

EXTERN_C_LINKAGE void msAPI_FCtrl_UnmountDrivesOnDevice(U8 deviceIndex);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FCtrl_UnmountDrivesOnDevice(U8 deviceIndex)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_RemoveDrivesOnDevice") )
	{
		if( 0 == deviceIndex )
			return ;
	}
}

EXTERN_C_LINKAGE void msAPI_FCtrl_FileHandleResetAll();
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FCtrl_FileHandleResetAll()
{
	return ;
}

EXTERN_C_LINKAGE EN_MSD_STATUS msAPI_MSDCtrl_GetDeviceStatus(U8 u8DeviceIndex);
EXTERN_C_LINKAGE EN_MSD_STATUS CppTest_Stub_msAPI_MSDCtrl_GetDeviceStatus(U8 u8DeviceIndex)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_StartDevice_if1_yes") )
	{
		if( 0 == u8DeviceIndex )
			return MSD_STATUS_IDLE;
	}
}

EXTERN_C_LINKAGE EN_DRIVE_INITIAL_STATUS msAPI_FCtrl_MountDrive(U8 deviceIndex,EN_FILE_SYSTEM_TYPE fsType,U8* partitionBytes,U32 logicalBlockAddress,U8 partitionNo, U32 u32MBRLogicBlockAddress, U8 u8IndexInMBR);
EXTERN_C_LINKAGE EN_DRIVE_INITIAL_STATUS CppTest_Stub_msAPI_FCtrl_MountDrive(U8 deviceIndex,EN_FILE_SYSTEM_TYPE fsType,U8* partitionBytes,U32 logicalBlockAddress,U8 partitionNo, U32 u32MBRLogicBlockAddress, U8 u8IndexInMBR)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes") )
	{
		return DRIVE_INITIAL_STATUS_MOUNTED_ALREADY;
	}
}

EXTERN_C_LINKAGE void FCtrl_addPartitionCount(U8 u8PartitionCount,U32 *PartitionStatus);
EXTERN_C_LINKAGE void CppTest_Stub_FCtrl_addPartitionCount(U8 u8PartitionCount,U32 *PartitionStatus)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_LoadPartitionsOnDevice_if_no_for_if_no_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes_if_yes") )
	{
		*PartitionStatus = 0;
	}
}

EXTERN_C_LINKAGE U32 msAPI_FCtrl_LoadPartitionsOnDevice(U8 deviceIndex);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_FCtrl_LoadPartitionsOnDevice(U8 deviceIndex)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE void FAT_HandlePostCreate( U8 u8FileHandleNo, FileEntry *pFileEntry, U8 u8OpenMode );
EXTERN_C_LINKAGE void CppTest_Stub_FAT_HandlePostCreate( U8 u8FileHandleNo, FileEntry *pFileEntry, U8 u8OpenMode )
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileHandleCreate_for_if_yes_if_yes") )
	return ;
}

EXTERN_C_LINKAGE void msAPI_MSDCtrl_SetDeviceStatus(U8 u8DeviceIndex, EN_MSD_STATUS status);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_MSDCtrl_SetDeviceStatus(U8 u8DeviceIndex, EN_MSD_STATUS status)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_ActiveDevice_if_no_for_if_no") )
		return ;
}


EXTERN_C_LINKAGE BOOLEAN N51FS_DirectoryChange(U8 enid,U32 mfr);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_N51FS_DirectoryChange(U8 enid,U32 mfr)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChange_if_no_if_no_if_no_if_yes") )
		return FALSE;
}
EXTERN_C_LINKAGE BOOLEAN FAT_DirectoryChange(U8 u8EnvironmentId, U32 u32DirStartClusterNo);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_DirectoryChange(U8 u8EnvironmentId, U32 u32DirStartClusterNo)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToContained_if_no_if_yes") )
			return FALSE;
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes") )
			return TRUE;
}

EXTERN_C_LINKAGE BOOLEAN msAPI_FCtrl_FileSystemGetByID(U8 u8FileSysID, void *pFStruct);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_FCtrl_FileSystemGetByID(U8 u8FileSysID, void *pFStruct)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes") )
	{
		((FAT_FileSysStruct*)pFStruct)->FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes") )
	{
//		(FAT_FileSysStruct*)pFStruct->FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryChangeToRoot_if_no_if_yes_if_yes") )
	{
			return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes") )
	{
		((FAT_FileSysStruct*)pFStruct)->u32RootDirStartClusterNo = 1;
			return TRUE;
	}
}

EXTERN_C_LINKAGE U8 msAPI_FCtrl_FileHandleCreate(void* pFileSys, FileEntry* pFileEntry, U8 u8OpenMode);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_FileHandleCreate(void* pFileSys, FileEntry* pFileEntry, U8 u8OpenMode)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes") )
	{
			return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes") )
	{
//		pFStruct->FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return 1;
	}
}

EXTERN_C_LINKAGE BOOLEAN FAT_FileOpen(U8 u8FileHandleNo, void * pFileEntry,BOOLEAN fastOpen);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FileOpen(U8 u8FileHandleNo, void * pFileEntry,BOOLEAN fastOpen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryOpen_ifno_ifno_ifno_ifyes_ififyes") )
	{
			return TRUE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileOpen_if_yes_if_no_if_no_if_yes_if_yes") )
	{
	//	pFStruct->FileSystemType = FILE_SYSTEM_TYPE_FAT;
			return TRUE;
	}
	return TRUE;
}

EXTERN_C_LINKAGE BOOLEAN FAT_FileClose(U8 u8FileHandleNo);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FileClose(U8 u8FileHandleNo)
{
	BOOLEAN flag = TRUE;
	printf("\nTRUE = %d\n",flag);
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes") )
	{
			BOOLEAN flag = TRUE;
			printf("\nTRUE = %d\n",flag);
			return TRUE;
	}
}

EXTERN_C_LINKAGE void msAPI_FCtrl_FileHandleFree(U8 u8HandleNo);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_FCtrl_FileHandleFree(U8 u8HandleNo)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileClose_return_true") )
	{
		return ;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileClose_if_no_if_no_if_no_if_no_if_yes") )
	{
		return ;
	}
	return ;
}

EXTERN_C_LINKAGE U32 FAT_FileRead(U8 u8FileHandleNo, U32 u32DesBufAdr, U32 u32ReadByteLength);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_FileRead(U8 u8FileHandleNo, U32 u32DesBufAdr, U32 u32ReadByteLength)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead_if_no_if_no_if_yes") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileRead2_if_no_if_no_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE BOOLEAN FAT_FileSeek(U8 u8FileHandleNo, U32 u32Length, EN_FILE_SEEK_OPTION eOption);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FileSeek(U8 u8FileHandleNo, U32 u32Length, EN_FILE_SEEK_OPTION eOption)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_if_yes_") )
	{
		return TRUE;
	}
}

EXTERN_C_LINKAGE U32 FAT_FileTell(U8 handleId);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_FileTell(U8 handleId)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_LongLong_ifno_ifno_ifyes") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileTell_if_no_if_no_if_yes") )
	{
		return 1;
	}
	return 1;
}

FAT_FileInode tmp_FAT_FileInode;
EXTERN_C_LINKAGE FAT_FileInode *FAT_File_GetInodeFromHandle(U8 u8FileHandleID);
EXTERN_C_LINKAGE FAT_FileInode *CppTest_Stub_FAT_File_GetInodeFromHandle(U8 u8FileHandleID)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_EntryFillCluster_if_u32FileStartClusterNo_eq_0") )
	{
		tmp_FAT_FileInode.u32FileTotalSize = 1;
		return &tmp_FAT_FileInode;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_LongLong_if_no_ifno_ifyes") )
	{
		tmp_FAT_FileInode.u32FileTotalSize = 1;
		return &tmp_FAT_FileInode;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileLength_if_no_if_no_if_yes_if_no") )
	{
		tmp_FAT_FileInode.u32FileTotalSize = 1;
		return &tmp_FAT_FileInode;
	}

	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileClusterChainFetch_if_pFATInode_eq_NULL") )
	{
		return NULL;
	}

	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileOpen_if_pFATInode_eq_NULL") )
	{
		return NULL;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileRead_if_pFATInode_eq_NULL") )
	{
		return NULL;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileSeekWithoutClusterChain_if_pFATInode_eq_NULL") )
	{
		return NULL;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FileSeek_if_pFATInode_eq_NULL") )
	{
		return NULL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_TRUE_and_if_successed"))
	{
		tmp_FAT_FileInode.u32FileTotalSize = 1;
		return &tmp_FAT_FileInode;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_if_successed"))
	{
		tmp_FAT_FileInode.u32FileTotalSize = 1;
		return &tmp_FAT_FileInode;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FILE_AppendClusterChain_bResult_is_FALSE_and_else"))
	{
		return NULL;
	}

}

EXTERN_C_LINKAGE U8 FAT_EntryGetCurrentNameToMIU(U8 enid,U32 destMIUAddr,U8 charLen);
EXTERN_C_LINKAGE U8 CppTest_Stub_FAT_EntryGetCurrentNameToMIU(U8 enid,U32 destMIUAddr,U8 charLen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetCurrentName_if_no_if_no_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE BOOLEAN FAT_EntryIsCurrentNameShortOnly(U8 enid);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_EntryIsCurrentNameShortOnly(U8 enid)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryIsCurrentNameShortNameOnly_if_no_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE BOOLEAN FAT_FileDelete(FileEntry* pFileEntry);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FileDelete(FileEntry* pFileEntry)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE BOOLEAN msAPI_FCtrl_EntryFirst(U8 enId);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_FCtrl_EntryFirst(U8 enId)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileDelete_if_no_if_no_case_FAT") )
	{
		return 1;
	}
	return 1;
}

EXTERN_C_LINKAGE U32 FAT_DirectoryGetParentClusterNo(U8 u8EnvironmentID);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_DirectoryGetParentClusterNo(U8 u8EnvironmentID)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOTDOT_if_no_if_no_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE void FAT_GetCurrentFileEntry(U8 enid, FileEntry *entry);
EXTERN_C_LINKAGE void CppTest_Stub_FAT_GetCurrentFileEntry(U8 enid, FileEntry *entry)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryGetDOT_if_no_if_yes") )
	{
		return ;
	}
}

FAT_Environment tmp_FAT_Environment;
EXTERN_C_LINKAGE U32* FAT_GetAddr(U8 u8EnvironmentId, EN_FAT_XDATA_OPTION option);
EXTERN_C_LINKAGE U32* CppTest_Stub_FAT_GetAddr(U8 u8EnvironmentId, EN_FAT_XDATA_OPTION option)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectoryEntrySave_end") )
	{
		tmp_FAT_Environment.stCurrentDirectory.s32CurrentDirEntryIndex = 0;
		return &tmp_FAT_Environment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirEntryFindEmpty_if_s32CurrentDirEntryIndex_lt_0_msAPI_MSDCtrl_SectorRead_return_FALSE") )
	{
		tmp_FAT_Environment.stCurrentDirectory.s32CurrentDirEntryIndex = 0;
		return &tmp_FAT_Environment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_SaveEnvironment_if_msAPI_FSEnv_GetEnvironment_return_NONULL") )
	{
		tmp_FAT_Environment.stCurrentDirectory.s32CurrentDirEntryIndex = 1;
		return &tmp_FAT_Environment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if") )
	{
		tmp_FAT_Environment.stCurrentDirectory.s32CurrentDirEntryIndex = 1;
		return &tmp_FAT_Environment;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryIsCurrentRoot_if_no_if_no_if_yes_if_no_if_yes") )
	{
		tmp_FAT_Environment.stCurrentDirectory.u32CurrentDirStartClusterNo = 1;
		return &tmp_FAT_Environment;
	}

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectroyDirEntryToFirst_if_FAT_Cache_DirectoryClusterFetch_return_NULL"))
    {
    	return &tmp_FAT_Environment;
    }

    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_DirectoryGetParentClusterNo"))
    {
    	return &tmp_FAT_Environment;
    }
    if (CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_EntryIsCurrentNameShortOnly"))
    {
		BOOLEAN tmp = FALSE;
    	return &tmp;
    }
}

EXTERN_C_LINKAGE U32 FAT_GetUnusedSizeInKB_New(U8 u8fsid);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_GetUnusedSizeInKB_New(U8 u8fsid)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetUnusedSizeInKB_ByDriveIndex_New_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE U32 FAT_GetTotalSizeInKB(U8 u8fsid);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_GetTotalSizeInKB(U8 u8fsid)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetTotalSizeInKB_ByDriveIndex_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE EN_ENTRY_NEXT_RESULT msAPI_FCtrl_EntryNext(U8 enId, FileEntry* pFileToSet);
EXTERN_C_LINKAGE EN_ENTRY_NEXT_RESULT CppTest_Stub_msAPI_FCtrl_EntryNext(U8 enId, FileEntry* pFileToSet)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if") )
	{
		return ENTRY_NEXT_RESULT_SUCCESS;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes") )
	{
		return ENTRY_NEXT_RESULT_SUCCESS;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes") )
	{
		return ENTRY_NEXT_RESULT_SUCCESS;
	}
}

EXTERN_C_LINKAGE void FS_RESET_WDT(void);
EXTERN_C_LINKAGE void CppTest_Stub_FS_RESET_WDT(void)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if") )
	{
		return ;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes") )
	{
		return ;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes") )
	{
		return ;
	}
	return ;
}

EXTERN_C_LINKAGE U8 msAPI_FCtrl_EntryGetCurrentName(U8 enId,U32 MIUAddr,U8 charLen);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_EntryGetCurrentName(U8 enId,U32 MIUAddr,U8 charLen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByName_if_no_while_if_no_while_if_yes_if_yes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE U8 msAPI_FCtrl_EntryGetShortNameByFileEntry(U8 enId, FileEntry* pEntry, U32 MIUAddr, U8 charLen);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_EntryGetShortNameByFileEntry(U8 enId, FileEntry* pEntry, U32 MIUAddr, U8 charLen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortNameFromCurrentDirEntry_if_no_if_no_while_while_if_while_if_if") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntrySearchByShortName_if_no_while_if_no_while_if_no_if_yes") )
	{
		return 1;
	}
	return 1;
}

EXTERN_C_LINKAGE U8 FAT_GetNameByFileEntry(U8 enid, FileEntry *entry, U32 destMIUAddr, U8 charLen, BOOLEAN *bIsLongName);
EXTERN_C_LINKAGE U8 CppTest_Stub_FAT_GetNameByFileEntry(U8 enid, FileEntry *entry, U32 destMIUAddr, U8 charLen, BOOLEAN *bIsLongName)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_GetNameByFileEntry_if_no_if_yes") )
	{
		return 1;
	}
	return 1;
}

EXTERN_C_LINKAGE U8 msAPI_FCtrl_GetNameByFileEntry(U8 enId, FileEntry* pEntry, U32 MIUAddr, U8 charLen, BOOLEAN *bIsLongName);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_GetNameByFileEntry(U8 enId, FileEntry* pEntry, U32 MIUAddr, U8 charLen, BOOLEAN *bIsLongName)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetShortNameByFileEntry") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_EntryGetLongNameByFileEntry") )
	{
		return 1;
	}
	return 1;
}

EXTERN_C_LINKAGE LongLong msAPI_FCtrl_FileLength_LongLong(U8 u8HandleNo);
EXTERN_C_LINKAGE LongLong CppTest_Stub_msAPI_FCtrl_FileLength_LongLong(U8 u8HandleNo)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes") )
	{
		LongLong val;
	    val.Hi=0;
	    val.Lo=0;
		return val;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_LongLong_Logic0"))
	{
		LongLong u64ObjTemp0;
		u64ObjTemp0.Hi = 0;
		u64ObjTemp0.Lo = 0;
		return u64ObjTemp0;
	}
}

EXTERN_C_LINKAGE BOOLEAN LL_greater_or_equal(LongLong* pX,LongLong* pY);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_LL_greater_or_equal(LongLong* pX,LongLong* pY)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileSeek_LongLong_ifno_while_ifyes") )
	{
		return TRUE;
	}
}

EXTERN_C_LINKAGE U8 FAT_FileCreate(U8 u8enid,U16 *pu16LongName,U8 charLen);
EXTERN_C_LINKAGE U8 CppTest_Stub_FAT_FileCreate(U8 u8enid,U16 *pu16LongName,U8 charLen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_WithoutNameChecking_if") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE U8 FS_strlen_U(U16* pString);
EXTERN_C_LINKAGE U8 CppTest_Stub_FS_strlen_U(U16* pString)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno") )
	{
		return 1;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE BOOLEAN msAPI_FCtrl_EntrySearchByName(U8 u8EnId,U16 *pu16FileNameToFind,U8 u8FileNameToFindLen ,FileEntry *pEntryToSet);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_FCtrl_EntrySearchByName(U8 u8EnId,U16 *pu16FileNameToFind,U8 u8FileNameToFindLen ,FileEntry *pEntryToSet)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno") )
	{
		return 0;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes") )
	{
		return 1;
	}
	return TRUE;
}

EXTERN_C_LINKAGE U8 msAPI_FCtrl_FileDelete(FileEntry* pFileEntry);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_FileDelete(FileEntry* pFileEntry)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE U8 msAPI_FCtrl_FileCreate_WithoutNameChecking(U8 u8enid, U16 *pu16LongName, U8 charLen);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FCtrl_FileCreate_WithoutNameChecking(U8 u8enid, U16 *pu16LongName, U8 charLen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FileCreate_ifno_ifyes_ifyes") )
	{
		return 1;
	}
}

EXTERN_C_LINKAGE U8 FAT_FolderCreate(U8 u8enid, U16 *pu16LongName, U8 charLen);
EXTERN_C_LINKAGE U8 CppTest_Stub_FAT_FolderCreate(U8 u8enid, U16 *pu16LongName, U8 charLen)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno") )
	{
		return 1;
	}
}
/*
EXTERN_C_LINKAGE EN_FILE_CLOSE_RESULT msAPI_FCtrl_FileClose(U8 u8HandleNo);
EXTERN_C_LINKAGE EN_FILE_CLOSE_RESULT CppTest_Stub_msAPI_FCtrl_FileClose(U8 u8HandleNo)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno") )
	{
		return FILE_CLOSE_RESULT_SUCCESS;
	}
	return FILE_CLOSE_RESULT_SUCCESS;
}*/
/*
EXTERN_C_LINKAGE EN_FILE_CLOSE_RESULT msAPI_FCtrl_FileClose(U8 u8HandleNo);
EXTERN_C_LINKAGE EN_FILE_CLOSE_RESULT CppTest_Stub_msAPI_FCtrl_FileClose(U8 u8HandleNo)
{
	EN_FILE_CLOSE_RESULT tmp = FILE_CLOSE_RESULT_SUCCESS;
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_DirectoryCreate_ififno_ifyes_ifno") )
		return tmp;
	return tmp;
}
*/

EXTERN_C_LINKAGE U32 FAT_FileWrite(U8 u8FileHandle, U32 u32SrcBufAddr, U32 u32BufferLen);
EXTERN_C_LINKAGE U32 CppTest_Stub_FAT_FileWrite(U8 u8FileHandle, U32 u32SrcBufAddr, U32 u32BufferLen)
{
	return 1;
}

EXTERN_C_LINKAGE U32 msAPI_MSDCtrl_GetBlockNum(U8 u8DeviceIndex);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_MSDCtrl_GetBlockNum(U8 u8DeviceIndex)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FAT16_Format_BPB_ifno_if_ifno") )
			return 1024;
		return 1024;
}

EXTERN_C_LINKAGE BOOLEAN msAPI_MSDCtrl_SectorWrite(U8 u8DeviceIndex, U32 u32StartSector, U32 u32SectorCount, U32 u32BufferAddress);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MSDCtrl_SectorWrite(U8 u8DeviceIndex, U32 u32StartSector, U32 u32SectorCount, U32 u32BufferAddress)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FAT_test_FAT_FATStructureWrite_if_msAPI_MSDCtrl_SectorWrite_return_false") )
	{
		return FALSE;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FAT16_Format_ifno_ifyes_ifno_while_if_while_if_while_if") )
			return TRUE;
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_FAT16_Format_BPB_ifno_if_ifno") )
			return TRUE;
		return TRUE;
}

EXTERN_C_LINKAGE BOOLEAN FAT_FastFormatByDriveIndex_enhance(MSDCtrl_Drive target_drive);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FAT_FastFormatByDriveIndex_enhance(MSDCtrl_Drive target_drive)
{
	if( CppTest_IsCurrentTestCase("TestSuite_msAPI_FCtrl_test_msAPI_FCtrl_FormatPartitionByDriveIndex_ifno_ifno_ifyes") )
			return TRUE;
	return TRUE;
}
