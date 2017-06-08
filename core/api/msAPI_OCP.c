//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (MStar Confidential Information!L) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MSAPI_OCP_C

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "MsCommon.h"
#include "MsIRQ.h"
#include "MsOS.h"

#include "datatype.h"

#include "apiGOP.h"
#include "msAPI_OSD.h"
#include "msAPI_Memory.h"
#include "msAPI_Font.h"
#include "msAPI_Timer.h"
#include "msAPI_DrvInit.h"
#include "drvSERFLASH.h"
#include "debug.h"
#include "msAPI_MIU.h"
#include "ms_decompress.h"
#include "msAPI_OSD_Resource.h"
#include "sysinfo.h"
#include "msAPI_OCP.h"
#include "msAPI_BDMA.h"
#include "drvCPU.h"
#include "SysInit.h"
#include "msAPI_Flash.h"

#include "msAPI_MailBox.h"
#if 1//def ZUI
#include "InfoBlock.h"
#endif

#include "MApp_GlobalVar.h"  //20091124EL
#include "ms_decompress.h"
#include "OSDcp_Bitmap_EnumIndex.h"

#define BITMAP_FMT_ARGB1555   1
#define BITMAP_FMT_ARGB4444   2
#define BITMAP_FMT_I8         3
#define BITMAP_FMT_ARGB8888   4

#if (SW_LOAD_BMP_ON_DEMAND)
  #if( UI_SKIN_960X540XI8 == UI_SKIN_SEL )
    //The total size
    //It needs set bigger than ZUI_bitmap_SW_LOAD.bin.
    #define BMP_TMP_BUFFER_OFFSET   0x28200  //This size is for LZMA compression only  960x540xI8 ZUI_bitmap_SW_LOAD.bin 161KB

    //It needs set bigger than all file size.
    //Please use the msAPI_OCP_GenerateBitmapHandle_SDRAMEx printf u32len.
    //It is raw data size. It depneds on reslution not depneds on real file size.
    //At turnky the biggeest file szie is EPG_IMG_SCHEDULE_LIST_BG1.PNG  0x1602C
    #define BMP_TMP_BUFFER_SIZE     0x10800     //This is is for LZMA compression only  //960x540xI8, biggest file EPG_IMG_SCHEDULE_LIST_BG1.BMP 45.1 KB , u32len = 0xB016 but set 0x10800(66KB)
    #define BMP_TMP_LZMA_TEMP_BUFFER_OFFSET (BMP_TMP_BUFFER_OFFSET+BMP_TMP_BUFFER_SIZE)
    #define BMP_TMP_LZMA_TEMP_BUFFER_SIZE   0x10800// Buffer        0x10800 //Reserved 66KB for LZMA temp buffer
    #define BMP_TMP_LZMA_ON_DEMAND_SIZE     (BMP_TMP_LZMA_TEMP_BUFFER_OFFSET+BMP_TMP_LZMA_TEMP_BUFFER_SIZE)     //0x49200, 960x540xI8  BMP_START set 300KB

  #elif( (UI_SKIN_1366X768X565==UI_SKIN_SEL)||(UI_SKIN_960X540X565==UI_SKIN_SEL))
    //The total size
    //It needs set bigger than ZUI_bitmap_SW_LOAD.bin.
    #define BMP_TMP_BUFFER_OFFSET   0x4B000  //This size is for LZMA compression only    //0x90000

    //It needs set bigger than all file size.
    //Please use the msAPI_OCP_GenerateBitmapHandle_SDRAMEx printf u32len.
    //It is raw data size. It depneds on reslution not depneds on real file size.
    //At turnky the biggeest file szie is EPG_IMG_SCHEDULE_LIST_BG1.PNG  0x1602C
    #define BMP_TMP_BUFFER_SIZE     0x1C000     //This is is for LZMA compression only  //0x40000 //1366X768X565 biggest file EPOP_IMG1.png 124 KB  32len =0x1B6C0 set 0x1C000
    #define BMP_TMP_LZMA_TEMP_BUFFER_OFFSET (BMP_TMP_BUFFER_OFFSET+BMP_TMP_BUFFER_SIZE)
    #define BMP_TMP_LZMA_TEMP_BUFFER_SIZE   0x10800// Buffer        0x10800 //Reserved 66KB for LZMA temp buffer
    #define BMP_TMP_LZMA_ON_DEMAND_SIZE     (BMP_TMP_LZMA_TEMP_BUFFER_OFFSET+BMP_TMP_LZMA_TEMP_BUFFER_SIZE)     //0x73800, 462KB
   #elif(UI_SKIN_1920X1080X565==UI_SKIN_SEL)
    //The total size
    //It needs set bigger than ZUI_bitmap_SW_LOAD.bin.
    #define BMP_TMP_BUFFER_OFFSET   0x4B000  //This size is for LZMA compression only    //0x90000

    //It needs set bigger than all file size.
    //Please use the msAPI_OCP_GenerateBitmapHandle_SDRAMEx printf u32len.
    //It is raw data size. It depneds on reslution not depneds on real file size.
    //At turnky the biggeest file szie is EPG_IMG_SCHEDULE_LIST_BG1.PNG  0x1602C
    #define BMP_TMP_BUFFER_SIZE     0x1C000     //This is is for LZMA compression only  //0x40000 //1366X768X565 biggest file EPOP_IMG1.png 124 KB  32len =0x1B6C0 set 0x1C000
    #define BMP_TMP_LZMA_TEMP_BUFFER_OFFSET (BMP_TMP_BUFFER_OFFSET+BMP_TMP_BUFFER_SIZE)
    #define BMP_TMP_LZMA_TEMP_BUFFER_SIZE   0x10800// Buffer        0x10800 //Reserved 66KB for LZMA temp buffer
    #define BMP_TMP_LZMA_ON_DEMAND_SIZE     (BMP_TMP_LZMA_TEMP_BUFFER_OFFSET+BMP_TMP_LZMA_TEMP_BUFFER_SIZE)     //0x73800, 462KB
  #endif

  #if( BMP_TMP_LZMA_ON_DEMAND_SIZE > BMP_START_LEN )
    #error "BMP_START_LEN is too small"
  #endif


#else
    #define BMP_TMP_BUFFER_OFFSET   0x90000
    #define BMP_TMP_BUFFER_SIZE     0x40000
#endif



#define OCP_DBG(x) //x

//!!extern GFX_GlyphBbox  g_SRAM_BBox;
//!!static  U32 fontCount;
//!!static U32 osdcp_fontpack_addr;
static U32 bmpaddr;
//!!static U32 fontaddr;


static BOOLEAN bmpCompressed;
//***************************************Bitmap

typedef struct
{
    U16 width;
    U16 height;
} OSDcp_loadbitmap_info_table;

typedef struct
{
    U16 u16BmpWidth;    //bmp dimension width
    U16 u16BmpHeight;   //bmp dimension height
    U16 u16BmpFmt;
    U16 u32BmpSrcSize;  //compressed source bitmap size
    U32 u32BmpAddr;     //32 bits addr in dram
}tCompressedBmp,*ptCompressedBmp;

#define MAX_BMP_NO  E_ZUI_BMP_MAX

#if SW_LOAD_BMP_ON_DEMAND

#define DEBUG_DYN_BMP(x)    //x

static BOOLEAN u8bmpCompressedEach=0;
tCompressedBmp BmpEx[E_ZUI_BMP_MAX]; //MAX_BMP_NO*12 = 6K bytes to store bmp info
#endif

typedef struct
{
    U32 magicNumber;
    U32 headerSize;
    U32 bodySize;
    U32 binaryType;
    U32 bodyDecompressedSize;
    U16 bodyCompressMethod;
} BitmapBinaryInfo;

void msAPI_OCP_Init(void)
{
    bmpaddr = GE_ADDR_ALIGNMENT(((BMP_START_MEMORY_TYPE & MIU1) ? (BMP_START_ADR | MIU_INTERVAL) : (BMP_START_ADR)));
    bmpCompressed = FALSE;
}

void msAPI_DynBmp_ReadFlashToVirBuf(U32 u32StartAddr, U8* pu8BufAddr, U32 u32ReadSize)
{
#if 0
    msAPI_Flash_Read(u32StartAddr, u32ReadSize, pu8BufAddr);
#else
    //eRETCODE MApi_BDMA_CopyFromResource(U32 offset,U32 destVA,U32 len)
    //U32 u32PhyAddr = (U32)MsOS_VA2PA((U32)pu8BufAddr);

    //MApi_BDMA_CopyFromResource(u32StartAddr, u32PhyAddr, u32ReadSize);
    MApi_BDMA_CopyFromResource(u32StartAddr, (U32)pu8BufAddr, u32ReadSize);
#endif
}

void LoadU16(U32 pSpiAddr, U16 *pU16)
{
    //MApi_BDMA_CopyFromResource(pSpiAddr,(U32)pU16,sizeof(U16));
    msAPI_DynBmp_ReadFlashToVirBuf(pSpiAddr, (U8*)pU16, sizeof(U16));

    *pU16 = BE2ME16(*pU16);
}

void LoadBitmapInfoTable(U32 pSpiAddr, OSDcp_loadbitmap_info_table *pLIT)
{
    OSDcp_loadbitmap_info_table tbl;

    memset(&tbl, 0, sizeof(OSDcp_loadbitmap_info_table));   //Fix coverity CID200731
    //MApi_BDMA_CopyFromResource(pSpiAddr,(U32)&tbl,sizeof(tbl));
    msAPI_DynBmp_ReadFlashToVirBuf(pSpiAddr,(U8*)&tbl, sizeof(tbl));

    pLIT->width  = BE2ME16(tbl.width);
    pLIT->height = BE2ME16(tbl.height);
}

//Load Bitmap table extension with compressed for each bitmap object
void LoadBitmapInfoTableEx(U32 pSpiAddr, ptCompressedBmp pBmInfo, U32 nBmp, U32 u32BmpIndex)
{
    OSDcp_loadbitmap_info_table tbl;
    U8 u8Fmt = 0;
    U32 u32Size = 0;

    if(pBmInfo==NULL)
    {
        MS_DEBUG_MSG(printf("null pointer\n"));
        MDrv_Sys_StopCpu(1);
    }
    memset(pBmInfo,0,sizeof(tCompressedBmp));
    memset(&tbl,0,sizeof(OSDcp_loadbitmap_info_table)); //Fix coverity CID200732

    //MApi_BDMA_CopyFromResource(pSpiAddr,(U32)&tbl,sizeof(tbl));
    //MApi_BDMA_CopyFromResource(pSpiAddr+((nBmp - u32BmpIndex)*4+u32BmpIndex),(U32)&u8Fmt,sizeof(u8Fmt));
    //MApi_BDMA_CopyFromResource(pSpiAddr+(nBmp*4+nBmp),(U32)&u32Size,sizeof(u32Size));

    msAPI_DynBmp_ReadFlashToVirBuf(pSpiAddr, (U8*)&tbl,sizeof(tbl));
    msAPI_DynBmp_ReadFlashToVirBuf(pSpiAddr+((nBmp - u32BmpIndex)*4+u32BmpIndex), &u8Fmt,sizeof(u8Fmt));
    msAPI_DynBmp_ReadFlashToVirBuf(pSpiAddr+(nBmp*4+nBmp), (U8*)&u32Size, sizeof(u32Size));

    pBmInfo->u16BmpWidth=BE2ME16(tbl.width);;
    pBmInfo->u16BmpHeight=BE2ME16(tbl.height);;
    pBmInfo->u16BmpFmt=(U16)u8Fmt;
    pBmInfo->u32BmpSrcSize=BE2ME32(u32Size);  //compressed source bitmap size
    pBmInfo->u32BmpAddr=0;     //32 bits addr in dram
}

void LoadBitmapBinaryInfo(U32 pSpiAddr, BitmapBinaryInfo *pBBI)
{
    U8 p[22];


    //printf("LoadBitmapBinaryInfo(pSpiAddr=0x%X)\n", pSpiAddr);

    //MApi_BDMA_CopyFromResource(pSpiAddr,(U32)p,22);
    msAPI_DynBmp_ReadFlashToVirBuf(pSpiAddr, p, 22);

    //Print_Buffer(p, 22 );

    pBBI->magicNumber = ReadU32BE(p + 0);
    pBBI->headerSize  = ReadU32BE(p + 4);
    pBBI->bodySize    = ReadU32BE(p + 8);
    pBBI->binaryType  = ReadU32BE(p + 12);
    pBBI->bodyCompressMethod = ReadU16BE(p + 16);
    pBBI->bodyDecompressedSize = ReadU32BE(p + 18);
}

void msAPI_OCP_LoadBitmap(BMPHANDLE* pbmpHandle)
{
    BININFO BinInfo;
    U32 osdcp_bmp_addr = 0, u32Offset;
    U16 u16Index;
    U16 bitmap_no;
    OSDcp_loadbitmap_info_table loadbitmap_info_table;
    BitmapBinaryInfo info;
    U8 u8Fmt;
    GFX_Buffer_Format fmt;
    BOOLEAN bResult;

    BinInfo.B_ID = BIN_ID_OSDCP_BMP;

    msAPI_MIU_Get_BinInfo(&BinInfo, &bResult);


//20091229EL
    if(BinInfo.B_IsComp !=0)
    {
        if ( bResult == PASS )
        {
            osdcp_bmp_addr = ((POOL_BUFFER_ADR & MIU1) ? (POOL_BUFFER_ADR | MIU_INTERVAL) : (POOL_BUFFER_ADR));
        }
        else
        {
            return;
        }

        memcpy(&bitmap_no, (void*)_PA2VA(osdcp_bmp_addr+INFO_SIZE), sizeof(U16));
        bitmap_no = BE2ME16(bitmap_no);
        //printf("bitmap_no = %d\n", bitmap_no);


        for (u16Index=0; u16Index<bitmap_no; u16Index++)
        {
            u32Offset = osdcp_bmp_addr + INFO_SIZE + sizeof(bitmap_no);

            {
                memcpy(&loadbitmap_info_table, (void*)_PA2VA(u32Offset+u16Index*sizeof(OSDcp_loadbitmap_info_table)), sizeof(OSDcp_loadbitmap_info_table));
                loadbitmap_info_table.width = BE2ME16(loadbitmap_info_table.width);
                loadbitmap_info_table.height = BE2ME16(loadbitmap_info_table.height);
            }

            memcpy(&u8Fmt, (void*)_PA2VA(u32Offset+bitmap_no*sizeof(OSDcp_loadbitmap_info_table)+u16Index), 1);
            //printf("~~~ u8Fmt = %d\n",u8Fmt);

            switch (u8Fmt)
            {
                case BITMAP_FMT_ARGB8888:
                    fmt = GFX_FMT_ARGB8888;
                    break;
                case BITMAP_FMT_ARGB4444:
                    fmt = GFX_FMT_ARGB4444;
                    break;
                case BITMAP_FMT_I8:
                    fmt = GFX_FMT_I8;
                    break;
                default:
                    fmt = GFX_FMT_ARGB1555;
                    break;
            }
            pbmpHandle[u16Index] = msAPI_OCP_GenerateBitmapHandle_SDRAM(loadbitmap_info_table.width, loadbitmap_info_table.height, fmt);
        }
    }
    else
    {
        if ( bResult == PASS )
        {
            osdcp_bmp_addr = BinInfo.B_FAddr;
        }
        else
        {
            return;
        }

        LoadBitmapBinaryInfo(osdcp_bmp_addr, &info);
        LoadU16(osdcp_bmp_addr+INFO_SIZE, &bitmap_no);
        //MDrv_Flash_Read(osdcp_bmp_addr,sizeof(info),(U8 *)&info);
        //MDrv_Flash_Read(osdcp_bmp_addr+INFO_SIZE, sizeof(bitmap_no), (U8 *)&bitmap_no);

    #if SW_LOAD_BMP_ON_DEMAND

        DEBUG_DYN_BMP( printf("info.bodyCompressMethod=%u\n", info.bodyCompressMethod); );

        if((info.bodyCompressMethod==6) || (info.bodyCompressMethod==7))
        {
            u32Offset = osdcp_bmp_addr + INFO_SIZE + sizeof(bitmap_no);

            if(bitmap_no>MAX_BMP_NO)
            {
                printf("bmp no error max > :%d\n",MAX_BMP_NO);
                MDrv_Sys_StopCpu(1);
            }

            for (u16Index=0; u16Index<bitmap_no; u16Index++)
            {
                LoadBitmapInfoTableEx(u32Offset+u16Index*sizeof(OSDcp_loadbitmap_info_table), &BmpEx[u16Index],bitmap_no,u16Index);
                //MApi_BDMA_CopyFromResource(u32Offset+bitmap_no*sizeof(OSDcp_loadbitmap_info_table)+u16Index,(U32)&u8Fmt,1);
                //BmpEx[u16Index].=u8Fmt;
                switch (BmpEx[u16Index].u16BmpFmt)
                {
                    case BITMAP_FMT_ARGB8888:
                        fmt = GFX_FMT_ARGB8888;
                        break;
                    case BITMAP_FMT_ARGB4444:
                        fmt = GFX_FMT_ARGB4444;
                        break;
                    case BITMAP_FMT_I8:
                        fmt = GFX_FMT_I8;
                        break;
                    default:
                        fmt = GFX_FMT_ARGB1555;
                        break;
                }
                pbmpHandle[u16Index] = msAPI_OCP_GenerateBitmapHandle_SDRAMEx(BmpEx[u16Index].u16BmpWidth, BmpEx[u16Index].u16BmpHeight, fmt);
            }

            BmpEx[0].u32BmpAddr=_PA2VA((BMP_START_MEMORY_TYPE & MIU1) ? (BMP_START_ADR | MIU_INTERVAL) : (BMP_START_ADR));

            for (u16Index=0; u16Index<bitmap_no; u16Index++)
            {
                if(u16Index==1)
                {
                    BmpEx[u16Index].u32BmpAddr=BmpEx[0].u32BmpAddr+BmpEx[0].u32BmpSrcSize;
                }
                else if(u16Index>0 && u16Index!=1)
                {
                    BmpEx[u16Index].u32BmpAddr=BmpEx[u16Index - 1].u32BmpAddr+BmpEx[u16Index - 1].u32BmpSrcSize;
                }

                DEBUG_DYN_BMP( printf("BmpEx[%d].u32BmpAddr=%x\n", u16Index, BmpEx[u16Index].u32BmpAddr); );
            }
        }
        else
    #endif
        {
            for (u16Index=0; u16Index<bitmap_no; u16Index++)
            {
                u32Offset = osdcp_bmp_addr + INFO_SIZE + sizeof(bitmap_no);
                LoadBitmapInfoTable(u32Offset+u16Index*sizeof(OSDcp_loadbitmap_info_table), &loadbitmap_info_table);
                MApi_BDMA_CopyFromResource(u32Offset+bitmap_no*sizeof(OSDcp_loadbitmap_info_table)+u16Index,(U32)&u8Fmt,1);

                switch (u8Fmt)
                {
                    case BITMAP_FMT_ARGB8888:
                        fmt = GFX_FMT_ARGB8888;
                        break;
                    case BITMAP_FMT_ARGB4444:
                        fmt = GFX_FMT_ARGB4444;
                        break;
                    case BITMAP_FMT_I8:
                        fmt = GFX_FMT_I8;
                        break;
                    default:
                        fmt = GFX_FMT_ARGB1555;
                        break;
                }
                pbmpHandle[u16Index] = msAPI_OCP_GenerateBitmapHandle_SDRAM(loadbitmap_info_table.width, loadbitmap_info_table.height, fmt);
            }
        }
    }
}

void msAPI_OCP_DecompressHandle(BMPHANDLE handle)
{
#if SW_LOAD_BMP_ON_DEMAND
    if(u8bmpCompressedEach)
    {
        DEBUG_DYN_BMP( printf("u8bmpCompressedEach=%u\n", u8bmpCompressedEach); );
        if ( u8bmpCompressedEach == 1 )
        {
            ms_DecompressInit((U8*)(_PA2VA((BMP_START_MEMORY_TYPE & MIU1) ? ((BMP_START_ADR+BMP_TMP_BUFFER_OFFSET) | MIU_INTERVAL) : (BMP_START_ADR+BMP_TMP_BUFFER_OFFSET))));
            ms_Decompress((const U8*)(BmpEx[handle].u32BmpAddr), BmpEx[handle].u32BmpSrcSize);
            ms_DecompressDeInit();
        }
        else if ( u8bmpCompressedEach == 2 )
        {
            //BmpEx[handle].u32BmpSrcSize-2 is to minus 0xBEEF 2 bytes end tag
            //use non-cacheable decompression destination address here to avoid d-cache flush problem
            DEBUG_DYN_BMP( printf("BmpEx[%u].u32BmpAddr=0x%X\n", handle, BmpEx[handle].u32BmpAddr); );

            if( BmpEx[handle].u32BmpAddr == 0 )
            {
                return;
            }

            if ( !DoMsDecompression7(
                  (U8 *)(BmpEx[handle].u32BmpAddr & NON_CACHEABLE_TO_CACHEABLE_MASK),
                  (U8 *)((_PA2VA((BMP_START_MEMORY_TYPE & MIU1) ? ((BMP_START_ADR+BMP_TMP_BUFFER_OFFSET) | MIU_INTERVAL) : (BMP_START_ADR+BMP_TMP_BUFFER_OFFSET))) & NON_CACHEABLE_TO_CACHEABLE_MASK),
                  (U8 *)(((_PA2VA((BMP_START_MEMORY_TYPE & MIU1) ? ((BMP_START_ADR+BMP_TMP_BUFFER_OFFSET) | MIU_INTERVAL) : (BMP_START_ADR+BMP_TMP_BUFFER_OFFSET)))+BMP_TMP_BUFFER_SIZE) & NON_CACHEABLE_TO_CACHEABLE_MASK),
                    BmpEx[handle].u32BmpSrcSize-2)
                )
            {
                printf("BMP decompress fail\n");
            }
        }
        MsOS_Dcache_Flush( _PA2VA((BMP_START_MEMORY_TYPE & MIU1) ? ((BMP_START_ADR+BMP_TMP_BUFFER_OFFSET) | MIU_INTERVAL) : (BMP_START_ADR+BMP_TMP_BUFFER_OFFSET))  & NON_CACHEABLE_TO_CACHEABLE_MASK, BMP_TMP_BUFFER_SIZE );
        MsOS_FlushMemory();
    }
#else
    handle=handle;
#endif
}

void msAPI_OCP_PrepareBitmapBinary(void)
{
    BININFO BinInfo;
    U32 osdcp_bmp_addr=0;
    BitmapBinaryInfo info;
    BOOLEAN bResult;
    U16 bmpno;

    BinInfo.B_ID = BIN_ID_OSDCP_BMP;

    msAPI_MIU_Get_BinInfo(&BinInfo, &bResult);

    if ( bResult != PASS)
    {
        MS_DEBUG_MSG(printf("ERROR!![%s]%d\n",__FILE__,__LINE__));
        return;
    }

//20091229EL
    //printf("~~1 BinInfo.B_Len = %ld\n",BinInfo.B_Len);
    if (SUCCESS == MDrv_DMA_LoadBin(&BinInfo, _PA2VA(((POOL_BUFFER_ADR+BUF_OFFSET_FOR_BITMAP_DECOMPRESS_DST) & MIU1) ? ((POOL_BUFFER_ADR+BUF_OFFSET_FOR_BITMAP_DECOMPRESS_DST) | MIU_INTERVAL) : (POOL_BUFFER_ADR+BUF_OFFSET_FOR_BITMAP_DECOMPRESS_DST)),
        _PA2VA(((POOL_BUFFER_ADR+ BUF_OFFSET_FOR_BITMAP_DECOMPRESS_SRC) & MIU1) ? ((POOL_BUFFER_ADR+ BUF_OFFSET_FOR_BITMAP_DECOMPRESS_SRC) | MIU_INTERVAL) : (POOL_BUFFER_ADR+ BUF_OFFSET_FOR_BITMAP_DECOMPRESS_SRC)),
        _PA2VA(((POOL_BUFFER_ADR+ BUF_OFFSET_FOR_BITMAP_DECOMPRESS_TMP) & MIU1) ? ((POOL_BUFFER_ADR+ BUF_OFFSET_FOR_BITMAP_DECOMPRESS_TMP) | MIU_INTERVAL) : (POOL_BUFFER_ADR+ BUF_OFFSET_FOR_BITMAP_DECOMPRESS_TMP))))
    {
        switch(BinInfo.B_IsComp)
        {
            case LZSS_COMPRESS:
            case MS_COMPRESS:
            case MS_COMPRESS7:
                //printf("~~1~~  LZSS_COMPRESS\n");
                bmpCompressed=TRUE;
                break;

            default:
                bmpCompressed=FALSE;
                break;
        }

        MsOS_FlushMemory();  //20091229EL

        osdcp_bmp_addr = (((POOL_BUFFER_ADR+BUF_OFFSET_FOR_BITMAP_DECOMPRESS_DST) & MIU1) ? ((POOL_BUFFER_ADR+BUF_OFFSET_FOR_BITMAP_DECOMPRESS_DST) | MIU_INTERVAL) : (POOL_BUFFER_ADR+BUF_OFFSET_FOR_BITMAP_DECOMPRESS_DST));
        {
            U8 p[80];
            memcpy(&p, (void*)_PA2VA(osdcp_bmp_addr), 80);
            info.magicNumber = ReadU32BE(p + 0);
            info.headerSize  = ReadU32BE(p + 4);
            info.bodySize    = ReadU32BE(p + 8);
            info.binaryType  = ReadU32BE(p + 12);
            info.bodyCompressMethod = ReadU16BE(p + 16);
            info.bodyDecompressedSize = ReadU32BE(p + 18);
            bmpno=ReadU16BE(p+0x40);
        }
        //printf(" info.magicNumber = %ld\n", info.magicNumber);
        //printf(" info.headerSize = %ld\n", info.headerSize);
        //printf(" info.bodySize = %ld\n", info.bodySize);
        //printf(" info.binaryType = %ld\n", info.binaryType);
        //printf(" info.bodyDecompressedSize = %ld\n", info.bodyDecompressedSize);
        //printf(" info.bodyCompressMethod = %d\n", info.bodyCompressMethod);

        MApi_BDMA_Copy((osdcp_bmp_addr),((POOL_BUFFER_ADR & MIU1) ? (POOL_BUFFER_ADR | MIU_INTERVAL) : (POOL_BUFFER_ADR)) , GE_ALIGNED_VALUE(info.headerSize,8),MIU_SDRAM2SDRAM);

    #if SW_LOAD_BMP_ON_DEMAND
        switch(info.bodyCompressMethod)
        {
            case 6:
                u8bmpCompressedEach=1;
                break;
            case 7:
                u8bmpCompressedEach=2;
                break;
            default:
                u8bmpCompressedEach=0;
                break;
        }

        if((info.bodyCompressMethod==6) || (info.bodyCompressMethod==7))
        {
            MApi_BDMA_Copy(((osdcp_bmp_addr+info.headerSize+(bmpno*4))),((BMP_START_MEMORY_TYPE & MIU1) ? (BMP_START_ADR | MIU_INTERVAL) : (BMP_START_ADR)), info.bodySize,MIU_SDRAM2SDRAM);
        }
        else
    #endif
        {
            MApi_BDMA_Copy((osdcp_bmp_addr+info.headerSize),(msAPI_OCP_GetBmpAddr()), info.bodySize ,MIU_SDRAM2SDRAM);
        }
    }
    else
    {
        MS_DEBUG_MSG(printf("ERROR!![%s]%d\n",__FILE__,__LINE__));
        return;
    }
}

BMPHANDLE msAPI_OCP_GenerateBitmapHandle_SDRAM(U16 u16width, U16 u16height, GFX_Buffer_Format fmt)
{
    U32 u32dstaddr = bmpaddr, u32len;

    if (fmt == GFX_FMT_I8)
        u32len = (U32)( (U32)u16width * u16height);
    else if (fmt == GFX_FMT_ARGB8888)
        u32len = (U32)( (U32)u16width * u16height) * 4;
    else
        u32len = (U32)( (U32)u16width * u16height) * 2;

    bmpaddr = GE_ADDR_ALIGNMENT(bmpaddr + u32len);
    return msAPI_OSD_RESOURCE_LoadBitmap(u32dstaddr, u32len, u16width, u16height, (BMP_Buffer_Format)fmt);
}

#if SW_LOAD_BMP_ON_DEMAND
BMPHANDLE msAPI_OCP_GenerateBitmapHandle_SDRAMEx(U16 u16width, U16 u16height, GFX_Buffer_Format fmt)
{
    //use same address for bitmap rendering
    //This address must be physical address for GE HW
    U32 u32dstaddr = ((BMP_START_MEMORY_TYPE & MIU1) ? ((BMP_START_ADR+BMP_TMP_BUFFER_OFFSET) | MIU_INTERVAL) : (BMP_START_ADR+BMP_TMP_BUFFER_OFFSET)), u32len;
    if (fmt == GFX_FMT_I8)
        u32len = (U32)( (U32)u16width * u16height);
    else if (fmt == GFX_FMT_ARGB8888)
        u32len = (U32)( (U32)u16width * u16height) * 4;
    else
        u32len = (U32)( (U32)u16width * u16height) * 2;

    //bmpaddr = GE_ADDR_ALIGNMENT(bmpaddr + u32len);
    //printf("u16width %d u16height%d u32len =0x%x \r\n",u16width,u16height,u32len);
    return msAPI_OSD_RESOURCE_LoadBitmap(u32dstaddr, u32len, u16width, u16height, (BMP_Buffer_Format)fmt);
}
#endif

U32 msAPI_OCP_GetBmpAddr()
{
    return GE_ADDR_ALIGNMENT(((BMP_START_MEMORY_TYPE & MIU1) ? (BMP_START_ADR | MIU_INTERVAL) : (BMP_START_ADR)));
}

//*******************String
typedef struct
{
    U32 magicNumber;
    U32 headerSize;
    U32 bodySize;
    U32 binaryType;
    U16 bodyCompressMethod;
    U32 bodyDecompressedSize;
    U16 bodyEncodingMethod;
} StringBinaryInfo;

typedef struct
{
    U32 startaddr;
    U16 length;
} OSDcp_string_info_table;

#define STRBUFF_LENGTH 256
static U32 osdcp_text_addr;
static StringBinaryInfo sStringBininfo;


static void LoadStringBinaryInfo(U8* p, StringBinaryInfo *pSBI)
{
    pSBI->magicNumber = ReadU32BE(p + 0);
    pSBI->headerSize = ReadU32BE(p + 4);
    pSBI->bodySize = ReadU32BE(p + 8);
    pSBI->binaryType = ReadU32BE(p + 12);
    pSBI->bodyCompressMethod = ReadU16BE(p + 16);
    pSBI->bodyDecompressedSize = ReadU32BE(p + 18);
    pSBI->bodyEncodingMethod = ReadU16BE(p + 22);
}

void msAPI_OCP_PrepareStringBinary(void)
{
    BININFO BinInfo;
    BOOLEAN bResult;

    BinInfo.B_ID = BIN_ID_OSDCP_TEXT;

    msAPI_MIU_Get_BinInfo(&BinInfo, &bResult);

    if ( bResult != PASS)
    {
        MS_DEBUG_MSG(printf("ERROR!![%s]%d\n",__FILE__,__LINE__));
        return;
    }

//20091127EL
    if (SUCCESS == MDrv_DMA_LoadBin(&BinInfo, _PA2VA(msAPI_OCP_GetStringAddr()),
        _PA2VA((POOL_BUFFER_ADR & MIU1) ? (POOL_BUFFER_ADR | MIU_INTERVAL) : (POOL_BUFFER_ADR)),
        _PA2VA(((POOL_BUFFER_ADR + BUF_FOR_DECOMPRESS_OFFSET1) & MIU1) ? ((POOL_BUFFER_ADR + BUF_FOR_DECOMPRESS_OFFSET1) | MIU_INTERVAL) : (POOL_BUFFER_ADR + BUF_FOR_DECOMPRESS_OFFSET1))  ))
    {
        switch(BinInfo.B_IsComp)
        {
        case LZSS_COMPRESS:
        case MS_COMPRESS:
        case MS_COMPRESS7:
            _bOCPFromMem   = TRUE;
            osdcp_text_addr  = msAPI_OCP_GetStringAddr();
            LoadStringBinaryInfo((U8*)(_PA2VA(osdcp_text_addr)), &sStringBininfo);
            break;
        default:
            {
                U8 p[24];
                osdcp_text_addr =  BinInfo.B_FAddr;
                MApi_BDMA_CopyFromResource(osdcp_text_addr,(U32)p,24);
                LoadStringBinaryInfo(p, &sStringBininfo);
            }
            break;
        }
    }
    else
    {
        MS_DEBUG_MSG(printf("ERROR!![%s]%d\n",__FILE__,__LINE__));
        return;
    }
}

static U32 readbin_language_addr( U8 language )
{
    U32 language_addr;
    U32 language_id_addr;

    language_id_addr = sizeof(U32) + language * sizeof(language_addr);

    if(_bOCPFromMem)
    {
        memcpy(&language_addr, (void *)_PA2VA((U32)(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR))+INFO_SIZE+language_id_addr)), sizeof(language_addr));
    }
    else
    {

        MApi_BDMA_CopyFromResource(osdcp_text_addr+INFO_SIZE+language_id_addr,(U32)&language_addr,sizeof(language_addr));
    }

    return BE2ME32(language_addr);
}

static OSDcp_string_info_table readbin_string_info(U32 language_addr, U16 id)
{
    OSDcp_string_info_table struct_string_info;

    U32 startaddr;
    U32 staraddr_next;
    U32 string_id_info_addr;

    string_id_info_addr = language_addr+sizeof(U32)/*string count*/+id*sizeof(startaddr);

    if(_bOCPFromMem)
    {
        memcpy(&startaddr, (void *)_PA2VA((((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR))+string_id_info_addr)), sizeof(startaddr));
        memcpy(&staraddr_next, (void *)_PA2VA((((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR))+string_id_info_addr+sizeof(startaddr))), sizeof(startaddr));
    }
    else
    {

        MApi_BDMA_CopyFromResource(osdcp_text_addr+string_id_info_addr,(U32)&startaddr,sizeof(startaddr));
        MApi_BDMA_CopyFromResource(osdcp_text_addr+string_id_info_addr+sizeof(startaddr),(U32)&staraddr_next,sizeof(startaddr));
    }

    startaddr = BE2ME32(startaddr);
    staraddr_next = BE2ME32(staraddr_next);

    struct_string_info.startaddr =startaddr;
    struct_string_info.length = (U16)(staraddr_next-startaddr);

    return struct_string_info;
}

static void msAPI_OCP_ReadBinaryString_ptr(U8 language, U16 id, U16 *pu16stringbuffer)
{
    U32 language_addr;
    OSDcp_string_info_table struct_string_info;
    U8 CHAR_BUFFER2[STRBUFF_LENGTH];

    language_addr = readbin_language_addr(language);
    struct_string_info = readbin_string_info(language_addr, id);

    if ( sStringBininfo.bodyEncodingMethod == ENCODING_UTF8 )
    {

        if(_bOCPFromMem)
        {
            memcpy(CHAR_BUFFER2, (void *)_PA2VA((((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + sStringBininfo.headerSize + struct_string_info.startaddr)), struct_string_info.length);
        }
        else
        {
            MApi_BDMA_CopyFromResource(osdcp_text_addr + sStringBininfo.headerSize + struct_string_info.startaddr,(U32)(&CHAR_BUFFER2[0]),struct_string_info.length);
        }


        msAPI_OCP_MappinUTF8ToUCS2( CHAR_BUFFER2, pu16stringbuffer, struct_string_info.length, STRBUFF_LENGTH );
        if ( pu16stringbuffer[0] == '\b' )
        {
            language_addr = readbin_language_addr(pu16stringbuffer[1]);
            struct_string_info = readbin_string_info(language_addr, id);
            MApi_BDMA_CopyFromResource(osdcp_text_addr + sStringBininfo.headerSize + struct_string_info.startaddr,(U32)(&CHAR_BUFFER2[0]),struct_string_info.length);
            msAPI_OCP_MappinUTF8ToUCS2( CHAR_BUFFER2, pu16stringbuffer, struct_string_info.length, STRBUFF_LENGTH );
        }
    }
    else if ( sStringBininfo.bodyEncodingMethod == ENCODING_FLAG_FOR_ONE_OR_TWO )
    {
        U8  i = 0, bUseOneOrTwoByte;

        if(_bOCPFromMem)
        {
            memcpy(CHAR_BUFFER2, (void *)_PA2VA((((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + sStringBininfo.headerSize + struct_string_info.startaddr)), struct_string_info.length);
        }
        else
        {
            MApi_BDMA_CopyFromResource(osdcp_text_addr + sStringBininfo.headerSize + struct_string_info.startaddr,(U32)(&CHAR_BUFFER2[0]),struct_string_info.length);
        }

        bUseOneOrTwoByte = CHAR_BUFFER2[0];
        if ( bUseOneOrTwoByte == 1 )
        {
            for ( i = 1; i < struct_string_info.length; i++ )
            {
                pu16stringbuffer[i - 1] = ( U16 )CHAR_BUFFER2[i];
            }
        }
        else if ( bUseOneOrTwoByte == 2 )
        {
            memcpy( ( U8 * )pu16stringbuffer, CHAR_BUFFER2 + 1, struct_string_info.length - 1 );
        }
    }
    else
    {
        U32 i;

        if(_bOCPFromMem)
        {
            memcpy(pu16stringbuffer, (void *)_PA2VA((((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + sStringBininfo.headerSize + struct_string_info.startaddr)), struct_string_info.length);
        }
        else
        {
            MApi_BDMA_CopyFromResource(osdcp_text_addr + sStringBininfo.headerSize + struct_string_info.startaddr,(U32)pu16stringbuffer,struct_string_info.length);
        }

        if (sStringBininfo.bodyEncodingMethod == ENCODING_UTF16_BIG_ENDIAN)
        {
            //convert from big endian to little
            for(i=0;i<struct_string_info.length/2;i++)
            {
                pu16stringbuffer[i]=BE2ME16(pu16stringbuffer[i]);
            }
        }
        if ( pu16stringbuffer[0] == '\b' ) //reduce the code size for duplicate characters
        {
            language_addr = readbin_language_addr(pu16stringbuffer[1]);
            struct_string_info = readbin_string_info(language_addr, id);

            if(_bOCPFromMem)
            {
                memcpy(pu16stringbuffer, (void *)_PA2VA((((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + sStringBininfo.headerSize + struct_string_info.startaddr)), struct_string_info.length);
            }
            else
            {
                MApi_BDMA_CopyFromResource( osdcp_text_addr + sStringBininfo.headerSize + struct_string_info.startaddr,(U32)pu16stringbuffer,struct_string_info.length);
            }

            if (sStringBininfo.bodyEncodingMethod == ENCODING_UTF16_BIG_ENDIAN)
            {
                //convert from big endian to little
                for(i=0;i<struct_string_info.length/2;i++)
                {
                    pu16stringbuffer[i]=BE2ME16(pu16stringbuffer[i]);
                }
            }
        }
    }
}

static void msAPI_OCP_ReadBinaryString_ptr_memory(U8 language, U16 id, U16 *pu16stringbuffer)
{
    U32 language_addr;
    OSDcp_string_info_table struct_string_info;
    U8 CHAR_BUFFER2[STRBUFF_LENGTH];

    language_addr = readbin_language_addr(language);
    struct_string_info = readbin_string_info(language_addr, id);

    if ( sStringBininfo.bodyEncodingMethod == ENCODING_UTF8 )
    {
        msAPI_MIU_Copy(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + struct_string_info.startaddr, XD2PHY(&(CHAR_BUFFER2[0])), struct_string_info.length, MIU_SDRAM2SDRAM);
        msAPI_OCP_MappinUTF8ToUCS2( CHAR_BUFFER2, pu16stringbuffer, struct_string_info.length, STRBUFF_LENGTH );
        if ( pu16stringbuffer[0] == '\b' )
        {
            language_addr = readbin_language_addr(pu16stringbuffer[1]);
            struct_string_info = readbin_string_info(language_addr, id);
            msAPI_MIU_Copy(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + struct_string_info.startaddr, XD2PHY(&(CHAR_BUFFER2[0])), struct_string_info.length, MIU_SDRAM2SDRAM);
            msAPI_OCP_MappinUTF8ToUCS2( CHAR_BUFFER2, pu16stringbuffer, struct_string_info.length, STRBUFF_LENGTH );
        }
    }
    else if ( sStringBininfo.bodyEncodingMethod == ENCODING_FLAG_FOR_ONE_OR_TWO )
    {
        U8  i = 0, bUseOneOrTwoByte;

        msAPI_MIU_Copy(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + struct_string_info.startaddr, XD2PHY(&(CHAR_BUFFER2[0])), struct_string_info.length, MIU_SDRAM2SDRAM);

        bUseOneOrTwoByte = CHAR_BUFFER2[0];
        if ( bUseOneOrTwoByte == 1 )
        {
            for ( i = 1; i < struct_string_info.length; i++ )
            {
                pu16stringbuffer[i - 1] = ( U16 )CHAR_BUFFER2[i];
            }
        }
        else if ( bUseOneOrTwoByte == 2 )
        {
            memcpy( ( U8 * )pu16stringbuffer, CHAR_BUFFER2 + 1, struct_string_info.length - 1 );
        }
    }
    else
    {
        msAPI_MIU_Copy(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + struct_string_info.startaddr, XD2PHY(&(pu16stringbuffer[0])), struct_string_info.length, MIU_SDRAM2SDRAM);
        if ( pu16stringbuffer[0] == '\b' )
        {
            language_addr = readbin_language_addr(pu16stringbuffer[1]);
            struct_string_info = readbin_string_info(language_addr, id);
            msAPI_MIU_Copy(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)) + struct_string_info.startaddr, XD2PHY(&(pu16stringbuffer[0])), struct_string_info.length, MIU_SDRAM2SDRAM);
        }
    }
}

void msAPI_OCP_ReadBinaryString(U8 language, U16 id, U16 *pu16stringbuffer)
{
    switch (sStringBininfo.bodyCompressMethod)
    {
        case SLZ_COMPRESS:
        case LZSS_COMPRESS:
        case MS_COMPRESS:  //20091127EL
        case MS_COMPRESS7:
            msAPI_OCP_ReadBinaryString_ptr_memory(language, id, pu16stringbuffer);
            break;
        default:
            msAPI_OCP_ReadBinaryString_ptr(language, id, pu16stringbuffer);
            break;
    }
}

U32 msAPI_OCP_GetStringAddr()
{
    return GE_ADDR_ALIGNMENT(((STRING_START_MEMORY_TYPE & MIU1) ? (STRING_START_ADR | MIU_INTERVAL) : (STRING_START_ADR)));
}

void msAPI_OCP_LoadAllStringToMem(void)
{
    _bOCPFromMem = TRUE;
    if (sStringBininfo.headerSize+sStringBininfo.bodySize <= STRING_START_LEN)
    {
        MApi_BDMA_CopyFromResource(osdcp_text_addr, _PA2VA(STRING_START_ADR) , sStringBininfo.headerSize+sStringBininfo.bodySize);
    }
    else
    {
        msWarning(ERR_OUT_OF_MEMORY);
    }
}

#if 0
//************************Font

typedef struct
{
    U32 magicNumber;
    U32 headerSize;
    U32 bodySize;
    U32 binaryType;
    U16 bodyCompressMethod;
    U32 bodyDecompressedSize;
}FontPackBinaryInfo;


void msAPI_OCP_ReadFontBoundary(U32 *pFontDataBoundary)
{

    MDrv_Flash_Read(osdcp_fontpack_addr+INFO_SIZE+sizeof(U32)/*count*/,sizeof(U32)*fontCount,(U8*)pFontDataBoundary);
}

U32 msAPI_OCP_PrepareFontPackBinary()//return the font count
{


    BININFO BinInfo;
    FontPackBinaryInfo info;

    fontCount=0;
    BinInfo.B_ID = BIN_ID_OSDCP_FONTPACK;

    if (msAPI_MIU_Get_BinInfo(&BinInfo) == PASS)
    {
        osdcp_fontpack_addr= BinInfo.B_FAddr;
    }

    /*read out information from FLASH*/
    MDrv_Flash_Read(osdcp_fontpack_addr,sizeof(info),(U8 *)&info);
    MDrv_Flash_Read(osdcp_fontpack_addr+INFO_SIZE,sizeof(U32),(U8*)&fontCount);
      alignedBodyLen=(U32)(((info.bodySize-1)/8+1)*8);
    //pFontDataBoundary=(U32 *)msAPI_Memory_Allocate(sizeof(U32)*2*fontCount);

    //MDrv_Flash_Read(osdcp_fontpack_addr+INFO_SIZE+sizeof(U32)/*count*/,sizeof(U32)*fontCount,(U8*)pFontDataBoundary);

    /*prepare the binary*/
     if(info.bodyCompressMethod==LZ_COMPRESS)
        {

            OCP_DBG(printf("FONT_DE_START:%lu, SRC_ADDR=%lu\n",msAPI_Timer_GetTime0(),VDEC_FRAMEBUFFER_ADR));

            MApi_BDMA_Copy(osdcp_fontpack_addr+info.headerSize,VDEC_FRAMEBUFFER_ADR,alignedBodyLen, MIU_FLASH2SDRAM);



            msAPI_LZ_Init(500);
            while(!msAPI_LZ_Decoder_Ready())
            {
                msAPI_Timer_Delayms(10);
            }
            OCP_DBG(printf("FONT_DE_READY:%lu\n",msAPI_Timer_GetTime0()));
            msAPI_LZ_StartDecompress(info.bodySize,VDEC_FRAMEBUFFER_ADR,msAPI_OCP_GetBmpAddr());

            msAPI_LZ_WaitDecompressFinished(5000);

            OCP_DBG(printf("FONT_DE_END:%lu\n",msAPI_Timer_GetTime0()));


        }
        else
        {
            MApi_BDMA_Copy(osdcp_fontpack_addr+info.headerSize,msAPI_OCP_GetBmpAddr(),alignedBodyLen, MIU_FLASH2SDRAM);
        }


    return fontCount;


}


//*****************
//*
//*****************
//for OSD resource





/*must be called before loading bitmap*/
FONTHANDLE msAPI_OCP_LoadSDRAMFont(U32 fontStartAddr, EN_FONT_TARGET_BPP u8TargetBPP)
{
    FONTHANDLE handle = INVALID_FONTHANDLE;
    FONT_BIN_HEADER         FontBinHeader;
    ST_LOAD_FONT_SDRAM_REPORT FontSdramInfo;

    u8TargetBPP=u8TargetBPP;

    if (!msAPI_Font_LoadSDRAMFont_Decompress(fontStartAddr, fontaddr, &FontBinHeader, &FontSdramInfo))
    {
        return INVALID_FONTHANDLE;
    }

    if (fontaddr + FontSdramInfo.u32SdramLen <= ((FONT_START_MEMORY_TYPE & MIU1) ? (FONT_START_ADR | MIU_INTERVAL) : (FONT_START_ADR)) + FONT_START_LEN)
    {
        handle = MDrv_GE_LoadFont( FontSdramInfo.u32StartAddr,
                                   FontSdramInfo.u32GlyphAddr,
                                   FontSdramInfo.u32BBoxAddr,
                                   FontSdramInfo.u32CodemapAddr,
                                   FontBinHeader.u32CharNum,
                                   FontBinHeader.u32CodemapBlockNum,
                                   FontBinHeader.u32Width,
                                   FontBinHeader.u32Height,
                                   FontBinHeader.u32BPP,
                                   FontBinHeader.u32CharGlyphBytes,
                                   FontBinHeader.u32Pitch,
                                   MIU_SDRAM
                                   );

        // calc for next font table starting address
        fontaddr = GE_ADDR_ALIGNMENT(fontaddr + FontSdramInfo.u32SdramLen);
    }
    else
        msWarning(ERR_FONT_OUT_OF_BUFFER);

    return handle;
}
#endif



/******************************************************************************/
///-Convert UTF8 to UCS2
///@param pu8Str \b IN
///@param pu16Str \b IN
///@param srcByteLen \b IN
///@param dstWideCharLen \b IN
///- pu8Str ...
///- pu16Str ...
///- srcByteLen ...
///- dstWideCharLen ...
/******************************************************************************/
U16 msAPI_OCP_MappinUTF8ToUCS2(U8 *pu8Str, U16 *pu16Str, U16 srcByteLen, U16 dstWideCharLen)
{
    //see reference from http://en.wikipedia.org/wiki/Utf-8
    U8 u8Value;
    U16 i, j;

    if ((pu8Str == 0) || (srcByteLen == 0) || (pu16Str == 0) || (dstWideCharLen <= 1)) return 0;

    for (i=0, j=0; i<srcByteLen && j<dstWideCharLen-1; i++, j++)
    {
        u8Value = pu8Str[i];
        if (u8Value == 0)
        {
            break;
        }
        if ((u8Value & 0x80) == 0)
        {
            // 0zzzzzzz(00-7F) => 00000000 0zzzzzzz
            pu16Str[j] = (U16) (u8Value & 0x7F);
        }
        else if (((u8Value & 0xE0) == 0xC0) && ((i+1)<srcByteLen))
        {
            // 110yyyyy(C2-DF) 10zzzzzz(80-BF) => 00000yyy yyzzzzzz
            pu16Str[j] = (U16) ( ((u8Value & 0x1F) << 6) | (pu8Str[i+1] & 0x3F) );
            i += 1;
        }
        else if (((u8Value & 0xF0) == 0xE0) && ((i+2)<srcByteLen))
        {
            // 1110xxxx(E0-EF) 10yyyyyy 10zzzzzz => xxxxyyyy yyzzzzzz
            pu16Str[j] = (U16) ( ((u8Value & 0xF) << 12) | ((pu8Str[i+1] & 0x3F) << 6) | (pu8Str[i+2] & 0x3F));
            i += 2;
        }
        else
        {
            // Unknown, skip
            j--;
            continue;
        }

        // convert control code
        if ( pu16Str[j]>=0x80 && pu16Str[j]<=0x9F )
        {
            pu16Str[j] = (0xE000 | pu16Str[j]);
        }
    }

    // NULL termination character
    pu16Str[j] = 0;

    return j;
}


#undef  MSAPI_OCP_C

