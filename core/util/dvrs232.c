//******************************************************************************
// COPYRIGHT (C) Digital View Limited 2017.
//
// All rights reserved. This document contains proprietary and
// confidential information of the Digital View Limited. This
// document is not to be copied in whole or part. Digital View
// assumes no responsibility for the consequences of use of such
// information nor for any infringement of patents or other rights of
// third parties which may result from its use. No license is granted by
// implication or otherwise under any patent or patent rights of
// Digital View.
//==============================================================================
//
// MODULE:      dvrs232.c
//
// USAGE:       This module contains functions for RS232 communication with PC
//
//******************************************************************************

//******************************************************************************
//  I N C L U D E    F I L E S
//******************************************************************************

#include "datatype.h"
#include "MsTypes.h"
#include "dvrs232.h"
#include "MApp_EEPROM_Map.h"		//Ray SEE 2017.02.13: For 0xF2 0x50 command to dump system parameter memory usage
#include "msAPI_Ram.h"			//Ray SEE 2017.02.13: For 0xF2 0x41/0x42 command to write/read System EEPROM
#include "MApp_GlobalSettingSt.h"	//Ray SEE 2017.02.20: To include all system parameter stGenSetting.g_SysSetting Macro
#include "Panel.h"			//Ray BKL 2017.02.20: for access API MApi_PNL_SetBackLight
#include "MApp_Exit.h"			//Ray BKL 2017.02.20: For access global variable sSaveSleepForPM and sFlagSimPowerShutDown
#include "MApp_Standby.h"		//Ray BKL 2017.02.20: For access global variable sSaveSleepForPM and sFlagSimPowerShutDown
#include "drvPWM.h"			//Ray BKL 2017.02.21: For access backlight PWM control & parameters
#include "MApp_XC_PQ.h"			//Ray BKL 2017.02.21: To include msAPI_Mode_PictureBackLightN100toReallyValue function
#include "MApp_RestoreToDefault.h"	//Ray BKL 2017.02.21: To access DFFAULT_PWM_FREQUENCY value
#include "dvNT72324.h"			//Ray IE2 2017.02.23: To access IE-2000 functions
#include "dvEDID.h"			//Ray EDD 2017.02.24: To access EDID functions
#include "drvGPIO.h"			//Ray EDD 2017.02.24: For test SDA SCL set high low
#include "EXT_GPIO.h"			//Ray IOE 2017.02.27: To access external IO expander functions
#include "dvExtAudio.h"			//Ray EXA 2017.02.27: To access external audio board functions
#include "msAPI_audio.h"		//Ray VOL 2017.06.19: To access msAPI_AUD_AdjustAudioFactor
#include "MApp_Audio.h"			//Ray VOL 2017.06.19: To access MAX_NUM_OF_VOL_LEVEL
#include "MApp_ZUI_ACTglobal.h"		//Ray BRI 2017.05.08: To access MApp_ZUI_ACT_DecIncValue function
#include "MApp_ZUI_ACTinputsource.h"	//Ray SRC 2017.05.08: To access MApp_ZUI_ACT_InputSourceSwitch
#include "apiXC_Ace.h"			//Ray SAT 2017.05.09: To access MApi_XC_ACE_PicSetSaturation
#include "MApp_PCMode.h"		//Ray SRC 2017.06.15: To access input source resolution, h and v freq
#include "MApp_IR.h"			//Ray OSM 2017.06.16: To access MApp_RS232_SetKey
#include "msIR.h"			//Ray OSM 2017.06.16: To access IR key definition like IRKEY_MENU
#include "MApp_Menu_Main.h"		//Ray DMP 2017.06.22: To access EN_MENU_STATE
#include "MApp_TopStateMachine.h"	//Ray DMP 2017.06.22: To access MApp_TopStateMachine_SetTopState
#include "MApp_UiMenuDef.h"		//Ray VGA 2017.06.22: To access stLMGenSetting
#include "ZUI_exefunc.h"		//Ray HKY 2017.09.29: To access hot key action like EN_EXE_SHOW_VOLUME_HOTKEY
#include <string.h>			//Ray VER 2017.05.09: To access strcpy, strcat functions

//******************************************************************************
//  F U N C T I O N    P R O T O T Y P E S
//******************************************************************************


void dv_SerialCmdInterface(void);
BYTE dv_isUART1CmdCompleted(BYTE* pcData);
BYTE dv_ProcessUart1IncomingData(void);
void dv_IntReadUART1Data(BYTE readData);
void dv_RS232_bCmdParaPtr_0(BYTE ucCmd);
void dv_RS232_bCmdParaPtr_1(BYTE ucCmd, BYTE *ucCmdPara);
void dv_RS232_bCmdParaPtr_2(BYTE ucCmd, BYTE *ucCmdPara);
void dv_RS232_bCmdParaPtr_3(BYTE ucCmd, BYTE *ucCmdPara);
void dv_RS232_bCmdParaPtr_4(BYTE ucCmd, BYTE *ucCmdPara);
void dv_RS232_bCmdParaPtr_5(BYTE ucCmd, BYTE *ucCmdPara);
void dv_RS232_bCmdParaPtr_6(BYTE ucCmd, BYTE *ucCmdPara);
void dv_RS232_bCmdParaPtr_More(BYTE ucCmd, WORD ucCmdNo, BYTE *ucCmdPara);
void dv_TxByteToUART(BYTE ucData);
BYTE dv_HexDigitToAscii(BYTE Data);
BYTE dv_AsciiToHexDigit(BYTE Data);
void dv_SerialTransmitHex(BYTE Data);
BYTE dv_GetAsciiValue(BYTE *para);
BYTE dv_GetAsciiBCDValue(BYTE *para);
void dv_Serial_CopyRight_Para0(BYTE ucCmdPara);
void dv_Serial_BackLightOnOff_Para0(BYTE ucCmdPara);
void dv_Serial_Brightness_Para0(BYTE ucCmdPara);
void dv_Serial_Brightness_Para1(BYTE *ucCmdPara);
void dv_Serial_Brightness_Para2(BYTE *ucCmdPara);
void dv_Serial_Brightness_Para4(BYTE *ucCmdPara);
void dv_Serial_Contrast_Para1(BYTE *ucCmdPara);
void dv_Serial_Contrast_Para2(BYTE *ucCmdPara);
void dv_Serial_Contrast_Para3(BYTE *ucCmdPara);
void dv_Serial_Contrast_Para5(BYTE *ucCmdPara);
void dv_Serial_ColorSat_Para0(BYTE ucCmdPara);
void dv_Serial_ColorSat_Para1(BYTE *ucCmdPara);
void dv_Serial_ColorSat_Para2(BYTE *ucCmdPara);
void dv_Serial_ColorSat_Para4(BYTE *ucCmdPara);
void dv_Serial_Hue_Para0(BYTE ucCmdPara);
void dv_Serial_Hue_Para1(BYTE *ucCmdPara);
void dv_Serial_Hue_Para2(BYTE *ucCmdPara);
void dv_Serial_Hue_Para4(BYTE *ucCmdPara);
void dv_Serial_Sharpness_Para0(BYTE ucCmdPara);
void dv_Serial_Sharpness_Para1(BYTE *ucCmdPara);
void dv_Serial_Sharpness_Para2(BYTE *ucCmdPara);
void dv_Serial_Sharpness_Para4(BYTE *ucCmdPara);
void dv_Serial_ScaleMode_Para0(BYTE ucCmdPara);
void dv_Serial_Source_Para0(BYTE ucCmdPara);
void dv_Serial_Source_Para1(BYTE *ucCmdPara);
void dv_Serial_AutoSource_Para0(BYTE ucCmdPara);
void dv_Serial_AutoSource_Para2(BYTE *ucCmdPara);
void dv_Serial_Gamma_Para0(BYTE ucCmdPara);
void dv_Serial_Info_Para0(BYTE ucCmdPara);
void dv_Serial_PWMFrequency_Para0(BYTE ucCmdPara);
void dv_Serial_PWMFrequency_Para2(BYTE *ucCmdPara);
void dv_Serial_DispOrient_Para0(BYTE ucCmdPara);
void dv_Serial_ColorTemp_Para0(BYTE ucCmdPara);
void dv_Serial_ColorTemp_Para2(BYTE *ucCmdPara);
void dv_Serial_ColorTemp_Para3(BYTE *ucCmdPara);
void dv_Serial_TempRed_Para0(BYTE ucCmdPara);
void dv_Serial_TempRed_Para1(BYTE *ucCmdPara);
void dv_Serial_TempGreen_Para0(BYTE ucCmdPara);
void dv_Serial_TempGreen_Para1(BYTE *ucCmdPara);
void dv_Serial_TempBlue_Para0(BYTE ucCmdPara);
void dv_Serial_TempBlue_Para1(BYTE *ucCmdPara);
void dv_Serial_QuerySource(void);
void dv_Serial_QuerySourceTx(E_DATA_INPUT_SOURCE ucSource);
void dv_Serial_BackLightControl_Para0(BYTE ucCmdPara);
void dv_Serial_BackLightControl_Para1(BYTE *ucCmdPara);
void dv_Serial_BackLight_PWM_DA_Para0(BYTE ucCmdPara);
void dv_Serial_BackLightInvert_Para0(BYTE ucCmdPara);
void dv_Serial_MinBackLightValue_Para0(BYTE ucCmdPara);
void dv_Serial_MinBackLightValue_Para1(BYTE *ucCmdPara);
void dv_Serial_DefaultPower_Para2(BYTE *ucCmdPara);
void dv_Serial_Power_Para0(BYTE ucCmdPara);
void dv_Serial_CommandQuery_Para1(BYTE *ucCmdPara);
void dv_Serial_CommandQuery_Para3(BYTE *ucCmdPara);
void dv_Serial_CommandQuery_Para5(BYTE *ucCmdPara);
void dv_Serial_Volume_Para1(BYTE *ucCmdPara);
void dv_Serial_Volume_Para2(BYTE *ucCmdPara);
void dv_Serial_Phase_Para0(BYTE ucCmdPara);
void dv_Serial_Phase_Para1(BYTE *ucCmdPara);
void dv_Serial_HorzPosn_Para0(BYTE ucCmdPara);
void dv_Serial_HorzPosn_Para1(BYTE *ucCmdPara);
void dv_Serial_VertPosn_Para0(BYTE ucCmdPara);
void dv_Serial_VertPosn_Para1(BYTE *ucCmdPara);
void dv_Serial_VgaClock_Para0(BYTE ucCmdPara);
void dv_Serial_VgaClock_Para1(BYTE *ucCmdPara);
void dv_Serial_TestCmd_Para1(BYTE *ucCmdPara);
WORD dv_DataInputSourceValue(E_DATA_INPUT_SOURCE ucSource);
WORD dv_UiInputSourceValue(E_UI_INPUT_SOURCE ucSource);


extern void MApp_Scaler_Setting_SetVDScale (EN_MENU_AspectRatio eAspect, SCALER_WIN eWindow);	//Ray ART 2017.05.24
extern void dv_SetImageOrientation(void);		//Ray ORI 2017.05.05
extern void MApp_UserReset(void);			//Ray LDF 2017.06.16
extern void  MApp_FactoryReset(void);			//Ray LDF 2017.06.16
extern void MApp_UiMenuFunc_AdjustBacklightPWM(BOOLEAN bEnable);	//Ray BKL 2017.06.19
extern BOOL MApp_WriteDatabase(U32 dstIndex, U8* srcAddr, U16 size);	//Ray BKL 2017.06.19: To save backlight level
extern void MApp_UiMenu_MuteWin_Show(void);		//Ray VOL 2017.06.19
extern void MApp_UiMenu_MuteWin_Hide(void);		//Ray VOL 2017.06.19
extern void MApp_DMP_Exit(void);							//Ray DMP 2017.06.22
extern void MApp_PCMode_SetFirstNoSignalSource(E_UI_INPUT_SOURCE eUiInputSource);	//Ray DMP 2017.06.22
extern void MApp_InputSource_RestoreSource(void);					//Ray DMP 2017.06.22
extern void MApp_TV_ShowHotKeyOSD(HOT_KEY hotkey);						//Ray HKY 2017.09.29



/*

//void dv_TransmitAcknowledgeByte(RS232_UART_CHANNEL Port,BYTE ucTxData);

//void dv_TxToUART1(BYTE *ucBuf, BYTE ucTxLen);

				//Ray 2016.12.15
void dv_SendBCDValuesToUART(BYTE ucSendByteNo,WORD usSendValue);	//Ray 2016.12.15
void dv_SendValuesToUART(BYTE ucSendByteNo,WORD usSendValue);












void dv_Serial_OsdRotate_Para0(BYTE ucCmdPara);
void dv_Serial_OsdHPosn_Para0(BYTE ucCmdPara);
void dv_Serial_OsdHPosn_Para1(BYTE *ucCmdPara);
void dv_Serial_OsdVPosn_Para0(BYTE ucCmdPara);
void dv_Serial_OsdVPosn_Para1(BYTE *ucCmdPara);
void dv_Serial_OsdTransparency_Para0(BYTE ucCmdPara);
void dv_Serial_OsdTransparency_Para1(BYTE *ucCmdPara);
void dv_Serial_PipHPosn_Para0(BYTE ucCmdPara);
void dv_Serial_PipHPosn_Para1(BYTE *ucCmdPara);
void dv_Serial_PipVPosn_Para0(BYTE ucCmdPara);
void dv_Serial_PipVPosn_Para1(BYTE *ucCmdPara);



void dv_Serial_NewInputDisp_Para0(BYTE ucCmdPara);
void dv_Serial_Timeout_Para0(BYTE ucCmdPara);
void dv_Serial_Timeout_Para1(BYTE *ucCmdPara);
void dv_Serial_HotKeys_Para1(BYTE *ucCmdPara);
void dv_Serial_Runtime_Para0(BYTE ucCmdPara);
void dv_Serial_Runtime_Para5(BYTE *ucCmdPara);
void dv_Serial_PipSource_Para0(BYTE ucCmdPara);
void dv_Serial_PipSize_Para0(BYTE ucCmdPara);
void dv_Serial_PipSize_Para1(BYTE *ucCmdPara);
void dv_Serial_SourceLayout_Para0(BYTE ucCmdPara);
void dv_Serial_AutoPowerSave_Para0(BYTE ucCmdPara);
void dv_Serial_AckSet_Para0(BYTE ucCmdPara);

void dv_Serial_TestPattern_Para0(BYTE ucCmdPara);		//Ray 2016.10.14




void dv_Serial_OSDSwitchMountLock_Para0(BYTE ucCmdPara);
void dv_Serial_Vx1PinState_Para1(BYTE *ucCmdPara);
void dv_Serial_EEPanelTime_Para0(BYTE *ucCmdPara);
WORD dv_Serial_EEPanelTime_Para1(BYTE *ucCmdPara,BYTE ucTx2UART);
void dv_Serial_EEPanelTime_Para2(BYTE *ucCmdPara);
void dv_Serial_EEPanelTime_Para3(BYTE *ucCmdPara);
void dv_Serial_EEPanelTime_Para4(BYTE *ucCmdPara);
void dv_Serial_UserEDID_Para3(BYTE *ucCmdPara);
void dv_Serial_UserEDID_More(BYTE *ucCmdPara);
void dv_Serial_MEMC_Para1(BYTE *ucCmdPara);
void dv_Serial_NT72324_Para2(BYTE *ucCmdPara);
void dv_Serial_PIP_Blender_Para0(BYTE ucCmdPara);
void dv_Serial_PIP_Blender_Para1(BYTE *ucCmdPara);


void dv_Serial_PipSource_Para1(BYTE *ucCmdPara);
void dv_Serial_PipSource_Para2(BYTE *ucCmdPara);






void dv_Serial_ColorEffectExt_Para2(BYTE *ucCmdPara);

BYTE dv_writeEDID(BYTE port);
WORD dv_UserEDID_EEPROM_Address(BYTE ucSource);
WORD dv_InputSourceValue(BYTE ucSource);
BYTE dv_GetDisplayRegion(BYTE ucPicture);
BYTE dv_GetSelectAllRegion(void);

extern BYTE dv_UpdateEDIDPrefTiming(BYTE port);			//Ray 2016.11.07
*/
//******************************************************************************
//  G L O B A L    V A R I A B L E S
//******************************************************************************
#define _EEPROM_CHECKSUM_ADDRESS                    0	//Ray 2016.01.04: Add this which is referred to UserCommonInclude.h
#define UART1_RD_BUF_SIZE  256				//Ray 2015.10.30: UART read buffer size is 256

int g_nInBuffReadIndex=0;				//Ray 2015.10.30: The index of read UART1 buffer
BYTE g_ucUart1Data[UART1_RD_BUF_SIZE];			//Ray 2015.10.30: UART1 buffer, Change size from 5 to 256, which is DV standard
BYTE g_ucUART1CmdPara[300];				//Ray 2016.11.30: UART1 Command Parameter buffer size is changed from 255 to 300
int g_nInBuffWriteIndex=0;				//Ray 2015.10.15: Read index of UART 1 receive buffer g_ucUart1Data[]
BYTE g_ucDVUart1Status = 0;				//Ray 2015.11.02: UART1 status
BYTE g_ucUART1Cmd = 0xff;				//Ray 2015.11.02: UART1 received command byte
WORD g_usUART1CmdParaPtr = 0;				//Ray 2016.12.08: Change UART1 received command parameter from BYTE to WORD
BYTE g_ucSerialAcknowledge = 1;			//Ray 2015.11.02: 1 = Need to send ack bytes to PC
BYTE g_ucSerialCommandEnable = 1;			//Ray 2015.11.02: 1 = Enable serial command process
//BYTE g_ucSysEEUpdate = 0;				//1 = Go to update System EEPROM as parameter is changed, 0 = No need to update system EEPROM
static int g_nVolLevel=16;				//Ray 2015.12.02: testing variable to set ext audio board volume level
//WORD g_usOSDInfoPos;					//Ray 2016.03.16: testing variable to set OSD info block position
BYTE g_ucOsdSwitchMountLock = 0;			//Ray 2016.06.01: 0 = no lock, 1 = lock OSD switch mount (no response to input keys)
BYTE g_ucVideoWallMode = 0;					//Ray 2016.03.24: Video wall mode testing

extern BYTE g_ucDVUart2Status;


//Ray GAM 2017.05.12: Add dummy type enum for gamma value
typedef enum{
  _GAMMA_18,
  _GAMMA_20,
  _GAMMA_22,
  _GAMMA_24,
};


//Implemented/Supported RS-232 commands table
BYTE code SerialCommandTable[] = {
    //Single byte commands
    Serial_Plus,
    Serial_Minus,
    Serial_Down,
    Serial_Up,
    Serial_Menu,
    Serial_HRes,
    Serial_VRes,
    Serial_HFreq,
    Serial_VFreq,
    Serial_Auto,
    Serial_Calibrate,
    Serial_QuerySource,
    Serial_LoadDefault,
    Serial_ALLLoadDefault,

    //Two bytes commands
    Serial_BackLightControl,
    Serial_BackLightOnOff,
    Serial_Brightness,
    Serial_ColorSat,
    Serial_Hue,
    Serial_Sharpness,
    Serial_Source,
    Serial_ColorTemp,
    Serial_AutoSource,
    Serial_ScaleMode,
    Serial_DispOrient,
    Serial_Power,
    Serial_Info,
    Serial_PWMFrequency,
    Serial_BackLight_PWM_DA,
    Serial_BackLightInvert,
    Serial_Phase,
    Serial_HorzPosn,
    Serial_VertPosn,
    Serial_VgaClock,

    //3 bytes command
    Serial_Volume,
    Serial_Contrast,
    Serial_CommandQuery,

    //4 bytes commands

};

//Implemented/Supported RS-232 extend commands table 0xEE
BYTE code SerialExtCommandTable[] = {
    Serial_MinBackLightValue,
};

//RS-232 extend commands table 0xEE with two command bytes
WORD code SerialExtCommand2ByteTable[]={
    Serial_DefaultPower,			//default power on/off
};




//extern BYTE g_ucUart2Data[];		//Ray 2016.10.04: UART2 receive buffer with length UART_RD_SIZE

//extern StructAdcDataType g_stAdcData;			//Ray 2016.04.19: To read color gain ADC data of VGA (test cmd 0xf2 0x52 0x30)

/*
BYTE code tEDID_TBL_D1[] =
{
#include ".\EDID\EdidTableHdmi_2_0_420.h"
};

BYTE code tEDID_TABLE_D2[] =
{
#include ".\EDID\EdidTableHdmi.h"
};

BYTE code tEDID_TABLE_D3[] =
{
#include ".\EDID\EdidTableHdmi.h"
};

BYTE code tEDID_TABLE_D4[] =
{
#include ".\EDID\EdidTableDvi.h"
};
*/
/*


*/
//******************************************************************************
//  C O D E
//******************************************************************************






//*********************************************************
// Routine: dv_SerialCmdInterface
// Usage: Process RS232 data from UART1
//**********************************************************
void dv_SerialCmdInterface(void)
{
  while(dv_ProcessUart1IncomingData());		//Process UART1 incoming data until no more data received

}



//*********************************************************
// Routine: dv_isUART1CmdCompleted
// Usage: Check if completely receive command from UART1.
// Input: pcData, byte pointer to get read data through this routine
// Output: 1 = completely receive command, buffer is empty;
//         0 = command isn't completely receive, buffer has data
// Globals: g_nInBuffWriteIndex, g_nInBuffReadIndex
//**********************************************************
BYTE dv_isUART1CmdCompleted(BYTE* pcData)
{
  BYTE ucCmdCompleted = 0;		//First denote buffer is not empty
  int nNextIndex;
  //Determine if we have any data in the buffer to read
  if(g_nInBuffReadIndex != g_nInBuffWriteIndex){
      //Data is in buffer. Get next available byte from buffer
      *pcData = g_ucUart1Data[g_nInBuffReadIndex];

      nNextIndex = g_nInBuffReadIndex + 1;	//Get next read index
      if(nNextIndex >= UART1_RD_BUF_SIZE ){
	  nNextIndex = 0;			//When reach end of ring buffer, wrap index back to start
      }
      g_nInBuffReadIndex = nNextIndex;		//Set read index to next one

  }
  else{
      ucCmdCompleted = 1;		//Buffer is empty, command is completely received
  }

  return ucCmdCompleted;
}

//*********************************************************
// Routine: dv_ProcessUart1IncomingData
// Usage: Process received data from UART1.
// Output: 1 = processed received command
//         0 = no data in buffer and no command is processed
//**********************************************************
BYTE dv_ProcessUart1IncomingData(void)
{
  BYTE ucRxData;					//Ray 2015.11.02: Received data byte


  //Read received data byte from UART1
  if(dv_isUART1CmdCompleted(&ucRxData)){
      //If there is no data in buffer, denote buffer is empty
      g_ucDVUart1Status = RCV_EMPTY;
      return FALSE;
  }
  g_ucDVUart1Status = RCV_READY;	//Else, denote received data in buffer

  if(g_ucSerialAcknowledge){
      //If serial acknowledge is enabled, received byte is echoed back to PC
      //dv_TransmitAcknowledgeByte(UART_1,ucRxData);
      dv_TxByteToUART(ucRxData);
  }


  if(g_ucSerialCommandEnable == TRUE){

      //Serial_Volume (0x80) is first RS232 command
      //Command byte should be >= 0x80
      //Command parameter should be less than 0x80
      if(ucRxData >=Serial_Volume){
	  g_ucUART1Cmd = ucRxData;	      	//If received data is command byte, save it
	  g_usUART1CmdParaPtr = 0;		//Reset command parameter pointer
	  dv_RS232_bCmdParaPtr_0(ucRxData);	//Process command byte of RS232 command

      }
      else{					//Else, it is command parameter byte
	if(g_usUART1CmdParaPtr <300){				//Ray 2016.11.30: Change from 255 to 300 as we need to store more bytes for user EDID download
	    g_ucUART1CmdPara[g_usUART1CmdParaPtr] = ucRxData;	//Save command parameter
	    g_usUART1CmdParaPtr++;				//Prepare to save next parameter byte
	}
	if(g_usUART1CmdParaPtr == 1){		//If received 1 parameter byte
	    dv_RS232_bCmdParaPtr_1(g_ucUART1Cmd,&g_ucUART1CmdPara[0]);	//Process command with 1st parameter byte
	}
	else if(g_usUART1CmdParaPtr == 2){		//If received 2 parameter byte
	    dv_RS232_bCmdParaPtr_2(g_ucUART1Cmd,&g_ucUART1CmdPara[0]);	//Process command with two parameter bytes
	}
	else if(g_usUART1CmdParaPtr == 3){		//If received 3 parameter byte
	    dv_RS232_bCmdParaPtr_3(g_ucUART1Cmd,&g_ucUART1CmdPara[0]);	//Process command with three parameter bytes
	}
	else if(g_usUART1CmdParaPtr == 4){		//If received 4 parameter byte
	    dv_RS232_bCmdParaPtr_4(g_ucUART1Cmd,&g_ucUART1CmdPara[0]);	//Process command with four parameter bytes
	}
	else if(g_usUART1CmdParaPtr == 5){		//If received 5 parameter byte
	    dv_RS232_bCmdParaPtr_5(g_ucUART1Cmd,&g_ucUART1CmdPara[0]);	//Process command with 5 parameter bytes
	}
	else if(g_usUART1CmdParaPtr == 6){		//If received 6 parameter byte
	    dv_RS232_bCmdParaPtr_6(g_ucUART1Cmd,&g_ucUART1CmdPara[0]);	//Process command with 6 parameter bytes
	}
	if ((g_usUART1CmdParaPtr >=260) && (g_ucUART1Cmd == Serial_Command_Extend)&&(g_ucUART1CmdPara[0] == Serial_UserEDID))	//Ray 2016.11.30: If received User EDID command, we process only after received 260 bytes
	{
	    dv_RS232_bCmdParaPtr_More(g_ucUART1Cmd, g_usUART1CmdParaPtr, &g_ucUART1CmdPara[0]);
	}
      }



  }
  g_ucDVUart1Status = RCV_EMPTY;		//After processed the command, set the status as empty
  return TRUE;


}


//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_0
// Usage: Process received RS232 first byte, which is command.
// Input: unCmd: received command data byte from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_0(BYTE ucCmd)
{

  U16 usValue,u16Fx10;
  int nTemp1;
  BYTE ucTemp2;
  BYTE ucTemp3[2];

  switch(ucCmd)
  {
      case Serial_HRes:					//Command 0xB7
	if (IsVgaInUse()){
	    usValue = MApp_PCMode_Get_HResolution(MAIN_WINDOW , TRUE);
	}else{
	    usValue = MApp_PCMode_Get_HResolution(MAIN_WINDOW, FALSE);
	}
      //Ray 2016.03.17: Need to check if we need to show 0x1000 for 4096x2160 input
      if((usValue/256)<0x10){
	ucTemp2 = 0x0f & (BYTE)(usValue/256);		//Get the 3rd digit hex byte
	ucTemp2 = dv_HexDigitToAscii(ucTemp2);		//Convert hex digital to ASCII
	dv_TxByteToUART(ucTemp2);			//Send 3rd digit hex byte in ASCII to UART1
      }
      else{
	ucTemp2 = 0x1f & (BYTE)(usValue/256);		//Ray 2016.03.17: Need to show 0x1000 for 4096x2160 input. So change from 0x0f to 0x1f
	dv_SerialTransmitHex(ucTemp2);
      }
      ucTemp2 = (BYTE)usValue;				//Get 2nd & 1st digit hex value and then send to UART1
      dv_SerialTransmitHex(ucTemp2);
      break;

    case Serial_VRes:					//Command 0xB8
	if (IsVgaInUse()){
	    usValue = MApp_PCMode_Get_VResolution(MAIN_WINDOW , TRUE);
	}else{
	    usValue = MApp_PCMode_Get_VResolution(MAIN_WINDOW, FALSE);
	}
      ucTemp2 = 0x0f & (BYTE)(usValue/256);		//Get the 3rd digit hex byte
      ucTemp2 = dv_HexDigitToAscii(ucTemp2);		//Convert hex digital to ASCII
      dv_TxByteToUART(ucTemp2);				//Send 3rd digit hex byte in ASCII to UART1
      ucTemp2 = (BYTE)usValue;				//Get 2nd & 1st digit hex value and then send to UART1
      dv_SerialTransmitHex(ucTemp2);
      break;

    case Serial_HFreq:					//Command 0xB9
      if (IsVgaInUse()){
	  usValue = (MApi_XC_Getu16HorizontalFrequency(MApp_PCMode_Get_Mode_Idx(MAIN_WINDOW))+5)/10; 	//Ray OSD 2017.04.19: Get horizontal freq (+5 is for round off before /10)
      }else{
	  usValue = (MApi_XC_PCMonitor_Get_HFreqx10(MAIN_WINDOW)+5)/10;		//(+5 is for round off before /10)
      }
      usValue *=10;					//From unit of kHz and change to unit of 100Hz
      ucTemp2 = 0x0f & (BYTE)(usValue/256);		//Get the 3rd digit hex byte
      ucTemp2 = dv_HexDigitToAscii(ucTemp2);		//Convert hex digital to ASCII
      dv_TxByteToUART(ucTemp2);				//Send 3rd digit hex byte in ASCII to UART1
      ucTemp2 = (BYTE)usValue;				//Get 2nd & 1st digit hex value and then send to UART1
      dv_SerialTransmitHex(ucTemp2);
      break;

    case Serial_VFreq:					//Command 0xBA
      if (IsVgaInUse()){
          u16Fx10 = MApi_XC_GetVerticalFrequency(MApp_PCMode_Get_Mode_Idx(MAIN_WINDOW));
          usValue = u16Fx10 / 10;
      }else{
	  u16Fx10 = MApi_XC_PCMonitor_Get_VFreqx10(MAIN_WINDOW);
	  usValue = (u16Fx10+5)/10;
      }
      ucTemp2 = 0x0f & (BYTE)(usValue/256);		//Get the 3rd digit hex byte
      ucTemp2 = dv_HexDigitToAscii(ucTemp2);		//Convert hex digital to ASCII
      dv_TxByteToUART(ucTemp2);				//Send 3rd digit hex byte in ASCII to UART1
      ucTemp2 = (BYTE)usValue;				//Get 2nd & 1st digit hex value and then send to UART1
      dv_SerialTransmitHex(ucTemp2);
      if ((MApi_XC_PCMonitor_GetSyncStatus(MAIN_WINDOW) & XC_MD_INTERLACE_BIT)&& IsHDMIInUse()){
	  dv_TxByteToUART('i');				//Send 'i' for interlace mode
      }
      else{
	  dv_TxByteToUART('p');				//Send 'p' for progressive mode
      }
      break;


    case Serial_Plus:					//Command 0xFC
      MApp_RS232_SetKey(IRKEY_RIGHT);			//Execute Press Plus key function as RIGHT
      break;

    case Serial_Minus:					//Command 0xFD
      MApp_RS232_SetKey(IRKEY_LEFT);			//Execute Press Minus key function as LEFT
      break;

    case Serial_Down:					//Command 0xFA
      MApp_RS232_SetKey(IRKEY_DOWN);			//Execute Press Down key function
      break;

    case Serial_Up:					//Command 0xFB
      MApp_RS232_SetKey(IRKEY_UP);				//Execute Press UP key function
      break;

    case Serial_Menu:					//Command 0xF7
      MApp_RS232_SetKey(IRKEY_MENU);			//Execute Press MENU key function
      break;

    case Serial_Auto:					//Ray VGA 2017.06.23: Command 0xC3, VGA auto adjust
      if(IsVgaInUse() && MApp_IsSrcHasSignal(MAIN_WINDOW))	//command is only available when input source is VGA and signal exist
      {
          if(MApp_PCMode_Enable_SelfAuto(ENABLE, MAIN_WINDOW))
          {   // to do Auto adjust
              MApp_PCMode_RunSelfAuto(MAIN_WINDOW);
              dv_TxByteToUART(0x31);			//send success result state
          }else{
              dv_TxByteToUART(0x30);			//send fail result state
          }
      }else{
	  dv_TxByteToUART(0x30);			//when input source is not VGA or no signal, auto adjust is reported as fail
      }
      break;

    case Serial_Calibrate:				//Ray VGA 2017.06.23: Command 0xC5, VGA auto color gain calibration
      if(IsVgaInUse() && MApp_IsSrcHasSignal(MAIN_WINDOW))	//command is only available when input source is VGA and signal exist
      {
          //Do auto color gain and get result
         if(MApp_RGB_Setting_Auto(E_XC_EXTERNAL_CALIBRATION,MAIN_WINDOW)){
             dv_TxByteToUART(0x31);			//send success result state
         }else{
             dv_TxByteToUART(0x30);			//send fail result state
         }
      }
      else{
	  dv_TxByteToUART(0x30);			//when input source is not VGA or no signal, auto calibration is reported as fail
      }
      break;


    case Serial_QuerySource:				//Command 0xC9
      dv_Serial_QuerySource();
      break;

    case Serial_LoadDefault:				//Command 0xCE
      MApp_UserReset();					//Load the default setting by reset
      dv_TxByteToUART(0x31);				//Transmit 0x31 to denote reset success
      break;

    case Serial_ALLLoadDefault:				//Command 0xCF
      dv_TxByteToUART(0x31);				//Transmit 0x31 to denote reset success
      MApp_FactoryReset();				//Load all default setting, including color temperature
      break;

/*
    case Serial_SaveUserDefault:			//Command 0xD7
      //Ray 2015.11.13: No such function in RTD2796 demo code.  Need to implement later on
      break;

    case Serial_LoadUserDefault:  			//Command 0xD8
      //Ray 2015.11.13: No such function in RTD2796 demo code.  Need to implement later on
      break;

    case Serial_OsdStatus:  				//Command 0xBB
      //Check if OSD is enabled
      if(ScalerOsdGetOsdEnable()==_ENABLE){
	  dv_TxByteToUART(0x31);			//OSD is enabled, send 0x31
	}
      else{
	  dv_TxByteToUART(0x30);			//OSD is disabled, send 0x30
      }
      break;

    case Serial_OsdOff:					//Command 0xBD
      if(ScalerOsdGetOsdEnable()==_ENABLE){
	  OsdDispDisableOsd();				//Go to disable OSD
	  dv_TxByteToUART(0x31);			//send 0x31 after success disabled OSD
	}
      else{
	  dv_TxByteToUART(0x30);			//OSD is disabled and so cannot diabled OSD anymore, send 0x30
      }
      break;



*/

    default:
      break;

  }

}

//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_1
// Usage: Process command with 1st command parameter byte
// Input: ucCmd: received command data byte from UART
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_1(BYTE ucCmd, BYTE *ucCmdPara)
{
  switch(ucCmd)
  {
    case Serial_Brightness:			//command 0x81, brightness control
      dv_Serial_Brightness_Para0(ucCmdPara[0]);
      break;

    case Serial_ColorSat:			//command 0x83, color saturation control
      dv_Serial_ColorSat_Para0(ucCmdPara[0]);
      break;

    case Serial_Hue:				//command 0x84, hue control
      dv_Serial_Hue_Para0(ucCmdPara[0]);
      break;

    case Serial_Phase:				//command 0x85, VGA phase control
      dv_Serial_Phase_Para0(ucCmdPara[0]);
      break;

    case Serial_HorzPosn:			//command 0x86, VGA horizontal position control
      dv_Serial_HorzPosn_Para0(ucCmdPara[0]);
      break;

    case Serial_VertPosn:			//command 0x87, VGA vertical position control
      dv_Serial_VertPosn_Para0(ucCmdPara[0]);
      break;

    case Serial_VgaClock:			//command 0x8B, VGA Clock control
      dv_Serial_VgaClock_Para0(ucCmdPara[0]);
      break;

    case Serial_Sharpness:			//command 0x8A, sharpness control
      dv_Serial_Sharpness_Para0(ucCmdPara[0]);
      break;

    case Serial_ScaleMode:			//command 0x8c, change aspect ratio
      dv_Serial_ScaleMode_Para0(ucCmdPara[0]);
      break;

    case Serial_DispOrient:			//command 0x8e, change display orientation
      dv_Serial_DispOrient_Para0(ucCmdPara[0]);
      break;

    case Serial_Source:				//command 0x98, Input 1P source selection
      dv_Serial_Source_Para0(ucCmdPara[0]);
      break;

    case Serial_AutoSource:			//command 0x99, Auto source seek setting
      dv_Serial_AutoSource_Para0(ucCmdPara[0]);
      break;

    case Serial_Gamma:				//command 0x9d, Gamma setting
      dv_Serial_Gamma_Para0(ucCmdPara[0]);
      break;

    case Serial_ColorTemp:			//command 0xb3, color temperature control
      dv_Serial_ColorTemp_Para0(ucCmdPara[0]);
      break;

    case Serial_TempRed:			//command 0xb4, red color temperature setting
      dv_Serial_TempRed_Para0(ucCmdPara[0]);
      break;

    case Serial_TempGreen:			//command 0xb5, green color temperature setting
      dv_Serial_TempGreen_Para0(ucCmdPara[0]);
      break;

    case Serial_TempBlue:			//command 0xb6, blue color temperature setting
      dv_Serial_TempBlue_Para0(ucCmdPara[0]);
      break;

    case Serial_Power:				//command 0xc8, Soft power on/off
      dv_Serial_Power_Para0(ucCmdPara[0]);
      break;

    case Serial_Info:				//command 0xcb, Check board information
      dv_Serial_Info_Para0(ucCmdPara[0]);
      break;

    case Serial_BackLightControl:		//Command 0xE0
      dv_Serial_BackLightControl_Para0(ucCmdPara[0]);
      break;

    case Serial_BackLightOnOff:			//Command 0xE1
      dv_Serial_BackLightOnOff_Para0(ucCmdPara[0]);
      break;

    case Serial_BackLight_PWM_DA:		//command 0xe5, PWM or D/A backlight control
      dv_Serial_BackLight_PWM_DA_Para0(ucCmdPara[0]);
      break;

    case Serial_PWMFrequency:			//command 0xE6, PWM frequency
      dv_Serial_PWMFrequency_Para0(ucCmdPara[0]);
      break;

    case Serial_BackLightInvert:		//command 0xE7, backlight invert control
      dv_Serial_BackLightInvert_Para0(ucCmdPara[0]);
      break;

    case Serial_CopyRight:			//Command 0xF8
      dv_Serial_CopyRight_Para0(ucCmdPara[0]);	//Transmit "DIGITALVIEW LTD." text to UART
      break;




/*















    case Serial_OsdRotate:			//command 0x8F, OSD orientation
      dv_Serial_OsdRotate_Para0(ucCmdPara[0]);
      break;


    case Serial_OsdHPosn:			//command 0x90, OSD horizontal position
      dv_Serial_OsdHPosn_Para0(ucCmdPara[0]);
      break;

    case Serial_OsdVPosn:			//command 0x91, OSD vertical position
      dv_Serial_OsdVPosn_Para0(ucCmdPara[0]);
      break;

    case Serial_OsdTransparency:		//command 0x92, OSD menu transparency
      dv_Serial_OsdTransparency_Para0(ucCmdPara[0]);
      break;

    case Serial_Timeout:			//command 0x93, OSD menu timeout
      dv_Serial_Timeout_Para0(ucCmdPara[0]);
      break;



    case Serial_Runtime:			//command 0xa1, panel runtime counter
      dv_Serial_Runtime_Para0(ucCmdPara[0]);
      break;

    case Serial_PipHPosn:			//command 0xa4, PIP horizontal position
      dv_Serial_PipHPosn_Para0(ucCmdPara[0]);
      break;

    case Serial_PipVPosn:			//command 0xa5, PIP vertical position
      dv_Serial_PipVPosn_Para0(ucCmdPara[0]);
      break;

    case Serial_PipSource:			//command 0xa7, Input 2P source selection
      dv_Serial_PipSource_Para0(ucCmdPara[0]);
      break;

    case Serial_PipSize:			//command 0xa6, PIP window size
      dv_Serial_PipSize_Para0(ucCmdPara[0]);
      break;





    case Serial_NewInputDisp:			//command 0xbc, new input video info display setting
      dv_Serial_NewInputDisp_Para0(ucCmdPara[0]);
      break;


    case Serial_SourceLayout:			//command 0x9a, 1P, PIP, 2/4 PBP
      dv_Serial_SourceLayout_Para0(ucCmdPara[0]);
      break;




    case Serial_AutoPowerSave:			//command 0x9F, Auto power saving setting
      dv_Serial_AutoPowerSave_Para0(ucCmdPara[0]);
      break;


    case Serial_AckSet:				//command 0xc1, RS-232 acknowledge
      dv_Serial_AckSet_Para0(ucCmdPara[0]);
      break;



    case Serial_TestPattern:			//command 0xcd, Display test pattern
      dv_Serial_TestPattern_Para0(ucCmdPara[0]);
      break;



    case Serial_PIP_Blender:			//command 0xed, PIP transparency control
      dv_Serial_PIP_Blender_Para0(ucCmdPara[0]);
      break;
*/
    default:
      break;
  }

}

//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_2
// Usage: Process command with two command parameter byte
// Input: ucCmd: received command data byte from UART
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_2(BYTE ucCmd, BYTE *ucCmdPara)
{
  switch(ucCmd)
  {
    case Serial_Volume:				//0x80, volume control
      dv_Serial_Volume_Para1(ucCmdPara);
      break;

    case Serial_Brightness:
      dv_Serial_Brightness_Para1(ucCmdPara);	//0x81, brightness control
      break;

    case Serial_ColorSat:			//0x83, color saturation control
      dv_Serial_ColorSat_Para1(ucCmdPara);
      break;

    case Serial_Contrast:			//0x82, contrast control
      dv_Serial_Contrast_Para1(ucCmdPara);
      break;

    case Serial_Hue:				//command 0x84, hue control
      dv_Serial_Hue_Para1(ucCmdPara);
      break;

    case Serial_Phase:				//command 0x85, VGA phase control
      dv_Serial_Phase_Para1(ucCmdPara);
      break;

    case Serial_HorzPosn:			//command 0x86, VGA horizontal position control
      dv_Serial_HorzPosn_Para1(ucCmdPara);
      break;

    case Serial_VertPosn:			//command 0x87, VGA vertical position control
      dv_Serial_VertPosn_Para1(ucCmdPara);
      break;

    case Serial_VgaClock:			//command 0x8B, VGA clock control
      dv_Serial_VgaClock_Para1(ucCmdPara);
      break;

    case Serial_Sharpness:			//0x8a, sharpness control
      dv_Serial_Sharpness_Para1(ucCmdPara);
      break;

    case Serial_Source:				//0x98, input 1P main source
      dv_Serial_Source_Para1(ucCmdPara);
      break;

    case Serial_TempRed:			//command 0xb4, red color temperature setting
      dv_Serial_TempRed_Para1(ucCmdPara);
      break;

    case Serial_TempGreen:			//command 0xb5, green color temperature setting
      dv_Serial_TempGreen_Para1(ucCmdPara);
      break;

    case Serial_TempBlue:			//command 0xb6, blue color temperature setting
      dv_Serial_TempBlue_Para1(ucCmdPara);
      break;

    case Serial_CommandQuery:			//command 0xc4, RS-232 command query
      dv_Serial_CommandQuery_Para1(ucCmdPara);
      break;

    case Serial_BackLightControl:		//Command 0xE0
      dv_Serial_BackLightControl_Para1(ucCmdPara);
      break;


    /*


    case Serial_Sharpness:			//0x8a, sharpness control
      dv_Serial_Sharpness_Para1(ucCmdPara);
      break;



    case Serial_PipSource:			//0xa7, PIP/PBP source
      dv_Serial_PipSource_Para1(ucCmdPara);
      break;














    case Serial_OsdHPosn:			//command 0x90, OSD horizontal position
      dv_Serial_OsdHPosn_Para1(ucCmdPara);
      break;

    case Serial_OsdVPosn:			//command 0x91, OSD vertical position
      dv_Serial_OsdVPosn_Para1(ucCmdPara);
      break;

    case Serial_OsdTransparency:		//command 0x92, OSD menu transparency
      dv_Serial_OsdTransparency_Para1(ucCmdPara);
      break;

    case Serial_Timeout:			//command 0x93, OSD menu timeout
      dv_Serial_Timeout_Para1(ucCmdPara);
      break;

    case Serial_HotKeys:			//command 0xa0, Hot keys setting
      dv_Serial_HotKeys_Para1(ucCmdPara);
      break;

    case Serial_PipHPosn:			//command 0xa4, PIP horizontal position
      dv_Serial_PipHPosn_Para1(ucCmdPara);
      break;

    case Serial_PipVPosn:			//command 0xa5, PIP vertical position
      dv_Serial_PipVPosn_Para1(ucCmdPara);
      break;

    case Serial_PipSize:			//command 0xa6, PIP window size
      dv_Serial_PipSize_Para1(ucCmdPara);
      break;





    case Serial_MEMC:				//command 0xca, MEMC setting
      dv_Serial_MEMC_Para1(ucCmdPara);
      break;


    case Serial_PIP_Blender:			//Command 0xED, PIP transparency control
       dv_Serial_PIP_Blender_Para1(ucCmdPara);
      break;
    */
    case Serial_TestCmd:			//command 0xF2, internal test command
      dv_Serial_TestCmd_Para1(ucCmdPara);
      break;

    case Serial_Command_Extend:			//Command 0xEE, extended command
      if(*ucCmdPara==Serial_MinBackLightValue){			//Command 0x5C, backlight minimum value
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_MinBackLightValue_Para0(ucCmdPara[0]);
      }
      /*
      if(*ucCmdPara==Serial_OSDSwitchMountLock){		//Command 0x62, OSD switch mount lock
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_OSDSwitchMountLock_Para0(ucCmdPara[0]);
      }
      if(*ucCmdPara== Serial_EEPanelTime){			//Command 0x74, panel timing setting
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_EEPanelTime_Para0(ucCmdPara);
      }
      */
      break;

    default:
      break;
  }

}


//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_3
// Usage: Process command with three command parameter byte
// Input: ucCmd: received command data byte from UART
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_3(BYTE ucCmd, BYTE *ucCmdPara)
{
  WORD usPara;

  switch(ucCmd)
  {

    case Serial_Volume:				//command 0x80, volume change
      dv_Serial_Volume_Para2(ucCmdPara);
      break;

    case Serial_Brightness:
      dv_Serial_Brightness_Para2(ucCmdPara);	//0x81, brightness control
      break;

    case Serial_Contrast:			//command 0x82, contrast change
      dv_Serial_Contrast_Para2(ucCmdPara);
      break;

    case Serial_ColorSat:			//0x83, color saturation control
      dv_Serial_ColorSat_Para2(ucCmdPara);
      break;

    case Serial_Hue:				//command 0x84, hue control
      dv_Serial_Hue_Para2(ucCmdPara);
      break;

    case Serial_Sharpness:			//0x8a, sharpness control
      dv_Serial_Sharpness_Para2(ucCmdPara);
      break;

    case Serial_AutoSource:			//0x99, Auto source seek
      dv_Serial_AutoSource_Para2(ucCmdPara);
      break;

    case Serial_ColorTemp:			//command 0xb3, color temperature control
      dv_Serial_ColorTemp_Para2(ucCmdPara);
      break;

    case Serial_PWMFrequency:			//command 0xe6, PWM frequency
      dv_Serial_PWMFrequency_Para2(ucCmdPara);
      break;


    /*





    case Serial_PipSource:			//command 0xa7, PBP P3/P4 source change
      dv_Serial_PipSource_Para2(ucCmdPara);
      break;
    */


    case Serial_Command_Extend:			//Command 0xEE, extended command
      /*
      if(*(WORD*)ucCmdPara== Serial_ColorEffectExt){		//Command 0x71 0x30, Color effect
	  ucCmdPara+=2;						//Go to parameter byte
	  dv_Serial_ColorEffectExt_Para2(ucCmdPara);
      }


      if(*ucCmdPara== Serial_Vx1PinState){			//Command 0x73, Vx1 Pin state setting
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_Vx1PinState_Para1(ucCmdPara);
      }
      if(*ucCmdPara== Serial_EEPanelTime){			//Command 0x74, panel timing setting
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_EEPanelTime_Para1(ucCmdPara,1);		//1 means timing value send to UART
      }
      */
      usPara = ucCmdPara[0]<<8;
      usPara |= ucCmdPara[1];
      if(usPara == Serial_DefaultPower){			//Command 0x6B 0x50, Default power
	  ucCmdPara+=2;						//Go to parameter byte
	  dv_Serial_DefaultPower_Para2(ucCmdPara);
      }
      if(*ucCmdPara==Serial_MinBackLightValue){			//Command 0x5C, backlight minimum value
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_MinBackLightValue_Para1(ucCmdPara);
      }

      break;

    default:
      break;
  }
}


//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_4
// Usage: Process command with four command parameter byte
// Input: ucCmd: received command data byte from UART
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_4(BYTE ucCmd, BYTE *ucCmdPara)
{
  switch(ucCmd)
  {
    case Serial_Contrast:				//command 0x82, contrast change
      dv_Serial_Contrast_Para3(ucCmdPara);
      break;

    case Serial_ColorTemp:				//command 0xb3, color temperature control
      dv_Serial_ColorTemp_Para3(ucCmdPara);
      break;

    case Serial_CommandQuery:				//command 0xC4, RS-232 command query
      dv_Serial_CommandQuery_Para3(ucCmdPara);
      break;

    /*


    case Serial_Command_Extend:				//Command 0xEE, extended command
      if(*ucCmdPara== Serial_EEPanelTime){		//Command 0x74, panel timing setting
	  ucCmdPara++;					//Go to parameter byte
	  dv_Serial_EEPanelTime_Para2(ucCmdPara);
      }
      else if(*ucCmdPara==Serial_NT72324){				//Command 0x78, NT72324 generic command
	  ucCmdPara++;						//Go to parameter byte
	  dv_Serial_NT72324_Para2(ucCmdPara);
      }
      else if(*ucCmdPara== Serial_UserEDID){		//Command 0x76, user EDID download
	  ucCmdPara++;					//Go to parameter byte
	  dv_Serial_UserEDID_Para3(ucCmdPara);
      }
      break;

  */
    default:
      break;
  }
}

//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_5
// Usage: Process command with five command parameter byte
// Input: ucCmd: received command data byte from UART
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_5(BYTE ucCmd, BYTE *ucCmdPara)
{
  switch(ucCmd)
  {

    case Serial_Brightness:				//0x81, brightness control
      dv_Serial_Brightness_Para4(ucCmdPara);
    break;

    case Serial_ColorSat:				//0x83, color saturation control
      dv_Serial_ColorSat_Para4(ucCmdPara);
      break;

    case Serial_Hue:					//command 0x84, hue control
      dv_Serial_Hue_Para4(ucCmdPara);
      break;

    case Serial_Sharpness:				//0x8a, sharpness control
      dv_Serial_Sharpness_Para4(ucCmdPara);
      break;

    /*
    case Serial_Command_Extend:				//Command 0xEE, extended command
      if(*ucCmdPara== Serial_EEPanelTime){		//Command 0x74, EEPROM panel timing setting
	  ucCmdPara++;					//Go to parameter byte
	  dv_Serial_EEPanelTime_Para3(ucCmdPara);
      }

      break;


    case Serial_Runtime:
      dv_Serial_Runtime_Para5(ucCmdPara);		//Command 0xa1 to set runtime coutner
      break;
     */
    default:
      break;
  }
}



//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_6
// Usage: Process command with six command parameter byte
// Input: ucCmd: received command data byte from UART
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_6(BYTE ucCmd, BYTE *ucCmdPara)
{
  switch(ucCmd)
  {
    case Serial_Contrast:			//command 0x82, contrast change
      dv_Serial_Contrast_Para5(ucCmdPara);
      break;

    case Serial_CommandQuery:				//command 0xC4, RS-232 command query
      dv_Serial_CommandQuery_Para5(ucCmdPara);
      break;

    /*


    case Serial_Command_Extend:				//Command 0xEE, extended command
      if(*ucCmdPara== Serial_EEPanelTime){		//Command 0x74, panel timing setting
	  ucCmdPara++;					//Go to parameter byte
	  dv_Serial_EEPanelTime_Para4(ucCmdPara);
      }
      break;
     */
    default:
      break;
  }
}

//*********************************************************
// Routine: dv_RS232_bCmdParaPtr_More
// Usage: Process command with much more command parameter bytes
// Input: ucCmd: received command data byte from UART
//     	  ucCmdNo: No of command data bytes received
//        *ucCmdPara: received command parameter byte pointer from UART
//**********************************************************
void dv_RS232_bCmdParaPtr_More(BYTE ucCmd, WORD usCmdNo, BYTE *ucCmdPara)
{/*

  switch(ucCmd)
  {
    case Serial_Command_Extend:				//Command 0xEE, extended command
      if(*ucCmdPara== Serial_UserEDID){			//Command 0x76, user EDID
	  if(usCmdNo>=260){				//User EDID command has 260 bytes when it contains EDID content
	    ucCmdPara++;				//Go to parameter byte
	    dv_Serial_UserEDID_More(ucCmdPara);
	  }
      }
      break;

    default:
      break;

  }
*/
}

//Ray URT 2017.02.03: Modify UART handler by adding input arg "readData"
//*********************************************************
// Routine: dv_IntReadUART1Data
// Usage: Interrupt handle routine to read UART1 data to buffer
// Input: readData: read data byte from UART
//**********************************************************
void dv_IntReadUART1Data(BYTE readData)
{
  int nNextIndex;

  //Ray 2015.11.02: Rewrite the routine to follow DV standard flow
  nNextIndex = g_nInBuffWriteIndex + 1;	//get next write buffer index

  if(nNextIndex>=UART1_RD_BUF_SIZE){
      nNextIndex = 0;			//If reach the end of buffer, wrap index back to start as it's a ring buffer
  }

  if(nNextIndex != g_nInBuffReadIndex){
      //Input buffer is not full. Write data byte to input buffer
      g_ucUart1Data[g_nInBuffWriteIndex] = readData;		//Read UART data from register

      //Go to next write buffer index
      g_nInBuffWriteIndex = nNextIndex;
  }
}


//*********************************************************
// Routine: dv_Serial_CopyRight_Para0
// Usage: Process RS232 0xF8 copyright command. Transmit "DIGITALVIEW LTD."
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_CopyRight_Para0(BYTE ucCmdPara)
{
  if(ucCmdPara=='C'){
	  dv_TxByteToUART('D');
	  dv_TxByteToUART('I');
	  dv_TxByteToUART('G');
	  dv_TxByteToUART('I');
	  dv_TxByteToUART('T');
	  dv_TxByteToUART('A');
	  dv_TxByteToUART('L');
	  dv_TxByteToUART('V');
	  dv_TxByteToUART('I');
	  dv_TxByteToUART('E');
	  dv_TxByteToUART('W');
	  dv_TxByteToUART(0x20);	//space
	  dv_TxByteToUART('L');
	  dv_TxByteToUART('T');
	  dv_TxByteToUART('D');
	  dv_TxByteToUART(0x2e);	//.
  }
}


//*********************************************************
// Routine: dv_TxByteToUART
// Usage: Transmit one byte to UART
// Input: ucData: Data sent to UART
//**********************************************************
void dv_TxByteToUART(BYTE ucData)
{
  //Ray 2016.06.24: send back data to UART only if ack is enabled
  if(g_ucSerialAcknowledge==TRUE){
    //Check if this is from UART1
    if(g_ucDVUart1Status==RCV_READY){
	putcharb(ucData);	//Transmit data to UART1
    }

  }
}


//Ray VOL 2017.06.19: dv_Serial_Volume_Para1
//*********************************************************
// Routine: dv_Serial_Volume_Para1
// Usage: Process RS232 0x80 volume control with parameter:
//	  'A'/'a': '+': increase, '-': decrease, 'r'/'R': reset, '?' query
//	   'M/n' : '1': unmute, '0': mute, 'r'/'R': reset, '?' query
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Volume_Para1(BYTE *ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucVol;
  BOOLEAN bIsAudioMuted;

  //All volume control command
  if(ucCmdPara[0]=='A'||ucCmdPara[0]=='a'){
      if(ucCmdPara[1] == '?'){
    	ucCmd = 0xff;			//Denote we need to send status to UART
      }
      else if(ucCmdPara[1] == 'R'||ucCmdPara[1] == 'r'){
	  ucCmd = 0xfe;				//Denote we need to change audio level
          stGenSetting.g_SoundSetting.Volume = DEFAULT_VOLUME_SETTING;		//Restore default volume level
      }
      else if(ucCmdPara[1] == '+'||ucCmdPara[1] == '-'){
	  ucCmd = 0xfe;						//Denote we need to change audio level
          if(ucCmdPara[1] == '+'){
              if ( stGenSetting.g_SoundSetting.Volume < MAX_NUM_OF_VOL_LEVEL )
              {
                  stGenSetting.g_SoundSetting.Volume++;			//Increase volume
              }
          }
          else{
              if ( stGenSetting.g_SoundSetting.Volume > 0 )
	      {
		  stGenSetting.g_SoundSetting.Volume --;		//Decrease volume

	      }
          }

      }

   //Check if we need to change audio
   if(ucCmd == 0xfe){
       ucCmd = 0xff;			//Denote we need to send status to UART
       bIsAudioMuted = msAPI_AUD_IsAudioMutedByUser();		//Get mute status
       if(bIsAudioMuted == TRUE){
	   //Cancel mute if it's muted before
      	      msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
      	      MApp_UiMenu_MuteWin_Hide();
      }
       msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME,  stGenSetting.g_SoundSetting.Volume, 0);		//Apply new volume

   }
   //Dump volume value to UART
   if(ucCmd == 0xff){
       dv_SerialTransmitHex(stGenSetting.g_SoundSetting.Volume);
   }

  }

  //Volume mute control
  if(ucCmdPara[0]=='M'||ucCmdPara[0]=='m'){
      if(ucCmdPara[1] == '0'||ucCmdPara[1] == '1'){
	//Mute volume
	if(ucCmdPara[1]=='0'){
	  msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
	  MApp_UiMenu_MuteWin_Show();
	}
	//Enable volume output
	if(ucCmdPara[1]=='1'){
	  msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
	  MApp_UiMenu_MuteWin_Hide();
	}
      }
      else if(ucCmdPara[1] == 'R'||ucCmdPara[1] == 'r'){
	  //If audio is muted, restore it to enable volume output
	  bIsAudioMuted = msAPI_AUD_IsAudioMutedByUser();		//Get mute status
	  if(bIsAudioMuted == TRUE){
	      //Cancel mute if it's muted before
	      msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
	      MApp_UiMenu_MuteWin_Hide();
	  }
      }

      //Dump volume mute status to UART
      bIsAudioMuted = msAPI_AUD_IsAudioMutedByUser();		//Get mute status
      if(bIsAudioMuted == TRUE){
	  ucVol = '0';
      }
      else{
	  ucVol = '1';
      }
      dv_TxByteToUART(ucVol);

  }
}

//Ray VOL 2017.06.19: dv_Serial_Volume_Para2
//*********************************************************
// Routine: dv_Serial_Volume_Para2
// Usage: Process RS232 0x80 volume control with parameter 'A'/'a'.
//	  nn: 2 hex digit input to set volume
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Volume_Para2(BYTE *ucCmdPara)
{
  BYTE ucVol;
  BOOLEAN bIsAudioMuted;

  //We only process all volume control command
  if(ucCmdPara[0]=='A'||ucCmdPara[0]=='a'){

      ucVol = dv_GetAsciiValue(&ucCmdPara[1]);			//transform ASCII to digit value
      //SP-4096 volume range is 0x00 to 0x64 (0~100)
      if(ucVol > MAX_NUM_OF_VOL_LEVEL){
	  ucVol = MAX_NUM_OF_VOL_LEVEL;		//Set it to max if input value is larger than max
      }

#if(_CUSTOMER_SVDU6==_ON)
          MApp_TV_ShowHotKeyOSD(HotKey_Volume);		//Ray HKY 2017.09.29: For SVUD6, we need to show volume OSD.
#endif

      bIsAudioMuted = msAPI_AUD_IsAudioMutedByUser();		//Get mute status
      if(bIsAudioMuted == TRUE){
	  //Cancel mute if it's muted before
	  msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
	  MApp_UiMenu_MuteWin_Hide();
      }

      stGenSetting.g_SoundSetting.Volume = ucVol;			//Set volume
      msAPI_AUD_AdjustAudioFactor(E_ADJUST_VOLUME, stGenSetting.g_SoundSetting.Volume, 0);	//Apply new volume
      dv_SerialTransmitHex(ucVol);

  }
  else{
      dv_SerialTransmitHex('?');	//Transmit '?' to denote unknown command
  }

}


//Ray BKL 2017.06.19
//*********************************************************
// Routine: dv_Serial_BackLightControl_Para0
// Usage: Process RS232 0xE0 backlight control command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default value
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_BackLightControl_Para0(BYTE ucCmdPara)
{
  int value1;
  BYTE ucCmd = 0;

  if(ucCmdPara == '?'){
	  ucCmd = 0xff;				//Denote we need to send backlight value to UART
  }
  else if(ucCmdPara == '+'){		//Increase backlight value
	  ucCmd = 0xff;	  			//Denote we need to send backlight value to UART
	  MApp_UiMenuFunc_AdjustBacklightPWM(ENABLE);		//Increase backlight level by 1
  }
  else if(ucCmdPara == '-'){		//Decrease backlight value
	  ucCmd = 0xff;	  			//Denote we need to send backlight value to UART
	  MApp_UiMenuFunc_AdjustBacklightPWM(DISABLE);		//Decrease backlight level by 1
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
	  ucCmd = 0xff;				//Denote we need to send backlight value to UART
	  stGenSetting.u8Backlight = 100;	//To reset backlight level to 100
	  Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));       //Apply reset backlight level
	  MApp_WriteDatabase(RM_GEN_BACKLIGHT_ADDRESS, (U8*)&(stGenSetting.u8Backlight), 1);    		//Save the value to Flash
  }
  if (ucCmd == 0xff){
	  //We need to send backlight value back to UART
	  value1 = stGenSetting.u8Backlight;
	  dv_SerialTransmitHex((BYTE)value1);
  }
}


//Ray BKL 2017.06.19
//*********************************************************
// Routine: dv_Serial_BackLightControl_Para1
// Usage: Process RS232 0xE0 backlight control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_BackLightControl_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 backlight range is 0x00 to 0x64 (0%~100%)
  if(ucValue > 100){
      ucValue = 100;		//Set it to max if input value is larger than max
  }

  //set new value
  stGenSetting.u8Backlight = ucValue;	//To reset backlight level to 100
  Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));        //Apply reset backlight level
  MApp_WriteDatabase(RM_GEN_BACKLIGHT_ADDRESS, (U8*)&(stGenSetting.u8Backlight), 1);    		//Save the value to Flash

  ucValue = stGenSetting.u8Backlight;
  dv_SerialTransmitHex(ucValue);	//Send value to UART

}


//*********************************************************
// Routine: dv_Serial_BackLightOnOff_Para0
// Usage: Process RS232 0xE1 backlight on/off command parameter byte 0 including:
//        ?: inquiry (0/1), 0: off, 1: on
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_BackLightOnOff_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;

  if(ucCmdPara == '?'){
	  ucCmd = 0xff;			//Denote we need to send backlight status to UART
  }
  else if(ucCmdPara == '0'){		//Turn off backlight
	  ucCmd = 0xff;			//Denote we need to send backlight status to UART
	  MApi_PNL_SetBackLight(DISABLE);	//Ray BKL 2017.02.17: Turn off backlight

  }
  else if(ucCmdPara == '1'||ucCmdPara == 'R'||ucCmdPara =='r'){		//Turn on backlight //Ray 2016.03.17: Default setting is to turn on backlight
	  ucCmd = 0xff;			//Denote we need to send backlight status to UART.
	  //Check if it's in power down mode
	  if((sFlagSimPowerShutDown&0x01)==0x01){
	      //Ray BKL 2017.02.20: After setting sFlagSimPowerShutDown bit 1 = 1, in the MApp_TopStateMachine.c, MApp_Standby_Init() will be called to turn on backlight and exit back to normal mode
	      sFlagSimPowerShutDown = ((sFlagSimPowerShutDown&0x01)|0x10);
	  }
	  //Check if it's power saving mode because of no signal
	  else if(sSaveSleepForPM==1){
	      //If yes, exit power saving mode and go back to normal
	      sSaveSleepForPM = 0;
	      MApp_SimplePowerSaving(0);	//Enable backlight and go back to normal mode
	  }
	  else{
	      //Else, it's in normal mode and just enable backlight
	      MApi_PNL_SetBackLight(ENABLE);	//Ray BKL 2017.02.17: Turn on backlight
	  }

  }

  if(ucCmd == 0xff){
	  if(GET_BACKLIGHT_ON()==ENABLE){
	      dv_TxByteToUART('1');
	  }
	  else{
	      dv_TxByteToUART('0');
	  }

  }

}

//Ray BRI 2017.05.08
//*********************************************************
// Routine: dv_Serial_Brightness_Para0
// Usage: Process RS232 0x81 brightness control command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default, m: query max, n: query min
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Brightness_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BOOLEAN action=0;

  ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  action = 1;			//1 = increase value
      }
      else{
	  action = 0;			//0 = decrease value
      }

      ST_PICTURE.u8Brightness = MApp_ZUI_ACT_DecIncValue(
          action,
          ST_PICTURE.u8Brightness, 0, 100, 1);				//Change brightness value
      MApp_XC_PQ_Set_Brightness(MAIN_WINDOW, TRUE);			//Apply new brightness value

  }

  else if(ucCmdPara == 'm'){
      dv_SerialTransmitHex(100);		//Send maximum brightness value (100%)
  }
  else if(ucCmdPara == 'n'){
      dv_SerialTransmitHex(0);			//Send minimum brightness value (0%)
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      //Reset all input ports to default brightness value
      MApp_DataBase_RestoreDefaultBrightness();
      MApp_XC_PQ_Set_Brightness(MAIN_WINDOW, TRUE);			//Apply new brightness value
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      dv_SerialTransmitHex((BYTE)ST_PICTURE.u8Brightness);  	//Dump current region's brightness value in 0%~100% to UART
  }
}

//Ray BRI 2017.05.08
//*********************************************************
// Routine: dv_Serial_Brightness_Para1
// Usage: Process RS232 0x81 brightness control. Set brightness value in 0~100% of current input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Brightness_Para1(BYTE *ucCmdPara)
{
  BYTE bValue;

  //Make sure we process this command at here if 1st parameter is not 'i' or 'o'
  if(ucCmdPara[0]!='i'&& ucCmdPara[0]!='o')
  {
      bValue = dv_GetAsciiValue(&ucCmdPara[0]);	//transform ASCII brightness to digit value
      //SP-4096 brightness range is 0~100
      if(bValue > 100){
	  bValue = 100;		//Set it to max if input value is larger than max
      }
      ST_PICTURE.u8Brightness = bValue;		//save input value to picture user mode
      MApp_XC_PQ_Set_Brightness(MAIN_WINDOW, TRUE);			//Apply new brightness value
      dv_SerialTransmitHex(bValue);		//Send brightness value back to UART
#if(_CUSTOMER_SVDU6==_ON)
      MApp_TV_ShowHotKeyOSD(HotKey_Brightness);		//Ray HKY 2017.09.29: For SVUD6, we need to show level on OSD.
#endif

  }
}

//Ray BRI 2017.05.08
//*********************************************************
// Routine: dv_Serial_Brightness_Para2
// Usage: Process RS232 0x81 brightness control. Read brightness value in 0~100% of specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Brightness_Para2(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  //Make sure we process this command at here if 1st parameter is 'o'
  if(ucCmdPara[0]=='o')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }
    //If valid input source is entered
    if(bSource!=0xff){
      //Show the brightness status the input source
      bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Brightness; 	//Read back picture user mode brightness value of user entered input source
      dv_SerialTransmitHex(bValue);		//Send brightness value back to UART
    }
  }
}


//Ray BRI 2017.05.08
//*********************************************************
// Routine: dv_Serial_Brightness_Para4
// Usage: Process RS232 0x81 brightness control. Set brightness value in 0~100% with user specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Brightness_Para4(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;


  //Make sure we process this command at here if 1st parameter is 'i'
  if(ucCmdPara[0]=='i')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }

    //If valid input source is entered
    if(bSource!=0xff){
	bValue = dv_GetAsciiValue(&ucCmdPara[3]);	//transform ASCII brightness to digit value
	//SP-4096 brightness range is 0~100
	if(bValue > 100){
	    bValue = 100;		//Set it to max if input value is larger than max
	}
	G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Brightness = bValue;		//save input value to picture user mode of entered input source
	//If entered input source is current source, the brightness level is changed immediately
	if(bSource==g_enDataInputSourceType[MAIN_WINDOW]){
	    MApp_XC_PQ_Set_Brightness(MAIN_WINDOW, TRUE);			//Apply new brightness value
	}

	//Show the brightness status the input source
	bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Brightness; 	//Read back picture user mode brightness value of user entered input source
	dv_SerialTransmitHex(bValue);		//Send brightness value back to UART
    }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
  }
}

//Ray VGA 2017.06.22: dv_Serial_Phase_Para0
//*********************************************************
// Routine: dv_Serial_Phase_Para0
// Usage: Process RS232 0x85 VGA phase control command parameter byte 0 including:
//        ?: inquiry (0~100), +: increase, -: decrease,
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Phase_Para0(BYTE ucCmdPara)
{

  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U16 u16ValueTmp;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;		//ENABLE action means increase
      }
      else{
	  ucAct = DISABLE;		//DISABLE action means increase
      }

      //Go to increase/decrease phase value
      u16ValueTmp = msAPI_Mode_GetPcPhaseValue(g_PcadcModeSetting[MAIN_WINDOW].u16Phase);	//Convert to 0~100 value
      u16ValueTmp = MApp_ZUI_ACT_DecIncValue(ucAct, u16ValueTmp, 0,100, 1);
      //Convert new value from 0~100 to real phase value and assign into phase variables
      stLMGenSetting.stMB.u16B7_PCMenu_Phase = g_PcadcModeSetting[MAIN_WINDOW].u16Phase=N100toReallyValue(u16ValueTmp,MIN_PC_PHASE, MAX_PC_PHASE );

      //Check if current input source is VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
       {
	  MApi_XC_ADC_SetPhase(stLMGenSetting.stMB.u16B7_PCMenu_Phase);		//Apply new phase
       }
      MApp_SetSaveModeDataFlag();	//Save new phase value to memory
  }

  if(ucCmd==0xff){
	//We need to send phase value back to UART
     dv_SerialTransmitHex(msAPI_Mode_GetPcPhaseValue(g_PcadcModeSetting[MAIN_WINDOW].u16Phase));
  }

}

//Ray VGA 2017.06.22: dv_Serial_Phase_Para1
//*********************************************************
// Routine: dv_Serial_Phase_Para1
// Usage: Process RS232 0x85 VGA phase control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Phase_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;
  U16 u16ValueTmp;

  //Only accept digit value between 0x00~0x64  (0~100)
  if(ucCmdPara[0]>='0'&& ucCmdPara[0]<='6')
  {
     ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
      //SVX-4096 phase range is 0x00 to 0x64 (0%~100%)
      if(ucValue > 100){
	  ucValue = 100;		//Set it to max if input value is larger than max
      }

      u16ValueTmp = g_PcadcModeSetting[MAIN_WINDOW].u16Phase;	//backup old value
      //Convert from 0~100 to real phase value and assign into phase variables
      stLMGenSetting.stMB.u16B7_PCMenu_Phase = g_PcadcModeSetting[MAIN_WINDOW].u16Phase=N100toReallyValue((U16)ucValue,MIN_PC_PHASE, MAX_PC_PHASE );

      //Check if current input source is VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
       {
           if(g_PcadcModeSetting[MAIN_WINDOW].u16Phase != u16ValueTmp)
           {
               MApi_XC_ADC_SetPhase(stLMGenSetting.stMB.u16B7_PCMenu_Phase);		//Apply new phase only if phase is really changed
           }
       }
      MApp_SetSaveModeDataFlag();	//Save new phase value to memory

      dv_SerialTransmitHex(msAPI_Mode_GetPcPhaseValue(g_PcadcModeSetting[MAIN_WINDOW].u16Phase));						//Send new value to UART

  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}

//Ray VGA 2017.06.23: dv_Serial_HorzPosn_Para0
//*********************************************************
// Routine: dv_Serial_HorzPosn_Para0
// Usage: Process RS232 0x86 VGA horizontal position control command parameter byte 0 including:
//        ?: inquiry (0~100), +: increase, -: decrease, R/r: reset to 50
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_HorzPosn_Para0(BYTE ucCmdPara)
{

  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U16 u16ValueTmp;


  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xfe;			//Denote we need to change horizontal position
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;		//ENABLE action means increase
      }
      else{
	  ucAct = DISABLE;		//DISABLE action means increase
      }

      u16ValueTmp = g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart;
      //Change horizontal start to 0~100 range
      u16ValueTmp = GetScale100Value(u16ValueTmp,MIN_PC_H_START(MAIN_WINDOW),MAX_PC_H_START(MAIN_WINDOW));
      u16ValueTmp = MApp_ZUI_ACT_DecIncValue(ucAct,u16ValueTmp,0,100,1);	//Increase/decrease horizontal start by 1


  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xfe;			//Denote we need to change horizontal position
      u16ValueTmp = 50;			//default value = 50
  }

  //Check if we need to change horizontal start position
  if(ucCmd==0xfe){
      ucCmd = 0xff;		//Denote we need to send status to UART
      //Change horizontal start from 0~100 back to original value
      g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart = N100toReallyValue(u16ValueTmp,MIN_PC_H_START(MAIN_WINDOW),MAX_PC_H_START(MAIN_WINDOW));
      //Apply new horizontal start if it's in VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
      {
	  MApi_XC_Set_PC_HPosition((g_PcadcModeSetting[MAIN_WINDOW].u16DefaultHStart* 2 -g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart), MAIN_WINDOW);
      }
      MApp_SetSaveModeDataFlag();	//Save new horizontal position to memory

  }

  if(ucCmd==0xff){
      //We need to send value back to UART
     u16ValueTmp = g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart;
     //Change horizontal start to 0~100 range
     u16ValueTmp = GetScale100Value(u16ValueTmp,MIN_PC_H_START(MAIN_WINDOW),MAX_PC_H_START(MAIN_WINDOW));
     dv_SerialTransmitHex((BYTE)u16ValueTmp);
  }

}


//*********************************************************
// Routine: dv_Serial_HorzPosn_Para1
// Usage: Process RS232 0x86 VGA horizontal position control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_HorzPosn_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  //Only accept digit value between 0x00~0x64  (0~100)
  if(ucCmdPara[0]>='0'&& ucCmdPara[0]<='6')
  {
     ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
      //SVX-4096 horizontal position range is 0x00 to 0x64 (0%~100%)
      if(ucValue > 100){
	  ucValue = 100;		//Set it to max if input value is larger than max
      }

      //Change horizontal start from 0~100 back to original value
      g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart = N100toReallyValue(ucValue,MIN_PC_H_START(MAIN_WINDOW),MAX_PC_H_START(MAIN_WINDOW));
      //Apply new horizontal start if it's in VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
      {
	  MApi_XC_Set_PC_HPosition((g_PcadcModeSetting[MAIN_WINDOW].u16DefaultHStart* 2 -g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalStart), MAIN_WINDOW);
      }
      MApp_SetSaveModeDataFlag();	//Save new horizontal position to memory
      dv_SerialTransmitHex(ucValue);						//Send new value to UART

  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}

//Ray VGA 2017.06.23: dv_Serial_VertPosn_Para0
//*********************************************************
// Routine: dv_Serial_VertPosn_Para0
// Usage: Process RS232 0x87 VGA vertical position control command parameter byte 0 including:
//        ?: inquiry (0~100), +: increase, -: decrease, R/r: reset
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_VertPosn_Para0(BYTE ucCmdPara)
{

  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U16 u16ValueTmp;


  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xfe;			//Denote we need to change vertical position
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;		//ENABLE action means increase
      }
      else{
	  ucAct = DISABLE;		//DISABLE action means increase
      }

      //Go to increase/decrease value. Since toal no. of step is less than 100, each increase/decrease unit maybe 1 or even more
      u16ValueTmp = g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart;
      g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart = MApp_ZUI_ACT_DecIncValue(ucAct,u16ValueTmp, MIN_PC_V_START, MAX_PC_V_START(MAIN_WINDOW), 1);
      //Change horizontal start to 0~100 range
      //u16ValueTmp = GetScale100Value(u16ValueTmp,MIN_PC_V_START,MAX_PC_V_START(MAIN_WINDOW));
      //u16ValueTmp = MApp_ZUI_ACT_DecIncValue(ucAct,u16ValueTmp,0,100,1);	//Increase/decrease vertical start by 1


  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xfe;			//Denote we need to change vertical position
      u16ValueTmp = 50;			//default value = 50
      //Change vertical start from 0~100 back to original value
      g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart = N100toReallyValue(u16ValueTmp,MIN_PC_V_START,MAX_PC_V_START(MAIN_WINDOW));
  }

  //Check if we need to change vertical start position
  if(ucCmd==0xfe){
      ucCmd = 0xff;		//Denote we need to send status to UART

      //Apply new vertical start if it's in VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
      {
	  MApi_XC_Set_PC_VPosition(g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart,MAIN_WINDOW);
      }
      MApp_SetSaveModeDataFlag();	//Save new vertical position to memory

  }

  if(ucCmd==0xff){
      //We need to send value back to UART
     u16ValueTmp = g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart;
     //Change vertical start to 0~100 range
     u16ValueTmp = GetScale100Value(u16ValueTmp,MIN_PC_V_START,MAX_PC_V_START(MAIN_WINDOW));
     dv_SerialTransmitHex((BYTE)u16ValueTmp);
  }

}


//Ray VGA 2017.06.23: dv_Serial_VertPosn_Para1
//*********************************************************
// Routine: dv_Serial_VertPosn_Para1
// Usage: Process RS232 0x87 VGA vertical position control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_VertPosn_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  //Only accept digit value between 0x00~0x64  (0~100)
  if(ucCmdPara[0]>='0'&& ucCmdPara[0]<='6')
  {
     ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
      //SVX-4096 horizontal position range is 0x00 to 0x64 (0%~100%)
      if(ucValue > 100){
	  ucValue = 100;		//Set it to max if input value is larger than max
      }
      //Change vertical start from 0~100 back to original value
      g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart = N100toReallyValue(ucValue,MIN_PC_V_START,MAX_PC_V_START(MAIN_WINDOW));
      //Apply new vertical start if it's in VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
      {
	  MApi_XC_Set_PC_VPosition(g_PcadcModeSetting[MAIN_WINDOW].u16VerticalStart,MAIN_WINDOW);
      }
      MApp_SetSaveModeDataFlag();	//Save new vertical position to memory
      dv_SerialTransmitHex(ucValue);						//Send new value to UART

  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}


//*********************************************************
// Routine: dv_Serial_VgaClock_Para0
// Usage: Process RS232 0x8B VGA clock control command parameter byte 0 including:
//        ?: inquiry (0~100), +: increase, -: decrease,
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_VgaClock_Para0(BYTE ucCmdPara)
{

  BYTE ucCmd = 0;
  BYTE ucAct = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;		//ENABLE action means increase
      }
      else{
	  ucAct = DISABLE;		//DISABLE action means increase
      }
      //Go to increase/decrease clock value. Since toal no. of step is less than 100, each increase/decrease unit maybe 1 or even more
      g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal =
          MApp_ZUI_ACT_DecIncValue(
              ucAct,
              g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal, MIN_PC_CLOCK(MAIN_WINDOW), MAX_PC_CLOCK(MAIN_WINDOW), 1);
      stLMGenSetting.stMB.u16B7_PCMenu_Size = g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal;

      //Check if current input source is VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
       {
	  MApi_XC_ADC_SetPcClock(stLMGenSetting.stMB.u16B7_PCMenu_Size);	//Apply new clock
       }
      MApp_SetSaveModeDataFlag();	//Save new phase value to memory
  }

  if(ucCmd==0xff){
	//We need to send clock value back to UART
     dv_SerialTransmitHex(msAPI_Mode_GetPcClockValue( MAIN_WINDOW, g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal));
  }


}


//*********************************************************
// Routine: dv_Serial_VgaClock_Para1
// Usage: Process RS232 0x8B VGA clock control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_VgaClock_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;
  U16 u16ValueTmp;

  //Only accept digit value between 0x00~0x64  (0~100)
  if(ucCmdPara[0]>='0'&& ucCmdPara[0]<='6')
  {
     ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
      //SVX-4096 phase range is 0x00 to 0x64 (0%~100%)
      if(ucValue > 100){
	  ucValue = 100;		//Set it to max if input value is larger than max
      }

      u16ValueTmp = g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal;	//backup old value
      //Convert from 0~100 to real phase value and assign into phase variables
      stLMGenSetting.stMB.u16B7_PCMenu_Size = g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal=N100toReallyValue((U16)ucValue,MIN_PC_CLOCK(MAIN_WINDOW), MAX_PC_CLOCK(MAIN_WINDOW));

      //Check if current input source is VGA
      if(IsSrcTypeVga(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)))
       {
           if(g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal != u16ValueTmp)
           {
               MApi_XC_ADC_SetPcClock(stLMGenSetting.stMB.u16B7_PCMenu_Size);	//Apply new clock only if phase is really changed
           }
       }
      MApp_SetSaveModeDataFlag();	//Save new clock value to memory

      dv_SerialTransmitHex(msAPI_Mode_GetPcClockValue( MAIN_WINDOW, g_PcadcModeSetting[MAIN_WINDOW].u16HorizontalTotal));						//Send new value to UART

  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}



//Ray SRC 2017.06.22
//*********************************************************
// Routine: dv_CheckExitDMPMode
// Usage: Check if it is currently in DMP mode before changing input source. If yes, exit DMP mode first.
//**********************************************************
void dv_CheckExitDMPMode(void)
{
  if( UI_INPUT_SOURCE_TYPE == UI_INPUT_SOURCE_DMP){
    ////Ray DMP 2017.06.22: Following are procedures to quit DMP mode
    MApp_ZUI_ACT_ShutdownOSD();
    MApp_DMP_Exit();
    MApp_PCMode_SetFirstNoSignalSource(UI_INPUT_SOURCE_NONE);	//Reset no signal source as NONE when exiting DMP
    MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS);
    MApp_InputSource_RestoreSource();	//Go back to previous source
  }

}

//Ray SRC 2017.05.08
//*********************************************************
// Routine: dv_Serial_Source_Para0
// Usage: Process RS232 0x98 main input source selection command parameter byte 0 including:
//        ?: inquiry, +: next source, -: previous source, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Source_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  WORD usInput;
  BOOLEAN action;
  //The input source change sequence is: HDMI1 <-> HDMI2 <-> HDMI3 <-> DVI<-> VGA
  E_UI_INPUT_SOURCE UI_SRC[]={UI_INPUT_SOURCE_HDMI,UI_INPUT_SOURCE_HDMI2,UI_INPUT_SOURCE_HDMI4,UI_INPUT_SOURCE_HDMI3,UI_INPUT_SOURCE_RGB};
  BYTE bNoOfSrc = sizeof(UI_SRC)/sizeof(UI_SRC[0]);
  BYTE currentSource,newSource;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      dv_CheckExitDMPMode();			//Check and exit DMP mode
      MApp_ZUI_ACT_InputSourceSwitch(UI_INPUT_SOURCE_HDMI);	//Change to new input source
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      dv_CheckExitDMPMode();		//Check and exit DMP mode
      if(ucCmdPara == '+'){
	  action = 1;			//1 = increase value
      }
      else{
	  action = 0;			//0 = decrease value
      }

      for(currentSource=0;currentSource<bNoOfSrc;currentSource++){
	  if(UI_SRC[currentSource]==UI_INPUT_SOURCE_TYPE){
	      break;
	  }
      }

      //Ray SRC 2017.06.20: If currentSource is max and increase, change to min
      if(currentSource==4&&ucCmdPara == '+'){
	  newSource = 0;
      }
      //Ray SRC 2017.06.20: If currentSource is min and decrease, change to max
      else if(currentSource==0&&ucCmdPara == '-'){
	  newSource = 4;
      }
      else{
	newSource = MApp_ZUI_ACT_DecIncValue(
	    action,
	    (U16)currentSource, 0, 4, 1);		//Increase/decrease input source value by 1
      }
      MApp_ZUI_ACT_InputSourceSwitch(UI_SRC[newSource]);	//Change to new input source
  }

  if(ucCmd==0xff)
  {
      //Send the input source value to UART
      usInput = dv_DataInputSourceValue(g_enDataInputSourceType[MAIN_WINDOW]);
      dv_TxByteToUART((usInput&0xff));
      dv_TxByteToUART((BYTE)((usInput&0xff00)>>8));

  }

}

//Ray SRC 2017.05.09
//*********************************************************
// Routine: dv_Serial_Source_Para1
// Usage: Process RS232 0x98 input source 2-byte value input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Source_Para1(BYTE *ucCmdPara)
{
  BYTE bValue,bSource;
  WORD usInput;
  E_UI_INPUT_SOURCE UI_SRC[]={UI_INPUT_SOURCE_HDMI,UI_INPUT_SOURCE_HDMI2,UI_INPUT_SOURCE_HDMI4,UI_INPUT_SOURCE_HDMI3,UI_INPUT_SOURCE_RGB};
  BYTE bNoOfSrc = sizeof(UI_SRC)/sizeof(UI_SRC[0]);

  bSource = 0xff;	//Set a invalid value first
  ucCmdPara++;
  usInput = (BYTE)*ucCmdPara;
  usInput = (usInput<<8) &0xff00;
  ucCmdPara--;
  usInput = usInput|(BYTE)*ucCmdPara;


  //Translate to firmware code input source value
  for(bValue=0;bValue<bNoOfSrc;bValue++){
    if(dv_UiInputSourceValue(UI_SRC[bValue])==usInput){
	  bSource = bValue;
    }
  }

  //Check if user input the correct source value
  if(bSource!=0xff){
      dv_CheckExitDMPMode();				//Check and exit DMP mode
      MApp_ZUI_ACT_InputSourceSwitch(UI_SRC[bSource]);	//Change to new input source

  }

  //Send the input source value to UART
  usInput = dv_UiInputSourceValue(UI_SRC[bSource]);
  dv_TxByteToUART((usInput&0xff));
  dv_TxByteToUART((BYTE)((usInput&0xff00)>>8));

}

//Ray ASS 2017.05.09
//*********************************************************
// Routine: dv_Serial_AutoSource_Para0
// Usage: Process RS232 0x99 auto source seek setting command
//        ?: inquiry,0: disable, 1: enable, R/r: reset to default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_AutoSource_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_AUTO_SOURCE_SEEK(DEFAULT_AUTO_SOURCE_SEEK);		//Ray ASS 2017.03.31: default auto source seek is ON
  }
  else if(ucCmdPara == '0'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_AUTO_SOURCE_SEEK(DISABLE);		//Disable auto source seek
  }
  else if(ucCmdPara == '1'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_AUTO_SOURCE_SEEK(ENABLE);		//Enable auto source seek
  }


  if(ucCmd==0xff)
  {
      dv_TxByteToUART(GET_AUTO_SOURCE_SEEK()+0x30);	//Send Auto source seek state to UART (+0x30 to transform 0,1 to their ASCII value)
  }

}

//Ray DMP 2017.06.22
//*********************************************************
// Routine: dv_Serial_AutoSource_Para2
// Usage: Process RS232 0x99 Auto source seek command.  We treat failover on/off as enable/disable DMP input source
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_AutoSource_Para2(BYTE *ucCmdPara)
{
  BYTE ucCmd = 0;
  WORD usInput;

  //Get the input source
  usInput = (BYTE)ucCmdPara[1];
  usInput = (usInput<<8) &0xff00;
  usInput = usInput|(BYTE)ucCmdPara[0];

  //If failover (DMP) source is entered
  if(usInput ==0x3159){
      if(ucCmdPara[2]=='?'){
	  ucCmd = 0xff;
      }
      if(ucCmdPara[2]=='1'){
	  ucCmd = 0xff;
	  SET_FAIL_OVER(ENABLE);		//Enable failover
      }
      if(ucCmdPara[2]=='0'){
	  ucCmd = 0xff;
	  SET_FAIL_OVER(DISABLE);		//Disable failover
      }


      if(ucCmd==0xff){
	  dv_TxByteToUART(GET_FAIL_OVER()+0x30);	//Dump Failover status

      }

  }

}

//*********************************************************
// Routine: dv_Serial_Info_Para0
// Usage: Process RS232 0xcb query command
//        0: read version no.; 1: read PCBA no.; 2: read EEPROM support;
//        3: read revision no.
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Info_Para0(BYTE ucCmdPara)
{
  BYTE i;
  char ucVersion[30];

  if(ucCmdPara == '0'){			//Read version no.
    for(i=0;i<30;i++){
	ucVersion[i]=0;		//Init array
    }
    strcpy(ucVersion,DigitalViewOSDVersion);	//Copy OSD version no.
    strcat(ucVersion,CustomerSubVersionNumber); //Add customer sub version no.
    for(i=0;i<30;i++){
	if(ucVersion[i]!=0){
	    dv_TxByteToUART(ucVersion[i]);
	}
    }
  }

  if(ucCmdPara == '1'){			//Read PCBA no.
    for(i=0;i<30;i++){
	ucVersion[i]=0;		//Init array
    }
    strcpy(ucVersion,NameDigitalViewBoardPCBA);
    for(i=0;i<30;i++){
	if(ucVersion[i]!=0){
	    dv_TxByteToUART(ucVersion[i]);
	}
    }
  }

  if(ucCmdPara == '2'){			//Check if external memory 24C256 supported
      dv_TxByteToUART('0');		//Reply not support
  }

   if(ucCmdPara == '3'){			//Read Revision no.
    for(i=0;i<30;i++){
	ucVersion[i]=0;				//Init array
    }
    strcpy(ucVersion,DigitalViewRevisionNumber);
    for(i=1;i<30;i++){				//i=1, so don't send "." to UART
	if(ucVersion[i]!=0){
	    dv_TxByteToUART(ucVersion[i]);
	}
    }
  }


}

//Ray CRS 2017.05.09
//*********************************************************
// Routine: dv_Serial_Contrast_Para1
// Usage: Process RS232 0x82 contrast control.
//	'?': query, '+': increase, '-': decrease, 'm': max query, 'n': min query, 'R/r': reset
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Contrast_Para1(BYTE *ucCmdPara)
{
  BYTE ucCmd = 0;
  BOOLEAN action=0;
  ucCmd = 0;

  if(ucCmdPara[0]!='A'|| ucCmdPara[0]!='a')
  {
      if(ucCmdPara[1] == '?'){
    	ucCmd = 0xff;			//Denote we need to send status to UART
      }
      else if(ucCmdPara[1] == '+'||ucCmdPara[1] == '-'){
          ucCmd = 0xff;			//Denote we need to send status to UART
          if(ucCmdPara[1] == '+'){
    	  action = 1;			//1 = increase value
          }
          else{
    	  action = 0;			//0 = decrease value
          }

          ST_PICTURE.u8Contrast = MApp_ZUI_ACT_DecIncValue(
              action,
              ST_PICTURE.u8Contrast, 0, 100, 1);			//Change contrast value
          MApp_XC_PQ_Set_Contrast( MAIN_WINDOW, FALSE);			//Apply new contrast value
      }

      else if(ucCmdPara[1] == 'm'){
          dv_SerialTransmitHex(100);		//Send maximum contrast value (100%)
      }
      else if(ucCmdPara[1] == 'n'){
          dv_SerialTransmitHex(0);		//Send minimum contrast value (0%)
      }
      else if(ucCmdPara[1] == 'R'||ucCmdPara[1] == 'r'){
          ucCmd = 0xff;			//Denote we need to send status to UART
          //Reset all input ports to default contrast value
          MApp_DataBase_RestoreDefaultContrast();
          MApp_XC_PQ_Set_Contrast( MAIN_WINDOW, FALSE);			//Apply new contrast value
      }
      if(ucCmd==0xff){
    	//We need to send value back to UART
          dv_SerialTransmitHex((BYTE)ST_PICTURE.u8Contrast);  	//Dump current region's contrast value in 0%~100% to UART
      }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }


}

//Ray CRS 2017.05.09
//*********************************************************
// Routine: dv_Serial_Contrast_Para2
// Usage: Process RS232 0x82 contrast control 2-digit input to set current input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Contrast_Para2(BYTE *ucCmdPara)
{
  BYTE ucValue;

  if(ucCmdPara[0]!='A'|| ucCmdPara[0]!='a')
  {
      if(ucCmdPara[1]!='i'&&ucCmdPara[1]!='o')
      {
	 ucValue = dv_GetAsciiValue(&ucCmdPara[1]);			//transform ASCII to digit value
	  //SP-4096 contrast range is 0~100
	  if(ucValue > 100){
	      ucValue = 100;		//Set it to max if input value is larger than max
	  }
	  ST_PICTURE.u8Contrast = ucValue;			//save input value to picture user mode
	  MApp_XC_PQ_Set_Contrast( MAIN_WINDOW, FALSE);		//Apply new contrast value
	  dv_SerialTransmitHex(ucValue);			//Send contrast value back to UART
      }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}

//Ray CRS 2017.05.09
//*********************************************************
// Routine: dv_Serial_Contrast_Para3
// Usage: Process RS232 0x82 contrast control. Read contrast value in 0~100% of specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Contrast_Para3(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  if(ucCmdPara[0]!='A'|| ucCmdPara[0]!='a')
  {
    //Make sure we process this command at here if 1st parameter is 'o'
    if(ucCmdPara[1]=='o')
    {
      //Get the input source
      usInput = (BYTE)ucCmdPara[3];
      usInput = (usInput<<8) &0xff00;
      usInput = usInput|(BYTE)ucCmdPara[2];
      //Translate to firmware code input source value
      for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
	if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	    bSource = bValue;
	}
      }
      //If valid input source is entered
      if(bSource!=0xff){
	//Show the brightness status the input source
	bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Contrast; 	//Read back picture user mode contrast value of user entered input source
	dv_SerialTransmitHex(bValue);		//Send brightness value back to UART
      }
    }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
   }
}


//Ray CRS 2017.05.09
//*********************************************************
// Routine: dv_Serial_Contrast_Para5
// Usage: Process RS232 0x82 contrast control. Set contrast value in 0~100% with user specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Contrast_Para5(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  if(ucCmdPara[0]!='A'|| ucCmdPara[0]!='a')
  {
    //Make sure we process this command at here if 1st parameter is 'i'
    if(ucCmdPara[1]=='i')
    {
      //Get the input source
      usInput = (BYTE)ucCmdPara[3];
      usInput = (usInput<<8) &0xff00;
      usInput = usInput|(BYTE)ucCmdPara[2];
      //Translate to firmware code input source value
      for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
	if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	    bSource = bValue;
	}
      }

      //If valid input source is entered
      if(bSource!=0xff){
	  bValue = dv_GetAsciiValue(&ucCmdPara[4]);	//transform ASCII contrast to digit value
	  //SP-4096 contrast range is 0~100
	  if(bValue > 100){
	      bValue = 100;		//Set it to max if input value is larger than max
	  }
	  G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Contrast = bValue;		//save input value to picture user mode of entered input source
	  //If entered input source is current source, the contrast level is changed immediately
	  if(bSource==g_enDataInputSourceType[MAIN_WINDOW]){
	      MApp_XC_PQ_Set_Contrast( MAIN_WINDOW, FALSE);		//Apply new contrast value
	  }

	  //Show the contrast status the input source
	  bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Contrast; 	//Read back picture user mode contrast value of user entered input source
	  dv_SerialTransmitHex(bValue);		//Send contrast value back to UART
      }
    }
    else{
	dv_SerialTransmitHex('?');	//Tx unknown command
    }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
   }

}

//Ray SAT 2017.05.09
//*********************************************************
// Routine: dv_Serial_ColorSat_Para0
// Usage: Process RS232 0x83 color saturation control command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default, m: query max, n: query min
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_ColorSat_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BOOLEAN action=0;

  ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  action = 1;			//1 = increase value
      }
      else{
	  action = 0;			//0 = decrease value
      }

      ST_PICTURE.u8Saturation = MApp_ZUI_ACT_DecIncValue(
          action,
          ST_PICTURE.u8Saturation, 0, 100, 1);				//Change brightness value
      MApi_XC_ACE_PicSetSaturation(MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW),  msAPI_Mode_PictureSaturationN100toReallyValue(ST_PICTURE.u8Saturation) );  //Apply new saturation value

  }

  else if(ucCmdPara == 'm'){
      dv_SerialTransmitHex(100);		//Send maximum saturation value (100%)
  }
  else if(ucCmdPara == 'n'){
      dv_SerialTransmitHex(0);			//Send minimum saturation value (0%)
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      //Reset all input ports to default saturation value
      MApp_DataBase_RestoreDefaultSaturation();
      MApi_XC_ACE_PicSetSaturation(MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW),  msAPI_Mode_PictureSaturationN100toReallyValue(ST_PICTURE.u8Saturation) );  //Apply new saturation value
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      dv_SerialTransmitHex((BYTE)ST_PICTURE.u8Saturation);  	//Dump current region's saturation value in 0%~100% to UART
  }
}

//Ray SAT 2017.05.09
//*********************************************************
// Routine: dv_Serial_ColorSat_Para1
// Usage: Process RS232 0x83 saturation control. Set saturation value in 0~100% of current input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_ColorSat_Para1(BYTE *ucCmdPara)
{
  BYTE bValue;

  //Make sure we process this command at here if 1st parameter is not 'i' or 'o'
  if(ucCmdPara[0]!='i'&& ucCmdPara[0]!='o')
  {
      bValue = dv_GetAsciiValue(&ucCmdPara[0]);	//transform ASCII saturation to digit value
      //SP-4096 saturation range is 0~100
      if(bValue > 100){
	  bValue = 100;		//Set it to max if input value is larger than max
      }
      ST_PICTURE.u8Saturation = bValue;		//save input value to picture user mode
      MApi_XC_ACE_PicSetSaturation(MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW),  msAPI_Mode_PictureSaturationN100toReallyValue(ST_PICTURE.u8Saturation) );  //Apply new saturation value
      dv_SerialTransmitHex(bValue);		//Send saturation value back to UART

  }
}

//Ray SAT 2017.05.09
//*********************************************************
// Routine: dv_Serial_ColorSat_Para2
// Usage: Process RS232 0x83 saturation control. Read saturation value in 0~100% of specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_ColorSat_Para2(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  //Make sure we process this command at here if 1st parameter is 'o'
  if(ucCmdPara[0]=='o')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }
    //If valid input source is entered
    if(bSource!=0xff){
      //Show the saturation status the input source
      bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Saturation; 	//Read back picture user mode saturation value of user entered input source
      dv_SerialTransmitHex(bValue);		//Send saturation value back to UART
    }
  }
}


//Ray SAT 2017.05.08
//*********************************************************
// Routine: dv_Serial_ColorSat_Para4
// Usage: Process RS232 0x83 saturation control. Set saturation value in 0~100% with user specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_ColorSat_Para4(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;


  //Make sure we process this command at here if 1st parameter is 'i'
  if(ucCmdPara[0]=='i')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }

    //If valid input source is entered
    if(bSource!=0xff){
	bValue = dv_GetAsciiValue(&ucCmdPara[3]);	//transform ASCII saturation to digit value
	//SP-4096 saturation range is 0~100
	if(bValue > 100){
	    bValue = 100;		//Set it to max if input value is larger than max
	}
	G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Saturation = bValue;		//save input value to picture user mode of entered input source
	//If entered input source is current source, the saturation level is changed immediately
	if(bSource==g_enDataInputSourceType[MAIN_WINDOW]){
	    MApi_XC_ACE_PicSetSaturation(MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW),  msAPI_Mode_PictureSaturationN100toReallyValue(ST_PICTURE.u8Saturation) );  //Apply new saturation value
	}

	//Show the saturation status the input source
	bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Saturation; 	//Read back picture user mode saturation value of user entered input source
	dv_SerialTransmitHex(bValue);		//Send saturation value back to UART
    }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
  }
}


//Ray HUE 2017.05.12
//*********************************************************
// Routine: dv_Serial_Hue_Para0
// Usage: Process RS232 0x84 hue control command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default, m: query max, n: query min
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Hue_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BOOLEAN action=0;

  ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  action = 1;			//1 = increase value
      }
      else{
	  action = 0;			//0 = decrease value
      }

      ST_PICTURE.u8Hue = MApp_ZUI_ACT_DecIncValue(
          action,
          ST_PICTURE.u8Hue, 0, 100, 1);				//Change brightness value
      MApi_XC_ACE_PicSetHue( MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW), msAPI_Mode_PictureHueN100toReallyValue(ST_PICTURE.u8Hue) );  //Apply new hue value

  }

  else if(ucCmdPara == 'm'){
      dv_SerialTransmitHex(100);		//Send maximum saturation value (100%)
  }
  else if(ucCmdPara == 'n'){
      dv_SerialTransmitHex(0);			//Send minimum saturation value (0%)
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      //Reset all input ports to default hue value
      MApp_DataBase_RestoreDefaultHue();
      MApi_XC_ACE_PicSetHue( MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW), msAPI_Mode_PictureHueN100toReallyValue(ST_PICTURE.u8Hue) ); //Apply new hue value
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      dv_SerialTransmitHex((BYTE)ST_PICTURE.u8Hue);  	//Dump current region's hue value in 0%~100% to UART
  }
}

//Ray HUE 2017.05.12
//*********************************************************
// Routine: dv_Serial_Hue_Para1
// Usage: Process RS232 0x84 hue control. Set hue value in 0~100% of current input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Hue_Para1(BYTE *ucCmdPara)
{
  BYTE bValue;

  //Make sure we process this command at here if 1st parameter is not 'i' or 'o'
  if(ucCmdPara[0]!='i'&& ucCmdPara[0]!='o')
  {
      bValue = dv_GetAsciiValue(&ucCmdPara[0]);	//transform ASCII hue to digit value
      //SP-4096 saturation range is 0~100
      if(bValue > 100){
	  bValue = 100;		//Set it to max if input value is larger than max
      }
      ST_PICTURE.u8Hue = bValue;		//save input value to picture user mode
      MApi_XC_ACE_PicSetHue( MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW), msAPI_Mode_PictureHueN100toReallyValue(ST_PICTURE.u8Hue) );  //Apply new hue value
      dv_SerialTransmitHex(bValue);		//Send hue value back to UART

  }
}

//Ray HUE 2017.05.12
//*********************************************************
// Routine: dv_Serial_Hue_Para2
// Usage: Process RS232 0x84 hue control. Read hue value in 0~100% of specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Hue_Para2(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  //Make sure we process this command at here if 1st parameter is 'o'
  if(ucCmdPara[0]=='o')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }
    //If valid input source is entered
    if(bSource!=0xff){
      //Show the hue status the input source
      bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Hue; 	//Read back picture user mode hue value of user entered input source
      dv_SerialTransmitHex(bValue);		//Send hue value back to UART
    }
  }
}


//Ray HUE 2017.05.08
//*********************************************************
// Routine: dv_Serial_Hue_Para4
// Usage: Process RS232 0x84 hue control. Set hue value in 0~100% with user specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Hue_Para4(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;


  //Make sure we process this command at here if 1st parameter is 'i'
  if(ucCmdPara[0]=='i')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }

    //If valid input source is entered
    if(bSource!=0xff){
	bValue = dv_GetAsciiValue(&ucCmdPara[3]);	//transform ASCII hue to digit value
	//SP-4096 hue range is 0~100
	if(bValue > 100){
	    bValue = 100;		//Set it to max if input value is larger than max
	}
	G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Hue = bValue;		//save input value to picture user mode of entered input source
	//If entered input source is current source, the hue level is changed immediately
	if(bSource==g_enDataInputSourceType[MAIN_WINDOW]){
	    MApi_XC_ACE_PicSetHue( MAIN_WINDOW, MApi_XC_IsYUVSpace(MAIN_WINDOW), msAPI_Mode_PictureHueN100toReallyValue(ST_PICTURE.u8Hue) );  //Apply new hue value
	}

	//Show the hue status the input source
	bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Hue; 	//Read back picture user mode hue value of user entered input source
	dv_SerialTransmitHex(bValue);		//Send hue value back to UART
    }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
  }
}


//Ray SHP 2017.05.12
//*********************************************************
// Routine: dv_Serial_Sharpness_Para0
// Usage: Process RS232 0x8a sharpness control command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default, m: query max, n: query min
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Sharpness_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BOOLEAN action=0;

  ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  action = 1;			//1 = increase value
      }
      else{
	  action = 0;			//0 = decrease value
      }

      ST_PICTURE.u8Sharpness = MApp_ZUI_ACT_DecIncValue(
          action,
          ST_PICTURE.u8Sharpness, 0, 100, 1);				//Change sharpness value
      MApi_XC_ACE_PicSetSharpness( MAIN_WINDOW, msAPI_Mode_PictureSharpnessN100toReallyValue(ST_PICTURE.u8Sharpness) );  //Apply new sharpness value

  }

  else if(ucCmdPara == 'm'){
      dv_SerialTransmitHex(100);		//Send maximum sharpness value (100%)
  }
  else if(ucCmdPara == 'n'){
      dv_SerialTransmitHex(0);			//Send minimum sharpness value (0%)
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      //Reset all input ports to default sharpness value
      MApp_DataBase_RestoreDefaultSharpness();
      MApi_XC_ACE_PicSetSharpness( MAIN_WINDOW, msAPI_Mode_PictureSharpnessN100toReallyValue(ST_PICTURE.u8Sharpness) ); 	//Apply new sharpness value
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      dv_SerialTransmitHex((BYTE)ST_PICTURE.u8Sharpness);  	//Dump current region's sharpness value in 0%~100% to UART
  }
}

//Ray SHP 2017.05.12
//*********************************************************
// Routine: dv_Serial_Sharpness_Para1
// Usage: Process RS232 0x8a sharpness control. Set sharpness value in 0~100% of current input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Sharpness_Para1(BYTE *ucCmdPara)
{
  BYTE bValue;

  //Make sure we process this command at here if 1st parameter is not 'i' or 'o'
  if(ucCmdPara[0]!='i'&& ucCmdPara[0]!='o')
  {
      bValue = dv_GetAsciiValue(&ucCmdPara[0]);	//transform ASCII sharpness to digit value
      //SP-4096 sharpness range is 0~100
      if(bValue > 100){
	  bValue = 100;		//Set it to max if input value is larger than max
      }
      ST_PICTURE.u8Sharpness = bValue;		//save input value to picture user mode
      MApi_XC_ACE_PicSetSharpness( MAIN_WINDOW, msAPI_Mode_PictureSharpnessN100toReallyValue(ST_PICTURE.u8Sharpness) ); 	//Apply new sharpness value
      dv_SerialTransmitHex(bValue);		//Send sharpness value back to UART

  }
}

//Ray SHP 2017.05.12
//*********************************************************
// Routine: dv_Serial_Sharpness_Para2
// Usage: Process RS232 0x8a sharpness control. Read sharpness value in 0~100% of specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Sharpness_Para2(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  //Make sure we process this command at here if 1st parameter is 'o'
  if(ucCmdPara[0]=='o')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }
    //If valid input source is entered
    if(bSource!=0xff){
      //Show the sharpness status the input source
      bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Sharpness; 	//Read back picture user mode sharpness value of user entered input source
      dv_SerialTransmitHex(bValue);		//Send sharpness value back to UART
    }
  }
}


//Ray SHP 2017.05.08
//*********************************************************
// Routine: dv_Serial_Sharpness_Para4
// Usage: Process RS232 0x84 sharpness control. Set sharpness value in 0~100% with user specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Sharpness_Para4(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;


  //Make sure we process this command at here if 1st parameter is 'i'
  if(ucCmdPara[0]=='i')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }

    //If valid input source is entered
    if(bSource!=0xff){
	bValue = dv_GetAsciiValue(&ucCmdPara[3]);	//transform ASCII sharpness to digit value
	//SP-4096 sharpness range is 0~100
	if(bValue > 100){
	    bValue = 100;		//Set it to max if input value is larger than max
	}
	G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Sharpness = bValue;		//save input value to picture user mode of entered input source
	//If entered input source is current source, the sharpness level is changed immediately
	if(bSource==g_enDataInputSourceType[MAIN_WINDOW]){
	    MApi_XC_ACE_PicSetSharpness( MAIN_WINDOW, msAPI_Mode_PictureSharpnessN100toReallyValue(ST_PICTURE.u8Sharpness) ); 	//Apply new sharpness value
	}

	//Show the sharpness status the input source
	bValue = G_VEDIO_SETTING[bSource].astPicture[PICTURE_USER].u8Sharpness; 	//Read back picture user mode sharpness value of user entered input source
	dv_SerialTransmitHex(bValue);		//Send sharpness value back to UART
    }
  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
  }
}

//Ray ART 2017.05.23:
//*********************************************************
// Routine: dv_Serial_ScaleMode_Para0
// Usage: Process RS232 0x8c aspect ratio command
//        '?': Query, 'R'|'r': reset, '0'(1:1),'1'(fill screen),'9'(4:3),;A'(16:9) to set aspect ratio
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void  dv_Serial_ScaleMode_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucARatio;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;
      MApp_DataBase_RestoreDefaultAspectRatio();					//Restore aspect ratio
      MApp_Scaler_Setting_SetVDScale( ST_VIDEO.eAspectRatio , MAIN_WINDOW );		//adjust aspect ratio
  }
  else if(ucCmdPara == '0'||ucCmdPara == '1'||ucCmdPara == '9'
      ||ucCmdPara == 'A'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      switch(ucCmdPara){
	case '0':			//1:1 aspect ratio
	  ST_VIDEO.eAspectRatio = EN_AspectRatio_Point_to_Point;
	  break;
	case '1':			//fill screen aspect ratio
	  ST_VIDEO.eAspectRatio = EN_AspectRatio_JustScan;
	  break;
	case '9':			//4:3 aspect ratio
	  ST_VIDEO.eAspectRatio = EN_AspectRatio_4X3;
	  break;
	case 'A':			//16:9 aspect ratio
	  ST_VIDEO.eAspectRatio = EN_AspectRatio_16X9;
	  break;
	default:
	  break;
      }
      MApp_Scaler_Setting_SetVDScale( ST_VIDEO.eAspectRatio , MAIN_WINDOW );		//adjust aspect ratio

  }
  if (ucCmd == 0xff){		//See if require to send aspect ratio setting to UART
      ucARatio = '1';
      ucCmd = ST_VIDEO.eAspectRatio;
      switch(ucCmd){
	case EN_AspectRatio_Point_to_Point:
	  ucARatio = '0';
	  break;
	case EN_AspectRatio_JustScan:
	  ucARatio = '1';
	  break;
	case EN_AspectRatio_4X3:
	  ucARatio = '9';
	  break;
	case EN_AspectRatio_16X9:
	  ucARatio = 'A';
	  break;
	default:
	  break;
      }
      dv_TxByteToUART(ucARatio);	//Send to UART
  }

}

//Ray ORI 2017.06.15: RS-232 0x8e image orientation command
//*********************************************************
// Routine: dv_Serial_DispOrient_Para0
// Usage: Process RS232 0x8e display orientation command
//        '?': Query, 'R'|'r': reset,
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void  dv_Serial_DispOrient_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd=0;
  BYTE ucRotation=0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;
      SET_IMG_ORIENTATION(MIRROR_NORMAL);	//Restore to normal
      dv_SetImageOrientation();		//Apply image orientation setting
  }


  else if(ucCmdPara == '0'||ucCmdPara == '1'||ucCmdPara == '2'||ucCmdPara == '3'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      switch(ucCmdPara){
	case '0':
	  if(GET_IMG_ORIENTATION()!=MIRROR_NORMAL){
	      ucCmd = 0xfc;				//Denote we need to change the video
	      SET_IMG_ORIENTATION(MIRROR_NORMAL);	//Restore to normal degree
	  }
	  break;
	case '1':
	  if(GET_IMG_ORIENTATION()!=MIRROR_V_ONLY){
	      ucCmd = 0xfc;				//Denote we need to change the video
	      SET_IMG_ORIENTATION(MIRROR_V_ONLY);	//Do vertical flip
	  }

	  break;
	case '2':
	  if(GET_IMG_ORIENTATION()!=MIRROR_H_ONLY){
	      ucCmd = 0xfc;				//Denote we need to change the video
	      SET_IMG_ORIENTATION(MIRROR_H_ONLY);	//Do horizontal flip
	  }
	  break;
	case '3':
	  if(GET_IMG_ORIENTATION()!=MIRROR_HV){
	      ucCmd = 0xfc;				//Denote we need to change the video
	      SET_IMG_ORIENTATION(MIRROR_HV);		//Do vertical and horizontal flip
	  }
	  break;

	default:
	  break;
      }
      //Check if we need to rotate the video
      if(ucCmd==0xfc){
	ucCmd = 0xff;			//Denote we need to send status to UART
	dv_SetImageOrientation();	//Apply image orientation setting
      }
  }
  if (ucCmd == 0xff){		//See if require to send image rotation setting to UART
      ucCmd = GET_IMG_ORIENTATION();
      switch(ucCmd){
	case MIRROR_NORMAL:
	  ucRotation = '0';					//'0' = 0x30
	  break;
	case MIRROR_V_ONLY:
	  ucRotation = '1';
	  break;
	case MIRROR_H_ONLY:
	  ucRotation = '2';
	  break;
	case MIRROR_HV:
	  ucRotation = '3';
	  break;
	default:
	  break;
      }
      dv_TxByteToUART(ucRotation);	//Send to UART
  }

}


//Ray GAM 2017.05.12: Function below only has dump response to serve for Controller Utility. Actual function needed to be implemented later.
//*********************************************************
// Routine: dv_Serial_Gamma_Para0
// Usage: Process RS232 0x9d gamma correction command
//        ?: inquiry,
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Gamma_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucValue=_GAMMA_22;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART

  }

  else if(ucCmdPara == '5'){
      ucCmd = 0xfe;				//Denote we need to set gamma value
      ucValue = _GAMMA_18;			//Set gamma 1.8
  }
  else if(ucCmdPara == '7'){
      ucCmd = 0xfe;				//Denote we need to set gamma value
      ucValue = _GAMMA_20;			//Set gamma 2.0
  }
  else if(ucCmdPara == '2'){
      ucCmd = 0xfe;				//Denote we need to set gamma value
      ucValue = _GAMMA_22;			//Set gamma 2.2
  }
  else if(ucCmdPara == 'A'){
      ucCmd = 0xfe;				//Denote we need to set gamma value
      ucValue = _GAMMA_24;			//Set gamma 2.4
  }

  //Check if we need to set gamma
  if(ucCmd == 0xfe){
     ucCmd = 0xff;				//Denote we need to send status to UART

  }

  //Check if we need to dump gamma value to UART
  if(ucCmd == 0xff){
      //switch(GET_OSD_GAMMA(GET_OSD_SELECT_REGION())){
      switch(ucValue){
	case _GAMMA_18:
	  ucValue = '5';
	  break;
	case _GAMMA_20:
	  ucValue = '7';
	  break;
	case _GAMMA_22:
	  ucValue = '2';
	  break;
	case _GAMMA_24:
	  ucValue = 'A';
	  break;
	default:
	  ucValue = '?';
	  break;
      }

      dv_TxByteToUART(ucValue); 		//Send gamma value to UART

  }


}


//Ray CTP 2017.06.15
//*********************************************************
// Routine: dv_GetMAppColorTemp
// Usage: Get color temp value for MStar MApp: MS_COLOR_TEMP_9300K,...,MS_COLOR_TEMP_USER
// Input: ucCmd:  5: 9300K, 6:7500K, 2:6500K, 3:5000K, 4: USER
// Output: color temp value for MStar MApp: MS_COLOR_TEMP_9300K,...,MS_COLOR_TEMP_USER. For unknown value, return '?'
//**********************************************************
BYTE dv_GetMAppColorTemp(BYTE ucCmd)
{
  if(ucCmd == '5'){			//Set color temp to 9300K
      return MS_COLOR_TEMP_9300K;
  }
  else if(ucCmd == '6'){		//Set color temp to 7500K
      return MS_COLOR_TEMP_7500K;
  }
  else if(ucCmd == '2'){		//Set color temp to 6500K
      return MS_COLOR_TEMP_6500K;
  }
  else if(ucCmd == '3'){		//Set color temp to 5000K
      return MS_COLOR_TEMP_5000K;
  }
  else if(ucCmd == '4'){		//Set color temp to USER
      return MS_COLOR_TEMP_USER;
  }
  else{
      return '?';
  }
}

//Ray CTP 2017.06.15
//*********************************************************
// Routine: dv_GetColorTempCmdValue
// Usage: Get color temp value of MStar MApp to RS-232 command value
// Input: color temp value for MStar MApp: MS_COLOR_TEMP_9300K,...,MS_COLOR_TEMP_USER
// Output: RS-232 color temp command value 5: 9300K, 6:7500K, 2:6500K, 3:5000K, 4: USER, '?' for undefined input
//**********************************************************
BYTE dv_GetColorTempCmdValue(BYTE ucTempValue)
{
  if(ucTempValue == MS_COLOR_TEMP_9300K)
    return '5';
  else if(ucTempValue == MS_COLOR_TEMP_7500K)
    return '6';
  else if(ucTempValue == MS_COLOR_TEMP_6500K)
    return '2';
  else if(ucTempValue == MS_COLOR_TEMP_5000K)
    return '3';
  else if(ucTempValue == MS_COLOR_TEMP_USER)
    return '4';
  else
    return '?';
}


//Ray CTP 2017.06.15
//*********************************************************
// Routine: dv_Serial_ColorTemp_Para0
// Usage: Process RS232 0xB3 color temperature control command parameter byte 0 including:
//        ?: inquiry(2,3,4,5,6), R/r: restore default, 5: 9300K, 6:7500K, 2:6500K, 3:5000K, 4: USER
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_ColorTemp_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE value1;
  if(ucCmdPara!='i'&& ucCmdPara!='o')
  {
    if(ucCmdPara == '?'){
	  ucCmd = 0xff;			//Denote we need to send status to UART
    }
    else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
	ucCmd = 0xff;					//Denote we need to send status to UART
	MApp_DataBase_RestoreColorTempSelection();	//Restore default color temperature selection
	MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Adjust new color temperature setting
    }
    else{
	value1 = dv_GetMAppColorTemp(ucCmdPara);		//Get color temp value for MStar MApp
	if(value1!='?'){			//If user input is not undefined value
	    ucCmd = 0xfc;			//Denote we will set new color temp
	}else{
	    ucCmd = 0xff;			//If it is undefined value, dump '?' to UART
	}
    }

    if(ucCmd == 0xfc){			//Check if we need to set new color temp
	ucCmd = 0xff;			//Denote we need to send status to UART
	ST_VIDEO.eColorTemp = (EN_MS_COLOR_TEMP)value1;		//value1 contains color temperature to be set
	MApp_PQ_Set_ColorTemp(MAIN_WINDOW);	//Adjust new color temperature setting
    }
    if(ucCmd == 0xff){			//Check if we need to send value back to UART
      ucCmd = dv_GetColorTempCmdValue(ST_VIDEO.eColorTemp);  //Get color temperature
      dv_TxByteToUART(ucCmd);
    }
  }

}


//Ray CTP 2017.06.15
//*********************************************************
// Routine: dv_Serial_ColorTemp_Para2
// Usage: Process RS232 0xB3 color temperature control. Read selected color temperature of specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_ColorTemp_Para2(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;

  //Make sure we process this command at here if 1st parameter is 'o'
  if(ucCmdPara[0]=='o')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }
    //If valid input source is entered
    if(bSource!=0xff){
      //Show the color temperature the input source
	bValue = dv_GetColorTempCmdValue(G_VEDIO_SETTING[bSource].eColorTemp);  //Get color temperature cmd value
	dv_TxByteToUART(bValue);
    }
  }
}


//Ray CTP 2017.06.15
//*********************************************************
// Routine: dv_Serial_ColorTemp_Para3
// Usage: Process RS232 0xB3 color temperature control. Set color temp in "5: 9300K, 6:7500K, 2:6500K, 3:5000K, 4: USER" with user specified input port
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_ColorTemp_Para3(BYTE *ucCmdPara)
{
  BYTE bValue;
  BYTE bSource=0xff;	//Set an invalid value first
  WORD usInput;


  //Make sure we process this command at here if 1st parameter is 'i'
  if(ucCmdPara[0]=='i')
  {
    //Get the input source
    usInput = (BYTE)ucCmdPara[2];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|(BYTE)ucCmdPara[1];
    //Translate to firmware code input source value
    for(bValue=DATA_INPUT_SOURCE_RGB;bValue<=DATA_INPUT_SOURCE_HDMI4;bValue++){
      if(dv_DataInputSourceValue((E_DATA_INPUT_SOURCE)bValue)==usInput){
	  bSource = bValue;
      }
    }

    //If valid input source is entered
    if(bSource!=0xff){
	bValue = dv_GetMAppColorTemp(ucCmdPara[3]);	//Transform user input to MStar color temp value
	if(bValue!='?'){
	  //Set color temp if user input valid color temp value
	   G_VEDIO_SETTING[bSource].eColorTemp = (EN_MS_COLOR_TEMP)bValue;	//Set color temperature
	  //If entered input source is current source, the color temp is changed immediately
	  if(bSource==g_enDataInputSourceType[MAIN_WINDOW]){
	      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);	//Adjust new color temperature setting
	  }
	  dv_TxByteToUART(dv_GetColorTempCmdValue(G_VEDIO_SETTING[bSource].eColorTemp));
	}else{
	    dv_TxByteToUART(bValue);		//Send '?' value back to UART
	}
    }
  }
  /*
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
  }
  */
}


//Ray CTP 2017.06.26: dv_Serial_TempRed_Para0
//Tuning color temperature is expected on the displayed video (i.e. current selected source) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempRed_Para0
// Usage: Process RS232 0xB4 red of selected input source user color temperature setting command parameter byte 0 including:
//        ?: inquiry, R/r: restore default, +: increase, -: decrease; m: max query; n: min query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TempRed_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U8 u8ValueTmp;
  BOOLEAN bIsNeedToReset = FALSE;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      MApp_DataBase_RestoreUserColorTempRed();	//Restore default selected user color temperature red
      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);	//Apply new color temp only if there is new change value
  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;				//ENABLE means increase value
      }
      else{
	  ucAct = DISABLE;				//DISABLE means decrease value
      }
      //Go to increase/decrease both actual and scale color temp
      u8ValueTmp = USER_COLOR_TEMP.cRedColor;
      USER_COLOR_TEMP.cRedColor = MApp_ZUI_ACT_DecIncValue(
	  ucAct,
          USER_COLOR_TEMP.cRedColor, MIN_USER_RGB, MAX_USER_RGB, 1);
      USER_COLOR_TEMP.cRedScaleValue = GetColorTemperatureScale100Value(
          u8ValueTmp, USER_COLOR_TEMP.cRedColor,
          MIN_USER_RGB, MAX_USER_RGB, USER_COLOR_TEMP.cRedScaleValue, &bIsNeedToReset);
      if (bIsNeedToReset == TRUE) USER_COLOR_TEMP.cRedColor = u8ValueTmp;

      if ((USER_COLOR_TEMP.cRedColor == u8ValueTmp) && !bIsNeedToReset)
      {
          //bRet = FALSE;
      }
      else
      {
          //bRet = TRUE;
          MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
      }

  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GetScale100Value(USER_COLOR_TEMP.cRedColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

  }

}


//Ray CTP 2017.06.26: dv_Serial_TempRed_Para1
//Tuning color temperature is expected on the displayed video (i.e. current selected source) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempRed_Para1
// Usage: Process RS232 0xB4 red color temperature setting command parameter 2 digits input 0x00~0x64
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TempRed_Para1(BYTE *ucCmdPara)
{
  BYTE u8Value;

  u8Value = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(u8Value>100){
      u8Value = 100;
  }
  USER_COLOR_TEMP.cRedScaleValue = u8Value;

  //Convert 0~100 to actual value
  USER_COLOR_TEMP.cRedColor = N100toReallyValue((U16)u8Value,MIN_USER_RGB, MAX_USER_RGB);
  MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp
  dv_SerialTransmitHex(GetScale100Value(USER_COLOR_TEMP.cRedColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

}


//Ray CTP 2017.06.26: dv_Serial_TempGreen_Para0
//Tuning color temperature is expected on the displayed video (i.e. current selected source) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempGreen_Para0
// Usage: Process RS232 0xB5 green color temperature setting command parameter byte 0 including:
//        ?: inquiry, R/r: restore default, +: increase, -: decrease; m: max query; n: min query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TempGreen_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U8 u8ValueTmp;
  BOOLEAN bIsNeedToReset = FALSE;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      MApp_DataBase_RestoreUserColorTempGreen();	//Restore default selected color temperature Green
      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;				//ENABLE means increase value
      }
      else{
	  ucAct = DISABLE;				//DISABLE means decrease value
      }
      //Go to increase/decrease both actual and scale color temp
      u8ValueTmp = USER_COLOR_TEMP.cGreenColor;
      USER_COLOR_TEMP.cGreenColor = MApp_ZUI_ACT_DecIncValue(
	  ucAct,
          USER_COLOR_TEMP.cGreenColor, MIN_USER_RGB, MAX_USER_RGB, 1);
      USER_COLOR_TEMP.cGreenScaleValue = GetColorTemperatureScale100Value(
          u8ValueTmp, USER_COLOR_TEMP.cGreenColor,
          MIN_USER_RGB, MAX_USER_RGB, USER_COLOR_TEMP.cGreenScaleValue, &bIsNeedToReset);
      if (bIsNeedToReset == TRUE) USER_COLOR_TEMP.cGreenColor = u8ValueTmp;

      if ((USER_COLOR_TEMP.cGreenColor == u8ValueTmp) && !bIsNeedToReset)
      {
          //bRet = FALSE;
      }
      else
      {
          //bRet = TRUE;
          MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
      }

  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GetScale100Value(USER_COLOR_TEMP.cGreenColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

  }

}

//Ray CTP 2017.06.26: dv_Serial_TempGreen_Para1
//Tuning color temperature is expected on the displayed video (i.e. current selected source) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempGreen_Para1
// Usage: Process RS232 0xB5 green color temperature setting command parameter 2 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TempGreen_Para1(BYTE *ucCmdPara)
{
  BYTE u8Value;

  u8Value = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(u8Value>100){
      u8Value = 100;
  }
  USER_COLOR_TEMP.cGreenScaleValue = u8Value;

  //Convert 0~100 to actual value
  USER_COLOR_TEMP.cGreenColor = N100toReallyValue((U16)u8Value,MIN_USER_RGB, MAX_USER_RGB);
  MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp
  dv_SerialTransmitHex(GetScale100Value(USER_COLOR_TEMP.cGreenColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

}

//Ray CTP 2017.06.26: dv_Serial_TempBlue_Para0
//Tuning color temperature is expected on the displayed video (i.e. current selected source) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempBlue_Para0
// Usage: Process RS232 0xB6 blue color temperature setting command parameter byte 0 including:
//        ?: inquiry, R/r: restore default, +: increase, -: decrease; m: max query; n: min query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TempBlue_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U8 u8ValueTmp;
  BOOLEAN bIsNeedToReset = FALSE;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      MApp_DataBase_RestoreUserColorTempBlue();	//Restore default selected color temperature Blue
      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;				//ENABLE means increase value
      }
      else{
	  ucAct = DISABLE;				//DISABLE means decrease value
      }
      //Go to increase/decrease both actual and scale color temp
      u8ValueTmp = USER_COLOR_TEMP.cBlueColor;
      USER_COLOR_TEMP.cBlueColor = MApp_ZUI_ACT_DecIncValue(
	  ucAct,
          USER_COLOR_TEMP.cBlueColor, MIN_USER_RGB, MAX_USER_RGB, 1);
      USER_COLOR_TEMP.cBlueScaleValue = GetColorTemperatureScale100Value(
          u8ValueTmp, USER_COLOR_TEMP.cBlueColor,
          MIN_USER_RGB, MAX_USER_RGB, USER_COLOR_TEMP.cBlueScaleValue, &bIsNeedToReset);
      if (bIsNeedToReset == TRUE) USER_COLOR_TEMP.cBlueColor = u8ValueTmp;

      if ((USER_COLOR_TEMP.cBlueColor == u8ValueTmp) && !bIsNeedToReset)
      {
          //bRet = FALSE;
      }
      else
      {
          //bRet = TRUE;
          MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
      }

  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GetScale100Value(USER_COLOR_TEMP.cBlueColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

  }

}

//Ray CTP 2017.06.26: dv_Serial_TempBlue_Para1
//Tuning color temperature is expected on the displayed video (i.e. current selected source) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempBlue_Para1
// Usage: Process RS232 0xB6 blue color temperature setting command parameter 2 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TempBlue_Para1(BYTE *ucCmdPara)
{
  BYTE u8Value;

  u8Value = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(u8Value>100){
      u8Value = 100;
  }
  USER_COLOR_TEMP.cBlueScaleValue = u8Value;

  //Convert 0~100 to actual value
  USER_COLOR_TEMP.cBlueColor = N100toReallyValue((U16)u8Value,MIN_USER_RGB, MAX_USER_RGB);
  MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp
  dv_SerialTransmitHex(GetScale100Value(USER_COLOR_TEMP.cBlueColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

}


//Ray CTP 2017.06.26: Disable selected color temp R,G,B gain adjustment.  We only need user color temp R,G,B gain adjustment
#if 0
//Ray CTP 2017.06.23: dv_Serial_TempRed_Para0
//Tuning color temperature is expected on the displayed video (i.e. current selected source and selected color temp) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempRed_Para0
// Usage: Process RS232 0xB4 red of selected color temperature setting command parameter byte 0 including:
//        ?: inquiry, R/r: restore default, +: increase, -: decrease; m: max query; n: min query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TempRed_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U8 u8ValueTmp;
  BOOLEAN bIsNeedToReset = FALSE;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      MApp_DataBase_RestoreSelColorTempRed();	//Restore default selected color temperature red
      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;				//ENABLE means increase value
      }
      else{
	  ucAct = DISABLE;				//DISABLE means decrease value
      }
      //Go to increase/decrease both actual and scale color temp
      u8ValueTmp = ST_COLOR_TEMP.cRedColor;
      ST_COLOR_TEMP.cRedColor = MApp_ZUI_ACT_DecIncValue(
	  ucAct,
          ST_COLOR_TEMP.cRedColor, MIN_USER_RGB, MAX_USER_RGB, 1);
      ST_COLOR_TEMP.cRedScaleValue = GetColorTemperatureScale100Value(
          u8ValueTmp, ST_COLOR_TEMP.cRedColor,
          MIN_USER_RGB, MAX_USER_RGB, ST_COLOR_TEMP.cRedScaleValue, &bIsNeedToReset);
      if (bIsNeedToReset == TRUE) ST_COLOR_TEMP.cRedColor = u8ValueTmp;

      if ((ST_COLOR_TEMP.cRedColor == u8ValueTmp) && !bIsNeedToReset)
      {
          //bRet = FALSE;
      }
      else
      {
          //bRet = TRUE;
          MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
      }

  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GetScale100Value(ST_COLOR_TEMP.cRedColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

  }

}


//Ray CTP 2017.06.23: dv_Serial_TempRed_Para1
//Tuning color temperature is expected on the displayed video (i.e. current selected source and selected color temp) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempRed_Para1
// Usage: Process RS232 0xB4 red color temperature setting command parameter 2 digits input 0x00~0x64
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TempRed_Para1(BYTE *ucCmdPara)
{
  BYTE u8Value;

  u8Value = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(u8Value>100){
      u8Value = 100;
  }
  ST_COLOR_TEMP.cRedScaleValue = u8Value;

  //Convert 0~100 to actual value
  ST_COLOR_TEMP.cRedColor = N100toReallyValue((U16)u8Value,MIN_USER_RGB, MAX_USER_RGB);
  MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp
  dv_SerialTransmitHex(GetScale100Value(ST_COLOR_TEMP.cRedColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

}


//Ray CTP 2017.06.23: dv_Serial_TempGreen_Para0
//Tuning color temperature is expected on the displayed video (i.e. current selected source and selected color temp) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempGreen_Para0
// Usage: Process RS232 0xB5 green color temperature setting command parameter byte 0 including:
//        ?: inquiry, R/r: restore default, +: increase, -: decrease; m: max query; n: min query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TempGreen_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U8 u8ValueTmp;
  BOOLEAN bIsNeedToReset = FALSE;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      MApp_DataBase_RestoreSelColorTempGreen();	//Restore default selected color temperature Green
      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;				//ENABLE means increase value
      }
      else{
	  ucAct = DISABLE;				//DISABLE means decrease value
      }
      //Go to increase/decrease both actual and scale color temp
      u8ValueTmp = ST_COLOR_TEMP.cGreenColor;
      ST_COLOR_TEMP.cGreenColor = MApp_ZUI_ACT_DecIncValue(
	  ucAct,
          ST_COLOR_TEMP.cGreenColor, MIN_USER_RGB, MAX_USER_RGB, 1);
      ST_COLOR_TEMP.cGreenScaleValue = GetColorTemperatureScale100Value(
          u8ValueTmp, ST_COLOR_TEMP.cGreenColor,
          MIN_USER_RGB, MAX_USER_RGB, ST_COLOR_TEMP.cGreenScaleValue, &bIsNeedToReset);
      if (bIsNeedToReset == TRUE) ST_COLOR_TEMP.cGreenColor = u8ValueTmp;

      if ((ST_COLOR_TEMP.cGreenColor == u8ValueTmp) && !bIsNeedToReset)
      {
          //bRet = FALSE;
      }
      else
      {
          //bRet = TRUE;
          MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
      }

  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GetScale100Value(ST_COLOR_TEMP.cGreenColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

  }

}

//Ray CTP 2017.06.23: dv_Serial_TempGreen_Para1
//Tuning color temperature is expected on the displayed video (i.e. current selected source and selected color temp) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempGreen_Para1
// Usage: Process RS232 0xB5 green color temperature setting command parameter 2 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TempGreen_Para1(BYTE *ucCmdPara)
{
  BYTE u8Value;

  u8Value = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(u8Value>100){
      u8Value = 100;
  }
  ST_COLOR_TEMP.cGreenScaleValue = u8Value;

  //Convert 0~100 to actual value
  ST_COLOR_TEMP.cGreenColor = N100toReallyValue((U16)u8Value,MIN_USER_RGB, MAX_USER_RGB);
  MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp
  dv_SerialTransmitHex(GetScale100Value(ST_COLOR_TEMP.cGreenColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

}

//Ray CTP 2017.06.23: dv_Serial_TempBlue_Para0
//Tuning color temperature is expected on the displayed video (i.e. current selected source and selected color temp) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempBlue_Para0
// Usage: Process RS232 0xB6 blue color temperature setting command parameter byte 0 including:
//        ?: inquiry, R/r: restore default, +: increase, -: decrease; m: max query; n: min query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TempBlue_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucAct = 0;
  U8 u8ValueTmp;
  BOOLEAN bIsNeedToReset = FALSE;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      MApp_DataBase_RestoreSelColorTempBlue();	//Restore default selected color temperature Blue
      MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  ucAct = ENABLE;				//ENABLE means increase value
      }
      else{
	  ucAct = DISABLE;				//DISABLE means decrease value
      }
      //Go to increase/decrease both actual and scale color temp
      u8ValueTmp = ST_COLOR_TEMP.cBlueColor;
      ST_COLOR_TEMP.cBlueColor = MApp_ZUI_ACT_DecIncValue(
	  ucAct,
          ST_COLOR_TEMP.cBlueColor, MIN_USER_RGB, MAX_USER_RGB, 1);
      ST_COLOR_TEMP.cBlueScaleValue = GetColorTemperatureScale100Value(
          u8ValueTmp, ST_COLOR_TEMP.cBlueColor,
          MIN_USER_RGB, MAX_USER_RGB, ST_COLOR_TEMP.cBlueScaleValue, &bIsNeedToReset);
      if (bIsNeedToReset == TRUE) ST_COLOR_TEMP.cBlueColor = u8ValueTmp;

      if ((ST_COLOR_TEMP.cBlueColor == u8ValueTmp) && !bIsNeedToReset)
      {
          //bRet = FALSE;
      }
      else
      {
          //bRet = TRUE;
          MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp only if there is new change value
      }

  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GetScale100Value(ST_COLOR_TEMP.cBlueColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

  }

}

//Ray CTP 2017.06.23: dv_Serial_TempBlue_Para1
//Tuning color temperature is expected on the displayed video (i.e. current selected source and selected color temp) since user need to watch the effect in tuning
//*********************************************************
// Routine: dv_Serial_TempBlue_Para1
// Usage: Process RS232 0xB6 blue color temperature setting command parameter 2 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TempBlue_Para1(BYTE *ucCmdPara)
{
  BYTE u8Value;

  u8Value = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(u8Value>100){
      u8Value = 100;
  }
  ST_COLOR_TEMP.cBlueScaleValue = u8Value;

  //Convert 0~100 to actual value
  ST_COLOR_TEMP.cBlueColor = N100toReallyValue((U16)u8Value,MIN_USER_RGB, MAX_USER_RGB);
  MApp_PQ_Set_ColorTemp(MAIN_WINDOW);		//Apply new color temp
  dv_SerialTransmitHex(GetScale100Value(ST_COLOR_TEMP.cBlueColor,MIN_USER_RGB, MAX_USER_RGB));	//Send color temperature value

}

#endif

//*********************************************************
// Routine: dv_Serial_Power_Para0
// Usage: Process RS232 0xc8 soft power on/off comand
//        0: power off; 1: power on; ?: query
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Power_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucStatus;


  if(ucCmdPara == '?'){
      ucCmd = 0xff;		//Denote we need to dump status to UART
  }
  else if(ucCmdPara == '1'){
      ucCmd = 0xfe;		//Denote we need to dump status to UART
      ucStatus = '1';
      //Check if it's in power saving mode
      if((sFlagSimPowerShutDown&0x01)==0x01){
	  MApp_RS232_SetKey(IRKEY_POWER);			//If yes, execute Press POWER key function to go to normal mode
      }
  }
  else if(ucCmdPara == '0'){
      ucCmd = 0xfe;		//Denote we need to dump status to UART
      ucStatus = '0';
      //Check if it's in normal mode
      if((sFlagSimPowerShutDown&0x01)==0x00){
	  MApp_RS232_SetKey(IRKEY_POWER);			//If yes, execute Press POWER key function to go to power saving mode
      }
  }

  //Check if we need to show power on/off status to UART
  if(ucCmd==0xff||ucCmd==0xfe){

      if(ucCmd==0xff){
	  //Check if it's in power saving mode
	  if((sFlagSimPowerShutDown&0x01)==0x01){
	  ucStatus ='0';
	}
	else{
	  ucStatus = '1';
	}
      }

      dv_TxByteToUART(ucStatus);
  }

}


//*********************************************************
// Routine: dv_Serial_CommandQuery_Para1
// Usage: Process RS232 0xC4 RS-232 command query parameter 2 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_CommandQuery_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;
  BYTE i=0;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  //We won't process extend serial command inquiry here, instead it will process in dv_Serial_CommandQuery_Para3()
  if(ucValue != Serial_Command_Extend){
    //Check if the query command is implemented
    do{
	if(SerialCommandTable[i]==ucValue){
	    i=0xff;						//Assign i = 0xff means we found that command is available and quit the searching process
	}
	else{
	    i++;							//Go to search next item
	}

    }while(i<sizeof(SerialCommandTable));


    if(i==0xff){
	dv_TxByteToUART('1');      				//1 means command is implemented
    }
    else{
	dv_TxByteToUART('0'); 					//0 means command is not implemented
    }
  }
}

//*********************************************************
// Routine: dv_Serial_CommandQuery_Para3
// Usage: Process RS232 0xC4 RS-232 command query parameter 4 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_CommandQuery_Para3(BYTE *ucCmdPara)
{
  BYTE ucLowB,ucHighB;
  BYTE i=0;
  BYTE ucExt2ByteCmd;

  ucHighB = dv_GetAsciiValue(&ucCmdPara[0]);			//transform high byte ASCII to digit value
  ucLowB = dv_GetAsciiValue(&ucCmdPara[2]);			//transform high byte ASCII to digit value

  if(ucHighB == Serial_Command_Extend){				//Check if looking for extend command byte
    //Check if the query extend command is implemented
    do{
	if(SerialExtCommandTable[i]==ucLowB){
	    i=0xff;						//Assign i = 0xff means we found that command is available and quit the searching process
	}
	else{
	    i++;							//Go to search next item
	}

    }while(i<sizeof(SerialExtCommandTable));

    //If query cmd is not done in extend command, Check if query extend command 2 bytes is implemented
    if(i!=0xff){
      i = 0;
      do{
	  ucExt2ByteCmd = (SerialExtCommand2ByteTable[i]>>8);
	  if(ucExt2ByteCmd==ucLowB){					//We only check first byte of two byte command
	      i=0xfe;							//Assign i = 0xfe means we found that command is available but no need to print
	  }
	  else{
	      i++;							//Go to search next item
	  }

	  }while(i<sizeof(SerialExtCommand2ByteTable));
    }
    if(i==0xff){
	dv_TxByteToUART('1');      				//1 means command is implemented
    }
    else if(i==0xfe){
	;							//Will go to check if next byte
    }
    else{
	dv_TxByteToUART('0'); 					//0 means command is not implemented
    }
  }
}


//*********************************************************
// Routine: dv_Serial_CommandQuery_Para5
// Usage: Process RS232 0xC4 RS-232 command query parameter 6 digits input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_CommandQuery_Para5(BYTE *ucCmdPara)
{
  BYTE ucCmdB;
  WORD usPara;
  BYTE i=0;

  ucCmdB = dv_GetAsciiValue(&ucCmdPara[0]);			//transform 0xee cmd byte ASCII to digit value
  usPara = dv_GetAsciiValue(&ucCmdPara[2])*256;			//transform 1st byte ASCII to digit value
  usPara += dv_GetAsciiValue(&ucCmdPara[4]);			//transform 2nd byte ASCII to digit value

  if(ucCmdB == Serial_Command_Extend){				//Check if looking for extend command byte
    //Check if the query extend command is implemented
    do{
	if(SerialExtCommand2ByteTable[i]==usPara){
	    i=0xff;						//Assign i = 0xff means we found that command is available and quit the searching process
	}
	else{
	    i++;							//Go to search next item
	}

    }while(i<sizeof(SerialExtCommand2ByteTable));
  }

  if(i==0xff){
      dv_TxByteToUART('1');      				//1 means command is implemented
  }
  else{
      dv_TxByteToUART('0'); 					//0 means command is not implemented
  }

}

#if 0			//Ray URT 2017.05.08 #if





//*********************************************************
// Routine: dv_Serial_Hue_Para0
// Usage: Process RS232 0x84 hue control command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default, m/n: query max/min value
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Hue_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_HUE(GET_OSD_SELECT_REGION()), _HUE_MAX, _HUE_MIN, _HUE_CENTER);	//Get selected region's hue value in 0%~100%
      if(ucCmdPara == '+'){
	if(value1<100)
	  value1++;			//Increase hue value if it's less than max 100%
      }
      else{
	if(value1>0)
	  value1--;			//Decrease hue value if it's more than min 0%
      }
      SET_OSD_SELECT_REGION(dv_GetSelectAllRegion());		//Select all regions
      RTDNVRamSaveOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Save select all region to System EEPROM
      SET_OSD_HUE(GET_OSD_SELECT_REGION(), UserCommonAdjustPercentToRealValue(value1, _HUE_MAX, _HUE_MIN, _HUE_CENTER));		//Save new value in 0~100%
      UserAdjustGlobalHueSat(GET_OSD_SYSTEM_SELECT_REGION(), (SWORD)GET_OSD_HUE(GET_OSD_SELECT_REGION()), GET_OSD_SATURATION(GET_OSD_SELECT_REGION()));	//Adjusted new saved value
      UserAdjustOsdSelectRegionColorProc();			//Apply setting to all regions
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_REGIONDATA_MSG);	//Going to save value into system EEPROM
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_OSD_SELECT_REGION(dv_GetSelectAllRegion());		//Select all regions
      RTDNVRamSaveOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Save select all region to System EEPROM
      RTDEepromRestoreHue();		//Restore default hue from EEPROM
      UserAdjustOsdSelectRegionColorProc();			//Apply setting to all regions
  }
  else if(ucCmdPara == 'm'){
      dv_SerialTransmitHex(100);	//Send max color hue value
  }
  else if(ucCmdPara == 'n'){
      dv_SerialTransmitHex(0);		//Send min color hue value
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
     value1 = UserCommonAdjustRealValueToPercent(GET_OSD_HUE(GET_OSD_SELECT_REGION()), _HUE_MAX, _HUE_MIN, _HUE_CENTER);	//Get selected region's hue value in 0%~100%
     dv_SerialTransmitHex((BYTE)value1);
  }
}


//*********************************************************
// Routine: dv_Serial_Hue_Para1
// Usage: Process RS232 0x84 color hue control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Hue_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  if(ucCmdPara[0]!='i'|| ucCmdPara[0]!='o')
  {
     ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
      //SVX-4096 color hue range is 0x00 to 0x64 (0%~100%)
      if(ucValue > 100){
	  ucValue = 100;		//Set it to max if input value is larger than max
      }
      if(ucValue < 0){
	  ucValue = 0;
      }
      //Save and set new value to all regions in current display mode
      SET_OSD_SELECT_REGION(dv_GetSelectAllRegion());		//Select all regions
      RTDNVRamSaveOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Save select all region to System EEPROM
      SET_OSD_HUE(GET_OSD_SELECT_REGION(), UserCommonAdjustPercentToRealValue(ucValue, _HUE_MAX, _HUE_MIN, _HUE_CENTER));		//Save new value in 0~100%
      UserAdjustGlobalHueSat(GET_OSD_SYSTEM_SELECT_REGION(), (SWORD)GET_OSD_HUE(GET_OSD_SELECT_REGION()), GET_OSD_SATURATION(GET_OSD_SELECT_REGION()));	//Adjusted new saved value
      UserAdjustOsdSelectRegionColorProc();			//Apply setting to all regions
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_REGIONDATA_MSG);	//Going to save value into system EEPROM

      ucValue = UserCommonAdjustRealValueToPercent(GET_OSD_HUE(GET_OSD_SELECT_REGION()), _HUE_MAX, _HUE_MIN, _HUE_CENTER);	//Get selected region's hue value in 0%~100%
      dv_SerialTransmitHex(ucValue);	//Send Hue value to UART



  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}













//*********************************************************
// Routine: dv_Serial_OsdRotate_Para0
// Usage: Process RS232 0x8F OSD orientation command parameter byte 0 including:
//        ?: inquiry, 0: normal, 1: 90, 2: 180, 3: 270, R/r: reset to 0
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_OsdRotate_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  value1 = GET_OSD_ROTATE_STATUS();	//Get original OSD status
  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '0'){
      ucCmd = 0xfe;			//Denote we need to rotate OSD menu
      SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_0);
  }
  else if(ucCmdPara == '1'){
      ucCmd = 0xfe;			//Denote we need to rotate OSD menu
      SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_270);	//Ray 2016.03.18: Swap OSD rotation 90 and 270
  }
  //Current firmware doesn't support 180 rotation
  /*
  else if(ucCmdPara == '2'){
      ucCmd = 0xfe;			//Denote we need to rotate OSD menu
      SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_180);
  }
  */
  else if(ucCmdPara == '3'){
      ucCmd = 0xfe;			//Denote we need to rotate OSD menu
      SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_90);	//Ray 2016.03.18: Swap OSD rotation 90 and 270
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xfe;			//Denote we need to rotate OSD menu
      SET_OSD_ROTATE_STATUS(_OSD_ROTATE_DEGREE_0);	//Reset to 0
  }

  //Check if we need to rotate OSD menu
  if(ucCmd==0xfe){
      ucCmd =0xff;		//We need to dump OSD rotation state to UART

	  OsdDispOsdRotateSwitch();		//Rotate OSD
	  OsdDispDisableOsd();			//Clear OSD first
	  SET_KEYMESSAGE(_MENU_KEY_MESSAGE);	//Enter into main menu
	  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Save new setting into System EEPROM

  }
  //Check if we need to dump OSD rotation status to UART
  if(ucCmd == 0xff){
      switch(GET_OSD_ROTATE_STATUS()){
	case _OSD_ROTATE_DEGREE_0:
	  value1 = '0';
	  break;
	case _OSD_ROTATE_DEGREE_270:		//Ray 2016.03.18: Swap OSD rotation 90 and 270
	  value1 = '1';
	  break;
	/*
	case _OSD_ROTATE_DEGREE_180:
	  value1 = '2';
	  break;
	*/
	case _OSD_ROTATE_DEGREE_90:		//Ray 2016.03.18: Swap OSD rotation 90 and 270
	  value1 = '3';
	  break;
	default:
	  value1 = '?';
	  break;
      }

      dv_TxByteToUART(value1);	//Send to UART
  }



}


//*********************************************************
// Routine: dv_Serial_OsdHPosn_Para0
// Usage: Process RS232 0x90 OSD horizontal position command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_OsdHPosn_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER);	//Get OSD horizontal position value in 0%~100%
      if(value1<100)
	value1++;			//Increase OSD horizontal position value if it's less than max 100%
      SET_OSD_HPOS(UserCommonAdjustPercentToRealValue(value1, _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER));		//Save new OSD position value in 0~100%
      OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());		//Adjusted new saved position value
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM
  }
  else if(ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER);	//Get OSD horizontal position value in 0%~100%
      if(value1>0)
	value1--;			//Decrease OSD horizontal position value if it's more than min 0%
      SET_OSD_HPOS(UserCommonAdjustPercentToRealValue(value1, _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER));		//Save new OSD position value in 0~100%
      OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());		//Adjusted new saved position value
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      RTDEepromRestoreOsdHPosn();	//Restore default OSD horizontal position from EEPROM
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER);	//Get OSD position value in 0%~100%
      dv_SerialTransmitHex((BYTE)value1);
  }
}


//*********************************************************
// Routine: dv_Serial_OsdHPosn_Para1
// Usage: Process RS232 0x90 OSD horizontal position 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_OsdHPosn_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 position range is 0x00 to 0x64 (0%~100%)
  if(ucValue > _OSD_H_POS_MAX){
      ucValue = _OSD_H_POS_MAX;		//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_H_POS_MIN){
      ucValue = _OSD_H_POS_MIN;
  }
  //Save and set new value
  SET_OSD_HPOS(UserCommonAdjustPercentToRealValue(ucValue, _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER));		//Save new OSD position value in 0~100%
  OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());		//Adjusted new saved position value
  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM

  ucValue = UserCommonAdjustRealValueToPercent(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER);	//Get OSD position value in 0%~100%
  dv_SerialTransmitHex(ucValue);	//Send Hue value to UART

}

//*********************************************************
// Routine: dv_Serial_OsdVPosn_Para0
// Usage: Process RS232 0x91 OSD vertical position command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_OsdVPosn_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER);	//Get OSD vertical position value in 0%~100%
      if(value1<100)
	value1++;			//Increase OSD vertical position value if it's less than max 100%
      SET_OSD_VPOS(UserCommonAdjustPercentToRealValue(value1, _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER));		//Save new OSD position value in 0~100%
      OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());		//Adjusted new saved position value
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM
  }
  else if(ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER);	//Get OSD vertical position value in 0%~100%
      if(value1>0)
	value1--;			//Decrease OSD vertical position value if it's more than min 0%
      SET_OSD_VPOS(UserCommonAdjustPercentToRealValue(value1, _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER));		//Save new OSD position value in 0~100%
      OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());		//Adjusted new saved position value
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      RTDEepromRestoreOsdVPosn();	//Restore default OSD vertical position from EEPROM
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER);	//Get OSD position value in 0%~100%
      dv_SerialTransmitHex((BYTE)value1);
  }
}

//*********************************************************
// Routine: dv_Serial_OsdVPosn_Para1
// Usage: Process RS232 0x91 OSD vertical position 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_OsdVPosn_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 position range is 0x00 to 0x64 (0%~100%)
  if(ucValue > _OSD_V_POS_MAX){
      ucValue = _OSD_V_POS_MAX;		//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_V_POS_MIN){
      ucValue = _OSD_V_POS_MIN;
  }
  //Save and set new value
  SET_OSD_VPOS(UserCommonAdjustPercentToRealValue(ucValue, _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER));		//Save new OSD position value in 0~100%
  OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());		//Adjusted new saved position value
  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM

  ucValue = UserCommonAdjustRealValueToPercent(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER);	//Get OSD position value in 0%~100%
  dv_SerialTransmitHex(ucValue);	//Send Hue value to UART

}


//*********************************************************
// Routine: dv_Serial_OsdTransparency_Para0
// Usage: Process RS232 0x92 OSD menu transparency command parameter byte 0 including:
//        ?: inquiry (0~100), +: increase, -: decrease,
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_OsdTransparency_Para0(BYTE ucCmdPara)
{

  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);		//Set right key message = increase value
      }
      else{
	  SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);		//Set left key message = decrease value
      }

      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_TRANSPARENCY_STATUS(), _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER);	//Ray 2016.05.17: Transform from real value to % value
      value1= (BYTE)OsdDisplayDetOverRange(value1, 100, 0, _OFF);	      	//Go to increase/decrease value
      SET_OSD_TRANSPARENCY_STATUS(UserCommonAdjustPercentToRealValue(value1, _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER));	//Ray 2016.05.17: Transform from % to real value and save it
      OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());			//Apply new value
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);		//Save new value to NVRAM
      SET_KEYMESSAGE(_NONE_KEY_MESSAGE);					//Cancel key message after change value
  }

  if(ucCmd==0xff){
      //We need to send value back to UART
     value1 = UserCommonAdjustRealValueToPercent(GET_OSD_TRANSPARENCY_STATUS(), _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER);	//Ray 2016.05.17: Transform from real value to % value
     dv_SerialTransmitHex((BYTE)value1);
  }

}


//*********************************************************
// Routine: dv_Serial_OsdTransparency_Para1
// Usage: Process RS232 0x92 OSD menu transparency control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_OsdTransparency_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  //Only accept digit value between 0x00~0x64  (0~100)
  if(ucCmdPara[0]>='0'&& ucCmdPara[0]<='6')
  {
     ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
      //SVX-4096 OSD transparency range is 0x00 to 0x64 (0%~100%)
      if(ucValue > 100){
	  ucValue = 100;		//Set it to max if input value is larger than max
      }
      if(ucValue < 0){
	  ucValue = 0;
      }
      SET_OSD_TRANSPARENCY_STATUS(UserCommonAdjustPercentToRealValue(ucValue, _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER));	//Ray 2016.05.17: Transform from % to real value and save it
      OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());			//Apply new value
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);		//Save new value to NVRAM
      dv_SerialTransmitHex(ucValue);						//Send new value to UART

  }
  else{
      dv_SerialTransmitHex('?');	//Tx unknown command
    }

}

//*********************************************************
// Routine: dv_Serial_Runtime_Para0
// Usage: Process RS232 0xA1 runtime counter command parameter byte 0 including:
//        ?: inquiry , R/r: reset to zero
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Runtime_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  DWORD ulRunCounter;


  if(ucCmdPara == '?'){
      ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_PANEL_TIME_HOUR(0);		//Reset runtime counter to 0
      SET_PANEL_TIME_MIN(0);
      RTDEepromSavePanelOnTime();	//Ray 2016.06.30: Save panel on time to its own EEPROM space
      //RTDNVRamSaveOsdUserData();
  }
  //Check if we need to send the panel time to UART
  if(ucCmd == 0xff){
      ulRunCounter = (DWORD)GET_PANEL_TIME_HOUR()*2;		//Get hour in unit of 30 min
      ulRunCounter += (GET_PANEL_TIME_MIN()/30);		//Get min in unit of 30 min
      dv_SendValuesToUART(1,(WORD)(ulRunCounter>>16));	//Send 5th byte to UART first
      dv_SendValuesToUART(4,ulRunCounter);		//Send 4th to first byte to UART
      DebugMessageSystem("Runtime counter F:",ulRunCounter);
      DebugMessageSystem("Runtime hour:",GET_PANEL_TIME_HOUR());
      DebugMessageSystem("Runtime min:",GET_PANEL_TIME_MIN());

  }

}


//*********************************************************
// Routine: dv_Serial_Runtime_Para5
// Usage: Process RS232 0xA1 runtime counter with 5 digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Runtime_Para5(BYTE *ucCmdPara)
{
  BYTE ucCmd,i;
  DWORD ulRunCounter;
  BYTE ucValue1[2];

  ucCmd = 0xff;		//First, assume we need to process input
 //Check if there is any non digit input
  for(i=0;i<5;i++){
      if(ucCmdPara[i]<0x30||ucCmdPara[i]>0x46){
	  ucCmd = 0xfe;			//denote input isn't ASCII digit value
      }
      else{
	 if(ucCmdPara[i]>0x39&&ucCmdPara[i]<0x41){
	     ucCmd = 0xfe;			//denote input isn't ASCII digit value
	 }
      }
  }

  //DebugMessageSystem("Runtime ucCmd:",ucCmd);

  //Check if we need to process input
  if(ucCmd==0xff){

    ucValue1[0] = 0;
    ucValue1[1] = ucCmdPara[0];				//Get MSB 5th byte
    ulRunCounter =dv_GetAsciiValue(&ucValue1)*0x10000;	//Transform 5th byte ASCII to digit value

    ucValue1[0] = ucCmdPara[1];			//Get MSB 4th byte
    ucValue1[1] = ucCmdPara[2];			//Get MSB 3rd byte
    ulRunCounter += dv_GetAsciiValue(&ucValue1)*0x100;	//Transform MSB 4th & 3rd byte ASCII to digit value
    ulRunCounter += dv_GetAsciiValue(&ucCmdPara[3]);	//Transform 1st & 2nd byte ASCII to digit value and get actual digital value of whole parameters

    DebugMessageSystem("Runtime input:",ulRunCounter);

    SET_PANEL_TIME_HOUR(ulRunCounter/2);			//ulRunCounter is in unit of 30min, transform it to hour and min
    SET_PANEL_TIME_MIN((ulRunCounter%2)*30);
    RTDEepromSavePanelOnTime();					//Ray 2016.06.30: Save panel on time to its own EEPROM space
    //RTDNVRamSaveOsdUserData();					//Save to NVRAM

    DebugMessageSystem("Runtime input hr:",GET_PANEL_TIME_HOUR());
    DebugMessageSystem("Runtime input min:",GET_PANEL_TIME_MIN());


  //we need to send the panel time to UART

      ulRunCounter = (DWORD)GET_PANEL_TIME_HOUR()*2;		//Get hour in unit of 30 min
      ulRunCounter += GET_PANEL_TIME_MIN()/30;		//Get min in unit of 30 min
      dv_SendValuesToUART(1,(ulRunCounter>>16)&0x0f);	//Send 5th byte to UART first
      dv_SendValuesToUART(4,ulRunCounter);		//Send 4th to first byte to UART
  }

}


//*********************************************************
// Routine: dv_Serial_PipHPosn_Para0
// Usage: Process RS232 0xA4  PIP horizontal position command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_PipHPosn_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_PIP_USER_POSITION_H(), _OSD_PIP_USER_POSITION_H_MAX, _OSD_PIP_USER_POSITION_H_MIN, _OSD_PIP_USER_POSITION_H_CENTER);	//Get PIP horizontal position value in 0%~100%
      if(ucCmdPara == '+'){
	if(value1<100)
	  value1++;			//Increase PIP horizontal position value if it's less than max 100%
      }
      else{
	if(value1>0)
	  value1--;			//Decrease PIP horizontal position value if it's more than min 0%
      }

      SET_OSD_PIP_POSITION_TYPE(_PIP_POSITON_USER);		//Set as PIP position type as user define
      RTDNVRamSaveOsdUserData();				//Save PIP position type in System EEPROM
      SET_OSD_PIP_USER_POSITION_H(UserCommonAdjustPercentToRealValue(value1, _OSD_PIP_USER_POSITION_H_MAX, _OSD_PIP_USER_POSITION_H_MIN, _OSD_PIP_USER_POSITION_H_CENTER));		//Save new PIP position value in 0~100%
#if(_PIP_DISPLAY_SUPPORT == _ON)
      if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
      {
	  UserCommonAdjustPipSubTimingFormat();			//Adjust new saved PIP position
      }
#endif
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_OSD_PIP_POSITION_TYPE(_PIP_POSITON_USER);		//Set as PIP position type as user define
      RTDNVRamSaveOsdUserData();				//Save PIP position type in System EEPROM
      RTDEepromRestorePipHPosn();	//Restore default PIP horizontal position from EEPROM
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_PIP_USER_POSITION_H(), _OSD_PIP_USER_POSITION_H_MAX, _OSD_PIP_USER_POSITION_H_MIN, _OSD_PIP_USER_POSITION_H_CENTER);	//Get PIP position value in 0%~100%
      dv_SerialTransmitHex((BYTE)value1);
  }
}

//*********************************************************
// Routine: dv_Serial_PipHPosn_Para1
// Usage: Process RS232 0xA4 PIP horizontal position 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_PipHPosn_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 position range is 0x00 to 0x64 (0%~100%)
  if(ucValue > _OSD_PIP_USER_POSITION_H_MAX){
      ucValue = _OSD_PIP_USER_POSITION_H_MAX;		//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_PIP_USER_POSITION_H_MIN){
      ucValue = _OSD_PIP_USER_POSITION_H_MIN;
  }
  //Save and set new value
  SET_OSD_PIP_POSITION_TYPE(_PIP_POSITON_USER);		//Set as PIP position type as user define
  RTDNVRamSaveOsdUserData();				//Save PIP position type in System EEPROM
  SET_OSD_PIP_USER_POSITION_H(UserCommonAdjustPercentToRealValue(ucValue, _OSD_PIP_USER_POSITION_H_MAX, _OSD_PIP_USER_POSITION_H_MIN, _OSD_PIP_USER_POSITION_H_CENTER));		//Save new PIP position value in 0~100%
#if(_PIP_DISPLAY_SUPPORT == _ON)
  if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
  {
	  UserCommonAdjustPipSubTimingFormat();			//Adjust new saved PIP position
  }
#endif
  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM

  ucValue = UserCommonAdjustRealValueToPercent(GET_OSD_PIP_USER_POSITION_H(), _OSD_PIP_USER_POSITION_H_MAX, _OSD_PIP_USER_POSITION_H_MIN, _OSD_PIP_USER_POSITION_H_CENTER);	//Get PIP position value in 0%~100%
  dv_SerialTransmitHex(ucValue);	//Send Hue value to UART

}



//*********************************************************
// Routine: dv_Serial_PipVPosn_Para0
// Usage: Process RS232 0xA5  PIP vertical position command parameter byte 0 including:
//        ?: inquiry (0~100%), +: increase, -: decrease, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_PipVPosn_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_PIP_USER_POSITION_V(), _OSD_PIP_USER_POSITION_V_MAX, _OSD_PIP_USER_POSITION_V_MIN, _OSD_PIP_USER_POSITION_V_CENTER);	//Get PIP vertical position value in 0%~100%
      if(ucCmdPara == '+'){
	if(value1<100)
	  value1++;			//Increase PIP vertical position value if it's less than max 100%
      }
      else{
	if(value1>0)
	  value1--;			//Decrease PIP vertical position value if it's more than min 0%
      }
      SET_OSD_PIP_POSITION_TYPE(_PIP_POSITON_USER);		//Set as PIP position type as user define
      RTDNVRamSaveOsdUserData();				//Save PIP position type in System EEPROM
      SET_OSD_PIP_USER_POSITION_V(UserCommonAdjustPercentToRealValue(value1, _OSD_PIP_USER_POSITION_V_MAX, _OSD_PIP_USER_POSITION_V_MIN, _OSD_PIP_USER_POSITION_V_CENTER));		//Save new PIP position value in 0~100%
#if(_PIP_DISPLAY_SUPPORT == _ON)
      if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
      {
	  UserCommonAdjustPipSubTimingFormat();			//Adjust new saved PIP position
      }
#endif
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_OSD_PIP_POSITION_TYPE(_PIP_POSITON_USER);		//Set as PIP position type as user define
      RTDNVRamSaveOsdUserData();				//Save PIP position type in System EEPROM
      RTDEepromRestorePipVPosn();	//Restore default PIP vertical position from EEPROM
  }
  if(ucCmd==0xff){
	//We need to send value back to UART
      value1 = UserCommonAdjustRealValueToPercent(GET_OSD_PIP_USER_POSITION_V(), _OSD_PIP_USER_POSITION_V_MAX, _OSD_PIP_USER_POSITION_V_MIN, _OSD_PIP_USER_POSITION_V_CENTER);	//Get PIP position value in 0%~100%
      dv_SerialTransmitHex((BYTE)value1);
  }
}


//*********************************************************
// Routine: dv_Serial_PipVPosn_Para1
// Usage: Process RS232 0xA5 PIP vertical position 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_PipVPosn_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 position range is 0x00 to 0x64 (0%~100%)
  if(ucValue > _OSD_PIP_USER_POSITION_V_MAX){
      ucValue = _OSD_PIP_USER_POSITION_V_MAX;		//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_PIP_USER_POSITION_V_MIN){
      ucValue = _OSD_PIP_USER_POSITION_V_MIN;
  }
  //Save and set new value
  SET_OSD_PIP_POSITION_TYPE(_PIP_POSITON_USER);		//Set as PIP position type as user define
  RTDNVRamSaveOsdUserData();				//Save PIP position type in System EEPROM
  SET_OSD_PIP_USER_POSITION_V(UserCommonAdjustPercentToRealValue(ucValue, _OSD_PIP_USER_POSITION_V_MAX, _OSD_PIP_USER_POSITION_V_MIN, _OSD_PIP_USER_POSITION_V_CENTER));		//Save new PIP position value in 0~100%
#if(_PIP_DISPLAY_SUPPORT == _ON)
  if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
  {
	  UserCommonAdjustPipSubTimingFormat();			//Adjust new saved PIP position
  }
#endif
  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save the OSD position into system EEPROM

  ucValue = UserCommonAdjustRealValueToPercent(GET_OSD_PIP_USER_POSITION_V(), _OSD_PIP_USER_POSITION_V_MAX, _OSD_PIP_USER_POSITION_V_MIN, _OSD_PIP_USER_POSITION_V_CENTER);	//Get PIP position value in 0%~100%
  dv_SerialTransmitHex(ucValue);	//Send Hue value to UART

}










//*********************************************************
// Routine: dv_Serial_NewInputDisp_Para0
// Usage: Process RS232 0xBC new input display video info setting command parameter byte 0 including:
//        ?: inquiry, 0: disable, 1: enable;
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_NewInputDisp_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;

  if(ucCmdPara == '?'){
      ucCmd = 0xff;			//Denote we need to send status to UART
  }
  if(ucCmdPara == '0'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_NEW_INPUT_DISP_INFO(_OFF);	//Disable new input display video info
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save value into system EEPROM
  }
  if(ucCmdPara == '1'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_NEW_INPUT_DISP_INFO(_ON);	//Enable new input display video info
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save value into system EEPROM
  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_TxByteToUART(GET_NEW_INPUT_DISP_INFO()+0x30);			//Send enable/disable status to UART
  }

}



//*********************************************************
// Routine: dv_Serial_Timeout_Para0
// Usage: Process RS232 0x93 OSD menu timeout command parameter byte 0 including:
//        ?: inquiry (10~60sec), +: increase 1 sec, -: decrease 1 sec, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_Timeout_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  int value1;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      RTDEepromRestoreOSDTimeout();	//Restore default OSD timeout from EEPROM
  }
  else if(ucCmdPara == '-'||ucCmdPara == '+'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      value1 = GET_OSD_TIME_OUT();		//Get OSD menu timeout value
      if(ucCmdPara == '+'){
	  if(value1<_OSD_TIMEOUT_MAX)		//Check if less than max 60 sec
	    value1++;				//Increase OSD timeout by 1 sec if it's less than max value
      }
      else{
	  if(value1>_OSD_TIMEOUT_MIN)		//Check if more than min 10 sec
	    value1--;				//Decrease OSD timeout by 1 sec if it's more than min value
      }
      SET_OSD_TIME_OUT(value1);			//Save new OSD timeout
      ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);	//Set new OSD timeout in effect
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save value into system EEPROM
  }
  if(ucCmd==0xff){
     //We need to send value back to UART
     value1 = GET_OSD_TIME_OUT();		//Get OSD menu timeout value
     dv_SerialTransmitHex((BYTE)value1);
  }
}


//*********************************************************
// Routine: dv_Serial_Timeout_Para1
// Usage: Process RS232 0x93 OSD menu timeout 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Timeout_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value

  if(ucValue > _OSD_TIMEOUT_MAX){
      ucValue = _OSD_TIMEOUT_MAX;		//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_TIMEOUT_MIN){
      ucValue = _OSD_TIMEOUT_MIN;
  }
  //Save and set new value
  SET_OSD_TIME_OUT(ucValue);			//Save new OSD timeout
  ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);	//Set new OSD timeout in effect
  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Going to save value into system EEPROM

  ucValue = GET_OSD_TIME_OUT();		//Get OSD menu timeout value
  dv_SerialTransmitHex(ucValue);	//Send Hue value to UART

}


//*********************************************************
// Routine: dv_Serial_HotKeys_Para1
// Usage: Process RS232 0xa0 hot keys definition
//	  '1'/'2': 'n': set hot keys 1,2 with 'n' function, 'r'/'R': reset, '?' query
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_HotKeys_Para1(BYTE *ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE ucHotKey;

  //Check if it set hot key 1 or 2
  if(ucCmdPara[0]=='1'||ucCmdPara[0]=='2'){

      ucCmd = 0xfe;				//Assume we need to change hot key definition first

      //Check if it's to change hot key definition
      switch(ucCmdPara[1]){
	case '1':
	  ucHotKey = _HOT_KEY_VOLUME;
	  break;
	case '2':
	  ucHotKey = _HOT_KEY_BRIGHTNESS;
	  break;
	case '3':
	  ucHotKey = _HOT_KEY_CONTRAST;
	  break;
	case '4':
	  ucHotKey = _HOT_KEY_SAT;
	  break;
	case '5':
	  ucHotKey = _HOT_KEY_INPUT;
	  break;
	case '9':
	  ucHotKey = _HOT_KEY_PIP_SIZE;
	  break;
	case 'B':
	  ucHotKey = _HOT_KEY_NO_FUNCTION;
	  break;
	case 'D':
	  ucHotKey = _HOT_KEY_INPUT_SWAP;
	  break;
	case 'E':
	  ucHotKey = _HOT_KEY_ASPECT_RATIO;
	  break;
	case 'G':
	  ucHotKey = _HOT_KEY_HUE;
	  break;
	case 'H':
	  ucHotKey = _HOT_KEY_BACKLIGHT;
	  break;
	case 'I':
	  ucHotKey = _HOT_KEY_AUTO_ADJUST;
	  break;
	case 'L':
	  ucHotKey = _HOT_KEY_SHARPNESS;
	  break;
	case 'M':
	  ucHotKey = _HOT_KEY_DISPLAYMODE;
	  break;
	default:
	  ucCmd = 0;				//If no match to change hot key cmd, No action
	  break;

      }

      if(ucCmdPara[1] == '?'){
    	ucCmd = 0xff;			//Denote we need to send status to UART
      }

      if(ucCmdPara[1] == 'R'||ucCmdPara[1] == 'r'){
          ucCmd = 0xff;				//Denote we need to send status to UART
          if(ucCmdPara[0]=='1'){
              RTDEepromRestoreHotKey1();		//Restore default hot keys 1
          }
          else{
              RTDEepromRestoreHotKey2();		//Restore default hot keys 2
          }
      }

      //Check if it's requested to change hot key definition
      if(ucCmd == 0xfe){
	  ucCmd = 0xff;			//Denote we need to send status to UART
	  //Check to change hot key 1 or 2 definition
	  if(ucCmdPara[0]=='1'){
	      SET_HOT_KEY_1(ucHotKey);
	  }
	  else{
	      SET_HOT_KEY_2(ucHotKey);
	  }
	  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Save new setting of hot key
      }

      //Check if it's requested to send status to UART
      if(ucCmd == 0xff){
	  //Check if we send hot key 1 or 2 status
	  if(ucCmdPara[0]=='1'){
	      ucHotKey = GET_HOT_KEY_1();
	  }
	  else{
	      ucHotKey = GET_HOT_KEY_2();
	  }
	 //Get hot key UART sent value
	 switch(ucHotKey){
	    case _HOT_KEY_VOLUME:
	      ucCmd = '1';
	      break;
	    case _HOT_KEY_BRIGHTNESS:
	      ucCmd = '2';
	      break;
	    case _HOT_KEY_CONTRAST:
	      ucCmd = '3';
	      break;
	    case _HOT_KEY_SAT:
	      ucCmd = '4';
	      break;
	    case _HOT_KEY_INPUT:
	      ucCmd = '5';
	      break;
	    case _HOT_KEY_PIP_SIZE:
	      ucCmd = '9';
	      break;
	    case _HOT_KEY_NO_FUNCTION:
	      ucCmd = 'B';
	      break;
	    case _HOT_KEY_INPUT_SWAP:
	      ucCmd = 'D';
	      break;
	    case _HOT_KEY_ASPECT_RATIO:
	      ucCmd = 'E';
	      break;
	    case _HOT_KEY_HUE:
	      ucCmd = 'G';
	      break;
	    case _HOT_KEY_BACKLIGHT:
	      ucCmd = 'H';
	      break;
	    case _HOT_KEY_AUTO_ADJUST:
	      ucCmd = 'I';
	      break;
	    case _HOT_KEY_SHARPNESS:
	      ucCmd = 'L';
	      break;
	    case _HOT_KEY_DISPLAYMODE:
	      ucCmd = 'M';
	      break;
	    default:
	      ucCmd = '?';				//If no match hot key cmd, send '?'
	      break;

	  }

	 dv_TxByteToUART(ucCmd);			//Send hot key value to UART

      }


  }

}




//*********************************************************
// Routine: dv_Serial_PipSource_Para0
// Usage: Process RS232 0xa7 (P2)input source selection command parameter byte 0 including:
//        ?: inquiry, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_PipSource_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd,ucRegion;
  WORD usInput;


  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART

      ucRegion = dv_GetDisplayRegion(2);	//Get the region of P2 of current display mode
      if(ucRegion!=_DISPLAY_RGN_NONE)		//If picture is shown in current display mode, we change to default source. Otherwise, we don't know which 2P picture (PIP, PBP) refer to
      {
	  RTDEepromRestoreInputSource(2);		//Write default input source for 2P into EEPROM
	  RTDNVRamLoadOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Read default source from EEPROM
	  UserAdjustRegionInputPort(ucRegion, GET_OSD_2P_INPUT_SOURCE());
      }

  }

  if(ucCmd==0xff)
  {
      //Send the 2P input source value to UART
      usInput = dv_InputSourceValue(GET_OSD_2P_INPUT_SOURCE());
      dv_TxByteToUART((usInput&0xff));
      dv_TxByteToUART((BYTE)((usInput&0xff00)>>8));

  }

}

//*********************************************************
// Routine: dv_Serial_PipSize_Para0
// Usage: Command 0xA6: Set the PIP window size with range 0~10
//        ?: inquiry, +: increase size, -: decrease size, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_PipSize_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART

      RTDRestorePIPSize();				//Load default PIP scaling value
      if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP) //If it's in PIP mode
      {
	  UserCommonAdjustPipSubTimingFormat();	//Set new PIP window size
      }

  }

  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);	//Temporary set right key message which is same as "+" function
      }
      else{
	SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);	//Temporary set left key message which is same as "-" function
      }

      g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_PIP_SIZE(), _OSD_PIP_SIZE_MAX, _OSD_PIP_SIZE_MIN, _OFF);	//Increase/decrease PIP window value by one
      SET_OSD_PIP_SIZE(g_usAdjustValue);	//Save new PIP window size
      SET_KEYMESSAGE(_NONE_KEY_MESSAGE);	//Clear key message
      if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
      {
	  UserCommonAdjustPipSubTimingFormat();	//Set new PIP window size
      }


  }

  if(ucCmd==0xff)
  {
      //Send the PIP size to UART
      dv_SerialTransmitHex(GET_OSD_PIP_SIZE());

  }

}

//*********************************************************
// Routine: dv_Serial_PipSize_Para1
// Usage: Command 0xA6: Set the PIP window size 2-digit input (00~10)
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_PipSize_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 PIP size is 00 to 10
  if(ucValue > _OSD_PIP_SIZE_MAX){
      ucValue = _OSD_PIP_SIZE_MAX;		//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_PIP_SIZE_MIN){
      ucValue = _OSD_PIP_SIZE_MIN;
  }
  //Save and set new value
  SET_OSD_PIP_SIZE(ucValue);	//Save new PIP window size
  if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
  {
	  UserCommonAdjustPipSubTimingFormat();	//Set new PIP window size
  }
  RTDNVRamSaveOsdUserData();				//Save PIP size in System EEPROM

  dv_SerialTransmitHex(GET_OSD_PIP_SIZE());		//Dump PIP size to UART

}


//*********************************************************
// Routine: dv_Serial_SourceLayout_Para0
// Usage: Command 0x9A: Set the video source layout in 1P, PIP or PBP
//        ?: inquiry, +: next source, -: previous source, R/r: restore default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_SourceLayout_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      RTDRestoreDisplayMode();			//Load default display mode 1P full window
      UserAdjustDisplayMode();			//Execute default display mode

  }

  else if(ucCmdPara == '0'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_OSD_DISPLAY_MODE(_OSD_DM_1P);		//Set to 1P full window display mode
      UserAdjustDisplayMode();      		//Execute 1P display mode
  }

  else if(ucCmdPara == '1'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_OSD_DISPLAY_MODE(_OSD_DM_2P_PIP);	//Set to PIP display mode
      UserAdjustDisplayMode();      		//Execute PIP display mode
  }

  else if(ucCmdPara == '2'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_OSD_DISPLAY_MODE(_OSD_DM_2P_LR);	//Set to 2 windows PBP left right display mode
      UserAdjustDisplayMode();      		//Execute new display mode
  }

  else if(ucCmdPara == '3'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_OSD_DISPLAY_MODE(_OSD_DM_2P_TB);	//Set to 2 windows PBP top bottom display mode
      UserAdjustDisplayMode();      		//Execute new display mode
  }

  else if(ucCmdPara == '4'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_OSD_DISPLAY_MODE(_OSD_DM_4P);		//Set to 4 windows PBP display mode
      UserAdjustDisplayMode();      		//Execute new display mode
  }

  if(ucCmd==0xff)
  {
      switch (GET_OSD_DISPLAY_MODE())		//Look up display mode value defined in RS232 0x9a cmd
      {
	case _OSD_DM_1P:
	  ucCmd = '0';
	  break;
	case _OSD_DM_2P_PIP:
	  ucCmd = '1';
	  break;
	case _OSD_DM_2P_LR:
	  ucCmd = '2';
	  break;
	case _OSD_DM_2P_TB:
	  ucCmd = '3';
	  break;
	case _OSD_DM_4P:
	  ucCmd = '4';
	  break;
	default:
	  ucCmd = 0xff;
	  break;
      }

      dv_TxByteToUART(ucCmd); 		//Send the display mode value to UART

  }

}






//*********************************************************
// Routine: dv_Serial_AutoPowerSave_Para0
// Usage: Process RS232 0x9F auto power saving setting command
//        ?: inquiry,0: disable, 1: enable, R/r: reset to default
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_AutoPowerSave_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      RTDEepromRestoreAutoPowerSave();							//Load default

  }
  else if(ucCmdPara == '0'){
      ucCmd = 0xfe;				//Denote we need to save and send status to UART
      SET_AUTO_POWER_SAVE(_OFF);		//Disable auto power saving
  }
  else if(ucCmdPara == '1'){
      ucCmd = 0xfe;				//Denote we need to save and send status to UART
      SET_AUTO_POWER_SAVE(_ON);	//Enable auto power saving
  }

  if(ucCmd == 0xfe)			//Check if we need to save status
  {
      ucCmd = 0xff;			//Denote we need to send status to UART
      //Save new auto power saving setting
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Save new setting of auto power save in NVRAM

  }


  if(ucCmd==0xff)
  {
      dv_TxByteToUART(GET_AUTO_POWER_SAVE()+0x30);	//Send Auto power saving state to UART (+0x30 to transform 0,1 to their ASCII value)
  }

}










//*********************************************************
// Routine: dv_Serial_AckSet_Para0
// Usage: Process RS232 0xc1 RS-232 acknowledge on/off comand
//        0: ack off; 1: ack on;
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_AckSet_Para0(BYTE ucCmdPara)
{

  if(ucCmdPara == '1'){
     g_ucSerialAcknowledge = TRUE;	//ack on
     dv_TxByteToUART('1');
  }
  if(ucCmdPara == '0'){
      g_ucSerialAcknowledge = FALSE;	//ack off
      dv_TxByteToUART('0');
  }


}








//*********************************************************
//Ray 2016.10.14
// Routine: dv_Serial_TestPattern_Para0
// Usage: Process RS232 0xcd display test pattern command
//        '0': normal mode (disable test pattern), '1': red test pattern,
//        '2': green test pattern, '3': blue test pattern
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_TestPattern_Para0(BYTE ucCmdPara)
{
  if(ucCmdPara =='0'){
      ScalerDDomainPatternGenEnable(_DISABLE);		//Disable test pattern generation
      if(GET_RGN_DISPLAY_STATE(0)!=_DISPLAY_STATE_ACTIVE){
	  ScalerDDomainBackgroundEnable(_DISPLAY_PATH_ALL, _ENABLE);	//Enable black background if there is no valid video in main picture 1
      }
      dv_TxByteToUART(ucCmdPara);			//dump command parameter back to UART
  }
  //Check if enable display whole screen test pattern
  if((ucCmdPara>='1')&&(ucCmdPara<='3')){
      switch(ucCmdPara){
	case '1':
	  ScalerDDomainPatternGenAdjustColor(255, 0, 0);	//Set red pattern for whole screen
	  break;
	case '2':
	  ScalerDDomainPatternGenAdjustColor(0, 255, 0);	//Set green pattern
	  break;
	case '3':
	  ScalerDDomainPatternGenAdjustColor(0, 0, 255);	//Set blue pattern
	  break;
	default:
	  break;
      }
      ScalerDDomainPatternGenEnable(_ENABLE);				//Enable test pattern
      ScalerDDomainBackgroundEnable(_DISPLAY_PATH_ALL, _DISABLE);	//Disable black ground
      dv_TxByteToUART(ucCmdPara);
  }

}
#endif   //Ray 2017.02.20


//Ray BKL 2017.06.19: dv_Serial_BackLight_PWM_DA_Para0
//*********************************************************
// Routine: dv_Serial_BackLight_PWM_DA_Para0
// Usage: Process RS232 0xe5 PWM D/A selection command
//        ?: inquiry, 0: PWM, 1: D/A , R/r: reset
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_BackLight_PWM_DA_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;				//Denote we need to send status to UART
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_BACKLIGHT_CONTROL(BKL_PWM);		//Default backlight control mode is PWM
      dv_AdjustBacklightPWMFreq(GET_BACKLIGHT_PWM_FREQ());				//Update backlight level after changing to PWM

  }
  else if(ucCmdPara == '0'||ucCmdPara == '1'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      if(ucCmdPara == '0'){
	  SET_BACKLIGHT_CONTROL(BKL_PWM);	//backlight control mode is PWM
     	  dv_AdjustBacklightPWMFreq(GET_BACKLIGHT_PWM_FREQ());				//Update backlight level after changing to PWM
      }
      else{
	  SET_BACKLIGHT_CONTROL(BKL_DA);	//Default backlight control mode is D/A
	  dv_AdjustBacklightPWMFreq(160);			//Update backlight PWM frequency to D/A one (160Hz) and then update backlight level
      }

  }

  if(ucCmd==0xff){
      //Send current backlight D/A PWM setting to UART
      if(GET_BACKLIGHT_CONTROL()==BKL_PWM){
	  dv_TxByteToUART('0');
      }else{
	  dv_TxByteToUART('1');
      }

  }

}








//*********************************************************
// Routine: dv_Serial_PWMFrequency_Para0
// Usage: Process RS232 0xe6 PWM frequency command
//        ?: inquiry, +: increase, -: decrease, R/r: reset
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_PWMFrequency_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  WORD sFreq;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_BACKLIGHT_PWM_FREQ(DFFAULT_PWM_FREQUENCY);		//Restore default backlight PWM frequency
      dv_AdjustBacklightPWMFreq(GET_BACKLIGHT_PWM_FREQ());	//Ray BKL 2017.02.21: Adjust new PWM frequency

  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;			//Denote we need to send status to UART

      sFreq = GET_BACKLIGHT_PWM_FREQ();
      if(ucCmdPara == '+'){
	if(sFreq < _BL_FREQ_MAX){
	    sFreq += 20;				//Increase 20Hz for each step
	}
      }
      else{
	if(sFreq > _BL_FREQ_MIN){
	    sFreq -= 20;				//Increase 20Hz for each step
	}
      }
      //Ensure PWM frequency is within min and max value
      if(sFreq>_BL_FREQ_MAX){
	 sFreq = _BL_FREQ_MAX;
      }
      if(sFreq<_BL_FREQ_MIN){
	  sFreq = _BL_FREQ_MIN;
      }
      SET_BACKLIGHT_PWM_FREQ(sFreq);			//Ray BKL 2017.02.21: Save new PWM frequency in system parameter
      dv_AdjustBacklightPWMFreq(sFreq);			//Ray BKL 2017.02.21: Adjust new PWM frequency
  }

  if(ucCmd==0xff)
  {
      sFreq = GET_BACKLIGHT_PWM_FREQ();
      dv_TxByteToUART(dv_HexDigitToAscii((sFreq&0xff00)>>8));	//Send high byte PWM frequency to UART
      dv_SerialTransmitHex((sFreq&0xff));			//Send low byte PWM frequency to UART
  }

}


//*********************************************************
// Routine: dv_Serial_PWMFrequency_Para2
// Usage: Process RS232 0xe6 PWM frequency command
//        3 digit PWM frequency
// Input: ucCmdPara: contain three command parameter byte
//**********************************************************
void dv_Serial_PWMFrequency_Para2(BYTE *ucCmdPara)
{
  BYTE ucCmd = 0;
  DWORD sFreq;					//Ray BKL 2017.02.21: Since the period arg of MDrv_PWM_Period( ) is DWORD unit
  BYTE * ucCmdPointer;

  ucCmdPointer = ucCmdPara;
  ucCmd = *ucCmdPointer;			//Get 1st parameter frequency hex byte
  sFreq = dv_AsciiToHexDigit(ucCmd)*0x100;	//Transform it to 3rd digit value
  ucCmdPointer++;				//Go to next byte
  sFreq += dv_GetAsciiValue(ucCmdPointer);	//transform ASCII two byte to digit value

  if(sFreq<_BL_FREQ_MIN){sFreq = _BL_FREQ_MIN;}
  else if ((sFreq>=_BL_FREQ_MIN)&&(sFreq<120)){sFreq = _BL_FREQ_MIN;}
  else if ((sFreq>=120)&&(sFreq<140)){sFreq = 120;}
  else if ((sFreq>=140)&&(sFreq<160)){sFreq = 140;}
  else if ((sFreq>=160)&&(sFreq<180)){sFreq = 160;}
  else if ((sFreq>=180)&&(sFreq<200)){sFreq = 180;}
  else if ((sFreq>=200)&&(sFreq<220)){sFreq = 200;}
  else if ((sFreq>=220)&&(sFreq<240)){sFreq = 220;}
  else if ((sFreq>=240)&&(sFreq<260)){sFreq = 240;}
  else if ((sFreq>=260)&&(sFreq<280)){sFreq = 260;}
  else if ((sFreq>=280)&&(sFreq<300)){sFreq = 280;}
  else if ((sFreq>=300)&&(sFreq<320)){sFreq = 300;}
  else if ((sFreq>=320)&&(sFreq<340)){sFreq = 320;}
  else if ((sFreq>=340)&&(sFreq<360)){sFreq = 340;}
  else if ((sFreq>=360)&&(sFreq<380)){sFreq = 360;}
  else if ((sFreq>=380)&&(sFreq<400)){sFreq = 380;}
  else if ((sFreq>=400)&&(sFreq<420)){sFreq = 400;}
  else if ((sFreq>=420)&&(sFreq<_BL_FREQ_MAX)){sFreq = 420;}
  else if  (sFreq>=_BL_FREQ_MAX){sFreq = _BL_FREQ_MAX;}
  else{sFreq = 160;}


  SET_BACKLIGHT_PWM_FREQ(sFreq);		//Ray BKL 2017.02.21: Save new PWM frequency in system parameter
  dv_AdjustBacklightPWMFreq(sFreq);		//Ray BKL 2017.02.21: Adjust new PWM frequency

  ucCmd = sFreq;
  ucCmd = (sFreq&0xff00)>>8;			//Extract the high byte of 2-byte freq value
  dv_TxByteToUART(dv_HexDigitToAscii(ucCmd));	//Send high byte PWM frequency to UART
  dv_SerialTransmitHex((sFreq&0xff));		//Send low byte PWM frequency to UART


}


//Ray BKL 2017.06.19: dv_Serial_BackLightInvert_Para0
//*********************************************************
// Routine: dv_Serial_BackLightInvert_Para0
// Usage: Process RS232 0xe7 backlight invert selection command
//        ?: inquiry, 0: no invert, 1: invert , R/r: reset
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_BackLightInvert_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;				//Denote we need to send status to UART
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_BACKLIGHT_INVERT(DISABLE);				//Ray BKL 2017.04.25: Default backlight invert is off
      //Update backlight level after changing backlight invert
      Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));

  }
  else if(ucCmdPara == '0'||ucCmdPara == '1'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      if(ucCmdPara == '0'){
	  SET_BACKLIGHT_INVERT(DISABLE);	//DISABLE = 0 means no invert
      }
      else{
	  SET_BACKLIGHT_INVERT(ENABLE);		//ENABLE = 1 means set backlight invert
      }
	//Update backlight level after changing backlight invert
	Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));
  }

  if(ucCmd==0xff){
      dv_TxByteToUART(GET_BACKLIGHT_INVERT()+0x30);	//Send current backlight invert setting to UART
  }

}


//Ray BKL 2017.06.19: dv_Serial_MinBackLightValue_Para0
//*********************************************************
// Routine: dv_Serial_MinBackLightValue_Para0
// Usage: Process RS232 0xee 0x5c min backlight setting command
//        ?: inquiry, +: increase, -: decrease , R/r: reset
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_MinBackLightValue_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd = 0;
  BYTE value;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;				//Denote we need to send status to UART
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      SET_BACKLIGHT_MIN_LEVEL(DEFAULT_MIN_BKL_LEVEL);		//Default min. backlight level
	//Update backlight level after changing min. backlight level
	Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));
  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  value = ENABLE;				//ENABLE means increase value in routine MApp_ZUI_ACT_DecIncValue
      }
      else{
	  value = DISABLE;				//DISABLE means decrease value in routine MApp_ZUI_ACT_DecIncValue
      }

	//Increase/decrease min. backlight level by 1 step, with max value = 50
	SET_BACKLIGHT_MIN_LEVEL(MApp_ZUI_ACT_DecIncValue(
	    value,
	    GET_BACKLIGHT_MIN_LEVEL(), 0, 50, 1));
	//Update backlight level after changing min. backlight level
	Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));

  }

  if(ucCmd==0xff){
      dv_SerialTransmitHex(GET_BACKLIGHT_MIN_LEVEL());			//Send backlight min value to UART
  }

}

//*********************************************************
// Routine: dv_Serial_MinBackLightValue_Para1
// Usage: Process RS232 0xee 0x5c min backlight value 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_MinBackLightValue_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SP-4096 min backlight range is 0~50
  if(ucValue > 50){
      ucValue = 50;						//Set it to max if input value is larger than max
  }


  SET_BACKLIGHT_MIN_LEVEL(ucValue);				//Save the new value in variable

  //Update backlight level after changing min. backlight level
  Panel_Backlight_PWM_ADJ(msAPI_Mode_PictureBackLightN100toReallyValue(stGenSetting.u8Backlight));

  dv_SerialTransmitHex(GET_BACKLIGHT_MIN_LEVEL());		//Send backlight min value to UART


}


//*********************************************************
//Ray DPW 2017.06.19: dv_Serial_DefaultPower_Para2
// Routine: dv_Serial_DefaultPower_Para2
// Usage: Process RS232 0xee 0x6b 0x50 default power on/off command
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_DefaultPower_Para2(BYTE *ucCmdPara)
{

  BYTE ucCmd = 0;

  switch (ucCmdPara[0]){
    case '?':
      ucCmd = 0xff;			//Denote we need to send status to UART
      break;
    case '0':
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_DEFAULT_POWER(_OFF);		//Set default power as off
      break;
    case '1':
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_DEFAULT_POWER(_ON);		//Set default power as on
      break;
    default:
      break;
  }

  if(ucCmd == 0xff){
      dv_TxByteToUART(GET_DEFAULT_POWER()+0x30);		//Send the default power status to UART
  }


}

#if 0			//Ray 2017.02.20
//*********************************************************
// Routine: dv_UserEDID_InputSrc
// Usage: Get user EDID EEPROM input source
// Input: ucCmdPara: pointer to memory saving command parameter byte of input source like 0x48 0x31 (HDMI1), 0x50 0x31(DP1)
// Output: User EDID input source present in _OSD_INPUT_D0, _OSD_INPUT_D1, ..._OSD_INPUT_D4
//         If input source parameter is invalid, it returns 0xff
//**********************************************************
BYTE dv_UserEDID_InputSrc(BYTE *ucCmdPara)
{
  BYTE bSource, bValue;
  WORD usInput;

  bSource = 0xff;	//Set a invalid value first
  //Get the input source byte from command parameter
  ucCmdPara++;
  usInput = (BYTE)*ucCmdPara;
  usInput = (usInput<<8) &0xff00;
  ucCmdPara--;
  usInput = usInput|(BYTE)*ucCmdPara;

  //There are 5 sources having EDID in SVX-4096, get the source value by translating the 2-byte value input
  //Please note VGA doesn't has its own EDID EEPROM
  for(bValue=_OSD_INPUT_D0;bValue<=_OSD_INPUT_D4;bValue++){
      if(dv_InputSourceValue(bValue)==usInput){
	  bSource = bValue;
      }
  }

  return bSource;
}


//*********************************************************
// Routine: dv_UserEDID_EEPROM_Address
// Usage: Get user EDID EEPROM start address
// Input: ucSource: in _OSD_INPUT_D0, _OSD_INPUT_D1, ..._OSD_INPUT_D4
// Output: User EDID EEPROM start address (in word size). If input source byte is invalid, it returns 0xffff
//**********************************************************
WORD dv_UserEDID_EEPROM_Address(BYTE ucSource)
{
  WORD usUserEDIDAdr=0xffff;

  //Check if user input the correct source value
  if(ucSource!=0xff){
      //If yes, assign the user EDID address
      switch(ucSource){
	case _OSD_INPUT_D0:
	  usUserEDIDAdr = _USER_EDID_D0_ADDRESS;
	  break;
	case _OSD_INPUT_D1:
	  usUserEDIDAdr = _USER_EDID_D1_ADDRESS;
	  break;
	case _OSD_INPUT_D2:
	  usUserEDIDAdr = _USER_EDID_D2_ADDRESS;
	  break;
	case _OSD_INPUT_D3:
	  usUserEDIDAdr = _USER_EDID_D3_ADDRESS;
	  break;
	case _OSD_INPUT_D4:
	  usUserEDIDAdr = _USER_EDID_D4_ADDRESS;
	  break;
	default:
	  break;
      }

  }

  return usUserEDIDAdr;

}



//*********************************************************
// Routine: dv_Serial_UserEDID_Para3
// Usage: Process RS232 0xee 0x76 User EDID command
//        1) reset to a input
//        2) hidden command to transmit the EDID memory content of an input to UART
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_UserEDID_Para3(BYTE *ucCmdPara)
{
  BYTE ucEnable,ucSource,ucResult,ucIICDevice;
  BYTE ucEDID[256];
  WORD usUserEDIDAdr;
  int i;

  ucResult = _SUCCESS;	//Init result as success first

  //process reset command "R" or "r"
  if(ucCmdPara[2]=='R'||ucCmdPara[2]=='r'){
     ucSource = dv_UserEDID_InputSrc(ucCmdPara);		//Get input source from parameter arg in form of _OSD_INPUT_D0,..._OSD_INPUT_D4
     usUserEDIDAdr = dv_UserEDID_EEPROM_Address(ucSource);	//Get the user EDID EEPROM start address of input source
     //If input source and thus user EDID EEEPROM start address is valid
     if(usUserEDIDAdr!=0xffff){
	//To reset user EDID EEPROM feature, write user EDID EEPROM enable byte as disable state
	ucEnable = _USER_EDID_DISABLE;
	ucResult &= UserCommonEepromWrite((usUserEDIDAdr-1), 1, (BYTE *)(&ucEnable));
	//Reset the EDID to the preset one
	if(ucSource==_OSD_INPUT_D0){
	    //For D0 (DisplayPort), write preset EDID into it's own internal memory
	    UserCommonInterfaceLoadEmbeddedEdidData();
	    ucResult &= _SUCCESS;
	}
	else{
	  //For D1 to D4, write preset EDID into it's own EEPROM
	  ucResult &= dv_writeEDIDEEPROM(ucSource);
	    //if the board is SVX-4096, we need to change the EDID with preferred timing
	    if(ucBoardVersion == _SVX4096_V20){
		ucResult &= dv_UpdateEDIDPrefTiming(ucSource);
	    }
	}
    }

     dv_TxByteToUART(ucResult+0x30);		//Send back the reset result (0x30 = fail, 0x31 = success)

  }
  //process hidden command "T" or "t" to transmit 256-byte content of current EDID in EDID memory (RAM or EEPROM) to UART
  if(ucCmdPara[2]=='T'||ucCmdPara[2]=='t'){
      ucSource = dv_UserEDID_InputSrc(ucCmdPara);		//Get input source from parameter arg in form of _OSD_INPUT_D0,..._OSD_INPUT_D4
      usUserEDIDAdr = dv_UserEDID_EEPROM_Address(ucSource);	//Get the user EDID EEPROM start address of input source
      //If input source and thus user EDID EEEPROM start address is valid, go to read back the EDID content in EDID memory
      if(usUserEDIDAdr!=0xffff){
	  if(ucSource==_OSD_INPUT_D0){				//if input source is DP
	      for(i=0;i<256;i++){
		 ucEDID[i]=MCU_DDCRAM_D0[i];		//DP EDID is stored in xdata MCU_DDCRAM_D0 location
	      }
	   }
	   else{
	       switch(ucSource){
		 case _OSD_INPUT_D1:
		   ucIICDevice = _IIC_DDC1_EEPROM;
		   break;
		 case _OSD_INPUT_D2:
		   ucIICDevice = _IIC_DDC2_EEPROM;
		   break;
		 case _OSD_INPUT_D3:
		   ucIICDevice = _IIC_DDC3_EEPROM;
		   break;
		 case _OSD_INPUT_D4:
		   ucIICDevice = _IIC_DDC4_EEPROM;
		   break;
		 default:
		   ucIICDevice = _IIC_DDC1_EEPROM;
		   break;
	       }
	       ucResult = dv_EDIDEepromRead(0, 256, ucEDID, ucIICDevice); 		//Read EDID of D1 to D4 which are stored in EEPROM
	       DebugMessageSystem("Ray: Read EDID result", ucResult);
	   }
	  //Send the 256 byte read EDID content in ASCII format
	  for(i=0;i<256;i++){
	      dv_SerialTransmitHex(ucEDID[i]);
	  }

      }

  }

}

//*********************************************************
// Routine: dv_Serial_UserEDID_More
// Usage: Process RS232 0xee 0x76 User EDID command to download 128-byte EDID (either 0~128 blocks or 129~255 blocks)
//        1) Write the 128-byte EDID into SYSTEM EEPROM
//        2) Write the 128-byte EDID into EDID EEPROM (D1~D4 port) or DDC RAM (D0 port)
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_UserEDID_More(BYTE *ucCmdPara)
{
  BYTE ucEnable,ucEDIDStartAddr,ucSource,ucResult,ucTemp;
  BYTE ucEDID[128];
  WORD usUserEDIDAdr;
  BYTE ucEDIDChksum = 0;
  BYTE ucCalChksum = 0;

  ucResult = _SUCCESS;		//Init result as success first
  ucEnable = 0;


  //Check if download 1st block 0~127
  if(ucCmdPara[2]=='S'||ucCmdPara[2]=='s'){
      ucEnable = _1ST_USER_EDID_ENABLE;
      ucEDIDStartAddr = 0x00;			//For first block, the start EDID EEPROM address is 0x00
  }
  //Check if download 2nd block 128~255
  if(ucCmdPara[2]=='E'||ucCmdPara[2]=='e'){
      ucEnable = _2ND_USER_EDID_ENABLE;
      ucEDIDStartAddr = 0x80;			//For second block, the start EDID EEPROM address is 0x80
  }

 if((ucEnable==_1ST_USER_EDID_ENABLE)||(ucEnable==_2ND_USER_EDID_ENABLE)) {

      ucSource = dv_UserEDID_InputSrc(ucCmdPara);		//Get input source from parameter arg in form of _OSD_INPUT_D0,..._OSD_INPUT_D4
      usUserEDIDAdr = dv_UserEDID_EEPROM_Address(ucSource);	//Get the user EDID EEPROM start address of input source

      //If input source and thus user EDID EEEPROM start address is valid
      if(usUserEDIDAdr!=0xffff){
 	//Convert the RS-232 256-byte EDID ASCII data byte to 128-byte EDID data
 	for(ucTemp=0;ucTemp<128;ucTemp++){
 	   ucEDID[ucTemp] = dv_GetAsciiValue((BYTE *)&ucCmdPara[3+ucTemp*2]);
 	  //dv_TxByteToUART(ucEDID[ucTemp]);			//Debug
 	   if(ucTemp<127){
 	      ucCalChksum += ucEDID[ucTemp];			//Calculate checksum of EDID data
 	   }
 	}

 	//Calculate the checksum of 128-byte EDID
 	ucCalChksum = (BYTE)(0x100 - ucCalChksum);
 	//DebugMessageSystem("Ray: Cal EDID chksum", ucCalChksum);
 	//DebugMessageSystem("Ray: User EDID chksum", ucEDID[127]);
 	//Write the user EDID into SYSTEM EEPROM only if calculated checksum = checksum byte
 	if (ucCalChksum == ucEDID[127]){

	  UserCommonEepromRead((usUserEDIDAdr-1), 1, (BYTE *)(&ucTemp));			//Read back current EDID EEPROM enable byte
	  if(ucEnable==_1ST_USER_EDID_ENABLE){
	      ucTemp &= 0xf0;		//Filter out LSB 4-bit in order to set _1ST_USER_EDID_ENABLE
	  }
	  else{
	      ucTemp &= 0x0f;		//Filter out MSB 4-bit in order to set _2ND_USER_EDID_ENABLE
	  }
	  ucTemp |= ucEnable;
	  ucResult &= UserCommonEepromWrite((usUserEDIDAdr-1), 1, (BYTE *)(&ucTemp));		//To write update user EDID EEPROM enable byte

	  ucResult &= UserCommonEepromWrite((usUserEDIDAdr+ucEDIDStartAddr), 128, (BYTE *)ucEDID);		//Write to 128-byte EDID in SYSTEM EEPROM

	  //Write the user EDID 128-byte into EDID EEPROM (D1~D4) or DDC RAM (D0)
	  if(ucSource==_OSD_INPUT_D0){
	      //For D0 (DisplayPort), write user EDID into it's own internal memory
	      memcpy((MCU_DDCRAM_D0+ucEDIDStartAddr), ucEDID, 0x80);
	      ucResult &= _SUCCESS;
	  }
	  else{
	    //For D1 to D4, write user EDID into it's own EEPROM
	    ucResult &= dv_write128ByteEDIDEEPROM(ucSource, ucEDID, ucEDIDStartAddr);	//Write user EDID in first 128-byte (0~127)
	  }

	  //After writing the EDID, calculate its EDID checksum from EDID memory and check if it's the same as previous calculated one
	  dv_CalEDIDChksum((ucSource-1), ucEDIDStartAddr, &ucEDIDChksum);
	  //DebugMessageSystem("Ray: Cal EDID chksum", ucCalChksum);
	  //DebugMessageSystem("Ray: User EDID chksum", ucEDIDChksum);
	  //DebugMessageSystem("Ray: User EDID result", ucResult);
	  if((ucCalChksum==ucEDIDChksum)&&(ucResult == _SUCCESS)){
	      dv_TxByteToUART('1');	//Send 0x31 to denote success user EDID download
	  }
	  else{
	      dv_TxByteToUART('0');	//Send 0x30 to denote fail user EDID download
	  }

 	}

     }

  }

}

//*********************************************************
// Routine: dv_Serial_NT72324_Para2
// Usage: Process RS232 0xee 0x78 NT72324 generic command control
// Input: ucCmdPara: pointer to memory saving command parameter byte
//	  The parameter sequence is Main Cmd, Sub Cmd, Data
//	  Note that if Data is 0x3F, the command will be read back instead
//**********************************************************
void dv_Serial_NT72324_Para2(BYTE *ucCmdPara)
{

  BYTE ucValue[4];
  dv_NT72324Init();			//Before send command, init IIC interface of NT72324
  if(ucCmdPara[2]!=0x3f){
      dv_NT72324WtCmd(ucCmdPara[0],ucCmdPara[1],ucCmdPara[2]);	//Write command to NT72324
  }
  else{
      //if Data (ucCmdPara[2] is 0x3F, the command will be read back instead
      dv_NT72324RdCmd(ucCmdPara[0],ucCmdPara[1],ucValue);
      dv_TxByteToUART(ucValue[0]+0x30);		//Send read NT72324 value to UART
  }




}

//*********************************************************
// Routine: dv_Serial_OSDSwitchMountLockt_Para0
// Usage: Process RS232 0xee 0x62 OSD switch mount lock command
//        ?: inquiry, 0: no lock, 1: lock
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_OSDSwitchMountLock_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd=0;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;				//Denote we need to send status to UART
  }

  else if(ucCmdPara == '0'||ucCmdPara == '1'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      g_ucOsdSwitchMountLock = ucCmdPara-0x30;		//Set OSD switch mount no lock = 0, or lock = 1 according to input command stored in ucCmdPara
  }


  if(ucCmd==0xff){
      dv_TxByteToUART(g_ucOsdSwitchMountLock+0x30);	//Send current OSD switch mount lock setting to UART
  }

}

//*********************************************************
// Routine: dv_Serial_Vx1PinState_Para1
// Usage: Process RS232 0xee 0x73 Vx1 pin state stting
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_Vx1PinState_Para1(BYTE *ucCmdPara)
{
  //ucCmdPara[0] stores Vx1 pin. After ucCmdPara[0]- 0x30, pin 15 =_Vx1_Pin15=0,pin16=_Vx1_Pin16=1,....
  //ucCmdPara[1] stores pin state: After ucCmdPara[1]-0x30,  0= Low, 1=high
  if(ucCmdPara[0]>=0x30&&ucCmdPara[0]<=0x39){
      if(ucCmdPara[1]=='0'||ucCmdPara[1]=='1'){
	OsdSetVx1PinState((ucCmdPara[0]-0x30),ucCmdPara[1]-0x30);	//Set Vx1 pin state
	RTDEepromSaveVx1PinState();					//save new pin state into System EEPROM
	dv_TxByteToUART(ucCmdPara[1]);					//Dump back the pin value
      }
  }

}




//*********************************************************
// Routine: dv_Serial_MEMC_Para1
// Usage: Process RS232 0xca NT72324 MEMC setting command
//        ?: inquiry, 0: disable, 1: enable
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_MEMC_Para1(BYTE *ucCmdPara)
{
  BYTE ucCmd=0;
  //MEMC setting is '9' next byte after 0xCA
  if(ucCmdPara[0]=='9'){
    if(ucCmdPara[1] == '?'){
	  ucCmd = 0xff;				//Denote we need to send status to UART
    }
    else if(ucCmdPara[1] == 'R'||ucCmdPara[1] == 'r'){
	ucCmd = 0xff;					//Denote we need to send status to UART
	dv_NT72324Memc(_DISABLE);			//Ray 2016.11.10: Reset MEMC to disable state
	SET_OSD_MEMC(_DISABLE);
	SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Save new setting in NVRAM
    }
    else if(ucCmdPara[1] == '0'||ucCmdPara[1] == '1'){
	ucCmd = 0xff;					//Denote we need to send status to UART
	ucCmdPara[1] -= 0x30;				//Convert command parameter from 0x30/0x31 to 0x00/0x01
	dv_NT72324Memc(ucCmdPara[1]);			//Set MEMC
	SET_OSD_MEMC(ucCmdPara[1]);
	SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Save new setting in NVRAM
    }


    if(ucCmd==0xff){
	dv_TxByteToUART(dv_NT72324MemcStatus()+0x30);	//Send current NT72324 MEMC setting to UART
    }
  }
}




//Ray 2016.12.15
//*********************************************************
// Routine: dv_SendBCDValuesToUART
// Usage: Transform values to BCD ASCII code and send to UART
//        E.g. 610 is sent as 0x36 0x31 0x30 to UART
// Input: ucSendByteNo = No of byte in value to be sent: 1~4
//        usSendValue = value to be sent (max is WORD size)
//**********************************************************
void dv_SendBCDValuesToUART(BYTE ucSendByteNo,WORD usSendValue)
{
  BYTE ucDigit;
  BYTE ucBcdASCII;

  //DebugMessageSystem("Send Value", usSendValue);
  switch(ucSendByteNo){
    case 4:
      ucDigit = (BYTE)(usSendValue/1000);		//Get 4th BCD digit
      ucBcdASCII = dv_HexDigitToAscii(ucDigit);		//Convert BCD digital to ASCII
      dv_TxByteToUART(ucBcdASCII);
      usSendValue = usSendValue-1000*ucDigit;		//Get 3rd BCD digit
      //We intentionally don't add "break;" so as to display remaining digits
    case 3:
      ucDigit = (BYTE)(usSendValue/100);
      //DebugMessageSystem("BCD 3rd digit", ucDigit);
      ucBcdASCII = dv_HexDigitToAscii(ucDigit);		//Convert BCD digital to ASCII
      dv_TxByteToUART(ucBcdASCII);
      usSendValue = usSendValue - 100*(ucDigit);	//Get 2nd BCD digit
      //We intentionally don't add "break;" so as to display remaining digits
    case 2:
      ucDigit = (BYTE)(usSendValue/10);
      //DebugMessageSystem("BCD 2nd digit", ucDigit);
      ucBcdASCII = dv_HexDigitToAscii(ucDigit);		//Convert BCD digital to ASCII
      dv_TxByteToUART(ucBcdASCII);
      usSendValue = usSendValue - 10*(ucDigit);		//Get 1st BCD digit
      //We intentionally don't add "break;" so as to display remaining digits
    case 1:
      ucDigit = (BYTE)usSendValue & 0x0f;
      //DebugMessageSystem("BCD 1st digit", ucDigit);
      ucBcdASCII = dv_HexDigitToAscii(ucDigit);		//Convert BCD digital to ASCII
      dv_TxByteToUART(ucBcdASCII);
    default:
      break;
  }

}


//*********************************************************
// Routine: dv_SendValuesToUART
// Usage: Transform values to ASCII code and send to UART
// Input: ucSendByteNo = No of byte in value to be sent: 1~4
//        usSendValue = value to be sent (max is WORD size)
//**********************************************************
void dv_SendValuesToUART(BYTE ucSendByteNo,WORD usSendValue)
{
  BYTE ucTemp1;

  if(ucSendByteNo==1){
      ucTemp1 = ((BYTE)usSendValue & 0x0f);
      ucTemp1 = dv_HexDigitToAscii(ucTemp1);			//Convert hex digital to ASCII
      dv_TxByteToUART(ucTemp1);
  }

  if(ucSendByteNo==2){
      ucTemp1 = (BYTE)usSendValue;
      dv_SerialTransmitHex(ucTemp1);
  }

  if(ucSendByteNo==3){
	ucTemp1 = 0x0f & (BYTE)(usSendValue/256);		//Get the 3rd digit hex byte
	ucTemp1 = dv_HexDigitToAscii(ucTemp1);			//Convert hex digital to ASCII
	dv_TxByteToUART(ucTemp1);				//Send 3rd digit hex byte in ASCII to UART1
	ucTemp1 = (BYTE)usSendValue;				//Get 2nd & 1st digit hex value and then send to UART1
	dv_SerialTransmitHex(ucTemp1);
  }
  if(ucSendByteNo==4){
	ucTemp1 = (BYTE)(usSendValue/256);			//Get the 4th & 3rd digit hex byte
	dv_SerialTransmitHex(ucTemp1);				//Send 4th & 3rd digit hex byte in ASCII to UART1
	ucTemp1 = (BYTE)usSendValue;				//Get 2nd & 1st digit hex value and then send to UART1
	dv_SerialTransmitHex(ucTemp1);
  }
}




//*********************************************************
// Routine: dv_Serial_EEPanelTime_Para0
// Usage: Process RS232 0xee 0x74 panel timing setting no parameter
//        command: 0x57 to write panel timing to EEPROM,
//                 0x4B to read checksum of all timing parameter in g_stEEPanel
//                 0x4C to read all panel timing parameter. It dump each timing starting with 0xEE 0x74 0xYY nnnn
//                      to facilitate saving dump data to file for send back to SVX-4096 later
// Input: *ucCmdPara: pointer to command byte
//**********************************************************
void dv_Serial_EEPanelTime_Para0(BYTE *ucCmdPara)
{
  BYTE ucChecksum=0;
  BYTE ucTxPara2UART=0;
  BYTE ucTxChecksum2UART=0;
  BYTE ucResult;
  WORD usParaValue;

  //0x57 is write panel timing setting to EEPROM command
  //0x4B is read checksum of current panel timing parameters
  if(ucCmdPara[0]==0x57||ucCmdPara[0]==0x4B||ucCmdPara[0]==0x4C){
      if(ucCmdPara[0]==0x57){			//0x57: write and then read panel timing setting between system EEPROM
	ucResult = RTDEepromSavePanelTiming();	//Save all panel timing parameters in g_stEEPanel to system EEPROM
	RTDEepromLoadPanelTiming();		//Read back all panel timing parameters of g_stEEPanel from system EEPROM to g_stEEPanel in SRAM
	ucTxPara2UART = 0;			//Ray 2016.12.15: Denote we won't send timing parameters to UART
	ucTxChecksum2UART = 0;			//Ray 2016.12.15: Denote we won't send checksum to UART
	dv_TxByteToUART(ucResult+0x30);		//Ray 2016.12.15: Send back save panel timing parameters result (0x30: fail, 0x31: success)

      }
      else if(ucCmdPara[0]==0x4B){
	  //This is 0x4B, we only need to send checksum to UART
	  ucTxPara2UART = 0;			//Denote will not send timing parameters to UART
	  ucTxChecksum2UART = 1;			//Denote will send checksum to UART
      }
      else{
	  //This is 0x4C, we need to send timing to UART
	  ucTxPara2UART = 1;			//Denote will send timing parameters to UART
	  //RTDEepromLoadPanelTiming();		//Ray 2016.12.15: Read back all panel timing parameters of g_stEEPanel from system EEPROM to g_stEEPanel in SRAM
	  ucTxChecksum2UART = 0;		//Denote will not send checksum to UART

      }
      //Then dump all panel timing parameters of g_stEEPanel to UART. Their RS-232 command is ranged from 0x30 to 0x4A
      ucCmdPara[1]=0x3F;			//Set 0x3F in order to dump the panel timing parameter to UART
      for(ucCmdPara[0]=0x30;ucCmdPara[0]<=0x4A;ucCmdPara[0]++){
	  if(ucTxPara2UART == 1){
	      dv_TxByteToUART(0xee);			//Send back command header 0xee 0x74 first
	      dv_TxByteToUART(0x74);
	      dv_TxByteToUART(ucCmdPara[0]);		//Dump back command byte to UART first before dump panel timing
	  }
	  usParaValue = dv_Serial_EEPanelTime_Para1(ucCmdPara,ucTxPara2UART);		//ucTxPara2UART: 1 = Dump timing parameter value to UART, 0 = no dump
	  ucChecksum += (BYTE)(usParaValue&0xff);				//Add low byte to checksum
	  ucChecksum += (BYTE)((usParaValue>>8)&0xff);				//Add high byte to checksum
      }
      if(ucTxChecksum2UART==1){
	  dv_TxByteToUART(ucChecksum);					//At last, Dump the checksum value to UART
      }
  }


}


//*********************************************************
// Routine: dv_Serial_EEPanelTime_Para1
// Usage: Process RS232 0xee 0x74 panel timing setting one parameter byte
//        of command: 0x33, 0x34, 0x35 and all command with 0x3F inquiry value
// Input: ucCmdPara: pointer to memory saving command parameter byte
//        ucTx2UART: 1 = send back timing value to UART; 0 = no send
// Output: panel parameter value sent to UART
//**********************************************************
WORD dv_Serial_EEPanelTime_Para1(BYTE *ucCmdPara, BYTE ucTx2UART)
{
  BYTE ucSendByteNo=0;
  WORD usSendValue=0;		//Send value is just the panel parameter value in SRAM (without transform to ASCII value)


  switch(ucCmdPara[0])
  {
    case 0x30:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 3;					//Denote we will send 3 byte to UART
	  usSendValue = _PANEL_TYP_FRAME_RATE/10;		//Ray 2016.12.20: Sent frame rate unit is in Hz (not 0.1Hz)
      }
      break;
    case 0x31:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 3;					//Denote we will send 3 byte to UART
	  usSendValue = _PANEL_MAX_FRAME_RATE/10;		//Ray 2016.12.20: Sent frame rate unit is in Hz (not 0.1Hz)
      }
      break;
    case 0x32:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 3;					//Denote we will send 3 byte to UART
	  usSendValue = _PANEL_MIN_FRAME_RATE/10;		//Ray 2016.12.20: Sent frame rate unit is in Hz (not 0.1Hz)
      }
      break;
    case 0x33:							//Set panel style command
      if(ucCmdPara[1]>0x30 && ucCmdPara[1]<0x36 || ucCmdPara[1]==0x3F ){
	  if(ucCmdPara[1]!=0x3F ){				//Support input values 0x31~0x35
	      _PANEL_STYLE = ucCmdPara[1]-0x30;
	  }
	  ucSendByteNo = 1;					//Denote we will send 1 byte to UART
	  usSendValue = _PANEL_STYLE;				//Save send value
      }
      break;
    case 0x34:							//Set eDP PHY rate command
      if(ucCmdPara[1]>0x30 && ucCmdPara[1]<0x33 || ucCmdPara[1]==0x3F  ){   //Support input values 1~2
	  if(ucCmdPara[1]!=0x3F ){
	      _DPTX_PANEL_PHY_RATE = ucCmdPara[1]-0x30;
	  }
	  ucSendByteNo = 1;					//Denote we will send 1 byte to UART
	  usSendValue = _DPTX_PANEL_PHY_RATE;			//Save send value
      }
      break;
    case 0x35:							//Set LVDS/Vx1 output ports command
      if(ucCmdPara[1]>=0x30 && ucCmdPara[1]<=0x33|| ucCmdPara[1]==0x3F  ){	//Support input values 0x30~0x33
	  if(ucCmdPara[1]!=0x3F ){
	      _LVDS_OUTPUT_PORT = ucCmdPara[1]-0x30;
	  }
	  ucSendByteNo = 1;					//Denote we will send 1 byte to UART
	  usSendValue = _LVDS_OUTPUT_PORT;			//Save send value
      }
      break;
    case 0x36:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DH_START;			//Save send value
      }
      break;
    case 0x37:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DH_WIDTH;			//Save send value
      }
      break;
    case 0x38:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DV_TOTAL;			//Save send value
      }
      break;
    case 0x39:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DV_TOTAL_MAX;			//Save send value
      }
      break;
    case 0x3A:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DV_TOTAL_MIN;			//Save send value
      }
      break;
    case 0x3B:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DV_START;			//Save send value
      }
      break;
    case 0x3C:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DV_HEIGHT;			//Save send value
      }
      break;
    case 0x3D:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DH_TOTAL;			//Save send value
      }
      break;
    case 0x3E:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DH_TOTAL_MAX;			//Save send value
      }
      break;
    case 0x3F:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_DH_TOTAL_MIN;			//Save send value
      }
      break;
    case 0x40:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 2;					//Denote we will send 2 byte to UART
	  usSendValue = _PANEL_DH_SYNC_WIDTH;			//Save send value
      }
      break;
    case 0x41:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 2;					//Denote we will send 2 byte to UART
	  usSendValue = _PANEL_DV_SYNC_HEIGHT;			//Save send value
      }
      break;
    case 0x42:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 3;					//Denote we will send 3 byte to UART
	  usSendValue = _PANEL_PIXEL_CLOCK;			//Save send value
      }
      break;
    case 0x43:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 3;					//Denote we will send 3 byte to UART
	  usSendValue = _PANEL_PIXEL_CLOCK_MAX;			//Save send value
      }
      break;
    case 0x44:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 3;					//Denote we will send 3 byte to UART
	  usSendValue = _PANEL_PIXEL_CLOCK_MIN;			//Save send value
      }
      break;
    case 0x45:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_POWER_ON_T1;			//Save send value
      }
      break;
    case 0x46:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_POWER_ON_T2;			//Save send value
      }
      break;
    case 0x47:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_POWER_ON_T3;			//Save send value
      }
      break;
    case 0x48:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_POWER_OFF_T4;			//Save send value
      }
      break;
    case 0x49:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_POWER_OFF_T5;			//Save send value
      }
      break;
    case 0x4A:
      if(ucCmdPara[1]==0x3F ){
	  ucSendByteNo = 4;					//Denote we will send 4 byte to UART
	  usSendValue = _PANEL_POWER_OFF_T6;			//Save send value
      }
      break;

    default:
      break;
  }


  //Check if we need to send value to UART
  if(ucSendByteNo>0 && ucTx2UART == 1){
      dv_SendBCDValuesToUART(ucSendByteNo,usSendValue);		//Ray 2016.12.15: Send value in BCD ASCII to UART
      //dv_SendValuesToUART(ucSendByteNo,usSendValue);
  }

  return usSendValue;

}

//*********************************************************
// Routine: dv_Serial_EEPanelTime_Para2
// Usage: Process RS232 0xee 0x74 panel timing setting two parameter byte
//        of command: 0x40, 0x41
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_EEPanelTime_Para2(BYTE *ucCmdPara)
{
  BYTE ucSendByteNo=0;
  WORD usSendValue;		//Send value is just the panel parameter value in SRAM (without transform to ASCII value)
  BYTE ucValue = dv_GetAsciiBCDValue(&ucCmdPara[1]);			//Ray 2016.12.15: transform ASCII BCD value to digit value
  //BYTE ucValue = dv_GetAsciiValue(&ucCmdPara[1]);			//transform ASCII to digit value

  switch(ucCmdPara[0])
  {
    case 0x40:						//Set DH sync width
      _PANEL_DH_SYNC_WIDTH = ucValue;
      ucSendByteNo = 2;					//Denote we will send 2 byte to UART
      usSendValue = _PANEL_DH_SYNC_WIDTH;		//Save send value
      break;
    case 0x41:						//Set DV sync height
      _PANEL_DV_SYNC_HEIGHT = ucValue;
      ucSendByteNo = 2;					//Denote we will send 2 byte to UART
      usSendValue = _PANEL_DV_SYNC_HEIGHT;		//Save send value
      break;
    default:
      break;
  }

  //Check if we need to send value to UART
  if(ucSendByteNo>0){
      dv_SendBCDValuesToUART(ucSendByteNo,usSendValue);		//Ray 2016.12.15: Send value in BCD ASCII to UART
      //dv_SendValuesToUART(ucSendByteNo,usSendValue);
  }

}

//*********************************************************
// Routine: dv_Serial_EEPanelTime_Para3
// Usage: Process RS232 0xee 0x74 panel timing setting three parameter byte
//        of command: 0x30, 0x31, 0x32, 0x42, 0x43, 0x44
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_EEPanelTime_Para3(BYTE *ucCmdPara)
{

  BYTE ucSendByteNo=0;
  WORD usSendValue;		//Send value is just the panel parameter value in SRAM (without transform to ASCII value)
  BYTE ucValue1[2];
  WORD usValue;
  //Ray 2016.12.15: Add sentence to convert input parameter in BCD format to actual value
  ucValue1[0] = 0x30;				//Set MSB 4th byte has nothing as it's 3-byte parameter (0x30 is BCD ASCII 0 value)
  ucValue1[1] = ucCmdPara[1];			//Get MSB 3rd byte
  usValue = dv_GetAsciiBCDValue(ucValue1)*100;	//Transform MSB 3rd byte ASCII BCD to digit value
  usValue += dv_GetAsciiBCDValue(&ucCmdPara[2]);	//Transform 1st & 2nd byte ASCII BCD to digit value and get actual digital value of whole parameters
  /*
  ucValue1[0] = 0;				//Set MSB 4th byte has nothing as it's 3-byte parameter
  ucValue1[1] = ucCmdPara[1];			//Get MSB 3rd byte
  usValue = dv_GetAsciiValue(&ucValue1)*256;	//Transform MSB 3rd byte ASCII to digit value
  usValue += dv_GetAsciiValue(&ucCmdPara[2]);	//Transform 1st & 2nd byte ASCII to digit value and get actual digital value of whole parameters
  */

  switch(ucCmdPara[0])
  {
    case 0x30:						//Set typical frame rate in 0.1Hz unit
      _PANEL_TYP_FRAME_RATE = usValue*10;		//Ray 2016.12.20: Received frame rate unit is in Hz (not 0.1Hz)
      ucSendByteNo = 3;					//Denote we will send 3 byte to UART
      usSendValue = _PANEL_TYP_FRAME_RATE/10;		//Ray 2016.12.20: Sent frame rate unit is in Hz (not 0.1Hz)
      break;
    case 0x31:						//Set max frame rate in 0.1Hz unit
      _PANEL_MAX_FRAME_RATE = usValue*10;		//Ray 2016.12.20: Received frame rate unit is in Hz (not 0.1Hz)
      ucSendByteNo = 3;					//Denote we will send 3 byte to UART
      usSendValue = _PANEL_MAX_FRAME_RATE/10;		//Ray 2016.12.20: Sent frame rate unit is in Hz (not 0.1Hz)
      break;
    case 0x32:						//Set min frame rate in 0.1Hz unit
      _PANEL_MIN_FRAME_RATE = usValue*10;		//Ray 2016.12.20: Received frame rate unit is in Hz (not 0.1Hz)
      ucSendByteNo = 3;					//Denote we will send 3 byte to UART
      usSendValue = _PANEL_MIN_FRAME_RATE/10;		//Ray 2016.12.20: Sent frame rate unit is in Hz (not 0.1Hz)
      break;
    case 0x42:						//Set typical pixel clock in MHz
      _PANEL_PIXEL_CLOCK = usValue;
      ucSendByteNo = 3;					//Denote we will send 3 byte to UART
      usSendValue = _PANEL_PIXEL_CLOCK;			//Save send value
      break;
    case 0x43:						//Set max pixel clock in MHz
      _PANEL_PIXEL_CLOCK_MAX = usValue;
      ucSendByteNo = 3;					//Denote we will send 3 byte to UART
      usSendValue = _PANEL_PIXEL_CLOCK_MAX;		//Save send value
      break;
    case 0x44:						//Set min pixel clock in MHz
      _PANEL_PIXEL_CLOCK_MIN = usValue;
      ucSendByteNo = 3;					//Denote we will send 3 byte to UART
      usSendValue = _PANEL_PIXEL_CLOCK_MIN;		//Save send value
      break;

    default:
      break;
  }

  //Check if we need to send value to UART
  if(ucSendByteNo>0){
      dv_SendBCDValuesToUART(ucSendByteNo,usSendValue);		//Ray 2016.12.15: Send value in BCD ASCII to UART
      //dv_SendValuesToUART(ucSendByteNo,usSendValue);
  }

}

//*********************************************************
// Routine: dv_Serial_EEPanelTime_Para4
// Usage: Process RS232 0xee 0x74 panel timing setting 4 parameter byte
//        of command: 0x36~0x3F, 0x45~0x4A
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_EEPanelTime_Para4(BYTE *ucCmdPara)
{
  BYTE ucSendByteNo=0;
  WORD usSendValue;		//Send value is just the panel parameter value in SRAM (without transform to ASCII value)
  BYTE ucValue1[2];
  WORD usValue;
  //Ray 2016.12.15: Add sentence to convert input parameter in BCD format to actual value
  ucValue1[0] = ucCmdPara[1];			//Get MSB 4th byte
  ucValue1[1] = ucCmdPara[2];			//Get MSB 3rd byte
  usValue = dv_GetAsciiBCDValue(ucValue1)*100;	//Transform MSB 4th & 3rd byte ASCII BCD to digit value
  usValue += dv_GetAsciiBCDValue(&ucCmdPara[3]);	//Transform 1st & 2nd byte ASCII BCD to digit value and get actual digital value of whole parameters
  /*
  ucValue1[0] = ucCmdPara[1];			//Get MSB 4th byte
  ucValue1[1] = ucCmdPara[2];			//Get MSB 3rd byte
  usValue = dv_GetAsciiValue(&ucValue1)*256;	//Transform MSB 4th & 3rd byte ASCII to digit value
  usValue += dv_GetAsciiValue(&ucCmdPara[3]);	//Transform 1st & 2nd byte ASCII to digit value and get actual digital value of whole parameters
   */
  ucSendByteNo = 4;					//By default, denote we will send 4 parameter byte back to UART first

  switch(ucCmdPara[0])
  {
    case 0x36:						//Set display horizontal start
      _PANEL_DH_START = usValue;
      usSendValue = _PANEL_DH_START;			//Save send value
      break;
    case 0x37:						//Set display horizontal width
      _PANEL_DH_WIDTH = usValue;
      usSendValue = _PANEL_DH_WIDTH;			//Save send value
      break;
    case 0x38:						//Set display vertical total typical
      _PANEL_DV_TOTAL = usValue;
      usSendValue = _PANEL_DV_TOTAL;			//Save send value
      break;
    case 0x39:						//Set display vertical total maximum
      _PANEL_DV_TOTAL_MAX = usValue;
      usSendValue = _PANEL_DV_TOTAL_MAX;		//Save send value
      break;
    case 0x3A:						//Set display vertical total minimum
      _PANEL_DV_TOTAL_MIN = usValue;
      usSendValue = _PANEL_DV_TOTAL_MIN;		//Save send value
      break;
    case 0x3B:						//Set display vertical start
      _PANEL_DV_START = usValue;
      usSendValue = _PANEL_DV_START;			//Save send value
      break;
    case 0x3C:						//Set display vertical height
      _PANEL_DV_HEIGHT = usValue;
      usSendValue = _PANEL_DV_HEIGHT;			//Save send value
      break;
    case 0x3D:						//Set display horizontal total typical
      _PANEL_DH_TOTAL = usValue;
      usSendValue = _PANEL_DH_TOTAL;			//Save send value
      break;
    case 0x3E:						//Set display horizontal total max
      _PANEL_DH_TOTAL_MAX = usValue;
      usSendValue = _PANEL_DH_TOTAL_MAX;		//Save send value
      break;
    case 0x3F:						//Set display horizontal total min
      _PANEL_DH_TOTAL_MIN = usValue;
      usSendValue = _PANEL_DH_TOTAL_MIN;		//Save send value
      break;
/***************************************************************
      T1: The delay time between PPWR pin set high to turn on panel power and then set either
          LVDS ports power on Vby1 PHY power on and init HTPDN (enble its interrupt, set it controlled by hardware)
          DP phy init
      T2: The delay time between interface port power on and init (i.e. above 1 of 3 items) and
          LVDS PLL on Vby1 HTPDN handler:(check if HTPDN is set low by Vby1 receiver. If yes, disable HTPDN, HTPDN controlled by Firmware,
          set HTPDN pull low, set LOCKN interrupt enable) DP link sequence and set video stream parameter
      T3: The delay time between above 1 of 3 items and Vby1 LockN handler: (check if LOCKN status is success. If not, force transfer to ALN pattern)  and then backlight on
          LVDS and DP just go to backlight on
***************************************************************/
    case 0x45:						//Set panel power on time T1
      _PANEL_POWER_ON_T1 = usValue;
      usSendValue = _PANEL_POWER_ON_T1;			//Save send value
      break;
    case 0x46:						//Set panel power on time T2
      _PANEL_POWER_ON_T2 = usValue;
      usSendValue = _PANEL_POWER_ON_T2;			//Save send value
      break;
    case 0x47:						//Set panel power on time T3
      _PANEL_POWER_ON_T3 = usValue;
      usSendValue = _PANEL_POWER_ON_T3;			//Save send value
      break;
    case 0x48:						//Set panel power off time T4
      _PANEL_POWER_OFF_T4 = usValue;
      usSendValue = _PANEL_POWER_OFF_T4;		//Save send value
      break;
    case 0x49:						//Set panel power off time T5
      _PANEL_POWER_OFF_T5 = usValue;
      usSendValue = _PANEL_POWER_OFF_T5;		//Save send value
      break;
    case 0x4A:						//Set panel power off time T6
      _PANEL_POWER_OFF_T6 = usValue;
      usSendValue = _PANEL_POWER_OFF_T6;		//Save send value
      break;
    default:
      ucSendByteNo = 0;					//If no match of command, no need to send data to UART
      break;
  }

  //Check if we need to send value to UART
  if(ucSendByteNo>0){
      dv_SendBCDValuesToUART(ucSendByteNo,usSendValue);		//Ray 2016.12.15: Send value in BCD ASCII to UART
      //dv_SendValuesToUART(ucSendByteNo,usSendValue);
  }


}

//*********************************************************
// Routine: dv_Serial_PIP_Blender_Para0
// Usage: Process RS232 0xed PIP transparency control command
//        ?: inquiry, +: increase, 1: decrease , R/r: reset
// Input: ucCmdPara: ucCmdPara[0] first command parameter byte
//**********************************************************
void dv_Serial_PIP_Blender_Para0(BYTE ucCmdPara)
{
  BYTE ucCmd;
  BYTE value;

  if(ucCmdPara == '?'){
	ucCmd = 0xff;				//Denote we need to send status to UART
  }

  else if(ucCmdPara == 'R'||ucCmdPara == 'r'){
      ucCmd = 0xff;				//Denote we need to send status to UART
      RTDEepromRestorePipTransparency();	//Restore default PIP transparency value

  }
  else if(ucCmdPara == '+'||ucCmdPara == '-'){
      ucCmd = 0xff;					//Denote we need to send status to UART
      if(ucCmdPara == '+'){
	  SET_KEYMESSAGE(_RIGHT_KEY_MESSAGE);		//Right key message means increase value
      }
      else{
	  SET_KEYMESSAGE(_LEFT_KEY_MESSAGE);		//Left key message means decrease value
      }

      value = (BYTE)OsdDisplayDetOverRange(GET_OSD_PIP_TRANSPARENCY(), _OSD_PIP_TRANSPARENCY_MAX, _OSD_PIP_TRANSPARENCY_MIN, _OFF);
      SET_KEYMESSAGE(_NONE_KEY_MESSAGE);		//Clear key message after changing value
      SET_OSD_PIP_TRANSPARENCY(value);     		//Save the new value in variable
      if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
      {
	  UserAdjustPipTransparency();			//Adjust new transparency value
      }
      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Go to save new value in NVRAM
  }

  //Check if it is requested to send status to UART
  if(ucCmd == 0xff){
      dv_SerialTransmitHex(GET_OSD_PIP_TRANSPARENCY());		//Send PIP transparency value

  }

}


//*********************************************************
// Routine: dv_Serial_PIP_Blender_Para1
// Usage: Process RS232 0xed PIP transparency control 2-digit input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_PIP_Blender_Para1(BYTE *ucCmdPara)
{
  BYTE ucValue;

  ucValue = dv_GetAsciiValue(&ucCmdPara[0]);			//transform ASCII to digit value
  //SVX-4096 position range is 0x00 to 0x0A (0~10)
  if(ucValue > _OSD_PIP_TRANSPARENCY_MAX){
      ucValue = _OSD_PIP_TRANSPARENCY_MAX;			//Set it to max if input value is larger than max
  }
  if(ucValue < _OSD_PIP_TRANSPARENCY_MIN){
      ucValue = _OSD_PIP_TRANSPARENCY_MIN;
  }

  SET_OSD_PIP_TRANSPARENCY(ucValue);     		//Save the new value in variable
  if(GET_OSD_DISPLAY_MODE() == _OSD_DM_2P_PIP)
  {
	  UserAdjustPipTransparency();			//Adjust new transparency value
  }
  SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);	//Go to save new value in NVRAM


  dv_SerialTransmitHex(GET_OSD_PIP_TRANSPARENCY());		//Send PIP transparency value

}






//*********************************************************
// Routine: dv_GetSelectAllRegion
// Usage: Get the selected as all region according to the display mode
//        This is used to set those regional parameters like brightness, contrast
//	  for all regions in current display mode
// Output: all region value like _OSD_SR_1P_FULL, _OSD_SR_2P_PIP_FULL
//**********************************************************
BYTE dv_GetSelectAllRegion()
{
  BYTE ucRegion;

  switch(GET_OSD_DISPLAY_MODE())
  {
	case _OSD_DM_1P:
	  ucRegion = _OSD_SR_1P_FULL;
	  break;
	case _OSD_DM_2P_PIP:
	  ucRegion = _OSD_SR_2P_PIP_FULL;
	  break;
	case _OSD_DM_2P_LR:
	  ucRegion = _OSD_SR_2P_LR_FULL;
	  break;
	case _OSD_DM_2P_TB:
	  ucRegion = _OSD_SR_2P_TB_FULL;
	  break;
	case _OSD_DM_4P:
	  ucRegion = _OSD_SR_4P_FULL;
	  break;
	default:
	  ucRegion = _DISPLAY_RGN_NONE;
	  break;
  }

  return ucRegion;
}




//*********************************************************
// Routine: dv_GetDisplayRegion
// Usage: Get the display region of a picture according to current display mode (1P, PIP, 2P/4P PBP)
//        The output value can be used as a argument to change input source in routine UserAdjustRegionInputPort()
// Input: Picture (1=1P, 2=2P, 3=3P, 4=4P)
// Output: Dislay region: _DISPLAY_RGN_1P, _DISPLAY_RGN_MAIN,....,_DISPLAY_RGN_RB
//**********************************************************
BYTE dv_GetDisplayRegion(BYTE ucPicture)
{
  BYTE ucRegion = _DISPLAY_RGN_NONE;

  //Select 1P picture region
  if(ucPicture==1)
  {
      switch(GET_OSD_DISPLAY_MODE())
      {
	case _OSD_DM_1P:
	  ucRegion = _DISPLAY_RGN_1P;
	  break;
	case _OSD_DM_2P_PIP:
	  ucRegion = _DISPLAY_RGN_MAIN;
	  break;
	case _OSD_DM_2P_LR:
	  ucRegion = _DISPLAY_RGN_LEFT;
	  break;
	case _OSD_DM_2P_TB:
	  ucRegion = _DISPLAY_RGN_TOP;
	  break;
	case _OSD_DM_4P:
	  ucRegion = _DISPLAY_RGN_LT;
	  break;
	default:
	  ucRegion = _DISPLAY_RGN_NONE;
	  break;
      }
  }



  //Select 2P picture region
  if(ucPicture==2)
  {
      switch(GET_OSD_DISPLAY_MODE())
      {
	case _OSD_DM_2P_PIP:
	  ucRegion = _DISPLAY_RGN_SUB;
	  break;
	case _OSD_DM_2P_LR:
	  ucRegion = _DISPLAY_RGN_RIGHT;
	  break;
	case _OSD_DM_2P_TB:
	  ucRegion = _DISPLAY_RGN_BOTTOM;
	  break;
	case _OSD_DM_4P:
	  ucRegion = _DISPLAY_RGN_LB;
	  break;
	default:
	  ucRegion = _DISPLAY_RGN_NONE;
	  break;
      }
  }

  if(ucPicture==3)
  {
      switch(GET_OSD_DISPLAY_MODE())
      {
	case _OSD_DM_4P:
	  ucRegion = _DISPLAY_RGN_RT;
	  break;
	default:
	  ucRegion = _DISPLAY_RGN_NONE;
	  break;
      }
  }

  if(ucPicture==4)
  {
      switch(GET_OSD_DISPLAY_MODE())
      {
	case _OSD_DM_4P:
	  ucRegion = _DISPLAY_RGN_RB;
	  break;
	default:
	  ucRegion = _DISPLAY_RGN_NONE;
	  break;
      }
  }

  return ucRegion;

}










//*********************************************************
// Routine: dv_Serial_PipSource_Para1
// Usage: Process RS232 0xa7 input PIP/PBP 2P source 2-byte value input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_PipSource_Para1(BYTE *ucCmdPara)
{
  BYTE bValue,bSource,ucRegion;
  WORD usInput;

  bValue = (BYTE)*ucCmdPara;

  //0x63 and 0x64 are for P3 and P4 source input. We won't process here.
  if(bValue!=0x63 && bValue!=0x64){

    bSource = 0xff;	//Set a invalid value first
    usInput = ucCmdPara[1];
    usInput = (usInput<<8) &0xff00;
    usInput = usInput|ucCmdPara[0];


    //There are 5 sources in SVX-4096, get the source value by translating the 2-byte value input
    for(bValue=_OSD_INPUT_A0;bValue<=_OSD_INPUT_D4;bValue++){
	if(dv_InputSourceValue(bValue)==usInput){
	    bSource = bValue;
	}
    }

    //Check if user input the correct source value
    if(bSource!=0xff){
	//Check if user input VGA while VGA port is not available
	//Ray 2016.03.17: Change the checking VGA port availability to g_usVGAEnable
      if(!((bSource == _OSD_INPUT_A0)&&(g_usVGAEnable==_DISABLE))){

	ucRegion = dv_GetDisplayRegion(2);	//Get the region of P2 of current display mode
	if(ucRegion!=_DISPLAY_RGN_NONE)		//If 2P picture is shown in current display mode, we change the 2P source
	{
	    SET_OSD_2P_INPUT_SOURCE(bSource);			//Set the user input source
	    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_DISPLAYMODEDATA_MSG);	//Denote going to save new input into NVRAM
	    UserAdjustRegionInputPort(ucRegion, GET_OSD_2P_INPUT_SOURCE());
	}
      }
    }

    //Send the input source value to UART
    usInput = dv_InputSourceValue(GET_OSD_2P_INPUT_SOURCE());
    dv_TxByteToUART((usInput&0xff));
    dv_TxByteToUART((BYTE)((usInput&0xff00)>>8));

  }
  //Send the input source value to UART for P3 or P4 inquiry
  if(ucCmdPara[0]==0x63||ucCmdPara[0]==0x64){
     bValue = 0;

    if(ucCmdPara[0]==0x63){
	if(ucCmdPara[1]=='R'||ucCmdPara[1]=='r'){
	  bValue = 0xff;				//Denote need to dump source value to UART
	  RTDEepromRestoreInputSource(3);		//Write default input source for P3 into EEPROM
	  RTDNVRamLoadOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Read default source from EEPROM
	  ucRegion = dv_GetDisplayRegion(3);		//Get the region of P3 of current display mode
	  if(ucRegion!=_DISPLAY_RGN_NONE)		//If picture is shown in current display mode, we change to default source
	  {
	      UserAdjustRegionInputPort(ucRegion, GET_OSD_3P_INPUT_SOURCE());
	  }
	}
	usInput = dv_InputSourceValue(GET_OSD_3P_INPUT_SOURCE());
    }

    if(ucCmdPara[0]==0x64){
	if(ucCmdPara[1]=='R'||ucCmdPara[1]=='r'){
	  bValue = 0xff;				//Denote need to dump source value to UART
	  RTDEepromRestoreInputSource(4);		//Write default input source for P4 into EEPROM
	  RTDNVRamLoadOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Read default source from EEPROM
	  ucRegion = dv_GetDisplayRegion(4);		//Get the region of P4 of current display mode
	  if(ucRegion!=_DISPLAY_RGN_NONE)		//If picture is shown in current display mode, we change to default source
	  {
	      UserAdjustRegionInputPort(ucRegion, GET_OSD_4P_INPUT_SOURCE());
	  }
	}
	usInput = dv_InputSourceValue(GET_OSD_4P_INPUT_SOURCE());
    }

    if(ucCmdPara[1]=='?'){
	bValue = 0xff;				//Denote need to dump source value to UART
    }

    if(bValue == 0xff){
      //Dump source value to UART
      dv_TxByteToUART((usInput&0xff));
      dv_TxByteToUART((BYTE)((usInput&0xff00)>>8));
    }
  }


}

//*********************************************************
// Routine: dv_Serial_PipSource_Para2
// Usage: Process RS232 0xa7 input PBP P3 (0x63) & P4 (0x64) source 2-byte value input
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_PipSource_Para2(BYTE *ucCmdPara)
{
  BYTE bValue,bSource,bChangeInput,ucRegion;
  WORD usInput;

  //We process 0x63 and 0x64 for P3 and P4 source input.
  bChangeInput = (BYTE)*ucCmdPara;
  if(bChangeInput!=0x63 || bChangeInput!=0x64){

    bSource = 0xff;	//Set a invalid value first
    ucCmdPara+=2;
    usInput = (BYTE)*ucCmdPara;
    usInput = (usInput<<8) &0xff00;
    ucCmdPara--;
    usInput = usInput|(BYTE)*ucCmdPara;


    //There are 5 sources in SVX-4096, get the source value by translating the 2-byte value input
    for(bValue=_OSD_INPUT_A0;bValue<=_OSD_INPUT_D4;bValue++){
	if(dv_InputSourceValue(bValue)==usInput){
	    bSource = bValue;
	}
    }

    //Check if user input the correct source value
    if(bSource!=0xff){
	//Check if user input VGA while VGA port is not available
	//Ray 2016.03.17: Change the checking VGA port availability to g_usVGAEnable
      if(!((bSource == _OSD_INPUT_A0)&&(g_usVGAEnable==_DISABLE))){
	if(bChangeInput==0x63){  //Change P3 source

	  ucRegion = dv_GetDisplayRegion(3);	//Get the region of P3 of current display mode
	  if(ucRegion!=_DISPLAY_RGN_NONE)		//If P3 picture is shown in current display mode, we change the P3 source
	  {
	      SET_OSD_3P_INPUT_SOURCE(bSource);			//Set the user input source
	      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_DISPLAYMODEDATA_MSG);	//Denote going to save new input into NVRAM
	      UserAdjustRegionInputPort(ucRegion, GET_OSD_3P_INPUT_SOURCE());
	  }
	}
	else{			//Change P4 source

	  ucRegion = dv_GetDisplayRegion(4);	//Get the region of P4 of current display mode
	  if(ucRegion!=_DISPLAY_RGN_NONE)		//If P4 picture is shown in current display mode, we change the P4 source
	  {
	      SET_OSD_4P_INPUT_SOURCE(bSource);			//Set the user input source
	      SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_DISPLAYMODEDATA_MSG);	//Denote going to save new input into NVRAM
	      UserAdjustRegionInputPort(ucRegion, GET_OSD_4P_INPUT_SOURCE());
	  }
	}

      }
    }


    //Send the input source value to UART
    if(bChangeInput==0x63){
	usInput = dv_InputSourceValue(GET_OSD_3P_INPUT_SOURCE());
    }
    else{
	usInput = dv_InputSourceValue(GET_OSD_4P_INPUT_SOURCE());
    }
    dv_TxByteToUART((usInput&0xff));
    dv_TxByteToUART((BYTE)((usInput&0xff00)>>8));

  }

}





//*********************************************************
// Routine: dv_Serial_ColorEffectExt_Para2
// Usage: Process RS232 0xee 0x71 0x30 color effect command
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_ColorEffectExt_Para2(BYTE *ucCmdPara)
{

  BYTE ucCmd = 0;
  BYTE ucEffect;
  if(ucCmdPara[0]=='?'){
    	ucCmd = 0xff;			//Denote we need to send status to UART
  }
  else if(ucCmdPara[0] == 'R'||ucCmdPara[0] == 'r'){
      ucCmd = 0xff;			//Denote we need to send status to UART
      SET_OSD_SELECT_REGION(dv_GetSelectAllRegion());		//Select all regions
      RTDNVRamSaveOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Save select all region to System EEPROM
      RTDEepromRestoreColorEffect();		//Restore default color effect from EEPROM
      UserAdjustOsdSelectRegionColorProc();	//Apply setting to all regions
  }
  else{
      ucCmd = 0xfe;				//Denote we need to set color effect
       switch(ucCmdPara[0] ){
 	case '0':
 	  ucEffect = _COLOREFFECT_STANDARD;	//Standard mode
 	  break;
 	case '1':
 	  ucEffect = _COLOREFFECT_GAME;		//Game mode
 	  break;
 	case '2':
 	  ucEffect = _COLOREFFECT_MOVIE;	//Movie mode
 	  break;
 	case '3':
 	  ucEffect = _COLOREFFECT_PHOTO;	//Movie mode
 	  break;
 	case '4':
 	  ucEffect = _COLOREFFECT_VIVID;	//Movie mode
 	  break;
 	case '5':
 	  ucEffect = _COLOREFFECT_USER;		//User mode
 	  break;
 	default:
 	  ucCmd = 0;				//Undefine command, no action
 	  break;
       }
  }

   //Check if we need to set color effect
   if(ucCmd == 0xfe){
       ucCmd = 0xff;			//Denote we need to send status to UART

       //Change effect only if it's different from current one
       if(GET_OSD_COLOR_EFFECT(GET_OSD_SELECT_REGION()) !=ucEffect){
 	SET_OSD_SELECT_REGION(dv_GetSelectAllRegion());		//Select all regions
 	RTDNVRamSaveOsdDisplayModeData(GET_OSD_DISPLAY_MODE());	//Save select all region to System EEPROM
 	SET_OSD_COLOR_EFFECT(GET_OSD_SELECT_REGION(), ucEffect);
 	UserAdjustColorEffectMode(GET_OSD_SYSTEM_SELECT_REGION());
 	UserAdjustOsdSelectRegionColorProc();			//Apply setting to all regions
 	SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_REGIONDATA_MSG);
       }
   }

   //Check if we need to dump color effect status to UART
   if(ucCmd == 0xff){
       switch(GET_OSD_COLOR_EFFECT(GET_OSD_SELECT_REGION())){
     	case _COLOREFFECT_STANDARD:
     	  ucEffect = '0';
     	  break;
     	case _COLOREFFECT_GAME:
     	  ucEffect = '1';
     	  break;
     	case _COLOREFFECT_MOVIE:
     	  ucEffect = '2';
     	  break;
     	case _COLOREFFECT_PHOTO:
     	  ucEffect = '3';
     	  break;
     	case _COLOREFFECT_VIVID:
     	  ucEffect = '4';
     	  break;
     	case _COLOREFFECT_USER:
     	  ucEffect = '5';
     	  break;
     	default:
     	  ucEffect = '?';
     	  break;
        }
        dv_TxByteToUART(ucEffect);
   }

}
#endif 		//Ray URT 2017.02.13: #endif

//*********************************************************
// Routine: dv_Serial_TestCmd_Para1
// Usage: Process RS232 0xF2 internal SVX-4096 hardware test command parameter byte 0
// Input: ucCmdPara: pointer to memory saving command parameter byte
//**********************************************************
void dv_Serial_TestCmd_Para1(BYTE *ucCmdPara)
{
  BYTE ucCmd[2];
  BYTE bValue1,bValue2;


  ucCmd[0]= *ucCmdPara;
  ucCmdPara++;
  ucCmd[1]= *ucCmdPara;

  //Ray SSE 2017.02.13: Write a byte to System EEPROM address 0x7f
  if(ucCmd[0] == 'A'){
      msAPI_rmWriteByte( 0x7f, ucCmd[1] );
      printf( "\r\n Ray: Write System EEPROM data : 0x%x", ucCmd[1] );
  }

  //Ray SSE 2017.02.13: Read a byte from System EEPROM address 0x7f
  if(ucCmd[0] == 'B'){
      printf( "\r\n Ray: Read System EEPROM data : 0x%x", msAPI_rmReadByte(0x7f));
  }

  //Ray EDD 2017.02.27: 0xF2 0x43 On/off EDID write protect
  if(ucCmd[0] == 'C'){
      if(ucCmd[1]=='0'){
	  EDID_EEPROM_WP_OFF();		//Turn off EDID write protect
      }
      if(ucCmd[1]=='1'){
	  EDID_EEPROM_WP_ON();		//Turn on EDID write protect
      }

  }

  //Ray EXA 2017.02.27: 0xF2 0x45 to change ext audio board volume level
  if(ucCmd[0] == 'E'){
      if(ucCmd[1]=='+'){
	if(g_nVolLevel<32)	//max vol level is 32
	  g_nVolLevel++;
	dv_SetExtAudioVolumeValue(g_nVolLevel);
      }
      else if(ucCmd[1]=='-'){
	if(g_nVolLevel>0)
	  g_nVolLevel--;
	dv_SetExtAudioVolumeValue(g_nVolLevel);
      }
      else if(ucCmd[1]=='0'){
	  dv_SerialTransmitHex(EXT_VOL_CAB());			//Send read value of VOL_CAB to UART
      }
  }


  //Ray LEP 2017.02.27: 0xF2 0x46 to change LED1A red and green state
  if(ucCmd[0] == 'F'){
      if(ucCmd[1]=='0')
	LED_RED_OFF();		//red LED1A off
      else if(ucCmd[1]=='1')
	LED_RED_ON();		//red LED1A on
      else if(ucCmd[1]=='2')
	LED_GREEN_OFF(); 	//green LED1A off
      else if(ucCmd[1]=='3')
	LED_GREEN_ON();		//green LED1A on

  }


  //Ray IE2 2017.02.23: Test panel I2C pins 0xF2 0x47. We use control IE-2000 H-flip V-flip as test
  if(ucCmd[0] == 'G'){
      dv_NT72324Init();				//Init IE-2000 first

      if(ucCmd[1]=='0'){
	dv_NT72324VFlip(DISABLE);		//Disable V Flip
	dv_NT72324HFlip(DISABLE);		//Disable H Flip
      }
      else if(ucCmd[1]=='1'){
	dv_NT72324VFlip(ENABLE);		//Enable V Flip
	dv_NT72324HFlip(DISABLE);		//Disable H Flip
      }
      else if(ucCmd[1]=='2'){
	dv_NT72324VFlip(DISABLE);		//Disable V Flip
	dv_NT72324HFlip(ENABLE);		//Enable H Flip

      }
      else if(ucCmd[1]=='3'){
	dv_NT72324VFlip(ENABLE);		//Enable V Flip
	dv_NT72324HFlip(ENABLE);		//Enable H Flip
      }
  }

 #ifdef sSP4096Board
  //Ray IOE 2017.02.27: 0xF2 0x48 to read and set I/O expander
  if(ucCmd[0] == 'H'){				//0x48: Read JC1 and JC2 pins, SHORT means 0, OPEN means 1
        bValue1 = 0xff;
      if(ucCmd[1]=='1')
	bValue1 = MDrv_ExGPIO_Get(JC3_1_2);	//Read JC3 pin 2
      else if(ucCmd[1]=='2')
	bValue1 = MDrv_ExGPIO_Get(JC3_3_4);	//Read JC3 pin 4
      else if(ucCmd[1]=='3')
	bValue1 = MDrv_ExGPIO_Get(JC3_5_6);	//Read JC3 pin 6
      else if(ucCmd[1]=='4')
	bValue1 = MDrv_ExGPIO_Get(JC3_7_8);	//Read JC3 pin 8
      else if(ucCmd[1]=='5')
	bValue1 = MDrv_ExGPIO_Get(JC3_9_10);	//Read JC3 pin 10
      else if(ucCmd[1]=='6')
	bValue1 = MDrv_ExGPIO_Get(JC3_11_12);	//Read JC3 pin 12
      else if(ucCmd[1]=='7')
	bValue1 = MDrv_ExGPIO_Get(ExGPIO_VOL_CAB);	//Read VOL_CAB
      else if(ucCmd[1]=='8')
	bValue1 = MDrv_ExGPIO_Get(ExGPIO_BL_STATUS);	//Read BL_STATUS
      else if(ucCmd[1]=='A')
	bValue1 = MDrv_ExGPIO_Get(SW3_1);	//Read DIP switch SW3 position 1
      else if(ucCmd[1]=='B')
	bValue1 = MDrv_ExGPIO_Get(SW3_2);	//Read DIP switch SW3 position 2
      else if(ucCmd[1]=='C')
	bValue1 = MDrv_ExGPIO_Get(SW3_3);	//Read DIP switch SW3 position 3
      else if(ucCmd[1]=='D')
	bValue1 = MDrv_ExGPIO_Get(SW3_4);	//Read DIP switch SW3 position 4
      else if(ucCmd[1]=='E')
	bValue1 = MDrv_ExGPIO_Get(SW3_5);	//Read DIP switch SW3 position 5
      else if(ucCmd[1]=='F')
	bValue1 = MDrv_ExGPIO_Get(SW3_6);	//Read DIP switch SW3 position 6
      else if(ucCmd[1]=='G')
	bValue1 = MDrv_ExGPIO_Get(SW3_7);	//Read DIP switch SW3 position 7
      else if(ucCmd[1]=='H')
	bValue1 = MDrv_ExGPIO_Get(SW3_8);	//Read DIP switch SW3 position 8
      else if(ucCmd[1]=='I')
	MDrv_ExGPIO_Set(ExGPIO_VOL_CAB,0);		//Write VOL_CAB to 0
      else if(ucCmd[1]=='J')
	MDrv_ExGPIO_Set(ExGPIO_VOL_CAB,1);		//Write VOL_CAB to 1
      else if(ucCmd[1]=='K')
	MDrv_ExGPIO_Set(ExGPIO_BL_STATUS,0);		//Write BL_STATUS to 0
      else if(ucCmd[1]=='L')
	MDrv_ExGPIO_Set(ExGPIO_BL_STATUS,1);		//Write BL_STATUS to 1

      dv_SerialTransmitHex(bValue1);			//Send read value to UART
  }
#endif

  //Ray PNL 2017.02.23: Read back panel backlight status pin level in CNB2
  if(ucCmd[0] == 'J'){				//Read BL_STATUS pin logic
      if(ucCmd[1]=='R'){
	  bValue1 = PANEL_BL_STATUS();
	  dv_SerialTransmitHex(bValue1);	//Send read value to UART

      }
  }

  //Ray EDD 2017.02.24: Write Preset EDID into DDC EEPROM
  if(ucCmd[0] == 'L'){				//0x4C, Write preset EDID into DDC EEPROM
      BYTE ucRead;
      if(ucCmd[1]=='0'){			//Write EDID into HDMI1, HDMI2, HDMI3 and DVI EEPROM
	  bValue1 = dv_LoadEDID();		//Ray 2016.12.13: Load either user EDID or preset EDID
	  dv_SerialTransmitHex(bValue1);	//Send result of write EDID 0x30(fail) or 0x31 (success) to UART
      }
      if(ucCmd[1]=='1'){			//Write HDMI D1 DDC EEPROM
	  bValue1 = dv_writeEDIDEEPROM(HDMI1);
	  dv_SerialTransmitHex(bValue1);	//Send result of write EDID 0x30(fail) or 0x31 (success) to UART
	  //Ray EDD 2017.02.27: Read back the checksum to see if it's correct
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, HDMI1);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, HDMI1);
	  dv_SerialTransmitHex(ucRead);
      }

      if(ucCmd[1]=='2'){			//Write HDMI D2 DDC EEPROM
	  bValue1 = dv_writeEDIDEEPROM(HDMI2);
	  dv_SerialTransmitHex(bValue1);	//Send result of write EDID 0x30(fail) or 0x31 (success) to UART
	  //Ray EDD 2017.02.27: Read back the checksum to see if it's correct
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, HDMI2);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, HDMI2);
	  dv_SerialTransmitHex(ucRead);
      }

      if(ucCmd[1]=='3'){			//Write HDMI D3 DDC EEPROM
	  bValue1 = dv_writeEDIDEEPROM(HDMI3);
	  dv_SerialTransmitHex(bValue1);	//Send result of write EDID 0x30(fail) or 0x31 (success) to UART
	  //Ray EDD 2017.02.27: Read back the checksum to see if it's correct
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, HDMI3);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, HDMI3);
	  dv_SerialTransmitHex(ucRead);
      }


      if(ucCmd[1]=='4'){			//Write DVI D4 DDC EEPROM
	  bValue1 = dv_writeEDIDEEPROM(DVI);
	  dv_SerialTransmitHex(bValue1);	//Send result of write EDID 0x30(fail) or 0x31 (success) to UART
	  //Ray EDD 2017.02.27: Read back the checksum to see if it's correct
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, DVI);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, DVI);
	  dv_SerialTransmitHex(ucRead);
      }

      if(ucCmd[1]=='5'){			//Ray EDD 2017.02.27: Read HDMI1 EDID checksum
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, HDMI1);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, HDMI1);
	  dv_SerialTransmitHex(ucRead);
      }

      if(ucCmd[1]=='6'){			//Ray EDD 2017.02.27: Read HDMI2 EDID checksum
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, HDMI2);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, HDMI2);
	  dv_SerialTransmitHex(ucRead);
      }

      if(ucCmd[1]=='7'){			//Ray EDD 2017.02.27: Read HDMI3 EDID checksum
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, HDMI3);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, HDMI3);
	  dv_SerialTransmitHex(ucRead);
      }

      if(ucCmd[1]=='8'){			//Ray EDD 2017.02.27: Read DVI EDID checksum
	  dv_EDIDEepromRead(0x7f, 1, &ucRead, DVI);
	  dv_SerialTransmitHex(ucRead);
	  dv_EDIDEepromRead(0xff, 1, &ucRead, DVI);
	  dv_SerialTransmitHex(ucRead);
      }

  }

#if 0  					//Ray URT 2017.02.13 #if 0
  /*
  if(ucCmd[0] == 'C'){		//Testing in SM2796A board, test pin control of Local dimming
      if(ucCmd[1]=='0')
	PCB_PANEL_LOCAL_DIMMING_EN(_PANEL_LOCAL_DIMMING_DISABLE)
      else if(ucCmd[1]=='1')
	PCB_PANEL_LOCAL_DIMMING_EN(_PANEL_LOCAL_DIMMING_ENABLE)
      else if(ucCmd[1]=='2'){	//Read back local dimming pin logic value
	  value1 = (int)PCB_PANEL_LOCAL_DIMMING();
	  dv_SerialTransmitHex((BYTE)value1);
      }
  }
  */



  if(ucCmd[0] == 'D'){		//Change Vx1 PANEL_IO[4:1] state
      if(ucCmd[1]=='0')
	PCB_PANEL_IO1(0)
      else if(ucCmd[1]=='1')
	PCB_PANEL_IO1(1)
      else if(ucCmd[1]=='2')
	PCB_PANEL_IO2(0)
      else if(ucCmd[1]=='3')
	PCB_PANEL_IO2(1)
      else if(ucCmd[1]=='4')
	PCB_PANEL_IO3(0)
      else if(ucCmd[1]=='5')
	PCB_PANEL_IO3(1)
      else if(ucCmd[1]=='6')
	PCB_PANEL_IO4(0)
      else if(ucCmd[1]=='7')
	PCB_PANEL_IO4(1)
  }







  if(ucCmd[0] == 'H'){				//0x48: Read JC1 and JC2 pins, SHORT means 0, OPEN means 1
        bValue1 = 0xff;
      if(ucCmd[1]=='1')
	bValue1 = dv_ReadJCHeader(JC1_02);	//Read JC1 pin 2
      else if(ucCmd[1]=='2')
	bValue1 = dv_ReadJCHeader(JC1_04);	//Read JC1 pin 4
      else if(ucCmd[1]=='3')
	bValue1 = dv_ReadJCHeader(JC1_06);	//Read JC1 pin 6
      else if(ucCmd[1]=='4')
	bValue1 = dv_ReadJCHeader(JC1_08);	//Read JC1 pin 8
      else if(ucCmd[1]=='5')
	bValue1 = dv_ReadJCHeader(JC1_10);	//Read JC1 pin 10
      else if(ucCmd[1]=='6')
	bValue1 = dv_ReadJCHeader(JC1_12);	//Read JC1 pin 12
      else if(ucCmd[1]=='7')
	bValue1 = dv_ReadJCHeader(JC1_14);	//Read JC1 pin 14
      else if(ucCmd[1]=='8')
	bValue1 = dv_ReadJCHeader(JC1_16);	//Read JC1 pin 16
      else if(ucCmd[1]=='A')
	bValue1 = dv_ReadJCHeader(JC2_02);	//Read JC2 pin 2
      else if(ucCmd[1]=='B')
	bValue1 = dv_ReadJCHeader(JC2_04);	//Read JC2 pin 4
      else if(ucCmd[1]=='C')
	bValue1 = dv_ReadJCHeader(JC2_06);	//Read JC2 pin 6
      else if(ucCmd[1]=='D')
	bValue1 = dv_ReadJCHeader(JC2_08);	//Read JC2 pin 8
      else if(ucCmd[1]=='E')
	bValue1 = dv_ReadJCHeader(JC2_10);	//Read JC2 pin 10
      else if(ucCmd[1]=='F')
	bValue1 = dv_ReadJCHeader(JC2_12);	//Read JC2 pin 12
      else if(ucCmd[1]=='G')
	bValue1 = dv_ReadJCHeader(JC2_14);	//Read JC2 pin 14
      else if(ucCmd[1]=='H')
	bValue1 = dv_ReadJCHeader(JC2_16);	//Read JC2 pin 16
      else if(ucCmd[1]=='I')
	dv_WriteJCHeader(JC2_02,0);		//Write JC2 pin 2 to 0
      else if(ucCmd[1]=='J')
	dv_WriteJCHeader(JC2_02,1);		//Write JC2 pin 2 to 1
      else if(ucCmd[1]=='K')
	dv_EnIP60_Mac_Prog(0);			//Write U13 pin 4 to 0
      else if(ucCmd[1]=='L')
	dv_EnIP60_Mac_Prog(1);			//Write U13 pin 4 to 1

      dv_SerialTransmitHex(bValue1);			//Send read value to UART
  }


  if(ucCmd[0] == 'I'){				//Read SW3 and SW4 Dip Switches: ON means 0, OFF means 1
        bValue1 = 0xff;
      if(ucCmd[1]=='1')
	bValue1 = dv_ReadDipSwitch(SW3_1);	//Read SW3 switch 1
      else if(ucCmd[1]=='2')
	bValue1 = dv_ReadDipSwitch(SW3_2);	//Read SW3 switch 2
      else if(ucCmd[1]=='3')
	bValue1 = dv_ReadDipSwitch(SW3_3);	//Read SW3 switch 3
      else if(ucCmd[1]=='4')
	bValue1 = dv_ReadDipSwitch(SW3_4);	//Read SW3 switch 4
      else if(ucCmd[1]=='5')
	bValue1 = dv_ReadDipSwitch(SW3_5);	//Read SW3 switch 5
      else if(ucCmd[1]=='6')
	bValue1 = dv_ReadDipSwitch(SW3_6);	//Read SW3 switch 6
      else if(ucCmd[1]=='7')
	bValue1 = dv_ReadDipSwitch(SW3_7);	//Read SW3 switch 7
      else if(ucCmd[1]=='8')
	bValue1 = dv_ReadDipSwitch(SW3_8);	//Read SW3 switch 8
      else if(ucCmd[1]=='A')
	bValue1 = dv_ReadDipSwitch(SW4_1);	//Read SW4 switch 1
      else if(ucCmd[1]=='B')
	bValue1 = dv_ReadDipSwitch(SW4_2);	//Read SW4 switch 2
      else if(ucCmd[1]=='C')
	bValue1 = dv_ReadDipSwitch(SW4_3);	//Read SW4 switch 3
      else if(ucCmd[1]=='D')
	bValue1 = dv_ReadDipSwitch(SW4_4);	//Read SW4 switch 4
      else if(ucCmd[1]=='E')
	bValue1 = dv_ReadDipSwitch(SW4_5);	//Read SW4 switch 5
      else if(ucCmd[1]=='F')
	bValue1 = dv_ReadDipSwitch(SW4_6);	//Read SW4 switch 6

      dv_SerialTransmitHex(bValue1);			//Send read value to UART
  }



  if(ucCmd[0] == 'K'){				//0x4B, SET SYSTEM EEPROM WP state
      if(ucCmd[1]=='0'){
	  PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE)

      }
      if(ucCmd[1]=='1'){
	  PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE)

      }
      bValue1=PCB_EEPROM_WRITE_PROTECT_DETECT();	//Read SYSTEM EEPROM WP state
      dv_SerialTransmitHex(bValue1);		//Send read value to UART

  }



  if(ucCmd[0] == 'M'){			//0x4D, init UART2
      dv_UART2Init();
  }

  if(ucCmd[0] == 'N'){			//0x4E, transmit a byte from UART2
      dv_UART2TxByte(ucCmd[1]);
  }

  if(ucCmd[0] == 'O'){			//0x4F, receive bytes from UART2
      bValue1=dv_UART2RxByte(g_ucUart2Data);
      dv_TxByteToUART(bValue1);			//Dump no. of byte received
      for(bValue2=0;bValue2<bValue1;bValue2++)
	dv_TxByteToUART(g_ucUart2Data[bValue2]);	//Dump received data
  }

#endif
  if(ucCmd[0] == 'P'){			//0x50 0xYY, dump system EEPROM address as debug message
      //Ray SSE 2017.02.13: system parameter memory usage dump
      printf("Ray:RM_BOOTLOADER_ADDR: %x\n",RM_BOOTLOADER_ADDR);
      printf("Ray:RM_BOOTLOADER_END_ADDR: %x\n",RM_BOOTLOADER_END_ADDR);
      printf("Ray:RM_HDCP_KEY_ADDR: %x\n",RM_HDCP_KEY_ADDR);
      printf("Ray:RM_HDCP_KEY_END_ADDR: %x\n",RM_HDCP_KEY_END_ADDR);
      printf("Ray:RM_FACTORY_START_ADDR: %x\n",RM_FACTORY_START_ADDR);
      printf("Ray:RM_FACTORY_END_ADDR: %x\n",RM_FACTORY_END_ADDR);
      printf("Ray:RM_GENSET_START_ADR: %x\n",RM_GENSET_START_ADR);
      printf("Ray:RM_GENSET_END_ADR: %x\n",RM_GENSET_END_ADR);
      printf("Ray://///Below are MS_GENSETTING data:\n");
      printf("Ray:RM_SYS_SETTING_ADDRESS: %x\n",RM_SYS_SETTING_ADDRESS);
      printf("Ray:RM_SOUND_SETTING_ADDRESS: %x\n",RM_SOUND_SETTING_ADDRESS);
      printf("Ray:RM_VIDEO_DATA_ADDRESS(0): %x\n",( RM_GENSET_START_ADR + (U32)&(((MS_GENSETTING*)0)->g_astVideo[0]) ));
      printf("Ray:RM_VIDEO_DATA_ADDRESS(DATA_INPUT_SOURCE_NUM): %x\n",( RM_GENSET_START_ADR + (U32)&(((MS_GENSETTING*)0)->g_astVideo[DATA_INPUT_SOURCE_NUM]) ));
      printf("Ray:RM_TIME_DATA_ADDRESS: %x\n",RM_TIME_DATA_ADDRESS);
      printf("Ray:RM_SCANMENU_SETTING_ADDRESS: %x\n",RM_SCANMENU_SETTING_ADDRESS);
      printf("Ray:RM_BLOCK_DATA_ADDRESS: %x\n",RM_BLOCK_DATA_ADDRESS);
      printf("Ray:RM_NONLINER_SETTING_ADDRESS: %x\n",RM_NONLINER_SETTING_ADDRESS);
      printf("Ray:RM_DRM_DATA_ADDRESS: %x\n",RM_DRM_DATA_ADDRESS);
      printf("Ray:RM_GEN_VERSION_1_ADDRESS: %x\n",RM_GEN_VERSION_1_ADDRESS);
      printf("Ray:RM_GEN_VERSION_2_ADDRESS: %x\n",RM_GEN_VERSION_2_ADDRESS);
      printf("Ray:RM_GEN_BACKLIGHT_ADDRESS: %x\n",RM_GEN_BACKLIGHT_ADDRESS);
      }

#if 0						//Ray URT 2017.02.13
  if(ucCmd[0] == 'Q'){			//0x51: Test video wall function.
      //Input: 0x30= normal, 0x31 = upper left, 0x32 = upper right, 0x33 = lower left, 0x34 = lower right
      //       0x35= left 1/3, 0x36 = middle 1/3, 0x37 = right 1/3
      //       Other values, except 0, set the video wall height & width = ucCmd[1]

      g_ucVideoWallMode = ucCmd[1];
      SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);	//Make image zoom setting in effect

  }


  //Ray 2016.04.19: 0xF2 0x52 0x30 to read the color ADC gain and offset to see the result of auto color gain set for VGA port
    if(ucCmd[0] == 'R'){
        if(ucCmd[1] == '0'){
            ScalerAutoGetAutoColorResult(&g_stAdcData);	  //Read ADC value
            //dv_TxByteToUART(g_stAdcData.ucAdcPGA);		//No value in this register
            dv_TxByteToUART(g_stAdcData.pucAdcGainMSB[2]);
            dv_TxByteToUART(g_stAdcData.pucAdcGainMSB[1]);
            dv_TxByteToUART(g_stAdcData.pucAdcGainMSB[0]);
            //dv_TxByteToUART(g_stAdcData.pucAdcGainLSB[2]);	//No value in this register
            //dv_TxByteToUART(g_stAdcData.pucAdcGainLSB[1]);
            //dv_TxByteToUART(g_stAdcData.pucAdcGainLSB[0]);
            dv_TxByteToUART(g_stAdcData.pucAdcOffsetMSB[2]);
            dv_TxByteToUART(g_stAdcData.pucAdcOffsetMSB[1]);
            dv_TxByteToUART(g_stAdcData.pucAdcOffsetMSB[0]);
            //dv_TxByteToUART(g_stAdcData.pucAdcOffsetLSB[2]);	//No value in this register
            //dv_TxByteToUART(g_stAdcData.pucAdcOffsetLSB[1]);
            //dv_TxByteToUART(g_stAdcData.pucAdcOffsetLSB[0]);

        }

    }

#if(_HD3000S_SUPPORT==_ON)
    //Ray 2016.04.19: 0xF2 0x53 0xYZ to read AVD-1000 board version no., where 0xYZ +0x80 is AVD-1000 command byte
      if(ucCmd[0] == 'S'){
              DebugMessageSystem("AVD-1000 version:", dvReadAVD1000(ucCmd[1]+0x80)); //Read AVD-1000 board version no.

      }

      //Ray 2016.04.19: 0xF2 0x54 0xYZ to read AVD-1000 board version no., where 0xYZ is HD-3000 command byte
        if(ucCmd[0] == 'T'){
                DebugMessageSystem("HD-3000 read value:", dvReadHDSDI(ucCmd[1]));

        }
#endif

     //Ray 2016.01.23: Test command to erase SYSTEM EEPROM to 0xFF. This is to emulate the case of "empty" board in manufacturing
        if(ucCmd[0] == 'U'){
            BYTE tempArray[128];
            BYTE result;
            DWORD i;
            result=_SUCCESS;
	    for(i=0;i<128;i++){
		tempArray[i]=0xFF;
	    }
            if(ucCmd[1] == '0'){
        	//Erase whole 512K-bit System EEPROM to 0xFF
        	for(i=0;i<0xffff;i+=0x80){
        	    result &= UserCommonEepromWrite(i, sizeof(tempArray), (BYTE *)(tempArray));
        	}
        	dv_TxByteToUART(result+0x30);		//Dump the erase system EEPROM result: 0x30 = fail, 0x31 = success
            }
            if(ucCmd[1] == '1'){
        	//Erase D1 to D4 EDID EEPROM to 0xFF
        	for(i=_OSD_INPUT_D1;i<=_OSD_INPUT_D4;i++){
        	    result &= dv_write128ByteEDIDEEPROM(i,tempArray,0);		//Write 0x00~0x7F
        	    result &= dv_write128ByteEDIDEEPROM(i,tempArray,0x80);	//Write 0x80~0xFF
        	}
        	dv_TxByteToUART(result+0x30);		//Dump the erase system EEPROM result: 0x30 = fail, 0x31 = success
            }

        }


#endif			//Ray URT 2017.02.13:
}


#if 0			//Ray URT 2017.02.13: #if 0
//*********************************************************
// Routine: dv_writeEDID
// Usage: Write EDID table to EEPROM
// Input: port: 1~4 => D1~D4
// Output: 1 = SUCCESS, 0 = FAIL
//**********************************************************
/*
BYTE dv_writeEDID(BYTE port)
{
  BYTE result = 0;

  switch(port){
    case 1:
       ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);	//Switch DDC1 SDA & SCL to GPIO port
	//Write EDID table from array to EEPROM
	result = (BYTE)UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0, 1, 256, tEDID_TBL_D1, _IIC_DDC1_EEPROM, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);  //Sub-address is 0 as slave address is 0xA0, sub-address length = 1
	ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);	//Switch back DDC1 SDA & SCL as DDC function after writing EEPROM
	break;
    case 2:
       ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);	//Switch DDC2 SDA & SCL to GPIO port
	//Write EDID table from array to EEPROM
       result = (BYTE)UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0, 1, 256, tEDID_TABLE_D2, _IIC_DDC2_EEPROM, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);  //Sub-address is 0 as slave address is 0xA0, sub-address length = 1
	ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);	//Switch back DDC2 SDA & SCL as DDC function after writing EEPROM
	break;
    case 3:
       ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);	//Switch DDC3 SDA & SCL to GPIO port
	//Write EDID table from array to EEPROM
       result = (BYTE)UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0, 1, 256, tEDID_TABLE_D3, _IIC_DDC3_EEPROM, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);  //Sub-address is 0 as slave address is 0xA0, sub-address length = 1
	ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);	//Switch back DDC3 SDA & SCL as DDC function after writing EEPROM
	break;
    case 4:
	ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_GPIO);	//Switch DDC4 SDA & SCL to GPIO port
	//Write EDID table from array to EEPROM
	result = (BYTE)UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0, 1, 256, tEDID_TABLE_D4, _IIC_DDC4_EEPROM, _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);  //Sub-address is 0 as slave address is 0xA0, sub-address length = 1
	ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_DDC);	//Switch back DDC4 SDA & SCL as DDC function after writing EEPROM
	break;
    default:
        break;
  }
  return(result);
}

*/


//*********************************************************
// Routine: dv_TransmitAcknowledgeByte
// Usage: Send 1 acknowledge byte to UART.
// Input: Port: UART_1 or UART_2
// 	  ucTxData: 1 byte data to be transmitted to UART
//**********************************************************
/*
void dv_TransmitAcknowledgeByte(RS232_UART_CHANNEL Port,BYTE ucTxData)
{
  if(Port == UART_1){
      dv_TxToUART1(&ucTxData, 1);
  }
}
*/

//*********************************************************
// Routine: dv_TxToUART1
// Usage: Transmit data from buffer to UART1
// Input: *ucbuf: pointer of BYTE buffer array to store transmit data
//        ucTxLen: length of data to be transmitted
//**********************************************************
/*
void dv_TxToUART1(BYTE *ucBuf, BYTE ucTxLen)
{
  BYTE i;
  for(i=0;i<ucTxLen;i++){
    ScalerMcuUartWrite(ucBuf[i]);
  }
}
*/



#endif 		//Ray 2017.02.21

//Ray SRC 2017.05.08
//*********************************************************
// Routine: dv_DataInputSourceValue
// Usage: Get the RS232 command value of data input video source
// Input: ucSource: input video source: DATA_INPUT_SOURCE_RGB (1) to DATA_INPUT_SOURCE_HDMI4 (5) (Pls note DATA_INPUT_SOURCE_HDMI3 is DVI)
// Output: RS232 command source value: 0x4x 0x3x
//**********************************************************
WORD dv_DataInputSourceValue(E_DATA_INPUT_SOURCE ucSource)
{

  switch(ucSource){
    case DATA_INPUT_SOURCE_RGB:
      return 0x3141;
      break;
    case DATA_INPUT_SOURCE_HDMI:
      return 0x3148;
      break;
    case DATA_INPUT_SOURCE_HDMI2:
      return 0x3248;
      break;
    case DATA_INPUT_SOURCE_HDMI3:
      return 0x3146;
      break;
    case DATA_INPUT_SOURCE_HDMI4:
      return 0x3348;
      break;
    case DATA_INPUT_SOURCE_STORAGE:
      return 0x3159;
      break;
    default:
      return '?';
      break;
  }

}

//Ray SRC 2017.05.09
//*********************************************************
// Routine: dv_UiInputSourceValue
// Usage: Get the RS232 command value of input video source according to firmware UI input source value
// Input: ucSource: input video source: UI_INPUT_SOURCE_HDMI (1) to UI_INPUT_SOURCE_RGB
// Output: RS232 command source value: 0x4x 0x3x
//**********************************************************
WORD dv_UiInputSourceValue(E_UI_INPUT_SOURCE ucSource)
{

  switch(ucSource){
    case UI_INPUT_SOURCE_RGB:
      return 0x3141;
      break;
    case UI_INPUT_SOURCE_HDMI:
      return 0x3148;
      break;
    case UI_INPUT_SOURCE_HDMI2:
      return 0x3248;
      break;
    case UI_INPUT_SOURCE_HDMI3:
      return 0x3146;
      break;
    case UI_INPUT_SOURCE_HDMI4:
      return 0x3348;
      break;
    default:
      return 0;
      break;
  }

}

//*********************************************************
// Routine: dv_HexDigitToAscii
// Usage: Convert hex digit(0x00 to 0x0f) to ASCII value
// Input: Data: digit (0x00 to 0x0f) to be converted
// Output: Converted ASCII value (0x30 to 0x46)
//**********************************************************
BYTE dv_HexDigitToAscii(BYTE Data)
{
    if (Data > 0x9)
    {
        Data += 7;
    }
    Data = Data + '0';
    return Data;
}

//*********************************************************
// Routine: dv_AsciiToHexDigit
// Usage: Convert ASCII value (0x30 to 0x46) to hex digit(0x00 to 0x0f)
// Input: ASCII value (0x30 ~ 0x39, 0x41 to 0x46, 0x61~0x66)to be converted
// Output: digit (0x00 to 0x0f)
//**********************************************************
BYTE dv_AsciiToHexDigit(BYTE Data)
{
    if (Data >= 'A'&& Data<='F')
    {
        Data -= 7;
    }
    else if(Data >= 'a'&& Data<='f')
    {
        Data -= 0x27;
    }

    Data = Data - '0';

    return Data;
}



//*********************************************************
// Routine: dv_SerialTransmitHex
// Usage: Convert hex digit(0x00 to 0xff) to ASCII value and then send to UART1
// Input: Data: digit (0x00 to 0xff) to be sent
//**********************************************************
void dv_SerialTransmitHex(BYTE Data)
{
    BYTE    Temp;
    Temp =  dv_HexDigitToAscii((Data & 0xf0) >> 4);
    dv_TxByteToUART(Temp);
    Temp =  dv_HexDigitToAscii(Data & 0x0f);
    dv_TxByteToUART(Temp);
}

//*********************************************************
// Routine: dv_GetAsciiValue
// Usage: Convert two byte ASCII value to digit value
//        For example: "0x31 0x43" is converted to 0x1C
// Input: pointer contains two byte ASCII
// Output: digital value of two byte ASCII
//**********************************************************
BYTE dv_GetAsciiValue(BYTE *para)
{
  BYTE value;

  value = dv_AsciiToHexDigit(*para)*0x10;
  para++;
  value +=dv_AsciiToHexDigit(*para);

  return value;

}

//Ray 2016.12.15
//*********************************************************
// Routine: dv_GetAsciiBCDValue
// Usage: Convert two byte ASCII BCD value to digit value
//        For example: "0x31 0x33" is converted to 13 decimal value
// Input: pointer contains two byte ASCII
// Output: digital value of two byte ASCII
//**********************************************************
BYTE dv_GetAsciiBCDValue(BYTE *para)
{
  BYTE value;

  value = dv_AsciiToHexDigit(*para)*10;
  para++;
  value +=dv_AsciiToHexDigit(*para);

  return value;

}


//Ray SRC 2017.06.16
//*********************************************************
// Routine: dv_Serial_QuerySource
// Usage: To process 0xC9 command by checking the input sources and reply to PC
//**********************************************************
void dv_Serial_QuerySource(void)
{
    //Check if input source has valid stable sync
    if(MApi_XC_PCMonitor(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), MAIN_WINDOW)==E_XC_PCMONITOR_STABLE_SYNC){
	dv_Serial_QuerySourceTx(g_enDataInputSourceType[MAIN_WINDOW]);
    }else{
	    dv_TxByteToUART('0');	//No valid video source in input
	    dv_TxByteToUART('0');
    }
}

//Ray SRC 2017.06.16
//*********************************************************
// Routine: dv_Serial_QuerySourceTx
// Usage: To transmit video source Two Byte values to PC for the command 0xC9
// Input: E_DATA_INPUT_SOURCE ucSource
//**********************************************************
void dv_Serial_QuerySourceTx(E_DATA_INPUT_SOURCE ucSource)
{
  switch(ucSource)
  {
    case DATA_INPUT_SOURCE_RGB:		//ARGB source
	dv_TxByteToUART('A');
	dv_TxByteToUART('1');
	break;
    case DATA_INPUT_SOURCE_HDMI:	//HDMI 1 source
	dv_TxByteToUART('H');
	dv_TxByteToUART('1');
	break;
    case DATA_INPUT_SOURCE_HDMI2:	//HDMI 2 source
	dv_TxByteToUART('H');
	dv_TxByteToUART('2');
	break;
    case DATA_INPUT_SOURCE_HDMI4:
	dv_TxByteToUART('H');		//HDMI 3 source
	dv_TxByteToUART('3');
	break;
    case DATA_INPUT_SOURCE_HDMI3:	//DVI source
	dv_TxByteToUART('F');
	dv_TxByteToUART('1');
	break;
    default:
	dv_TxByteToUART('0');		//Invalid source
	dv_TxByteToUART('0');
      break;
  }
}

