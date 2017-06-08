/*
 * msAPI_CPU_stub.c
 *
 *  Created on: 5 Nov 2013
 *      Author: muters
 */

#include "cpptest.h"

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
#include "retcode.h"

BOOLEAN u8DMPStartFlag;

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_SelectSourceScanType(EN_GOP_DWIN_SCAN_MODE) */
EXTERN_C_LINKAGE void MDrv_Sys_Get_BinInfo(BININFO *pBinInfo, BOOLEAN *pbResult);
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_Sys_Get_BinInfo(BININFO *pBinInfo, BOOLEAN *pbResult)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_CPU_test_msAPI_COPRO_Init_ifAllPass"))
	{
		return;
	}
    return ;
}

EXTERN_C_LINKAGE eRETCODE MDrv_DMA_LoadBin(BININFO *pBinInfo, U32 u32DstVA, U32 u32DecVA, U32 u32TmpVA);
EXTERN_C_LINKAGE eRETCODE CppTest_Stub_MDrv_DMA_LoadBin(BININFO *pBinInfo, U32 u32DstVA, U32 u32DecVA, U32 u32TmpVA)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_CPU_test_msAPI_COPRO_Init_ifAllPass"))
	{
		return SUCCESS;
	}
    return SUCCESS;
}
/*
EXTERN_C_LINKAGE BDMA_Result MApi_BDMA_Copy(U32 u32Srcaddr, U32 u32Dstaddr, U32 u32Len, MEMCOPYTYPE eType);
EXTERN_C_LINKAGE BDMA_Result CppTest_Stub_MApi_BDMA_Copy(U32 u32Srcaddr, U32 u32Dstaddr, U32 u32Len, MEMCOPYTYPE eType)
{
	return E_BDMA_OK;
}*/

EXTERN_C_LINKAGE eRETCODE MApi_BDMA_CopyFromResource(U32 offset,U32 destVA,U32 len);
EXTERN_C_LINKAGE eRETCODE CppTest_Stub_MApi_BDMA_CopyFromResource(U32 offset,U32 destVA,U32 len)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if"))
	{
		return SUCCESS;
	}
    return SUCCESS;
}
/*
EXTERN_C_LINKAGE BOOLEAN msAPI_Flash_Write(U32 u32StartAddr, U32 u32WriteSize, U8 * user_buffer);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Flash_Write(U32 u32StartAddr, U32 u32WriteSize, U8 * user_buffer)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearIspUpdate_ifno"))
	{
		return TRUE;
	}
    return TRUE;
}*/

EXTERN_C_LINKAGE U32 GetFlashPosOf2ndMagicNo(void);
EXTERN_C_LINKAGE U32 CppTest_Stub_GetFlashPosOf2ndMagicNo(void)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_Bootloader_test_msAPI_BLoader_ClearIspUpdate_ifno"))
	{
		return 1;
	}
    return 1;
}

EXTERN_C_LINKAGE void msAPI_Tuner_ChangeProgram(void);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Tuner_ChangeProgram(void)
{
	return ;
}

EXTERN_C_LINKAGE void MDrv_SERFLASH_SetFlashWPCallBack(ms_Flash_SetHWWP_CB FlashWP_cb);
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_SERFLASH_SetFlashWPCallBack(ms_Flash_SetHWWP_CB FlashWP_cb)
{
	return ;
}

EXTERN_C_LINKAGE unsigned msAPI_HuffmanDecode (const unsigned char * pbufEncStr, unsigned nLenStr, unsigned char nEncodeType, unsigned char * pbufDecStr, unsigned nMaxBufDecStr) ;
EXTERN_C_LINKAGE unsigned CppTest_Stub_msAPI_HuffmanDecode (const unsigned char * pbufEncStr, unsigned nLenStr, unsigned char nEncodeType, unsigned char * pbufDecStr, unsigned nMaxBufDecStr)
{
    return 0U;
}

/** User stub definition for function: BOOLEAN msAPI_CI_ConfigResource(EN_CI_FUNCTION, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_ConfigResource (EN_CI_FUNCTION eCI_Function, BOOLEAN bEnable) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_ConfigResource (EN_CI_FUNCTION eCI_Function, BOOLEAN bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_CI_ConfigResourceDefaultSetting(EN_CI_VERSION, EN_CI_PLUS_VERSION, BOOLEAN) */
EXTERN_C_LINKAGE void msAPI_CI_ConfigResourceDefaultSetting (EN_CI_VERSION eCiVersion, EN_CI_PLUS_VERSION eCiPlusVersion, BOOLEAN bResourceHighestIdFilterEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_ConfigResourceDefaultSetting (EN_CI_VERSION eCiVersion, EN_CI_PLUS_VERSION eCiPlusVersion, BOOLEAN bResourceHighestIdFilterEnable)
{
}
#include "mapp_epgdb_public.h"


/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetPresentEventIdx(MEMBER_SI_SERVICETYPE, U16, EventIndex *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetPresentEventIdx (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, EventIndex * pEvent) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetPresentEventIdx (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, EventIndex * pEvent) 
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteSetAudLangDialogAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteSetAudLangDialogAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_ZUI_ACT_ExecuteSetAudLangDialogAction (U16 act) 
{
    return (unsigned char)0;
}
#include "mapp_epgdb_public.h"


/** User stub definition for function: U8 MApp_Epg_EventText_LoadFromSED(U16 *, U16, U8 *) */
EXTERN_C_LINKAGE U8 MApp_Epg_EventText_LoadFromSED (U16 * pu16Dst, U16 Length, U8 * pSED) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_Epg_EventText_LoadFromSED (U16 * pu16Dst, U16 Length, U8 * pSED) 
{
    return (unsigned char)0;
}

/** User stub definition for function: void hash_sbrk_SetMemPoolSize(unsigned long) */
EXTERN_C_LINKAGE void hash_sbrk_SetMemPoolSize (unsigned long u32Size) ;
EXTERN_C_LINKAGE void CppTest_Stub_hash_sbrk_SetMemPoolSize (unsigned long u32Size) 
{
}

/** User stub definition for function: void * hash_sbrk(unsigned int) */
EXTERN_C_LINKAGE void * hash_sbrk (unsigned size) ;
EXTERN_C_LINKAGE void * CppTest_Stub_hash_sbrk (unsigned size) 
{
    return (void *)0;
}
