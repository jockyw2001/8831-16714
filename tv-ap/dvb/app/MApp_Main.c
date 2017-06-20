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
// (��MStar Confidential Information��) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_MAIN_C

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "Board.h"
#include "datatype.h"

// Common Definition
#include "MsCommon.h"
#include "MsIRQ.h"
#include "MsOS.h"
#include "debug.h"
#include "apiXC.h"
#include "MsTypes.h"
#include "drvBDMA.h"
#include "drvUART.h"
#include "drvUartDebug.h"
#include "msAPI_MIU.h"
#include "msAPI_DrvInit.h"
#include "msAPI_Memory.h"
#include "msAPI_Timer.h"
#include "MApp_MultiTasks.h"
#include "MApp_Main.h"
#include "MApp_Init.h"
#include "MApp_TopStateMachine.h"
#include "MApp_TV.h"
#include "MApp_Scan.h"
#include "GPIO_macro.h"
#include "MApp_Standby.h"		//Ray DPW 2017.05.29: For access global variable sFlagSimPowerShutDown

#if (ENABLE_SECURITY_R2)
#include "msAPI_SecurityR2.h"
#endif





#if ENABLE_SBTVD_BRAZIL_CM_APP
#include "msAPI_ChProc.h"
#include "msAPI_ATVSystem.h"
#endif

#ifdef MSOS_TYPE_LINUX
#include <unistd.h>
#include <string.h>
#include "madp.h"
#include "debug.h"
#include "MApp_APEngine.h"
#endif

#if ENABLE_ATSC_TTS
#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_ACTglobal.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_GlobalFunction.h"
#include "OSDcp_String_EnumIndex.h"
#include "MApp_TTSControlHandler.h"
#endif
#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
#include "MApp_UiMenuFunc_ATSC.h"
#endif

#if ENABLE_AUTOTEST
extern BOOLEAN g_bAutobuildDebug;
#endif

//------------------------------------------------------------------------------
// Locals
//------------------------------------------------------------------------------

#ifdef ENABLE_MINI_DUMP
extern void   MiniDump_MountDrive(void);
#endif

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

void MApp_Power_On_Load_App(void)
{
#ifdef ENABLE_LOAD_APP_FROM_USB
    static BOOLEAN flag = FALSE;

    if((g_bDebugProgStopFlag)&&(flag==FALSE))
    {
        U8 name[]="APP.BIN";

        extern BOOLEAN LoadAppbyFileNameFromUSB(U8 *fn);

        flag = LoadAppbyFileNameFromUSB(name);

        MsOS_DelayTask( 5000 );
    }
#endif
}

void MApp_Power_On_Post_Init(void)
{
#if 0//(ENABLE_POST_INIT)
    MApp_PostInit();
#endif
}

void MApp_Power_On_Mini_Dump(void)
{
#ifdef ENABLE_MINI_DUMP
    if(!IsStorageInUse())
    {
        MiniDump_MountDrive();
    }
#endif
}

void MApp_Power_On_System_Polling(void)
{

}

/***************************************************************************************/

#define UART_DEBUG_STOP_MAIN_LOOP   TRUE
#define UART_DEBUG_NORMAL_MAIN_LOOP FALSE

MS_BOOL MApp_PowerOn_Stage_Debug(void)
{
#if (ENABLE_MSTV_UART_DEBUG)
    if ( msAPI_UART_DecodeCommand() )
    {
    #if ( !CHANNEL_SCAN_AUTO_TEST )

      #if ( WATCH_DOG == ENABLE )
        msAPI_Timer_ResetWDT();
      #endif

        return UART_DEBUG_STOP_MAIN_LOOP; // stop main loop for debug

    #endif
    }

    if ( g_bDebugProgStopFlag )
    {
    #if ( WATCH_DOG == ENABLE )
        msAPI_Timer_ResetWDT();
    #endif

        return UART_DEBUG_STOP_MAIN_LOOP;
    }
#endif

    return UART_DEBUG_NORMAL_MAIN_LOOP;
}

/***************************************************************************************/

#define MAIN_FUNC_STATE_DBG(x)      //x


En_MSTAR_MAIN_FUNCTION_STAGE enPower_ON_Stage;
En_MSTAR_MAIN_FUNCTION_STAGE enPrePower_ON_Stage;

En_PRE_INIT_SUB_STATE   enPreInit_Sub_State;
En_WHILE_LOOP_SUB_STATE enWhileLoop_Sub_State;

/***************************************************************************************/

#define PRE_INIT_ONGOING    TRUE
#define PRE_INIT_DONE       FALSE

#ifdef BENCH_CODE_USAGE

#if (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)

#define BENCH_CHIP          (char*)"MILAN"
#define BENCH_BOOTSTATUS    (char*)"BOOT_PASS"
#define BENCH_VERSION       (char*)"V03" //DDR2 Etron U03 setting
#if (MS_BOARD_TYPE_SEL == BD_MST214A_D01A_S_MILAN)
#define BENCH_BOARD         (char*)"214A"
#elif (MS_BOARD_TYPE_SEL == BD_MST214B_D01A_S_MILAN)
#define BENCH_BOARD         (char*)"214B"
#elif (MS_BOARD_TYPE_SEL == BD_MST214C_D01A_S_MILAN)
#define BENCH_BOARD         (char*)"214C"
#elif (MS_BOARD_TYPE_SEL == BD_MST214D_D01A_S_MILAN)
#define BENCH_BOARD         (char*)"214D"
#elif (MS_BOARD_TYPE_SEL == BD_MST074B_10AGS)
#define BENCH_BOARD         (char*)"074B"
#elif (MS_BOARD_TYPE_SEL == BD_MST073B_10AGS)
#define BENCH_BOARD         (char*)"073B"
#else
#error "Please select board type"
#endif

#else
#define BENCH_CHIP          (char*)"CHIP"
#define BENCH_BOOTSTATUS    (char*)"BOOTSTATUS"
#define BENCH_VERSION       (char*)"VERSION"
#define BENCH_BOARD         (char*)"BOARD"
#endif

void MApp_Bench_PowerOffLED(void)
{
  #if (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)
    #if (MS_BOARD_TYPE_SEL == BD_MST214A_D01A_S_MILAN) || (MS_BOARD_TYPE_SEL == BD_MST074B_10AGS)
    mdrv_gpio_set_low(PAD_TCON0);
    #else
    mdrv_gpio_set_low(PAD_GPIO2);
    #endif
  #endif
  //printf("\n[BENCH][%s][%s] %s_%s\n",BENCH_CHIP,BENCH_BOARD,BENCH_BOOTSTATUS,BENCH_VERSION);
}
#endif

MS_BOOL MApp_PreInit_State(void)
{
    MS_BOOL bPreInitDone = PRE_INIT_ONGOING;
    U32 u32Time_StateStart = MsOS_GetSystemTime();
    U32 u32Time_StateEnd;
    U32 u32StateUseTime;

    if (MApp_PowerOn_Stage_Debug() == UART_DEBUG_STOP_MAIN_LOOP)
    {
        return PRE_INIT_ONGOING;
    }

    MAIN_FUNC_STATE_DBG(printf(" [MApp_PreInit_State %u] start at %u ms\n", enPreInit_Sub_State, u32Time_StateStart));

    switch ( enPreInit_Sub_State )
    {
        case EN_PRE_INIT_INITIATION:
            break;

        case EN_PRE_INIT_STAGE_AUTOTEST_INIT:
            MApp_PreInit_Autotest_Init();
            break;

        case EN_PRE_INIT_STAGE_GLOBALVAR_INIT:
            MApp_PreInit_GlobalVariable_Init();
            break;

        case EN_PRE_INIT_STAGE_POWERSETTING_INIT:
            MApp_PreInit_PowerSettingVariable_Init();
            break;

        case EN_PRE_INIT_STAGE_FLASHVAR_INIT:
            MApp_PreInit_FlashVariable_Init();
            break;

        case EN_PRE_INIT_STAGE_CHIP_INIT:
            MApp_PreInit_Chip_Init();
            break;

        case EN_PRE_INIT_STAGE_AUDIO_INIT:
            MApp_PreInit_Audio();
            break;

        case EN_PRE_INIT_STAGE_CUSTOMER_INFO_INIT:
            MApp_PreInit_CustomerInfo();
            break;

        case EN_PRE_INIT_STAGE_PANEL_SETINVERTER_INIT:
            MApp_PreInit_Panel_SetInverter();
            break;

        case EN_PRE_INIT_STAGE_READ_DDRPHASE_INIT:
            MApp_PreInit_ReadDDRPhase();
            break;

        case EN_PRE_INIT_STAGE_DRIVER_STEP1_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start driver init");
            MApp_PreInit_Driver_Step1_Init();
            break;

        case EN_PRE_INIT_STAGE_INTERRUPT_INIT:
            MApp_PreInit_Interrupt_Init();
            break;

        case EN_PRE_INIT_STAGE_DATABASE_INIT:
            MApp_PreInit_DateBase_Init();
            break;

        case EN_PRE_INIT_STAGE_ATVPROC_AUDIO_INIT:
        //Reduce power-on music playing time.
            PRINT_AUTOTEST_CHECKPT_TIME("start ATVProc_Init_Audio");
            MApp_PreInit_ATVProc_Audio_Init();
            PRINT_AUTOTEST_CHECKPT_TIME("start AUD_Setting");
            MApp_PreInit_Audio_Setting_Init();
            break;

        case EN_PRE_INIT_STAGE_FONT_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start FontInit");
            MApp_PreInit_Font_Init();
            break;

        case EN_PRE_INIT_STAGE_DRIVER_STEP2_INIT:
            MApp_PreInit_Driver_Step2_Init();
            break;

        case EN_PRE_INIT_STAGE_ENABLESKIP3D_LRFLAG_SETHWLVDS_LRFLAG_INIT:
            MApp_PreInit_EnableSkip3D_LRFlag_SetHWLVDS_LRFlag();
            break;

        case EN_PRE_INIT_STAGE_DNR_MEMORY_INIT:
            MApp_PreInit_DNR_Memory_Init();
            break;

        case EN_PRE_INIT_STAGE_SYSTEM_INIT:
            MApp_PreInit_System_Init();
            break;

        case EN_PRE_INIT_STAGE_PANEL_ENABLE_INIT:
            MApp_PreInit_Panel_Enable();
            break;

        case EN_PRE_INIT_STAGE_ENABLE_DCC_DDC2BI_INIT:
            MApp_PreInit_EnableDCC_DDC2BI_Init();
            break;

        case EN_PRE_INIT_STAGE_DATABASE_CHECKING_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start DB Check");
            MApp_PreInit_DataBase_Checking();
            MApp_PreInit_Check_Sel_Dn_Reset();			//Ray LDF 2017.06.15: Check if SEL DN down pressed and do reset
            break;

        case EN_PRE_INIT_STAGE_SSC_SETTING_INIT:
            MApp_PreInit_SSC_Setting_Init();
            break;

        case EN_PRE_INIT_STAGE_TTX_INIT:
            MApp_PreInit_TTX_Init();
            break;

        case EN_PRE_INIT_STAGE_IMAGE_SETMIRROR_INIT:
            MApp_PreInit_Image_SetMirror();
            break;

        case EN_PRE_INIT_STAGE_UI_INPUTSOURCE_INIT:
            MApp_PreInit_UI_InputSource_Init();
            break;

        case EN_PRE_INIT_STAGE_FLAG_INIT:
            MApp_PreInit_Flag_Init();
            break;

        case EN_PRE_INIT_STAGE_CI_INIT:
            MApp_PreInit_CI_Init();
            break;

        case EN_PRE_INIT_STAGE_HDMISWITCH_PS321_INIT:
            MApp_PreInit_HDMISwitch_PS321_Init();
            break;

        case EN_PRE_INIT_STAGE_TUNER_DEMOD_INIT:
            MApp_PreInit_Tuner_And_Demod_Init();
            break;

        case EN_PRE_INIT_STAGE_TIME_SETTING_INIT:
            MApp_PreInit_Time_Setting_Init();
            break;

        case EN_PRE_INIT_STAGE_EPGTIMER_DATA_INIT:
            MApp_PreInit_EPGTimer_Data_Init();
            break;

        case EN_PRE_INIT_STAGE_CHECKONTIMER_INIT:
            MApp_PreInit_CheckOnTimer_Init();
            break;

        case EN_PRE_INIT_STAGE_LOGO_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start Logo");
            MApp_PreInit_Logo_Init();
            break;

        case EN_PRE_INIT_STAGE_ATVPROC_OTHERS_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start ATVProc_Init_Others");
            MApp_PreInit_ATVProc_Others_Init();
            break;

        case EN_PRE_INIT_STAGE_OCP_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start OCP_Init");
            MApp_PreInit_OCP_Init();
            break;

        case EN_PRE_INIT_STAGE_ENVIRONMENT_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start env init");
            MApp_PreInit_Environment_Init();
            break;

        case EN_PRE_INIT_STAGE_DISPLAY_STEP1_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start display step 1 init");
            MApp_PreInit_Display_Step1_Init();
            break;

        case EN_PRE_INIT_STAGE_SORCE_CHANGE_INIT:
            MApp_PreInit_Source_Change_Init();
            break;

        case EN_PRE_INIT_STAGE_DISPLAY_STEP2_INIT:
            PRINT_AUTOTEST_CHECKPT_TIME("start display step 2 init");
            MApp_PreInit_Display_Step2_Init();
            break;

        case EN_PRE_INIT_STAGE_OTHERS_INIT:
            MApp_PreInit_Others_Init();
            break;

        case EN_PRE_INIT_STAGE_DONE:
            MAIN_FUNC_STATE_DBG(printf("    Pre Init DONE! \n"));
            bPreInitDone = PRE_INIT_DONE;    // PreInit Done, go to next MAIN FUNCTION State
            break;
    }

    u32Time_StateEnd = MsOS_GetSystemTime();
    u32StateUseTime = msAPI_Timer_DiffTime_2(u32Time_StateStart, u32Time_StateEnd);

    if( u32StateUseTime > 10 )
    {
        MAIN_FUNC_STATE_DBG(printf(" >>>>> state %u end at %u ms, use %u ms\n\n", enPreInit_Sub_State, u32Time_StateEnd, u32StateUseTime););
    }

    enPreInit_Sub_State ++; // go to next Preinit Sub state


  #if( ENABLE_HDMI_HPD_TASK )
	//Back ground task, handle HDMI HPD hi/low control
    if( MApi_XC_HPD_Is_Task_Working() )
    {
        MApi_XC_HPD_Task();
    }

    /*if( (bPreInitDone == PRE_INIT_DONE) && MApi_XC_HPD_Is_Task_Working() )
    {
        printf("HPD task is working!\n");
        bPreInitDone = PRE_INIT_ONGOING;
    }*/
  #endif

    return bPreInitDone;
}

/***************************************************************************************/

void MApp_While_Loop_State(void)
{
    switch (enWhileLoop_Sub_State)
    {
        default:
        {
            //printf("\n !!! Wrong enWhileLoop_Sub_State(%d) \n", enWhileLoop_Sub_State);
            break;
        }

        case EN_WHILE_LOOP_INITIATION:
        {
            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_LOAD_APP:
        {
            MApp_Power_On_Load_App();

            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_POST_INIT:
        {
            MApp_Power_On_Post_Init();

            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_UART_PAUSE:
        {
            if (MApp_PowerOn_Stage_Debug() == UART_DEBUG_STOP_MAIN_LOOP)
            {
                ;   // stay in this "Uart Pause" state
            }
            else
            {
                enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            }
            break;
        }

        case EN_WHILE_LOOP_MULTITASKS:
        {
            MApp_MultiTasks();

            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_TOPSTATEMACHINE:
        {
            MApp_TopStateMachine();

            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_INTERMEDIATE_MINI_DUMP:
        {
            MApp_Power_On_Mini_Dump();

            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_INTERMEDIATE_SYSTEM_POLLING:
        {
            MApp_Power_On_System_Polling();

            enWhileLoop_Sub_State++;  // go to next WHILELOOP Sub state
            break;
        }

        case EN_WHILE_LOOP_IDLE:
        {
            enWhileLoop_Sub_State = EN_WHILE_LOOP_INITIATION;
            break;
        }
    }
}

int main(void) //MingYuan Main Loop
{
    U32 u32MainLoopTime_Last = 0;
    U32 u32MainLoopTime_Cur = 0;

    DEBUG_BOOT_TIME( printf("main() at %u\n", MsOS_GetSystemTime()); );

    enPower_ON_Stage    = EN_MSTAR_MAIN_FUNCTION_POWER_ON_INITIATION;

    enPreInit_Sub_State = EN_PRE_INIT_INITIATION;
    enWhileLoop_Sub_State = EN_WHILE_LOOP_INITIATION;

	  #if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
	  u16TargetBlPwm = 100;
    u16CurrentBlPwm = 99;
    #endif    
    
    while ( 1 )
    {
        enPrePower_ON_Stage = enPower_ON_Stage;

        switch (enPower_ON_Stage)
        {
            default:
            {
                MAIN_FUNC_STATE_DBG(printf("\n !!! Wrong enPower_ON_Stage(%d) \n", enPower_ON_Stage));
                break;
            }

            case EN_MSTAR_MAIN_FUNCTION_POWER_ON_INITIATION:
            {
                MAIN_FUNC_STATE_DBG(printf(" [EN_MSTAR_MAIN_FUNCTION_POWER_ON_INITIATION] at %u\n", MsOS_GetSystemTime()); );

                enPower_ON_Stage++;  // go to next POWER_ON_INIT state
                break;
            }

            case EN_MSTAR_MAIN_FUNCTION_STANDBY2ON:
            {
                MAIN_FUNC_STATE_DBG(printf(" [EN_MSTAR_MAIN_FUNCTION_STANDBY2ON] at %u\n", MsOS_GetSystemTime()); );

                MApp_Power_On_Init_Standby2On();

                enPower_ON_Stage++;  // go to next POWER_ON_INIT state
                break;
            }

            case EN_MSTAR_MAIN_FUNCTION_PRE_INIT:
            {
                if ( MApp_PreInit_State() == PRE_INIT_DONE )
                {
                    MAIN_FUNC_STATE_DBG(printf(" >>>>> Total Pre-Init time use %u ms\n\n", MsOS_GetSystemTime()););
                    enPower_ON_Stage++;  // go to next POWER_ON_INIT state
                }
                else //if ( MApp_PreInit_State() == PRE_INIT_ONGOING )
                {
                    // PreInit not finished yet...
                }

                break;
            }

            case EN_MSTAR_MAIN_FUNCTION_POWERON:
            {
                MAIN_FUNC_STATE_DBG(printf(" [EN_MSTAR_MAIN_FUNCTION_POWERON] at %u\n", MsOS_GetSystemTime()); );

                MApp_Power_On_Init_On();

                #if (ENABLE_SECURITY_R2)
                msAPI_SecurityR2_Start();
                #endif

                enPower_ON_Stage++;  // go to next POWER_ON_INIT state
                break;
            }

            case EN_MSTAR_MAIN_FUNCTION_ENTERING_WHILE_LOOP:
            {
                MAIN_FUNC_STATE_DBG(printf(" [EN_MSTAR_MAIN_FUNCTION_ENTERING_WHILE_LOOP] at %u\n", MsOS_GetSystemTime()));

                //printf("\n===== Enter main loop at %u\n", MsOS_GetSystemTime());
                //printf("\n===== Timestamp %s, %s\n",__DATE__, __TIME__);
    						#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
								if(LightSensor_Init())
								{
									bLightSensorFlag = 1;
								}
								else
								{
									bLightSensorFlag = 0;
								}	    
    						#endif

		//Ray DPW 2017.05.29: If it supply power on, and default power is set as off, we request go to power off state at here
		if(GET_DEFAULT_POWER()== 0){
		    sFlagSimPowerShutDown = ((sFlagSimPowerShutDown&0x01)|0x10);
		    MApp_TopStateMachine_SetTopState(STATE_TOP_STANDBY);
		}

                #ifdef BENCH_CODE_USAGE
                MApp_Bench_AudioTest();
                MApp_Bench_PowerOffLED();
                #endif
                enPower_ON_Stage++;  // go to next POWER_ON_INIT state
#if ENABLE_ATSC_TTS
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_Power), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_Power)));
                MApp_TTSControlSetInputText(MApp_ZUI_API_GetString(en_str_On), MApp_UiMenu_u16Strlen(MApp_ZUI_API_GetString(en_str_On)));
#endif
                break;
            }

            case EN_MSTAR_MAIN_FUNCTION_WHILE_LOOP:
            {
                //MAIN_FUNC_STATE_DBG(printf(" %d: [EN_MSTAR_MAIN_FUNCTION_ENTERING_WHILE_LOOP] \n", __LINE__));

                u32MainLoopTime_Cur = MsOS_GetSystemTime();
                if( msAPI_Timer_DiffTime_2(u32MainLoopTime_Last, u32MainLoopTime_Cur) > 5000 )
                {
                    u32MainLoopTime_Last = u32MainLoopTime_Cur;
                    //printf("t=%u\n", u32MainLoopTime_Cur );
                }

                MApp_While_Loop_State();
                #ifdef sSupportEarPhone
								if(EAR_PHONE_DETECT())
								{
									MApp_Audio_MuteOnOff_ByEarPhone(1);
								}
								else
								{
									MApp_Audio_MuteOnOff_ByEarPhone(0);
								}                
                #endif
		    				#if(SENSOR_CHIP!=NOT_SUPPORT_LIGHT_SENSOR)
		    				if(bLightSensorFlag)
		    				{ 	
        					if(bDetectLS_ADC)
	      				 	{		
	      				 		if(G_FACTORY_SETTING.stFacLightSensorSetting.u8LS_Enable)
	      				 		{
	  	  				   		if(CheckLS_Change(20))
  	  					   		{
  	  					   			u8BklPwmSmoothTime = BKL_SMOOTH_TIME_LS;
  	  					   			Panel_Backlight_PWM_WithLS(u16TargetBlPwm);
    	  				  		}
	    							}	
			  				 	}
		    					if((u8CheckBklStatus)&&(G_FACTORY_SETTING.stFacLightSensorSetting.u8LS_Enable))
		    					{
		    						Panel_Backlight_PWM_WithSmooth();
		    						u8CheckBklStatus = 0;
		    					}
		    				}
		    				#endif                
                break;
            }

        }

    }//main while end

    return 0;
}

BOOL MApp_Main_Is_PowerOnPreInitFinish(void)
{
    if( enPower_ON_Stage > EN_MSTAR_MAIN_FUNCTION_PRE_INIT )
        return TRUE;

    return FALSE;
}

BOOL MApp_Main_Is_PowerOnInitFinish(void)
{
    if( enPower_ON_Stage >= EN_MSTAR_MAIN_FUNCTION_WHILE_LOOP )
        return TRUE;

    return FALSE;
}

#undef MAPP_MAIN_C

