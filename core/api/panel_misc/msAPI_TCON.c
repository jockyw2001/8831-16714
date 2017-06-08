

#include "Board.h"

#include "Panel.h"

#if( ENABLE_TCON_2014 )

#include "BinInfo.h"
#include "SysInit.h"

#include "Utl.h"

#include "msAPI_BDMA.h"
#include "msAPI_PnlBin.h"
#include "msAPI_TCON.h"




#define DEBUG_TCON(x)       //x

#define DEBUG_PRINT_REG     0//1

#define TCON_WRITE_REG(addr, mask, val)   MDrv_WriteByteMask((addr),(val),(mask))

#define _TCON_BANK_BACKUP()     //U8 u8TConBankBackup = MDrv_ReadByte(REG_23FE);
#define _TCON_BANK_RESTORE()    //MDrv_WriteByte(REG_23FE, u8TConBankBackup)

//======================================================================
//#define ENABLE_TCON_BIN 1

#define TCON_USE_SWDB   0

//---------------------------------------------------------------------------

//#define MAKEU16(ptr, x) (U16)((ptr)[(x)] + ((ptr)[(x)+1] << 8))
//#define MAKEU32(ptr, x) (U32)((ptr)[(x)] + ((ptr)[(x)+1] << 8) + ((ptr)[(x)+2] << 16) + ((ptr)[(x)+3] << 24))
#define MAKEU16_BIG(ptr, x) (U16)((ptr)[(x)+1] + ((ptr)[(x)+0] << 8))
#define MAKEU32_BIG(ptr, x) (U32)((ptr)[(x)+3] + ((ptr)[(x)+2] << 8) + ((ptr)[(x)+1] << 16) + ((ptr)[(x)+0] << 24))

//---------------------------------------------------------------------------

//#define TCON_CHANGE_SETTING_NONE        0
//#define TCON_CHANGE_SETTING_START       1
//#define TCON_CHANGE_SETTING_WAIT_UPDATE 2
//#define TCON_CHANGE_SETTING_DONE        3

//static U8 s_TCON_u8ChangeSettingState = TCON_CHANGE_SETTING_NONE;

//---------------------------------------------------------------------------

typedef enum
{
    TCON_TABTYPE_GENERAL        = 0,
    TCON_TABTYPE_GPIO           = 1,
    TCON_TABTYPE_SCALER         = 2,
    TCON_TABTYPE_MOD            = 3,
    TCON_TABTYPE_GAMMA          = 4,
    TCON_TABTYPE_POWER_SEQUENCE_ON = 5,
    TCON_TABTYPE_POWER_SEQUENCE_OFF = 6,
} E_TCON_SUB_TAB_TYPE;

typedef enum
{
    TCON_REG_TYPE__6BYTE = 0,
    TCON_REG_TYPE__4BYTE = 1,

} E_TCON_REG_TYPE;

typedef struct STRCUT_PACK
{
    U8 u8SubTableType;  // TCON Sub-Table type
    U16 u16RegCount;    // Register count
    U8 u8RegType;       // Register type
    U32 u32RegListOffset; // Register offset
} STRU_TCON_SUB_TABLE_INFO;

//---------------------------------------------------------------------------

//static U32 g_Tcon_Reset_u32Time = 0;
//static U32 g_Tcon_Reset_u32VCnt = 0;
static BOOL g_Tcon_bInitDone = 0;

static BOOL s_TCON_BIN_bInitDone = 0;

static U32 s_TCON_BIN_u32MemAddr;

#define TCON_BIN_SIZE_MAX   12000
static U8 s_TCON_BIN_au8BinData[TCON_BIN_SIZE_MAX] = {0};


#define TCON_BIN_TBL_2D 0
#define TCON_BIN_TBL_3D 1
static U8 s_TCON_BIN_u8TblNum[2] = {0,0}; // 2D, 3D

//======================================================================

#define BIN_DATA_OFFSET_PNL_BIN_HEADER      0
#define BIN_DATA_OFFSET_TCON_BIN_HEADER     (BIN_DATA_OFFSET_PNL_BIN_HEADER+PNL_BIN_HEADER_SIZE)

#define BIN_DATA_OFFSET_TCON_2D_TBL_NUM     (BIN_DATA_OFFSET_TCON_BIN_HEADER+0)
#define BIN_DATA_OFFSET_TCON_3D_TBL_NUM     (BIN_DATA_OFFSET_TCON_BIN_HEADER+1)

#define BIN_DATA__TCON_SUB_TBL_INFO_SIZE    8
#define BIN_DATA__TCON_SUB_TBL_INFO_NUM     7 // Every tcon-table has 7 sub-table

#define BIN_DATA__TCON_SUB_TBL_INFO_ALL_SIZE    (BIN_DATA__TCON_SUB_TBL_INFO_SIZE*BIN_DATA__TCON_SUB_TBL_INFO_NUM) // 8 X 7

#define BIN_DATA_OFFSET_TCON_SUB_TBL_START  (BIN_DATA_OFFSET_TCON_BIN_HEADER+8)

U32 MDrv_TCON_BIN_Get_SubTableOffset(BOOL bIs3D, U8 u8TblIdx, U8 u8SubTblIdx)
{
    if( u8SubTblIdx >= BIN_DATA__TCON_SUB_TBL_INFO_NUM )
    {
        printf("\nError: u8SubTblIdx=%u is wrong!\n", u8SubTblIdx);
        u8SubTblIdx = 0;
        return 0;
    }

    if( bIs3D )
    {
        if( u8TblIdx >= s_TCON_BIN_u8TblNum[TCON_BIN_TBL_3D] )
        {
            printf("\nError: u8TblIdx=%u is wrong!\n", u8TblIdx);
            u8TblIdx = 0;
            return 0;
        }

        // 3D is after 2D, so add 2d sub table size
        u8TblIdx += s_TCON_BIN_u8TblNum[TCON_BIN_TBL_2D];
    }
    else
    {
        if( u8TblIdx >= s_TCON_BIN_u8TblNum[TCON_BIN_TBL_2D] )
        {
            printf("\nError: u8TblIdx=%u is wrong!\n", u8TblIdx);
            u8TblIdx = 0;
            return 0;
        }
    }

    return BIN_DATA_OFFSET_TCON_SUB_TBL_START
            + (u8TblIdx*BIN_DATA__TCON_SUB_TBL_INFO_ALL_SIZE)
            + (u8SubTblIdx*BIN_DATA__TCON_SUB_TBL_INFO_SIZE);
}

BOOL MDrv_TCON_BIN_Get_SubTableInfo(BOOL bIs3D, U8 u8TblIdx, U8 u8SubTblIdx,
                                        STRU_TCON_SUB_TABLE_INFO* pstTCON_SUB_TABLE_INFO)
{
    U32 u32SubTableOffset;

    u32SubTableOffset = MDrv_TCON_BIN_Get_SubTableOffset(bIs3D, u8TblIdx, u8SubTblIdx);

    if( u32SubTableOffset == 0 )
    {
        return FALSE;
    }

    memcpy(pstTCON_SUB_TABLE_INFO,
        &(s_TCON_BIN_au8BinData[u32SubTableOffset]),
        sizeof(STRU_TCON_SUB_TABLE_INFO) );

    return TRUE;
}

BOOL MDrv_TCON_BIN_Init(void)
{
    BININFO BinInfo;
    BOOLEAN bResult;
    STRU_PNL_BIN_HEADER stPnlBinHeader;
    U16 u16BinChecksum = 0;
    //U32 i;


    DEBUG_TCON( printf("MDrv_TCON_BIN_Init()\n"););

    BinInfo.B_ID = (U32)BIN_ID_TCON;
    MDrv_Sys_Get_BinInfo(&BinInfo, &bResult);
    if ( bResult != PASS)
    {
         printf( "could not find TCON binary on flash.\n" );
         return FALSE;
    }
    DEBUG_TCON( printf(" B_FAddr=0x%x\n", BinInfo.B_FAddr ); );
    DEBUG_TCON( printf(" B_Len=0x%x\n", BinInfo.B_Len); );
    //DEBUG_TCON( printf(" B_IsComp=0x%x\n", BinInfo.B_IsComp); );

#if 0//( ENABLE_BIN_DATA_FROM_DRAM )
    s_TCON_BIN_u32MemAddr = BIN_GROUP_MEM_ADR + BinInfo.B_FAddr - MDrv_BinInfo_Get_BinData_FlashAddrStart();

    DEBUG_TCON( printf("s_TCON_BIN_u32MemAddr=%x\n", s_TCON_BIN_u32MemAddr); );

#else

    //check bin length
    if( BinInfo.B_Len > TCON_BIN_SIZE_MAX)
    {
        printf("\n!!ERROR!! !Load TCON table is too biggggg!\n");
        return FALSE;
    }

    s_TCON_BIN_u32MemAddr = MsOS_VA2PA((U32)s_TCON_BIN_au8BinData); //TCON_TBL_ADR;

    DEBUG_TCON(printf(" s_TCON_BIN_au8BinData=0x%x\n", (U32)s_TCON_BIN_au8BinData);)
    DEBUG_TCON(printf(" s_TCON_BIN_u32MemAddr=0x%x\n", s_TCON_BIN_u32MemAddr);)

    if( !MDrv_DMA_LoadBin(&BinInfo, _PA2VA((U32)(s_TCON_BIN_u32MemAddr)), 0, 0) )
    {
        printf("\n!!ERROR!! !Load TCONtable Fail!\n");
        return FALSE;
    }
#endif

    //if (Get_BinHeader(&TCON_BinHeader, s_TCON_BIN_u32MemAddr))
    if( msAPI_PNL_BIN_Get_BinHeader( &(s_TCON_BIN_au8BinData[BIN_DATA_OFFSET_PNL_BIN_HEADER]), &stPnlBinHeader) )
    {
        DEBUG_TCON(printf(" BIN_ID=0x%x", stPnlBinHeader.u16BinID);)
        DEBUG_TCON(printf(" CUS_ID=0x%x", stPnlBinHeader.u16CustomerID);)
        DEBUG_TCON(printf(" CHKSUM=0x%x", stPnlBinHeader.u16BinChecksum);)
        DEBUG_TCON(printf(" Data_Len=0x%x\n", stPnlBinHeader.u32Data_Len);)
    }
    else
    {
        printf("\nError: Get_PnlBinHeader fail!\n");
        return FALSE;
    }

    // Check bin id
    if( (stPnlBinHeader.u16BinID < PNL_BIN_ID_TCON_START)
      ||(stPnlBinHeader.u16BinID > PNL_BIN_ID_TCON_END)
      )
    {
        printf( "\nError! Tcon bin header-id(0x%X) is wrong\n", stPnlBinHeader.u16BinID);
        return FALSE;
    }

    // Check data size
    if( stPnlBinHeader.u32Data_Len + PNL_BIN_HEADER_SIZE > BinInfo.B_Len )
    {
        printf( "\nError! Tcon bin data-len=(0x%X) is wrong\n", stPnlBinHeader.u32Data_Len);
        return FALSE;
    }

    // Check checksum
    u16BinChecksum = msAPI_PNL_BIN_Cal_Checksum(s_TCON_BIN_au8BinData, stPnlBinHeader.u32Data_Len + PNL_BIN_HEADER_SIZE);
    if( u16BinChecksum != stPnlBinHeader.u16BinChecksum )
    {
        //printf(" u16BinChecksum=0x%X\n", u16BinChecksum);
        printf( "\nError! Tcon bin checksum is wrong!(%X,%X)\n", stPnlBinHeader.u16BinChecksum, u16BinChecksum);
        return FALSE;
    }

    s_TCON_BIN_u8TblNum[TCON_BIN_TBL_2D] = s_TCON_BIN_au8BinData[BIN_DATA_OFFSET_TCON_2D_TBL_NUM];
    s_TCON_BIN_u8TblNum[TCON_BIN_TBL_3D] = s_TCON_BIN_au8BinData[BIN_DATA_OFFSET_TCON_3D_TBL_NUM];
    DEBUG_TCON(printf(" s_TCON_BIN_u8TblNum=%u,%u\n", s_TCON_BIN_u8TblNum[0], s_TCON_BIN_u8TblNum[1]););

#if 0
{
    STRU_TCON_SUB_TABLE_INFO stTCON_SUB_TABLE_INFO;
    U8 i;

    for( i = 0; i < 7; ++ i )
    {
        MDrv_TCON_BIN_Get_SubTableInfo(0, 0, i, &stTCON_SUB_TABLE_INFO );

        printf(" i=%u\n", i );

        printf("  u8SubTableType=%u\n", stTCON_SUB_TABLE_INFO.u8SubTableType );
        printf("  u16RegCount=%u\n", stTCON_SUB_TABLE_INFO.u16RegCount );
        printf("  u8RegType=%u\n", stTCON_SUB_TABLE_INFO.u8RegType );
        printf("  u32RegListOffset=0x%X\n", stTCON_SUB_TABLE_INFO.u32RegListOffset );
    }
}
#endif


    s_TCON_BIN_bInitDone = TRUE;

    return TRUE;
}

// address: 4 Byte (Big Endian)
// mask:    1 Byte
// value:   1 Byte
void MDrv_TCON_BIN_DownloadTbl_Reg_6Byte(U8* pu8RegTable, U16 u16RegCount)
{
    U32 u32RegAddr;
    U8 u8Mask;
    U8 u8Value;
    U16 i;
    U8 u8TconBank = 0xFF;


    DEBUG_TCON( printf("MDrv_TCON_BIN_DownloadTbl_Reg_6Byte(u16RegCount=%u)\n", u16RegCount); );

    for( i = 0; i < u16RegCount; ++ i )
    {
        u32RegAddr = MAKEU32_BIG(pu8RegTable, 0);
        u8Mask = pu8RegTable[4];
        u8Value = pu8RegTable[5];

        if( u32RegAddr == 0x103000 )
        {
            u8TconBank = u8Value;
        }

    #if(DEBUG_PRINT_REG)
        if( (u32RegAddr&0xFFFF00) == 0x103000 )
            printf("(%u) %02X %06X,%02X,%02X\n", i, u8TconBank, u32RegAddr, u8Mask, u8Value);
        else
            printf("(%u)  %06X,%02X,%02X\n", i, u32RegAddr, u8Mask, u8Value);
    #endif

        TCON_WRITE_REG(u32RegAddr, u8Mask, u8Value);

        pu8RegTable += 6;
    }
}

// address: 2 Byte (Big Endian)
// mask:    1 Byte
// value:   1 Byte
void MDrv_TCON_BIN_DownloadTbl_Reg_4Byte(U8* pu8RegTable, U16 u16RegCount)
{
    U32 u32RegAddr;
    U8 u8Mask;
    U8 u8Value;
    U16 i;


    DEBUG_TCON( printf("MDrv_TCON_BIN_DownloadTbl_Reg_4Byte(u16RegCount=%u)\n", u16RegCount); );

    for( i = 0; i < u16RegCount; ++ i )
    {
        u32RegAddr = MAKEU16_BIG(pu8RegTable, 0);
        u8Mask = pu8RegTable[2];
        u8Value = pu8RegTable[3];

    #if(DEBUG_PRINT_REG)
        printf("(%u) %06X,%02X,%02X\n", i, u32RegAddr, u8Mask, u8Value);
    #endif

        TCON_WRITE_REG(u32RegAddr, u8Mask, u8Value);

        pu8RegTable += 4;
    }
}

void MDrv_TCON_BIN_DownloadSubTable(STRU_TCON_SUB_TABLE_INFO* pstTCON_SUB_TABLE_INFO)
{
    U8* pu8RegTable;
    U8 u8SubTableType;
    U16 u16RegCount;


    DEBUG_TCON( printf("MDrv_TCON_BIN_DownloadSubTable()\n"); );

    if( pstTCON_SUB_TABLE_INFO == NULL )
        return;

    u8SubTableType = pstTCON_SUB_TABLE_INFO->u8SubTableType;
    u16RegCount = pstTCON_SUB_TABLE_INFO->u16RegCount;
    DEBUG_TCON( printf("  u8SubTableType=%u\n", u8SubTableType ); );
    DEBUG_TCON( printf("  u16RegCount=%u\n", u16RegCount ); );

    if( u16RegCount == 0 )
    {
        DEBUG_TCON( printf(" => Empty sub table\n"); );
        return;
    }

    DEBUG_TCON( printf("   u8RegType=%u\n", pstTCON_SUB_TABLE_INFO->u8RegType ); );
    DEBUG_TCON( printf("   u32RegListOffset=0x%X\n", pstTCON_SUB_TABLE_INFO->u32RegListOffset ); );


    pu8RegTable = &(s_TCON_BIN_au8BinData[pstTCON_SUB_TABLE_INFO->u32RegListOffset]);

    switch( u8SubTableType )
    {
        default:
            printf("\nError: Unsupported tcon u8SubTableType=%u\n", u8SubTableType);
            break;

        case TCON_TABTYPE_GENERAL:
        case TCON_TABTYPE_GPIO:
        case TCON_TABTYPE_SCALER:
        case TCON_TABTYPE_MOD:
            if( pstTCON_SUB_TABLE_INFO->u8RegType == TCON_REG_TYPE__6BYTE )
            {
                MDrv_TCON_BIN_DownloadTbl_Reg_6Byte(pu8RegTable, u16RegCount );
            }
            else if( pstTCON_SUB_TABLE_INFO->u8RegType == TCON_REG_TYPE__4BYTE )
            {
                MDrv_TCON_BIN_DownloadTbl_Reg_4Byte(pu8RegTable, u16RegCount );
            }
            else
            {
                printf("\nError: Unsupported tcon reg-type=%u!\n", pstTCON_SUB_TABLE_INFO->u8RegType);
            }
            break;
    }

}

BOOL MDrv_TCON_BIN_SwitchTable(BOOL bIs3D, U8 u8TblIdx)
{
    STRU_TCON_SUB_TABLE_INFO stTCON_SUB_TABLE_INFO;
    U8 i;


    DEBUG_TCON(printf("MDrv_TCON_BIN_SwitchTable(bIs3D=%u, u8TblIdx=%u)\n", bIs3D, u8TblIdx););

    if( s_TCON_BIN_bInitDone == 0 )
    {
        printf("\nError: TCON BIN is not init!\n");
        return FALSE;
    }

    for( i = 0; i < BIN_DATA__TCON_SUB_TBL_INFO_NUM; ++ i )
    {
        //printf(" i=%u\n", i );

        if( FALSE == MDrv_TCON_BIN_Get_SubTableInfo(bIs3D, u8TblIdx, i, &stTCON_SUB_TABLE_INFO ) )
        {
            break;
        }

        //printf("  u8SubTableType=%u\n", stTCON_SUB_TABLE_INFO.u8SubTableType );
        //printf("  u16RegCount=%u\n", stTCON_SUB_TABLE_INFO.u16RegCount );
        //printf("  u8RegType=%u\n", stTCON_SUB_TABLE_INFO.u8RegType );
        //printf("  u32RegListOffset=0x%X\n", stTCON_SUB_TABLE_INFO.u32RegListOffset );

        MDrv_TCON_BIN_DownloadSubTable(&stTCON_SUB_TABLE_INFO);
    }

    return TRUE;
}

void MDrv_TCON_ChangeSetting_Start(void)
{
#if 0
    if( s_TCON_u8ChangeSettingState == TCON_CHANGE_SETTING_WAIT_UPDATE )
    {
        printf("\nError: TCON_ChangeSetting_Start: state=WAIT_UPDATE\n");
        return;
    }

    s_TCON_u8ChangeSettingState = TCON_CHANGE_SETTING_START;

    _TCON_BANK_BACKUP();

    //printf("MDrv_TCON_ChangeSetting_Start() at %u\n", MsOS_GetSystemTime());

    MDrv_WriteByte(REG_23FE,0x0); //switch to sub bank 0

#if TCON_USE_SWDB
    MDrv_WriteRegBit(REG_2313,0,BIT7);
#else
    MDrv_Write2ByteMask(REG_2312,  BIT13, (_BIT15|BIT13)); //  Disable para update, En DB
#endif

    _TCON_BANK_RESTORE();
#endif
}

void MDrv_TCON_ChangeSetting_End(void)
{
#if 0
    if( s_TCON_u8ChangeSettingState != TCON_CHANGE_SETTING_START )
    {
        printf("\nError: TCON_ChangeSetting_End: state!=START\n");
        return;
    }

    //printf("MDrv_TCON_ChangeSetting_End() at %u\n", MsOS_GetSystemTime());

#if TCON_USE_SWDB

    s_TCON_u8ChangeSettingState = TCON_CHANGE_SETTING_WAIT_UPDATE;

#else

    _TCON_BANK_BACKUP();

    MDrv_WriteByte(REG_23FE, 0x0); //switch to sub bank 0
    MDrv_Write2Byte(REG_2312, BIT15      |BIT13); // tcon frame counter reset

    _TCON_BANK_RESTORE();

    s_TCON_u8ChangeSettingState = TCON_CHANGE_SETTING_DONE;

    if( g_Tcon_Reset_u32Time == 0 ) // First time reset
    {
        g_Tcon_Reset_u32Time = MsOS_GetSystemTime();
        g_Tcon_Reset_u32VCnt = MDrv_ISR_Get_VSyncCount();

      #if 0//( ENABLE_AUO_POWER_ON_SEQ )
        Cus_AUO_PwrSeq_TConResetDone();
      #endif
    }

#endif

#endif
}

#if 0//TCON_USE_SWDB
#define PREVIOUS_WAIT_VSYNC_NUM 1
#define WAIT_VSYNC_NUM          (4+PREVIOUS_WAIT_VSYNC_NUM)

void MDrv_TCON_VSync_ISR(void)
{
    static U8 su8_Tcon_u8WaitVSyncCount = 0;

    if( s_TCON_u8ChangeSettingState == TCON_CHANGE_SETTING_WAIT_UPDATE )
    {
        _TCON_BANK_BACKUP();

        MDrv_WriteByte(REG_23FE,0x0);//switch to sub bank 0

        su8_Tcon_u8WaitVSyncCount++;

        if (su8_Tcon_u8WaitVSyncCount == PREVIOUS_WAIT_VSYNC_NUM)
        {
            MDrv_WriteRegBit(REG_2313, BIT7,   BIT7  );//[15]
            MDrv_WriteRegBit(REG_2313, BIT6,   BIT6  );//[14]
        }
        else if(su8_Tcon_u8WaitVSyncCount == WAIT_VSYNC_NUM)
        {
            MDrv_WriteRegBit(REG_2313, 0x0,   BIT7  );//[15]
            MDrv_WriteRegBit(REG_2313, 0x0,   BIT6  );//[14]

            if( g_Tcon_Reset_u32Time == 0 ) // First time reset
            {
                g_Tcon_Reset_u32Time = MsOS_GetSystemTime();
                g_Tcon_Reset_u32VCnt = MDrv_ISR_Get_VSyncCount();

            #if 0//( ENABLE_AUO_POWER_ON_SEQ )
                Cus_AUO_PwrSeq_TConResetDone();
            #endif
            }
            s_TCON_u8ChangeSettingState = TCON_CHANGE_SETTING_DONE;
            su8_Tcon_u8WaitVSyncCount = 0;
        }

        _TCON_BANK_RESTORE();
    }
}
#endif

BOOL MDrv_TCON_SwitchTable(BOOL bIs3D, U8 u8TblIdx)
{
    BOOL bResult = TRUE;

    DEBUG_TCON(printf("MDrv_TCON_SwitchTable(bIs3D=%u, u8TblIdx=%u)\n", bIs3D, u8TblIdx););

    if( g_Tcon_bInitDone == 0 )
    {
        printf("\nError: TCON is not init!\n");
        return FALSE;
    }

#if 1
    MDrv_TCON_ChangeSetting_Start();

    //MDrv_Pnl_LoadTconSetting(bIs3D); // Load 2D setting

#if 1//(ENABLE_TCON_BIN)
    bResult = MDrv_TCON_BIN_SwitchTable( bIs3D, u8TblIdx);
#else
    MDrv_TCON_ChangeSetting_End();
#endif

#endif

    return bResult;
}

BOOL MDrv_TCON_Init(void)
{
    BOOL bResult = TRUE;


    DEBUG_TCON( printf("MDrv_TCON_Init()\n"); );
    printf("MDrv_TCON_Init()\n");

    //g_Tcon_Reset_u32Time = 0;
    //g_Tcon_Reset_u32VCnt = 0;

    //s_TCON_u8ChangeSettingState = TCON_CHANGE_SETTING_NONE;

#if 1//(ENABLE_TCON_BIN)
    if( FALSE == MDrv_TCON_BIN_Init() )
    {
        printf("\nError: MDrv_TCON_Init() failed\n");
        return FALSE;
    }
#endif

    g_Tcon_bInitDone = TRUE;

    MDrv_TCON_SwitchTable(0, 0); // Load 2D setting

    return bResult;
}

BOOL msAPI_TCON_Init(void)
{
    BOOL bResult = TRUE;


    bResult = MDrv_TCON_Init();

    if( bResult == FALSE )
    {
        MsOS_DelayTask(5000);
    }

    //while(1){}

    return bResult;
}

BOOL msAPI_TCON_LoadTable(BOOL bIs3D)
{
    return MDrv_TCON_SwitchTable(bIs3D, 0);
}

#endif

