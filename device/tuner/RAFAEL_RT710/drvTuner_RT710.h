
//***********************************************
//RT710 software update: 2015/03/24
//file: header file
//version: v2.7B
//***********************************************

//#include "..\stdafx.h"

#ifndef  _RT710_H_ 
#define _RT710_H_

//#define UINT8 unsigned char
//#define UINT16 unsigned int
//#define UINT32 unsigned long

#define UINT8  unsigned char
//#define UINT16 unsigned short
#define UINT32 unsigned long
#define INT32 signed int



#define RT710_VERSION   "RT710_GUI_v2.7B"
#define RT710_Reg_Num	16

#define RT710_Xtal	16000

typedef struct _I2C_LEN_TYPE
{
	UINT8 RegAddr;
	UINT8 Data[50];
	UINT8 Len;
}I2C_LEN_TYPE;

typedef struct _I2C_TYPE
{
	UINT8 RegAddr;
	UINT8 Data;
}I2C_TYPE;



#define RT710_0DBM_SETTING 	FALSE   
//#define RT710_0DBM_SETTING 	TRUE  

typedef enum _RT710_Err_Type
{
	RT710_Success = TRUE,
	RT710_Fail    = FALSE
}RT710_Err_Type;

typedef enum _RT710_LoopThrough_Type
{
	LOOP_THROUGH = TRUE,
	SIGLE_IN     = FALSE
}RT710_LoopThrough_Type;

typedef enum _RT710_ClockOut_Type
{
	ClockOutOn = TRUE,
	ClockOutOff= FALSE
}RT710_ClockOut_Type;

typedef enum _RT710_OutputSignal_Type
{
	DifferentialOut = TRUE,
	SingleOut     = FALSE
}RT710_OutputSignal_Type;

typedef enum _RT710_AGC_Type
{
	AGC_Negative = TRUE,
	AGC_Positive = FALSE
}RT710_AGC_Type;

typedef enum _RT710_AttenVga_Type
{
	ATTENVGAON = TRUE,
	ATTENVGAOFF= FALSE
}RT710_AttenVga_Type;

typedef enum _R710_FineGain_Type
{
	FINEGAIN_3DB = 0,
	FINEGAIN_2DB,
	FINEGAIN_1DB,
	FINEGAIN_0DB
}R710_FineGain_Type;

typedef struct _RT710_RF_Gain_Info
{
	UINT8   RF_gain;

}RT710_RF_Gain_Info;

typedef struct _RT710_INFO_Type
{
	UINT32 DVBSBW;
	UINT32 RT710_Freq;
	RT710_LoopThrough_Type RT710_LoopThrough_Mode;
	RT710_ClockOut_Type RT710_ClockOut_Mode;
	RT710_OutputSignal_Type RT710_OutputSignal_Mode;
	RT710_AGC_Type RT710_AGC_Mode;
	RT710_AttenVga_Type RT710_AttenVga_Mode;
	R710_FineGain_Type R710_FineGain;
}RT710_INFO_Type;

typedef enum _TUNER_NUM
{
	RT710_TUNER_1 = 0,
	RT710_TUNER_2,
	RT710_TUNER_3,
	RT710_TUNER_4,
	MAX_TUNER_NUM
}RT710_TUNER_NUM_TYPE;

//----------------------------------------------------------//
//                   RT710 Function                         //
//----------------------------------------------------------//
#define R710_Delay_MS	OS_DELAY_TASK
RT710_Err_Type RT710_Setting(RT710_INFO_Type RT710_Set_Info);
RT710_Err_Type RT710_Standby( RT710_LoopThrough_Type RT710_LTSel);
RT710_Err_Type RT710_GetRfGain(RT710_RF_Gain_Info *RT710_rf_gain);
RT710_Err_Type RT710_GetRfRssi(UINT32 RF_Freq_Khz, INT32 *RfLevelDbm, UINT8 *fgRfGainflag);
RT710_Err_Type RT710_SetInitFlag(UINT8 InitFlag);


extern UINT8 RT710_Reg_Arry_Init[RT710_Reg_Num] ;
extern UINT8 RT710_ADDRESS;
extern UINT8 R0TOR3_Write_Arry[4];

MS_BOOL MDrv_DVBS_Tuner_SetFreq(MS_U16 u16CenterFreq_MHz, MS_U32 u32SymbolRate_Ks);
MS_BOOL MDrv_DVBS_Tuner_Initial(void);
MS_BOOL MDrv_DVBS_Tuner_CheckLock(void);
float MDrv_DVBS_Tuner_Get_RSSI(MS_U16 u16_gain, MS_U8 Dtype);    




#endif


