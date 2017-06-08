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
// MODULE:      dvEDID.c
//
// USAGE:       This module contains functions for EDID manipulation
//
//******************************************************************************

//******************************************************************************
//  I N C L U D E    F I L E S
//******************************************************************************

#define DV_EDID_C
#include "datatype.h"
#include "dvEDID.h"
#include "drvIIC.h"			//Ray EDD 2017.02.24: Access Maya IIC functions
#include "drvGPIO.h"			//Ray EDD 2017.02.27: For EDID_EEPROM_WP_ON/OFF

//******************************************************************************
//  F U N C T I O N    P R O T O T Y P E S
//******************************************************************************
static BYTE dv_EDIDBurstWriteBytes(U16 wSlaveID, U16 wIndex, U8 *pBuf, U16 ucBufLen);

//******************************************************************************
//  G L O B A L    V A R I A B L E S
//******************************************************************************
#define EDID_PAGE_WRITE_LEN	8		//24C02 EEPROM page write length is 8

//******************************************************************************
//  C O D E
//******************************************************************************

//Ray EDD 2017.02.24: Define EDID tables
BYTE tEDID_TBL_HDMI1_4[] =
{
  #include "./EDID/EdidTableHdmi.h"
};

BYTE tEDID_TBL_HDMI2_0[] =
{
  #include "./EDID/EdidTableHdmi_2_0.h"
};

BYTE tEDID_TBL_DVI[] =
{
  #include "./EDID/EdidTableDvi.h"
};



//Ray EDD 2017.02.27: burst write EDID function which is only used inside dvEDID.c
//*********************************************************
// Routine: dv_EDIDBurstWriteBytes
// Usage: Burst Write EDID EEPROM
// Input: wSlaveID: low byte is IIC address, high byte is the bus select index in g_I2CBus
//        wIndex: start address to write EEPROM
//	  pBuf: pointer to data buffer to be written to EEPROM
//	  ucBufLen: length of data to be written
// Output: write result: 1 = PASS, 0 = FAIL
//**********************************************************
static BYTE dv_EDIDBurstWriteBytes(U16 wSlaveID, U16 wIndex, U8 *pBuf, U16 ucBufLen)
{
    U8 ucWriteCount;  // write counter
    U8 ucRemainLen;   // i2c word address
    BYTE ucAddr;
    BYTE result=PASS;

    EDID_EEPROM_WP_OFF();	//Turn off EDID write protect first

    while ( 1 )
    {
        // check page write roll over
        if (ucBufLen > EDID_PAGE_WRITE_LEN)
        {
            ucWriteCount = EDID_PAGE_WRITE_LEN;
        }
        else
        {
            ucWriteCount = (U8)ucBufLen;
        }

        // check word address higher than page write bits
        ucRemainLen = LOBYTE(wIndex) % EDID_PAGE_WRITE_LEN;

        if (ucRemainLen) // check ramain
        {
            ucRemainLen = EDID_PAGE_WRITE_LEN - ucRemainLen;

            if (ucWriteCount > ucRemainLen) // check not roll over
            {
                ucWriteCount = ucRemainLen;
            }
        }

        // EEPROM page write
        //msAPI_rmPageWrite(wIndex, pBuf, ucWriteCount);
        ucAddr = (BYTE)wIndex;
        result &= MDrv_IIC_WriteBytes(wSlaveID, 1, &ucAddr, ucWriteCount, pBuf);
        MsOS_DelayTask(12);		//Ray EDD 2017.03.16: Add delay after page write, which is also done in msAPI_rmPageWrite routine

        // check end of buffer
        ucBufLen -= ucWriteCount;

        if ( ucBufLen == 0 )
        {
            break;
        }

        wIndex += ucWriteCount; // next word address
        pBuf += ucWriteCount; // next buffer pointer
    }

    EDID_EEPROM_WP_ON();	//Turn on EDID write protect after finish writing

    return result;

}


//Ray EDD 2017.02.27:
//*********************************************************
// Routine: dv_LoadEDID
// Usage: Load all ports EDID either from predefine EDID in firmware, or from user EDID
//        in SYSTEM EEPROM and then write into EDID EEPROMs.
//        If it loads 1st 128 bytes EDID from predefine EDID, it also
//           - checks and loads EDID product name if it's needed
//           - loads EDID preferred timing according to DIP switch SW3 if the board is SVX-4096
// Output:  1 = PASS, 0 = FAIL
//**********************************************************
BYTE dv_LoadEDID(void)
{
  WORD usUserEDIDAdr;
  BYTE ucInputPort;
  //BYTE ucUserEDIDEn;
  //BYTE ucEDID[128];
  BYTE *ucPredefEDID;
  BYTE ucResult = PASS;


  //Load EDID table to EDID EEPROM from HDMI1 to DVI one by one
  for(ucInputPort=HDMI1;ucInputPort<=DVI;ucInputPort++){

      //Load predefined EDID table address
      switch(ucInputPort){
	case HDMI1:
	  ucPredefEDID = tEDID_TBL_HDMI2_0;
	  usUserEDIDAdr = I2C_DEV_EDID_D0;
	  break;
	case HDMI2:
	  ucPredefEDID = tEDID_TBL_HDMI2_0;		//Ray EDD 2017.05.25: HDMI2 changes to use HDMI2.0 EDID
	  //ucPredefEDID = tEDID_TBL_HDMI1_4;
	  usUserEDIDAdr = I2C_DEV_EDID_D1;
	  break;
	case HDMI3:
	  ucPredefEDID = tEDID_TBL_HDMI1_4;
	  usUserEDIDAdr = I2C_DEV_EDID_D2;
	  break;
	case DVI:
	  ucPredefEDID = tEDID_TBL_DVI;
	  usUserEDIDAdr = I2C_DEV_EDID_D3;
	  break;
	default:
	  break;
      }

      //Ray EDD 2017.02.27: We temporary write EDID by function below when user EDID function not done yet
      ucResult &= dv_EDIDBurstWriteBytes(usUserEDIDAdr, 0, ucPredefEDID, 256);

      //Ray EDD 2017.02.27: We temporary disable user EDID function as it's not implemented yet
      /*
      //Check if User EDID is enabled
      usUserEDIDAdr = dv_UserEDID_EEPROM_Address(ucInputPort);	//Get the user EDID EEPROM start address of input source

      //If input source and thus user EDID EEEPROM start address is valid
      if(usUserEDIDAdr!=0xffff){
	  UserCommonEepromRead((usUserEDIDAdr-1), 1, (BYTE *)(&ucUserEDIDEn));			//Read back current EDID EEPROM enable byte
	  //Check if 1st user EDID (0~127 byte)is enabled
	  if((ucUserEDIDEn&0x0f)==_1ST_USER_EDID_ENABLE){
	      ucResult &= UserCommonEepromRead(usUserEDIDAdr, 128, (BYTE *)ucEDID);		//Read user EDID byte 0~0x7f from SYSTEM EEPROM
	      ucResult &= dv_write128ByteEDIDEEPROM(ucInputPort, ucEDID, 0x00);		//Write user EDID table from EDID buffer to EDID EEPROM address 0~0x7F
	  }
	  else{
	      //As user EDID 0~127 byte is disabled, load EDID from predefined EDID table and write it to EDID EEPROM from address 0x00~0x7f
	      ucResult &=dv_write128ByteEDIDEEPROM(ucInputPort, ucPredefEDID, 0x00);
	      //Check if it's needed to write EDID product name
	      ucResult &= dv_checkWriteEDIDProductName(ucInputPort);
	      //Load preferred EDID timing if the board is SVX-4096
	      if(ucBoardVersion == _SVX4096_V20){
		  ucResult &= dv_UpdateEDIDPrefTiming(ucInputPort);
	      }
	  }
	  //Check if 2nd user EDID (128~255 byte)is enabled
	  if((ucUserEDIDEn&0xf0)==_2ND_USER_EDID_ENABLE){
	      ucResult &= UserCommonEepromRead((usUserEDIDAdr+0x80), 128, (BYTE *)ucEDID);	//Read user EDID byte 0x80~0xff from SYSTEM EEPROM
	      ucResult &= dv_write128ByteEDIDEEPROM(ucInputPort, ucEDID, 0x80);		//Write user EDID table from EDID buffer to EDID EEPROM address 0x80~0xFF
	  }
	  else{
	      //As user EDID 128~255 byte is disabled, load EDID from predefined EDID table and write it to EDID EEPROM from address 0x80~0xff
	      ucResult &= dv_write128ByteEDIDEEPROM(ucInputPort, (ucPredefEDID+0x80), 0x80);
	  }

      }
      */
  }
  return ucResult;

}



//Ray EDD 2017.02.24: write EDID function
//*********************************************************
// Routine: dv_writeEDIDEEPROM
// Usage: Write EDID table to EEPROM
// Input: port: HDMI1,HDMI2,HDMI3,DVI
// Output: 1 = PASS, 0 = FAIL
//**********************************************************
BYTE dv_writeEDIDEEPROM(BYTE port)
{
  BYTE result = PASS;
  //BYTE userEDIDEn = 0;		//Denote if User EDID is enabled


  switch(port){
    case HDMI1:
	result &= dv_EDIDBurstWriteBytes(I2C_DEV_EDID_D0, 0, tEDID_TBL_HDMI2_0, sizeof(tEDID_TBL_HDMI2_0));	//Ray EDD 2017.02.27: Write HDMI2.0 EDID to EDID EEPROM.
	break;
    case HDMI2:
	result &= dv_EDIDBurstWriteBytes(I2C_DEV_EDID_D1, 0, tEDID_TBL_HDMI2_0, sizeof(tEDID_TBL_HDMI2_0));	//Ray EDD 2017.05.08: Default write HDMI2.0 EDID to HDMI2
	//result &= dv_EDIDBurstWriteBytes(I2C_DEV_EDID_D1, 0, tEDID_TBL_HDMI1_4, sizeof(tEDID_TBL_HDMI1_4));	//Ray EDD 2017.02.27: Write HDMI1.4 EDID to EDID EEPROM.
	break;
    case HDMI3:
	result &= dv_EDIDBurstWriteBytes(I2C_DEV_EDID_D2, 0, tEDID_TBL_HDMI1_4, sizeof(tEDID_TBL_HDMI1_4));	//Ray EDD 2017.02.27: Write HDMI1.4 EDID to EDID EEPROM.
	break;
    case DVI:
	result &= dv_EDIDBurstWriteBytes(I2C_DEV_EDID_D3, 0, tEDID_TBL_DVI, sizeof(tEDID_TBL_DVI));		//Ray EDD 2017.02.27: Write DVI EDID to EDID EEPROM.
	break;
    default:
	result = FAIL;
        break;
  }

  //Ray 2016.12.13: Check if it's needed to write EDID product name
  //result &= dv_checkWriteEDIDProductName(port);

  return(result);
}

//Ray EDD 2017.02.27: Read EDID EEPROM routine
//*********************************************************
// Routine: dv_EDIDEepromRead
// Usage: Read EDID EEPROM.
// Input:
//        readAddr: start address to read data
//	  readLen: length of data to be read
//	  readData: pointer to memory storing read data
//        port: HDMI1,HDMI2,HDMI3,DVI
//
// Output: 1 = PASS, 0 = FAIL
//**********************************************************
BYTE dv_EDIDEepromRead(BYTE readAddr, WORD readLen, BYTE *readData, BYTE port)
{
  BYTE result=FAIL;
  BYTE edidAddr = readAddr;

  switch(port){
    case HDMI1:
	result = MDrv_IIC_ReadBytes(I2C_DEV_EDID_D0, 1, &edidAddr, readLen, readData);		//Ray EDD 2017.02.27: Read EDID EEPROM
	break;
    case HDMI2:
	result = MDrv_IIC_ReadBytes(I2C_DEV_EDID_D1, 1, &edidAddr, readLen, readData);		//Ray EDD 2017.02.27: Read EDID EEPROM
	break;
    case HDMI3:
	result = MDrv_IIC_ReadBytes(I2C_DEV_EDID_D2, 1, &edidAddr, readLen, readData);		//Ray EDD 2017.02.27: Read EDID EEPROM
	break;
    case DVI:
	result = MDrv_IIC_ReadBytes(I2C_DEV_EDID_D3, 1, &edidAddr, readLen, readData);		//Ray EDD 2017.02.27: Read EDID EEPROM
	break;
    default:
	result = FAIL;
        break;
  }
  return result;
}





