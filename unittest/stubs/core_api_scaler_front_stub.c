/*
 * core_api_scaler_front_stub.c
 *
 *  Created on: 10 Oct 2013
 *      Author: muters
 */
#include "cpptest.h"
#include "msAPI_Mode.h"
#include "apiPNL.h"
#include "MApp_Scaler.h"
#include "apiVDEC.h"
EXTERN_C_LINKAGE_START
extern BOOLEAN bTest_msAPI_Mode_GetPcClockValue_CallGetScale100Value = FALSE;
extern BOOLEAN bTest_msAPI_Mode_GetPcPhaseValue_CallGetScale100Value = FALSE;
extern BOOLEAN bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From = FALSE;
extern BOOLEAN bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To = FALSE;
EXTERN_C_LINKAGE_END
EXTERN_C_LINKAGE U8 GetScale100Value(U16 wValue, U16 wMinValue, U16 wMaxValue) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_GetScale100Value(U16 wValue, U16 wMinValue, U16 wMaxValue)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcClockValue"))
	{
		if(wValue == 1)
		{
			bTest_msAPI_Mode_GetPcClockValue_CallGetScale100Value = TRUE;
		}
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_msAPI_Mode_GetPcPhaseValue"))
	{
		if(wValue == 1)
		{
			bTest_msAPI_Mode_GetPcPhaseValue_CallGetScale100Value = TRUE;
		}
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_GreaterThan_wValueFrom"))
	{
		if(wValue == 10)
		{
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From = TRUE;
			return (unsigned char)10;
		}
		else if(wValue == 20)
		{
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To = TRUE;
			return (unsigned char)20;
		}
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_LessThan_wValueFrom"))
	{
		if(wValue == 20)
		{
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From = TRUE;
			return (unsigned char)20;
		}
		else if(wValue == 10)
		{
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To = TRUE;
			return (unsigned char)10;
		}
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIsZero"))
	{
		if(wValue == 0)
		{
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From = TRUE;
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To = TRUE;
			return (unsigned char)0;
		}
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_GetColorTemperatureScale100Value_wValueTo_Equal_wValueFrom_u8ScaleValueFromIs100"))
	{
		if(wValue == 100)
		{
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_From = TRUE;
			bTest_GetColorTemperatureScale100Value_CallGetScale100Value_To = TRUE;
			return (unsigned char)100;
		}
	}
	return (unsigned char)1;
}
EXTERN_C_LINKAGE_START
BOOLEAN bTest_msAPI_Mode_PictureBackLightN100toReallyValue_callmsAPI_Mode_PictureBackLightN100toReallyValue = FALSE;
EXTERN_C_LINKAGE_END
EXTERN_C_LINKAGE U16 msAPI_Mode_PictureBackLightN100toReallyValue ( U8 u8value );
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_Mode_PictureBackLightN100toReallyValue ( U8 u8value )
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Mode_test_msAPI_Mode_PictureBackLightN100toReallyValue"))
	{
		if(u8value == 5)
		{
			bTest_msAPI_Mode_PictureBackLightN100toReallyValue_callmsAPI_Mode_PictureBackLightN100toReallyValue = TRUE;
		}
	}
}

EXTERN_C_LINKAGE_START
U8  u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 0;
EXTERN_C_LINKAGE_END
EXTERN_C_LINKAGE BOOLEAN _msAPI_Picture_AdjustWidth_CutByHeight(SRC_RATIO_INFO *pstSrcRatioInfo, MS_WINDOW_TYPE *pstSrcWin,  MS_WINDOW_TYPE *pstDstWin);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__msAPI_Picture_AdjustWidth_CutByHeight(SRC_RATIO_INFO *pstSrcRatioInfo, MS_WINDOW_TYPE *pstSrcWin,  MS_WINDOW_TYPE *pstDstWin)
{
	if (CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic1"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 2;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic2"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 3;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic3"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 4;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic4"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 5;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic5"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 6;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic6"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 7;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic7"))
	{
		u8Test_MApp_XC_Sys_test_msAPI_Picture_Adjust_AFDSourceWindow_Logic0_Call_msAPI_Picture_AdjustWidth_CutByHeight = 8;
	}
	return FALSE;
}

EXTERN_C_LINKAGE_START
BOOLEAN  bTest_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow_Call_msAPI_Picture_CalculateSAR = 0;
EXTERN_C_LINKAGE_END
EXTERN_C_LINKAGE BOOLEAN _msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *pstSrcRatioInfo,VDEC_CodecType codecType);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__msAPI_Picture_CalculateSAR(SRC_RATIO_INFO *pstSrcRatioInfo,VDEC_CodecType codecType)
{
	if (CppTest_IsCurrentTestCase("TestSuit_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow"))
	{
		bTest_MApp_XC_Sys_test_msAPI_Picture_CalculateAFDWindow_Call_msAPI_Picture_CalculateSAR = 1;
	}
	return FALSE;
}
