#include "cpptest.h"

/**
 * This file contains user stub definitions.
 *
 * To create a user stub:
 * 1. Open stub template list:
 *    - Eclipse IDE: type 'stub' and press <Ctrl> <Space>
 *    - Microsoft Visual Studio IDE: use context menu C++test->Insert Snippet...
 * 2. Choose the stub template from the list.
 * 3. #include the header file where the function you want to stub is originally
 *    declared as well as any supporting header files as necessary.
 * 4. Fill out the stub signature to match that of the original function,
 *    while keeping the CppTest_Stub prefix when it applies.
 *    Note: for C++ operators, use appropriate stub names - e.g.:
 *        CppTest_Stub_operator_new    for operator new
 *        CppTest_Stub_operator_delete for operator delete
 *        CppTest_Stub_operator_plus   for operator +
 *    Refer to C++test User's Guide for a complete list of stub names for operators.
 * 5. Fill out the body of the stub according to intent.
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Board.h"
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
#include "msAPI_DTVSystem.h"
#include "drvWDT.h"

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_SelectSourceScanType(EN_GOP_DWIN_SCAN_MODE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_SelectSourceScanType (EN_GOP_DWIN_SCAN_MODE enScanMode) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_SelectSourceScanType (EN_GOP_DWIN_SCAN_MODE enScanMode)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApp_SI_Disable_Auto_Update(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_SI_Disable_Auto_Update (BOOLEAN bDisable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Disable_Auto_Update (BOOLEAN bDisable)
{
}

/** User stub definition for function: void MApi_AUDIO_SIF_SendCmd(En_AUD_SIF_CmdType, MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_SendCmd (En_AUD_SIF_CmdType enAudSifCommand, MS_U8 comm_arg1, MS_U8 comm_arg2) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_SendCmd (En_AUD_SIF_CmdType enAudSifCommand, MS_U8 comm_arg1, MS_U8 comm_arg2)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_IsInputSourceDisabled(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsInputSourceDisabled (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsInputSourceDisabled (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_ActiveSource(void) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_ActiveSource () ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_ActiveSource (void)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: void msAPI_CI_NotifyOtherPMTUpdate(U8 *, U16) */
EXTERN_C_LINKAGE void msAPI_CI_NotifyOtherPMTUpdate (U8 * pu8PMTSection, U16 u16PMTLength) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_NotifyOtherPMTUpdate (U8 * pu8PMTSection, U16 u16PMTLength)
{
}

/** User stub definition for function: MS_BOOL MDrv_PCMCIA_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE MS_BOOL MDrv_PCMCIA_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_PCMCIA_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_XC_WaitInputVSync(MS_U8, MS_U16, SCALER_WIN) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_WaitInputVSync (MS_U8 u8NumVSyncs, MS_U16 u16Timeout, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_WaitInputVSync (MS_U8 u8NumVSyncs, MS_U16 u16Timeout, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MsOS_DelayTask(MS_U32) */
EXTERN_C_LINKAGE void MsOS_DelayTask (MS_U32 u32Ms) ;
EXTERN_C_LINKAGE void CppTest_Stub_MsOS_DelayTask (MS_U32 u32Ms)
{
}

/** User stub definition for function: MS_U16 MApi_XC_ADC_GetMaximalOffsetValue(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_ADC_GetMaximalOffsetValue () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_ADC_GetMaximalOffsetValue (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U8 MApi_XC_ACE_DNR_GetNoise_Weight(MS_U8, MS_U8, MS_U8, MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ACE_DNR_GetNoise_Weight (MS_U8 u8CurNoise, MS_U8 u8PreNoise, MS_U8 u8Range, MS_U8 u8DeFlick_Th, MS_U8 u8DeFlick_Step) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ACE_DNR_GetNoise_Weight (MS_U8 u8CurNoise, MS_U8 u8PreNoise, MS_U8 u8Range, MS_U8 u8DeFlick_Th, MS_U8 u8DeFlick_Step)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_MIU_Protect(MS_U8, MS_U8 *, MS_U32, MS_U32, MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MIU_Protect (MS_U8 u8Blockx, MS_U8 * pu8ProtectId, MS_U32 u32Start, MS_U32 u32End, MS_BOOL bSetFlag) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MIU_Protect (MS_U8 u8Blockx, MS_U8 * pu8ProtectId, MS_U32 u32Start, MS_U32 u32End, MS_BOOL bSetFlag)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetSignalQuality(MS_U16 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetSignalQuality (MS_U16 * u16Quality) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetSignalQuality (MS_U16 * u16Quality)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MApp_Epg_EventName_LoadFromSED(U16 *, U16, U8 *) */
EXTERN_C_LINKAGE U8 MApp_Epg_EventName_LoadFromSED (U16 * pu16Dst, U16 Length, U8 * pSED) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_Epg_EventName_LoadFromSED (U16 * pu16Dst, U16 Length, U8 * pSED)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_AUDIO_CheckPlayDone(void) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_CheckPlayDone () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_CheckPlayDone (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Main_case1"))
	{
		    return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_Init(DMD_DVBT_InitData *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_Init (DMD_DVBT_InitData * pDMD_DVBT_InitData, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_Init (DMD_DVBT_InitData * pDMD_DVBT_InitData, MS_U32 u32InitDataLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_SupportRGB(MS_BOOL) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_SupportRGB (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_SupportRGB (MS_BOOL bEnable)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: void MApi_AUDIO_SetTreble(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetTreble (MS_U8 u8Treble) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetTreble (MS_U8 u8Treble)
{
}

/** User stub definition for function: En_DVB_decCmdType MApi_AUDIO_GetDecStatus(void) */
EXTERN_C_LINKAGE En_DVB_decCmdType MApi_AUDIO_GetDecStatus () ;
EXTERN_C_LINKAGE En_DVB_decCmdType CppTest_Stub_MApi_AUDIO_GetDecStatus (void)
{
    return MSAPI_AUD_DVB_DECCMD_STOP;
}

/** User stub definition for function: void MDrv_MVOP_Init(void) */
EXTERN_C_LINKAGE void MDrv_MVOP_Init () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_MVOP_Init (void)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_SetAlphaValue(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_SetAlphaValue (MS_U8 u8AlphaVal) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_SetAlphaValue (MS_U8 u8AlphaVal)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: BOOLEAN msAPI_CI_HLC_SetCountry(U8 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HLC_SetCountry (U8 * pCountry) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HLC_SetCountry (U8 * pCountry)
{
    return (unsigned char)0;
}

/** User stub definition for function: PM_Result MDrv_PM_PowerDown(PM_PowerDownCfg *) */
EXTERN_C_LINKAGE PM_Result MDrv_PM_PowerDown (PM_PowerDownCfg * pPmPowerDownCfg) ;
EXTERN_C_LINKAGE PM_Result CppTest_Stub_MDrv_PM_PowerDown (PM_PowerDownCfg * pPmPowerDownCfg)
{
    return E_PM_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_3D_PostPQSetting(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_3D_PostPQSetting (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_3D_PostPQSetting (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_PNL_MOD_OutputConfig_User(MS_U32, MS_U32, MS_U32) */
EXTERN_C_LINKAGE void MApi_PNL_MOD_OutputConfig_User (MS_U32 u32OutputCFG0_7, MS_U32 u32OutputCFG8_15, MS_U32 u32OutputCFG16_21) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_PNL_MOD_OutputConfig_User (MS_U32 u32OutputCFG0_7, MS_U32 u32OutputCFG8_15, MS_U32 u32OutputCFG16_21)
{
}

/** User stub definition for function: void MDrv_HDMI_pullhpd(MS_BOOL, E_MUX_INPUTPORT, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_HDMI_pullhpd (MS_BOOL bHighLow, E_MUX_INPUTPORT enInputPortType, MS_BOOL bInverse) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDMI_pullhpd (MS_BOOL bHighLow, E_MUX_INPUTPORT enInputPortType, MS_BOOL bInverse)
{
}

/** User stub definition for function: void msAPI_Subtitle_SetPageIDs(U16, U16) */
EXTERN_C_LINKAGE void msAPI_Subtitle_SetPageIDs (U16 u16CPID, U16 u16APID) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_SetPageIDs (U16 u16CPID, U16 u16APID)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_OutputLayerSwitch(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_OutputLayerSwitch (MS_U8 u8GOP) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_OutputLayerSwitch (MS_U8 u8GOP)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApp_SI_Reset(SI_RESET_TYPE) */
EXTERN_C_LINKAGE void MApp_SI_Reset (SI_RESET_TYPE eType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Reset (SI_RESET_TYPE eType)
{
}

/** User stub definition for function: MS_BOOL MsOS_CPU_EnableInterrupt(void) */
EXTERN_C_LINKAGE MS_BOOL MsOS_CPU_EnableInterrupt () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_CPU_EnableInterrupt (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_SC_IsForceFreerun(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_SC_IsForceFreerun () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SC_IsForceFreerun (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_FrameLockCheck(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_FrameLockCheck () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_FrameLockCheck (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_XC_WaitOutputVSync(MS_U8, MS_U16, SCALER_WIN) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_WaitOutputVSync (MS_U8 u8NumVSyncs, MS_U16 u16Timeout, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_WaitOutputVSync (MS_U8 u8NumVSyncs, MS_U16 u16Timeout, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_GetCommand(MVOP_Handle *, MVOP_Command, void *, MS_U32) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_GetCommand (MVOP_Handle * stHd, MVOP_Command eCmd, void * pPara, MS_U32 u32ParaSize) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_GetCommand (MVOP_Handle * stHd, MVOP_Command eCmd, void * pPara, MS_U32 u32ParaSize)
{
    return E_MVOP_OK;
}

/** User stub definition for function: MS_BOOL MDrv_VE_GetTtxReadDoneStatus(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VE_GetTtxReadDoneStatus () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VE_GetTtxReadDoneStatus (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_Start(MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_Start (MS_BOOL bPvrAll) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_Start (MS_BOOL bPvrAll)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApi_AUDIO_SIF_SetPALType(AUDIO_SIF_PAL_TYPE) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_SetPALType (AUDIO_SIF_PAL_TYPE pal_type) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_SetPALType (AUDIO_SIF_PAL_TYPE pal_type)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Init(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Init () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Init (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_Write(MS_U32, MS_U32, MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_Write (MS_U32 u32FlashAddr, MS_U32 u32FlashSize, MS_U8 * user_buffer) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_Write (MS_U32 u32FlashAddr, MS_U32 u32FlashSize, MS_U8 * user_buffer)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AVD_Set_Htt_UserMD(MS_U16) */
EXTERN_C_LINKAGE void MDrv_AVD_Set_Htt_UserMD (MS_U16 u16Htt) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_Set_Htt_UserMD (MS_U16 u16Htt)
{
}

/** User stub definition for function: PWM_Result MDrv_PWM_Init(PWM_DbgLv) */
EXTERN_C_LINKAGE PWM_Result MDrv_PWM_Init (PWM_DbgLv eLevel) ;
EXTERN_C_LINKAGE PWM_Result CppTest_Stub_MDrv_PWM_Init (PWM_DbgLv eLevel)
{
    return E_PWM_OK;
}

/** User stub definition for function: BOOLEAN MApp_Epg_IsEventSplit(EventIndex) */
EXTERN_C_LINKAGE BOOLEAN MApp_Epg_IsEventSplit (EventIndex event) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Epg_IsEventSplit (EventIndex event)
{
    return (unsigned char)0;
}

/** User stub definition for function: OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessUNT(U8 *, UNT_DESCRIPTOR *) */
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessUNT (U8 * _MT_var614, UNT_DESCRIPTOR * _MT_var615) ;
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE CppTest_Stub_msAPI_OAD_ProcessUNT (U8 * _MT_var288, UNT_DESCRIPTOR * _MT_var289)
{
    return OAD_SUCCEED;
}

/** User stub definition for function: void msAPI_CI_SendEmptyPmt(U16, U8) */
EXTERN_C_LINKAGE void msAPI_CI_SendEmptyPmt (U16 u16ServiceID, U8 u8PmtVersion) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_SendEmptyPmt (U16 u16ServiceID, U8 u8PmtVersion)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Info(MS_U8, DMX_Flt_info *, MS_U32 *, MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Info (MS_U8 u8DmxId, DMX_Flt_info * pDmxFltInfo, MS_U32 * pDmxFltType, MS_BOOL bSet) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Info (MS_U8 u8DmxId, DMX_Flt_info * pDmxFltInfo, MS_U32 * pDmxFltType, MS_BOOL bSet)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApi_JPEG_DumpMPO(void) */
EXTERN_C_LINKAGE void MApi_JPEG_DumpMPO () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_DumpMPO (void)
{
}

/** User stub definition for function: U8 __MDrv_ReadByte(U32) */
EXTERN_C_LINKAGE U8 __MDrv_ReadByte (U32 u32Reg) ;
EXTERN_C_LINKAGE U8 CppTest_Stub___MDrv_ReadByte (U32 u32Reg)
{
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Get_Power_Flag"))
	{
		return (unsigned char)0;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_Is1STBootUp"))
	{
    return (unsigned char)0;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown"))
	{
		return (unsigned char )0;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown"))
		{
			return (unsigned char )PM_FIRST_BOOTUP;
		}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S1"))
			{
				return (unsigned char )PM_PDMODE_S1;
			}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S2"))
				{
					return (unsigned char )PM_PDMODE_S2;
				}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S3"))
					{
						return (unsigned char )PM_PDMODE_S3;
					}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S4"))
						{
							return (unsigned char )PM_PDMODE_S4;
						}
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_IsPowerDown_default"))
							{
								return (unsigned char )2*PM_PDMODE_S4;
							}
}

/** User stub definition for function: void MApi_XC_ADC_AdjustGainOffset(APIXC_AdcGainOffsetSetting *) */
EXTERN_C_LINKAGE void MApi_XC_ADC_AdjustGainOffset (APIXC_AdcGainOffsetSetting * pstADCSetting) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_AdjustGainOffset (APIXC_AdcGainOffsetSetting * pstADCSetting)
{
}

/** User stub definition for function: void MApp_Epg_SwapProgram(WORD, WORD) */
EXTERN_C_LINKAGE void MApp_Epg_SwapProgram (WORD wFromOrder, WORD wToOrder) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Epg_SwapProgram (WORD wFromOrder, WORD wToOrder)
{
}

/** User stub definition for function: MS_U16 MApi_XC_R2BYTEMSK(MS_U32, MS_U16) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_R2BYTEMSK (MS_U32 u32Reg, MS_U16 u16mask) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_R2BYTEMSK (MS_U32 u32Reg, MS_U16 u16mask)
{
    return (unsigned short)0;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_HdlVidxChk(void) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_HdlVidxChk () ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_HdlVidxChk (void)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: MS_U8 MApi_AUDIO_ConvertVolumeUnit(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_ConvertVolumeUnit (MS_U8 UiVolume) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_ConvertVolumeUnit (MS_U8 UiVolume)
{
    return (unsigned char)0;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetGuidanceDescription(EventIndex, U16 *, U16 *, U16) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetGuidanceDescription (EventIndex event, U16 * pDescription, U16 * pStrLength, U16 length) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetGuidanceDescription (EventIndex event, U16 * pDescription, U16 * pStrLength, U16 length)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: void MDrv_DDC2BI_Set_CustomerCallBack(CALLBACK_AlignControl) */
EXTERN_C_LINKAGE void MDrv_DDC2BI_Set_CustomerCallBack (CALLBACK_AlignControl align_control) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DDC2BI_Set_CustomerCallBack (CALLBACK_AlignControl align_control)
{
}

/** User stub definition for function: MS_BOOL MsOS_ReleaseMutex(MS_S32) */
EXTERN_C_LINKAGE MS_BOOL MsOS_ReleaseMutex (MS_S32 s32MutexId) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_ReleaseMutex (MS_S32 s32MutexId)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_SectPatternSet(MS_U8, MS_U8 *, MS_U8 *, MS_U8 *, MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_SectPatternSet (MS_U8 u8DmxId, MS_U8 * pPattern, MS_U8 * pMask, MS_U8 * pu8NotMask, MS_U32 MatchSize) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_SectPatternSet (MS_U8 u8DmxId, MS_U8 * pPattern, MS_U8 * pMask, MS_U8 * pu8NotMask, MS_U32 MatchSize)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_DDC2BI_Init(void) */
EXTERN_C_LINKAGE void MDrv_DDC2BI_Init () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DDC2BI_Init (void)
{
}

/** User stub definition for function: void MDrv_UsbClose_Port2(void) */
EXTERN_C_LINKAGE void MDrv_UsbClose_Port2 () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_UsbClose_Port2 (void)
{
}

/** User stub definition for function: unsigned char msAPI_CNI_FindStationInfo(unsigned short, unsigned short, unsigned short, unsigned short *, unsigned short *) */
EXTERN_C_LINKAGE unsigned char msAPI_CNI_FindStationInfo (unsigned short wVPSCode, unsigned short wF1Code, unsigned short wF2Code, unsigned short * pStationId, unsigned short * pcStationIdList) ;
EXTERN_C_LINKAGE unsigned char CppTest_Stub_msAPI_CNI_FindStationInfo (unsigned short wVPSCode, unsigned short wF1Code, unsigned short wF2Code, unsigned short * pStationId, unsigned short * pcStationIdList)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_SWI2C_AccessStart(MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_SWI2C_AccessStart (MS_U8 u8SlaveID, MS_U8 trans_t) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SWI2C_AccessStart (MS_U8 u8SlaveID, MS_U8 trans_t)
{
    return (unsigned char)0;
}

/** User stub definition for function: IR_Result MDrv_IR_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE IR_Result MDrv_IR_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE IR_Result CppTest_Stub_MDrv_IR_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_IR_FAIL;
}

/** User stub definition for function: BDMA_Result MDrv_BDMA_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE BDMA_Result MDrv_BDMA_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE BDMA_Result CppTest_Stub_MDrv_BDMA_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_BDMA_NOT_SUPPORT;
}

/** User stub definition for function: MS_U16 MApi_XC_GetOutputVFreqX100(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_GetOutputVFreqX100 () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_GetOutputVFreqX100 (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Flush(VDEC_FreezePicSelect) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Flush (VDEC_FreezePicSelect eFreezePic) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Flush (VDEC_FreezePicSelect eFreezePic)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetDetailDescription(EventIndex, U16 *, U16 *, U16) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetDetailDescription (EventIndex event, U16 * pDescription, U16 * pStrLength, U16 length) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetDetailDescription (EventIndex event, U16 * pDescription, U16 * pStrLength, U16 length)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_GetLibVer (const MSIF_Version ** ppVersion)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApp_SI_SetTargetRegion(U8 *, U8, U8, U16) */
EXTERN_C_LINKAGE void MApp_SI_SetTargetRegion (U8 * pu8Country, U8 u8PrimaryRegion, U8 u8SecondaryRegion, U16 u16Tertiary) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_SetTargetRegion (U8 * pu8Country, U8 u8PrimaryRegion, U8 u8SecondaryRegion, U16 u16Tertiary)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_AVFifo_Status(MS_U32, MS_U32 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_AVFifo_Status (MS_U32 DmxFltType, MS_U32 * u32FifoLevel) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_AVFifo_Status (MS_U32 DmxFltType, MS_U32 * u32FifoLevel)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MDrv_MVOP_GetIsInterlace(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MVOP_GetIsInterlace () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MVOP_GetIsInterlace (void)
{
    if( CppTest_IsCurrentTestCase("TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True") )
    {
        return 1;
    }

    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_CEC_GetCmdLen(void) */
EXTERN_C_LINKAGE MS_U8 MApi_CEC_GetCmdLen () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_CEC_GetCmdLen (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void DRV_VIF_Init(VIFInitialIn *, MS_U32) */
EXTERN_C_LINKAGE void DRV_VIF_Init (VIFInitialIn * pVIF_InitData, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_Init (VIFInitialIn * pVIF_InitData, MS_U32 u32InitDataLen)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_IsBlackVideoEnable(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsBlackVideoEnable (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsBlackVideoEnable (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Dmx_SetOADScanMode(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_Dmx_SetOADScanMode (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_SetOADScanMode (BOOLEAN bEnable)
{
}

/** User stub definition for function: void MDrv_DDC2BI_CommandHandler(void) */
EXTERN_C_LINKAGE void MDrv_DDC2BI_CommandHandler () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DDC2BI_CommandHandler (void)
{
}

/** User stub definition for function: void MApi_JPEG_Rst(void) */
EXTERN_C_LINKAGE void MApi_JPEG_Rst () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_Rst (void)
{
}

/** User stub definition for function: const unsigned short ** __ctype_b_loc(void) */
EXTERN_C_LINKAGE const unsigned short ** __ctype_b_loc () ;
EXTERN_C_LINKAGE const unsigned short ** CppTest_Stub___ctype_b_loc (void)
{
    return (const unsigned short **)0;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_Init(JPEG_InitParam *) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_Init (JPEG_InitParam * pInitParam) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_Init (JPEG_InitParam * pInitParam)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: MS_U32 MDrv_BDMA_CRC32(MS_PHYADDR, MS_U32, MS_U32, MS_U32, BDMA_SrcDev, MS_BOOL) */
EXTERN_C_LINKAGE MS_U32 MDrv_BDMA_CRC32 (MS_PHYADDR u32Addr, MS_U32 u32Len, MS_U32 u32Poly, MS_U32 u32Seed, BDMA_SrcDev eDev, MS_BOOL bReflect) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_BDMA_CRC32 (MS_PHYADDR u32Addr, MS_U32 u32Len, MS_U32 u32Poly, MS_U32 u32Seed, BDMA_SrcDev eDev, MS_BOOL bReflect)
{
    return 0UL;
}

/** User stub definition for function: GFX_Result MApi_GFX_BeginDraw(void) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_BeginDraw () ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_BeginDraw (void)
{
    return GFX_FAIL;
}

/** User stub definition for function: IR_Result MDrv_IR_SetCallback(IR_Callback) */
EXTERN_C_LINKAGE IR_Result MDrv_IR_SetCallback (IR_Callback pCallback) ;
EXTERN_C_LINKAGE IR_Result CppTest_Stub_MDrv_IR_SetCallback (IR_Callback pCallback)
{
    return E_IR_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_SetSpeed(VDEC_SpeedType, VDEC_DispSpeed) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_SetSpeed (VDEC_SpeedType eSpeedType, VDEC_DispSpeed eSpeed) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_SetSpeed (VDEC_SpeedType eSpeedType, VDEC_DispSpeed eSpeed)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_Get_3D_HW2DTo3D_Parameters(MS_XC_3D_HW2DTO3D_PARA *) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Get_3D_HW2DTo3D_Parameters (MS_XC_3D_HW2DTO3D_PARA * pst3DHw2DTo3DPara) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Get_3D_HW2DTo3D_Parameters (MS_XC_3D_HW2DTO3D_PARA * pst3DHw2DTo3DPara)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MsOS_ObtainMutex(MS_S32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MsOS_ObtainMutex (MS_S32 s32MutexId, MS_U32 u32WaitMs) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_ObtainMutex (MS_S32 s32MutexId, MS_U32 u32WaitMs)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_MMICancelEnq(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_MMICancelEnq () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_MMICancelEnq (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_GenPattern(VDEC_PatternType, MS_PHYADDR, MS_U32 *) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_GenPattern (VDEC_PatternType ePatternType, MS_PHYADDR u32Addr, MS_U32 * pu32Size) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_GenPattern (VDEC_PatternType ePatternType, MS_PHYADDR u32Addr, MS_U32 * pu32Size)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: BOOLEAN msAPI_CI_GetCICAMName(U8 *, U8) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_GetCICAMName (U8 * u8pCICAM_Name, U8 u8NameBufferSize) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_GetCICAMName (U8 * u8pCICAM_Name, U8 u8NameBufferSize)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_GetInfo(CI_OP_INFO *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_GetInfo (CI_OP_INFO * pstOP_Info) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_GetInfo (CI_OP_INFO * pstOP_Info)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL mapi_mhl_SendRCP_PressRelease_Cmd(MS_U8, MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_SendRCP_PressRelease_Cmd (MS_U8 u8RCPKey, MS_BOOL bIsRelease) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_SendRCP_PressRelease_Cmd (MS_U8 u8RCPKey, MS_BOOL bIsRelease)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_DNR_Init_Motion(void) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DNR_Init_Motion () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DNR_Init_Motion (void)
{
}

/** User stub definition for function: void MApp_SI_ResetPATMonitor(void) */
EXTERN_C_LINKAGE void MApp_SI_ResetPATMonitor () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_ResetPATMonitor (void)
{
}

/** User stub definition for function: MS_U16 MDrv_HDMI_Func_Caps(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_HDMI_Func_Caps () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_HDMI_Func_Caps (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U16 MDrv_MVOP_GetHStart(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_MVOP_GetHStart () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_MVOP_GetHStart (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U8 MApi_CEC_GetTxStatus(void) */
EXTERN_C_LINKAGE MS_U8 MApi_CEC_GetTxStatus () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_CEC_GetTxStatus (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetAC3PInfo(Audio_AC3P_infoType, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetAC3PInfo (Audio_AC3P_infoType infoType, MS_U32 param1, MS_U32 param2) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetAC3PInfo (Audio_AC3P_infoType infoType, MS_U32 param1, MS_U32 param2)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_ACE_Init(XC_ACE_InitData *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_ACE_Init (XC_ACE_InitData * pstXC_ACE_InitData, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_ACE_Init (XC_ACE_InitData * pstXC_ACE_InitData, MS_U32 u32InitDataLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_VE_Exit(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VE_Exit () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VE_Exit (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_SectReset(MS_U8) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_SectReset (MS_U8 u8DmxId) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_SectReset (MS_U8 u8DmxId)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApp_SI_Get_MoveServiceIDS(MOVE_SERVICE_IDS *) */
EXTERN_C_LINKAGE void MApp_SI_Get_MoveServiceIDS (MOVE_SERVICE_IDS * pMoveSrv) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Get_MoveServiceIDS (MOVE_SERVICE_IDS * pMoveSrv)
{
}

/** User stub definition for function: void MApi_XC_SetHdmiSyncMode(E_HDMI_SYNC_TYPE) */
EXTERN_C_LINKAGE void MApi_XC_SetHdmiSyncMode (E_HDMI_SYNC_TYPE esynctype) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetHdmiSyncMode (E_HDMI_SYNC_TYPE esynctype)
{
}

/** User stub definition for function: MS_U8 MApi_XC_ACE_DNR_GetMotion_Weight(MS_U8, MS_U8, MS_U8, MS_U8, MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ACE_DNR_GetMotion_Weight (MS_U8 u8CurMotion, MS_U8 u8PreMotion, MS_U8 u8CurMotionLvl, MS_U8 u8PreMotionLvl, MS_U8 u8DeFlick_Thre, MS_U8 u8DeFilick_Step) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ACE_DNR_GetMotion_Weight (MS_U8 u8CurMotion, MS_U8 u8PreMotion, MS_U8 u8CurMotionLvl, MS_U8 u8PreMotionLvl, MS_U8 u8DeFlick_Thre, MS_U8 u8DeFilick_Step)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_SetNearestMode(MS_BOOL) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetNearestMode (MS_BOOL enable) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetNearestMode (MS_BOOL enable)
{
    return GFX_FAIL;
}

/** User stub definition for function: PM_Result MDrv_PM_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE PM_Result MDrv_PM_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE PM_Result CppTest_Stub_MDrv_PM_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_PM_FAIL;
}

/** User stub definition for function: void MApp_SI_GetFileInPIDS(FileIn_SERVICE_INFO *) */
EXTERN_C_LINKAGE void MApp_SI_GetFileInPIDS (FileIn_SERVICE_INFO * stFileInServiceInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_GetFileInPIDS (FileIn_SERVICE_INFO * stFileInServiceInfo)
{
}

/** User stub definition for function: void MApi_XC_GenerateBlackVideoForBothWin(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_GenerateBlackVideoForBothWin (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GenerateBlackVideoForBothWin (MS_BOOL bEnable)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_Set_3D_Mode(E_XC_3D_INPUT_MODE, E_XC_3D_OUTPUT_MODE, E_XC_3D_PANEL_TYPE, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Set_3D_Mode (E_XC_3D_INPUT_MODE e3dInputMode, E_XC_3D_OUTPUT_MODE e3dOutputMode, E_XC_3D_PANEL_TYPE e3dPanelType, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Set_3D_Mode (E_XC_3D_INPUT_MODE e3dInputMode, E_XC_3D_OUTPUT_MODE e3dOutputMode, E_XC_3D_PANEL_TYPE e3dPanelType, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MApi_XC_Get_3D_HW_Version(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_Get_3D_HW_Version () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_Get_3D_HW_Version (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test_MApp_Scaler_SetVideo3DMode_3D_HW_Version_1"))
	{
		return (unsigned short)3;
	}
	else
	{
		return (unsigned short)0;
	}
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_GetMAD_LOCK(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_GetMAD_LOCK () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_GetMAD_LOCK (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SwapOverlapWin(MS_U8, MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SwapOverlapWin (MS_U8 u8GOP, MS_U8 u8win) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SwapOverlapWin (MS_U8 u8GOP, MS_U8 u8win)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_XC_SetFrameBufferAddress(MS_PHYADDR, MS_PHYADDR, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetFrameBufferAddress (MS_PHYADDR u32FBAddress, MS_PHYADDR u32FBSize, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetFrameBufferAddress (MS_PHYADDR u32FBAddress, MS_PHYADDR u32FBSize, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApi_XC_GetDEWidthHeightInDEByPassMode(MS_U16 *, MS_U16 *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_GetDEWidthHeightInDEByPassMode (MS_U16 * pu16Width, MS_U16 * pu16Height, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GetDEWidthHeightInDEByPassMode (MS_U16 * pu16Width, MS_U16 * pu16Height, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApi_CEC_SetFifoIdx(MS_U8) */
EXTERN_C_LINKAGE void MApi_CEC_SetFifoIdx (MS_U8 u8Idx) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetFifoIdx (MS_U8 u8Idx)
{
}

/** User stub definition for function: MS_BOOL MApi_CEC_CheckFrame(MsCEC_MSG_TRANS_TYPE, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_CEC_CheckFrame (MsCEC_MSG_TRANS_TYPE msg_type, MS_U8 ucLen) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_CEC_CheckFrame (MsCEC_MSG_TRANS_TYPE msg_type, MS_U8 ucLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_MHEG_DecodeIFrame(MS_PHYADDR, MS_PHYADDR, MS_PHYADDR) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_MHEG_DecodeIFrame (MS_PHYADDR u32FrameBufAddr, MS_PHYADDR u32SrcSt, MS_PHYADDR u32SrcEnd) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_MHEG_DecodeIFrame (MS_PHYADDR u32FrameBufAddr, MS_PHYADDR u32SrcSt, MS_PHYADDR u32SrcEnd)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_MIUSel(MS_U8, EN_GOP_SEL_TYPE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_MIUSel (MS_U8 u8GOP, EN_GOP_SEL_TYPE MiuSel) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_MIUSel (MS_U8 u8GOP, EN_GOP_SEL_TYPE MiuSel)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_XC_MLoad_Enable(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_MLoad_Enable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_MLoad_Enable (MS_BOOL bEnable)
{
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_FeatureAbort(MsCEC_DEVICELA, MsCEC_MSGLIST, MsCEC_MSG_ABORT_REASON) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_FeatureAbort (MsCEC_DEVICELA dst_address, MsCEC_MSGLIST msg, MsCEC_MSG_ABORT_REASON cmd) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_FeatureAbort (MsCEC_DEVICELA dst_address, MsCEC_MSGLIST msg, MsCEC_MSG_ABORT_REASON cmd)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: U8 MApp_SI_GetScanNumOfPatItem(void) */
EXTERN_C_LINKAGE U8 MApp_SI_GetScanNumOfPatItem () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_SI_GetScanNumOfPatItem (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Switch2Gwin(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Switch2Gwin (MS_U8 winId) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Switch2Gwin (MS_U8 winId)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Open(MS_U32, MS_U8 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Open (MS_U32 DmxFltType, MS_U8 * pu8DmxId) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Open (MS_U32 DmxFltType, MS_U8 * pu8DmxId)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MDrv_DMX_TTX_Init(MS_PHYADDR, MS_U16) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMX_TTX_Init (MS_PHYADDR bufferAddr, MS_U16 packetCount) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMX_TTX_Init (MS_PHYADDR bufferAddr, MS_U16 packetCount)
{
    return (unsigned char)0;
}

/** User stub definition for function: void mapi_mhl_RegisterCallBackFunctions(link_cbus_event_handle_func, link_cbus_event_handle_func) */
EXTERN_C_LINKAGE void mapi_mhl_RegisterCallBackFunctions (link_cbus_event_handle_func rcp, link_cbus_event_handle_func rap) ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_RegisterCallBackFunctions (link_cbus_event_handle_func rcp, link_cbus_event_handle_func rap)
{
}

/** User stub definition for function: void MDrv_VBI_GetVPS_Data(MS_U8 *, MS_U8 *) */
EXTERN_C_LINKAGE void MDrv_VBI_GetVPS_Data (MS_U8 * lowerWord, MS_U8 * higherWord) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VBI_GetVPS_Data (MS_U8 * lowerWord, MS_U8 * higherWord)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_ModeParse_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_ModeParse_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_ModeParse_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AVD_SetRegFromDSP(void) */
EXTERN_C_LINKAGE void MDrv_AVD_SetRegFromDSP () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_SetRegFromDSP (void)
{
}

/** User stub definition for function: U8 MDrv_UsbGetMaxLUNCount_Port2(void) */
EXTERN_C_LINKAGE U8 MDrv_UsbGetMaxLUNCount_Port2 () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_UsbGetMaxLUNCount_Port2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_DTV_HDMI_CFG(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_DTV_HDMI_CFG (MS_U8 ctrl) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_DTV_HDMI_CFG (MS_U8 ctrl)
{
}

/** User stub definition for function: MS_U16 MDrv_AVD_GetVTotal(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_AVD_GetVTotal(void) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_AVD_GetVTotal(void)
{
    return 625;
}

/** User stub definition for function: MS_BOOL MDrv_AVD_SetVideoStandard(AVD_VideoStandardType, MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AVD_SetVideoStandard (AVD_VideoStandardType eStandard, MS_BOOL bIsInAutoTuning) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AVD_SetVideoStandard (AVD_VideoStandardType eStandard, MS_BOOL bIsInAutoTuning)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_CEC_SetMsgCnt(MS_U8) */
EXTERN_C_LINKAGE void MApi_CEC_SetMsgCnt (MS_U8 u8Cnt) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetMsgCnt (MS_U8 u8Cnt)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_SetPlaybackStamp(MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_SetPlaybackStamp (MS_U32 u32Stamp) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_SetPlaybackStamp (MS_U32 u32Stamp)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_U8 MDrv_HDMI_err_status_update(MS_U8, MS_BOOL) */
EXTERN_C_LINKAGE MS_U8 MDrv_HDMI_err_status_update (MS_U8 u8value, MS_BOOL bread) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_HDMI_err_status_update (MS_U8 u8value, MS_BOOL bread)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_SetAutoPreScaling(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetAutoPreScaling (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetAutoPreScaling (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApi_XC_ACE_SelectYUVtoRGBMatrix(MS_BOOL, MS_U8, MS_S16 *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_SelectYUVtoRGBMatrix (MS_BOOL eWindow, MS_U8 ucMatrix, MS_S16 * psUserYUVtoRGBMatrix) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_SelectYUVtoRGBMatrix (MS_BOOL eWindow, MS_U8 ucMatrix, MS_S16 * psUserYUVtoRGBMatrix)
{
}

/** User stub definition for function: MS_U8 DRV_VIF_Read_CR_LOCK_STATUS(void) */
EXTERN_C_LINKAGE MS_U8 DRV_VIF_Read_CR_LOCK_STATUS () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_DRV_VIF_Read_CR_LOCK_STATUS (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_MVOP_Enable(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_MVOP_Enable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_MVOP_Enable (MS_BOOL bEnable)
{
}

/** User stub definition for function: BOOLEAN msAPI_Subtitle_CheckPTS(U32) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Subtitle_CheckPTS (U32 u32STC) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Subtitle_CheckPTS (U32 u32STC)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Stop(MS_U8) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Stop (MS_U8 u8DmxId) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Stop (MS_U8 u8DmxId)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MApi_XC_3DMainSub_IPSync(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_3DMainSub_IPSync () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_3DMainSub_IPSync (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ADC_Source_Calibrate(INPUT_SOURCE_TYPE_t) */
EXTERN_C_LINKAGE void MApi_XC_ADC_Source_Calibrate (INPUT_SOURCE_TYPE_t enInputSourceType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_Source_Calibrate (INPUT_SOURCE_TYPE_t enInputSourceType)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_GetFileInTimeStamp(MS_U32 *) */

EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_GetFileInTimeStamp (MS_U32 * pu32FileInTS) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_GetFileInTimeStamp (MS_U32 * pu32FileInTS)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_else") )
	{

		*pu32FileInTS = 40*90*1000;

	}
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_GetPlaybackTimeSec_if") )
	{
		*pu32FileInTS = 4490000;
	}

    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void msAPI_Subtitle_Init_Display(U16, U16) */
EXTERN_C_LINKAGE void msAPI_Subtitle_Init_Display (U16 u16VideoWidth, U16 u16VideoHeight) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_Init_Display (U16 u16VideoWidth, U16 u16VideoHeight)
{
}

/** User stub definition for function: void MDrv_AUDIO_WriteDecMailBox(MS_U8, MS_U16) */
EXTERN_C_LINKAGE void MDrv_AUDIO_WriteDecMailBox (MS_U8 paramNum, MS_U16 data1) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_WriteDecMailBox (MS_U8 paramNum, MS_U16 data1)
{
}

/** User stub definition for function: MS_U16 MDrv_MVOP_GetHSize(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_MVOP_GetHSize () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_MVOP_GetHSize (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApi_JPEG_SetProMaxDecodeResolution(MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_JPEG_SetProMaxDecodeResolution (MS_U16 u16ProWidth, MS_U16 u16ProHeight) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetProMaxDecodeResolution (MS_U16 u16ProWidth, MS_U16 u16ProHeight)
{
}

/** User stub definition for function: void MDrv_VE_Init(MS_PHYADDR) */
EXTERN_C_LINKAGE void MDrv_VE_Init (MS_PHYADDR u32MIUAddress) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_Init (MS_PHYADDR u32MIUAddress)
{
}

/** User stub definition for function: void MApi_XC_FreezeImg(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_FreezeImg (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_FreezeImg (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_ADVSOUND_ProcessEnable(ADVSND_TYPE) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_ADVSOUND_ProcessEnable (ADVSND_TYPE type) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_ADVSOUND_ProcessEnable (ADVSND_TYPE type)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_DT_SendUTC(U8 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_DT_SendUTC (U8 * pu8UTCTime) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_DT_SendUTC (U8 * pu8UTCTime)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 msAPI_CI_RemoveControlByte(U8 *, U8) */
EXTERN_C_LINKAGE U8 msAPI_CI_RemoveControlByte (U8 * pu8Req, U8 u8Len) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_CI_RemoveControlByte (U8 * pu8Req, U8 u8Len)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SPDIF_SetMute(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_SPDIF_SetMute (MS_BOOL mute_en) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SPDIF_SetMute (MS_BOOL mute_en)
{
}

/** User stub definition for function: MS_U16 MApi_XC_ACE_DNR_Blending_MISC(MS_U8, MS_U16, MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_ACE_DNR_Blending_MISC (MS_U8 u8NewItem, MS_U16 u16PreItem, MS_U8 u8Weight, MS_U8 u8Step) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_ACE_DNR_Blending_MISC (MS_U8 u8NewItem, MS_U16 u16PreItem, MS_U8 u8Weight, MS_U8 u8Step)
{
    return (unsigned short)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Filein_Info(DMX_Filein_info *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Filein_Info (DMX_Filein_info * pFileinInfo) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Filein_Info (DMX_Filein_info * pFileinInfo)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApi_AUDIO_SetAbsoluteVolume(MS_U8, MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetAbsoluteVolume (MS_U8 u8Path, MS_U8 u8Vol1, MS_U8 u8Vol2) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetAbsoluteVolume (MS_U8 u8Path, MS_U8 u8Vol1, MS_U8 u8Vol2)
{
}

/** User stub definition for function: void msAPI_CI_HSS_Set(U8 *, U16, U16, U16) */
EXTERN_C_LINKAGE void msAPI_CI_HSS_Set (U8 * pu8Section, U16 u16Length, U16 u16TS_ID, U16 u16ServiceID) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_HSS_Set (U8 * pu8Section, U16 u16Length, U16 u16TS_ID, U16 u16ServiceID)
{
}

/** User stub definition for function: void MDrv_HDCP_Enable(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_HDCP_Enable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDCP_Enable (MS_BOOL bEnable)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Proc(MS_U8, MS_U32 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Proc (MS_U8 u8DmxId, MS_U32 * pEvent) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Proc (MS_U8 u8DmxId, MS_U32 * pEvent)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_PWM_Polarity(PWM_ChNum, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PWM_Polarity (PWM_ChNum u8IndexPWM, MS_BOOL bPolPWM) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PWM_Polarity (PWM_ChNum u8IndexPWM, MS_BOOL bPolPWM)
{
}

/** User stub definition for function: void MApi_XC_SetDispWinToReg(MS_WINDOW_TYPE *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetDispWinToReg (MS_WINDOW_TYPE * pstDspwin, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetDispWinToReg (MS_WINDOW_TYPE * pstDspwin, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_PHYADDR MApi_JPEG_GetFreeMemory(MS_U32) */
EXTERN_C_LINKAGE MS_PHYADDR MApi_JPEG_GetFreeMemory (MS_U32 size) ;
EXTERN_C_LINKAGE MS_PHYADDR CppTest_Stub_MApi_JPEG_GetFreeMemory (MS_U32 size)
{
    return 0UL;
}

/** User stub definition for function: void MApi_CEC_SetActiveDeviceCECVersion(MS_U8) */
EXTERN_C_LINKAGE void MApi_CEC_SetActiveDeviceCECVersion (MS_U8 u8Ver) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetActiveDeviceCECVersion (MS_U8 u8Ver)
{
}

/** User stub definition for function: void MAPP_EPG_SetFunctionFlag(EN_EPG_FUNC_FLAG) */
EXTERN_C_LINKAGE void MAPP_EPG_SetFunctionFlag (EN_EPG_FUNC_FLAG eFlag) ;
EXTERN_C_LINKAGE void CppTest_Stub_MAPP_EPG_SetFunctionFlag (EN_EPG_FUNC_FLAG eFlag)
{
}

/** User stub definition for function: MS_BOOL MApi_JPEG_IsProgressive(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_JPEG_IsProgressive () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_JPEG_IsProgressive (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_S32 MsOS_CreateTimer(TimerCb, MS_U32, MS_U32, MS_BOOL, char *) */
EXTERN_C_LINKAGE MS_S32 MsOS_CreateTimer (TimerCb pTimerCb, MS_U32 u32FirstTimeMs, MS_U32 u32PeriodTimeMs, MS_BOOL bStartTimer, char * pName) ;
EXTERN_C_LINKAGE MS_S32 CppTest_Stub_MsOS_CreateTimer (TimerCb pTimerCb, MS_U32 u32FirstTimeMs, MS_U32 u32PeriodTimeMs, MS_BOOL bStartTimer, char * pName)
{
    return 0L;
}

/** User stub definition for function: MS_S32 msAPI_Timer_GetTime0(void) */
EXTERN_C_LINKAGE U32 msAPI_Timer_GetTime0 (void) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Timer_GetTime0 (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_Yes"))
	{
		return (unsigned char)100;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_GetDownTimer0_No"))
	{
		return (unsigned char)60;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetDownTimer0"))
	{
		return (unsigned char)2;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_Sleep_test_MApp_Sleep_SetAutoOn_OffTime_IF_TRUE"))
	{
		return (unsigned char)50;
	}
	else
	{
		return 0L;
	}
}

/** User stub definition for function: void mdrv_gpio_set_high(MS_GPIO_NUM) */
EXTERN_C_LINKAGE void mdrv_gpio_set_high (MS_GPIO_NUM gpio) ;
EXTERN_C_LINKAGE void CppTest_Stub_mdrv_gpio_set_high (MS_GPIO_NUM gpio)
{
}

/** User stub definition for function: void msAPI_CI_SetMMIBufAddr(U32) */
EXTERN_C_LINKAGE void msAPI_CI_SetMMIBufAddr (U32 u32BufAdr) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_SetMMIBufAddr (U32 u32BufAdr)
{
}

/** User stub definition for function: MS_BOOL MApi_SWI2C_ReadByte(MS_U16, MS_U8, MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL MApi_SWI2C_ReadByte (MS_U16 u16BusNumSlaveID, MS_U8 u8RegAddr, MS_U8 * pu8Data) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SWI2C_ReadByte (MS_U16 u16BusNumSlaveID, MS_U8 u8RegAddr, MS_U8 * pu8Data)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U32 MApi_JPEG_GetDataOffset(void) */
EXTERN_C_LINKAGE MS_U32 MApi_JPEG_GetDataOffset () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_JPEG_GetDataOffset (void)
{
    return 0UL;
}

/** User stub definition for function: void MDrv_HDCP_Vsync_end_en(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_HDCP_Vsync_end_en (MS_BOOL bStable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDCP_Vsync_end_en (MS_BOOL bStable)
{
}

/** User stub definition for function: MS_U16 MApi_XC_PCMonitor_Get_VFreqx10(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_PCMonitor_Get_VFreqx10 (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_PCMonitor_Get_VFreqx10 (SCALER_WIN eWindow)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U16 MApi_XC_PCMonitor_Get_Vtotal(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_PCMonitor_Get_Vtotal (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_PCMonitor_Get_Vtotal (SCALER_WIN eWindow)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApp_SI_CICAM_NIT_Parse(U8 *, U16) */
EXTERN_C_LINKAGE void MApp_SI_CICAM_NIT_Parse (U8 * pu8SectionData, U16 u16SecCount) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_CICAM_NIT_Parse (U8 * pu8SectionData, U16 u16SecCount)
{
}

/** User stub definition for function: void DRV_VIF_ShiftClk(MS_U8) */
EXTERN_C_LINKAGE void DRV_VIF_ShiftClk (MS_U8 VifShiftClk) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_ShiftClk (MS_U8 VifShiftClk)
{
}

/** User stub definition for function: IR_Result MDrv_IR_Config(IR_TimeBnd *) */
EXTERN_C_LINKAGE IR_Result MDrv_IR_Config (IR_TimeBnd * pIRTimeBnd) ;
EXTERN_C_LINKAGE IR_Result CppTest_Stub_MDrv_IR_Config (IR_TimeBnd * pIRTimeBnd)
{
    return E_IR_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_SectWriteGet(MS_U8, MS_PHYADDR *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_SectWriteGet (MS_U8 u8DmxId, MS_PHYADDR * pWrite) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_SectWriteGet (MS_U8 u8DmxId, MS_PHYADDR * pWrite)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_VE_SetBlackScreen(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_VE_SetBlackScreen (MS_BOOL bEn) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SetBlackScreen (MS_BOOL bEn)
{
}

/** User stub definition for function: void MDrv_HDCP_ClearStatus(void) */
EXTERN_C_LINKAGE void MDrv_HDCP_ClearStatus () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDCP_ClearStatus (void)
{
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsFrameRdy(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsFrameRdy () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsFrameRdy (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_U32 MDrv_PM_RTCGetMatchTime(void) */
EXTERN_C_LINKAGE MS_U32 MDrv_PM_RTCGetMatchTime () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_PM_RTCGetMatchTime (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCWakeUpTime"))
	{
		return (unsigned char)100;
	}
	else
	{
    return 0UL;
}
}

/** User stub definition for function: void MApi_AUDIO_EnableAutoVolume(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_EnableAutoVolume (MS_BOOL EnAVL) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_EnableAutoVolume (MS_BOOL EnAVL)
{
}

/** User stub definition for function: void MApi_XC_DLC_Handler(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_DLC_Handler (MS_BOOL bWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_Handler (MS_BOOL bWindow)
{
}

/** User stub definition for function: void mdrv_gpio_init(void) */
EXTERN_C_LINKAGE void mdrv_gpio_init () ;
EXTERN_C_LINKAGE void CppTest_Stub_mdrv_gpio_init (void)
{
}

/** User stub definition for function: void MApi_XC_ACE_MWESetDispWin(MS_U16, MS_U16, MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_ACE_MWESetDispWin (MS_U16 u16MWE_Disp_Hstart, MS_U16 u16MWE_Disp_Vstart, MS_U16 u16MWE_Disp_Width, MS_U16 u16MWE_Disp_Height) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_MWESetDispWin (MS_U16 u16MWE_Disp_Hstart, MS_U16 u16MWE_Disp_Vstart, MS_U16 u16MWE_Disp_Width, MS_U16 u16MWE_Disp_Height)
{
}

/** User stub definition for function: double sqrt(double) */
EXTERN_C_LINKAGE double sqrt (double __x) ;
EXTERN_C_LINKAGE double CppTest_Stub_sqrt (double __x)
{
    return 0.0;
}

/** User stub definition for function: PWM_Result MDrv_PWM_UnitDiv(MS_U16) */
EXTERN_C_LINKAGE PWM_Result MDrv_PWM_UnitDiv (MS_U16 u16UnitDivPWM) ;
EXTERN_C_LINKAGE PWM_Result CppTest_Stub_MDrv_PWM_UnitDiv (MS_U16 u16UnitDivPWM)
{
    return E_PWM_OK;
}

/** User stub definition for function: MS_U16 MApi_XC_CalculateHFreqx10(MS_U16) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_CalculateHFreqx10 (MS_U16 u16HPeriod) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_CalculateHFreqx10 (MS_U16 u16HPeriod)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MDrv_BDMA_SetSPIOffsetForMCU(void) */
EXTERN_C_LINKAGE void MDrv_BDMA_SetSPIOffsetForMCU () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_BDMA_SetSPIOffsetForMCU (void)
{
}

/** User stub definition for function: BOOLEAN MDrv_UsbDeviceConnect(void) */
EXTERN_C_LINKAGE BOOLEAN MDrv_UsbDeviceConnect () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_UsbDeviceConnect (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MDrv_GET_MASS_VALID_LUN(void) */
EXTERN_C_LINKAGE U8 MDrv_GET_MASS_VALID_LUN () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_GET_MASS_VALID_LUN (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_HDMI_ARC_PINControl(E_MUX_INPUTPORT, MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_HDMI_ARC_PINControl (E_MUX_INPUTPORT enInputPortType, MS_BOOL bEnable, MS_BOOL bDrivingHigh) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDMI_ARC_PINControl (E_MUX_INPUTPORT enInputPortType, MS_BOOL bEnable, MS_BOOL bDrivingHigh)
{
}

/** User stub definition for function: PWM_Result MDrv_PWM_Period(PWM_ChNum, MS_U32) */
EXTERN_C_LINKAGE PWM_Result MDrv_PWM_Period (PWM_ChNum u8IndexPWM, MS_U32 u32PeriodPWM) ;
EXTERN_C_LINKAGE PWM_Result CppTest_Stub_MDrv_PWM_Period (PWM_ChNum u8IndexPWM, MS_U32 u32PeriodPWM)
{
    return E_PWM_OK;
}

/** User stub definition for function: void msAPI_OAD_ClearData(void) */
EXTERN_C_LINKAGE void msAPI_OAD_ClearData () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_OAD_ClearData (void)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_CheckCurProgScramble(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_CheckCurProgScramble () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_CheckCurProgScramble (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_ColorCorrectionTable(MS_BOOL, MS_S16 *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_ColorCorrectionTable (MS_BOOL bScalerWin, MS_S16 * psColorCorrectionTable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_ColorCorrectionTable (MS_BOOL bScalerWin, MS_S16 * psColorCorrectionTable)
{
}

/** User stub definition for function: E_XC_3D_PANEL_TYPE MApi_XC_Get_3D_Panel_Type(void) */
EXTERN_C_LINKAGE E_XC_3D_PANEL_TYPE MApi_XC_Get_3D_Panel_Type () ;
EXTERN_C_LINKAGE E_XC_3D_PANEL_TYPE CppTest_Stub_MApi_XC_Get_3D_Panel_Type (void)
{
    return E_XC_3D_PANEL_NONE;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_DeleteWin(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_DeleteWin (MS_U8 winId) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_DeleteWin (MS_U8 winId)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_GetAccess(MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_GetAccess (MS_U32 u32Try) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_GetAccess (MS_U32 u32Try)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Switch2FB(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Switch2FB (MS_U8 fbId) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Switch2FB (MS_U8 fbId)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void TT_DecoderInputPackets(void) */
EXTERN_C_LINKAGE void TT_DecoderInputPackets () ;
EXTERN_C_LINKAGE void CppTest_Stub_TT_DecoderInputPackets (void)
{
}

/** User stub definition for function: void msAPI_Subtitle_SetReduceGwin(BOOLEAN) */
EXTERN_C_LINKAGE void msAPI_Subtitle_SetReduceGwin (BOOLEAN bSet) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_SetReduceGwin (BOOLEAN bSet)
{
}

/** User stub definition for function: void msAPI_Subtitle_Init_Display_OP(void) */
EXTERN_C_LINKAGE void msAPI_Subtitle_Init_Display_OP () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_Init_Display_OP (void)
{
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventSplit(EventIndex, MW_EN_EPG_CRID_SEARCH, U8 *, U16 *, EventIndex *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventSplit (EventIndex event, MW_EN_EPG_CRID_SEARCH enSearch, U8 * pPCN, U16 * pServiceID, EventIndex * pEvent) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetEventSplit (EventIndex event, MW_EN_EPG_CRID_SEARCH enSearch, U8 * pPCN, U16 * pServiceID, EventIndex * pEvent)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: void MApi_CEC_SetActiveLogicalAddress(MsCEC_DEVICELA) */
EXTERN_C_LINKAGE void MApi_CEC_SetActiveLogicalAddress (MsCEC_DEVICELA Addr) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetActiveLogicalAddress (MsCEC_DEVICELA Addr)
{
}

/** User stub definition for function: U32 MApp_EPGDB_GetMaxEventNumInDB(void) */
EXTERN_C_LINKAGE U32 MApp_EPGDB_GetMaxEventNumInDB () ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_EPGDB_GetMaxEventNumInDB (void)
{
    return 0UL;
}

/** User stub definition for function: void MDrv_DMX_TTX_RingBuffer_Reset(void) */
EXTERN_C_LINKAGE void MDrv_DMX_TTX_RingBuffer_Reset () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DMX_TTX_RingBuffer_Reset (void)
{
}

/** User stub definition for function: MS_BOOL mapi_mhl_SendRAPCmd(MS_U8) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_SendRAPCmd (MS_U8 databuf) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_SendRAPCmd (MS_U8 databuf)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MDrv_AVD_GetStatus(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_AVD_GetStatus () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_AVD_GetStatus (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApp_SI_Update_Time(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_SI_Update_Time (BOOLEAN bAutoClock) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Update_Time (BOOLEAN bAutoClock)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetClip(GFX_Point *, GFX_Point *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetClip (GFX_Point * v0, GFX_Point * v1) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetClip (GFX_Point * v0, GFX_Point * v1)
{
    return GFX_FAIL;
}

/** User stub definition for function: AU_DVB_DECCMD MApi_AUDIO_GetCommand(En_DVB_AudioDecoder) */
EXTERN_C_LINKAGE AU_DVB_DECCMD MApi_AUDIO_GetCommand (En_DVB_AudioDecoder AdoDecoderNo) ;
EXTERN_C_LINKAGE AU_DVB_DECCMD CppTest_Stub_MApi_AUDIO_GetCommand (En_DVB_AudioDecoder AdoDecoderNo)
{
    return AU_DVB_DECCMD_STOP;
}

/** User stub definition for function: void MApi_AUDIO_HDMI_SetNonpcm(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_HDMI_SetNonpcm (MS_U8 nonPCM_en) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_HDMI_SetNonpcm (MS_U8 nonPCM_en)
{
}

/** User stub definition for function: void msAPI_Subtitle_Init_Queue(U32, U32) */
EXTERN_C_LINKAGE void msAPI_Subtitle_Init_Queue (U32 u32Adr, U32 u32Len) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_Init_Queue (U32 u32Adr, U32 u32Len)
{
}

/** User stub definition for function: void MApi_AUDIO_SetOutputInfo(AUDIO_OUT_INFO *) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetOutputInfo (AUDIO_OUT_INFO * pout_info) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetOutputInfo (AUDIO_OUT_INFO * pout_info)
{
}

/** User stub definition for function: void MApi_XC_EnableFrameBufferLess(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_EnableFrameBufferLess (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableFrameBufferLess (MS_BOOL bEnable)
{
}

/** User stub definition for function: MS_U16 MDrv_MVOP_GetVSize(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_MVOP_GetVSize () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_MVOP_GetVSize (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U32 MApi_XC_GetCapability(MS_U32) */
EXTERN_C_LINKAGE MS_U32 MApi_XC_GetCapability (MS_U32 u32Id) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_XC_GetCapability (MS_U32 u32Id)
{
    return 0UL;
}

/** User stub definition for function: void msAPI_CI_Initial(BOOLEAN) */
EXTERN_C_LINKAGE void msAPI_CI_Initial (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_Initial (BOOLEAN bEnable)
{
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_CopyHnd(MS_PHYADDR, MS_PHYADDR, MS_U32, SPIDMA_Dev, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_CopyHnd (MS_PHYADDR u32FlashAddr, MS_PHYADDR u32DstAddr, MS_U32 u32Len, SPIDMA_Dev eDstDev, MS_U8 u8OpCfg) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_CopyHnd (MS_PHYADDR u32FlashAddr, MS_PHYADDR u32DstAddr, MS_U32 u32Len, SPIDMA_Dev eDstDev, MS_U8 u8OpCfg)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_Set_3D_HW2DTo3D_Buffer(MS_PHYADDR, MS_PHYADDR) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Set_3D_HW2DTo3D_Buffer (MS_PHYADDR u32HW2DTO3D_DD_Buf, MS_PHYADDR u32HW2DTO3D_DR_Buf) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Set_3D_HW2DTo3D_Buffer (MS_PHYADDR u32HW2DTO3D_DD_Buf, MS_PHYADDR u32HW2DTO3D_DR_Buf)
{
    return (unsigned char)0;
}

/** User stub definition for function: PM_Result MDrv_PM_Init(PM_WakeCfg *) */
EXTERN_C_LINKAGE PM_Result MDrv_PM_Init (PM_WakeCfg * pPmWakeCfg) ;
EXTERN_C_LINKAGE PM_Result CppTest_Stub_MDrv_PM_Init (PM_WakeCfg * pPmWakeCfg)
{
    return E_PM_FAIL;
}

/** User stub definition for function: void MApi_XC_PCMonitor_Restart(SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_PCMonitor_Restart (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_PCMonitor_Restart (SCALER_WIN eWindow)
{
}

/** User stub definition for function: void qsort(void *, size_t, size_t, __compar_fn_t) */
EXTERN_C_LINKAGE void qsort (void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar) ;
EXTERN_C_LINKAGE void CppTest_Stub_qsort (void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
{
}

/** User stub definition for function: void MApi_XC_SoftwareReset(MS_U8, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SoftwareReset (MS_U8 u8Reset, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SoftwareReset (MS_U8 u8Reset, SCALER_WIN eWindow)
{
}

/** User stub definition for function: UART_DEVICE_TYPE mdrv_uart_get_connection(UART_PORT_TYPE) */
EXTERN_C_LINKAGE UART_DEVICE_TYPE mdrv_uart_get_connection (UART_PORT_TYPE uart_port) ;
EXTERN_C_LINKAGE UART_DEVICE_TYPE CppTest_Stub_mdrv_uart_get_connection (UART_PORT_TYPE uart_port)
{
    return E_UART_INVALID;
}

/** User stub definition for function: void MApi_CEC_ConfigWakeUp(void) */
EXTERN_C_LINKAGE void MApi_CEC_ConfigWakeUp () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_ConfigWakeUp (void)
{
}

/** User stub definition for function: void MApp_SI_GetDtvPmgData(SI_SHORT_DTV_CHANNEL_INFO *, U8, SI_DTV_CHANNEL_INFO *) */
EXTERN_C_LINKAGE void MApp_SI_GetDtvPmgData (SI_SHORT_DTV_CHANNEL_INFO * pstDtvPmgDataNoSrvName, U8 SrvNameIdx, SI_DTV_CHANNEL_INFO * pstDtvPgmData) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_GetDtvPmgData (SI_SHORT_DTV_CHANNEL_INFO * pstDtvPmgDataNoSrvName, U8 SrvNameIdx, SI_DTV_CHANNEL_INFO * pstDtvPgmData)
{
}

/** User stub definition for function: MS_U32 MsOS_GetSystemTime(void) */
EXTERN_C_LINKAGE MS_U32 MsOS_GetSystemTime () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_GetSystemTime (void)
{
	  if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_GetTime0"))
	  {
		  return 1UL;
	  }
	  else
	  {
          return 0UL;
      }
}

/** User stub definition for function: MS_BOOL MApi_XC_Enable_TwoInitFactor(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Enable_TwoInitFactor (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Enable_TwoInitFactor (MS_BOOL bEnable, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 mdrv_uart_set_rx_callback_halreg(MS_U32, ms_uart_rx_callback_halreg) */
EXTERN_C_LINKAGE MS_U16 mdrv_uart_set_rx_callback_halreg (MS_U32 uart, ms_uart_rx_callback_halreg rx_cb) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_mdrv_uart_set_rx_callback_halreg (MS_U32 uart, ms_uart_rx_callback_halreg rx_cb)
{
    return (unsigned short)0;
}

/** User stub definition for function: MMI_INFO * msAPI_CI_MMIGetData(void) */
EXTERN_C_LINKAGE MMI_INFO * msAPI_CI_MMIGetData () ;
EXTERN_C_LINKAGE MMI_INFO * CppTest_Stub_msAPI_CI_MMIGetData (void)
{
    return (MMI_INFO *)0;
}

/** User stub definition for function: MS_U16 MApi_JPEG_GetCurVidx(void) */
EXTERN_C_LINKAGE MS_U16 MApi_JPEG_GetCurVidx () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_JPEG_GetCurVidx (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessDDB(U8 *, U16 *, U16 *, U32 *, U16 *) */
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessDDB (U8 * _MT_var609, U16 * _MT_var610, U16 * _MT_var611, U32 * _MT_var612, U16 * _MT_var613) ;
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE CppTest_Stub_msAPI_OAD_ProcessDDB (U8 * _MT_var330, U16 * _MT_var331, U16 * _MT_var332, U32 * _MT_var333, U16 * _MT_var334)
{
    return OAD_SUCCEED;
}

/** User stub definition for function: BOOLEAN ms_DecompressInit(U8 *) */
EXTERN_C_LINKAGE BOOLEAN ms_DecompressInit (U8 * pOutStream) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_ms_DecompressInit (U8 * pOutStream)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_LZSS_COMPRESS_ifno"))
	{
		int tmp = 1 ;
		printf("print:tmp =  %d", tmp);
		return TRUE;
	}
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_UART_Init(UART_DEVICE_TYPE, MS_U32) */
EXTERN_C_LINKAGE void MDrv_UART_Init (UART_DEVICE_TYPE uart_dev, MS_U32 baudrate) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_UART_Init (UART_DEVICE_TYPE uart_dev, MS_U32 baudrate)
{
}

/** User stub definition for function: void MApi_GFX_Init(GFX_Config *) */
EXTERN_C_LINKAGE void MApi_GFX_Init (GFX_Config * geConfig) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_GFX_Init (GFX_Config * geConfig)
{
}

/** User stub definition for function: MS_BOOL MApi_GOP_GWIN_IsEnabled(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_GOP_GWIN_IsEnabled () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_GOP_GWIN_IsEnabled (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_SI_Get_NetWorkName(U8 *, U8 *, U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Get_NetWorkName (U8 * name, U8 * len, U8 u16MaxLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Get_NetWorkName (U8 * name, U8 * len, U8 u16MaxLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AVD_SetFreerunFreq(AVD_FreeRunFreq) */
EXTERN_C_LINKAGE void MDrv_AVD_SetFreerunFreq (AVD_FreeRunFreq eFreerunfreq) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_SetFreerunFreq (AVD_FreeRunFreq eFreerunfreq)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_RegisterGetFontCB(MS_U32 (*)(MS_S8, GFX_FontInfo *)) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_RegisterGetFontCB (MS_U32 (* fpGFX_CB)(MS_S8, GFX_FontInfo *)) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_RegisterGetFontCB (MS_U32 (* fpGFX_CB)(MS_S8, GFX_FontInfo *))
{
    return GFX_FAIL;
}

/** User stub definition for function: GFX_Result MApi_GFX_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_GetLibVer (const MSIF_Version ** ppVersion)
{
    return GFX_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_EnableLastFrameShow(MS_BOOL) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_EnableLastFrameShow (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_EnableLastFrameShow (MS_BOOL bEnable)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: AUDIO_HDMI_RX_TYPE MApi_AUDIO_HDMI_RX_GetNonPCM(void) */
EXTERN_C_LINKAGE AUDIO_HDMI_RX_TYPE MApi_AUDIO_HDMI_RX_GetNonPCM () ;
EXTERN_C_LINKAGE AUDIO_HDMI_RX_TYPE CppTest_Stub_MApi_AUDIO_HDMI_RX_GetNonPCM (void)
{
    return HDMI_RX_PCM;
}

/** User stub definition for function: MS_U8 MDrv_AVD_GetHsyncEdge(void) */
EXTERN_C_LINKAGE MS_U8 MDrv_AVD_GetHsyncEdge () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_AVD_GetHsyncEdge (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AUDIO_FwTriggerDSP(MS_U16) */
EXTERN_C_LINKAGE void MDrv_AUDIO_FwTriggerDSP (MS_U16 u16Cmd) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_FwTriggerDSP (MS_U16 u16Cmd)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_2GSetPaletteOpt(GOP_PaletteEntry *, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_2GSetPaletteOpt (GOP_PaletteEntry * pPalArray, MS_U16 u32PalStart, MS_U16 u32PalEnd) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_2GSetPaletteOpt (GOP_PaletteEntry * pPalArray, MS_U16 u32PalStart, MS_U16 u32PalEnd)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_Read(MS_U32, MS_U32, MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_Read (MS_U32 u32FlashAddr, MS_U32 u32FlashSize, MS_U8 * user_buffer) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_Read (MS_U32 u32FlashAddr, MS_U32 u32FlashSize, MS_U8 * user_buffer)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_Bootloader_test_GetFlashPosOf2ndMagicNo_ifyes_ifyes"))
	{
		*user_buffer = 1;
	//	((BININFO*)user_buffer)->B_ID == BIN_ID_MAGIC_55AAABCD;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_Bootloader_test_msAPI_BLoader_IsIspUpdate_ifyes"))
	{
		*user_buffer = 0;
	}
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_CU_GetState(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CU_GetState () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CU_GetState (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MDrv_AUDIO_ReadDecMailBox(MS_U8) */
EXTERN_C_LINKAGE MS_U16 MDrv_AUDIO_ReadDecMailBox (MS_U8 paramNum) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_AUDIO_ReadDecMailBox (MS_U8 paramNum)
{
    return (unsigned short)0;
}

/** User stub definition for function: U8 msAPI_OAD_GetDsiVersionNum(void) */
EXTERN_C_LINKAGE U8 msAPI_OAD_GetDsiVersionNum () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_OAD_GetDsiVersionNum (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_Enable(MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_Enable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_Enable (MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: GFX_Result MApi_GFX_ClearFrameBuffer(MS_PHYADDR, MS_U32, MS_U8) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_ClearFrameBuffer (MS_PHYADDR StrAddr, MS_U32 length, MS_U8 ClearValue) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_ClearFrameBuffer (MS_PHYADDR StrAddr, MS_U32 length, MS_U8 ClearValue)
{
    return GFX_FAIL;
}

/** User stub definition for function: JPEG_ErrCode MApi_JPEG_GetErrorCode(void) */
EXTERN_C_LINKAGE JPEG_ErrCode MApi_JPEG_GetErrorCode () ;
EXTERN_C_LINKAGE JPEG_ErrCode CppTest_Stub_MApi_JPEG_GetErrorCode (void)
{
    return E_JPEG_NO_ERROR;
}

/** User stub definition for function: BOOLEAN MDrv_UsbBlockReadToMIU_Port2(U8, U32, U32, U32) */
EXTERN_C_LINKAGE BOOLEAN MDrv_UsbBlockReadToMIU_Port2 (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_UsbBlockReadToMIU_Port2 (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_Sys_RunCodeInSPI(void) */
EXTERN_C_LINKAGE void MDrv_Sys_RunCodeInSPI () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_Sys_RunCodeInSPI (void)
{
}

/** User stub definition for function: U8 MApp_Dmx_EIT_Get_CurPfVer(void) */
EXTERN_C_LINKAGE U8 MApp_Dmx_EIT_Get_CurPfVer () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_Dmx_EIT_Get_CurPfVer (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_COPRO_Init_End(MS_U32) */
EXTERN_C_LINKAGE void MDrv_COPRO_Init_End (MS_U32 u32_ADR) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_COPRO_Init_End (MS_U32 u32_ADR)
{
}

/** User stub definition for function: BOOLEAN DRV_VIF_GetInputLevelIndicator(void) */
EXTERN_C_LINKAGE BOOLEAN DRV_VIF_GetInputLevelIndicator () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_DRV_VIF_GetInputLevelIndicator (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: VE_Result MDrv_VE_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE VE_Result MDrv_VE_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE VE_Result CppTest_Stub_MDrv_VE_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_VE_NOT_SUPPORT;
}

/** User stub definition for function: OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessDSI(U8 *) */
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessDSI (U8 * _MT_var607) ;
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE CppTest_Stub_msAPI_OAD_ProcessDSI (U8 * _MT_var230)
{
    return OAD_SUCCEED;
}

/** User stub definition for function: MS_S16 MApi_XC_Mux_CreatePath(XC_MUX_PATH_INFO *, MS_U32) */
EXTERN_C_LINKAGE MS_S16 MApi_XC_Mux_CreatePath (XC_MUX_PATH_INFO * Path_Info, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE MS_S16 CppTest_Stub_MApi_XC_Mux_CreatePath (XC_MUX_PATH_INFO * Path_Info, MS_U32 u32InitDataLen)
{
    return (short)0;
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_ReadStatusRegister(MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_ReadStatusRegister (MS_U8 * pu8StatusReg) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_ReadStatusRegister (MS_U8 * pu8StatusReg)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Dmx_SetFid(U8, EN_FID) */
EXTERN_C_LINKAGE void MApp_Dmx_SetFid (U8 u8Fid, EN_FID eFid) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_SetFid (U8 u8Fid, EN_FID eFid)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_GetCheckFreqChange(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_GetCheckFreqChange () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_GetCheckFreqChange (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_SetWinProperty(GOP_DwinProperty *) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_SetWinProperty (GOP_DwinProperty * pproperty) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_SetWinProperty (GOP_DwinProperty * pproperty)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_GetDispInfo(VDEC_DispInfo *) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_GetDispInfo (VDEC_DispInfo * pDispinfo) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_GetDispInfo (VDEC_DispInfo * pDispinfo)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: BOOLEAN MApp_EPGDB_Setup(U16, U32, U32, U32, U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_EPGDB_Setup (U16 u16MaxDTVProgram, U32 u32EventDBSDRAMAdr, U32 u32EventDBSDRAMLen, U32 u32EPGExtDBSDRAMAdr, U32 u32EPGExtDBSDRAMLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_EPGDB_Setup (U16 u16MaxDTVProgram, U32 u32EventDBSDRAMAdr, U32 u32EventDBSDRAMLen, U32 u32EPGExtDBSDRAMAdr, U32 u32EPGExtDBSDRAMLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AVD_SetHsyncDetectionForTuning(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_AVD_SetHsyncDetectionForTuning (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_SetHsyncDetectionForTuning (MS_BOOL bEnable)
{
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_SetCommand(MVOP_Handle *, MVOP_Command, void *) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_SetCommand (MVOP_Handle * stHd, MVOP_Command eCmd, void * pPara) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_SetCommand (MVOP_Handle * stHd, MVOP_Command eCmd, void * pPara)
{
    return E_MVOP_OK;
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_DeckControl(MsCEC_DEVICELA, MsCEC_MSG_DC_DECK_CTRL_PARM) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_DeckControl (MsCEC_DEVICELA dst_address, MsCEC_MSG_DC_DECK_CTRL_PARM cmd) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_DeckControl (MsCEC_DEVICELA dst_address, MsCEC_MSG_DC_DECK_CTRL_PARM cmd)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: MS_HDMI_PACKET_VALUE_t MDrv_HDMI_Packet_Received(MS_BOOL) */
EXTERN_C_LINKAGE MS_HDMI_PACKET_VALUE_t MDrv_HDMI_Packet_Received (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_HDMI_PACKET_VALUE_t CppTest_Stub_MDrv_HDMI_Packet_Received (MS_BOOL bEnable)
{
    static MS_HDMI_PACKET_VALUE_t _MT_svar1;    return _MT_svar1;
}

/** User stub definition for function: MS_U32 mdrv_uart_open(UART_DEVICE_TYPE) */
EXTERN_C_LINKAGE MS_U32 mdrv_uart_open (UART_DEVICE_TYPE uart_dev) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_mdrv_uart_open (UART_DEVICE_TYPE uart_dev)
{
    return 0UL;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetCurrentFBID(void) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetCurrentFBID () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetCurrentFBID (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MsOS_CPU_SetEBASE(MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MsOS_CPU_SetEBASE (MS_U32 u32Addr) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_CPU_SetEBASE (MS_U32 u32Addr)
{
    return (unsigned char)0;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_Pf_GetTableVersion(MEMBER_SI_SERVICETYPE, U16, U8 *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_Pf_GetTableVersion (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, U8 * pu8TableVer) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_Pf_GetTableVersion (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, U8 * pu8TableVer)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: BOOLEAN MApp_SI_Get_UTCTime(U8 *) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Get_UTCTime (U8 * time) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Get_UTCTime (U8 * time)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U32 MsOS_CPU_DisableInterrupt(void) */
EXTERN_C_LINKAGE MS_U32 MsOS_CPU_DisableInterrupt () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_CPU_DisableInterrupt (void)
{
    return 0UL;
}

/** User stub definition for function: OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessDII(U8 *) */
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE msAPI_OAD_ProcessDII (U8 * _MT_var608) ;
EXTERN_C_LINKAGE OAD_STATUS_REPORT_TYPE CppTest_Stub_msAPI_OAD_ProcessDII (U8 * _MT_var318)
{
    return OAD_SUCCEED;
}

/** User stub definition for function: void MApi_JPEG_UpdateReadInfo(MS_U32, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_JPEG_UpdateReadInfo (MS_U32 u32DataRead, MS_BOOL bEOFflag) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_UpdateReadInfo (MS_U32 u32DataRead, MS_BOOL bEOFflag)
{
}

/** User stub definition for function: U32 msAPI_DecodeStr(const U8 *, U32, U8, U8 *, U32) */
EXTERN_C_LINKAGE unsigned int msAPI_DecodeStr (const unsigned char * pbufEncStr, unsigned int nLenStr, unsigned char nEncodeType, unsigned char * pbufDecStr, unsigned int nMaxBufDecStr) ;
EXTERN_C_LINKAGE unsigned int CppTest_Stub_msAPI_DecodeStr (const unsigned char * pbufEncStr, unsigned int nLenStr, unsigned char nEncodeType, unsigned char * pbufDecStr, unsigned int nMaxBufDecStr)
{
    return 0UL;
}

/** User stub definition for function: MS_PAT_ITEM * MApp_SI_Get_PastPATItem(void) */
EXTERN_C_LINKAGE MS_PAT_ITEM * MApp_SI_Get_PastPATItem () ;
EXTERN_C_LINKAGE MS_PAT_ITEM * CppTest_Stub_MApp_SI_Get_PastPATItem (void)
{
    return (MS_PAT_ITEM *)0;
}

/** User stub definition for function: void MDrv_PWM_Vdben(PWM_ChNum, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PWM_Vdben (PWM_ChNum u8IndexPWM, MS_BOOL bVdbenPWM) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PWM_Vdben (PWM_ChNum u8IndexPWM, MS_BOOL bVdbenPWM)
{
}

/** User stub definition for function: void MDrv_UsbClose(void) */
EXTERN_C_LINKAGE void MDrv_UsbClose () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_UsbClose (void)
{
}

/** User stub definition for function: void MApp_Dmx_Disable_Reset_Filter(void) */
EXTERN_C_LINKAGE void MApp_Dmx_Disable_Reset_Filter () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_Disable_Reset_Filter (void)
{
}

/** User stub definition for function: void msAPI_CNI_GetStationName(unsigned short, unsigned char *) */
EXTERN_C_LINKAGE void msAPI_CNI_GetStationName (unsigned short wStationId, unsigned char * sStationName) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CNI_GetStationName (unsigned short wStationId, unsigned char * sStationName)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_SetFW(MS_PHYADDR, MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_SetFW (MS_PHYADDR pFwAddr, MS_U32 u32FwSize) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_SetFW (MS_PHYADDR pFwAddr, MS_U32 u32FwSize)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void DRV_VIF_Reset(void) */
EXTERN_C_LINKAGE void DRV_VIF_Reset () ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_Reset (void)
{
}

/** User stub definition for function: int puts(const char *) */
EXTERN_C_LINKAGE int puts (const char * s) ;
EXTERN_C_LINKAGE int CppTest_Stub_puts (const char * s)
{
    return 0;
}

/** User stub definition for function: void MApp_SI_Reset_CheckSameServiceTimer(void) */
EXTERN_C_LINKAGE void MApp_SI_Reset_CheckSameServiceTimer () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Reset_CheckSameServiceTimer (void)
{
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetFreeFBID(void) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetFreeFBID () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetFreeFBID (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MAsm_CPU_Sync(void) */
EXTERN_C_LINKAGE void MAsm_CPU_Sync () ;
EXTERN_C_LINKAGE void CppTest_Stub_MAsm_CPU_Sync (void)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_SetHK(MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_SetHK (MS_BOOL bIsHK) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_SetHK (MS_BOOL bIsHK)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MDrv_MVOP_CheckCapability(MS_U16, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MVOP_CheckCapability (MS_U16 u16HSize, MS_U16 u16VSize, MS_U16 u16Fps) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MVOP_CheckCapability (MS_U16 u16HSize, MS_U16 u16VSize, MS_U16 u16Fps)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_IsCicamInProfile(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_IsCicamInProfile () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_IsCicamInProfile (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Filein_Start(DMX_FILEIN_DST, MS_PHYADDR, MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Filein_Start (DMX_FILEIN_DST Dst, MS_PHYADDR pBuf, MS_U32 u32BufSize) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Filein_Start (DMX_FILEIN_DST Dst, MS_PHYADDR pBuf, MS_U32 u32BufSize)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_BlockToAddress(MS_U32, MS_U32 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_BlockToAddress (MS_U32 u32BlockIndex, MS_U32 * pu32FlashAddr) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_BlockToAddress (MS_U32 u32BlockIndex, MS_U32 * pu32FlashAddr)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SOUND_SetParam(Sound_SET_Type, MS_U32 *) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SOUND_SetParam (Sound_SET_Type Type, MS_U32 * p_param) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SOUND_SetParam (Sound_SET_Type Type, MS_U32 * p_param)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MDrv_AVD_GetRegValue(MS_U16) */
EXTERN_C_LINKAGE MS_U8 MDrv_AVD_GetRegValue (MS_U16 u16Addr) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_AVD_GetRegValue (MS_U16 u16Addr)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_SetSrcColorKey(MS_BOOL, GFX_ColorKeyMode, GFX_Buffer_Format, void *, void *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetSrcColorKey (MS_BOOL enable, GFX_ColorKeyMode opMode, GFX_Buffer_Format fmt, void * ps_color, void * pe_color) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetSrcColorKey (MS_BOOL enable, GFX_ColorKeyMode opMode, GFX_Buffer_Format fmt, void * ps_color, void * pe_color)
{
    return GFX_FAIL;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_MVOP_OK;
}

/** User stub definition for function: GFX_Result MApi_GFX_DrawBitmap(MS_S32, GFX_DrawBmpInfo *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_DrawBitmap (MS_S32 handle, GFX_DrawBmpInfo * pbmpfmt) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_DrawBitmap (MS_S32 handle, GFX_DrawBmpInfo * pbmpfmt)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_Set_3D_LR_Frame_Exchg(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Set_3D_LR_Frame_Exchg (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Set_3D_LR_Frame_Exchg (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_Subtitle_Queue_Push(U32, U16, U32) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Subtitle_Queue_Push (U32 u32Address, U16 u16Len, U32 u32PTS) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Subtitle_Queue_Push (U32 u32Address, U16 u16Len, U32 u32PTS)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_HLC_SetLanguage(U8 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HLC_SetLanguage (U8 * pLanguage) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HLC_SetLanguage (U8 * pLanguage)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MApi_AUDIO_HDMI_GetSynthFreq(void) */
EXTERN_C_LINKAGE MS_U16 MApi_AUDIO_HDMI_GetSynthFreq () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_AUDIO_HDMI_GetSynthFreq (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U8 MDrv_AUTH_IPCheck(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MDrv_AUTH_IPCheck (MS_U8 u8Bit) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_AUTH_IPCheck (MS_U8 u8Bit)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_AddressErase(MS_U32, MS_U32, MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_AddressErase (MS_U32 u32StartAddr, MS_U32 u32EraseSize, MS_BOOL bWait) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_AddressErase (MS_U32 u32StartAddr, MS_U32 u32EraseSize, MS_BOOL bWait)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_GetFBInfo(MS_U8, GOP_GwinFBAttr *) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_GetFBInfo (MS_U8 fbId, GOP_GwinFBAttr * fbAttr) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_GetFBInfo (MS_U8 fbId, GOP_GwinFBAttr * fbAttr)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: BOOLEAN msAPI_CI_HC_GetTunePMTSection(U8 *, U16 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HC_GetTunePMTSection (U8 * u8pTunePMTSection, U16 * u16pTunePMTSectionLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HC_GetTunePMTSection (U8 * u8pTunePMTSection, U16 * u16pTunePMTSectionLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 drvUSBHost_HID_Initial_Port2(void) */
EXTERN_C_LINKAGE U8 drvUSBHost_HID_Initial_Port2 () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_drvUSBHost_HID_Initial_Port2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_SetTrickMode(VDEC_TrickDec) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_SetTrickMode (VDEC_TrickDec eTrickDec) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_SetTrickMode (VDEC_TrickDec eTrickDec)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: BOOLEAN MDrv_UsbBlockWriteFromMIU_Port2(U8, U32, U32, U32) */
EXTERN_C_LINKAGE BOOLEAN MDrv_UsbBlockWriteFromMIU_Port2 (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_UsbBlockWriteFromMIU_Port2 (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_CheckWriteDone(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_CheckWriteDone () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_CheckWriteDone (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_AUDIO_RA8_Param(MS_U16, MS_U16, MS_U16, MS_U16 *, MS_U16 *, MS_U16 *, MS_U16 *, MS_U16 *) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_RA8_Param (MS_U16 mNumCodecs, MS_U16 mSamples, MS_U16 mSampleRate, MS_U16 * Channels, MS_U16 * Regions, MS_U16 * cplStart, MS_U16 * cplQbits, MS_U16 * FrameSize) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_RA8_Param (MS_U16 mNumCodecs, MS_U16 mSamples, MS_U16 mSampleRate, MS_U16 * Channels, MS_U16 * Regions, MS_U16 * cplStart, MS_U16 * cplQbits, MS_U16 * FrameSize)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MDrv_HDMI_GC_Info(HDMI_GControl_INFO_t) */
EXTERN_C_LINKAGE MS_U16 MDrv_HDMI_GC_Info (HDMI_GControl_INFO_t gcontrol) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_HDMI_GC_Info (HDMI_GControl_INFO_t gcontrol)
{
    return (unsigned short)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetPaletteOpt(GOP_PaletteEntry *, MS_U16, MS_U16, EN_GOP_PALETTE_TYPE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetPaletteOpt (GOP_PaletteEntry * pPalArray, MS_U16 u32PalStart, MS_U16 u32PalEnd, EN_GOP_PALETTE_TYPE ePalType) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetPaletteOpt (GOP_PaletteEntry * pPalArray, MS_U16 u32PalStart, MS_U16 u32PalEnd, EN_GOP_PALETTE_TYPE ePalType)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApp_Epg_SrvPriorityHandler(U16) */
EXTERN_C_LINKAGE void MApp_Epg_SrvPriorityHandler (U16 u16MainlistIdx) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Epg_SrvPriorityHandler (U16 u16MainlistIdx)
{
}

/** User stub definition for function: void MApi_AUTH_Process(MS_U8 *, MS_U8 *) */
EXTERN_C_LINKAGE void MApi_AUTH_Process (MS_U8 * string, MS_U8 * hash) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUTH_Process (MS_U8 * string, MS_U8 * hash)
{
}

/** User stub definition for function: EN_SMARTCARD_TYPE msAPI_CI_GetCardType(void) */
EXTERN_C_LINKAGE EN_SMARTCARD_TYPE msAPI_CI_GetCardType () ;
EXTERN_C_LINKAGE EN_SMARTCARD_TYPE CppTest_Stub_msAPI_CI_GetCardType (void)
{
    return EN_SMARTCARD_TYPE_NONE;
}

/** User stub definition for function: AVD_VideoStandardType MDrv_AVD_GetStandardDetection(MS_U16 *) */
EXTERN_C_LINKAGE AVD_VideoStandardType MDrv_AVD_GetStandardDetection (MS_U16 * u16LatchStatus) ;
EXTERN_C_LINKAGE AVD_VideoStandardType CppTest_Stub_MDrv_AVD_GetStandardDetection (MS_U16 * u16LatchStatus)
{
    return E_VIDEOSTANDARD_PAL_BGHI;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_SetOwner(MS_U8, MS_U8, MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_SetOwner (MS_U8 u8DmxIdStart, MS_U8 u8DmxIdEnd, MS_BOOL bOwner) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_SetOwner (MS_U8 u8DmxIdStart, MS_U8 u8DmxIdEnd, MS_BOOL bOwner)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApp_Epg_RemoveProgram(WORD) */
EXTERN_C_LINKAGE void MApp_Epg_RemoveProgram (WORD wSrvOrder) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Epg_RemoveProgram (WORD wSrvOrder)
{
}

/** User stub definition for function: MBX_Result MDrv_MBX_ClearMSG(MBX_Class) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_ClearMSG (MBX_Class eMsgClass) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_ClearMSG (MBX_Class eMsgClass)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MApi_XC_ADC_SetCVBSOut(MS_BOOL, E_DEST_TYPE, INPUT_SOURCE_TYPE_t, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_ADC_SetCVBSOut (MS_BOOL bEnable, E_DEST_TYPE enOutputType, INPUT_SOURCE_TYPE_t enInputPortType, MS_BOOL isDigitalSource) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_SetCVBSOut (MS_BOOL bEnable, E_DEST_TYPE enOutputType, INPUT_SOURCE_TYPE_t enInputPortType, MS_BOOL isDigitalSource)
{
}

/** User stub definition for function: MS_BOOL mapi_mhl_CableDetect(void) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_CableDetect () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_CableDetect (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: int ms_Decompress(const U8 *, U32) */
EXTERN_C_LINKAGE int ms_Decompress (const U8 * pInStream, U32 u32DataLen) ;
EXTERN_C_LINKAGE int CppTest_Stub_ms_Decompress (const U8 * pInStream, U32 u32DataLen)
{
    return 0;
}

/** User stub definition for function: MS_BOOL MsOS_Dcache_Flush(MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MsOS_Dcache_Flush (MS_U32 u32Start, MS_U32 u32Size) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_Dcache_Flush (MS_U32 u32Start, MS_U32 u32Size)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetTransClr(EN_GOP_TRANSCLR_FMT, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetTransClr (EN_GOP_TRANSCLR_FMT fmt, MS_U16 clr) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetTransClr (EN_GOP_TRANSCLR_FMT fmt, MS_U16 clr)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_TimeStampEnable(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_TimeStampEnable () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_TimeStampEnable (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_SetBEON_Host(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_SetBEON_Host (MS_BOOL bHost) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_SetBEON_Host (MS_BOOL bHost)
{
}

/** User stub definition for function: E_XC_3D_INPUT_MODE MApi_XC_Get_3D_Input_Mode(SCALER_WIN) */
EXTERN_C_LINKAGE E_XC_3D_INPUT_MODE MApi_XC_Get_3D_Input_Mode (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE E_XC_3D_INPUT_MODE CppTest_Stub_MApi_XC_Get_3D_Input_Mode (SCALER_WIN eWindow)
{
    return E_XC_3D_INPUT_FRAME_PACKING;
}

/** User stub definition for function: void MApp_Dmx_GetScanTableStateInit(void) */
EXTERN_C_LINKAGE void MApp_Dmx_GetScanTableStateInit () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_GetScanTableStateInit (void)
{
}

/** User stub definition for function: MsCEC_DEVICELA MApi_CEC_GetActiveLogicalAddress(void) */
EXTERN_C_LINKAGE MsCEC_DEVICELA MApi_CEC_GetActiveLogicalAddress () ;
EXTERN_C_LINKAGE MsCEC_DEVICELA CppTest_Stub_MApi_CEC_GetActiveLogicalAddress (void)
{
    return E_LA_TV;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_DetectType(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_DetectType () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_DetectType (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_DetectSize(MS_U32 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_DetectSize (MS_U32 * u32FlashSize) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_DetectSize (MS_U32 * u32FlashSize)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init"))
	{
		return (unsigned char)1;
	}
	else
	{
    return (unsigned char)0;
}
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_GetNIT(U8 *, U16 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_GetNIT (U8 * pu8OP_NIT, U16 * u16pOP_NITLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_GetNIT (U8 * pu8OP_NIT, U16 * u16pOP_NITLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_DNR_Blending_NRTbl(MS_U8 *, MS_U8, MS_U8, MS_U16 *, MS_U16 *, MS_U8 *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DNR_Blending_NRTbl (MS_U8 * pu8NewNR, MS_U8 u8Weight, MS_U8 u8Step, MS_U16 * pu16PreY0, MS_U16 * pu16PreY1, MS_U8 * pu8NRTBL) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DNR_Blending_NRTbl (MS_U8 * pu8NewNR, MS_U8 u8Weight, MS_U8 u8Step, MS_U16 * pu16PreY0, MS_U16 * pu16PreY1, MS_U8 * pu8NRTBL)
{
}

/** User stub definition for function: E_PWS_Result MDrv_PWS_Init(E_PWS_VIF_type) */
EXTERN_C_LINKAGE E_PWS_Result MDrv_PWS_Init (E_PWS_VIF_type eVifType) ;
EXTERN_C_LINKAGE E_PWS_Result CppTest_Stub_MDrv_PWS_Init (E_PWS_VIF_type eVifType)
{
    return PWS_FAIL;
}

/** User stub definition for function: PM_Result MDrv_PM_RtcInit(PM_RtcParam *) */
EXTERN_C_LINKAGE PM_Result MDrv_PM_RtcInit (PM_RtcParam * pPmRtcParam) ;
EXTERN_C_LINKAGE PM_Result CppTest_Stub_MDrv_PM_RtcInit (PM_RtcParam * pPmRtcParam)
{
    return E_PM_FAIL;
}

/** User stub definition for function: AUDIO_HDMI_RX_TYPE MApi_AUDIO_HDMI_RX_SetNonpcm(MS_U8) */
EXTERN_C_LINKAGE AUDIO_HDMI_RX_TYPE MApi_AUDIO_HDMI_RX_SetNonpcm (MS_U8 nonPCM_en) ;
EXTERN_C_LINKAGE AUDIO_HDMI_RX_TYPE CppTest_Stub_MApi_AUDIO_HDMI_RX_SetNonpcm (MS_U8 nonPCM_en)
{
    return HDMI_RX_PCM;
}

/** User stub definition for function: MS_U16 MApi_XC_ACE_DNR_Get_PrecisionShift(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_ACE_DNR_Get_PrecisionShift () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_ACE_DNR_Get_PrecisionShift (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendExit(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendExit () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendExit (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void DRV_VIF_BypassDBBAudioFilter(BOOLEAN) */
EXTERN_C_LINKAGE void DRV_VIF_BypassDBBAudioFilter (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_BypassDBBAudioFilter (BOOLEAN bEnable)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendInfoReq(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendInfoReq () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendInfoReq (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_CI_Set_TXRX_Interval(U16, U16, BOOLEAN) */
EXTERN_C_LINKAGE void msAPI_CI_Set_TXRX_Interval (U16 u16RXTXIntervalms, U16 u16TXRXIntervalms, BOOLEAN bEnableAlways) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_Set_TXRX_Interval (U16 u16RXTXIntervalms, U16 u16TXRXIntervalms, BOOLEAN bEnableAlways)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_IsMemoryFormat422(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsMemoryFormat422 (SCALER_WIN eWindow) ;
MS_BOOL g_XC_bIsMemoryFormat422;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsMemoryFormat422 (SCALER_WIN eWindow)
{
  if(CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_ForceOff"))
  {
	return (unsigned char)g_XC_bIsMemoryFormat422;
  }

  if(CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_HIGH"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_GetTuneDescriptor(U8 *, U16 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_GetTuneDescriptor (U8 * u8pTuneDescriptor, U16 * u16pTuneDescriptorLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_GetTuneDescriptor (U8 * u8pTuneDescriptor, U16 * u16pTuneDescriptorLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_ForceExit(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_ForceExit () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_ForceExit (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_AUDIO_SetDspBaseAddr(MS_U8, MS_U32, MS_U32) */
EXTERN_C_LINKAGE void MDrv_AUDIO_SetDspBaseAddr (MS_U8 u8Index, MS_U32 u32Bin_Base_Address, MS_U32 u32Mad_Base_Buffer_Adr) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_SetDspBaseAddr (MS_U8 u8Index, MS_U32 u32Bin_Base_Address, MS_U32 u32Mad_Base_Buffer_Adr)
{
}

/** User stub definition for function: MS_U32 MDrv_AUDIO_GetDspMadBaseAddr(MS_U8) */
EXTERN_C_LINKAGE MS_U32 MDrv_AUDIO_GetDspMadBaseAddr (MS_U8 u8Index) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_AUDIO_GetDspMadBaseAddr (MS_U8 u8Index)
{
  return 0UL;
}

/** User stub definition for function: MS_U32 MApi_VDEC_GetESWritePtr(void) */
EXTERN_C_LINKAGE MS_U32 MApi_VDEC_GetESWritePtr () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_VDEC_GetESWritePtr (void)
{
    return 0UL;
}

/** User stub definition for function: MS_U32 MsOS_DisableAllInterrupts(void) */
EXTERN_C_LINKAGE MS_U32 MsOS_DisableAllInterrupts () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_DisableAllInterrupts (void)
{
    return 0UL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsAlive(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsAlive () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsAlive (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SetMute(MS_U8, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetMute (MS_U8 u8Path, MS_BOOL EnMute) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetMute (MS_U8 u8Path, MS_BOOL EnMute)
{
}

/** User stub definition for function: U8 MDrv_GET_MASS_VALID_LUN_PORT2(void) */
EXTERN_C_LINKAGE U8 MDrv_GET_MASS_VALID_LUN_PORT2 () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_GET_MASS_VALID_LUN_PORT2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_JPEG_SetMRBufferValid(JPEG_BuffLoadType) */
EXTERN_C_LINKAGE void MApi_JPEG_SetMRBufferValid (JPEG_BuffLoadType u8MRBuffType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetMRBufferValid (JPEG_BuffLoadType u8MRBuffType)
{
}

/** User stub definition for function: void MApi_XC_WriteByte(MS_U32, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_WriteByte (MS_U32 u32Reg, MS_U8 u8Val) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_WriteByte (MS_U32 u32Reg, MS_U8 u8Val)
{
}

/** User stub definition for function: void MApp_SI_SetCheckFreqChange(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_SI_SetCheckFreqChange (BOOLEAN bFlag) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_SetCheckFreqChange (BOOLEAN bFlag)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_RectFill(GFX_RectFillInfo *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_RectFill (GFX_RectFillInfo * pfillblock) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_RectFill (GFX_RectFillInfo * pfillblock)
{
    return GFX_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_Stop(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_Stop () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_Stop (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: BOOLEAN msAPI_CI_MMIAnswerEnq(U8 *, U8) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_MMIAnswerEnq (U8 * pBuffer, U8 u8Length) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_MMIAnswerEnq (U8 * pBuffer, U8 u8Length)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_HDMI_COLOR_FORMAT MDrv_HDMI_Get_ColorFormat(void) */
EXTERN_C_LINKAGE MS_HDMI_COLOR_FORMAT MDrv_HDMI_Get_ColorFormat () ;
EXTERN_C_LINKAGE MS_HDMI_COLOR_FORMAT CppTest_Stub_MDrv_HDMI_Get_ColorFormat (void)
{
    return MS_HDMI_COLOR_RGB;
}

/** User stub definition for function: void MApi_XC_WriteByteMask(MS_U32, MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_WriteByteMask (MS_U32 u32Reg, MS_U8 u8Val, MS_U8 u8Msk) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_WriteByteMask (MS_U32 u32Reg, MS_U8 u8Val, MS_U8 u8Msk)
{
}

/** User stub definition for function: void MDrv_HDCP_initproductionkey(MS_U8 *) */
EXTERN_C_LINKAGE void MDrv_HDCP_initproductionkey (MS_U8 * pu8HdcpKeyData) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDCP_initproductionkey (MS_U8 * pu8HdcpKeyData)
{
}

/** User stub definition for function: void msAPI_CI_MMIFreeData(MMI_INFO *) */
EXTERN_C_LINKAGE void msAPI_CI_MMIFreeData (MMI_INFO * pMMIInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_MMIFreeData (MMI_INFO * pMMIInfo)
{
}

/** User stub definition for function: MS_HDCP_STATUS_INFO_t * MDrv_HDCP_GetStatus(void) */
EXTERN_C_LINKAGE MS_HDCP_STATUS_INFO_t * MDrv_HDCP_GetStatus () ;
EXTERN_C_LINKAGE MS_HDCP_STATUS_INFO_t * CppTest_Stub_MDrv_HDCP_GetStatus (void)
{
    return (MS_HDCP_STATUS_INFO_t *)0;
}

/** User stub definition for function: MS_U16 mdrv_uart_write(MS_U32, const MS_U8 *, MS_U16) */
EXTERN_C_LINKAGE MS_U16 mdrv_uart_write (MS_U32 uart, const MS_U8 * buf, MS_U16 len) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_mdrv_uart_write (MS_U32 uart, const MS_U8 * buf, MS_U16 len)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetFreeWinID(void) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetFreeWinID () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetFreeWinID (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_CEC_SetActivePowerStatus(MsCEC_MSG_POWER_STATUS_PARM) */
EXTERN_C_LINKAGE void MApi_CEC_SetActivePowerStatus (MsCEC_MSG_POWER_STATUS_PARM Status) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetActivePowerStatus (MsCEC_MSG_POWER_STATUS_PARM Status)
{
}

/** User stub definition for function: BOOLEAN DoMsDecompression7(U8 *, U8 *, U8 *, U32) */
EXTERN_C_LINKAGE BOOLEAN DoMsDecompression7 (U8 * pSrc, U8 * pDst, U8 * pTmp, U32 srclen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_DoMsDecompression7 (U8 * pSrc, U8 * pDst, U8 * pTmp, U32 srclen)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MDrv_UsbGetMaxLUNCount(void) */
EXTERN_C_LINKAGE U8 MDrv_UsbGetMaxLUNCount () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_UsbGetMaxLUNCount (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_MapFB2Win(MS_U8, MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_MapFB2Win (MS_U8 fbId, MS_U8 gwinId) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_MapFB2Win (MS_U8 fbId, MS_U8 gwinId)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_Auto_DetectWidth(XC_Auto_Signal_Info_Ex *, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Auto_DetectWidth (XC_Auto_Signal_Info_Ex * pSignalInfo, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Auto_DetectWidth (XC_Auto_Signal_Info_Ex * pSignalInfo, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ADC_SetPhaseEx(MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_ADC_SetPhaseEx (MS_U16 u16Value) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_SetPhaseEx (MS_U16 u16Value)
{
}

/** User stub definition for function: void MApi_XC_ADC_ScartRGB_SOG_ClampDelay(MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_ADC_ScartRGB_SOG_ClampDelay (MS_U16 u16Clpdly, MS_U16 u16Caldur) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_ScartRGB_SOG_ClampDelay (MS_U16 u16Clpdly, MS_U16 u16Caldur)
{
}

/** User stub definition for function: MS_BOOL MsOS_EnableInterrupt(InterruptNum) */
EXTERN_C_LINKAGE MS_BOOL MsOS_EnableInterrupt (InterruptNum eIntNum) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_EnableInterrupt (InterruptNum eIntNum)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_ResetNetwork(void) */
EXTERN_C_LINKAGE void MApp_SI_ResetNetwork () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_ResetNetwork (void)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Set_VStretchMode(EN_GOP_STRETCH_VMODE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Set_VStretchMode (EN_GOP_STRETCH_VMODE VStrchMode) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Set_VStretchMode (EN_GOP_STRETCH_VMODE VStrchMode)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Stc_Set(MS_U32, MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Stc_Set (MS_U32 u32Stc32, MS_U32 u32Stc) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Stc_Set (MS_U32 u32Stc32, MS_U32 u32Stc)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF1")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_ELSE1")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF_IF")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_IF")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_ELSE"))
		{
			u32Stc32 = 0;
			u32Stc = 0;
		}

    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_SYS_SetAGCPadMux(SYS_AGC_PAD_SET) */
EXTERN_C_LINKAGE void MDrv_SYS_SetAGCPadMux (SYS_AGC_PAD_SET eAgcPadMux) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_SYS_SetAGCPadMux (SYS_AGC_PAD_SET eAgcPadMux)
{
}

/** User stub definition for function: void MApp_Dmx_EIT_Proc(U32) */
EXTERN_C_LINKAGE void MApp_Dmx_EIT_Proc (U32 u32PollingMs) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_EIT_Proc (U32 u32PollingMs)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_PCMonitor_InvalidTimingDetect(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_PCMonitor_InvalidTimingDetect (MS_BOOL bPollingOnly, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_PCMonitor_InvalidTimingDetect (MS_BOOL bPollingOnly, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Dmx_SetReset_EventInfo_status(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_Dmx_SetReset_EventInfo_status (BOOLEAN bStatus) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_SetReset_EventInfo_status (BOOLEAN bStatus)
{
}

/** User stub definition for function: E_HDMI_SYNC_TYPE MApi_XC_GetHdmiSyncMode(void) */
EXTERN_C_LINKAGE E_HDMI_SYNC_TYPE MApi_XC_GetHdmiSyncMode () ;
EXTERN_C_LINKAGE E_HDMI_SYNC_TYPE CppTest_Stub_MApi_XC_GetHdmiSyncMode (void)
{
    return HDMI_SYNC_DE;
}

/** User stub definition for function: E_XC_ACE_RESULT MApi_XC_ACE_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE E_XC_ACE_RESULT MApi_XC_ACE_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE E_XC_ACE_RESULT CppTest_Stub_MApi_XC_ACE_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_XC_ACE_FAIL;
}

/** User stub definition for function: IR_Result MDrv_IR_Init(IR_RegCfg *) */
EXTERN_C_LINKAGE IR_Result MDrv_IR_Init (IR_RegCfg * pIRRegCfg) ;
EXTERN_C_LINKAGE IR_Result CppTest_Stub_MDrv_IR_Init (IR_RegCfg * pIRRegCfg)
{
    return E_IR_FAIL;
}

/** User stub definition for function: const XC_ApiInfo * MApi_XC_GetInfo(void) */
EXTERN_C_LINKAGE const XC_ApiInfo * MApi_XC_GetInfo () ;
EXTERN_C_LINKAGE const XC_ApiInfo * CppTest_Stub_MApi_XC_GetInfo (void)
{
	static XC_ApiInfo _stXC_ApiInfo;

	if( CppTest_IsCurrentTestCase("TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange") )
	{
		_stXC_ApiInfo.u8MaxWindowNum = 1;
		return &_stXC_ApiInfo;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_TRUE") )
	{
		_stXC_ApiInfo.u8MaxWindowNum = 1;
		return &_stXC_ApiInfo;
	}
	else if( CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_Abort_TRUE") )
	{
		_stXC_ApiInfo.u8MaxWindowNum = 1;
		return &_stXC_ApiInfo;
	}
	return (const XC_ApiInfo *)0;
}

/** User stub definition for function: void MDrv_AVD_3DCombSpeedup(void) */
EXTERN_C_LINKAGE void MDrv_AVD_3DCombSpeedup () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_3DCombSpeedup (void)
{
}

/** User stub definition for function: void MDrv_PM_RTCSetSystemTime(MS_U32) */
BOOL btest_msAPI_Timer_SetSystemTime = FALSE;
EXTERN_C_LINKAGE void MDrv_PM_RTCSetSystemTime (MS_U32 u32PmSysTime) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PM_RTCSetSystemTime (MS_U32 u32PmSysTime)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetSystemTime"))
	{
		btest_msAPI_Timer_SetSystemTime = TRUE;
	}
}

/** User stub definition for function: MS_BOOL MDrv_MVOP_EnableFreerunMode(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MVOP_EnableFreerunMode (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MVOP_EnableFreerunMode (MS_BOOL bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: long long MApi_AUDIO_GetCommAudioInfo(Audio_COMM_infoType) */
EXTERN_C_LINKAGE long long MApi_AUDIO_GetCommAudioInfo (Audio_COMM_infoType infoType) ;
EXTERN_C_LINKAGE long long CppTest_Stub_MApi_AUDIO_GetCommAudioInfo (Audio_COMM_infoType infoType)
{
    return (long long)0;
}

/** User stub definition for function: void MApp_SI_EnableNetworkCheck(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_SI_EnableNetworkCheck (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_EnableNetworkCheck (BOOLEAN bEnable)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_Open(DMX_Pvr_info *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_Open (DMX_Pvr_info * pPvrInfo) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_Open (DMX_Pvr_info * pPvrInfo)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetWmaInfo(Audio_WMA_infoType, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetWmaInfo (Audio_WMA_infoType infoType, MS_U32 param1, MS_U32 param2) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetWmaInfo (Audio_WMA_infoType infoType, MS_U32 param1, MS_U32 param2)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_TextOut(MS_S32, MS_U8 *, MS_U32, GFX_TextOutInfo *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_TextOut (MS_S32 fhandle, MS_U8 * pindex, MS_U32 strwidth, GFX_TextOutInfo * pfmt) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_TextOut (MS_S32 fhandle, MS_U8 * pindex, MS_U32 strwidth, GFX_TextOutInfo * pfmt)
{
    return GFX_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsStartSync(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsStartSync () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsStartSync (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_Init(void) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_Init () ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_Init (void)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: void msAPI_CI_ReInitial(void) */
EXTERN_C_LINKAGE void msAPI_CI_ReInitial () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_ReInitial (void)
{
}

/** User stub definition for function: MS_U32 MsOS_Timer_DiffTimeFromNow(MS_U32) */
EXTERN_C_LINKAGE MS_U32 MsOS_Timer_DiffTimeFromNow (MS_U32 u32TaskTimer) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_Timer_DiffTimeFromNow (MS_U32 u32TaskTimer)
{

  if(CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE_DELAY") ||
    CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE_DELAY")
    )
  {
    return 301;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_DELAY"))
  {
    return HDMI_HPD_DELAY+1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_DiffTimeFromNow"))
  {
    return 2013UL;
  }
  else
    return 0UL;
}

/** User stub definition for function: void mapi_mhl_init(MS_U8 *, MS_U8 *) */
EXTERN_C_LINKAGE void mapi_mhl_init (MS_U8 * edid, MS_U8 * DevCap) ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_init (MS_U8 * edid, MS_U8 * DevCap)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_Is_ChangeTOSameService(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Is_ChangeTOSameService () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Is_ChangeTOSameService (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_SI_IsSdtOtherCome(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_IsSdtOtherCome () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_IsSdtOtherCome (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Set_TranspColorStretchMode(EN_GOP_STRCH_TRANSPCOLORMODE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Set_TranspColorStretchMode (EN_GOP_STRCH_TRANSPCOLORMODE TColorStrchMode) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Set_TranspColorStretchMode (EN_GOP_STRCH_TRANSPCOLORMODE TColorStrchMode)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void msAPI_CI_SetCIMessageType(E_CIMSG_TYPE) */
EXTERN_C_LINKAGE void msAPI_CI_SetCIMessageType (E_CIMSG_TYPE u8Type) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_SetCIMessageType (E_CIMSG_TYPE u8Type)
{
}

/** User stub definition for function: void msAPI_CI_MMIEnterMenu(void) */
EXTERN_C_LINKAGE void msAPI_CI_MMIEnterMenu () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_MMIEnterMenu (void)
{
}

/** User stub definition for function: MS_U32 MApi_VDEC_GetFrameCnt(void) */
EXTERN_C_LINKAGE MS_U32 MApi_VDEC_GetFrameCnt () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_VDEC_GetFrameCnt (void)
{
    return 0UL;
}

/** User stub definition for function: void msAPI_Subtitle_DeInit(void) */
EXTERN_C_LINKAGE void msAPI_Subtitle_DeInit () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_DeInit (void)
{
}

/** User stub definition for function: void MDrv_USB_Init(U32) */
EXTERN_C_LINKAGE void MDrv_USB_Init (U32 _MT_var419) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_USB_Init (U32 _MT_var230)
{
}

/** User stub definition for function: XC_PCMONITOR_STATUS MApi_XC_PCMonitor(INPUT_SOURCE_TYPE_t, SCALER_WIN) */
EXTERN_C_LINKAGE XC_PCMONITOR_STATUS MApi_XC_PCMonitor (INPUT_SOURCE_TYPE_t src, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE XC_PCMONITOR_STATUS CppTest_Stub_MApi_XC_PCMonitor (INPUT_SOURCE_TYPE_t src, SCALER_WIN eWindow)
{
    return E_XC_PCMONITOR_STABLE_NOSYNC;
}

/** User stub definition for function: XC_MODEPARSE_RESULT MApi_XC_ModeParse_MatchModeEx(MS_PCADC_MODETABLE_TYPE_EX *, MS_U8, XC_MODEPARSE_INPUT_INFO *) */
EXTERN_C_LINKAGE XC_MODEPARSE_RESULT MApi_XC_ModeParse_MatchModeEx (MS_PCADC_MODETABLE_TYPE_EX * ModeDB, MS_U8 u16NumberOfItems, XC_MODEPARSE_INPUT_INFO * psInputInfo) ;
EXTERN_C_LINKAGE XC_MODEPARSE_RESULT CppTest_Stub_MApi_XC_ModeParse_MatchModeEx (MS_PCADC_MODETABLE_TYPE_EX * ModeDB, MS_U8 u16NumberOfItems, XC_MODEPARSE_INPUT_INFO * psInputInfo)
{
    return XC_MODEPARSE_NOT_PARSED;
}

/** User stub definition for function: MS_U16 MDrv_VBI_TTX_PacketBufferGetNoOfOverflows(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_VBI_TTX_PacketBufferGetNoOfOverflows () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_VBI_TTX_PacketBufferGetNoOfOverflows (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApp_Dmx_PES_Monitor(U16, void *, BOOLEAN) */
EXTERN_C_LINKAGE void MApp_Dmx_PES_Monitor (U16 u16PID, void * pfNotify, BOOLEAN bFileIn) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_PES_Monitor (U16 u16PID, void * pfNotify, BOOLEAN bFileIn)
{
}

/** User stub definition for function: void MApi_XC_DLC_CGC_CheckCGainInPQCom(void) */
EXTERN_C_LINKAGE void MApi_XC_DLC_CGC_CheckCGainInPQCom () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_CGC_CheckCGainInPQCom (void)
{
}

/** User stub definition for function: void MApp_Dmx_Enable_NIT_Other(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_Dmx_Enable_NIT_Other (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_Enable_NIT_Other (BOOLEAN bEnable)
{
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetCommAudioInfo(Audio_COMM_infoType, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetCommAudioInfo (Audio_COMM_infoType infoType, MS_U32 param1, MS_U32 param2) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetCommAudioInfo (Audio_COMM_infoType infoType, MS_U32 param1, MS_U32 param2)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SetBufferProcess(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetBufferProcess (MS_U8 DelayTime) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetBufferProcess (MS_U8 DelayTime)
{
    return;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_EnableTransClr(EN_GOP_TRANSCLR_FMT, MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_EnableTransClr (EN_GOP_TRANSCLR_FMT fmt, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_EnableTransClr (EN_GOP_TRANSCLR_FMT fmt, MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Init(VDEC_InitParam *) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Init (VDEC_InitParam * pInitParam) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Init (VDEC_InitParam * pInitParam)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SetSourceInfo(AUDIO_SOURCE_INFO_TYPE) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSourceInfo (AUDIO_SOURCE_INFO_TYPE eSourceType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSourceInfo (AUDIO_SOURCE_INFO_TYPE eSourceType)
{
}

/** User stub definition for function: AVD_VideoFreq MDrv_AVD_GetVerticalFreq(void) */
EXTERN_C_LINKAGE AVD_VideoFreq MDrv_AVD_GetVerticalFreq () ;
EXTERN_C_LINKAGE AVD_VideoFreq CppTest_Stub_MDrv_AVD_GetVerticalFreq (void)
{
    return E_VIDEO_FQ_NOSIGNAL;
}

/** User stub definition for function: MS_BOOL MsOS_AttachInterrupt(InterruptNum, InterruptCb) */
EXTERN_C_LINKAGE MS_BOOL MsOS_AttachInterrupt (InterruptNum eIntNum, InterruptCb pIntCb) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_AttachInterrupt (InterruptNum eIntNum, InterruptCb pIntCb)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_PM_RTCSetMatchTime(MS_U32) */
BOOL btest_msAPI_Timer_SetRTCWakeUpTime = FALSE;
EXTERN_C_LINKAGE void MDrv_PM_RTCSetMatchTime (MS_U32 u32PmSysTime) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PM_RTCSetMatchTime (MS_U32 u32PmSysTime)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetRTCWakeUpTime"))
	{
		btest_msAPI_Timer_SetRTCWakeUpTime = TRUE;
	}

}

/** User stub definition for function: MS_U8 MApi_XC_ReadByte(MS_U32) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ReadByte (MS_U32 u32Reg) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ReadByte (MS_U32 u32Reg)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_VBI_Init(VBI_INIT_TYPE) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_Init (VBI_INIT_TYPE type) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_Init (VBI_INIT_TYPE type)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U32 MDrv_COPRO_GetBase(void) */
EXTERN_C_LINKAGE MS_U32 MDrv_COPRO_GetBase () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_COPRO_GetBase (void)
{
    return 0UL;
}

/** User stub definition for function: void MApi_XC_EnableForceRGBin(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_EnableForceRGBin (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableForceRGBin (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_HSS_Get(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HSS_Get () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HSS_Get (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_PicSetPostColorTemp2Ex(MS_BOOL, MS_BOOL, XC_ACE_color_temp_ex *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PicSetPostColorTemp2Ex (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, XC_ACE_color_temp_ex * pstColorTemp) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PicSetPostColorTemp2Ex (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, XC_ACE_color_temp_ex * pstColorTemp)
{
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_IsMadLock(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_IsMadLock () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_IsMadLock (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_AudioCmdHandler_case_IS_DTV_DECODE_OK_OK")
  || CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1")
  || CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetSystem(En_DVB_decSystemType) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetSystem (En_DVB_decSystemType enDecSystem) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetSystem (En_DVB_decSystemType enDecSystem)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_CEC_SetActiveDeviceType(MsCEC_DEVICE_TYPE) */
EXTERN_C_LINKAGE void MApi_CEC_SetActiveDeviceType (MsCEC_DEVICE_TYPE Type) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetActiveDeviceType (MsCEC_DEVICE_TYPE Type)
{
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetSNR(float *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetSNR (float * fSNR) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetSNR (float * fSNR)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL mapi_mhl_SendMSGCmdFlag(void) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_SendMSGCmdFlag () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_SendMSGCmdFlag (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_W2BYTEMSK(MS_U32, MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_W2BYTEMSK (MS_U32 u32Reg, MS_U16 u16Val, MS_U16 u16Mask) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_W2BYTEMSK (MS_U32 u32Reg, MS_U16 u16Val, MS_U16 u16Mask)
{
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_Exit(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_Exit () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_Exit (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_DNR_Init_Luma(void) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DNR_Init_Luma () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DNR_Init_Luma (void)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetAlpha(MS_BOOL, GFX_BlendCoef, GFX_AlphaSrcFrom, MS_U8) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetAlpha (MS_BOOL enable, GFX_BlendCoef coef, GFX_AlphaSrcFrom db_abl, MS_U8 abl_const) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetAlpha (MS_BOOL enable, GFX_BlendCoef coef, GFX_AlphaSrcFrom db_abl, MS_U8 abl_const)
{
    return GFX_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_GetPlaybackStamp(MS_U32 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_GetPlaybackStamp (MS_U32 * pu32Stamp) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_GetPlaybackStamp (MS_U32 * pu32Stamp)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MsOS_ReadMemory(void) */
EXTERN_C_LINKAGE void MsOS_ReadMemory () ;
EXTERN_C_LINKAGE void CppTest_Stub_MsOS_ReadMemory (void)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_CC_LoadKeyFromFlash(MS_CI_KEY_SETTING *, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CC_LoadKeyFromFlash (MS_CI_KEY_SETTING * pstCiKeySetting, BOOLEAN bEnableEncrypt) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CC_LoadKeyFromFlash (MS_CI_KEY_SETTING * pstCiKeySetting, BOOLEAN bEnableEncrypt)
{
    return (unsigned char)0;
}

/** User stub definition for function: MBX_Result MDrv_MBX_SetInformation(MBX_ROLE_ID, MS_U8 *, MS_U8) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_SetInformation (MBX_ROLE_ID eTargetRole, MS_U8 * pU8Info, MS_U8 u8Size) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_SetInformation (MBX_ROLE_ID eTargetRole, MS_U8 * pU8Info, MS_U8 u8Size)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MApi_XC_DLC_CGC_Handler(void) */
EXTERN_C_LINKAGE void MApi_XC_DLC_CGC_Handler () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_CGC_Handler (void)
{
}

/** User stub definition for function: U32 msAPI_Subtitle_SetPTS(U8 *, U32) */
EXTERN_C_LINKAGE U32 msAPI_Subtitle_SetPTS (U8 * pu8bff, U32 u32STC) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Subtitle_SetPTS (U8 * pu8bff, U32 u32STC)
{
    return 0UL;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_GetEXIFOrientation(JPEG_EXIF_Orientation *) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_GetEXIFOrientation (JPEG_EXIF_Orientation * eOrientation) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_GetEXIFOrientation (JPEG_EXIF_Orientation * eOrientation)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_SetDataFmt(EN_GOP_DWIN_DATA_FMT) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_SetDataFmt (EN_GOP_DWIN_DATA_FMT fmt) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_SetDataFmt (EN_GOP_DWIN_DATA_FMT fmt)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_JPEG_SetJPDEventFlag(JPEG_Event) */
EXTERN_C_LINKAGE void MApi_JPEG_SetJPDEventFlag (JPEG_Event eEvtVal) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetJPDEventFlag (JPEG_Event eEvtVal)
{
}

/** User stub definition for function: void MApi_SWI2C_UseBus(MS_U8) */
EXTERN_C_LINKAGE void MApi_SWI2C_UseBus (MS_U8 u8BusChn) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_SWI2C_UseBus (MS_U8 u8BusChn)
{
}

/** User stub definition for function: void MApi_XC_W2BYTE(MS_U32, MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_W2BYTE (MS_U32 u32Reg, MS_U16 u16Val) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_W2BYTE (MS_U32 u32Reg, MS_U16 u16Val)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_EnableIntr(MS_U16, MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_EnableIntr (MS_U16 u8mask, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_EnableIntr (MS_U16 u8mask, MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MDrv_AUDIO_TriggerSifPLL(void) */
EXTERN_C_LINKAGE void MDrv_AUDIO_TriggerSifPLL () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_TriggerSifPLL (void)
{
}

/** User stub definition for function: U8 * MApp_SI_FindLoopHead(U8 *, EN_PSIP_TABLE, EN_LOOP_TYPE) */
EXTERN_C_LINKAGE U8 * MApp_SI_FindLoopHead (U8 * pu8Section, EN_PSIP_TABLE enTable, EN_LOOP_TYPE enType) ;
EXTERN_C_LINKAGE U8 * CppTest_Stub_MApp_SI_FindLoopHead (U8 * pu8Section, EN_PSIP_TABLE enTable, EN_LOOP_TYPE enType)
{
    return pu8Section;
}

/** User stub definition for function: MS_HDMI_AR_TYPE MDrv_HDMI_Get_AspectRatio(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE MS_HDMI_AR_TYPE MDrv_HDMI_Get_AspectRatio (MS_BOOL bEn_PAR, MS_BOOL bEn_AFAR) ;
EXTERN_C_LINKAGE MS_HDMI_AR_TYPE CppTest_Stub_MDrv_HDMI_Get_AspectRatio (MS_BOOL bEn_PAR, MS_BOOL bEn_AFAR)
{
    return HDMI_AF_AR_Reserve_0;
}

/** User stub definition for function: PM_Result MDrv_PM_Check_Version(MS_BOOL) */
EXTERN_C_LINKAGE PM_Result MDrv_PM_Check_Version (MS_BOOL bCheck) ;
EXTERN_C_LINKAGE PM_Result CppTest_Stub_MDrv_PM_Check_Version (MS_BOOL bCheck)
{
    return E_PM_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetReg(MS_U16, MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetReg (MS_U16 u16Addr, MS_U8 * pu8Data) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetReg (MS_U16 u16Addr, MS_U8 * pu8Data)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_EIT_Init(MS_EIT_INIT_PARAMETER *) */
EXTERN_C_LINKAGE void MApp_EIT_Init (MS_EIT_INIT_PARAMETER * psInitParameter) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_EIT_Init (MS_EIT_INIT_PARAMETER * psInitParameter)
{
}

/** User stub definition for function: void MDrv_VE_SetWSSData(MS_BOOL, MS_U16) */
EXTERN_C_LINKAGE void MDrv_VE_SetWSSData (MS_BOOL bEn, MS_U16 u16WSSData) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SetWSSData (MS_BOOL bEn, MS_U16 u16WSSData)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_RegisterXCGetCapHStartCB(MS_U16 (*)(void)) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_RegisterXCGetCapHStartCB (MS_U16 (* fpGOP_CB)(void)) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_RegisterXCGetCapHStartCB (MS_U16 (* fpGOP_CB)(void))
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MDrv_AUDIO_InitMMIO(void) */
EXTERN_C_LINKAGE void MDrv_AUDIO_InitMMIO () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_InitMMIO (void)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetPatchMode(MS_BOOL) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetPatchMode (MS_BOOL enable) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetPatchMode (MS_BOOL enable)
{
    return GFX_FAIL;
}

/** User stub definition for function: void MApi_PNL_TCON_Count_Reset(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_PNL_TCON_Count_Reset (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_PNL_TCON_Count_Reset (MS_BOOL bEnable)
{
}

/** User stub definition for function: U8 msAPI_CI_CC_GetCicamRating(void) */
EXTERN_C_LINKAGE U8 msAPI_CI_CC_GetCicamRating () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_CI_CC_GetCicamRating (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MBX_Result MDrv_MBX_Enable(MS_BOOL) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_Enable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_Enable (MS_BOOL bEnable)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: BOOLEAN MApp_EIT_IsCurPFInfoExist(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_EIT_IsCurPFInfoExist () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_EIT_IsCurPFInfoExist (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U32 MDrv_GetUsbBlockNum(U8) */
EXTERN_C_LINKAGE U32 MDrv_GetUsbBlockNum (U8 lun) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MDrv_GetUsbBlockNum (U8 lun)
{
    return 0UL;
}

/** User stub definition for function: MS_U16 MApi_XC_Get_3D_VerVideoOffset(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_Get_3D_VerVideoOffset () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_Get_3D_VerVideoOffset (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApi_XC_ACE_GetColorMatrix(MS_BOOL, MS_U16 *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_GetColorMatrix (MS_BOOL eWindow, MS_U16 * pu16Matrix) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_GetColorMatrix (MS_BOOL eWindow, MS_U16 * pu16Matrix)
{
}

/** User stub definition for function: MS_U16 MApi_XC_R2BYTE(MS_U32) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_R2BYTE (MS_U32 u32Reg) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_R2BYTE (MS_U32 u32Reg)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U16 MApi_XC_PCMonitor_Get_HFreqx10(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_PCMonitor_Get_HFreqx10 (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_PCMonitor_Get_HFreqx10 (SCALER_WIN eWindow)
{
    return (unsigned short)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsSeqChg(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsSeqChg () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsSeqChg (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: BOOLEAN MApp_SI_Is_Running(BOOLEAN *) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Is_Running (BOOLEAN * pu8Replacement) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Is_Running (BOOLEAN * pu8Replacement)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsTrue"))
  {
    *pu8Replacement = TRUE;
    return TRUE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsTrue"))
  {
    *pu8Replacement = TRUE;
    return FALSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1")
      ||CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_0")
      ||CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1"))
  {
    *pu8Replacement = FALSE;
    return TRUE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_IsProgramRunning_bRunning_IsFalse_bRepacement_IsFalse_enMVDVideoStatus_Not_Equal_MVD_GOOD_VIDEO_Mapi_AUDIO_IsMadLock_1"))
  {
    *pu8Replacement = FALSE;
    return FALSE;
  }
  else
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MApi_JPEG_GetAlignedWidth(void) */
EXTERN_C_LINKAGE MS_U16 MApi_JPEG_GetAlignedWidth () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_JPEG_GetAlignedWidth (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_SetBlueScreen(MS_BOOL) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_SetBlueScreen (MS_BOOL bOn) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_SetBlueScreen (MS_BOOL bOn)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: BOOLEAN MApp_Epg_IsEventAlternate(EventIndex) */
EXTERN_C_LINKAGE BOOLEAN MApp_Epg_IsEventAlternate (EventIndex event) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Epg_IsEventAlternate (EventIndex event)
{
    return (unsigned char)0;
}

/** User stub definition for function: MBX_Result MDrv_MBX_GetInformation(MBX_ROLE_ID, MS_U8 *, MS_U8) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_GetInformation (MBX_ROLE_ID eTargetRole, MS_U8 * pU8Info, MS_U8 u8Size) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_GetInformation (MBX_ROLE_ID eTargetRole, MS_U8 * pU8Info, MS_U8 u8Size)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MApi_XC_EnableSubWindow(MS_WINDOW_TYPE *) */
EXTERN_C_LINKAGE void MApi_XC_EnableSubWindow (MS_WINDOW_TYPE * pstDispWin) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableSubWindow (MS_WINDOW_TYPE * pstDispWin)
{
}

/** User stub definition for function: MS_BOOL MsOS_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MsOS_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MApi_XC_ADC_GetPhaseRange(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_ADC_GetPhaseRange () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_ADC_GetPhaseRange (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: E_APIXC_ReturnValue MApi_XC_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE E_APIXC_ReturnValue MApi_XC_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE E_APIXC_ReturnValue CppTest_Stub_MApi_XC_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_APIXC_RET_FAIL;
}

/** User stub definition for function: void UsbPort0UTMIInitial(void) */
EXTERN_C_LINKAGE void UsbPort0UTMIInitial () ;
EXTERN_C_LINKAGE void CppTest_Stub_UsbPort0UTMIInitial (void)
{
}

/** User stub definition for function: void __MDrv_Write2Byte(U32, U16) */
EXTERN_C_LINKAGE void __MDrv_Write2Byte (U32 u32Reg, U16 u16Val) ;
EXTERN_C_LINKAGE void CppTest_Stub___MDrv_Write2Byte (U32 u32Reg, U16 u16Val)
{
}

/** User stub definition for function: void msAPI_Subtitle_Renderer_Clear(void) */
EXTERN_C_LINKAGE void msAPI_Subtitle_Renderer_Clear () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_Renderer_Clear (void)
{
}

/** User stub definition for function: MS_BOOL MsOS_CPU_UnMaskInterrupt(MHAL_INTERRUPT_TYPE) */
EXTERN_C_LINKAGE MS_BOOL MsOS_CPU_UnMaskInterrupt (MHAL_INTERRUPT_TYPE intr_num) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_CPU_UnMaskInterrupt (MHAL_INTERRUPT_TYPE intr_num)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_IsCurrentFrameBufferLessMode(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsCurrentFrameBufferLessMode () ;
MS_BOOL g_XC_bIsFBL = 0;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsCurrentFrameBufferLessMode (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_ForceOff"))
	{
		return (unsigned char)g_XC_bIsFBL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MAPP_VDPlayer_SetPIPDisplayWindow_MApi_XC_IsCurrentFrameBufferLessMode_return_TRUE"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_Mux_TriggerPathSyncEvent(INPUT_SOURCE_TYPE_t, void *) */
EXTERN_C_LINKAGE void MApi_XC_Mux_TriggerPathSyncEvent (INPUT_SOURCE_TYPE_t src, void * para) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Mux_TriggerPathSyncEvent (INPUT_SOURCE_TYPE_t src, void * para)
{
}

/** User stub definition for function: MS_U32 MDrv_BDMA_Search(MS_PHYADDR, MS_U32, MS_U32, MS_U32, BDMA_SrcDev) */
EXTERN_C_LINKAGE MS_U32 MDrv_BDMA_Search (MS_PHYADDR u32Addr, MS_U32 u32Len, MS_U32 u32Pattern, MS_U32 u32ExcluBit, BDMA_SrcDev eDev) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_BDMA_Search (MS_PHYADDR u32Addr, MS_U32 u32Len, MS_U32 u32Pattern, MS_U32 u32ExcluBit, BDMA_SrcDev eDev)
{
    return 0UL;
}

/** User stub definition for function: void DRV_VIF_SetClock(BOOLEAN) */
EXTERN_C_LINKAGE void DRV_VIF_SetClock (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_SetClock (BOOLEAN bEnable)
{
}

/** User stub definition for function: void __assert(const char *, int, const char *) */
EXTERN_C_LINKAGE void __assert (const char * file, int line, const char * expr) ;
EXTERN_C_LINKAGE void CppTest_Stub___assert (const char * file, int line, const char * expr)
{
}

/** User stub definition for function: MS_U8 MApi_XC_DLC_GetAverageValue(void) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_DLC_GetAverageValue () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_DLC_GetAverageValue (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_SI_RemoveMismatchedMux(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_RemoveMismatchedMux () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_RemoveMismatchedMux (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Set_STRETCHWIN(MS_U8, EN_GOP_DST_TYPE, MS_U16, MS_U16, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Set_STRETCHWIN (MS_U8 u8GOP_num, EN_GOP_DST_TYPE eDstType, MS_U16 x, MS_U16 y, MS_U16 width, MS_U16 height) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Set_STRETCHWIN (MS_U8 u8GOP_num, EN_GOP_DST_TYPE eDstType, MS_U16 x, MS_U16 y, MS_U16 width, MS_U16 height)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MBX_Result MDrv_MBX_DeInit(MS_BOOL) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_DeInit (MS_BOOL bForceDiscardPendingMsg) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_DeInit (MS_BOOL bForceDiscardPendingMsg)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_PVR_SetPacketMode(MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_PVR_SetPacketMode (MS_BOOL bSet) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_PVR_SetPacketMode (MS_BOOL bSet)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MsOS_CPU_AttachInterrupt(MHAL_INTERRUPT_TYPE, mhal_isr_t, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MsOS_CPU_AttachInterrupt (MHAL_INTERRUPT_TYPE intr_num, mhal_isr_t isr, MS_U32 dat) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_CPU_AttachInterrupt (MHAL_INTERRUPT_TYPE intr_num, mhal_isr_t isr, MS_U32 dat)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SetSystemInfo(AUDIO_INIT_INFO *) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSystemInfo (AUDIO_INIT_INFO * pau_info) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSystemInfo (AUDIO_INIT_INFO * pau_info)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_Is_Save_Audio(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Is_Save_Audio () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Is_Save_Audio (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_PWM_Dben(PWM_ChNum, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_PWM_Dben (PWM_ChNum u8IndexPWM, MS_BOOL bDbenPWM) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PWM_Dben (PWM_ChNum u8IndexPWM, MS_BOOL bDbenPWM)
{
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SIF_SetSoundMode(MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SIF_SetSoundMode (MS_U8 u8SifSoundMode) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SIF_SetSoundMode (MS_U8 u8SifSoundMode)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Filein_CMDQ_Reset(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Filein_CMDQ_Reset () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Filein_CMDQ_Reset (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_CaptureOneFrame(void) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_CaptureOneFrame () ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_CaptureOneFrame (void)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetPaletteRead(EN_GOP_PALETTE_READTYPE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetPaletteRead (EN_GOP_PALETTE_READTYPE type) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetPaletteRead (EN_GOP_PALETTE_READTYPE type)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_Set_3D_HW2DTo3D_Parameters(MS_XC_3D_HW2DTO3D_PARA) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Set_3D_HW2DTo3D_Parameters (MS_XC_3D_HW2DTO3D_PARA st3DHw2DTo3DPara) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Set_3D_HW2DTo3D_Parameters (MS_XC_3D_HW2DTO3D_PARA st3DHw2DTo3DPara)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetFieldInver(MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetFieldInver (MS_BOOL enable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetFieldInver (MS_BOOL enable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_DestroyWin(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_DestroyWin (MS_U8 gId) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_DestroyWin (MS_U8 gId)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_JPEG_SetMPOProMaxDecodeResolution(MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_JPEG_SetMPOProMaxDecodeResolution (MS_U16 u16ProWidth, MS_U16 u16ProHeight) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetMPOProMaxDecodeResolution (MS_U16 u16ProWidth, MS_U16 u16ProHeight)
{
}

/** User stub definition for function: BOOLEAN MApp_Epg_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE BOOLEAN MApp_Epg_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Epg_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_Epg_IsEventSeries(EventIndex) */
EXTERN_C_LINKAGE BOOLEAN MApp_Epg_IsEventSeries (EventIndex event) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Epg_IsEventSeries (EventIndex event)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_EnableBorder(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_EnableBorder (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableBorder (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: BOOLEAN MDrv_UsbBlockReadToMIU(U8, U32, U32, U32) */
EXTERN_C_LINKAGE BOOLEAN MDrv_UsbBlockReadToMIU (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_UsbBlockReadToMIU (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_BD_LVDS_Output_Type(MS_U16) */
EXTERN_C_LINKAGE void MApi_BD_LVDS_Output_Type (MS_U16 Type) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_BD_LVDS_Output_Type (MS_U16 Type)
{
}

/** User stub definition for function: void MApi_GFX_RectFrame(GFX_RectFillInfo *, GFX_DrawLineInfo *) */
EXTERN_C_LINKAGE void MApi_GFX_RectFrame (GFX_RectFillInfo * pblock, GFX_DrawLineInfo * plinefmt) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_GFX_RectFrame (GFX_RectFillInfo * pblock, GFX_DrawLineInfo * plinefmt)
{
}

/** User stub definition for function: void msAPI_OAD_SetOui(U8, U8, U8) */
EXTERN_C_LINKAGE void msAPI_OAD_SetOui (U8 byte1, U8 byte2, U8 byte3) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_OAD_SetOui (U8 byte1, U8 byte2, U8 byte3)
{
}

/** User stub definition for function: MS_U8 DRV_VIF_Read_CR_FOE(void) */
EXTERN_C_LINKAGE MS_U8 DRV_VIF_Read_CR_FOE () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_DRV_VIF_Read_CR_FOE (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_MVOP_GetIsHDuplicate(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MVOP_GetIsHDuplicate () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MVOP_GetIsHDuplicate (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 msAPI_CI_Polling(void) */
EXTERN_C_LINKAGE U8 msAPI_CI_Polling () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_CI_Polling (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_SetFreezeDisp(MS_BOOL) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_SetFreezeDisp (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_SetFreezeDisp (MS_BOOL bEnable)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MDrv_AUDIO_SetPlayFileFlag(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_AUDIO_SetPlayFileFlag (MS_BOOL bDspType, MS_BOOL bSet) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_SetPlayFileFlag (MS_BOOL bDspType, MS_BOOL bSet)
{
}

/** User stub definition for function: void MApi_XC_MLoad_Init(MS_PHYADDR, MS_U32) */
EXTERN_C_LINKAGE void MApi_XC_MLoad_Init (MS_PHYADDR PhyAddr, MS_U32 u32BufByteLen) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_MLoad_Init (MS_PHYADDR PhyAddr, MS_U32 u32BufByteLen)
{
}

/** User stub definition for function: void msAPI_CI_MAINLOOP(void) */
EXTERN_C_LINKAGE void msAPI_CI_MAINLOOP () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_MAINLOOP (void)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_IsTSChanged(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_IsTSChanged () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_IsTSChanged (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_CNI_SetCountryLangId(unsigned char, unsigned char) */
EXTERN_C_LINKAGE void msAPI_CNI_SetCountryLangId (unsigned char ucCountryId, unsigned char ucLanguageId) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CNI_SetCountryLangId (unsigned char ucCountryId, unsigned char ucLanguageId)
{
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_ReqActiveSource(void) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_ReqActiveSource () ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_ReqActiveSource (void)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: void MApp_SI_Force_PMT_Parse(void) */
EXTERN_C_LINKAGE void MApp_SI_Force_PMT_Parse () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Force_PMT_Parse (void)
{
}

/** User stub definition for function: void MApi_XC_ACE_PicSetSharpness(MS_BOOL, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PicSetSharpness (MS_BOOL eWindow, MS_U8 u8Sharpness) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PicSetSharpness (MS_BOOL eWindow, MS_U8 u8Sharpness)
{
}

/** User stub definition for function: BOOLEAN MDrv_UsbDeviceConnect_Port2(void) */
EXTERN_C_LINKAGE BOOLEAN MDrv_UsbDeviceConnect_Port2 () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_UsbDeviceConnect_Port2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_PQ_LoadFunction(PQ_Function_Info *, MS_U32) */
MS_U8 g_CppTest_Stub_MApi_XC_PQ_LoadFunction_u8Result = 0;
EXTERN_C_LINKAGE void MApi_XC_PQ_LoadFunction (PQ_Function_Info * function_Info, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_PQ_LoadFunction (PQ_Function_Info * function_Info, MS_U32 u32InitDataLen)
{
	if(CppTest_IsCurrentTestCase("TestSuite_apiXC_Sys_test__MApi_XC_Sys_Init_PQ_call_MApi_XC_PQ_LoadFunction"))
	{
		g_CppTest_Stub_MApi_XC_PQ_LoadFunction_u8Result = 0;

	    if( function_Info->pq_deside_srctype == NULL )
	    	return;

	    if( function_Info->pq_disable_filmmode == NULL )
	    	return;

	    if( function_Info->pq_load_scalingtable == NULL )
	    	return;

	    if( function_Info->pq_set_420upsampling == NULL )
	    	return;

	    if( function_Info->pq_set_csc == NULL )
	    	return;

	    if( function_Info->pq_set_memformat == NULL )
	    	return;

	    if( function_Info->pq_set_modeInfo == NULL )
	    	return;

	    if( function_Info->pq_get_memyuvfmt == NULL )
	    	return;

	    if( function_Info->pq_ioctl == NULL )
	    	return;

	    g_CppTest_Stub_MApi_XC_PQ_LoadFunction_u8Result = 1;
		return ;
	}

	return ;
}

/** User stub definition for function: EN_SI_DELIVERY_SYS_TYPE MApp_SI_GetDeliveryTypeFromNIT(U8 *, U16) */
EXTERN_C_LINKAGE EN_SI_DELIVERY_SYS_TYPE MApp_SI_GetDeliveryTypeFromNIT (U8 * pu8SectionData, U16 u16SecCount) ;
EXTERN_C_LINKAGE EN_SI_DELIVERY_SYS_TYPE CppTest_Stub_MApp_SI_GetDeliveryTypeFromNIT (U8 * pu8SectionData, U16 u16SecCount)
{
    return E_SI_DELIVERY_SYS_NONE;
}

/** User stub definition for function: void MDrv_AUDIO_SetNormalPath(AUDIO_PATH_TYPE, AUDIO_INPUT_TYPE, AUDIO_OUTPUT_TYPE) */
EXTERN_C_LINKAGE void MDrv_AUDIO_SetNormalPath (AUDIO_PATH_TYPE u8Path, AUDIO_INPUT_TYPE u8Input, AUDIO_OUTPUT_TYPE output) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_SetNormalPath (AUDIO_PATH_TYPE u8Path, AUDIO_INPUT_TYPE u8Input, AUDIO_OUTPUT_TYPE output)
{
}

/** User stub definition for function: MS_BOOL MDrv_MMIO_GetBASE(MS_U32 *, MS_U32 *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MMIO_GetBASE (MS_U32 * u32Baseaddr, MS_U32 * u32Basesize, MS_U32 u32Module) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MMIO_GetBASE (MS_U32 * u32Baseaddr, MS_U32 * u32Basesize, MS_U32 u32Module)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MsOS_CPU_MaskAllInterrupt(void) */
EXTERN_C_LINKAGE MS_BOOL MsOS_CPU_MaskAllInterrupt () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_CPU_MaskAllInterrupt (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_XC_3D_OUTPUT_MODE MApi_XC_Get_3D_Output_Mode(void) */
EXTERN_C_LINKAGE E_XC_3D_OUTPUT_MODE MApi_XC_Get_3D_Output_Mode () ;
EXTERN_C_LINKAGE E_XC_3D_OUTPUT_MODE CppTest_Stub_MApi_XC_Get_3D_Output_Mode (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test_MApp_Scaler_SetVideo3DMode_3D_HW_Version_1") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test_MApp_Scaler_SetVideo3DMode_3D_HW_Version_2")
		)
	{
		return E_XC_3D_OUTPUT_LINE_ALTERNATIVE;
	}
	else
	{
		return E_XC_3D_OUTPUT_MODE_NONE;
	}
}

/** User stub definition for function: void MApi_AUDIO_SetADAbsoluteVolume(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetADAbsoluteVolume (MS_U8 AbsVolume) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetADAbsoluteVolume (MS_U8 AbsVolume)
{
}

/** User stub definition for function: MS_BOOL MApi_PNL_GetDstInfo(MS_PNL_DST_DispInfo *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_PNL_GetDstInfo (MS_PNL_DST_DispInfo * pDstInfo, MS_U32 u32SizeofDstInfo) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_PNL_GetDstInfo (MS_PNL_DST_DispInfo * pDstInfo, MS_U32 u32SizeofDstInfo)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_SetDispWindowColor(MS_U8, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetDispWindowColor (MS_U8 u8Color, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetDispWindowColor (MS_U8 u8Color, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_IsYUVSpace(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsYUVSpace (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsYUVSpace (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_Is_SubWindowEanble(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Is_SubWindowEanble () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Is_SubWindowEanble (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_TTX_WriteGet(MS_U8, MS_PHYADDR *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_TTX_WriteGet (MS_U8 u8DmxId, MS_PHYADDR * pWrite) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_TTX_WriteGet (MS_U8 u8DmxId, MS_PHYADDR * pWrite)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MirrorMode_t MApi_XC_GetMirrorModeType(void) */
EXTERN_C_LINKAGE MirrorMode_t MApi_XC_GetMirrorModeType () ;
EXTERN_C_LINKAGE MirrorMode_t CppTest_Stub_MApi_XC_GetMirrorModeType (void)
{
    return MIRROR_NORMAL;
}

/** User stub definition for function: void MDrv_SERFLASH_Init(void) */
EXTERN_C_LINKAGE void MDrv_SERFLASH_Init () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_SERFLASH_Init (void)
{
}

/** User stub definition for function: EN_HDMI_COLOR_RANGE MDrv_HDMI_Get_ColorRange(void) */
EXTERN_C_LINKAGE EN_HDMI_COLOR_RANGE MDrv_HDMI_Get_ColorRange () ;
EXTERN_C_LINKAGE EN_HDMI_COLOR_RANGE CppTest_Stub_MDrv_HDMI_Get_ColorRange (void)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange") )
	{
		return E_HDMI_COLOR_RANGE_LIMIT;
	}
    return E_HDMI_COLOR_RANGE_DEFAULT;
}

/** User stub definition for function: void MApi_AUDIO_SetPathInfo(AUDIO_PATH_INFO *) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetPathInfo (AUDIO_PATH_INFO * path_info) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetPathInfo (AUDIO_PATH_INFO * path_info)
{
}

/** User stub definition for function: double floor(double) */
EXTERN_C_LINKAGE double floor (double __x) ;
EXTERN_C_LINKAGE double CppTest_Stub_floor (double __x)
{
    return 0.0;
}

/** User stub definition for function: EN_CI_APP_TYPE msAPI_CI_GetAppType(void) */
EXTERN_C_LINKAGE EN_CI_APP_TYPE msAPI_CI_GetAppType () ;
EXTERN_C_LINKAGE EN_CI_APP_TYPE CppTest_Stub_msAPI_CI_GetAppType (void)
{
    return EN_CI_APP_TYPE_CA;
}

/** User stub definition for function: void msAPI_CI_NotifyCurrentServiceInfo(U16, U16) */
EXTERN_C_LINKAGE void msAPI_CI_NotifyCurrentServiceInfo (U16 u16CurrentTS_ID, U16 u16CurrentServiceID) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_NotifyCurrentServiceInfo (U16 u16CurrentTS_ID, U16 u16CurrentServiceID)
{
}

/** User stub definition for function: JPEG_Result MApi_JPEG_GetEXIFDateTime(JPEG_EXIF_DateTime *) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_GetEXIFDateTime (JPEG_EXIF_DateTime * DateTime) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_GetEXIFDateTime (JPEG_EXIF_DateTime * DateTime)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: BOOLEAN MApp_Dmx_GetOADScanMode(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_Dmx_GetOADScanMode () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Dmx_GetOADScanMode (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_Decode(void) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_Decode () ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_Decode (void)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_Init(GOP_InitInfo *) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_Init (GOP_InitInfo * pGopInit) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_Init (GOP_InitInfo * pGopInit)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetLock(DMD_DVBT_GETLOCK_TYPE, DMD_LOCK_STATUS *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetLock (DMD_DVBT_GETLOCK_TYPE eType, DMD_LOCK_STATUS * eLockStatus) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetLock (DMD_DVBT_GETLOCK_TYPE eType, DMD_LOCK_STATUS * eLockStatus)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Dmx_PES_Restart(void) */
EXTERN_C_LINKAGE void MApp_Dmx_PES_Restart () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_PES_Restart (void)
{
}

/** User stub definition for function: CEC_ERROR_CODE MsAPI_CEC_Msg_RecordOn(MsCEC_DEVICELA, MsCEC_MSG_RECORD_SOURCE_TYPE) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MsAPI_CEC_Msg_RecordOn (MsCEC_DEVICELA dst_address, MsCEC_MSG_RECORD_SOURCE_TYPE cmd) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MsAPI_CEC_Msg_RecordOn (MsCEC_DEVICELA dst_address, MsCEC_MSG_RECORD_SOURCE_TYPE cmd)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_WriteGet(MS_U32 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_WriteGet (MS_U32 * pu32Write) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_WriteGet (MS_U32 * pu32Write)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_ClearIntr(MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_ClearIntr (MS_U16 u8mask) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_ClearIntr (MS_U16 u8mask)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Set_HStretchMode(EN_GOP_STRETCH_HMODE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Set_HStretchMode (EN_GOP_STRETCH_HMODE HStrchMode) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Set_HStretchMode (EN_GOP_STRETCH_HMODE HStrchMode)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SetEq(MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetEq (MS_U8 u8band, MS_U8 u8level) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetEq (MS_U8 u8band, MS_U8 u8level)
{
}

/** User stub definition for function: MS_BOOL MApi_SWI2C_SendByte(MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_SWI2C_SendByte (MS_U8 u8date) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SWI2C_SendByte (MS_U8 u8date)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_Subtitle_SetFreeRunTime(U8) */
EXTERN_C_LINKAGE void msAPI_Subtitle_SetFreeRunTime (U8 u8FreeRunTime) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_SetFreeRunTime (U8 u8FreeRunTime)
{
}

/** User stub definition for function: AUDIO_PATH_GROUP_TYPE MDrv_AUDIO_GetPathGroup(void) */
EXTERN_C_LINKAGE AUDIO_PATH_GROUP_TYPE MDrv_AUDIO_GetPathGroup () ;
EXTERN_C_LINKAGE AUDIO_PATH_GROUP_TYPE CppTest_Stub_MDrv_AUDIO_GetPathGroup (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_DEFAULT") ||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_DTV")	||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_TV")	||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_CVBS")	||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_YPBPR")||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_HDMI")	||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_VGA")	||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_DVI")	||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_ChangeAudioSource_else_case_INPUT_SOURCE_STORAGE")
	    )
	{
		return AUDIO_PATH_GROUP_1;
	}
	else
	{
		return AUDIO_PATH_GROUP_2;
	}
}

/** User stub definition for function: MS_BOOL MApi_PNL_ChangePanelType(PanelType *) */
EXTERN_C_LINKAGE MS_BOOL MApi_PNL_ChangePanelType (PanelType * pSelPanelType) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_PNL_ChangePanelType (PanelType * pSelPanelType)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_TimeStampDisable(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_TimeStampDisable () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_TimeStampDisable (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApi_XC_PCMonitor_Get_Dvi_Hdmi_De_Info(SCALER_WIN, MS_WINDOW_TYPE *) */
EXTERN_C_LINKAGE void MApi_XC_PCMonitor_Get_Dvi_Hdmi_De_Info (SCALER_WIN eWindow, MS_WINDOW_TYPE * msWin) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_PCMonitor_Get_Dvi_Hdmi_De_Info (SCALER_WIN eWindow, MS_WINDOW_TYPE * msWin)
{
}

/** User stub definition for function: U32 msAPI_Subtitle_Queue_GetSDRAMAddress(U16) */
EXTERN_C_LINKAGE U32 msAPI_Subtitle_Queue_GetSDRAMAddress (U16 u16Len) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Subtitle_Queue_GetSDRAMAddress (U16 u16Len)
{
    return 0UL;
}

/** User stub definition for function: void msAPI_CI_NotifyServiceExit(void) */
EXTERN_C_LINKAGE void msAPI_CI_NotifyServiceExit () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_NotifyServiceExit (void)
{
}

/** User stub definition for function: void msAPI_CI_HSS_Check(void) */
EXTERN_C_LINKAGE void msAPI_CI_HSS_Check () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_HSS_Check (void)
{
}

/** User stub definition for function: void MApi_AUDIO_SIF_StartAutoStandardDetection(void) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_StartAutoStandardDetection () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_StartAutoStandardDetection (void)
{
}

/** User stub definition for function: SAR_Result MDrv_SAR_SetCallback(SAR_Callback) */
EXTERN_C_LINKAGE SAR_Result MDrv_SAR_SetCallback (SAR_Callback pCallback) ;
EXTERN_C_LINKAGE SAR_Result CppTest_Stub_MDrv_SAR_SetCallback (SAR_Callback pCallback)
{
    return E_SAR_FAIL;
}

/** User stub definition for function: void MApi_XC_set_FD_Mask(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_set_FD_Mask (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_set_FD_Mask (MS_BOOL bEnable)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_Recollect_TSRFList2Scan(U16, U16, U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Recollect_TSRFList2Scan (U16 u16NID, U16 u16ONID, U16 u16TSID) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Recollect_TSRFList2Scan (U16 u16NID, U16 u16ONID, U16 u16TSID)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_PNL_Init_Ex(PanelType *, MSIF_Version) */
EXTERN_C_LINKAGE MS_BOOL MApi_PNL_Init_Ex (PanelType * pSelPanelType, MSIF_Version LIBVER) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_PNL_Init_Ex (PanelType * pSelPanelType, MSIF_Version LIBVER)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_USB_Init_Port2(U32) */
EXTERN_C_LINKAGE void MDrv_USB_Init_Port2 (U32 _MT_var418) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_USB_Init_Port2 (U32 _MT_var234)
{
}

/** User stub definition for function: void DRV_VIF_SetFreqBand(FrequencyBand) */
EXTERN_C_LINKAGE void DRV_VIF_SetFreqBand (FrequencyBand u8FreqBand) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_SetFreqBand (FrequencyBand u8FreqBand)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_SetSourceSel(EN_GOP_DWIN_SRC_SEL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_SetSourceSel (EN_GOP_DWIN_SRC_SEL enSrcSel) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_SetSourceSel (EN_GOP_DWIN_SRC_SEL enSrcSel)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_XC_ACE_3DClonePQMap(XC_ACE_WEAVETYPE) */
EXTERN_C_LINKAGE void MApi_XC_ACE_3DClonePQMap (XC_ACE_WEAVETYPE enWeaveType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_3DClonePQMap (XC_ACE_WEAVETYPE enWeaveType)
{
}

/** User stub definition for function: MS_U8 MApi_CEC_GetFifoIdx(void) */
EXTERN_C_LINKAGE MS_U8 MApi_CEC_GetFifoIdx () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_CEC_GetFifoIdx (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_AUDIO_XPCM_Param(XPCM_TYPE, MS_U8, MS_U16, MS_U8, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_XPCM_Param (XPCM_TYPE audioType, MS_U8 channels, MS_U16 sampleRate, MS_U8 bitsPerSample, MS_U16 blockSize, MS_U16 samplePerBlock) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_XPCM_Param (XPCM_TYPE audioType, MS_U8 channels, MS_U16 sampleRate, MS_U8 bitsPerSample, MS_U16 blockSize, MS_U16 samplePerBlock)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_SetClockTimeZone(EN_SI_Clock_TimeZone) */
EXTERN_C_LINKAGE void MApp_SI_SetClockTimeZone (EN_SI_Clock_TimeZone eClock_TimeZone) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_SetClockTimeZone (EN_SI_Clock_TimeZone eClock_TimeZone)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_SetWindow(XC_SETWIN_INFO *, MS_U32, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_SetWindow (XC_SETWIN_INFO * pstXC_SetWin_Info, MS_U32 u32InitDataLen, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_SetWindow (XC_SETWIN_INFO * pstXC_SetWin_Info, MS_U32 u32InitDataLen, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_EnableEuroHdtvDetection(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_EnableEuroHdtvDetection (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableEuroHdtvDetection (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_GetIPAutoNoSignal(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_GetIPAutoNoSignal (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_GetIPAutoNoSignal (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_TSPInit(DMX_TSPParam *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_TSPInit (DMX_TSPParam * param) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_TSPInit (DMX_TSPParam * param)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApi_XC_ADC_SetPhase(MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ADC_SetPhase (MS_U8 u8Value) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_SetPhase (MS_U8 u8Value)
{
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBC_Exit(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBC_Exit () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBC_Exit (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventAlternate(EventIndex, MW_EN_EPG_CRID_SEARCH, U8 *, U16 *, EventIndex *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventAlternate (EventIndex event, MW_EN_EPG_CRID_SEARCH enSearch, U8 * pPCN, U16 * pServiceID, EventIndex * pEvent) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetEventAlternate (EventIndex event, MW_EN_EPG_CRID_SEARCH enSearch, U8 * pPCN, U16 * pServiceID, EventIndex * pEvent)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Filein_Resume(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Filein_Resume () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Filein_Resume (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MDrv_VBI_SetVideoStandard(VBI_VIDEO_STANDARD) */
EXTERN_C_LINKAGE void MDrv_VBI_SetVideoStandard (VBI_VIDEO_STANDARD eStandard) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VBI_SetVideoStandard (VBI_VIDEO_STANDARD eStandard)
{
}

/** User stub definition for function: void MApp_Dmx_PMT_FileIn_Parse(U8 *) */
EXTERN_C_LINKAGE void MApp_Dmx_PMT_FileIn_Parse (U8 * pu8Section) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_PMT_FileIn_Parse (U8 * pu8Section)
{
}

/** User stub definition for function: void MDrv_VE_SetOutputCtrl(PMS_VE_Output_Ctrl) */
EXTERN_C_LINKAGE void MDrv_VE_SetOutputCtrl (PMS_VE_Output_Ctrl pOutputCtrl) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SetOutputCtrl (PMS_VE_Output_Ctrl pOutputCtrl)
{
}

/** User stub definition for function: BOOLEAN MApp_EIT_GetCurPFInfo(MS_EIT_CUR_EVENT_PF *) */
EXTERN_C_LINKAGE BOOLEAN MApp_EIT_GetCurPFInfo (MS_EIT_CUR_EVENT_PF * pEventInfo) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_EIT_GetCurPFInfo (MS_EIT_CUR_EVENT_PF * pEventInfo)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_RegisterXCReduceBWForOSDCB(void (*)(MS_U8, MS_BOOL)) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_RegisterXCReduceBWForOSDCB (void (* fpGOP_CB)(MS_U8, MS_BOOL)) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_RegisterXCReduceBWForOSDCB (void (* fpGOP_CB)(MS_U8, MS_BOOL))
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_U16 MApi_XC_GetStatusEx(XC_ApiStatusEx *, SCALER_WIN) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_GetStatusEx (XC_ApiStatusEx * pDrvStatusEx, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_GetStatusEx (XC_ApiStatusEx * pDrvStatusEx, SCALER_WIN eWindow)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApi_XC_Set_OPWriteOffEnable(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_Set_OPWriteOffEnable (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Set_OPWriteOffEnable (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_Check_HNonLinearScaling(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Check_HNonLinearScaling () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Check_HNonLinearScaling (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MBX_Result MDrv_MBX_RegisterMSG(MBX_Class, MS_U16) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_RegisterMSG (MBX_Class eMsgClass, MS_U16 u16MsgQueueSize) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_RegisterMSG (MBX_Class eMsgClass, MS_U16 u16MsgQueueSize)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_GetWinInfo(MS_U8, GOP_GwinInfo *) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_GetWinInfo (MS_U8 u8win, GOP_GwinInfo * pinfo) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_GetWinInfo (MS_U8 u8win, GOP_GwinInfo * pinfo)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MDrv_COPRO_Disable(void) */
EXTERN_C_LINKAGE void MDrv_COPRO_Disable () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_COPRO_Disable (void)
{
}

/** User stub definition for function: void msAPI_OAD_SetVersionCheck(U8 (*)(U16, U8 *)) */
EXTERN_C_LINKAGE void msAPI_OAD_SetVersionCheck (U8 (* cb)(U16, U8 *)) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_OAD_SetVersionCheck (U8 (* cb)(U16, U8 *))
{
}

/** User stub definition for function: MS_U32 MsOS_VA2PA(MS_U32) */
EXTERN_C_LINKAGE MS_U32 MsOS_VA2PA (MS_U32 addr) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_VA2PA (MS_U32 addr)
{
    return 0UL;
}

/** User stub definition for function: PWM_Result MDrv_PWM_DutyCycle(PWM_ChNum, MS_U32) */
EXTERN_C_LINKAGE PWM_Result MDrv_PWM_DutyCycle (PWM_ChNum u8IndexPWM, MS_U32 u32DutyPWM) ;
EXTERN_C_LINKAGE PWM_Result CppTest_Stub_MDrv_PWM_DutyCycle (PWM_ChNum u8IndexPWM, MS_U32 u32DutyPWM)
{
    return E_PWM_OK;
}

/** User stub definition for function: void MApi_XC_ACE_PatchDTGColorChecker(MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PatchDTGColorChecker (MS_U8 u8Mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PatchDTGColorChecker (MS_U8 u8Mode)
{
}

/** User stub definition for function: EN_CC_CICAM_PIN_CAPABILITIES msAPI_CI_CC_GetCicamPinCapability(void) */
EXTERN_C_LINKAGE EN_CC_CICAM_PIN_CAPABILITIES msAPI_CI_CC_GetCicamPinCapability () ;
EXTERN_C_LINKAGE EN_CC_CICAM_PIN_CAPABILITIES CppTest_Stub_msAPI_CI_CC_GetCicamPinCapability (void)
{
    return EN_CC_CICAM_PIN_CAPABILITIES_NO_HANDLE;
}

/** User stub definition for function: MS_BOOL MApi_XC_Set_MemFmt(MS_XC_MEM_FMT) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Set_MemFmt (MS_XC_MEM_FMT eMemFmt) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Set_MemFmt (MS_XC_MEM_FMT eMemFmt)
{
    return (unsigned char)0;
}

/** User stub definition for function: U16 msAPI_CI_HC_GetBroadcastServiceId(void) */
EXTERN_C_LINKAGE U16 msAPI_CI_HC_GetBroadcastServiceId () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_CI_HC_GetBroadcastServiceId (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetPostViterbiBer(float *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetPostViterbiBer (float * ber) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetPostViterbiBer (float * ber)
{
    return (unsigned char)0;
}

/** User stub definition for function: void mapi_mhl_CbusIsolate(void) */
EXTERN_C_LINKAGE void mapi_mhl_CbusIsolate () ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_CbusIsolate (void)
{
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventName(EventIndex, U16 *, U16) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventName (EventIndex event, U16 * pName, U16 length) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetEventName (EventIndex event, U16 * pName, U16 length)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: void MApi_JPEG_SetMPOMaxDecodeResolution(MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_JPEG_SetMPOMaxDecodeResolution (MS_U16 u16Width, MS_U16 u16Height) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetMPOMaxDecodeResolution (MS_U16 u16Width, MS_U16 u16Height)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetHMirror(MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetHMirror (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetHMirror (MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: BOOLEAN MApp_SI_IsAutoClockValid(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_IsAutoClockValid () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_IsAutoClockValid (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void ms_DecompressDeInit(void) */
EXTERN_C_LINKAGE void ms_DecompressDeInit () ;
EXTERN_C_LINKAGE void CppTest_Stub_ms_DecompressDeInit (void)
{
}

/** User stub definition for function: MS_BOOL MDrv_AUDIO_GetPlayFileFlag(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AUDIO_GetPlayFileFlag (MS_BOOL bDspType) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AUDIO_GetPlayFileFlag (MS_BOOL bDspType)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetCellID(MS_U16 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetCellID (MS_U16 * u16CellID) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetCellID (MS_U16 * u16CellID)
{
    return (unsigned char)0;
}

/** User stub definition for function: void __MDrv_Write3Byte(U32, U32) */
EXTERN_C_LINKAGE void __MDrv_Write3Byte (U32 u32Reg, U32 u32Val) ;
EXTERN_C_LINKAGE void CppTest_Stub___MDrv_Write3Byte (U32 u32Reg, U32 u32Val)
{
}

/** User stub definition for function: void MApp_SI_Init(MS_SI_INIT_PARAMETER *) */
EXTERN_C_LINKAGE void MApp_SI_Init (MS_SI_INIT_PARAMETER * pSIParameter) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Init (MS_SI_INIT_PARAMETER * pSIParameter)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetIntensity(MS_U32, GFX_Buffer_Format, MS_U32 *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetIntensity (MS_U32 id, GFX_Buffer_Format fmt, MS_U32 * pColor) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetIntensity (MS_U32 id, GFX_Buffer_Format fmt, MS_U32 * pColor)
{
    return GFX_FAIL;
}

/** User stub definition for function: void mapi_mhl_MHLSupportPath(MS_U8) */
EXTERN_C_LINKAGE void mapi_mhl_MHLSupportPath (MS_U8 ucSelect) ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_MHLSupportPath (MS_U8 ucSelect)
{
}

/** User stub definition for function: MS_U8 MApi_XC_ACE_DNR_GetLuma_Weight(MS_U8, MS_U8, MS_U8, MS_U8, MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ACE_DNR_GetLuma_Weight (MS_U8 u8CurAvgLuma, MS_U8 u8PreAvgLuam, MS_U8 u8CurLumaLvl, MS_U8 u8PreLumaLvl, MS_U8 u8DeFlick_Th, MS_U8 u8DeFlick_Step) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ACE_DNR_GetLuma_Weight (MS_U8 u8CurAvgLuma, MS_U8 u8PreAvgLuam, MS_U8 u8CurLumaLvl, MS_U8 u8PreLumaLvl, MS_U8 u8DeFlick_Th, MS_U8 u8DeFlick_Step)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetCurrentWinId(void) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetCurrentWinId () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetCurrentWinId (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SPDIF_SetMode(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SPDIF_SetMode (MS_U8 spdif_mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SPDIF_SetMode (MS_U8 spdif_mode)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetVMirror(MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetVMirror (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetVMirror (MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: GFX_Result MApi_GFX_EndDraw(void) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_EndDraw () ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_EndDraw (void)
{
    return GFX_FAIL;
}

/** User stub definition for function: FONTHANDLE msAPI_Font_LoadFlashFontToSDRAM(U16) */
EXTERN_C_LINKAGE FONTHANDLE msAPI_Font_LoadFlashFontToSDRAM (U16 u16FontBinID) ;
EXTERN_C_LINKAGE FONTHANDLE CppTest_Stub_msAPI_Font_LoadFlashFontToSDRAM (U16 u16FontBinID)
{
    return (signed char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HC_ReplyTune (EN_HC_TUNE_REPLY_STATUS eTuneStatus) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HC_ReplyTune (EN_HC_TUNE_REPLY_STATUS eTuneStatus)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Set_VSCALE(MS_BOOL, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Set_VSCALE (MS_BOOL bEnable, MS_U16 src, MS_U16 dst) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Set_VSCALE (MS_BOOL bEnable, MS_U16 src, MS_U16 dst)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: U8 drvUSBHost_HID_Initial(void) */
EXTERN_C_LINKAGE U8 drvUSBHost_HID_Initial () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_drvUSBHost_HID_Initial (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MApp_SI_Get_New_RF_Index(void) */
EXTERN_C_LINKAGE U8 MApp_SI_Get_New_RF_Index () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_SI_Get_New_RF_Index (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_SkipOPWriteOffInSetWindow(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SkipOPWriteOffInSetWindow (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SkipOPWriteOffInSetWindow (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetForceWrite(MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetForceWrite (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetForceWrite (MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MDrv_VE_SetTtxBuffer(MS_U32, MS_U32) */
EXTERN_C_LINKAGE void MDrv_VE_SetTtxBuffer (MS_U32 u32StartAddr, MS_U32 u32Size) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SetTtxBuffer (MS_U32 u32StartAddr, MS_U32 u32Size)
{
}

/** User stub definition for function: MS_BOOL MApi_CEC_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE MS_BOOL MApi_CEC_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_CEC_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MDrv_Usb_Device_Enum(void) */
EXTERN_C_LINKAGE BOOLEAN MDrv_Usb_Device_Enum () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_Usb_Device_Enum (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventID(EventIndex, EventID *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventID (EventIndex event, EventID * pEventID) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetEventID (EventIndex event, EventID * pEventID)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendTuneStatus(U8, U8, U8, EN_OP_TUNE_STATUS, U8 *, U16) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendTuneStatus (U8 u8DescriptorNumber, U8 u8SignalStrength, U8 u8SignalQuality, EN_OP_TUNE_STATUS eStatus, U8 * pu8Descriptor, U16 u16DescriptorLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendTuneStatus (U8 u8DescriptorNumber, U8 u8SignalStrength, U8 u8SignalQuality, EN_OP_TUNE_STATUS eStatus, U8 * pu8Descriptor, U16 u16DescriptorLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_APIXC_ReturnValue MApi_XC_Mux_SetSupportMhlPathInfo(MS_U8) */
EXTERN_C_LINKAGE E_APIXC_ReturnValue MApi_XC_Mux_SetSupportMhlPathInfo (MS_U8 u8MhlSupportInfo) ;
EXTERN_C_LINKAGE E_APIXC_ReturnValue CppTest_Stub_MApi_XC_Mux_SetSupportMhlPathInfo (MS_U8 u8MhlSupportInfo)
{
    return E_APIXC_RET_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MDrv_AVD_SetChannelChange(void) */
EXTERN_C_LINKAGE void MDrv_AVD_SetChannelChange () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_SetChannelChange (void)
{
}

/** User stub definition for function: MS_BOOL MApi_SWI2C_WriteByte(MS_U16, MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_SWI2C_WriteByte (MS_U16 u16BusNumSlaveID, MS_U8 u8RegAddr, MS_U8 u8Data) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SWI2C_WriteByte (MS_U16 u16BusNumSlaveID, MS_U8 u8RegAddr, MS_U8 u8Data)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_CEC_Init(MS_CEC_INIT_INFO *) */
EXTERN_C_LINKAGE void MApi_CEC_Init (MS_CEC_INIT_INFO * pCECInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_Init (MS_CEC_INIT_INFO * pCECInfo)
{
}

/** User stub definition for function: void MApi_AUDIO_EnableSurround(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_EnableSurround (MS_BOOL EnSurround) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_EnableSurround (MS_BOOL EnSurround)
{
}

/** User stub definition for function: MS_BOOL MsOS_DisableInterrupt(InterruptNum) */
EXTERN_C_LINKAGE MS_BOOL MsOS_DisableInterrupt (InterruptNum eIntNum) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MsOS_DisableInterrupt (InterruptNum eIntNum)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_DLC_CGC_ResetCGain(void) */
EXTERN_C_LINKAGE void MApi_XC_DLC_CGC_ResetCGain () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_CGC_ResetCGain (void)
{
}

/** User stub definition for function: void MApi_XC_DLC_CGC_Init(void) */
EXTERN_C_LINKAGE void MApi_XC_DLC_CGC_Init () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_CGC_Init (void)
{
}

/** User stub definition for function: void MDrv_VE_SetMode(MS_VE_Set_Mode_Type *) */
EXTERN_C_LINKAGE void MDrv_VE_SetMode (MS_VE_Set_Mode_Type * pVESetMode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SetMode (MS_VE_Set_Mode_Type * pVESetMode)
{
}

/** User stub definition for function: MBX_Result MDrv_MBX_UnRegisterMSG(MBX_Class, MS_BOOL) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_UnRegisterMSG (MBX_Class eMsgClass, MS_BOOL bForceDiscardMsgQueue) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_UnRegisterMSG (MBX_Class eMsgClass, MS_BOOL bForceDiscardMsgQueue)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MDrv_HDMI_init(void) */
EXTERN_C_LINKAGE void MDrv_HDMI_init () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDMI_init (void)
{
}

/** User stub definition for function: MBX_Result MDrv_MBX_Init(MBX_CPU_ID, MBX_ROLE_ID, MS_U32) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_Init (MBX_CPU_ID eHKCPU, MBX_ROLE_ID eHostRole, MS_U32 u32TimeoutMillSecs) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_Init (MBX_CPU_ID eHKCPU, MBX_ROLE_ID eHostRole, MS_U32 u32TimeoutMillSecs)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: GFX_Result MApi_GFX_DrawLine(GFX_DrawLineInfo *) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_DrawLine (GFX_DrawLineInfo * pline) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_DrawLine (GFX_DrawLineInfo * pline)
{
    return GFX_FAIL;
}

/** User stub definition for function: void MApi_SC_Enable_FPLL_FSM(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_SC_Enable_FPLL_FSM (MS_BOOL bTrue) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_SC_Enable_FPLL_FSM (MS_BOOL bTrue)
{
}

/** User stub definition for function: void MApp_Dmx_CloseAllFilters(void) */
EXTERN_C_LINKAGE void MApp_Dmx_CloseAllFilters () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_CloseAllFilters (void)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_EnableAlphaBlending(MS_BOOL) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_EnableAlphaBlending (MS_BOOL enable) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_EnableAlphaBlending (MS_BOOL enable)
{
    return GFX_FAIL;
}

/** User stub definition for function: EN_AVI_INFOFRAME_VERSION MDrv_HDMI_Get_AVIInfoFrameVer(void) */
EXTERN_C_LINKAGE EN_AVI_INFOFRAME_VERSION MDrv_HDMI_Get_AVIInfoFrameVer () ;
EXTERN_C_LINKAGE EN_AVI_INFOFRAME_VERSION CppTest_Stub_MDrv_HDMI_Get_AVIInfoFrameVer (void)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange") )
	{
		return E_AVI_INFOFRAME_VERSION2;
	}
    return E_AVI_INFOFRAME_VERSION_NON;
}

/** User stub definition for function: U32 MDrv_GetUsbBlockSize_Port2(U8) */
EXTERN_C_LINKAGE U32 MDrv_GetUsbBlockSize_Port2 (U8 lun) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MDrv_GetUsbBlockSize_Port2 (U8 lun)
{
    return 0UL;
}

/** User stub definition for function: GFX_Result MApi_GFX_GetBufferInfo(PGFX_BufferInfo, PGFX_BufferInfo) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_GetBufferInfo (PGFX_BufferInfo srcbufInfo, PGFX_BufferInfo dstbufInfo) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_GetBufferInfo (PGFX_BufferInfo srcbufInfo, PGFX_BufferInfo dstbufInfo)
{
    return GFX_FAIL;
}

/** User stub definition for function: void msAPI_CI_SetMHEG5BufAddr(U32) */
EXTERN_C_LINKAGE void msAPI_CI_SetMHEG5BufAddr (U32 u32BufAdr) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_SetMHEG5BufAddr (U32 u32BufAdr)
{
}

/** User stub definition for function: MS_BOOL MDrv_SYS_SetPadMux(SYS_PAD_MUX_SET, SYS_PAD_SEL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SYS_SetPadMux (SYS_PAD_MUX_SET ePadMuxType, SYS_PAD_SEL ePadSel) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SYS_SetPadMux (SYS_PAD_MUX_SET ePadMuxType, SYS_PAD_SEL ePadSel)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_GetCaptureWindow(MS_WINDOW_TYPE *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_GetCaptureWindow (MS_WINDOW_TYPE * capture_win, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GetCaptureWindow (MS_WINDOW_TYPE * capture_win, SCALER_WIN eWindow)
{
}

/** User stub definition for function: BOOLEAN msAPI_Subtitle_Decoder_Main(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Subtitle_Decoder_Main () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Subtitle_Decoder_Main (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_IsCurrentRequest_FrameBufferLessMode(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsCurrentRequest_FrameBufferLessMode () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsCurrentRequest_FrameBufferLessMode (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_VDEC_GetActiveFormat(void) */
EXTERN_C_LINKAGE MS_U8 MApi_VDEC_GetActiveFormat () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_VDEC_GetActiveFormat (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_EventFindByID(MEMBER_SI_SERVICETYPE, U16, U16, EventIndex *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_EventFindByID (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, U16 u16EventID, EventIndex * pEventIdx) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_EventFindByID (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, U16 u16EventID, EventIndex * pEventIdx)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: U32 msAPI_OAD_GetMISVersionId(void) */
EXTERN_C_LINKAGE U32 msAPI_OAD_GetMISVersionId () ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_OAD_GetMISVersionId (void)
{
    return 0UL;
}

/** User stub definition for function: MS_BOOL MApi_XC_IsFieldPackingModeSupported(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsFieldPackingModeSupported () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsFieldPackingModeSupported (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_Table_Monitor(void) */
EXTERN_C_LINKAGE void MApp_SI_Table_Monitor () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Table_Monitor (void)
{
}
/** User stub definition for function: void MApp_SI_Table_Monitor(void) */
EXTERN_C_LINKAGE void MApp_SI_FileIn_Parse () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_FileIn_Parse (void)
{
}

EXTERN_C_LINKAGE void MApp_Dmx_DisableFileInMonitor () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_DisableFileInMonitor (void)
{
}

EXTERN_C_LINKAGE void MApp_Dmx_EnableFileInMonitorNumber(U16 u16ProgrammeNumberServiceID);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_EnableFileInMonitorNumber (U16 u16ProgrammeNumberServiceID)
{
}

/** User stub definition for function: MS_U8 MApi_XC_ACE_DNR_GetParam(MS_BOOL, XC_ACE_DNR_Param) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ACE_DNR_GetParam (MS_BOOL eWindow, XC_ACE_DNR_Param eParam) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ACE_DNR_GetParam (MS_BOOL eWindow, XC_ACE_DNR_Param eParam)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendSearchStart(BOOLEAN, U8 *, U8, U8 *, U8, U8 *, U8) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendSearchStart (BOOLEAN bUnattendedFlag, U8 * u8pServiceType, U8 u8ServiceTypeLoopLen, U8 * u8pDeliveryCapability, U8 u8DeliveryCapabilityLoopLen, U8 * u8pApplicationCapability, U8 u8ApplicationCapabilityLoopLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendSearchStart (BOOLEAN bUnattendedFlag, U8 * u8pServiceType, U8 u8ServiceTypeLoopLen, U8 * u8pDeliveryCapability, U8 u8DeliveryCapabilityLoopLen, U8 * u8pApplicationCapability, U8 u8ApplicationCapabilityLoopLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AVD_StartAutoStandardDetection(void) */
EXTERN_C_LINKAGE void MDrv_AVD_StartAutoStandardDetection () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_StartAutoStandardDetection (void)
{
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsWithValidStream(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsWithValidStream () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsWithValidStream (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_XC_Mux_TriggerDestOnOffEvent(INPUT_SOURCE_TYPE_t, void *) */
EXTERN_C_LINKAGE void MApi_XC_Mux_TriggerDestOnOffEvent (INPUT_SOURCE_TYPE_t src, void * para) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Mux_TriggerDestOnOffEvent (INPUT_SOURCE_TYPE_t src, void * para)
{
}

/** User stub definition for function: MS_BOOL MApi_DMX_Filein_IsIdle(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_DMX_Filein_IsIdle () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_DMX_Filein_IsIdle (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U32 MDrv_GetUsbBlockSize(U8) */
EXTERN_C_LINKAGE U32 MDrv_GetUsbBlockSize (U8 lun) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MDrv_GetUsbBlockSize (U8 lun)
{
    return 0UL;
}

/** User stub definition for function: COPRO_Result MDrv_COPRO_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE COPRO_Result MDrv_COPRO_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE COPRO_Result CppTest_Stub_MDrv_COPRO_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_COPRO_OK;
}

/** User stub definition for function: void MApi_AUDIO_SetAvcMode(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetAvcMode (MS_U8 AvcMode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetAvcMode (MS_U8 AvcMode)
{
}

/** User stub definition for function: void MApi_AUDIO_SetAvcAT(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetAvcAT (MS_U8 AvcAT) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetAvcAT (MS_U8 AvcAT)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_DeleteFB(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_DeleteFB (MS_U8 fbId) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_DeleteFB (MS_U8 fbId)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MBX_Result MDrv_MBX_RecvMsg(MBX_Class, MBX_Msg *, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_RecvMsg (MBX_Class eTargetClass, MBX_Msg * pMsg, MS_U32 u32WaitMillSecs, MS_U32 u32Flag) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_RecvMsg (MBX_Class eTargetClass, MBX_Msg * pMsg, MS_U32 u32WaitMillSecs, MS_U32 u32Flag)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MDrv_DrvDgb2NextPage(void) */
EXTERN_C_LINKAGE void MDrv_DrvDgb2NextPage () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DrvDgb2NextPage (void)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_GetStatus(CI_OP_STATUS *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_GetStatus (CI_OP_STATUS * pstInfo) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_GetStatus (CI_OP_STATUS * pstInfo)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendEntitlementAck(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendEntitlementAck () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendEntitlementAck (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void mapi_mhl_Send3DInformation(void) */
EXTERN_C_LINKAGE void mapi_mhl_Send3DInformation () ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_Send3DInformation (void)
{
}

/** User stub definition for function: void MApi_AUDIO_SetPreScale(MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetPreScale (MS_U8 u8Path, MS_U8 u8PreScale) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetPreScale (MS_U8 u8Path, MS_U8 u8PreScale)
{
}

/** User stub definition for function: MBX_Result MDrv_MBX_RegisterMSGWithCallBack(MBX_Class, MS_U16, MBX_MAIL_ARRIVE_NOTIFY_FUNC) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_RegisterMSGWithCallBack (MBX_Class eMsgClass, MS_U16 u16MsgQueueSize, MBX_MAIL_ARRIVE_NOTIFY_FUNC notifier) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_RegisterMSGWithCallBack (MBX_Class eMsgClass, MS_U16 u16MsgQueueSize, MBX_MAIL_ARRIVE_NOTIFY_FUNC notifier)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MDrv_HDMI_dvi_adjust(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_HDMI_dvi_adjust (MS_BOOL bClockLessThan70MHz) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDMI_dvi_adjust (MS_BOOL bClockLessThan70MHz)
{
}

/** User stub definition for function: void MApi_XC_ChangePanelType(XC_PANEL_INFO *) */
EXTERN_C_LINKAGE void MApi_XC_ChangePanelType (XC_PANEL_INFO * pstPanelInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ChangePanelType (XC_PANEL_INFO * pstPanelInfo)
{
}

/** User stub definition for function: void mapi_mhl_PowerCtrl(E_MHL_POWERCTRL_Mode) */
EXTERN_C_LINKAGE void mapi_mhl_PowerCtrl (E_MHL_POWERCTRL_Mode pctrl) ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_PowerCtrl (E_MHL_POWERCTRL_Mode pctrl)
{
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetFBfromGWIN(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetFBfromGWIN (MS_U8 gwinId) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetFBfromGWIN (MS_U8 gwinId)
{
    return (unsigned char)0;
}

/** User stub definition for function: void __MDrv_WriteByte(U32, U8) */
EXTERN_C_LINKAGE void __MDrv_WriteByte (U32 u32Reg, U8 u8Val) ;
EXTERN_C_LINKAGE void CppTest_Stub___MDrv_WriteByte (U32 u32Reg, U8 u8Val)
{
}

/** User stub definition for function: PWM_Result MDrv_PWM_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE PWM_Result MDrv_PWM_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE PWM_Result CppTest_Stub_MDrv_PWM_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_PWM_OK;
}

/** User stub definition for function: U8 MDrv_GetUsbDeviceStatus(void) */
EXTERN_C_LINKAGE U8 MDrv_GetUsbDeviceStatus () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_GetUsbDeviceStatus (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MDrv_GetUsbDevInterfaceClass(void) */
EXTERN_C_LINKAGE U8 MDrv_GetUsbDevInterfaceClass () ;
EXTERN_C_LINKAGE U8 MDrv_GetUsbDevInterfaceClass (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_AVD_SetInput(AVD_InputSourceType, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AVD_SetInput (AVD_InputSourceType eSource, MS_U8 u8ScartFB) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AVD_SetInput (AVD_InputSourceType eSource, MS_U8 u8ScartFB)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_DNR_Init_Noise(void) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DNR_Init_Noise () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DNR_Init_Noise (void)
{
}

/** User stub definition for function: void msAPI_CI_AppMmi_FileReq(U8 *, U8, EN_APPMMI_REQTYPE) */
EXTERN_C_LINKAGE void msAPI_CI_AppMmi_FileReq (U8 * u8pFileName, U8 u8FileNameLen, EN_APPMMI_REQTYPE eReqType) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_AppMmi_FileReq (U8 * u8pFileName, U8 u8FileNameLen, EN_APPMMI_REQTYPE eReqType)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_Auto_GainOffset(XC_Auto_CalibrationType, XC_Auto_TuneType, APIXC_AdcGainOffsetSetting *, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Auto_GainOffset (XC_Auto_CalibrationType type, XC_Auto_TuneType enAutoTuneType, APIXC_AdcGainOffsetSetting * pstADCSetting, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Auto_GainOffset (XC_Auto_CalibrationType type, XC_Auto_TuneType enAutoTuneType, APIXC_AdcGainOffsetSetting * pstADCSetting, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AUDIO_SetPowerDownWait(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_AUDIO_SetPowerDownWait (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AUDIO_SetPowerDownWait (MS_BOOL bEnable)
{
}

/** User stub definition for function: void MApi_XC_GenerateBlackVideo(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_GenerateBlackVideo (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GenerateBlackVideo (MS_BOOL bEnable, SCALER_WIN eWindow)
{
}

/** User stub definition for function: E_PWS_Result MDrv_PWS_HandleSource(E_PWS_Operation, E_PWS_SouceInfo, E_PWS_Sync) */
EXTERN_C_LINKAGE E_PWS_Result MDrv_PWS_HandleSource (E_PWS_Operation operation, E_PWS_SouceInfo source, E_PWS_Sync sync_type) ;
EXTERN_C_LINKAGE E_PWS_Result CppTest_Stub_MDrv_PWS_HandleSource (E_PWS_Operation operation, E_PWS_SouceInfo source, E_PWS_Sync sync_type)
{
    return PWS_FAIL;
}

/** User stub definition for function: double tan(double) */
EXTERN_C_LINKAGE double tan (double __x) ;
EXTERN_C_LINKAGE double CppTest_Stub_tan (double __x)
{
    return 0.0;
}

/** User stub definition for function: U16 __MDrv_Read2Byte(U32) */
EXTERN_C_LINKAGE U16 __MDrv_Read2Byte (U32 u32Reg) ;
EXTERN_C_LINKAGE U16 CppTest_Stub___MDrv_Read2Byte (U32 u32Reg)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MDrv_DDC2BI_Set_StandardCallBack(CALLBACK_AlignControl) */
EXTERN_C_LINKAGE void MDrv_DDC2BI_Set_StandardCallBack (CALLBACK_AlignControl align_control) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DDC2BI_Set_StandardCallBack (CALLBACK_AlignControl align_control)
{
}

/** User stub definition for function: U8 MDrv_Usb_Device_Enum_EX_Port2(void) */
EXTERN_C_LINKAGE U8 MDrv_Usb_Device_Enum_EX_Port2 () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_Usb_Device_Enum_EX_Port2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_GetCurrentPMTSection(U8 *, U16 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_GetCurrentPMTSection (U8 * pu8PMTSection, U16 * pu16PMTSectionLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_GetCurrentPMTSection (U8 * pu8PMTSection, U16 * pu16PMTSectionLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_GOP_GWIN_IsGWINEnabled(MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_GOP_GWIN_IsGWINEnabled (MS_U8 winId) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_GOP_GWIN_IsGWINEnabled (MS_U8 winId)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_Set_3D_HShift(MS_U16) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Set_3D_HShift (MS_U16 u16HShift) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Set_3D_HShift (MS_U16 u16HShift)
{
    return (unsigned char)0;
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_TxSendMsg(MsCEC_DEVICELA, MsCEC_MSGLIST, MS_U8 *, MS_U8) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_TxSendMsg (MsCEC_DEVICELA header, MsCEC_MSGLIST opcode, MS_U8 * operand_ptr, MS_U8 len) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_TxSendMsg (MsCEC_DEVICELA header, MsCEC_MSGLIST opcode, MS_U8 * operand_ptr, MS_U8 len)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GetLibVer (const MSIF_Version ** ppVersion)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: BOOLEAN msAPI_Subtitle_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Subtitle_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Subtitle_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_SetDither(MS_BOOL) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetDither (MS_BOOL enable) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetDither (MS_BOOL enable)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_DLC_GetLumaCurveStatus(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_DLC_GetLumaCurveStatus () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_DLC_GetLumaCurveStatus (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_SI_IS_GotTDTOrTOT(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_IS_GotTDTOrTOT () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_IS_GotTDTOrTOT (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3")||
		CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1")
		)
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: void MApp_Dmx_SetMonitorStatus(BOOLEAN, EN_MONITOR_TABLE) */
EXTERN_C_LINKAGE void MApp_Dmx_SetMonitorStatus (BOOLEAN bStatus, EN_MONITOR_TABLE eTable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_SetMonitorStatus (BOOLEAN bStatus, EN_MONITOR_TABLE eTable)
{
}

/** User stub definition for function: MS_U8 MDrv_HDMI_audio_cp_hdr_info(void) */
EXTERN_C_LINKAGE MS_U8 MDrv_HDMI_audio_cp_hdr_info () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_HDMI_audio_cp_hdr_info (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_SetOutputCfg(MVOP_VidStat *, MS_BOOL) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_SetOutputCfg (MVOP_VidStat * pstVideoStatus, MS_BOOL bEnHDup) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_SetOutputCfg (MVOP_VidStat * pstVideoStatus, MS_BOOL bEnHDup)
{
    return E_MVOP_OK;
}

/** User stub definition for function: MS_BOOL MApi_XC_Get_3D_IsSupportedHW2DTo3D(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Get_3D_IsSupportedHW2DTo3D () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Get_3D_IsSupportedHW2DTo3D (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_CardDetect(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CardDetect () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CardDetect (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_else"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_WriteProtect_Disable_Range_Set(MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_WriteProtect_Disable_Range_Set (MS_U32 DisableLowerBound, MS_U32 DisableSize) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_WriteProtect_Disable_Range_Set (MS_U32 DisableLowerBound, MS_U32 DisableSize)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_VBI_RingBuffer_Reset(void) */
EXTERN_C_LINKAGE void MDrv_VBI_RingBuffer_Reset () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VBI_RingBuffer_Reset (void)
{
}

/** User stub definition for function: void MApi_XC_ACE_DNR_SetParam(MS_BOOL, XC_ACE_DNR_Param, MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DNR_SetParam (MS_BOOL eWindow, XC_ACE_DNR_Param eParam, MS_U16 u16val) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DNR_SetParam (MS_BOOL eWindow, XC_ACE_DNR_Param eParam, MS_U16 u16val)
{
}

/** User stub definition for function: void MApi_PNL_SetOutput(APIPNL_OUTPUT_MODE) */
EXTERN_C_LINKAGE void MApi_PNL_SetOutput (APIPNL_OUTPUT_MODE eOutputMode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_PNL_SetOutput (APIPNL_OUTPUT_MODE eOutputMode)
{
}

/** User stub definition for function: void DRV_VIF_SetSoundSystem(VIFSoundSystem) */
EXTERN_C_LINKAGE void DRV_VIF_SetSoundSystem (VIFSoundSystem ucSoundSystem) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_SetSoundSystem (VIFSoundSystem ucSoundSystem)
{
}

/** User stub definition for function: AUDIOSTANDARD_TYPE MApi_AUDIO_SIF_ConvertToBasicAudioStandard(AUDIOSTANDARD_TYPE) */
EXTERN_C_LINKAGE AUDIOSTANDARD_TYPE MApi_AUDIO_SIF_ConvertToBasicAudioStandard (AUDIOSTANDARD_TYPE eStandard) ;
EXTERN_C_LINKAGE AUDIOSTANDARD_TYPE CppTest_Stub_MApi_AUDIO_SIF_ConvertToBasicAudioStandard (AUDIOSTANDARD_TYPE eStandard)
{
    return E_AUDIOSTANDARD_BG;
}

/** User stub definition for function: void MApi_AUDIO_EnablePEQ(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_EnablePEQ (MS_BOOL Enpeq) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_EnablePEQ (MS_BOOL Enpeq)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pid(MS_U8, MS_U16 *, MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pid (MS_U8 u8DmxId, MS_U16 * pu16Pid, MS_BOOL bSet) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pid (MS_U8 u8DmxId, MS_U16 * pu16Pid, MS_BOOL bSet)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendNitReq(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendNitReq () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendNitReq (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_HDMI_PROG_DDCRAM(XC_DDCRAM_PROG_INFO *, MS_U32) */
EXTERN_C_LINKAGE void MDrv_HDMI_PROG_DDCRAM (XC_DDCRAM_PROG_INFO * pstDDCRam_Info, MS_U32 u32SizeOfInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDMI_PROG_DDCRAM (XC_DDCRAM_PROG_INFO * pstDDCRam_Info, MS_U32 u32SizeOfInfo)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_PCMonitor_Init(MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_PCMonitor_Init (MS_U8 u8MaxWindowNum) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_PCMonitor_Init (MS_U8 u8MaxWindowNum)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SIF_SetPrescale(MS_U8, int) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_SetPrescale (MS_U8 _MT_var366, int _MT_var367) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_SetPrescale (MS_U8 _MT_var188, int _MT_var189)
{
}

/** User stub definition for function: S32 MApp_SI_Get_OffsetTime(U32, BOOLEAN *, BOOLEAN *, BOOLEAN) */
EXTERN_C_LINKAGE S32 MApp_SI_Get_OffsetTime (U32 u32Seconds, BOOLEAN * bDayLightTime, BOOLEAN * bGotTOT, BOOLEAN bIsStartTime) ;
EXTERN_C_LINKAGE S32 CppTest_Stub_MApp_SI_Get_OffsetTime (U32 u32Seconds, BOOLEAN * bDayLightTime, BOOLEAN * bGotTOT, BOOLEAN bIsStartTime)
{
    return 0L;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_SetClkForCapture(void) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_SetClkForCapture () ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_SetClkForCapture (void)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_CreateFB2(MS_U8, MS_U16, MS_U16, MS_U16, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_CreateFB2 (MS_U8 FBId, MS_U16 x, MS_U16 y, MS_U16 width, MS_U16 height, MS_U16 fbFmt) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_CreateFB2 (MS_U8 FBId, MS_U16 x, MS_U16 y, MS_U16 width, MS_U16 height, MS_U16 fbFmt)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_SetDebugLevel(EN_CI_FUNCTION, U8) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_SetDebugLevel (EN_CI_FUNCTION eCI_Function, U8 u8DebugLevel) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_SetDebugLevel (EN_CI_FUNCTION eCI_Function, U8 u8DebugLevel)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MDrv_AVD_GetNoiseMag(void) */
EXTERN_C_LINKAGE MS_U8 MDrv_AVD_GetNoiseMag () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_AVD_GetNoiseMag (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_RegisterXCIsInterlaceCB(MS_BOOL (*)(void)) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_RegisterXCIsInterlaceCB (MS_BOOL (* fpGOP_CB)(void)) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_RegisterXCIsInterlaceCB (MS_BOOL (* fpGOP_CB)(void))
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetAACInfo(Audio_AAC_infoType, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetAACInfo (Audio_AAC_infoType infoType, MS_U32 param1, MS_U32 param2) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetAACInfo (Audio_AAC_infoType infoType, MS_U32 param1, MS_U32 param2)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_CI_AppMmi_FileInquire(U8 *, U8, EN_APPMMI_REQTYPE) */
EXTERN_C_LINKAGE void msAPI_CI_AppMmi_FileInquire (U8 * u8pFileName, U8 u8FileDataLen, EN_APPMMI_REQTYPE eReqType) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_AppMmi_FileInquire (U8 * u8pFileName, U8 u8FileDataLen, EN_APPMMI_REQTYPE eReqType)
{
}

/** User stub definition for function: void mdrv_gpio_set_low(MS_GPIO_NUM) */
EXTERN_C_LINKAGE void mdrv_gpio_set_low (MS_GPIO_NUM gpio) ;
EXTERN_C_LINKAGE void CppTest_Stub_mdrv_gpio_set_low (MS_GPIO_NUM gpio)
{
}

/** User stub definition for function: MS_BOOL MDrv_VBI_IsTTX_Ready(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_IsTTX_Ready () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_IsTTX_Ready (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SPDIF_HWEN(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_SPDIF_HWEN (MS_BOOL spdif_hwen) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SPDIF_HWEN (MS_BOOL spdif_hwen)
{
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_WriteProtect(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_WriteProtect (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_WriteProtect (MS_BOOL bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_EnableEQ(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_EnableEQ (MS_BOOL EnEQ) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_EnableEQ (MS_BOOL EnEQ)
{
}

/** User stub definition for function: BOOLEAN MApp_Epg_IsEventInfoUpdated(MEMBER_SI_SERVICETYPE, U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_Epg_IsEventInfoUpdated (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Epg_IsEventInfoUpdated (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_SetRotate(GFX_RotateAngle) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetRotate (GFX_RotateAngle angle) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetRotate (GFX_RotateAngle angle)
{
    return GFX_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetBlending(MS_U8, MS_BOOL, MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetBlending (MS_U8 u8win, MS_BOOL bEnable, MS_U8 u8coef) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetBlending (MS_U8 u8win, MS_BOOL bEnable, MS_U8 u8coef)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_Init(XC_INITDATA *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Init (XC_INITDATA * pXC_InitData, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Init (XC_INITDATA * pXC_InitData, MS_U32 u32InitDataLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_S32 MsOS_CreateMutex(MsOSAttribute, char *, MS_U32) */
EXTERN_C_LINKAGE MS_S32 MsOS_CreateMutex (MsOSAttribute eAttribute, char * pMutexName, MS_U32 u32Flag) ;
EXTERN_C_LINKAGE MS_S32 CppTest_Stub_MsOS_CreateMutex (MsOSAttribute eAttribute, char * pMutexName, MS_U32 u32Flag)
{
    return 0L;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_GetOutputTiming(MVOP_Timing *) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_GetOutputTiming (MVOP_Timing * pMVOPTiming) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_GetOutputTiming (MVOP_Timing * pMVOPTiming)
{
    return E_MVOP_OK;
}

/** User stub definition for function: void MApi_XC_EnableMainWindow(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_EnableMainWindow (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableMainWindow (MS_BOOL bEnable)
{
}

/** User stub definition for function: void MDrv_DVI_SwitchSrc(E_MUX_INPUTPORT) */
EXTERN_C_LINKAGE void MDrv_DVI_SwitchSrc (E_MUX_INPUTPORT enInputPortType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DVI_SwitchSrc (E_MUX_INPUTPORT enInputPortType)
{
}

/** User stub definition for function: void MApi_AUDIO_SetAvcThreshold(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetAvcThreshold (MS_U8 Level) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetAvcThreshold (MS_U8 Level)
{
}

/** User stub definition for function: double pow(double, double) */
EXTERN_C_LINKAGE double pow (double __x, double __y) ;
EXTERN_C_LINKAGE double CppTest_Stub_pow (double __x, double __y)
{
    return 0.0;
}

/** User stub definition for function: E_APIXC_ReturnValue MApi_XC_GetMISCStatus(XC_INITMISC *) */
EXTERN_C_LINKAGE E_APIXC_ReturnValue MApi_XC_GetMISCStatus (XC_INITMISC * pXC_Init_Misc) ;
EXTERN_C_LINKAGE E_APIXC_ReturnValue CppTest_Stub_MApi_XC_GetMISCStatus (XC_INITMISC * pXC_Init_Misc)
{
    return E_APIXC_RET_FAIL;
}

/** User stub definition for function: GFX_Result MApi_GFX_SetSrcBufferInfo(GFX_BufferInfo *, MS_U32) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetSrcBufferInfo (GFX_BufferInfo * bufInfo, MS_U32 offsetofByte) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetSrcBufferInfo (GFX_BufferInfo * bufInfo, MS_U32 offsetofByte)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_BOOL mapi_mhl_CbusStatus(void) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_CbusStatus () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_CbusStatus (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL mapi_mhl_SendRCPAutoReleaseCmd(MS_U8 ) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_SendRCPAutoReleaseCmd(MS_U8 ucKeyCode);
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_SendRCPAutoReleaseCmd(MS_U8 ucKeyCode)
{
    return TRUE;
}

/** User stub definition for function: void mapi_mhl_handler(void) */
EXTERN_C_LINKAGE void mapi_mhl_handler () ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_handler (void)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetGOPDst(MS_U8, EN_GOP_DST_TYPE) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetGOPDst (MS_U8 u8GOP, EN_GOP_DST_TYPE dsttype) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetGOPDst (MS_U8 u8GOP, EN_GOP_DST_TYPE dsttype)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_SWI2C_Stop(void) */
EXTERN_C_LINKAGE void MApi_SWI2C_Stop () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_SWI2C_Stop (void)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_HC_GetTuneDescriptor(U8 *, U16 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HC_GetTuneDescriptor (U8 * u8pTuneDescriptor, U16 * u16pTuneDescriptorLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HC_GetTuneDescriptor (U8 * u8pTuneDescriptor, U16 * u16pTuneDescriptorLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_AddressToBlock(MS_U32, MS_U32 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_AddressToBlock (MS_U32 u32FlashAddr, MS_U32 * pu32BlockIndex) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_AddressToBlock (MS_U32 u32FlashAddr, MS_U32 * pu32BlockIndex)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_JPEG_IsMPOFormat(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_JPEG_IsMPOFormat () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_JPEG_IsMPOFormat (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void mdrv_dvi_reset(void) */
EXTERN_C_LINKAGE void mdrv_dvi_reset () ;
EXTERN_C_LINKAGE void CppTest_Stub_mdrv_dvi_reset (void)
{
}

/** User stub definition for function: unsigned int int_sqrt(unsigned int) */
EXTERN_C_LINKAGE unsigned int_sqrt (unsigned n) ;
EXTERN_C_LINKAGE unsigned CppTest_Stub_int_sqrt (unsigned n)
{
    return 0U;
}

/** User stub definition for function: void MApi_XC_DLC_SetOnOff(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_DLC_SetOnOff (MS_BOOL bSwitch, MS_BOOL bWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_SetOnOff (MS_BOOL bSwitch, MS_BOOL bWindow)
{
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_SendMenuLanguage(MS_U8 *) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_SendMenuLanguage (MS_U8 * pu8MenuLanguageCode) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_SendMenuLanguage (MS_U8 * pu8MenuLanguageCode)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_DestroyFB(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_DestroyFB (MS_U8 fbId) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_DestroyFB (MS_U8 fbId)
{
    return (unsigned char)0;
}

/** User stub definition for function: MsCEC_MSG_POWER_STATUS_PARM MApi_CEC_GetPowerStatus(void) */
EXTERN_C_LINKAGE MsCEC_MSG_POWER_STATUS_PARM MApi_CEC_GetPowerStatus () ;
EXTERN_C_LINKAGE MsCEC_MSG_POWER_STATUS_PARM CppTest_Stub_MApi_CEC_GetPowerStatus (void)
{
    return E_MSG_PWRSTA_ON;
}

/** User stub definition for function: signed long ms_MVF_LoadFont(void) */
EXTERN_C_LINKAGE signed long ms_MVF_LoadFont () ;
EXTERN_C_LINKAGE signed long CppTest_Stub_ms_MVF_LoadFont (void)
{
    return 0L;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Exit(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Exit () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Exit (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_Auto_Geometry_Ex(XC_Auto_TuneType, XC_Auto_Signal_Info_Ex *, XC_Auto_Signal_Info_Ex *, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Auto_Geometry_Ex (XC_Auto_TuneType enAutoTuneType, XC_Auto_Signal_Info_Ex * ActiveInfo, XC_Auto_Signal_Info_Ex * StandardInfo, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Auto_Geometry_Ex (XC_Auto_TuneType enAutoTuneType, XC_Auto_Signal_Info_Ex * ActiveInfo, XC_Auto_Signal_Info_Ex * StandardInfo, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void DRV_VIF_SetIfFreq(IfFrequencyType) */
EXTERN_C_LINKAGE void DRV_VIF_SetIfFreq (IfFrequencyType u16IfFreq) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_SetIfFreq (IfFrequencyType u16IfFreq)
{
}

/** User stub definition for function: U8 * MApp_SI_FindNextLoop(U8 *, U8 *, U16, EN_PSIP_TABLE) */
EXTERN_C_LINKAGE U8 * MApp_SI_FindNextLoop (U8 * pu8Section, U8 * pu8LoopPosition, U16 u16TotalDescriptorLength, EN_PSIP_TABLE enTable) ;
EXTERN_C_LINKAGE U8 * CppTest_Stub_MApp_SI_FindNextLoop (U8 * pu8Section, U8 * pu8LoopPosition, U16 u16TotalDescriptorLength, EN_PSIP_TABLE enTable)
{
    return pu8Section;
}

/** User stub definition for function: void MApi_CEC_SetActivePhysicalAddress(MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_CEC_SetActivePhysicalAddress (MS_U8 u8Para1, MS_U8 u8Para2) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_CEC_SetActivePhysicalAddress (MS_U8 u8Para1, MS_U8 u8Para2)
{
}

/** User stub definition for function: MS_U8 MApi_CEC_GetRxData(MS_U8, MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_CEC_GetRxData (MS_U8 u8Fifoidx, MS_U8 u8Idx) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_CEC_GetRxData (MS_U8 u8Fifoidx, MS_U8 u8Idx)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_SetAvcRT(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetAvcRT (MS_U8 AvcRT) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetAvcRT (MS_U8 AvcRT)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetFMT0TransClr(MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetFMT0TransClr (MS_U16 clr) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetFMT0TransClr (MS_U16 clr)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_XC_ACE_EnableMWE(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_ACE_EnableMWE (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_EnableMWE (MS_BOOL bEnable)
{
}

/** User stub definition for function: AUDIOSTANDARD_TYPE MApi_AUDIO_SIF_GetResultOfAutoStandardDetection(void) */
EXTERN_C_LINKAGE AUDIOSTANDARD_TYPE MApi_AUDIO_SIF_GetResultOfAutoStandardDetection () ;
EXTERN_C_LINKAGE AUDIOSTANDARD_TYPE CppTest_Stub_MApi_AUDIO_SIF_GetResultOfAutoStandardDetection (void)
{
    return E_AUDIOSTANDARD_BG;
}

/** User stub definition for function: void MApi_Audio_Monitor(void) */
EXTERN_C_LINKAGE void MApi_Audio_Monitor () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_Audio_Monitor (void)
{
}

/** User stub definition for function: void msAPI_CI_HC_NotifyTuneDone(void) */
EXTERN_C_LINKAGE void msAPI_CI_HC_NotifyTuneDone () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_HC_NotifyTuneDone (void)
{
}

/** User stub definition for function: void MApp_SI_SetDefaultCountry(EN_SI_COUNTRY_SETTING) */
EXTERN_C_LINKAGE void MApp_SI_SetDefaultCountry (EN_SI_COUNTRY_SETTING eSICountry) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_SetDefaultCountry (EN_SI_COUNTRY_SETTING eSICountry)
{
}

/** User stub definition for function: MS_U32 MApi_VDEC_GetPTS(void) */
EXTERN_C_LINKAGE MS_U32 MApi_VDEC_GetPTS () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_VDEC_GetPTS (void)
{

	if( CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF1"))
	{
		return 0UL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_ELSE1")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_IF"))
			{
				return 1UL;
			}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_ELSE"))
			{
				return 2912UL;
			}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF"))
			{
				return 46UL;
			}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF")||
			CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF_IF"))
			{
				return 2913UL;
			}
	else{
		 return 0UL;
		}


}

/** User stub definition for function: MS_U16 MDrv_AVD_Scan_HsyncCheck(MS_U8) */
EXTERN_C_LINKAGE MS_U16 MDrv_AVD_Scan_HsyncCheck (MS_U8 u8HtotalTolerance) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_AVD_Scan_HsyncCheck (MS_U8 u8HtotalTolerance)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_S16 MApi_XC_Mux_EnablePath(MS_U16) */
EXTERN_C_LINKAGE MS_S16 MApi_XC_Mux_EnablePath (MS_U16 PathId) ;
EXTERN_C_LINKAGE MS_S16 CppTest_Stub_MApi_XC_Mux_EnablePath (MS_U16 PathId)
{
    return (short)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Set_HSCALE(MS_BOOL, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Set_HSCALE (MS_BOOL bEnable, MS_U16 src, MS_U16 dst) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Set_HSCALE (MS_BOOL bEnable, MS_U16 src, MS_U16 dst)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_U16 MDrv_HDMI_GetHDE(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_HDMI_GetHDE () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_HDMI_GetHDE (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: U32 msAPI_Subtitle_GetQueueLength(void) */
EXTERN_C_LINKAGE U32 msAPI_Subtitle_GetQueueLength () ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Subtitle_GetQueueLength (void)
{
    return 0UL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_IsStart(MS_U8, MS_BOOL *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_IsStart (MS_U8 u8DmxId, MS_BOOL * pbEnable) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_IsStart (MS_U8 u8DmxId, MS_BOOL * pbEnable)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_GetFBAddr(MS_U8, MS_U32 *) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_GetFBAddr (MS_U8 fbID, MS_U32 * pAddr) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_GetFBAddr (MS_U8 fbID, MS_U32 * pAddr)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MDrv_AVD_SetRegValue(MS_U16, MS_U8) */
EXTERN_C_LINKAGE void MDrv_AVD_SetRegValue (MS_U16 u16Addr, MS_U8 u8Value) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_SetRegValue (MS_U16 u16Addr, MS_U8 u8Value)
{
}

/** User stub definition for function: U8 * MApp_Dmx_GetSI4KSectionBuffer(void) */
EXTERN_C_LINKAGE U8 * MApp_Dmx_GetSI4KSectionBuffer () ;
EXTERN_C_LINKAGE U8 * CppTest_Stub_MApp_Dmx_GetSI4KSectionBuffer (void)
{
    return (U8 *)0;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventTime(EventIndex, EventTime *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventTime (EventIndex event, EventTime * pEventTime) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetEventTime (EventIndex event, EventTime * pEventTime)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: MS_BOOL MDrv_SYS_DMD_VD_MBX_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SYS_DMD_VD_MBX_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SYS_DMD_VD_MBX_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_MIU_ProtectAlign(MS_U32 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MIU_ProtectAlign (MS_U32 * u32PageShift) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MIU_ProtectAlign (MS_U32 * u32PageShift)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_DMX_TTX_SetFilterID(MS_U8) */
EXTERN_C_LINKAGE void MDrv_DMX_TTX_SetFilterID (MS_U8 fid) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DMX_TTX_SetFilterID (MS_U8 fid)
{
}

/** User stub definition for function: void mapi_mhl_CbusControl(MS_U8) */
EXTERN_C_LINKAGE void mapi_mhl_CbusControl (MS_U8 ucState) ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_CbusControl (MS_U8 ucState)
{
}

/** User stub definition for function: SI_MHEG5_STATUS MApp_SI_CheckMHEG5Status(void) */
EXTERN_C_LINKAGE SI_MHEG5_STATUS MApp_SI_CheckMHEG5Status () ;
EXTERN_C_LINKAGE SI_MHEG5_STATUS CppTest_Stub_MApp_SI_CheckMHEG5Status (void)
{
    return SI_MHEG5_DISABLE;
}

/** User stub definition for function: void MDrv_VE_SwitchOuputDest(PMS_Switch_VE_Dest_Info) */
EXTERN_C_LINKAGE void MDrv_VE_SwitchOuputDest (PMS_Switch_VE_Dest_Info pSwitchInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SwitchOuputDest (PMS_Switch_VE_Dest_Info pSwitchInfo)
{
}

/** User stub definition for function: void * MsOS_ReallocateMemory(void *, MS_U32, MS_S32) */
EXTERN_C_LINKAGE void * MsOS_ReallocateMemory (void * pOrgAddress, MS_U32 u32NewSize, MS_S32 s32PoolId) ;
EXTERN_C_LINKAGE void * CppTest_Stub_MsOS_ReallocateMemory (void * pOrgAddress, MS_U32 u32NewSize, MS_S32 s32PoolId)
{
    return pOrgAddress;
}

/** User stub definition for function: U32 __MDrv_Read4Byte(U32) */
EXTERN_C_LINKAGE U32 __MDrv_Read4Byte (U32 u32Reg) ;
EXTERN_C_LINKAGE U32 CppTest_Stub___MDrv_Read4Byte (U32 u32Reg)
{
    return 0UL;
}

/** User stub definition for function: MS_BOOL MDrv_MIU_SetIOMapBase(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MIU_SetIOMapBase () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MIU_SetIOMapBase (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_DMS(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DMS (MS_BOOL eWindow, MS_BOOL bisATV) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DMS (MS_BOOL eWindow, MS_BOOL bisATV)
{
}

/** User stub definition for function: AVD_Result MDrv_AVD_Init(VD_INITDATA *, MS_U32) */
EXTERN_C_LINKAGE AVD_Result MDrv_AVD_Init (VD_INITDATA * pVD_InitData, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE AVD_Result CppTest_Stub_MDrv_AVD_Init (VD_INITDATA * pVD_InitData, MS_U32 u32InitDataLen)
{
    return E_AVD_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SetBalance(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetBalance (MS_U8 u8Balance) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetBalance (MS_U8 u8Balance)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_Initialize_StretchWindow(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_Initialize_StretchWindow (MS_U8 u8GOPNum) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_Initialize_StretchWindow (MS_U8 u8GOPNum)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: E_HDMI_ADDITIONAL_VIDEO_FORMAT MDrv_HDMI_Check_Additional_Format(void) */
EXTERN_C_LINKAGE E_HDMI_ADDITIONAL_VIDEO_FORMAT MDrv_HDMI_Check_Additional_Format () ;
EXTERN_C_LINKAGE E_HDMI_ADDITIONAL_VIDEO_FORMAT CppTest_Stub_MDrv_HDMI_Check_Additional_Format (void)
{
    return E_HDMI_NO_ADDITIONAL_FORMAT;
}

/** User stub definition for function: MS_U16 MDrv_MVOP_GetVStart(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_MVOP_GetVStart () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_MVOP_GetVStart (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: SAR_Result MDrv_SAR_Enable(MS_BOOL) */
EXTERN_C_LINKAGE SAR_Result MDrv_SAR_Enable (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE SAR_Result CppTest_Stub_MDrv_SAR_Enable (MS_BOOL bEnable)
{
    return E_SAR_FAIL;
}

/** User stub definition for function: MS_U16 MDrv_DMX_TTX_PacketBufferGetNoOfOverflows(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_DMX_TTX_PacketBufferGetNoOfOverflows () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_DMX_TTX_PacketBufferGetNoOfOverflows (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: U8 msAPI_OAD_GetProgress(void) */
EXTERN_C_LINKAGE U8 msAPI_OAD_GetProgress () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_OAD_GetProgress (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Pause(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Pause () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Pause (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SIF_Shift(En_AUD_VIF_Type) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_Shift (En_AUD_VIF_Type type) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_Shift (En_AUD_VIF_Type type)
{
}

/** User stub definition for function: BOOLEAN MDrv_UsbBlockWriteFromMIU(U8, U32, U32, U32) */
EXTERN_C_LINKAGE BOOLEAN MDrv_UsbBlockWriteFromMIU (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_UsbBlockWriteFromMIU (U8 lun, U32 u32BlockAddr, U32 u32BlockNum, U32 u32Buffer)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_SetRecordStamp(MS_U32) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_SetRecordStamp (MS_U32 u32Stamp) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_SetRecordStamp (MS_U32 u32Stamp)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApp_Dmx_EnableTableMonitor(void) */
EXTERN_C_LINKAGE void MApp_Dmx_EnableTableMonitor () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_EnableTableMonitor (void)
{
}

/** User stub definition for function: void MApi_XC_SetPanelTiming(XC_SetTiming_Info *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetPanelTiming (XC_SetTiming_Info * pTimingInfo, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetPanelTiming (XC_SetTiming_Info * pTimingInfo, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MDrv_VBI_IsWSS_Ready(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_IsWSS_Ready () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_IsWSS_Ready (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: SI_SHORT_DTV_CHANNEL_INFO * MApp_SI_Get_PastVirtualCh(void) */
EXTERN_C_LINKAGE SI_SHORT_DTV_CHANNEL_INFO * MApp_SI_Get_PastVirtualCh () ;
EXTERN_C_LINKAGE SI_SHORT_DTV_CHANNEL_INFO * CppTest_Stub_MApp_SI_Get_PastVirtualCh (void)
{
    return (SI_SHORT_DTV_CHANNEL_INFO *)0;
}

/** User stub definition for function: JPEG_Event MApi_JPEG_GetJPDEventFlag(void) */
EXTERN_C_LINKAGE JPEG_Event MApi_JPEG_GetJPDEventFlag () ;
EXTERN_C_LINKAGE JPEG_Event CppTest_Stub_MApi_JPEG_GetJPDEventFlag (void)
{
    return E_JPEG_EVENT_DEC_DONE;
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_RecordOff(MsCEC_DEVICELA) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_RecordOff (MsCEC_DEVICELA dst_address) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_RecordOff (MsCEC_DEVICELA dst_address)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: void MDrv_COPRO_Init_Front(void) */
EXTERN_C_LINKAGE void MDrv_COPRO_Init_Front () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_COPRO_Init_Front (void)
{
}

/** User stub definition for function: void MApi_AUDIO_ExitAudioSystem(void) */
EXTERN_C_LINKAGE void MApi_AUDIO_ExitAudioSystem () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_ExitAudioSystem (void)
{
}

/** User stub definition for function: void MApi_AUDIO_WritePreInitTable(void) */
EXTERN_C_LINKAGE void MApi_AUDIO_WritePreInitTable () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_WritePreInitTable (void)
{
}

/** User stub definition for function: PM_Result MDrv_PM_SetDbgLevel(PM_DbgLv) */
EXTERN_C_LINKAGE PM_Result MDrv_PM_SetDbgLevel (PM_DbgLv eLevel) ;
EXTERN_C_LINKAGE PM_Result CppTest_Stub_MDrv_PM_SetDbgLevel (PM_DbgLv eLevel)
{
    return E_PM_FAIL;
}

/** User stub definition for function: void MApi_XC_Auto_AutoOffset(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_Auto_AutoOffset (MS_BOOL bEnable, MS_BOOL bIsYPbPrFlag) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Auto_AutoOffset (MS_BOOL bEnable, MS_BOOL bIsYPbPrFlag)
{
}

/** User stub definition for function: void MApi_AUDIO_SetADOutputMode(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetADOutputMode (MS_U8 out_mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetADOutputMode (MS_U8 out_mode)
{
}

/** User stub definition for function: void MApp_SI_Force_NIT_Parse(void) */
EXTERN_C_LINKAGE void MApp_SI_Force_NIT_Parse () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Force_NIT_Parse (void)
{
}

/** User stub definition for function: U16 MApp_SI_GetFileInServiceID(void) */
EXTERN_C_LINKAGE U16 MApp_SI_GetFileInServiceID () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_SI_GetFileInServiceID (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_RegisterGetBMPCB(MS_U32 (*)(MS_S16, GFX_BitmapInfo *)) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_RegisterGetBMPCB (MS_U32 (* fpGFX_CB)(MS_S16, GFX_BitmapInfo *)) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_RegisterGetBMPCB (MS_U32 (* fpGFX_CB)(MS_S16, GFX_BitmapInfo *))
{
    return GFX_FAIL;
}

/** User stub definition for function: void msAPI_CI_MMIDoneEvent(U8) */
EXTERN_C_LINKAGE void msAPI_CI_MMIDoneEvent (U8 u8Evt) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_MMIDoneEvent (U8 u8Evt)
{
}

/** User stub definition for function: void MApi_XC_ACE_PicSetContrast(MS_BOOL, MS_BOOL, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PicSetContrast (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, MS_U8 u8Contrast) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PicSetContrast (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, MS_U8 u8Contrast)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetWinDispPosition(MS_U8, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetWinDispPosition (MS_U8 gId, MS_U16 dispX, MS_U16 dispY) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetWinDispPosition (MS_U8 gId, MS_U16 dispX, MS_U16 dispY)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: BOOLEAN MApp_SI_CompareCIContentByte(U8, U8 *, U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_CompareCIContentByte (U8 u8ContentByte, U8 * pu8LabelChar, U8 u8LabelLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_CompareCIContentByte (U8 u8ContentByte, U8 * pu8LabelChar, U8 u8LabelLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_AUDIO_HDMI_Monitor(void) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_HDMI_Monitor () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_HDMI_Monitor (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_GE_ClearFrameBufferByWord(MS_PHYADDR, MS_U32, MS_U32) */
EXTERN_C_LINKAGE void msAPI_GE_ClearFrameBufferByWord (MS_PHYADDR StrAddr, MS_U32 length, MS_U32 ClearValue) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_GE_ClearFrameBufferByWord (MS_PHYADDR StrAddr, MS_U32 length, MS_U32 ClearValue)
{
}

/** User stub definition for function: U8 * msAPI_CI_AppMmiGetBufPtr(void) */
EXTERN_C_LINKAGE U8 * msAPI_CI_AppMmiGetBufPtr () ;
EXTERN_C_LINKAGE U8 * CppTest_Stub_msAPI_CI_AppMmiGetBufPtr (void)
{
    return (U8 *)0;
}

/** User stub definition for function: MS_S16 MApi_XC_Mux_OnOffPeriodicHandler(INPUT_SOURCE_TYPE_t, MS_BOOL) */
EXTERN_C_LINKAGE MS_S16 MApi_XC_Mux_OnOffPeriodicHandler (INPUT_SOURCE_TYPE_t src, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_S16 CppTest_Stub_MApi_XC_Mux_OnOffPeriodicHandler (INPUT_SOURCE_TYPE_t src, MS_BOOL bEnable)
{
    return (short)0;
}

/** User stub definition for function: MS_U16 MApi_JPEG_GetAlignedPitch(void) */
EXTERN_C_LINKAGE MS_U16 MApi_JPEG_GetAlignedPitch () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_JPEG_GetAlignedPitch (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsIFrameFound(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsIFrameFound () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsIFrameFound (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: E_MUX_INPUTPORT MApi_XC_Mux_GetHDMIPort(INPUT_SOURCE_TYPE_t) */
EXTERN_C_LINKAGE E_MUX_INPUTPORT MApi_XC_Mux_GetHDMIPort (INPUT_SOURCE_TYPE_t src) ;
EXTERN_C_LINKAGE E_MUX_INPUTPORT CppTest_Stub_MApi_XC_Mux_GetHDMIPort (INPUT_SOURCE_TYPE_t src)
{
    return INPUT_PORT_NONE_PORT;
}

/** User stub definition for function: BOOLEAN msAPI_CI_CC_GetURI(U8 *, U8 *, U8 *, U8 *, U8 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CC_GetURI (U8 * pu8RCT, U8 * pu8EMI, U8 * pu8APS, U8 * pu8ICT, U8 * pu8RL) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CC_GetURI (U8 * pu8RCT, U8 * pu8EMI, U8 * pu8APS, U8 * pu8ICT, U8 * pu8RL)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SIF_IsPALType(AUDIO_SIF_PAL_TYPE) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SIF_IsPALType (AUDIO_SIF_PAL_TYPE pal_type) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SIF_IsPALType (AUDIO_SIF_PAL_TYPE pal_type)
{
    return (unsigned char)0;
}

/** User stub definition for function: MW_DVB_TARGET_REGION_INFO * MApp_SI_GetTargetRegionNameInfo(void) */
EXTERN_C_LINKAGE MW_DVB_TARGET_REGION_INFO * MApp_SI_GetTargetRegionNameInfo () ;
EXTERN_C_LINKAGE MW_DVB_TARGET_REGION_INFO * CppTest_Stub_MApp_SI_GetTargetRegionNameInfo (void)
{
    return (MW_DVB_TARGET_REGION_INFO *)0;
}

/** User stub definition for function: SAR_Result MDrv_SAR_Config(SAR_RegCfg *) */
EXTERN_C_LINKAGE SAR_Result MDrv_SAR_Config (SAR_RegCfg * pSARRegCfg) ;
EXTERN_C_LINKAGE SAR_Result CppTest_Stub_MDrv_SAR_Config (SAR_RegCfg * pSARRegCfg)
{
    return E_SAR_FAIL;
}

/** User stub definition for function: U8 msAPI_CI_AppMmi_Get_SSM(void) */
EXTERN_C_LINKAGE U8 msAPI_CI_AppMmi_Get_SSM () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_CI_AppMmi_Get_SSM (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Dmx_Init_OAD(MS_DMX_NOTIFY *) */
EXTERN_C_LINKAGE void MApp_Dmx_Init_OAD (MS_DMX_NOTIFY * psNotify) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_Init_OAD (MS_DMX_NOTIFY * psNotify)
{
}

/** User stub definition for function: void MApi_AUDIO_SetSurroundXB(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSurroundXB (MS_U8 mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSurroundXB (MS_U8 mode)
{
}

/** User stub definition for function: void MApi_AUDIO_SetSurroundXA(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSurroundXA (MS_U8 mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSurroundXA (MS_U8 mode)
{
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Resume(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Resume () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Resume (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SetSurroundXK(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSurroundXK (MS_U8 mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSurroundXK (MS_U8 mode)
{
}

/** User stub definition for function: MS_BOOL MDrv_AUDIO_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AUDIO_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AUDIO_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_PicSetHue(MS_BOOL, MS_BOOL, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PicSetHue (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, MS_U8 u8Hue) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PicSetHue (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, MS_U8 u8Hue)
{
}

/** User stub definition for function: E_XC_ACE_RESULT MApi_XC_ACE_SkipWaitVsync( MS_BOOL ,MS_BOOL ) */
EXTERN_C_LINKAGE E_XC_ACE_RESULT MApi_XC_ACE_SkipWaitVsync( MS_BOOL eWindow,MS_BOOL bIsSkipWaitVsyn);
EXTERN_C_LINKAGE E_XC_ACE_RESULT CppTest_Stub_MApi_XC_ACE_SkipWaitVsync( MS_BOOL eWindow,MS_BOOL bIsSkipWaitVsyn)
{
    return E_XC_ACE_OK;
}

/** User stub definition for function: MS_BOOL MDrv_ACE_GetSkipWaitVsync( MS_BOOL ) */
EXTERN_C_LINKAGE MS_BOOL MDrv_ACE_GetSkipWaitVsync( MS_BOOL bScalerWin);
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_ACE_GetSkipWaitVsync( MS_BOOL bScalerWin)
{
    return TRUE;
}

/** User stub definition for function: MLOAD_TYPE MApi_XC_MLoad_GetStatus(void) */
EXTERN_C_LINKAGE MLOAD_TYPE MApi_XC_MLoad_GetStatus(void);
EXTERN_C_LINKAGE MLOAD_TYPE CppTest_Stub_MApi_XC_MLoad_GetStatus(void)
{
    return E_MLOAD_ENABLED;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_GetIsEnable(MS_BOOL *) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_GetIsEnable (MS_BOOL * pbEnable) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_GetIsEnable (MS_BOOL * pbEnable)
{
    if( CppTest_IsCurrentTestCase("TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True") )
    {
        *pbEnable = 1;
        return E_MVOP_OK;
    }

    return E_MVOP_OK;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_RegisterFBFmtCB(MS_U32 (*)(MS_U16, MS_U32, MS_U16)) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_RegisterFBFmtCB (MS_U32 (* fpGOP_CB)(MS_U16, MS_U32, MS_U16)) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_RegisterFBFmtCB (MS_U32 (* fpGOP_CB)(MS_U16, MS_U32, MS_U16))
{
    return GOP_API_FAIL;
}

/** User stub definition for function: U32 MDrv_GetUsbBlockNum_Port2(U8) */
EXTERN_C_LINKAGE U32 MDrv_GetUsbBlockNum_Port2 (U8 lun) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MDrv_GetUsbBlockNum_Port2 (U8 lun)
{
    return 0UL;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SPDIF_ChannelStatus_CTRL(AUDIO_SPDIF_CS_TYPE, AUDIO_SPDIF_CS_TYPE_STATUS) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SPDIF_ChannelStatus_CTRL (AUDIO_SPDIF_CS_TYPE cs_mode, AUDIO_SPDIF_CS_TYPE_STATUS status) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SPDIF_ChannelStatus_CTRL (AUDIO_SPDIF_CS_TYPE cs_mode, AUDIO_SPDIF_CS_TYPE_STATUS status)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_APIXC_ReturnValue MApi_XC_EnableIPAutoNoSignal(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE E_APIXC_ReturnValue MApi_XC_EnableIPAutoNoSignal (MS_BOOL bEnable, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE E_APIXC_ReturnValue CppTest_Stub_MApi_XC_EnableIPAutoNoSignal (MS_BOOL bEnable, SCALER_WIN eWindow)
{
    return E_APIXC_RET_FAIL;
}

/** User stub definition for function: void MApp_SI_AddNewTSService(void) */
EXTERN_C_LINKAGE void MApp_SI_AddNewTSService () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_AddNewTSService (void)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetAlpha_ARGB1555(MS_U8) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetAlpha_ARGB1555 (MS_U8 coef) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetAlpha_ARGB1555 (MS_U8 coef)
{
    return GFX_FAIL;
}

/** User stub definition for function: void DRV_VIF_Handler(BOOLEAN) */
EXTERN_C_LINKAGE void DRV_VIF_Handler (BOOLEAN bAutoScan) ;
EXTERN_C_LINKAGE void CppTest_Stub_DRV_VIF_Handler (BOOLEAN bAutoScan)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_Enable_3D_LR_Sbs2Line(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_Enable_3D_LR_Sbs2Line (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_Enable_3D_LR_Sbs2Line (MS_BOOL bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MDrv_Sys_IsCodeInSPI(void) */
EXTERN_C_LINKAGE U8 MDrv_Sys_IsCodeInSPI () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_Sys_IsCodeInSPI (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MDrv_Usb_Device_Enum_Port2(void) */
EXTERN_C_LINKAGE BOOLEAN MDrv_Usb_Device_Enum_Port2 () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_Usb_Device_Enum_Port2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_XC_PCMonitor_GetSyncStatus(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_PCMonitor_GetSyncStatus (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_PCMonitor_GetSyncStatus (SCALER_WIN eWindow)
{
    if( CppTest_IsCurrentTestCase("TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True") )
    {
        return XC_MD_INTERLACE_BIT;
    }

    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_Mux_SourceMonitor(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_Mux_SourceMonitor (MS_BOOL bRealTimeMonitorOnly) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Mux_SourceMonitor (MS_BOOL bRealTimeMonitorOnly)
{
}

/** User stub definition for function: void __MDrv_Write4Byte(U32, U32) */
EXTERN_C_LINKAGE BOOL btest_msAPI_Timer_delayus = FALSE;
EXTERN_C_LINKAGE void __MDrv_Write4Byte (U32 u32Reg, U32 u32Val) ;
EXTERN_C_LINKAGE void CppTest_Stub___MDrv_Write4Byte (U32 u32Reg, U32 u32Val)
{
    if( CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_delayus") )
    {
    	btest_msAPI_Timer_delayus = TRUE;
    }
}

/** User stub definition for function: BOOLEAN MApp_SI_SetTimeZone(EN_SI_TIMEZONE) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_SetTimeZone (EN_SI_TIMEZONE eTimeZone) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_SetTimeZone (EN_SI_TIMEZONE eTimeZone)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_AVD_IsSyncLocked(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AVD_IsSyncLocked () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AVD_IsSyncLocked (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_JPEG_GetScaleDownFactor(void) */
EXTERN_C_LINKAGE MS_U8 MApi_JPEG_GetScaleDownFactor () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_JPEG_GetScaleDownFactor (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Pvr_Pid_Open(MS_U32, MS_U8 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Pvr_Pid_Open (MS_U32 Pid, MS_U8 * pu8DmxId) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Pvr_Pid_Open (MS_U32 Pid, MS_U8 * pu8DmxId)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApi_AUDIO_SetCommand(En_DVB_decCmdType) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetCommand (En_DVB_decCmdType enDecComamnd) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetCommand (En_DVB_decCmdType enDecComamnd)
{
}

/** User stub definition for function: void MDrv_VE_Set_TestPattern(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_VE_Set_TestPattern (MS_BOOL bEn) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_Set_TestPattern (MS_BOOL bEn)
{
}

/** User stub definition for function: void MDrv_HDMI_pkt_reset(HDMI_REST_t) */
EXTERN_C_LINKAGE void MDrv_HDMI_pkt_reset (HDMI_REST_t breset) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_HDMI_pkt_reset (HDMI_REST_t breset)
{
}

/** User stub definition for function: BOOLEAN MApp_EIT_GetPfString(U8, U8 *, U16, U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_EIT_GetPfString (U8 sec, U8 * pdest, U16 u16Shift, U16 u16Size) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_EIT_GetPfString (U8 sec, U8 * pdest, U16 u16Shift, U16 u16Size)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SIF_GetAudioStatus(AUDIOSTATUS *) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SIF_GetAudioStatus (AUDIOSTATUS * eAudioStatus) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SIF_GetAudioStatus (AUDIOSTATUS * eAudioStatus)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_AudioCmdHandler_case_IS_ATV_DECODE_OK_GetAudioStatusFail"))
  {
    return (unsigned char)0;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_AudioCmdHandler_case_IS_ATV_DECODE_OK_OK"))
  {
    *eAudioStatus = E_STATE_AUDIO_PRIMARY_CARRIER;
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: MS_U32 MApi_AUDIO_GetMpegInfo(Audio_MPEG_infoType) */
EXTERN_C_LINKAGE MS_U32 MApi_AUDIO_GetMpegInfo (Audio_MPEG_infoType infoType) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_AUDIO_GetMpegInfo (Audio_MPEG_infoType infoType)
{
    return 0UL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_GetControl(VDEC_User_Cmd, MS_U32 *) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_GetControl (VDEC_User_Cmd cmd_id, MS_U32 * param) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_GetControl (VDEC_User_Cmd cmd_id, MS_U32 * param)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Video_test_msAPI_VID_IsNeedFrameBufferLessMode_Yes"))
	{
		*param = 1000000;
		return E_VDEC_OK;
	}
    return E_VDEC_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_DWIN_Init(void) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_DWIN_Init () ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_DWIN_Init (void)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_MiuSwitch(MS_U8) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_MiuSwitch (MS_U8 u8Miu) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_MiuSwitch (MS_U8 u8Miu)
{
    return E_MVOP_OK;
}

/** User stub definition for function: void MApi_XC_GetDispWinFromReg(MS_WINDOW_TYPE *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_GetDispWinFromReg (MS_WINDOW_TYPE * pstDspwin, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GetDispWinFromReg (MS_WINDOW_TYPE * pstDspwin, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MDrv_PWM_Div(PWM_ChNum, MS_U16) */
EXTERN_C_LINKAGE void MDrv_PWM_Div (PWM_ChNum u8IndexPWM, MS_U16 u16DivPWM) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PWM_Div (PWM_ChNum u8IndexPWM, MS_U16 u16DivPWM)
{
}

/** User stub definition for function: void MApi_XC_ACE_PicSetSaturation(MS_BOOL, MS_BOOL, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PicSetSaturation (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, MS_U8 u8Saturation) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PicSetSaturation (MS_BOOL eWindow, MS_BOOL bUseYUVSpace, MS_U8 u8Saturation)
{
}

/** User stub definition for function: MS_U16 MApi_JPEG_GetOriginalWidth(void) */
EXTERN_C_LINKAGE MS_U16 MApi_JPEG_GetOriginalWidth () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_JPEG_GetOriginalWidth (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_StepDisp(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_StepDisp () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_StepDisp (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: int rand(void) */
EXTERN_C_LINKAGE int rand () ;
EXTERN_C_LINKAGE int CppTest_Stub_rand (void)
{
    return 0;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetCurrentGOP(void) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetCurrentGOP () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetCurrentGOP (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MApp_SI_GetString(U8 *, U8, U8 *, U8, U8) */
EXTERN_C_LINKAGE U8 MApp_SI_GetString (U8 * pu8Dest, U8 u8DestBufLen, U8 * pu8Src, U8 u8SrcBufLen, U8 ControlCodes) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_SI_GetString (U8 * pu8Dest, U8 u8DestBufLen, U8 * pu8Src, U8 u8SrcBufLen, U8 ControlCodes)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_CC_SaveKeyToFlash(MS_CI_KEY_SETTING *, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CC_SaveKeyToFlash (MS_CI_KEY_SETTING * pstCiKeySetting, BOOLEAN bEnableEncrypt) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CC_SaveKeyToFlash (MS_CI_KEY_SETTING * pstCiKeySetting, BOOLEAN bEnableEncrypt)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_JPEG_Exit(void) */
EXTERN_C_LINKAGE void MApi_JPEG_Exit () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_Exit (void)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_SYS_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SYS_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SYS_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MApp_EIT_GetCurParentControl(void) */
EXTERN_C_LINKAGE U8 MApp_EIT_GetCurParentControl () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_EIT_GetCurParentControl (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U16 MApp_SI_Get_PMT_PID(void) */
EXTERN_C_LINKAGE U16 MApp_SI_Get_PMT_PID () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_SI_Get_PMT_PID (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_BOOL MApi_SWI2C_WriteBytes(MS_U16, MS_U8, MS_U8 *, MS_U16, MS_U8 *) */

EXTERN_C_LINKAGE MS_BOOL MApi_SWI2C_WriteBytes (MS_U16 u16BusNumSlaveID, MS_U8 u8addrcount, MS_U8 * pu8addr, MS_U16 u16size, MS_U8 * pu8data) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SWI2C_WriteBytes (MS_U16 u16BusNumSlaveID, MS_U8 u8addrcount, MS_U8 * pu8addr, MS_U16 u16size, MS_U8 * pu8data)
{
    return (MS_BOOL)0;
}


/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SwitchGOP(MS_U8) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SwitchGOP (MS_U8 u8GOP) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SwitchGOP (MS_U8 u8GOP)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Filein_CMDQ_GetEmptyNum(MS_U32 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Filein_CMDQ_GetEmptyNum (MS_U32 * pu32EmptySlot) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Filein_CMDQ_GetEmptyNum (MS_U32 * pu32EmptySlot)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: BOOLEAN MApp_SI_GetServiceGuidanceInfoTextWithIDs(U16, U16, U16, U16 *, U16 *, U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_GetServiceGuidanceInfoTextWithIDs (U16 u16OnId, U16 u16TsId, U16 u16SrvId, U16 * pu16DestBuf, U16 * pu16DestRetLen, U16 u16MaxDestLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_GetServiceGuidanceInfoTextWithIDs (U16 u16OnId, U16 u16TsId, U16 u16SrvId, U16 * pu16DestBuf, U16 * pu16DestRetLen, U16 u16MaxDestLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_DMX_Filein_IsPause(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_DMX_Filein_IsPause () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_DMX_Filein_IsPause (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_Set_NR(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_Set_NR (MS_BOOL bEn, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Set_NR (MS_BOOL bEn, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MsOS_FlushMemory(void) */
EXTERN_C_LINKAGE void MsOS_FlushMemory () ;
EXTERN_C_LINKAGE void CppTest_Stub_MsOS_FlushMemory (void)
{
}

/** User stub definition for function: void MApi_XC_SetFreeRunTiming(void) */
EXTERN_C_LINKAGE void MApi_XC_SetFreeRunTiming () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetFreeRunTiming (void)
{
}

/** User stub definition for function: void MApi_AUDIO_SPDIF_SetSCMS(MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SPDIF_SetSCMS (MS_U8 C_bit_en, MS_U8 L_bit_en) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SPDIF_SetSCMS (MS_U8 C_bit_en, MS_U8 L_bit_en)
{
}

/** User stub definition for function: void MApi_XC_SetFrameColor(MS_U32) */
EXTERN_C_LINKAGE void MApi_XC_SetFrameColor (MS_U32 u32aRGB) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetFrameColor (MS_U32 u32aRGB)
{
}

/** User stub definition for function: VDEC_Result MApi_VDEC_SetAVSyncFreerunThreshold(MS_U32) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_SetAVSyncFreerunThreshold (MS_U32 u32Threshold) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_SetAVSyncFreerunThreshold (MS_U32 u32Threshold)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MDrv_DMX_TTX_SetCB(DMX_CB_FN) */
EXTERN_C_LINKAGE void MDrv_DMX_TTX_SetCB (DMX_CB_FN fn) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DMX_TTX_SetCB (DMX_CB_FN fn)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_HC_GetTuneInfo(U16 *, U16 *, U16 *, U16 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_HC_GetTuneInfo (U16 * pu16NetworkID, U16 * pu16OriginalNetworkID, U16 * pu16TransportStreamID, U16 * pu16ServiceID) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_HC_GetTuneInfo (U16 * pu16NetworkID, U16 * pu16OriginalNetworkID, U16 * pu16TransportStreamID, U16 * pu16ServiceID)
{
    return (unsigned char)0;
}

/** User stub definition for function: XC_PCMONITOR_STATUS MApi_XC_PCMonitor_GetCurrentState(SCALER_WIN) */
EXTERN_C_LINKAGE XC_PCMONITOR_STATUS MApi_XC_PCMonitor_GetCurrentState (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE XC_PCMONITOR_STATUS CppTest_Stub_MApi_XC_PCMonitor_GetCurrentState (SCALER_WIN eWindow)
{
    if( CppTest_IsCurrentTestCase("TestSuite_apiXC_Cus_test_mvideo_sc_is_interlace_Dtv_True") )
    {
        return E_XC_PCMONITOR_STABLE_SYNC;
    }

    return E_XC_PCMONITOR_STABLE_NOSYNC;
}

/** User stub definition for function: void MDrv_MVOP_SetMonoMode(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_MVOP_SetMonoMode (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_MVOP_SetMonoMode (MS_BOOL bEnable)
{
}

/** User stub definition for function: void MApp_SI_Force_SDT_Parse(void) */
EXTERN_C_LINKAGE void MApp_SI_Force_SDT_Parse () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Force_SDT_Parse (void)
{
}

/** User stub definition for function: void ProcessTimer0Isr(MHAL_SavedRegisters *, U32) */
EXTERN_C_LINKAGE void ProcessTimer0Isr (MHAL_SavedRegisters * pHalReg, U32 vector) ;
EXTERN_C_LINKAGE void CppTest_Stub_ProcessTimer0Isr (MHAL_SavedRegisters * pHalReg, U32 vector)
{
}

/** User stub definition for function: MS_BOOL mapi_mhl_AutoSwitchHandler(MS_BOOL, MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL mapi_mhl_AutoSwitchHandler (MS_BOOL bReset, MS_U8 * ucCbusPath) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_mapi_mhl_AutoSwitchHandler (MS_BOOL bReset, MS_U8 * ucCbusPath)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ADC_SetPcClock(MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_ADC_SetPcClock (MS_U16 u16Clock) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_SetPcClock (MS_U16 u16Clock)
{
}

/** User stub definition for function: E_DDC2BI_ReturnValue MDrv_DDC2BI_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE E_DDC2BI_ReturnValue MDrv_DDC2BI_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE E_DDC2BI_ReturnValue CppTest_Stub_MDrv_DDC2BI_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_DDC2BI_RET_FAIL;
}

/** User stub definition for function: MS_U16 MDrv_VBI_GetWSS_Data(void) */
EXTERN_C_LINKAGE MS_U16 MDrv_VBI_GetWSS_Data () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MDrv_VBI_GetWSS_Data (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: const VE_DrvInfo * MDrv_VE_GetInfo(void) */
EXTERN_C_LINKAGE const VE_DrvInfo * MDrv_VE_GetInfo () ;
EXTERN_C_LINKAGE const VE_DrvInfo * CppTest_Stub_MDrv_VE_GetInfo (void)
{
    return (const VE_DrvInfo *)0;
}

/** User stub definition for function: void MApi_XC_Mux_Init(void (*)(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *)) */
EXTERN_C_LINKAGE void MApi_XC_Mux_Init (void (* input_source_to_input_port)(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *)) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_Mux_Init (void (* input_source_to_input_port)(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *))
{
}

/** User stub definition for function: void MApi_XC_GetDEWindow(MS_WINDOW_TYPE *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_GetDEWindow (MS_WINDOW_TYPE * psWin, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GetDEWindow (MS_WINDOW_TYPE * psWin, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventSeries(EventIndex, MW_EN_EPG_CRID_SEARCH, U8 *, U16 *, EventIndex *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetEventSeries (EventIndex event, MW_EN_EPG_CRID_SEARCH enSearch, U8 * pPCN, U16 * pServiceID, EventIndex * pEvent) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetEventSeries (EventIndex event, MW_EN_EPG_CRID_SEARCH enSearch, U8 * pPCN, U16 * pServiceID, EventIndex * pEvent)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_CreateWin(MS_U16, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_CreateWin (MS_U16 width, MS_U16 height, MS_U16 fbFmt) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_CreateWin (MS_U16 width, MS_U16 height, MS_U16 fbFmt)
{
    return (unsigned char)0;
}

/** User stub definition for function: U32 msAPI_Subtitle_GetDemuxBuffer(void) */
EXTERN_C_LINKAGE U32 msAPI_Subtitle_GetDemuxBuffer () ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Subtitle_GetDemuxBuffer (void)
{
    return 0UL;
}

/** User stub definition for function: MS_U8 MApi_CEC_GetMsgCnt(void) */
EXTERN_C_LINKAGE MS_U8 MApi_CEC_GetMsgCnt () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_CEC_GetMsgCnt (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_MVOP_SetTileFormat(MVOP_TileFormat) */
EXTERN_C_LINKAGE MS_BOOL MDrv_MVOP_SetTileFormat (MVOP_TileFormat eTileFmt) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_MVOP_SetTileFormat (MVOP_TileFormat eTileFmt)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Epg_MoveSrvBuffer(U16, U16) */
EXTERN_C_LINKAGE void MApp_Epg_MoveSrvBuffer (U16 u16FromIndex, U16 u16ToIndex) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Epg_MoveSrvBuffer (U16 u16FromIndex, U16 u16ToIndex)
{
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_ReqCECVersion(MsCEC_DEVICELA) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_ReqCECVersion (MsCEC_DEVICELA dst_address) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_ReqCECVersion (MsCEC_DEVICELA dst_address)
{
    return E_CEC_FEATURE_ABORT;
}

//global variables
U32 g_au32FileBufPtrTemp[20]={0};
U8 	g_au8FileBufPtrTemp_Parser[600] = {0};

/** User stub definition for function: MS_U32 MsOS_PA2KSEG1(MS_U32) */
EXTERN_C_LINKAGE MS_U32 MsOS_PA2KSEG1 (MS_U32 addr) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_PA2KSEG1 (MS_U32 addr)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration"))
  {
//    return (MS_U32)&addr;
	  return (MS_U32)&g_au32FileBufPtrTemp;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_CalculateMP3CBRDuration_ID3V2"))
  {
	  return (MS_U32)&g_au32FileBufPtrTemp;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_SearchFirstFrame_case1"))
  {
//    return (MS_U32)&addr;
	  return (MS_U32)&g_au32FileBufPtrTemp;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ParseFlac_StreamInfo"))
  {
    U8 u8FileBufPtrTemp[34]={0x10,0x00,0x10,0x00,
                             0x00,0x00,0x0E,0x00,
                             0x38,0x64,0x0A,0xC4,
                             0x42,0xF0,0x00,0x79,
                             0xD0,0xAC,0x6A,0x37,
                             0x12,0x69,0x5E,0x62,
                             0x27,0x8B,0x8D,0x8A,
                             0x36,0xAC,0x6C,0xF5,
                             0x3E,0xA7};

    memcpy(g_au8FileBufPtrTemp_Parser,u8FileBufPtrTemp,sizeof(u8FileBufPtrTemp));
    return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ParseFlac_SeekTable_case1"))
  {
    U8 u8FileBufPtrTemp[34]={0x10,0x00,0x10,0x00,
                             0x00,0x00,0x0E,0x00,
                             0x38,0x64,0x0A,0xC4,
                             0x42,0xF0,0x00,0x79,
                             0xD0,0xAC,0x6A,0x37,
                             0x12,0x69,0x5E,0x62,
                             0x27,0x8B,0x8D,0x8A,
                             0x36,0xAC,0x6C,0xF5,
                             0x3E,0xA7};

    memcpy(g_au8FileBufPtrTemp_Parser,u8FileBufPtrTemp,sizeof(u8FileBufPtrTemp));
    return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Flac_CollectInfo_case2"))
  {
    U8 u8FileBufPtrTemp[4]={0x80,0x00,0x00,0x22};

    memcpy(g_au8FileBufPtrTemp_Parser,u8FileBufPtrTemp,sizeof(u8FileBufPtrTemp));
    return (MS_U32)&g_au8FileBufPtrTemp_Parser;

  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Wav_CollectInfo_case1"))
  {
    U8 u8FileBufPtrTemp[44]={0x52,0x49,0x46,0x46,
                            0xC7,0x11,0x2E,0x03,
                            0x57,0x41,0x56,0x45,
                            0x66,0x6D,0x74,0x20,
                            0x10,0x00,0x00,0x00,
                            0x01,0x00,0x02,0x00,
                            0x44,0xAC,0x00,0x00,
                            0x10,0xB1,0x02,0x00,
                            0x04,0x00,0x10,0x00,
                            0x64,0x61,0x74,0x61,
		0x10,0x10,0x2E,0x03};

    memcpy(g_au8FileBufPtrTemp_Parser,u8FileBufPtrTemp,sizeof(u8FileBufPtrTemp));
    return (MS_U32)&g_au8FileBufPtrTemp_Parser;

  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case4"))
  {
    //U8 u8FileBufPtrTemp[3000];
    //return (MS_U32)&u8FileBufPtrTemp;
    return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_M4AParser_Get_AAC_Info_case1"))
  {
//	    U8 u8FileBufPtrTemp[3000];
//	    return (MS_U32)&u8FileBufPtrTemp;

	    return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_GetLyricTag"))
  {
	  typedef struct
	  {
	      U32 u32Time;
	      U16 u16LyricPos;
	  } Music_Lyric_Tag;

	  Music_Lyric_Tag LyricTagBaseTemp;
	  LyricTagBaseTemp.u32Time = 1;

	  memcpy(g_au8FileBufPtrTemp_Parser,(void *)&LyricTagBaseTemp, sizeof(Music_Lyric_Tag));
	  return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1"))
  {
//      U8 u8FileBufPtrTemp[3000];
//      return (MS_U32)&u8FileBufPtrTemp;
      return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_MP3TimeOffset_case1"))
  {
//      U8 u8FileBufPtrTemp[30];
//      return (MS_U32)&u8FileBufPtrTemp;
      return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case1"))
  {
//      U8 u8FileBufPtrTemp[30];
//      return (MS_U32)&u8FileBufPtrTemp;
      return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_AAC_Probe_case1"))
  {
//      U8 u8FileBufPtrTemp[30];
//      return (MS_U32)&u8FileBufPtrTemp;
      return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_M4A_Probe_case1"))
  {
	  //
	  //U32 g_au32FileBufPtrTemp[3]={0};
	  //U8 	g_au8FileBufPtrTemp_Parser[600] = {0};

      //U8 u8FileBufPtrTemp[30];
      return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_FLAC_Probe_case1"))
  {
//        U8 u8FileBufPtrTemp[30];
//        return (MS_U32)&u8FileBufPtrTemp;
	  return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_WAV_Probe_case1"))
  {
//        U8 u8FileBufPtrTemp[44];
//        return (MS_U32)&u8FileBufPtrTemp;
        return (MS_U32)&g_au8FileBufPtrTemp_Parser;
  }
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadPTime_case1"))
	{
//		return(MS_U32)&addr;
		return (MS_U32)&g_au32FileBufPtrTemp;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadPTime_case1"))
	{
//		U8 u8FileBufPtrTemp[300];
//		return (MS_U32)&u8FileBufPtrTemp;
		return (MS_U32)&g_au8FileBufPtrTemp_Parser;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_GetPayloadIndexFromIndexTable_case1"))
	{

	    U32 u32FileBufPtrTemp[10] = {3000,20,
									  6000,40,
									  6500,50,
									  9000,70,
									  15000,90 };


	    memcpy(g_au32FileBufPtrTemp,u32FileBufPtrTemp,sizeof(u32FileBufPtrTemp));
		return (MS_U32)&g_au32FileBufPtrTemp;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_CollectInfo_case1"))
	{
//		U8 u8FileBufPtrTemp[5000];
//		return (MS_U32)&u8FileBufPtrTemp;
		return (MS_U32)&g_au8FileBufPtrTemp_Parser;

	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_Probe_case1"))
	{
//		U8 u8FileBufPtrTemp[5000];
//		return (MS_U32)&u8FileBufPtrTemp;
		return (MS_U32)&g_au8FileBufPtrTemp_Parser;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u32TimeOver"))
	{
		g_au32FileBufPtrTemp[0] = 0;
		g_au32FileBufPtrTemp[1] = 4;
		return (MS_U32)&g_au32FileBufPtrTemp[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_Subtitle_BinarySearchBuffByCurTime_u23TimeLower"))
	{
		g_au32FileBufPtrTemp[0] = 0;
		g_au32FileBufPtrTemp[1] = 4;
		g_au32FileBufPtrTemp[2] = 4;
		return (MS_U32)&g_au32FileBufPtrTemp[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_ASCII"))
	{
		U8 au8temp[] = {0x31,0xd,0xa,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2c,0x30,0x30,0x30,0x20,0x2d,0x2d,0x3e,0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x33,0x2c,0x30,0x30,0x30,0xd,0xa,0x61,0xd,0xa,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		/*
		1
		00:00:01,000 --> 00:00:03,000
		a
		 */
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_Parser_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x31,0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x31,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x20,
				0x0,0x2d,0x0,0x2d,0x0,0x3e,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30
				,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,
				0x0,0x61,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		/*
		1
		00:00:01,000 --> 00:00:03,000
		a
		 */
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_ASCII"))
	{
		U8 au8temp[] = {0x5b,0x45,0x76,0x65,0x6e,0x74,0x73,0x5d,0xd,0xa,0x44,0x69,0x61,0x6c,0x6f,0x67,0x75,0x65,0x3a,0x20,0x30,0x2c,0x30,0x3a,0x30,0x30,0x3a,0x30,0x30,0x2e,0x30,0x30,0x2c,0x30,0x3a,0x30,0x30,0x3a,0x30,0x35,0x2e,0x30,0x30,0x2c,0x44,0x65,0x66,0x61,0x75,0x6c,0x74,0x2c,0x2c,0x30,0x30,0x30,0x30,0x2c,0x30,0x30,0x30,0x30,0x2c,0x30,0x30,0x30,0x30,0x2c,0x2c,0x30,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_Parser_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x5b,0x0,0x45,0x0,0x76,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,0x73,0x0,
				0x5d,0x0,0xd,0x0,0xa,0x0,0x44,0x0,0x69,0x0,0x61,0x0,0x6c,0x0,0x6f,0x0,
				0x67,0x0,0x75,0x0,0x65,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x2c,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x2e,0x0,0x30,0x0,
				0x30,0x0,0x2c,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x35,
				0x0,0x2e,0x0,0x30,0x0,0x30,0x0,0x2c,0x0,0x44,0x0,0x65,0x0,0x66,0x0,0x61,0x0,
				0x75,0x0,0x6c,0x0,0x74,0x0,0x2c,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x2c,0x0,0x30,0x0,
				0x30,0x0,0x30,0x0,0x30,0x0,0x2c,0x0,0x2c,0x0,0x61,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII"))
	{
		U8 au8temp[] = {0x31,0xd,0xa,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2c,0x30,0x30,0x30,0x20,0x2d,0x2d,0x3e,0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x33,0x2c,0x30,0x30,0x30,0xd,0xa,0x61,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		/*
		1
		00:00:01,000 --> 00:00:03,000
		a
		 */
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x31,0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x31,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x20,
				0x0,0x2d,0x0,0x2d,0x0,0x3e,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30
				,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,
				0x0,0x61,0x00, 0xd,0x0,0xa,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		/*
		1
		00:00:01,000 --> 00:00:03,000
		a
		 */
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII"))
	{
		U8 au8temp[] = {0x5b,0x45,0x76,0x65,0x6e,0x74,0x73,0x5d,0xd,0xa,0x44,0x69,0x61,0x6c,0x6f,0x67,0x75,0x65,0x3a,0x20,0x30,0x2c,0x30,0x3a,0x30,0x30,0x3a,0x30,0x30,0x2e,0x30,0x30,0x2c,0x30,0x3a,0x30,0x30,0x3a,0x30,0x35,0x2e,0x30,0x30,0x2c,0x44,0x65,0x66,0x61,0x75,0x6c,0x74,0x2c,0x2c,0x30,0x30,0x30,0x30,0x2c,0x30,0x30,0x30,0x30,0x2c,0x30,0x30,0x30,0x30,0x2c,0x2c,0x30,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x5b,0x0,0x45,0x0,0x76,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,0x73,0x0,
				0x5d,0x0,0xd,0x0,0xa,0x0,0x44,0x0,0x69,0x0,0x61,0x0,0x6c,0x0,0x6f,0x0,
				0x67,0x0,0x75,0x0,0x65,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x2c,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x2e,0x0,0x30,0x0,
				0x30,0x0,0x2c,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x35,
				0x0,0x2e,0x0,0x30,0x0,0x30,0x0,0x2c,0x0,0x44,0x0,0x65,0x0,0x66,0x0,0x61,0x0,
				0x75,0x0,0x6c,0x0,0x74,0x0,0x2c,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x2c,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x2c,0x0,0x30,0x0,
				0x30,0x0,0x30,0x0,0x30,0x0,0x2c,0x0,0x2c,0x0,0x61,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_ASCII"))
	{
		U8 au8temp[] = {0x7b,0x31,0x7d,0x7b,0x31,0x7d,0x32,0x35,0x2e,0x30,0x30,0x30,0xd,0xa,0x7b,0x32,0x35,0x7d,0x7b,0x35,0x30,0x7d,0x2a,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_Parser_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x7b,0x0,0x31,0x0,0x7d,0x0,0x7b,0x0,0x31,0x0,0x7d,0x0,0x32
				,0x0,0x35,0x0,0x2e,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x7b,0x0,0x32,
				0x0,0x35,0x0,0x7d,0x0,0x7b,0x0,0x35,0x0,0x30,0x0,0x7d,0x0,0x2a,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII"))
	{
		U8 au8temp[] = {0x3c,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,0x65,0x78,
				0x74,0x2f,0x63,0x73,0x73,0x22,0x3e,0x3c,0x21,0x2d,0x2d,0xd,0xa,0x2e,0x45,0x4e,0x43,0x43,0x20,0x7b,0x4e,0x61,0x6d,0x65,0x3a,0x20,0x22,0x45,0x6e,0x67,0x6c,0x69,0x73,0x68,0x22,0x3b,0x20,0x6c,0x61,0x6e,0x67,0x3a,0x20,0x65,0x6e,0x3b,0x7d,0xd,0xa,0x2e,0x46,0x52,0x43,0x43,0x20,0x7b,0x4e,0x61,0x6d,0x65,0x3a,0x20,0x22,0x46,0x72
				,0x65,0x6e,0x63,0x68,0x22,0x3b,0x20,0x6c,0x61,0x6e,0x67,0x3a,0x20,0x66,0x72,0x3b,0x7d,0xd,0xa,0x2d,0x2d,0x3e,0xd,0xa,0x3c,0x2f,0x53,0x54,0x59,0x4c,0x45,0x3e,0xd
				,0xa,0x3c,0x2f,0x48,0x45,0x41,0x44,0x3e,0xd,0xa,0x3c,0x53,0x59,0x4e,0x43,0x20,0x53,0x74,0x61,0x72,0x74,0x3d,0x30,0x30,0x30,0x30,0x3e,0xd,0xa,0x3c,0x50,0x20,0x43
				,0x6c,0x61,0x73,0x73,0x3d,0x45,0x4e,0x43,0x43,0x3e,0x31,0xd,0xa,0x3c,0x50,0x20,0x43,0x6c,0x61,0x73,0x73,0x3d,0x46,0x52,0x43,0x43,0x3e,0x31};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x3c,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x20,
				0x0,0x54,0x0,0x59,0x0,0x50,0x0,0x45,0x0,0x3d,0x0,0x22,0x0,0x74,0x0,0x65,0x0,0x78,
				0x0,0x74,0x0,0x2f,0x0,0x63,0x0,0x73,0x0,0x73,0x0,0x22,0x0,0x3e,0x0,0x3c,0x0,0x21,
				0x0,0x2d,0x0,0x2d,0x0,0xd,0x0,0xa,0x0,0x2e,0x0,0x45,0x0,0x4e,0x0,0x43,0x0,0x43,
				0x0,0x20,0x0,0x7b,0x0,0x4e,0x0,0x61,0x0,0x6d,0x0,0x65,0x0,0x3a,0x0,0x20,0x0,0x22,
				0x0,0x45,0x0,0x6e,0x0,0x67,0x0,0x6c,0x0,0x69,0x0,0x73,0x0,0x68,0x0,0x22,0x0,0x3b,
				0x0,0x20,0x0,0x6c,0x0,0x61,0x0,0x6e,0x0,0x67,0x0,0x3a,0x0,0x20,0x0,0x65,0x0,
				0x6e,0x0,0x3b,0x0,0x7d,0x0,0xd,0x0,0xa,0x0,0x2e,0x0,0x46,0x0,0x52,0x0,0x43,0x0,0x43,
				0x0,0x20,0x0,0x7b,0x0,0x4e,0x0,0x61,0x0,0x6d,0x0,0x65,0x0,0x3a,0x0,0x20,0x0,
				0x22,0x0,0x46,0x0,0x72,0x0,0x65,0x0,0x6e,0x0,0x63,0x0,0x68,0x0,0x22,0x0,0x3b,0x0,
				0x20,0x0,0x6c,0x0,0x61,0x0,0x6e,0x0,0x67,0x0,0x3a,0x0,0x20,0x0,0x66,0x0,0x72,0x0,
				0x3b,0x0,0x7d,0x0,0xd,0x0,0xa,0x0,0x2d,0x0,0x2d,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,
				0x0,0x2f,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x3e,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x2f,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x53,0x0,0x59,0x0,0x4e,0x0,0x43,0x0,0x20,0x0,0x53,0x0,0x74,0x0,0x61,
				0x0,0x72,0x0,0x74,0x0,0x3d,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x3e,0x0,0xd,
				0x0,0xa,0x0,0x3c,0x0,0x50,0x0,0x20,0x0,0x43,0x0,0x6c,0x0,0x61,0x0,0x73,0x0,0x73,
				0x0,0x3d,0x0,0x45,0x0,0x4e,0x0,0x43,0x0,0x43,0x0,0x3e,0x0,0x31,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x50,0x0,0x20,0x0,0x43,0x0,0x6c,0x0,0x61,0x0,0x73,0x0,0x73,0x0,0x3d,
				0x0,0x46,0x0,0x52,0x0,0x43,0x0,0x43,0x0,0x3e,0x0,0x31,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_ASCII_NoClassName"))
	{
		U8 au8temp[] = {0x3c,0x53,0x41,0x4d,0x49,0x3e,0xd,0xa,0x3c,0x48,0x45,0x41,0x44,0x3e,0xd,0xa,0x3c
				,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,0x65,0x78,0x74
				,0x2f,0x63,0x73,0x73,0x22,0x3e,0xd,0xa,0x3c,0x21,0x2d,0x2d,0xd,0xa,0x2d,0x2d,0x3e,
				0xd,0xa,0x3c,0x2f,0x53,0x54,0x59,0x4c,0x45,0x3e,0xd,0xa,0x3c,0x2f,0x48,0x45,0x41,
				0x44,0x3e,0xd,0xa,0x3c,0x42,0x4f,0x44,0x59,0x3e,0xd,0xa,0x3c,0x53,0x59,0x4e,0x43,
				0x20,0x53,0x74,0x61,0x72,0x74,0x3d,0x30,0x30,0x35,0x30,0x30,0x30,0x3e,0x3c,0x50,
				0x20,0x43,0x6c,0x61,0x73,0x73,0x3d,0x55,0x4e,0x4b,0x4e,0x4f,0x57,0x4e,0x43,0x43,
				0x3e,0x61};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_Parser_UNICODE_NoClassName"))
	{
		U8 au8temp[] = {0xff,0xfe,0x3c,0x0,0x53,0x0,0x41,0x0,0x4d,0x0,0x49,0x0,0x3e,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,
				0x3c,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x20,0x0,0x54,0x0,0x59,0x0,
				0x50,0x0,0x45,0x0,0x3d,0x0,0x22,0x0,0x74,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x2f,
				0x0,0x63,0x0,0x73,0x0,0x73,0x0,0x22,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x21,0x0,
				0x2d,0x0,0x2d,0x0,0xd,0x0,0xa,0x0,0x2d,0x0,0x2d,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,
				0x3c,0x0,0x2f,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x3e,0x0,0xd,0x0,
				0xa,0x0,0x3c,0x0,0x2f,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x42,0x0,0x4f,0x0,0x44,0x0,0x59,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,
				0x0,0x53,0x0,0x59,0x0,0x4e,0x0,0x43,0x0,0x20,0x0,0x53,0x0,0x74,0x0,0x61,0x0,0x72,
				0x0,0x74,0x0,0x3d,0x0,0x30,0x0,0x30,0x0,0x35,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x3e,
				0x0,0x3c,0x0,0x50,0x0,0x20,0x0,0x43,0x0,0x6c,0x0,0x61,0x0,0x73,0x0,0x73,0x0,
				0x3d,0x0,0x55,0x0,0x4e,0x0,0x4b,0x0,0x4e,0x0,0x4f,0x0,0x57,0x0,0x4e,0x0,0x43,0x0,
				0x43,0x0,0x3e,0x0,0x61,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII"))
	{
		U8 au8temp[] = {0x7b,0x31,0x7d,0x7b,0x31,0x7d,0x32,0x35,0x2e,0x30,0x30,0x30,0xd,0xa,0x7b,0x32,0x35,0x7d,0x7b,0x35,0x30,0x7d,0x2a,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE"))
	{
		U8 au8temp[] = {0xff,0xfe,0x7b,0x0,0x31,0x0,0x7d,0x0,0x7b,0x0,0x31,0x0,0x7d,0x0,0x32
				,0x0,0x35,0x0,0x2e,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x7b,0x0,0x32,
				0x0,0x35,0x0,0x7d,0x0,0x7b,0x0,0x35,0x0,0x30,0x0,0x7d,0x0,0x2a,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII"))
	{
/*
 <SAMI>
<HEAD>
<STYLE TYPE="text/css">
<!--
.UNKNOWNCC {Name:Unknown; lang:en-US; SAMIType:CC;}
-->
</STYLE>
</HEAD>
<BODY>
<SYNC Start=005000><P Class=UNKNOWNCC>OK
</BODY>
 */
		U8 au8temp[] = {0x3c,0x53,0x41,0x4d,0x49,0x3e,0xd,0xa,0x3c,0x48,0x45,0x41,0x44,0x3e,0xd,0xa,0x3c
				,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,0x65,0x78,0x74
				,0x2f,0x63,0x73,0x73,0x22,0x3e,0xd,0xa,0x3c,0x21,0x2d,0x2d,0xd,0xa,0x2e,0x55,0x4e,
				0x4b,0x4e,0x4f,0x57,0x4e,0x43,0x43,0x20,0x7b,0x4e,0x61,0x6d,0x65,0x3a,0x55,0x6e,
				0x6b,0x6e,0x6f,0x77,0x6e,0x3b,0x20,0x6c,0x61,0x6e,0x67,0x3a,0x65,0x6e,0x2d,0x55,
				0x53,0x3b,0x20,0x53,0x41,0x4d,0x49,0x54,0x79,0x70,0x65,0x3a,0x43,0x43,0x3b,0x7d,
				0xd,0xa,0x2d,0x2d,0x3e,0xd,0xa,0x3c,0x2f,0x53,0x54,0x59,0x4c,0x45,0x3e,0xd,0xa,
				0x3c,0x2f,0x48,0x45,0x41,0x44,0x3e,0xd,0xa,0x3c,0x42,0x4f,0x44,0x59,0x3e,0xd,0xa,
				0x3c,0x53,0x59,0x4e,0x43,0x20,0x53,0x74,0x61,0x72,0x74,0x3d,0x30,0x30,0x35,0x30,
				0x30,0x30,0x3e,0x3c,0x50,0x20,0x43,0x6c,0x61,0x73,0x73,0x3d,0x55,0x4e,0x4b,0x4e,
				0x4f,0x57,0x4e,0x43,0x43,0x3e,0x4f,0x4b,0xd,0xa,0x3c,0x2f,0x42,0x4f,0x44,0x59,
				0x3e};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE"))
	{
/*
 <SAMI>
<HEAD>
<STYLE TYPE="text/css">
<!--
.UNKNOWNCC {Name:Unknown; lang:en-US; SAMIType:CC;}
-->
</STYLE>
</HEAD>
<BODY>
<SYNC Start=005000><P Class=UNKNOWNCC>OK
</BODY>
 */
		U8 au8temp[] = {0xff,0xfe,0x3c,0x0,0x53,0x0,0x41,0x0,0x4d,0x0,0x49,0x0,0x3e,0x0,0xd,
				0x0,0xa,0x0,0x3c,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,
				0x3c,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x20,0x0,0x54,0x0,0x59,0x0,
				0x50,0x0,0x45,0x0,0x3d,0x0,0x22,0x0,0x74,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x2f,
				0x0,0x63,0x0,0x73,0x0,0x73,0x0,0x22,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x21,0x0,
				0x2d,0x0,0x2d,0x0,0xd,0x0,0xa,0x0,0x2e,0x0,0x55,0x0,0x4e,0x0,0x4b,0x0,0x4e,0x0,
				0x4f,0x0,0x57,0x0,0x4e,0x0,0x43,0x0,0x43,0x0,0x20,0x0,0x7b,0x0,0x4e,0x0,0x61,0x0,
				0x6d,0x0,0x65,0x0,0x3a,0x0,0x55,0x0,0x6e,0x0,0x6b,0x0,0x6e,0x0,0x6f,0x0,0x77,
				0x0,0x6e,0x0,0x3b,0x0,0x20,0x0,0x6c,0x0,0x61,0x0,0x6e,0x0,0x67,0x0,0x3a,0x0,0x65
				,0x0,0x6e,0x0,0x2d,0x0,0x55,0x0,0x53,0x0,0x3b,0x0,0x20,0x0,0x53,0x0,0x41,0x0,0x4d,
				0x0,0x49,0x0,0x54,0x0,0x79,0x0,0x70,0x0,0x65,0x0,0x3a,0x0,0x43,0x0,0x43,0x0,0x3b,
				0x0,0x7d,0x0,0xd,0x0,0xa,0x0,0x2d,0x0,0x2d,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,
				0x2f,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,
				0x3c,0x0,0x2f,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,
				0x3c,0x0,0x42,0x0,0x4f,0x0,0x44,0x0,0x59,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,
				0x53,0x0,0x59,0x0,0x4e,0x0,0x43,0x0,0x20,0x0,0x53,0x0,0x74,0x0,0x61,0x0,0x72,0x0,
				0x74,0x0,0x3d,0x0,0x30,0x0,0x30,0x0,0x35,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x3e,0x0,
				0x3c,0x0,0x50,0x0,0x20,0x0,0x43,0x0,0x6c,0x0,0x61,0x0,0x73,0x0,0x73,0x0,0x3d,
				0x0,0x55,0x0,0x4e,0x0,0x4b,0x0,0x4e,0x0,0x4f,0x0,0x57,0x0,0x4e,0x0,0x43,0x0,0x43,
				0x0,0x3e,0x0,0x4f,0x0,0x4b,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x2f,0x0,0x42,0x0,0x4f,
				0x0,0x44,0x0,0x59,0x0,0x3e};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_ASCII"))
	{
/*
 <TextSample sampleTime="00:00:01.000" xml:space="preserve">
a
 */
		U8 au8temp[] = {0x3c,0x53,0x41,0x4d,0x49,0x3e,0xd,0xa,0x3c,0x48,0x45,0x41,0x44,0x3e,0xd,0xa,0x3c
				,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,0x65,0x78,0x74
				,0x2f,0x63,0x73,0x73,0x22,0x3e,0xd,0xa,0x3c,0x21,0x2d,0x2d,0xd,0xa,0x3c,0x54,0x65,
				0x78,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x54,
				0x69,0x6d,0x65,0x3d,0x22,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2e,0x30,0x30,
				0x30,0x22,0x20,0x78,0x6d,0x6c,0x3a,0x73,0x70,0x61,0x63,0x65,0x3d,0x22,0x70,0x72,
				0x65,0x73,0x65,0x72,0x76,0x65,0x22,0x3e,0xd,0xa,0x61};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_Parser_UNICODE"))
	{
/*
 <TextSample sampleTime="00:00:01.000" xml:space="preserve">
a
 */
		U8 au8temp[] = {0xff,0xfe,0x3c,0x0,0x53,0x0,0x41,0x0,0x4d,0x0,0x49,0x0,0x3e,0x0,0xd,
				0x0,0xa,0x0,0x3c,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,
				0x3c,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,0x0,0x20,0x0,0x54,0x0,0x59,0x0,
				0x50,0x0,0x45,0x0,0x3d,0x0,0x22,0x0,0x74,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x2f,
				0x0,0x63,0x0,0x73,0x0,0x73,0x0,0x22,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x21,0x0,
				0x2d,0x0,0x2d,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,
				0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x20,0x0,0x73,0x0,0x61,0x0,
				0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x54,0x0,0x69,0x0,0x6d,0x0,0x65,0x0,0x3d,
				0x0,0x22,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x31,
				0x0,0x2e,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x22,0x0,0x20,0x0,0x78,0x0,0x6d,0x0,0x6c,
				0x0,0x3a,0x0,0x73,0x0,0x70,0x0,0x61,0x0,0x63,0x0,0x65,0x0,0x3d,0x0,0x22,0x0,0x70,
				0x0,0x72,0x0,0x65,0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x76,0x0,0x65,0x0,0x22,0x0,0x3e,
				0x0,0xd,0x0,0xa,0x0,0x61,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII"))
	{
/*
<SAMI>
<HEAD>
<STYLE TYPE="text/css">
<!--
<TextSample sampleTime="00:00:01.000" xml:space="preserve">a
</TextSample>
<TextSample sampleTime="00:00:11.000" xml:space="preserve">End</TextSample>
</TextStream>
 */
		U8 au8temp[] = {0x3c,0x53,0x41,0x4d,0x49,0x3e,0xd,0xa,0x3c,0x48,0x45,0x41,0x44,0x3e,0xd,0xa,0x3c
				,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,0x65,0x78,0x74
				,0x2f,0x63,0x73,0x73,0x22,0x3e,0xd,0xa,0x3c,0x21,0x2d,0x2d,0xd,0xa,0x3c,0x54,0x65,
				0x78,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x54,
				0x69,0x6d,0x65,0x3d,0x22,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2e,0x30,0x30,
				0x30,0x22,0x20,0x78,0x6d,0x6c,0x3a,0x73,0x70,0x61,0x63,0x65,0x3d,0x22,0x70,0x72,
				0x65,0x73,0x65,0x72,0x76,0x65,0x22,0x3e,0x61,0xd,0xa,0x3c,0x2f,0x54,0x65,0x78,
				0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x3e,0xd,0xa,0x3c,0x54,0x65,0x78,0x74,0x53,0x61,
				0x6d,0x70,0x6c,0x65,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x54,0x69,0x6d,0x65,0x3d,
				0x22,0x30,0x30,0x3a,0x30,0x30,0x3a,0x31,0x31,0x2e,0x30,0x30,0x30,0x22,0x20,0x78,
				0x6d,0x6c,0x3a,0x73,0x70,0x61,0x63,0x65,0x3d,0x22,0x70,0x72,0x65,0x73,0x65,0x72,
				0x76,0x65,0x22,0x3e,0x45,0x6e,0x64,0x3c,0x2f,0x54,0x65,0x78,0x74,0x53,0x61,0x6d,
				0x70,0x6c,0x65,0x3e,0xd,0xa,0x3c,0x2f,0x54,0x65,0x78,0x74,0x53,0x74,0x72,0x65
				,0x61,0x6d,0x3e,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE"))
	{
/*
<SAMI>
<HEAD>
<STYLE TYPE="text/css">
<!--
<TextSample sampleTime="00:00:01.000" xml:space="preserve">a
</TextSample>
<TextSample sampleTime="00:00:11.000" xml:space="preserve">End</TextSample>
</TextStream>
 */
		U8 au8temp[] = {0xff,0xfe,0x3c,0x0,0x53,0x0,0x41,0x0,0x4d,0x0,0x49,0x0,0x3e,0x0,0xd,
				0x0,0xa,0x0,0x3c,0x0,0x48,0x0,0x45,0x0,0x41,0x0,0x44,0x0,0x3e,0x0,
				0xd,0x0,0xa,0x0,0x3c,0x0,0x53,0x0,0x54,0x0,0x59,0x0,0x4c,0x0,0x45,
				0x0,0x20,0x0,0x54,0x0,0x59,0x0,0x50,0x0,0x45,0x0,0x3d,0x0,0x22,0x0,
				0x74,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x2f,0x0,0x63,0x0,0x73,0x0,0x73,
				0x0,0x22,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x21,0x0,0x2d,0x0,
				0x2d,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,
				0x0,0x53,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x20,0x0,
				0x73,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x54,0x0,0x69,
				0x0,0x6d,0x0,0x65,0x0,0x3d,0x0,0x22,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,
				0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x31,0x0,0x2e,0x0,0x30,0x0,0x30,
				0x0,0x30,0x0,0x22,0x0,0x20,0x0,0x78,0x0,0x6d,0x0,0x6c,0x0,0x3a,0x0,
				0x73,0x0,0x70,0x0,0x61,0x0,0x63,0x0,0x65,0x0,0x3d,0x0,0x22,0x0,0x70,
				0x0,0x72,0x0,0x65,0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x76,0x0,0x65,0x0,
				0x22,0x0,0x3e,0x0,0x61,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x2f,0x0,0x54,
				0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,
				0x6c,0x0,0x65,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x54,0x0,0x65,
				0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,
				0x65,0x0,0x20,0x0,0x73,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,
				0x0,0x54,0x0,0x69,0x0,0x6d,0x0,0x65,0x0,0x3d,0x0,0x22,0x0,0x30,0x0,
				0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x31,0x0,0x31,0x0,0x2e,
				0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x22,0x0,0x20,0x0,0x78,0x0,0x6d,0x0,
				0x6c,0x0,0x3a,0x0,0x73,0x0,0x70,0x0,0x61,0x0,0x63,0x0,0x65,0x0,0x3d,
				0x0,0x22,0x0,0x70,0x0,0x72,0x0,0x65,0x0,0x73,0x0,0x65,0x0,0x72,0x0,
				0x76,0x0,0x65,0x0,0x22,0x0,0x3e,0x0,0x45,0x0,0x6e,0x0,0x64,0x0,0x3c,
				0x0,0x2f,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,0x0,
				0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,
				0x0,0x2f,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x74,0x0,
				0x72,0x0,0x65,0x0,0x61,0x0,0x6d,0x0,0x3e,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10"))
	{
/*
<TextStream version="1.0">
</TextSampleDescription>
</TextStreamHeader>
<TextSample sampleTime="00:00:00.000" text="">
</TextSample>
<<TextSample sampleTime="00:03:23.000" text="">
</TextSample>
</TextStream>
 */
		U8 au8temp[] = {0x3c,0x54,0x65,0x78,0x74,0x53,0x74,0x72,0x65,0x61,0x6d,0x20,0x76,0x65,0x72,
				0x73,0x69,0x6f,0x6e,0x3d,0x22,0x31,0x2e,0x30,0x22,0x3e,0xd,0xa,0x3c,0x2f,
				0x54,0x65,0x78,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x44,0x65,0x73,0x63,0x72,
				0x69,0x70,0x74,0x69,0x6f,0x6e,0x3e,0xd,0xa,0x3c,0x2f,0x54,0x65,0x78,0x74,
				0x53,0x74,0x72,0x65,0x61,0x6d,0x48,0x65,0x61,0x64,0x65,0x72,0x3e,0xd,0xa,
				0x3c,0x54,0x65,0x78,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x20,0x73,0x61,0x6d,
				0x70,0x6c,0x65,0x54,0x69,0x6d,0x65,0x3d,0x22,0x30,0x30,0x3a,0x30,0x30,0x3a,
				0x30,0x30,0x2e,0x30,0x30,0x30,0x22,0x20,0x74,0x65,0x78,0x74,0x3d,0x22,0x22,
				0x3e,0xd,0xa,0x3c,0x2f,0x54,0x65,0x78,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,
				0x3e,0xd,0xa,0x3c,0x3c,0x54,0x65,0x78,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,
				0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x54,0x69,0x6d,0x65,0x3d,0x22,0x30,0x30,
				0x3a,0x30,0x33,0x3a,0x32,0x33,0x2e,0x30,0x30,0x30,0x22,0x20,0x74,0x65,0x78,
				0x74,0x3d,0x22,0x22,0x3e,0xd,0xa,0x3c,0x2f,0x54,0x65,0x78,0x74,0x53,0x61,
				0x6d,0x70,0x6c,0x65,0x3e,0xd,0xa,0x3c,0x2f,0x54,0x65,0x78,0x74,0x53,0x74,
				0x72,0x65,0x61,0x6d,0x3e};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10"))
	{
/*
<TextStream version="1.0">
</TextSampleDescription>
</TextStreamHeader>
<TextSample sampleTime="00:00:00.000" text="">
</TextSample>
<<TextSample sampleTime="00:03:23.000" text="">
</TextSample>
</TextStream>
 */
		U8 au8temp[] = {0x2f,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,0x0,0x6d,
				0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x44,0x0,0x65,0x0,0x73,0x0,0x63,0x0,
				0x72,0x0,0x69,0x0,0x70,0x0,0x74,0x0,0x69,0x0,0x6f,0x0,0x6e,0x0,0x3e,
				0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x2f,0x0,0x54,0x0,0x65,0x0,0x78,0x0,
				0x74,0x0,0x53,0x0,0x74,0x0,0x72,0x0,0x65,0x0,0x61,0x0,0x6d,0x0,0x48,
				0x0,0x65,0x0,0x61,0x0,0x64,0x0,0x65,0x0,0x72,0x0,0x3e,0x0,0xd,0x0,
				0xa,0x0,0x3c,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,
				0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x20,0x0,0x73,0x0,0x61,0x0,
				0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x54,0x0,0x69,0x0,0x6d,0x0,0x65,
				0x0,0x3d,0x0,0x22,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x2e,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x22,
				0x0,0x20,0x0,0x74,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x3d,0x0,0x22,0x0,
				0x22,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x2f,0x0,0x54,0x0,0x65,
				0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,
				0x65,0x0,0x3e,0x0,0xd,0x0,0xa,0x0,0x3c,0x0,0x3c,0x0,0x54,0x0,0x65,
				0x0,0x78,0x0,0x74,0x0,0x53,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,
				0x65,0x0,0x20,0x0,0x73,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,
				0x0,0x54,0x0,0x69,0x0,0x6d,0x0,0x65,0x0,0x3d,0x0,0x22,0x0,0x30,0x0,
				0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x3a,0x0,0x32,0x0,0x33,0x0,0x2e,
				0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x22,0x0,0x20,0x0,0x74,0x0,0x65,0x0,
				0x78,0x0,0x74,0x0,0x3d,0x0,0x22,0x0,0x22,0x0,0x3e,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x2f,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,
				0x61,0x0,0x6d,0x0,0x70,0x0,0x6c,0x0,0x65,0x0,0x3e,0x0,0xd,0x0,0xa,
				0x0,0x3c,0x0,0x2f,0x0,0x54,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x53,0x0,
				0x74,0x0,0x72,0x0,0x65,0x0,0x61,0x0,0x6d,0x0,0x3e,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_ASCII"))
	{
/*
00:00:01,1=Subtitle Track: 1
00:00:01,2=00:00:01,000 to 00:00:03,000
00:00:03,1=
00:00:03,2=
 */
		U8 au8temp[] = {0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2c,0x31,0x3d,0x53,0x75,0x62,0x74,
				0x69,0x74,0x6c,0x65,0x20,0x54,0x72,0x61,0x63,0x6b,0x3a,0x20,0x31,0xd,0xa,
				0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2c,0x32,0x3d,0x30,0x30,0x3a,0x30,
				0x30,0x3a,0x30,0x31,0x2c,0x30,0x30,0x30,0x20,0x74,0x6f,0x20,0x30,0x30,0x3a,
				0x30,0x30,0x3a,0x30,0x33,0x2c,0x30,0x30,0x30,0xd,0xa,0x30,0x30,0x3a,0x30,
				0x30,0x3a,0x30,0x33,0x2c,0x31,0x3d,0xd,0xa,0x30,0x30,0x3a,0x30,0x30,0x3a,
				0x30,0x33,0x2c,0x32,0x3d,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_Parser_UNICODE"))
	{
/*
00:00:01,1=Subtitle Track: 1
00:00:01,2=00:00:01,000 to 00:00:03,000
00:00:03,1=
00:00:03,2=
 */
		U8 au8temp[] = {0xff,0xfe,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,
				0x0,0x31,0x0,0x2c,0x0,0x31,0x0,0x3d,0x0,0x53,0x0,0x75,0x0,0x62,0x0,
				0x74,0x0,0x69,0x0,0x74,0x0,0x6c,0x0,0x65,0x0,0x20,0x0,0x54,0x0,0x72,
				0x0,0x61,0x0,0x63,0x0,0x6b,0x0,0x3a,0x0,0x20,0x0,0x31,0x0,0xd,0x0,
				0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,
				0x0,0x31,0x0,0x2c,0x0,0x32,0x0,0x3d,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,
				0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x31,0x0,0x2c,0x0,0x30,0x0,0x30,
				0x0,0x30,0x0,0x20,0x0,0x74,0x0,0x6f,0x0,0x20,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x30,
				0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,
				0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x31,0x0,0x3d,
				0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x32,0x0,0x3d,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII"))
	{
/*
00:00:01,1=Subtitle Track: 1
00:00:01,2=00:00:01,000 to 00:00:03,000
00:00:03,1=
00:00:03,2=
 */
		U8 au8temp[] = {0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2c,0x31,0x3d,0x53,0x75,0x62,0x74,
				0x69,0x74,0x6c,0x65,0x20,0x54,0x72,0x61,0x63,0x6b,0x3a,0x20,0x31,0xd,0xa,
				0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x2c,0x32,0x3d,0x30,0x30,0x3a,0x30,
				0x30,0x3a,0x30,0x31,0x2c,0x30,0x30,0x30,0x20,0x74,0x6f,0x20,0x30,0x30,0x3a,
				0x30,0x30,0x3a,0x30,0x33,0x2c,0x30,0x30,0x30,0xd,0xa,0x30,0x30,0x3a,0x30,
				0x30,0x3a,0x30,0x33,0x2c,0x31,0x3d,0xd,0xa,0x30,0x30,0x3a,0x30,0x30,0x3a,
				0x30,0x33,0x2c,0x32,0x3d,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE"))
	{
/*
00:00:01,1=Subtitle Track: 1
00:00:01,2=00:00:01,000 to 00:00:03,000
00:00:03,1=
00:00:03,2=
 */
		U8 au8temp[] = {0xff,0xfe,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,
				0x0,0x31,0x0,0x2c,0x0,0x31,0x0,0x3d,0x0,0x53,0x0,0x75,0x0,0x62,0x0,
				0x74,0x0,0x69,0x0,0x74,0x0,0x6c,0x0,0x65,0x0,0x20,0x0,0x54,0x0,0x72,
				0x0,0x61,0x0,0x63,0x0,0x6b,0x0,0x3a,0x0,0x20,0x0,0x31,0x0,0xd,0x0,
				0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,
				0x0,0x31,0x0,0x2c,0x0,0x32,0x0,0x3d,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,
				0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x31,0x0,0x2c,0x0,0x30,0x0,0x30,
				0x0,0x30,0x0,0x20,0x0,0x74,0x0,0x6f,0x0,0x20,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x30,
				0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,
				0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x31,0x0,0x3d,
				0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x33,0x0,0x2c,0x0,0x32,0x0,0x3d,0x0,0xd,0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_GetFileSizeByPlaylistIndex_TRUE"))
	{
	  return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_ASCII"))
	{
/*
00:00:01:00 00:00:03:00 a
00:00:03:00 00:00:05:00 b
 */
		U8 au8temp[] = {0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x3a,0x30,0x30,0x20,0x30,0x30,0x3a,
				0x30,0x30,0x3a,0x30,0x33,0x3a,0x30,0x30,0x20,0x61,0xd,0xa,0x30,0x30,0x3a,
				0x30,0x30,0x3a,0x30,0x33,0x3a,0x30,0x30,0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,
				0x30,0x35,0x3a,0x30,0x30,0x20,0x62,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_Parser_UNICODE"))
	{
/*
00:00:01:00 00:00:03:00 a
00:00:03:00 00:00:05:00 b
 */
		U8 au8temp[] = {0xff,0xfe,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,
				0x0,0x31,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x20,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x3a,0x0,0x30,
				0x0,0x30,0x0,0x20,0x0,0x61,0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x3a,0x0,0x30,
				0x0,0x30,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x35,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x20,0x0,0x62,
				0x0,0xd,0x0,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII"))
	{
/*
00:00:01:00 00:00:03:00 a
00:00:03:00 00:00:05:00 b
 */
		U8 au8temp[] = {0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x31,0x3a,0x30,0x30,0x20,0x30,0x30,0x3a,
				0x30,0x30,0x3a,0x30,0x33,0x3a,0x30,0x30,0x20,0x61,0xd,0xa,0x30,0x30,0x3a,
				0x30,0x30,0x3a,0x30,0x33,0x3a,0x30,0x30,0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,
				0x30,0x35,0x3a,0x30,0x30,0x20,0x62,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE"))
	{
/*
00:00:01:00 00:00:03:00 a
00:00:03:00 00:00:05:00 b
 */
		U8 au8temp[] = {0xff,0xfe,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,
				0x0,0x31,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x20,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x3a,0x0,0x30,
				0x0,0x30,0x0,0x20,0x0,0x61,0x0,0xd,0x0,0xa,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x33,0x0,0x3a,0x0,0x30,
				0x0,0x30,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,
				0x3a,0x0,0x30,0x0,0x35,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x20,0x0,0x62,
				0x0,0xd,0x0,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_ASCII"))
	{
/*
palette: 000000, f0f0f0, cccccc, 999999, 3333fa, 1111bb, fa3333, bb1111, 33fa33, 11bb11, fafa33, bbbb11, fa33fa, bb11bb, 33fafa, 11bbbb
id: en, index: 0
timestamp: 00:00:00:538, filepos: 000000000
id: en, index: 1
timestamp: 00:00:00:538, filepos: 000037000
 */
		U8 au8temp[] = {0x70,0x61,0x6c,0x65,0x74,0x74,0x65,0x3a,0x20,0x30,0x30,0x30,0x30,0x30,0x30,
				0x2c,0x20,0x66,0x30,0x66,0x30,0x66,0x30,0x2c,0x20,0x63,0x63,0x63,0x63,0x63,
				0x63,0x2c,0x20,0x39,0x39,0x39,0x39,0x39,0x39,0x2c,0x20,0x33,0x33,0x33,0x33,
				0x66,0x61,0x2c,0x20,0x31,0x31,0x31,0x31,0x62,0x62,0x2c,0x20,0x66,0x61,0x33,
				0x33,0x33,0x33,0x2c,0x20,0x62,0x62,0x31,0x31,0x31,0x31,0x2c,0x20,0x33,0x33,
				0x66,0x61,0x33,0x33,0x2c,0x20,0x31,0x31,0x62,0x62,0x31,0x31,0x2c,0x20,0x66,
				0x61,0x66,0x61,0x33,0x33,0x2c,0x20,0x62,0x62,0x62,0x62,0x31,0x31,0x2c,0x20,
				0x66,0x61,0x33,0x33,0x66,0x61,0x2c,0x20,0x62,0x62,0x31,0x31,0x62,0x62,0x2c,
				0x20,0x33,0x33,0x66,0x61,0x66,0x61,0x2c,0x20,0x31,0x31,0x62,0x62,0x62,0x62,
				0xd,0xa,0x69,0x64,0x3a,0x20,0x65,0x6e,0x2c,0x20,0x69,0x6e,0x64,0x65,0x78,
				0x3a,0x20,0x30,0xd,0xa,0x74,0x69,0x6d,0x65,0x73,0x74,0x61,0x6d,0x70,0x3a,
				0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x30,0x3a,0x35,0x33,0x38,0x2c,0x20,
				0x66,0x69,0x6c,0x65,0x70,0x6f,0x73,0x3a,0x20,0x30,0x30,0x30,0x30,0x30,0x30,
				0x30,0x30,0x30,0xd,0xa,0x69,0x64,0x3a,0x20,0x65,0x6e,0x2c,0x20,0x69,0x6e,
				0x64,0x65,0x78,0x3a,0x20,0x31,0xd,0xa,0x74,0x69,0x6d,0x65,0x73,0x74,0x61,
				0x6d,0x70,0x3a,0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x30,0x3a,0x35,0x33,
				0x38,0x2c,0x20,0x66,0x69,0x6c,0x65,0x70,0x6f,0x73,0x3a,0x20,0x30,0x30,0x30,
				0x30,0x33,0x37,0x30,0x30,0x30,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_Parser_UNICODE"))
	{
/*
palette: 000000, f0f0f0, cccccc, 999999, 3333fa, 1111bb, fa3333, bb1111, 33fa33, 11bb11, fafa33, bbbb11, fa33fa, bb11bb, 33fafa, 11bbbb
id: en, index: 0
timestamp: 00:00:00:538, filepos: 000000000
id: en, index: 1
timestamp: 00:00:00:538, filepos: 000037000
 */
		U8 au8temp[] = {0xff,0xfe,0x70,0x0,0x61,0x0,0x6c,0x0,0x65,0x0,0x74,0x0,0x74,0x0,0x65,
				0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x2c,0x0,0x20,0x0,0x66,0x0,0x30,0x0,0x66,0x0,0x30,0x0,0x66,
				0x0,0x30,0x0,0x2c,0x0,0x20,0x0,0x63,0x0,0x63,0x0,0x63,0x0,0x63,0x0,
				0x63,0x0,0x63,0x0,0x2c,0x0,0x20,0x0,0x39,0x0,0x39,0x0,0x39,0x0,0x39,
				0x0,0x39,0x0,0x39,0x0,0x2c,0x0,0x20,0x0,0x33,0x0,0x33,0x0,0x33,0x0,
				0x33,0x0,0x66,0x0,0x61,0x0,0x2c,0x0,0x20,0x0,0x31,0x0,0x31,0x0,0x31,
				0x0,0x31,0x0,0x62,0x0,0x62,0x0,0x2c,0x0,0x20,0x0,0x66,0x0,0x61,0x0,
				0x33,0x0,0x33,0x0,0x33,0x0,0x33,0x0,0x2c,0x0,0x20,0x0,0x62,0x0,0x62,
				0x0,0x31,0x0,0x31,0x0,0x31,0x0,0x31,0x0,0x2c,0x0,0x20,0x0,0x33,0x0,
				0x33,0x0,0x66,0x0,0x61,0x0,0x33,0x0,0x33,0x0,0x2c,0x0,0x20,0x0,0x31,
				0x0,0x31,0x0,0x62,0x0,0x62,0x0,0x31,0x0,0x31,0x0,0x2c,0x0,0x20,0x0,
				0x66,0x0,0x61,0x0,0x66,0x0,0x61,0x0,0x33,0x0,0x33,0x0,0x2c,0x0,0x20,
				0x0,0x62,0x0,0x62,0x0,0x62,0x0,0x62,0x0,0x31,0x0,0x31,0x0,0x2c,0x0,
				0x20,0x0,0x66,0x0,0x61,0x0,0x33,0x0,0x33,0x0,0x66,0x0,0x61,0x0,0x2c,
				0x0,0x20,0x0,0x62,0x0,0x62,0x0,0x31,0x0,0x31,0x0,0x62,0x0,0x62,0x0,
				0x2c,0x0,0x20,0x0,0x33,0x0,0x33,0x0,0x66,0x0,0x61,0x0,0x66,0x0,0x61,
				0x0,0x2c,0x0,0x20,0x0,0x31,0x0,0x31,0x0,0x62,0x0,0x62,0x0,0x62,0x0,
				0x62,0x0,0xd,0x0,0xa,0x0,0x69,0x0,0x64,0x0,0x3a,0x0,0x20,0x0,0x65,
				0x0,0x6e,0x0,0x2c,0x0,0x20,0x0,0x69,0x0,0x6e,0x0,0x64,0x0,0x65,0x0,
				0x78,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x74,0x0,0x69,
				0x0,0x6d,0x0,0x65,0x0,0x73,0x0,0x74,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,
				0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,
				0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x35,0x0,0x33,0x0,0x38,0x0,0x2c,0x0,
				0x20,0x0,0x66,0x0,0x69,0x0,0x6c,0x0,0x65,0x0,0x70,0x0,0x6f,0x0,0x73,
				0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x69,0x0,0x64,
				0x0,0x3a,0x0,0x20,0x0,0x65,0x0,0x6e,0x0,0x2c,0x0,0x20,0x0,0x69,0x0,
				0x6e,0x0,0x64,0x0,0x65,0x0,0x78,0x0,0x3a,0x0,0x20,0x0,0x31,0x0,0xd,
				0x0,0xa,0x0,0x74,0x0,0x69,0x0,0x6d,0x0,0x65,0x0,0x73,0x0,0x74,0x0,
				0x61,0x0,0x6d,0x0,0x70,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,
				0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x35,0x0,
				0x33,0x0,0x38,0x0,0x2c,0x0,0x20,0x0,0x66,0x0,0x69,0x0,0x6c,0x0,0x65,
				0x0,0x70,0x0,0x6f,0x0,0x73,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x30,0x0,0x33,0x0,0x37,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,
				0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII"))
	{
/*
palette: 000000, f0f0f0, cccccc, 999999, 3333fa, 1111bb, fa3333, bb1111, 33fa33, 11bb11, fafa33, bbbb11, fa33fa, bb11bb, 33fafa, 11bbbb
id: en, index: 0
timestamp: 00:00:00:538, filepos: 000000000
id: en, index: 1
timestamp: 00:00:00:538, filepos: 000037000
 */
		U8 au8temp[] = {0x70,0x61,0x6c,0x65,0x74,0x74,0x65,0x3a,0x20,0x30,0x30,0x30,0x30,0x30,0x30,
				0x2c,0x20,0x66,0x30,0x66,0x30,0x66,0x30,0x2c,0x20,0x63,0x63,0x63,0x63,0x63,
				0x63,0x2c,0x20,0x39,0x39,0x39,0x39,0x39,0x39,0x2c,0x20,0x33,0x33,0x33,0x33,
				0x66,0x61,0x2c,0x20,0x31,0x31,0x31,0x31,0x62,0x62,0x2c,0x20,0x66,0x61,0x33,
				0x33,0x33,0x33,0x2c,0x20,0x62,0x62,0x31,0x31,0x31,0x31,0x2c,0x20,0x33,0x33,
				0x66,0x61,0x33,0x33,0x2c,0x20,0x31,0x31,0x62,0x62,0x31,0x31,0x2c,0x20,0x66,
				0x61,0x66,0x61,0x33,0x33,0x2c,0x20,0x62,0x62,0x62,0x62,0x31,0x31,0x2c,0x20,
				0x66,0x61,0x33,0x33,0x66,0x61,0x2c,0x20,0x62,0x62,0x31,0x31,0x62,0x62,0x2c,
				0x20,0x33,0x33,0x66,0x61,0x66,0x61,0x2c,0x20,0x31,0x31,0x62,0x62,0x62,0x62,
				0xd,0xa,0x69,0x64,0x3a,0x20,0x65,0x6e,0x2c,0x20,0x69,0x6e,0x64,0x65,0x78,
				0x3a,0x20,0x30,0xd,0xa,0x74,0x69,0x6d,0x65,0x73,0x74,0x61,0x6d,0x70,0x3a,
				0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x30,0x3a,0x35,0x33,0x38,0x2c,0x20,
				0x66,0x69,0x6c,0x65,0x70,0x6f,0x73,0x3a,0x20,0x30,0x30,0x30,0x30,0x30,0x30,
				0x30,0x30,0x30,0xd,0xa,0x69,0x64,0x3a,0x20,0x65,0x6e,0x2c,0x20,0x69,0x6e,
				0x64,0x65,0x78,0x3a,0x20,0x31,0xd,0xa,0x74,0x69,0x6d,0x65,0x73,0x74,0x61,
				0x6d,0x70,0x3a,0x20,0x30,0x30,0x3a,0x30,0x30,0x3a,0x30,0x30,0x3a,0x35,0x33,
				0x38,0x2c,0x20,0x66,0x69,0x6c,0x65,0x70,0x6f,0x73,0x3a,0x20,0x30,0x30,0x30,
				0x30,0x33,0x37,0x30,0x30,0x30,0xd,0xa};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE"))
	{
/*
palette: 000000, f0f0f0, cccccc, 999999, 3333fa, 1111bb, fa3333, bb1111, 33fa33, 11bb11, fafa33, bbbb11, fa33fa, bb11bb, 33fafa, 11bbbb
id: en, index: 0
timestamp: 00:00:00:538, filepos: 000000000
id: en, index: 1
timestamp: 00:00:00:538, filepos: 000037000
 */
		U8 au8temp[] = {0xff,0xfe,0x70,0x0,0x61,0x0,0x6c,0x0,0x65,0x0,0x74,0x0,0x74,0x0,0x65,
				0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x2c,0x0,0x20,0x0,0x66,0x0,0x30,0x0,0x66,0x0,0x30,0x0,0x66,
				0x0,0x30,0x0,0x2c,0x0,0x20,0x0,0x63,0x0,0x63,0x0,0x63,0x0,0x63,0x0,
				0x63,0x0,0x63,0x0,0x2c,0x0,0x20,0x0,0x39,0x0,0x39,0x0,0x39,0x0,0x39,
				0x0,0x39,0x0,0x39,0x0,0x2c,0x0,0x20,0x0,0x33,0x0,0x33,0x0,0x33,0x0,
				0x33,0x0,0x66,0x0,0x61,0x0,0x2c,0x0,0x20,0x0,0x31,0x0,0x31,0x0,0x31,
				0x0,0x31,0x0,0x62,0x0,0x62,0x0,0x2c,0x0,0x20,0x0,0x66,0x0,0x61,0x0,
				0x33,0x0,0x33,0x0,0x33,0x0,0x33,0x0,0x2c,0x0,0x20,0x0,0x62,0x0,0x62,
				0x0,0x31,0x0,0x31,0x0,0x31,0x0,0x31,0x0,0x2c,0x0,0x20,0x0,0x33,0x0,
				0x33,0x0,0x66,0x0,0x61,0x0,0x33,0x0,0x33,0x0,0x2c,0x0,0x20,0x0,0x31,
				0x0,0x31,0x0,0x62,0x0,0x62,0x0,0x31,0x0,0x31,0x0,0x2c,0x0,0x20,0x0,
				0x66,0x0,0x61,0x0,0x66,0x0,0x61,0x0,0x33,0x0,0x33,0x0,0x2c,0x0,0x20,
				0x0,0x62,0x0,0x62,0x0,0x62,0x0,0x62,0x0,0x31,0x0,0x31,0x0,0x2c,0x0,
				0x20,0x0,0x66,0x0,0x61,0x0,0x33,0x0,0x33,0x0,0x66,0x0,0x61,0x0,0x2c,
				0x0,0x20,0x0,0x62,0x0,0x62,0x0,0x31,0x0,0x31,0x0,0x62,0x0,0x62,0x0,
				0x2c,0x0,0x20,0x0,0x33,0x0,0x33,0x0,0x66,0x0,0x61,0x0,0x66,0x0,0x61,
				0x0,0x2c,0x0,0x20,0x0,0x31,0x0,0x31,0x0,0x62,0x0,0x62,0x0,0x62,0x0,
				0x62,0x0,0xd,0x0,0xa,0x0,0x69,0x0,0x64,0x0,0x3a,0x0,0x20,0x0,0x65,
				0x0,0x6e,0x0,0x2c,0x0,0x20,0x0,0x69,0x0,0x6e,0x0,0x64,0x0,0x65,0x0,
				0x78,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x74,0x0,0x69,
				0x0,0x6d,0x0,0x65,0x0,0x73,0x0,0x74,0x0,0x61,0x0,0x6d,0x0,0x70,0x0,
				0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,
				0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x35,0x0,0x33,0x0,0x38,0x0,0x2c,0x0,
				0x20,0x0,0x66,0x0,0x69,0x0,0x6c,0x0,0x65,0x0,0x70,0x0,0x6f,0x0,0x73,
				0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,0x0,0xa,0x0,0x69,0x0,0x64,
				0x0,0x3a,0x0,0x20,0x0,0x65,0x0,0x6e,0x0,0x2c,0x0,0x20,0x0,0x69,0x0,
				0x6e,0x0,0x64,0x0,0x65,0x0,0x78,0x0,0x3a,0x0,0x20,0x0,0x31,0x0,0xd,
				0x0,0xa,0x0,0x74,0x0,0x69,0x0,0x6d,0x0,0x65,0x0,0x73,0x0,0x74,0x0,
				0x61,0x0,0x6d,0x0,0x70,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,0x3a,
				0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x30,0x0,0x30,0x0,0x3a,0x0,0x35,0x0,
				0x33,0x0,0x38,0x0,0x2c,0x0,0x20,0x0,0x66,0x0,0x69,0x0,0x6c,0x0,0x65,
				0x0,0x70,0x0,0x6f,0x0,0x73,0x0,0x3a,0x0,0x20,0x0,0x30,0x0,0x30,0x0,
				0x30,0x0,0x30,0x0,0x33,0x0,0x37,0x0,0x30,0x0,0x30,0x0,0x30,0x0,0xd,
				0x0,0xa,0x0};
		//copy to golbal varialbes
		memcpy(g_au8FileBufPtrTemp_Parser, au8temp, sizeof(au8temp));
		return (MS_U32)&g_au8FileBufPtrTemp_Parser[0];
	}
    return 0UL;
}

/** User stub definition for function: MS_U32 MsOS_PA2KSEG0(MS_U32) */
EXTERN_C_LINKAGE MS_U32 MsOS_PA2KSEG0 (MS_U32 addr) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MsOS_PA2KSEG0 (MS_U32 addr)
{
    return 0UL;
}

/** User stub definition for function: BOOLEAN MApp_SI_Reset_New_RF_Index(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Reset_New_RF_Index (U8 u8RFIndex) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Reset_New_RF_Index (U8 u8RFIndex)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_Get_Service_Replacement_Info(RP_SERVICE_INFO *) */
EXTERN_C_LINKAGE void MApp_SI_Get_Service_Replacement_Info (RP_SERVICE_INFO * stRP_Info) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Get_Service_Replacement_Info (RP_SERVICE_INFO * stRP_Info)
{
}

/** User stub definition for function: void MDrv_PM_RTCEnableInterrupt(MS_BOOL) */
BOOL btest_msAPI_Timer_EnableRTCWakeUp = FALSE;
EXTERN_C_LINKAGE void MDrv_PM_RTCEnableInterrupt (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PM_RTCEnableInterrupt (MS_BOOL bEnable)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_EnableRTCWakeUp"))
	{
		btest_msAPI_Timer_EnableRTCWakeUp = TRUE;
	}
}

/** User stub definition for function: GFX_Result MApi_GFX_SetAlphaSrcFrom(GFX_AlphaSrcFrom) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetAlphaSrcFrom (GFX_AlphaSrcFrom eMode) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetAlphaSrcFrom (GFX_AlphaSrcFrom eMode)
{
    return GFX_FAIL;
}

/** User stub definition for function: void MApp_Dmx_DisableTableMonitor(void) */
EXTERN_C_LINKAGE void MApp_Dmx_DisableTableMonitor () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_DisableTableMonitor (void)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_InterruptAttach(SC_INT_SRC , SC_InterruptCb , void * ) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_InterruptAttach(SC_INT_SRC enIntNum, SC_InterruptCb pIntCb, void * pParam);
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_InterruptAttach(SC_INT_SRC enIntNum, SC_InterruptCb pIntCb, void * pParam)
{
    return TRUE;
}

/** User stub definition for function: void MApi_XC_DisableInputSource(MS_BOOL, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_DisableInputSource (MS_BOOL bDisable, SCALER_WIN eWidnow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DisableInputSource (MS_BOOL bDisable, SCALER_WIN eWidnow)
{
}

/** User stub definition for function: void msAPI_CI_NotifySystemUTCtime(U8 *) */
EXTERN_C_LINKAGE void msAPI_CI_NotifySystemUTCtime (U8 * pu8UTCTime) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_NotifySystemUTCtime (U8 * pu8UTCTime)
{
}

/** User stub definition for function: void MApi_XC_EnableRequest_FrameBufferLess(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_EnableRequest_FrameBufferLess (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableRequest_FrameBufferLess (MS_BOOL bEnable)
{
}

/** User stub definition for function: void free(void *) */
EXTERN_C_LINKAGE void free (void * __ptr) ;
EXTERN_C_LINKAGE void CppTest_Stub_free (void * __ptr)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_FlushQueue(void) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_FlushQueue () ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_FlushQueue (void)
{
    return GFX_FAIL;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsAllBufferEmpty(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsAllBufferEmpty () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsAllBufferEmpty (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: U8 * msAPI_CI_CC_GetCredentialsBufferAddr(void) */
EXTERN_C_LINKAGE U8 * msAPI_CI_CC_GetCredentialsBufferAddr () ;
EXTERN_C_LINKAGE U8 * CppTest_Stub_msAPI_CI_CC_GetCredentialsBufferAddr (void)
{
    return (U8 *)0;
}

/** User stub definition for function: BOOLEAN MApp_SI_Is_Service_Change(MS_SI_CUR_SERVICE_INFO *, E_SERVICE_CHANGE *) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Is_Service_Change (MS_SI_CUR_SERVICE_INFO * pServiceInfo, E_SERVICE_CHANGE * pChangeType) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Is_Service_Change (MS_SI_CUR_SERVICE_INFO * pServiceInfo, E_SERVICE_CHANGE * pChangeType)
{
    return (unsigned char)0;
}

/** User stub definition for function: APIPNL_Result MApi_PNL_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE APIPNL_Result MApi_PNL_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE APIPNL_Result CppTest_Stub_MApi_PNL_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_APIPNL_FAIL;
}

/** User stub definition for function: MS_U8 MDrv_HDMI_audio_channel_status(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MDrv_HDMI_audio_channel_status (MS_U8 u8byte) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MDrv_HDMI_audio_channel_status (MS_U8 u8byte)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN DoMsDecompression(U8 *, U8 *, U8 *, U32) */
EXTERN_C_LINKAGE BOOLEAN DoMsDecompression (U8 * pSrc, U8 * pDst, U8 * pTmp, U32 srclen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_DoMsDecompression (U8 * pSrc, U8 * pDst, U8 * pTmp, U32 srclen)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_BDMA_test_MDrv_DMA_LoadBin_MS_COMPRESS_for_if_if"))
		return TRUE;
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_DLC_GetHistogramHandler(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_DLC_GetHistogramHandler (MS_BOOL bWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_DLC_GetHistogramHandler (MS_BOOL bWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_FlowSet(DMX_FLOW, DMX_FLOW_INPUT, MS_BOOL, MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_FlowSet (DMX_FLOW DmxFlow, DMX_FLOW_INPUT DmxFlowInput, MS_BOOL bClkInv, MS_BOOL bExtSync, MS_BOOL bParallel) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_FlowSet (DMX_FLOW DmxFlow, DMX_FLOW_INPUT DmxFlowInput, MS_BOOL bClkInv, MS_BOOL bExtSync, MS_BOOL bParallel)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MDrv_SEM_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SEM_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SEM_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_ResetSdtOtherComeFlag(void) */
EXTERN_C_LINKAGE void MApp_SI_ResetSdtOtherComeFlag () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_ResetSdtOtherComeFlag (void)
{
}

/** User stub definition for function: E_CARD_STATE msAPI_CI_GetCardState(void) */
EXTERN_C_LINKAGE E_CARD_STATE msAPI_CI_GetCardState () ;
EXTERN_C_LINKAGE E_CARD_STATE CppTest_Stub_msAPI_CI_GetCardState (void)
{
    return EN_NO_MODULE;
}

/** User stub definition for function: MS_S16 MApi_XC_Mux_DeletePath(INPUT_SOURCE_TYPE_t, E_DEST_TYPE) */
EXTERN_C_LINKAGE MS_S16 MApi_XC_Mux_DeletePath (INPUT_SOURCE_TYPE_t src, E_DEST_TYPE dest) ;
EXTERN_C_LINKAGE MS_S16 CppTest_Stub_MApi_XC_Mux_DeletePath (INPUT_SOURCE_TYPE_t src, E_DEST_TYPE dest)
{
    return (short)0;
}

/** User stub definition for function: void MApi_XC_DLC_DecodeExtCmd(tDLC_CONTROL_PARAMS *) */
EXTERN_C_LINKAGE void MApi_XC_DLC_DecodeExtCmd (tDLC_CONTROL_PARAMS * params) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_DecodeExtCmd (tDLC_CONTROL_PARAMS * params)
{
}

/** User stub definition for function: void * __rawmemchr(const void *, int) */
EXTERN_C_LINKAGE void * __rawmemchr (const void * __s, int __c) ;
EXTERN_C_LINKAGE void * CppTest_Stub___rawmemchr (const void * __s, int __c)
{
    return (void *)0;
}

/** User stub definition for function: PWM_Result MDrv_PWM_Oen(PWM_ChNum, MS_BOOL) */
EXTERN_C_LINKAGE PWM_Result MDrv_PWM_Oen (PWM_ChNum u8IndexPWM, MS_BOOL bOenPWM) ;
EXTERN_C_LINKAGE PWM_Result CppTest_Stub_MDrv_PWM_Oen (PWM_ChNum u8IndexPWM, MS_BOOL bOenPWM)
{
    return E_PWM_OK;
}

/** User stub definition for function: void MDrv_MVOP_Exit(void) */
EXTERN_C_LINKAGE void MDrv_MVOP_Exit () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_MVOP_Exit (void)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_Enable(MS_U8, MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_Enable (MS_U8 winId, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_Enable (MS_U8 winId, MS_BOOL bEnable)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApp_Dmx_SetCITuneServiceId(U16) */
EXTERN_C_LINKAGE void MApp_Dmx_SetCITuneServiceId (U16 u16ServiceId) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_SetCITuneServiceId (U16 u16ServiceId)
{
}

/** User stub definition for function: JPEG_Result MApi_JPEG_SupportCMYK(MS_BOOL) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_SupportCMYK (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_SupportCMYK (MS_BOOL bEnable)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Filein_Pause(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Filein_Pause () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Filein_Pause (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MApi_Mod_Do_Calibration(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_Mod_Do_Calibration () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_Mod_Do_Calibration (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_XC_DLC_Init_Ex(XC_DLC_init *, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_DLC_Init_Ex (XC_DLC_init * pstXC_DLC_InitData, MS_U32 u32InitDataLen) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_DLC_Init_Ex (XC_DLC_init * pstXC_DLC_InitData, MS_U32 u32InitDataLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_PicSetBrightness(MS_BOOL, MS_U8, MS_U8, MS_U8) */
EXTERN_C_LINKAGE void MApi_XC_ACE_PicSetBrightness (MS_BOOL eWindow, MS_U8 u8Brightness_R, MS_U8 u8Brightness_G, MS_U8 u8Brightness_B) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_PicSetBrightness (MS_BOOL eWindow, MS_U8 u8Brightness_R, MS_U8 u8Brightness_G, MS_U8 u8Brightness_B)
{
}

/** User stub definition for function: void MApi_AUDIO_SetBass(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetBass (MS_U8 u8Bass) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetBass (MS_U8 u8Bass)
{
}

/** User stub definition for function: MS_U16 mdrv_uart_connect(UART_PORT_TYPE, UART_DEVICE_TYPE) */
EXTERN_C_LINKAGE MS_U16 mdrv_uart_connect (UART_PORT_TYPE uart_port, UART_DEVICE_TYPE uart_dev) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_mdrv_uart_connect (UART_PORT_TYPE uart_port, UART_DEVICE_TYPE uart_dev)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MDrv_VBI_EnableTTXSlicer(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_VBI_EnableTTXSlicer (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VBI_EnableTTXSlicer (MS_BOOL bEnable)
{
}

/** User stub definition for function: void MApi_XC_SetInputSource(INPUT_SOURCE_TYPE_t, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetInputSource (INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetInputSource (INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_U16 MApi_GOP_DWIN_GetIntrStatus(void) */
EXTERN_C_LINKAGE MS_U16 MApi_GOP_DWIN_GetIntrStatus () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_GOP_DWIN_GetIntrStatus (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_U16 MApi_XC_CalculateVFreqx10(MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_CalculateVFreqx10 (MS_U16 u16HFreqx10, MS_U16 u16VTotal) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_CalculateVFreqx10 (MS_U16 u16HFreqx10, MS_U16 u16VTotal)
{
    return (unsigned short)0;
}

/** User stub definition for function: MVOP_Result MDrv_MVOP_SetInputCfg(MVOP_InputSel, MVOP_InputCfg *) */
EXTERN_C_LINKAGE MVOP_Result MDrv_MVOP_SetInputCfg (MVOP_InputSel in, MVOP_InputCfg * pCfg) ;
EXTERN_C_LINKAGE MVOP_Result CppTest_Stub_MDrv_MVOP_SetInputCfg (MVOP_InputSel in, MVOP_InputCfg * pCfg)
{
    return E_MVOP_OK;
}

/** User stub definition for function: U8 MDrv_GetUsbDeviceStatusPort2(void) */
EXTERN_C_LINKAGE U8 MDrv_GetUsbDeviceStatusPort2 () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_GetUsbDeviceStatusPort2 (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetAC3Info(Audio_AC3_infoType, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetAC3Info (Audio_AC3_infoType infoType, MS_U32 param1, MS_U32 param2) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetAC3Info (Audio_AC3_infoType infoType, MS_U32 param1, MS_U32 param2)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_XC_ACE_DNR_Blending(MS_U8, MS_U16, MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ACE_DNR_Blending (MS_U8 u8NewItem, MS_U16 u16PreItem, MS_U8 u8Weight) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ACE_DNR_Blending (MS_U8 u8NewItem, MS_U16 u16PreItem, MS_U8 u8Weight)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_SetDefaultLanguage(EN_SI_LANGUAGE) */
EXTERN_C_LINKAGE void MApp_SI_SetDefaultLanguage (EN_SI_LANGUAGE eSILanguage) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_SetDefaultLanguage (EN_SI_LANGUAGE eSILanguage)
{
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetWinPosition(MS_U8, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetWinPosition (MS_U8 winId, MS_U16 dispX, MS_U16 dispY) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetWinPosition (MS_U8 winId, MS_U16 dispX, MS_U16 dispY)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_HDMI_SetForClockLessThan70Mhz(E_MUX_INPUTPORT) */
EXTERN_C_LINKAGE MS_BOOL MDrv_HDMI_SetForClockLessThan70Mhz (E_MUX_INPUTPORT InputSourceType) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_HDMI_SetForClockLessThan70Mhz (E_MUX_INPUTPORT InputSourceType)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_AVFifo_Reset(MS_U32, MS_BOOL) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_AVFifo_Reset (MS_U32 DmxFltType, MS_BOOL bFlush) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_AVFifo_Reset (MS_U32 DmxFltType, MS_BOOL bFlush)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void msAPI_CI_CC_Reset_URI(void) */
EXTERN_C_LINKAGE void msAPI_CI_CC_Reset_URI () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_CC_Reset_URI (void)
{
}

/** User stub definition for function: BDMA_Result MDrv_BDMA_Init(MS_U32) */
EXTERN_C_LINKAGE BDMA_Result MDrv_BDMA_Init (MS_U32 u32Miu1Base) ;
EXTERN_C_LINKAGE BDMA_Result CppTest_Stub_MDrv_BDMA_Init (MS_U32 u32Miu1Base)
{
    return E_BDMA_NOT_SUPPORT;
}

/** User stub definition for function: void MApi_AUDIO_SetSurroundLPFGain(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSurroundLPFGain (MS_U8 mode) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSurroundLPFGain (MS_U8 mode)
{
}

/** User stub definition for function: void MApi_XC_EnableMirrorMode(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_EnableMirrorMode (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_EnableMirrorMode (MS_BOOL bEnable)
{
}

/** User stub definition for function: void MDrv_AVD_Exit(void) */
EXTERN_C_LINKAGE void MDrv_AVD_Exit () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_Exit (void)
{
}

/** User stub definition for function: MBX_Result MDrv_MBX_GetMsgQueueStatus(MBX_Class, MBX_MSGQ_Status *) */
EXTERN_C_LINKAGE MBX_Result MDrv_MBX_GetMsgQueueStatus (MBX_Class eTargetClass, MBX_MSGQ_Status * pMsgQueueStatus) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MDrv_MBX_GetMsgQueueStatus (MBX_Class eTargetClass, MBX_MSGQ_Status * pMsgQueueStatus)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: MS_U16 MApi_XC_ADC_GetMaximalGainValue(void) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_ADC_GetMaximalGainValue () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_ADC_GetMaximalGainValue (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApi_AUDIO_SIF_SetStandard(AUDIOSTANDARD_TYPE) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_SetStandard (AUDIOSTANDARD_TYPE standard_type) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_SetStandard (AUDIOSTANDARD_TYPE standard_type)
{
}

/** User stub definition for function: void MApi_AUDIO_Initialize(void) */
EXTERN_C_LINKAGE void MApi_AUDIO_Initialize () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_Initialize (void)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_OP_SendStatusReq(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_OP_SendStatusReq () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_OP_SendStatusReq (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_EIT_Reset_Cur_PF_Change(void) */
EXTERN_C_LINKAGE void MApp_EIT_Reset_Cur_PF_Change () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_EIT_Reset_Cur_PF_Change (void)
{
}

/** User stub definition for function: MS_BOOL MApi_SWI2C_ReadBytes(MS_U16, MS_U8, MS_U8 *, MS_U16, MS_U8 *) */

EXTERN_C_LINKAGE MS_BOOL MApi_SWI2C_ReadBytes (MS_U16 u16BusNumSlaveID, MS_U8 u8AddrNum, MS_U8 * paddr, MS_U16 u16size, MS_U8 * pu8data) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_SWI2C_ReadBytes (MS_U16 u16BusNumSlaveID, MS_U8 u8AddrNum, MS_U8 * paddr, MS_U16 u16size, MS_U8 * pu8data)
{
    return (MS_BOOL)0;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_SetConfigHPLPSetIF(DMD_RF_CHANNEL_BANDWIDTH, MS_BOOL, MS_BOOL, MS_BOOL, MS_U32, MS_U32, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_SetConfigHPLPSetIF (DMD_RF_CHANNEL_BANDWIDTH BW, MS_BOOL bSerialTS, MS_BOOL bPalBG, MS_BOOL bLPSel, MS_U32 u32IFFreq, MS_U32 u32FSFreq, MS_U8 u8IQSwap) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_SetConfigHPLPSetIF (DMD_RF_CHANNEL_BANDWIDTH BW, MS_BOOL bSerialTS, MS_BOOL bPalBG, MS_BOOL bLPSel, MS_U32 u32IFFreq, MS_U32 u32FSFreq, MS_U8 u8IQSwap)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_CopyData(MS_U8, MS_U8 *, MS_U32, MS_U32 *, MS_U32 *, DMX_CheckCb) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_CopyData (MS_U8 u8DmxId, MS_U8 * pu8Buf, MS_U32 u32BufSize, MS_U32 * pu32ActualSize, MS_U32 * pu32RmnSize, DMX_CheckCb pfCheckCB) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_CopyData (MS_U8 u8DmxId, MS_U8 * pu8Buf, MS_U32 u32BufSize, MS_U32 * pu32ActualSize, MS_U32 * pu32RmnSize, DMX_CheckCb pfCheckCB)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: void MApp_EIT_All_Sche_ResetFilter(void) */
EXTERN_C_LINKAGE void MApp_EIT_All_Sche_ResetFilter () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_EIT_All_Sche_ResetFilter (void)
{
}

/** User stub definition for function: SAR_Result MDrv_SAR_Init(void) */
EXTERN_C_LINKAGE SAR_Result MDrv_SAR_Init () ;
EXTERN_C_LINKAGE SAR_Result CppTest_Stub_MDrv_SAR_Init (void)
{
    return E_SAR_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_VBI_TTX_PacketBufferIsEmpty(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_TTX_PacketBufferIsEmpty () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_TTX_PacketBufferIsEmpty (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: JPEG_Result MApi_JPEG_DecodeHdr(void) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_DecodeHdr () ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_DecodeHdr (void)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: U8 msAPI_CI_MMICheckEvent(void) */
EXTERN_C_LINKAGE U8 msAPI_CI_MMICheckEvent () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_CI_MMICheckEvent (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: U16 MApp_SI_GetFileIn_PMT_PID(void) */
EXTERN_C_LINKAGE U16 MApp_SI_GetFileIn_PMT_PID () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_SI_GetFileIn_PMT_PID (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApi_JPEG_SetMaxDecodeResolution(MS_U16, MS_U16) */
EXTERN_C_LINKAGE void MApi_JPEG_SetMaxDecodeResolution (MS_U16 u16Width, MS_U16 u16Height) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetMaxDecodeResolution (MS_U16 u16Width, MS_U16 u16Height)
{
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_BlockErase(MS_U32, MS_U32, MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_BlockErase (MS_U32 u32StartBlock, MS_U32 u32EndBlock, MS_BOOL bWait) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_BlockErase (MS_U32 u32StartBlock, MS_U32 u32EndBlock, MS_BOOL bWait)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MApi_GOP_GWIN_Get_HSTART(void) */
EXTERN_C_LINKAGE MS_U16 MApi_GOP_GWIN_Get_HSTART () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_GOP_GWIN_Get_HSTART (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: void MApi_XC_ACE_SetColorMatrix(MS_BOOL, MS_U16 *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_SetColorMatrix (MS_BOOL eWindow, MS_U16 * pu16Matrix) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_SetColorMatrix (MS_BOOL eWindow, MS_U16 * pu16Matrix)
{
}

/** User stub definition for function: E_APIXC_ReturnValue MApi_XC_Init_MISC(XC_INITMISC *, MS_U32) */
EXTERN_C_LINKAGE E_APIXC_ReturnValue MApi_XC_Init_MISC (XC_INITMISC * pXC_Init_Misc, MS_U32 u32InitMiscDataLen) ;
EXTERN_C_LINKAGE E_APIXC_ReturnValue CppTest_Stub_MApi_XC_Init_MISC (XC_INITMISC * pXC_Init_Misc, MS_U32 u32InitMiscDataLen)
{
    return E_APIXC_RET_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_DMX_TTX_PacketBufferIsEmpty(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMX_TTX_PacketBufferIsEmpty () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMX_TTX_PacketBufferIsEmpty (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void mapi_mhl_CbusWakeupIntSetting(void) */
EXTERN_C_LINKAGE void mapi_mhl_CbusWakeupIntSetting () ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_CbusWakeupIntSetting (void)
{
}

/** User stub definition for function: void MApi_XC_DLC_CGC_Reset(void) */
EXTERN_C_LINKAGE void MApi_XC_DLC_CGC_Reset () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_CGC_Reset (void)
{
}

/** User stub definition for function: MS_BOOL MDrv_DSCMB_Init(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DSCMB_Init () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DSCMB_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_SetPCYUV2RGB(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_ACE_SetPCYUV2RGB (MS_BOOL eWindow, MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_SetPCYUV2RGB (MS_BOOL eWindow, MS_BOOL bEnable)
{
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_GetUCS1EventName(EventIndex, U8 *, U8) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_GetUCS1EventName (EventIndex event, U8 * pName, U8 length) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_GetUCS1EventName (EventIndex event, U8 * pName, U8 length)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: U32 __MDrv_Read3Byte(U32) */
EXTERN_C_LINKAGE U32 __MDrv_Read3Byte (U32 u32Reg) ;
EXTERN_C_LINKAGE U32 CppTest_Stub___MDrv_Read3Byte (U32 u32Reg)
{
    return 0UL;
}

/** User stub definition for function: void MApi_XC_DLC_EnableMainSubCurveSynchronization(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_XC_DLC_EnableMainSubCurveSynchronization (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_EnableMainSubCurveSynchronization (MS_BOOL bEnable)
{
}

/** User stub definition for function: void MApi_XC_DLC_SetCaptureRange(XC_DLC_CAPTURE_Range *) */
EXTERN_C_LINKAGE void MApi_XC_DLC_SetCaptureRange (XC_DLC_CAPTURE_Range * pu16_Range) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DLC_SetCaptureRange (XC_DLC_CAPTURE_Range * pu16_Range)
{
}

/** User stub definition for function: BOOLEAN msAPI_CI_GetCIS(U8 *, U8 *, U8 *, U8 *, U8 *, U8 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_GetCIS (U8 * pu8Manufacturer, U8 * pu8ManufacturerLen, U8 * pu8Product, U8 * pu8ProductLen, U8 * pu8Info1, U8 * pu8Info1Len) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_GetCIS (U8 * pu8Manufacturer, U8 * pu8ManufacturerLen, U8 * pu8Product, U8 * pu8ProductLen, U8 * pu8Info1, U8 * pu8Info1Len)
{
    return (unsigned char)0;
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_UserCtrlPressed(MS_BOOL, MsCEC_DEVICELA, MsCEC_MSG_USER_CTRL_PARM) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_UserCtrlPressed (MS_BOOL bUserCtrlEn, MsCEC_DEVICELA dst_address, MsCEC_MSG_USER_CTRL_PARM cmd) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_UserCtrlPressed (MS_BOOL bUserCtrlEn, MsCEC_DEVICELA dst_address, MsCEC_MSG_USER_CTRL_PARM cmd)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: void MApi_XC_SetBorderFormat(MS_U8, MS_U8, MS_U8, MS_U8, MS_U8, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetBorderFormat (MS_U8 u8Left, MS_U8 u8Right, MS_U8 u8Up, MS_U8 u8Down, MS_U8 u8color, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetBorderFormat (MS_U8 u8Left, MS_U8 u8Right, MS_U8 u8Up, MS_U8 u8Down, MS_U8 u8color, SCALER_WIN eWindow)
{
}

/** User stub definition for function: E_XC_3D_INPUT_MODE MDrv_HDMI_Get_3D_Structure(void) */
EXTERN_C_LINKAGE E_XC_3D_INPUT_MODE MDrv_HDMI_Get_3D_Structure () ;
EXTERN_C_LINKAGE E_XC_3D_INPUT_MODE CppTest_Stub_MDrv_HDMI_Get_3D_Structure (void)
{
    return E_XC_3D_INPUT_FRAME_PACKING;
}

/** User stub definition for function: MS_U8 MApi_SWI2C_GetByte(MS_U16) */
EXTERN_C_LINKAGE MS_U8 MApi_SWI2C_GetByte (MS_U16 u16Ack) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_SWI2C_GetByte (MS_U16 u16Ack)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_DVI_ClkPullLow(MS_BOOL, E_MUX_INPUTPORT) */
EXTERN_C_LINKAGE void MDrv_DVI_ClkPullLow (MS_BOOL bPullLow, E_MUX_INPUTPORT enInputPortType) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_DVI_ClkPullLow (MS_BOOL bPullLow, E_MUX_INPUTPORT enInputPortType)
{
}

/** User stub definition for function: void MApp_SI_Free_NetworkChangeInfo(void) */
EXTERN_C_LINKAGE void MApp_SI_Free_NetworkChangeInfo () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Free_NetworkChangeInfo (void)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetMirror(MS_BOOL, MS_BOOL) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetMirror (MS_BOOL isMirrorX, MS_BOOL isMirrorY) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetMirror (MS_BOOL isMirrorX, MS_BOOL isMirrorY)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_U8 MApi_AUDIO_SIF_GetSoundMode(void) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_SIF_GetSoundMode () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_SIF_GetSoundMode (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_PNL_PreInit(E_PNL_PREINIT_OPTIONS) */
EXTERN_C_LINKAGE MS_BOOL MApi_PNL_PreInit (E_PNL_PREINIT_OPTIONS eInitParam) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_PNL_PreInit (E_PNL_PREINIT_OPTIONS eInitParam)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U16 MApi_JPEG_GetOriginalHeight(void) */
EXTERN_C_LINKAGE MS_U16 MApi_JPEG_GetOriginalHeight () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_JPEG_GetOriginalHeight (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_GetDecFrameInfo(VDEC_FrameInfo *) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_GetDecFrameInfo (VDEC_FrameInfo * pFrmInfo) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_GetDecFrameInfo (VDEC_FrameInfo * pFrmInfo)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Exit(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Exit () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Exit (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: U16 MApp_Dmx_GetCITuneServiceId(void) */
EXTERN_C_LINKAGE U16 MApp_Dmx_GetCITuneServiceId () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_MApp_Dmx_GetCITuneServiceId (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_BOOL MApi_JPEG_ThumbnailFound(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_JPEG_ThumbnailFound () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_JPEG_ThumbnailFound (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_SetCaptureWindowVstart(MS_U16, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetCaptureWindowVstart (MS_U16 u16Vstart, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetCaptureWindowVstart (MS_U16 u16Vstart, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MDrv_FLASH_Write(MS_U32, MS_U32, MS_U8 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_FLASH_Write (MS_U32 u32FlashAddr, MS_U32 u32FlashSize, MS_U8 * user_buffer) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_FLASH_Write (MS_U32 u32FlashAddr, MS_U32 u32FlashSize, MS_U8 * user_buffer)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_SWI2C_Init(SWI2C_BusCfg *, MS_U8) */
EXTERN_C_LINKAGE void MApi_SWI2C_Init (SWI2C_BusCfg  SWI2CBusCfg[], MS_U8 u8CfgBusNum) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_SWI2C_Init (SWI2C_BusCfg  SWI2CBusCfg[], MS_U8 u8CfgBusNum)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_Action_CheckServiceInfo(SI_DTV_CHANNEL_INFO *) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Action_CheckServiceInfo (SI_DTV_CHANNEL_INFO * pstVirtualCh) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Action_CheckServiceInfo (SI_DTV_CHANNEL_INFO * pstVirtualCh)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U32 MDrv_PM_RTCGetSystemTime(void) */
BOOL btest_msAPI_Timer_SyncToPmRTC = FALSE;
EXTERN_C_LINKAGE MS_U32 MDrv_PM_RTCGetSystemTime () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_PM_RTCGetSystemTime (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SyncToPmRTC"))
	{
		btest_msAPI_Timer_SyncToPmRTC = TRUE;
		return (unsigned char)100;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_GetRTCSystemTime"))
	{
		return (unsigned char)101;
	}
	else
	{
    return 0UL;
}
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_CreateFB(MS_U8, MS_U16, MS_U16, MS_U16, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_CreateFB (MS_U8 fbId, MS_U16 dispX, MS_U16 dispY, MS_U16 width, MS_U16 height, MS_U16 fbFmt) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_CreateFB (MS_U8 fbId, MS_U16 dispX, MS_U16 dispY, MS_U16 width, MS_U16 height, MS_U16 fbFmt)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_VE_SwitchInputSource(PMS_Switch_VE_Src_Info) */
EXTERN_C_LINKAGE void MDrv_VE_SwitchInputSource (PMS_Switch_VE_Src_Info pSwitchInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VE_SwitchInputSource (PMS_Switch_VE_Src_Info pSwitchInfo)
{
}

/** User stub definition for function: MS_BOOL MDrv_DMX_TTX_PacketBufferIsOverflow(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMX_TTX_PacketBufferIsOverflow () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMX_TTX_PacketBufferIsOverflow (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Stc_Get(MS_U32 *, MS_U32 *) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Stc_Get (MS_U32 * pu32Stc32, MS_U32 * pu32Stc) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Stc_Get (MS_U32 * pu32Stc32, MS_U32 * pu32Stc)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF")||
	    CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF1")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_ELSE1")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF_IF")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_ELSE"))
	{
		* pu32Stc32 = 0;
		* pu32Stc = 0;
	}else if (CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_IF"))
	{
		* pu32Stc32 = 0;
		* pu32Stc = 262053;

	}
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: BOOLEAN msAPI_CI_CC_GetCredentialsType(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CC_GetCredentialsType () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CC_GetCredentialsType (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_HDMI_SetDownSample(MS_U8) */
EXTERN_C_LINKAGE void MApi_AUDIO_HDMI_SetDownSample (MS_U8 ratio) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_HDMI_SetDownSample (MS_U8 ratio)
{
}

/** User stub definition for function: VDEC_Result MApi_VDEC_SetControl(VDEC_User_Cmd, MS_U32) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_SetControl (VDEC_User_Cmd cmd_id, MS_U32 param) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_SetControl (VDEC_User_Cmd cmd_id, MS_U32 param)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_SetReg(MS_U16, MS_U8) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_SetReg (MS_U16 u16Addr, MS_U8 u8Data) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_SetReg (MS_U16 u16Addr, MS_U8 u8Data)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_XC_ACE_DNR_SetNRTbl(MS_U8 *) */
EXTERN_C_LINKAGE void MApi_XC_ACE_DNR_SetNRTbl (MS_U8 * pu8Tbl) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ACE_DNR_SetNRTbl (MS_U8 * pu8Tbl)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_Scan_End(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Scan_End () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Scan_End (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_Dmx_GetDeliveryDescriptorData(EN_DESCRIPTOR_TAG, void *, U8 *) */
EXTERN_C_LINKAGE BOOLEAN MApp_Dmx_GetDeliveryDescriptorData (EN_DESCRIPTOR_TAG enTag, void * punDesc, U8 * pu8Descp) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Dmx_GetDeliveryDescriptorData (EN_DESCRIPTOR_TAG enTag, void * punDesc, U8 * pu8Descp)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_XC_DLC_RESULT MApi_XC_DLC_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE E_XC_DLC_RESULT MApi_XC_DLC_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE E_XC_DLC_RESULT CppTest_Stub_MApi_XC_DLC_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_XC_DLC_FAIL;
}

/** User stub definition for function: void MApp_Dmx_PES_Stop(void) */
EXTERN_C_LINKAGE void MApp_Dmx_PES_Stop () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Dmx_PES_Stop (void)
{
}

/** User stub definition for function: void msAPI_Subtitle_Remove(U32) */
EXTERN_C_LINKAGE void msAPI_Subtitle_Remove (U32 u32STC) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_Remove (U32 u32STC)
{
}

/** User stub definition for function: void msAPI_Subtitle_Remove_Expired(U32) */
EXTERN_C_LINKAGE void msAPI_Subtitle_Remove_Expired (U32 u32STC) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Subtitle_Remove_Expired (U32 u32STC)
{
}

/** User stub definition for function: MS_U8 MApi_AUDIO_SPDIF_GetSCMS(void) */
EXTERN_C_LINKAGE MS_U8 MApi_AUDIO_SPDIF_GetSCMS () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_AUDIO_SPDIF_GetSCMS (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MDrv_AVD_SetFlag(MS_U32) */
EXTERN_C_LINKAGE void MDrv_AVD_SetFlag (MS_U32 u32VDPatchFlag) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_SetFlag (MS_U32 u32VDPatchFlag)
{
}

/** User stub definition for function: MS_U16 MApi_XC_ACE_GetACEInfo(MS_BOOL, E_XC_ACE_INFOTYPE) */
EXTERN_C_LINKAGE MS_U16 MApi_XC_ACE_GetACEInfo (MS_BOOL bWindow, E_XC_ACE_INFOTYPE eXCACEInfoType) ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_XC_ACE_GetACEInfo (MS_BOOL bWindow, E_XC_ACE_INFOTYPE eXCACEInfoType)
{
    return (unsigned short)0;
}

/** User stub definition for function: U8 MApp_SI_Get_PSISIVersion(E_PSI_SI_VERSION) */
EXTERN_C_LINKAGE U8 MApp_SI_Get_PSISIVersion (E_PSI_SI_VERSION eVerMember) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_SI_Get_PSISIVersion (E_PSI_SI_VERSION eVerMember)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApi_AUDIO_EnableTone(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_AUDIO_EnableTone (MS_BOOL EnTone) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_EnableTone (MS_BOOL EnTone)
{
}

/** User stub definition for function: void MApi_XC_GetSyncStatus(INPUT_SOURCE_TYPE_t, XC_IP_SYNC_STATUS *, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_GetSyncStatus (INPUT_SOURCE_TYPE_t eCurrentSrc, XC_IP_SYNC_STATUS * sXC_Sync_Status, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_GetSyncStatus (INPUT_SOURCE_TYPE_t eCurrentSrc, XC_IP_SYNC_STATUS * sXC_Sync_Status, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_HDMI_GetNonpcmFlag(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_HDMI_GetNonpcmFlag () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_HDMI_GetNonpcmFlag (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: float powf(float, float) */
EXTERN_C_LINKAGE float powf (float __x, float __y) ;
EXTERN_C_LINKAGE float CppTest_Stub_powf (float __x, float __y)
{
    return 0.0f;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_AVSyncOn(MS_BOOL, MS_U32, MS_U16) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_AVSyncOn (MS_BOOL bOn, MS_U32 u32SyncDelay, MS_U16 u16SyncTolerance) ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_AVSyncOn (MS_BOOL bOn, MS_U32 u32SyncDelay, MS_U16 u16SyncTolerance)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_XC_ADC_Set_SOGBW(MS_U16) */
EXTERN_C_LINKAGE void MApi_XC_ADC_Set_SOGBW (MS_U16 u16value) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_Set_SOGBW (MS_U16 u16value)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_WaitFPLLDone(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_WaitFPLLDone () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_WaitFPLLDone (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_Dmx_GetScanTables(SCAN_TABLE_CONFIG *, U8 *) */
EXTERN_C_LINKAGE BOOLEAN MApp_Dmx_GetScanTables (SCAN_TABLE_CONFIG * stScanConfig, U8 * u8FoundNum) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Dmx_GetScanTables (SCAN_TABLE_CONFIG * stScanConfig, U8 * u8FoundNum)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_Dmx_AstraHD_GetScanTables(SCAN_TABLE_CONFIG *, U8 *) */
/*EXTERN_C_LINKAGE BOOLEAN MApp_Dmx_AstraHD_GetScanTables (SCAN_TABLE_CONFIG * stScanConfig, U8 * u8FoundNum) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Dmx_AstraHD_GetScanTables (SCAN_TABLE_CONFIG * stScanConfig, U8 * u8FoundNum)
{
    return (unsigned char)0;
}*/

/** User stub definition for function: BOOLEAN msAPI_MVF_init_mempool(void *, U32) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MVF_init_mempool (void * pool, U32 size) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MVF_init_mempool (void * pool, U32 size)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 * MApp_Dmx_GetFid(EN_FID) */
EXTERN_C_LINKAGE U8 * MApp_Dmx_GetFid (EN_FID eFid) ;
EXTERN_C_LINKAGE U8 * CppTest_Stub_MApp_Dmx_GetFid (EN_FID eFid)
{
    return (U8 *)0;
}

/** User stub definition for function: void msAPI_CI_MMIClose(void) */
EXTERN_C_LINKAGE void msAPI_CI_MMIClose () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_MMIClose (void)
{
}

/** User stub definition for function: void MApi_XC_SetCaptureWindowHstart(MS_U16, SCALER_WIN) */
EXTERN_C_LINKAGE void MApi_XC_SetCaptureWindowHstart (MS_U16 u16Hstart, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_SetCaptureWindowHstart (MS_U16 u16Hstart, SCALER_WIN eWindow)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_ACE_MWEStatus(void) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_ACE_MWEStatus () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_ACE_MWEStatus (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void * MsOS_AllocateMemory(MS_U32, MS_S32) */
EXTERN_C_LINKAGE void * MsOS_AllocateMemory (MS_U32 u32Size, MS_S32 s32PoolId) ;
EXTERN_C_LINKAGE void * CppTest_Stub_MsOS_AllocateMemory (MS_U32 u32Size, MS_S32 s32PoolId)
{
    return (void *)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsReachSync(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsReachSync () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsReachSync (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void MApi_AUDIO_SIF_SetThreshold(THR_TBL_TYPE *) */
EXTERN_C_LINKAGE void MApi_AUDIO_SIF_SetThreshold (THR_TBL_TYPE * ThrTbl) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SIF_SetThreshold (THR_TBL_TYPE * ThrTbl)
{
}

/** User stub definition for function: MS_BOOL MDrv_DMX_TTX_GetPacket(MS_PHYADDR *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMX_TTX_GetPacket (MS_PHYADDR * packetAddress) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMX_TTX_GetPacket (MS_PHYADDR * packetAddress)
{
    return (unsigned char)0;
}

/** User stub definition for function: signed long ms_MVF_MakeFont2(void) */
EXTERN_C_LINKAGE signed long ms_MVF_MakeFont2 () ;
EXTERN_C_LINKAGE signed long CppTest_Stub_ms_MVF_MakeFont2 (void)
{
    return 0L;
}

/** User stub definition for function: BOOLEAN MApp_Dmx_GetMonitorStatus(EN_MONITOR_TABLE) */
EXTERN_C_LINKAGE BOOLEAN MApp_Dmx_GetMonitorStatus (EN_MONITOR_TABLE eTable) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Dmx_GetMonitorStatus (EN_MONITOR_TABLE eTable)
{
    return (unsigned char)0;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Rst(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Rst () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Rst (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_SetSerialControl(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_SetSerialControl (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_SetSerialControl (MS_BOOL bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_CI_InstallCallback_CI_Event(f_CI_Event_Callback) */
EXTERN_C_LINKAGE void msAPI_CI_InstallCallback_CI_Event (f_CI_Event_Callback fnCallback_f_CI_Event) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_InstallCallback_CI_Event (f_CI_Event_Callback fnCallback_f_CI_Event)
{
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_ReleaseAccess(void) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_ReleaseAccess () ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_ReleaseAccess (void)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MApi_XC_IsFreezeImg(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_IsFreezeImg (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_IsFreezeImg (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void UsbPort2UTMIInitial(void) */
EXTERN_C_LINKAGE void UsbPort2UTMIInitial () ;
EXTERN_C_LINKAGE void CppTest_Stub_UsbPort2UTMIInitial (void)
{
}

/** User stub definition for function: MS_BOOL MApi_XC_GetStatus(XC_ApiStatus *, SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_GetStatus (XC_ApiStatus * pDrvStatus, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_GetStatus (XC_ApiStatus * pDrvStatus, SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: void srand(unsigned int) */
EXTERN_C_LINKAGE void srand (unsigned __seed) ;
EXTERN_C_LINKAGE void CppTest_Stub_srand (unsigned __seed)
{
}

/** User stub definition for function: BOOLEAN _MApp_SI_IsServiceMove(U16, U16) */
EXTERN_C_LINKAGE BOOLEAN _MApp_SI_IsServiceMove (U16 u16SID, U16 u16LCN) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_SI_IsServiceMove (U16 u16SID, U16 u16LCN)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MsOS_Sync(void) */
EXTERN_C_LINKAGE void MsOS_Sync () ;
EXTERN_C_LINKAGE void CppTest_Stub_MsOS_Sync (void)
{
}

/** User stub definition for function: MS_U8 MApi_XC_GetVSyncWidth(SCALER_WIN) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_GetVSyncWidth (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_GetVSyncWidth (SCALER_WIN eWindow)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_VE_SetOutputVideoStd(MS_VE_VIDEOSYS) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VE_SetOutputVideoStd (MS_VE_VIDEOSYS VideoSystem) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VE_SetOutputVideoStd (MS_VE_VIDEOSYS VideoSystem)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_SI_Scan_Init(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Scan_Init () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Scan_Init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MApi_GFX_BitBlt(GFX_DrawRect *, MS_U32) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_BitBlt (GFX_DrawRect * drawbuf, MS_U32 drawflag) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_BitBlt (GFX_DrawRect * drawbuf, MS_U32 drawflag)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_CheckWriteDone(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_CheckWriteDone () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_CheckWriteDone (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Start(MS_U8) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Start (MS_U8 u8DmxId) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Start (MS_U8 u8DmxId)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_CheckDispInfoRdy(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_CheckDispInfoRdy () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_CheckDispInfoRdy (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_VBI_TTX_GetPacket(MS_PHYADDR *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_TTX_GetPacket (MS_PHYADDR * packetAddress) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_TTX_GetPacket (MS_PHYADDR * packetAddress)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_CIMSG_TYPE msAPI_CI_GetCIMessageType(void) */
EXTERN_C_LINKAGE E_CIMSG_TYPE msAPI_CI_GetCIMessageType () ;
EXTERN_C_LINKAGE E_CIMSG_TYPE CppTest_Stub_msAPI_CI_GetCIMessageType (void)
{
    return EN_CIMSG_NONE;
}

/** User stub definition for function: void mapi_mhl_VbusConfigSetting(MS_U8) */
EXTERN_C_LINKAGE void mapi_mhl_VbusConfigSetting (MS_U8 ucState) ;
EXTERN_C_LINKAGE void CppTest_Stub_mapi_mhl_VbusConfigSetting (MS_U8 ucState)
{
}

/** User stub definition for function: void msAPI_CI_NotifyCurrentPMTUpdate(U8 *, U16) */
EXTERN_C_LINKAGE void msAPI_CI_NotifyCurrentPMTUpdate (U8 * pu8PMTSection, U16 u16PMTLength) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_NotifyCurrentPMTUpdate (U8 * pu8PMTSection, U16 u16PMTLength)
{
}

/** User stub definition for function: MS_U32 MApi_AUDIO_GetWmaInfo(Audio_WMA_infoType) */
EXTERN_C_LINKAGE MS_U32 MApi_AUDIO_GetWmaInfo (Audio_WMA_infoType infoType) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_AUDIO_GetWmaInfo (Audio_WMA_infoType infoType)
{
    return 0UL;
}

/** User stub definition for function: void MApp_SI_Force_PAT_Parse(void) */
EXTERN_C_LINKAGE void MApp_SI_Force_PAT_Parse () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_Force_PAT_Parse (void)
{
}

/** User stub definition for function: BOOLEAN MApp_SI_Is_NetworkChange(BOOLEAN *, BOOLEAN *, BOOLEAN *, BOOLEAN *) */
EXTERN_C_LINKAGE BOOLEAN MApp_SI_Is_NetworkChange (BOOLEAN * bMuxAdd, BOOLEAN * bMuxRemove, BOOLEAN * bCellRemove, BOOLEAN * bFreqChange) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SI_Is_NetworkChange (BOOLEAN * bMuxAdd, BOOLEAN * bMuxRemove, BOOLEAN * bCellRemove, BOOLEAN * bFreqChange)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U32 MApi_AUDIO_GetAC3Info(Audio_AC3_infoType) */
EXTERN_C_LINKAGE MS_U32 MApi_AUDIO_GetAC3Info (Audio_AC3_infoType infoType) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_AUDIO_GetAC3Info (Audio_AC3_infoType infoType)
{
    return 0UL;
}

/** User stub definition for function: void MApi_AUDIO_InputSwitch(AUDIO_INPUT_TYPE, AUDIO_SWITCH_GROUP) */
EXTERN_C_LINKAGE void MApi_AUDIO_InputSwitch (AUDIO_INPUT_TYPE enSource, AUDIO_SWITCH_GROUP enGroup) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_InputSwitch (AUDIO_INPUT_TYPE enSource, AUDIO_SWITCH_GROUP enGroup)
{
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsAVSyncOn(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsAVSyncOn () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsAVSyncOn (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: void msAPI_CI_SetPMTBufAddr(U32) */
EXTERN_C_LINKAGE void msAPI_CI_SetPMTBufAddr (U32 u32BufAdr) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_SetPMTBufAddr (U32 u32BufAdr)
{
}

/** User stub definition for function: MS_U16 MApi_JPEG_GetAlignedHeight(void) */
EXTERN_C_LINKAGE MS_U16 MApi_JPEG_GetAlignedHeight () ;
EXTERN_C_LINKAGE MS_U16 CppTest_Stub_MApi_JPEG_GetAlignedHeight (void)
{
    return (unsigned short)0;
}

/** User stub definition for function: MS_BOOL MDrv_VBI_IsVPS_Ready(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_IsVPS_Ready () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_IsVPS_Ready (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: DMX_FILTER_STATUS MApi_DMX_Close(MS_U8) */
EXTERN_C_LINKAGE DMX_FILTER_STATUS MApi_DMX_Close (MS_U8 u8DmxId) ;
EXTERN_C_LINKAGE DMX_FILTER_STATUS CppTest_Stub_MApi_DMX_Close (MS_U8 u8DmxId)
{
    return DMX_FILTER_STATUS_OK;
}

/** User stub definition for function: MS_BOOL MApi_JPEG_GetMPOIndex(JPEG_MPO_INDEX_INFO **) */
EXTERN_C_LINKAGE MS_BOOL MApi_JPEG_GetMPOIndex (JPEG_MPO_INDEX_INFO ** ppMPOIndex) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_JPEG_GetMPOIndex (JPEG_MPO_INDEX_INFO ** ppMPOIndex)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_SI_ResetNetworkNewService(void) */
EXTERN_C_LINKAGE void MApp_SI_ResetNetworkNewService () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SI_ResetNetworkNewService (void)
{
}

/** User stub definition for function: void MApi_XC_DisableSubWindow(void) */
EXTERN_C_LINKAGE void MApi_XC_DisableSubWindow () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_DisableSubWindow (void)
{
}

/** User stub definition for function: void MApi_AUDIO_SetPEQCoef(AUDIO_PEQ_COEF *) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetPEQCoef (AUDIO_PEQ_COEF * peq_coef) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetPEQCoef (AUDIO_PEQ_COEF * peq_coef)
{
}

/** User stub definition for function: BDMA_Result MDrv_BDMA_CopyHnd(MS_PHYADDR, MS_PHYADDR, MS_U32, BDMA_CpyType, MS_U8) */
EXTERN_C_LINKAGE BDMA_Result MDrv_BDMA_CopyHnd (MS_PHYADDR u32SrcAddr, MS_PHYADDR u32DstAddr, MS_U32 u32Len, BDMA_CpyType eCpyType, MS_U8 u8OpCfg) ;
EXTERN_C_LINKAGE BDMA_Result CppTest_Stub_MDrv_BDMA_CopyHnd (MS_PHYADDR u32SrcAddr, MS_PHYADDR u32DstAddr, MS_U32 u32Len, BDMA_CpyType eCpyType, MS_U8 u8OpCfg)
{
    return E_BDMA_NOT_SUPPORT;
}

/** User stub definition for function: VDEC_Result MApi_VDEC_Play(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_Play () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_Play (void)
{
    return E_VDEC_FAIL;
}

/** User stub definition for function: MS_BOOL MDrv_AVD_ForceVideoStandard(AVD_VideoStandardType) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AVD_ForceVideoStandard (AVD_VideoStandardType eVideoStandardType) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AVD_ForceVideoStandard (AVD_VideoStandardType eVideoStandardType)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN msAPI_CI_CC_SetFID(U8, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CI_CC_SetFID (U8 u8Fid, BOOLEAN bEnable) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CI_CC_SetFID (U8 u8Fid, BOOLEAN bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN DRV_VIF_SetParameter(VIF_PARA_GROUP, void *, MS_U32) */
EXTERN_C_LINKAGE BOOLEAN DRV_VIF_SetParameter (VIF_PARA_GROUP paraGroup, void * pVIF_Para, MS_U32 u32DataLen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_DRV_VIF_SetParameter (VIF_PARA_GROUP paraGroup, void * pVIF_Para, MS_U32 u32DataLen)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_SwUpdate_Start(EN_SW_UPDATE_MODE, BOOLEAN, BOOLEAN, BOOLEAN, U32, U32, U8, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN MApp_SwUpdate_Start (EN_SW_UPDATE_MODE u8UpdateMode, BOOLEAN allowTwoFlashMode, BOOLEAN bDownloadType, BOOLEAN bSecondRun, U32 u32DramStartAddr, U32 u32FileSize, U8 u8MemType, BOOLEAN bAPBinFlag) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_SwUpdate_Start (EN_SW_UPDATE_MODE u8UpdateMode, BOOLEAN allowTwoFlashMode, BOOLEAN bDownloadType, BOOLEAN bSecondRun, U32 u32DramStartAddr, U32 u32FileSize, U8 u8MemType, BOOLEAN bAPBinFlag)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_VDEC_GetStatus(VDEC_Status *) */
EXTERN_C_LINKAGE MS_BOOL MApi_VDEC_GetStatus (VDEC_Status * pStatus) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_VDEC_GetStatus (VDEC_Status * pStatus)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType, MS_U32, MS_U32) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetMpegInfo (Audio_MPEG_infoType infoType, MS_U32 param1, MS_U32 param2) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetMpegInfo (Audio_MPEG_infoType infoType, MS_U32 param1, MS_U32 param2)
{
    return (unsigned char)0;
}

/** User stub definition for function: EN_CI_VERSION msAPI_CI_CC_CAM_Mode(void) */
EXTERN_C_LINKAGE EN_CI_VERSION msAPI_CI_CC_CAM_Mode () ;
EXTERN_C_LINKAGE EN_CI_VERSION CppTest_Stub_msAPI_CI_CC_CAM_Mode (void)
{
    return EN_CI_IVALID_VERSION;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_GetTPSInfo(MS_U16 *) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_GetTPSInfo (MS_U16 * u16Info) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_GetTPSInfo (MS_U16 * u16Info)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_AUD_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE MS_BOOL MDrv_AUD_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_AUD_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: int memcmp(const void *, const void *, size_t) */
EXTERN_C_LINKAGE int memcmp (const void * __s1, const void * __s2, size_t __n) ;
EXTERN_C_LINKAGE int CppTest_Stub_memcmp (const void * __s1, const void * __s2, size_t __n)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1"))
  {
      return (int)0;
  }
    return 0;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_IsGwinExist(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_IsGwinExist (MS_U8 gId) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_IsGwinExist (MS_U8 gId)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_DMD_DVBT_SetActive(MS_BOOL) */
EXTERN_C_LINKAGE MS_BOOL MDrv_DMD_DVBT_SetActive (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_DMD_DVBT_SetActive (MS_BOOL bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: double ceil(double) */
EXTERN_C_LINKAGE double ceil (double __x) ;
EXTERN_C_LINKAGE double CppTest_Stub_ceil (double __x)
{
    return 0.0;
}

/** User stub definition for function: CEC_ERROR_CODE MApi_CEC_Msg_ReportPowerStatus(MsCEC_DEVICELA) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MApi_CEC_Msg_ReportPowerStatus (MsCEC_DEVICELA dst_address) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MApi_CEC_Msg_ReportPowerStatus (MsCEC_DEVICELA dst_address)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: void MDrv_MVOP_EnableBlackBG(void) */
EXTERN_C_LINKAGE void MDrv_MVOP_EnableBlackBG () ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_MVOP_EnableBlackBG (void)
{
}

/** User stub definition for function: void MDrv_AVD_Set3dComb(MS_BOOL) */
EXTERN_C_LINKAGE void MDrv_AVD_Set3dComb (MS_BOOL bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_AVD_Set3dComb (MS_BOOL bEnable)
{
}

/** User stub definition for function: GFX_Result MDrv_GE_SetAlphaBlending(GFX_BlendCoef, MS_U8) */
EXTERN_C_LINKAGE GFX_Result MDrv_GE_SetAlphaBlending (GFX_BlendCoef blendcoef, MS_U8 u8ConstantAlpha) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MDrv_GE_SetAlphaBlending (GFX_BlendCoef blendcoef, MS_U8 u8ConstantAlpha)
{
    return GFX_FAIL;
}

/** User stub definition for function: BOOLEAN MApp_EIT_Is_Cur_PF_Change(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_EIT_Is_Cur_PF_Change () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_EIT_Is_Cur_PF_Change (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: const __int32_t ** __ctype_toupper_loc(void) */
EXTERN_C_LINKAGE const __int32_t ** __ctype_toupper_loc () ;
EXTERN_C_LINKAGE const __int32_t ** CppTest_Stub___ctype_toupper_loc (void)
{
    return (const __int32_t **)0;
}

/** User stub definition for function: MS_BOOL MDrv_VBI_TTX_PacketBufferIsOverflow(void) */
EXTERN_C_LINKAGE MS_BOOL MDrv_VBI_TTX_PacketBufferIsOverflow () ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_VBI_TTX_PacketBufferIsOverflow (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_UpdateRegOnce(MS_BOOL) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_UpdateRegOnce (MS_BOOL bWriteRegOnce) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_UpdateRegOnce (MS_BOOL bWriteRegOnce)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MApi_XC_ADC_GetDefaultGainOffset(INPUT_SOURCE_TYPE_t, APIXC_AdcGainOffsetSetting *) */
EXTERN_C_LINKAGE void MApi_XC_ADC_GetDefaultGainOffset (INPUT_SOURCE_TYPE_t eSource, APIXC_AdcGainOffsetSetting * pstADCSetting) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_ADC_GetDefaultGainOffset (INPUT_SOURCE_TYPE_t eSource, APIXC_AdcGainOffsetSetting * pstADCSetting)
{
}

/** User stub definition for function: JPEG_Result MApi_JPEG_GetBuffLoadType(JPEG_BuffLoadType *) */
EXTERN_C_LINKAGE JPEG_Result MApi_JPEG_GetBuffLoadType (JPEG_BuffLoadType * pBuffLoadType) ;
EXTERN_C_LINKAGE JPEG_Result CppTest_Stub_MApi_JPEG_GetBuffLoadType (JPEG_BuffLoadType * pBuffLoadType)
{
    return E_JPEG_FAILED;
}

/** User stub definition for function: MS_U32 MDrv_AVD_GetFlag(void) */
EXTERN_C_LINKAGE MS_U32 MDrv_AVD_GetFlag () ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MDrv_AVD_GetFlag (void)
{
    return 0UL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_RegisterEventNotify(void (*)(MS_U32, void *)) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_RegisterEventNotify (void (* fpGOP_CB)(MS_U32, void *)) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_RegisterEventNotify (void (* fpGOP_CB)(MS_U32, void *))
{
    return GOP_API_FAIL;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_GetTotalGwinNum(void) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_GetTotalGwinNum () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_GetTotalGwinNum (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MDrv_SERFLASH_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE MS_BOOL MDrv_SERFLASH_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MDrv_SERFLASH_GetLibVer (const MSIF_Version ** ppVersion)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_CI_MMIAnswerMenu(U8) */
EXTERN_C_LINKAGE void msAPI_CI_MMIAnswerMenu (U8 u8Choice) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_CI_MMIAnswerMenu (U8 u8Choice)
{
}

/** User stub definition for function: HDMI_Ret_Value MDrv_HDMI_GetLibVer(const MSIF_Version **) */
EXTERN_C_LINKAGE HDMI_Ret_Value MDrv_HDMI_GetLibVer (const MSIF_Version ** ppVersion) ;
EXTERN_C_LINKAGE HDMI_Ret_Value CppTest_Stub_MDrv_HDMI_GetLibVer (const MSIF_Version ** ppVersion)
{
    return E_HDMI_RET_FAIL;
}

/** User stub definition for function: MW_EN_EPG_FUNC_STATUS MApp_Epg_EventFindByTime(MEMBER_SI_SERVICETYPE, U16, U32, EventIndex *) */
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS MApp_Epg_EventFindByTime (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, U32 u32BaseTime, EventIndex * pEvent) ;
EXTERN_C_LINKAGE MW_EN_EPG_FUNC_STATUS CppTest_Stub_MApp_Epg_EventFindByTime (MEMBER_SI_SERVICETYPE enSrvType, U16 u16SrvPos, U32 u32BaseTime, EventIndex * pEvent)
{
    return MW_EN_EPG_FUNC_STATUS_SUCCESS;
}

/** User stub definition for function: GFX_Result MApi_GFX_SetDC_CSC_FMT(GFX_YUV_Rgb2Yuv, GFX_YUV_OutRange, GFX_YUV_InRange, GFX_YUV_422, GFX_YUV_422) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetDC_CSC_FMT (GFX_YUV_Rgb2Yuv mode, GFX_YUV_OutRange yuv_out_range, GFX_YUV_InRange uv_in_range, GFX_YUV_422 srcfmt, GFX_YUV_422 dstfmt) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetDC_CSC_FMT (GFX_YUV_Rgb2Yuv mode, GFX_YUV_OutRange yuv_out_range, GFX_YUV_InRange uv_in_range, GFX_YUV_422 srcfmt, GFX_YUV_422 dstfmt)
{
    return GFX_FAIL;
}

/** User stub definition for function: E_GOP_API_Result MApi_GOP_GWIN_SetHDisplaySize(MS_U8, MS_U16, MS_U16) */
EXTERN_C_LINKAGE E_GOP_API_Result MApi_GOP_GWIN_SetHDisplaySize (MS_U8 gId, MS_U16 Width, MS_U16 X_Start) ;
EXTERN_C_LINKAGE E_GOP_API_Result CppTest_Stub_MApi_GOP_GWIN_SetHDisplaySize (MS_U8 gId, MS_U16 Width, MS_U16 X_Start)
{
    return GOP_API_FAIL;
}

/** User stub definition for function: void MDrv_VBI_InitializeTTXSlicer(MS_PHYADDR, MS_U16) */
EXTERN_C_LINKAGE void MDrv_VBI_InitializeTTXSlicer (MS_PHYADDR bufferAddr, MS_U16 packetCount) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_VBI_InitializeTTXSlicer (MS_PHYADDR bufferAddr, MS_U16 packetCount)
{
}

/** User stub definition for function: GFX_Result MApi_GFX_SetDstBufferInfo(GFX_BufferInfo *, MS_U32) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetDstBufferInfo (GFX_BufferInfo * bufInfo, MS_U32 offsetofByte) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetDstBufferInfo (GFX_BufferInfo * bufInfo, MS_U32 offsetofByte)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_U8 MApi_XC_ACE_DNR_GetMotion(void) */
EXTERN_C_LINKAGE MS_U8 MApi_XC_ACE_DNR_GetMotion () ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_XC_ACE_DNR_GetMotion (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_BOOL MApi_AUDIO_SetDTSCommonCtrl(Audio_DTS_infoType, Audio_DTS_CtrlType) */
EXTERN_C_LINKAGE MS_BOOL MApi_AUDIO_SetDTSCommonCtrl (Audio_DTS_infoType infoType, Audio_DTS_CtrlType ctrl_type) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_AUDIO_SetDTSCommonCtrl (Audio_DTS_infoType infoType, Audio_DTS_CtrlType ctrl_type)
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_CreateWin2(MS_U16, MS_U16, MS_U16, EN_GOP_FRAMEBUFFER_STRING) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_CreateWin2 (MS_U16 width, MS_U16 height, MS_U16 fbFmt, EN_GOP_FRAMEBUFFER_STRING FBString) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_CreateWin2 (MS_U16 width, MS_U16 height, MS_U16 fbFmt, EN_GOP_FRAMEBUFFER_STRING FBString)
{
    return (unsigned char)0;
}

/** User stub definition for function: U8 MDrv_Usb_Device_Enum_EX(void) */
EXTERN_C_LINKAGE U8 MDrv_Usb_Device_Enum_EX () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MDrv_Usb_Device_Enum_EX (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: GFX_Result MDrv_GE_EnableAlphaBlending(MS_BOOL) */
EXTERN_C_LINKAGE GFX_Result MDrv_GE_EnableAlphaBlending (MS_BOOL enable) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MDrv_GE_EnableAlphaBlending (MS_BOOL enable)
{
    return GFX_FAIL;
}

/** User stub definition for function: MS_BOOL MApi_XC_PCMonitor_SyncLoss(SCALER_WIN) */
EXTERN_C_LINKAGE MS_BOOL MApi_XC_PCMonitor_SyncLoss (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApi_XC_PCMonitor_SyncLoss (SCALER_WIN eWindow)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_if") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_if_else") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_RGB_else_if2")
    )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: GFX_Result MApi_GFX_SetAlphaBlending(GFX_BlendCoef, MS_U8) */
EXTERN_C_LINKAGE GFX_Result MApi_GFX_SetAlphaBlending (GFX_BlendCoef blendcoef, MS_U8 blendfactor) ;
EXTERN_C_LINKAGE GFX_Result CppTest_Stub_MApi_GFX_SetAlphaBlending (GFX_BlendCoef blendcoef, MS_U8 blendfactor)
{
    return GFX_FAIL;
}

MS_U16 _GetPanelWidth(void)
{
	return 1920;
}
MS_U16 _GetPanelHigh(void)
{
	return 1920;
}

//XC_PNL_OBJ g_IPanel;
XC_PNL_OBJ g_IPanel =
{
    //
    //  Data
    //
    .Name            = NULL, // _getPanelName,
    .HStart          = NULL, // _getPanelHstart,
    .VStart          = NULL, // _getPanelVstart,
    .Width           = _GetPanelWidth, // _getPanelWidth,
    .Height          = _GetPanelHigh, // _getPanelHeight,
    .HTotal          = NULL, // _getPanelhtotal,
    .VTotal          = NULL, // _getPanelVtotal,
    .HSynWidth       = NULL, // _getPanelHSyncWidth,
    .HSynBackPorch   = NULL, // _getPanelHSyncBackPorch,
    .VSynBackPorch   = NULL, // _getPanelVSyncBackPorch,
    .DefaultVFreq    = NULL, // _getPanelDefVFreq,
    .LPLL_Mode       = NULL, // _getPanel_LPLL_Mode,            /* 0: single, 1: dual mode */
    .LPLL_Type       = NULL, // _getPanel_LPLL_Type,
    .AspectRatio     = NULL, // _getPanel_ARC,
    .MinSET          = NULL, // _getPanelMinSET,
    .MaxSET          = NULL, // _getPanelMaxSET,
    .OutTimingMode   = NULL, // _getOutTimingMode,
    // Manipulation
    //
    .SetSSC          = NULL, // _SetSSC,
    .Enable          = NULL, // _EnablePanel,
    .SetGammaTbl     = NULL, // _SetGammaTbl,
    .GammaTab        = NULL, // _getGammaTbl,
    .Dump            = NULL, // _MApi_XC_DumpPanelData,
    .DimCtrl         = NULL, // _getPanelDimCTRL,
    .OnTiming        = NULL, // _getPanelOnTiming,
    .OffTiming       = NULL, // _getPanelOffTiming,
    //
    // Custimized methods, can be provided by clinets.
    //
    .TurnBackLightOn = NULL, // _EmptyMethod,
    .SetGammaValue   = NULL, // _SetGammaValue,
    .GetGammaTbl     = NULL, // _GetGammaTbl,
};


HDMI_POLLING_STATUS_t    g_HdmiPollingStatus;

#include "TT_IRenderSystem.h"
TT_IRenderSystem TT_CharRenderSystem;

#include "TT_API25.h"
TT_Engine TT_EngineObj;

#include "TT_IDecoder.h"
const TT_IDecoder TT_DecoderL15;

MS_U16 g_AVMUTEMissingCounter;
MS_U16 g_AVIMissingCounter;
MS_U16 g_ACPMissingCounter;
U8 g_OAD_OUI[3];
U8 KeypadCount;
U8 KeypadSamplePeriod;
U8  _readonly_start[];
U8  _readonly_end[];
U32 __heap;
U32 __heap_end;
U32 __stack_begin;


#include "MApp_AutoTest.h"
/** User stub definition for function: MS_BOOL _MApp_AT_CmdParser(AT_CMD *) */
EXTERN_C_LINKAGE MS_BOOL _MApp_AT_CmdParser (AT_CMD *ATCmd) ;
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub__MApp_AT_CmdParser (AT_CMD *ATCmd)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_CmdParseFail"))
  {
    return (unsigned char)0;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_KEY_SHORT_PRESS_CMD") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_KEY_SHORT_PRESS_CMD_ResultOnGoing")
      )
  {
    ATCmd->u8CmdType = EN_AUTO_TEST_CMD_TYPE_KEY_SHORT_PRESS_CMD;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_KEY_LONG_PRESS_CMD"))
  {
    ATCmd->u8CmdType = EN_AUTO_TEST_CMD_TYPE_KEY_LONG_PRESS_CMD;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_DIRECT_CMD") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_DIRECT_CMD_ResultOnGoing")
      )
  {
    ATCmd->u8CmdType = EN_AUTO_TEST_CMD_TYPE_DIRECT_CMD;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_AUDIO_CMD") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_AUDIO_CMD_ResultOnGoing")
      )
  {
    ATCmd->u8CmdType = EN_AUTO_TEST_CMD_TYPE_AUDIO_CMD;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_MISC_CMD") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_MISC_CMD_ResultOnGoing")
      )
  {
    ATCmd->u8CmdType = EN_AUTO_TEST_CMD_TYPE_MISC_CMD;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_OAD_CMD") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_OAD_CMD_ResultOnGoing")
      )
  {
    ATCmd->u8CmdType = EN_AUTO_TEST_CMD_TYPE_OAD_CMD;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_DEFAULT"))
  {
    ATCmd->u8CmdType = 0;
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: EN_AT_RESULT _MApp_AT_DirectCmdHandler(AT_CMD) */
EXTERN_C_LINKAGE EN_AT_RESULT _MApp_AT_DirectCmdHandler(AT_CMD ATCmd);
EXTERN_C_LINKAGE EN_AT_RESULT CppTest_Stub__MApp_AT_DirectCmdHandler (AT_CMD ATCmd)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_DIRECT_CMD_ResultOnGoing"))
  {
    return EN_AT_RESULT_ONGOING;
  }
  else
  {
    return EN_AT_RESULT_ER;
  }
}

/** User stub definition for function: EN_AT_RESULT _MApp_AT_AudioCmdHandler(AT_CMD) */
EXTERN_C_LINKAGE EN_AT_RESULT _MApp_AT_AudioCmdHandler(AT_CMD ATCmd);
EXTERN_C_LINKAGE EN_AT_RESULT CppTest_Stub__MApp_AT_AudioCmdHandler (AT_CMD ATCmd)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_AUDIO_CMD_ResultOnGoing"))
  {
    return EN_AT_RESULT_ONGOING;
  }
  else
  {
    return EN_AT_RESULT_ER;
  }
}

/** User stub definition for function: BOOLEAN _MApp_AT_CheckStartAutoTest(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_AT_CheckStartAutoTest(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_AT_CheckStartAutoTest (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MDrv_UART_RecvAutoTestHandler_c_is_ENTER_startAT"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN _MApp_AT_CheckStopAutoTest(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_AT_CheckStopAutoTest(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_AT_CheckStopAutoTest (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MDrv_UART_RecvAutoTestHandler_c_is_ENTER_stopAT"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

#if(AT_IR_SIM)
/** User stub definition for function: BOOLEAN _MApp_AT_CheckIRKeySimulation(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_AT_CheckIRKeySimulation(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_AT_CheckIRKeySimulation (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MDrv_UART_RecvAutoTestHandler_c_is_ENTER_GotCmd_IRKeySimulation"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}
#endif

/** User stub definition for function: BOOLEAN _MApp_AT_CheckCommandHeader(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_AT_CheckCommandHeader(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_AT_CheckCommandHeader (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MDrv_UART_RecvAutoTestHandler_c_is_ENTER_GotCmd_CheckCommandHeader"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

#include "MApp_GlobalSettingSt.h"
/** User stub definition for function: void MApp_ZUI_ACT_InputSourceSwitch(E_UI_INPUT_SOURCE) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_InputSourceSwitch(E_UI_INPUT_SOURCE source_type);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_ZUI_ACT_InputSourceSwitch (E_UI_INPUT_SOURCE source_type)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_SET_INPUT_SOURCE_OK"))
  {
    return;
  }
}

#if 0
/** User stub definition for function: BOOLEAN MApp_IsSrcHasSignal(SCALER_WIN) */
EXTERN_C_LINKAGE BOOLEAN MApp_IsSrcHasSignal(SCALER_WIN eWindow);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_IsSrcHasSignal (SCALER_WIN eWindow)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_INPUT_SIGNAL_OK"))
  {
    return (unsigned char)1;
  }
}
#endif

#if ENABLE_3D_PROCESS
E_XC_3D_INPUT_MODE    g_HdmiInput3DFormat;
E_XC_3D_INPUT_MODE    g_HdmiInput3DFormatStatus;
#endif

/** User stub definition for function: CEC_ERROR_CODE MDrv_CEC_TxApi2(MsCEC_DEVICELA, MsCEC_MSGLIST, MS_U8 *, MS_U8) */
EXTERN_C_LINKAGE CEC_ERROR_CODE MDrv_CEC_TxApi2 (MsCEC_DEVICELA dst_address, MsCEC_MSGLIST msg, MS_U8 * operand_ptr, MS_U8 len) ;
EXTERN_C_LINKAGE CEC_ERROR_CODE CppTest_Stub_MDrv_CEC_TxApi2 (MsCEC_DEVICELA dst_address, MsCEC_MSGLIST msg, MS_U8 * operand_ptr, MS_U8 len)
{
    return E_CEC_FEATURE_ABORT;
}

/** User stub definition for function: void MDrv_CEC_ConfigWakeupInfoVendorID(MS_U8 *) */
EXTERN_C_LINKAGE void MDrv_CEC_ConfigWakeupInfoVendorID (MS_U8 * u8CecVendorID) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_CEC_ConfigWakeupInfoVendorID (MS_U8 * u8CecVendorID)
{
}

/** User stub definition for function: void MDrv_CEC_SetRetryCount(MS_U8) */
EXTERN_C_LINKAGE void MDrv_CEC_SetRetryCount (MS_U8 u8RetryCount) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_CEC_SetRetryCount (MS_U8 u8RetryCount)
{
}

/** User stub definition for function: void MDrv_CEC_Init(MS_U32) */
EXTERN_C_LINKAGE void MDrv_CEC_Init (MS_U32 u32XTAL_CLK_Hz) ;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_CEC_Init (MS_U32 u32XTAL_CLK_Hz)
{
}

#include "MApp_TopStateMachine.h"
/** User stub definition for function: EN_TOP_STATE MApp_TopStateMachine_GetTopState(void) */
EXTERN_C_LINKAGE EN_TOP_STATE MApp_TopStateMachine_GetTopState(void);
EXTERN_C_LINKAGE EN_TOP_STATE CppTest_Stub_MApp_TopStateMachine_GetTopState (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_DIRECT_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_DIRECT_SCAN_ONGOING")
    )
  {
    return STATE_TOP_DIGITALINPUTS;
  }
  else
  {
    return STATE_TOP_MENU;
  }
}

/** User stub definition for function: void MApp_SetOSDCountrySetting(EN_OSD_COUNTRY_SETTING, BOOLEAN) */
EXTERN_C_LINKAGE void MApp_SetOSDCountrySetting(EN_OSD_COUNTRY_SETTING eOSDCountrySetting, BOOLEAN bSave);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SetOSDCountrySetting (EN_OSD_COUNTRY_SETTING eOSDCountrySetting, BOOLEAN bSave)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SCAN_ONGOING")
    )
  {
    return;
  }
}

/** User stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteMainMenuAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteMainMenuAction(U16 act);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_ZUI_ACT_ExecuteMainMenuAction (U16 ac5)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_DTV_DIRECT_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_DIRECT_SCAN_ONGOING") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_OADCmdHandler_case_EN_AUTO_TEST_OAD_SOFTWARE_UPDATE_USB")
    )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CM_GetServiceName(MEMBER_SERVICETYPE, WORD, BYTE * ) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CM_GetServiceName(MEMBER_SERVICETYPE bServiceType, WORD wPosition, BYTE * bChannelName);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_GetServiceName (MEMBER_SERVICETYPE bServiceType, WORD wPosition, BYTE * bChannelName)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_DTV_CHANNEL_LIST_OK"))
  {
    return (unsigned char)0;
  }
}


/** User stub definition for function: BYTE msAPI_ATV_GetActiveProgramCount(void) */
EXTERN_C_LINKAGE BYTE msAPI_ATV_GetActiveProgramCount(void);
EXTERN_C_LINKAGE BYTE CppTest_Stub_msAPI_ATV_GetActiveProgramCount (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_ATV_CHANNEL_LIST_ER") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SIGNAL_ER2") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SIGNAL_ER3")
    )
  {
    return (unsigned char)0;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_ATV_CHANNEL_LIST_OK") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SIGNAL_ER1") ||
      CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_ATV_SIGNAL_OK")
      )
  {
    return (unsigned char)5;
  }
  else
  {
	  return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN msAPI_ATV_GetStationName(BYTE, BYTE *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_GetStationName(BYTE u8ProgramNumber, BYTE *sName);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_GetStationName (BYTE u8ProgramNumber, BYTE *sName)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_ATV_CHANNEL_LIST_OK"))
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: INPUT_SOURCE_TYPE_t MApp_InputSource_GetInputSourceType(E_UI_INPUT_SOURCE) */
EXTERN_C_LINKAGE INPUT_SOURCE_TYPE_t MApp_InputSource_GetInputSourceType(E_UI_INPUT_SOURCE stInputSrc);
EXTERN_C_LINKAGE INPUT_SOURCE_TYPE_t CppTest_Stub_MApp_InputSource_GetInputSourceType (E_UI_INPUT_SOURCE stInputSrc)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_INPUT_SOURCE_ER"))
  {
    return INPUT_SOURCE_NONE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_DirectCmdHandler_case_GET_INPUT_SOURCE_OK"))
  {
    return INPUT_SOURCE_TV;
  }
}

/** User stub definition for function: U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t enSrc) */
EXTERN_C_LINKAGE U8 _MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t enSrc);
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_InputSource_PIP_GetCompatibleNum(INPUT_SOURCE_TYPE_t enSrc)
{
  if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS"))
  {
    return 2;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS2"))
  {
    return 2;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS3"))
    {
      return 2;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS4"))
    {
      return 2;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS5"))
    {
      return 2;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS6"))
    {
      return 2;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS7"))
    {
      return 2;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_CVBS8"))
    {
      return 2;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_DTV"))
    {
      return 0;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI"))
    {
      return 7;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI2"))
    {
      return 7;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI3"))
    {
      return 7;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_HDMI4"))
    {
      return 7;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART"))
    {
      return 3;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SCART2"))
    {
      return 3;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO"))
    {
      return 4;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO2"))
    {
      return 4;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO3"))
    {
      return 4;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_SVIDEO4"))
    {
      return 4;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage"))
    {
      return 8;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_Storage2"))
    {
      return 8;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_TV"))
    {
      return 1;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_VGA"))
    {
      return 6;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR"))
    {
      return 5;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR2"))
    {
      return 5;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_PIP_test_MApp_InputSource_PIP_Get1stCompatibleSrc_YPBPR3"))
    {
      return 5;
    }
}

/** User stub definition for function: BOOLEAN msAPI_MHL_IsCbusConnected(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MHL_IsCbusConnected(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MHL_IsCbusConnected (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsTRUE") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing")
    )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

#include "MApp_ChannelChange.h"
/** User stub definition for function: U32 msAPI_Timer_DiffTimeFromNow(U32) */
EXTERN_C_LINKAGE U32 msAPI_Timer_DiffTimeFromNow(U32 u32TaskTimer);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Timer_DiffTimeFromNow (U32 u32TaskTimer)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUIGoing"))
  {
    return 2001UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_DEFAULT_MHL_Cbus_Connect_FlagIsFALSEandZUINotGoing")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF1")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_ELSE1")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_IF_IF")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_IF")||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_AVSync_test_MApp_AVSync_ForceSync_IF_IF2_IF_ELSE_ELSE"))
  {
    return 2000UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_if"))
  {
    return CHANNEL_CHANGE_KEY_REPEAT_DELAY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Stop__gbEnableInternalSubtitle_TRUE"))
  {
    return 10000;
  }
  //else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_MApp_DB_SaveNowGenSetting_g_bGenSettingStoreUseNewMethodTRUE"))
  //{
  //  return 1001;
  //}
  else
  {
    return 0xFFFFFFFF;
  }
}

#include "MApp_Exit.h"
/** User stub definition for function: EN_RET MApp_ChannelChange_ShowAnalogBanner(void) */
EXTERN_C_LINKAGE EN_RET MApp_ChannelChange_ShowAnalogBanner(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_ChannelChange_ShowAnalogBanner (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ANALOG_SHOW_BANNER_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_ChannelChange(void) */
EXTERN_C_LINKAGE EN_RET MApp_ChannelChange(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_ChannelChange (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_CHANNELCHANGE_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_OAD_Scan(U8*) */
EXTERN_C_LINKAGE EN_RET MApp_OAD_Scan(U8* percentage);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_OAD_Scan (U8* percentage)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsTRUE_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_DTV_Scan(void) */
EXTERN_C_LINKAGE EN_RET MApp_DTV_Scan(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_DTV_Scan (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_PREVIOUS"))
  {
    return EXIT_GOTO_PREVIOUS;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_TV"))
  {
    return EXIT_GOTO_TV;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_SCAN_bShowOadScanPageIsFALSE_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_DTV_Scan_Update_Mux(void) */
EXTERN_C_LINKAGE EN_RET MApp_DTV_Scan_Update_Mux(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_DTV_Scan_Update_Mux (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_PREVIOUS"))
  {
    return EXIT_GOTO_PREVIOUS;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_WAIT"))
  {
    return EXIT_GOTO_WAIT;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_SCAN_NEW_MUX_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_ATV_Scan(void) */
EXTERN_C_LINKAGE EN_RET MApp_ATV_Scan(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_ATV_Scan (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_TV"))
  {
    return EXIT_GOTO_TV;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_PREVIOUS"))
  {
    return EXIT_GOTO_PREVIOUS;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_DTV_SCAN"))
  {
    return EXIT_GOTO_DTVSCAN;
  }
  #if(ENABLE_SBTVD_BRAZIL_APP)
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_EXIT_GOTO_CATVSCAN"))
  {
    return EXIT_GOTO_CATVSCAN;
  }
  #endif
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_SCAN_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_TV(void) */
EXTERN_C_LINKAGE EN_RET MApp_TV(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_TV (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_USB"))
  {
    return EXIT_GOTO_USB;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OAD"))
  {
    return EXIT_GOTO_OAD;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INSTALLGUIDE"))
  {
    return EXIT_GOTO_INSTALLGUIDE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_EPG"))
  {
    return EXIT_GOTO_EPG;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_INPUTSOURCE"))
  {
    return EXIT_GOTO_INPUTSOURCE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_OSDPAGE"))
  {
    return EXIT_GOTO_OSDPAGE;
  }
  #if ENABLE_CI
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_MMI"))
  {
    return EXIT_GOTO_MMI;
  }
  #endif
  #if ENABLE_DMP
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_DMP"))
  {
    return EXIT_GOTO_DMP;
  }
  #endif
  #if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_EXIT_GOTO_SCAN_NEW_MUX"))
  {
    return EXIT_GOTO_SCAN_NEW_MUX;
  }
  #endif
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DIGITALINPUTS_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_PVR_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_PVR_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_PVR_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_PVR_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}


/** User stub definition for function: EN_RET MApp_PVR_Main(void) */
EXTERN_C_LINKAGE void MApi_Audio_SPDIF_Monitor(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_Audio_SPDIF_Monitor (void)
{

}


/** User stub definition for function: BOOLEAN MApp_Analog_NoSignal_ExcludeATV(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_Analog_NoSignal_ExcludeATV(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Analog_NoSignal_ExcludeATV (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AnalogInputs_test_MApp_AnalogInputs_FunctionNotAvailableCheck_IsTrue"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: E_MHEG_CI_STATUS msAPI_IsCIMHEGRun(void) */
EXTERN_C_LINKAGE E_MHEG_CI_STATUS msAPI_IsCIMHEGRun(void);
EXTERN_C_LINKAGE E_MHEG_CI_STATUS CppTest_Stub_msAPI_IsCIMHEGRun (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GoMHEGWhenSubtitleOn_E_MHEG_CI_OFF"))
  {
    return E_MHEG_CI_OFF;
  }
  else
  {
    return E_MHEG_CI_RUNNING;
  }
}


/** User stub definition for function: BOOLEAN MApp_MHEG5_CheckGoMHEG5Process(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MHEG5_CheckGoMHEG5Process(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MHEG5_CheckGoMHEG5Process (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_0"))
  {
    return (unsigned char)0;
  }
  else
  {
    return (unsigned char)1;
  }
}

/** User stub definition for function: BOOLEAN msAPI_MHEG5_VID_IsFullScreen(MS_MHEG5_VIDEO_ACTION *pstMHEG5VideoAction) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MHEG5_VID_IsFullScreen(MS_MHEG5_VIDEO_ACTION *pstMHEG5VideoAction);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MHEG5_VID_IsFullScreen (MS_MHEG5_VIDEO_ACTION *pstMHEG5VideoAction)
{
  if(CppTest_IsCurrentTestCase("TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_0_isFullScreen_1")
   ||CppTest_IsCurrentTestCase("TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_0_u8MheGSubtitleControl_1_isFullScreen_1")
   ||CppTest_IsCurrentTestCase("TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_0_isFullScreen_1")
   ||CppTest_IsCurrentTestCase("TestSuite_msAPI_MHEG5_test_msAPI_MHEG5_GetSubtitleMode_MApp_MHEG5_CheckGoMHEG5Process_Equals_1_bIFrame_Equals_1_u8MheGSubtitleControl_1_isFullScreen_1"))
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CEC_QuerySystemAudioMode(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CEC_QuerySystemAudioMode(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CEC_QuerySystemAudioMode (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_MINUS_bSystemAudioMode_IsTrue") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_CEC_CheckRepeatKey_KEY_VOLUME_PLUS_bSystemAudioMode_IsTrue")
    )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CEC_QuerySystemAudioMode(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_GetKeyPad(U8 *u8key,U8 *u8Repstatus);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_GetKeyPad(U8 *u8key,U8 *u8Repstatus)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetKeyPad_OK"))
  {
    return MSRET_OK;
  }
  else
  {
    return MSRET_ERROR;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CEC_QuerySystemAudioMode(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_GetIRKey(U8 *u8key,U8 *u8Repstatus);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_GetIRKey(U8 *u8key,U8 *u8Repstatus)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_CheckKeyStatus_msAPI_GetIRKey_OK"))
  {
    return MSRET_OK;
  }
  else
  {
    return MSRET_ERROR;
  }
}

#if ( ENABLE_DVB_TAIWAN_APP || ENABLE_SBTVD_BRAZIL_APP || (TV_SYSTEM == TV_NTSC) )
/** User stub definition for function: void msAPI_ATV_ResetChannelData(EN_CHANNEL_RESET_SELECTION eChannelResetType) */
EXTERN_C_LINKAGE void msAPI_ATV_ResetChannelData(EN_CHANNEL_RESET_SELECTION eChannelResetType);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_ATV_ResetChannelData(EN_CHANNEL_RESET_SELECTION eChannelResetType)
{
}
#else
/** User stub definition for function: void msAPI_ATV_ResetChannelData(void) */
EXTERN_C_LINKAGE void msAPI_ATV_ResetChannelData(void);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_ATV_ResetChannelData(void)
{
}
#endif

/** User stub definition for function: BOOLEAN msAPI_ATV_SetLastVideoStandard(AVD_InputSourceType eVideoSource, AVD_VideoStandardType eVideoStandard) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetLastVideoStandard(AVD_InputSourceType eVideoSource, AVD_VideoStandardType eVideoStandard);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetLastVideoStandard(AVD_InputSourceType eVideoSource, AVD_VideoStandardType eVideoStandard)
{
}

/** User stub definition for function: BOOLEAN msAPI_ATV_SetBrightness(AVD_InputSourceType eVideoSource, BYTE u8Percent) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetBrightness(AVD_InputSourceType eVideoSource, BYTE u8Percent);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetBrightness(AVD_InputSourceType eVideoSource, BYTE u8Percent)
{
}

/** User stub definition for function: BOOLEAN msAPI_ATV_SetContrast(AVD_InputSourceType eVideoSource, BYTE u8Percent) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetContrast(AVD_InputSourceType eVideoSource, BYTE u8Percent);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetContrast(AVD_InputSourceType eVideoSource, BYTE u8Percent)
{
}

/** User stub definition for function: BOOLEAN msAPI_ATV_SetColor(AVD_InputSourceType eVideoSource, BYTE u8Percent) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetColor(AVD_InputSourceType eVideoSource, BYTE u8Percent);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetColor(AVD_InputSourceType eVideoSource, BYTE u8Percent)
{
}

/** User stub definition for function: BOOLEAN msAPI_ATV_SetHue(AVD_InputSourceType eVideoSource, BYTE u8Percent) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetHue(AVD_InputSourceType eVideoSource, BYTE u8Percent);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetHue(AVD_InputSourceType eVideoSource, BYTE u8Percent)
{
}

/** User stub definition for function: BOOLEAN msAPI_ATV_SetSharpness(AVD_InputSourceType eVideoSource, BYTE u8Percent) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetSharpness(AVD_InputSourceType eVideoSource, BYTE u8Percent);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetSharpness(AVD_InputSourceType eVideoSource, BYTE u8Percent)
{
}

/** User stub definition for function: BOOLEAN msAPI_ATV_SetAudioMode(AUDIOSOURCE_TYPE eSource, AUDIOMODE_TYPE eAudioMode) */
EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_SetAudioMode(AUDIOSOURCE_TYPE eSource, AUDIOMODE_TYPE eAudioMode);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_SetAudioMode(AUDIOSOURCE_TYPE eSource, AUDIOMODE_TYPE eAudioMode)
{
}



#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_ACTeffect.h"

#include "MApp_ZUI_APIwindow.h"
#include "MApp_ZUI_APItables.h"
#include "MApp_DMP_Main.h"

/** User stub definition for function: void MApp_ZUI_ACT_TransitionEffectBegin(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TransitionEffectBegin(ZUI_TRANSEFFMODE mode, ZUI_STATE target);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_ZUI_ACT_TransitionEffectBegin(ZUI_TRANSEFFMODE mode, ZUI_STATE target)
{
}

/** User stub definition for function: void MApp_ZUI_ACT_TransitionEffectDoing(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TransitionEffectDoing(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_ZUI_ACT_TransitionEffectDoing(void)
{
}

/** User stub definition for function: void MApp_ZUI_ACT_TransitionEffectEnd(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TransitionEffectEnd(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_ZUI_ACT_TransitionEffectEnd(void)
{
}

/** User stub definition for function: void MApp_ZUI_ACT_ExitThumbnailMode(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_ExitThumbnailMode(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_ZUI_ACT_ExitThumbnailMode(void)
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_ACT_GetDmpDynamicText(HWND) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_ACT_GetDmpDynamicText (HWND hwnd) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_ACT_GetDmpDynamicText (HWND hwnd)
{
    return (LPTSTR)0;
}

/** Auto-generated stub definition for function: void MApp_DMP_InitDMPStat(void) */
EXTERN_C_LINKAGE void MApp_DMP_InitDMPStat () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_DMP_InitDMPStat (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpAlertWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpAlertWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpAlertWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpProgressWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpProgressWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpProgressWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DMPMovieResumeWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DMPMovieResumeWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DMPMovieResumeWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_UiMediaPlayer_Notify(enumMPlayerNotifyType, void *) */
EXTERN_C_LINKAGE BOOLEAN MApp_UiMediaPlayer_Notify (enumMPlayerNotifyType eNotify, void * pInfo) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_UiMediaPlayer_Notify (enumMPlayerNotifyType eNotify, void * pInfo)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_DMP_NotifyUiState(EN_DMP_UI_STATE) */
EXTERN_C_LINKAGE void MApp_DMP_NotifyUiState (EN_DMP_UI_STATE enDmpUiState) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_DMP_NotifyUiState (EN_DMP_UI_STATE enDmpUiState)
{
}

/** Auto-generated stub definition for function: U16 MApp_ZUI_ACT_GetDmpDynamicBitmap(HWND, DRAWSTYLE_TYPE) */
EXTERN_C_LINKAGE U16 MApp_ZUI_ACT_GetDmpDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetDmpDynamicBitmap (HWND hwnd, DRAWSTYLE_TYPE ds_type)
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_HandleDmpKey(VIRTUAL_KEY_CODE) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_HandleDmpKey (VIRTUAL_KEY_CODE key) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_HandleDmpKey (VIRTUAL_KEY_CODE key)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DMPMarqueeTextWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DMPMarqueeTextWinProc (HWND hWnd, PMSG pMsg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DMPMarqueeTextWinProc (HWND hWnd, PMSG pMsg)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_AppShowDmp(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_AppShowDmp () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_AppShowDmp (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpPlayStatusWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpPlayStatusWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpPlayStatusWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_DMP_GetZUIFbAttr(GOP_GwinFBAttr *) */
EXTERN_C_LINKAGE void MApp_DMP_GetZUIFbAttr (GOP_GwinFBAttr * pFbAttr) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_DMP_GetZUIFbAttr (GOP_GwinFBAttr * pFbAttr)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DMPVolumeWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DMPVolumeWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DMPVolumeWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_ACT_TerminateDmp(void) */
EXTERN_C_LINKAGE void MApp_ZUI_ACT_TerminateDmp () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_ACT_TerminateDmp (void)
{
}

/** Auto-generated stub definition for function: EN_DMP_UI_STATE MApp_DMP_GetDmpUiState(void) */
EXTERN_C_LINKAGE EN_DMP_UI_STATE MApp_DMP_GetDmpUiState () ;
EXTERN_C_LINKAGE EN_DMP_UI_STATE CppTest_Auto_Stub_MApp_DMP_GetDmpUiState (void)
{
    return DMP_UI_STATE_MEDIA_SELECT;
}

/** Auto-generated stub definition for function: EN_DMP_STATE MApp_DMP_GetDMPStat(void) */
EXTERN_C_LINKAGE EN_DMP_STATE MApp_DMP_GetDMPStat () ;
EXTERN_C_LINKAGE EN_DMP_STATE CppTest_Auto_Stub_MApp_DMP_GetDMPStat (void)
{
    return DMP_STATE_INIT;
}

/** Auto-generated stub definition for function: void MApp_DMP_Exit(void) */
EXTERN_C_LINKAGE void MApp_DMP_Exit () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_DMP_Exit (void)
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpEqPlayWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpEqPlayWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpEqPlayWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: EN_RET MApp_DMP_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_DMP_Main () ;
EXTERN_C_LINKAGE EN_RET CppTest_Auto_Stub_MApp_DMP_Main (void)
{
    return EXIT_NULL;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpBgmFileSelectThumbnailWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpBgmFileSelectThumbnailWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpBgmFileSelectThumbnailWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteDmpAction(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteDmpAction (U16 act) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_ACT_ExecuteDmpAction (U16 act)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpFileSelectThumbnailWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpFileSelectThumbnailWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpFileSelectThumbnailWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DMPUartWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DMPUartWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DMPUartWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DmpPreviewWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DmpPreviewWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DmpPreviewWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: EN_DMP_FLAG MApp_DMP_GetDmpFlag(void) */
EXTERN_C_LINKAGE EN_DMP_FLAG MApp_DMP_GetDmpFlag () ;
EXTERN_C_LINKAGE EN_DMP_FLAG CppTest_Auto_Stub_MApp_DMP_GetDmpFlag (void)
{
    return DMP_FLAG_NONE;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_ACT_DMPResumeStopWinProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_ACT_DMPResumeStopWinProc (HWND hwnd, PMSG msg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_ACT_DMPResumeStopWinProc (HWND hwnd, PMSG msg)
{
    return 0L;
}

/** Auto-generated stub definition for function: S16 MApp_ZUI_ACT_GetDmpDynamicValue(HWND) */
EXTERN_C_LINKAGE S16 MApp_ZUI_ACT_GetDmpDynamicValue (HWND hwnd) ;
EXTERN_C_LINKAGE S16 CppTest_Auto_Stub_MApp_ZUI_ACT_GetDmpDynamicValue (HWND hwnd)
{
    return (short)0;
}

/** User stub definition for function: BOOLEAN MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(U16 act) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_ACT_ExecuteMenuCommonDialogAction(U16 act);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_ZUI_ACT_ExecuteMenuCommonDialogAction (U16 act)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_MiscCmdHandler_case_EN_AUTO_TEST_MISC_RESET_FACTORY") )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: void MDrv_Sys_WholeChipReset(void) */
EXTERN_C_LINKAGE void MDrv_Sys_WholeChipReset(void);
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_Sys_WholeChipReset (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_MiscCmdHandler_case_EN_AUTO_TEST_MISC_REBOOT") )
  {
    return (unsigned char)0;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CM_ResetAllProgram(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CM_ResetAllProgram(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_ResetAllProgram (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_MiscCmdHandler_case_EN_AUTO_TEST_MISC_CLEAR_PROGRAM") )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

typedef enum _COMMON_DLG_MODE
{
    EN_COMMON_DLG_MODE_INVALID,
    EN_COMMON_DLG_MODE_FACTORY_RESET,
    EN_COMMON_DLG_MODE_FACTORY_RESET_CONFIRM,
    EN_COMMON_DLG_MODE_DIVX,
    EN_COMMON_DLG_MODE_DEACTIVATION,
    EN_COMMON_DLG_MODE_DEACTIVATION_CONFIRM,
    EN_COMMON_DLG_MODE_SCAN_INPUT_PASSWORD,
    EN_COMMON_DLG_MODE_DTV_TUNING_INPUT_PASSWORD,
    EN_COMMON_DLG_MODE_ATV_TUNING_INPUT_PASSWORD,
    EN_COMMON_DLG_MODE_FACTORY_RESET_INPUT_PASSWORD,
    EN_COMMON_DLG_MODE_WRONG_PASSWORD,
    EN_COMMON_DLG_MODE_MISMATCH_PASSWORD,
    EN_COMMON_DLG_MODE_INPUT_PASSWORD,
    EN_COMMON_DLG_MODE_SET_PASSWORD,
    EN_COMMON_DLG_MODE_USB_NOT_DETECTED,
    EN_COMMON_DLG_MODE_CI_NO_MODULE,
    EN_COMMON_DLG_MODE_SW_FILE_NOT_DETECTED,
    EN_COMMON_DLG_MODE_USB_UPDATE_CONFIRM,
    EN_COMMON_DLG_MODE_USB_UPGRADING,
    EN_COMMON_DLG_MODE_ENTER_MENU_LOCK_PAGE_INPUT_PASSWORD,
} COMMON_DLG_MODE;
/** User stub definition for function: void _MApp_ZUI_ACT_OpenCommonDialog(COMMON_DLG_MODE dlg) */
EXTERN_C_LINKAGE void _MApp_ZUI_ACT_OpenCommonDialog(COMMON_DLG_MODE dlg);
EXTERN_C_LINKAGE void CppTest_Stub__MApp_ZUI_ACT_OpenCommonDialog (COMMON_DLG_MODE dlg)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_OADCmdHandler_case_EN_AUTO_TEST_OAD_SOFTWARE_UPDATE_USB") )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: BOOLEAN MW_UsbDownload_Start(void) */
EXTERN_C_LINKAGE BOOLEAN MW_UsbDownload_Start(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MW_UsbDownload_Start (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test__MApp_AT_OADCmdHandler_case_EN_AUTO_TEST_OAD_SOFTWARE_UPDATE_USB") )
  {
    return (unsigned char)1;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: EN_AT_RESULT _MApp_AT_MiscCmdHandler(AT_CMD ATCmd) */
EXTERN_C_LINKAGE EN_AT_RESULT _MApp_AT_MiscCmdHandler(AT_CMD ATCmd);
EXTERN_C_LINKAGE EN_AT_RESULT CppTest_Stub__MApp_AT_MiscCmdHandler (AT_CMD ATCmd)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_MISC_CMD_ResultOnGoing") )
  {
    return (unsigned char)EN_AT_RESULT_ONGOING;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: EN_AT_RESULT _MApp_AT_KeyShortPressHandler(AT_CMD ATCmd) */
EXTERN_C_LINKAGE EN_AT_RESULT _MApp_AT_KeyShortPressHandler(AT_CMD ATCmd);
EXTERN_C_LINKAGE EN_AT_RESULT CppTest_Stub__MApp_AT_KeyShortPressHandler (AT_CMD ATCmd)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_KEY_SHORT_PRESS_CMD_ResultOnGoing") )
  {
    return (unsigned char)EN_AT_RESULT_ONGOING;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: EN_AT_RESULT _MApp_AT_OADCmdHandler(AT_CMD ATCmd) */
EXTERN_C_LINKAGE EN_AT_RESULT _MApp_AT_OADCmdHandler(AT_CMD ATCmd);
EXTERN_C_LINKAGE EN_AT_RESULT CppTest_Stub__MApp_AT_OADCmdHandler (AT_CMD ATCmd)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_AutoTest_test_MApp_AT_CmdHandler_case_EN_AUTO_TEST_CMD_TYPE_OAD_CMD_ResultOnGoing") )
  {
    return (unsigned char)EN_AT_RESULT_ONGOING;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: EN_RET MApp_DTV_ManualTuning_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_DTV_ManualTuning_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_DTV_ManualTuning_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_EXIT_GOTO_DTVSCAN"))
  {
    return EXIT_GOTO_DTVSCAN;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_DTV_MANUAL_TUNING_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_ATV_ManualTuning_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_ATV_ManualTuning_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_ATV_ManualTuning_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_EXIT_GOTO_ATVSCAN"))
  {
    return EXIT_GOTO_ATVSCAN;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_ATV_MANUAL_TUNING_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_OSDPage_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_OSDPage_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_OSDPage_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_EPG"))
  {
    return EXIT_GOTO_EPG;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_INPUTSOURCE"))
  {
    return EXIT_GOTO_INPUTSOURCE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_EXIT_GOTO_DMP"))
  {
    return EXIT_GOTO_DMP;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OSDPAGE_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_InstallGuide_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_InstallGuide_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_InstallGuide_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_SCAN"))
  {
    return EXIT_GOTO_SCAN;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_EPG"))
  {
    return EXIT_GOTO_EPG;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INSTALLGUIDE_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_Epg_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_Epg_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_Epg_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_EPG_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_InputSource_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_InputSource_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_InputSource_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_if") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_CLOSE_else")
    )
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_DMP"))
  {
    return EXIT_GOTO_DMP;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_OSDPAGE"))
  {
    return EXIT_GOTO_OSDPAGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_MENU"))
  {
    return EXIT_GOTO_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_EXIT_GOTO_INFO"))
  {
    return EXIT_GOTO_INFO;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_INPUTSOURCE_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: EN_RET MApp_OAD_AppMain(void) */
EXTERN_C_LINKAGE EN_RET MApp_OAD_AppMain(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_OAD_AppMain (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_EXIT_CLOSE"))
  {
    return EXIT_CLOSE;
  }

  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_OAD_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: void MApp_Standby_Init(void) */
EXTERN_C_LINKAGE void MApp_Standby_Init(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Standby_Init (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_STANDBY"))
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: EN_RET MApp_Menu_Main(void) */
EXTERN_C_LINKAGE EN_RET MApp_Menu_Main(void);
EXTERN_C_LINKAGE EN_RET CppTest_Stub_MApp_Menu_Main (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_if") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_CLOSE_else")
    )
  {
    return EXIT_CLOSE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_STANDBY"))
  {
    return EXIT_GOTO_STANDBY;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_EPG"))
  {
    return EXIT_GOTO_EPG;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DTV_MANUALTUNING"))
  {
    return EXIT_GOTO_DTV_MANUALTUNING;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_ATV_MANUALTUNING"))
  {
    return EXIT_GOTO_ATV_MANUALTUNING;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_CHANNELCHANGE"))
  {
    return EXIT_GOTO_CHANNELCHANGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_MMI"))
  {
    return EXIT_GOTO_MMI;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_DMP"))
  {
    return EXIT_GOTO_DMP;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_PVR_CHECK_FS"))
  {
    return EXIT_GOTO_PVR_CHECK_FS;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_OSDPAGE"))
  {
    return EXIT_GOTO_OSDPAGE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INPUTSOURCE"))
  {
    return EXIT_GOTO_INPUTSOURCE;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_EXIT_GOTO_INFO"))
  {
    return EXIT_GOTO_INFO;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TopStateMachine_test_MApp_TopStateMachine_case_STATE_TOP_MENU_case_DEFAULT"))
  {
    return EXIT_NULL;
  }
  else
  {
    return EXIT_NULL;
  }
}

/** User stub definition for function: void msAPI_ClearIRFIFO(void) */
EXTERN_C_LINKAGE void msAPI_ClearIRFIFO(void);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_ClearIRFIFO (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_Key_Initial_Status"))
  {
    return;
  }
}

/** User stub definition for function: void *memcpy(void *d, const void *s, size_t n) */
EXTERN_C_LINKAGE void *memcpy(void *d, const void *s, size_t n);
EXTERN_C_LINKAGE void *CppTest_Stub_memcpy (void *d, const void *s, size_t n)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_GetMBIR"))
  {
    return;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Wav_CollectInfo_case1"))
  {
    return;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1"))
  {
  return;
  }
  else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes"))
  {
  return;
  }
  return;

}

/** User stub definition for function: E_APIXC_ReturnValue MApi_XC_Mux_SetMhlHotPlugInverseInfo(MS_BOOL); */
EXTERN_C_LINKAGE E_APIXC_ReturnValue MApi_XC_Mux_SetMhlHotPlugInverseInfo(MS_BOOL bIsMhlHotPlugInverse);
EXTERN_C_LINKAGE E_APIXC_ReturnValue CppTest_Stub_MApi_XC_Mux_SetMhlHotPlugInverseInfo(MS_BOOL bIsMhlHotPlugInverse)
{
  return (unsigned char)0;
}

/** User stub definition for function: void MApi_PNL_En(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_PNL_En(MS_BOOL bPanelOn);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_PNL_En (MS_BOOL bPanelOn)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_else"))
  {
    return;
  }
}

/** User stub definition for function: void MApi_PNL_SetBackLight(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_PNL_SetBackLight(MS_BOOL bEnable);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_PNL_SetBackLight (MS_BOOL bEnable)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_if") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_else")
    )
  {
    return;
  }
}

/** User stub definition for function: void msAPI_AUD_AdjustAudioFactor2(ADJUST_TVAVFACTOR, WORD, WORD) */
EXTERN_C_LINKAGE void msAPI_AUD_AdjustAudioFactor2(ADJUST_TVAVFACTOR eFactor, WORD wParam1, WORD wParam2);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_AUD_AdjustAudioFactor2 (ADJUST_TVAVFACTOR eFactor, WORD wParam1, WORD wParam2)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_if") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_SetActiveStandbyMode_else")
    )
  {
    return;
  }
}

/** User stub definition for function: BOOLEAN msAPI_MHEG5_checkGoBackMHEG5(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MHEG5_checkGoBackMHEG5(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MHEG5_checkGoBackMHEG5 (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ClearCIFlag"))
  {
	  return FALSE;
  }
  else
  {
	  return TRUE;
  }
}

/** User stub definition for function: BOOLEAN msAPI_IsMBIREnabled(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_IsMBIREnabled(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_IsMBIREnabled (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_if_case_DEFAULT") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_SUBCODE") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_FF") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_REWIND") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_PREVIOUS") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_if_case_KEY_NEXT")
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/** User stub definition for function: BOOLEAN FillAudioStreamInfoWithDefault() */
EXTERN_C_LINKAGE BOOLEAN FillAudioStreamInfoWithDefault();
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_FillAudioStreamInfoWithDefault ()
{
  return TRUE;
}


/** User stub definition for function: void MDrv_PQ_LoadNRTable(PQ_WIN eWindow, PQ_3D_NR_FUNCTION_TYPE en3DNRType) */
EXTERN_C_LINKAGE void MDrv_PQ_LoadNRTable(PQ_WIN eWindow, PQ_3D_NR_FUNCTION_TYPE en3DNRType);
PQ_3D_NR_FUNCTION_TYPE g_PQ_e3DNRType = PQ_3D_NR_NUM;
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PQ_LoadNRTable (PQ_WIN eWindow, PQ_3D_NR_FUNCTION_TYPE en3DNRType)
{
	g_PQ_e3DNRType = en3DNRType;
    return;
}

/** User stub definition for function: void _MApi_XC_Sys_Init_Panel(void) */
EXTERN_C_LINKAGE void _MApi_XC_Sys_Init_Panel(void);
EXTERN_C_LINKAGE void CppTest_Stub__MApi_XC_Sys_Init_Panel (void)
{
  return;
}

/** User stub definition for function: void _MApi_XC_Sys_Init_XC(XC_INITDATA *pstXC_InitData) */
EXTERN_C_LINKAGE void _MApi_XC_Sys_Init_XC(XC_INITDATA *pstXC_InitData);
EXTERN_C_LINKAGE void CppTest_Stub__MApi_XC_Sys_Init_XC (XC_INITDATA *pstXC_InitData)
{
  return;
}

/** User stub definition for function: void _MApi_XC_Sys_Init_DLC(XC_INITDATA *pstXC_InitData) */
EXTERN_C_LINKAGE void _MApi_XC_Sys_Init_DLC(XC_INITDATA *pstXC_InitData);
EXTERN_C_LINKAGE void CppTest_Stub__MApi_XC_Sys_Init_DLC (XC_INITDATA *pstXC_InitData)
{
  return;
}

/** User stub definition for function: void _MApi_XC_Sys_Init_PQ(XC_INITDATA *pstXC_InitData) */
EXTERN_C_LINKAGE void _MApi_XC_Sys_Init_PQ(XC_INITDATA *pstXC_InitData);
EXTERN_C_LINKAGE void CppTest_Stub__MApi_XC_Sys_Init_PQ (XC_INITDATA *pstXC_InitData)
{
  return;
}

/** User stub definition for function: U32 MApp_ZUI_GetActiveOSD() */
EXTERN_C_LINKAGE U32 MApp_ZUI_GetActiveOSD(void);
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_ZUI_GetActiveOSD(void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_isKeypadUPLR_TRUE"))
  {
    return E_OSD_MAIN_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_if"))
  {
    return E_OSD_CHANNEL_INFO;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_ShowAnalogBanner_case_STATE_CHANNELCHANGE_INIT_else"))
  {
    return E_OSD_MAIN_MENU;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_MApp_MHEG5_Main_test_MApp_MHEG5_Quit_Detection_if"))
  {
    return E_OSD_PROGRAM_EDIT;
  }
  else
  {
    return E_OSD_EMPTY;
  }
}

/** User stub definition for function: BOOLEAN msAPI_CM_GetAudioStreamInfo(MEMBER_SERVICETYPE bServiceType, WORD wPosition, AUD_INFO * pstAudioStreamInfo, BYTE cOrdinal) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CM_GetAudioStreamInfo(MEMBER_SERVICETYPE bServiceType, WORD wPosition, AUD_INFO * pstAudioStreamInfo, BYTE cOrdinal);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_GetAudioStreamInfo(MEMBER_SERVICETYPE bServiceType, WORD wPosition, AUD_INFO * pstAudioStreamInfo, BYTE cOrdinal)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_success"))
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/** User stub definition for function: msAPI_CM_GetAudioStreamCount(MEMBER_SERVICETYPE bServiceType, WORD wPosition)*/
EXTERN_C_LINKAGE BYTE msAPI_CM_GetAudioStreamCount(MEMBER_SERVICETYPE bServiceType, WORD wPosition);
EXTERN_C_LINKAGE BYTE CppTest_Stub_msAPI_CM_GetAudioStreamCount(MEMBER_SERVICETYPE bServiceType, WORD wPosition)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_Audio_test_MApp_Audio_SearchAdAudio_success"))
  {
    return (unsigned char)9;
  }
  else
  {
    return (unsigned char)0;
  }
}

/** User stub definition for function: U32 msAPI_OCP_MappinUTF8ToUCS2(U8 *pu8Str, U16 *pu16Str, U16 srcByteLen, U16 dstWideCharLen) */
EXTERN_C_LINKAGE U32 msAPI_OCP_MappinUTF8ToUCS2(U8 *pu8Str, U16 *pu16Str, U16 srcByteLen, U16 dstWideCharLen);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_OCP_MappinUTF8ToUCS2(U8 *pu8Str, U16 *pu16Str, U16 srcByteLen, U16 dstWideCharLen)
{
  return 0UL;
}

/** User stub definition for function: void msAPI_OSD_DrawPunctuatedString(FONTHANDLE font_handle, U16 *pu16Str, OSDClrBtn *pclrBtn, U8 max_row_num) */
EXTERN_C_LINKAGE void msAPI_OSD_DrawPunctuatedString(FONTHANDLE font_handle, U16 *pu16Str, OSDClrBtn *pclrBtn, U8 max_row_num);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_OSD_DrawPunctuatedString(FONTHANDLE font_handle, U16 *pu16Str, OSDClrBtn *pclrBtn, U8 max_row_num)
{
  return;
}

#include "MApp_SignalMonitor.h"
/** User stub definition for function: EN_SIGNAL_LOCK_STATUS MApp_GetSignalStatus(void) */
EXTERN_C_LINKAGE EN_SIGNAL_LOCK_STATUS MApp_GetSignalStatus(void);
EXTERN_C_LINKAGE EN_SIGNAL_LOCK_STATUS CppTest_Stub_MApp_GetSignalStatus(void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_DTV_if"))
  {
    return SIGNAL_UNLOCK;
  }
  else
  {
    return SIGNAL_UNKNOWN;
  }
}

/** User stub definition for function: BOOLEAN IsVDHasSignal(void) */
EXTERN_C_LINKAGE BOOLEAN IsVDHasSignal(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_IsVDHasSignal(void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_ATV_if") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_DetectSignalStatus_case_UI_INPUT_SOURCE_AV_if")
    )
  {
    return FALSE;
  }
  else if( CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_true") ||
		  CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NO_SHOW_PROGRAM2")
		  )
  {
	  return TRUE;
  }
  else if( CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_false") )
  {
	  return FALSE;
  }
  else
  {
    return TRUE;
  }
}

/** User stub definition for function: BOOLEAN MApp_KeyIsReapeatStatus(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_KeyIsReapeatStatus(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_KeyIsReapeatStatus(void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_ChannelChange_test_MApp_ChannelChange_KeyRepeatDelay_if"))
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/** User stub definition for function: U8 MApp_GetDayOfWeek(U16 u16Year, U8 u8Month, U8 u8Day) */
EXTERN_C_LINKAGE U8 MApp_GetDayOfWeek(U16 u16Year, U8 u8Month, U8 u8Day);
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_GetDayOfWeek(U16 u16Year, U8 u8Month, U8 u8Day)
{
  if(CppTest_IsCurrentTestCase("TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekStartingTime") ||
    CppTest_IsCurrentTestCase("TestSuite_MApp_EpgTimer_test__MApp_EpgTimer_GetWeekEndingTime")
    )
  {
    return 5;
  }
}

/** User stub definition for function: void MApp_DB_SaveNowGenSetting(void) */
EXTERN_C_LINKAGE void MApp_DB_SaveNowGenSetting(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_DB_SaveNowGenSetting(void)
{
	return;
}

/** User stub definition for function: void _MApp_EpgTimer_DelPastTimeItems(U32 u32TimeActing) */
EXTERN_C_LINKAGE void _MApp_EpgTimer_DelPastTimeItems(U32 u32TimeActing);
EXTERN_C_LINKAGE void CppTest_Stub__MApp_EpgTimer_DelPastTimeItems(U32 u32TimeActing)
{
	return;
}

/** User stub definition for function: void _MApp_EpgTimer_SortTimerList(void) */
EXTERN_C_LINKAGE void _MApp_EpgTimer_SortTimerList(void);
EXTERN_C_LINKAGE void CppTest_Stub__MApp_EpgTimer_SortTimerList(void)
{
	return;
}

/** User stub definition for function: void _MApp_EpgTimer_SaveTimerList(BOOLEAN bUpdateDB) */
EXTERN_C_LINKAGE void _MApp_EpgTimer_SaveTimerList(BOOLEAN bUpdateDB);
EXTERN_C_LINKAGE void CppTest_Stub__MApp_EpgTimer_SaveTimerList(BOOLEAN bUpdateDB)
{
	return;
}

/** User stub definition for function: U32 MApp_EpgTimer_ResetStartUpTimer(U32 u32TimeAct) */
EXTERN_C_LINKAGE U32 MApp_EpgTimer_ResetStartUpTimer(U32 u32TimeAct);
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_EpgTimer_ResetStartUpTimer(U32 u32TimeAct)
{
	return;
}

/** User stub definition for function: U32 MApp_GetLocalSystemTime(void) */
EXTERN_C_LINKAGE U32 MApp_GetLocalSystemTime(void);
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_GetLocalSystemTime(void)
{
	return 0UL;
}


/** Auto-generated stub definition for function: void MApp_IFrame_Hide(void) */
EXTERN_C_LINKAGE void MApp_IFrame_Hide () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_IFrame_Hide (void)
{
}

/** Auto-generated stub definition for variable: BOOLEAN g_PIDfromMHEG5 */
EXTERN_C_LINKAGE_START
extern BOOLEAN g_PIDfromMHEG5;
BOOLEAN CppTest_Variable_Auto_Stub_g_PIDfromMHEG5 = (unsigned char)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U16 g_u16MHEG5_VideoPID */
EXTERN_C_LINKAGE_START
extern U16 g_u16MHEG5_VideoPID;
U16 CppTest_Variable_Auto_Stub_g_u16MHEG5_VideoPID = (unsigned short)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: U16 g_u16MHEG5_AudioPID */
EXTERN_C_LINKAGE_START
extern U16 g_u16MHEG5_AudioPID;
U16 CppTest_Variable_Auto_Stub_g_u16MHEG5_AudioPID = (unsigned short)0;
EXTERN_C_LINKAGE_END

/** Auto-generated stub definition for variable: BOOLEAN g_bQuietlyTune */
EXTERN_C_LINKAGE_START
extern BOOLEAN g_bQuietlyTune;
BOOLEAN CppTest_Variable_Auto_Stub_g_bQuietlyTune = (unsigned char)0;
EXTERN_C_LINKAGE_END


/** Auto-generated stub definition for function: void MApp_MHEG5_DsmccTime_Update(void) */
EXTERN_C_LINKAGE void MApp_MHEG5_DsmccTime_Update () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_MHEG5_DsmccTime_Update (void)
{
}

/** Auto-generated stub definition for function: M5_MB_RETURN_STATE MApp_MHEG5_ProcessMailBox(void) */
EXTERN_C_LINKAGE M5_MB_RETURN_STATE MApp_MHEG5_ProcessMailBox () ;
EXTERN_C_LINKAGE M5_MB_RETURN_STATE CppTest_Auto_Stub_MApp_MHEG5_ProcessMailBox (void)
{
    return M5_MB_RETURN_OK;
}

/** Auto-generated stub definition for function: void MApp_MHEG5_BootingMonitor(void) */
EXTERN_C_LINKAGE void MApp_MHEG5_BootingMonitor () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_MHEG5_BootingMonitor (void)
{
}

/** Auto-generated stub definition for function: U32 MApp_MHEG5_DsmccTime_Get(void) */
EXTERN_C_LINKAGE U32 MApp_MHEG5_DsmccTime_Get () ;
EXTERN_C_LINKAGE U32 CppTest_Auto_Stub_MApp_MHEG5_DsmccTime_Get (void)
{
    return 0UL;
}

/** Auto-generated stub definition for function: void MApp_MHEG5_DsmccTime_Reset(void) */
EXTERN_C_LINKAGE void MApp_MHEG5_DsmccTime_Reset () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_MHEG5_DsmccTime_Reset (void)
{
}

#include "COFDM_Demodulator.h"


/** Auto-generated stub definition for function: void devCOFDM_SwitchTransportSteamInferface(TS_INTERFACE) */
EXTERN_C_LINKAGE void devCOFDM_SwitchTransportSteamInferface (TS_INTERFACE interface) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_devCOFDM_SwitchTransportSteamInferface (TS_INTERFACE interface)
{
}

/** Auto-generated stub definition for function: FUNCTION_RESULT devCOFDM_GetSignalQuality(WORD *) */
EXTERN_C_LINKAGE FUNCTION_RESULT devCOFDM_GetSignalQuality (WORD * quality) ;
EXTERN_C_LINKAGE FUNCTION_RESULT CppTest_Auto_Stub_devCOFDM_GetSignalQuality (WORD * quality)
{
    return E_RESULT_SUCCESS;
}

/** Auto-generated stub definition for function: BOOLEAN devCOFDM_GetBER(float *) */
EXTERN_C_LINKAGE BOOLEAN devCOFDM_GetBER (float * ber) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_devCOFDM_GetBER (float * ber)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN devCOFDM_GetLockStatus(COFDM_LOCK_STATUS) */
EXTERN_C_LINKAGE BOOLEAN devCOFDM_GetLockStatus (COFDM_LOCK_STATUS eStatus) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_devCOFDM_GetLockStatus (COFDM_LOCK_STATUS eStatus)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BYTE devCOFDM_GetSignalToNoiseRatio(void) */
EXTERN_C_LINKAGE BYTE devCOFDM_GetSignalToNoiseRatio () ;
EXTERN_C_LINKAGE BYTE CppTest_Auto_Stub_devCOFDM_GetSignalToNoiseRatio (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void devCOFDM_SetFrequency(DWORD, RF_CHANNEL_BANDWIDTH, RF_CHANNEL_HP_LP, U8) */
EXTERN_C_LINKAGE void devCOFDM_SetFrequency (DWORD dwFrequency, RF_CHANNEL_BANDWIDTH eBandWidth, RF_CHANNEL_HP_LP eHpLp, U8 u8PlpID) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_devCOFDM_SetFrequency (DWORD dwFrequency, RF_CHANNEL_BANDWIDTH eBandWidth, RF_CHANNEL_HP_LP eHpLp, U8 u8PlpID)
{
}

/** Auto-generated stub definition for function: BOOLEAN devCOFDM_Get_CELL_ID(WORD *) */
EXTERN_C_LINKAGE BOOLEAN devCOFDM_Get_CELL_ID (WORD * wCell_id) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_devCOFDM_Get_CELL_ID (WORD * wCell_id)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN devCOFDM_Is_Hierarchy_On(void) */
EXTERN_C_LINKAGE BOOLEAN devCOFDM_Is_Hierarchy_On () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_devCOFDM_Is_Hierarchy_On (void)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void devCOFDM_ControlPowerOnOff(BOOLEAN) */
EXTERN_C_LINKAGE void devCOFDM_ControlPowerOnOff (BOOLEAN bPowerOn) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_devCOFDM_ControlPowerOnOff (BOOLEAN bPowerOn)
{
}

/** Auto-generated stub definition for function: FUNCTION_RESULT devCOFDM_GetSignalStrength(WORD *) */
EXTERN_C_LINKAGE FUNCTION_RESULT devCOFDM_GetSignalStrength (WORD * strength) ;
EXTERN_C_LINKAGE FUNCTION_RESULT CppTest_Auto_Stub_devCOFDM_GetSignalStrength (WORD * strength)
{
    return E_RESULT_SUCCESS;
}

/** Auto-generated stub definition for function: int strcasecmp(const char *, const char *) */
EXTERN_C_LINKAGE int strcasecmp (const char * __s1, const char * __s2) ;
EXTERN_C_LINKAGE int CppTest_Auto_Stub_strcasecmp (const char * __s1, const char * __s2)
{
    return 0;
}

/** Auto-generated stub definition for function: BOOLEAN devCOFDM_Get_Modul_Mode(WORD *) */
EXTERN_C_LINKAGE BOOLEAN devCOFDM_Get_Modul_Mode (WORD * Modul_Mode) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_devCOFDM_Get_Modul_Mode (WORD * Modul_Mode)
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void devCOFDM_Init(void) */
EXTERN_C_LINKAGE void devCOFDM_Init () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_devCOFDM_Init (void)
{
}

#include "TDSY_G230D.h"


/** Auto-generated stub definition for function: void devTunerInit(void) */
EXTERN_C_LINKAGE void devTunerInit () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_devTunerInit (void)
{
}

/** Auto-generated stub definition for function: void devTunerSetFreq(U32) */
EXTERN_C_LINKAGE void devTunerSetFreq (U32 u32Freq) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_devTunerSetFreq (U32 u32Freq)
{
}

/** User stub definition for function: EN_PIP_MODE MApp_Get_PIPMode(void) */
EXTERN_C_LINKAGE EN_PIP_MODE MApp_Get_PIPMode (void) ;
EXTERN_C_LINKAGE EN_PIP_MODE CppTest_Stub_MApp_Get_PIPMode (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_RestoreSource"))
	{
		return EN_PIP_MODE_MAX;
	}
}

/** User stub definition for function: BOOLEAN MApp_ClosePIPSubWindowSource(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_ClosePIPSubWindowSource (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_ClosePIPSubWindowSource (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_RestoreSource"))
	{
		return TRUE;
	}
}

/** User stub definition for function: void MApp_InputSource_ChangeInputSource_2(SCALER_WIN eWindow) */
EXTERN_C_LINKAGE void MApp_InputSource_ChangeInputSource_2 (SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_InputSource_ChangeInputSource_2 (SCALER_WIN eWindow)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_InputSource_test_MApp_InputSource_RestoreSource"))
	{
		return;
	}
}

/** User stub definition for function: void memset(void * s, int c, size_t count) */
EXTERN_C_LINKAGE void *memset(void * s, int c, size_t count);
EXTERN_C_LINKAGE void *CppTest_Stub_memset (void * s, int c, size_t count)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_Probe_case1"))
	{
		memset(s,c,count);
		return;
	}
  return;
}

/** User stub definition for function: void * UTL_memset(void *, int, size_t) */
EXTERN_C_LINKAGE void *UTL_memset( void *d, int c, size_t n );
EXTERN_C_LINKAGE void * CppTest_Stub_UTL_memset( void *d, int c, size_t n )
{
	char* pcData = (char*)d;

	//printf("UT_memset()\n");

	if( pcData == NULL )
		return;

	while(n)
	{
		*pcData = c;
		pcData += 1;
		n -= 1;
	}
}

/** User stub definition for function: void MDrv_PQ_Init(MS_PQ_Init_Info *pstPQInitInfo); */
EXTERN_C_LINKAGE void MDrv_PQ_Init(MS_PQ_Init_Info *pstPQInitInfo);
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_PQ_Init(MS_PQ_Init_Info *pstPQInitInfo)
{
    return;
}

/** User stub definition for function: BOOLEAN msAPI_Tuner_IsTuningProcessorBusy (void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Tuner_IsTuningProcessorBusy (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Tuner_IsTuningProcessorBusy (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_EXIT_SCAN_TYPE_MANUAL")
	|| CppTest_IsCurrentTestCase("TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_MENU_SCAN_TYPE_MANUAL")
	|| CppTest_IsCurrentTestCase("TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_RIGHT_SCAN_TYPE_MANUAL")
	|| CppTest_IsCurrentTestCase("TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_ProcessUserInput_case_KEY_LEFT_SCAN_TYPE_MANUAL")
	|| CppTest_IsCurrentTestCase("TestSuite_MApp_ATV_Scan_test_MApp_ATV_Scan_End")
	|| CppTest_IsCurrentTestCase("TestSuite_MApp_ATVProc_test_MApp_ATVProc_Exit_IF_Success"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: void msAPI_Tuner_TuningProcessor (eAFTSTEP eState) */
EXTERN_C_LINKAGE void msAPI_Tuner_TuningProcessor(eAFTSTEP eState);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Tuner_TuningProcessor (eAFTSTEP eState)
{
}

/** User stub definition for function: BOOLEAN MApp_isKeypadUPLR(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_isKeypadUPLR (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_isKeypadUPLR (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_PLUS_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_CHANNEL_MINUS_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_PLUS_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_VOLUME_MINUS_if")
		)
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: BOOLEAN MApp_isKeypadSourceKeyCanSelect(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_isKeypadSourceKeyCanSelect (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_isKeypadSourceKeyCanSelect (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_IR_test_MApp_ParseKey_else_case_IRKEY_INPUT_SOURCE_if"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: BOOLEAN msAPI_VID_GetVidInfo(VDEC_DispInfo *pstVidStatus) */
EXTERN_C_LINKAGE BOOLEAN msAPI_VID_GetVidInfo(VDEC_DispInfo *pstVidStatus);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_VID_GetVidInfo(VDEC_DispInfo *pstVidStatus)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_true"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_IsSrcHasSignal_false"))
	{
		return (unsigned char)0;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: void MDrv_Sys_SetWatchDogTimer (U8) */
EXTERN_C_LINKAGE void MDrv_Sys_SetWatchDogTimer( U8 sec );
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_Sys_SetWatchDogTimer( U8 sec )
{
}

/** User stub definition for function: MDrv_Sys_EnableWatchDog(void) */
EXTERN_C_LINKAGE void MDrv_Sys_EnableWatchDog(void);
EXTERN_C_LINKAGE void CppTest_Stub_MDrv_Sys_EnableWatchDog(void)
{
}

/** User stub definition for function: BDMA_Result MApi_BDMA_Copy(U32 u32Srcaddr, U32 u32Dstaddr, U32 u32Len, MEMCOPYTYPE eType) */
EXTERN_C_LINKAGE BDMA_Result MApi_BDMA_Copy(U32 u32Srcaddr, U32 u32Dstaddr, U32 u32Len, MEMCOPYTYPE eType);
EXTERN_C_LINKAGE BDMA_Result CppTest_Stub_MApi_BDMA_Copy(U32 u32Srcaddr, U32 u32Dstaddr, U32 u32Len, MEMCOPYTYPE eType)
{
	return E_BDMA_OK;
}

/** User stub definition for function: void msAPI_VE_SetOutputCtrl(PMS_VE_Output_Ctrl pOutputCtrl) */
EXTERN_C_LINKAGE void msAPI_VE_SetOutputCtrl(PMS_VE_Output_Ctrl pOutputCtrl);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_VE_SetOutputCtrl(PMS_VE_Output_Ctrl pOutputCtrl)
{
}

//!!
/** User stub definition for function: BOOLEAN msAPI_InputSrcType_InUsedType(SCALER_WIN eWindow,EN_SYS_INPUT_SOURCE_TYPE enInpSrcType) */
EXTERN_C_LINKAGE BOOLEAN msAPI_InputSrcType_InUsedType(SCALER_WIN eWindow,EN_SYS_INPUT_SOURCE_TYPE enInpSrcType);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_InputSrcType_InUsedType(SCALER_WIN eWindow,EN_SYS_INPUT_SOURCE_TYPE enInpSrcType)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_USBDownload_test_MApp_UsbDownload_Init") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_SetCheckAlternativeFlag") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test__MApp_TV_LossSignal_CheckOriginalRF") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2") ||
		CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3") ||
		CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetCurrentOrdinal_E_SERVICETYPE_UNITED_TV_ifyes_ifyes")
		)
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: MW_AUD_SetSoundMute(SOUND_MUTE_SOURCE eSoundMuteSource, SOUND_MUTE_TYPE eOnOff) */
EXTERN_C_LINKAGE void MW_AUD_SetSoundMute(SOUND_MUTE_SOURCE eSoundMuteSource, SOUND_MUTE_TYPE eOnOff);
EXTERN_C_LINKAGE void CppTest_Stub_MW_AUD_SetSoundMute(SOUND_MUTE_SOURCE eSoundMuteSource, SOUND_MUTE_TYPE eOnOff)
{
}

/** User stub definition for function: MW_UsbDownload_Init(U8 u8USBPortNo, U8 u8FlashID, U32 u32DRAMAddr, U32 u32DRAMLen, U32 u32FlashSize, U8 u8UpgradeMode, U8 u8MemType, U8 * pu8FileName, pZUIDrawCB ZUIDrawPercentage, BOOLEAN bAPBinFlag) */
EXTERN_C_LINKAGE void MW_UsbDownload_Init(U8 u8USBPortNo, U8 u8FlashID, U32 u32DRAMAddr, U32 u32DRAMLen, U32 u32FlashSize, U8 u8UpgradeMode, U8 u8MemType, U8 * pu8FileName, pZUIDrawCB ZUIDrawPercentage, BOOLEAN bAPBinFlag);
EXTERN_C_LINKAGE void CppTest_Stub_MW_UsbDownload_Init(U8 u8USBPortNo, U8 u8FlashID, U32 u32DRAMAddr, U32 u32DRAMLen, U32 u32FlashSize, U8 u8UpgradeMode, U8 u8MemType, U8 * pu8FileName, pZUIDrawCB ZUIDrawPercentage, BOOLEAN bAPBinFlag)
{
}

/** User stub definition for function: BOOLEAN msAPI_Picture_isAFDEnable(EN_ASPECT_RATIO_TYPE enVideoScreen) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Picture_isAFDEnable (EN_ASPECT_RATIO_TYPE enVideoScreen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Picture_isAFDEnable (EN_ASPECT_RATIO_TYPE enVideoScreen)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MHEG5_Main_test_MApp_MHEG5_Init_if"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: BOOLEAN msAPI_Picture_isCurrentAFDVaild(U8 tmpAFD) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Picture_isCurrentAFDVaild (EN_ASPECT_RATIO_TYPE enVideoScreen) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Picture_isCurrentAFDVaild (EN_ASPECT_RATIO_TYPE enVideoScreen)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MHEG5_Main_test_MApp_MHEG5_Init_if"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: void msAPI_MHEG5_SendOSWidthHeight_AudioPid_PanelRatio (U32 u32Width, U32 u32Height, U16 u16AudioPid, U16 u16VideoPid) */
EXTERN_C_LINKAGE void msAPI_MHEG5_SendOSWidthHeight_AudioPid_PanelRatio(U32 u32Width, U32 u32Height, U16 u16AudioPid, U16 u16VideoPid);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_MHEG5_SendOSWidthHeight_AudioPid_PanelRatio (U32 u32Width, U32 u32Height, U16 u16AudioPid, U16 u16VideoPid)
{
	return;
}

/** User stub definition for function: void msAPI_MHEG5_SendPanelInfo (void) */
EXTERN_C_LINKAGE void msAPI_MHEG5_SendPanelInfo(void);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_MHEG5_SendPanelInfo (void)
{
	return;
}

/** User stub definition for function: EN_ASPECT_RATIO_TYPE MApp_Scaler_GetAspectRatio (SCALER_WIN eWindow,EN_MENU_AspectRatio eAspect) */
EXTERN_C_LINKAGE EN_ASPECT_RATIO_TYPE MApp_Scaler_GetAspectRatio(SCALER_WIN eWindow,EN_MENU_AspectRatio eAspect);
EXTERN_C_LINKAGE EN_ASPECT_RATIO_TYPE CppTest_Stub_MApp_Scaler_GetAspectRatio (SCALER_WIN eWindow,EN_MENU_AspectRatio eAspect)
{
	return VIDEOSCREEN_NUMS;
}

/** User stub definition for function: BOOLEAN msAPI_MHEG5_IsRunning(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MHEG5_IsRunning (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MHEG5_IsRunning (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MHEG5_Main_test_MApp_MHEG5_Set_Display_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_MHEG5_Main_test_MApi_MHEG5_Disable_case_EN_MHEG5_DM_DISABLE_WITH_AUTOBOOT_LATER") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test_MApp_Scaler_SetVideo3DMode_MHEG5_E_USER_3D_MODE_OFF")
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/** User stub definition for function: U8 msAPI_MHEG5_GetGraphInfoRefreshType(void) */
EXTERN_C_LINKAGE U8 msAPI_MHEG5_GetGraphInfoRefreshType (void) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_MHEG5_GetGraphInfoRefreshType (void)
{
	return TRUE;
}

/** User stub definition for function: BOOLEAN msAPI_MHEG5_GetBinStatus(void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MHEG5_GetBinStatus (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MHEG5_GetBinStatus (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MHEG5_Main_test_MApi_MHEG5_Disable_return"))
	{
		return FALSE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime"))
	{
		return TRUE;
	}
	else
	{
		return TRUE;
	}
}

/** User stub definition for function: U16 msAPI_PVRFS_GetBulksNumToCreate(void) */
EXTERN_C_LINKAGE U16 msAPI_PVRFS_GetBulksNumToCreate (void) ;
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_PVRFS_GetBulksNumToCreate (void)
{
	return 10;
}

/** User stub definition for function: U16 msAPI_PVRFS_GetCurrentCreateBulkNum(void) */
EXTERN_C_LINKAGE U16 msAPI_PVRFS_GetCurrentCreateBulkNum (void) ;
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_PVRFS_GetCurrentCreateBulkNum (void)
{
	return 11;
}

/** User stub definition for function: U32 msAPI_PVRFS_GetFATFormatWriteCnt(U8 u8DriveNo) */
EXTERN_C_LINKAGE U32 msAPI_PVRFS_GetFATFormatWriteCnt (U8 u8DriveNo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_PVRFS_GetFATFormatWriteCnt (U8 u8DriveNo)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_DiskFormatGetPercentage_if"))
	{
		return 10;
	}
	else
	{
		return 0;
	}
}

/** User stub definition for function: U8 msAPI_FSEnv_Register(U8 driveID) */
EXTERN_C_LINKAGE U8 msAPI_FSEnv_Register (U8 driveID) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_FSEnv_Register (U8 driveID)
{
	if(CppTest_IsCurrentTestCase("test_MApp_PVR_DiskGetAvailableSizeMB_if"))
	{
		return FS_ENVIRONMENT_NUM;
	}
	else if(CppTest_IsCurrentTestCase("test_MApp_PVR_DiskGetAvailableSizeMB_else"))
	{
		return (0);
	}
}

/** User stub definition for function: void MApp_Record_AudioAddServices (U8 u8PathNum, U8 u8Idx, U8 u8Num) */
EXTERN_C_LINKAGE void MApp_Record_AudioAddServices(U8 u8PathNum, U8 u8Idx, U8 u8Num);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Record_AudioAddServices (U8 u8PathNum, U8 u8Idx, U8 u8Num)
{
	return;
}

/** User stub definition for function: void MApp_Record_SubtitleAddServices (U8 u8PathNum, U8 u8Idx, U8 u8Num) */
EXTERN_C_LINKAGE void MApp_Record_SubtitleAddServices(U8 u8PathNum, U8 u8Idx, U8 u8Num);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Record_SubtitleAddServices (U8 u8PathNum, U8 u8Idx, U8 u8Num)
{
	return;
}

/** User stub definition for function: void MApp_Playback_AudioSelectLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_Playback_AudioSelectLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_AudioSelectLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: void MApp_TimeShift_AudioSelectLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_TimeShift_AudioSelectLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_AudioSelectLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: void MApp_Playback_AudioStopLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_Playback_AudioStopLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_AudioStopLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: void MApp_TimeShift_AudioStopLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_TimeShift_AudioStopLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_AudioStopLanguage (U8 u8AudSelectedIndex)
{
	return;
}

#include "MApp_TimeShift.h"
#include "MApp_Playback.h"
/** User stub definition for function: void MApp_Playback_AdAudioSelectLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_Playback_AdAudioSelectLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_AdAudioSelectLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: void MApp_TimeShift_AdAudioSelectLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_TimeShift_AdAudioSelectLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_AdAudioSelectLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: void MApp_Playback_AdAudioStopLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_Playback_AdAudioStopLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_AdAudioStopLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: void MApp_TimeShift_AdAudioStopLanguage (U8 u8AudSelectedIndex) */
EXTERN_C_LINKAGE void MApp_TimeShift_AdAudioStopLanguage(U8 u8AudSelectedIndex);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_AdAudioStopLanguage (U8 u8AudSelectedIndex)
{
	return;
}

/** User stub definition for function: enTimeShiftState MApp_TimeShift_StateMachineGet (void) */
EXTERN_C_LINKAGE enTimeShiftState MApp_TimeShift_StateMachineGet(void);
EXTERN_C_LINKAGE enTimeShiftState CppTest_Stub_MApp_TimeShift_StateMachineGet (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_if")
		)
	{
		return E_TIMESHIFT_STATE_RECORDINGnPLAYBACKING;
	}

}

/** User stub definition for function: enPlaybackState MApp_Playback_StateMachineGet (void) */
EXTERN_C_LINKAGE enPlaybackState MApp_Playback_StateMachineGet(void);
EXTERN_C_LINKAGE enPlaybackState CppTest_Stub_MApp_Playback_StateMachineGet (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadServices_elseif") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_PlaybackSubtitleLoadMenu_elseif") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_PlaybackGetTTXSubtitleNum_elseif")
		)
	{
		return E_PLAYBACK_STATE_PLAYBACKING;
	}

}

/** User stub definition for function: void MApp_TimeShift_Subtitle_LoadMenu (U8* pu8SelIdx, U8* pu8Num, SUBTITLE_MENU* options, U8* pu8fEnableSubtitle, U8* pu8fEnableTTXSubtitle) */
EXTERN_C_LINKAGE void MApp_TimeShift_Subtitle_LoadMenu(U8* pu8SelIdx, U8* pu8Num, SUBTITLE_MENU* options, U8* pu8fEnableSubtitle, U8* pu8fEnableTTXSubtitle);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_Subtitle_LoadMenu (U8* pu8SelIdx, U8* pu8Num, SUBTITLE_MENU* options, U8* pu8fEnableSubtitle, U8* pu8fEnableTTXSubtitle)
{
	return;
}

/** User stub definition for function: void MApp_Playback_Subtitle_LoadMenu (U8* pu8SelIdx, U8* pu8Num, SUBTITLE_MENU* options, U8* pu8fEnableSubtitle, U8* pu8fEnableTTXSubtitle) */
EXTERN_C_LINKAGE void MApp_Playback_Subtitle_LoadMenu(U8* pu8SelIdx, U8* pu8Num, SUBTITLE_MENU* options, U8* pu8fEnableSubtitle, U8* pu8fEnableTTXSubtitle);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_Subtitle_LoadMenu (U8* pu8SelIdx, U8* pu8Num, SUBTITLE_MENU* options, U8* pu8fEnableSubtitle, U8* pu8fEnableTTXSubtitle)
{
	return;
}

/** User stub definition for function: void MApp_Playback_Subtitle_LoadServices (U8* pu8SelIdx, U8* pu8Num, DVB_SUBTITLE_SERVICE* options) */
EXTERN_C_LINKAGE void MApp_Playback_Subtitle_LoadServices(U8* pu8SelIdx, U8* pu8Num, DVB_SUBTITLE_SERVICE* options);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_Subtitle_LoadServices (U8* pu8SelIdx, U8* pu8Num, DVB_SUBTITLE_SERVICE* options)
{
	return;
}

/** User stub definition for function: void MApp_TimeShift_Subtitle_LoadServices (U8* pu8SelIdx, U8* pu8Num, DVB_SUBTITLE_SERVICE* options) */
EXTERN_C_LINKAGE void MApp_TimeShift_Subtitle_LoadServices(U8* pu8SelIdx, U8* pu8Num, DVB_SUBTITLE_SERVICE* options);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_Subtitle_LoadServices (U8* pu8SelIdx, U8* pu8Num, DVB_SUBTITLE_SERVICE* options)
{
	return;
}

/** User stub definition for function: void MApp_TimeShift_TTXSubtitle_GetNum (U8* pu8Num) */
EXTERN_C_LINKAGE void MApp_TimeShift_TTXSubtitle_GetNum(U8* pu8Num);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_TimeShift_TTXSubtitle_GetNum (U8* pu8Num)
{
	return;
}

/** User stub definition for function: void MApp_Playback_TTXSubtitle_GetNum (U8* pu8Num) */
EXTERN_C_LINKAGE void MApp_Playback_TTXSubtitle_GetNum(U8* pu8Num);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Playback_TTXSubtitle_GetNum (U8* pu8Num)
{
	return;
}

/** User stub definition for function: EN_TELETEXT_MODE MApp_TTX_GetControlMode (void) */
EXTERN_C_LINKAGE EN_TELETEXT_MODE MApp_TTX_GetControlMode(void);
EXTERN_C_LINKAGE EN_TELETEXT_MODE CppTest_Stub_MApp_TTX_GetControlMode (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK_chagnetoNULL"))
	{
		return TTX_MODE_CLOCK;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else"))
	{
		return TTX_MODE_STATUS;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DEFAULT") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_CLOCK") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RED") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_GREEN") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_YELLOW") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BLUE") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_BACK") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UP") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_DOWN") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_LEFT") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_RIGHT") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_UPDATE") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_DSC_KEY_MULTI_PIP") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TIME") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_HOLD") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_REVEAL") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SIZE") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_TTX_MODE") ||
			//CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_PIP") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_PLUS") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_VOLUME_MINUS") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_if") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_SUBTITLE_else") ||
			CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_if_case_KEY_EXIT")
			)
	{
		return TTX_MODE_SUBTITLE;
	}
	else
	{
		return TTX_MODE_NORMAL;
	}
}

/** User stub definition for function: void MApp_AVCH264_VariableInit (void) */
EXTERN_C_LINKAGE void MApp_AVCH264_VariableInit( void );
EXTERN_C_LINKAGE void CppTest_Stub_MApp_AVCH264_VariableInit( void )
{
}

/** User stub definition for function: void MApp_MVD_VariableInit (void) */
EXTERN_C_LINKAGE void MApp_MVD_VariableInit( void );
EXTERN_C_LINKAGE void CppTest_Stub_MApp_MVD_VariableInit( void )
{
}

/** User stub definition for function: void msAPI_VID_GetCodecType (void) */
EXTERN_C_LINKAGE VDEC_CodecType msAPI_VID_GetCodecType(void);
EXTERN_C_LINKAGE VDEC_CodecType CppTest_Stub_msAPI_VID_GetCodecType(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MVDMode_test_MApp_VID_PrepareTimingChange_IS_HVD_CODEC")
	|| CppTest_IsCurrentTestCase("TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_IS_HVD_CODEC"))
	{
		return E_VDEC_CODEC_TYPE_H264;
	}
	else
	{
		return E_VDEC_CODEC_TYPE_MPEG2;
	}
}

/** User stub definition for function: void MApp_AVCH264_SetMode (void) */
EXTERN_C_LINKAGE BOOLEAN MApp_AVCH264_SetMode( SCALER_WIN eWindow );
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_AVCH264_SetMode( SCALER_WIN eWindow )
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_IS_HVD_CODEC"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: void MApp_MVD_SetMode (void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MVD_SetMode( SCALER_WIN eWindow );
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MVD_SetMode( SCALER_WIN eWindow )
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_MVDMode_test_MApp_VID_SetMode_NOT_HVD_CODEC"))
	{
		return (unsigned char)1;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** User stub definition for function: BOOLEAN msAPI_AUD_IsAudioMutedByUser (void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_AUD_IsAudioMutedByUser(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_AUD_IsAudioMutedByUser (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_if"))
	{
		return FALSE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TTX_Idle_ProcessUserInput_if_else_case_KEY_MUTE_else"))
	{
		return TRUE;
	}
}

/** User stub definition for function: EN_OSD_COUNTRY_SETTING MApp_GetOSDCountrySetting (void) */
EXTERN_C_LINKAGE EN_OSD_COUNTRY_SETTING MApp_GetOSDCountrySetting(void);
EXTERN_C_LINKAGE EN_OSD_COUNTRY_SETTING CppTest_Stub_MApp_GetOSDCountrySetting (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_SetCheckAlternativeFlag") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test__MApp_TV_LossSignal_CheckOriginalRF") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3") ||
		CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1")
		)
	{
		return OSD_COUNTRY_NORWAY;
	}
}

/** User stub definition for function: BYTE msAPI_CM_GetOriginalRFnumber (MEMBER_SERVICETYPE bServiceType, WORD wPosition) */
EXTERN_C_LINKAGE BYTE msAPI_CM_GetOriginalRFnumber(MEMBER_SERVICETYPE bServiceType, WORD wPosition);
EXTERN_C_LINKAGE BYTE CppTest_Stub_msAPI_CM_GetOriginalRFnumber (MEMBER_SERVICETYPE bServiceType, WORD wPosition)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test__MApp_TV_LossSignal_CheckOriginalRF"))
	{
		return 0x01;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1"))
	{
		return INVALID_PHYSICAL_CHANNEL_NUMBER;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2"))
	{
		return 0x01;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3"))
	{
		return INVALID_PHYSICAL_CHANNEL_NUMBER;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_Scan_test_MApp_Scan_AddOneDTVPchVchs_logic1"))
	{
		return INVALID_PHYSICAL_CHANNEL_NUMBER;
	}
}

#include "MApp_GlobalFunction.h"
/** User stub definition for function: U32 msAPI_Timer_GetSystemTime (void) */
EXTERN_C_LINKAGE U32 msAPI_Timer_GetSystemTime(void);
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Timer_GetSystemTime (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1"))
	{
		return 0;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3"))
	{
		return (SECONDS_PER_30DAYS*2);
	}
}

/** User stub definition for function: BOOLEAN msAPI_CM_GetIDTable (BYTE bIDIndex, BYTE * pcBuffer,PROGRAMDATA_MEMBER eMember) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CM_GetIDTable(BYTE bIDIndex, BYTE * pcBuffer,PROGRAMDATA_MEMBER eMember);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_GetIDTable (BYTE bIDIndex, BYTE * pcBuffer,PROGRAMDATA_MEMBER eMember)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if1"))
	{
		return 0;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if2"))
	{
		return 0;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_CheckLossSignal30Days_if3"))
	{
		return 0;
	}
}

/** User stub definition for function: BOOLEAN MApp_PVR_IsPlaybacking (void) */
EXTERN_C_LINKAGE BOOLEAN MApp_PVR_IsPlaybacking(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_PVR_IsPlaybacking (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_MApp_PVR_IsPlaybacking"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/** User stub definition for function: BOOLEAN msAPI_CM_GetProgramAttribute (MEMBER_SERVICETYPE bServiceType, WORD wPosition, E_MEMBER_CHANNEL_ATTRIBUTE eAttributeMember) */
EXTERN_C_LINKAGE BOOLEAN msAPI_CM_GetProgramAttribute(MEMBER_SERVICETYPE bServiceType, WORD wPosition, E_MEMBER_CHANNEL_ATTRIBUTE eAttributeMember);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_GetProgramAttribute (MEMBER_SERVICETYPE bServiceType, WORD wPosition, E_MEMBER_CHANNEL_ATTRIBUTE eAttributeMember)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING1"))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/** User stub definition for function: BOOLEAN MApp_TV_IsProgramRunning (void) */
EXTERN_C_LINKAGE BOOLEAN MApp_TV_IsProgramRunning(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_TV_IsProgramRunning (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NOT_RUNNING2"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/** User stub definition for function: WORD msAPI_CM_CountProgram (MEMBER_SERVICETYPE bServiceType, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary) */
EXTERN_C_LINKAGE WORD msAPI_CM_CountProgram(MEMBER_SERVICETYPE bServiceType, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_CountProgram (MEMBER_SERVICETYPE bServiceType, E_MEMBER_PROGRAM_ACCESSIBLE_BOUNDARY eBoundary)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetAttributeOfOrdinal_E_SERVICE_ATTR_TYPE__E_SERVICETYPE_UNITED_TV_ifyes"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif2"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif1"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif3"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif2"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 1;
	}
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TV_test_MApp_TV_ScreenSaverClear_EN_SCREENSAVER_NODATABASE"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif1"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_elif2"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_E_SERVICETYPE_UNITED_TV_else"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV_break"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_DTV"))
	{
		return 1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_CountProgram_E_SERVICETYPE_UNITED_TV"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

EXTERN_C_LINKAGE BOOLEAN msAPI_CM_SetCurrentServiceType(MEMBER_SERVICETYPE bServiceType);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_SetCurrentServiceType(MEMBER_SERVICETYPE bServiceType)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if"))
	{
		return TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetNextProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped, CHANNEL_LIST_TYPE bList_type, MEMBER_SERVICETYPE *bNewServiceType);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetNextProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped, CHANNEL_LIST_TYPE bList_type, MEMBER_SERVICETYPE *bNewServiceType)
{
	return 0;
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetPrevProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped, CHANNEL_LIST_TYPE bList_type, MEMBER_SERVICETYPE *bNewServiceType);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetPrevProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped, CHANNEL_LIST_TYPE bList_type, MEMBER_SERVICETYPE *bNewServiceType)
{
	return 0;
}

EXTERN_C_LINKAGE WORD msAPI_CM_CountFavoriteProgram(MEMBER_SERVICETYPE bServiceType);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_CountFavoriteProgram(MEMBER_SERVICETYPE bServiceType)
{
	return 0;
}

//BYTE msAPI_ATV_ConvertProgramNumberToOrdinalNumber(BYTE u8ProgramNumber)
EXTERN_C_LINKAGE BYTE msAPI_ATV_ConvertProgramNumberToOrdinalNumber(BYTE u8ProgramNumber);
EXTERN_C_LINKAGE BYTE CppTest_Stub_msAPI_ATV_ConvertProgramNumberToOrdinalNumber(BYTE u8ProgramNumber)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_else"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif2"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif1"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_else"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_else"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif3"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif2"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetPrevFavoriteOrdinal_E_SERVICETYPE_ATV"))
	{
		return 0xFF;
	}
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return 0xFF;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return 0xFF;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetNextFavoriteOrdinal_E_SERVICETYPE_ATV"))
	{
		return 0xFF;
	}
	return 0;
}

EXTERN_C_LINKAGE void msAPI_ATV_SetCurrentProgramNumber(BYTE u8ProgramNumber);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_ATV_SetCurrentProgramNumber(BYTE u8ProgramNumber)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_ATV"))
	{
		return ;
	}
	else
	{
		return ;
	}
}

EXTERN_C_LINKAGE BOOLEAN msAPI_CM_SetCurrentPosition(MEMBER_SERVICETYPE bServiceType, WORD wPosition);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_CM_SetCurrentPosition(MEMBER_SERVICETYPE bServiceType, WORD wPosition)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_RADIO_if"))
	{
		return TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_SetMove2CurrentOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/** User stub definition for function: enPvrApiStatus msAPI_PVR_PlaybackPathAddPID (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath, U16 u16PID, MSAPI_DMX_FILTER_TYPE enFltType) */
EXTERN_C_LINKAGE enPvrApiStatus msAPI_PVR_PlaybackPathAddPID(_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath, U16 u16PID, MSAPI_DMX_FILTER_TYPE enFltType);
EXTERN_C_LINKAGE enPvrApiStatus CppTest_Stub_msAPI_PVR_PlaybackPathAddPID (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath, U16 u16PID, MSAPI_DMX_FILTER_TYPE enFltType)
{
	return E_PVR_API_STATUS_OK;
}

/** User stub definition for function: enPvrApiStatus msAPI_PVR_PlaybackPathDelPID (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath, U16 u16PID, MSAPI_DMX_FILTER_TYPE enFltType) */
EXTERN_C_LINKAGE enPvrApiStatus msAPI_PVR_PlaybackPathDelPID(_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath, U16 u16PID, MSAPI_DMX_FILTER_TYPE enFltType);
EXTERN_C_LINKAGE enPvrApiStatus CppTest_Stub_msAPI_PVR_PlaybackPathDelPID (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath, U16 u16PID, MSAPI_DMX_FILTER_TYPE enFltType)
{
	return E_PVR_API_STATUS_OK;
}

/** User stub definition for function: enPvrApiStatus msAPI_PVR_PlaybackPathClose (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath) */
EXTERN_C_LINKAGE enPvrApiStatus msAPI_PVR_PlaybackPathClose(_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath);
EXTERN_C_LINKAGE enPvrApiStatus CppTest_Stub_msAPI_PVR_PlaybackPathClose (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackClose_else"))
	{
		return E_PVR_API_STATUS_OK;
	}
}

/** User stub definition for function: enPvrApiStatus msAPI_PVR_PlaybackPathStop (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath) */
EXTERN_C_LINKAGE enPvrApiStatus msAPI_PVR_PlaybackPathStop(_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath);
EXTERN_C_LINKAGE enPvrApiStatus CppTest_Stub_msAPI_PVR_PlaybackPathStop (_msAPI_PVR_PlaybackPath * pstPvrPlaybackPath)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_if") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_PlaybackDisable_else")
		)
	{
		return E_PVR_API_STATUS_OK;
	}
}

#include "MApp_MassStorage.h"
/** User stub definition for function: U8 MApp_MassStorage_DeviceConnectionDetect (void) */
EXTERN_C_LINKAGE U8 MApp_MassStorage_DeviceConnectionDetect(void);
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_MassStorage_DeviceConnectionDetect (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_if"))
	{
		return MS_PLAYALL;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_else"))
	{
		return MS_USB_CONNECTED;
	}
}

/** User stub definition for function: U8 msAPI_PVRFS_FileOpen (U16* pu16FileName, EN_PVRFS_OPEN_MODE mode) */
EXTERN_C_LINKAGE U8 msAPI_PVRFS_FileOpen(U16* pu16FileName, EN_PVRFS_OPEN_MODE mode);
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_PVRFS_FileOpen (U16* pu16FileName, EN_PVRFS_OPEN_MODE mode)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_DelTsFileName_else"))
	{
		return 0x01;
	}
}

/** User stub definition for function: EN_PVRFS_FSTYPE msAPI_PVRFS_GetFileSystemType (void) */
EXTERN_C_LINKAGE EN_PVRFS_FSTYPE msAPI_PVRFS_GetFileSystemType(void);
EXTERN_C_LINKAGE EN_PVRFS_FSTYPE CppTest_Stub_msAPI_PVRFS_GetFileSystemType (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if2"))
	{
		return PVR_FS_N51FAT32;
	}
	else
	{
		return PVR_FS_BULKFS;
	}
}

/** User stub definition for function: BOOLEAN msAPI_PVR_IsRecordSpaceEnough (void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_PVR_IsRecordSpaceEnough(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_PVR_IsRecordSpaceEnough (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if2"))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/** User stub definition for function: _msAPI_PVR_RecordPath * msAPI_PVR_RecordPathOpen (U16 *pu16RecordPathName, enPvrFileMode enFileMode) */
EXTERN_C_LINKAGE _msAPI_PVR_RecordPath * msAPI_PVR_RecordPathOpen(U16 *pu16RecordPathName, enPvrFileMode enFileMode);
EXTERN_C_LINKAGE _msAPI_PVR_RecordPath * CppTest_Stub_msAPI_PVR_RecordPathOpen (U16 *pu16RecordPathName, enPvrFileMode enFileMode)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_if3"))
	{
		int iTest=10;
		return &iTest;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_TimeShift_test_MApp_TimeShift_RecordOpen_else3"))
	{
		return 0;
	}
}

/** User stub definition for function: BOOLEAN msAPI_AVD_IsSyncLocked(void)*/
EXTERN_C_LINKAGE BOOLEAN msAPI_AVD_IsSyncLocked(void);
EXTERN_C_LINKAGE BOOLEAN * CppTest_Stub_msAPI_AVD_IsSyncLocked(void)
{
    if( CppTest_IsCurrentTestCase("TestSuite_MApp_VDMode_test_MApp_VD_IsSyncLock_True") )
    {
        return 1;
    }

    return 0;
}

/** User stub definition for function: BOOLEAN msAPI_MHEG5_IsIFrameExist (void) */
EXTERN_C_LINKAGE BOOLEAN msAPI_MHEG5_IsIFrameExist(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_MHEG5_IsIFrameExist (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test_MApp_Scaler_SetVideo3DMode_MHEG5_E_USER_3D_MODE_OFF"))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
EXTERN_C_LINKAGE BOOLEAN msAPI_PVRFS_SetBulkSpeed(U16 _newSpeed);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_PVRFS_SetBulkSpeed(U16 _newSpeed)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_DiskSetSpeed_Yes"))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

EXTERN_C_LINKAGE BOOLEAN msAPI_PVRFS_IsInitialized();
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_PVRFS_IsInitialized()
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_DiskGetSpeed_If2_IsTrue"))
	{
		return TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_PVR_test_MApp_PVR_DiskGetSpeed_If2_IsFalse"))
	{
		return FALSE;
	}
}

EXTERN_C_LINKAGE AVD_VideoStandardType msAPI_AVD_GetVideoStandard(void);
EXTERN_C_LINKAGE AVD_VideoStandardType CppTest_Stub_msAPI_AVD_GetVideoStandard(void)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test__MApp_Scaler_ProgDigitalWin_ntsc") )
	{
		return E_VIDEOSTANDARD_NTSC_M;
	}
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_Scaler_test__MApp_Scaler_ProgDigitalWin_PAL") )
	{
		return E_VIDEOSTANDARD_PAL_BGHI;
	}

    return E_VIDEOSTANDARD_NOTSTANDARD;
}

EXTERN_C_LINKAGE BOOLEAN _SetNVRAM(DWORD u32Address, BYTE *pu8Buffer, BYTE u8Size);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__SetNVRAM(DWORD u32Address, BYTE *pu8Buffer, BYTE u8Size)
{
    if( CppTest_IsCurrentTestCase("TestSuite_msAPI_ATVSystem_test__SwapPRTable_index_invalid") )
    {
        return FALSE;
    }

    return TRUE;
}

EXTERN_C_LINKAGE const HDMI_PACKET_INFO_t *MApi_XC_HDMI_GetPacketInfo(void);
EXTERN_C_LINKAGE const HDMI_PACKET_INFO_t* CppTest_Stub_MApi_XC_HDMI_GetPacketInfo(void)
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_XC_PQ_test_MApp_Picture_ColorCtrl_CheckColorRange") )
	{
		g_HdmiPacketInfo.enPKT_Value.PKT_AVI_VALUE = BIT(3);
	}

    return &g_HdmiPacketInfo;
}

/** User stub definition for function: void MApp_MultiTasks(void)*/
EXTERN_C_LINKAGE void MApp_MultiTasks(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_MultiTasks(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_MULTITASKS"))
	{
		return;
	}
}

/** User stub definition for function: MS_BOOL MApp_PowerOn_Stage_Debug(void)*/
EXTERN_C_LINKAGE MS_BOOL MApp_PowerOn_Stage_Debug(void);
EXTERN_C_LINKAGE MS_BOOL CppTest_Stub_MApp_PowerOn_Stage_Debug(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_if"))
	{
		return TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_While_Loop_State_case_EN_WHILE_LOOP_UART_PAUSE_else"))
	{
		return FALSE;
	}
}

/** User stub definition for function: void MApp_PreInit_State01(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State01(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State01(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_01"))
	{
		return;
	}
}

/** User stub definition for function: void MApp_PreInit_State02(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State02(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State02(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_02"))
	{
		return;
	}
}

/** User stub definition for function: void MApp_PreInit_State03_DrvInitStep1(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State03_DrvInitStep1(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State03_DrvInitStep1(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_03"))
	{
		return;
	}
}

/** User stub definition for function: void MApp_PreInit_State04(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State04(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State04(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_04"))
	{
		return;
	}
}

/** User stub definition for function: void MApp_PreInit_State06_DrvInitStep2(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State06_DrvInitStep2(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State06_DrvInitStep2(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_06"))
	{
		return;
	}
}

/** User stub definition for function: void MApp_PreInit_State08(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State08(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State08(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_08"))
	{
		return;
	}
}

/** User stub definition for function: void MApp_PreInit_State10_DataBaseChecking(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State10_DataBaseChecking(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State10_DataBaseChecking(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_10"))
	{
		return;
	}
}
EXTERN_C_LINKAGE U8 MApp_GetLeap(U16 u16Year );
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_GetLeap(U16 u16Year )
{
	if( CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_TRUE") ||
		CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisMonth_IF")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek_IF"))
		{
		return 1;
		}
	else if( CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_GetDaysOfThisYear_IS_FALSE")||
		CppTest_IsCurrentTestCase("TestSuite_MApp_GlobalFunction_test_MApp_GetDayOfWeek__NOT_LEAPYERA"))
		{
		return 0;
		}
	return 0;
}

EXTERN_C_LINKAGE BOOLEAN msAPI_UART_DecodeCommand(void);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_UART_DecodeCommand(void)
{
    if( CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isDecodeCommand_True") )
    {
        return TRUE;
    }
    else if( CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isDebugProgStopFlag_FALSE") )
    {
        return FALSE;
    }
    else if( CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PowerOn_Stage_Debug_isDebugProgStopFlag_TRUE") )
    {
        return FALSE;
    }
}

/** User stub definition for function: void MApp_PreInit_State11(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State11(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State11(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_11"))
	{
		return;
	}
}
EXTERN_C_LINKAGE S32 msAPI_Timer_GetOffsetTime(void);
EXTERN_C_LINKAGE S32 CppTest_Stub_msAPI_Timer_GetOffsetTime(void)
{
    if( CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime") )
    {
        return 1;
    }

    return 0;
}
EXTERN_C_LINKAGE Bool btest_msAPI_Timer_SetOffsetTime = FALSE;
EXTERN_C_LINKAGE void msAPI_MHEG5_SystemTime_Transmit(U32 u32SystemTime, S32 s32OffsetTime);
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_MHEG5_SystemTime_Transmit(U32 u32SystemTime, S32 s32OffsetTime)
{
    if( CppTest_IsCurrentTestCase("TestSuite_msAPI_Timer_test_msAPI_Timer_SetOffsetTime") )
    {
    	btest_msAPI_Timer_SetOffsetTime = TRUE;
    }
}

/** User stub definition for function: void msIR_WriteByte(U16 u16RegIndex, U8 u8Value) */
EXTERN_C_LINKAGE void msIR_WriteByte(U16 u16RegIndex, U8 u8Value);
EXTERN_C_LINKAGE void CppTest_Stub_msIR_WriteByte(U16 u16RegIndex, U8 u8Value)
{
}

/** User stub definition for function: void msIR_Write2Byte(U16 u16RegIndex, U16 u16Value) */
EXTERN_C_LINKAGE void msIR_Write2Byte(U16 u16RegIndex, U16 u16Value);
EXTERN_C_LINKAGE void CppTest_Stub_msIR_Write2Byte(U16 u16RegIndex, U16 u16Value)
{
}

/** User stub definition for function: void MApp_PreInit_State16_ATVProc_Init(void)*/
EXTERN_C_LINKAGE void MApp_PreInit_State16_ATVProc_Init(void);
EXTERN_C_LINKAGE void CppTest_Stub_MApp_PreInit_State16_ATVProc_Init(void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_Main_test_MApp_PreInit_State_case_EN_PRE_INIT_STAGE_16"))
	{
		return;
	}
}

/** User stub definition for function: VDEC_Result MApi_VDEC_IsStepDispDone(void) */
EXTERN_C_LINKAGE VDEC_Result MApi_VDEC_IsStepDispDone () ;
EXTERN_C_LINKAGE VDEC_Result CppTest_Stub_MApi_VDEC_IsStepDispDone (void)
{
    return E_VDEC_FAIL;
}

EXTERN_C_LINKAGE void mdrv_gpio_set_input(MS_GPIO_NUM gpio);
EXTERN_C_LINKAGE void CppTest_Stub_mdrv_gpio_set_input(MS_GPIO_NUM gpio)
{
}
//void mdrv_gpio_set_output(MS_GPIO_NUM gpio);
EXTERN_C_LINKAGE int mdrv_gpio_get_inout(MS_GPIO_NUM gpio);
EXTERN_C_LINKAGE int CppTest_Stub_mdrv_gpio_get_inout(MS_GPIO_NUM gpio)
{
}
EXTERN_C_LINKAGE int mdrv_gpio_get_level(MS_GPIO_NUM gpio);
EXTERN_C_LINKAGE int CppTest_Stub_mdrv_gpio_get_level(MS_GPIO_NUM gpio)
{
}
EXTERN_C_LINKAGE BOOLEAN MDrv_Power_Set_HwClock (HW_MODULE_CLOCK_SETTING eModule, int eValue);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MDrv_Power_Set_HwClock (HW_MODULE_CLOCK_SETTING eModule, int eValue)
{
	if(CppTest_IsCurrentTestCase("TestSuit_drvPower_test_MDrv_Power_Saving_Mode"))
	{
		return 0 ;
	}
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetFirstFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, BOOLEAN bIncludeSkipped);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetFirstFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, BOOLEAN bIncludeSkipped)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetFirstFavoriteOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return 0xFFFF ;
	}
	else 	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 0xFFFF ;
	}
	else 	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 0xFFFF ;
	}
	else 	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif1"))
	{
		return 0xFFFF ;
	}
	else 	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_elif2"))
	{
		return 0xFFFF ;
	}
	else 	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetNextFavoriteOrdinalOfUnitedTV_else"))
	{
		return 0xFFFF ;
	}
	return 0;
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetLastFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, BOOLEAN bIncludeSkipped);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetLastFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, BOOLEAN bIncludeSkipped)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test_msAPI_CHPROC_CM_GetLastFavoriteOrdinal_E_SERVICETYPE_UNITED_TV"))
	{
		return 0xFFFF ;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_else"))
	{
		return 0xFFFF ;
	}
	return 0;
}

EXTERN_C_LINKAGE WORD _GetNextFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped);
EXTERN_C_LINKAGE WORD CppTest_Stub__GetNextFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
	return 0;
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetNextFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetNextFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped)
{
	return 0;
}

EXTERN_C_LINKAGE WORD _GetPrevFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped);
EXTERN_C_LINKAGE WORD CppTest_Stub__GetPrevFavoriteOrdinalOfUnitedTV(WORD wBaseOrdinal, BOOLEAN bIncludeSkipped)
{
	return 0;
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetPrevFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetPrevFavoriteProgramPosition(MEMBER_SERVICETYPE bServiceType, WORD wBasePosition, BOOLEAN bIncludeSkipped)
{
	if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_ifyes"))
	{
		return 0xFFFF ;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif2"))
	{
		return 0xFFFF ;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_ChProc_test__GetPrevFavoriteOrdinalOfUnitedTV_elif3"))
	{
		return 0xFFFF ;
	}
	return 0;
}

EXTERN_C_LINKAGE BYTE msAPI_ATV_GetPreviousFavoriteProgramNumber(BYTE u8BaseProgramNumber);
EXTERN_C_LINKAGE BYTE CppTest_Stub_msAPI_ATV_GetPreviousFavoriteProgramNumber(BYTE u8BaseProgramNumber)
{
	return 0;
}

EXTERN_C_LINKAGE WORD msAPI_CM_GetLogicalChannelNumber(MEMBER_SERVICETYPE bServiceType, WORD wPosition);
EXTERN_C_LINKAGE WORD CppTest_Stub_msAPI_CM_GetLogicalChannelNumber(MEMBER_SERVICETYPE bServiceType, WORD wPosition)
{
	return 0;
}

EXTERN_C_LINKAGE BYTE msAPI_ATV_ConvertOrdinalNumberToProgramNumber(WORD u16OrdinalNumber);
EXTERN_C_LINKAGE BYTE CppTest_Stub_msAPI_ATV_ConvertOrdinalNumberToProgramNumber(WORD u16OrdinalNumber)
{
	return 0;
}

EXTERN_C_LINKAGE BOOLEAN msAPI_ATV_IsProgramNumberActive(BYTE u8ProgramNumber);
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_ATV_IsProgramNumberActive(BYTE u8ProgramNumber)
{
	return TRUE;
}

/** User stub definition for function: BOOLEAN _MApp_Music_Ac3TimeOffset(U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_Ac3TimeOffset (U32 u32GotoTimeMs) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_Ac3TimeOffset (U32 u32GotoTimeMs)
{
    return TRUE;
}

/** User stub definition for function: EN_AUTOSLEEP_TIME_STATE MApp_AutoSleep_GetCurrentSleepState(void) */
EXTERN_C_LINKAGE EN_AUTOSLEEP_TIME_STATE MApp_AutoSleep_GetCurrentSleepState(void);
EXTERN_C_LINKAGE EN_AUTOSLEEP_TIME_STATE CppTest_Stub_MApp_AutoSleep_GetCurrentSleepState(void)
{
	if(CppTest_IsCurrentTestCase("TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_4HR"))
	{
		return STATE_AUTOSLEEP_4HOUR ;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_6HR"))
	{
		return STATE_AUTOSLEEP_6HOUR ;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_MApp_Sleep_test_MApp_GetAutoSleep_Time_SwitchCase_test_STATE_AUTOSLEEP_8HR"))
	{
		return STATE_AUTOSLEEP_8HOUR ;
	}
	else
		return STATE_AUTOSLEEP_NEVER ;
}

/** User stub definition for function: void MApi_JPEG_ProcessEOF(JPEG_BuffLoadType u8MRBuffType) */
EXTERN_C_LINKAGE void MApi_JPEG_ProcessEOF(JPEG_BuffLoadType u8MRBuffType);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_ProcessEOF(JPEG_BuffLoadType u8MRBuffType)
{
    return ;
}

/** User stub definition for function: void MApi_JPEG_SetErrCode(JPEG_ErrCode ErrStatus) */
EXTERN_C_LINKAGE void MApi_JPEG_SetErrCode(JPEG_ErrCode ErrStatus);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetErrCode(JPEG_ErrCode ErrStatus)
{
    return ;
}

/** User stub definition for function: void MApi_JPEG_SetDbgLevel(MS_U8 u8DbgLevel) */
EXTERN_C_LINKAGE void MApi_JPEG_SetDbgLevel(MS_U8 u8DbgLevel);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_SetDbgLevel(MS_U8 u8DbgLevel)
{
    return ;
}

/** User stub definition for function: void MApi_JPEG_GetInfo(JPEG_Info *pJPEG_Info) */
EXTERN_C_LINKAGE void MApi_JPEG_GetInfo(JPEG_Info *pJPEG_Info);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_GetInfo(JPEG_Info *pJPEG_Info)
{
    return ;
}

/** User stub definition for function: void MApi_JPEG_GetStatus(JPEG_Status *pJPEG_Status) */
EXTERN_C_LINKAGE void MApi_JPEG_GetStatus(JPEG_Status *pJPEG_Status);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_JPEG_GetStatus(JPEG_Status *pJPEG_Status)
{
    return ;
}

/** User stub definition for function: JPEG_DecodeStatus MApi_JPEG_WaitDone(void) */
EXTERN_C_LINKAGE JPEG_DecodeStatus MApi_JPEG_WaitDone(void);
EXTERN_C_LINKAGE JPEG_DecodeStatus CppTest_Stub_MApi_JPEG_WaitDone(void)
{
    return ;
}



/** User stub definition for function: MS_U32 MApi_VDEC_GetPatternLeastLength(VDEC_PatternType) */
EXTERN_C_LINKAGE MS_U32 MApi_VDEC_GetPatternLeastLength (VDEC_PatternType ePatternType) ;
EXTERN_C_LINKAGE MS_U32 CppTest_Stub_MApi_VDEC_GetPatternLeastLength (VDEC_PatternType ePatternType)
{
    return 0UL;
}

/** User stub definition for function: void MApi_DMX_BypassFileInTimeStamp(MS_BOOL) */
EXTERN_C_LINKAGE void MApi_DMX_BypassFileInTimeStamp (MS_BOOL bbypass) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_DMX_BypassFileInTimeStamp (MS_BOOL bbypass)
{
}

/** User stub definition for function: WDT_Result MDrv_WDT_Clear(void) */
EXTERN_C_LINKAGE WDT_Result MDrv_WDT_Clear () ;
EXTERN_C_LINKAGE WDT_Result CppTest_Stub_MDrv_WDT_Clear (void)
{
    return E_WDT_OK;
}
EXTERN_C_LINKAGE void ttf_sbrk_SetMemPoolSize(unsigned long u32Size);
EXTERN_C_LINKAGE void CppTest_Stub_ttf_sbrk_SetMemPoolSize(unsigned long u32Size)
{

}
EXTERN_C_LINKAGE void *ttf_sbrk(unsigned int size);
EXTERN_C_LINKAGE void *CppTest_Stub_ttf_sbrk(unsigned int size)
{

}
EXTERN_C_LINKAGE void MApi_XC_PCMonitor_SetTimingCount(MS_U16 u16TimingStableCounter, MS_U16 u16TimingNosyncCounter);
EXTERN_C_LINKAGE void CppTest_Stub_MApi_XC_PCMonitor_SetTimingCount(MS_U16 u16TimingStableCounter, MS_U16 u16TimingNosyncCounter)
{

}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_IsFBExist(MS_U8) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_IsFBExist (MS_U8 fbId) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_IsFBExist (MS_U8 fbId) 
{
    return (unsigned char)0;
}

/** User stub definition for function: MS_U8 MApi_GOP_GWIN_CreateWin_Assign_FB(MS_U8, MS_U8, MS_U16, MS_U16) */
EXTERN_C_LINKAGE MS_U8 MApi_GOP_GWIN_CreateWin_Assign_FB (MS_U8 u8GOP, MS_U8 FBId, MS_U16 dispX, MS_U16 dispY) ;
EXTERN_C_LINKAGE MS_U8 CppTest_Stub_MApi_GOP_GWIN_CreateWin_Assign_FB (MS_U8 u8GOP, MS_U8 FBId, MS_U16 dispX, MS_U16 dispY) 
{
    return (unsigned char)0;
}
