#include "cpptest.h"

/**
 * This file contains auto-generated stub definitions.
 *
 * Available C++test API functions (see C++test Users Guide for details):
 *     void CppTest_Assert(bool test, const char * message)
 *     void CppTest_Break()
 *     const char* CppTest_GetCurrentTestCaseName()
 *     const char* CppTest_GetCurrentTestSuiteName()
 *     bool CppTest_IsCurrentTestCase(const char* testCaseName)
 */

/**
 * Header files where the stubbed functions are originally declared.
 * Verify #include directives and add any additional header files as necessary.
 */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#include "datatype.h"
#include "MsOS.h"
#include "apiXC.h"
#include "apiXC_Sys.h"
#include "drvPQ.h"
#include "drvPQ_Define.h"
#include "drvPQ_Datatypes.h"
#include "mhal_pq.h"


/** Auto-generated stub definition for variable: MS_BOOL _bOSD_On */
EXTERN_C_LINKAGE_START
extern MS_BOOL _bOSD_On;
MS_BOOL CppTest_Variable_Auto_Stub__bOSD_On = (unsigned char)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: MS_S32 _PQ_Mutex */
EXTERN_C_LINKAGE_START
extern MS_S32 _PQ_Mutex;
MS_S32 CppTest_Variable_Auto_Stub__PQ_Mutex = 0L;
EXTERN_C_LINKAGE_END


/** Auto-generated stub definition for function: void MDrv_PQ_AdaptiveTuning(void) */
EXTERN_C_LINKAGE void MDrv_PQ_AdaptiveTuning () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_AdaptiveTuning (void)
{
}

/** Auto-generated stub definition for function: MS_PQ_ADC_SAMPLING_TYPE MDrv_PQ_Get_ADCSampling_Info(PQ_WIN, PQ_INPUT_SOURCE_TYPE, MS_PQ_Mode_Info *) */
EXTERN_C_LINKAGE MS_PQ_ADC_SAMPLING_TYPE MDrv_PQ_Get_ADCSampling_Info (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType, MS_PQ_Mode_Info * pstPQModeInfo) ;
EXTERN_C_LINKAGE MS_PQ_ADC_SAMPLING_TYPE CppTest_Auto_Stub_MDrv_PQ_Get_ADCSampling_Info (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType, MS_PQ_Mode_Info * pstPQModeInfo)
{
    if( CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test__MApp_Scaler_ProgAnalogWin_YPbPr_2x") )
    {
        return E_PQ_ADC_SAMPLING_X_2;
    }

    return E_PQ_ADC_SAMPLING_NONE;
}

/** Auto-generated stub definition for function: MS_U16 Hal_PQ_get_sram_size(MS_U16) */
EXTERN_C_LINKAGE MS_U16 Hal_PQ_get_sram_size (MS_U16 u16sramtype) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Auto_Stub_Hal_PQ_get_sram_size (MS_U16 u16sramtype)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set_DTVInfo(PQ_WIN, MS_PQ_Dtv_Info *) */
EXTERN_C_LINKAGE void MDrv_PQ_Set_DTVInfo (PQ_WIN eWindow, MS_PQ_Dtv_Info * pstPQDTVInfo) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Set_DTVInfo (PQ_WIN eWindow, MS_PQ_Dtv_Info * pstPQDTVInfo)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_Get_PointToPoint(PQ_WIN) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_Get_PointToPoint (PQ_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_Get_PointToPoint (PQ_WIN eWindow)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void Hal_PQ_set_c_sram_table(MS_U8, void *) */
EXTERN_C_LINKAGE void Hal_PQ_set_c_sram_table (MS_U8 u8sramtype, void * pData) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_Hal_PQ_set_c_sram_table (MS_U8 u8sramtype, void * pData)
{
}

/** Auto-generated stub definition for function: void Hal_PQ_set_y_sram_table(MS_U8, void *) */
EXTERN_C_LINKAGE void Hal_PQ_set_y_sram_table (MS_U8 u8sramtype, void * pData) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_Hal_PQ_set_y_sram_table (MS_U8 u8sramtype, void * pData)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set_MultiMediaInfo(PQ_WIN, MS_PQ_MuliMedia_Info *) */
EXTERN_C_LINKAGE void MDrv_PQ_Set_MultiMediaInfo (PQ_WIN eWindow, MS_PQ_MuliMedia_Info * pstPQMMInfo) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Set_MultiMediaInfo (PQ_WIN eWindow, MS_PQ_MuliMedia_Info * pstPQMMInfo)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set420upsampling(PQ_WIN, MS_BOOL, MS_BOOL, MS_U16) */
EXTERN_C_LINKAGE void MDrv_PQ_Set420upsampling (PQ_WIN eWindow, MS_BOOL bFBL, MS_BOOL bPreV_ScalingDown, MS_U16 u16V_CropStart) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Set420upsampling (PQ_WIN eWindow, MS_BOOL bFBL, MS_BOOL bPreV_ScalingDown, MS_U16 u16V_CropStart)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set_NOLoadScalingTable(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_Set_NOLoadScalingTable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Set_NOLoadScalingTable (MS_BOOL bEnable)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_Get_VDSampling_Info(PQ_WIN, PQ_INPUT_SOURCE_TYPE, PQ_VIDEOSTANDARD_TYPE, MS_PQ_VD_Sampling_Info *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_Get_VDSampling_Info (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType, PQ_VIDEOSTANDARD_TYPE eStandard, MS_PQ_VD_Sampling_Info * pInfo) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_Get_VDSampling_Info (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType, PQ_VIDEOSTANDARD_TYPE eStandard, MS_PQ_VD_Sampling_Info * pInfo)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set_ModeInfo(PQ_WIN, PQ_INPUT_SOURCE_TYPE, MS_PQ_Mode_Info *) */
EXTERN_C_LINKAGE void MDrv_PQ_Set_ModeInfo (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType, MS_PQ_Mode_Info * pstPQModeInfo) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Set_ModeInfo (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType, MS_PQ_Mode_Info * pstPQModeInfo)
{
}

/** Auto-generated stub definition for function: void MDrv_BW_LoadTableByContext(PQ_WIN) */
EXTERN_C_LINKAGE void MDrv_BW_LoadTableByContext (PQ_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_BW_LoadTableByContext (PQ_WIN eWindow)
{
}

/** Auto-generated stub definition for function: PQ_DEINTERLACE_MODE MDrv_PQ_SetMemFormat(PQ_WIN, MS_BOOL, MS_BOOL, MS_U8 *) */
EXTERN_C_LINKAGE PQ_DEINTERLACE_MODE MDrv_PQ_SetMemFormat (PQ_WIN eWindow, MS_BOOL bMemFmt422, MS_BOOL bFBL, MS_U8 * u8BitsPerPixel) ;
EXTERN_C_LINKAGE PQ_DEINTERLACE_MODE CppTest_Auto_Stub_MDrv_PQ_SetMemFormat (PQ_WIN eWindow, MS_BOOL bMemFmt422, MS_BOOL bFBL, MS_U8 * u8BitsPerPixel)
{
    return PQ_DEINT_OFF;
}

/** Auto-generated stub definition for function: void MDrv_PQ_LoadSettings(PQ_WIN) */
EXTERN_C_LINKAGE void MDrv_PQ_LoadSettings (PQ_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_LoadSettings (PQ_WIN eWindow)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_DesideSrcType(PQ_WIN, PQ_INPUT_SOURCE_TYPE) */
EXTERN_C_LINKAGE void MDrv_PQ_DesideSrcType (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_DesideSrcType (PQ_WIN eWindow, PQ_INPUT_SOURCE_TYPE enInputSourceType)
{
}

/** Auto-generated stub definition for function: MS_U16 MDrv_PQ_GetSrcType(PQ_WIN) */
EXTERN_C_LINKAGE MS_U16 MDrv_PQ_GetSrcType (PQ_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Auto_Stub_MDrv_PQ_GetSrcType (PQ_WIN eWindow)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_Get_MemYUVFmt(PQ_WIN, PQ_FOURCE_COLOR_FMT) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_Get_MemYUVFmt (PQ_WIN eWindow, PQ_FOURCE_COLOR_FMT enFourceColor) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_Get_MemYUVFmt (PQ_WIN eWindow, PQ_FOURCE_COLOR_FMT enFourceColor)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_SetDMSV12L(PQ_WIN, MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_SetDMSV12L (PQ_WIN eWindow, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_SetDMSV12L (PQ_WIN eWindow, MS_BOOL bEnable)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_SetSelectCSC(MS_U16, PQ_WIN) */
EXTERN_C_LINKAGE void MDrv_PQ_SetSelectCSC (MS_U16 u16selection, PQ_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_SetSelectCSC (MS_U16 u16selection, PQ_WIN eWindow)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_SetColorRange(PQ_WIN, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_SetColorRange (PQ_WIN eWindow, MS_BOOL bColorRange0_255) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_SetColorRange (PQ_WIN eWindow, MS_BOOL bColorRange0_255)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_Init(MS_PQ_Init_Info *) */
EXTERN_C_LINKAGE void MDrv_PQ_Init (MS_PQ_Init_Info * pstPQInitInfo) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Init (MS_PQ_Init_Info * pstPQInitInfo)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_Check_PointToPoint_Condition(XC_SETWIN_INFO *, PQ_WIN) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_Check_PointToPoint_Condition (XC_SETWIN_INFO * pstXC_SetWin_Info, PQ_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_Check_PointToPoint_Condition (XC_SETWIN_INFO * pstXC_SetWin_Info, PQ_WIN eWindow)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_U16 MDrv_PQ_GetDelayTime(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_PQ_GetDelayTime () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Auto_Stub_MDrv_PQ_GetDelayTime (void)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_DisableFilmMode(PQ_WIN, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_DisableFilmMode (PQ_WIN eWindow, MS_BOOL bOn) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_DisableFilmMode (PQ_WIN eWindow, MS_BOOL bOn)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_LoadScalingTable(PQ_WIN, MS_U8, MS_BOOL, MS_BOOL, MS_BOOL, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_LoadScalingTable (PQ_WIN eWindow, MS_U8 eScalingType, MS_BOOL bPreV_ScalingDown, MS_BOOL bInterlace, MS_BOOL bColorSpaceYUV, MS_U16 u16InputSize, MS_U16 u16SizeAfterScaling) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_LoadScalingTable (PQ_WIN eWindow, MS_U8 eScalingType, MS_BOOL bPreV_ScalingDown, MS_BOOL bInterlace, MS_BOOL bColorSpaceYUV, MS_U16 u16InputSize, MS_U16 u16SizeAfterScaling)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_U16 MDrv_PQ_GetVsize(PQ_WIN) */
EXTERN_C_LINKAGE MS_U16 MDrv_PQ_GetVsize (PQ_WIN enPQWin) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Auto_Stub_MDrv_PQ_GetVsize (PQ_WIN enPQWin)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_SetHDMIInfo(PQ_WIN, const MS_PQ_Hdmi_Info *const) */
EXTERN_C_LINKAGE void MDrv_PQ_SetHDMIInfo (PQ_WIN eWindow, const MS_PQ_Hdmi_Info *const pstPQHDMIInfo) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_SetHDMIInfo (PQ_WIN eWindow, const MS_PQ_Hdmi_Info *const pstPQHDMIInfo)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_3DCloneforPIP(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_3DCloneforPIP (MS_BOOL bIpSync) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_3DCloneforPIP (MS_BOOL bIpSync)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_DisableUCFeature(PQ_WIN) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_DisableUCFeature (PQ_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_DisableUCFeature (PQ_WIN eWindow)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MDrv_BW_LoadInitTable(void) */
EXTERN_C_LINKAGE void MDrv_BW_LoadInitTable () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_BW_LoadInitTable (void)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set_DisplayType(MS_U16, PQ_DISPLAY_TYPE) */
EXTERN_C_LINKAGE void MDrv_PQ_Set_DisplayType (MS_U16 u16DisplayWidth, PQ_DISPLAY_TYPE enDisplaType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PQ_Set_DisplayType (MS_U16 u16DisplayWidth, PQ_DISPLAY_TYPE enDisplaType)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_SetH264_OnOff(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_SetH264_OnOff (MS_BOOL bEn) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_SetH264_OnOff (MS_BOOL bEn)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_ReduceBW_ForPVR(PQ_WIN, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_ReduceBW_ForPVR (PQ_WIN eWindow, MS_BOOL bPVR_On) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_ReduceBW_ForPVR (PQ_WIN eWindow, MS_BOOL bPVR_On)
{
}

/** Auto-generated stub definition for function: MS_U8 MDrv_PQ_GetCurrentMotionValue(void) */
EXTERN_C_LINKAGE MS_U8 MDrv_PQ_GetCurrentMotionValue () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Auto_Stub_MDrv_PQ_GetCurrentMotionValue (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_IOCTL(PQ_WIN, MS_U32, void *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_IOCTL (PQ_WIN eWindow, MS_U32 u32Flag, void * pBuf, MS_U32 u32BufSize) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_IOCTL (PQ_WIN eWindow, MS_U32 u32Flag, void * pBuf, MS_U32 u32BufSize)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_ReduceBW_ForOSD(PQ_WIN, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_ReduceBW_ForOSD (PQ_WIN eWindow, MS_BOOL bOSD_On) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_ReduceBW_ForOSD (PQ_WIN eWindow, MS_BOOL bOSD_On)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_SetNonLinearScaling(PQ_WIN, MS_U8, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PQ_SetNonLinearScaling (PQ_WIN eWindow, MS_U8 u8Level, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_SetNonLinearScaling (PQ_WIN eWindow, MS_U8 u8Level, MS_BOOL bEnable)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_Set_PointToPoint(XC_SETWIN_INFO *, MS_BOOL, PQ_WIN) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_Set_PointToPoint (XC_SETWIN_INFO * pstXC_SetWin_Info, MS_BOOL bEnable, PQ_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_Set_PointToPoint (XC_SETWIN_INFO * pstXC_SetWin_Info, MS_BOOL bEnable, PQ_WIN eWindow)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MDrv_PQ_LoadPTPTable(PQ_WIN, PQ_PTP_FUNCTION_TYPE) */
EXTERN_C_LINKAGE void MDrv_PQ_LoadPTPTable (PQ_WIN eWindow, PQ_PTP_FUNCTION_TYPE enPTP_Type) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_LoadPTPTable (PQ_WIN eWindow, PQ_PTP_FUNCTION_TYPE enPTP_Type)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_Set_VDInfo(PQ_WIN, MS_PQ_Vd_Info *) */
EXTERN_C_LINKAGE void MDrv_PQ_Set_VDInfo (PQ_WIN eWindow, MS_PQ_Vd_Info * pstPQVDInfo) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_Set_VDInfo (PQ_WIN eWindow, MS_PQ_Vd_Info * pstPQVDInfo)
{
}

/** Auto-generated stub definition for function: void Hal_PQ_set_sram_color_gain_snr_table(MS_U8, void *) */
EXTERN_C_LINKAGE void Hal_PQ_set_sram_color_gain_snr_table (MS_U8 u8sramtype, void * pData) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_Hal_PQ_set_sram_color_gain_snr_table (MS_U8 u8sramtype, void * pData)
{
}

/** Auto-generated stub definition for function: void Hal_PQ_set_sram_color_index_table(MS_U8, void *) */
EXTERN_C_LINKAGE void Hal_PQ_set_sram_color_index_table (MS_U8 u8sramtype, void * pData) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_Hal_PQ_set_sram_color_index_table (MS_U8 u8sramtype, void * pData)
{
}

/** Auto-generated stub definition for function: void MDrv_PQ_LoadNRTable(PQ_WIN, PQ_3D_NR_FUNCTION_TYPE) */
EXTERN_C_LINKAGE void MDrv_PQ_LoadNRTable (PQ_WIN eWindow, PQ_3D_NR_FUNCTION_TYPE en3DNRType) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MDrv_PQ_LoadNRTable (PQ_WIN eWindow, PQ_3D_NR_FUNCTION_TYPE en3DNRType)
{
}

/** Auto-generated stub definition for function: void Hal_PQ_set_sram_ihc_crd_table(MS_U8, void *) */
EXTERN_C_LINKAGE void Hal_PQ_set_sram_ihc_crd_table (MS_U8 u8sramtype, void * pData) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_Hal_PQ_set_sram_ihc_crd_table (MS_U8 u8sramtype, void * pData)
{
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_SetMM_OnOff(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_SetMM_OnOff (MS_BOOL bEn) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_SetMM_OnOff (MS_BOOL bEn)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_U16 MDrv_PQ_GetHsize(PQ_WIN) */
EXTERN_C_LINKAGE MS_U16 MDrv_PQ_GetHsize (PQ_WIN enPQWin) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Auto_Stub_MDrv_PQ_GetHsize (PQ_WIN enPQWin)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_IsInterlace(PQ_WIN) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_IsInterlace (PQ_WIN enPQWin) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_IsInterlace (PQ_WIN enPQWin)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: MS_BOOL MDrv_PQ_SetCSC(PQ_WIN, PQ_FOURCE_COLOR_FMT) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PQ_SetCSC (PQ_WIN eWindow, PQ_FOURCE_COLOR_FMT enFourceColor) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Auto_Stub_MDrv_PQ_SetCSC (PQ_WIN eWindow, PQ_FOURCE_COLOR_FMT enFourceColor)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void Hal_PQ_set_sram_icc_crd_table(MS_U8, void *) */
EXTERN_C_LINKAGE void Hal_PQ_set_sram_icc_crd_table (MS_U8 u8sramtype, void * pData) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_Hal_PQ_set_sram_icc_crd_table (MS_U8 u8sramtype, void * pData)
{
}
