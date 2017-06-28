//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (MStar Confidential Information) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_PCMODE_C

/********************************************************************************/
/*                            Header Files                                      */
/********************************************************************************/
#include <string.h>
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"

// Common Definition
#include "msAPI_Timer.h"

#include "debug.h"
#include "drvGlobal.h"

#include "apiXC.h"
#include "apiXC_Adc.h"
#include "drvXC_HDMI_if.h"
#include "apiXC_Sys.h"
#include "apiXC_PCMonitor.h"
#include "apiXC_ModeParse.h"
#include "apiXC_Cus.h"
#include "apiXC_Adc.h"
#include "apiXC_Auto.h"
#include "apiXC_Hdmi.h"
#include "MApp_GlobalSettingSt.h"           ///< for ADC setting structure
#if 0//( MS_SW_CUS_SEL == SW_CONFIG_TRUNK_ATSC )
#include "msAPI_MIU.h"
#include "MApp_DataBase_A.h"                ///< for ATSC
#include "MApp_GlobalVar.h"                    ///< for ATSC
#include "MApp_GlobalFunction.h"            ///< for ATSC
#else
#include "MApp_SaveData.h"                  ///< for load mode data
#endif
#include "MApp_PCMode.h"
#include "MApp_MultiTasks.h"                ///< DELAY_FOR_REMOVE_SCREENMUTE
#include "MApp_Scaler.h"                    ///< for MApp_Picture_Setting_SetColor()
#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
//#include "ZUI_exefunc.h"
#include "MApp_AnalogInputs.h"              ///< for MApp_AnalogInputs_Force2MonitorWindows()


//for Audio mute issue
#include "MApp_Audio.h"                     ///< u8HDMIchkflag
#include "MApp_InputSource.h"               ///< switch audio input source
#include "msAPI_audio.h"

//for Audio mute issue
#include "MApp_GlobalFunction.h"
#include "apiXC_Hdmi.h"
#if ENABLE_MFC_6M20
#include "drvUrsaMFCAPI.h"
#endif
#if ENABLE_MFC_6M30
#include "drvUrsa6M30.h"
#endif
#if(ENABLE_6M40_4KX2K_PROCESS)
#include "drvUrsa6M40.h"
#endif

#if(ENABLE_PIP)
#include "MApp_PIP.h"
#endif

#include "MApp_UI_EventHandler.h"
#if(TVE_NoSignalFunctionType==TVE_NoSignalToPollingSource)
#include "MApp_ZUI_ACTinputsource.h"
#endif
#if(sPowerDown_Function==sSimple_PowerDownFun)
#include "MApp_Standby.h"
#include "MApp_Sleep.h"
#endif
#if 0//( ((FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF)||(FRONTEND_IF_DEMODE_TYPE == MSTAR_INTERN_VIF)) )
    extern BOOLEAN gbTVAutoScanChannelEnable;
    extern void MDrv_VIF_Handler(BOOLEAN bAutoScan);
#endif

//#include "MApp_UiMenuFunc_ATSC.h" 	     //Ray DMP 2017.04.07
#include "MApp_TopStateMachine.h"   	     //Ray DMP 2017.04.07
#include "drvUSB.h" 			    //Ray DMP 2017.04.07: Add to access USB for fail over
#include "drvGlobal.h"		//Ray DMP 2017.04.07
#include "mapp_mplayer.h"	//Ray DMP 2017.04.07
//#include "msAPI_MSDCtrl.h"	//Ray DMP 2017.04.07
#include "MApp_DMP_Main.h"	//Ray DMP 2017.04.07

/********************************************************************************/
/*                               Macro                                          */
/********************************************************************************/

#define GENSET_ADC    G_ADC_SETTING

#define DEBUG_HDMI_FLOW(x)  //x
#define PCMSG(x)            //x
#define PC_SelfAuto_MSG(x)  //x
#define HDMI_4KX2K_MSG(x)   //x

// Range of RGB OOR
#if ENABLE_VGA_EIA_TIMING
#define MIN_HFREQ_OF_RGB            140  // 150
#else
#define MIN_HFREQ_OF_RGB            270    // 150
#endif
#define MAX_HFREQ_OF_RGB            950//840

#if ENABLE_VGA_EIA_TIMING
#define MIN_VFREQ_OF_RGB            240
#else
#define MIN_VFREQ_OF_RGB            470
#endif

#if ENABLE_RGB_SUPPORT_85HZ
#define MAX_VFREQ_OF_RGB            870
#else
#define MAX_VFREQ_OF_RGB            770
#endif

#define MIN_VTOTAL_OF_RGB           415
#define MAX_VTOTAL_OF_RGB           1550 // 1250
// Range of DVI OOR
#define MIN_HFREQ_OF_DVI            140    // same with HDMI
#if(ENABLE_HDMI_4K_2K)
#define MAX_HFREQ_OF_DVI            1400
#else
#define MAX_HFREQ_OF_DVI            950//840    // same with RGB
#endif
#define MIN_VFREQ_OF_DVI            230    // same with HDMI
#define MAX_VFREQ_OF_DVI            770    // same with RGB
#define MIN_VTOTAL_OF_DVI           250    // same with HDMI
#define MAX_WIDTH_OF_DVI            4096//3860   // 1930 ENABLE_HDMI_4K_2K --> 3860
#if (ENABLE_3D_PROCESS||ENABLE_HDMI_4K_2K)          //for mode like 1280x1470(720x2+30), 1920x2205(1080x2+45)
#define MAX_VTOTAL_OF_DVI           2300//1250// same with HDMI
#define MAX_HEIGHT_OF_DVI           2800
#else
#define MAX_VTOTAL_OF_DVI           1300//1250// same with HDMI
#define MAX_HEIGHT_OF_DVI           1210
#endif

// Range of YPbPr OOR
#define MIN_HFREQ_OF_YPBPR          140
#define MIN_VFREQ_OF_YPBPR          230
#if ENABLE_3D_PROCESS          //for mode like 1280x1470(720x2+30), 1920x2205(1080x2+45)
#define MAX_HFREQ_OF_YPBPR          950
#define MIN_VTOTAL_OF_YPBPR         200
#define MAX_VTOTAL_OF_YPBPR         2300
#define MAX_VFREQ_OF_YPBPR          2700 //620 change for support 75Hz
#else
#define MAX_HFREQ_OF_YPBPR          700
#define MIN_VTOTAL_OF_YPBPR         250
#define MAX_VTOTAL_OF_YPBPR         1300
#define MAX_VFREQ_OF_YPBPR          770 //620 change for support 75Hz
#endif

#define HRESOLUTION_TOLERANCE 1

/********************************************************************************/
/*                               Local Defines                                 */
/********************************************************************************/

// #0718715 : [HDMI] When changing source to HDMI, blurred screen sometimes.
// Option to resolved specified HDMI player when fast switch from TV to HDMI, screen will display garbage fortuitously.
// When option enable, switch time to HDMI source will extend a while time.
#define ENABLE_WAIT_HDCP_READY          DISABLE

/********************************************************************************/
/*                               Enum                                           */
/********************************************************************************/

/********************************************************************************/
/*                                 Local                                        */
/********************************************************************************/
typedef struct
{
    PCMODE_SyncStatus eCurrentState;  ///< timing monitor state
    // Mode parse result
    XC_MODEPARSE_RESULT eModeParseResult;           ///< the result after mode parse
    XC_MODEPARSE_INPUT_INFO sModeParseInputInfo;    ///< prepare the input info for mode parse
} PCMode_Info;

void _MApp_PCMode_SetHdmiAvgMode(BOOLEAN bEnable);
//#define PC_POLLING_COUNTER          50  // (30/TIMER_PERIOD), unit ms
#if(TVE_NoSignalFunctionType==TVE_NoSignalToPollingSource)
static U8 sPollingCheckC = 0;
#endif
BOOLEAN ucUSBNoMediaFile = 0;		//Ray DMP 2017.04.07: 1 = USB doesn't have media file
static U8 USBConnectCheckF = 0;		//Ray DMP 2017.04.07: no. of time to check if USB is connected

/********************************************************************************/
/*                               Functions                                      */
/********************************************************************************/


/********************************************************************************/
/*                               Local Variables                                */
/********************************************************************************/
static PCMode_Info PCMODE_INFO[2] ;

static U8 Enable_SelfAuto[MAX_WINDOW] = {DISABLE, DISABLE};
static BOOLEAN s_bIsHdmiAvgMode = FALSE;

static BYTE ucFirstNoSignalSource=UI_INPUT_SOURCE_NONE;		//Ray DMP 2017.04.07: ucFirstNoSignalSource to denote the input source which has no signal first

//Ray DMP 2017.04.07: To set ucFirstNoSignalSource by external function
void MApp_PCMode_SetFirstNoSignalSource(E_UI_INPUT_SOURCE eUiInputSource)
{
  ucFirstNoSignalSource = eUiInputSource;
}

void msApiPrintfHDMI_STATUSMode(E_XC_HDMI_Status eE_XC_HDMI_Status)
{
    switch (eE_XC_HDMI_Status)
    {
        default:
        case E_HDMI_STATUS_UNKNOWN:
            MS_DEBUG_MSG(printf("\r\n Unknown Mode"));
            break;

        case E_HDMI_STATUS_DVI:
            //MS_DEBUG_MSG(printf("\r\n DVI Mode"));
            printf(" DVI Mode\n");
            break;

        case E_HDMI_STATUS_HDMI:
            MS_DEBUG_MSG(printf("\r\n HDMI Mode"));
            printf(" HDMI Mode\n");
            break;
    }
}

BOOLEAN MApp_PCMode_IsAspectRatioWide(INPUT_SOURCE_TYPE_t enInputSourceType)
{
     if(IsSrcTypeHDMI(enInputSourceType))
     {
        MS_HDMI_AR_TYPE enHdmiArType = HDMI_AR_INIT_VALUE;
        MS_HDMI_AR_TYPE enActiveFormatAR = HDMI_Pic_AR_NODATA;
        MS_HDMI_AR_TYPE enPictureAR = HDMI_Pic_AR_NODATA;
        enHdmiArType = (MS_HDMI_AR_TYPE)g_HdmiPacketInfo.enPKT_Status.AspectRatio;
        enPictureAR = (MS_HDMI_AR_TYPE) HINIBBLE(enHdmiArType);
        enActiveFormatAR = (MS_HDMI_AR_TYPE) LONIBBLE(enHdmiArType);
        if( enPictureAR == HINIBBLE(HDMI_Pic_AR_16x9) )
        {
            return TRUE;
        }
        else if( enPictureAR == HINIBBLE(HDMI_Pic_AR_4x3) )
        {
            return FALSE;
        }
        else
        {
        //720*480 must be 4:3
        if (((U32)MApp_PCMode_Get_HResolution(MAIN_WINDOW , FALSE)*2) >
            ((U32)MApp_PCMode_Get_VResolution(MAIN_WINDOW,FALSE)*3))
            return TRUE;
        else
            return FALSE;
            //return TRUE;
        }
     }
     else
     {
        //720*480 must be 4:3
        if (((U32)MApp_PCMode_Get_HResolution(MAIN_WINDOW, TRUE)*2) >
            ((U32)MApp_PCMode_Get_VResolution(MAIN_WINDOW, TRUE)*3))
            return TRUE;
        else
            return FALSE;
     }
}


//*************************************************************************
//Function name:     MApp_YPbPr_Setting_Auto
//Passing parameter: none
//Return parameter:  none
//Description:       Auto adjust video for YPbpr mode
//*************************************************************************
BOOLEAN MApp_YPbPr_Setting_Auto (XC_Auto_CalibrationType type,SCALER_WIN eWindow)
{
    MS_BOOL bResult = FALSE;
    XC_Auto_CalibrationType calibration_type = type;
    E_ADC_SET_INDEX eAdcSetIdx, eAdcSetIdxToCopy;

    MS_DEBUG_MSG(printf(" Rgain %x \n", GENSET_ADC[ADC_SET_YPBPR_SD].stAdcGainOffsetSetting.u16RedGain ));
    MS_DEBUG_MSG(printf(" ggain %x \n", GENSET_ADC[ADC_SET_YPBPR_SD].stAdcGainOffsetSetting.u16GreenGain ));
    MS_DEBUG_MSG(printf(" bgain %x \n", GENSET_ADC[ADC_SET_YPBPR_SD].stAdcGainOffsetSetting.u16BlueGain ));

    MApi_XC_Auto_SetCalibrationMode(E_XC_SW_CALIBRATION);

    if((type == E_XC_EXTERNAL_CALIBRATION) && (MApp_IsSrcHasSignal(eWindow) != TRUE))
    {
        // external calibration without input signal
        calibration_type = E_XC_INTERNAL_CALIBRATION;
    }

    if (calibration_type == E_XC_EXTERNAL_CALIBRATION )
    {
        // seperate SD/HD setting
        if(MApi_XC_Sys_IsSrcHD(eWindow))
        {
            eAdcSetIdx = ADC_SET_YPBPR_HD;              // calibration HD resolution
        }
        else
        {
            eAdcSetIdx = ADC_SET_YPBPR_SD;
        }
    }
    else // Internal calibration
    {
        eAdcSetIdx = ADC_SET_YPBPR_SD;
        eAdcSetIdxToCopy = ADC_SET_YPBPR_HD;        // if internal calibration, copy SD setting to HD
    }

    bResult = MApi_XC_Auto_GainOffset(calibration_type, E_XC_AUTO_TUNE_YUV_COLOR,
        &GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting, eWindow);

    // do auto calibration

    GENSET_ADC[ADC_SET_YPBPR_SD].u8AdcCalOK = 0x00;
    GENSET_ADC[ADC_SET_YPBPR_HD].u8AdcCalOK = 0x00;

    if(bResult)
    {
        // auto gain/offset calibration successed
        GENSET_ADC[eAdcSetIdx].u8AdcCalOK = 0xAA;
        GENSET_ADC[eAdcSetIdx].u8CalibrationMode = E_XC_SW_CALIBRATION;
    }
    else
    {
        GENSET_ADC[eAdcSetIdx].u8AdcCalOK = 0x00;
    }

    MS_DEBUG_MSG(printf("u16RedGain %x \n",GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting.u16RedGain));
    MS_DEBUG_MSG(printf("u16GreenGain %x \n",GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting.u16GreenGain));
    MS_DEBUG_MSG(printf("u16BlueGain %x \n",GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting.u16BlueGain));
    MS_DEBUG_MSG(printf("u16RedOffset %x \n",GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting.u16RedOffset));
    MS_DEBUG_MSG(printf("u16GreenOffset %x \n",GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting.u16GreenOffset));
    MS_DEBUG_MSG(printf("u16BlueOffset %x \n",GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting.u16BlueOffset));

    MApp_SaveData_ADC_SaveSetting(eAdcSetIdx);

    if(calibration_type == E_XC_INTERNAL_CALIBRATION)
    {
        memcpy(&GENSET_ADC[eAdcSetIdxToCopy].stAdcGainOffsetSetting,
               &GENSET_ADC[eAdcSetIdx].stAdcGainOffsetSetting,
               sizeof(APIXC_AdcGainOffsetSetting));

        GENSET_ADC[eAdcSetIdxToCopy].u8AdcCalOK = GENSET_ADC[eAdcSetIdx].u8AdcCalOK;
        MApp_SaveData_ADC_SaveSetting(eAdcSetIdxToCopy);
    }

    return bResult;
}

BOOLEAN MApp_RGB_Setting_Auto(XC_Auto_CalibrationType type,SCALER_WIN eWindow)
{
    MS_BOOL bResult = FALSE;
    XC_Auto_CalibrationType calibration_type = type;

    MApi_XC_Auto_SetCalibrationMode(E_XC_SW_CALIBRATION);

    if((type == E_XC_EXTERNAL_CALIBRATION) && (MApp_IsSrcHasSignal(eWindow) != TRUE))
    {
        // external calibration without input signal
        calibration_type = E_XC_INTERNAL_CALIBRATION;
    }

    bResult =  MApi_XC_Auto_GainOffset(calibration_type, E_XC_AUTO_TUNE_RGB_COLOR,
        &GENSET_ADC[ADC_SET_VGA].stAdcGainOffsetSetting,eWindow);

    // do auto calibration
    if(bResult)
    {
        // auto gain/offset calibration successed
        GENSET_ADC[ADC_SET_VGA].u8AdcCalOK = 0xAA;
        GENSET_ADC[ADC_SET_VGA].u8CalibrationMode = E_XC_SW_CALIBRATION;
    }
    else
    {
        GENSET_ADC[ADC_SET_VGA].u8AdcCalOK = 0x00;
    }


    MApp_SaveData_ADC_SaveSetting(ADC_SET_VGA);

    return bResult;
}

BOOLEAN MApp_SCART_RGB_Setting_Auto (XC_Auto_CalibrationType type,SCALER_WIN eWindow)
{
    BOOLEAN bResult = FALSE;

    MApi_XC_Auto_SetCalibrationMode(E_XC_SW_CALIBRATION);

    if(MApp_IsSrcHasSignal(eWindow))
    {
        if (MApi_XC_Auto_GainOffset( type, E_XC_AUTO_TUNE_YUV_COLOR,
            &GENSET_ADC[ADC_SET_SCART_RGB].stAdcGainOffsetSetting, eWindow) ) // auto-tune
        {
            GENSET_ADC[ADC_SET_SCART_RGB].u8AdcCalOK = 0xAA;
            bResult = TRUE;
            GENSET_ADC[ADC_SET_SCART_RGB].u8CalibrationMode = E_XC_SW_CALIBRATION;
            PCMSG(printf("E_XC_AUTO_TUNE_RGB_COLOR OK \n" ));
        }
        else
        {
            GENSET_ADC[ADC_SET_SCART_RGB].u8AdcCalOK = 0x00;
            bResult = FALSE;
            PCMSG(printf("E_XC_AUTO_TUNE_RGB_COLOR FAIL \n" ));
        }
        MApp_SaveData_ADC_SaveSetting(ADC_SET_SCART_RGB);
    }
    else
    {
        bResult = FALSE;
    }

    return bResult;
}

//MS_U16 MDrv_XC_ADC_GetPcClock(void);
///
static void _MApp_PCMode_SelfAuto(SCALER_WIN eWindow)
{
    XC_Auto_Signal_Info_Ex active;
    XC_Auto_Signal_Info_Ex standard;
    MS_PCADC_MODETABLE_TYPE_EX sModeTbl;


    PC_SelfAuto_MSG(printf("\n MApp_PCMode_SelfAuto \n"); );

    if(MApp_IsSrcHasSignal(eWindow))
    {
        if( ( SYS_INPUT_SOURCE_TYPE(eWindow) == INPUT_SOURCE_VGA )
          &&(g_PcadcModeSetting[eWindow].u8AutoSign == 0)
          )
        {
            PC_SelfAuto_MSG(printf("Cur HFreq = %d\n", MApi_XC_PCMonitor_Get_HFreqx10(eWindow)); );
            PC_SelfAuto_MSG(printf("Cur VFreq = %d\n", MApi_XC_PCMonitor_Get_VFreqx10(eWindow)); );
            PC_SelfAuto_MSG(printf("Cur VTotal = %d\n", MApi_XC_PCMonitor_Get_Vtotal(eWindow)); );
            PC_SelfAuto_MSG(printf("Cur u8SyncStatus = 0x%X\n", MApi_XC_PCMonitor_GetSyncStatus(eWindow)); );

            // Current signal info
            active.u16HorizontalStart = g_PcadcModeSetting[eWindow].u16HorizontalStart;
            active.u16VerticalStart   = g_PcadcModeSetting[eWindow].u16VerticalStart;
            active.u16HorizontalTotal = g_PcadcModeSetting[eWindow].u16HorizontalTotal;
            active.u16Phase = g_PcadcModeSetting[eWindow].u16Phase;
            active.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;

            // Get std info from mode table
            MApi_XC_ModeParse_GetModeTbl(g_PcadcModeSetting[eWindow].u8ModeIndex, &sModeTbl);
            standard.u16HorizontalStart = sModeTbl.u16HorizontalStart;
            standard.u16VerticalStart = sModeTbl.u16VerticalStart;
            standard.u16HorizontalTotal = sModeTbl.u16HorizontalTotal;
            standard.u16HResolution = MApp_PCMode_Get_HResolution(eWindow,TRUE);
            standard.u16Phase = sModeTbl.u16AdcPhase;
            standard.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;

            PC_SelfAuto_MSG(printf("Std u8ModeIndex = %u\n",g_PcadcModeSetting[eWindow].u8ModeIndex););
            PC_SelfAuto_MSG(printf("Std HStart = %d\n",standard.u16HorizontalStart););
            PC_SelfAuto_MSG(printf("Std VStart = %d\n",standard.u16VerticalStart););
            PC_SelfAuto_MSG(printf("Std Htotal = %d\n",standard.u16HorizontalTotal););
            PC_SelfAuto_MSG(printf("Std HResolution = %d\n",standard.u16HResolution););
            PC_SelfAuto_MSG(printf("Std Phase = %d\n",standard.u16Phase););
            PC_SelfAuto_MSG(printf("Std u16Version = %d\n",standard.u16Version););


            //ZUI: MApp_UiMenu_Show_Warning_Message_Dialog(MENU_AUTO_ADJUSTING_MSG);
            PC_SelfAuto_MSG(printf("Start Geometry ...\n"));

            //PC_SelfAuto_MSG(printf("MDrv_XC_ADC_GetPcClock() = %u\n", MDrv_XC_ADC_GetPcClock()); );

            // Geometry will update current active signal.
            if (MApi_XC_Auto_Geometry_Ex(E_XC_AUTO_TUNE_BASIC, &active, &standard, eWindow)) // auto-tune
            {
                // update default H/V start after E_XC_AUTO_TUNE_POSITION ( Do we need these two statements?)
                g_PcadcModeSetting[eWindow].u16DefaultHStart = active.u16HorizontalStart;
                g_PcadcModeSetting[eWindow].u16DefaultVStart = active.u16VerticalStart;
                g_PcadcModeSetting[eWindow].u16DefaultHTotal = active.u16HorizontalTotal;
                g_PcadcModeSetting[eWindow].u16HorizontalStart = active.u16HorizontalStart;
                g_PcadcModeSetting[eWindow].u16VerticalStart = active.u16VerticalStart;
                g_PcadcModeSetting[eWindow].u16HorizontalTotal = active.u16HorizontalTotal;
                g_PcadcModeSetting[eWindow].u16Phase = active.u16Phase;

                g_PcadcModeSetting[eWindow].u8AutoSign = TRUE;   // Auto config OK
                MApp_PCMode_SaveModeRamSetting(eWindow);

                PC_SelfAuto_MSG(printf("\n ==> AutoTune OK \r\n"));
            }
            else
            {
                g_PcadcModeSetting[eWindow].u8AutoSign = FALSE;  // Auto config NG restore to stanrd mode

                g_PcadcModeSetting[eWindow].u16DefaultHStart = standard.u16HorizontalStart;
                g_PcadcModeSetting[eWindow].u16DefaultVStart = standard.u16VerticalStart;
                g_PcadcModeSetting[eWindow].u16DefaultHTotal = standard.u16HorizontalTotal;
                g_PcadcModeSetting[eWindow].u16HorizontalStart = standard.u16HorizontalStart;
                g_PcadcModeSetting[eWindow].u16VerticalStart = standard.u16VerticalStart;
                g_PcadcModeSetting[eWindow].u16HorizontalTotal = standard.u16HorizontalTotal;
                g_PcadcModeSetting[eWindow].u16Phase = standard.u16Phase;

                //Mode change During AutoConfiguration
                MApp_PCMode_SaveModeRamSetting(eWindow);
                printf("\nWarning: AutoTune FAIL load default value!\n");

                PC_SelfAuto_MSG(printf("Std HStart = %d\n",standard.u16HorizontalStart););
                PC_SelfAuto_MSG(printf("Std VStart = %d\n",standard.u16VerticalStart););
                PC_SelfAuto_MSG(printf("Std Htotal = %d\n",standard.u16HorizontalTotal););
                PC_SelfAuto_MSG(printf("Std HResolution = %d\n",standard.u16HResolution););
                PC_SelfAuto_MSG(printf("Std Phase = %d\n",standard.u16Phase););
                PC_SelfAuto_MSG(printf("Std u16Version = %d\n",standard.u16Version););


                PC_SelfAuto_MSG( printf("ValidDataThr=%u\n", MDrv_ReadByte(0x130121)>>4); );
                PC_SelfAuto_MSG( printf("HW: V Start = %u\n", MDrv_ReadByte(0x130124)); );
                PC_SelfAuto_MSG( printf("HW: V End = %u\n", MDrv_ReadByte(0x130128)); );
                PC_SelfAuto_MSG( printf("HW: H Start = %u\n", MDrv_ReadByte(0x130126)); );
                PC_SelfAuto_MSG( printf("HW: H End = %u\n", MDrv_ReadByte(0x13012A)); );
            }

            PC_SelfAuto_MSG(printf("Mode Index = %u \r\n",g_PcadcModeSetting[eWindow].u8ModeIndex));
            PC_SelfAuto_MSG(printf("Mode HStart = %d \r\n",g_PcadcModeSetting[eWindow].u16HorizontalStart));
            PC_SelfAuto_MSG(printf("Mode VStart = %d \r\n",g_PcadcModeSetting[eWindow].u16VerticalStart));
            PC_SelfAuto_MSG(printf("Mode Htotal = %d \r\n",g_PcadcModeSetting[eWindow].u16HorizontalTotal));
            PC_SelfAuto_MSG(printf("Mode Phase =  %d \r\n",g_PcadcModeSetting[eWindow].u16Phase));
            PC_SelfAuto_MSG(printf("Mode H Size = %d \r\n",MApp_PCMode_Get_HResolution(eWindow,TRUE)));
            PC_SelfAuto_MSG(printf("Mode V Size = %d \r\n",MApp_PCMode_Get_VResolution(eWindow,TRUE)));
            PC_SelfAuto_MSG(printf("Mode u8AutoSign = %bu \r\n",g_PcadcModeSetting[eWindow].u8AutoSign));
        }
    }
    else
    {
        PC_SelfAuto_MSG(printf("[PC]no signal \r\n"));
    }
}

void MApp_PCMode_RunSelfAuto(SCALER_WIN eWindow)
{
    if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(eWindow))&&(Enable_SelfAuto[eWindow] == ENABLE))
    {
        U8 u8DBModeIndex;

        Enable_SelfAuto[eWindow] = DISABLE;
        g_PcadcModeSetting[eWindow].u8AutoSign = 0;
        _MApp_PCMode_SelfAuto(eWindow);

        if(g_u8PcUserModeRamIndex[eWindow] == 0xFF)
            u8DBModeIndex = g_PcadcModeSetting[eWindow].u8ModeIndex; //standard
        else
            u8DBModeIndex = g_u8PcUserModeRamIndex[eWindow]; //user

        PC_SelfAuto_MSG( printf("u8DBModeIndex = %u\n", u8DBModeIndex); );

        MApp_DB_SaveModeSetting(eWindow, u8DBModeIndex);
    }
}

//*************************************************************************
//------------------------------ Warning ----------------------------------
//Attention: !!!!!!------ Don't add UI variable or unneeded code in this file
//
//           Don't modify this procedure !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//*************************************************************************


//*************************************************************************
//------------------------------ Warning ----------------------------------
//Attention: !!!!!!------ Don't add UI variable or unneeded code in this file
//
//           Don't modify this procedure !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//*************************************************************************

static void _MApp_PCMode_Verify_ModeTable_Valid(SCALER_WIN eWindow, U8 u8ModeIndex)
{
    if( (g_PcadcModeSetting[eWindow].u8ModeIndex != u8ModeIndex) ||
        (g_PcadcModeSetting[eWindow].u16HorizontalTotal < MApp_PCMode_Get_HResolution(eWindow,TRUE)) ||
        (g_PcadcModeSetting[eWindow].u16HorizontalStart > MAX_PC_H_START(eWindow) || g_PcadcModeSetting[eWindow].u16HorizontalStart < MIN_PC_H_START(eWindow)) ||
        (g_PcadcModeSetting[eWindow].u16VerticalStart> MAX_PC_V_START(eWindow) || g_PcadcModeSetting[eWindow].u16VerticalStart < MIN_PC_V_START))
        //(g_PcadcModeSetting.u16HorizontalTotal-MApp_PCMode_Get_HResolution(MAIN_WINDOW) < g_PcadcModeSetting.u16HorizontalStart) )
    {
        MApp_DB_LoadDefaultTable(eWindow, u8ModeIndex);
    }
}

static U8 _MApp_PCMode_CheckModeRamAddr(SCALER_WIN eWindow, U8 u8ModeIndex)
{
    U8 u8Index; // loop index

    // seek new mode that once have
    for (u8Index=0; u8Index!=stGenSetting.g_SysSetting.NextNewRamIndex; u8Index++)
    {
        MApp_DB_LoadModeSetting( eWindow, u8Index + MApi_XC_GetTotalModeCount() );
        if (u8ModeIndex == g_PcadcModeSetting[eWindow].u8ModeIndex)
            return (MApi_XC_GetTotalModeCount() + u8Index);
    } // for

    // move [mode RAM] to [new mode RAM]
    MApp_DB_LoadDefaultTable(eWindow, u8ModeIndex);
    MApp_DB_SaveModeSetting(eWindow, MApi_XC_GetTotalModeCount()+stGenSetting.g_SysSetting.NextNewRamIndex);

    // next new mode index
    u8Index = stGenSetting.g_SysSetting.NextNewRamIndex;
    stGenSetting.g_SysSetting.NextNewRamIndex =
    (stGenSetting.g_SysSetting.NextNewRamIndex + 1) % MAX_USER_MODE_NUM;


    return (MApi_XC_GetTotalModeCount() + u8Index);
}

//*************************************************************************
//------------------------------ Warning ----------------------------------
//Attention: !!!!!!------ Don't add UI variable or unneeded code in this file
//
//           Don't modify this procedure !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//*************************************************************************
//*************************************************************************
//Function name:    MApp_PCMode_SetMode
//Passing parameter:    none
//Return parameter:     U8: mode set success or not
//Description:  This function will set registers needed when mode change
//*************************************************************************
static BOOLEAN _MApp_PCMode_SetMode (SCALER_WIN eWindow)
{
    MS_U8 u8_ADC_Idx;
    BOOL  bDisplay = 1;
#if 0//(ENABLE_HDMI_4K_2K)
  #if(SUPPORT_4K_TO_2K_CONVERT)
    XC_SETWIN_INFO stSetWinInfo;
  #endif
#endif

    //printf(">> _MApp_PCMode_SetMode \r\n");
#if (ENABLE_WAIT_HDCP_READY)
    MS_U8 i = 0;
    for( i = 0 ; i < 10 ; i++ )
#endif
    {
        MApi_XC_HDMI_CheckModeChanged(TRUE, eWindow);
        #if (ENABLE_WAIT_HDCP_READY)
        msAPI_Timer_Delayms(1);
        #endif
    }

#if (ENABLE_WAIT_HDCP_READY)
    if (IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(eWindow)))
#endif
    {
        if (MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(eWindow)) == E_HDMI_STATUS_DVI)
        {
            //reset HDMI status
            MApi_XC_WriteByteMask(0x10270D, 0 , BIT(2)|BIT(3));
            MDrv_HDMI_pkt_reset(REST_HDMI_STATUS);

        #if (ENABLE_WAIT_HDCP_READY)
            for( i = 0 ; i < 100 ; i++ )
            {
                MApi_XC_WriteByteMask(0x10270D, 0 , BIT(2)|BIT(3));
                MDrv_HDMI_pkt_reset(REST_HDMI_STATUS);
                MApi_XC_HDMI_CheckModeChanged(TRUE, eWindow);

                if(MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(eWindow)) == E_HDMI_STATUS_HDMI)
                {
                    break;
                }
                msAPI_Timer_Delayms(10);
            }
        #endif

        }
        else
        {
        //HDMI_06[10]reg_vmuteblank: "Blanking when AV mute is active.0: Disable.1: Enable."
        //HDMI_06[11]reg_en_avmute: "Enable video mute.0: Disable.1: Enable when AVMUTE signal is received."

            MApi_XC_WriteByteMask(0x10270D, BIT(2)|BIT(3) , BIT(2)|BIT(3));
        }
    }

    if (IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(eWindow)))
    {
        MApi_XC_HDMI_CheckPacketInfo();
        DEBUG_HDMI_COLOR( printf("Pkt.Color=%u(%s)\n", g_HdmiPacketInfo.enPKT_Status.PacketColorFormat, MApi_HDMI_Get_ColorFormatString(g_HdmiPacketInfo.enPKT_Status.PacketColorFormat)); );
        DEBUG_HDMI_COLOR( printf("Pol.olor=%u(%s)\n", g_HdmiPollingStatus.u8ColorFormat, MApi_HDMI_Get_ColorFormatString(g_HdmiPollingStatus.u8ColorFormat)); );

        if( g_HdmiPacketInfo.enPKT_Status.PacketColorFormat == MS_HDMI_COLOR_UNKNOWN )
        {
            g_HdmiPollingStatus.u8ColorFormat = MS_HDMI_COLOR_DEFAULT;//MS_HDMI_COLOR_RGB;
            printf("Unknown HDMI color format => Use Default=%u!\n", g_HdmiPollingStatus.u8ColorFormat);
        }
        else
        {
            g_HdmiPollingStatus.u8ColorFormat = g_HdmiPacketInfo.enPKT_Status.PacketColorFormat;
        }

    #if (ENABLE_HDMI_4K_2K)
       if(MDrv_HDMI_Check4K2K())
        {
            HDMI_4KX2K_MSG(printf("->>>>>>>>>4KX2K Timing>>>>>>>>>>>>\n"));
            g_HdmiInput4Kx2KFormat=TRUE;
        }

      #if(SUPPORT_4K_TO_2K_CONVERT)
        if(MDrv_HDMI_Check4K2K())
        {
            //Some IP counter bit not enough, need to scaling down in HDMI RX first.
            //Thus, when HDMI 3840x2160 input, Scaler input is 1920x2160
            //MDrv_HDMI_AVG_ScaleringDown(TRUE);
            if(g_HdmiPollingStatus.u8ColorFormat == MS_HDMI_COLOR_YUV_422)
            {
                MDrv_HDMI_Switch_YUV422to444(TRUE);
            }
            else
            {
                MDrv_HDMI_Switch_YUV422to444(FALSE);
            }

            //printf("MDrv_HDMI_AVG_ScaleringDown(1)\n");
            MDrv_HDMI_AVG_ScaleringDown(TRUE);
        }
        else
        {
            MDrv_HDMI_Switch_YUV422to444(FALSE);
            //printf("MDrv_HDMI_AVG_ScaleringDown(0)\n");
            MDrv_HDMI_AVG_ScaleringDown(FALSE);
        }
      #endif // #if(SUPPORT_4K_TO_2K_CONVERT)
    #endif // #if (ENABLE_HDMI_4K_2K)

    #if ENABLE_3D_PROCESS

      #if 0
        if(MApp_PCMode_Get_VResolution(eWindow,FALSE) >= 1400)
        {
            printf("3D: framepacking is detected[Vsize=%d]\n", MApp_PCMode_Get_VResolution(eWindow,FALSE));
            g_HdmiInput3DFormatStatus = E_XC_3D_INPUT_FRAME_PACKING;
        }
       #endif

        //Test with Samsung BD-C6900(1080P 3D Only!),sometimes package can not meet timing change.
        if(g_HdmiInput3DFormatStatus == E_XC_3D_INPUT_FRAME_PACKING)
        {
             printf("->>>>>>>>>>FramePacking Timing>>>>>>>>>>>>\n");
            //MD_1280X1470_50P, //59
            //MD_1280X1470_60P, //60
            //MD_1920X2205_24P, //61
            //if(MApp_PCMode_Get_VResolution(eWindow,FALSE) < 1400)
            //fixed mantis 0329389,for 720_1005_60P and 720_1201_50P
            if(MApp_PCMode_Get_VResolution(eWindow,FALSE) < 1000)
            {
                printf("<<Correct_VResolution[%d]>>\n", MApp_PCMode_Get_VResolution(eWindow,FALSE));
                g_HdmiInput3DFormatStatus = E_XC_3D_INPUT_MODE_NONE;
            }
        }

        //g_HdmiInput3DFormatStatus = E_XC_3D_INPUT_FRAME_PACKING;
        if((eWindow == MAIN_WINDOW)&&(g_HdmiInput3DFormatStatus != E_XC_3D_INPUT_MODE_NONE))
        {
            g_HdmiInput3DFormat = g_HdmiInput3DFormatStatus;

      #if 0
        #if(ENABLE_NEW_3D_FLOW)
            MApp_Scaler_Set_3DMode( g_HdmiInput3DFormatStatus );
        #else
            MApp_Scaler_Set_3DMode(MAPP_Scaler_Map3DFormatTo3DUserMode(g_HdmiInput3DFormatStatus));
        #endif

        #if (ENABLE_MFC_6M20 || ENABLE_MFC_6M30)
            MAPP_Scaler_Map3DFormatToUrsa3DMode(g_HdmiInput3DFormatStatus);
            /*
            if(MApi_XC_Get_3D_Output_Mode() == E_XC_3D_OUTPUT_LINE_ALTERNATIVE)
            {
                MDrv_Ursa_6M30_3D_MODE(PANEL_3D_MODE_LINE_INTERLEAVED_2X,FALSE);
            }
            else if(MApi_XC_Get_3D_Output_Mode() == E_XC_3D_OUTPUT_FRAME_ALTERNATIVE)
            {
                MDrv_Ursa_6M30_3D_MODE(PANEL_3D_MODE_FRAME_INTERLEAVE_25X,FALSE);
            }
                */
        #endif
    #endif
        }

#endif
    }

    if ( (IsSrcTypeHDMI(SYS_INPUT_SOURCE_TYPE(eWindow))) &&
          (MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(eWindow)) == E_HDMI_STATUS_HDMI) )
    {
    /*
        if (MApi_XC_HDMI_GetPacketInfo()->enPKT_Value.PKT_GC_VALUE)
        {
            if (MApi_XC_HDMI_GetPacketInfo()->enPKT_Status.AVMuteStatus)
            {
                bDisplay = 0;
                g_HdmiPollingStatus.bMuteHDMIVideo = 1;
            }
            else
            {
                bDisplay = 1;
                g_HdmiPollingStatus.bMuteHDMIVideo = 0;
            }
        }
    */
    //   if (MApi_XC_HDMI_GetPacketInfo()->enPKT_Status.ChecksumErrOrBCHParityErr)
       if(!MApi_XC_HDMI_CheckSumAndBCH(SYS_INPUT_SOURCE_TYPE(eWindow)))
        {
            bDisplay = 0;
           // g_HdmiPollingStatus.bMuteHDMIVideo = 1;
        }
    }

    if (MApi_XC_PCMonitor_InvalidTimingDetect(TRUE, eWindow))
    {
        bDisplay = 0;
        printf("[SetMode] Invalid Timing Detect!\n");
    }

    if ( !bDisplay )
    {
        U8 u8Para = FALSE;
        MApi_XC_Mux_TriggerDestOnOffEvent(SYS_INPUT_SOURCE_TYPE(eWindow), &u8Para);

        MApi_XC_PCMonitor_Restart(eWindow);

        printf("[SetMode]SET MODE FAIL!\n");
        return FALSE;
    }

#if (ENABLE_HDMI_4K_2K&&ENABLE_6M40_4KX2K_PROCESS)
    if ( g_HdmiInput4Kx2KFormat==TRUE)
    {
        HDMI_4KX2K_MSG(printf(" change to 1080p30 timing  \r\n"));
        g_PNL_TypeSel = PNL_LVDS_1080P30;
        msAPI_Scaler_ChangePanelType(g_PNL_TypeSel,MAIN_WINDOW);
        MDrv_Ursa_6M40_Set4K2KType(E_URSA_4K2K_MODE_HDMI4K2K);
        MApi_SC_ForceFreerun(ENABLE);
    }
   else
    {
        HDMI_4KX2K_MSG(printf(" change to 1080p60 timing  \r\n"));
        g_PNL_TypeSel = PNL_FULLHD_CMO216_H1L01;
        msAPI_Scaler_ChangePanelType(g_PNL_TypeSel,MAIN_WINDOW);
        MDrv_Ursa_6M40_Set4K2KType(E_URSA_4K2K_MODE_FULLHD);
        MApi_SC_ForceFreerun(DISABLE);
    }
#endif

    // Set all destination device connected with current source
    MApi_XC_Mux_TriggerPathSyncEvent(SYS_INPUT_SOURCE_TYPE(eWindow), NULL);

    if (IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(eWindow)) || IsSrcTypeYPbPr(SYS_INPUT_SOURCE_TYPE(eWindow)))
    {
        /////////////////////////////////
        /// Setup user gain / offset
        /////////////////////////////////
        if ( IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(eWindow)) )
        {
            u8_ADC_Idx = ADC_SET_VGA;
        }
        else
        {
            // YPbPr
            if( MApi_XC_Sys_IsSrcHD(eWindow) )
            {
                // HD
        #if (ENABLE_ADC_BY_SOURCE ==1)
            #if(INPUT_YPBPR_VIDEO_COUNT==2)
                if(SYS_INPUT_SOURCE_TYPE(eWindow)==INPUT_SOURCE_YPBPR2)
                {
                    u8_ADC_Idx = ADC_SET_YPBPR2_HD;
                }
                else
            #endif
            #if(INPUT_YPBPR_VIDEO_COUNT==3)
                if(SYS_INPUT_SOURCE_TYPE(eWindow)==INPUT_SOURCE_YPBPR2)
                {
                    u8_ADC_Idx = ADC_SET_YPBPR3_HD;
                }
                else
            #endif
        #endif
                {
                    u8_ADC_Idx = ADC_SET_YPBPR_HD;
                }
            }
            else
            {
                // SD
        #if (ENABLE_ADC_BY_SOURCE ==1)
            #if(INPUT_YPBPR_VIDEO_COUNT==2)
                if(SYS_INPUT_SOURCE_TYPE(eWindow)==INPUT_SOURCE_YPBPR2)
                {
                    u8_ADC_Idx = ADC_SET_YPBPR2_SD;
                }
                else
            #endif
            #if(INPUT_YPBPR_VIDEO_COUNT==3)
                if(SYS_INPUT_SOURCE_TYPE(eWindow)==INPUT_SOURCE_YPBPR2)
                {
                    u8_ADC_Idx = ADC_SET_YPBPR3_SD;
                }
                else
            #endif
        #endif
                {
                    u8_ADC_Idx = ADC_SET_YPBPR_SD;
                }
            }
        }

        MApi_XC_ADC_AdjustGainOffset(&GENSET_ADC[u8_ADC_Idx].stAdcGainOffsetSetting);
    }

    // Setup enrivement parameter by mode
    if( IsSrcTypeYPbPr(SYS_INPUT_SOURCE_TYPE(eWindow)) )
    {
        MApi_XC_Auto_AutoOffset( ENABLE, TRUE ); // Trigger ADC to do auto-offset
        //msAPI_Timer_Delayms(100);
    }
    else
    {
        MApi_XC_Auto_AutoOffset( DISABLE, FALSE );
    }

    return TRUE;
}

////Separate from PCMODe; Suggestion: Move to DRV Layer
#if 0  //for HDMI/DVI
static U8 MApp_HDMI_SetMode (void)
{
    /// Setup ADC by table query for DVI
    //msAPI_ADC_SetAnalogADC(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), &g_PcadcModeSetting, MApi_XC_PCMonitor_GetSyncStatus(MAIN_WINDOW));
    MApi_XC_ADC_SetMode(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), &g_PcadcModeSetting, MApi_XC_PCMonitor_GetSyncStatus(MAIN_WINDOW));

    if (MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) == E_HDMI_STATUS_DVI)
    {
        //reset HDMI status
        Hal_HDMI_pkt_reset(REST_HDMI_STATUS);
    }
    mvideo_HDMI_GetPacketInfo();
    g_HdmiPollingStatus.u8PreClolrFormat = g_HdmiPacketInfo.u8PacketColorFormat ;

    // Set all destination device connected with current source
    mvideo_mux_trigger_paths_sync_event(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), NULL);

    if (MApi_XC_PCMonitor_GetCurrentState(MAIN_WINDOW) == E_XC_PCMONITOR_UNSTABLE || MApi_XC_PCMonitor_InvalidTimingDetect(TRUE, MAIN_WINDOW))    //(g_bInputTimingChange || _MApp_PCMode_InvalidTimingDetect())
    {
        PCMSG(printf("SET MODE FAIL, timing chg or invalid timing detected\n"));
        return FALSE;
    }
    MApi_XC_Auto_Set_Auto( DISABLE, FALSE );


    return TRUE;
}
U8 MApp_HDMI_SearchMode (void)
{
    //MS_PCADC_MODETABLE_TYPE stTempInputBuff;
    U16 u16HFreqx10, u16VFreqx10, u16Vtotal;
    //U8 u8ModeIndex; // mode index

    U16 u16MinHfreq, u16MaxHfreq;
    U16 u16MinVfreq, u16MaxVfreq;
    U16 u16MinVtotal, u16MaxVtotal;
    XC_IP_SYNC_STATUS sXC_SyncStatus;

    // clear mode flag
    g_bUnsupportMode = FALSE;
    g_u8PcUserModeRamIndex = 0xFF;

    if(MApi_XC_PCMonitor_InvalidTimingDetect(TRUE, MAIN_WINDOW))
    {
        return FALSE;
    }

    // refresh H/V counter
    MDrv_XC_ip_get_sync_status(&sXC_SyncStatus, MAIN_WINDOW);

    // calculate H/V frequency
    u16HFreqx10 = MApi_XC_PCMonitor_Get_HFreqx10(MAIN_WINDOW);
    u16VFreqx10 = MApi_XC_PCMonitor_Get_VFreqx10(MAIN_WINDOW);
    u16Vtotal = MApi_XC_PCMonitor_Get_Vtotal(MAIN_WINDOW);

    // interlace mode
    if ( MApi_XC_PCMonitor_GetSyncStatus(MAIN_WINDOW) & MD_INTERLACE_BIT )
    {
        u16VFreqx10 *= 2; // vsync x 2
    }

    mvideo_sc_set_input_vfreq( u16VFreqx10, MAIN_WINDOW );

    PCMSG(printf("u16HFreqx10 %u\n", u16HFreqx10));
    PCMSG(printf("u16VFreqx10 %u\n", u16VFreqx10));
    PCMSG(printf("g_wVerticalTotal %u\n", u16Vtotal));

    // check sync over range
    if( MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW))==E_HDMI_STATUS_DVI )
    {
        u16MinHfreq    = MIN_HFREQ_OF_DVI;
        u16MaxHfreq    = MAX_HFREQ_OF_DVI;
        u16MinVfreq    = MIN_VFREQ_OF_DVI;
        u16MaxVfreq    = MAX_VFREQ_OF_DVI;
        u16MinVtotal   = MIN_VTOTAL_OF_DVI;
        u16MaxVtotal   = MAX_VTOTAL_OF_DVI;
    }

    if( (u16HFreqx10 > u16MaxHfreq) || (u16HFreqx10 < u16MinHfreq) ||
        (u16VFreqx10 > u16MaxVfreq) || (u16VFreqx10 < u16MinVfreq) ||
        (u16Vtotal > u16MaxVtotal) || (u16Vtotal < u16MinVtotal)
        ||((IsHDMIInUse()&&(MApp_PCMode_Get_HResolution(MAIN_WINDOW) > 1930)) || (MApp_PCMode_Get_VResolution(MAIN_WINDOW) > 1210))

        )
    {
        PCMSG(printf("OOR u16HFreqx10 %u\n", u16HFreqx10));
        PCMSG(printf("OOR u16VFreqx10 %u\n", u16VFreqx10));
        PCMSG(printf("OOR g_wVerticalTotal %u\n", u16Vtotal));

//        PCMSG(printf("OOR u16MinHfreq %u\n", u16MinHfreq));
//        PCMSG(printf("OOR u16MaxHfreq %u\n", u16MaxHfreq));
//        PCMSG(printf("OOR u16MinVfreq %u\n", u16MinVfreq));
//
//        PCMSG(printf("OOR u16MaxVfreq %u\n", u16MaxVfreq));
//        PCMSG(printf("OOR u16MinVtotal %u\n", u16MinVtotal));
//        PCMSG(printf("OOR u16MaxVtotal %u\n", u16MaxVtotal));

        g_bUnsupportMode = TRUE;
        return TRUE;
    }
    return TRUE;
}


static EN_MODE_HANDLE_EVENT MApp_HDMI_SearchModeHandler(void)
{
    EN_MODE_HANDLE_EVENT enModeHandleEvent;

    if ( !MApi_XC_PCMonitor_SyncLoss(MAIN_WINDOW) ) // check have sync
    {

        MApi_XC_HDMI_CheckModeChanged(TRUE);

        if ( !MApp_HDMI_SearchMode() ) // search mode
        {
            if ( !g_bUnsupportMode )
            {
                PCMSG(printf("MODE_HANDLE_SET_FAIL = \n" ));
                return MODE_HANDLE_SET_FAIL;
            }
        }

        if ( !g_bUnsupportMode ) // general support mode
        {
            if (MApp_HDMI_SetMode() == FALSE ) // set mode fail
            {
                PCMSG(printf("MODE_HANDLE_SET_FAIL 2 = \n" ));
                return MODE_HANDLE_SET_FAIL;
            }

            enModeHandleEvent = MODE_HANDLE_SET_READY;
            PCMSG(printf("MODE_HANDLE_SET_READY  = \n" ));
            // Set mode successful ...

        } // End support mode
        else
        {
            PCMSG(printf("MODE_HANDLE_UNSUPPORT 2 = \n" ));
            enModeHandleEvent = MODE_HANDLE_UNSUPPORT;
        }
    }
    else // no signal
    {
        PCMSG(printf("NO SIGNAL = \n" ));

        enModeHandleEvent = MODE_HANDLE_NO_SYNC;
    }

    return enModeHandleEvent;
}
#endif


static MS_BOOL _MApp_PCMode_Check_OOR(SCALER_WIN eWindow, XC_MODEPARSE_INPUT_INFO *psInputInfo)
{
    MS_U16 u16MinHfreq, u16MaxHfreq;
    MS_U16 u16MinVfreq, u16MaxVfreq;
    MS_U16 u16MinVtotal, u16MaxVtotal;
    UNUSED(eWindow);
    if(IsSrcTypeVga(psInputInfo->eSrcType))
    {
        u16MinHfreq    = MIN_HFREQ_OF_RGB;
        u16MaxHfreq    = MAX_HFREQ_OF_RGB;
        u16MinVfreq    = MIN_VFREQ_OF_RGB;
        u16MaxVfreq    = MAX_VFREQ_OF_RGB;
        u16MinVtotal   = MIN_VTOTAL_OF_RGB;
        u16MaxVtotal   = MAX_VTOTAL_OF_RGB;
    }
#if (INPUT_HDMI_VIDEO_COUNT > 0)
    else if( IsSrcTypeHDMI(psInputInfo->eSrcType) )
    {
        u16MinHfreq    = MIN_HFREQ_OF_DVI;
        u16MaxHfreq    = MAX_HFREQ_OF_DVI;
        u16MinVfreq    = MIN_VFREQ_OF_DVI;
        u16MaxVfreq    = MAX_VFREQ_OF_DVI;
        u16MinVtotal   = MIN_VTOTAL_OF_DVI;
        u16MaxVtotal   = MAX_VTOTAL_OF_DVI;
    }
#endif
    else
    {
        u16MinHfreq    = MIN_HFREQ_OF_YPBPR;
        u16MaxHfreq    = MAX_HFREQ_OF_YPBPR;
        u16MinVfreq    = MIN_VFREQ_OF_YPBPR;
        u16MaxVfreq    = MAX_VFREQ_OF_YPBPR;
        u16MinVtotal   = MIN_VTOTAL_OF_YPBPR;
        u16MaxVtotal   = MAX_VTOTAL_OF_YPBPR;
    }
        PCMSG(printf("OOR u16HFreqx10 %d \r\n", psInputInfo->u16HFreqx10));
        PCMSG(printf("OOR u16VFreqx10 %d \r\n", psInputInfo->u16VFreqx10));
        PCMSG(printf("OOR u16Vtotal %d \r\n", psInputInfo->u16Vtotal));

    if( (psInputInfo->u16HFreqx10 > u16MaxHfreq) || (psInputInfo->u16HFreqx10 < u16MinHfreq) ||
        (psInputInfo->u16VFreqx10 > u16MaxVfreq) || (psInputInfo->u16VFreqx10 < u16MinVfreq) ||
        (psInputInfo->u16Vtotal > u16MaxVtotal) || (psInputInfo->u16Vtotal < u16MinVtotal)
#if (INPUT_HDMI_VIDEO_COUNT > 0)
        ||(IsSrcTypeHDMI(psInputInfo->eSrcType)&&((psInputInfo->sDVI_HDMI_DE_Info.width > MAX_WIDTH_OF_DVI) || (psInputInfo->sDVI_HDMI_DE_Info.height > MAX_HEIGHT_OF_DVI)))
#endif
        )
    {
        PCMSG(printf("[1]OOR u16HFreqx10 %d\n", psInputInfo->u16HFreqx10));
        PCMSG(printf("[1]OOR u16VFreqx10 %d\n", psInputInfo->u16VFreqx10));
        PCMSG(printf("[1]OOR u16Vtotal %d\n", psInputInfo->u16Vtotal));

        return TRUE;
    }

    return FALSE;
}

void _MApp_PCMode_ModeParse(INPUT_SOURCE_TYPE_t src,SCALER_WIN eWindow)
{
    // to match mode, we need these information
    // H/V freq., Vtt
    // Sync polarity
    // Interlaced or Progrssive
    PCMODE_INFO[eWindow].sModeParseInputInfo.eSrcType = src;
    PCMODE_INFO[eWindow].sModeParseInputInfo.u16HFreqx10 = MApi_XC_PCMonitor_Get_HFreqx10(eWindow);
    PCMODE_INFO[eWindow].sModeParseInputInfo.u16VFreqx10 = MApi_XC_PCMonitor_Get_VFreqx10(eWindow);
    PCMODE_INFO[eWindow].sModeParseInputInfo.u8SyncStatus = MApi_XC_PCMonitor_GetSyncStatus(eWindow);
    PCMODE_INFO[eWindow].sModeParseInputInfo.u16Vtotal = MApi_XC_PCMonitor_Get_Vtotal(eWindow);
    PCMSG(printf("PCMODE_INFO: u16HFreqx10=%d,u16VFreqx10=%d,u16Vtotal=%d\n", PCMODE_INFO[eWindow].sModeParseInputInfo.u16HFreqx10, PCMODE_INFO[eWindow].sModeParseInputInfo.u16VFreqx10, PCMODE_INFO[eWindow].sModeParseInputInfo.u16Vtotal));
    PCMSG(printf("PCMODE_INFO: u8SyncStatus=%d,eSrcType=%d\n", PCMODE_INFO[eWindow].sModeParseInputInfo.u8SyncStatus, PCMODE_INFO[eWindow].sModeParseInputInfo.eSrcType));

    if ( IsSrcTypeHDMI(src) )
    {
        if ( MApi_XC_GetHdmiSyncMode() == HDMI_SYNC_DE)
        {
            MApi_XC_PCMonitor_Get_Dvi_Hdmi_De_Info(eWindow,&(PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info));
            PCMSG(printf("\n HDMI DE X=%u Y=%u width=%u height=%d \n",PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.x,PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.y,PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.width,PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.height));
        }
        else
        {
            MApi_XC_GetDEWidthHeightInDEByPassMode(&PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.width,&PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.height, eWindow );
            printf("daniel_test DEWidthHeightInDEByPassMode: W=%u,H=%u\n", PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.width, PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.height);
        }
    }

    // Pre-Check the signal Range
    if(_MApp_PCMode_Check_OOR(eWindow, &(PCMODE_INFO[eWindow].sModeParseInputInfo)))
    {
        PCMODE_INFO[eWindow].eModeParseResult = XC_MODEPARSE_OUT_OF_RANGE;
        PCMSG(printf(" OUT_OF_RANGE \r\n"));
    }
    else
    {
        PCMODE_INFO[eWindow].eModeParseResult = MApi_XC_ModeParse_MatchModeEx(MApi_XC_GetModeTable() ,MApi_XC_GetTotalModeCount() , &(PCMODE_INFO[eWindow].sModeParseInputInfo));

        if (IsSrcTypeVga(src))//VGA EIA timing
        {
            //MApi_XC_SetDbgLevel(XC_DBGLEVEL_AUTOGEOMETRY);
            if (XC_MODEPARSE_SUPPORT_MODE == PCMODE_INFO[eWindow].eModeParseResult)
            {
                MS_U8 u8Index;
                MS_PCADC_MODETABLE_TYPE_EX sModeTbl;
                XC_Auto_Signal_Info_Ex stModeInfo;
                MS_BOOL bFind = FALSE;
                MS_BOOL bFindEx = FALSE;

                u8Index = PCMODE_INFO[eWindow].sModeParseInputInfo.u8ModeIndex;
                PCMSG(printf("u8ModeIndex = %d\n", u8Index));
                PCMSG(printf("u8SyncStatus= %d\n", PCMODE_INFO[eWindow].sModeParseInputInfo.u8SyncStatus));

                if ((MD_720x480_60I == u8Index )||( MD_720x576_50I == u8Index))
                {
                    PCMODE_INFO[eWindow].eModeParseResult=XC_MODEPARSE_UNSUPPORT_MODE;
                }
                else if( (MD_1400x1050_60 == u8Index ) ||( MD_1680x1050_60 == u8Index) )
                {
                    if(!bFind)
                    {
                        MApi_XC_ModeParse_GetModeTbl((U8)MD_1400x1050_60, &sModeTbl);
                        stModeInfo.u16HorizontalStart = sModeTbl.u16HorizontalStart;
                        stModeInfo.u16VerticalStart = sModeTbl.u16VerticalStart;
                        stModeInfo.u16HorizontalTotal = 1880;//sModeTbl.u16HorizontalTotal;
                        stModeInfo.u16HResolution = 1400;
                        stModeInfo.u16Phase = sModeTbl.u16AdcPhase;
                        stModeInfo.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;
                        //memcpy(&tmpinfo, &stModeInfo, sizeof(XC_Auto_Signal_Info_Ex));
                        //if (MApi_XC_Auto_Geometry_Ex(E_XC_AUTO_TUNE_BASIC, &stModeInfo, &tmpinfo, eWindow)) // auto-tune
                        if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                        {
                            if(abs(stModeInfo.u16HResolution - 1400) <= HRESOLUTION_TOLERANCE)
                            {
                                u8Index = MD_1400x1050_60;
                                bFind = TRUE;
                            }
                        }
                        if(!bFind)
                        {
                            stModeInfo.u16HorizontalTotal = 1864;//sModeTbl.u16HorizontalTotal;
                            stModeInfo.u16HResolution = 1400;
                            if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                            {
                                if(abs(stModeInfo.u16HResolution - 1400) <= HRESOLUTION_TOLERANCE)
                                {
                                    u8Index = MD_1400x1050_60;
                                    bFind = TRUE;
                                }
                            }
                        }
                    }
                    if(!bFind)
                    {
                        MApi_XC_ModeParse_GetModeTbl((U8)MD_1680x1050_60, &sModeTbl);
                        stModeInfo.u16HorizontalStart = sModeTbl.u16HorizontalStart;
                        stModeInfo.u16VerticalStart = sModeTbl.u16VerticalStart;
                        stModeInfo.u16HorizontalTotal = 2240;//sModeTbl.u16HorizontalTotal;
                        stModeInfo.u16HResolution = 1680;
                        stModeInfo.u16Phase = sModeTbl.u16AdcPhase;
                        stModeInfo.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;
                        //memcpy(&tmpinfo, &stModeInfo, sizeof(XC_Auto_Signal_Info_Ex));
                        //if (MApi_XC_Auto_Geometry_Ex(E_XC_AUTO_TUNE_BASIC, &stModeInfo, &tmpinfo, eWindow)) // auto-tune
                        if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                        {
                            if(abs(stModeInfo.u16HResolution - 1680) <= HRESOLUTION_TOLERANCE)
                            {
                                u8Index = MD_1680x1050_60;
                                bFind = TRUE;
                            }
                        }
                    }
                }
                else if((MD_1400x1050_59 == u8Index)
                     || (MD_1680x1050_59 == u8Index))
                {
                    //Distinguish Reduce blanking timing of these two modes
                    if(!bFind)
                    {
                        MApi_XC_ModeParse_GetModeTbl((U8)MD_1400x1050_59, &sModeTbl);
                        stModeInfo.u16HorizontalStart = sModeTbl.u16HorizontalStart;
                        stModeInfo.u16VerticalStart = sModeTbl.u16VerticalStart;
                        stModeInfo.u16HorizontalTotal = 1560;//sModeTbl.u16HorizontalTotal;
                        stModeInfo.u16HResolution = 1400;
                        stModeInfo.u16Phase = sModeTbl.u16AdcPhase;
                        stModeInfo.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;
                        //memcpy(&tmpinfo, &stModeInfo, sizeof(XC_Auto_Signal_Info_Ex));
                        //if (MApi_XC_Auto_Geometry_Ex(E_XC_AUTO_TUNE_BASIC, &stModeInfo, &tmpinfo, eWindow)) // auto-tune
                        if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                        {
                            if(abs(stModeInfo.u16HResolution - 1400) <= HRESOLUTION_TOLERANCE)
                            {
                                u8Index = MD_1400x1050_59;
                                bFind = TRUE;
                            }
                        }
                    }
                    if(!bFind)
                    {
                        MApi_XC_ModeParse_GetModeTbl((U8)MD_1680x1050_59, &sModeTbl);
                        stModeInfo.u16HorizontalStart = sModeTbl.u16HorizontalStart;
                        stModeInfo.u16VerticalStart = sModeTbl.u16VerticalStart;
                        stModeInfo.u16HorizontalTotal = 1840;//sModeTbl.u16HorizontalTotal;
                        stModeInfo.u16HResolution = 1680;
                        stModeInfo.u16Phase = sModeTbl.u16AdcPhase;
                        stModeInfo.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;
                        //memcpy(&tmpinfo, &stModeInfo, sizeof(XC_Auto_Signal_Info_Ex));
                        //if (MApi_XC_Auto_Geometry_Ex(E_XC_AUTO_TUNE_BASIC, &stModeInfo, &tmpinfo, eWindow)) // auto-tune
                        if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                        {
                            if(abs(stModeInfo.u16HResolution - 1680) <= HRESOLUTION_TOLERANCE)
                            {
                                u8Index = MD_1680x1050_59;
                                bFind = TRUE;
                            }
                        }
                    }
                }
                else if((MD_1440x900_60 == u8Index) || (MD_1600x900_60 == u8Index))
                {
                    if(!bFindEx)
                    {
                        MApi_XC_ModeParse_GetModeTbl((U8)MD_1600x900_60, &sModeTbl);
                        stModeInfo.u16HorizontalStart = sModeTbl.u16HorizontalStart;
                        stModeInfo.u16VerticalStart = sModeTbl.u16VerticalStart;
                        stModeInfo.u16HorizontalTotal = 2128;
                        stModeInfo.u16HResolution = 1600;
                        stModeInfo.u16Phase = sModeTbl.u16AdcPhase;
                        stModeInfo.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;
                        if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                        {
                            if(abs(stModeInfo.u16HResolution - 1600) <= HRESOLUTION_TOLERANCE)
                            {
                                u8Index = MD_1600x900_60;
                                bFindEx = TRUE;
                            }
                        }
                    }
                    if(!bFindEx)
                    {
                        MApi_XC_ModeParse_GetModeTbl((U8)MD_1440x900_60, &sModeTbl);
                        stModeInfo.u16HorizontalStart = sModeTbl.u16HorizontalStart;
                        stModeInfo.u16VerticalStart = sModeTbl.u16VerticalStart;
                        stModeInfo.u16HorizontalTotal = 1904;
                        stModeInfo.u16HResolution = 1440;
                        stModeInfo.u16Phase = sModeTbl.u16AdcPhase;
                        stModeInfo.u16Version = XC_AUTO_SIGNAL_INFO_VERSION;
                        if(MApi_XC_Auto_DetectWidth(&stModeInfo, eWindow))
                        {
                            if(abs(stModeInfo.u16HResolution - 1440) <= HRESOLUTION_TOLERANCE)
                            {
                                u8Index = MD_1440x900_60;
                                bFindEx = TRUE;
                            }
                        }
                    }
                }

                if(bFind)
                {
                    PCMODE_INFO[eWindow].sModeParseInputInfo.u8ModeIndex = u8Index;
                    if((u8Index == MD_1680x1050_60) ||
                        (u8Index == MD_1680x1050_59))
                    {
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1680;
                    }
                    else
                    {
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1400;
                    }
                }

                if(bFindEx)
                {
                    if(u8Index ==  MD_1600x900_60)
                    {
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1600;
                    }
                    else
                    {
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1440;
                    }
                }
            }
        }

#if ENABLE_VGA_EIA_TIMING
        if (IsSrcTypeVga(src))//VGA EIA timing
        {
            if (XC_MODEPARSE_SUPPORT_MODE == PCMODE_INFO[eWindow].eModeParseResult)
            {
                MS_U8 u8Index;

                u8Index = PCMODE_INFO[eWindow].sModeParseInputInfo.u8ModeIndex;

                if (MD_1280x768_60 == u8Index || MD_1280x768_60_RB == u8Index ||
                    MD_1360x768_60== u8Index || MD_1366x768_60 == u8Index)
                {
                    XC_IP_SYNC_STATUS sXC_SyncStatus;
                    MApi_XC_GetSyncStatus(src, &sXC_SyncStatus, eWindow);

                    PCMSG(printf("VGA EIA timing further discrimination 1: "));
                    if ((sXC_SyncStatus.u8SyncStatus & (XC_MD_VSYNC_POR_BIT|XC_MD_HSYNC_POR_BIT)) == 2)
                    {
                        u8Index = MD_1280x768_60_RB;
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1280;
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResHeight= 768;
                        PCMSG(printf("1280x768_60RB\n"));
                    }
                    else if((sXC_SyncStatus.u8SyncStatus & (XC_MD_VSYNC_POR_BIT|XC_MD_HSYNC_POR_BIT)) == 1)
                    {
                        u8Index = MD_1280x768_60;
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1280;
                        PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResHeight= 768;
                        PCMSG(printf("1280x768_60\n"));
                    }
                    else if((sXC_SyncStatus.u8SyncStatus & (XC_MD_VSYNC_POR_BIT|XC_MD_HSYNC_POR_BIT)) == 3)
                    {
                        if (MApi_XC_GetVSyncWidth(eWindow) < 5)
                        {
                            u8Index = MD_1366x768_60;
                            PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1366;
                            PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResHeight= 768;
                            PCMSG(printf("1366x768_60\n"));
                        }
                        else
                        {
                            u8Index = MD_1360x768_60;
                            PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth = 1360;
                            PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResHeight= 768;
                            PCMSG(printf("1360x768_60\n"));
                        }
                    }
                }

                // Fix Mantis-0939712:  [SQC][Maya_084B][2nd_ATSC][D-Sub] 使用MSPG-925FS > Timing :1920x1080@60Hz >畫面偏移
                // 20150819: It should not change the result of ModeParse!!
                // It will cause mode index wrong and auto position failed!
                /*
                if (MD_1920x1080_60P == u8Index)
                {
                    u8Index = MD_1920X1080_60;
                    printf("\nWarning: Force MD_1920x1080_60P to MD_1920X1080_60\n");
                } */

                PCMODE_INFO[eWindow].sModeParseInputInfo.u8ModeIndex = u8Index;
            }
        }
#endif
    }
}

//*************************************************************************
//------------------------------ Warning ----------------------------------
//Attention: !!!!!!------ Don't add UI variable or unneeded code in this file
//
//           Don't modify this procedure !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//*************************************************************************
//*************************************************************************
//Function name:    MApp_PCMode_ModeHandler
//Passing parameter:    none
//Return parameter:     none
//Description:  This function will handle mode settings when signal is changed and stable
//*************************************************************************
static void _MApp_PCMode_StatusHandler(INPUT_SOURCE_TYPE_t src, XC_PCMONITOR_STATUS current_status , SCALER_WIN eWindow)
{
    U8 u8TurnOffDestination = FALSE;
    static XC_PCMONITOR_STATUS previous_status[2] = {E_XC_PCMONITOR_STABLE_NOSYNC, E_XC_PCMONITOR_STABLE_NOSYNC};
  #if (ENABLE_HDMI_4K_2K && SUPPORT_4K_TO_2K_CONVERT )
    XC_SETWIN_INFO stSetWinInfo;
  #endif

    // Stable -> unstable or no sync
    if (  previous_status[eWindow] == E_XC_PCMONITOR_STABLE_SYNC &&
          previous_status[eWindow] != current_status ) // unstable or no sync
    {
        // Disable all destination as soon as possiable.
        //printf("[PCMode] stable -> unstable or no sync(%u) at %u\n", current_status, MsOS_GetSystemTime());

    #if(DEBUG_CHG_SRC_TIME)
        msDebug_PrintChgSrcTime("Sync unstable");
    #endif

        // Trigger to turn off window
        MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

        if( IsSrcTypeHDMI(src) )
        {
            // If chip is not support IMM switch, need reset DVI port
            if( FALSE == MApi_XC_Sys_Is_SupportImmSwitch() )
            {
                MApi_XC_Sys_ResetDVIPort(src);
            }


         #if ENABLE_3D_PROCESS
            if((eWindow == MAIN_WINDOW)&&(g_HdmiInput3DFormat != E_XC_3D_INPUT_MODE_NONE))
            {
                g_HdmiInput3DFormat = E_XC_3D_INPUT_MODE_NONE;
                g_HdmiInput3DFormatStatus = E_XC_3D_INPUT_MODE_NONE;
                previous_status[SUB_WINDOW] = E_XC_PCMONITOR_STABLE_NOSYNC;
                if(IsSrcTypeHDMI(src))
                {
                    MDrv_HDMI_pkt_reset(REST_HDMI_STATUS);
                }

                MApp_Scaler_3D_ResetForChangeTiming();
            }
        #endif

        #if (ENABLE_HDMI_4K_2K && SUPPORT_4K_TO_2K_CONVERT)
            MApp_Scaler_GetWinInfo(&stSetWinInfo, MAIN_WINDOW);
            if(stSetWinInfo.stDispWin.width <= 1920)
            {
                if(MDrv_HDMI_Check4K2K())
                {
                    //Some IP counter bit not enough, need to scaling down in HDMI RX first.
                    //Thus, when HDMI 3840x2160 input, Scaler input is 1920x2160
                    //MDrv_HDMI_AVG_ScaleringDown(TRUE);
                    _MApp_PCMode_SetHdmiAvgMode(TRUE);
                }
                else
                {
                    //MDrv_HDMI_AVG_ScaleringDown(FALSE);
                    _MApp_PCMode_SetHdmiAvgMode(FALSE);
                }
            }
            else    //4k to 4k, no need to scaling down
            {
                //MDrv_HDMI_AVG_ScaleringDown(FALSE);
                _MApp_PCMode_SetHdmiAvgMode(FALSE);
            }
        #endif

        #if (ENABLE_HDMI_4K_2K&&ENABLE_6M40_4KX2K_PROCESS)
            if(g_HdmiInput4Kx2KFormat)
            {
                HDMI_4KX2K_MSG(printf(" NoSync change to 1080p60 timing  \r\n"));
                g_HdmiInput4Kx2KFormat= FALSE;
                g_PNL_TypeSel = PNL_FULLHD_CMO216_H1L01;
                msAPI_Scaler_ChangePanelType(g_PNL_TypeSel,MAIN_WINDOW);
                MDrv_Ursa_6M40_Set4K2KType(E_URSA_4K2K_MODE_FULLHD);
                MApi_SC_ForceFreerun(DISABLE);
            }
        #endif
        }

      #if (ENABLE_PIP)
        if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
      #endif
        {
            //MApi_AUDIO_HDMI_SetDownSample(0);
            _MDrv_HDMI_audio_downsample();
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        }

        MApp_DB_LoadDefaultTable(eWindow, 0);

        if ( current_status == E_XC_PCMONITOR_UNSTABLE )
            PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_UNSTABLE;
        else
            PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_NOSYNC;


        MApp_UI_NotifySysEvent(E_SYS_EVENT_PC_MODE_CHANGE_START, NULL);
    }

    // unstable or no sync -> stable
    else if( current_status == E_XC_PCMONITOR_STABLE_SYNC &&
             previous_status[eWindow] != current_status)
    {
        //printf("[PCMode] unstable or no sync -> stable at %u\n", MsOS_GetSystemTime());
	ucFirstNoSignalSource=UI_INPUT_SOURCE_NONE;	 //Ray DMP 2017.04.07:As it is stable again, ucFirstNoSignalSource is set to NONE
    #if(DEBUG_CHG_SRC_TIME)
        msDebug_PrintChgSrcTime("Sync stable");
    #endif


    #if (INPUT_HDMI_VIDEO_COUNT > 0)
        if(IsSrcTypeHDMI(src))
        {
        #if  (ENABLE_HDMI_4K_2K && SUPPORT_4K_TO_2K_CONVERT)
            MApp_Scaler_GetWinInfo(&stSetWinInfo, MAIN_WINDOW);
            if(stSetWinInfo.stDispWin.width <= 1920) // Not 4K panel
            {
                if(MDrv_HDMI_Check4K2K())
                {
                    //Some IP counter bit not enough, need to scaling down in HDMI RX first.
                    //Thus, when HDMI 3840x2160 input, Scaler input is 1920x2160
                    //MDrv_HDMI_AVG_ScaleringDown(TRUE);
                    _MApp_PCMode_SetHdmiAvgMode(TRUE);
                }
                else
                {
                    //MDrv_HDMI_AVG_ScaleringDown(FALSE);
                    _MApp_PCMode_SetHdmiAvgMode(FALSE);
                }
            }
            else    //4k to 4k, no need to scaling down
            {
                //MDrv_HDMI_AVG_ScaleringDown(FALSE);
                _MApp_PCMode_SetHdmiAvgMode(FALSE);
            }

        #endif
            // check if HDMI or DVI
            MApi_XC_HDMI_CheckModeChanged(TRUE, eWindow);

            msApiPrintfHDMI_STATUSMode(MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(eWindow)));
        }
    #endif

        // Mode parse after timing stable.
        _MApp_PCMode_ModeParse(src, eWindow);

        if(PCMODE_INFO[eWindow].eModeParseResult == XC_MODEPARSE_SUPPORT_MODE)
        {
            PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_STABLE_SUPPORT_MODE;

            // load mode setting
            MApp_PCMode_LoadModeData(eWindow, PCMODE_INFO[eWindow].sModeParseInputInfo.u8ModeIndex, (BOOLEAN)( (PCMODE_INFO[eWindow].sModeParseInputInfo.u8SyncStatus & XC_MD_USER_MODE_BIT) >0));

            if(_MApp_PCMode_SetMode(eWindow))
            {
                //printf("[PCMode] Set Mode ok at %u\n", MsOS_GetSystemTime());

                MApp_AnalogInputs_Force2MonitorWindows(eWindow);
                // switch audio between HDMI/DVI
              #if 1//defined (DVB_SYSTEM)  // mantis : 0969658
                if(IsHDMIInUse())
                {
                #if HDMI_DVI_AUDIO_MODE_CONFIG
                    if(stGenSetting.g_SysSetting.fEnableHdmiDviAudioModeConfig == EN_HDMI_DVI_AUDIOMODE_DIGTAL)
                    {
                        MAPP_InputSource_SwitchHDMI_DVI(E_HDMI_STATUS_HDMI);
                    }
                    else if(stGenSetting.g_SysSetting.fEnableHdmiDviAudioModeConfig == EN_HDMI_DVI_AUDIOMODE_ANALOG)
                    {
                        MAPP_InputSource_SwitchHDMI_DVI(E_HDMI_STATUS_DVI);
                    }
                    else
                #endif
                    {
                        if (MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(eWindow)) == E_HDMI_STATUS_HDMI)
                        {
                        #if (ENABLE_PIP)
                            if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
                        #endif
                            {
                                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                                MAPP_InputSource_SwitchHDMI_DVI(E_HDMI_STATUS_HDMI);
                            }
                        }
                        else if(MApi_XC_HDMI_GetHdmiType(SYS_INPUT_SOURCE_TYPE(eWindow)) == E_HDMI_STATUS_DVI)
                        {
                        #if (ENABLE_PIP)
                            if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
                        #endif
                            {
                                MAPP_InputSource_SwitchHDMI_DVI(E_HDMI_STATUS_DVI);
                            }
                        }
                    }
                }
            #endif

                // un-mute video
            #if (ENABLE_HDMI_4K_2K&&ENABLE_6M40_4KX2K_PROCESS)
                if ( g_HdmiInput4Kx2KFormat)
                {
                    u8TurnOffDestination = DISABLE;
                    HDMI_4KX2K_MSG(printf(" 4KX2K Set Mode Disable output \n"));
                }
                else
            #endif
                {
                    u8TurnOffDestination = ENABLE;
                }

                MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

                // un-mute audio
              #if (ENABLE_PIP)
                if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
              #endif
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }

                //MApp_PCMode_SelfAuto();
                if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(eWindow))&&(g_PcadcModeSetting[eWindow].u8AutoSign == 0))
                {
                    if(MApp_PCMode_Enable_SelfAuto(ENABLE, eWindow))
                    {
                        MApp_UI_NotifySysEvent(E_SYS_EVENT_PC_AUTO_TUNE_START, NULL);
                    }
                }

                MApp_UI_NotifySysEvent(E_SYS_EVENT_PC_YPBPR_HDMI_SET_MODE_DONE, NULL);
            }
            else
            {
                // set mode failed (timing changed), so disable all destination.
                //printf("[PCMode] SetMode failed!\n");

                MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

              #if (ENABLE_PIP)
                if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
              #endif
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }

                MApp_DB_LoadDefaultTable(eWindow, 0);
            }
        }
        else
        {
            // un-support, so disable all destination.
            MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

          #if (ENABLE_PIP)
            if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
          #endif
            {
                msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }
            MApp_DB_LoadDefaultTable(eWindow, 0);

            PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_STABLE_UN_SUPPORT_MODE;
        }
        #if(sPowerDown_Function==sSimple_PowerDownFun)
        if(sSaveSleepForPM)
        {
        	sSaveSleepForPM = 0;
        	//#ifdef sAddPMSavePara
  				//msAPI_rmBurstWriteBytes(RM_PM_POWER_STATUS_ADDR, (BYTE *)&sSaveSleepForPM, 1);        	
  				//#endif        	
        	MApp_SimplePowerSaving(0);
        	MApp_Sleep_ReleaseSleepTimer();
					/*#ifdef sShowInputMsgDelay
  	  		if ( E_OSD_EMPTY != MApp_ZUI_GetActiveOSD())
	    		{
	    			MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_CLOSE_CURRENT_OSD);
      			//MApp_ZUI_ACT_ShutdownOSD();		
					}	
    			MApp_ZUI_ACT_StartupOSD(E_OSD_CHANNEL_INFO);
					MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);				
					#endif*/
        	//#ifdef sAddPMSavePara
  				//msAPI_rmBurstWriteBytes(RM_PM_POWER_STATUS_ADDR, (BYTE *)&sSaveSleepForPM, 1);        	
  				//#endif
        }	
        #endif 
    }

    // Unstable -> no snyc
    else if ( previous_status[eWindow] == E_XC_PCMONITOR_UNSTABLE && current_status == E_XC_PCMONITOR_STABLE_NOSYNC)
    {
        //printf("[PCMode] unstable -> No Sync at %u\n", MsOS_GetSystemTime());
    		#if(DEBUG_CHG_SRC_TIME)
        //msDebug_PrintChgSrcTime("unstable -> No Sync");
    		#endif
        PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_NOSYNC;
    		#if (ENABLE_PIP)
        if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
    		#endif
        {
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        }
        #if(TVE_NoSignalFunctionType==TVE_NoSignalToPollingSource)	
        //printf("MingYuan MApp_ZUI_GetActiveOSD() %d \n",MApp_ZUI_GetActiveOSD());
				#ifdef sUseSimplePowerShutDown
				if((sFlagSimPowerShutDown&0x01)==0x01)
				{
					sPollingCheckC = 0;
					return;
				}	
				#endif	        
        if (MApp_ZUI_GetActiveOSD() == E_OSD_SCREEN_SAVER)
        {
	        sPollingCheckC++;
  	      msAPI_Timer_Delayms(1);  	    
          if(sPollingCheckC>=200)
          {
          	sIsPollingSwitch = 1;
          	sPollingCheckC = 0;

          	//Ray ASS 2017.03.14: Switch to next source only when auto source seek is ENABLE
          	if(GET_AUTO_SOURCE_SEEK()==ENABLE){
          	    printf("\nRay: auto source seek from source %d\n",UI_INPUT_SOURCE_TYPE);		//Ray DBG 2017.03.14

		     //Ray DMP 2017.04.07: If UI_INPUT_SOURCE_TYPE is the first no signal source again and Fail over is enabled, go to DMP
		    if((ucFirstNoSignalSource==UI_INPUT_SOURCE_TYPE)&&(GET_FAIL_OVER() == ENABLE))
		    {
			//Ray DMP 2017.04.07: Enter to play DMP if USB drive exists
			if(MApp_NoSignal_EnterDMP()==FAIL){
			    //Ray DMP 2017.04.07: If fail to detect USB for first 3 time, just quit without change to next input source so that we can detect USB drive again next time
			    return;
			}
		    }

		    //Ray DMP 2017.04.07:Check if it's first time that no sync detected
		    if(ucFirstNoSignalSource==UI_INPUT_SOURCE_NONE)
		    {
			    //Ray DMP 2017.04.07: If yes, joint down the input source which has no signal first (stable-> no sync)
			    ucFirstNoSignalSource=UI_INPUT_SOURCE_TYPE;
			    //printf("\nRay Joint down ucFirstNoSignalSource =%d",ucFirstNoSignalSource);		//Ray DBG 2017.04.07
		    }

#ifdef sSP4096Board					//Ray ASS 2017.03.29: Set auto source seek sequence
		    if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI3)
		    {
			MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_RGB);  //Ray ASS 2017.03.29: Go to VGA
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_RGB)
		    {
			MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI);	//Ray ASS 2017.03.29: Go to HDMI1 (port A)
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI)
		    {
			MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI2);	//Ray ASS 2017.03.29: Go to HDMI2 (port B)
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI2)
		    {
			MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI4);	//Ray ASS 2017.03.29: Go to HDMI3 (port D)
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI4)
		    {
			MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI3);	//Ray ASS 2017.03.29: Go to DVI (port C)
		    }
		    printf("\nRay: auto source seek to source %d\n",UI_INPUT_SOURCE_TYPE);		//Ray DBG 2017.04.10
#else
		    if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI3)
		    {
								MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_RGB);
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_RGB)
		    {
								MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI);
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI)
		    {
								MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI2);
		    }
		    else if(UI_INPUT_SOURCE_TYPE==UI_INPUT_SOURCE_HDMI2)
		    {
								MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI3);
		    }
#endif
          	}
    		//Ray DMP 2017.04.07: If Auto Source seek is disable and if there is no sync, and if fail over is enabled, just go to play DMP
    		else if (GET_FAIL_OVER()== ENABLE)
		{
		    if(MApp_NoSignal_EnterDMP()==FAIL)
		      {
			//Ray DMP 2017.04.07: If fail to detect USB for first 3 time, just quit without change previous_status[eWindow] so that we can detect USB drive again next time
			return;
		      }
    		}

            sIsPollingSwitch = 0;
            return;			//Ray ASS 2017.06.21: Add return without change previous_status[eWindow] so that we can continuous detect if auto source seek changed between disabled and enabled
      	  }
      	  else
      	  {
      	  	sIsPollingSwitch = 0;
      	  	return;
      	  }       
      	}
      	else
      	{
      		sIsPollingSwitch = 0;
      		return;
      	}   
        #elif(TVE_NoSignalFunctionType==TVE_NoSignalToBurnInMode)
        
        #endif
    }

    // no sync -> unstable
    else if (previous_status[eWindow] == E_XC_PCMONITOR_STABLE_NOSYNC && current_status == E_XC_PCMONITOR_UNSTABLE)
    {
        //printf("[PCMode] no sync -> unstable at %u\n", MsOS_GetSystemTime());

    #if(DEBUG_CHG_SRC_TIME)
        //msDebug_PrintChgSrcTime("no sync -> unstable");
    #endif

        PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_UNSTABLE;

    #if (ENABLE_PIP)
        if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
    #endif
        {
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        }
    }
  #if ENABLE_NO_AUDIO_INPUT_AUTO_MUTE
    else if( current_status == E_XC_PCMONITOR_STABLE_SYNC&&IsSrcTypeAnalog(src))
    {
       BYTE NR_status;
       static BYTE PreNR_status=0;
       NR_status = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_getNR_Status) ;

       if(PreNR_status!=NR_status)
         {
           if(!NR_status)
             {
               PreNR_status=NR_status;
               msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_1_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
               printf("NRenable=%d\n",(MS_U32)(MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_getNR_Status) ));
             }
           else
             {
               PreNR_status=NR_status;
        #if (ENABLE_PIP)
            if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
        #endif
            {
               msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_INTERNAL_1_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
            }
               printf("NRenable=%d\n",(MS_U32)(MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_getNR_Status) ));
             }
         }

    }
   #endif

    if ( previous_status[eWindow] != current_status )
    {
        previous_status[eWindow] = current_status;
    }
}


//Ray DMP 2017.04.07: Routine to enter into DMP. It is called when there is no sync found in input source
//Output: PASS = detect USB drive and enter into DMP, or already failed to detect USB drive for 4 times
//        FAIL = Cannot detect USB drive for first 4 times
BOOLEAN MApp_NoSignal_EnterDMP(void)
{
  U8 u8PortEnStatus = 0;
  U8 u8ConnectResult = 0;
  u8PortEnStatus = MDrv_USBGetPortEnableStatus();

  //Ray DMP 2017.04.11: If USB 1 is enable, check USB 1 first
    if((u8PortEnStatus & BIT0) == BIT0){
	u8ConnectResult = MDrv_UsbDeviceConnect();
    }
    //If USB 1 is not connected, then check USB 2 if it's enabled and connected
    if(u8ConnectResult==0 &&((u8PortEnStatus & BIT1) == BIT1)){
 	u8ConnectResult = MDrv_UsbDeviceConnect_Port2();
     }



    if (u8ConnectResult)
    {
	//Ray DMP 2017.04.07: Enter into DMP only if media file exists in USB (ucUSBNoMediaFile= 0)
	if(ucUSBNoMediaFile == 0)
	{
	  USBConnectCheckF=0;			//Ray DMP 2017.04.07: Clear checking after success detect USB

	  if(sSaveSleepForPM)			//Ray DMP 2017.04.07: If it is in sleep mode, clear sleep mode flag
	     {
          	sSaveSleepForPM = 0;
	     }
	  MApp_SimplePowerSaving(0);				//meathew 03032017	wake up
	  MApp_Sleep_ReleaseSleepTimer();			//meathew 03032017
	  //printf("\nRay: MApp_NoSignal_EnterDMP");		//Ray DBG 2017.04.10
	  //SetDmpPrePlayingMediaType(E_MPLAYER_TYPE_MOVIE);		//Ray DMP 2017.04.07: Not found this routine in SP-4096 code //meathew 01032017
	  MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_DMP); 	//Ray DMP 2017.04.07: Switch to DMP source
	  MApp_ZUI_ACT_ShutdownOSD();
	  MApp_ZUI_ACT_StartupOSD(E_OSD_DMP);
	  MApp_TopStateMachine_SetTopState(STATE_TOP_DMP);
	}
	return PASS;
    }
    else
    {
	USBConnectCheckF++;		//Denote fail to detect USB for 1 more time
	ucUSBNoMediaFile = 0;		//As no USB detect, we clear USB no media file status
	printf("Ray: rrrrrrrrrrrrrrrrrrrrrrrrrrrrrr USBConnectCheckF, 0x%d\r\n", USBConnectCheckF);
	//If fail to detect USB drive for 4 time
	if(USBConnectCheckF>=4){
	  printf("Ray: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx USBConnectCheckF, 0x%d\r\n", USBConnectCheckF);
	  USBConnectCheckF=0;
	  return PASS;
	}

    }
    return FAIL;
}


void MApp_PCMode_Reset( SCALER_WIN eWindow)
{
    PCMODE_INFO[eWindow].eCurrentState = E_PCMODE_NOSYNC;
    PCMODE_INFO[eWindow].eModeParseResult = XC_MODEPARSE_NOT_PARSED;
    memset(&(PCMODE_INFO[eWindow].sModeParseInputInfo), 0, sizeof(XC_MODEPARSE_INPUT_INFO));
#if ENABLE_3D_PROCESS
    if(eWindow == MAIN_WINDOW)
    {
        g_HdmiInput3DFormat = E_XC_3D_INPUT_MODE_NONE;
        g_HdmiInput3DFormatStatus = E_XC_3D_INPUT_MODE_NONE;
    }
#endif

#if (ENABLE_HDMI_4K_2K)
   if(g_HdmiInput4Kx2KFormat)
   {
    #if (SUPPORT_4K_TO_2K_CONVERT)
    _MApp_PCMode_SetHdmiAvgMode(FALSE);
    #endif

     g_HdmiInput4Kx2KFormat= FALSE;

     #if ENABLE_6M40_4KX2K_PROCESS
        HDMI_4KX2K_MSG(printf(" Reset change to 1080p60 timing  \r\n"));
        g_PNL_TypeSel = PNL_FULLHD_CMO216_H1L01;
        msAPI_Scaler_ChangePanelType(g_PNL_TypeSel,MAIN_WINDOW);
        MDrv_Ursa_6M40_Set4K2KType(E_URSA_4K2K_MODE_FULLHD);
        MApi_SC_ForceFreerun(DISABLE);
     #endif
   }
#endif

}

static void _MApp_HDMI_ModeSetting(INPUT_SOURCE_TYPE_t src, SCALER_WIN eWindow)
{
    U8 u8TurnOffDestination = ENABLE;

    {
        //printf("Do HDMI Mode setting\n");
        if(MApi_XC_HDMI_Monitor(src))
        {
            DEBUG_HDMI_FLOW( printf(" MApi_XC_HDMI_Monitor() => True \n"); );

        #if 0// (ENABLE_HDMI_AR_CHECK)
            PRINT_CURRENT_LINE();
            printf("enPKT_Status.AspectRatio=%u\n", g_HdmiPacketInfo.enPKT_Status.AspectRatio);
            g_HdmiPollingStatus.u8AspectRatio = g_HdmiPacketInfo.enPKT_Status.AspectRatio;
            MApp_Scaler_Setting_HDMI_PAR();
        #endif

            if(stSystemInfo[eWindow].u8PanelPowerStatus & PANEL_POWER_BLUESCREEN)
            {
                // un-mute video
              #if (ENABLE_HDMI_4K_2K&&ENABLE_6M40_4KX2K_PROCESS)
                if ( g_HdmiInput4Kx2KFormat)
                {
                    u8TurnOffDestination = DISABLE;
                }
                else
              #endif
                {
                    u8TurnOffDestination = ENABLE;
                }

                MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

              #if (ENABLE_PIP)
                if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
              #endif
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
            }

            if(g_HdmiPollingStatus.bMuteHDMIVideo)
            {
                // Why do av_mute here, MApi_XC_HDMI_Monitor() already do it??
                PRINT_CURRENT_LINE();
                printf("[HDMI] mute video = 0\n");

                g_HdmiPollingStatus.bMuteHDMIVideo = 0;

            #if (ENABLE_PIP)
                if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
            #endif
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYSYNC_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }

                msAPI_Scaler_SetScreenMute(E_SCREEN_MUTE_TEMPORARY, ENABLE, DELAY_FOR_REMOVE_SCREENMUTE, eWindow);

                u8TurnOffDestination = DISABLE;
                MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

                MApp_UI_NotifySysEvent(E_SYS_EVENT_HDMI_AVMUTE_1_TO_0, NULL);
            }

            if( g_HdmiPollingStatus.bColorFMTChange )
            {
                printf("[HDMI] Color change detected\n");

                // Turn off window
                u8TurnOffDestination = DISABLE;
                MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

            #if HDMI_COLOR_CHANGE_NO_MODE_CHANGE
                // Reload setting...
                // Set window&Timing
                MApi_XC_Mux_TriggerPathSyncEvent(src, NULL);

                // Turn On window(Reload color setting)
                u8TurnOffDestination = ENABLE;
                MApi_XC_Mux_TriggerDestOnOffEvent(src,&u8TurnOffDestination);

            #else
                // Restart timing monitor...

                // HDMI/DVI mode change, restart timing monitor
                MApi_XC_PCMonitor_Restart(eWindow);

                // reset HDMI variables
                MApi_XC_HDMI_Handler_Init();

            #endif

                g_HdmiPollingStatus.bColorFMTChange = 0;
            }

        }
        else
        {
            DEBUG_HDMI_FLOW( printf(" MApi_XC_HDMI_Monitor() => False \n"); );
        }

    #if( ENABLE_HDMI_AR_CHECK )
        if(MApi_XC_HDMI_GetHdmiType(src) == E_HDMI_STATUS_HDMI)
        {
            if( g_HdmiPollingStatus.u8AspectRatio != g_HdmiPacketInfo.enPKT_Status.AspectRatio )
            {
                printf("[HDMI] AR change: 0x%X, 0x%X\n", g_HdmiPollingStatus.u8AspectRatio, g_HdmiPacketInfo.enPKT_Status.AspectRatio);

                g_HdmiPollingStatus.u8AspectRatio = g_HdmiPacketInfo.enPKT_Status.AspectRatio;
                MApp_Scaler_Setting_HDMI_PAR();
            }
        }
    #endif

        u8HDMIchkflag = 1;

        // HDMI Audio PCM/non-PCM checking and setting
      #if (ENABLE_PIP)
        if( (MApp_Get_PIPMode() == EN_PIP_MODE_OFF) || UI_IS_AUDIO_SOURCE_IN(eWindow) )
      #endif
        {
            MApp_Audio_HDMI_MODE_CONFIG(g_HdmiPollingStatus, &g_HdmiPacketInfo);
        }
    }

    //printf("call mdrv_dvi_reset()\n");
    mdrv_dvi_reset();
}

void MAPP_PCMode_PIP_ChangeAudioSource2HDMI(SCALER_WIN eWindow)
{
    if( (MApp_PCMode_GetCurrentState(eWindow)==E_PCMODE_STABLE_SUPPORT_MODE) )
    {
        MApp_Audio_HDMI_MODE_CONFIG(g_HdmiPollingStatus, &g_HdmiPacketInfo);
    }
}

MS_U8 MApp_PCMode_Get_Mode_Idx(SCALER_WIN eWindow)
{
    if((PCMODE_INFO[eWindow].eCurrentState == E_PCMODE_UNSTABLE) || (PCMODE_INFO[eWindow].eCurrentState == E_PCMODE_NOSYNC))
    {
        return 0;
    }
    else
    {
        return PCMODE_INFO[eWindow].sModeParseInputInfo.u8ModeIndex;
    }
}

MS_U16 MApp_PCMode_Get_HResolution(SCALER_WIN eWindow,MS_BOOL IsYpbprOrVga)
{
#if (ENABLE_HDMI_4K_2K && SUPPORT_4K_TO_2K_CONVERT)
	const U8 u8DOUBLE = 2 ;
#endif

    if( (PCMODE_INFO[eWindow].eCurrentState == E_PCMODE_UNSTABLE) || (PCMODE_INFO[eWindow].eCurrentState == E_PCMODE_NOSYNC))
    {
        return 0;
    }
    else
    {
        if(IsYpbprOrVga)
        {
            // VGA/YPbPr
            return (PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResWidth);
        }
        else
        {
	        #if (ENABLE_HDMI_4K_2K && SUPPORT_4K_TO_2K_CONVERT)
	          if(MApp_PCMode_GetCurrentHdmiAvgMode())
	            {
	                return (PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.width)*u8DOUBLE;
	            }
	            else
	            {
	                return PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.width;
	            }
			#else
				 return PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.width;

			#endif
        }
    }
}

MS_U16 MApp_PCMode_Get_VResolution(SCALER_WIN eWindow,MS_BOOL IsYpbprOrVga)
{
    if((PCMODE_INFO[eWindow].eCurrentState == E_PCMODE_UNSTABLE) || (PCMODE_INFO[eWindow].eCurrentState == E_PCMODE_NOSYNC))
    {
        return 0;
    }
    else
    {
        if(IsYpbprOrVga)
        {
            // VGA/YPbPr
            return PCMODE_INFO[eWindow].sModeParseInputInfo.u16ResHeight;
        }
        else
        {
            return PCMODE_INFO[eWindow].sModeParseInputInfo.sDVI_HDMI_DE_Info.height;
        }
    }
}

PCMODE_SyncStatus MApp_PCMode_GetCurrentState(SCALER_WIN eWindow)
{
    if( eWindow >= MAX_WINDOW )
        return E_PCMODE_UNSTABLE;

    return PCMODE_INFO[eWindow].eCurrentState;
}

void MApp_PCMode_SaveModeRamSetting(SCALER_WIN eWindow)
{
    U8 u8ModeIndex;

    if(g_u8PcUserModeRamIndex[eWindow] == 0xFF)
        u8ModeIndex = g_PcadcModeSetting[eWindow].u8ModeIndex;   //standard
    else
        u8ModeIndex = g_u8PcUserModeRamIndex[eWindow];   //user

    PCMSG(printf("MApp_PCMode_SaveModeRamSetting %bu\n", u8ModeIndex));

    //g_PcadcModeSetting.u8AutoSign = TRUE;
    MApp_DB_SaveModeSetting(eWindow, u8ModeIndex);
}

void MApp_PCMode_LoadModeData(SCALER_WIN eWindow, U8 u8ModeIndex, BOOLEAN bIsNewMode)
{
    if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(eWindow))||IsSrcTypeYPbPr(SYS_INPUT_SOURCE_TYPE(eWindow)))
    {
        if(bIsNewMode && IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(eWindow))) //user new mode
        {
            g_u8PcUserModeRamIndex[eWindow] = _MApp_PCMode_CheckModeRamAddr(eWindow, u8ModeIndex);
            PCMSG(printf("g_u8PcUserModeRamIndex %bu\n", g_u8PcUserModeRamIndex[eWindow]));
        }
        else    //standard mode
        {
            g_u8PcUserModeRamIndex[eWindow] = 0xFF;
            MApp_DB_LoadModeSetting(eWindow, u8ModeIndex);
        }

        _MApp_PCMode_Verify_ModeTable_Valid(eWindow, u8ModeIndex);
    }
    else
    {
        MApp_DB_LoadDefaultTable(eWindow, u8ModeIndex);
    }

    PCMSG(printf("MApp_PCMode_LoadModeData \r\n"));
    PCMSG(printf("Mode Index = %bd \r\n",g_PcadcModeSetting[eWindow].u8ModeIndex));
    PCMSG(printf("Mode HStart = %d \r\n",g_PcadcModeSetting[eWindow].u16HorizontalStart));
    PCMSG(printf("Mode VStart = %d \r\n",g_PcadcModeSetting[eWindow].u16VerticalStart));
    PCMSG(printf("Mode Htotal = %d \r\n",g_PcadcModeSetting[eWindow].u16HorizontalTotal));
    PCMSG(printf("Mode Phase =  %d \r\n",g_PcadcModeSetting[eWindow].u16Phase));

    PCMSG(printf("u16DefaultHStart =  %d \r\n",g_PcadcModeSetting[eWindow].u16DefaultHStart));
    PCMSG(printf("u16DefaultVStart =  %d \r\n",g_PcadcModeSetting[eWindow].u16DefaultVStart));

    PCMSG(printf("Mode H Size = %d \r\n",MApp_PCMode_Get_HResolution(eWindow,TRUE)));
    PCMSG(printf("Mode V Size = %d \r\n",MApp_PCMode_Get_VResolution(eWindow,TRUE)));
    PCMSG(printf("Mode u8AutoSign = %bu \r\n",g_PcadcModeSetting[eWindow].u8AutoSign));
}

BOOLEAN MApp_PCMode_Enable_SelfAuto(BOOLEAN EnableAuto, SCALER_WIN eWindow)
{
    if(!MApi_XC_PCMonitor_SyncLoss(eWindow))
    {
        Enable_SelfAuto[eWindow] = EnableAuto;
        return TRUE;
    }

    Enable_SelfAuto[eWindow] = DISABLE;

    return FALSE;
}

////////////////////////////////////////////
// Analog Handler (RGB / Component / HDMI)
////////////////////////////////////////////
static void _MApp_PC_Hdmi_Monitor(INPUT_SOURCE_TYPE_t src, SCALER_WIN eWindow)
{
    static MS_U32 su32LastHdmiMonitorTime = 0;
    static MS_BOOL bIsTimingChanged2Stable = FALSE;

    // check if input source type is HDMI
    if(!IsSrcTypeHDMI(src))
    {
        //printf("HDMI_Monitor: return not HDMI\n");
        return;
    }

    // check if init HDMI variables
    if(MApp_PCMode_GetCurrentState(eWindow) != E_PCMODE_STABLE_SUPPORT_MODE)
    {
        if(bIsTimingChanged2Stable)
        {
            // reset HDMI variables because changed from stable_support to other mode
            bIsTimingChanged2Stable = FALSE;
            if(MApi_XC_HDMI_Func_Caps() & CAPS_VSYNC_END_EN)
            {
                MApi_XC_HDCP_Vsync_end_en(FALSE);
            }
        }

        //printf("HDMI_Monitor: return not stb_support\n");
        return;
    }
    else
    {
        if(!bIsTimingChanged2Stable)
        {
            // 1st time changed to stable_support
            bIsTimingChanged2Stable = TRUE;
            if(MApi_XC_HDMI_Func_Caps() & CAPS_VSYNC_END_EN)
            {
                MApi_XC_HDCP_Vsync_end_en(TRUE);
            }
        }
    }

    if(msAPI_Timer_GetTime0() > (su32LastHdmiMonitorTime + HDMI_POLLING_COUNTER))
    {
        su32LastHdmiMonitorTime = msAPI_Timer_GetTime0();

        if(MApi_XC_HDMI_CheckModeChanged(FALSE, eWindow))
        {
            printf("[HDMI Monitor] Mode changed\n");

            // HDMI/DVI mode change, restart timing monitor
            MApi_XC_PCMonitor_Restart(eWindow);

            // reset HDMI variables
            MApi_XC_HDMI_Handler_Init();

            //printf("HDMI_Monitor: return mode chg\n");
            return;
        }
        else
        {
            // execute HDMI monitor
            {
                _MApp_HDMI_ModeSetting(src, eWindow);
            }
        }
    }
    else
    {
        // no need to execute HDMI monitor
        //printf("HDMI_Monitor: return no need to execute, OS_Time=%d, last=%d\n", msAPI_Timer_GetTime0(), su32LastHdmiMonitorTime);
        return;
    }
}

void MApp_PC_MainWin_Handler(INPUT_SOURCE_TYPE_t src, BOOLEAN bRealTimeMonitorOnly)
{
    static U32 _s_PC_MainWin_Handler_u32LastTime = 0;
    U32 u32CurTime;


    u32CurTime = MsOS_GetSystemTime();
    //printf(" t=%u,", u32CurTime);
    if( msAPI_Timer_DiffTime_2(_s_PC_MainWin_Handler_u32LastTime, u32CurTime) < PC_MODE_TIMING_MONITOR_PERIOD )
    {
        return;
    }

    _s_PC_MainWin_Handler_u32LastTime = u32CurTime;
    //printf(" t=%u,", u32CurTime);

    UNUSED(bRealTimeMonitorOnly);

#if (INPUT_HDMI_VIDEO_COUNT > 0)
  #if ( ENABLE_HDMI_HPD_TASK )
    if( IsSrcTypeHDMI(src) )
    {
        if( MApi_XC_HPD_Is_Task_Working() )
        {
            //MApi_XC_HPD_Task(FALSE);
            return;
        }
    }
  #endif

    if(MApi_XC_HDMI_Func_Caps() & CAPS_DVI_ADJ_70M)
    {
    #ifndef DVI_NEW_Patch // mark the original DVI 70 MHz patch
        if (IsSrcTypeHDMI(src))
            MApi_XC_HDMI_CheckAndAdjustDVI(src);
    #endif
    }
#endif

#if (INPUT_SCART_VIDEO_COUNT > 0)
    MApp_InputSource_ScartIOMonitor();
#endif

    // timing stable, either with sync or without sync, mode parse finished
    _MApp_PCMode_StatusHandler(src, MApi_XC_PCMonitor(src, MAIN_WINDOW) ,MAIN_WINDOW);

    MApp_PCMode_RunSelfAuto(MAIN_WINDOW);

    _MApp_PC_Hdmi_Monitor(src, MAIN_WINDOW);

}

#if (ENABLE_PIP)
void MApp_PC_SubWin_Handler(INPUT_SOURCE_TYPE_t src, BOOLEAN bRealTimeMonitorOnly)
{
    static U32 _s_PC_SubWin_Handler_u32LastTime = 0;
    U32 u32CurTime;


    u32CurTime = MsOS_GetSystemTime();

    if( msAPI_Timer_DiffTime_2(_s_PC_SubWin_Handler_u32LastTime, u32CurTime) < PC_MODE_TIMING_MONITOR_PERIOD )
    {
        return;
    }

    _s_PC_SubWin_Handler_u32LastTime = u32CurTime;
    //printf(" t=%u,", u32CurTime);

    UNUSED(bRealTimeMonitorOnly);

#if (INPUT_HDMI_VIDEO_COUNT > 0)
    if(MApi_XC_HDMI_Func_Caps() & CAPS_DVI_ADJ_70M)
    {
    #ifndef DVI_NEW_Patch // mark the original DVI 70 MHz patch
        if (IsSrcTypeHDMI(src))
            MApi_XC_HDMI_CheckAndAdjustDVI(src);
    #endif
    }
#endif

    if(IsPIPSupported())
    {
        // timing stable, either with sync or without sync, mode parse finished
        _MApp_PCMode_StatusHandler(src, MApi_XC_PCMonitor(src, SUB_WINDOW) ,SUB_WINDOW);
        _MApp_PC_Hdmi_Monitor(src, SUB_WINDOW);
        MApp_PCMode_RunSelfAuto(SUB_WINDOW);
    }
}
#endif

BOOLEAN MApp_ADC_HW_SaveGainOffset(void)
{
    BOOLEAN bRet = TRUE;
#if (ENABLE_HW_INTERNAL_ADC_CALIBRATION)
    MS_ADC_SETTING stAdcSetting;
    memset(&stAdcSetting, 0, sizeof(MS_ADC_SETTING));

    if ( (E_XC_HW_CALIBRATION == (XC_Auto_CalibrationMode)GENSET_ADC[ADC_SET_VGA].u8CalibrationMode)
      && MApi_XC_Auto_SetCalibrationMode((XC_Auto_CalibrationMode)GENSET_ADC[ADC_SET_VGA].u8CalibrationMode))
    {
        MApp_RGB_Setting_Auto(E_XC_INTERNAL_CALIBRATION, MAIN_WINDOW);
    }
    else
    {
        GENSET_ADC[ADC_SET_VGA].u8CalibrationMode = E_XC_SW_CALIBRATION;
        MApp_SaveADCSetting(ADC_SET_VGA);
        bRet = FALSE;
    }

    if ( (E_XC_HW_CALIBRATION == (XC_Auto_CalibrationMode)GENSET_ADC[ADC_SET_YPBPR_HD].u8CalibrationMode)
      && MApi_XC_Auto_SetCalibrationMode((XC_Auto_CalibrationMode)GENSET_ADC[ADC_SET_YPBPR_HD].u8CalibrationMode))
    {
        MApp_YPbPr_Setting_Auto(E_XC_INTERNAL_CALIBRATION, MAIN_WINDOW);
    }
    else
    {
        GENSET_ADC[ADC_SET_YPBPR_HD].u8CalibrationMode = E_XC_SW_CALIBRATION;
        MApp_SaveADCSetting(ADC_SET_YPBPR_HD);
        bRet = FALSE;
    }

    if ( (E_XC_HW_CALIBRATION == (XC_Auto_CalibrationMode)GENSET_ADC[ADC_SET_YPBPR_SD].u8CalibrationMode)
      && MApi_XC_Auto_SetCalibrationMode((XC_Auto_CalibrationMode)GENSET_ADC[ADC_SET_YPBPR_SD].u8CalibrationMode))
    {
        MApp_YPbPr_Setting_Auto(E_XC_INTERNAL_CALIBRATION, MAIN_WINDOW);
    }
    else
    {
        GENSET_ADC[ADC_SET_YPBPR_SD].u8CalibrationMode = E_XC_SW_CALIBRATION;
        MApp_SaveADCSetting(ADC_SET_YPBPR_SD);
        bRet = FALSE;
    }
#endif
    return bRet;
}

BOOLEAN MApp_PCMode_GetCurrentHdmiAvgMode(void)
{
    return s_bIsHdmiAvgMode;
}

void _MApp_PCMode_SetHdmiAvgMode(BOOLEAN bEnable)
{
    //printf("_MApp_PCMode_SetHdmiAvgMode(%u)\n", bEnable);
    s_bIsHdmiAvgMode = bEnable;
    MDrv_HDMI_AVG_ScaleringDown(bEnable);
}

#undef MAPP_PCMODE_C
