//******************************************************************************
// COPYRIGHT (C) Digital View Limited 2015.
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
// MODULE:      dvNT72324.h
//
// USAGE:       Header file of dvNT72324.c which contains functions for NT72324 control
//
//******************************************************************************

#ifndef USER_DIGITALVIEW_HEADER_DVNT72324_H_
#define USER_DIGITALVIEW_HEADER_DVNT72324_H_

//----------------------------------------------------------------------------
// DEFINE DEFINITION
//----------------------------------------------------------------------------

//****************************************************************************
// GLOBAL DEFINITION
//****************************************************************************

//****************************************************************************
// FUNCTION PROTOTYPE
//****************************************************************************
bit dv_NT72324Init(void);
void dv_NT72324FunctionInit(void);
void dv_NT72324Memc(bit bSet);
void dv_NT72324VFlip(bit bSet);
void dv_NT72324HFlip(bit bSet);
void dv_NT72324VideoBlank(bit bSet);
BYTE dv_NT72324MemcStatus(void);
BYTE dv_NT72324VFlipStatus(void);
BYTE dv_NT72324HFlipStatus(void);
bit dv_NT72324RdCmd(BYTE ucMainCmd, BYTE ucSubCmd, BYTE *ucData);
bit dv_NT72324WtCmd(BYTE ucMainCmd, BYTE ucSubCmd, BYTE ucData);
bit dv_NT72324Write(BYTE *ucData, BYTE ucNoOfByte);



//****************************************************************************
// EXTERN VARIABLE
//****************************************************************************


#endif /* USER_DIGITALVIEW_HEADER_DVNT72324_H_ */
