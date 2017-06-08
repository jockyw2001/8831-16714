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
// MODULE:      dvExtAudio.h
//
// USAGE:       Header file of dvExtAudio.c which contains functions for external audio board manipulation
//
//******************************************************************************
//----------------------------------------------------------------------------
// DEFINE DEFINITION
//----------------------------------------------------------------------------
#ifndef USER_DIGITALVIEW_HEADER_DVEXT_AUDIO_H_
#define USER_DIGITALVIEW_HEADER_DVEXT_AUDIO_H_

#ifdef DV_EXT_AUDIO_C
#define INTERFACE
#else
#define INTERFACE extern
#endif



//****************************************************************************
// GLOBAL DEFINITION
//****************************************************************************

INTERFACE BYTE g_ucExtAudioVol;		//Ray 2016.03.03: External audio board volume 0~32


//****************************************************************************
// FUNCTION PROTOTYPE
//****************************************************************************
INTERFACE void dv_SetExtAudioVolZero(void);
INTERFACE void dv_ExtAudioVolumeInit(void);
INTERFACE void dv_SetExtAudioVolumeValue(BYTE Volume);


//****************************************************************************
// EXTERN VARIABLE
//****************************************************************************


#endif /* USER_DIGITALVIEW_HEADER_DVEXT_AUDIO_H_*/
