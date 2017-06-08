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
//Ray IOE 2017.02.27
//
// MODULE:      EXT_GPIO.h
//
// USAGE:       Header file of EXT_GPIO.c which contains functions for I/O expander manipulation
//
//******************************************************************************
//----------------------------------------------------------------------------
// DEFINE DEFINITION
//----------------------------------------------------------------------------
#ifndef USER_DIGITALVIEW_HEADER_DVEXT_GPIO_H_
#define USER_DIGITALVIEW_HEADER_DVEXT_GPIO_H_

#ifdef EXT_GPIO_C
#define INTERFACE
#else
#define INTERFACE extern
#endif



//****************************************************************************
// GLOBAL DEFINITION
//****************************************************************************
//Ray IOE 2017.02.27: Define the external IO pins positions
#define ExGPIO_BL_STATUS	0x01
#define ExGPIO_VOL_CAB		0x02
#define JC3_11_12		0x04
#define JC3_9_10		0x08
#define JC3_7_8			0x10
#define JC3_5_6			0x20
#define JC3_3_4			0x40
#define JC3_1_2			0x80
#define SW3_8			0x0100
#define SW3_7			0x0200
#define SW3_6			0x0400
#define SW3_5			0x0800
#define SW3_4			0x1000
#define SW3_3			0x2000
#define SW3_2			0x4000
#define SW3_1			0x8000



//****************************************************************************
// FUNCTION PROTOTYPE
//****************************************************************************
INTERFACE void MDrv_ExGPIO_Init(void);
INTERFACE void MDrv_ExGPIO_Set(U16 u16BitMask, BOOLEAN bHigh);
INTERFACE BYTE MDrv_ExGPIO_Get(U16 u16BitMask);

//****************************************************************************
// EXTERN VARIABLE
//****************************************************************************


#endif /* USER_DIGITALVIEW_HEADER_DVEXT_GPIO_H_*/
