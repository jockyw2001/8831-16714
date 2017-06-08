#include <math.h>
#include "MsCommon.h"
#include "drvIIC.h"
#include "Board.h"
#include "drvTuner_AV2017.h"
#include "msAPI_Demod.h"
#include "msAPI_Tuner.h"

#if (FRONTEND_TUNER_S2_TYPE==AVAILINK_AV2017)

#define MAX_INPUT_FREQ 2150 //Mhz
#define MIN_INPUT_FREQ 950  //Mhz

#define  TUNER_AV2017_SLAVE_ID      0xC6
#define  TUNER_CRYSTAL_FREQ         27
static MS_U8 _u8SlaveID = TUNER_AV2017_SLAVE_ID;
static MS_U8 sCurRolloff=SAT_RO_35;
typedef struct
{
    float    LvdBm;
    MS_U16 u16_if_agc;
}S_RSSI_TABLE;

#define RSSI_ARRAY_NUM 30
/*
static S_RSSI_TABLE rssi_AV2017_131x[]=
{//19*10-4 = 186
{-92.5, 0xF253},{-92.0, 0xF1EA},{-91.5, 0xF145},{-91.0, 0xF0C8},{-90.5, 0xF05A},{-90.0, 0xEFE2},{-89.5, 0xEF2E},{-89.0, 0xEEAC},{-88.5, 0xEE34},{-88.0, 0xEDB2},
{-87.5, 0xECFE},{-87.0, 0xEC63},{-86.5, 0xEBE6},{-86.0, 0xEB28},{-85.5, 0xEA92},{-85.0, 0xE9F7},{-84.5, 0xE970},{-84.0, 0xE894},{-83.5, 0xE7E5},{-83.0, 0xE6EB},
{-82.5, 0xE62D},{-82.0, 0xE5A1},{-81.5, 0xE510},{-81.0, 0xE443},{-80.5, 0xE3A8},{-80.0, 0xE303},{-79.5, 0xE236},{-79.0, 0xE1A0},{-78.5, 0xE0EC},{-78.0, 0xE024},
{-77.5, 0xDFB6},{-77.0, 0xDF57},{-76.5, 0xDEF3},{-76.0, 0xDE67},{-75.5, 0xDDF9},{-75.0, 0xDD86},{-74.5, 0xDD2C},{-74.0, 0xDCD2},{-73.5, 0xDC73},{-73.0, 0xDC14},
{-72.5, 0xDBB5},{-72.0, 0xDB38},{-71.5, 0xDA5C},{-71.0, 0xD99E},{-70.5, 0xD8D6},{-70.0, 0xD7E6},{-69.5, 0xD728},{-69.0, 0xD660},{-68.5, 0xD584},{-68.0, 0xD4B2},
{-67.5, 0xD3F4},{-67.0, 0xD32C},{-66.5, 0xD26E},{-66.0, 0xD1C4},{-65.5, 0xD12E},{-65.0, 0xD0A7},{-64.5, 0xD03E},{-64.0, 0xCFD0},{-63.5, 0xCF71},{-63.0, 0xCF12},
{-62.5, 0xCEBD},{-62.0, 0xCE68},{-61.5, 0xCE18},{-61.0, 0xCDC8},{-60.5, 0xCD82},{-60.0, 0xCD37},{-59.5, 0xCCE2},{-59.0, 0xCC9C},{-58.5, 0xCC4C},{-58.0, 0xCBFC},
{-57.5, 0xCBAC},{-57.0, 0xCB5C},{-56.5, 0xCAEE},{-56.0, 0xCA44},{-55.5, 0xC97C},{-55.0, 0xC850},{-54.5, 0xC73D},{-54.0, 0xC670},{-53.5, 0xC5D0},{-53.0, 0xC53F},
{-52.5, 0xC4C2},{-52.0, 0xC445},{-51.5, 0xC3CD},{-51.0, 0xC350},{-50.5, 0xC2DD},{-50.0, 0xC26A},{-49.5, 0xC1DE},{-49.0, 0xC152},{-48.5, 0xC0BC},{-48.0, 0xC021},
{-47.5, 0xBF9A},{-47.0, 0xBF09},{-46.5, 0xBE73},{-46.0, 0xBE05},{-45.5, 0xBD74},{-45.0, 0xBCED},{-44.5, 0xBC70},{-44.0, 0xBBE4},{-43.5, 0xBB7B},{-43.0, 0xBAF9},
{-42.5, 0xBA6D},{-42.0, 0xB9BE},{-41.5, 0xB90A},{-41.0, 0xB838},{-40.5, 0xB77F},{-40.0, 0xB6DF},{-39.5, 0xB635},{-39.0, 0xB568},{-38.5, 0xB4C8},{-38.0, 0xB43C},
{-37.5, 0xB3C4},{-37.0, 0xB333},{-36.5, 0xB2B6},{-36.0, 0xB239},{-35.5, 0xB1A8},{-35.0, 0xB12B},{-34.5, 0xB09F},{-34.0, 0xB022},{-33.5, 0xAFA5},{-33.0, 0xAF28},
{-32.5, 0xAEB0},{-32.0, 0xAE42},{-31.5, 0xADD9},{-31.0, 0xAD75},{-30.5, 0xAD02},{-30.0, 0xAC80},{-29.5, 0xABFE},{-29.0, 0xAB77},{-28.5, 0xAB04},{-28.0, 0xAA87},
{-27.5, 0xAA1E},{-27.0, 0xA9BF},{-26.5, 0xA965},{-26.0, 0xA91A},{-25.5, 0xA8A2},{-25.0, 0xA820},{-24.5, 0xA7B2},{-24.0, 0xA753},{-23.5, 0xA6DB},{-23.0, 0xA64F},
{-22.5, 0xA5D7},{-22.0, 0xA564},{-21.5, 0xA4E7},{-21.0, 0xA82F},{-20.5, 0xA3B6},{-20.0, 0xA2F8},{-19.5, 0xA24E},{-19.0, 0xA1C7},{-18.5, 0xA145},{-18.0, 0xA096},
{-17.5, 0xA00A},{-17.0, 0x9F83},{-16.5, 0x9ED4},{-16.0, 0x9E4D},{-15.5, 0x9DD0},{-15.0, 0x9CEA},{-14.5, 0x9C72},{-14.0, 0x9BFA},{-13.5, 0x9B6E},{-13.0, 0x9ACE},
{-12.5, 0x9A60},{-12.0, 0x9A0B},{-11.5, 0x99A2},{-11.0, 0x992F},{-10.5, 0x98D0},{-10.0, 0x9871},{-9.5, 0x982B},{-9.0, 0x97D6},{-8.5, 0x9772},{-8.0, 0x9722},
{-7.5, 0x96E1},{-7.0, 0x96A5},{-6.5, 0x965A},{-6.0, 0x960A},{-5.5, 0x95B5},{-5.0, 0x9560},{-4.5, 0x951F},{-4.0, 0x94E3},{-3.5, 0x94A2},{-3.0, 0x9452},
{-2.5, 0x93F8},{-2.0, 0x939E},{-1.5, 0x934E},{-1.0, 0x9312},{-0.5, 0x92D1},{-0.0, 0x9286}
};
*/
static S_RSSI_TABLE rssi_AV2017_1240[]=
{
{-95.0,0xFF00},
{-90.0,0xFF00},
{-85.0,0x8B5C},
{-80.0,0x81DC},
{-75.0,0x7D44},
{-70.0,0x7B88},
{-65.0,0x770F},
{-60.0,0x74FB},
{-55.0,0x7256},
{-50.0,0x6C8F},
{-45.0,0x6986},
{-40.0,0x6753},
{-35.0,0x64E6},
{-30.0,0x6295},
{-25.0,0x606E},
{-20.0,0x5E5B},
{-15.0,0x5BF8},
{-10.0,0x5A1F},
{- 5.0,0x5971},
{- 0.0,0x591D},
};
MS_U8 TunerInitialSetting[2][42]=
{//test for VideoCon
    {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29},
    {0x38, 0x00, 0x00, 0x50, 0x1F, 0xA3, 0xFD, 0x58, 0x2E, 0x82, 0x88, 0xB4, 0xD6, 0x40, 0x94, 0x4A, 0x66, 0x40, 0x80, 0x2B, 0x6A, 0x50, 0x91, 0x27, 0x8F, 0xCC, 0x21, 0x10, 0x80, 0xEE, 0xF5, 0x7F, 0x4D, 0xBF, 0xE0, 0xE0, 0x2E, 0x02, 0xAB, 0x97, 0xC5, 0xA8}	
};

MS_BOOL AV2017_WriteReg(MS_U8 u8SlaveID, MS_U8 u8Addr, MS_U8 u8Data)
{
    MS_BOOL bRet=TRUE;
    MS_U8 u8Value[2];
    u8Value[0]=u8Addr;
    u8Value[1]=u8Data;
    MS_U8 addr_size =0;
//    bRet &= MDrv_IIC_Write(u8SlaveID, 0, 0, u8Value, 2);
    bRet &= MDrv_IIC_WriteBytes((U16)((DVBS_TUNER_IIC_BUS<<8)|u8SlaveID), 0, &addr_size, 2,u8Value);

	if(bRet)
	{
		//printf(" DevTuner AVL2017 Write u8Addr=[%x]=%x, Success....  \n", u8Addr, u8Data);
	}
	else
	{
		//printf(" DevTuner AVL2017 Write u8Addr=[%x]=%x, Fail...  \n", u8Addr, u8Data);
	}
    return bRet;
}
MS_BOOL AV2017_ReadReg(MS_U8 u8SlaveID, MS_U8 u8Addr, MS_U8 *u8Data)
{
    MS_BOOL bRet=TRUE;
    MS_U8 addr_data =  u8Addr;
    MS_U8 addr_size =0;
//    bRet&=MDrv_IIC_Write(u8SlaveID, 0, 0, &u8Addr, 1);
//    bRet&=MDrv_IIC_Read(u8SlaveID, 0, 0, u8Data, 1);

    bRet&= MDrv_IIC_WriteBytes((U16)((DVBS_TUNER_IIC_BUS<<8)|u8SlaveID), 0, &addr_size, 1,&addr_data);
    bRet&= MDrv_IIC_ReadBytes((U16)((DVBS_TUNER_IIC_BUS<<8)|u8SlaveID), 0, &addr_size,1,u8Data);



	if(bRet)
	{
		//printf("\r\n >>DevTuner AVL2017 Read Success.... \n");
	}
	else
	{
		//printf("\r\n >>DevTuner AVL2017 Read Fail.... \n");
	}
    return bRet;
}

void AV2017_SlaveID_Check(void)
{

#if 1
     MS_U8 regValue;

      _u8SlaveID = 0xC0;
      do
      {
          regValue=(char) (0x38);
          if(AV2017_WriteReg(_u8SlaveID,0,regValue))
          {
               regValue = 0;
               if(AV2017_ReadReg(_u8SlaveID,0,&regValue))
               {
                     if(regValue == 0x38)
                     {
                         break;
                     }
               }
          }
          _u8SlaveID += 0x02;
      } while(_u8SlaveID <= 0xC6);
      if(_u8SlaveID > 0xC6)
      {
           _u8SlaveID = TUNER_AV2017_SLAVE_ID;
      }
#else
      _u8SlaveID = TUNER_AV2017_SLAVE_ID;

#endif

      //printf("\r\n DVBS TUNER SLAVE ID = %x", _u8SlaveID);
}

MS_BOOL MDrv_Tuner_Initial(void)
{
    MS_BOOL bRet=TRUE;
    MS_U8 index_temp; //ohya++ modyify 20130802


    AV2017_SlaveID_Check();

    for (index_temp=0; index_temp < 12; index_temp++)
    {
        bRet&=AV2017_WriteReg(_u8SlaveID, TunerInitialSetting[0][index_temp], TunerInitialSetting[1][index_temp]);
    }
    MsOS_DelayTask(1);
    for (index_temp=13; index_temp < 42; index_temp++)
    {
        bRet&=AV2017_WriteReg(_u8SlaveID, TunerInitialSetting[0][index_temp], TunerInitialSetting[1][index_temp]);
    }
    MsOS_DelayTask(1);
    bRet&=AV2017_WriteReg(_u8SlaveID, TunerInitialSetting[0][12], TunerInitialSetting[1][12]);
    MsOS_DelayTask(100);
    for (index_temp=0; index_temp < 12; index_temp++)
    {
        bRet&=AV2017_WriteReg(_u8SlaveID, TunerInitialSetting[0][index_temp], TunerInitialSetting[1][index_temp]);
    }
    MsOS_DelayTask(1);
    for (index_temp=13; index_temp < 42; index_temp++)
    {
        bRet&=AV2017_WriteReg(_u8SlaveID, TunerInitialSetting[0][index_temp], TunerInitialSetting[1][index_temp]);
    }
    MsOS_DelayTask(1);
    bRet&=AV2017_WriteReg(_u8SlaveID, TunerInitialSetting[0][12], TunerInitialSetting[1][12]);
    MsOS_DelayTask(50);
    return bRet;
}

MS_BOOL MDrv_Tuner_SetFreq(MS_U16 u16CenterFreq, MS_U32 u32SymbolRate_Hz)
{
    MS_BOOL bRet=TRUE;
    MS_BOOL bAutoScan=FALSE;
    MS_U32 u32FracN;
    MS_U32 BW;
    MS_U32 BF;
    MS_U8 u8Reg[8];
    MS_U8 u8RolloffFacter = 135;

    DEBUG_DEMOD_S( printf("AV2017 tuner setFreq(u16CenterFreq=%u, u32SymbolRate_Hz=%u)\n",u16CenterFreq, u32SymbolRate_Hz ); );
    if((u16CenterFreq > MAX_INPUT_FREQ) || (u16CenterFreq < MIN_INPUT_FREQ)){
        printf("center frequency  setting is out of range   [ %d : %d] \n",MIN_INPUT_FREQ,MAX_INPUT_FREQ);
        return FALSE;

    }
    //printf("Funs=%s, line=%d, u16CenterFreq=%ld, \n",__FUNCTION__,__LINE__, u16CenterFreq);
    //printf("Funs=%s, line=%d, u32SymbolRate_Hz=%ld, \n",__FUNCTION__,__LINE__, u32SymbolRate_Hz);
    if (u32SymbolRate_Hz == 0 || u32SymbolRate_Hz == 45000) //auto-scan mode
    {
	    bAutoScan = TRUE;
    }
    MsOS_DelayTask(50);
    u32FracN = (u16CenterFreq + TUNER_CRYSTAL_FREQ/2)/TUNER_CRYSTAL_FREQ;
    if(u32FracN > 0xff)
    {
   	   u32FracN = 0xff;
    }
    u8Reg[0]=(MS_U8) (u32FracN & 0xff);
    u32FracN = (u16CenterFreq<<17)/TUNER_CRYSTAL_FREQ;
    u32FracN = (u32FracN & 0x1ffff);
    u8Reg[1]=(MS_U8) ((u32FracN>>9)&0xff);
    u8Reg[2]=(MS_U8) ((u32FracN>>1)&0xff);
    u8Reg[3]=(MS_U8) (((u32FracN<<7)&0x80) | 0x50); // default is 0x50
    // Channel Filter Bandwidth Setting.
    if(bAutoScan==TRUE)//requested by BB
    {
        u8Reg[5] = 0xA3; //BW=27MHz
    }
    else
    {
        // rolloff is 35%
        //BW = u32SymbolRate_Hz*135/200;
        switch(sCurRolloff)
        {
            case SAT_RO_35:
                u8RolloffFacter = 135;
                break;
            case SAT_RO_25:
                u8RolloffFacter = 125;
                break;
            case SAT_RO_20:
                u8RolloffFacter = 120;
                break;
        }
        //u8RolloffFacter = 135;
        BW = u32SymbolRate_Hz*u8RolloffFacter/200;
        // monsen 20080726, BB request low IF when sym < 6.5MHz
        // add 6M when Rs<6.5M,
        if(u32SymbolRate_Hz<6500)
        {
            BW = BW + 6000;
        }
        // add 2M for LNB frequency shifting
        BW = BW + 2000;
        // add 8% margin since fc is not very accurate
        BW = BW*108/100;
        // Bandwidth can be tuned from 4M to 40M
        if( BW< 4000)
        {
            BW = 4000;
        }
        if( BW> 40000)
        {
            BW = 40000;
        }
        BF = (BW*127 + 21100/2) / (21100); // BW(MHz) * 1.27 / 211KHz
        u8Reg[5] = (MS_U8)BF;
    }
    // Sequence 4
    // Send Reg0 ->Reg4
    MsOS_DelayTask(5);
    bRet&=AV2017_WriteReg(_u8SlaveID, 0x00, u8Reg[0]);
    bRet&=AV2017_WriteReg(_u8SlaveID, 0x01, u8Reg[1]);
    bRet&=AV2017_WriteReg(_u8SlaveID, 0x02, u8Reg[2]);
    bRet&=AV2017_WriteReg(_u8SlaveID, 0x03, u8Reg[3]);

    MsOS_DelayTask(5);
    // Sequence 5
    // Send Reg5
    bRet&=AV2017_WriteReg(_u8SlaveID, 0x05, u8Reg[5]);
    MsOS_DelayTask(5);
    // Fine-tune Function Control
    //Tuner fine-tune gain function block. bit2.
    //not auto-scan case. enable block function. FT_block=1, FT_EN=1
    if (bAutoScan==FALSE)
    {
         u8Reg[6] = 0x06;
         bRet&=AV2017_WriteReg(_u8SlaveID, 0x25, u8Reg[6]);
         MsOS_DelayTask(5);
         //Disable RFLP at Lock Channel sequence after reg[37]
         //RFLP=OFF at Lock Channel sequence
         // RFLP can be Turned OFF, only at Receving mode.
         u8Reg[7] = 0xD6;
         bRet&=AV2017_WriteReg(_u8SlaveID, 0x0C, u8Reg[7]);
    }
    return bRet;
}

MS_BOOL MDrv_Tuner_CheckLock(void)
{
    MS_BOOL bRet=TRUE;
    MS_U8 u8Data=FALSE;

    bRet&=AV2017_ReadReg(_u8SlaveID, 0x0B, &u8Data);
    if (bRet==FALSE)
    {
        return bRet;
    }
    else
    {
        if ((u8Data&0x03)!=0x03)
        {
            bRet=FALSE;
        }
    }
    //printf("\r\n =============>> Tuner Status 0x%x,bRet = %d\n", u8Data,bRet);
    return bRet;
}

MS_BOOL MDrv_DVBS_Tuner_SetFreq(MS_U16 u16CenterFreq_MHz, MS_U32 u32SymbolRate_Ks)
{
    return MDrv_Tuner_SetFreq(u16CenterFreq_MHz, u32SymbolRate_Ks);
}
MS_BOOL MDrv_DVBS_Tuner_Initial(void)
{
    return MDrv_Tuner_Initial();
}
MS_BOOL MDrv_DVBS_Tuner_CheckLock(void)
{
    return MDrv_Tuner_CheckLock();
}
// input IF_AGC,
// return dBm.
float MDrv_DVBS_Tuner_Get_RSSI(MS_U16 u16_gain)
{
    MS_U8 indx = 0;
    MS_U8 arry_size = 0;
    float rf_dbm = 0.0;
    S_RSSI_TABLE *rssi_AV2017;

#if 1  //demod 1240
    arry_size = sizeof(rssi_AV2017_1240)/sizeof(S_RSSI_TABLE);
    rssi_AV2017 = rssi_AV2017_1240;
#else  //demod 131x
    arry_size = sizeof(rssi_AV2017_131x)/sizeof(S_RSSI_TABLE);
    rssi_AV2017 = rssi_AV2017_131x;
#endif


    // printf("array_size = %d, gain=0x%x\n",arry_size,u16_gain);
    if (u16_gain > rssi_AV2017[0].u16_if_agc)
    {
        rf_dbm = (float)(u16_gain - rssi_AV2017[1].u16_if_agc)/(float)(rssi_AV2017[0].u16_if_agc - rssi_AV2017[1].u16_if_agc)*(rssi_AV2017[0].LvdBm - rssi_AV2017[1].LvdBm)+rssi_AV2017[1].LvdBm;
    }
    else if (u16_gain <= rssi_AV2017[arry_size-1].u16_if_agc)
    {
        rf_dbm = (float)(u16_gain - rssi_AV2017[arry_size-2].u16_if_agc)/(float)(rssi_AV2017[arry_size-1].u16_if_agc - rssi_AV2017[arry_size-2].u16_if_agc)*(rssi_AV2017[arry_size-1].LvdBm - rssi_AV2017[arry_size-2].LvdBm)+rssi_AV2017[arry_size-2].LvdBm;
    }
    else
    {
        for(indx = 0;indx<arry_size;indx++)
        {
            if (u16_gain > rssi_AV2017[indx].u16_if_agc) break;
        }
        if(indx < arry_size)
        {
            rf_dbm = (float)(u16_gain - rssi_AV2017[indx].u16_if_agc)/(float)(rssi_AV2017[indx-1].u16_if_agc - rssi_AV2017[indx].u16_if_agc)*(rssi_AV2017[indx-1].LvdBm - rssi_AV2017[indx].LvdBm)+rssi_AV2017[indx].LvdBm;
        }
    }

    // printf("gain=0x%x,rf_dbm=%f, indx=%d, arry_size=%d\n",u16_gain,rf_dbm,indx,arry_size);

    return rf_dbm;
}

#endif
