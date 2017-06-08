//******************************************************************************
// COPYRIGHT (C) Digital View Limited 2016.
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
// MODULE:      dvNT72324.c
//
// USAGE:       This module contains functions for I2C control of
//		Novatek NT72324 FRC 120Hz chipset in SVX-4096 120
//
// NOTE:
//******************************************************************************

//******************************************************************************
//  I N C L U D E    F I L E S
//******************************************************************************

#include "drvIIC.h"			//Ray IIC 2017.02.23: Access Maya IIC functions
#include "MsOS.h"			//Ray IE2 2017.02.23: Access MsOS_DelayTask() function
#include "dvNT72324.h"

//******************************************************************************
//  F U N C T I O N    P R O T O T Y P E S
//******************************************************************************


//******************************************************************************
//  G L O B A L    V A R I A B L E S
//******************************************************************************
BYTE writeBuf[10];		//Buffer of data to be written to NT72324
BYTE readBuf[4];		//Buffer of data read from NT72324

//******************************************************************************
//  C O D E
//******************************************************************************





//*********************************************************
// Routine: dv_NT72324Init
// Usage: Routine to initialize NT72324 for I2C communication
// Output: Init Result: PASS or FAIL
//**********************************************************
BOOLEAN dv_NT72324Init(void)
{
  BOOLEAN result;

  writeBuf[0] = 0xFE;
  writeBuf[1] = 0x31;
  result = dv_NT72324Write(writeBuf,2);		//Write 2 bytes to NT72324

  writeBuf[0] = 0xFF;
  writeBuf[1] = 0x72;
  result &= dv_NT72324Write(writeBuf,2);	//Write 2 bytes to NT72324

  return result;

}


//*********************************************************
// Routine: dv_NT72324FunctionInit
// Usage: Routine to initialize NT72324 H-Flip, V-Flip and MEMC function
//        according to memory setting
//**********************************************************
void dv_NT72324FunctionInit(void)
{
  dv_NT72324Init();			//Initialize IIC interface of NT72324
  //Ray IE2 2017.02.23: Currently we disable all features in initialization. In future, the status could be restored from system memory
  dv_NT72324HFlip(DISABLE);
  dv_NT72324VFlip(DISABLE);
  dv_NT72324Memc(DISABLE);
}



//*********************************************************
// Routine: dv_NT72324Memc
// Usage: To enable or disable MEMC in NT72324
// Input: bSet: ENABLE = enable MEMC;  DISABLE = disable MEMC
//**********************************************************
void dv_NT72324Memc(BOOLEAN bSet)
{
  dv_NT72324VideoBlank(ENABLE);	//Blank the video by NT72324 before changing between PC and video mode to avoid noisy video displaying on screen

  if(bSet==ENABLE){
      dv_NT72324WtCmd(0x02,0x00,1);	//If enable MEMC, we set EN_FORMAT_VD_MODE
  }
  else{
      dv_NT72324WtCmd(0x02,0x00,0);	//If disable MEMC, we set EN_FORMAT_PC_MODE
  }

  dv_NT72324WtCmd(0x01,0x00,bSet);	//Enable/disable MEMC

  MsOS_DelayTask(200);			//Delay 200ms to pass over the noisy video period

  dv_NT72324VideoBlank(DISABLE);	//Disable blank the video by NT72324

}

//*********************************************************
// Routine: dv_NT72324MemcStatus
// Usage: To get the enable or disable status MEMC in NT72324
// Output:  ENABLE = enable MEMC;  DISABLE = disable MEMC
//**********************************************************
BYTE dv_NT72324MemcStatus(void)
{
  dv_NT72324RdCmd(0x01,0x00,readBuf);
  printf("NT72324 MEMC state %d\n", readBuf[0]);
  return readBuf[0];
}



//*********************************************************
// Routine: dv_NT72324VFlip
// Usage: To enable or disable vertical flip in NT72324
// Input: bSet: ENABLE = enable VFlip;  DISABLE = disable VFlip
//**********************************************************
void dv_NT72324VFlip(BOOLEAN bSet)
{

  dv_NT72324WtCmd(0x02,0x0A,bSet);	//Enable/disable VFlip  //Ray 2016.08.25: We use 0x0A command as 0x0D has no response
}


//*********************************************************
// Routine: dv_NT72324VFlipStatus
// Usage: To get the enable or disable status V Flip in NT72324
// Output:  ENABLE = enable V Flip;  DISABLE = disable V Flip
//**********************************************************
BYTE dv_NT72324VFlipStatus(void)
{

  dv_NT72324RdCmd(0x02,0x0A,readBuf);		//Ray 2016.08.25: We use 0x0A command as 0x0D has no response
  printf("NT72324 VFlip state %d\n", readBuf[0]);
  return readBuf[0];
}

//*********************************************************
// Routine: dv_NT72324HFlip
// Usage: To enable or disable horizontal flip in NT72324
// Input: bSet: ENABLE = enable HFlip;  DISABLE = disable HFlip
//**********************************************************
void dv_NT72324HFlip(BOOLEAN bSet)
{
  dv_NT72324WtCmd(0x02,0x0E,bSet);	//Enable/disable HFlip

}

//*********************************************************
// Routine: dv_NT72324HFlipStatus
// Usage: To get the enable or disable status H Flip in NT72324
// Output:  ENABLE = enable H Flip;  DISABLE = disable H Flip
//**********************************************************
BYTE dv_NT72324HFlipStatus(void)
{

  dv_NT72324RdCmd(0x02,0x0E,readBuf);
  printf("NT72324 HFlip state %d\n", readBuf[0]);
  return readBuf[0];
}


//*********************************************************
// Routine: dv_NT72324VideoBlank
// Usage: To enable or disable blank the video by NT72324
// Input: bSet: ENABLE = enable video blank;  DISABLE = disable video blank
//**********************************************************
void dv_NT72324VideoBlank(BOOLEAN bSet)
{
  dv_NT72324WtCmd(0x00,0x00,bSet);	//Enable/disable video blank

}



//*********************************************************
// Routine: dv_NT72324RdCmd
// Usage: Routine to read data of command from NT72324
// Input: ucMainCmd: Main command
//        ucSubCmd: Sub command
//	  *ucData: pointer of buffer to save read data
// Output: Read command result: PASS or FAIL
//**********************************************************
BOOLEAN dv_NT72324RdCmd(BYTE ucMainCmd, BYTE ucSubCmd, BYTE *ucData)
{
  BOOLEAN result;
  BYTE subAddr;

  ucMainCmd |= 0x80;		//Need to set MSB of main cmd to 1 for read its data

  result = dv_NT72324WtCmd(ucMainCmd, ucSubCmd, 0);	//Write the read location command

  //Set the result register 0x9F0A0128
  writeBuf[0] = 0x08;
  writeBuf[1] = 0x28;
  writeBuf[2] = 0x01;
  writeBuf[3] = 0x0A;
  writeBuf[4] = 0x9F;
  result &= dv_NT72324Write(writeBuf,5);		//Write 5 bytes to NT72324

  //Slave address = 0x34, sub address length = 1, sub address = 0x0c, read 4 data bytes
  subAddr = 0x0c;
  result &= MDrv_IIC_ReadBytes(0x34,1,&subAddr,4,ucData);		//Ray IIC 2017.02.23: Use Maya IIC function
  //result &= ScalerMcuIICRead(0x34,1,0x0c,4,ucData);

  return result;

}


//*********************************************************
// Routine: dv_NT72324WtCmd
// Usage: Routine to write command to NT72324
// Input: ucMainCmd: Main command
//        ucSubCmd: Sub command
//	  ucData: Command data
// Output: Write command result: PASS or FAIL
//**********************************************************
BOOLEAN dv_NT72324WtCmd(BYTE ucMainCmd, BYTE ucSubCmd, BYTE ucData)
{
  BOOLEAN result;

  //Set the command register 0x9F0A0120
  writeBuf[0] = 0x00;		//0x00 is dummy byte between slave address and command register
  writeBuf[1] = 0x20;
  writeBuf[2] = 0x01;
  writeBuf[3] = 0x0A;
  writeBuf[4] = 0x9F;

  writeBuf[5] = ucData;		//Set data of command
  writeBuf[6] = 0;		//2nd data byte is 0

  writeBuf[7] = ucSubCmd;	//Set Sub command
  writeBuf[8] = ucMainCmd;	//Set Main command

  result = dv_NT72324Write(writeBuf,9);	//Write 9 bytes to NT72324

  return result;

}




//*********************************************************
// Routine: dv_NT72324Write
// Usage: It is low level routine to write data bytes to NT72324
// Input: *ucData: pointer to data byte array to be written
//         ucNoOfByte: No of byte to be written
// Output: Write result: PASS or FAIL
//**********************************************************
BOOLEAN dv_NT72324Write(BYTE *ucData, BYTE ucNoOfByte)
{
  BOOLEAN result;							//Jot down IIC communication result

  //NT72324 slave address is 0x34
  result = MDrv_IIC_WriteBytes(0x34, 0, 0, ucNoOfByte, (BYTE *)ucData);	//Ray IIC 2017.02.23: Use Maya IIC function
  //result = ScalerMcuIICWrite(0x34, 0, 0, ucNoOfByte, (BYTE *)ucData);
  if(result==FAIL){
      printf("Fail to write NT72324\n");
  }

  return result;
}






