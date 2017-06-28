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
// (ï¿½ï¿½MStar Confidential Informationï¿½ï¿½) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_IR_C

#include <stdio.h>
#include <string.h>
#include "Board.h"
#include "datatype.h"
#include "MsCommon.h"
#include "MsIRQ.h"
#include "MsOS.h"
#include "SysInit.h"
#include "MApp_Init.h"

#include "apiXC.h"
#include "apiXC_Adc.h"
#include "MApp_GlobalSettingSt.h"
#include "msAPI_Global.h"
#include "MApp_GlobalFunction.h"

#include "msAPI_ATVSystem.h"
#include "msAPI_DTVSystem.h"
#include "msAPI_IR.h"
#include "msAPI_Timer.h"
#include "msAPI_Power.h"
#include "drvUartDebug.h"

//#if (DEBUG_SYS_INFO_REPORT && MHEG5_ENABLE)
#if (MHEG5_ENABLE)
#include "msAPI_MHEG5.h"
#endif

#include "MApp_GlobalVar.h"
#include "MApp_Key.h"
#include "MApp_IR.h"
#include "MApp_DataBase.h"
#include "MApp_Sleep.h"
#include "MApp_NoOperate_AutoSleep.h"
#include "MApp_SaveData.h"
#include "MApp_ATVProc.h"
#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
#include "ZUI_exefunc.h"
#include "MApp_UiMenuDef.h" //ZUI: #include "MApp_UiMenu.h"
#include "MApp_Main.h"

#if MHEG5_ENABLE
#include "MApp_ChannelChange.h"
#endif

//CEC
#if ENABLE_CEC
#include "msAPI_CEC.h"
#endif

#include "mstar_debug.h"
#include "msIR.h"
#include "GPIO.h"
#include "MApp_TopStateMachine.h"

#include "msAPI_Tuning.h"
#include "mapp_videoplayer.h"
#include "MApp_RestoreToDefault.h"

#if (ENABLE_MFC_6M20)
#include "drvUrsaMFCAPI.h"
#endif

#if ENABLE_MFC_6M30
#include "drvUrsa6M30.h"
#endif

//MHL
#if (ENABLE_MHL == ENABLE)
#include "msAPI_MHL.h"
#endif

#if(CHAKRA3_AUTO_TEST)
#include "MApp_AutoTest.h"
#endif

#ifndef SCAN_TEST_MODE_ENABLE
#define SCAN_TEST_MODE_ENABLE 0
#endif
#if ENABLE_S2
#include "MApp_TV.h"
#include "MApp_MenuChannel.h"
#endif
#if ENABLE_KEY_LOGGER
#include "MApp_KeyLogger.h"
#endif
#if ENABLE_EWS
#include "MApp_EWS.h"
#endif
#if (ENABLE_AUDIO_ONLY_CUSTOMERMODE == 1)
#include "MApp_ChannelProc_ATSC.h"
#include "MApp_XC_PQ.h"
#include "MApp_UiMenuFunc_ATSC.h"
#endif

#if (NO_SIGNAL_AUTO_SHUTDOWN )
#include "MApp_NoSignal_AutoSleep.h"
#endif
#if(sPowerDown_Function==sSimple_PowerDownFun)
#include "MApp_Standby.h"
#endif
//#ifdef sUseSimplePowerShutDown
//extern EN_TOP_STATE enTopState;
//#endif  
//==============================================================================
/*                                 Macro                                        */
//==============================================================================
#define CUSTOM_CODE 0xAB
#define KEY_DEBUG(y)            //y
#define DEBUG_OBAMA_KEY 0
#define CEC_DEBUG(y)            //y
//==============================================================================
/*                                 Global                                        */
//==============================================================================
extern BOOLEAN gCECUserControlEnable;

//==============================================================================
/*                                 Local                                        */
//==============================================================================
static void MApp_ParseKey(void);
static void MApp_CheckKeyStatus(void);
static void MApp_SetKeyRepeatState(U8 u8KeyData);
#ifdef IR_FACTORY_OSD_NUM
static U8 sPassNum=0;
#endif
static KEYSTAT stKeyStatus;
static U8 rs232KeyCmd = IRKEY_DUMY;			//Ray OSM 2017.06.16: To store key from RS-232 command (like 0xF7 = MENU key)

#define OSD_REPEAT_MASK     (BIT1|BIT0)
#define OSD_REPEAT_DISABLE  (0x00)
#define OSD_REPEAT_H_ENABLE (BIT0)
#define OSD_REPEAT_V_ENABLE (BIT1)
#define OSD_REPEAT_ENABLE   (BIT1|BIT0)

static U8 u8KeyRepeatState = OSD_REPEAT_ENABLE;
static U8 u8HwDebugFlag = 0;
#if (IR_MODE_SEL == IR_TYPE_FULLDECODE_MODE)
extern U8 u8IRTimerBlockstatus;
#endif

#if (FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF_MSB1210) // GEM_SYNC_0815
#define MSTAR_VIF_MSB1210_DEBUG_MODE      0
#define GEMINI_KEY_NONE                   0
#define GEMINI_KEY_WAIT_1                 1
#define GEMINI_KEY_WAIT_2                 2
#define GEMINI_KEY_WAIT_3                 3
#define GEMINI_GET_KEY_1                  1
#define GEMINI_GET_KEY_2                  2

U8 gGemini_KeyState            =0;
U8 gGemini_FactoryMode_Enable  =0;
U8 gGemini_GetKey              =0;
U8 gGemini_KeyValue            =0;
extern U8 gVifTop;
#if (FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF)
extern void msVifTopAdjust(void);
#endif
#if (FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF_MSB1210)
extern BOOL msVifTopAdjust(BYTE ucVifTop);
#endif
extern U8 MApp_ProcessUserInput_MSVIF_Debug(U8 keycode);
#endif

static ST_MBIR mbir;
#if ENABLE_AUTOTEST
extern BOOLEAN g_bAutobuildDebug;
#endif
#if (ENABLE_MSTV_UART_DEBUG && ENABLE_MMS)
extern U8 g_DisableIr;
#endif

#if(ENABLE_CEC)
extern BOOLEAN gCECProcessCMDbyKey;
extern MS_U8 gCECProcessCMDKeycode;
MS_U16 u16CEC_UserCtrlReleasedTimeIsr = 0;
#endif

//******************************************************************************

BOOLEAN MApp_isKeypadSourceKeyCanSelect(void)
{
    /*/ZUI_TODO:
    if((g_u8MenuPageIndex == MENU_SETUP_A1_Scan_CheckMenu)||
        (g_u8MenuPageIndex == MENU_SETUP_A1_Scan_ConfirmMsg_SkipATV)||
        (g_u8MenuPageIndex == MENU_SETUP_A1_Scan_ConfirmMsg_SkipDTV)||
        (g_u8MenuPageIndex == MENU_CHANNEL_DTV_ManualScan)||
        (g_u8MenuPageIndex == MENU_OPTION_FACTORY_RESET)||  //Restore to default
        (g_u8MenuPageIndex == MENU_TIME_D1_Clock)|| // Cur timer's close option
        (g_u8MenuPageIndex == MENU_TIME_D2_OffTimer)||// off timer 's close option
        (g_u8MenuPageIndex == MENU_TIME_D3_OnTimer)// on timer 's close option
        )
            return TRUE;
    else
            return FALSE;
    */
    return FALSE;
}

#if (IR_CHANNEL_USE_AS_UPDOWN && IR_VOLUME_USE_AS_LEFTRIGHT)
BOOLEAN MApp_isKeypadUPLR(void)
{
   if ((MApp_ZUI_GetActiveOSD() == E_OSD_MAIN_MENU) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_INPUT_SOURCE) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_PROGRAM_EDIT) ||
#if(ENABLE_DTV)
        (MApp_ZUI_GetActiveOSD() == E_OSD_DTV_MANUAL_TUNING) ||
#endif
        (MApp_ZUI_GetActiveOSD() == E_OSD_ATV_MANUAL_TUNING) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_AUTO_TUNING) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_CHANNEL_LIST) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_AUDIO_LANGUAGE) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_SUBTITLE_LANGUAGE) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_INSTALL_GUIDE) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_FACTORY_MENU) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_AUDIO_LANGUAGE) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_AUDIO_LANGUAGE) ||
        (MApp_ZUI_GetActiveOSD() == E_OSD_AUDIO_LANGUAGE)
        )
    {
        //printf("@@ keypad LRUD\n");
        return TRUE;
    }
    else
        return FALSE;
}
#endif
/******************************************************************************/
/*                             Functions                                      */
/******************************************************************************/
static void MApp_ParseKey(void)
{           	
      //printf("\nRay: Received key:%d, sFlagSimPowerShutDown:%d,Top state:%d,enMainMenuState:%d\n",stKeyStatus.keydata,sFlagSimPowerShutDown,MApp_TopStateMachine_GetTopState(),MApp_Menu_Main_GetState());		//Ray DBG 2017.05.24
      //printf("Ray: STATE_TOP_STANDBY value = %d",STATE_TOP_STANDBY);		//Ray DBG 2017.06.05
		#ifdef sUseSimplePowerShutDown
		if((sFlagSimPowerShutDown&0x01)==0x01)
		{
			if(!((stKeyStatus.keydata==IRKEY_POWER)||(stKeyStatus.keydata==IRKEY_MENU)))		//Ray DPW 2017.05.24: If menu key is pressed when power saving, it wakes up to normal
			{
				stKeyStatus.keydata = IRKEY_DUMY;
				u8KeyCode = KEY_NULL;
				return;
			}
		}	
		#endif		
		#if(sPowerDown_Function==sSimple_PowerDownFun)
		if(sSaveSleepForPM)
		{
			//if(stKeyStatus.keydata!=IRKEY_POWER)
			//if((stKeyStatus.keydata!=IRKEY_POWER)&&(stKeyStatus.keydata!=IRKEY_DUMY))
			if(stKeyStatus.keydata!=IRKEY_DUMY)
			{
       	sSaveSleepForPM = 0;
       	//#ifdef sAddPMSavePara
 				//msAPI_rmBurstWriteBytes(RM_PM_POWER_STATUS_ADDR, (BYTE *)&sSaveSleepForPM, 1);        	
 				//#endif				
       	MApp_SimplePowerSaving(0);
				/*#ifdef sShowInputMsgDelay
    		if ( E_OSD_EMPTY != MApp_ZUI_GetActiveOSD())
    		{
    			MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_CLOSE_CURRENT_OSD);
      		//MApp_ZUI_ACT_ShutdownOSD();		
				}	
    		MApp_ZUI_ACT_StartupOSD(E_OSD_CHANNEL_INFO);
				MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_SOURCE_BANNER);				
				#endif*/			
 				//MApp_Sleep_ResetNoSignalShutdown();
				stKeyStatus.keydata = IRKEY_DUMY;
				u8KeyCode = KEY_NULL;
				return;
			}	
		}	
		#endif			
#if ENABLE_AUTOTEST
    if(g_bAutobuildDebug)
    {
        return;
    }
#endif

#if (ENABLE_MSTV_UART_DEBUG && ENABLE_MMS)
    if (g_DisableIr)
    {
        return;
    }
#endif

#if( ENABLE_SCRIPT_EXECUTE)
        if(g_stFactorySetting.stFacMiscSetting.eFactoryExecuteScript== EN_FACTORY_EXECUTE_SCRIPT_ON)
        {
            if(msUS_CheckEventPoolEmpty())
            {
                msUS_ScriptExecute(EN_SCRIPT_EVENT_PROCESSUSERINPUT);
            }
        }
#endif


    MWDBGprintf(MWDBG_KEYINPUT, MWDBGLVL_STATUS_B, "IR:%02dh\n", (int)stKeyStatus.keydata);

#if (ENABLE_AUDIO_ONLY_CUSTOMERMODE == 1)
    if ( ( g_AudioOnly  == AUDIO_ONLY_ON ) && (IsAnyTVSourceInUse()) )
    {
        u32MonitorAudioOnlyTimer = msAPI_Timer_GetTime0();
        switch ( stKeyStatus.keydata )
        {
            case IRKEY_MUTE:
            case IRKEY_VOLUME_PLUS:
            case IRKEY_VOLUME_MINUS:
								#ifdef sUseSimplePowerShutDown
								break;
								#endif                 
            case IRKEY_POWER:
								#ifdef sUseSimplePowerShutDown
								//printf("MingYuan KEY_POWER 2 \n");
								//printf("MingYuan enTopState 2 : %d\n",enTopState);
								sFlagSimPowerShutDown = ((sFlagSimPowerShutDown&0x01)|0x10);
								#endif            
                break;

            default:
                if(fEnableAudioOnlyFunc == ENABLE )
                {
                    g_AudioOnly = AUDIO_ONLY_OFF;
                    //if(!( (IsDTVInUse())&&(MApp_ChanProc_GetCurChannelPointer()->u16VideoPid==0) && (MApp_ChanProc_GetCurChannelPointer()->astSoundTrack[0].u16AudioPid !=0)))
                    //    MApp_SetPictureMode(MAIN_WINDOW, TRUE); //need check
                    MApp_UiMenuFunc_ExitAudioOnlyMode();
                    stKeyStatus.keydata = IRKEY_DUMY;

                }
                break;
        }
    }
#endif

    if(msAPI_IsMBIREnabled())//for OBAMA
    {
        // The key code is parsed in Linux.
        switch(stKeyStatus.keydata)
        {
            case KEY_SUBCODE: // subtitle function was opened by subcode key.
                u8KeyCode = KEY_SUBTITLE;
            break;

            //Mapping keycode,Because some keycode not correct. The same reason.
            //Because some IR key codes are defined un-correctly, so we have to change key mapping below.

            case KEY_FF:
            {
                u8KeyCode = KEY_NEXT;
                break;
            }
            case KEY_REWIND:
            {
                u8KeyCode = KEY_PREVIOUS;
                break;
            }
            case KEY_PREVIOUS:
            {
                u8KeyCode = KEY_REWIND;
                break;
            }
            case KEY_NEXT:
            {
                u8KeyCode = KEY_FF;
                break;
            }

            default:
                u8KeyCode = stKeyStatus.keydata;
                break;
        }

      #if DEBUG_OBAMA_KEY
        static U8 pre_u8KeyCode = 0xFF;
        if(u8KeyCode != pre_u8KeyCode)
        {
            printf("%s %s Line %d: u8KeyCode[0x%X]\n", __FILE__, __FUNCTION__, __LINE__,u8KeyCode);
            pre_u8KeyCode = u8KeyCode;
        }
      #endif
    }
    else
    {
    #ifndef HISENSE_6I78 //for Hisense use msAPI_IsMBIREnabled
        switch ( stKeyStatus.keydata )
        {
#if (IR_TYPE_SEL != IR_TYPE_CUS21SH)
            case IRKEY_HOME:                u8KeyCode = KEY_HOME;               break;
#endif
        #if (ENABLE_DMP == DISABLE)
            case IRKEY_TV_RADIO:            u8KeyCode = KEY_TV_RADIO;           break;
        #endif
            case IRKEY_POWER:               
            u8KeyCode = KEY_POWER;              
						#ifdef sUseSimplePowerShutDown
						//printf("MingYuan KEY_POWER 1 : %d\n",sFlagSimPowerShutDown);
						//printf("MingYuan enTopState 1 : %d\n",enTopState);
						sFlagSimPowerShutDown = ((sFlagSimPowerShutDown&0x01)|0x10);
						#endif	            
            break;
            //Ray OSD 2017.06.01: EXIT key acts as OSD back key in main menu
            case IRKEY_EXIT:
              if(E_OSD_MAIN_MENU == MApp_ZUI_GetActiveOSD())
        	{
        	  u8KeyCode = KEY_OSD_BACK;
        	}else{
        	    u8KeyCode = KEY_MENU;	//In no menu mode, press the key to show main menu

        	}

              break;
            //case IRKEY_EXIT:                u8KeyCode = KEY_EXIT;               break;
        #if (ENABLE_DTV_EPG)
            case IRKEY_EPG:                 u8KeyCode = KEY_EPG;                break;
        #else
            case IRKEY_EPG:
                u8KeyCode = KEY_EPG;                break;
        #endif //#if (ENABLE_DTV_EPG)

            case IRKEY_MENU:
            		//----- MingYuan Keypad Split MSD8220_ReferCodeBase -----
            		#ifdef sKeypadSplitWithIR
                if(stKeyStatus.keytype == KEY_TYPE_KEYPAD)
            		{
            			if(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	{
                		u8KeyCode = KEYPAD_MENU;
                	}
                	else if((E_OSD_CHANNEL_LIST == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_MAIN_MENU == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_EPG == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_INSTALL_GUIDE == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_FACTORY_MENU == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_INPUT_SOURCE == MApp_ZUI_GetActiveOSD())                   
                  )                         
                  {
                  	u8KeyCode = KEY_SELECT;
                  }                  	
	            		else
	            		{
            				u8KeyCode = KEY_MENU;
            			}	            				      			
            		}
            		else
            		{
            		    //Ray OSD 2017.06.01: IR MENU key act as OSD next key
            	              if(E_OSD_MAIN_MENU == MApp_ZUI_GetActiveOSD())
            	        	{
            	        	  u8KeyCode = KEY_OSD_NEXT;
            	        	}else{
            	        	    u8KeyCode = KEY_MENU;	//In no menu mode, press the key to show main menu
            	        	}
            		}
                //Ray DPW 2017.05.24: When it's in power saving mode and press MENU key (not IR MNEU key), set sFlagSimPowerShutDown bit 1 to 1 to request back to normal mode
                if((sFlagSimPowerShutDown&0x01)==0x01){
                    if(stKeyStatus.keytype == KEY_TYPE_KEYPAD){
		      u8KeyCode = KEY_POWER;
		      //printf("\nRay: Menu key assign to KEY POWER");			//Ray DBG 2017.06.05
		      sFlagSimPowerShutDown = ((sFlagSimPowerShutDown&0x01)|0x10);
                    }
                }
            		#else
            			u8KeyCode = KEY_MENU;
            	  #endif
            		//-------------------------------------------------------
                break;

            case IRKEY_INPUT_SOURCE:
            		//----- MingYuan Keypad Split MSD8220_ReferCodeBase -----
            		#ifdef sKeypadSplitWithIR
            		if(stKeyStatus.keytype == KEY_TYPE_KEYPAD)
            		{
            			//printf("MingYuan MApp_ZUI_GetActiveOSD() = %d\n",MApp_ZUI_GetActiveOSD());
            			//printf("MingYuan MApp_ZUI_API_GetFocus() = %d\n",MApp_ZUI_API_GetFocus());
									if(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	{
                	  u8KeyCode = KEYPAD_INPUT_SOURCE;
                	}            		
                	else if((E_OSD_CHANNEL_LIST == MApp_ZUI_GetActiveOSD())
                	      ||(E_OSD_MAIN_MENU == MApp_ZUI_GetActiveOSD())
                	      ||(E_OSD_EPG == MApp_ZUI_GetActiveOSD())
                	      //||(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	      ||(E_OSD_INSTALL_GUIDE == MApp_ZUI_GetActiveOSD())
                	  		||(E_OSD_FACTORY_MENU == MApp_ZUI_GetActiveOSD())
                        ||(E_OSD_INPUT_SOURCE == MApp_ZUI_GetActiveOSD())                	  		
                	)                                 		
                	{
                	    u8KeyCode = KEY_EXIT;
                	}                    
                  else
            		  {
            				u8KeyCode = KEY_INPUT_SOURCE;
            			}
            		}
            		else
            		{
            			u8KeyCode = KEY_INPUT_SOURCE;            		
            		}
            		#else
            			u8KeyCode = KEY_INPUT_SOURCE;
            		#endif	
            		//-------------------------------------------------------            
                break;
                
            case IRKEY_UP:            
            		//----- MingYuan Keypad Split MSD8220_ReferCodeBase -----
            		#ifdef sKeypadSplitWithIR
            		if(stKeyStatus.keytype == KEY_TYPE_KEYPAD)
            		{
                  /*if(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	{
                	  u8KeyCode = KEYPAD_UP;
                	}                	  
            		  else*/
            		  {
            				u8KeyCode = KEY_UP;
            			}	
            		}
            		else
            		{
            			u8KeyCode = KEY_UP;
            		}
            		#else
            			u8KeyCode = KEY_UP;
            		#endif	
            		//-------------------------------------------------------                                  
            		break;
            case IRKEY_DOWN:           
                //----- MingYuan Keypad Split MSD8220_ReferCodeBase -----
            		#ifdef sKeypadSplitWithIR
            		if(stKeyStatus.keytype == KEY_TYPE_KEYPAD)
            		{
                  /*if(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	{
                	  u8KeyCode = KEYPAD_DOWN;
                	}                	  
            		  else*/
            		  {
            				u8KeyCode = KEY_DOWN;
            			}	
            		}
            		else
            		{
            			u8KeyCode = KEY_DOWN;
            		}
            		#else
            			u8KeyCode = KEY_DOWN;
            		#endif	
            		//-------------------------------------------------------                     
    		        break;
            case IRKEY_RIGHT:       
                //----- MingYuan Keypad Split MSD8220_ReferCodeBase -----
            		#ifdef sKeypadSplitWithIR
            		if(stKeyStatus.keytype == KEY_TYPE_KEYPAD)
            		{                
                  /*if(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	{
                	  u8KeyCode = KEYPAD_RIGHT;
                	}            		
                	else */if((E_OSD_EMPTY == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_MESSAGE_BOX == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_AUDIO_VOLUME == MApp_ZUI_GetActiveOSD())
                  )
                  {
                    u8KeyCode = KEY_VOLUME_PLUS;
                  }
                  else
                  {
                      //Ray DMP 2017.04.11: If it's in DMP mode without menu, press + key pad = volume plus key
                      if((E_OSD_DMP == MApp_ZUI_GetActiveOSD())&&(MApp_ZUI_API_GetFocus()==HWND_DMP_PLAYBACK_TRANSPARENT_BG)){
      			u8KeyCode = KEY_VOLUME_PLUS;
                      }
                      else{
                	  u8KeyCode = KEY_RIGHT;
                      }
                  }                     
                }
                else
                {
                    //Ray DMP 2017.04.11: If it's in DMP mode without menu, press right IR key = volume plus key
                    if((E_OSD_DMP == MApp_ZUI_GetActiveOSD())&&(MApp_ZUI_API_GetFocus()==HWND_DMP_PLAYBACK_TRANSPARENT_BG)){
    			u8KeyCode = KEY_VOLUME_PLUS;
                    }
                    else{
            		u8KeyCode = KEY_RIGHT;
                    }
                }
                #else
            			u8KeyCode = KEY_RIGHT;                
                #endif
            		//-------------------------------------------------------                     
            		break;
            case IRKEY_LEFT:      
                //----- MingYuan Keypad Split MSD8220_ReferCodeBase -----
            		#ifdef sKeypadSplitWithIR
            		if(stKeyStatus.keytype == KEY_TYPE_KEYPAD)
            		{                
                  /*if(E_OSD_DMP == MApp_ZUI_GetActiveOSD())
                	{
                	  u8KeyCode = KEYPAD_LEFT;
                	}            		
                	else */if((E_OSD_EMPTY == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_MESSAGE_BOX == MApp_ZUI_GetActiveOSD())
                   ||(E_OSD_AUDIO_VOLUME == MApp_ZUI_GetActiveOSD())                   
                  )
                  {
                    u8KeyCode = KEY_VOLUME_MINUS;
                  }
                  else
                  {
                      //Ray DMP 2017.04.11: If it's in DMP mode without menu, press - key pad = volume minus key
                      if((E_OSD_DMP == MApp_ZUI_GetActiveOSD())&&(MApp_ZUI_API_GetFocus()==HWND_DMP_PLAYBACK_TRANSPARENT_BG)){
      			u8KeyCode = KEY_VOLUME_MINUS;
                      }
                      else{
                	  u8KeyCode = KEY_LEFT;
                      }
                  }                     
                }
                else
                {
                    //Ray DMP 2017.04.11: If it's in DMP mode without menu, press left IR key = volume minus key
                      if((E_OSD_DMP == MApp_ZUI_GetActiveOSD())&&(MApp_ZUI_API_GetFocus()==HWND_DMP_PLAYBACK_TRANSPARENT_BG)){
      			u8KeyCode = KEY_VOLUME_MINUS;
                      }
                      else{
            		u8KeyCode = KEY_LEFT;
                      }
                }
                #else
            			u8KeyCode = KEY_LEFT;                
                #endif
            		//-------------------------------------------------------                                  
    	         	break;
            case IRKEY_SELECT:              u8KeyCode = KEY_SELECT;             break;
            case IRKEY_CHANNEL_RETURN:      u8KeyCode = KEY_CHANNEL_RETURN;     break;            
            case IRKEY_BACK:                u8KeyCode = KEY_BACK;               break;
            case IRKEY_NUM_0:               u8KeyCode = KEY_0;                  break;
            case IRKEY_NUM_1:               u8KeyCode = KEY_1;                  break;
            case IRKEY_NUM_2:               u8KeyCode = KEY_2;                  break;
            case IRKEY_NUM_3:               u8KeyCode = KEY_3;                  break;
            case IRKEY_NUM_4:               u8KeyCode = KEY_4;                  break;
            case IRKEY_NUM_5:               u8KeyCode = KEY_5;                  break;
            case IRKEY_NUM_6:               u8KeyCode = KEY_6;                  break;

        #if (SCAN_TEST_MODE_ENABLE==1)
            case IRKEY_NUM_7:
                u8KeyCode = KEY_7;
                AutoScanTest.u8State= TEST_MODE_ATV_SCAN_STATE_DISABLE;
                AutoScanTest.u16VerifyCount=0;
                printf("Test--> Test Mode ATV Scan = Disable\n");
                break;

            case IRKEY_NUM_8:
                u8KeyCode = KEY_8;
                AutoScanTest.u8State= TEST_MODE_ATV_SCAN_STATE_SAVE_DATA;
                AutoScanTest.u16VerifyCount=0;
                printf("Test--> Test Mode ATV Scan = SAVE_DATA\n");
                break;

            case IRKEY_NUM_9:
                u8KeyCode = KEY_9;
                AutoScanTest.u8State= TEST_MODE_ATV_SCAN_STATE_VERIFY;
                AutoScanTest.u16VerifyCount=0;
                AutoScanTest.u16Total_Lost_Channel=0;
                AutoScanTest.u16Total_Ghost_Channel=0;
                switch (AutoScanTest.u16VerifyCountInput)
                {
                    case 1://30 min
                        AutoScanTest.u16VerifyCountInput=10;//60 min
                        printf("Test--> VerifyCountInput = 10, (30 minutes) \n");
                        break;
                    case 10://30 min
                        AutoScanTest.u16VerifyCountInput=20;//60 min
                        printf("Test--> VerifyCountInput = 20, (60 minutes) \n");
                        break;
                    case 20:
                        AutoScanTest.u16VerifyCountInput=50;//300 min = 5 hours
                        printf("Test--> VerifyCountInput = 50, (5 hours) \n");
                        break;
                    case 50://5 hours
                        AutoScanTest.u16VerifyCountInput=100;//10hours
                        printf("Test--> VerifyCountInput = 100, (10 hours) \n");
                        break;
                    case 100://10 hours
                        AutoScanTest.u16VerifyCountInput=10000;//1000hours = 41 days
                        printf("Test--> VerifyCountInput = 10000, (41 days) \n");
                        break;
                    default://10 hours
                        AutoScanTest.u16VerifyCountInput=1;
                        printf("Test--> VerifyCountInput = 1, (3~ minutes) \n");
                        break;
                }

                printf("Test--> Test Mode ATV Scan = Verify \n");
                break;
        #else
            case IRKEY_NUM_7:               u8KeyCode = KEY_7;                  break;
            case IRKEY_NUM_8:               u8KeyCode = KEY_8;                  break;
            case IRKEY_NUM_9:               u8KeyCode = KEY_9;                  break;
        #endif

            case IRKEY_CHANNEL_FAV_LIST:
            case IRKEY_GUIDE:
                u8KeyCode = KEY_CHANNEL_FAV_LIST;
                break;
            case IRKEY_MUTE:                u8KeyCode = KEY_MUTE;               break;
            case IRKEY_FREEZE:              u8KeyCode = KEY_FREEZE;             break;
            case IRKEY_INFO:                u8KeyCode = KEY_INFO;               break;
            case IRKEY_AUDIO:               u8KeyCode = KEY_AUDIO;              break;
            case IRKEY_MTS:                 u8KeyCode = KEY_MTS;                break;
#if (IR_TYPE_SEL != IR_TYPE_CUS21SH)
            case IRKEY_PICTURE:             u8KeyCode = KEY_PICTURE;            break;
#endif
            case IRKEY_ZOOM:                u8KeyCode = KEY_ZOOM;               break;
            case IRKEY_RED:                 u8KeyCode = KEY_RED;                break;
            case IRKEY_GREEN:               u8KeyCode = KEY_GREEN;              break;
            case IRKEY_YELLOW:              u8KeyCode = KEY_YELLOW;             break;
            case IRKEY_BLUE:                u8KeyCode = KEY_BLUE;               break;
            case IRKEY_RED2:                u8KeyCode = KEY_RED;                break;
            case IRKEY_GREEN2:              u8KeyCode = KEY_GREEN;              break;
						#if(IR_TYPE_SEL==IR_TYPE_TRIVIEW_STD)
						case IRKEY_USB:                 u8KeyCode = KEY_USB;                break;
						#endif
        #if ENABLE_SBTVD_BRAZIL_APP
            case IRKEY_SUBTITLE:            u8KeyCode = KEY_DASH;               break;
        #else
            case IRKEY_SUBTITLE:            u8KeyCode = KEY_SUBTITLE;           break;
        #endif

            case IRKEY_UPDATE:              u8KeyCode = KEY_UPDATE;             break;        // add UPDATE key
            case IRKEY_TTX_MODE:            u8KeyCode = KEY_TTX_MODE;           break;
            case IRKEY_MIX:                 u8KeyCode = KEY_MIX;                break;
#if (IR_TYPE_SEL != IR_TYPE_CUS21SH)
            case IRKEY_CLOCK:               u8KeyCode = KEY_CLOCK;              break;
#endif

        #if ENABLE_SBTVD_BRAZIL_APP
            case IRKEY_TTX:                 u8KeyCode = KEY_NULL;                break;
        #else
            case IRKEY_TTX:                 u8KeyCode = KEY_TTX;                break;
        #endif

            case IRKEY_SIZE:                u8KeyCode = KEY_SIZE;               break;
            case IRKEY_HOLD:                u8KeyCode = KEY_HOLD;               break;
            case IRKEY_INDEX:               u8KeyCode = KEY_INDEX;              break;

            case IRKEY_CHANNEL_LIST:        u8KeyCode = KEY_CHANNEL_LIST;       break;
            case IRKEY_SLEEP:               u8KeyCode = KEY_SLEEP;              break;
            case IRKEY_DASH:                u8KeyCode = KEY_DASH;               break;
            case IRKEY_TV_INPUT:            u8KeyCode = KEY_TV_INPUT;           break;

            //Because some IR key codes are defined un-correctly, so we have to change key mapping below.
            case IRKEY_BACKWARD:            u8KeyCode = KEY_PREVIOUS;            break;
            case IRKEY_FORWARD:             u8KeyCode = KEY_NEXT;                break;

          #if (ENABLE_DMP)
            case IRKEY_PAGE_UP:             u8KeyCode = KEY_PAGE_UP;             break;
          #endif

            case IRKEY_PAGE_DOWN:           u8KeyCode = KEY_PAGE_DOWN;           break;
            case IRKEY_PREVIOUS:            u8KeyCode = KEY_FF;                  break;
            case IRKEY_NEXT:                u8KeyCode = KEY_REWIND;              break;
            case IRKEY_CC:                  u8KeyCode = KEY_CC;                  break;

            case IRKEY_CHANNEL_PLUS:
             #if(IR_CHANNEL_USE_AS_UPDOWN==1)
                if((stKeyStatus.keytype == KEY_TYPE_KEYPAD)&&MApp_isKeypadUPLR())
             #else
                if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )
             #endif
                {
                    u8KeyCode = KEY_UP;
                }
                else
                {
                    u8KeyCode = KEY_CHANNEL_PLUS;
                }
                break;

            case IRKEY_CHANNEL_MINUS:
              #if(IR_CHANNEL_USE_AS_UPDOWN==1)
                if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD)&&MApp_isKeypadUPLR() )//ZUI_TODO: &&
              #else
                if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )
              #endif
                {
                    u8KeyCode = KEY_DOWN;
                }
                else
                {
                    u8KeyCode = KEY_CHANNEL_MINUS;
                }
                break;

            case IRKEY_VOLUME_PLUS:
                // special case : when in input select mode, the KEYPAD LEFT/RIGHT is interpreted as VolUP/VolDOWN
              #if(IR_VOLUME_USE_AS_LEFTRIGHT==1)
                if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD)&&MApp_isKeypadUPLR())
                {
                    u8KeyCode = KEY_RIGHT;
                }
                else
                {
                    u8KeyCode = KEY_VOLUME_PLUS;
                }
              #else
                if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )//ZUI_TODO: &&
                {
                    u8KeyCode = KEY_VOLUME_PLUS;
                }
                else if((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )//ZUI_TODO: &&
                {
                    u8KeyCode = KEY_SELECT;
                }
                else if((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )//ZUI_TODO: &&
                    //ZUI_TODO: (enMenuFlowState != FS_WAIT_MENU))
                {
                    u8KeyCode = KEY_RIGHT;
                }
                else
                {
                    u8KeyCode = KEY_VOLUME_PLUS;
                }
              #endif
                break;

            case IRKEY_VOLUME_MINUS:
                // special case : when in input select mode, the KEYPAD LEFT/RIGHT is interpreted as VolUP/VolDOWN
               #if(IR_VOLUME_USE_AS_LEFTRIGHT==1)
                   if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD)&&MApp_isKeypadUPLR() )
                   {
                    u8KeyCode = KEY_LEFT;
                    }
                else
                   {
                    u8KeyCode = KEY_VOLUME_MINUS;
                   }
              #else
                if ((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )//ZUI_TODO: &&
                {
                    u8KeyCode = KEY_VOLUME_MINUS;
                }
             else if((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )//ZUI_TODO: &&
                    //ZUI_TODO: (g_u8MenuPageIndex==MENU_INPUT_SOURCE))
                {
                  u8KeyCode = KEY_SELECT;
                }
                else if((stKeyStatus.keytype == KEY_TYPE_KEYPAD) )//ZUI_TODO: &&
                    //ZUI_TODO: (enMenuFlowState != FS_WAIT_MENU))
                {
                    u8KeyCode = KEY_LEFT;
                }

                else
                {
                    u8KeyCode = KEY_VOLUME_MINUS;
                }
            #endif
                break;

            case IRKEY_ADJUST:                  u8KeyCode = KEY_ADJUST;             break;
            case IRKEY_KEY_DISABLE_KEYPAD:      u8KeyCode = KEY_DISABLE_KEYPAD;     break;
            case IRKEY_REVEAL:                  u8KeyCode = KEY_REVEAL;             break;

        #if ENABLE_DMP || ENABLE_PVR
            case IRKEY_RECORD:                  u8KeyCode = KEY_RECORD;           break;
            case IRKEY_STOP:                    u8KeyCode = KEY_STOP;             break;
        #else
            //CEC
        #endif

        #if (MCU_AEON_ENABLE|ENABLE_CEC)
    //        case IRKEY_CC:                       u8KeyCode = KEY_UARTDEBUGPORT;      break;
          #if ENABLE_DMP
            case IRKEY_PLAY:                     u8KeyCode = KEY_PLAY;               break;
            case IRKEY_PAUSE:                    u8KeyCode = KEY_PAUSE;              break;
          #endif
        #endif

            case IRKEY_SUBPAGE:                 u8KeyCode = KEY_SUBPAGE;            break;
            case IRKEY_DTV:                     u8KeyCode = KEY_DTV;                 break;
            case IRKEY_TV:                      u8KeyCode = KEY_TV;                    break;
#if (IR_TYPE_SEL != IR_TYPE_CUS21SH)
            case IRKEY_SCART:                   u8KeyCode = KEY_SCART;             break;
            case IRKEY_HDMI:                    u8KeyCode = KEY_HDMI;                 break;
            case IRKEY_AV:                      u8KeyCode = KEY_AV;                 break;
#endif

            case IRKEY_PC:                      u8KeyCode = KEY_PC;                    break;
            case IRKEY_COMPONENT:               u8KeyCode = KEY_COMPONENT;             break;
            case IRKEY_SV:                      u8KeyCode = KEY_SV;                    break;

            //Ray FWD IRC 2017.01.24: USB firmware download key
            case IRKEY_USB_DOWNLOAD:		u8KeyCode = KEY_USB_DOWNLOAD;	     break;
            default:                             u8KeyCode = KEY_NULL;               break;
        }
    #endif // #ifndef HISENSE_6I78
    }

#if ( ENABLE_NO_OPERATE_AUTO_SLEEP )
    if( u8KeyCode != KEY_NULL )
    {
        MApp_NoOperateAutoSleep_ResetOpTime();
    }
#endif

#if (ENABLE_KEY_LOGGER && _KEYLOGGER_CAPTURE_BY_SPECIAL_IR_KEY_)
    MApp_KeyLogger_ComboKeyChecker(u8KeyCode);
#endif


  #if ( ENABLE_CHCHANGETIME )
    if (u8KeyCode != KEY_NULL)
    {
        gbKeyPress = TRUE;
        gU32ChChangeTime = msAPI_Timer_GetTime0();
        printf("[ch change time]start\n");
    }
  #endif

#if ( CHAKRA3_AUTO_TEST )
    if (u8KeyCode != KEY_NULL)
    {
        g_AT_en8ChangeChannelState = E_AUTO_TEST_CHANGE_CHANNEL_START;
        //printf("[CK3_Auto_Test] ch change start\n");
        MApp_AT_SendEvent( E_AT_EVENT_CHANGE_CHANNEL_TIME_START, (void*)MsOS_GetSystemTime() );
    }
#endif

#if(DEBUG_CHG_SRC_TIME)
    //printf("ChgSrc start %u\n", MsOS_GetSystemTime());
    g_Debug_u32Time_ChangeSrc = 0;
    g_Debug_bChangeSrc = 1;
    msDebug_PrintChgSrcTime("ChgSrc Start");
#endif

    MApp_SetKeyRepeatState(u8KeyCode);

#if(ENABLE_EWS)
    //if(u8KeyCode != KEY_NULL)
    //    printf("\r\nu8KeyCode=%x",u8KeyCode);

    if(MApp_EWS_DisasterStatusCheck()== TRUE) //customized
    {
        //printf("\r\nStatus=%x   Flage=%x",MApp_EWS_GetStatus(),MApp_EWS_GetMsgCancelFlag());
        if((MApp_EWS_GetStatus()== EN_EWS_WASPADA)&&(MApp_EWS_GetMsgCancelFlag()== TRUE))
        {
            //bypass: cancel WASPASA msg status
        }
        else
        {

            if((MApp_ZUI_GetActiveOSD() == E_OSD_MESSAGE_BOX) && (MApp_ZUI_API_IsWindowVisible(HWND_EWS_FRAME) == TRUE  || MApp_ZUI_API_IsWindowVisible(HWND_EWS_FRAME_WASPADA) == TRUE))
            {


                if(u8KeyCode != KEY_POWER)
                {
                    if((u8KeyCode == KEY_EXIT) && (MApp_EWS_GetStatus()== EN_EWS_WASPADA))
                    {
                        MApp_EWS_SetMsgCancelFlag(TRUE); //cancel EWS
                    }
                    else if((u8KeyCode == KEY_UP) && (MApp_EWS_GetStatus()== EN_EWS_WASPADA))
                    {
                        //SCROLL UP
                        MApp_EWS_Scroll_Text(EN_EWS_SCROLL_UP);
                    }
                    else if((u8KeyCode == KEY_DOWN) && (MApp_EWS_GetStatus()== EN_EWS_WASPADA))
                    {
                        //SCROLL DOWN
                        MApp_EWS_Scroll_Text(EN_EWS_SCROLL_DOWN);
                    }

                    u8KeyCode = KEY_NULL;
                }
            }
        }
    }
#endif

#if 0
    if (u8KeyCode != KEY_NULL)
    {
        printf("ParseKey -> %u\n", u8KeyCode);
        if( u8KeyCode == KEY_POWER )
        {
            printf("Got KEY_POWER\n");
        }
    }
#endif
}

/******************************************************************************/
static void MApp_SetKeyRepeatState(U8 u8KeyData)
{
    if ( u8KeyData == KEY_UP             ||
         u8KeyData == KEY_DOWN           ||
         u8KeyData == KEY_LEFT           ||
         u8KeyData == KEY_RIGHT          ||
         u8KeyData == KEY_VOLUME_PLUS    ||
         u8KeyData == KEY_VOLUME_MINUS   ||
         u8KeyData == KEY_CHANNEL_PLUS   ||
         u8KeyData == KEY_CHANNEL_MINUS )
    {
        u8KeyRepeatState = OSD_REPEAT_ENABLE;
    }
    else
    {
        u8KeyRepeatState = OSD_REPEAT_DISABLE;
    }
}

#define System_Stable_Testing   0

#if System_Stable_Testing
#define KEY_TIMEOUT_1MS  (1000LU)
U8 Test_Key = 0;
U32 Test_Time = 0;
#endif

#if 0
#if ENABLE_MSTV_UART_DEBUG
static BOOLEAN MApp_IsLocalkeyEnabled(U8 u8LocalKey)
{
    U8 u8key;
    u8key = u8LocalKey; // Reserved for  future use.
    if(stGenSetting.g_SysSetting.g_enKeyLock == EN_E5_KeyLock_On) // KeyLock in TvLink-Tuner & Child Lock in User Menu
    {
        if(MApp_TopStateMachine_GetTopState() == STATE_TOP_DIGITALINPUTS)
        {
            //ZUI: MApp_UiMenu_Show_Warning_Message_Dialog(MENU_KEY_LOCK_MSG);
            MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_KEY_LOCK_MSGBOX);

        }
        /*
        if(MApp_TopStateMachine_GetTopState() == STATE_TOP_ANALOGINPUTS)
        {
            //ZUI: MApp_UiMenu_Show_Warning_Message_Dialog(MENU_KEY_LOCK_MSG);
            MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
            MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_KEY_LOCK_MSGBOX);

        }*/
        return FALSE;
    }
    return TRUE;
}
#endif
#endif

static void MApp_CheckKeyStatus(void)
{
    U8 key;
    U8 KeyRepeatStatus;
  #if ENABLE_KEY_LOGGER
    U8 u8KeyType=0;
  #endif
#if 0
    if(!msAPI_IsMBIREnabled())//for OBAMA
    {
        if ( msAPI_GetIRKey(&key, &KeyRepeatStatus) == MSRET_OK )
        {
            stKeyStatus.keytype = KEY_TYPE_IR;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = key;
            stKeyStatus.keyrepeat = KeyRepeatStatus;
            KEY_DEBUG( printf(" IR key value = 0x%02bx, KeyRepeatStatus = %bu \n", key, KeyRepeatStatus) );
        }
        else if ( msAPI_GetKeyPad(&key, &KeyRepeatStatus)== MSRET_OK )
        {
            stKeyStatus.keytype = KEY_TYPE_KEYPAD;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = key;
            stKeyStatus.keyrepeat = KeyRepeatStatus;
            KEY_DEBUG(printf(" Keypad key value = 0x%02bx, KeyRepeatStatus = %bu \n", key, KeyRepeatStatus));
        }
        /*
        else if (enMenuFlowState == FS_WAIT_MENU
            && msAPI_Timer_DiffTimeFromNow(u32IRTimer) > 8000)
        {
            stKeyStatus.keytype = KEY_TYPE_IR;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = 0x52;
            stKeyStatus.keyrepeat = 0;

            printf("keydata = 0x52\n");

            u32IRTimer = msAPI_Timer_GetTime0();
        }
       */

       /* This chicking is used to auto bench testing */
#if ENABLE_MSTV_UART_DEBUG
        else if ( msAPI_GetKeyPad(&key, &KeyRepeatStatus)== MSRET_OK && MApp_IsLocalkeyEnabled(key))
        {
            /* The UART simulates the IR key, so we set keytyps as IR key type*/
            stKeyStatus.keytype = KEY_TYPE_IR;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = key;
            stKeyStatus.keyrepeat = KeyRepeatStatus;
        }
#endif
        else
        {
        #if (IR_MODE_SEL == IR_TYPE_FULLDECODE_MODE)
            if (u8IRTimerBlockstatus == 0xff)
            {
                stKeyStatus.keydown = FALSE;
                stKeyStatus.keydata = KEY_NULL;
                stKeyStatus.keyrepeat = FALSE;
            }
            else
        #endif
            {
                stKeyStatus.keydown = FALSE;
                stKeyStatus.keydata = KEY_NULL;
                stKeyStatus.keyrepeat = FALSE;
            }
        }
    }
    else
#else
    {
        if ( msAPI_GetKeyPad(&key, &KeyRepeatStatus)== MSRET_OK )
        {
            stKeyStatus.keytype = KEY_TYPE_KEYPAD;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = key;
            stKeyStatus.keyrepeat = KeyRepeatStatus;
          #if ENABLE_KEY_LOGGER
            MApp_KeyLogger_Action_Save(KEY_TYPE_KEYPAD, key, KeyRepeatStatus);

            //When user enter any key input during key logger simulation
            //Termination simulation and ignore current key
            if(MApp_KeyLogger_TerminateSimulation())
            {
                stKeyStatus.keydown = FALSE;
            }
          #endif
            //printf(" SAR value = 0x%02x, Repeat = %u \n", key, KeyRepeatStatus);
            //printf(" MingYuan Print SAR value = 0x%02x, Repeat = %u \n", key, KeyRepeatStatus);
        }
        else if ( msAPI_GetIRKey(&key, &KeyRepeatStatus) == MSRET_OK )
        {
            stKeyStatus.keytype = KEY_TYPE_IR;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = key;
            stKeyStatus.keyrepeat = KeyRepeatStatus;
          #if ENABLE_KEY_LOGGER
            MApp_KeyLogger_Action_Save(KEY_TYPE_IR, key, KeyRepeatStatus);
            //When user enter any key input during key logger simulation
            //Termination simulation and ignore current key
            if(MApp_KeyLogger_TerminateSimulation())
            {
                stKeyStatus.keydown = FALSE;
            }
          #endif
            //printf(" IR value = 0x%02bx, Repeat = %bu \n", key, KeyRepeatStatus);
        }
      #if ENABLE_KEY_LOGGER
        else if (MApp_KeyLogger_GetSimulatedKey(&key, &u8KeyType, &KeyRepeatStatus))
        {
            stKeyStatus.keytype = u8KeyType;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = key;
            stKeyStatus.keyrepeat = KeyRepeatStatus;
        }
      #endif
        else if(mbir.empty)
        {
            stKeyStatus.keydown   = FALSE;
            stKeyStatus.keydata   = KEY_NULL;
            stKeyStatus.keyrepeat = FALSE;
        }
        else
        {
            stKeyStatus.keytype=KEY_TYPE_IR;
            stKeyStatus.keydown=TRUE;
            stKeyStatus.keydata=(U8)mbir.keydata;
            stKeyStatus.keyrepeat=mbir.repeat;
            mbir.empty=TRUE;
        }

        //Ray OSM 2017.06.16: Check if RS-232 command set key. If yes, set the key into stKeyStatus.keydata
        if(rs232KeyCmd != IRKEY_DUMY){
            stKeyStatus.keytype = KEY_TYPE_KEYPAD;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keydata = rs232KeyCmd;
            stKeyStatus.keyrepeat = FALSE;
            rs232KeyCmd = IRKEY_DUMY;		//Clear RS-232 command key
        }

    }
#endif

#if System_Stable_Testing
    if (Test_Key != 0)
    {
        stKeyStatus.keytype = KEY_TYPE_IR;
        stKeyStatus.keydown = TRUE;
        stKeyStatus.keyrepeat = 0;
    }
#endif


#if(CHAKRA3_AUTO_TEST)
    if( stKeyStatus.keydown == FALSE )
    {
        if( MApp_AT_Get_SimuIRKey(&key) )
        {
            stKeyStatus.keydata = key;
            stKeyStatus.keytype = KEY_TYPE_IR;
            stKeyStatus.keydown = TRUE;
            stKeyStatus.keyrepeat = FALSE;
        }
    }
#endif

#if 0
    if( stKeyStatus.keydown )
    {
        printf("keytype=%u\n", stKeyStatus.keytype);
        if( KEY_TYPE_KEYPAD == stKeyStatus.keytype )
            printf("KEY_TYPE_KEYPAD\n");
        else if( KEY_TYPE_IR == stKeyStatus.keytype )
            printf("KEY_TYPE_IR\n");

        printf("keydata=%u\n", stKeyStatus.keydata);
        printf("keyrepeat=%u\n", stKeyStatus.keyrepeat);
    }
#endif
}

#define System_Script_Testing   0

#if System_Script_Testing
U8 u8KeyScriptOn=0;


U8 code u8ScriptKeys[] = {

    KEY_CHANNEL_PLUS,KEY_CHANNEL_PLUS,0x81,KEY_EXIT, 0x83,
    KEY_CHANNEL_MINUS,KEY_CHANNEL_MINUS,0x81,KEY_EXIT, 0x83,

    #if 0
    // rotate OSD
    KEY_MENU, KEY_RIGHT, KEY_RIGHT,
    //  scan channel
    KEY_SELECT, KEY_DOWN, KEY_DOWN, KEY_SELECT, KEY_DOWN, KEY_GREEN, 0x85,
    // adjust volume
    KEY_VOLUME_PLUS, KEY_VOLUME_PLUS, KEY_VOLUME_PLUS, 0x83,
    // change channel,
    KEY_SELECT, KEY_UP, KEY_SELECT, 0x84,
    // change to PC
    KEY_INPUT_SOURCE, KEY_UP, KEY_SELECT, 0x83,
    // mute
    KEY_MUTE,
    #endif
};
U16 u16ScriptIndex = 0;
U32 u32WaitTime = 0;
#endif


#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EDEN)|| \
     (CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)|| \
     (CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER) )
BOOLEAN MDrv_Power_CheckPowerOnKey(void)
{
    U8 key;
    U8 KeyRepeatStatus;
    KEYSTAT tmpKeyStatus;

    memset(&tmpKeyStatus, 0, sizeof(KEYSTAT));

    tmpKeyStatus.keydata = 0xFF;
    tmpKeyStatus.keydown = FALSE;

    if ( msAPI_GetIRKey(&key, &KeyRepeatStatus) == MSRET_OK )
    {
        tmpKeyStatus.keytype = KEY_TYPE_IR;
        tmpKeyStatus.keydown = TRUE;
        tmpKeyStatus.keydata = key;
        tmpKeyStatus.keyrepeat = KeyRepeatStatus;
        KEY_DEBUG( printf(" IR key value = 0x%02bx, KeyRepeatStatus = %bu \n", key, KeyRepeatStatus) );
    }
    else if ( msAPI_GetKeyPad(&key, &KeyRepeatStatus)== MSRET_OK )
    {
        tmpKeyStatus.keytype = KEY_TYPE_KEYPAD;
        tmpKeyStatus.keydown = TRUE;
        tmpKeyStatus.keydata = key;
        tmpKeyStatus.keyrepeat = KeyRepeatStatus;
        KEY_DEBUG(printf(" Keypad key value = 0x%02bx, KeyRepeatStatus = %bu \n", key, KeyRepeatStatus));
    }

    if ( tmpKeyStatus.keydown )
    {
        MApp_ParseKey();

        if ( tmpKeyStatus.keydata == IRKEY_POWER )
            return TRUE;
    }

    return FALSE;
}
#endif // #if (CHIP_FAMILY_TYPE == CHIP_FAMILY_M10)||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)

/******************************************************************************/

#if (ENABLE_CEC)
static void MApp_CEC_CheckRepeatKey(void)
{
    switch (u8KeyCode)
    {
        case KEY_SELECT:
        case KEY_LEFT:
        case KEY_RIGHT:
        case KEY_0:
        case KEY_1:
        case KEY_2:
        case KEY_3:
        case KEY_4:
        case KEY_5:
        case KEY_6:
        case KEY_7:
        case KEY_8:
        case KEY_9:
        case KEY_REWIND:
        case KEY_FF:
        case KEY_NEXT:
        case KEY_PREVIOUS:
        case KEY_BLUE:
        case KEY_RED:
        case KEY_GREEN:
        case KEY_YELLOW:
            stKeyStatus.RepeatEnable = TRUE;
            break;

        /*
        Only when System Audio Control is enabled.
        */
        case KEY_VOLUME_PLUS:
        case KEY_VOLUME_MINUS:
            stKeyStatus.RepeatEnable = (msAPI_CEC_QuerySystemAudioMode())? TRUE:FALSE;
            break;

        default:
            stKeyStatus.RepeatEnable = FALSE;
            break;
    }
}
#endif

//MHL
#if (ENABLE_MHL == ENABLE)
#define PRESS_RELEASE_TIMEOUT 150 // ms
#endif

void MApp_ProcessUserInput(void)
{
    //MHL
#if (ENABLE_MHL == ENABLE)
    static U32 u32KeydownTime = 0;
    static BOOL bIsPressed = FALSE;
    static U8 u8PrePressedKey = KEY_NULL;
#endif

#if (ENABLE_CEC)
  #if(CEC_VERSION_USING == CEC_NEW_VERSION)
    static BOOLEAN bIsUserCtrlPressed = FALSE;
    static U32 u32UserCtrlPressedTime = 0;
  #endif
#endif

    MApp_CheckKeyStatus();

#if(ENABLE_CEC)
#if(CEC_VERSION_USING == CEC_NEW_VERSION)

    if(bIsUserCtrlPressed== TRUE) //if user pressed, send a UserControlRelease msg
    {
        if (stKeyStatus.RepeatEnable)
        {
            //passed 400ms, it means there's no the other key inputed.
            if(msAPI_Timer_DiffTimeFromNow(u32UserCtrlPressedTime) > CEC_IR_ENABLE_REPEAT_KEY_PRESS_TIME )
            {
                CEC_DEBUG(printf("\n\33[1;29m Sent UserControlRelease 1  -------- \33[0m"));
                CEC_DEBUG(printf("  TIME= %ld   ", msAPI_Timer_DiffTimeFromNow(u32UserCtrlPressedTime)));
                CEC_DEBUG(printf("\33[1;29m SENT!!! \33[0m \n"));
                u32UserCtrlPressedTime = 0;
                bIsUserCtrlPressed = FALSE;

                //Sent UserControlRelease
                msAPI_CEC_PostMsg_UserCtrlReleased(DIRECTMSG, gCECUserControlEnable, msAPI_CEC_GetActiveDevice());
            }
        }
        else
        {
            if(msAPI_Timer_DiffTimeFromNow(u32UserCtrlPressedTime) > CEC_IR_DISABLE_REPEAT_KEY_RESET_TIME )
            {
                CEC_DEBUG(printf("\n\33[1;29m Sent UserControlRelease 2  -------- \33[0m"));
                CEC_DEBUG(printf("   TIME= %ld  ", msAPI_Timer_DiffTimeFromNow(u32UserCtrlPressedTime)));
                CEC_DEBUG(printf("\33[1;29m SENT!!! \33[0m \n"));
                u32UserCtrlPressedTime = 0;
                bIsUserCtrlPressed = FALSE;

                //Sent UserControlRelease
                msAPI_CEC_PostMsg_UserCtrlReleased(DIRECTMSG, gCECUserControlEnable, msAPI_CEC_GetActiveDevice());
            }
        }
    }
#endif
#endif // #if(ENABLE_CEC)



    if ( stKeyStatus.keydown )
    {
				#ifdef sIntoFactOSDKey
				if(stKeyStatus.keydata==KEY_DIR_FACTORY)
			    u8KeyCode = KEY_DIR_FACTORY;
			  else  
			  	MApp_ParseKey();
				#else    	
        MApp_ParseKey();
        #endif        
        #ifdef IR_FACTORY_OSD_NUM
        if((u8KeyCode>=KEY_0)&&(u8KeyCode<=KEY_9))
        {
        	if((E_OSD_EMPTY == MApp_ZUI_GetActiveOSD())||(E_OSD_MESSAGE_BOX == MApp_ZUI_GetActiveOSD())||(E_OSD_CHANNEL_INFO == MApp_ZUI_GetActiveOSD())) //þýªåþý
        	{
        		if((sPassNum==0)&&((u8KeyCode-KEY_0)==IR_FACTORY_OSD_KEY0))
        			sPassNum = 1;
        		else if((sPassNum==1)&&((u8KeyCode-KEY_0)==IR_FACTORY_OSD_KEY1))
        			sPassNum = 2;
        		else if((sPassNum==2)&&((u8KeyCode-KEY_0)==IR_FACTORY_OSD_KEY2))
        			sPassNum = 3;
        		else if((sPassNum==3)&&((u8KeyCode-KEY_0)==IR_FACTORY_OSD_KEY3))
        			sPassNum = 4;
        		else if((sPassNum==4)&&((u8KeyCode-KEY_0)==IR_FACTORY_OSD_KEY4))
        			sPassNum = 5;
        		//#if(IR_TYPE_SEL!=IR_TYPE_DYNASCAN)
        		else if((sPassNum==5)&&((u8KeyCode-KEY_0)==IR_FACTORY_OSD_KEY5))
        			sPassNum = 6;        		
        		//#endif	
        		else
        			sPassNum = 0;
        		//printf("MingYuan Print IR sPassNum %d \n",sPassNum);
        		if(sPassNum==IR_FACTORY_OSD_NUM)	
        		{
        			u8KeyCode = KEY_DIR_FACTORY;
        			sPassNum = 0;
        			//printf("MingYuan Print IR KEY_DIR_FACTORY \n");
        		}
        	}	
        }
        else
        {
        	sPassNum = 0;
        }
        #endif
        
    #if (ENABLE_ARABIC_OSD)
        if ( !msAPI_OSD_GetDivxSubtitleMode() )
        {
            switch ( MApp_GetMenuLanguage() )
            {
          #if (ENABLE_ARABIC_TEST_UI)
            case LANGUAGE_SPANISH:
          #endif
            case LANGUAGE_ARABIC:
            case LANGUAGE_PARSI:
            case LANGUAGE_KURDISH:
            case LANGUAGE_HEBREW:
                if ( u8KeyCode == KEY_LEFT )
                {
                    u8KeyCode = KEY_RIGHT;
                }
                else if ( u8KeyCode == KEY_RIGHT )
                {
                    u8KeyCode = KEY_LEFT;
                }
                break;
            default:
                break;
            }
        }
    #endif

      //MHL
  #if (ENABLE_MHL == ENABLE)
    if (((UI_INPUT_SOURCE_HDMI <= UI_INPUT_SOURCE_TYPE) && (UI_INPUT_SOURCE_TYPE < UI_INPUT_SOURCE_HDMI_END))
        && mapi_mhl_SendMSGCmdFlag() \
        && (MApp_TopStateMachine_GetTopState() == STATE_TOP_DIGITALINPUTS)\
        && msAPI_MHL_IsCbusConnected()\
         )
        {
        if(msAPI_CheckMHL_IRKeyValid(u8KeyCode))
        {
            if ((FALSE == stKeyStatus.keyrepeat)&&(u8PrePressedKey != u8KeyCode)&&(DIFFERENCE(u32KeydownTime, msAPI_Timer_GetTime0()) > 350))
        {
                if (msAPI_MHL_IRKeyProcess(u8KeyCode, FALSE))
                {
                  //  printf("[press] IRKey Diff Time = %d\n", DIFFERENCE(u32KeydownTime, msAPI_Timer_GetTime0()));
                    u8PrePressedKey = u8KeyCode;
                    u8KeyCode = KEY_NULL;
                    u32KeydownTime = msAPI_Timer_GetTime0();
                    bIsPressed = TRUE;
                    return;
                }
                else
                {
					u8PrePressedKey = u8KeyCode;
					u8KeyCode		= KEY_NULL;
					u32KeydownTime	= msAPI_Timer_GetTime0();
					bIsPressed		= FALSE;
                }
        }
		else
			{
                if((TRUE == stKeyStatus.keyrepeat)
                    &&((u8KeyCode==KEY_UP)||(u8KeyCode==KEY_DOWN)||(u8KeyCode==KEY_LEFT)
                            ||(u8KeyCode==KEY_RIGHT)||(u8KeyCode==KEY_REWIND)||(u8KeyCode==KEY_FF))
                )
                {
                    u32KeydownTime  = msAPI_Timer_GetTime0();
                    if (msAPI_MHL_IRKeyProcess(u8KeyCode, FALSE))
                    {
                            u8PrePressedKey = u8KeyCode;
                            u8KeyCode = KEY_NULL;
                            u32KeydownTime = msAPI_Timer_GetTime0();
                            bIsPressed = TRUE;
                    }
					else
                     {
                            u8PrePressedKey = u8KeyCode;
                            u8KeyCode       = KEY_NULL;
                            u32KeydownTime  = msAPI_Timer_GetTime0();
                            bIsPressed      = FALSE;
                     }
			    }
                u8KeyCode       = KEY_NULL;
                }
            }
    else
        {
            bIsPressed = FALSE;
            u8PrePressedKey = KEY_NULL;
        }
        }
  #endif

#if (ENABLE_CEC)
    if (  (DB_HDMI_SETTING.g_bHdmiCecMode == ENABLE)  // CEC function Enable
       && (msAPI_CEC_GetDeviceTotalNum() > 0)                   // at least one connected CEC device
       )
    {
        if (  ( (IsHDMIInUse() && MApp_IsSrcHasSignal(MAIN_WINDOW))   // HDMI source and has singal
              &&(DB_HDMI_SETTING.g_bHdmiCecDeviceControl == ENABLE) ) // Device control turn on
#if(CEC_VERSION_USING == CEC_NEW_VERSION)
           || ( (msAPI_CEC_IsAudioSystemKeyValid())
#else
           || ( (stGenSetting.g_SoundSetting.TVspeakerMode == TVspeaker_Mode_ExtAmp)
#endif
              &&((u8KeyCode == KEY_VOLUME_PLUS) || (u8KeyCode == KEY_VOLUME_MINUS) || (u8KeyCode == KEY_MUTE)) ) //[4] Tv speaker is CEC and key is volume key
           )
        {
            MApp_CEC_CheckRepeatKey();

    #if(CEC_VERSION_USING == CEC_NEW_VERSION)
            if(stKeyStatus.keyrepeat == FALSE)
            {
                CEC_DEBUG(printf("\n\33[1;31m First key or Change Key \33[0m"));

                if (msAPI_CEC_IrdaKeyProcess(u8KeyCode))
                {
                    u32UserCtrlPressedTime = msAPI_Timer_GetTime0();
                    bIsUserCtrlPressed = TRUE;
                    stKeyStatus.keydown = FALSE;
                    return;
                }
            }
            else if(stKeyStatus.keyrepeat && stKeyStatus.RepeatEnable)
            {
                CEC_DEBUG(printf("\n\33[1;32m Sent UserControlPress  -------- \33[0m"));
                CEC_DEBUG(printf("%ld  ", msAPI_Timer_DiffTimeFromNow(u32UserCtrlPressedTime)));
                 // sent UserControlPress msg durning 200~500ms, otherwise do nothing.
                 if(msAPI_Timer_DiffTimeFromNow(u32UserCtrlPressedTime) > CEC_IR_USER_CONTROL_PRESSED_TIME) //check if the time between 200 to 500 ms
                 {
                    if(msAPI_CEC_IrdaKeyProcess(u8KeyCode))
                    {
                        CEC_DEBUG(printf("\33[1;32m SENT!!!  = %d \33[0m \n", bIsUserCtrlPressed));
                        stKeyStatus.keydown = FALSE;
                        u32UserCtrlPressedTime = msAPI_Timer_GetTime0();
                        return;
                    }
                }
            }
    #else
            if (  (!stKeyStatus.keyrepeat)//new key
               || (stKeyStatus.keyrepeat && stKeyStatus.RepeatEnable)//repeat admitted key
               )
            {
                if ( msAPI_CEC_IrdaKeyProcess(u8KeyCode) )
                {
                    stKeyStatus.keydown = FALSE;
                    return;
                }
            }
    #endif
        }
    }
  #endif // #if(ENABLE_CEC)


    #if (FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF_MSB1210)
      #if (MSTAR_VIF_MSB1210_DEBUG_MODE==1)
        if (MApp_ProcessUserInput_MSVIF_Debug(u8KeyCode)==1)
            return;
      #endif
    #endif

    #if System_Script_Testing
        if ( u8KeyCode == KEY_GREEN )
        {
            if(u8KeyScriptOn)
                u8KeyScriptOn=0;
            else
                u8KeyScriptOn=1;
        }
    #endif

    #if MHEG5_ENABLE
        if ( u8KeyCode == KEY_POWER )
            MApp_ChannelPosition_Restore();
    #endif

    #if MCU_AEON_ENABLE
        // TODO, For debug only, remove it later!
        if ( u8KeyCode == KEY_UARTDEBUGPORT )
        {
            //ZUI_TODO: MApp_UiMenu_Show_Warning_Message_Dialog(MENU_CEC_DEVICE_ISR_MSG);
          #if 0
            switch(XBYTE[0x1EAA] & 0x1C)
            {
                case 0x00:
                    XBYTE[0x1EAA] &= ~0x1C;
                    XBYTE[0x1EAA] |= 0x0C; //aeon1
                    break;

                case 0x0C:
                    XBYTE[0x1EAA] &= ~0x1C;
                    XBYTE[0x1EAA] |= 0x14; //aeon2
                    break;

                default:
                case 0x14:
                    XBYTE[0x1EAA] &= ~0x1C; //hk51
                    printf("==>Uart for HK51\n");
                    break;
            }
          #endif
            u8KeyCode = KEY_NULL;
        }
      #if (MHEG5_ENABLE && DEBUG_SYS_INFO_REPORT)
        // Query System Inormation
        else if(u8KeyCode == KEY_INFO)
            msAPI_System_StatusReport();
      #endif
    #endif

        MApp_Sleep_SetAutoOn_OffTime(DISABLE);

        // Enter Serial Debug Mode through IR Command 8033
        switch ( u8HwDebugFlag )
        {
            case 1:
                if ( u8KeyCode == KEY_0 )
                {
                    u8HwDebugFlag++;
                }
                else
                {
                    u8HwDebugFlag=0;
                }
                break;

            case 2:
                if (u8KeyCode == KEY_3)
                {
                    u8HwDebugFlag++;
                }
                else
                {
                    u8HwDebugFlag=0;
                }
                break;

            case 3:
                if (u8KeyCode == KEY_4)
                {
                #if 0//Delet this function, It's danger when user kit this one day!
                    MApp_DataBase_RestoreFactoryDefault(RESTORE_GENSETTING|RESTORE_DATABASE);

                    MDrv_Sys_WholeChipReset();
                #endif
                }
              #if (ENABLE_DMP)
                else if (u8KeyCode == KEY_9)
                {
                    MApp_VDPlayer_UartSwitch(E_UART_SWITCH_TO_HK);
                    u8HwDebugFlag=0;
                }
                else if (u8KeyCode == KEY_0)
                {
                    MApp_VDPlayer_UartSwitch(E_UART_SWITCH_TO_COPROCESSOR);
                    u8HwDebugFlag=0;
                }
              #endif
                else
                {
                    u8HwDebugFlag=0;
                }
                break;

            case 0:
                if (u8KeyCode == KEY_8)
                {
                    u8HwDebugFlag++;
                }
                else
                {
                    u8HwDebugFlag=0;
                }
                break;

            default :
                u8HwDebugFlag=0;
                break;
        }

        // End Enter Serial Debug Mode through IR Command 8033

        if ( stKeyStatus.keyrepeat )
        {
            switch ( u8KeyRepeatState )
            {
            case OSD_REPEAT_DISABLE:
                u8KeyCode = KEY_NULL;
                break;

            case OSD_REPEAT_H_ENABLE:
                if (u8KeyCode == KEY_UP || u8KeyCode == KEY_DOWN)
                {
                     u8KeyCode = KEY_NULL;
                }
                break;

            case OSD_REPEAT_V_ENABLE:
                if ( u8KeyCode == KEY_LEFT || u8KeyCode == KEY_RIGHT)
                {
                     u8KeyCode = KEY_NULL;
                }
                break;
            }

        }

      #if (NO_SIGNAL_AUTO_SHUTDOWN )
        MApp_NoSignalAutoSleep_Reset_StartTime();
      #endif

        u32MonitorOsdTimer = msAPI_Timer_GetTime0();

        if (stKeyStatus.KeyFilterPower)
        {
            stKeyStatus.KeyFilterPower = FALSE;

            if ((u32MonitorOsdTimer < 8000) && ((u8KeyCode == KEY_POWER) || (u8KeyCode == DSC_KEY_PWROFF)))
            {
                u8KeyCode = KEY_NULL;
            }
        }
    }

  #if 0//(ENABLE_CEC) //don't know what this is??
    else if ( (gCECProcessCMDbyKey == TRUE)
            &&(gCECProcessCMDKeycode != 0xFF) )
    {
        U8 u8KeyDataTemp = 0xff;

        //fixed for CEC 11.1.3 System Standby
        u8KeyDataTemp = stKeyStatus.keydata;
        stKeyStatus.keydata = gCECProcessCMDKeycode;
        MApp_ParseKey();
        stKeyStatus.keydata = u8KeyDataTemp;

        if ( (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI)
         #if (INPUT_HDMI_VIDEO_COUNT >= 2)
          || (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI2)
          #if (INPUT_HDMI_VIDEO_COUNT >= 3)
          || (UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_HDMI3)
          #endif
         #endif
           )
        {
            if(msAPI_CEC_IrdaKeyProcess(u8KeyCode))
            {
                return;
            }
        }

      #if 1//power off DVD in other source
        if(gCECProcessCMDKeycode == KEY_POWER)
        {
            msAPI_CEC_IrdaKeyProcess(gCECProcessCMDKeycode);
        }
      #endif
    }
  #endif

  #if (ENABLE_MHL == ENABLE)
      else if (((UI_INPUT_SOURCE_HDMI <= UI_INPUT_SOURCE_TYPE) && (UI_INPUT_SOURCE_TYPE < UI_INPUT_SOURCE_HDMI_END))
            && mapi_mhl_SendMSGCmdFlag()&&msAPI_MHL_IsCbusConnected())
      {
          if ((bIsPressed == TRUE)&&(DIFFERENCE(u32KeydownTime, msAPI_Timer_GetTime0()) > PRESS_RELEASE_TIMEOUT))
          {
              //printf("[Release]DIFFERENCE=%d, PRESS_RELEASE_TIMEOUT=%d\n", DIFFERENCE(u32KeydownTime, msAPI_Timer_GetTime0()), PRESS_RELEASE_TIMEOUT);
              if (msAPI_MHL_IRKeyProcess(u8PrePressedKey, TRUE))
              {
                  //printf("[1]0x%x Key Released\r\n", u8PrePressedKey);
                  u8PrePressedKey = KEY_NULL;
                  u8KeyCode = KEY_NULL;
                  bIsPressed = FALSE;
                  return;
              }
              else
              {
                  //printf("[Release]MHL IR key False\r\n");
                  u8PrePressedKey = KEY_NULL;
                  u8KeyCode = KEY_NULL;
                  bIsPressed = FALSE;
              }
          }
      }
  #endif

  #if System_Script_Testing
    if(u8KeyScriptOn)
    {
        if (u16ScriptIndex < sizeof(u8ScriptKeys) / sizeof(u8ScriptKeys[0]))
        {
            if (u8ScriptKeys[u16ScriptIndex] & 0x80)
            {
                if (msAPI_Timer_DiffTime( msAPI_Timer_GetTime0(), u32WaitTime ) >
                    (u8ScriptKeys[u16ScriptIndex] & 0x7F) * 1000LU)
                {
                    u16ScriptIndex++;
                }
                u8KeyCode = KEY_NULL;
            }
            else
            {
                if (msAPI_Timer_DiffTime( msAPI_Timer_GetTime0(), u32WaitTime ) > 200LU)
                {
                    u32WaitTime = u32MonitorOsdTimer = msAPI_Timer_GetTime0();
                    u8KeyCode = u8ScriptKeys[u16ScriptIndex++];
                }

                else
                {
                    u8KeyCode = KEY_NULL;
                }
            }
        }
        else
        {
            u16ScriptIndex=0;
        }
    }
  #endif

    /* simple key leaner */
    #define STUDY_BEGIN_KEY        KEY_NULL//KEY_INDEX
    #define STUDY_SEND_KEY        KEY_HOLD

    if (STUDY_BEGIN_KEY != KEY_NULL && STUDY_SEND_KEY != KEY_NULL)
    {
        #define SK_STATE_NONE  0
        #define SK_STATE_LEARN 1
        #define SK_STATE_SEND  2
        #define SK_STATE_DELAY 3

        static U32 WaitTime;
        static U8 Keys[16];
        static U8 NumberOfKeys = 0;
        static U8 CurrentKeyIndex = 0;
        static U8 state = SK_STATE_NONE;
        static U8 u8LastKey = KEY_NULL;

        switch (state)
        {
        default:
        case SK_STATE_NONE:
            if (u8KeyCode == STUDY_BEGIN_KEY)    // begin of study
            {
                NumberOfKeys = 0;
                state = SK_STATE_LEARN;
                u8KeyCode = KEY_NULL;
//                printf("+\n");
            }
            else if (u8KeyCode == STUDY_SEND_KEY)// start to send keys
            {
                if (NumberOfKeys)
                {
                    CurrentKeyIndex = 0;
                    state = SK_STATE_SEND;
                    u8KeyCode = KEY_NULL;
//                    printf(">\n");
                }
            }
            break;

        case SK_STATE_LEARN:
            if (u8KeyCode == KEY_NULL)
                break;
            if (u8LastKey == STUDY_SEND_KEY)        // escape key
            {
                u8LastKey = KEY_NULL;

                // delay time
                if (u8KeyCode >= KEY_0 && u8KeyCode <= KEY_9)
                    u8KeyCode = 0x81 - KEY_0 + u8KeyCode;
            }
            else if (u8KeyCode == STUDY_SEND_KEY)    // escape
            {
                u8LastKey = u8KeyCode;
                u8KeyCode = KEY_NULL;
                break;
            }
            else if (u8KeyCode == STUDY_BEGIN_KEY)    // end of study
            {
                state = SK_STATE_NONE;
                u8KeyCode = KEY_NULL;
//                printf("-%d\n", (int)NumberOfKeys);
                break;
            }
            if (NumberOfKeys >= (sizeof(Keys) / sizeof(Keys[0])))
                break;
            Keys[NumberOfKeys++] = u8KeyCode;
//            printf("%x\n", (int)u8KeyCode);

            if (u8KeyCode >= 0x80)
                u8KeyCode = KEY_NULL;
            break;

        case SK_STATE_SEND:
        case SK_STATE_DELAY:
            if (u8KeyCode == STUDY_SEND_KEY)        // stop send
            {
                state = SK_STATE_NONE;
                u8KeyCode = KEY_NULL;
//                printf("<\n");
            }
            else
            {
                u32MonitorOsdTimer = msAPI_Timer_GetTime0();
                if (CurrentKeyIndex >= NumberOfKeys)
                    CurrentKeyIndex = 0;
                u8KeyCode = Keys[CurrentKeyIndex];
                if (u8KeyCode >= 0x80 /* && u8KeyCode <= 0x80 + 10 */)    // commented out for bank overflow
                {
                    if (state == SK_STATE_SEND)
                    {
                        state = SK_STATE_DELAY;
                        WaitTime = msAPI_Timer_GetSystemTime();
                    }
                    else if ((msAPI_Timer_GetSystemTime() - WaitTime) >= (U32)(u8KeyCode & 0x7F))
                    {
                        state = SK_STATE_SEND;
                        CurrentKeyIndex++;
                    }
                    u8KeyCode = KEY_NULL;
                    break;
                }
                CurrentKeyIndex++;
            }
            break;
        }
    }
}

/******************************************************************************/
void MApp_Key_Initial_Status(void)
{
    stKeyStatus.KeyFilterPower = TRUE;
    msAPI_ClearIRFIFO();
}

/******************************************************************************/
BOOLEAN MApp_GetCurrentKeyType(void)
{
    return stKeyStatus.keytype;
}

BOOLEAN MApp_KeyIsReapeatStatus(void)
{
    //printf("stKeyStatus.keyrepeat %bu\n", stKeyStatus.keyrepeat);
    if (stKeyStatus.keyrepeat == TRUE )
    {
        return TRUE;
    }

    return FALSE;
}

void MApp_GetMBIR(ST_MBIR* pMBIR)
{
    memcpy(pMBIR,&mbir,sizeof(ST_MBIR));
}

void MApp_FillMBIR(U8 keycode, U8 repeat)
{
    mbir.empty=FALSE;
    mbir.keydata=keycode;
    mbir.repeat=repeat;
}

void MApp_ClearMBIR(void)
{
    mbir.empty=TRUE;
    mbir.keydata=0xFFFF;
    mbir.repeat=FALSE;
}

void MApp_SetMBIRFlag(U8 val)
{
    mbir.flag=val;
}

U8 MApp_GetMBIRFlag(void)
{
    return mbir.flag;
}

//Ray OSM 2017.06.16
//*************************************************************************
//Function name:        MApp_RS232_SetKey
//Input:    		key value like IRKEY_MENU etc
//Output:     		none
//Description:          Put RS-232 command key into rs232KeyCmd
//*************************************************************************
void MApp_RS232_SetKey(U8 key)
{
  rs232KeyCmd = key;
}


#if (FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF_MSB1210)
#if (MSTAR_VIF_MSB1210_DEBUG_MODE==1)

U8 MApp_ProcessUserInput_MSVIF_Debug(U8 keycode)
{
#if 0 //Debug
    printf("--Key = 0x%bx (gGemini_KeyState = 0x%bx)\n",keycode,gGemini_KeyState);
    printf("--gGemini_FactoryMode_Enable = 0x%bx (gGemini_KeyValue = 0x%bx)\n"
        ,gGemini_FactoryMode_Enable,gGemini_KeyValue);
#endif

    switch (keycode)
    {
        case KEY_1:
                if (gGemini_KeyState == GEMINI_KEY_WAIT_1)
                    gGemini_KeyState = GEMINI_KEY_WAIT_2;
                else
                {
                    gGemini_KeyState = GEMINI_KEY_NONE;
                }
        break;
        case KEY_2:
                if (gGemini_KeyState == GEMINI_KEY_WAIT_2)
                    gGemini_KeyState = GEMINI_KEY_WAIT_3;
                else
                {
                    gGemini_KeyState = GEMINI_KEY_NONE;
                }
        break;
        case KEY_3:
                if (gGemini_KeyState == GEMINI_KEY_WAIT_3)
                {
                    gGemini_KeyState = GEMINI_KEY_NONE;
                    gGemini_FactoryMode_Enable=1;
                    gGemini_GetKey = GEMINI_GET_KEY_1;
                    gGemini_KeyValue=0XFF;
                    printf("---> MSVIF Debug Enable...\n");
                }
                else
                {
                    gGemini_KeyState = GEMINI_KEY_NONE;
                }
        break;

        case KEY_RED:
                if (gGemini_FactoryMode_Enable ==1)
                {
                    gGemini_KeyState = GEMINI_KEY_NONE;
                    gGemini_FactoryMode_Enable = 0;
                    printf("---> MSVIF Debug Disable...\n");
                    break;
                }else
                {
                    if (gGemini_KeyState == GEMINI_KEY_NONE)
                        gGemini_KeyState = GEMINI_KEY_WAIT_1;
                    else
                    {
                        gGemini_KeyState = GEMINI_KEY_NONE;
                    }
                }
        break;

        default:

        break;
    }

    if (gGemini_FactoryMode_Enable == 1)
    {
        //To support Gemini Key Factory Mode from 1 to 15
           if ((keycode >= KEY_0) &&(keycode <= KEY_9) )
           {
            if (gGemini_GetKey == GEMINI_GET_KEY_1)
               {
                gGemini_KeyValue = keycode & 0x0F;
                gGemini_GetKey = GEMINI_GET_KEY_2;
            }
            else
            {
                gGemini_KeyValue = (gGemini_KeyValue *10) + (keycode & 0x0F);
                gGemini_GetKey = GEMINI_GET_KEY_1;
            }
       }
         if (keycode == KEY_SELECT)
         {
            printf("---> MSVIF Get Key = (0x%bx)\n",gGemini_KeyValue);
            if (gGemini_KeyValue <= 15)
            {
                gVifTop = gGemini_KeyValue;
                printf("---> MSVIF Call msVifTopAdjust(0x%bx)\n",gGemini_KeyValue);
                msVifTopAdjust(gVifTop);

            }
            gGemini_GetKey = GEMINI_GET_KEY_1;
            gGemini_KeyValue = 0XFF;
         }
    }

    if ((gGemini_FactoryMode_Enable == 1)||(gGemini_KeyState != GEMINI_KEY_NONE))
    {
         if (((keycode >= KEY_0) &&(keycode <= KEY_9) )
             ||(keycode == IRKEY_RED)||(keycode == KEY_SELECT))
            return (1);
    }
    return (0);

}
#endif
#endif
#undef MAPP_IR_C

