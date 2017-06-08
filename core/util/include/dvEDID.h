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
// MODULE:      dvEDID.h
//
// USAGE:       Header file of dvEDID.c which contains functions for EDID manipulation
//
//******************************************************************************
//----------------------------------------------------------------------------
// DEFINE DEFINITION
//----------------------------------------------------------------------------
#ifndef USER_DIGITALVIEW_HEADER_DVEDID_H_
#define USER_DIGITALVIEW_HEADER_DVEDID_H_

#ifdef DV_EDID_C
#define INTERFACE
#else
#define INTERFACE extern
#endif



//****************************************************************************
// GLOBAL DEFINITION
//****************************************************************************
//Ray EDD 2017.02.24: Input source typedef
typedef enum
{
  HDMI1,
  HDMI2,
  HDMI3,
  DVI,
}EDID_INPUT_SOURCE;


//****************************************************************************
// FUNCTION PROTOTYPE
//****************************************************************************
INTERFACE BYTE dv_writeEDIDEEPROM(BYTE port);
INTERFACE BYTE dv_EDIDEepromRead(BYTE readAddr, WORD readLen, BYTE *readData, BYTE port);
INTERFACE BYTE dv_LoadEDID(void);


//****************************************************************************
// EXTERN VARIABLE
//****************************************************************************


#endif /* USER_DIGITALVIEW_HEADER_DVEDID_H_*/
