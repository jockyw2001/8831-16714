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
// MODULE:      dvrs232.h
//
// USAGE:       Header file of dvrs232.c which contains functions for RS232 communication with PC
//
//******************************************************************************
#ifndef __DVRS232_H__
#define __DVRS232_H__

//----------------------------------------------------------------------------
// DV serial command definition
//----------------------------------------------------------------------------
#define Serial_NoFunction		0x00
#define Serial_Volume           0x80
#define Serial_Brightness       0x81
#define Serial_Contrast         0x82
#define Serial_ColorSat         0x83
#define Serial_Hue             	0x84
#define Serial_Phase            0x85
#define Serial_HorzPosn         0x86
#define Serial_VertPosn         0x87

#define Serial_RgbSharpness     0x89
#define Serial_Sharpness        0x8a
#define Serial_VgaClock         0x8b
#define Serial_ScaleMode        0x8c

#define Serial_DispOrient       0x8e
#define Serial_OsdRotate        0x8f
#define Serial_OsdHPosn         0x90
#define Serial_OsdVPosn         0x91
#define Serial_OsdTransparency  0x92
#define Serial_Timeout          0x93

#define Serial_Language         0x95
#define Serial_InputFilter      0x96

#define Serial_Source           0x98
#define Serial_AutoSource       0x99
#define Serial_SourceLayout     0x9a
#define Serial_VidMode          0x9b
#define Serial_Type             0x9c
#define Serial_Gamma            0x9d
#define Serial_AutoPowerSave    0x9f
#define Serial_HotKeys          0xa0
#define Serial_Runtime          0xa1
#define Serial_PipBright        0xa2
#define Serial_PipContrast      0xa3
#define Serial_PipHPosn         0xa4
#define Serial_PipVPosn         0xa5
#define Serial_PipSize          0xa6
#define Serial_PipSource        0xa7
#define Serial_ZoomLevel        0xa8
#define Serial_ZoomHPosn        0xa9
#define Serial_ZoomVPosn        0xaa
#define Serial_HClip            0xab
#define Serial_HOffset          0xac
#define Serial_HStretch         0xad
#define Serial_VClip            0xae
#define Serial_VOffset          0xaf
#define Serial_VStretch         0xb0
#define Serial_HPanPosn         0xb1
#define Serial_VPanPosn         0xb2
#define Serial_ColorTemp        0xb3
#define Serial_TempRed          0xb4
#define Serial_TempGreen        0xb5
#define Serial_TempBlue         0xb6
#define Serial_HRes             0xb7
#define Serial_VRes             0xb8
#define Serial_HFreq            0xb9
#define Serial_VFreq            0xba
#define Serial_OsdStatus        0xbb
#define Serial_NewInputDisp  	0xbc
#define Serial_OsdOff           0xbd
#define Serial_VideoPort        0xbe
#define Serial_UserGammaData    0xbf
#define Serial_MatrixCommand    0xc0
#define Serial_AckSet           0xc1
#define Serial_Auto             0xc3
#define Serial_CommandQuery     0xc4
#define Serial_Calibrate        0xc5
#define Serial_Freeze           0xc6
#define Serial_Rotate           0xc7
#define Serial_Power            0xc8
#define Serial_QuerySource      0xc9
#define Serial_MEMC      	0xca
#define Serial_Info             0xcb
#define Serial_APL              0xcc
#define Serial_TestPattern      0xcd
#define Serial_LoadDefault      0xce
#define Serial_ALLLoadDefault   0xcf

#define Serial_PanelWallSize    0xd0
#define Serial_PanelPosition    0xd1
#define Serial_PanelHorzEdge    0xd2
#define Serial_PanelVertEdge    0xd3
#define Serial_ConfigPanel      0xd4
#define Serial_SelectPanel      0xd5
#define Serial_Broadcast        0xd6
#define Serial_SaveUserDefault  0xd7
#define Serial_LoadUserDefault  0xd8
#define Serial_WideScreenMode	0xd9

#define Serial_BackLightControl	0xe0
#define Serial_BackLightOnOff	0xe1
#define Serial_BlueOnly		0xe2
#define Serial_SwapMainAndPip	0xe3
#define Serial_ReadTemperature	0xe4	//Reserve: RS-232 command for their "Read sensor" 08Oct2007
#define Serial_BackLight_PWM_DA	0xe5
#define Serial_PWMFrequency	0xe6
#define Serial_BackLightInvert	0xe7
#define Serial_OffsetRed        0xe8
#define Serial_OffsetGreen      0xe9
#define Serial_OffsetBlue       0xea
#define Serial_FillDisplay      0xec
#define Serial_PIP_Blender	0xed
#define Serial_Command_Extend	0xee

  #define Serial_MinBackLightValue 	0x5C
  #define Serial_OSDSwitchMountLock 	0x62
  #define Serial_DefaultPower		0x6B50		//Ray 2016.10.14: 0x6B 0x50 to set default power on/off
  #define Serial_ColorEffectExt		0x7130		//0x71 0x30 color effect command
  #define Serial_Vx1PinState		0x73
  #define Serial_EEPanelTime		0x74
  #define Serial_UserEDID		0x76 		//Ray 2016.11.30: User EDID download through RS-232
  #define Serial_NT72324		0x78		//Ray 2016.08.22: NT72324 generic command

#define Serial_Display_Text     	0xf0
#define Serial_Display_Mark     	0xf1

#define Serial_TestCmd		0xf2	//Ray 2015.11.30: Internal command to test SVX-4096 hardware

#define Serial_Menu	        0xf7
#define Serial_CopyRight        0xf8
#define Serial_Down             0xfa
#define Serial_Up               0xfb
#define Serial_Plus             0xfc
#define Serial_Minus            0xfd
#define Serial_Reset            0xfe//<-- No function


//****************************************************************************
// GLOBAL DEFINITION
//****************************************************************************
enum UART_STATES			  //Ray 2015.11.02, g_ucDVUart1Status value definition
{
   RCV_EMPTY,                              // No data packet
   RCV_READY                               // Data packet received
};

typedef enum
{
	UART_1,
	UART_2,
} RS232_UART_CHANNEL;

typedef enum
{
    _WRITE_SIZE_8 = 8,
    _WRITE_SIZE_16 = 16,
    _WRITE_SIZE_32 = 32,
} EnumEepromWriteSize;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void putcharb(MS_U8 byte);		//Ray URT 2017.02.03
//extern void RTDKeyMessageProc(void);
//extern code void (*OperationTable[])(void);
//extern void ExeOperationalTable();
/*
extern BYTE UserCommonAdjustRealValueToPercent(WORD usRealValue, WORD usMax, WORD usMin, WORD usCenter);
extern WORD UserCommonAdjustPercentToRealValue(BYTE ucPercentValue, WORD usMax, WORD usMin, WORD usCenter);
extern void UserCommonAdjustSharpness(EnumSelRegion enumSelRegion, EnumSourceSearchPort enumSourceSearchPort);
#if(_PIP_DISPLAY_SUPPORT == _ON)
extern void UserCommonAdjustPipSubTimingFormat(void);
#endif
extern void dv_SetExtAudioVolumeValue(BYTE bVolume);
extern bit UserCommonEepromIICWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum, EnumEepromWriteSize enumWriteSize);
extern bit UserCommonEepromWrite(WORD usSubAddr, WORD usLength, BYTE *pucWriteArray);
extern bit UserCommonEepromRead(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
extern bit UserCommonEepromIICRead(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucReadArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum);
extern BYTE dv_CalEDIDChksum(BYTE iicDevice, int readAddr, BYTE *chksum);		//Ray 2016.12.07
extern bit dv_LoadEDID(void);			//Ray 2016.12.13
extern BYTE dv_writeEDIDEEPROM(BYTE port);
extern BYTE dv_write128ByteEDIDEEPROM(BYTE source, BYTE *EDID, BYTE startAddr);		//Ray 2016.12.07
extern bit dv_EDIDEepromRead(BYTE readAddr, WORD readLen, BYTE *readData, BYTE iicDevice);	//Ray 2016.12.08
extern void MenuHotKeySource(void);
extern void MenuSource_2P_ADJ(void);
extern void MenuSource_3P_ADJ(void);
extern void MenuSource_4P_ADJ(void);
extern void RTDEepromRestoreInputSource(BYTE ucPicture);		//Ray 2016.01.21: Add restore input source default value
extern void RTDRestorePIPSize(void);			//Ray 2016.01.22: Restore PIP window size
extern void RTDRestoreDisplayMode(void);		//Ray 2016.01.22: Restore display mode to 1P

extern void UserCommonAdjustPhase(BYTE ucPhase);		//Ray 2016.05.13
extern void UserCommonSetPhase(BYTE ucPhase);			//Ray 2016.05.13
extern BYTE UserCommonGetPhase(void);				//Ray 2016.05.13
extern void UserCommonAdjustHPosition(BYTE ucUserHPosition, EnumDisplayRegion enumDisplayRegion);	//Ray 2016.05.13
extern void UserCommonSetHPosition(BYTE ucHPos);		//Ray 2016.05.13
extern BYTE UserCommonGetHPosition(void);			//Ray 2016.05.13
extern void UserCommonAdjustVPosition(BYTE ucUserVPosition, EnumDisplayRegion enumDisplayRegion);	//Ray 2016.05.13
extern void UserCommonSetVPosition(BYTE ucVPos);		//Ray 2016.05.13
extern BYTE UserCommonGetVPosition(void);			//Ray 2016.05.13
extern void UserCommonAdjustClock(WORD usUserIHTotal);		//Ray 2016.05.17
extern void UserCommonSetVgaClock(BYTE ucClk);			//Ray 2016.05.17
extern BYTE UserCommonGetVgaClock(void);			//Ray 2016.05.17
extern void Menu_VgaAutoAdjust(void);				//Ray 2016.05.27: Do VGA auto adjust
extern BYTE Menu_VgaAutoColorGainSet(void);			//Ray 2016.05.27
extern void OsdAdjBlLevelPerMinVal(void);			//Ray 2016.05.27
extern WORD OsdDisplayDetOverRangeStep(WORD ucValue, WORD ucMax, WORD ucMin, WORD ucStep, bit bCycle);	//Ray 2016.05.27
//extern void dv_UART2TxByte(BYTE bData);			//Ray 2016.01.26: Write to UART2
*/
//****************************************************************************
// EXTERN VARIABLE
//****************************************************************************
/*
extern BYTE g_ucUart1Data[];		//UART1 receive buffer with length UART_RD_SIZE
extern BYTE g_ucInBuffWriteIndex;	//UART1 receive buffer write index
extern BYTE g_ucKeyStateCurr;
*/

#endif 	//End of #ifndef __DVRS232_H__
