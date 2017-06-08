/****************************************************************
                           RT710.c
Copyright 2015 by Rafaelmicro., Inc.
                 C H A N G E   R E C O R D
  Date        Author           Version      Description
--------   --------------    --------   ----------------------
03/06/2012     Ryan 	        v2.1
04/08/2013	   Ryan				v2.2		add rfgain Function
07/25/2013	   Ryan				v2.3        vga agc slop from negative to positive
01/15/2014	   Ryan				v2.4		modify  setting Frequency from 1650~2000
02/25/2014	   Ryan				v2.5		add Vga Attenuator Function
03/11/2014	   Ryan				v2.6		modify rf gain calculate
01/06/2015	   Ryan				v2.7		Initialization value write-once
03/24/2015	   Ryan				v2.7B		add RF RSSI funvtion(output dBm)
****************************************************************/
#include <math.h>
#include "MsCommon.h"
#include "drvIIC.h"
#include "Board.h"

#include "drvTuner_RT710.h"

#if 0 //(FRONTEND_TUNER_TYPE == RAFAEL_R842_TUNER)
    #if CVT_EN_R842_RT710_NEW_ADDR
    UINT8 RT710_ADDRESS=0xF4;
    #else
    UINT8 RT710_ADDRESS=0xB4;
    #endif
#else
UINT8 RT710_ADDRESS=0xF4;
#endif
UINT8 R0TOR3_Write_Arry[4]={0x00,0x00,0x00,0x00};

//MSB1245
UINT16   _u16SignalLevel[3][4][2]=
{
    {{36657,    60},{32099,    70},{29773,    80},{252,    90}},
	{{36855,    60},{32364,    70},{30049,    80},{252,    90}},
	{{36032,    60},{31641,    70},{28838,    80},{252,    90}},
};
#define LOWBAND 0
#define MIDBAND 1
#define HIGHBAND 2

I2C_TYPE RT710_Write_Byte;
I2C_LEN_TYPE RT710_Write_Len;
I2C_LEN_TYPE RT710_Read_Len;
UINT8 Read_type = TRUE;
UINT8  R710_Initial_done_flag = FALSE;
static MS_U16 IFfreqMHz;
int RT710_Convert(int InvertNum)
{
	int ReturnNum = 0;
	int AddNum    = 0x80;
	int BitNum    = 0x01;
	int CuntNum   = 0;

	for(CuntNum = 0;CuntNum < 8;CuntNum ++)
	{
		if(BitNum & InvertNum)
			ReturnNum += AddNum;

		AddNum /= 2;
		BitNum *= 2;
	}

	return ReturnNum;
}

//bRet&= MDrv_IIC_WriteBytes((U16)((DVBS_TUNER_IIC_BUS<<8)|u8SlaveID), 0, &addr_size, 1,&addr_data);


MS_BOOL RT710_I2C_Write_Len(I2C_LEN_TYPE *I2C_Info)
{
//	MDrv_IIC_WriteBytes(R828_ADDRESS, 1, &I2C_Info->RegAddr, I2C_Info->Len, I2C_Info->Data);
    if(MDrv_IIC_WriteBytes((U16)((DVBS_TUNER_IIC_BUS<<8)|RT710_ADDRESS), 1, &I2C_Info->RegAddr, I2C_Info->Len, I2C_Info->Data)==FALSE)
    {
        printf("\r\n-----RT710_I2C_Write_Len error------");
        return FALSE;
    }
    return TRUE;
}

MS_BOOL RT710_I2C_Read_Len(I2C_LEN_TYPE *I2C_Info)
{
    int DataCunt = 0;

    MDrv_IIC_ReadBytes((U16)((DVBS_TUNER_IIC_BUS<<8)|RT710_ADDRESS), 0, NULL, I2C_Info->Len, &I2C_Info->Data[0]);

    for(DataCunt = 0;DataCunt < I2C_Info->Len;DataCunt ++)
    {
        I2C_Info->Data[DataCunt] = RT710_Convert(I2C_Info->Data[DataCunt]);
    }

    return true;
}

MS_BOOL RT710_I2C_Write(I2C_TYPE *I2C_Info)
{
       //printf("\r\nADDR %d = %x", I2C_Info->RegAddr,I2C_Info->Data);
    if(MDrv_IIC_WriteByte((U16)((DVBS_TUNER_IIC_BUS<<8)|RT710_ADDRESS), I2C_Info->RegAddr, I2C_Info->Data)==FALSE)
        printf("\r\n -----RT710_I2C_Write error------");

    return TRUE;
}


RT710_Err_Type RT710_PLL(UINT32 PLL_Freq);

static UINT16 RT710_Lna_Acc_Gain[19] =
{
 0, 26, 42, 74, 103, 129, 158, 181, 188, 200,  //0~9
 220, 248, 280, 312, 341, 352, 366, 389, 409,	//10~19
};
static UINT16 RT710_Lna2_Acc_Gain[32] =
{
 0, 27, 53, 81, 109, 134, 156, 176, 194, 202,   //0~9
 211, 221, 232, 245, 258, 271, 285, 307, 326, 341,	//10~19
 357, 374, 393, 410, 428, 439, 445, 470, 476, 479, 	//20~29
 495, 507	//30~31
};

#if(RT710_0DBM_SETTING == TRUE)
	//0dBm ; LT:lna output ; LT:HPF off  ; LT Current High
	UINT8 RT710_Reg_Arry_Init[RT710_Reg_Num] ={0x40, 0x1C, 0xA0, 0x90, 0x41, 0x50, 0xED, 0x25, 0x47, 0x58, 0x39, 0x60, 0x38, 0xE7, 0x90, 0x35};
#else
	//-10~-30dBm ; LT:lna center ; LT:HPF on  ; LT Current Low
	UINT8 RT710_Reg_Arry_Init[RT710_Reg_Num] ={0x40, 0x1D, 0xA0, 0x10, 0x41, 0x50, 0xED, 0x25, 0x07, 0x58, 0x39, 0x64, 0x38, 0xE7, 0x90, 0x35};
#endif

UINT8 RT710_Reg_Arry[RT710_Reg_Num]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


RT710_Err_Type RT710_Setting(RT710_INFO_Type RT710_Set_Info)
{

		UINT8 fine_tune=0,Coarse_tune=0;
		//UINT8 test_coar=0x0D;
		UINT32 Coarse=0;
        int icount;
        int i;

		RT710_Write_Len.RegAddr=0x00;
		RT710_Write_Len.Len=0x10;

		RT710_Read_Len.RegAddr=0x00;
		RT710_Read_Len.Len=0x10;

		if(R710_Initial_done_flag == FALSE)
		{
			RT710_I2C_Read_Len(&RT710_Read_Len) ;
			if((RT710_Read_Len.Data[3]&0xF0)==0x70)
				Read_type=TRUE;
			else
				Read_type=FALSE;
			for(icount=0;icount<RT710_Reg_Num;icount++)
			{
				RT710_Reg_Arry[icount]=RT710_Reg_Arry_Init[icount];
			}

			// LOOP_THROUGH(0=on ; 1=off)
			if(RT710_Set_Info.RT710_LoopThrough_Mode != LOOP_THROUGH)
			{
				RT710_Reg_Arry[1] |=0x04;
			}
			else
			{
				RT710_Reg_Arry[1] &=0xFB;
			}

			//Clock out(1=off ; 0=on)
			if(RT710_Set_Info.RT710_ClockOut_Mode != ClockOutOn)
			{
				RT710_Reg_Arry[3] |=0x10;
			}
			else
			{
				RT710_Reg_Arry[3] &=0xEF;
			}

			//Output Signal Mode
			if(RT710_Set_Info.RT710_OutputSignal_Mode != DifferentialOut)
			{
				RT710_Reg_Arry[11] |=0x10;
			}
			else
			{
				RT710_Reg_Arry[11] &=0xEF;
			}

			//AGC Type  //R13[4] Negative=0 ; Positive=1;
			if(RT710_Set_Info.RT710_AGC_Mode != AGC_Positive)
			{
				RT710_Reg_Arry[13] &=0xEF;
			}
			else
			{
				RT710_Reg_Arry[13] |=0x10;
			}

			//RT710_Vga_Sttenuator_Type
			if(RT710_Set_Info.RT710_AttenVga_Mode != ATTENVGAON)
			{
				RT710_Reg_Arry[11] &= 0xF7;
			}
			else
			{
				RT710_Reg_Arry[11] |= 0x08;
			}

			//R710_Fine_Gain_Type
			switch(RT710_Set_Info.R710_FineGain)
			{
				case FINEGAIN_3DB:
					RT710_Reg_Arry[14] = (RT710_Reg_Arry[14] & 0xFC) | 0x00;
				break;
				case FINEGAIN_2DB:
					RT710_Reg_Arry[14] = (RT710_Reg_Arry[14] & 0xFC) | 0x01;
				break;
				case FINEGAIN_1DB:
					RT710_Reg_Arry[14] = (RT710_Reg_Arry[14] & 0xFC) | 0x02;
				break;
				case FINEGAIN_0DB:
					RT710_Reg_Arry[14] = (RT710_Reg_Arry[14] & 0xFC) | 0x03;
				break;
				default:
					 RT710_Reg_Arry[14] = (RT710_Reg_Arry[14] & 0xFC) | 0x00;
				break;
			}

			for(i=0;i<RT710_Write_Len.Len;i++)
			{
				RT710_Write_Len.Data[i]=RT710_Reg_Arry[i];
			}

			if(RT710_I2C_Write_Len(&RT710_Write_Len) != RT710_Success)
				return RT710_Fail;

			R710_Initial_done_flag = TRUE;
		}
		if(RT710_PLL(RT710_Set_Info.RT710_Freq)!=RT710_Success)
			 return RT710_Fail;

		R710_Delay_MS(10);

		if((RT710_Set_Info.RT710_Freq >= 1600000) && (RT710_Set_Info.RT710_Freq <= 1950000))
		{
			RT710_Reg_Arry[2] |= 0x40; //LNA Mode with att
			RT710_Reg_Arry[8] |= 0x80; //Mixer Buf -3dB
		}
		else
		{
			RT710_Reg_Arry[2] &= 0xBF; //LNA Mode no att
			RT710_Reg_Arry[8] &= 0x7F; //Mixer Buf off
			if(RT710_Set_Info.RT710_Freq >= 1950000)
			{
				RT710_Reg_Arry[10] = ((RT710_Reg_Arry[10] & 0xF0) | 0x08); //AGC VTH:1.14V
				RT710_Reg_Arry[10] = ((RT710_Reg_Arry[10] & 0x0F) | 0x30); //AGC VTL:0.64V
				RT710_Write_Byte.RegAddr = 0x0A;
				RT710_Write_Byte.Data = RT710_Reg_Arry[10];
				if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
					return RT710_Fail;
			}
			else
			{
				RT710_Reg_Arry[10] =  (RT710_Reg_Arry_Init[10]); //AGC VTH:1.14V  ;  VTL:0.64V
				RT710_Write_Byte.RegAddr = 0x0A;
				RT710_Write_Byte.Data = RT710_Reg_Arry[10];
				if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
					return RT710_Fail;
			}
		}
		RT710_Write_Byte.RegAddr = 0x02;
		RT710_Write_Byte.Data = RT710_Reg_Arry[2];
		if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
			return RT710_Fail;
		RT710_Write_Byte.RegAddr = 0x08;
		RT710_Write_Byte.Data = RT710_Reg_Arry[8];
		if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
			return RT710_Fail;


		if(RT710_Set_Info.RT710_Freq >= 2000000)
		{
			RT710_Reg_Arry[14]=( RT710_Reg_Arry[14]& 0xF3)|0x08;
		}
		else
		{
			RT710_Reg_Arry[14]=( RT710_Reg_Arry[14]& 0xF3)|0x00;
		}
		RT710_Write_Byte.RegAddr = 0x0E;
		RT710_Write_Byte.Data = RT710_Reg_Arry[14];
		if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;


		if(RT710_Set_Info.DVBSBW >=38000)
		{
			fine_tune=1;
			Coarse =(( RT710_Set_Info.DVBSBW -38000) /1740)+16;
			if((( RT710_Set_Info.DVBSBW -38000) % 1740) > 0)
			Coarse+=1;
		}
		else if(RT710_Set_Info.DVBSBW<=5000)
		{
			Coarse=0;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>5000) && (RT710_Set_Info.DVBSBW<=7300))
		{
			Coarse=0;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>7300) && (RT710_Set_Info.DVBSBW<=9600))
		{
			Coarse=1;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>9600) && (RT710_Set_Info.DVBSBW<=10400))
		{
			Coarse=1;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>10400) && (RT710_Set_Info.DVBSBW<=11600))
		{
			Coarse=2;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>11600) && (RT710_Set_Info.DVBSBW<=12600))
		{
			Coarse=2;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>12600) && (RT710_Set_Info.DVBSBW<=13400))
		{
			Coarse=3;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>13400) && (RT710_Set_Info.DVBSBW<=14600))
		{
			Coarse=3;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>14600) && (RT710_Set_Info.DVBSBW<=15800))
		{
			Coarse=4;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>15800) && (RT710_Set_Info.DVBSBW<=17000))
		{
			Coarse=4;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>17000) && (RT710_Set_Info.DVBSBW<=17800))
		{
			Coarse=5;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>17800) && (RT710_Set_Info.DVBSBW<=19000))
		{
			Coarse=5;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>19000) && (RT710_Set_Info.DVBSBW<=20200))
		{
			Coarse=6;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>20200) && (RT710_Set_Info.DVBSBW<=21200))
		{
			Coarse=6;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>21200) && (RT710_Set_Info.DVBSBW<=21800))
		{
			Coarse=7;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>21800) && (RT710_Set_Info.DVBSBW<=23400))
		{
			Coarse=7;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>23400) && (RT710_Set_Info.DVBSBW<=24400))
		{
			Coarse=9;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>24400) && (RT710_Set_Info.DVBSBW<=24600))
		{
			Coarse=10;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>24600) && (RT710_Set_Info.DVBSBW<=26200))
		{
			Coarse=10;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>26200) && (RT710_Set_Info.DVBSBW<=26600))
		{
			Coarse=11;
			fine_tune=0;
		}
		else if((RT710_Set_Info.DVBSBW>26600) && (RT710_Set_Info.DVBSBW<=28200))
		{
			Coarse=11;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>28200) && (RT710_Set_Info.DVBSBW<=29800))
		{
			Coarse=12;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>29800) && (RT710_Set_Info.DVBSBW<=31800))
		{
			Coarse=13;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>31800) && (RT710_Set_Info.DVBSBW<=34000))
		{
			Coarse=14;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>34000) && (RT710_Set_Info.DVBSBW<=35800))
		{
			Coarse=15;
			fine_tune=1;
		}
		else if((RT710_Set_Info.DVBSBW>35800) && (RT710_Set_Info.DVBSBW<=38000))
		{
			Coarse=16;
			fine_tune=1;
		}
	Coarse_tune = (unsigned char) Coarse;//coras filter value

	//fine tune and coras filter write
	RT710_Write_Byte.RegAddr = 0x0F;
	RT710_Read_Len.Data[15] &= 0x00;
	RT710_Reg_Arry[15] = ((RT710_Read_Len.Data[15] | ( fine_tune  ) ) | ( Coarse_tune<<2));
	RT710_Write_Byte.Data = RT710_Reg_Arry[15];
	if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;

	for(icount=0;icount<4;icount++)
	{
		R0TOR3_Write_Arry[icount]=RT710_Reg_Arry[icount];
	}
	return RT710_Success;
}




RT710_Err_Type RT710_PLL(UINT32 Freq)
{
	UINT8  MixDiv   = 2;
	UINT8  DivBuf   = 0;
	UINT8  Ni       = 0;
	UINT8  Si       = 0;
	UINT8  DivNum   = 0;
	UINT8  Nint     = 0;
	UINT32 VCO_Min  = 2350000;
	if (Freq>=2350000)
	{
		VCO_Min  = Freq;
	}
	UINT32 VCO_Max  = VCO_Min*2;
	UINT32 VCO_Freq = 0;
	UINT32 PLL_Ref	= RT710_Xtal;
	UINT32 VCO_Fra	= 0;		//VCO contribution by SDM (kHz)
	UINT16 Nsdm		= 2;
	UINT16 SDM		= 0;
	UINT16 SDM16to9	= 0;
	UINT16 SDM8to1  = 0;
	//UINT8  Judge    = 0;
	//UINT8  VCO_fine_tune = 0;

	while(MixDiv <= 4)  // 2 or 4
	{
		if(((Freq * MixDiv) >= VCO_Min) && ((Freq * MixDiv) <= VCO_Max))// Lo_Freq->Freq
		{
			DivBuf = MixDiv;
			while(DivBuf <4) // 0:VCO/4 ; 1:VCO/2
			{
				DivBuf = DivBuf << 1;
				DivNum ++;
			}
			break;
		}
		MixDiv = MixDiv << 1;
	}

	//Divider
	RT710_Write_Byte.RegAddr = 0x04;
	RT710_Reg_Arry[4] &= 0xFE;
	RT710_Reg_Arry[4] |= DivNum ;
	RT710_Write_Byte.Data = RT710_Reg_Arry[4];
	if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;

	VCO_Freq = Freq * MixDiv;		// Lo_Freq->Freq
	Nint     = (UINT8) (VCO_Freq / 2 / PLL_Ref);
	VCO_Fra  = (UINT16) (VCO_Freq - 2 * PLL_Ref * Nint);

	//boundary spur prevention
	if (VCO_Fra < PLL_Ref/64)             // 2*PLL_Ref/128
		VCO_Fra = 0;
	else if (VCO_Fra > PLL_Ref*127/64)    // 2*PLL_Ref*127/128
	{
		VCO_Fra = 0;
		Nint ++;
	}
	else if((VCO_Fra > PLL_Ref*127/128) && (VCO_Fra < PLL_Ref)) //> 2*PLL_Ref*127/256,  < 2*PLL_Ref*128/256
		VCO_Fra = PLL_Ref*127/128;      // VCO_Fra = 2*PLL_Ref*127/256
	else if((VCO_Fra > PLL_Ref) && (VCO_Fra < PLL_Ref*129/128)) //> 2*PLL_Ref*128/256,  < 2*PLL_Ref*129/256
		VCO_Fra = PLL_Ref*129/128;      // VCO_Fra = 2*PLL_Ref*129/256
	else
		VCO_Fra = VCO_Fra;

	//N & S
	Ni       = (Nint - 13) / 4;
	Si       = Nint - 4 *Ni - 13;
	RT710_Write_Byte.RegAddr = 0x05;
	RT710_Reg_Arry[5]  = 0x00;
	RT710_Reg_Arry[5] |= (Ni + (Si << 6));
	RT710_Write_Byte.Data  = RT710_Reg_Arry[5];
	if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;

	//pw_sdm
	RT710_Write_Byte.RegAddr = 0x04;
	RT710_Reg_Arry[4] &= 0xFD;
	if(VCO_Fra == 0)
		RT710_Reg_Arry[4] |= 0x02;
	RT710_Write_Byte.Data = RT710_Reg_Arry[4];
	if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;

	//SDM calculator
	while(VCO_Fra > 1)
	{
		if (VCO_Fra > (2*PLL_Ref / Nsdm))
		{
			SDM = SDM + 32768 / (Nsdm/2);
			VCO_Fra = VCO_Fra - 2*PLL_Ref / Nsdm;
			if (Nsdm >= 0x8000)
				break;
		}
		Nsdm = Nsdm << 1;
	}

	SDM16to9 = SDM >> 8;
	SDM8to1 =  SDM - (SDM16to9 << 8);

	RT710_Write_Byte.RegAddr = 0x07;
	RT710_Reg_Arry[7]   = (UINT8) SDM16to9;
	RT710_Write_Byte.Data    = RT710_Reg_Arry[7];
	if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;
	RT710_Write_Byte.RegAddr = 0x06;
	RT710_Reg_Arry[6]   = (UINT8) SDM8to1;
	RT710_Write_Byte.Data    = RT710_Reg_Arry[6];
	if(RT710_I2C_Write(&RT710_Write_Byte) != RT710_Success)
		return RT710_Fail;
    return RT710_Success;
}



RT710_Err_Type RT710_Standby( RT710_LoopThrough_Type RT710_LTSel )
{
    int i;
    int icount;

	UINT8 RT710_Standby_Reg_Arry[RT710_Reg_Num]={0xFF, 0x58, 0x88, 0x10, 0x41, 0xC8, 0xED, 0x25, 0x07, 0xFC, 0x48, 0xA2, 0x08, 0x0F, 0xF3, 0x59};

	if(RT710_LTSel == LOOP_THROUGH)
	{
		RT710_Standby_Reg_Arry[1] &=0xFB;//LOOP THROUGH ON
		RT710_Standby_Reg_Arry[1] &=0xFD;//LNA POWER ON
	}
	else
	{
		RT710_Standby_Reg_Arry[1] |=0x04;//LOOP THROUGH OFF
		RT710_Standby_Reg_Arry[1] |=0x02;//LNA POWER OFF
	}


	RT710_Write_Len.RegAddr=0x00;
	RT710_Write_Len.Len=0x10;
	for(i=0;i<RT710_Write_Len.Len;i++)
	{
		RT710_Write_Len.Data[i]=RT710_Standby_Reg_Arry[i];
	}

	if(RT710_I2C_Write_Len(&RT710_Write_Len) != RT710_Success)
		return RT710_Fail;

	R710_Initial_done_flag = FALSE;

	for(icount=0;icount<4;icount++)
	{
		R0TOR3_Write_Arry[icount]=RT710_Standby_Reg_Arry[icount];
	}


	return RT710_Success;
}

RT710_Err_Type RT710_SetInitFlag(UINT8 InitFlag)
{
    R710_Initial_done_flag = InitFlag;

    return RT710_Success;
}

RT710_Err_Type RT710_GetRfGain(RT710_RF_Gain_Info *RT710_rf_gain)
{
	I2C_LEN_TYPE Dlg_I2C_Len;
	Dlg_I2C_Len.RegAddr = 0x00;
	Dlg_I2C_Len.Len     = 0x04;
	RT710_I2C_Read_Len(&Dlg_I2C_Len) ; // read data length
	RT710_rf_gain->RF_gain = (Dlg_I2C_Len.Data[1]>>4); //get rf gain
	RT710_rf_gain->RF_gain +=((Dlg_I2C_Len.Data[1] & 0x01)<<4);

	/*0~5: mixeramp
	  6~7: mix-buf
	  29~30:mix-buf
	  other:lna
	*/
	if(Read_type == TRUE)
	{
		if (RT710_rf_gain->RF_gain <= 2)
		{
			RT710_rf_gain->RF_gain=0;
		}
		else if(RT710_rf_gain->RF_gain > 2 && RT710_rf_gain->RF_gain <= 9)
		{
			RT710_rf_gain->RF_gain -=2;
		}
		else if(RT710_rf_gain->RF_gain >9 && RT710_rf_gain->RF_gain <=12)
		{
			RT710_rf_gain->RF_gain = 7;
		}
		else if(RT710_rf_gain->RF_gain>12 && RT710_rf_gain->RF_gain <= 22)
		{
			RT710_rf_gain->RF_gain -= 5;
		}
		else if(RT710_rf_gain->RF_gain > 22)
		{
			RT710_rf_gain->RF_gain = 18;
		}
	}

	return RT710_Success;
}

//----------------------------------------------------------------------------------------//
//  RT710_GetRfRssi( ): Get RF RSSI                                     		 //
//  1st parameter: input RF Freq    (KHz)                               		//
//  2rd parameter: output signal level (dBm*1000)                       		//
//  3th parameter: output RF max gain indicator (0:min gain, 1:max gain, 2:active gain)	//
//--------------------------------------------------------------------------------------//
RT710_Err_Type RT710_GetRfRssi(UINT32 RF_Freq_Khz, INT32 *RfLevelDbm, UINT8 *fgRfGainflag)
{
	RT710_RF_Gain_Info rf_gain_info;
	UINT8  u1Gain1;
	UINT16  acc_lna_gain=0;
	UINT16  rf_total_gain;
	UINT16  u2FreqFactor;
	INT32     rf_rssi;
	INT32    fine_tune = 0;    //for find tune

	RT710_GetRfGain(&rf_gain_info);

	u1Gain1 = rf_gain_info.RF_gain;
//printf("\n[ww] u1Gain1 [%d]\n",u1Gain1);
   //max gain indicator
	if(((u1Gain1==18)&&(Read_type==TRUE))||((u1Gain1==31)&&(Read_type==FALSE)))
		*fgRfGainflag = 1;
	else if(u1Gain1==0)
		*fgRfGainflag = 0;
	else
		*fgRfGainflag = 2;

	u2FreqFactor = 0;

	//Select LNA freq table
	if(Read_type==FALSE)
	{
		u2FreqFactor = 70;
	}
	else if(RF_Freq_Khz<1200000)   //<1200M
	{
		u2FreqFactor = 190;
	}
	else if((RF_Freq_Khz>=1200000)&&(RF_Freq_Khz<1800000))   //1200~1800M
	{
		u2FreqFactor = 170;
	}
	else    // >=2000MHz
	{
		u2FreqFactor = 140;
	}

	//LNA Gain
	if(Read_type==FALSE)
		acc_lna_gain = RT710_Lna2_Acc_Gain[u1Gain1];
	else
    {
        if ((u1Gain1) < COUNTOF(RT710_Lna_Acc_Gain)) // Coverity 91227
		   acc_lna_gain = RT710_Lna_Acc_Gain[u1Gain1];
    }
//printf("[ww] acc_lna_gain [%d] Read_type %d\n",acc_lna_gain,Read_type);
	//Add Rf Buf and Mixer Gain
	rf_total_gain = acc_lna_gain;

	rf_rssi = fine_tune - (INT32) (rf_total_gain + u2FreqFactor);
	*RfLevelDbm = (rf_rssi*100) ;


    return RT710_Success;
}



MS_BOOL MDrv_DVBS_Tuner_SetFreq(MS_U16 u16CenterFreq_MHz, MS_U32 u32SymbolRate_Ks)
{
    //Set RT710_Info
    RT710_INFO_Type RT710_Info_Msg;
    RT710_Info_Msg.RT710_Freq = (u16CenterFreq_MHz * 1000); // Set RF Freq. unit: KHz
    IFfreqMHz=u16CenterFreq_MHz;
    #if 0
    #ifdef DVBS_RRPLACE_BY_SLT
    if (eBW == 0)
    {
        RT710_Info_Msg.DVBSBW = u32SymbolRate_Ks * 2; //BW = Symbol Rate * (2)
        // RT710_Info_Msg.DVBSBW = dSym_KHz * 27 / 20; //BW = Symbol Rate * (1 + Roll Off), Roll Off = 0.35
    }
    else
    {
        RT710_Info_Msg.DVBSBW = u32SymbolRate_Ks;
    }
    #elif defined DVBS2_BS_WQ
    RT710_Info_Msg.DVBSBW = u32SymbolRate_Ks;
    #else
    if (g_RT710_fIsScanning)
        RT710_Info_Msg.DVBSBW = u32SymbolRate_Ks;
    else
        RT710_Info_Msg.DVBSBW = u32SymbolRate_Ks * 27 / 20; //BW = Symbol Rate * (1 + Roll Off), Roll Off = 0.35
    #endif
    #endif
    RT710_Info_Msg.DVBSBW = u32SymbolRate_Ks * 27 / 20;//chenhongxiang@2015/04/16 Remark: For DVBS2 8-PSK can't detect!
    RT710_Info_Msg.RT710_LoopThrough_Mode = SIGLE_IN; //Set LoopThrough ON
    RT710_Info_Msg.RT710_ClockOut_Mode = ClockOutOff; //Set Clock Out
    RT710_Info_Msg.RT710_OutputSignal_Mode = SingleOut; //DifferentialOut;//SingleOut; //Modify for UCCP spectrum analyser
    RT710_Info_Msg.RT710_AGC_Mode = AGC_Negative;
    RT710_Info_Msg.RT710_AttenVga_Mode = ATTENVGAOFF;
    RT710_Info_Msg.R710_FineGain = FINEGAIN_3DB;

    //Run RT710_Setting
    if(RT710_Setting(RT710_Info_Msg) != RT710_Success)
        return RT710_Fail;

    return RT710_Success;

}

MS_BOOL MDrv_Tuner_CheckLock(void)
{
    return TRUE;
}


MS_BOOL MDrv_Tuner_Initial(void)
{
    return TRUE;
}

//  to do
MS_BOOL MDrv_DVBS_Tuner_Initial(void)
{
    return MDrv_Tuner_Initial();
}

MS_BOOL MDrv_DVBS_Tuner_CheckLock(void)
{
    return MDrv_Tuner_CheckLock();
}


//float MDrv_DVBS_Tuner_Get_RSSI(MS_U16 u16_gain)
float MDrv_DVBS_Tuner_Get_RSSI(MS_U16 u16_gain, MS_U8 Dtype)
{
       INT32 RfLevelDbm;
	UINT8 fgRfGainflag,u8Index,band=LOWBAND;
	float rf_level_dbm=0;
	RT710_GetRfRssi(IFfreqMHz*1000, &RfLevelDbm, &fgRfGainflag);
    //printf("\n[ww] 710 RFlevel [%d] \n",RfLevelDbm);
    Dtype =Dtype;
	if(IFfreqMHz<1200)   //<1200M
		band= LOWBAND;
	else if((IFfreqMHz>=1200)&&(IFfreqMHz<1800))   //1200~1800M
		band= MIDBAND;
	else    // >=2000MHz
		band= HIGHBAND;
if((band==LOWBAND && RfLevelDbm<=-59900)||
	(band==MIDBAND && RfLevelDbm<=-57900)||
	(band==HIGHBAND && RfLevelDbm<=-54900)
)
{
	  for (u8Index=0; u8Index < 3; u8Index++)
        {
              if ((65535 - u16_gain) >= _u16SignalLevel[band][u8Index][0])
             {
                 if (u8Index >=1)
                {
                      rf_level_dbm = (float)(_u16SignalLevel[band][u8Index-1][1])+(float)((65535 - u16_gain)-_u16SignalLevel[band][u8Index-1][0]) / (float)(_u16SignalLevel[band][u8Index][0] - _u16SignalLevel[band][u8Index-1][0])*(float)(_u16SignalLevel[band][u8Index][1] - _u16SignalLevel[band][u8Index-1][1]);
                 }
                 else
                 {
                      rf_level_dbm = (float)_u16SignalLevel[band][u8Index][1];
                 }
			 rf_level_dbm*=(-1);
			 if(rf_level_dbm>-57)
			 	rf_level_dbm=-57;
			 else if(rf_level_dbm<-100)
			 	rf_level_dbm=-100;
              }
         }
}
else{
	rf_level_dbm= (float)RfLevelDbm/1000;
}
    return rf_level_dbm;
}

