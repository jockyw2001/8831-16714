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
// (“MStar Confidential Information”) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_STANDBY_C

//------------------------------------------------------------------------------
//                            Header Files
//------------------------------------------------------------------------------
#include "hwreg.h"
#include "sysinfo.h"
#include "debug.h"
#include "msAPI_Global.h"
#include "msAPI_Power.h"
#include "apiGOP.h"
#include "MsCommon.h"
#include "MsIRQ.h"
#include "MsOS.h"
#if (EEPROM_DB_STORAGE == EEPROM_SAVE_NONE)
#include "msAPI_MIU.h"
#include "msAPI_Flash.h"
#endif
#include "msAPI_IR.h"
#include "msAPI_Timer.h"
#include "msAPI_Ram.h"
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "apiXC_Sys.h"

#include "Panel.h"
#include "apiPNL.h"

#include "drvXC_HDMI_if.h"
#include "apiXC_Hdmi.h"
#include "MApp_Exit.h"
#include "MApp_Standby.h"
#include "MApp_Key.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_GlobalVar.h"
#include "MApp_SaveData.h"
#include "msAPI_Flash.h"

#include "MApp_DataBase.h"

#if (ENABLE_DTV)
#include "mapp_demux.h"
#endif

#include "MApp_SignalMonitor.h"
#include "MApp_ChannelChange.h"
#include "MApp_Audio.h"
#include "msAPI_audio.h"
#include "MApp_ATVProc.h"

//For Sleep Timer
#include "MApp_Sleep.h"

#include "MApp_ZUI_Main.h"

#include "GPIO.h"

#include "MApp_GlobalFunction.h"
#include "MApp_GlobalSettingSt.h"

#include "MApp_Menu_Main.h"			//Ray DPW 2017.05.31: To access EN_MENU_STATE

#if ENABLE_CI_PLUS
#include "MApp_CIMMI.h"
#endif

#if ENABLE_OAD
#include "MApp_OAD.h"
#endif

#ifdef sUseSimplePowerShutDown
#include "msAPI_Bootloader.h"
#endif			
#define STDBY_DBGINFO(y)    //y

extern void  MApp_ZUI_ACT_SetTargetMenuState(EN_MENU_STATE MenuState);		//Ray DPW 2017.05.31: To access MApp_ZUI_ACT_SetTargetMenuState()function


/********************************************************************************/
/*                               Local                                      */
/********************************************************************************/


/********************************************************************************/
/*                               Functions                                      */
/********************************************************************************/
#if(sPowerDown_Function==sSimple_PowerDownFun)
void MApp_SimplePowerSaving(U8 u8State)
{
	if(u8State==2) //power down
	{
    LED_GRN_Off();
    LED_RED_Off();		
    if ( E_OSD_EMPTY != MApp_ZUI_GetActiveOSD())
    {
      MApp_ZUI_ACT_ShutdownOSD();
    }	
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);        
    MsOS_DelayTask(150);
    Audio_Amplifier_OFF();
    MsOS_DelayTask(150);
		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
		#else    
    MUTE_On();
    #endif
    MApi_PNL_SetBackLight(DISABLE);
    MsOS_DelayTask(300);
    MApi_PNL_En(FALSE);  
    MsOS_DelayTask(300);
	}
	else if(u8State==1) //power saving
	{
    LED_GRN_Off();
    LED_RED_On();		
    if ( E_OSD_EMPTY != MApp_ZUI_GetActiveOSD())
    {
      MApp_ZUI_ACT_ShutdownOSD();
    }	
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);        
    MsOS_DelayTask(150);
    Audio_Amplifier_OFF();
    MsOS_DelayTask(150);
		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
		#else    
    MUTE_On();
    #endif
    MApi_PNL_SetBackLight(DISABLE);
    MsOS_DelayTask(300);
    MApi_PNL_En(FALSE);  
    MsOS_DelayTask(300);
	}
	else	//power on
	{
    if ( E_OSD_EMPTY != MApp_ZUI_GetActiveOSD())
    {
      MApp_ZUI_ACT_ShutdownOSD();
    }			
		//MApp_Sleep_ResetNoSignalShutdown();	    
		MApp_Sleep_ReleaseSleepTimer();			
		//MApp_Sleep_ReleaseCountDownStatus();	
    LED_GREEN_ON();
    LED_RED_OFF();
    MApi_PNL_En(TRUE);         
    MsOS_DelayTask(300);
    MApi_PNL_SetBackLight(ENABLE);
    MsOS_DelayTask(300);    
    Audio_Amplifier_ON();
    MsOS_DelayTask(150);
		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);
		#else
		MUTE_Off();
		#endif
    MsOS_DelayTask(150);    
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);    			   
	}
}
#endif

// Turn off audio standard flow: (by Cathy)
//  1.DSP mute
//  2.Delay 10ms
//  3.Amp mute on
//  4.Amp power off
void MApp_Standby_Init(void)
{
    ST_TIME _stTime;
    DAYOFWEEK eDayOfWeek;
		#ifdef sUseSimplePowerShutDown //未完
		if(sFlagSimPowerShutDown&0x10)
		{
			//printf("MingYuan MApp_Standby_Init %d \n",sFlagSimPowerShutDown);
			if((sFlagSimPowerShutDown&0x01)==0x01)
			{
				//printf("MingYuan MApp_Standby_Init 0x01 \n");	//Ray DBG 2017.06.05
				MApp_SimplePowerSaving(0);			//Ray DPW 2017.05.29: enable simple power save back to normal. cancel reboot when release from standby to normal
				sFlagSimPowerShutDown = 0x00;
				MApp_ZUI_ACT_SetTargetMenuState(STATE_MENU_INIT);
				//msAPI_BLoader_Reboot(); //先用reboot , 否則OSD會當	//Ray DPW 2017.05.29: cancel reboot when release from standby to normal
			}
			else
			{
				//printf("MingYuan MApp_Standby_Init 0x00 \n");	//Ray DBG 2017.06.05
				MApp_SimplePowerSaving(2);
				sFlagSimPowerShutDown = 0x01;				
			}			
			//printf("MingYuan MApp_Standby_Init 2 : %d \n",sFlagSimPowerShutDown);
			//MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_CLOSE_CURRENT_OSD);
		}	
		return;
		#endif	
    STDBY_DBGINFO(printf("Enter Standby mode\n"));

    // Turn off audio: 1.DSP mute
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_PERMANENT_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);

    // Turn off audio: 2.Delay 10ms
    msAPI_Timer_Delayms(10);//DELAY_FOR_ENTERING_MUTE);

    // Turn off audio: 3.Amp mute on
		#ifdef sNewAudioMuteStyle
		msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, 0, 0);
		#else    
    MUTE_On();
    #endif

    // Turn off audio: 4.Amp power off
    Audio_Amplifier_OFF();


  #if EAR_PHONE_POLLING
    EarPhone_OFF();
  #endif
    MApi_PNL_SetBackLight(DISABLE);

    MApp_ConvertSeconds2StTime(msAPI_Timer_GetSystemTime(),&_stTime);
    //eDayOfWeek = (DAYOFWEEK) MApp_GetDayOfWeek(_stTime.u16Year, _stTime.u8Month, _stTime.u8Day); //ZUI: refine function name
    eDayOfWeek = (DAYOFWEEK) MApp_GetDayOfWeek(_stTime.u16Year, _stTime.u8Month, _stTime.u8Day);

    MApp_SetDayOfWeek(eDayOfWeek);

  #if (INPUT_HDMI_VIDEO_COUNT > 0)
    MApi_XC_Sys_HDMI_PowerOff( );
  #endif

    //For Sleep Timer
//    MApp_Sleep_ReleaseSleepTimer();

#if ENABLE_OAD
	//MApp_OAD_SetInfo() ;
#endif

#if (ENABLE_CI_PLUS)
    MApp_CI_ExitCiOperatorProfile();
#endif

    MApp_InitRtcWakeUpTimer();

    if (IsAnyTVSourceInUse())
    {
        MApp_ChannelChange_DisableChannel(TRUE, MAIN_WINDOW);
    }
    MApp_ZUI_ACT_ShutdownOSD();//ZUI: MApp_UiMenu2_DeleteALLOSDWindow();

    msAPI_Scaler_SetBlueScreen( ENABLE, E_XC_FREE_RUN_COLOR_BLACK, DEFAULT_SCREEN_UNMUTE_TIME, MAIN_WINDOW);

    MApi_PNL_En(FALSE);

  #if 0
    if((MApp_MassStorage_DeviceConnectionDetect() & MS_USB_CONNECTED) ||
      (MApp_MassStorage_DeviceConnectionDetect() & MS_USB2_CONNECTED))
        {
            msAPI_BKFS_FlashCopy(BKF_FLASHCOPY_DRAM2FLASH, EVENTDB_SDRAM_ADR, EVENTDB_SDRAM_LEN+EPGEXTDB_SDRAM_LEN, (U16*)msAPI_BKFS_GetEPGFileName(), msAPI_BKFS_GetEPGFileLength());
        }
  #endif

    //MApp_ATVProc_Exit();

    MApp_SaveGenSetting();

    MApp_DB_SaveDataBase_RightNow(SAVE_DB_FLAG_CHECK_DB_CH_CHANGED);


    msAPI_Key_PowerDown_Mode(STANDBY_MODE);
}


/*******************************************************************************************/

#undef MAPP_STANDBY_C

