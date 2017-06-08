#include "cpptest.h"
/*
 * core_middleware_dvb_stub.c
 *
 *  Created on: 15 Oct 2013
 *      Author: muters
 */
#include "msAPI_demux.h"
#include "mapp_demux_if.h"

EXTERN_C_LINKAGE_START
extern BOOLEAN gbTest_msAPI_SI_Dmx_CheckCRC32_CallmsAPI_DMX_CheckCRC32 = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Close_CallmsAPI_DMX_Close = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Close_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_CloseFilter_CallmsAPI_DMX_CloseFilter = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_DMX_CopyData = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_DMX_Pid = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_DMX_Proc = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_DMX_Reset = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_RestartFilter_CallmsAPI_DMX_RestartFilter = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_DMX_SectionGet = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_DMX_SectionMonitor = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Start_CallmsAPI_DMX_Start = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Start_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_DMX_Stop = FALSE;
extern BOOLEAN gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_SI_Dmx_Filter_Status = FALSE;
EXTERN_C_LINKAGE_END


EXTERN_C_LINKAGE BOOL msAPI_DMX_CheckCRC32(U8* pu8Section);
EXTERN_C_LINKAGE BOOL CppTest_Stub_msAPI_DMX_CheckCRC32(U8* pu8Section)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CheckCRC32"))
	{
		if (0 == pu8Section)
		{
			gbTest_msAPI_SI_Dmx_CheckCRC32_CallmsAPI_DMX_CheckCRC32 = TRUE;
		}
		return TRUE;
	}
	return TRUE;
}



EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_Close(U8 u8FltID);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_Close(U8 u8FltID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Close"))
	{
		if (0 == u8FltID)
		{
			gbTest_msAPI_SI_Dmx_Close_CallmsAPI_DMX_Close = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;

}



EXTERN_C_LINKAGE SI_DMX_FILTER_STATUS msAPI_SI_Dmx_Filter_Status(DMX_FILTER_STATUS eStatus);
EXTERN_C_LINKAGE SI_DMX_FILTER_STATUS CppTest_Stub_msAPI_SI_Dmx_Filter_Status(DMX_FILTER_STATUS eStatus)
{
	// printf("eStatus = %d\n", eStatus);
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Close"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_Close_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CopyData"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Pid"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Proc"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Reset"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionGet"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionMonitor"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Start"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_Start_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Stop"))
	{
		if (DMX_FILTER_STATUS_OK == eStatus)
		{
			gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_SI_Dmx_Filter_Status = TRUE;
		}
		return SI_DMX_FILTER_STATUS_OK;
	}

	return SI_DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE void msAPI_DMX_CloseFilter(U8 u8FltID);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DMX_CloseFilter(U8 u8FltID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CloseFilter"))
	{
		if (0 == u8FltID)
		{
			gbTest_msAPI_SI_Dmx_CloseFilter_CallmsAPI_DMX_CloseFilter = TRUE;
		}
	}
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_CopyData(MS_U8 u8DmxId, MS_U8* pu8Buf, MS_U32 u32BufSize, MS_U32* pu32ActualSize, MS_U32* pu32RmnSize, DMX_CheckCb pfCheckCB);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_CopyData(MS_U8 u8DmxId, MS_U8* pu8Buf, MS_U32 u32BufSize, MS_U32* pu32ActualSize, MS_U32* pu32RmnSize, DMX_CheckCb pfCheckCB)
{

	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_CopyData"))
	{
		if (0 == u8DmxId && 0 == pu8Buf && 0 == u32BufSize && 0 == pu32ActualSize && 0 == pu32RmnSize && NULL == pfCheckCB)
		{
			gbTest_msAPI_SI_Dmx_CopyData_CallmsAPI_DMX_CopyData = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}


EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_Pid(U8 u8FltID, U16* pu16Pid, BOOL bSet);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_Pid(U8 u8FltID, U16* pu16Pid, BOOL bSet)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Pid"))
	{
		if (0 == u8FltID && 0 == pu16Pid && 0 == bSet)
		{
			gbTest_msAPI_SI_Dmx_Pid_CallmsAPI_DMX_Pid = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_Proc(U8 u8DmxId);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_Proc(U8 u8DmxId)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Proc"))
	{
		if (0 == u8DmxId)
		{
			gbTest_msAPI_SI_Dmx_Proc_CallmsAPI_DMX_Proc = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_Reset(U8 u8FltID);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_Reset(U8 u8FltID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Reset"))
	{
		if (0 == u8FltID)
		{
			gbTest_msAPI_SI_Dmx_Reset_CallmsAPI_DMX_Reset = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE void msAPI_DMX_RestartFilter(U8 u8FltID);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DMX_RestartFilter(U8 u8FltID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_RestartFilter"))
	{
		if (0 == u8FltID)
		{
			gbTest_msAPI_SI_Dmx_RestartFilter_CallmsAPI_DMX_RestartFilter = TRUE;
		}
	}
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_SectionGet(MS_DMX_SECTIONGET_PARA * pstSectionGet);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_SectionGet(MS_DMX_SECTIONGET_PARA * pstSectionGet)
{
	int i = 0, matchLen = (SI_DMX_MATCH_PATTERN_LENGTH > MSAPI_DMX_MATCH_PATTERN_LENGTH) ? MSAPI_DMX_MATCH_PATTERN_LENGTH : SI_DMX_MATCH_PATTERN_LENGTH;
	U8 zeroArr[matchLen];
	for (i = 0; i < matchLen; i++)
	{
		zeroArr[i] = 0;
	}

	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionGet"))
	{
		if (pstSectionGet->u16PID == 0
			&& pstSectionGet->u32SectionFltType == 0
			&& !memcmp(pstSectionGet->au8MatchByte, zeroArr, matchLen)
			&& !memcmp(pstSectionGet->au8MaskByte, zeroArr, matchLen)
			&& !memcmp(pstSectionGet->au8NotMatchByte, zeroArr, matchLen)
			&& pstSectionGet->pu8Section == 0
			&& pstSectionGet->u16MaxSecSize == 0
			&& pstSectionGet->u16TimeoutMilliSec == 0
			&& pstSectionGet->bCheckCrc == 0
			)
		{
			gbTest_msAPI_SI_Dmx_SectionGet_CallmsAPI_DMX_SectionGet = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_SectionMonitor(MS_DMX_SECTIONMONITOR_PARA * pstSectionMonitor, BOOL bFileIn);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_SectionMonitor(MS_DMX_SECTIONMONITOR_PARA * pstSectionMonitor, BOOL bFileIn)
{
	int i = 0, matchLen = (SI_DMX_MATCH_PATTERN_LENGTH > MSAPI_DMX_MATCH_PATTERN_LENGTH) ? MSAPI_DMX_MATCH_PATTERN_LENGTH : SI_DMX_MATCH_PATTERN_LENGTH;
	U8 zeroArr[matchLen];
	for (i = 0; i < matchLen; i++)
	{
		zeroArr[i] = 0;
	}
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_SectionMonitor"))
	{
		if (pstSectionMonitor->u16PID == 0
			&& pstSectionMonitor->u32SectionFltType == 0
			&& !memcmp(pstSectionMonitor->au8MatchByte, zeroArr, matchLen)
			&& !memcmp(pstSectionMonitor->au8MaskByte, zeroArr, matchLen)
			&& !memcmp(pstSectionMonitor->au8NotMatchByte, zeroArr, matchLen)
			&& pstSectionMonitor->pfNotify == 0
			&& pstSectionMonitor->u16TimeoutMilliSec == 0
			&& pstSectionMonitor->SectMode == 0
			&& pstSectionMonitor->pu8FID == 0
			)
		{
			gbTest_msAPI_SI_Dmx_SectionMonitor_CallmsAPI_DMX_SectionMonitor = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_Start(U8 u8FltID);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_Start(U8 u8FltID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Start"))
	{
		if (0 == u8FltID)
		{
			gbTest_msAPI_SI_Dmx_Start_CallmsAPI_DMX_Start = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}

EXTERN_C_LINKAGE DMX_FILTER_STATUS msAPI_DMX_Stop(U8 u8FltID);
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_msAPI_DMX_Stop(U8 u8FltID)
{
	if (CppTest_IsCurrentTestCase("TestSuite_mapp_demux_if_test_msAPI_SI_Dmx_Stop"))
	{
		if (0 == u8FltID)
		{
			gbTest_msAPI_SI_Dmx_Stop_CallmsAPI_DMX_Stop = TRUE;
		}
		return DMX_FILTER_STATUS_OK;
	}
	return DMX_FILTER_STATUS_OK;
}
