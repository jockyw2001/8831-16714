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
//Ray EXA 2017.02.27
//
// MODULE:      dvExtAudio.c
//
// USAGE:       This module contains functions for controlling external audio board (P/N 416940020-3)
//
//******************************************************************************

//******************************************************************************
//  I N C L U D E    F I L E S
//******************************************************************************
#define DV_EXT_AUDIO_C
#include "Board.h"
#include "drvGPIO.h"
#include "dvExtAudio.h"


//******************************************************************************
//  F U N C T I O N    P R O T O T Y P E S
//******************************************************************************


//******************************************************************************
//  G L O B A L    V A R I A B L E S
//******************************************************************************



//******************************************************************************
//  C O D E
//******************************************************************************


//*********************************************************
// Routine: dv_SetExtAudioVolZero
// Usage: Set external audio board volume to zero
//**********************************************************
void dv_SetExtAudioVolZero(void)
{
      BYTE i;
      EXT_VOL_SEL_L();			//chip select left channel
      EXT_VOL_SEL_R();			//chip select right channel
      EXT_VOL_DN();			//Volume down
      //Generate 32 clock cycle to decrease volume to zero, as volume level is 32 (X9314 potentiometer has 32 tap, it is negative edge trigger)
      for(i=0;i<32;i++){
	  EXT_VOL_CLK_1();
	  MsOS_DelayTask (1);		//Delay 1ms
	  EXT_VOL_CLK_0();
	  MsOS_DelayTask (1);		//Delay 1ms
	  EXT_VOL_CLK_1();			//Ray 2016.03.03: Need to set to high first in order for X9314 storing the new potentiometer value
      }
      g_ucExtAudioVol = 0;	//Denote volume level = 0
      //Un-select Left and Right channel after finishing volume setting
      EXT_VOL_UNSEL_L();
      EXT_VOL_UNSEL_R();
      EXT_VOL_UP();

}


//*********************************************************
// Routine: dv_AudioVolumeInit
// Usage: Initialize external audio board volume to 32 (highest volume)
//**********************************************************
void dv_ExtAudioVolumeInit(void)
{
  dv_SetExtAudioVolZero();
  dv_SetExtAudioVolumeValue(30);		//Ray VOL 2016.05.22: Init volume level of the amp to 30 higher volume level for better testing
  //dv_SetExtAudioVolumeValue(16);	//Ray 2016.02.23: Init volume level of the amp to middle
  printf("\nVOL_CAB pin",EXT_VOL_CAB());		//Ray 2016.10.06: Test to read VOL_CAB pin which detect external audio board existence. When board exists, VOL_CAB = 0.

}


//*********************************************************
// Routine: dv_SetExtAudioVolumeValue
// Usage: Set external audio board volume level
// Input: bVolume: 0 ~ 32
//**********************************************************
void dv_SetExtAudioVolumeValue(BYTE bVolume)
{
      BYTE i;
      BYTE changeVol;

      EXT_VOL_SEL_L();			//chip select left channel
      EXT_VOL_SEL_R();			//chip select right channel


      //DebugMessageSystem("Ray: exist volume", g_ucExtAudioVol);
      //DebugMessageSystem("Ray: input volume", bVolume);

      //Check if it's to decrease volume
      if(bVolume<g_ucExtAudioVol){
	  changeVol = g_ucExtAudioVol - bVolume;
	  //DebugMessageSystem("Ray: decrease volume:", changeVol);
	  g_ucExtAudioVol = bVolume;
	  EXT_VOL_DN();			//Volume down
	  //Generate  clock cycle to decrease volume
	  for(i=0;i<changeVol;i++){
	      EXT_VOL_CLK_1();
	      MsOS_DelayTask (1);		//Delay 1ms
	      EXT_VOL_CLK_0();
	      MsOS_DelayTask (1);		//Delay 1ms
	      EXT_VOL_CLK_1();			//Need to set to high first in order for X9314 storing the new potentiometer value
	  }
      }

      //Check if it's to increase volume
      else if(bVolume>g_ucExtAudioVol){
	  changeVol = bVolume - g_ucExtAudioVol;
	  //DebugMessageSystem("Ray: increase volume", changeVol);
	  g_ucExtAudioVol = bVolume;
	  EXT_VOL_UP();				//Volume up
	  //Generate clock cycle to increase volume to desired level
	  for(i=0;i<changeVol;i++){
	      EXT_VOL_CLK_1();
	      MsOS_DelayTask (1);		//Delay 1ms
	      EXT_VOL_CLK_0();
	      MsOS_DelayTask (1);		//Delay 1ms
	      EXT_VOL_CLK_1();			//Need to set to high first in order for X9314 storing the new potentiometer value
	  }
      }

      //Un-select Left and Right channel after finishing volume setting
      EXT_VOL_UNSEL_L();
      EXT_VOL_UNSEL_R();

}



