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
// (MStar Confidential Information) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_MUSIC_C

//-------------------------------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

// Global Layer
#include "sysinfo.h"

#include "SysInit.h"

//#include "msAPI_XdataExt.h"

#include "BinInfo.h"
#include "drvGPIO.h"
//#include "Tv_china.h"
#include "drvSERFLASH.h"
// For MM
// API Layer
#include "apiXC.h"
#include "apiXC_Adc.h"
#include "msAPI_MIU.h"
#include "msAPI_Memory.h"
#include "msAPI_Timer.h"
#include "msAPI_FCtrl.h"
#include "msAPI_Music.h"
#include "apiGOP.h"
#include "msAPI_Flash.h"
#include "msAPI_audio.h"

// AP Layer
#include "MApp_GlobalSettingSt.h"
#include "MApp_GlobalVar.h"
#include "MApp_GlobalFunction.h"
#include "MApp_Exit.h"
#include "mapp_music.h"
#include "MApp_Audio.h"
//#include "AnalogAudioDecoder.h"
#include "MApp_FileBrowser.h"
#include "MApp_UiMediaPlayer.h"
#include "MApp_SaveData.h"
#include "MApp_InputSource.h"
#include "MApp_UiMediaPlayer_Define.h"
#include "msAPI_DataStreamIO.h"
#include "mapp_buffermanage.h"

#if (ENABLE_DMP)

#include "MsIRQ.h"
#include "MsOS.h"

#include <ctype.h>

#define msAPI_Stream_Seek(x,y) msAPI_DataStreamIO_Seek(x,y,E_DATA_STREAM_SEEK_SET)

#define COMB_U16(hi,lo)          ((((U16)hi)<<8) | ((U16)lo))
#define COMB_U32(hh,hl,lh,ll)    ((((U32)hh)<<24) | (((U32)hl)<<16) | (((U32)lh)<<8) | ((U32)ll))

#if ENABLE_MPLAYER_MUSIC

//-------------------------------------------------------------------------------------------------
// Local Defines
//-------------------------------------------------------------------------------------------------
#define MP3_FLASH_BLOCK_SIZE    0x10000//SIZE_64KB
#define MUSIC_CANNOT_FIND_1ST_FRAME 0xFFFFFFFF
#define MP3_SEARCH_FIRST_FRAME_TIME_OUT     (5000)
#define MP3_SEARCH_BY_DSP_TIME_OUT          (300)

#define MP3_LAYER_CHECK_COUNT   3
#define READ_BLOCK_SIZE         4096

//#define MP3_INFO_READ_ADR MUSIC_LYRIC_TAG_ADR
#define MP3_ID3_V1_LEN 128

#define MP3_TIMER_FINE_TUNE(x) (x) //(x + x/60)

#define MUSIC_LYRIC_MAX_COUNT     (MUSIC_LYRIC_TAG_LEN/sizeof(Music_Lyric_Tag))

#define MP3_FF_FB_THOESHOLD 2 // sec

static U8 u8MusicFFFWMode = 0;
#define MP3_NORMAL_MODE 0
#define MP3_FF_Mode BIT0
#define MP3_FW_Mode BIT1
#define AAC_LC_PROFILE 1

#define MUSIC_WAV_HEADER_LENGTH 44

#define MUSIC_WAV_READ_THRESHOLD 0x2000 //8k

#define POWER_MUSIC_MAX_SIZE             0x10000             // 64K BYTE
#define AUDIO_ES_MIN_FREE_SPACE        0x20                  // 2 line space = 16x2 (bytes)
#define POWER_MUSIC_REQUEST_SIZE     POWER_MUSIC_MAX_SIZE-AUDIO_ES_MIN_FREE_SPACE    //Request 64KB-2 line space

#ifdef OGG_PARSER
#define OGG_PRINTDATA  0

#define OGG_PAGE_CONT  0x01
#define OGG_PAGE_BOS   0x02
#define OGG_PAGE_EOS   0x04

typedef struct {
    U32 u32PageHeaderOffset;
    U32 u32HeaderLen;
    U32 u32PageBodyOffset;
    U32 u32BodyLen;
    LongLong u64Granulepos;
    U32 u32SerialNo;
    U32 u32PageNo;
    U8   u8HeaderType;
    U8   u8SegmentNum;
} Ogg_Page;

typedef struct   {
    U32 u32SerialNo;
    U32 u32VorbisHeaderAddr[3];
    U32 u32VorbisHeaderSize[3];
    U32 u32VorbisHeaderTotalSize;
    U32 u32VorbisHeaderLeftSizeToWrite;
    U32 u32VorbisFirstAudioPageOffset;
    U32 u32VorbisLastAudioPageOffset;
    Ogg_Page CurrentPage;
    U32 u32CurrPageIndex;
    U32 u32LeftSizeInPage;
    BOOLEAN bEndofFile;
    U32 u32LeftDataToFill;
    BOOLEAN bNeedAddHeader;
    BOOLEAN bInputFromPacketStart;
    BOOLEAN bSeekToCurrentTime;
} OggInfo;

typedef enum OGGCOMMENTID{
    OGG_NONE,
    OGG_TITLE,
    OGG_VERSION,
    OGG_ALBUM,
    OGG_ARTIST,
    OGG_GENRE,
    OGG_DATE,
    OGG_TRACKNUMBER,
}OGG_COMMENTID;

typedef struct OGGCOMMENTFIELD{
    char * CommentField;
    OGG_COMMENTID Ogg_CommentId;
}OGG_COMMENTFIELD;

OGG_COMMENTFIELD CommentFields[7] ={{"TITLE",OGG_TITLE},
                                                                  {"VERSION",OGG_VERSION},
                                                                  {"ALBUM",OGG_ALBUM},
                                                                  {"ARTIST",OGG_ARTIST},
                                                                  {"GENRE",OGG_GENRE},
                                                                  {"DATE",OGG_DATE},
                                                                  {"TRACKNUMBER",OGG_TRACKNUMBER},
                                                                 };

#endif
#ifndef U64
    typedef unsigned long long U64;
#endif

#if (ENABLE_FLAC)
/// Flac Seek table
typedef struct
{
    /// Sample number of first sample in the target frame,
    /// or 0xFFFFFFFFFFFFFFFF for a placeholder point.
    U64 u64SampleNum;
    /// Offset (in bytes) from the first byte of the first frame header to the first byte of the target frame's header.
    U64 u64FrameOffset;
    /// Number of samples in the target frame.
    U16 u16SamplesOfFrame;
}ST_FLAC_SEEK_TABLE;

/// Flac info
typedef struct
{
    /// offset of the First valid audio data
    U32 u32DataOffset;
    /// Total samples in stream. 'Samples' means inter-channel sample,
    /// i.e. one second of 44.1Khz audio will have 44100 samples regardless of the number of channels.
    /// A value of zero here means the number of total samples is unknown.
    U64 u64TotalSamples;

    ST_FLAC_SEEK_TABLE *pstSeekTable;
    U32 u32SeekEntryCount;
    U32 u32SampleRate;
   // U32 u32FileSize;
    U32 u32Duration;
    //U32 u32DataLeft;

    U8 u8Channel;
    U8 u8BitsPerSample;
    BOOLEAN bHasSeekTable;
} ST_FLAC_INFO;
#endif

#if (ENABLE_AC3)
/// AC3 info
typedef struct
{
    /// The FrameSize
    U32 u32FrameSize;
    /// cyclic redundancy check
    U16 u16Crc;
    /// Sample Rate Code
    U8 u8Fscod;
    /// Frame Size Code
    U8 u8FrmsizeCod;
    /// Bit Stream Identification
    U8 u8Bsid;
    /// Audio Coding Mode
    U8 u8Acmod;
    /// Low Frequency Effects Channel On
    U8 u8Lfeon;
    /// The Number of Audio Blocks
    U8 u8NumBlk;
    ///file start offset
    U32 u32FileStart;
    /// Is AC3P Format
    BOOLEAN bIsEAC3;
}ST_AC3_INFO;
#endif

#if (ENABLE_AMR)

 typedef struct   {
     BOOLEAN bAMR_NB;   //TRUE: AMR_NB , FALSE: AMR_WB
     U8 u8HeaderSize;
 } ST_AMR_INFO;

#define AMR_FILEREAD_BUF_LEN   (MUSIC_LYRIC_BUFFER_LEN)
#define AMR_FRAME_NUMBER_PER_SEC    50  //Each AMR duration of frame is 20ms, one seconds have 50 frames
#define AMR_ONE_FRAME_DURATION_IN_MS    20  //Each AMR duration of frame is 20ms
#define AMR_WB_HEADER_LEN       9
#define AMR_NB_HEADER_LEN       6
#define AMR_CREATE_INDEX_TABLE_TIME_OUT (5000)
#define AMR_TOC_LEN                 1

#endif

#define MUSIC_INPUT_DUMP  0
#if MUSIC_INPUT_DUMP
    U8 m_u8FileHandleMusicInput = INVALID_FILE_HANDLE;
#endif

#define ENABLE_MUSIC_BUFFER_MANAGEMENT      1

//@: All M4A Parser Codes are enclosed by the following define
#ifdef M4APARSER

#define M4A_COLLECT_TIME_OUT  (5000)
#define M4A_PROBE_TIME_OUT  (5000)
#define M4A_MAX_STCO_ENTRY_PERPAGE 1024
#define M4A_STCO_ENTRY_SIZE 4
#define M4A_CO64_ENTRY_SIZE 8
#define M4A_FRAME_TIME_OFFSET 8
#define M4A_DURATION_MARGIN 2
//#define AAC_TIME_FREEZE_FRAME 3
//#define M4A_DISCARD_LAST //discard last buffer residual
#define M4A_FFREW_FRAME 8
//#define AAC_FFREW_DELAY 150
//#define M4A_BUFFER_ADR M4VD_BITSTREAM_BUFF_AVAILABLE //buffer start address
#define M4A_PARSER_BUFFER_SIZE 4096 //use 4K bufeer

#define AAC_DSP_BUFFER_SIZE 2048//1024//1536////1024//2048
#define STCO_ENTRY_OFFEST 8
#define CO64_ENTRY_OFFEST 8
#define STSC_ENTRY_OFFEST 8
#define STSZ_ENTRY_OFFEST 8

#define M4A_STCO_ENTRY_BUFFER ((M4A_STCO_MEMORY_TYPE & MIU1) ? (((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)) | MIU_INTERVAL) : (((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR))))
#define M4A_STCO_ENTRY_BUFFER_LEN M4A_STCO_LEN
#define M4A_CO64_ENTRY_BUFFER M4A_STCO_ENTRY_BUFFER
#define M4A_CO64_ENTRY_BUFFER_LEN M4A_STCO_ENTRY_BUFFER_LEN
#define M4A_STSC_ENTRY_BUFFER M4A_STCO_ADR
#define M4A_STSC_ENTRY_BUFFER_LEN M4A_STCO_LEN
#if (defined(M4A_STSZ_ADR)&&defined(M4A_STSZ_LEN)&&(M4A_STSZ_LEN != 0))
#define M4A_STSZ_ENTRY_BUFFER ((M4A_STSZ_MEMORY_TYPE & MIU1) ? (M4A_STSZ_ADR | MIU_INTERVAL) : (M4A_STSZ_ADR))//(M4A_STCO_ENTRY_BUFFER+M4A_STCO_ENTRY_BUFFER_LEN)
#define M4A_STSZ_ENTRY_BUFFER_LEN M4A_STSZ_LEN//(M4A_STCO_LEN-M4A_STCO_ENTRY_BUFFER_LEN)
#else
#define M4A_STSZ_ENTRY_BUFFER ((SECBUF_START_MEMORY_TYPE & MIU1) ? (SECBUF_START_ADR | MIU_INTERVAL) : (SECBUF_START_ADR))//(M4A_STCO_ENTRY_BUFFER+M4A_STCO_ENTRY_BUFFER_LEN)
#define M4A_STSZ_ENTRY_BUFFER_LEN SECBUF_START_LEN//(M4A_STCO_LEN-M4A_STCO_ENTRY_BUFFER_LEN)
#endif

#define M4A_CHUNK_HEADER_SIZE                 8
#define M4A_CHUNK_ENTRY_OFFSET                8
#define MVHD_VERSION_TYPE_SIZE                4
#define MVHD_TIMESCALE_VERSION0_OFFSET        8
#define MVHD_DURATION_VERSION0_OFFSET         12
#define MVHD_TIMESCALE_VERSION1_OFFSET        16
#define MVHD_DURATION_VERSION1_OFFSET         20
#define MDHD_TIMESCALE_OFFSET                 12
#define MDHD_DURATION_OFFSET                  16
#define HDLR_MEDIA_SUBTYPE                    12
#define STSD_SAMPLERATE_OFFSET                40
#define STSD_DATAFORMAT_OFFSET                12
#define STCO_ENTRY_SIZE                        4
#define STCO_ENTRY_OFFSET                      4
#define STCO_FRAME_LOCATION_OFFSET             8
#define CO64_ENTRY_SIZE                        8
#define CO64_ENTRY_OFFSET                      4
#define CO64_FRAME_LOCATION_OFFSET             8
#define STSZ_ENTRY_SIZE                        4
#define STSZ_ENTRY_OFFSET                      8
#define STSZ_FRAME_LOCATION_OFFSET            12
#define STSC_ENTRY_OFFSET                      4
#define MDAT_LOCATION_OFFEST                   8
#define ESDS_ENTRY_OFFSET                     44
#define HDLR_ENTRY_OFFSET                     16
#define Swap64(x) ((x << 56) | ((x & 0xFF00) << 40) | ((x & 0xFF0000) << 24) | ((x & 0xFF000000) << 8) | ((x & 0xFF00000000ULL) >> 8) | ((x & 0xFF0000000000ULL) >> 24) | ((x & 0xFF000000000000ULL) >> 40) | (x >> 56))

const U32 M4ASamplerateTable[] =
{
    0, 96000, 88200, 64000, 48000, 44100, 32000,
    24000, 22050, 16000, 12000, 11025, 8000,
    7350, 0, 0, 0
};

typedef enum
{
    AUDIO_OT_NULL,
                               // Support?                Name
    AUDIO_OT_AAC_MAIN,              ///< N                       Main
    AUDIO_OT_AAC_LC,                ///< Y                       Low Complexity
    AUDIO_OT_AAC_SSR,               ///< N (code in SoC repo)    Scalable Sample Rate
    AUDIO_OT_AAC_LTP,               ///< N (code in SoC repo)    Long Term Prediction
    AUDIO_OT_SBR,                   ///< Y (in progress)         Spectral Band Replication
    AUDIO_OT_AAC_SCALABLE,          ///< N                       Scalable
    AUDIO_OT_TWINVQ,                ///< N                       Twin Vector Quantizer
    AUDIO_OT_CELP,                  ///< N                       Code Excited Linear Prediction
    AUDIO_OT_HVXC,                  ///< N                       Harmonic Vector eXcitation Coding
    AUDIO_OT_TTSI             = 12, ///< N                       Text-To-Speech Interface
    AUDIO_OT_MAINSYNTH,             ///< N                       Main Synthesis
    AUDIO_OT_WAVESYNTH,             ///< N                       Wavetable Synthesis
    AUDIO_OT_MIDI,                  ///< N                       General MIDI
    AUDIO_OT_SAFX,                  ///< N                       Algorithmic Synthesis and Audio Effects
    AUDIO_OT_ER_AAC_LC,             ///< N                       Error Resilient Low Complexity
    AUDIO_OT_ER_AAC_LTP       = 19, ///< N                       Error Resilient Long Term Prediction
    AUDIO_OT_ER_AAC_SCALABLE,       ///< N                       Error Resilient Scalable
    AUDIO_OT_ER_TWINVQ,             ///< N                       Error Resilient Twin Vector Quantizer
    AUDIO_OT_ER_BSAC,               ///< N                       Error Resilient Bit-Sliced Arithmetic Coding
    AUDIO_OT_ER_AAC_LD,             ///< N                       Error Resilient Low Delay
    AUDIO_OT_ER_CELP,               ///< N                       Error Resilient Code Excited Linear Prediction
    AUDIO_OT_ER_HVXC,               ///< N                       Error Resilient Harmonic Vector eXcitation Coding
    AUDIO_OT_ER_HILN,               ///< N                       Error Resilient Harmonic and Individual Lines plus Noise
    AUDIO_OT_ER_PARAM,              ///< N                       Error Resilient Parametric
    AUDIO_OT_SSC,                   ///< N                       SinuSoidal Coding
}AUDIO_OBJECT_TYPE;


//M4A_BUFFER_ADR is defined in sysinfo2.h
//#define M4A_STCO_ENTRY_BUFFER M4A_BUFFER_ADR + M4A_PARSER_BUFFER_SIZE //base + 4096
//#define M4A_STCO_ENTRY_BUFFER_LEN (M4A_BUFFER_LEN - M4A_PARSER_BUFFER_SIZE) //60K MAX
//#define M4A_WRITE_BUFFER_BASE M4A_READ_BUFFER_BASE + 4096

#define INIT_VOLUME stGenSetting.g_SoundSetting.Volume

#define CBR_DURATION_LIMIT   0x300000 // 3MB
#define MP3_DATA_SIZE_NEED_FOR_VBR_HEADER_PARSING 0x30
#define MP3_DATA_SIZE_NEED_FOR_FRAME_HEADER_PARSING 0x8

#if (ENABLE_AAC)

#define MP4_PARSER_ADTS_HEADER_SIZE 7 //bytes
static U32 _u32M4aCurrentFrameIndex = 0;
static U32 u32M4aPreviousFrameIndex = 0;
static U32 u32M4aReadLeft = 0;
static U32 u32M4aTimeTemp = 0;
static BOOLEAN _bM4aEnableFFFB = FALSE;
static BOOLEAN bM4aRelocateFilePosition = FALSE;

static U32 _u32FrameArrayIndex = 0;
static U32 _u32StszTotalFrame = 0;
static U32 _u32StszCurrentFrame = 0;
static U32 _u32ADTSWriteLeft=0;
static U8 _pu8ADTSHeader[8];  //0~6:ADTS header   7:Left Size
static U32 u32MaxCurrentTimeTemp=0;  //For AAC
#endif

code const U32 samplerate_table[] = {
0, 96000, 88200, 64000, 48000, 44100, 32000,
24000, 22050, 16000, 12000, 11025, 8000,
7350, 0, 0, 0
};

#if (ENABLE_AAC)
U8 box_four_buffer[4];
U8 postfix_seven_buffer[7];

static ST_M4A_INFO stM4aInfo;

//for m4a audio stsc entry counter smaller than STSC_ENTRY_LIMIT
U32 u32EntryInfoSmaller[STSC_ENTRY_LIMIT*STSC_INFO_ENTRY_INFO_COUNT];


static BOOLEAN _bM4aJustOpened = FALSE;
static BOOLEAN _bM4aTimerbyDSP = FALSE;
#endif

#if (ENABLE_FLAC)
#define FLAC_SEEKPOINT_LEN 18   //Sample Number:   8 byte
                                //File Offset:     8 byte
                                //how many sample: 2 byte

#endif

#if (ENABLE_AC3)
//AC3
#define AC3_SYNC_WORD 0x0B77
#define AC3_SYNC_WORD_BE 0x770B
#define AC3_PARSE_BUFFER_SIZE 0x10
#endif

static EN_MUSIC_STATE enTimeoutCheck_Mp3PrevState = STATE_MUSIC_NONE;
static U32 u32TimeoutCheck_PreFilePosition = -1; // set to -1 is ok because all we need is a value that is not quite possible
static U32 u32TimeoutCheck_TimeMarker = 0;

static BOOLEAN bStop_After_FB_To_Begin = FALSE;

#if (ENABLE_OGG)
static OggInfo g_OggInfo;
#endif

#endif

#if (ENABLE_AMR)
static ST_AMR_INFO m_AMRInfo;
//AMR Narrow band frame size table
const U8 NBpacked_size[16] = {12, 13, 15, 17, 19, 20, 26, 31, 5, 0, 0, 0, 0, 0, 0, 0};
//AMR Wide band frame size table
const U8 WBpacked_size[16] = {17, 23, 32, 36, 40, 46, 50, 58, 60,  5,  0,  0,  0,  0,  0,  0};
const U8 *pu8AMRPackedSize = NBpacked_size;
#endif

//WAV
ST_WAV_CHUNK stWavChunk;

//PCM
static ST_PCM_PARAM stPCMParam;

//DTS
static const U32 DTS_Sample_Rates[] =
{
    0, 8000, 16000, 32000, 0, 0, 11025, 22050, 44100, 0, 0,
    12000, 24000, 48000, 96000, 192000
};

static const int DTS_Bit_Rates[] =
{
    32000, 56000, 64000, 96000, 112000, 128000,
    192000, 224000, 256000, 320000, 384000,
    448000, 512000, 576000, 640000, 768000,
    896000, 1024000, 1152000, 1280000, 1344000,
    1408000, 1411200, 1472000, 1536000, 1920000,
    2048000, 3072000, 3840000, 1/*open*/, 2/*variable*/, 3/*lossless*/
};

#if (ENABLE_AC3)

//ac3
static const U32 u32Ac3BitrateTable[38] =
{
    32000,32000,40000,40000,48000,48000,56000,56000, 64000, 64000,
    80000,80000,96000,96000,112000,112000,128000,128000, 160000, 160000,
    192000,192000,224000,224000,256000,256000,320000,320000, 384000, 384000,
    448000,448000,512000,512000,576000,576000,640000,640000
};
static const U32 u32Ac3FramesizeTable[3][38] =
{
    // Unit: Words(16bits)/syncframe
     {
         64,64,80,80,96,96,112,112, 128, 128,                //48K
         160,160,192,192,224,224,256,256, 320, 320,
         384,384,448,448,512,512,640,640, 768, 768,
         896,896,1024,1024,1152,1152,1280,1280},
     {
         69,70,87,88,104,105,121,122, 139, 140,              //44.1K
         174,175,208,209,243,244,278,279, 348, 349,
         417,418,487,488,557,558,696,697, 835, 836,
         975,976,1114,1115,1253,1254,1393,1394},
     {
          96,96,120,120,144,144, 168, 168, 192, 192,          //32K
          240,240,288,288,336,336, 384, 384, 480,480,
          576,576,672,672,768,768, 960, 960, 1152,1152,
          1344,1344,1536,1536,1728,1728, 1920, 1920}
};
static const U32 u32Ac3SampleRateTable[4] =
{
    48000, 44100, 32000,48000
};
static const U32 u32Ac3ChannelTable[8] =
{
    2,1,2,
    3,3,4,
    4,5
};
static const U32 u32Ac3NumBlkTable[4]=
{
    1,2,3,6
};
#endif

#if (ENABLE_AMR)
static U32 u32AMR_Frame_Buf_Total_Count = (M4A_STCO_LEN/sizeof(unsigned long));
static U32 u32AMRFrameAddr = ((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR));
#endif

//error code
EN_MUSIC_ERRCODE _enMusic_ErrCode = E_MUSIC_ERR_NONE;
//-------------------------------------------------------------------------------------------------
// Macros
//-------------------------------------------------------------------------------------------------
#define MUSIC_DBG(x)     //x
#define MUSIC_DBG1(x)    //x
#define MP3_SHOW_TIMEOUT 4000

/******************************************************************************/
/*                                 Enum                                       */
/******************************************************************************/
typedef enum
{
    EN_MP3_PLAY,
    EN_MP3_PLAY_ALL,
    EN_MP3_PLAY_ALL_DISK,
    EN_MP3_STOP,
    EN_MP3_NUMBER,
} EN_MP3_MODE;

//-------------------------------------------------------------------------------------------------
// Global Variables
//-------------------------------------------------------------------------------------------------
//static EN_MP3_MODE g_u8MP3PlayMode;

//-------------------------------------------------------------------------------------------------
// Local Variables
//-------------------------------------------------------------------------------------------------
EN_MUSIC_STATE  enMusicState   =  STATE_MUSIC_NONE;
EN_MUSIC_STATE  enPreMusicState = STATE_MUSIC_NONE;

static EN_RET       enMp3RetVal;

static U32 u32Mp3ShowTimer;
static U32 u32Mp3TimeOutDefault = MP3_SHOW_TIMEOUT; // ms

static FileEntry *m_pMp3FileEntry;
static U32 u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
static U32 u32Mp3FileBytesLeft;
static MP3_PLAY_STATUS enMp3PlayStatus = MP3_STATUS_STOP;

static BOOLEAN m_bCheckFftoEnd = FALSE;

static BOOLEAN _bMusicRecording = FALSE;
static U32 _u32MusicRecordLength = 0;
static U32 _u32MusicRecordStartTime = 0;
static U32 _u32MusicRecordTotalTime = 0;

static En_DVB_decSystemType enCurrentDecSystem;
static BOOLEAN bReloadDsp;
#if (ENABLE_LYRICS3) || (ENABLE_LRC_LYRIC)
static U16 u16LyricTagCount;
#endif  // #if (ENABLE_LYRICS3) || (ENABLE_LRC_LYRIC)
static ST_MP3_INFO stMp3Info;
static EN_MP3_SPEED enMp3PlaySpeed = EN_MP3_SPEED_X1;
U32 u32FfRewTimer;
static EN_MUSIC_TYPE enCurrentMusicType;
//static BININFO KeySoundBinInfo;
#if (ENABLE_AAC)
// for play QT format
static BOOLEAN m_IsQtFormat = FALSE;
static BOOLEAN m_bPlayQtFormat = TRUE;
#endif

#if (ENABLE_FLAC)
static ST_FLAC_INFO m_stFlacInfo;
#endif

#if (ENABLE_AC3)
static ST_AC3_INFO m_stAc3Info;
#endif

//-------------------------------------------------------------------------------------------------
// Local Function Prototypes
//-------------------------------------------------------------------------------------------------
static BOOLEAN MApp_Music_CollectInfo(ST_MP3_INFO *pMp3Info);
static void MApp_Music_UpdatePlayTime(void);

#if (ENABLE_FLAC)
static BOOLEAN _MApp_Music_Flac_CollectInfo(void);
static BOOLEAN _MApp_Music_Flac_DataInput(U32 dwReqAddress, U32 u32ReqBytes);
static BOOLEAN _MApp_Music_FLACTimeOffset(U32 u32GotoTimeMs);
static BOOLEAN _MApp_Music_FLACTimeOffsetNoTable(U32 u32GotoTimeMs);

#endif

#if (ENABLE_AC3)
static BOOLEAN _MApp_Music_Ac3_CollectInfo(void);
static BOOLEAN _MApp_Music_Ac3_DataInput(U32 dwReqAddress, U32 u32ReqBytes);
static BOOLEAN _MApp_Music_Ac3TimeOffset(U32 u32GotoTimeMs);
#endif

#if (ENABLE_AAC)
static BOOLEAN MApp_Music_IsAAC(void);

//For check AAC Iinfo.
static BOOLEAN MApp_AAC_Frame_Parsing(void);
//static code U16 AACSampleRateTable[16]=
//{96000, 88200, 64000, 48000, 44100, 32000, 24000, 22050, 16000, 12000, 11025, 8000, MP3_INVALID_RATE, MP3_INVALID_RATE, MP3_INVALID_RATE, MP3_INVALID_RATE}; // For AAC ADTS
static U32 AACID3Jump=0;
BOOLEAN M4AParser_Get_AAC_Info(ST_MP3_INFO *pMp3Info);
#endif

#if (ENABLE_WAV)
//WAV
static BOOLEAN _MApp_Music_Wav_CollectInfo(void);
static BOOLEAN _MApp_Music_Wav_DataInput(U32 dwReqAddress, U32 u32ReqBytes);

//PCM
static BOOLEAN _MApp_Music_PCM_CollectInfo(void);
static BOOLEAN _MApp_Music_PCM_DataInput(U32 dwReqAddress, U32 u32ReqBytes);
#endif

#if (ENABLE_OGG)
//Ogg
static BOOLEAN _MApp_Music_Ogg_CollectInfo(void);
static BOOLEAN MApp_Music_OggParser_WriteDSP(U32 dwReqAddress, U32 u32ReqBytes);
#endif

#if (ENABLE_AMR)
//AMR
static U32 _MApp_Music_AMRGetDurationAndFrameIdxTable(U32 u32Buf , U32 u32BufLen);
static BOOLEAN _MApp_Music_AMR_CollectInfo(void);
static BOOLEAN _MApp_Music_AMRTimeOffset(U32 u32GotoTimeMs);
#endif



//-------------------------------------------------------------------------------------------------
// Function Implementation
//-------------------------------------------------------------------------------------------------
//extern void MApp_UiMenu_DrawMenuPage(void);

#if (ENABLE_AAC)
static BOOLEAN MApp_AAC_Frame_Parsing(void)
{
    //U16 u16SampleRate;
    //U16 u16Offset=0;
    U32 u32TagSize=0,u32Position;
    //U8 *pFileBufPtr;

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        MUSIC_DBG(printf("Open file failed\n"));
        return TRUE;
    }

    // get MP3 ID3 v2 information
    msAPI_Stream_Seek(u32Mp3FileHandle, 0);
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN); // 4k is xdata window size

    u32TagSize = msAPI_Music_Parse_ID3v2(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN, &stMp3Info.stID3v2, FALSE);

    if(u32TagSize > 0)
    {
        stMp3Info.bID3TagV2 = TRUE;
    }

    u32Position=u32TagSize;
    AACID3Jump=u32TagSize;

    MUSIC_DBG(printf("\nFound ID3 tag size=0x%lx\n",u32TagSize));

    //msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32Position, E_DATA_STREAM_SEEK_SET);
    //u32Mp3FileBytesLeft=msAPI_DataStreamIO_Read(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), FAT_SECTOR_SIZE_512BYTE * 8); // 4k is xdata window size

    /*
    //ADTS
    while(u32Position<u32FileLength)
    //while(u32Position< FAT_SECTOR_SIZE_512BYTE * 8*2)
    {
        msAPI_Timer_ResetWDT();

        if(u16Offset>FAT_SECTOR_SIZE_512BYTE * 8)
        {
            //u16Offset-=FAT_SECTOR_SIZE_512BYTE * 8;
            u16Offset=0;
            //msAPI_DataStreamIO_Seek(u32Mp3FileHandle, (u32Position/(FAT_SECTOR_SIZE_512BYTE * 8)));
            msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32Position, E_DATA_STREAM_SEEK_SET);
            u32Mp3FileBytesLeft=msAPI_DataStreamIO_Read(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), FAT_SECTOR_SIZE_512BYTE * 8); // 4k is xdata window size
            pFileBufPtr = (U8 *)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));
        }
        else
        {
            pFileBufPtr = (U8 *)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)) + u16Offset;
        }


        if ((pFileBufPtr[0] & 0xff) && ( (pFileBufPtr[1] & 0xf0) | 0x0f))
        {
            u32TagSize=(U32) (pFileBufPtr[3] & 0x03);
            u32TagSize <<= 8;
            u32TagSize |= (U32) (pFileBufPtr[4] & 0xFF);
            u32TagSize <<= 3;
            u32TagSize |= (U32) ((pFileBufPtr[5] & 0xE0)>>5);

            u16SampleRate=AACSampleRateTable[((pFileBufPtr[2] & 0x3c) >> 2)];
            //u16SampleRate=((pFileBufPtr[2] & 0x3c) >> 2);

            //printf("find ADTS, pFileBufPtr[3]=%bx, pFileBufPtr[4]=%bx, pFileBufPtr[5]=%bx,Frame length=0x%lx ,u16SampleRate=%u\n",pFileBufPtr[3], pFileBufPtr[4], pFileBufPtr[5],u32TagSize,u16SampleRate);

            if(u32TagSize==0)
            {
                u16Offset=0;
                //msAPI_DataStreamIO_Seek(u32Mp3FileHandle, (u32Position/(FAT_SECTOR_SIZE_512BYTE * 8)));
                msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32Position, E_DATA_STREAM_SEEK_SET);
                u32Mp3FileBytesLeft=msAPI_DataStreamIO_Read(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), FAT_SECTOR_SIZE_512BYTE * 8); // 4k is xdata window size
                pFileBufPtr = (U8 *)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));
            }
            else
            {
                u16Offset+=u32TagSize;
                u32Position+=u32TagSize;
            }
            //printf("u32Position=0x%lx\n",u32Position);
        }
        else
        {
            u16Offset=0;
            //msAPI_DataStreamIO_Seek(u32Mp3FileHandle, (u32Position/(FAT_SECTOR_SIZE_512BYTE * 8)));
            msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32Position, E_DATA_STREAM_SEEK_SET);
            u32Mp3FileBytesLeft=msAPI_DataStreamIO_Read(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), FAT_SECTOR_SIZE_512BYTE * 8); // 4k is xdata window size
            pFileBufPtr = (U8 *)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));
        }

        //u32Position+=3;
    }*/

    //ADIF

    //printf("u32Mp3FileBytesLeft=%lu, u32FileLength=%lu\n",u32Mp3FileBytesLeft,u32FileLength);

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    return TRUE;
}
#endif

void MApp_Music_SetFileEntry(FileEntry *pEntry)
{
    m_pMp3FileEntry = pEntry;
}

#if 0
static U32 MApp_Music_SecToByte(U32 u32Sec)
{
    u32Sec = 128000 * 5;
    return u32Sec;
}
#endif

BOOLEAN MApp_Music_Initial(void)
{
#if (ENABLE_AAC)
    memset(&stM4aInfo, 0, sizeof(ST_M4A_INFO));
#endif
    memset(&stMp3Info, 0, sizeof(stMp3Info));
#if (ENABLE_FLAC)
    memset(&m_stFlacInfo, 0, sizeof(m_stFlacInfo));
#endif
#if (ENABLE_AC3)
    memset(&m_stAc3Info, 0, sizeof(m_stAc3Info));
RestartInitial:
#endif
    _enMusic_ErrCode = E_MUSIC_ERR_NONE;
    stMp3Info.bCheckFfFb = TRUE; //Enable FF/FB
    if(enCurrentMusicType == EN_MUSIC_MP3)
    {
        if (MApp_Music_CollectInfo(&stMp3Info) == FALSE)
        {
            return FALSE;
        }
        MUSIC_DBG(printf("L: %u, D: %u, B: %lu, F: %u\n", stMp3Info.enLayer, stMp3Info.u32Duration, (U32)stMp3Info.u16BitRate * 1000, stMp3Info.u8Flag));
#if 0
        if (enMPlayerState==STATE_MPLAYER_MP3)
        {
            g_u16GroupXPos = 0;
            g_u16GroupYPos = 0;
            MApp_UiMenu_DrawComponents(DrawMp3InfoBG);
            MApp_UiMenu_DrawComponents(DrawMp3InfoText);
            g_u16GroupXPos = UI_MEDIA_PLAYER_INFO_X;
            g_u16GroupYPos = UI_MEDIA_PLAYER_INFO_Y;
            MApp_UiMenu_DrawComponents(DrawMp3InfoItem);
        }
#endif
        if (stMp3Info.enLayer == EN_MP3_LAYER_3)
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_MP3;
        }
        else if ((stMp3Info.enLayer == EN_MP3_LAYER_1) || (stMp3Info.enLayer == EN_MP3_LAYER_2))
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_MPEG;
        }
        else
        {
            MUSIC_DBG(printf("Unknown layer: %u\n", stMp3Info.enLayer));
            return FALSE;
        }
    }
#if (ENABLE_AAC)
    else if(enCurrentMusicType == EN_MUSIC_AAC)
    {
        //Eric-PH Lee 20080613:Parsing AAC for jump ID3 tag!!
        MApp_AAC_Frame_Parsing();

        AAC_ERR2(printf("AAC initial\n"));
#if 0
        g_u16GroupXPos = 0;
        g_u16GroupYPos = 0;
        MApp_UiMenu_DrawComponents(DrawMp3InfoBG);
        g_u16GroupXPos = UI_MEDIA_PLAYER_INFO_X;
        g_u16GroupYPos = UI_MEDIA_PLAYER_INFO_Y;
        MApp_UiMenu_DrawComponents(DrawMp3InfoItem);
#endif
        enCurrentDecSystem = MSAPI_AUD_DVB_AAC;
        msAPI_Music_FileEndDataHandle(0);

#ifdef M4APARSER
        //reset stM4aInfo
        memset(&stM4aInfo, 0, sizeof(ST_M4A_INFO));
        if (M4AParser_Get_M4A_Info(&stM4aInfo) == TRUE)
        {
            AAC_DBG(printf("found stco: %d   loc: 0x%x\n", stM4aInfo.bFoundstco, stM4aInfo.u32stcoFrameLocation));
            AAC_DBG(printf("found co64: %d   loc: 0x%x\n", stM4aInfo.bFoundco64, stM4aInfo.u32co64FrameLocation));
            if(stM4aInfo.enCodec==EN_MUSIC_AC3)
            {
                enCurrentMusicType = EN_MUSIC_AC3;
                AAC_DBG(printf("RestartInitial"));
                goto RestartInitial;
            }
            else if(stM4aInfo.enCodec!=EN_MUSIC_AAC)
            {
                AAC_ERR(printf("not AC3, not AAC; won't support\n"));
                return FALSE;
            }

            if(stM4aInfo.u8object_type != AUDIO_OT_AAC_LC)
            {
                AAC_ERR(printf("[esds] object type is :%d, not supported, we only support LC profile\n", stM4aInfo.u8object_type));
                return FALSE;
            }
            else
            {
                AAC_DBG(printf("[esds] object type is :%d, LC profile.\n", stM4aInfo.u8object_type));
            }

            AAC_ERR(printf("mdat loc: %lu, SR: %u, mdat size: %lu, stco:%d\n", stM4aInfo.u32MdatLocation,stM4aInfo.u8SampleRateIndex,stM4aInfo.u32MdatSize, stM4aInfo.bFoundstco));

            if(stM4aInfo.u8channelConfiguration == 0)
            {
                AAC_ERR(printf("[M4A]ERROR: channel: %u\n", stM4aInfo.u8channelConfiguration));
                return FALSE;
            }

            if ((m_IsQtFormat == TRUE) && (m_bPlayQtFormat == FALSE))
            {
                AAC_DBG(printf("Don't play QT format\n"));
                m_IsQtFormat = FALSE;
                return FALSE;
            }

            if (stM4aInfo.bFoundhdlr_vide)
            {
                AAC_DBG(printf("Don't play. It's mp4 with video.\n"));
                return FALSE;
            }

            if (stM4aInfo.u8SampleRateIndex != 255 )
            {
                //msAPI_Music_SetSampleRateIndex((U16)boxM4a.u8SampleRateIndex);
                AAC_ERR2(printf("@M4a inform samplerate\n"));
            }
            else
            {
                //msAPI_Music_SetSampleRateIndex(0);
                AAC_ERR(printf("@M4a samplerate error\n"));
            }

            //save frame infor here only when DRAM is available
            // clear first
            msAPI_MIU_Clear(0,(U32)M4A_STCO_ENTRY_BUFFER,M4A_STCO_ENTRY_BUFFER_LEN,0);

            if(M4AParser_SaveFrameLocation()==FALSE)
            {
                AAC_ERR(printf("M4AParser_SaveFrameLocation fail\n"));

                if((stM4aInfo.stscInfo.pu32EntryInfo!=NULL)  && (stM4aInfo.stscInfo.pu32EntryInfo != u32EntryInfoSmaller))
                {
                    msAPI_Memory_Free(stM4aInfo.stscInfo.pu32EntryInfo,BUF_ID_FILEBROWER);
                    stM4aInfo.stscInfo.pu32EntryInfo = NULL;
                    AAC_ERR(printf("free boxM4a.stscInfo.pu32EntryInfo because M4AParser_SaveFrameLocation fail\n"));

                }
                return FALSE;
            }

            if ((stM4aInfo.bFoundstco || stM4aInfo.bFoundco64) && _u32FrameArrayIndex > 0)
            {
                AAC_ERR2(printf("@M4A total frame %lu\n",_u32FrameArrayIndex));
                _bM4aEnableFFFB = TRUE;
            }
            else
            {
                AAC_ERR(printf("@M4A Disalbe FF/FB for no frame info, Array Index:%lu\n",_u32FrameArrayIndex));
                _bM4aEnableFFFB = FALSE;
                stMp3Info.bCheckFfFb = FALSE; //Disable FF/FB
            }

            AAC_DBG(printf("@M4A Duration in second:%d\n",stM4aInfo.u32Duration ));
        }
        else if(M4AParser_Get_AAC_Info(&stMp3Info))
        {
            _bM4aEnableFFFB = FALSE;
            stMp3Info.bCheckFfFb = TRUE;  // Enable FF/FB for AAC
            _u32FrameArrayIndex = 0;
            //msAPI_Music_SetSampleRateIndex(0);
        }
        else if(_enMusic_ErrCode != E_MUSIC_ERR_NONE)
        {
            AAC_ERR(printf("ERROR CODE:%d\n", _enMusic_ErrCode));
            return FALSE;
        }
        else //no header info in aac
        {
            AAC_ERR2(printf("M4a has no header...\n"));
            AAC_ERR(printf("@M4A Disalbe FF/FB for no frame info\n"));
            _bM4aEnableFFFB = FALSE;
            stMp3Info.bCheckFfFb = FALSE; //Disable FF/FB
            _u32FrameArrayIndex = 0;
            //msAPI_Music_SetSampleRateIndex(0);
        }
#endif
    }
#endif
#if (ENABLE_FLAC)
    else if(enCurrentMusicType == EN_MUSIC_FLAC)
    {
        memset(&m_stFlacInfo, 0, sizeof(m_stFlacInfo));
    if (_MApp_Music_Flac_CollectInfo() == FALSE)
    {
        FLAC_ERR(printf("FLAC collection fail\n"));

        if(m_stFlacInfo.pstSeekTable!=NULL)
        {
            msAPI_Memory_Free(m_stFlacInfo.pstSeekTable,BUF_ID_FILEBROWER);
            FLAC_DBG(printf("free stFlacInfo.pSeekTable\n"));
            m_stFlacInfo.pstSeekTable = NULL;

        }
        return FALSE;
    }
    FLAC_DBG(printf("FLAC initial\n"));
    FLAC_DBG(printf("stMp3Info.u32Duration:%lu\n",stMp3Info.u32Duration));
    FLAC_DBG(printf("stFlacInfo.u32DataOffset:%lu\n",m_stFlacInfo.u32DataOffset));

    enCurrentDecSystem = MSAPI_AUD_DVB_FLAC;   //loader FLAC decoder

    }
#endif
#if (ENABLE_AC3)
    else if(enCurrentMusicType == EN_MUSIC_AC3)
    {
        memset(&m_stAc3Info, 0, sizeof(m_stAc3Info));
        if (_MApp_Music_Ac3_CollectInfo() == FALSE)
        {
            AC3_ERR(printf("AC3 collection fail\n"));
            return FALSE;
        }
        AC3_DBG(printf("AC3 initial\n"));
        AC3_DBG(printf("stMp3Info.u32Duration:%lu\n",stMp3Info.u32Duration));
        AC3_DBG(printf("stAc3Info.bIsEAC3:%d\n",m_stAc3Info.bIsEAC3));

        if(m_stAc3Info.bIsEAC3==TRUE)  //ac3+
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_AC3P;
        }
        else
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_AC3;   //loader AC3 decoder
        }
    }
#endif

#if (ENABLE_WAV)
    else if(enCurrentMusicType == EN_MUSIC_WAV)
    {
        MUSIC_DBG(printf("WAV init\n"));
        if(_MApp_Music_Wav_CollectInfo() == FALSE)
        {
            return FALSE;
        }

        if(stWavChunk.bIsDTS)
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_DTS;
        }
        else
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_XPCM;
        }
        //msAPI_Music_SetXPCMParam((XPCM_TYPE)(stWavChunk.u16FormatTag), (U8)(stWavChunk.u16Channels-1), (U16)stWavChunk.u32SamplesPerSec, (U8)stWavChunk.u16BitsPerSample, stWavChunk.u16BlockSize, 0);
    }
    else if(enCurrentMusicType == EN_MUSIC_PCM)
    {
        MUSIC_DBG(printf("PCM init\n"));
        if(_MApp_Music_PCM_CollectInfo() == FALSE)
        {
            return FALSE;
        }
        enCurrentDecSystem = MSAPI_AUD_DVB_XPCM;
        //last param:0x77 means dsp auto detect big endia/little endian; 0xff means Big endian; 0x0 means little endian
        //msAPI_Music_SetXPCMParam((XPCM_TYPE)(stPCMParam.u16FormatTag), (U8)(stPCMParam.u16Channels-1), (U16)stPCMParam.u32SamplesPerSec, (U8)stPCMParam.u16BitsPerSample, stPCMParam.u16BlockSize, 0x77);
    }
#endif
    else if(enCurrentMusicType == EN_MUSIC_LOAS)
    {
        enCurrentDecSystem = MSAPI_AUD_DVB_AAC;
        u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);
        stMp3Info.u32MusicDataBytesLeft = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        msAPI_DataStreamIO_Close(u32Mp3FileHandle);
        u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
    }
#ifdef OGG_PARSER
#if (ENABLE_OGG)
    else if(enCurrentMusicType == EN_MUSIC_OGG)
    {
        OGG_DBG(printf("OGG init\n"));
        if(_MApp_Music_Ogg_CollectInfo() == FALSE)
        {
            OGG_ERR(printf("OGG init fail\n"));
            return FALSE;
        }
        g_OggInfo.bNeedAddHeader = TRUE;
        g_OggInfo.u32VorbisHeaderLeftSizeToWrite = g_OggInfo.u32VorbisHeaderTotalSize;
        enCurrentDecSystem = MSAPI_AUD_DVB_VORBIS;
    }
#endif
#endif
#if (ENABLE_AMR)
    else if( (enCurrentMusicType == EN_MUSIC_AMR) || (enCurrentMusicType == EN_MUSIC_AWB) )
    {
        AMR_DBG(printf("AMR init\n"));
        if(_MApp_Music_AMR_CollectInfo() == FALSE)
        {
            AMR_DBG(printf("AMR init fail\n"));
            return FALSE;
        }

        if ( m_AMRInfo.bAMR_NB )
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_AMR_NB;
        }
        else
        {
            enCurrentDecSystem = MSAPI_AUD_DVB_AMR_WB;
        }
    }
#endif
    else
    {
        MUSIC_DBG(printf("error type\n"));
        return FALSE;
    }


    msAPI_Music_Init(enCurrentDecSystem, INIT_VOLUME);

    //Set parameters after music init!
    switch ( enCurrentMusicType )
    {
    case EN_MUSIC_FLAC:
        MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_8KB, 0);
        break;
    case EN_MUSIC_MP3:
        MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_8KB, 0);
        break;
    case EN_MUSIC_WAV:
        MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_8KB, 0);
        if(stWavChunk.bIsDTS)
        {
        //now only T3 NonOs has define Audio_DTS_ESData_ByteSwap_ON.
        //after all chip define , below line can be removed.
        #ifdef DTS_PARSER
            if(stWavChunk.bDTSIsLittleEndian)
            {
                MApi_AUDIO_SetDTSCommonCtrl(Audio_DTS_infoType_ESData_ByteSwap, Audio_DTS_Ctrl_ByteSwap_ON);
            }
            else
            {
                MApi_AUDIO_SetDTSCommonCtrl(Audio_DTS_infoType_ESData_ByteSwap , Audio_DTS_Ctrl_ByteSwap_OFF);
            }
        #endif
        }
        else
        {
            #ifdef DTS_PARSER
            MApi_AUDIO_SetDTSCommonCtrl(Audio_DTS_infoType_ESData_ByteSwap , Audio_DTS_Ctrl_ByteSwap_OFF);
            #endif

            if(stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM)
            {
                //for M_ADPCM , last parameter mean sampleperblock=2 + 2 * (blockalign - 7 * psf->sf.channels) / psf->sf.channels, otherwise it mean little/big endian
                msAPI_Music_SetXPCMParam((XPCM_TYPE)(stWavChunk.u16FormatTag), (U8)(stWavChunk.u16Channels-1), (U16)stWavChunk.u32SamplesPerSec, (U8)stWavChunk.u16BitsPerSample, stWavChunk.u16BlockSize, 2 + 2 *(stWavChunk.u16BlockSize - 7*stWavChunk.u16Channels)/stWavChunk.u16Channels);
            }
            else if(stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM)
            {
                //for IMA_ADPCM , last parameter mean sampleperblock=1 + 2 * (blockalign - 4 * psf->sf.channels) / psf->sf.channels, otherwise it mean little/big endian
                msAPI_Music_SetXPCMParam((XPCM_TYPE)(stWavChunk.u16FormatTag), (U8)(stWavChunk.u16Channels-1), (U16)stWavChunk.u32SamplesPerSec, (U8)stWavChunk.u16BitsPerSample, stWavChunk.u16BlockSize, 1 + 2 *(stWavChunk.u16BlockSize - 4*stWavChunk.u16Channels)/stWavChunk.u16Channels);
            }
            else if(stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_ALAW)
            {
                msAPI_Music_SetXPCMParam((XPCM_TYPE)(stWavChunk.u16FormatTag), (U8)(stWavChunk.u16Channels-1), (U16)stWavChunk.u32SamplesPerSec, (U8)stWavChunk.u16BitsPerSample, stWavChunk.u16BlockSize, 0xff);
            }
            else
            {
                msAPI_Music_SetXPCMParam((XPCM_TYPE)(stWavChunk.u16FormatTag), (U8)(stWavChunk.u16Channels-1), (U16)stWavChunk.u32SamplesPerSec, (U8)stWavChunk.u16BitsPerSample, stWavChunk.u16BlockSize, 0);
            }
        }
        break;
    case EN_MUSIC_PCM:
        #ifdef DTS_PARSER
        MApi_AUDIO_SetDTSCommonCtrl(Audio_DTS_infoType_ESData_ByteSwap , Audio_DTS_Ctrl_ByteSwap_OFF);
        #endif
        if(stPCMParam.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM)
        {
            //for M_ADPCM , last parameter mean sampleperblock=2 + 2 * (blockalign - 7 * psf->sf.channels) / psf->sf.channels, otherwise it mean little/big endian
            msAPI_Music_SetXPCMParam((XPCM_TYPE)(stPCMParam.u16FormatTag), (U8)(stPCMParam.u16Channels-1), (U16)stPCMParam.u32SamplesPerSec, (U8)stPCMParam.u16BitsPerSample, stPCMParam.u16BlockSize, 2 + 2 *(stPCMParam.u16BlockSize - 7*stPCMParam.u16Channels)/stPCMParam.u16Channels);
        }
        else if(stPCMParam.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM)
        {
            //for IMA_ADPCM , last parameter mean sampleperblock=1 + 2 * (blockalign - 4 * psf->sf.channels) / psf->sf.channels, otherwise it mean little/big endian
            msAPI_Music_SetXPCMParam((XPCM_TYPE)(stPCMParam.u16FormatTag), (U8)(stPCMParam.u16Channels-1), (U16)stPCMParam.u32SamplesPerSec, (U8)stPCMParam.u16BitsPerSample, stPCMParam.u16BlockSize, 1 + 2 *(stPCMParam.u16BlockSize - 4*stPCMParam.u16Channels)/stPCMParam.u16Channels);
        }
        else
        {
            //last param:0x77 means dsp auto detect big endia/little endian; 0xff means Big endian; 0x0 means little endian
            msAPI_Music_SetXPCMParam((XPCM_TYPE)(stPCMParam.u16FormatTag), (U8)(stPCMParam.u16Channels-1), (U16)stPCMParam.u32SamplesPerSec, (U8)stPCMParam.u16BitsPerSample, stPCMParam.u16BlockSize, 0x77);
        }
        break;
    default:
        break;
    }

  /*  if(msAPI_AUD_IsAudioMutedByUser())
    {
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    }
    else
    {
        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    }*/
    bReloadDsp = FALSE;

    enMp3PlayStatus = MP3_STATUS_PLAYING;

#ifdef M4APARSER
    if(enCurrentMusicType == EN_MUSIC_MP3) //mp3 update time
    {
#endif
        MApp_Music_UpdatePlayTime();

#ifdef M4APARSER
     }
#endif
    return TRUE;
}

void MApp_Music_CloseFile(void)
{
    if(u32Mp3FileHandle != INVALID_DATA_STREAM_HDL)
    {
        msAPI_DataStreamIO_Close(u32Mp3FileHandle);
        u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
    }
}

void MApp_Music_Stop(void)
{
#if (ENABLE_LAST_MEMORY==1)&&ENABLE_LAST_MEMORY_ENABLE_MUSIC
    if (m_u8LastMemoryCheck==TRUE)
    {
        MApp_MPlayer_LastMemory_SetResumePlayAttribute(0);
        m_u8LastMemoryCheck=FALSE;
    }
#endif

#if (ENABLE_FLAC)
    if(m_stFlacInfo.pstSeekTable!=NULL)
    {
        msAPI_Memory_Free(m_stFlacInfo.pstSeekTable,BUF_ID_FILEBROWER);
        FLAC_DBG(printf("free stFlacInfo.pSeekTable\n"));
        m_stFlacInfo.pstSeekTable = NULL;
    }
#endif

    msAPI_Music_StopDecode();

#if (ENABLE_AAC)
    //if m4a file is playing and user press stop , next or previous music
    //we need to release boxM4a.stscInfo.u32EntryInfo if necessary
    if((stM4aInfo.stscInfo.pu32EntryInfo!=NULL) && (stM4aInfo.stscInfo.pu32EntryInfo != u32EntryInfoSmaller))
    {
        msAPI_Memory_Free(stM4aInfo.stscInfo.pu32EntryInfo,BUF_ID_FILEBROWER);
        stM4aInfo.stscInfo.pu32EntryInfo = NULL;
        AAC_ERR(printf("free boxM4a.stscInfo.pu32EntryInfo at Music Stop\n"));
    }
#endif

    MApp_Music_CloseFile();

#if MUSIC_INPUT_DUMP
    if(m_u8FileHandleMusicInput!=INVALID_FILE_HANDLE)
    {
        msAPI_FCtrl_FileClose(m_u8FileHandleMusicInput);
    }
    m_u8FileHandleMusicInput = INVALID_FILE_HANDLE;
#endif

#ifdef DTS_PARSER
    MApi_AUDIO_SetDTSCommonCtrl(Audio_DTS_infoType_ESData_ByteSwap , Audio_DTS_Ctrl_ByteSwap_OFF);
#endif

    u8MusicFFFWMode = MP3_NORMAL_MODE;
    enMp3PlayStatus = MP3_STATUS_STOP;
    enMusicState = STATE_MUSIC_STANDBY;

    _bMusicRecording = FALSE;
    _u32MusicRecordLength = 0;
    _u32MusicRecordStartTime = 0;
    stPCMParam.bIsConfig = FALSE;
}

BOOLEAN MApp_Music_OpenFile(void)
{
    MUSIC_DBG(printf("\nOpen File"));
    if(u32Mp3FileHandle != INVALID_DATA_STREAM_HDL)
    {
        MApp_Music_CloseFile();
    }

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
#ifdef M4APARSER
    #if (ENABLE_AAC)
        _bM4aJustOpened = FALSE;
    #endif
#endif

#if (ENABLE_FLAC)
        if(m_stFlacInfo.pstSeekTable!=NULL)
        {
            msAPI_Memory_Free(m_stFlacInfo.pstSeekTable,BUF_ID_FILEBROWER);
            FLAC_DBG(printf("free stFlacInfo.pSeekTable\n"));
            m_stFlacInfo.pstSeekTable = NULL;
        }
#endif

        return FALSE;
    }

    if(enCurrentMusicType == EN_MUSIC_MP3)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, stMp3Info.u32ID3TagV2Size, E_DATA_STREAM_SEEK_SET);
    }
#if (ENABLE_AAC)
    else if(enCurrentMusicType == EN_MUSIC_AAC)
    {
        //Eric-PH Lee:20080614 Jump ID3 Tag for AAC
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, AACID3Jump, E_DATA_STREAM_SEEK_SET);
    }
#endif
#if (ENABLE_FLAC)
    else if(enCurrentMusicType == EN_MUSIC_FLAC)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, m_stFlacInfo.u32DataOffset, E_DATA_STREAM_SEEK_SET);  //to first frame
        FLAC_DBG(printf("file open and jump to %lu\n",m_stFlacInfo.u32DataOffset));
    }
#endif
#if (ENABLE_AC3)
    else if(enCurrentMusicType == EN_MUSIC_AC3)
    {
        //msAPI_DataStreamIO_Seek(u32Mp3FileHandle, 0, E_DATA_STREAM_SEEK_SET);
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, m_stAc3Info.u32FileStart, E_DATA_STREAM_SEEK_SET);
        AC3_DBG(printf("file open and jump to 0x%x\n",m_stAc3Info.u32FileStart));
    }
#endif

#if (ENABLE_WAV)
    else if(enCurrentMusicType == EN_MUSIC_WAV)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, stWavChunk.u32HeaderSize, E_DATA_STREAM_SEEK_SET);
    }
    else if(enCurrentMusicType == EN_MUSIC_PCM)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, 0, E_DATA_STREAM_SEEK_SET);
    }
#endif
    else if(enCurrentMusicType == EN_MUSIC_LOAS)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, 0, E_DATA_STREAM_SEEK_SET);
    }
#if (ENABLE_OGG)
    else if(enCurrentMusicType == EN_MUSIC_OGG)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, g_OggInfo.u32VorbisFirstAudioPageOffset, E_DATA_STREAM_SEEK_SET);
    }
#endif
#if (ENABLE_AMR)
    else if( (enCurrentMusicType == EN_MUSIC_AMR) || (enCurrentMusicType == EN_MUSIC_AWB) )
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, m_AMRInfo.u8HeaderSize, E_DATA_STREAM_SEEK_SET);
    }
#endif

#ifdef M4APARSER
    #if (ENABLE_AAC)
        _bM4aJustOpened = TRUE;
    #endif
#endif
    return TRUE;
}

BOOLEAN MApp_SaveMp3_EraseFlash(U32 u32FlashStartAddr, U32 u32DataSize)
{
/*
    U32 u32StartSector, u32EndSector, u32CurSector, u32FlashEndAddr;

    u32StartSector =0;
    u32EndSector =0;
*/

    if (u32DataSize == 0)
    {
        return FALSE;
    }

    //U32 u32FlashEndAddr = u32FlashStartAddr + u32DataSize - 1;
    //MUSIC_DBG(printf("u32FlashStartAddr=0x%lx, u32FlashEndAddr=0x%lx\n", u32FlashStartAddr, u32FlashEndAddr));

/*
    if (!msAPI_Flash_AddressToBlock(u32FlashStartAddr, &u32StartSector))
    {
        return FALSE;
    }

    if (!msAPI_Flash_AddressToBlock(u32FlashEndAddr, &u32EndSector))
    {
        return FALSE;
    }

    MUSIC_DBG(printf("u16StartSector=%d, u32EndSector=%d\n", u32StartSector, u32EndSector));

    for (u32CurSector = u32StartSector; u32CurSector <= u32EndSector; u32CurSector++)
    {
        if (!msAPI_Flash_BlockErase(u32CurSector, u32CurSector, TRUE))
        {
            return FALSE;
        }
    }
*/

    msAPI_Flash_AddressErase(u32FlashStartAddr, u32DataSize, TRUE);

    MUSIC_DBG(printf("MApp_SaveMp3_EraseFlash OK\n");)

    return TRUE;
}


BOOLEAN MApp_SaveMp3_WriteFlash(U32 u32SrcAddr, U32 u32FlashAddr, U32 u32DataSize)
{
    U32 u32LeftSize;
    U16 u32CopySize;
    U32 u32TmpBuffAddr = MemAlign(POOL_BUFFER_MEMORY_TYPE & MIU1 ? (POOL_BUFFER_ADR | MIU_INTERVAL) : POOL_BUFFER_ADR, 0x1000);

    u32LeftSize = u32DataSize;
    u32CopySize = 0x1000;

    while (u32LeftSize > 0)
    {
        if (u32LeftSize < 0x1000)
        {
            u32CopySize = u32LeftSize;
        }

        msAPI_MIU_Copy(u32SrcAddr, u32TmpBuffAddr, (U32)u32CopySize, MIU_SDRAM2SDRAM);
        if (!msAPI_Flash_Write(u32FlashAddr, u32CopySize, (U8 *)_PA2VA(u32TmpBuffAddr)))
        {
            MUSIC_DBG(printf("MApp_SaveMp3_WriteFlash: Writing error\n"));
            return FALSE;
        }

        u32SrcAddr += u32CopySize;
        u32FlashAddr += u32CopySize;
        u32LeftSize -= u32CopySize;
    }

    MUSIC_DBG(printf("MApp_SaveMp3_WriteFlash OK: Addr %lx, Len %lx\n", u32FlashAddr, u32DataSize));

    return TRUE;
}

void MApp_Music_StartCapture(void)
{
#if (ENABLE_MPLAYER_CAPTURE_MUSIC)
    if (_bMusicRecording == FALSE)
    {
        _bMusicRecording = TRUE;
        _u32MusicRecordLength = 0;

        _u32MusicRecordTotalTime = 0;
        _u32MusicRecordStartTime = msAPI_Timer_GetTime0();

        // erase flash
        //msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_1);
       // MDrv_SERFLASH_Init();

        msAPI_Flash_AddressErase(USER_MP3_FLASH_START_ADDR, USER_MP3_FLASH_END - USER_MP3_FLASH_START_ADDR, TRUE);

      //  msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_0);
      //  MDrv_SERFLASH_Init();

        MUSIC_DBG(printf("Music: Capture start\n"));
    }
#endif // #if (ENABLE_MPLAYER_CAPTURE_MUSIC)
}

void MApp_Music_StopCapture(void)
{
#if (ENABLE_MPLAYER_CAPTURE_MUSIC)
    if (_bMusicRecording)
    {
        _bMusicRecording = FALSE;
        _u32MusicRecordLength = 0;

        _u32MusicRecordTotalTime = MsOS_Timer_DiffTimeFromNow(_u32MusicRecordStartTime);
        _u32MusicRecordStartTime = 0;

        stGenSetting.g_SysSetting.UsrPowerOnMusic = POWERON_MUSIC_USER;
#ifndef ATSC_SYSTEM
        //[hardes.chen]
        MApp_SaveSysSetting();
#endif

        MUSIC_DBG(printf("Music: Capture stop\n"));
    }
#endif // #if (ENABLE_MPLAYER_CAPTURE_MUSIC)
}

//******************************************************************************
/// This function will set state of music to init state for initializing.
/// @param  N/A
/// @return N/A
//******************************************************************************
void MApp_Music_Init(void)
{
    msAPI_Music_StopDecode();
    MApp_Music_CloseFile();
    enMusicState = STATE_MUSIC_INIT;
}

void MApp_Music_Input(void)
{
    U32 u32ReqAddr, u32ReqBytes;
    BOOLEAN bInputEnd = FALSE;

//    if ((enMp3PlayStatus == MP3_STATUS_PAUSE) || (msAPI_Music_CheckInputRequest(&u32ReqAddr, &u32ReqBytes) == FALSE))
    if ((enMp3PlayStatus == MP3_STATUS_PAUSE) ||
        (enMp3PlayStatus == MP3_STATUS_SCAN) ||
        (msAPI_Music_CheckInputRequest(&u32ReqAddr, &u32ReqBytes) == FALSE))
            return;

#ifdef M4APARSER
    if(enCurrentMusicType == EN_MUSIC_MP3)
    {
#endif
        if (u32ReqBytes == 0)
            return;

        if ((msAPI_DataStreamIO_Tell(u32Mp3FileHandle) + u32ReqBytes) > msAPI_DataStreamIO_Length(u32Mp3FileHandle))
        {
            // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
            msAPI_Music_CleanFileEndData(u32ReqAddr, u32ReqBytes, 0x0UL);
        }

        u32Mp3FileBytesLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)u32ReqAddr, u32ReqBytes);
        MUSIC_DBG(printf("msAPI_DataStreamIO_Read  addr=%lx,len=%lx\n",u32ReqAddr,u32ReqBytes);)

#if (ENABLE_MPLAYER_CAPTURE_MUSIC)
        if(_bMusicRecording)
        {
#if (WATCH_DOG == ENABLE)
            msAPI_Timer_ResetWDT();
#endif

            if ((USER_MP3_FLASH_START_ADDR + _u32MusicRecordLength < USER_MP3_FLASH_END)
                    && (MsOS_Timer_DiffTimeFromNow(_u32MusicRecordStartTime) < USER_MP3_CAPTURE_TIMEOUT))
            {
                // switch to extra flash
                //msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_1);
                //MDrv_SERFLASH_Init();

                MApp_SaveMp3_WriteFlash(u32ReqAddr, USER_MP3_FLASH_START_ADDR + _u32MusicRecordLength, u32ReqBytes);

                // switch back to default flash
                //msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_0);
               // MDrv_SERFLASH_Init();

                _u32MusicRecordLength += u32ReqBytes;
            }
            else
            {
                MApp_Music_StopCapture();
            }
        }
#endif // #if (ENABLE_MPLAYER_CAPTURE_MUSIC)

        if (u32Mp3FileBytesLeft!=0)
        {
            //infor DSP residual bytes
            //end of file
            msAPI_Music_FileEndDataHandle(u32Mp3FileBytesLeft);
            MUSIC_DBG(printf("End of file\n"));
            bInputEnd = TRUE;
        }

#ifdef M4APARSER
    }
#if (ENABLE_AAC)
    else if(enCurrentMusicType == EN_MUSIC_AAC)
    {
        //AAC_ERR2(printf("@M4aM4AParser_WriteDSP\n"));

        if (stM4aInfo.bM4aHeader)
        {
            if (M4AParser_WriteDSP(u32ReqAddr,u32ReqBytes) == FALSE)
            {
                AAC_ERR2(printf("M4a to DSP NG\n"));
                return;
            }
        }
        else
        {
            if ((msAPI_DataStreamIO_Tell(u32Mp3FileHandle) + u32ReqBytes) > msAPI_DataStreamIO_Length(u32Mp3FileHandle))
            {
                // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
                msAPI_Music_CleanFileEndData(u32ReqAddr, u32ReqBytes, 0x0UL);
            }

            if (M4AParser_WriteDSPNoHead(u32ReqAddr,u32ReqBytes) == FALSE)
            {
                AAC_ERR2(printf("M4a No Head to DSP NG\n"));
                return;
            }
        }

        if (u32Mp3FileBytesLeft == 0)
        {
            // end of file
            AAC_ERR(printf("@End of M4A file\n"));
            bInputEnd = TRUE;
            //enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
            //return;
        }
    } //end of else of if mediaservice != 9
#endif
#endif
#if (ENABLE_FLAC)
    else if(enCurrentMusicType == EN_MUSIC_FLAC)
    {

        if(_MApp_Music_Flac_DataInput(u32ReqAddr,u32ReqBytes) == FALSE)
        {
            FLAC_ERR(printf("FLAC input error!\n"));
            return;
        }

        if (stMp3Info.u32MusicDataBytesLeft == 0)
        {
            // end of file
            FLAC_ERR(printf("@End of FLAC file\n"));
            bInputEnd = TRUE;

        }

    }
#endif
#if (ENABLE_AC3)
    else if(enCurrentMusicType == EN_MUSIC_AC3)
    {

        if(_MApp_Music_Ac3_DataInput(u32ReqAddr,u32ReqBytes) == FALSE)
        {
            AC3_ERR(printf("AC3 input error!\n"));
            return;
        }

        if (stMp3Info.u32MusicDataBytesLeft == 0)
        {
            // end of file
            AC3_ERR(printf("@End of AC3 file\n"));
            bInputEnd = TRUE;

        }

    }
#endif

#if (ENABLE_WAV)
    else if(enCurrentMusicType == EN_MUSIC_WAV)
    {
        if(_MApp_Music_Wav_DataInput(u32ReqAddr,u32ReqBytes) == FALSE)
        {
            WAV_ERR(printf("WAV input error!\n"));
            return;
        }

        if (stMp3Info.u32MusicDataBytesLeft == 0)
        {
            // end of file
            WAV_ERR(printf("@End of WAV file\n"));
            bInputEnd = TRUE;
            //enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
            //return;
        }
    }
    else if(enCurrentMusicType == EN_MUSIC_PCM)
    {
        if(_MApp_Music_PCM_DataInput(u32ReqAddr,u32ReqBytes) == FALSE)
        {
            WAV_ERR(printf("PCM input error!\n"));
            return;
        }

        if (stMp3Info.u32MusicDataBytesLeft == 0)
        {
            // end of file
            WAV_ERR(printf("@End of PCM file\n"));
            bInputEnd = TRUE;
            //enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
            //return;
        }
    }
#endif
    else if(enCurrentMusicType == EN_MUSIC_LOAS)
    {
        U32 u32ReadLeft;
        msAPI_Music_CleanFileEndData(u32ReqAddr,u32ReqBytes,0x0UL);
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)u32ReqAddr,u32ReqBytes);

        if(u32ReadLeft>0)
        {
            msAPI_Music_FileEndDataHandle(u32ReadLeft);
            stMp3Info.u32MusicDataBytesLeft = 0;
            bInputEnd = TRUE;
            //enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
            //return;
        }
    }
#ifdef OGG_PARSER
#if (ENABLE_OGG)
    else if(enCurrentMusicType == EN_MUSIC_OGG)
    {
        OGG_DBG(printf("[OGG]: input data for Ogg.\n"));
        if( g_OggInfo.bNeedAddHeader)
        {
            OGG_DBG(printf("[[OGG]: Add header :request size: 0x%x, left header size:0x%x\n",u32ReqBytes, g_OggInfo.u32VorbisHeaderLeftSizeToWrite));
            if(u32ReqBytes >= g_OggInfo.u32VorbisHeaderLeftSizeToWrite)
            {
                memcpy((void*)(_PA2VA(u32ReqAddr)), (void*)_PA2VA(g_OggInfo.u32VorbisHeaderAddr[0]+(g_OggInfo.u32VorbisHeaderTotalSize - g_OggInfo.u32VorbisHeaderLeftSizeToWrite)),
                                           g_OggInfo.u32VorbisHeaderLeftSizeToWrite);

                u32ReqAddr += g_OggInfo.u32VorbisHeaderLeftSizeToWrite;
                u32ReqBytes -= g_OggInfo.u32VorbisHeaderLeftSizeToWrite;
                g_OggInfo.u32VorbisHeaderLeftSizeToWrite = 0;
                g_OggInfo.bNeedAddHeader = FALSE;
                g_OggInfo.bInputFromPacketStart = TRUE;
            }
            else
            {
                memcpy((void*)_PA2VA(u32ReqAddr), (void*)_PA2VA(g_OggInfo.u32VorbisHeaderAddr[0] + (g_OggInfo.u32VorbisHeaderTotalSize - g_OggInfo.u32VorbisHeaderLeftSizeToWrite)), u32ReqBytes);
                g_OggInfo.u32VorbisHeaderLeftSizeToWrite -= u32ReqBytes;
                u32ReqAddr += u32ReqBytes;
                u32ReqBytes = 0;
            }
        }

        if(u32ReqBytes > 0)
        {
            if (MApp_Music_OggParser_WriteDSP(u32ReqAddr,u32ReqBytes) == FALSE)
            {
                    OGG_ERR(printf("Ogg parser data error!\n"));
                    return;
            }

            if(g_OggInfo.u32LeftDataToFill != 0)
            {
                //infor DSP residual bytes
                msAPI_Music_FileEndDataHandle(g_OggInfo.u32LeftDataToFill);
            }

            if (g_OggInfo.bEndofFile)
            {
                // end of file
                OGG_ERR(printf("@End of Ogg file\n"));
                bInputEnd = TRUE;
            }
     }
    }
#endif
#endif
#if (ENABLE_AMR)
    else if( (enCurrentMusicType == EN_MUSIC_AMR) || (enCurrentMusicType == EN_MUSIC_AWB) )
    {
        U32 u32ReadLeft;
        msAPI_Music_CleanFileEndData(u32ReqAddr,u32ReqBytes,0x0UL);
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)u32ReqAddr,u32ReqBytes);

        if(u32ReadLeft>0)
        {
            msAPI_Music_FileEndDataHandle(u32ReadLeft);
            stMp3Info.u32MusicDataBytesLeft = 0;
            bInputEnd = TRUE;
            //enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
            //return;
        }
    }
#endif
    else
    {
        MUSIC_DBG(printf("error type\n"));
    }

#if MUSIC_INPUT_DUMP
    if(m_u8FileHandleMusicInput!=INVALID_FILE_HANDLE)
    {
            msAPI_FCtrl_FileWrite(m_u8FileHandleMusicInput, u32ReqAddr, u32ReqBytes);
        }
#endif
    msAPI_Music_SetInput();

    if(bInputEnd == TRUE)
    {
        enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
    }
}

BOOLEAN MApp_Music_LoadDspCodec(En_DVB_decSystemType enDecSystem)
{
    // stop codec
    msAPI_Music_StopDecode();

    if (bReloadDsp == TRUE)
    {
        // reload dsp codec before
        return FALSE;
    }

    enCurrentDecSystem = enDecSystem;
    msAPI_Music_Init(enCurrentDecSystem, INIT_VOLUME);
    bReloadDsp = TRUE;

    return TRUE;
}

#if (ENABLE_LRC_LYRIC) || (ENABLE_LYRICS3)
static S16 _MApp_Music_ScanDigit(U8 *pu8Data, U32 *pu32Val, BOOLEAN bIsUnicode)
{
    U8 u8Offset;
    S16 s16Index = 0;
    U16 u16Temp = '0';

    pu32Val[0] = 0;

    if(bIsUnicode)
    {
        u8Offset = 2;
    }
    else
    {
        u8Offset = 1;
    }

    do{
        pu32Val[0] = pu32Val[0] * 10 + (U32)(u16Temp - '0');
        memcpy(&u16Temp,&pu8Data[s16Index],u8Offset);
        if(u16Temp == '-') //Fixex time < 0 , EX: [00:-4.71]
        {
            *pu32Val = 0;
            return -1;
        }
        s16Index += u8Offset;

    }while((u16Temp >= '0') && (u16Temp <= '9') && (s16Index<=6));   //u16Index<=6 for loop protect

    s16Index -= u8Offset;

    return s16Index;
}
#endif

#if (ENABLE_LYRICS3)
static U8 _MApp_Music_ScanfLyrics3Time(U8  *pu8Data, U32 *pu32Min, U32 *pu32Sec, BOOLEAN bIsUnicode)
{
    //#define LYRICS3_TIME_STAMP_FMT  "[%ld:%ld]"
    U16 u16Index=0;
    U16 u16DigitCnt;

    // Scan Min
    u16DigitCnt = _MApp_Music_ScanDigit(pu8Data, pu32Min, bIsUnicode);
    u16Index += u16DigitCnt;
    if(u16DigitCnt == 0 || pu8Data[u16Index] != ':')
    {
        return 0;
    }

    // Scan Sec
    u16DigitCnt = _MApp_Music_ScanDigit(pu8Data, pu32Sec, bIsUnicode);
    u16Index += u16DigitCnt;
    if(u16DigitCnt == 0 || pu8Data[u16Index] != '\0')
    {
        return 0;
    }

    return 2;
}

static BOOLEAN MApp_Music_Lyrics3_Parser(void)
{
    #define LYRICS3_CACHE_SIZE      255
    BOOLEAN bRet = FALSE;
    U32 u32Size;
    U32 u32Start;
    U32 u32ParsedPos;
    U8 *pu8Data;
//    U8 u8LyricsVersion;
    U32 u32LyricSize=0;
    U32 i;
    BOOLEAN bFound;
    U32 u32Min, u32Second;
    Music_Lyric_Tag *pLyricTag;
    BOOLEAN bIsUnicode = FALSE;

    u16LyricTagCount = 0;

    pu8Data = (U8*)msAPI_Memory_Allocate(LYRICS3_CACHE_SIZE+2, BUF_ID_FILEBROWER);
    if(pu8Data == NULL)
    {
        __ASSERT(0);
        goto MApp_Music_Lyric_Parser_END;
    }

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        MUSIC_DBG1(printf("Open file failed\n"));
        msAPI_Memory_Free(pu8Data, BUF_ID_FILEBROWER);
        return bRet;
    }

    pLyricTag = (Music_Lyric_Tag *)_PA2VA((void *)MUSIC_LYRIC_TAG_ADR);

    u32Size = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
    u32Start = (u32Size-128-9-6) & (~(READ_BLOCK_SIZE-1));
    u32ParsedPos = (U32)_PA2VA((void *)(u32Size - u32Start - 128 - 9 - 6 + ((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR))));

    msAPI_Stream_Seek(u32Mp3FileHandle, u32Start);
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), READ_BLOCK_SIZE*8);
    //msAPI_MIU_Copy(u32ParsedPos, (U32)(&pu8Data[0]), 6, MIU_SDRAM2SDRAM);
    memcpy(&pu8Data[0], (U8 *)(u32ParsedPos), 6);
    pu8Data[6] = '\0';
    u32ParsedPos+=6;
    //msAPI_MIU_Copy(u32ParsedPos, (U32)(&pu8Data[6+1]), 9, MIU_SDRAM2SDRAM);
    memcpy(&pu8Data[6+1], (U8 *)(u32ParsedPos), 9);
    pu8Data[6+1+9] = '\0';

    // Check the lyrics3 version.
    if(strncmp((char *)(&pu8Data[6+1]), "LYRICS200", 9) == 0)
    {
        if(_MApp_Music_ScanDigit(&pu8Data[0], &u32LyricSize, bIsUnicode) != 6)
        {
            MUSIC_DBG1(printf("LYRICS200 length error!\n"));
            goto MApp_Music_Lyric_Parser_END;
        }
        u32LyricSize += (9 + 6);
        MUSIC_DBG1(printf("Lyric ver. 2 size = %ld\n", u32LyricSize));
//        u8LyricsVersion = 2;
    }
    else if(strncmp((char *)(&pu8Data[6+1]), "LYRICSEND", 9) == 0)
    {
        u32LyricSize = 5100 + 9 + 6 + 11;
        MUSIC_DBG1(printf("Lyric ver. 2 size = %ld\n", 5100+128));
//        u8LyricsVersion = 1;
    }
    else
    {
        MUSIC_DBG1(printf("No Lyric!\n"));
        goto MApp_Music_Lyric_Parser_END;
    }

    u32Start = (u32Size-u32LyricSize) & (~(READ_BLOCK_SIZE-1));
    u32LyricSize = u32Size - u32Start;
    if((u32LyricSize >= u32Size) || (u32LyricSize > MUSIC_LYRIC_BUFFER_LEN))
    {
        MUSIC_DBG1(printf("File size if too small!\n"));
        goto MApp_Music_Lyric_Parser_END;
    }

    // Read all lyric data to buffer.
    msAPI_Stream_Seek(u32Mp3FileHandle, u32Start);
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), u32LyricSize);

    // Search the token "LYRICSBEGIN"
    #define LYRICSBEGIN_LEN     11
    bFound = FALSE;
    for(u32ParsedPos=0; u32ParsedPos<u32LyricSize; u32ParsedPos++)
    {
        //msAPI_MIU_Copy(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), LYRICSBEGIN_LEN, MIU_SDRAM2SDRAM);
        memcpy(&pu8Data[0], (U8 *)_PA2VA((void *)(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), LYRICSBEGIN_LEN);

        if(strncmp((char *)(&pu8Data[0]), "LYRICSBEGIN", LYRICSBEGIN_LEN) == 0)
        {
            bFound = TRUE;
            u32ParsedPos += LYRICSBEGIN_LEN;
            break;
        }
    }
    if(!bFound)
    {
        MUSIC_DBG1(printf("Cannot find LYRICSBEGIN!\n"));
        goto MApp_Music_Lyric_Parser_END;
    }

    while(u32ParsedPos<u32LyricSize)
    {
        #define FLD_NAME_LEN        3
        #define FLD_SIZE_LEN        5
        // Search field name.
        //msAPI_MIU_Copy(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), FLD_NAME_LEN+FLD_SIZE_LEN, MIU_SDRAM2SDRAM);
        memcpy(&pu8Data[0], (U8 *)_PA2VA((void *)(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), FLD_NAME_LEN+FLD_SIZE_LEN);

        pu8Data[FLD_NAME_LEN+FLD_SIZE_LEN] = '\0';
        if(strncmp((char *)(&pu8Data[0]), "IND", FLD_NAME_LEN) == 0)
        {
            if(_MApp_Music_ScanDigit(&pu8Data[FLD_NAME_LEN], &u32Size, bIsUnicode) != 5)
            {
                MUSIC_DBG1(printf("IND field length is wrong!\n"));
                goto MApp_Music_Lyric_Parser_END;
            }
            if(u32Size > 1)
            {
                //msAPI_MIU_Copy(u32ParsedPos+8+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), 2, MIU_SDRAM2SDRAM);
                memcpy(&pu8Data[0], (U8 *)_PA2VA((void *)(u32ParsedPos+8+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), 2);

                if(pu8Data[1] != '1')
                {
                    MUSIC_DBG1(printf("IND indicated no time stamp!\n"));
                    goto MApp_Music_Lyric_Parser_END;
                }
            }
            else
            {
                MUSIC_DBG1(printf("No IND data\n"));
                goto MApp_Music_Lyric_Parser_END;
            }
            u32ParsedPos += u32Size + FLD_NAME_LEN + FLD_SIZE_LEN;
        }
        else if((strncmp((char *)(&pu8Data[0]), "ETT", FLD_NAME_LEN) == 0) ||
                (strncmp((char *)(&pu8Data[0]), "EAR", FLD_NAME_LEN) == 0) ||
                (strncmp((char *)(&pu8Data[0]), "EAL", FLD_NAME_LEN) == 0) ||
                (strncmp((char *)(&pu8Data[0]), "AUT", FLD_NAME_LEN) == 0) ||
                (strncmp((char *)(&pu8Data[0]), "INF", FLD_NAME_LEN) == 0) ||
                (strncmp((char *)(&pu8Data[0]), "IMG", FLD_NAME_LEN) == 0))
        {
            if(_MApp_Music_ScanDigit(&pu8Data[FLD_NAME_LEN], &u32Size, bIsUnicode) != 5)
            {
                MUSIC_DBG1(printf("Field length is wrong\n"));
                goto MApp_Music_Lyric_Parser_END;
            }
            u32ParsedPos += u32Size + FLD_NAME_LEN + FLD_SIZE_LEN;
        }
        else if(strncmp((char *)(&pu8Data[0]), "LYR", FLD_NAME_LEN) == 0)
        {
            #define LYRIC_TAG_MAX       (MUSIC_LYRIC_TAG_LEN/sizeof(Music_Lyric_Tag))
            U16 u16TagStart;

            if(_MApp_Music_ScanDigit(&pu8Data[FLD_NAME_LEN], &u32Size, bIsUnicode) != 5)
            {
                MUSIC_DBG1(printf("LYR length is wrong\n"));
                goto MApp_Music_Lyric_Parser_END;
            }
            // Save u32ParsedPos to u32Size.
            u32Size = u32ParsedPos + u32Size  + FLD_NAME_LEN + FLD_SIZE_LEN;

            u32ParsedPos += FLD_NAME_LEN + FLD_SIZE_LEN;
            // Parse Lyric.
            // Parse time stamp.
            #define LYRICS3_TIME_STAMP_LEN  7
            while(u32ParsedPos<u32LyricSize)
            {
                bFound = FALSE;
                u16TagStart = u16LyricTagCount;
                while(u32ParsedPos<u32LyricSize)
                {
                    //msAPI_MIU_Copy(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), TIME_STAMP_LEN, MIU_SDRAM2SDRAM);
                    memcpy(&pu8Data[0], (U8 *)_PA2VA((void *)(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), LYRICS3_TIME_STAMP_LEN);

                    pu8Data[LYRICS3_TIME_STAMP_LEN] = '\0';
                    if(_MApp_Music_ScanfLyrics3Time(&pu8Data[0], &u32Min, &u32Second, bIsUnicode) != 2)
                    {
                        if(pu8Data[0] == '[')
                        {
                            MUSIC_DBG1(printf("Wrong time stamp!\n"));
                            goto MApp_Music_Lyric_Parser_END;
                        }
                        break;
                    }
                    pLyricTag[u16LyricTagCount].u32Time = (u32Min * 60 + u32Second)*1000;
                    pLyricTag[u16LyricTagCount].u16LyricPos = 0;
                    u16LyricTagCount++;
                    u32ParsedPos += LYRICS3_TIME_STAMP_LEN;
                    bFound = TRUE;
                }
                // Read lyric.
                if(bFound)
                {
                    //msAPI_MIU_Copy(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), LYRIC_CACHE_SIZE, MIU_SDRAM2SDRAM);
                    memcpy(&pu8Data[0], (U8 *)_PA2VA((void *)(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), LYRICS3_CACHE_SIZE);

                    // Search the end of one line.
                    for(i=0; i<LYRICS3_CACHE_SIZE; i++)
                    {
                        if(pu8Data[i] == '\r')
                        {
                            if(pu8Data[i+1] == '\n')
                            {
                                i+=2;
                                break;
                            }
                            else
                            {
                                MUSIC_DBG1(printf("Line feed wrong!!\n"));
                                goto MApp_Music_Lyric_Parser_END;
                            }
                        }
                    }
                    if(i < LYRICS3_CACHE_SIZE)
                    {
                        for(u32Start=u16TagStart;u32Start<u16LyricTagCount;u32Start++)
                        {
                            pLyricTag[u32Start].u16LyricPos = u32ParsedPos;
                        }
                        u32ParsedPos += i;
                        bRet = TRUE;
                    }
                    else
                    {
                        MUSIC_DBG1(printf("One line lyric is too long!!\n"));
                        goto MApp_Music_Lyric_Parser_END;
                    }
                }
                else
                {
                    break;  // No more lyrics.
                }
            }

            // Sort by time stamp.
            if(u16LyricTagCount > 1)
            {
                for(u32Start=0;u32Start<(U32)u16LyricTagCount-1;u32Start++)
                for(i=u32Start+1;i<(U32)u16LyricTagCount;i++)
                {
                    if(pLyricTag[i].u32Time < pLyricTag[u32Start].u32Time)
                    {
                        U32 u32Temp;

                        u32Temp = pLyricTag[i].u32Time;
                        pLyricTag[i].u32Time = pLyricTag[u32Start].u32Time;
                        pLyricTag[u32Start].u32Time = u32Temp;
                        u32Temp = pLyricTag[i].u16LyricPos;
                        pLyricTag[i].u16LyricPos = pLyricTag[u32Start].u16LyricPos;
                        pLyricTag[u32Start].u16LyricPos = u32Temp;
                    }
                }
            }

            u32ParsedPos = u32Size;     // Restore u32ParsedPos.
            break;                      // Only get lyric temporarily.
        }
    }

#if 0
    for(i=0;i<u16LyricTagCount;i++)
    {
        printf("Time = %d, Pos = 0x%04x\n", pLyricTag[i].u32Time, pLyricTag[i].u16LyricPos);
    }
#endif

MApp_Music_Lyric_Parser_END:

    if(pu8Data)
    {
        msAPI_Memory_Free(pu8Data, BUF_ID_FILEBROWER);
    }

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;

    return bRet;
}

#endif  // #if (ENABLE_LYRICS3)

#if (ENABLE_LRC_LYRIC)
static U8 _MApp_Music_ScanfLrCTime(U8  *pu8Data, U32 *pu32Min, U32 *pu32Sec, U32 *pu32Ms, U32 *pu32MsLen, BOOLEAN bIsUnicode)
{
    //#define TIME_STAMP_FMT  "[%ld:%ld.%ld]"
    U8 u8Offset;
    U16 u16Index=0;
    S16 s16DigitCnt;

    if(bIsUnicode)
    {
        u8Offset=2;
    }
    else
    {
        u8Offset=1;
    }
    u16Index += u8Offset;

    // Scan Min
    s16DigitCnt = _MApp_Music_ScanDigit(pu8Data+u16Index, pu32Min, bIsUnicode);
    u16Index += s16DigitCnt;
    if((s16DigitCnt == 0) || (s16DigitCnt == -1) || (pu8Data[u16Index] != ':'))
    {
        return 0;
    }

    // Scan Sec
    u16Index += u8Offset;
    s16DigitCnt = _MApp_Music_ScanDigit(pu8Data+u16Index, pu32Sec, bIsUnicode);
    u16Index += s16DigitCnt;
    if((s16DigitCnt == 0) || ((s16DigitCnt != -1) && (pu8Data[u16Index] != '.')) )
    {
        //No Ms, set *pu32Ms=0
        *pu32Ms=0;
        *pu32MsLen = 0;
        return 2;
    }
    else if(s16DigitCnt == -1)
    {
        return 0;
    }
    else
    {
        // Scan Ms
        u16Index += u8Offset;
        s16DigitCnt = _MApp_Music_ScanDigit(pu8Data+u16Index, pu32Ms, bIsUnicode);
        u16Index += s16DigitCnt;
        if(s16DigitCnt == 0 || pu8Data[u16Index] != ']')
        {
            return 0;
        }
        *pu32MsLen = s16DigitCnt;
    }

    //printf("[%02ld:%02ld.%02ld]\n",*pu32Min,*pu32Sec,*pu32Ms);
    return 3;
}

BOOLEAN MApp_Music_LRC_Lyrics_Parser(U32 u32FileSize)
{
    #define LYRIC_CACHE_SIZE      510
    BOOLEAN bRet = FALSE;
    U16 i;
    Music_Lyric_Tag *pLyricTag;
    U32 u32Min, u32econd, u32ms, u32MsLen;
    U32 u32ParsedPos;
    U8 *pu8Data;
    BOOLEAN bFound,bLyricStartTagFound;
    BOOLEAN bIsUnicode = FALSE;
    U16 u16TagStart;
    U8 u8NumOfTimeTag;
    U8 u8Offset, u8Add;
    U16 u16StartTag,u16EndTag;
    S8 s8Temp = -1;
    S8 s8TimeStampLength = -1;

    u16LyricTagCount = 0;

    pu8Data = (U8*)msAPI_Memory_Allocate(LYRIC_CACHE_SIZE+2, BUF_ID_FILEBROWER);
    if(pu8Data == NULL)
    {
        __ASSERT(0);
        goto MApp_Music_LRC_Lyrics_Parser_END;
    }

    pLyricTag = (Music_Lyric_Tag *)_PA2VA(MUSIC_LYRIC_TAG_ADR);

    // Parse the time
    u32ParsedPos = 0;
    bLyricStartTagFound = FALSE;

    memcpy((U8 *)(&pu8Data[0]),(U8 *)_PA2VA(MUSIC_LYRIC_BUFFER_ADR),2);

    if(pu8Data[0]==0xFF && pu8Data[1]==0xFE)
    {
        //printf("It's unicode!\n");
        u8Offset = 2;
        bIsUnicode = TRUE;
    }
    else
    {
        u8Offset = 1;
        bIsUnicode = FALSE;
    }

    //search Lyric Tag start point
    while( (u32ParsedPos < u32FileSize) && (bLyricStartTagFound == FALSE) )
    {
        //msAPI_MIU_Copy(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), LYRIC_CACHE_SIZE, MIU_SDRAM2SDRAM);
        memcpy(&pu8Data[0], (U8 *)_PA2VA((u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), LYRIC_CACHE_SIZE);

        for(i=0;i<LYRIC_CACHE_SIZE;i++)
        {
            u16StartTag=0;
            memcpy(&u16StartTag,&pu8Data[i],u8Offset);
            if( (u16StartTag == '[') && (s8TimeStampLength == -1) )
            {
                if(bIsUnicode)
                {
                    s8Temp = pu8Data[i+2] - '0';
                }
                else
                {
                    s8Temp = pu8Data[i+1] - '0';
                }

                if(s8Temp>=0 && s8Temp<=9 )
                {
                    s8TimeStampLength = i;
                }
            }
            else if( (u16StartTag == ']') && (s8TimeStampLength != -1) )
            {
                s8TimeStampLength = (i-s8TimeStampLength+1);

                bLyricStartTagFound = TRUE;
                break;
            }

        }

        u32ParsedPos += (i-s8TimeStampLength+1);

    }


    while(u32ParsedPos < u32FileSize)
    {
        bFound = FALSE;
        u16TagStart = u16LyricTagCount;
        while(u32ParsedPos<u32FileSize)
        {
            //msAPI_MIU_Copy(u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)), (U32)(&pu8Data[0]), LYRIC_CACHE_SIZE, MIU_SDRAM2SDRAM);
            memcpy(&pu8Data[0], (U8 *)_PA2VA((u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), LYRIC_CACHE_SIZE);

            u8NumOfTimeTag = _MApp_Music_ScanfLrCTime(pu8Data, &u32Min, &u32econd, &u32ms, &u32MsLen, bIsUnicode);
            if(u8NumOfTimeTag < 2)
            {
                memcpy(&u16StartTag,&pu8Data[0],u8Offset);
                if(u16StartTag == '[')
                {
                    // Find the next line.
                    for(i=1;i<LYRIC_CACHE_SIZE;i++)
                    {
                        memcpy(&u16StartTag,&pu8Data[i],u8Offset);
                        if(u16StartTag == '[')
                        {
                            break;  //Break for!
                        }
                    }
                    if(i >= LYRIC_CACHE_SIZE)
                    {
                        MUSIC_DBG1(printf("Cannot find the next time stamp\n"));
                        goto MApp_Music_LRC_Lyrics_Parser_END;
                    }
                    u32ParsedPos += i;
                    continue;
                }
                break;
            }
            pLyricTag[u16LyricTagCount].u32Time = (u32Min * 60 + u32econd) * 1000 + u32ms * 10;
            pLyricTag[u16LyricTagCount].u16LyricPos = 0;
            u16LyricTagCount++;
            if(MUSIC_LYRIC_MAX_COUNT <= u16LyricTagCount)
            {
                u16LyricTagCount = u16TagStart;
                bFound = FALSE;
                break;
            }

            u8Add = 0;
            if(bIsUnicode)
            {
                //some lyric ms has three charactors
                if(u32MsLen == 6)
                {
                    u8Add = 1;
                }
                u32ParsedPos += ((u8NumOfTimeTag*3+1+u8Add)*2);
            }
            else
            {
                //some lyric ms has three charactors
                if(u32MsLen == 3)
                {
                    u8Add = 1;
                }
                u32ParsedPos += (u8NumOfTimeTag*3+1+u8Add);
            }
            bFound = TRUE;
        }
        // Read lyric.
        if(bFound)
        {
            for(i=u16TagStart;i<u16LyricTagCount;i++)
            {
                pLyricTag[i].u16LyricPos = u32ParsedPos;
            }
            //msAPI_MIU_Copy(((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR))+u32ParsedPos, (U32)(&pu8Data[0]), LYRIC_CACHE_SIZE, MIU_SDRAM2SDRAM);
            memcpy(&pu8Data[0], (U8 *)_PA2VA((u32ParsedPos+((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR)))), LYRIC_CACHE_SIZE);

            // Search the end of one line.
            for(i=0; i<LYRIC_CACHE_SIZE; i+=u8Offset)
            {
                memcpy(&u16StartTag,&pu8Data[i],u8Offset);
                memcpy(&u16EndTag,&pu8Data[i+u8Offset],u8Offset);
                if(bIsUnicode)
                {
                    if(u16StartTag == 0x005B || u16EndTag == 0x005D)
                    {   // Next lyric.
                        break;
                    }
                }
                else
                {
                    if(u16StartTag == '[')
                    {   // Next lyric.
                        break;
                    }
                }
                u32ParsedPos += u8Offset;
                if(u32ParsedPos > u32FileSize)
                {
                    break;
                }
            }
            if(i < LYRIC_CACHE_SIZE)
            {
                bRet = TRUE;
            }
            else
            {
                MUSIC_DBG1(printf("One line lyric is too long!!\n"));
                u16LyricTagCount = u16TagStart;
                goto MApp_Music_LRC_Lyrics_Parser_END;
            }
        }
        else
        {
            break;  // No more lyrics.
        }
    }
    // Sort by time stamp.
    if(u16LyricTagCount > 1)
    {
        for(u16TagStart=0;u16TagStart<u16LyricTagCount-1;u16TagStart++)
        for(i=u16TagStart+1;i<u16LyricTagCount;i++)
        {
            if(pLyricTag[i].u32Time < pLyricTag[u16TagStart].u32Time)
            {
                U32 u32Temp;

                u32Temp = pLyricTag[i].u32Time;
                pLyricTag[i].u32Time = pLyricTag[u16TagStart].u32Time;
                pLyricTag[u16TagStart].u32Time = u32Temp;
                u32Temp = pLyricTag[i].u16LyricPos;
                pLyricTag[i].u16LyricPos = pLyricTag[u16TagStart].u16LyricPos;
                pLyricTag[u16TagStart].u16LyricPos = u32Temp;
            }
        }
#if 0
        for(i=0;i<u16LyricTagCount;i++)
        {
            printf("Time = %ld, %04x\n", pLyricTag[i].u32Time, pLyricTag[i].u16LyricPos);
        }
#endif
    }

MApp_Music_LRC_Lyrics_Parser_END:
    if(pu8Data)
    {
        msAPI_Memory_Free(pu8Data, BUF_ID_FILEBROWER);
    }

    return bRet;
}
#endif

void MApp_Music_Play(void)
{
    msAPI_Music_StopDecode();
    msAPI_DataStreamIO_Close(u32Mp3FileHandle);

    if(enMp3PlayStatus == MP3_STATUS_PLAYING ||
       enMp3PlayStatus == MP3_STATUS_PAUSE ||
       enMp3PlayStatus == MP3_STATUS_SCAN)
    {

        enMusicState = STATE_MUSIC_WAIT;
        enMp3PlayStatus = MP3_STATUS_STOP;
    }
    else
    {
        enMusicState = STATE_MUSIC_INIT;
        enMp3PlayStatus = MP3_STATUS_PLAYING;

    }
}

static U32 MApp_Music_SearchFirstFrame(U32 u32FileHandle, U32 u32ID3v2Offset)
{
    U8 u8FoundFrames = 0;
    U8* pFileBufPtr;
    U32 u32TotalOffset = 0;
    U32 u32Offset;
    U32 u32FirstFrameOffset = 0;
    U8 u8BitRateIndex_I,u8BitRateIndex_II;
    U8 u8Version_I,u8Version_II;
    U8 u8Layer_I,u8Layer_II;
    U8 u8PaddingFlag_I;
    U8 u8SampleRateIndex_I,u8SampleRateIndex_II;
    U32 u32Tag_I;
    U32 u32FileLength;
    U32 u32FileRemain;
    U32 u32FrameSize_I;
    U32 u32ParseBufSize = MP3_INFO_READ_LEN;
    U32 u32TimeLimit;
    U32 u32ReadLen = 0;

    u32FileLength = msAPI_DataStreamIO_Length(u32FileHandle);
    msAPI_Stream_Seek(u32FileHandle, u32ID3v2Offset);

//File length maybe smaller than u32ParseBufSize
    if ( u32FileLength <= u32ID3v2Offset )
        return MUSIC_CANNOT_FIND_1ST_FRAME;

    u32FileRemain = u32FileLength - u32ID3v2Offset;
    if(u32FileRemain > u32ParseBufSize)
    {
        u32ReadLen = u32ParseBufSize;
    }
    else
    {
        u32ReadLen = u32FileRemain;
    }

    u32FileRemain -= u32ReadLen;

    msAPI_DataStreamIO_Read(u32FileHandle, (void*)((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)), u32ReadLen);

    pFileBufPtr = (U8*)_PA2VA(((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)));

    u32Offset = 0;

    u32TimeLimit = msAPI_Timer_GetTime0();

    while(1)
    {

        if (msAPI_Timer_DiffTimeFromNow(u32TimeLimit) > MP3_SEARCH_FIRST_FRAME_TIME_OUT) // total sequence can't exceed 5 sec
        {
            return MUSIC_CANNOT_FIND_1ST_FRAME;
        }

#if ( WATCH_DOG == ENABLE )
        msAPI_Timer_ResetWDT();
#endif

        //Search first frame!
        while( ((pFileBufPtr[u32Offset] != 0xff) ||
                  ((pFileBufPtr[u32Offset+1] & 0xe0) != 0xe0)) &&
                  (u32Offset < (u32ReadLen-MP3_DATA_SIZE_NEED_FOR_VBR_HEADER_PARSING)) )
        {
            u32Offset++;
        }

        //printf("u32TotalOffset:0x%lx u32Offset:0x%lx\n",u32TotalOffset,u32Offset);
        if(u32Offset >= (u32ReadLen-MP3_DATA_SIZE_NEED_FOR_VBR_HEADER_PARSING))
        {
            if ( u32FileRemain == 0 )
            {
                return MUSIC_CANNOT_FIND_1ST_FRAME;
            }

            //Reload data to parse
            u32TotalOffset += u32Offset;
            msAPI_Stream_Seek(u32FileHandle, (u32ID3v2Offset+u32TotalOffset));
            u32ParseBufSize = M4A_STCO_LEN;

            if ( u32FileRemain > u32ParseBufSize )
            {
                u32ReadLen = u32ParseBufSize;
            }
            else
            {
                u32ReadLen = u32FileRemain;
            }

            msAPI_DataStreamIO_Read(u32FileHandle, (void*)((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)), u32ReadLen);
            u32FileRemain -= u32ReadLen;
            u32Offset = 0;
            continue;
        }
        else if(u32TotalOffset >= (u32FileLength-u32ID3v2Offset))
        {
            return MUSIC_CANNOT_FIND_1ST_FRAME;
        }

        memcpy(&u32Tag_I,(pFileBufPtr + u32Offset + 36),4);
        u32Tag_I=Swap32(u32Tag_I);
        if (u32Tag_I == MP3_TAG_XING)
        {
            u32Tag_I = MP3_FLAG_VBR_XING;
        }
        else if(u32Tag_I == MP3_TAG_VBRI)
        {
            u32Tag_I = MP3_FLAG_VBR_VBRI;
        }
        else
        {
            memcpy(&u32Tag_I,(pFileBufPtr + u32Offset + 21),4);
            u32Tag_I=Swap32(u32Tag_I);
            if (u32Tag_I == MP3_TAG_XING)
            {
                u32Tag_I = MP3_FLAG_VBR_XING;
            }
            else
            {
                memcpy(&u32Tag_I,(pFileBufPtr + u32Offset + 13),4);
                u32Tag_I=Swap32(u32Tag_I);
                if (u32Tag_I == MP3_TAG_XING)
                {
                    u32Tag_I = MP3_FLAG_VBR_XING;
                }
                else
                {
                    u32Tag_I = 0xFF;
                }
            }
        }

        if(u32Tag_I != 0xFF)
        {
            u32TotalOffset += u32Offset;
            return u32TotalOffset;
        }

        u8Version_I = (pFileBufPtr[u32Offset+1] >> 0x3) & 0x3;
        u8Layer_I = (pFileBufPtr[u32Offset+1] >> 0x1) & 0x3;
        u8PaddingFlag_I = (pFileBufPtr[u32Offset+2] & 0x02) >> 1;
        u8SampleRateIndex_I = (pFileBufPtr[u32Offset+2] & 0x0c) >> 2;
        u8BitRateIndex_I = ((pFileBufPtr[u32Offset+2]>>4) & 0x0F);

        if( !(((u8Version_I == EN_MP3_VERSION_2_5) ||
            (u8Version_I == EN_MP3_VERSION_2) ||
            (u8Version_I == EN_MP3_VERSION_1)) &&
            (u8SampleRateIndex_I < 3)) )
        {
            u32Offset++;
            u8FoundFrames = 0;
            continue;
        }

        u32FrameSize_I = msAPI_Music_GetMP3CBRFrameSize(u8Version_I, u8Layer_I, u8PaddingFlag_I, u8SampleRateIndex_I, u8BitRateIndex_I);

        if(u32FrameSize_I == 0)
        {
            u32Offset++;
            u8FoundFrames = 0;
            continue;
        }

        //printf("I Offset:0x%lx Offset_end:0x%lx u8Version:%u u16SampleRate:%u u32FrameSize_I:0x%lx\n",(u32ID3v2Offset+u32TotalOffset+u32Offset),(u32ID3v2Offset+u32TotalOffset+u32Offset+u32FrameSize_I),u8Version_I,u16SampleRate_I,u32FrameSize_I);

        if( ( (u32Offset+u32FrameSize_I) >= (u32ReadLen-MP3_DATA_SIZE_NEED_FOR_FRAME_HEADER_PARSING) )  && ( u32FrameSize_I <= u32FileRemain ) )
        {
            if ( u32FileRemain == 0 )
            {
                return MUSIC_CANNOT_FIND_1ST_FRAME;
            }

            //Reload data to parse
            u32TotalOffset += u32Offset;
            msAPI_Stream_Seek(u32FileHandle, (u32ID3v2Offset+u32TotalOffset));
            u32ParseBufSize = M4A_STCO_LEN;

            if ( u32FileRemain > u32ParseBufSize )
            {
                u32ReadLen = u32ParseBufSize;
            }
            else
            {
                u32ReadLen = u32FileRemain;
            }

            msAPI_DataStreamIO_Read(u32FileHandle, (void*)((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)), u32ReadLen);
            u32FileRemain -= u32ReadLen;
            u32Offset = 0;
            continue;
        }
        if((u32TotalOffset+u32FrameSize_I) >= (u32FileLength-u32ID3v2Offset))
        {
            return MUSIC_CANNOT_FIND_1ST_FRAME;
        }

        u8Version_II = (pFileBufPtr[u32Offset+u32FrameSize_I+1] >> 0x3) & 0x3;
        u8Layer_II = (pFileBufPtr[u32Offset+u32FrameSize_I+1] >> 0x1) & 0x3;
        u8SampleRateIndex_II = (pFileBufPtr[u32Offset+u32FrameSize_I+2] & 0x0c) >> 2;
        u8BitRateIndex_II = ((pFileBufPtr[u32Offset+u32FrameSize_I+2]>>4) & 0x0F);

        if( (pFileBufPtr[u32Offset+u32FrameSize_I] == 0xff) &&
            ((pFileBufPtr[u32Offset+u32FrameSize_I+1] & 0xe0) == 0xe0) &&
            (u8Version_I == u8Version_II) &&
            (u8Layer_I == u8Layer_II) &&
            (u8SampleRateIndex_I == u8SampleRateIndex_II) )
        {
            u8FoundFrames++;

            if(u8FoundFrames>=5)
            {
                u32TotalOffset = u32FirstFrameOffset;
                break;
            }
            else if(u8FoundFrames==1)
            {
                u32FirstFrameOffset = (u32TotalOffset + u32Offset);
            }
            else
            {
                u32Offset += u32FrameSize_I;
            }
        }
        else
        {
            u32Offset++;
            u8FoundFrames = 0;
            continue;
        }

    }
    return u32TotalOffset;
}

static U32 MApp_Music_CalculateMP3CBRDuration(ST_MP3_INFO *pMp3Info, U32 u32FileHandle)
{
    U32 u32Duration = 0;
    U32 u32FileSize = 0;
    U32 u32CurPosition = 0;
    U32 u32FrameCount;
    U32 u32FrameSize = 0;
    U32 u32Offset;
    U32 u32TotalBitRate;
    U8 u8BitRateIndexTemp;
    U8 u8CBRFrameCheck;
    U8 u8Version = 0, u8Layer = 0, u8PaddingFlag = 0, u8SampleRateIndex = 0, u8BitRateIndex = 0;
    U8 *pFileBufPtr;

    u32FileSize = pMp3Info->u32FileSize;

    if((pMp3Info->bID3TagV1) && (u32FileSize>pMp3Info->u16ID3TagV1Size))
    {
        u32FileSize -= pMp3Info->u16ID3TagV1Size;
    }

    if((pMp3Info->bID3TagV2) && (u32FileSize>pMp3Info->u32ID3TagV2Size))
    {
        u32FileSize -= pMp3Info->u32ID3TagV2Size;
    }

    u32CurPosition = pMp3Info->u32ID3TagV2Size;
    msAPI_Stream_Seek(u32FileHandle, u32CurPosition);
    msAPI_DataStreamIO_Read(u32FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);
    pFileBufPtr = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

    u32Offset = 0;
    u32FrameCount = 0;
    u32TotalBitRate = 0;
    u8CBRFrameCheck = 0;
    u8BitRateIndexTemp = 0;
    while((u32CurPosition < (u32FileSize + pMp3Info->u32ID3TagV2Size)) &&
        (u32CurPosition<(CBR_DURATION_LIMIT + pMp3Info->u32ID3TagV2Size)))
    {
        //Search first frame!
        if( (pFileBufPtr[u32Offset] == 0xff) && ((pFileBufPtr[u32Offset+1] & 0xe0) == 0xe0) )
        {
            u8Version = (pFileBufPtr[u32Offset+1] >> 0x3) & 0x3;
            u8Layer = (pFileBufPtr[u32Offset+1] >> 0x1) & 0x3;
            u8PaddingFlag = (pFileBufPtr[u32Offset+2] & 0x02) >> 1;
            u8SampleRateIndex = (pFileBufPtr[u32Offset+2] & 0x0c) >> 2;
            u8BitRateIndex = ((pFileBufPtr[u32Offset+2]>>4) & 0x0F);

            if( u32FrameCount == 0 )
            {
                u8BitRateIndexTemp = u8BitRateIndex;
            }
            else if(u8BitRateIndexTemp == u8BitRateIndex) //u32FrameCount > 0
            {
                u8CBRFrameCheck++;
                if((u8CBRFrameCheck >= 10) && (u32FrameCount <= 15))
                {
                    break;
                }
            }
            else
            {
                u8CBRFrameCheck = 0;
            }

            u32FrameSize = msAPI_Music_GetMP3CBRFrameSize(u8Version, u8Layer, u8PaddingFlag, u8SampleRateIndex, u8BitRateIndex);
            if(u32FrameSize == 0)
            {
                //It is wrong frame, read next byte to try
                u32FrameSize = 1;
                u32FrameCount = 0;
            }
            else
            {
                u32FrameCount++;
            }

            u32CurPosition += u32FrameSize;

            if(u8BitRateIndex < 16)
            {
                u32TotalBitRate += msAPI_Music_GetBitRateByIndex(u8Version, u8Layer, u8BitRateIndex);
            }
        }
        else
        {
            u32Offset++;
            u32FrameSize = 0;
            u32CurPosition++;
        }

        if((u32Offset+u32FrameSize)>(MP3_INFO_READ_LEN-MP3_DATA_SIZE_NEED_FOR_FRAME_HEADER_PARSING))  //FF XX XX
        {
            msAPI_Stream_Seek(u32FileHandle, u32CurPosition);
            msAPI_DataStreamIO_Read(u32FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);
            u32Offset = 0;
        }
        else
        {
            u32Offset += u32FrameSize;
        }

    }

    //printf("u32FileSize:0x%lx u32FrameCount:%lu u32FrameSize:0x%lx u8BitRateIndex:%u\n",u32FileSize,u32FrameCount,u32FrameSize,u8BitRateIndex);

    if(u8CBRFrameCheck >= 10)          //CBR
    {
        U32 u32BitRate;
        u32BitRate = msAPI_Music_GetBitRateByIndex(u8Version, u8Layer, u8BitRateIndexTemp);// Kps
        if(u32BitRate > 0)
        {
            u32Duration = (u32FileSize /u32BitRate)*8;
            u32Duration /= 1000;
            if(u32Duration < 1)
            {
                u32Duration = 1;   //Smaller than 1000ms, set as 1s
            }
            pMp3Info->u16BitRate = u32BitRate;
        }
    }
    else if( (u32FileSize >= CBR_DURATION_LIMIT) && (u32FrameCount >0) )
    {
        pMp3Info->u16BitRate = u32TotalBitRate/u32FrameCount;
        U64 u64TempFileSize = ((U64)u32FileSize<<3);
        u32Duration = (U32)((u64TempFileSize/(U64)pMp3Info->u16BitRate)/1000);
    }
    else if( (u32FrameSize!=0) && (u8BitRateIndex < 16) && (u32FrameCount>0) )
    {
        U32 u32BitRate;
        u32BitRate = msAPI_Music_GetBitRateByIndex(u8Version, u8Layer, u8BitRateIndex);// Kps
        if(u32BitRate > 0)
        {
            u32Duration = (u32FrameCount * u32FrameSize * 8) / u32BitRate;
            u32Duration /= 1000;
            pMp3Info->u16BitRate = u32TotalBitRate/u32FrameCount;

            if(u32Duration < 1)
            {
                u32Duration = 1;   //Smaller than 1000ms, set as 1s
            }
        }
    }
    else
    {
        u32Duration = 0;
    }

    return u32Duration;
}

#if ENABLE_FLAC

BOOLEAN MApp_Music_ParseFlac_StreamInfo(U32 u32Offset)
{

    U8* pu8Data = NULL;
    U32 i = 0;

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        FLAC_ERR(printf("u32Mp3FileHandle is NULL at line:%d\n",__LINE__));
        return FALSE;
    }

    U32 u32Remain = 0;

    msAPI_DataStreamIO_Seek(u32Mp3FileHandle,u32Offset,E_DATA_STREAM_SEEK_SET);
    u32Remain = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),0x22);
    pu8Data = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

    if(u32Remain!=0)
    {
       FLAC_ERR(printf("not enough byte to read at line:%d\n",__LINE__));
       return FALSE;
    }

    // Flush mininum/maxinum block size, minimum/maximum frame size
    i += 10;

    // sample rate
    m_stFlacInfo.u32SampleRate =  COMB_U32(0, (pu8Data[i]>>4), ((pu8Data[i]&0xF)<<4)|(pu8Data[i+1]>>4), ((pu8Data[i+1]&0xF)<<4)|(pu8Data[i+2]>>4));
    FLAC_DBG(printf("sample rate: %ld\n", m_stFlacInfo.u32SampleRate));

    // Channel
    m_stFlacInfo.u8Channel = (pu8Data[i+2]>>1)&0x7;
    FLAC_DBG(printf("channel :%d\n ", m_stFlacInfo.u8Channel));

    // Bits/Sample
    m_stFlacInfo.u8BitsPerSample = ((pu8Data[i+2] & 0x1)<<4) | (pu8Data[i+3]>>4);
    FLAC_DBG(printf("bits/sample : %d\n", m_stFlacInfo.u8BitsPerSample));

    // Total Sample
    m_stFlacInfo.u64TotalSamples = (U64)(pu8Data[i+3] & 0xF)<<32 | COMB_U32(pu8Data[i+4], pu8Data[i+5], pu8Data[i+6], pu8Data[i+7]);
    FLAC_DBG(printf("total sample: %lld\n", m_stFlacInfo.u64TotalSamples));

    // duration
    if ((m_stFlacInfo.u64TotalSamples != 0) && (m_stFlacInfo.u32SampleRate != 0))
    {
        m_stFlacInfo.u32Duration = (U32)m_stFlacInfo.u64TotalSamples/m_stFlacInfo.u32SampleRate;
        FLAC_DBG(printf("duration: %ld\n", m_stFlacInfo.u32Duration));

    }
    return TRUE;


}

BOOLEAN MApp_Music_ParseFlac_SeekTable(U32 u32Offset, U32 u32TableLen)
{

    if(u32Mp3FileHandle==INVALID_DATA_STREAM_HDL)
    {
        FLAC_ERR(printf("u32Mp3FileHandle is NULL at line:%d\n",__LINE__));
        return FALSE;
    }

    m_stFlacInfo.u32SeekEntryCount = u32TableLen/FLAC_SEEKPOINT_LEN;

    if(m_stFlacInfo.pstSeekTable!=NULL)
    {
        msAPI_Memory_Free(m_stFlacInfo.pstSeekTable,BUF_ID_FILEBROWER);
        FLAC_DBG(printf("[erroe] stFlacInfo.pSeekTable is not null at Line:%d\n",__LINE__));
        m_stFlacInfo.pstSeekTable = NULL;
    }

    m_stFlacInfo.pstSeekTable = (ST_FLAC_SEEK_TABLE *)msAPI_Memory_Allocate(m_stFlacInfo.u32SeekEntryCount * sizeof(ST_FLAC_SEEK_TABLE),BUF_ID_FILEBROWER);

    FLAC_DBG(printf("seek table: %lx(%ld)\n", u32TableLen, u32TableLen));

    if (m_stFlacInfo.pstSeekTable == NULL)
    {
        FLAC_ERR(printf("not enought memory for seek table: %lx(%ld)\n", u32TableLen, u32TableLen));
        return FALSE;
    }

    U8 *pu8Data = NULL;
    U32 u32Remain = 0, u32TrueRead=0;

    msAPI_DataStreamIO_Seek(u32Mp3FileHandle,u32Offset,E_DATA_STREAM_SEEK_SET);
    u32Remain = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),MP3_INFO_READ_LEN);
    u32TrueRead = MP3_INFO_READ_LEN - u32Remain;
    pu8Data = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

    U32 u32BufferIdx = 0;
    U32 u32TableIdx = 0;

    if(u32TrueRead < FLAC_SEEKPOINT_LEN)
    {
        FLAC_ERR(printf("not enough byte to read at line:%d\n",__LINE__));
        goto Lable_ParseFlacTable_End;
    }

    for(u32TableIdx=0; u32TableIdx<m_stFlacInfo.u32SeekEntryCount; u32TableIdx++)
    {
        #define LOAD_U32(x) ((U32)(*(x) << 24)) | ((U32)(*(x + 1) << 16)) | ((U32)(*(x + 2) << 8)) | ((U32)(*(x + 3)))
        U32 u32PartH, u32PartL;

        u32PartH = LOAD_U32(pu8Data+u32BufferIdx);
        u32PartL = LOAD_U32(pu8Data+u32BufferIdx+4);
        m_stFlacInfo.pstSeekTable[u32TableIdx].u64SampleNum = ((U64)u32PartH << 32) | u32PartL;

        u32PartH = LOAD_U32(pu8Data + u32BufferIdx + 8);
        u32PartL = LOAD_U32(pu8Data + u32BufferIdx+ 12);
        m_stFlacInfo.pstSeekTable[u32TableIdx].u64FrameOffset = ((U64)u32PartH << 32) | u32PartL;

        m_stFlacInfo.pstSeekTable[u32TableIdx].u16SamplesOfFrame = ((U16)(*(pu8Data + u32BufferIdx+ 16)) << 8) | ((U16)(*(pu8Data + u32BufferIdx + 17)));

        FLAC_DBG(printf("idx: %ld  0x%llx  0x%llx  0x%x\n", u32TableIdx, m_stFlacInfo.pstSeekTable[u32TableIdx].u64SampleNum,
        m_stFlacInfo.pstSeekTable[u32TableIdx].u64FrameOffset, m_stFlacInfo.pstSeekTable[u32TableIdx].u16SamplesOfFrame ));

        u32BufferIdx = u32BufferIdx+FLAC_SEEKPOINT_LEN;

        if(u32BufferIdx+FLAC_SEEKPOINT_LEN > u32TrueRead)
        {
            msAPI_DataStreamIO_Seek(u32Mp3FileHandle,u32Offset+(u32TableIdx * FLAC_SEEKPOINT_LEN),E_DATA_STREAM_SEEK_SET);
            u32Remain = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),MP3_INFO_READ_LEN);
            u32TrueRead = MP3_INFO_READ_LEN - u32Remain;
            u32BufferIdx = 0;

            if(u32TrueRead < FLAC_SEEKPOINT_LEN)
            {
                FLAC_ERR(printf("not enough byte to read at line:%d\n",__LINE__));
                goto Lable_ParseFlacTable_End;
            }
        }
    }

    return TRUE;

Lable_ParseFlacTable_End:

    if(m_stFlacInfo.pstSeekTable!=NULL)
    {
        msAPI_Memory_Free(m_stFlacInfo.pstSeekTable,BUF_ID_FILEBROWER);
        FLAC_DBG(printf("free stFlacInfo.pSeekTable\n"));
        m_stFlacInfo.pstSeekTable = NULL;
    }
    m_stFlacInfo.u32SeekEntryCount = 0;
    return FALSE;

}




static BOOLEAN _MApp_Music_Flac_CollectInfo(void)
{

    BOOLEAN bBlockStreamInfo = FALSE;
    BOOLEAN bBlockSeek = FALSE;

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC2);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        FLAC_ERR(printf("Open file failed at line: %d\n",__LINE__));
        return FALSE;
    }

    stMp3Info.u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);

    if (stMp3Info.u32FileSize < 42)  //FileSize too small, no StreamInfo Block
    {
        FLAC_ERR(printf("File size smaller than 42, no streamInfo Block\n"));
        goto Lable_CollectFLACInfo_End;
    }

    U32 u32Idx = 0;
    U32 u32BufferIdx = 0;
    U32 u32MetaDataSize = 0;
    U8 u8LastMetaDataFlag = 0;
    U8 u8BlockType = 0;
    U8* pu8Data = NULL;

    U32 u32Remain = 0;
    u32Idx = 4;

    pu8Data = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));
    /*flac need skip the ID3 TAG*/
     msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN); // 4k is xdata window size
     U32 u32TagSize = msAPI_Music_Parse_ID3v2(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN, &stMp3Info.stID3v2, FALSE);
     if (u32TagSize > 0)
     {
	     u32Idx += u32TagSize;
	     stMp3Info.bID3TagV2 = TRUE;
     }
     FLAC_DBG(printf("flac u32TagSize is %ld,u32Idx is %ld \n",u32TagSize,u32Idx));

    while(u32Idx < stMp3Info.u32FileSize)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle,u32Idx,E_DATA_STREAM_SEEK_SET);
        u32Remain = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),0x4);
        u32BufferIdx = 0;

        if(u32Remain!=0)
        {
            FLAC_ERR(printf("not enough byte to read at line:%d\n",__LINE__));
            goto Lable_CollectFLACInfo_End;
        }

        u8LastMetaDataFlag = (pu8Data[u32BufferIdx] & 0x80) >> 7;
        u8BlockType = pu8Data[u32BufferIdx] & 0x7F;
        u32MetaDataSize = COMB_U32(0, pu8Data[u32BufferIdx+1], pu8Data[u32BufferIdx+2], pu8Data[u32BufferIdx+3]);
        u32Idx += 4;

        FLAC_DBG(printf("%d %d 0x%lx\n", u8LastMetaDataFlag, u8BlockType, u32MetaDataSize));

        if( (bBlockStreamInfo==FALSE) && (u8BlockType ==0))   //Stream info
        {
            bBlockStreamInfo = TRUE;

            if( MApp_Music_ParseFlac_StreamInfo(u32Idx) == FALSE )
            {
                FLAC_ERR(printf("Parse StreamInfo Block Fail\n"));
                goto Lable_CollectFLACInfo_End;
            }

            FLAC_DBG(printf("stream info u32Idx: 0x%lx\n", u32Idx));

        }
        else if((bBlockSeek==FALSE) && (u8BlockType ==3))    //seektable, optional
        {
            m_stFlacInfo.bHasSeekTable = MApp_Music_ParseFlac_SeekTable(u32Idx, u32MetaDataSize);
            bBlockSeek = TRUE;
        }

        if(u8LastMetaDataFlag==1)  //ready to leave this loop
        {
            m_stFlacInfo.u32DataOffset =  u32Idx +  u32MetaDataSize;   // first frame data position
            FLAC_DBG(printf("stFlacInfo->u32DataOffset: %lu\n",m_stFlacInfo.u32DataOffset));

            if( bBlockStreamInfo == FALSE)   //no Stream Block, illegal
            {
                FLAC_ERR(printf("no StreamInfo Block\n"));
                goto Lable_CollectFLACInfo_End;
            }
            break;  //end of while loop
        }
        u32Idx += u32MetaDataSize;
    }

    stMp3Info.u32MusicDataBytesLeft = stMp3Info.u32FileSize - m_stFlacInfo.u32DataOffset + 1;
    stMp3Info.u32Duration = m_stFlacInfo.u32Duration;
    stMp3Info.u16SampleRate = (U16)m_stFlacInfo.u32SampleRate;
    stMp3Info.u16BitRate =(U64)stMp3Info.u32MusicDataBytesLeft*(U64)m_stFlacInfo.u32SampleRate*8/m_stFlacInfo.u64TotalSamples/1000;

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
    FLAC_DBG(printf("Flac collection done\n"));
    return TRUE;

Lable_CollectFLACInfo_End:

    if(m_stFlacInfo.pstSeekTable!=NULL)
    {
        msAPI_Memory_Free(m_stFlacInfo.pstSeekTable,BUF_ID_FILEBROWER);
        FLAC_DBG(printf("free stFlacInfo.pSeekTable\n"));
        m_stFlacInfo.pstSeekTable = NULL;
    }

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;

    FLAC_ERR(printf("FLAC collection Error\n"));
    return FALSE;
}
#endif

#if ENABLE_AC3

static BOOLEAN _MApp_Music_Ac3_CollectInfo(void)
{

    memset(&m_stAc3Info,0,sizeof(m_stAc3Info));
    memset(&stMp3Info,0,sizeof(stMp3Info));

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC2);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        AC3_ERR(printf("Open file failed at line: %d\n",__LINE__));
        return FALSE;
    }

#if (ENABLE_AAC)
    //container: m4a, codec:ac3
    AC3_DBG(printf("boxM4a.bM4aHeader%d   boxM4a.u32MdatSize:0x%x  boxM4a.u32MdatLocation:%x\n",stM4aInfo.bM4aHeader,stM4aInfo.u32MdatSize,stM4aInfo.u32MdatLocation));
    if((stM4aInfo.bM4aHeader==TRUE) && (stM4aInfo.u32MdatSize>0))
    {
        m_stAc3Info.u32FileStart = stM4aInfo.u32MdatLocation;
        stMp3Info.u32FileSize = stM4aInfo.u32MdatSize;
    }
    else
#endif
    {
        m_stAc3Info.u32FileStart = 0;
        stMp3Info.u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
    }
    msAPI_DataStreamIO_Seek(u32Mp3FileHandle,m_stAc3Info.u32FileStart,E_DATA_STREAM_SEEK_SET);
    AC3_DBG(printf("m_stAc3Info.u32FileStart:0x%x   stMp3Info.u32FileSize:0x%x\n",m_stAc3Info.u32FileStart,stMp3Info.u32FileSize));

    U8* pu8Data = NULL;
    pu8Data = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

    U32 u32Remain = 0;
    u32Remain = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),AC3_PARSE_BUFFER_SIZE);

    if(u32Remain!=0)
    {
        AC3_ERR(printf("First frame too short\n"));
        goto Lable_CollectAC3Info_Error;
    }

    U16 u16SyncWord  = 0;
    u16SyncWord = COMB_U16(pu8Data[0],pu8Data[1]);

    U32 u32count = 0;
    U8 u8tmp = 0;


    //search first frame
    if( u16SyncWord == AC3_SYNC_WORD_BE )
    {
        AC3_DBG(printf("detect the Big endian sync word."));
        for( u32count = 0 ; u32count < AC3_PARSE_BUFFER_SIZE ; u32count += 2 )
        {
            u8tmp = pu8Data[u32count];
            pu8Data[u32count]   = pu8Data[u32count+1];
            pu8Data[u32count+1] = u8tmp;
        }
        u16SyncWord = AC3_SYNC_WORD;
    }


    U32 u32BitRate = 0;
    U32 u32SampleRate = 0;

    if( u16SyncWord == AC3_SYNC_WORD )
    {
        m_stAc3Info.u8Bsid = pu8Data[5]>>3;
        if( m_stAc3Info.u8Bsid <= 0x08) //ac3 format
        {
            m_stAc3Info.bIsEAC3 = FALSE;
            m_stAc3Info.u16Crc  = COMB_U16(pu8Data[2],pu8Data[3]);
            m_stAc3Info.u8Fscod = pu8Data[4]>>6;
            if( ( m_stAc3Info.u8Fscod ) == 0x11 )
            {
                AC3_ERR(printf("AC3 find Fscod error.\n"));

                goto Lable_CollectAC3Info_Error;
            }
            m_stAc3Info.u8FrmsizeCod = pu8Data[4] & 0x3F;
            if( ( m_stAc3Info.u8FrmsizeCod ) > 37)
            {
                AC3_ERR(printf("AC3 find FrameSizeCode error.\n"));
                goto Lable_CollectAC3Info_Error;
            }
            m_stAc3Info.u8Acmod      = ( pu8Data[6] & 0xE0 ) >> 5;
            m_stAc3Info.u32FrameSize = u32Ac3FramesizeTable[m_stAc3Info.u8Fscod][m_stAc3Info.u8FrmsizeCod] * 2;

            stMp3Info.u16Channel     = (U16)u32Ac3ChannelTable[m_stAc3Info.u8Acmod];
            u32SampleRate  = u32Ac3SampleRateTable[m_stAc3Info.u8Fscod];
            u32BitRate     = u32Ac3BitrateTable[m_stAc3Info.u8FrmsizeCod] / 1000;


        }
        else if((m_stAc3Info.u8Bsid > 0xa) && (m_stAc3Info.u8Bsid<=0x10))//ac3+ format
        {
            m_stAc3Info.bIsEAC3 = TRUE;
            m_stAc3Info.u32FrameSize = (U32) ( ( ( ( pu8Data[2] & 0x07 ) << 8 ) | pu8Data[3] ) + 1) * 2;//in WORD, so we have to transfer the value to bytes..
            m_stAc3Info.u8Fscod = pu8Data[4]>>6;

            if( ( m_stAc3Info.u8Fscod ) == 0x3 )
            {
                U8 u8fscod2 = ( pu8Data[4] & 0x3f ) >> 4;
                if( u8fscod2 == 0x3 )
                {
                    AC3_ERR(printf("Ac3 find sampleRate error.\n"));
                    goto Lable_CollectAC3Info_Error;

                }
                u32SampleRate  =  u32Ac3SampleRateTable[u8fscod2] / 2;
                m_stAc3Info.u8NumBlk = (U8) u32Ac3NumBlkTable[0x3];
            }
            else
            {
                u32SampleRate =  u32Ac3SampleRateTable[ m_stAc3Info.u8Fscod ];
                m_stAc3Info.u8NumBlk = (U8) u32Ac3NumBlkTable[ ( pu8Data[4] & 0x3f ) >> 4 ];
            }

            m_stAc3Info.u8Acmod = ( pu8Data[4] & 0x0F ) >> 1;
            m_stAc3Info.u8Lfeon = pu8Data[4] & 0x01;
            stMp3Info.u16Channel = (U16) (u32Ac3ChannelTable[ m_stAc3Info.u8Acmod ] + ( m_stAc3Info.u8Lfeon ));
            u32BitRate = ( ( ( ( 8 * ( m_stAc3Info.u32FrameSize ) )*( u32SampleRate) ) / ( m_stAc3Info.u8NumBlk ) ) / 256 ) / 1000;
        }
        else
        {
            AC3_ERR(printf("Ac3 doesn't support bsid = %d.\n", m_stAc3Info.u8Bsid));
            goto Lable_CollectAC3Info_Error;
        }

        if(u32BitRate==0)
        {
            AC3_ERR(printf("Bitrate is 0\n"));
            goto Lable_CollectAC3Info_Error;
        }

        stMp3Info.u32MusicDataBytesLeft = stMp3Info.u32FileSize;

#if (ENABLE_AAC)
        if(stM4aInfo.bM4aHeader==TRUE)
        {
            stMp3Info.u32Duration = stM4aInfo.u32Duration;
            printf("u32Duration:%d from m4a container\n",stMp3Info.u32Duration);
        }
        else
#endif
        {
            stMp3Info.u32Duration = ( 8 * stMp3Info.u32FileSize ) / u32BitRate;
            if( ( stMp3Info.u32Duration ) < 1000)
            {
                stMp3Info.u32Duration = 1;
            }
            else
            {
                stMp3Info.u32Duration = ( stMp3Info.u32Duration ) / 1000;
            }
            printf("u32Duration:%d from ac3 header\n",stMp3Info.u32Duration);
        }

        stMp3Info.u16SampleRate = (U16) u32SampleRate;
        stMp3Info.u16BitRate = (U16) u32BitRate;
        stMp3Info.bCheckFfFb = TRUE;  //allow FF/FB

        AC3_DBG(printf("AC3 u32FrameSize: %lu\n", m_stAc3Info.u32FrameSize));
        AC3_DBG(printf("AC3 u32SampleRate: %lu\n",u32SampleRate));
        AC3_DBG(printf("AC3 u16SampleRate: %lu\n",stMp3Info.u16SampleRate));
        AC3_DBG(printf("AC3 u16Channel: %d\n",    stMp3Info.u16Channel));
        AC3_DBG(printf("AC3 u32BitRate: %lu\n",   u32BitRate));
        AC3_DBG(printf("AC3 u16BitRate: %lu\n",   stMp3Info.u16BitRate));
        AC3_DBG(printf("AC3 u32DataLeft: %lu\n",  stMp3Info.u32MusicDataBytesLeft));
        AC3_DBG(printf("AC3 u32Duration: %lu\n",  stMp3Info.u32Duration));
    }//end of search first frame


    //search second frame
    msAPI_Stream_Seek(u32Mp3FileHandle, m_stAc3Info.u32FileStart + m_stAc3Info.u32FrameSize);

    u32Remain = msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),AC3_PARSE_BUFFER_SIZE);

    if(u32Remain!=0)
    {
        AC3_ERR(printf("File length too short\n"));
        goto Lable_CollectAC3Info_Error;
    }

    u16SyncWord = COMB_U16( pu8Data[0] , pu8Data[1] );
    if(( u16SyncWord != AC3_SYNC_WORD) &&
       ( u16SyncWord != AC3_SYNC_WORD_BE))
    {
        AC3_ERR(printf("Second frame too short!\n"));
        goto Lable_CollectAC3Info_Error;

    }//end search second frame

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    return TRUE;


Lable_CollectAC3Info_Error:
    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    return FALSE;
}

#endif

static BOOLEAN MApp_Music_CollectInfo(ST_MP3_INFO *pMp3Info)
{
    U32 u32Offset, u32TimeLimit;
    U32 u32FirstFrameOffset;

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC2);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        MUSIC_DBG(printf("Open file failed\n"));
        _enMusic_ErrCode = E_MUSIC_ERR_DATA_OPERATION_FAILURE;
        return FALSE;
    }

    // get MP3 ID3 v1 information
    pMp3Info->u16ID3TagV1Size = MP3_ID3_V1_LEN;
    pMp3Info->u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);

    if(pMp3Info->u32FileSize > MP3_ID3_V1_LEN)
    {
        u32Offset = (pMp3Info->u32FileSize - MP3_ID3_V1_LEN);
        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
        msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_ID3_V1_LEN);
        pMp3Info->bID3TagV1= msAPI_Music_Parse_ID3v1(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), &pMp3Info->stID3v1);
    }

    // get MP3 ID3 v2 information
    msAPI_Stream_Seek(u32Mp3FileHandle, 0);
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)), M4A_STCO_LEN);
    u32Offset = msAPI_Music_Parse_ID3v2(u32Mp3FileHandle, ((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR)), M4A_STCO_LEN, &pMp3Info->stID3v2, FALSE);
    if(u32Offset != 0) //Fix double ID3 tag ex:h-.mp3
    {
        pMp3Info->bID3TagV2 = TRUE;
        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
        msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);
        u32Offset += msAPI_Music_Parse_ID3v2(u32Mp3FileHandle, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN, &pMp3Info->stID3v2, TRUE);
    }
    pMp3Info->u32ID3TagV2Size = u32Offset;

    //Skip Garbage.
    MUSIC_DBG(printf("1 pMp3Info->u32ID3TagV2Size=0x%ld\n",pMp3Info->u32ID3TagV2Size));
    u32FirstFrameOffset = MApp_Music_SearchFirstFrame(u32Mp3FileHandle, pMp3Info->u32ID3TagV2Size);
    if(u32FirstFrameOffset == MUSIC_CANNOT_FIND_1ST_FRAME)
    {
        MUSIC_DBG(printf("!!!! Fail: Can not search 1st Frame!!!!\n"));
        _enMusic_ErrCode = E_MUSIC_ERR_DECODE_HEADER_FAILURE;
        return FALSE;
    }
    else
    {
        pMp3Info->u32ID3TagV2Size += u32FirstFrameOffset;
    }
    MUSIC_DBG(printf("2 pMp3Info->u32ID3TagV2Size=0x%ld\n",pMp3Info->u32ID3TagV2Size));

    // get MP3 layer, bitrate, etc.
    msAPI_Stream_Seek(u32Mp3FileHandle, pMp3Info->u32ID3TagV2Size);
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);
    pMp3Info->u32Duration = msAPI_Music_GetFileTime(
            ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),
            pMp3Info->u32FileSize,
            &pMp3Info->enVersion,
            &pMp3Info->enLayer,
            &pMp3Info->u16BitRate,
            &pMp3Info->u16SampleRate,
            &pMp3Info->u8Flag,
            &pMp3Info->u16TOCLength,
            &pMp3Info->u8TOC[0]);

    if(pMp3Info->u32Duration == 0)
    {
        pMp3Info->u32Duration = MApp_Music_CalculateMP3CBRDuration(pMp3Info, u32Mp3FileHandle);
    }

    if ((pMp3Info->u32Duration == 0)
        || ((pMp3Info->enLayer != EN_MP3_LAYER_3)
            && (pMp3Info->enLayer != EN_MP3_LAYER_2)
            && (pMp3Info->enLayer != EN_MP3_LAYER_1))
        ||(pMp3Info->u16BitRate == MP3_INVALID_RATE)
        ||(pMp3Info->u16SampleRate == MP3_INVALID_RATE))
    {
        // unable to get the relative info, ask DSP's help
        // it doesn't matter which codec isloaded to DSP
        MUSIC_DBG(printf("ask DSP's help\n"));

        if((pMp3Info->enLayer == EN_MP3_LAYER_1) || (pMp3Info->enLayer == EN_MP3_LAYER_2))
        {
            msAPI_Music_Init(MSAPI_AUD_DVB_MPEG, INIT_VOLUME);
        }
        else
        {
            msAPI_Music_Init(MSAPI_AUD_DVB_MP3, INIT_VOLUME);
        }

        MApp_Music_OpenFile();
        msAPI_Music_StartBrowse();
        u32TimeLimit = msAPI_Timer_GetTime0();
        while (msAPI_Timer_DiffTimeFromNow(u32TimeLimit) < MP3_SEARCH_BY_DSP_TIME_OUT) // total sequence can't exceed 300 ms
        {
            MApp_Music_Input();
            if (msAPI_Music_GetCurrentFrameNumber() > 0) // 1st frame is parsed
            {
                pMp3Info->enLayer = msAPI_Music_GetLayer();
                pMp3Info->u16BitRate = msAPI_Music_GetBitRate();
                pMp3Info->u16SampleRate = msAPI_Music_GetSampleRate();
                pMp3Info->u8Flag = 0x0; // unknown, treat it like a CBR
                pMp3Info->u32Duration = pMp3Info->u32FileSize / (((U32)pMp3Info->u16BitRate * 1000) >> 3);

                break;
            }
#if( WATCH_DOG == ENABLE )
            msAPI_Timer_ResetWDT();
#endif
        }

        //If DSP cannot parse MP3 Frame, return unsupport file
        if((pMp3Info->u16BitRate == 0) && (msAPI_Music_GetPlayTick()==0))
        {
            msAPI_Music_StopDecode();
            msAPI_DataStreamIO_Close(u32Mp3FileHandle);
            u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
            _enMusic_ErrCode = E_MUSIC_ERR_DECODE_FAILURE;
            return FALSE;
        }

        msAPI_Music_StopDecode();
    }

    //For some stream mode (ex. DLNA), maybe not support file length.
    if(msAPI_DataStreamIO_Length(u32Mp3FileHandle) == 0xFFFFFFFF)
    {
        pMp3Info->u32Duration = 0xFFFFFFFF;
    }

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;

    return TRUE;
}

#if (ENABLE_FLAC)
static BOOLEAN _MApp_Music_Flac_DataInput(U32 dwReqAddress, U32 u32ReqBytes)
{
    U32 u32ReadLeft;

    //FLAC_DBG(printf("stMp3Info.u32MusicDataBytesLeft:%lu   u32ReqBytes:%lu\n",stMp3Info.u32MusicDataBytesLeft,u32ReqBytes));
    if(stMp3Info.u32MusicDataBytesLeft>= u32ReqBytes)
    {
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32ReqBytes);
        stMp3Info.u32MusicDataBytesLeft -= u32ReqBytes;
    }
    else
    {
        msAPI_Music_CleanFileEndData(dwReqAddress,u32ReqBytes,0x0UL);
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, stMp3Info.u32MusicDataBytesLeft);
        msAPI_Music_FileEndDataHandle((u32ReqBytes-stMp3Info.u32MusicDataBytesLeft)+u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    if(u32ReadLeft>0)
    {
        msAPI_Music_FileEndDataHandle(u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    return TRUE;
}



#endif

#if (ENABLE_AC3)
static BOOLEAN _MApp_Music_Ac3_DataInput(U32 dwReqAddress, U32 u32ReqBytes)
{
    U32 u32ReadLeft;

    //AC3_DBG(printf("stMp3Info.u32MusicDataBytesLeft:%lu   u32ReqBytes:%lu\n",stMp3Info.u32MusicDataBytesLeft,u32ReqBytes));
    if(stMp3Info.u32MusicDataBytesLeft>= u32ReqBytes)
    {
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32ReqBytes);
        stMp3Info.u32MusicDataBytesLeft -= u32ReqBytes;
    }
    else
    {
        msAPI_Music_CleanFileEndData(dwReqAddress,u32ReqBytes,0x0UL);
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, stMp3Info.u32MusicDataBytesLeft);
        msAPI_Music_FileEndDataHandle((u32ReqBytes-stMp3Info.u32MusicDataBytesLeft)+u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    if(u32ReadLeft>0)
    {
        msAPI_Music_FileEndDataHandle(u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    return TRUE;
}
#endif

#if (ENABLE_WAV)
static BOOLEAN _MApp_Music_Wav_CollectInfo(void)
{
    U8 *pu8Data=(U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));
    //U32 u32CurrentPosition = 0;
    BOOLEAN bRet=FALSE;
    U32 u32WAVBuffReadLength = (MP3_INFO_READ_LEN & 0xFFFFF000); //4k alignment

    U32 u32WAVFileSize = 0;

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        MUSIC_DBG(printf("Open file failed\n"));
        return FALSE;
    }

    u32WAVFileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);

    if(u32WAVFileSize < MUSIC_WAV_HEADER_LENGTH)
    {
        WAV_DBG(printf("WAV file header length is smaller than 44 bytes\n"));
        return FALSE;
    }

    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), u32WAVBuffReadLength);


#if 0
    if((pu8Data[0] == 'R') && (pu8Data[1] == 'I') &&  (pu8Data[2] == 'F') && (pu8Data[3] == 'F'))
    {
        U32 u32CurrentPosition = 0;

        u32CurrentPosition += 4;  //Offset RIFF
        memcpy(&stWavChunk.u32RIFFChunkSize,pu8Data+u32CurrentPosition,4);
        u32CurrentPosition += 4; //RIFF offset chunk size

        if((pu8Data[u32CurrentPosition] == 'W') && (pu8Data[u32CurrentPosition+1] == 'A') &&
            (pu8Data[u32CurrentPosition+2] == 'V') && (pu8Data[u32CurrentPosition+3] == 'E') &&
            (pu8Data[u32CurrentPosition+4] == 'f') && (pu8Data[u32CurrentPosition+5] == 'm') &&
            (pu8Data[u32CurrentPosition+6] == 't') && (pu8Data[u32CurrentPosition+7] == ' '))
        {
            u32CurrentPosition += 8; //offset "WAVEfmt "

            memcpy(&stWavChunk.u32fmtChunkSize,pu8Data+u32CurrentPosition,4);
            u32CurrentPosition += 4;//offset u32WavHeaderSize

            memcpy(&stWavChunk.u16FormatTag,pu8Data+u32CurrentPosition,2);
            u32CurrentPosition += 2;//offset u16FormatTag

            memcpy(&stWavChunk.u16Channels,pu8Data+u32CurrentPosition,2);
            u32CurrentPosition += 2;//offset u8Channels

            memcpy(&stWavChunk.u32SamplesPerSec,pu8Data+u32CurrentPosition,4);
            u32CurrentPosition += 4;//offset u32SamplesPerSec

            memcpy(&stWavChunk.u32AvgBytesPerSec,pu8Data+u32CurrentPosition,4);
            u32CurrentPosition += 4;//offset u32AvgBytesPerSec

            memcpy(&stWavChunk.u16BlockSize,pu8Data+u32CurrentPosition,2);
            u32CurrentPosition += 2;//offset Data block size,

            memcpy(&stWavChunk.u16BitsPerSample,pu8Data+u32CurrentPosition,2);
            u32CurrentPosition += 2;//offset u16BitsPerSample

            if(stWavChunk.u32fmtChunkSize > 0x10)
            {
                memcpy(&stWavChunk.u16CExtensionSize,pu8Data+u32CurrentPosition,2);
                u32CurrentPosition += 2;//offset u16CExtensionSize
            }
            else
            {   //No Size of the extension
                stWavChunk.u16CExtensionSize = 0;
            }

            stWavChunk.u32HeaderSize = (u32CurrentPosition + stWavChunk.u16CExtensionSize);
            u32CurrentPosition += stWavChunk.u16CExtensionSize;//offset  stWavChunk.u16CExtensionSize

            if((pu8Data[u32CurrentPosition] == 'f') && (pu8Data[u32CurrentPosition+1] == 'a') &&
               (pu8Data[u32CurrentPosition+2] == 'c') && (pu8Data[u32CurrentPosition+3] == 't'))
            {
                stWavChunk.u32HeaderSize += 12;
                u32CurrentPosition += 12;//offset fact chunk
            }

            if((pu8Data[u32CurrentPosition] == 'd') && (pu8Data[u32CurrentPosition+1] == 'a') &&
               (pu8Data[u32CurrentPosition+2] == 't') && (pu8Data[u32CurrentPosition+3] == 'a'))
            {
                stWavChunk.u32HeaderSize += 8;
                u32CurrentPosition += 4;//offset data
                memcpy(&stWavChunk.u32DataChunkSize,pu8Data+u32CurrentPosition,4);
                u32CurrentPosition += 4;//offset u32DataChunkSize
            }

            //end
            WAV_DBG(printf("u32HeaderSize:0x%lx\n",stWavChunk.u32HeaderSize));
            WAV_DBG(printf("u16FormatTag:0x%x\n",stWavChunk.u16FormatTag));
            WAV_DBG(printf("u32DataChunkSize:0x%lx\n",stWavChunk.u32DataChunkSize));
            WAV_DBG(printf("u16BlockSize:0x%x\n",stWavChunk.u16BlockSize));
            WAV_DBG(printf("u16Channels:%u\n",stWavChunk.u16Channels));
            WAV_DBG(printf("u32SamplesPerSec:%lu\n",stWavChunk.u32SamplesPerSec));
            WAV_DBG(printf("u32AvgBytesPerSec:0x%lx\n",stWavChunk.u32AvgBytesPerSec));
            WAV_DBG(printf("u16BitsPerSample:0x%x\n",stWavChunk.u16BitsPerSample));

            stMp3Info.u32MusicDataBytesLeft = stWavChunk.u32DataChunkSize;
            stMp3Info.u16SampleRate = (U16)(stWavChunk.u32SamplesPerSec);
            stMp3Info.u32Duration =  (U16)(stWavChunk.u32DataChunkSize/stWavChunk.u32AvgBytesPerSec);
            stMp3Info.u16BitRate = (U16)((stWavChunk.u32AvgBytesPerSec<<3)/1000);
            WAV_DBG(printf("u32Duration:0x%lx\n",stMp3Info.u32Duration));

            if( (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_PCM) ||
                (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM) ||
                (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_EXTENSIBLE) ||
                (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM) ||
                (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_ALAW) ||
                (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_MULAW))
            {
                bRet = TRUE;
            }
            else
            {
                bRet = FALSE;
            }
        }
        else
        {
            bRet = FALSE;
        }
    }
    else
    {
        bRet = FALSE;
    }
#else
    {
        U32 offset=0;
        U32 tag;
        U32 tagsize;

        MApp_Music_GetRIFFTag(&pu8Data[offset], &tag, &tagsize);
        if (tag==RIFF_TAG_RIFF)
        {
            memcpy(&stWavChunk.u32RIFFChunkSize, &tagsize,4);
            offset+=8;
            MApp_Music_GetRIFFTag(&pu8Data[offset], &tag, &tagsize);
            offset+=4;
            if (tag==RIFF_TAG_WAVE)
            {
                while (1)
                {
                    if ((offset+8) > u32WAVBuffReadLength)
                    {
                        stWavChunk.u16FormatTag=0;
                        break;
                    }
                    MApp_Music_GetRIFFTag(&pu8Data[offset], &tag, &tagsize);
                    if (tag==RIFF_TAG_fmt)
                    {
                        WAV_DBG(printf("wave fmt found\n"));

                        memcpy(&stWavChunk.u32fmtChunkSize,(&pu8Data[offset])+4,4);
                        memcpy(&stWavChunk.u16FormatTag,(&pu8Data[offset])+8,2);
                        memcpy(&stWavChunk.u16Channels,(&pu8Data[offset])+10,2);
                        memcpy(&stWavChunk.u32SamplesPerSec,(&pu8Data[offset])+12,4);
                        memcpy(&stWavChunk.u32AvgBytesPerSec,(&pu8Data[offset])+16,4);
                        memcpy(&stWavChunk.u16BlockSize,(&pu8Data[offset])+20,2);
                        memcpy(&stWavChunk.u16BitsPerSample,(&pu8Data[offset])+22,2);
                    }
                    else if (tag==RIFF_TAG_data)
                    {
                        WAV_DBG(printf("wave data found\n"));
                        memcpy(&stWavChunk.u32DataChunkSize,(&pu8Data[offset])+4,4);
                        stWavChunk.u32HeaderSize = (offset+8);
                        break;
                    }
                    offset+=(tagsize+8);
                }

                WAV_DBG(printf("u32HeaderSize:0x%lx\n",stWavChunk.u32HeaderSize));
                WAV_DBG(printf("u16FormatTag:0x%x\n",stWavChunk.u16FormatTag));
                WAV_DBG(printf("u32DataChunkSize:0x%lx\n",stWavChunk.u32DataChunkSize));
                WAV_DBG(printf("u16BlockSize:0x%x\n",stWavChunk.u16BlockSize));
                WAV_DBG(printf("u16Channels:%u\n",stWavChunk.u16Channels));
                WAV_DBG(printf("u32SamplesPerSec:%lu\n",stWavChunk.u32SamplesPerSec));
                WAV_DBG(printf("u32AvgBytesPerSec:0x%lx\n",stWavChunk.u32AvgBytesPerSec));
                WAV_DBG(printf("u16BitsPerSample:0x%x\n",stWavChunk.u16BitsPerSample));

                stMp3Info.u32MusicDataBytesLeft = stWavChunk.u32DataChunkSize;
                stMp3Info.u16SampleRate = (U16)(stWavChunk.u32SamplesPerSec);
                stMp3Info.u32Duration =  (U16)(stWavChunk.u32DataChunkSize/stWavChunk.u32AvgBytesPerSec);
                stMp3Info.u16BitRate = (U16)((stWavChunk.u32AvgBytesPerSec<<3)/1000);
                WAV_DBG(printf("u32Duration:0x%lx\n",stMp3Info.u32Duration));

                if(stWavChunk.u32SamplesPerSec <= 48*1000 && stWavChunk.u32SamplesPerSec >= 8*1000
                    && stWavChunk.u16BitsPerSample <= 16 )
                {
                    if( (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_PCM) ||
                        (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM) ||
                        (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_EXTENSIBLE) ||
                        (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM) ||
                        (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_ALAW) ||
                        (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_MULAW))
                    {
                        bRet = TRUE;
                        stWavChunk.bIsDTS = FALSE;
                        //check whether it is CD-DTS
                        if(stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_PCM)
                        {
                            U32 u32FrameSize;
                            U32 u32SampleRateIndex = 0;
                            U32 u32BitRateIndex = 0;
                            U32 u32WAVParsedSize;

                            offset = stWavChunk.u32HeaderSize;
                            u32WAVParsedSize = offset;

                            while (u32WAVParsedSize <= MUSIC_WAV_READ_THRESHOLD && u32WAVParsedSize <= u32WAVFileSize)
                            {
                                if (offset >= u32WAVBuffReadLength)
                                {
                                    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), u32WAVBuffReadLength);
                                    offset = 0;
                                }
                                //14bit sync header 0x1FFFE800+0x07F
                                //little endian case
                                if(pu8Data[offset] == 0xFF && pu8Data[offset+1] == 0x1F &&
                                    pu8Data[offset+2] == 0x00 && pu8Data[offset+3] == 0xE8 &&
                                    (pu8Data[offset+4]&0xF0) == 0xF0 && pu8Data[offset+5] == 0x07)
                                {
                                    //get fsize
                                    U16 u16FrameHdr[4];

                                    u16FrameHdr[0] = (U16)(pu8Data[offset+4] | pu8Data[offset+5] << 8) & 0x3FFF;
                                    u16FrameHdr[1] = (U16)(pu8Data[offset+6] | pu8Data[offset+7] << 8) & 0x3FFF;
                                    u16FrameHdr[2] = (U16)(pu8Data[offset+8] | pu8Data[offset+9] << 8) & 0x3FFF;
                                    u16FrameHdr[3] = (U16)(pu8Data[offset+10] | pu8Data[offset+11] << 8) & 0x3FFF;

                                    u32FrameSize = (U32)((u16FrameHdr[1] & 0x3FF) << 4 |(u16FrameHdr[2] & 0x3C00) >> 10) + 1;
                                    u32SampleRateIndex = (U32)(u16FrameHdr[2] & 0xF);
                                    u32BitRateIndex = (U32)((u16FrameHdr[3] & 0x3E00)>> 9);
                                    WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                       u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                    WAV_DBG(printf("find DTS sync header (14bit little endian) and frame size is :0x%lx\n",u32FrameSize));
                                    if(u32SampleRateIndex > 15)
                                    {
                                        WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                        stWavChunk.bIsDTS = FALSE;
                                        break;
                                    }

                                    if(u32BitRateIndex > 31)
                                    {
                                        WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                        stWavChunk.bIsDTS = FALSE;
                                        break;
                                    }
                                    stWavChunk.u16BitsPerSample = 14;
                                    stWavChunk.bDTSIsLittleEndian = TRUE;
                                    stWavChunk.bIsDTS = TRUE;
                                    break;
                                }
                                //14bit sync header 0x1FFFE800+0x07F
                                //big endian case
                                else if(pu8Data[offset] == 0x1F && pu8Data[offset+1] == 0xFF &&
                                           pu8Data[offset+2] == 0xE8 && pu8Data[offset+3] == 0x00 &&
                                           pu8Data[offset+4] == 0x07 && (pu8Data[offset+5]&0xF0) == 0xF0)
                                {
                                    //get fsize
                                    U16 u16FrameHdr[4];

                                    u16FrameHdr[0] = (U16)(pu8Data[offset+4] << 8 | pu8Data[offset+5]) & 0x3FFF;
                                    u16FrameHdr[1] = (U16)(pu8Data[offset+6] << 8 | pu8Data[offset+7]) & 0x3FFF;
                                    u16FrameHdr[2] = (U16)(pu8Data[offset+8] << 8 | pu8Data[offset+9]) & 0x3FFF;
                                    u16FrameHdr[3] = (U16)(pu8Data[offset+10] << 8 | pu8Data[offset+11]) & 0x3FFF;

                                    u32FrameSize = (U32)((u16FrameHdr[1] & 0x3FF) << 4 |(u16FrameHdr[2] & 0x3C00) >> 10) + 1;
                                    u32SampleRateIndex = (U32)(u16FrameHdr[2] & 0xF);
                                    u32BitRateIndex = (U32)((u16FrameHdr[3] & 0x3E00)>> 9);
                                    WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                       u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                    WAV_DBG(printf("find DTS sync header (14bit big endian)and frame size is :0x%lx\n",u32FrameSize));
                                    if(u32SampleRateIndex > 15)
                                    {
                                        WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                        stWavChunk.bIsDTS = FALSE;
                                        break;
                                    }

                                    if(u32BitRateIndex > 31)
                                    {
                                        WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                        stWavChunk.bIsDTS = FALSE;
                                        break;
                                    }
                                    stWavChunk.u16BitsPerSample = 14;
                                    stWavChunk.bDTSIsLittleEndian = FALSE;
                                    stWavChunk.bIsDTS = TRUE;
                                    break;
                                }
                                //16bit sync header 0x7FFE8001+0x3F
                                //little endian case
                                else if(pu8Data[offset] == 0xFE && pu8Data[offset+1] == 0x7F &&
                                        pu8Data[offset+2] == 0x01 && pu8Data[offset+3] == 0x80 && pu8Data[offset+5]>>2 == 0x3F)
                                {
                                     //get fsize
                                     U16 u16FrameHdr[3];

                                     u16FrameHdr[0] = (U16)(pu8Data[offset+4] | pu8Data[offset+5] << 8);
                                     u16FrameHdr[1] = (U16)(pu8Data[offset+6] | pu8Data[offset+7] << 8);
                                     u16FrameHdr[2] = (U16)(pu8Data[offset+8] | pu8Data[offset+9] << 8);

                                     u32FrameSize = (U32)((u16FrameHdr[0] & 3) << 12 |(u16FrameHdr[1] & 0xFFF0) >> 4) + 1;
                                     u32SampleRateIndex = (U32)((u16FrameHdr[2] & 0x3C00)>> 10);
                                     u32BitRateIndex = (U32)((u16FrameHdr[2] & 0x3E0)>> 5);
                                     WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                        u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                     WAV_DBG(printf("find DTS sync header (16bit little endian) and frame size is :0x%lx\n",u32FrameSize));
                                     if(u32SampleRateIndex > 15)
                                     {
                                         WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                         stWavChunk.bIsDTS = FALSE;
                                         break;
                                     }

                                     if(u32BitRateIndex > 31)
                                     {
                                         WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                         stWavChunk.bIsDTS = FALSE;
                                         break;
                                     }
                                     stWavChunk.u16BitsPerSample = 16;
                                     stWavChunk.bDTSIsLittleEndian = TRUE;
                                     stWavChunk.bIsDTS = TRUE;
                                     break;
                                }
                                //16bit sync header 0x7FFE8001+0x3F
                                //big endian case
                                else if(pu8Data[offset] == 0x7F && pu8Data[offset+1] == 0xFE &&
                                        pu8Data[offset+2] == 0x80 && pu8Data[offset+3] == 0x01 && pu8Data[offset+4]>>2 == 0x3F)
                                {
                                     //get fsize
                                     U16 u16FrameHdr[3];

                                     u16FrameHdr[0] = (U16)(pu8Data[offset+4] << 8 | pu8Data[offset+5]);
                                     u16FrameHdr[1] = (U16)(pu8Data[offset+6] << 8 | pu8Data[offset+7]);
                                     u16FrameHdr[2] = (U16)(pu8Data[offset+8] << 8 | pu8Data[offset+9]);

                                     u32FrameSize = (U32)((u16FrameHdr[0] & 3) << 12 |(u16FrameHdr[1] & 0xFFF0) >> 4) + 1;
                                     u32SampleRateIndex = (U32)((u16FrameHdr[2] & 0x3C00)>> 10);
                                     u32BitRateIndex = (U32)((u16FrameHdr[2] & 0x3E0)>> 5);
                                     WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                        u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                     WAV_DBG(printf("find DTS sync header(16bit big endian) and frame size is :0x%lx\n",u32FrameSize));
                                     if(u32SampleRateIndex > 15)
                                     {
                                         WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                         stWavChunk.bIsDTS = FALSE;
                                         break;
                                     }

                                     if(u32BitRateIndex > 31)
                                     {
                                         WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                         stWavChunk.bIsDTS = FALSE;
                                         break;
                                     }
                                     stWavChunk.u16BitsPerSample = 16;
                                     stWavChunk.bDTSIsLittleEndian = FALSE;
                                     stWavChunk.bIsDTS = TRUE;
                                     break;
                                }
                                offset++;
                                u32WAVParsedSize++;
                            }

                            if(stWavChunk.bIsDTS)
                            {
                                stWavChunk.u32SamplesPerSec = DTS_Sample_Rates[u32SampleRateIndex];
                                stWavChunk.u32AvgBytesPerSec = DTS_Bit_Rates[u32BitRateIndex]>>3;
                                stMp3Info.u16SampleRate = (U16)(stWavChunk.u32SamplesPerSec);
                                stMp3Info.u32Duration =  (U16)(stWavChunk.u32DataChunkSize/stWavChunk.u32AvgBytesPerSec);
                                stMp3Info.u16BitRate = (U16)((stWavChunk.u32AvgBytesPerSec<<3)/1000);
                                WAV_DBG(printf("DTS u32SamplesPerSec:%lu\n",stWavChunk.u32SamplesPerSec));
                                WAV_DBG(printf("DTS u32AvgBytesPerSec:0x%lx\n",stWavChunk.u32AvgBytesPerSec));
                                WAV_DBG(printf("DTS u32Duration:0x%lx\n",stMp3Info.u32Duration));
                                WAV_DBG(printf("DTS u16BitsPerSample:0x%x\n",stWavChunk.u16BitsPerSample));
                            }
                        }
                    }
                }
                else
                {
                    WAV_ERR(printf("sample rate is not supported!n"));
                }
            }
        }
    }
#endif

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;

    return bRet;

}

static BOOLEAN _MApp_Music_Wav_DataInput(U32 dwReqAddress, U32 u32ReqBytes)
{
    U32 u32ReadLeft;

    if(stMp3Info.u32MusicDataBytesLeft >= u32ReqBytes)
    {
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32ReqBytes);
        stMp3Info.u32MusicDataBytesLeft -= u32ReqBytes;
    }
    else
    {
        msAPI_Music_CleanFileEndData(dwReqAddress,u32ReqBytes,0x0UL);
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, stMp3Info.u32MusicDataBytesLeft);
        msAPI_Music_FileEndDataHandle((u32ReqBytes-stMp3Info.u32MusicDataBytesLeft)+u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    if(u32ReadLeft>0)
    {
        msAPI_Music_FileEndDataHandle(u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    return TRUE;
}


BOOLEAN MApp_Music_PCM_SetInfo(U16 u16FormatTag, U16 u16Channels, U32 u32SamplesPerSec, U16 u16BitsPerSample, BOOLEAN bBigEndian)
{
    stPCMParam.u16FormatTag = u16FormatTag;
    stPCMParam.u16Channels = u16Channels;
    stPCMParam.u32SamplesPerSec = u32SamplesPerSec;
    stPCMParam.u16BitsPerSample = u16BitsPerSample;
    stPCMParam.bBigEndian = bBigEndian;
    stPCMParam.u32AvgBytesPerSec = u32SamplesPerSec*u16Channels*(u16BitsPerSample/8);
    stPCMParam.u16BlockSize = u16BitsPerSample/8*u16Channels;
    stPCMParam.bIsConfig = TRUE;
    WAV_DBG(printf("pcm parameter: u16FormatTag:%x,channel:%x,samplerate:%x,bitspersample:%x,AvgBytesPerSec:%x,u16BlockSize:%x\n",
        stPCMParam.u16FormatTag,stPCMParam.u16Channels,stPCMParam.u32SamplesPerSec,stPCMParam.u16BitsPerSample,
        stPCMParam.u32AvgBytesPerSec,stPCMParam.u16BlockSize));

    return TRUE;
}

static BOOLEAN _MApp_Music_PCM_CollectInfo(void)
{
    BOOLEAN bRet;

    if(stPCMParam.bIsConfig && stPCMParam.u16BitsPerSample <= 16 &&
                                                  ((stPCMParam.u16FormatTag == (U16)WAVE_FORMAT_PCM) ||
                                                  (stPCMParam.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM) ||
                                                  (stPCMParam.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM)))
    {
        u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);
        stMp3Info.u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        msAPI_DataStreamIO_Close(u32Mp3FileHandle);
        u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;

        stMp3Info.u32MusicDataBytesLeft = stMp3Info.u32FileSize;
        stMp3Info.u16SampleRate = (U16)(stPCMParam.u32SamplesPerSec);
        //For some stream mode (ex. DLNA), maybe not support file length.
        if(msAPI_DataStreamIO_Length(u32Mp3FileHandle) == 0xFFFFFFFF)
        {
            stMp3Info.u32Duration = 0xFFFFFFFF;
        }
        else
        {
            stMp3Info.u32Duration =  (U16)(stMp3Info.u32FileSize/stPCMParam.u32AvgBytesPerSec);
        }
        stMp3Info.u16BitRate = (U16)((stPCMParam.u32AvgBytesPerSec<<3)/1000);
        WAV_DBG(printf("u32Duration:0x%lx\n",stMp3Info.u32Duration));
        bRet = TRUE;
    }
    else
    {
        bRet = FALSE;
    }
    return bRet;
}

static BOOLEAN _MApp_Music_PCM_DataInput(U32 dwReqAddress, U32 u32ReqBytes)
{
    U32 u32ReadLeft;

    if(stMp3Info.u32MusicDataBytesLeft >= u32ReqBytes)
    {
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32ReqBytes);
        stMp3Info.u32MusicDataBytesLeft -= u32ReqBytes;
    }
    else
    {
        msAPI_Music_CleanFileEndData(dwReqAddress,u32ReqBytes,0x0UL);
        u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, stMp3Info.u32MusicDataBytesLeft);
        msAPI_Music_FileEndDataHandle((u32ReqBytes-stMp3Info.u32MusicDataBytesLeft)+u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    if(u32ReadLeft>0)
    {
        msAPI_Music_FileEndDataHandle(u32ReadLeft);
        stMp3Info.u32MusicDataBytesLeft = 0;
    }

    return TRUE;
}
#endif

static void MApp_Music_UpdatePlayTime(void)
{
    U32 u32FilePosition;

    if ((u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
         || ((stMp3Info.enLayer != EN_MP3_LAYER_3)
            && (stMp3Info.enLayer != EN_MP3_LAYER_2)
            && (stMp3Info.enLayer != EN_MP3_LAYER_1)))
    {
        stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();
        stMp3Info.u32CurrentPlayTime = 0;
        return;
    }
    u32FilePosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);

    if ((u32FilePosition == 0) // no data read
        || (u32FilePosition < stMp3Info.u32ID3TagV2Size))
    {
        // reset timer
        stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();
        stMp3Info.u32CurrentPlayTime = 0;
        return;
    }

    if ((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
    {
        // reset timer
        stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();
        return;
    }

    if (stMp3Info.u32CurrentPlayTime == 0)
    {
        // check if first frame read
        if (msAPI_Music_GetCurrentFrameNumber() == 0)
        {
            // reset timer
            stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0() - msAPI_Music_GetPlayTick();
            return;
        }
    }

    stMp3Info.u32CurrentPlayTime += msAPI_Timer_DiffTimeFromNow(stMp3Info.u32PlayTimer);
    stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();

    if (stMp3Info.u32CurrentPlayTime >= ((U32)stMp3Info.u32Duration * 1000))
    {
        // prevent out of range
        stMp3Info.u32CurrentPlayTime = (U32)stMp3Info.u32Duration * 1000;
    }
}

U32 MApp_Music_GetTotalTime(void)
{
#ifdef M4APARSER

    if(enCurrentMusicType == EN_MUSIC_MP3)
    {
#endif
        if (u32Mp3FileHandle == INVALID_DATA_STREAM_HDL && enMusicState > STATE_MUSIC_INIT)
        {
            U32 u32CurrentPlayTime;
            U32 u32PlayTimer;

            // reserve time info
            u32CurrentPlayTime = stMp3Info.u32CurrentPlayTime;
            u32PlayTimer = stMp3Info.u32PlayTimer;

            memset(&stMp3Info, 0, sizeof(stMp3Info));
            stMp3Info.bCheckFfFb = TRUE;

            // restore time info
            stMp3Info.u32CurrentPlayTime = u32CurrentPlayTime;
            stMp3Info.u32PlayTimer = u32PlayTimer;
            if (MApp_Music_CollectInfo(&stMp3Info) == FALSE)
            {
                return 0;
            }
        }

        return stMp3Info.u32Duration;

#ifdef M4APARSER
    }
#if (ENABLE_AAC)
    else if(enCurrentMusicType == EN_MUSIC_AAC)
    {
            return stMp3Info.u32Duration;
        }
#endif
#endif
#if (ENABLE_WAV)
    else if(enCurrentMusicType == EN_MUSIC_WAV)
    {
        return stMp3Info.u32Duration;
    }
    else if(enCurrentMusicType == EN_MUSIC_PCM)
    {
        return stMp3Info.u32Duration;
    }
#endif
    else if(enCurrentMusicType == EN_MUSIC_LOAS)
    {
        return stMp3Info.u32Duration;
    }
#if (ENABLE_OGG)
    else if(enCurrentMusicType == EN_MUSIC_OGG)
    {
        return stMp3Info.u32Duration;
    }
#endif
#if (ENABLE_AMR)
    else if( (enCurrentMusicType == EN_MUSIC_AMR) || (enCurrentMusicType == EN_MUSIC_AWB) )
    {
        return stMp3Info.u32Duration;
    }
#endif
#if (ENABLE_FLAC)
    else if(enCurrentMusicType == EN_MUSIC_FLAC)
    {
        return stMp3Info.u32Duration;
    }
#endif
#if (ENABLE_AC3)
        else if(enCurrentMusicType == EN_MUSIC_AC3)
        {
            return stMp3Info.u32Duration;
        }
#endif


    return 0;
}

U32 MApp_Music_GetCurrentTime(void)
{
    U32 u32CurrentTime=0;

#ifdef M4APARSER
    if (!((enMusicState == STATE_MUSIC_INPUT)
            || (enMusicState == STATE_MUSIC_WAIT_DECODE_DONE)
            || (enMusicState == STATE_MUSIC_WAIT)))
    {
        return 0;
    }

    if(enCurrentMusicType == EN_MUSIC_MP3) //Mp3
    {
#endif

        MApp_Music_UpdatePlayTime();
        u32CurrentTime = MP3_TIMER_FINE_TUNE(stMp3Info.u32CurrentPlayTime);
        u32CurrentTime /= 1000;

        if(u32CurrentTime > stMp3Info.u32Duration)
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }

 #ifdef M4APARSER
    }
#if (ENABLE_AAC)
    else if(enCurrentMusicType == EN_MUSIC_AAC)//aac or m4a
    {
        if(MApp_Music_IsAAC())
        {
            if(u8MusicFFFWMode == MP3_NORMAL_MODE)
            {
                if(enMusicState >= STATE_MUSIC_WAIT)
                {
                    if((u32MaxCurrentTimeTemp/1000)<stMp3Info.u32Duration)
                        return stMp3Info.u32Duration;
                    else
                        return (u32MaxCurrentTimeTemp/1000);
                }
                else
                {
                    u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();

                    if(u32CurrentTime>u32MaxCurrentTimeTemp)
                    {
                        u32MaxCurrentTimeTemp=u32CurrentTime;
                    }
                    u32CurrentTime /= 1000;
                    AAC_ERR2(printf("@M4A Drv u32CurrentTime :%lu\n",u32CurrentTime));
                }
            }
            else
            {
                u32CurrentTime = MP3_TIMER_FINE_TUNE(stMp3Info.u32CurrentPlayTime);
                u32CurrentTime /= 1000;
            }
        }
        else
        {
            if(stM4aInfo.bFoundstsz && stM4aInfo.bFoundstsc && stM4aInfo.u32stscSize >0)
            {
                 //For file-end current time counting!
                if(enMusicState >= STATE_MUSIC_WAIT)
                {
                    u32MaxCurrentTimeTemp += msAPI_Timer_DiffTimeFromNow(u32Mp3ShowTimer);   //add 1 sec until equal to duration
                    u32M4aTimeTemp = u32MaxCurrentTimeTemp;
                    u32CurrentTime = u32M4aTimeTemp;
                    u32CurrentTime /= 1000;

                    if(u32CurrentTime<stM4aInfo.u32Duration)
                    {
                        u32Mp3ShowTimer = msAPI_Timer_GetTime0();
                    }
                }
                else
                {
                    if(bM4aRelocateFilePosition)
                    {
                        stMp3Info.u32CurrentPlayTime =(U32)((U64)_u32StszCurrentFrame*1024* 1000/((U64)stMp3Info.u16SampleRate)) ;   //ADTS: 1024 samples per frame.
                        u32CurrentTime = stMp3Info.u32CurrentPlayTime /1000;
                        u32M4aTimeTemp = stMp3Info.u32CurrentPlayTime;
                        u32MaxCurrentTimeTemp = u32M4aTimeTemp;
                    }
                    else
                    {
                        u32CurrentTime = u32M4aTimeTemp + msAPI_Music_GetPlayTick();
                        if(msAPI_Music_GetPlayTick() != 0)
                        {
                            u32MaxCurrentTimeTemp = u32CurrentTime;
                        }
                        AAC_ERR2(printf("@M4A Drv u32CurrentTime :%lu\n",u32CurrentTime));
                        u32CurrentTime /= 1000;
                    }

                    if(_u32StszCurrentFrame==0 && _u32M4aCurrentFrameIndex==0)
                    {
                        u32CurrentTime=0;
                    }
                }
            }
            else
            {

                if(_bM4aEnableFFFB && !_bM4aTimerbyDSP)
                {
                    //51 reports the playing time
                    if(_u32M4aCurrentFrameIndex == 0  || stM4aInfo.u32Duration ==0 ||_u32FrameArrayIndex < M4A_FRAME_TIME_OFFSET+1)
                    {
                        AAC_ERR2(printf("@M4A _bM4aEnableFFFB TRUE:%lu\n",_bM4aEnableFFFB ));
                        return 0;
                    }

                    if(_u32M4aCurrentFrameIndex > M4A_FRAME_TIME_OFFSET)
                    {
                        u32CurrentTime = stM4aInfo.u32Duration  * (_u32M4aCurrentFrameIndex+1 -M4A_FRAME_TIME_OFFSET) / (_u32FrameArrayIndex-M4A_FRAME_TIME_OFFSET) + M4A_DURATION_MARGIN;
                    }
                    else
                    {
                        u32CurrentTime = 0;
                    }
                }
                else //get timestamp from DSP
                {
                    u32CurrentTime = msAPI_Music_GetPlayTick();
                    AAC_ERR2(printf("@M4A Drv u32CurrentTime :%lu\n",u32CurrentTime ));
                    u32CurrentTime /= 1000;
                }
            }

            if( u32CurrentTime > stM4aInfo.u32Duration && stM4aInfo.u32Duration > 0 )
            {
                u32CurrentTime = stM4aInfo.u32Duration;
            }

            AAC_ERR2(printf("@Time :%lu, F#:%lu, TF:%lu\n",u32CurrentTime,_u32M4aCurrentFrameIndex, _u32FrameArrayIndex));
        }
    }
#endif
#if (ENABLE_WAV)
    else if(enCurrentMusicType == EN_MUSIC_WAV)//aac or m4a
    {
        //for state change to wait, the msAPI_Music_GetPlayTick will return 0
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
    else if(enCurrentMusicType == EN_MUSIC_PCM)//aac or m4a
    {
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
#endif
    else if(enCurrentMusicType == EN_MUSIC_LOAS)//aac or m4a
    {
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
#if (ENABLE_OGG)
    else if(enCurrentMusicType == EN_MUSIC_OGG)//ogg
    {
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
#endif

#if (ENABLE_FLAC)
    else if(enCurrentMusicType == EN_MUSIC_FLAC)//flac
    {
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
#endif

#if (ENABLE_AC3)
    else if(enCurrentMusicType == EN_MUSIC_AC3)//AC3
    {
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
#endif

#if (ENABLE_AMR)
    else if( (enCurrentMusicType == EN_MUSIC_AMR) || (enCurrentMusicType == EN_MUSIC_AWB) ) //amr
    {
        if(enMusicState != STATE_MUSIC_WAIT)
        {
            u32CurrentTime = stMp3Info.u32CurrentPlayTime + msAPI_Music_GetPlayTick();
            u32CurrentTime /= 1000;
        }
        else
        {
            u32CurrentTime = stMp3Info.u32Duration;
        }
    }
#endif
    else
    {
        u32CurrentTime = 0;
    }

    return u32CurrentTime;

#endif
}

U32 MApp_Music_GetCurrentTimeMs(void)
{
    U32 u32CurrentTime;

 #ifdef M4APARSER
    if(enCurrentMusicType == EN_MUSIC_MP3) //Mp3
    {
#endif

    MApp_Music_UpdatePlayTime();
    u32CurrentTime = MP3_TIMER_FINE_TUNE(stMp3Info.u32CurrentPlayTime);
    return (u32CurrentTime < ((U32)stMp3Info.u32Duration * 1000) ? u32CurrentTime : ((U32)stMp3Info.u32Duration * 1000));

 #ifdef M4APARSER
    }
    else  //aac
    {
        //1011 _u32M4aCurrentFrameIndex * 1024

        u32CurrentTime = MApp_Music_GetCurrentTime();
        return u32CurrentTime * 1000;
    }
#endif
}

U32 MApp_Music_GetPlayTick(void)
{
    return msAPI_Music_GetPlayTick();
}

#if 0
void MApp_Music_DrawStatus(void)
{
    g_u16GroupXPos=0;
    g_u16GroupYPos=0;

    switch (enMp3PlayStatus)
    {
        case MP3_STATUS_PLAYING:
            MApp_UiMenu_DrawComponents(DrawA3_MediaPlayer_Music_Play);
            break;

        case MP3_STATUS_PAUSE:
//            if (u8MusicFFFWMode == MP3_NORMAL_MODE)
            {
                MApp_UiMenu_DrawComponents(DrawA3_MediaPlayer_Music_Pause);
            }
            break;
        case MP3_STATUS_SCAN:
            if (u8MusicFFFWMode == MP3_FF_Mode)
            {
                MApp_UiMenu_DrawComponents(DrawA3_MediaPlayer_Music_Ff);
            }
            else if (u8MusicFFFWMode == MP3_FW_Mode)
            {
                MApp_UiMenu_DrawComponents(DrawA3_MediaPlayer_Music_Rew);
            }
            break;

        case MP3_STATUS_STOP:
            MApp_UiMenu_DrawComponents(DrawA3_MediaPlayer_Music_Stop);
            break;
    }
}
#endif

EN_MP3_SPEED MApp_Music_GetFfRewSpeed(void)
{
    if (u8MusicFFFWMode == MP3_NORMAL_MODE)
        return EN_MP3_SPEED_X1;

    return enMp3PlaySpeed;
}

void MApp_Music_ProcessFfRew(void)
{
    U32 u32FilePosition, u32SkipByte;
#if (ENABLE_AAC)
    U32 u32CachedData;
#endif
#if ( (ENABLE_AAC) || (ENABLE_WAV) || (ENABLE_OGG) || (ENABLE_AMR) || (ENABLE_FLAC) || (ENABLE_AC3))
    U32 u32FileLength;
#endif
#if (ENABLE_OGG)
    U32 u32SkipTime;
    U32 u32CurTime; // sec
#endif
    U8 u8FakeKey;
#if (ENABLE_AAC)
    U8 *pFileBufPtr;
    U16 i;
#endif

    if (u8MusicFFFWMode == MP3_NORMAL_MODE)
        return;

    if (u8MusicFFFWMode == MP3_FF_Mode)
    {
        u8FakeKey = KEY_FF;
    }
    else if (u8MusicFFFWMode == MP3_FW_Mode)
    {
        u8FakeKey = KEY_REWIND;
    }
    else
    {
        return;
    }

#ifdef M4APARSER
    if(enCurrentMusicType == EN_MUSIC_MP3) //MP3
    {
 #endif
        u32FilePosition = (((U64)stMp3Info.u32CurrentPlayTime * (U64)(stMp3Info.u16BitRate))>>3) + (U64)stMp3Info.u32ID3TagV2Size;

        if(stMp3Info.u32Duration != 0)
        {
            if((stMp3Info.u8Flag & MP3_FLAG_VBR_XING) && (stMp3Info.u16TOCLength>0))
            {
                U16 u16TOCIdx = stMp3Info.u32CurrentPlayTime / stMp3Info.u32Duration;
                U32 u32SkipPercentage = 0;
re_check:
                if (u8MusicFFFWMode == MP3_FF_Mode)
                {
                    if (u16TOCIdx >= 985) // 98.5 * 10
                    {
                        u16TOCIdx = 1000;
                        u32FilePosition = stMp3Info.u32FileSize;
                        m_bCheckFftoEnd = TRUE;
                    }
                    else
                    {
                        if (u32SkipPercentage == 0)
                        {
                            u16TOCIdx += 15; // 1.5 * 10
                            u32SkipPercentage += 15;
                        }
                        else
                        {
                            u16TOCIdx += 10; // 1.0 * 10
                            u32SkipPercentage += 10;
                        }

                        u32FilePosition = (unsigned long long)(stMp3Info.u32FileSize - stMp3Info.u32ID3TagV2Size) * stMp3Info.u8TOC[u16TOCIdx / 10] / 256 + stMp3Info.u32ID3TagV2Size;
                        if (((u32SkipPercentage * stMp3Info.u32Duration) / 1000) < MP3_FF_FB_THOESHOLD)
                            goto re_check;
                    }
                }
                else
                {
                    if (u16TOCIdx <= 5) // 0.5 * 10
                    {
                        u16TOCIdx = 0;
                        u32FilePosition = 0;
                        u8MusicFFFWMode = MP3_NORMAL_MODE;
                        if(bStop_After_FB_To_Begin)
                        {
                            enMusicState = STATE_MUSIC_WAIT;
                        }
                        else
                        {
                            MApp_Music_Resume();
                        }
                    }
                    else
                    {
                        if (u32SkipPercentage == 0)
                        {
                            u16TOCIdx -= 5; // 0.5 * 10
                            u32SkipPercentage += 10;
                        }
                        else
                        {
                            u16TOCIdx -= 10; // 1.0 * 10
                            u32SkipPercentage += 10;
                        }

                        u32FilePosition = (unsigned long long)(stMp3Info.u32FileSize - stMp3Info.u32ID3TagV2Size) * stMp3Info.u8TOC[u16TOCIdx / 10] / 256 + stMp3Info.u32ID3TagV2Size;
                        if (((u32SkipPercentage * stMp3Info.u32Duration) / 1000) < MP3_FF_FB_THOESHOLD)
                            goto re_check;
                    }
                }

#if 0
                // check point
                if ((u8FakeKey == KEY_FF) && (u32SkipPercentage != 15))
                    printf("vbr, ff, %lu\n", u32SkipPercentage);
                if ((u8FakeKey == KEY_REWIND) && (u32SkipPercentage != 10))
                    printf("vbr, rew, %lu\n", u32SkipPercentage);
#endif

                // re-calculate timer
                if (u16TOCIdx == 0)
                {
                    stMp3Info.u32CurrentPlayTime = 0;
                }
                else
                {
                    stMp3Info.u32CurrentPlayTime = (U32)stMp3Info.u32Duration * ((u16TOCIdx / 10) * 10);
                }

                stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();

            }
            else
            {
                u32SkipByte = stMp3Info.u32FileSize / 100; // jump 1%

                // if skipped byte is less than 2 secs, try to skip at least 2 sec
                // Fix U32 overflow problem
                while ((((U64)u32SkipByte * (U64)stMp3Info.u32Duration)/(U64)stMp3Info.u32FileSize) < MP3_FF_FB_THOESHOLD)
                {
                    u32SkipByte *= 2;
                }

                MUSIC_DBG(printf("b: %u ,k: %lu, p: %lu, l: %lu, t: %u\n", stMp3Info.u16BitRate, u32SkipByte, u32FilePosition, stMp3Info.u32FileSize, MApp_Music_GetCurrentTime()));
                if (u8MusicFFFWMode == MP3_FF_Mode)
                {
                    if (u32FilePosition + u32SkipByte > stMp3Info.u32FileSize)
                    {
                        u32FilePosition = stMp3Info.u32FileSize;
                        m_bCheckFftoEnd = TRUE;
                    }
                    else
                    {
                        u32FilePosition += u32SkipByte;
                    }
                }
                else // FB
                {
                    if (u32FilePosition < u32SkipByte)
                    {
                        u32FilePosition = 0;
                        u8MusicFFFWMode = MP3_NORMAL_MODE;
                        if(bStop_After_FB_To_Begin)
                        {
                            enMusicState = STATE_MUSIC_WAIT;
                        }
                        else
                        {
                            MApp_Music_Resume();
                        }
                    }
                    else
                    {
                        u32FilePosition -= u32SkipByte;
                    }
                }

                // re-calculate timer
                if (u32FilePosition == 0)
                {
                    stMp3Info.u32CurrentPlayTime = 0;
                }
                else
                {
                    U64 u64TempFilePosition = ((U64)u32FilePosition - (U64)stMp3Info.u32ID3TagV2Size)<<3;
                    stMp3Info.u32CurrentPlayTime =  (U32)(u64TempFilePosition / (U64)(stMp3Info.u16BitRate));
                }

                stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();

            }

            msAPI_Music_StopDecode();

    //        if ((enMp3PlayStatus == MP3_STATUS_PAUSE) && (msAPI_MP3_GetResidualBufferSize() != 0))
            if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                && (msAPI_Music_GetResidualBufferSize() != 0))
            {
                // clear audio variables
                msAPI_Timer_Delayms(50);
                msAPI_Music_StartDecode();
                msAPI_Timer_Delayms(50);
                msAPI_Music_StopDecode();
            }

            msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
            msAPI_Timer_Delayms(50); // this delay is critical, can't be too small

            if (enMp3PlayStatus == MP3_STATUS_PLAYING)
            {
                msAPI_Music_StartDecode();
            }
        }

#ifdef M4APARSER
    }
#if (ENABLE_AAC)
    else if(enCurrentMusicType == EN_MUSIC_AAC) //AAC
    {
        //AAC
        if(MApp_Music_IsAAC() && !stM4aInfo.bFoundmdat)
        {
            u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
            u32FilePosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
            u32CachedData = (U32)msAPI_Music_GetResidualBufferSize();

            //FF/FB must minus PCM Buffer Size at first time!!!
            if(u32CachedData!=0)
            {
                u32CachedData += msAPI_Music_GetPCMBufferSize2(stMp3Info.u16BitRate,stMp3Info.u16SampleRate);
            }

            if((u32FilePosition-AACID3Jump) >= u32CachedData)
            {
                u32FilePosition -= u32CachedData;
            }
            else
            {
                u32FilePosition = AACID3Jump;
            }

            MUSIC_DBG(printf("AAC u32FileSize=%lx u32FilePosition=%lx\n",u32FileLength,u32FilePosition));

            stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
            msAPI_Music_StopDecode();

            if (u8FakeKey == KEY_FF)
            {
                u32SkipByte=((u32FileLength-u32FilePosition)/(((U32)stMp3Info.u32Duration) *1000 - stMp3Info.u32CurrentPlayTime))*2000; //Jump 2 seconds

                if (u32FilePosition + u32SkipByte >= u32FileLength)
                {
                    //u32FilePosition = u32FileLength-1;
                    //u8MusicFFFWMode = MP3_NORMAL_MODE;
                    //MApp_Music_Resume();

                    //Go file-end state directly!!
                    m_bCheckFftoEnd = TRUE;
                    return;
                }
                else
                {
                    u32FilePosition += u32SkipByte;
                }
            }
            else // FB
            {
                u32SkipByte=((u32FilePosition-AACID3Jump)/stMp3Info.u32CurrentPlayTime)*2000; //Jump 2 seconds

                if (u32FilePosition - u32SkipByte< AACID3Jump)
                {
                    u32FilePosition = AACID3Jump;//0;
                    u8MusicFFFWMode = MP3_NORMAL_MODE;
                    if(bStop_After_FB_To_Begin)
                    {
                        enMusicState = STATE_MUSIC_WAIT;
                    }
                    else
                    {
                        MApp_Music_Resume();
                    }
                }
                else
                {
                    u32FilePosition -= u32SkipByte;
                }
            }

            //if ((enMp3PlayStatus == MP3_STATUS_PAUSE) && (msAPI_MP3_GetResidualBufferSize() != 0))
            if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                && (msAPI_Music_GetResidualBufferSize() != 0))
            {
                // clear audio variables
                msAPI_Timer_Delayms(50);
                msAPI_Music_StartDecode();
                msAPI_Timer_Delayms(50);
                msAPI_Music_StopDecode();
            }

            msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
            msAPI_Timer_Delayms(50); // this delay is critical, can't be too small

            //AP level AAC header pasing!
            msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), FAT_SECTOR_SIZE_512BYTE * 8); // 4k is xdata window size


            // MP3_INFO_READ_ADR must be 4K alignment
            pFileBufPtr = (U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

            for(i=0;i<2048;i++)
            {
                if( (pFileBufPtr[i] == 0xff) &&
                     ((pFileBufPtr[i+1] & 0xf0) == 0xf0) &&
                     (((pFileBufPtr[i+1]>>1) & 0x03) == 0x00))
                {
                    MUSIC_DBG(printf("%bX %bX %bX %bX %bX %bX %bX \n",pFileBufPtr[i],pFileBufPtr[i+1],pFileBufPtr[i+2],pFileBufPtr[i+3],pFileBufPtr[i+4],pFileBufPtr[i+5],pFileBufPtr[i+6]));
                    break;
                }
            }

            msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition+i);

            //u32FilePosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
            //printf("Frame u32FilePosition=0x%lx\n",u32FilePosition);



            if (u32FilePosition == 0)
            {
                stMp3Info.u32CurrentPlayTime = 0;
            }
            else
            {
                 if (u8FakeKey == KEY_FF)
                 {
                    stMp3Info.u32CurrentPlayTime = stMp3Info.u32CurrentPlayTime + 2000;
                 }
                 else
                 {
                    if(stMp3Info.u32CurrentPlayTime<=2000)
                    {
                        stMp3Info.u32CurrentPlayTime = 0 ;
                        u32FilePosition = 0;
                        msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
                        u8MusicFFFWMode = MP3_NORMAL_MODE;
                        if(bStop_After_FB_To_Begin)
                        {
                            enMusicState = STATE_MUSIC_WAIT;
                        }
                        else
                        {
                            MApp_Music_Resume();
                        }
                    }
                    else
                    {
                        stMp3Info.u32CurrentPlayTime = stMp3Info.u32CurrentPlayTime - 2000;
                    }
                 }
            }
            stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();

            if (enMp3PlayStatus == MP3_STATUS_PLAYING)
            {
                msAPI_Music_StartDecode();
            }
        }
        else   //M4A
        {
            //deal M4A FF/FB by here...
            //AAC_ERR3(printf("@M4a FF/FB...\n"));

            if(_bM4aEnableFFFB)
            {
                if(stM4aInfo.bFoundstsz && stM4aInfo.bFoundstsc && stM4aInfo.u32stscSize>0)
                {
                    bM4aRelocateFilePosition = TRUE;
                    stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
                    msAPI_Music_StopDecode();

                    _u32ADTSWriteLeft=0;
                    memset(_pu8ADTSHeader,0,8);
                    if(u8FakeKey == KEY_FF)
                    {
                        //printf("FF current time:%lu total time:%lu\n",stMp3Info.u32CurrentPlayTime,stMp3Info.u32Duration);

                        stMp3Info.u32CurrentPlayTime+=3000;

                        if((stMp3Info.u32CurrentPlayTime/1000)>stMp3Info.u32Duration)
                        {
                            stMp3Info.u32CurrentPlayTime=stMp3Info.u32Duration;
                            stMp3Info.u32CurrentPlayTime *= 1000;
                            _u32StszCurrentFrame=_u32StszTotalFrame;
                            m_bCheckFftoEnd = TRUE;
                        }
                        else
                        {
                            _u32StszCurrentFrame = (U32)((U64)stMp3Info.u32CurrentPlayTime*(U64)stMp3Info.u16SampleRate/(1000*1024));   //ADTS: 1024 samples per frame.
                        }
                        //printf("StszCurrentFrame:%lu\n",_u32StszCurrentFrame);
                    }
                    else // FB
                    {
                        //printf("FB current time:%lu\n",stMp3Info.u32CurrentPlayTime);

                        if(stMp3Info.u32CurrentPlayTime<2000)
                        {
                            stMp3Info.u32CurrentPlayTime=0;
                            _u32StszCurrentFrame = 0;
                            _u32M4aCurrentFrameIndex = 0;
                            u8MusicFFFWMode = MP3_NORMAL_MODE;
                            if(bStop_After_FB_To_Begin)
                            {
                                enMusicState = STATE_MUSIC_WAIT;
                            }
                            else
                            {
                                MApp_Music_Resume();
                            }
                            return;
                        }
                        else
                        {
                        stMp3Info.u32CurrentPlayTime-=2000;
                        _u32StszCurrentFrame = (U32)((U64)stMp3Info.u32CurrentPlayTime*(U64)stMp3Info.u16SampleRate/(1000*1024));   //ADTS: 1024 samples per frame.
                        }
                        //printf("StszCurrentFrame:%lu\n",_u32StszCurrentFrame);
                    }

                    //sometimes bM4aRelocateFilePosition is set false in M4AParser_WriteDSP before MApp_Music_GetCurrentTime is called.
                    //so it need update u32M4aTimeTemp after FF/FB in time.
                    u32M4aTimeTemp = stMp3Info.u32CurrentPlayTime;

                    if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                        && (msAPI_Music_GetResidualBufferSize() != 0))
                    {
                        // clear audio variables
                        msAPI_Timer_Delayms(50);
                        msAPI_Music_StartDecode();
                        msAPI_Timer_Delayms(50);
                        msAPI_Music_StopDecode();
                    }

                }
                else
                {
                    if(_u32M4aCurrentFrameIndex != 0 || u8MusicFFFWMode == MP3_FF_Mode)    //prevent from queueing key
                    {
                        msAPI_Music_StopDecode();

                        //set index by FF or FB
                        M4AParser_SetFrameIndexbyBtn(u8MusicFFFWMode);

                        // need to work on here?
                        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                            && (msAPI_Music_GetResidualBufferSize() != 0))
        //                if ((enMp3PlayStatus == MP3_STATUS_PAUSE) && (msAPI_MP3_GetResidualBufferSize() != 0))
                        //if ((enMp3PlayStatus == MP3_STATUS_PAUSE)) //aac is another story?
                        {
                            // clear audio variables
                            msAPI_Timer_Delayms(50);
                            msAPI_Music_StartDecode();
                            msAPI_Timer_Delayms(50);
                            msAPI_Music_StopDecode();
                        }

                        msAPI_Timer_Delayms(50);

                        if (enMp3PlayStatus == MP3_STATUS_PLAYING)
                        {
                            msAPI_Music_StartDecode();
                        }

                        _bM4aTimerbyDSP = FALSE;
                    }
                }
            }
        }

        // AAC_ERR3(printf("@M4a End FF/FB...\n"));
    }
#endif
#endif
#if (ENABLE_WAV)
    else if(enCurrentMusicType == EN_MUSIC_WAV) //WAV
    {
        u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        u32FilePosition = (U32)stWavChunk.u32HeaderSize;

        stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
        msAPI_Music_StopDecode();

        //if ((enMp3PlayStatus == MP3_STATUS_PAUSE) && (msAPI_MP3_GetResidualBufferSize() != 0))
        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
            && (msAPI_Music_GetResidualBufferSize() != 0))
        {
            // clear audio variables
            msAPI_Timer_Delayms(50);
            msAPI_Music_StartDecode();
            msAPI_Timer_Delayms(50);
            msAPI_Music_StopDecode();
        }

        if(u8FakeKey == KEY_FF)
        {
            stMp3Info.u32CurrentPlayTime += 2000;
            if((stMp3Info.u32CurrentPlayTime/1000) > stMp3Info.u32Duration)
            {
                stMp3Info.u32CurrentPlayTime = stMp3Info.u32Duration;
                stMp3Info.u32CurrentPlayTime *= 1000;
                stMp3Info.u32MusicDataBytesLeft = 0;
                m_bCheckFftoEnd = TRUE;
            }
            else
            {
                u32FilePosition += ((stMp3Info.u32CurrentPlayTime/1000) * stWavChunk.u32AvgBytesPerSec);
                if(stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM || stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM)
                {
                    u32FilePosition = (u32FilePosition - stWavChunk.u32HeaderSize)/stWavChunk.u16BlockSize*stWavChunk.u16BlockSize + stWavChunk.u32HeaderSize;
                }
                if(u32FilePosition>u32FileLength)
                {
                    u32FilePosition = u32FileLength;
                }
                stMp3Info.u32MusicDataBytesLeft = u32FileLength - u32FilePosition;
                msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
            }
        }
        else // FB
        {
            if(stMp3Info.u32CurrentPlayTime<=2000)
            {
                stMp3Info.u32CurrentPlayTime = 0;
                stMp3Info.u32MusicDataBytesLeft = stWavChunk.u32DataChunkSize;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                if(bStop_After_FB_To_Begin)
                {
                   enMusicState = STATE_MUSIC_WAIT;
                }
                else
                {
                   MApp_Music_Resume();
                }
            }
            else
            {
                stMp3Info.u32CurrentPlayTime -= 2000;
                u32FilePosition += ((stMp3Info.u32CurrentPlayTime/1000) * stWavChunk.u32AvgBytesPerSec);
                if(stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM || stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM)
                {
                    u32FilePosition = (u32FilePosition - stWavChunk.u32HeaderSize)/stWavChunk.u16BlockSize*stWavChunk.u16BlockSize + stWavChunk.u32HeaderSize;
                }
                stMp3Info.u32MusicDataBytesLeft = u32FileLength - u32FilePosition;
                msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
            }
        }
    }
    else if(enCurrentMusicType == EN_MUSIC_PCM) //pcm
    {
        u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        u32FilePosition = 0;

        stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
        msAPI_Music_StopDecode();

        //if ((enMp3PlayStatus == MP3_STATUS_PAUSE) && (msAPI_MP3_GetResidualBufferSize() != 0))
        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
            && (msAPI_Music_GetResidualBufferSize() != 0))
        {
            // clear audio variables
            msAPI_Timer_Delayms(50);
            msAPI_Music_StartDecode();
            msAPI_Timer_Delayms(50);
            msAPI_Music_StopDecode();
        }

        if(u8FakeKey == KEY_FF)
        {
            stMp3Info.u32CurrentPlayTime += 2000;
            if((stMp3Info.u32CurrentPlayTime/1000) > stMp3Info.u32Duration)
            {
                stMp3Info.u32CurrentPlayTime = stMp3Info.u32Duration;
                stMp3Info.u32CurrentPlayTime *= 1000;
                stMp3Info.u32MusicDataBytesLeft = 0;
                m_bCheckFftoEnd = TRUE;
            }
            else
            {
                u32FilePosition += ((stMp3Info.u32CurrentPlayTime/1000) * stPCMParam.u32AvgBytesPerSec);
                if(u32FilePosition>u32FileLength)
                {
                    u32FilePosition = u32FileLength;
                }
                stMp3Info.u32MusicDataBytesLeft = u32FileLength - u32FilePosition;
                msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
            }
        }
        else // FB
        {
            if(stMp3Info.u32CurrentPlayTime<=2000)
            {
                stMp3Info.u32CurrentPlayTime = 0;
                stMp3Info.u32MusicDataBytesLeft = stMp3Info.u32FileSize;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                if(bStop_After_FB_To_Begin)
                {
                   enMusicState = STATE_MUSIC_WAIT;
                }
                else
                {
                   MApp_Music_Resume();
                }
            }
            else
            {
                stMp3Info.u32CurrentPlayTime -= 2000;
                u32FilePosition += ((stMp3Info.u32CurrentPlayTime/1000) * stPCMParam.u32AvgBytesPerSec);
                stMp3Info.u32MusicDataBytesLeft = u32FileLength - u32FilePosition;
                msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
            }
        }
    }
#endif
#if (ENABLE_OGG)
    else if(enCurrentMusicType == EN_MUSIC_OGG) //OGG
    {
        g_OggInfo.bNeedAddHeader = TRUE;
        g_OggInfo.u32VorbisHeaderLeftSizeToWrite = g_OggInfo.u32VorbisHeaderTotalSize;
        g_OggInfo.u32LeftSizeInPage = 0;
        g_OggInfo.bInputFromPacketStart = TRUE;
        g_OggInfo.bSeekToCurrentTime = TRUE;
#if 1
        u32CurTime = MApp_Music_GetCurrentTime();
        u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        u32SkipTime = stMp3Info.u32Duration / 100; // jump 1%
        if (u32SkipTime < MP3_FF_FB_THOESHOLD)
            u32SkipTime  = MP3_FF_FB_THOESHOLD;

        if (u8MusicFFFWMode == MP3_FF_Mode)
        {
            if (u32CurTime+u32SkipTime > stMp3Info.u32Duration)
            {
                u32CurTime = stMp3Info.u32Duration;
                u32FilePosition = u32FileLength;
            }
            else
            {
                u32CurTime += u32SkipTime;
                u32FilePosition = u32CurTime * ((stMp3Info.u16BitRate*1000)>>3);
                if(u32FilePosition>u32FileLength)
                {
                    u32FilePosition = u32FileLength;
                    u32CurTime = stMp3Info.u32Duration;
                }
            }
        }
        else // FB
        {
            if (u32CurTime < u32SkipTime)
            {
                u32CurTime = 0;
                u32FilePosition = g_OggInfo.u32VorbisFirstAudioPageOffset;
            }
            else
            {
                u32CurTime -= u32SkipTime;
                u32FilePosition = u32CurTime * ((stMp3Info.u16BitRate*1000)>>3);
                if(u32FilePosition<g_OggInfo.u32VorbisFirstAudioPageOffset)
                {
                    u32FilePosition = g_OggInfo.u32VorbisFirstAudioPageOffset;
                    stMp3Info.u32CurrentPlayTime = 0;
                }
            }
        }

        MUSIC_DBG(printf("b: %u ,skip t: %lu, p: %lu, l: %lu, t: %u\n", stMp3Info.u16BitRate, u32SkipTime, u32FilePosition, stMp3Info.u32FileSize, u32CurTime));

        if (u32CurTime == stMp3Info.u32Duration)
        {
            m_bCheckFftoEnd = TRUE;
        }
        else if (u32CurTime == 0)
        {
            u8MusicFFFWMode = MP3_NORMAL_MODE;
            if(bStop_After_FB_To_Begin)
            {
                enMusicState = STATE_MUSIC_WAIT;
            }
            else
            {
                g_OggInfo.bInputFromPacketStart = FALSE;
                g_OggInfo.bSeekToCurrentTime = FALSE;
                MApp_Music_Resume();
            }
        }
        //after FF/FB, set new current time
        stMp3Info.u32CurrentPlayTime = u32CurTime*1000;
#else
        u32FilePosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
        u32CachedData = msAPI_Music_GetResidualBufferSize();

        //FF/FB must minus PCM Buffer Size at first time!!!
        if(u32CachedData!=0)
        {
            u32CachedData += msAPI_Music_GetPCMBufferSize2(stMp3Info.u16BitRate,stMp3Info.u16SampleRate);
        }

        if((u32FilePosition-stMp3Info.u32ID3TagV2Size) >= u32CachedData)
        {
            u32FilePosition -= u32CachedData;
        }
        else
        {
            u32FilePosition = stMp3Info.u32ID3TagV2Size;
        }

        u32SkipByte = stMp3Info.u32FileSize / 100; // jump 1%

        // if skipped byte is less than 2 secs, try to skip at least 2 sec
        while (((u32SkipByte * stMp3Info.u32Duration) / stMp3Info.u32FileSize) < MP3_FF_FB_THOESHOLD)
        {
            u32SkipByte *= 2;
        }

        MUSIC_DBG(printf("b: %u ,k: %lu, p: %lu, l: %lu, t: %u\n", stMp3Info.u16BitRate, u32SkipByte, u32FilePosition, stMp3Info.u32FileSize, MApp_Music_GetCurrentTime()));
        if (u8MusicFFFWMode == MP3_FF_Mode)
        {
            if (u32FilePosition + u32SkipByte > stMp3Info.u32FileSize)
            {
                u32FilePosition = stMp3Info.u32FileSize;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                MApp_Music_Resume();
            }
            else
            {
                u32FilePosition += u32SkipByte;
            }
        }
        else // FB
        {
            if (u32FilePosition < u32SkipByte)
            {
                u32FilePosition = 0;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                if(bStop_After_FB_To_Begin)
                {
                    enMusicState = STATE_MUSIC_WAIT;
                }
                else
                {
                    MApp_Music_Resume();
                }
            }
            else
            {
                u32FilePosition -= u32SkipByte;
            }
        }

        // re-calculate timer
        if (u32FilePosition == 0)
        {
            stMp3Info.u32CurrentPlayTime = 0;
        }
        else
        {
            stMp3Info.u32CurrentPlayTime = u32FilePosition / (U32)(stMp3Info.u16BitRate >> 3);
        }
#endif
        msAPI_Music_StopDecode();

        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
            && (msAPI_Music_GetResidualBufferSize() != 0))
        {
            // clear audio variables
            msAPI_Timer_Delayms(50);
            msAPI_Music_StartDecode();
            msAPI_Timer_Delayms(50);
            msAPI_Music_StopDecode();
        }

        msAPI_Stream_Seek(u32Mp3FileHandle, u32FilePosition);
        msAPI_Timer_Delayms(50); // this delay is critical, can't be too small

        if (enMp3PlayStatus == MP3_STATUS_PLAYING)
        {
            msAPI_Music_StartDecode();
        }
    }
#endif

#if (ENABLE_FLAC)
    else if( enCurrentMusicType == EN_MUSIC_FLAC )//FLAC
    {
        u32FileLength = stMp3Info.u32FileSize;

        stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
        msAPI_Music_StopDecode();

        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                && (msAPI_Music_GetResidualBufferSize() != 0))
        {
            // clear audio variables
            msAPI_Timer_Delayms(50);
            msAPI_Music_StartDecode();
            msAPI_Timer_Delayms(50);
            msAPI_Music_StopDecode();
        }

        if(u8FakeKey == KEY_FF)
        {
            stMp3Info.u32CurrentPlayTime += 2000;
            if((stMp3Info.u32CurrentPlayTime/1000) > stMp3Info.u32Duration)
            {
                stMp3Info.u32CurrentPlayTime = stMp3Info.u32Duration;
                stMp3Info.u32CurrentPlayTime *= 1000;
                stMp3Info.u32MusicDataBytesLeft = 0;
                m_bCheckFftoEnd = TRUE;
            }
            else
            {
                if(_MApp_Music_FLACTimeOffset(stMp3Info.u32CurrentPlayTime)==FALSE)
                {
                    _MApp_Music_FLACTimeOffsetNoTable(stMp3Info.u32CurrentPlayTime);

                }
            }
        }
        else // FB
        {
            if(stMp3Info.u32CurrentPlayTime<=2000)
            {
                stMp3Info.u32CurrentPlayTime = 0;
                stMp3Info.u32MusicDataBytesLeft = u32FileLength - m_stFlacInfo.u32DataOffset;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                if(bStop_After_FB_To_Begin)
                {
                    enMusicState = STATE_MUSIC_WAIT;
                }
                else
                {
                    MApp_Music_Resume();
                }
            }
            else
            {
                stMp3Info.u32CurrentPlayTime -= 2000;
                if(_MApp_Music_FLACTimeOffset(stMp3Info.u32CurrentPlayTime)==FALSE)
                {
                    _MApp_Music_FLACTimeOffsetNoTable(stMp3Info.u32CurrentPlayTime);

                }
            }
        }
    }
#endif

#if (ENABLE_AC3)
    else if( enCurrentMusicType == EN_MUSIC_AC3 )//AC3
    {
        u32FileLength = stMp3Info.u32FileSize;

        stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
        msAPI_Music_StopDecode();

        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                && (msAPI_Music_GetResidualBufferSize() != 0))
        {
            // clear audio variables
            msAPI_Timer_Delayms(50);
            msAPI_Music_StartDecode();
            msAPI_Timer_Delayms(50);
            msAPI_Music_StopDecode();
        }

        if(u8FakeKey == KEY_FF)
        {
            stMp3Info.u32CurrentPlayTime += 2000;
            if((stMp3Info.u32CurrentPlayTime/1000) > stMp3Info.u32Duration)
            {
                stMp3Info.u32CurrentPlayTime = stMp3Info.u32Duration;
                stMp3Info.u32CurrentPlayTime *= 1000;
                stMp3Info.u32MusicDataBytesLeft = 0;
                m_bCheckFftoEnd = TRUE;
            }
            else
            {
                _MApp_Music_Ac3TimeOffset(stMp3Info.u32CurrentPlayTime);
            }
        }
        else // FB
        {
            if(stMp3Info.u32CurrentPlayTime<=2000)
            {
                stMp3Info.u32CurrentPlayTime = 0;
                stMp3Info.u32MusicDataBytesLeft = u32FileLength;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                if(bStop_After_FB_To_Begin)
                {
                    enMusicState = STATE_MUSIC_WAIT;
                }
                else
                {
                    MApp_Music_Resume();
                }
            }
            else
            {
                stMp3Info.u32CurrentPlayTime -= 2000;
                _MApp_Music_Ac3TimeOffset(stMp3Info.u32CurrentPlayTime);
            }
        }
    }
#endif


#if (ENABLE_AMR)
    else if( (enCurrentMusicType == EN_MUSIC_AMR) || (enCurrentMusicType == EN_MUSIC_AWB) )//AMR
    {
        //u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        u32FileLength = stMp3Info.u32FileSize;

        stMp3Info.u32CurrentPlayTime += msAPI_Music_GetPlayTick();
        msAPI_Music_StopDecode();

        if (((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
                && (msAPI_Music_GetResidualBufferSize() != 0))
        {
            // clear audio variables
            msAPI_Timer_Delayms(50);
            msAPI_Music_StartDecode();
            msAPI_Timer_Delayms(50);
            msAPI_Music_StopDecode();
        }

        if(u8FakeKey == KEY_FF)
        {
            stMp3Info.u32CurrentPlayTime += 2000;
            if((stMp3Info.u32CurrentPlayTime/1000) > stMp3Info.u32Duration)
            {
                stMp3Info.u32CurrentPlayTime = stMp3Info.u32Duration;
                stMp3Info.u32CurrentPlayTime *= 1000;
                stMp3Info.u32MusicDataBytesLeft = 0;
                m_bCheckFftoEnd = TRUE;
            }
            else
            {
                _MApp_Music_AMRTimeOffset(stMp3Info.u32CurrentPlayTime);
            }
        }
        else // FB
        {
            if(stMp3Info.u32CurrentPlayTime<=2000)
            {
                stMp3Info.u32CurrentPlayTime = 0;
                stMp3Info.u32MusicDataBytesLeft = u32FileLength - m_AMRInfo.u8HeaderSize;
                u8MusicFFFWMode = MP3_NORMAL_MODE;
                if(bStop_After_FB_To_Begin)
                {
                    enMusicState = STATE_MUSIC_WAIT;
                }
                else
                {
                    MApp_Music_Resume();
                }
            }
            else
            {
                stMp3Info.u32CurrentPlayTime -= 2000;
                _MApp_Music_AMRTimeOffset(stMp3Info.u32CurrentPlayTime);
            }
        }
    }
#endif
}

#if 0
BOOLEAN MApp_Music_ProcessKey (void)
{
    BOOLEAN ret = FALSE;

#ifdef M4APARSER
    U8 u8MediaService;
    u8MediaService = MApp_MPlayer_GetServiceType();
#endif

    switch (u8KeyCode)
    {
#ifndef DEMO_
#if 0 // do not support this key now
        case KEY_MENU:
            g_u8MenuPageIndex = MENU_MP3_PLAYER;
            g_u8MenuMainItemIndex = MApp_UiMenu_GetMenuState(g_u8MenuPageIndex);
            MApp_UiMenu2_ShowOSDGWin(GWIN_MAIN_MENU);
            MApp_UiMenu_DrawMenuPage();
            break;
#endif
#endif

        case KEY_EXIT:
            MApp_MP3_StopCapture();
            msAPI_Music_StopDecode();

            u8MusicFFFWMode = MP3_NORMAL_MODE;
            enMusicState = STATE_MUSIC_EXIT;
            ret = TRUE;
//            BtnBff = BTN_NOTHING;
            break;

#ifndef DEMO_
        case KEY_POWER:
            MApp_Music_CloseFile();

            u8MusicFFFWMode = MP3_NORMAL_MODE;
            enMusicState = STATE_MUSIC_INIT;
            enMp3RetVal = EXIT_MP3_TRAN_STANDBY;
//            BtnBff = BTN_NOTHING;
            break;
#endif

        case KEY_VOLUME_MINUS:
        case KEY_VOLUME_PLUS:
            MApp_MEDIA_VolumeMenu();
//            BtnBff = BTN_NOTHING;
            break;

        case KEY_PAUSE:
            if ((enMp3PlayStatus == MP3_STATUS_PLAYING)||(enMp3PlayStatus == MP3_STATUS_SCAN))
            {
                msAPI_Music_PauseDecode();
                enMp3PlayStatus = MP3_STATUS_PAUSE;
                ret = TRUE;
            }
#if (ENABLE_PAUSE_PLAY_TOGGLE)
            else if (enMp3PlayStatus == MP3_STATUS_PAUSE)
            {
                printf(" pause->play\n");
            MApp_UiMenu_DrawComponents(DrawA3_MediaPlayer_Music_Play);

                msAPI_Music_StartDecode();
                if(eMPlayerStatus&MPLAYER_MUSIC_MUTE)
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
                else
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
                enMp3PlayStatus = MP3_STATUS_PLAYING;
                ret = TRUE;
            }
#endif
            u8MusicFFFWMode = MP3_NORMAL_MODE;
//            BtnBff = BTN_NOTHING;
            break;

        case KEY_PLAY:
            if ((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
            {
                msAPI_Music_StartDecode();
                if(eMPlayerStatus&MPLAYER_MUSIC_MUTE)
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
                else
                {
                    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                }
                enMp3PlayStatus = MP3_STATUS_PLAYING;
                ret = TRUE;
            }

            u8MusicFFFWMode = MP3_NORMAL_MODE;
//            BtnBff = BTN_NOTHING;
            break;
#if 0
        case KEY_LEFT:
            BtnBff = BTN_LEFT;
            break;

        case KEY_RIGHT:
            BtnBff = BTN_RIGHT;
            break;

        case KEY_SELECT:
            BtnBff = BTN_SELECT;
            break;
#endif
        case KEY_PREVIOUS:
            u8MusicFFFWMode = MP3_NORMAL_MODE;
            enMusicState = STATE_MUSIC_SKIP_PLAY_PREV;
            ret = TRUE;
            break;

        case KEY_NEXT:
            u8MusicFFFWMode = MP3_NORMAL_MODE;
            enMusicState = STATE_MUSIC_SKIP_PLAY_NEXT;
            ret = TRUE;
            break;

        case KEY_FF:
        case KEY_REWIND:
            if (enMusicState != STATE_MUSIC_INPUT)
                break;

            ret = TRUE;
            if (((u8MusicFFFWMode == MP3_FF_Mode) && (u8KeyCode == KEY_FF))
                    || ((u8MusicFFFWMode == MP3_FW_Mode) && (u8KeyCode == KEY_REWIND)))
            {
                if (enMp3PlaySpeed < EN_MP3_SPEED_MAX)
                {
                    enMp3PlaySpeed++;
                }
                else
                {
                    msAPI_Music_StartDecode();
                    u8MusicFFFWMode = MP3_NORMAL_MODE;
                    enMp3PlaySpeed = EN_MP3_SPEED_X1;
                    enMp3PlayStatus = MP3_STATUS_PLAYING;
                }

                break;
            }

            enMp3PlayStatus = MP3_STATUS_SCAN;
            if (enMp3PlayStatus == MP3_STATUS_PLAYING)
            {
                msAPI_Music_PauseDecode();
            }


            if (u8KeyCode == KEY_FF)
            {
                u8MusicFFFWMode = MP3_FF_Mode;
            }
            else
            {
                u8MusicFFFWMode = MP3_FW_Mode;
            }
            enMp3PlaySpeed = EN_MP3_SPEED_X2;
            break;
#if (ENABLE_MUSIC_PREVIEW)
        case KEY_UP:
        case KEY_DOWN:
#endif
        case KEY_STOP:
            msAPI_Music_StopDecode();
            u8MusicFFFWMode = MP3_NORMAL_MODE;
            enMusicState = STATE_MUSIC_EXIT;
            enMp3PlayStatus = MP3_STATUS_STOP;

            ret = TRUE;
//            BtnBff = BTN_NOTHING;
            // temp solution
            g_u8MenuPageIndex = MENU_MEDIA_PLAYER_LIST;
//            g_u8MenuPageIndex = 0x46;
            MApp_UiMenu_DrawMenuPage();
//            MApp_UiMenu2_ShowOSDGWin(GWIN_MEDIA_PLAYER);
#if (ENABLE_MUSIC_PREVIEW)
            if(u8KeyCode == KEY_DOWN)
            {
                u8FWKey = KEY_DOWN;
            }
            else if(u8KeyCode == KEY_UP)
            {
                u8FWKey = KEY_UP;
            }
#endif
            break;

        default:
//            BtnBff = BTN_NOTHING;
            break;

    }
#ifndef DEMO_
//    MApp_UiMenu_ExecuteKey(BtnBff);
#endif
    MApp_Music_DrawStatus();

    u8KeyCode = KEY_NULL;
    return ret;
}
#endif

// this function is used to check if mp3 is hanging or something else abnormal
// the decoder state state and file position shouldn't stay at same value for a period of time

#define MP3_TIME_OUT_THRESHOLD 3000 // ms
#define MP3_FILE_END_TIME_OUT_THRESHOLD 20000 // ms

static BOOLEAN MApp_Music_TimeOutCheck(void)
{
    U32 u32FilePosition, u32TimeOut = MP3_TIME_OUT_THRESHOLD;
    BOOLEAN bCheck = FALSE;
    static U32 u16PreDspCounter = 0;

    u32FilePosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);

    if ((enTimeoutCheck_Mp3PrevState != enMusicState) || (enMp3PlayStatus == MP3_STATUS_PAUSE) || (enMp3PlayStatus == MP3_STATUS_SCAN))
    {
        // at least state has changed
        u32TimeoutCheck_TimeMarker = msAPI_Timer_GetTime0();
        enTimeoutCheck_Mp3PrevState = enMusicState;
        u32TimeoutCheck_PreFilePosition = -1;
    }
    else
    {
        if (enMusicState != STATE_MUSIC_WAIT) // it's ok to be in idle state and waiting for key event
        {
            if((enMusicState == STATE_MUSIC_WAIT_DECODE_DONE)
            && (msAPI_Music_GetEsMEMCnt() != u16PreDspCounter))
            {
                //when last audio data push to DSP we need wait audio dsp play finish
                //we check DSP counter is continues decrease or not
                u16PreDspCounter = msAPI_Music_GetEsMEMCnt();
                u32TimeoutCheck_TimeMarker = msAPI_Timer_GetTime0();
            }
            else if (u32FilePosition != u32TimeoutCheck_PreFilePosition) // here, check if file position still the same for many times
            {
                u32TimeoutCheck_PreFilePosition = u32FilePosition;

                // if the checking criteria are
                // 1. the decoder stays in one state for a period of time AND
                // 2. no file data read for a period of time
                // the we have to update time marker here by
                u32TimeoutCheck_TimeMarker = msAPI_Timer_GetTime0();
                // otherwise, the criteria will be
                // 1. the decoder stays in one state for a period of time OR
                // 2. no file data read for a period of time
            }
            else
            {
                bCheck = TRUE;
            }
        }
    }

    if (bCheck == TRUE)
    {
        if ((u32FilePosition == msAPI_DataStreamIO_Length(u32Mp3FileHandle))
#ifdef M4APARSER
    #if (ENABLE_AAC)
            ||((enCurrentMusicType == EN_MUSIC_AAC)&&stM4aInfo.bM4aHeader&&(u32Mp3FileBytesLeft==0))
    #else
            &&(u32Mp3FileBytesLeft==0)
    #endif
#endif
            )
        {
            u32TimeOut = MP3_FILE_END_TIME_OUT_THRESHOLD;
        }

        if ((msAPI_Timer_GetTime0() - u32TimeoutCheck_TimeMarker > u32TimeOut) && (msAPI_Music_GetResidualBufferSize() < ES_ALIGNMENT))
        {
            return TRUE;
        }
    }

    return FALSE;
}

#if (ENABLE_POWERON_MUSIC)

static U16 m_u16BinID;

//******************************************************************************
/// Initialize of playback melody from flash.
/// @param  u16BinID \b IN Specify melody bin ID.
/// @return NA
//******************************************************************************
void MApp_Music_StateInit(U16 u16BinID)
{
    enMusicState = STATE_MUSIC_INIT;
    m_u16BinID = u16BinID;
}

BOOLEAN MApp_Music_PowerON_Melody_Decode_OneTime(void)
{
    static BOOLEAN bDataOnFlash;
    static U32 u32FlashStart, u32FlashEnd;
    BININFO BinInfo;
#if((CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)\
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)\
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)\
    )
    U32  u32AudioEsStartAddress = 0;
#else
    U32 u32ReqAddr, u32ReqBytes;
#endif

    bDataOnFlash = FALSE;

#if (ENABLE_MPLAYER_CAPTURE_MUSIC)
    if (stGenSetting.g_SysSetting.UsrPowerOnMusic == POWERON_MUSIC_USER)
    {
        //msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_1);
       //MDrv_SERFLASH_Init();

        u32FlashStart = (U32)USER_MP3_FLASH_START_ADDR;
        u32FlashEnd = (U32)USER_MP3_FLASH_END;

        bDataOnFlash = TRUE;
    }
    else
#endif // #if (ENABLE_MPLAYER_CAPTURE_MUSIC)
    {
        BOOLEAN bResult;

        BinInfo.B_ID = m_u16BinID;
        msAPI_MIU_Get_BinInfo(&BinInfo, &bResult) ;

        if (bResult != PASS)
        {
            MUSIC_DBG(printf("Audio: could not find MP3 file on flash.\n"));
            return FALSE;
        }

        u32FlashStart = BinInfo.B_FAddr;
        u32FlashEnd = BinInfo.B_FAddr + BinInfo.B_Len;
    }

    msAPI_Music_Init(MSAPI_AUD_DVB_MP3, INIT_VOLUME);

//==============================================================
#if((CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)\
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)\
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)) // // Use R2 decoder (MM new mode)
 // Get Audio ES buffer start address
    u32AudioEsStartAddress = MApi_AUDIO_GetCommAudioInfo(Audio_Comm_infoType_Get_UNI_ES_Base);

 // Copy MP3 file to audio ES buffer (file size must < 64KB)
    if (bDataOnFlash)
    {
        msAPI_Flash_Read(u32FlashStart, BinInfo.B_Len, (U8 *)_PA2VA(u32AudioEsStartAddress));
    }
    else
    {
        msAPI_MIU_Copy(u32FlashStart, u32AudioEsStartAddress, BinInfo.B_Len, MIU_FLASH2SDRAM);
    }

  // Play music with MM New mode
    MApi_AUDIO_MM2_initAesInfo(AU_DEC_ID1);
    msAPI_Timer_Delayms(5);
    MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAYMM_FILE2);
    msAPI_Timer_Delayms(5);
    MApi_AUDIO_MM2_inputAesFinished(AU_DEC_ID1, BinInfo.B_Len, 0, 0); //Inform R2 how much ES data is sent

    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_DURING_LIMITED_TIME_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

    return TRUE;
#else // Use DSP decoder (MM old mode)
    MApi_AUDIO_SetMpegInfo(Audio_MPEG_infoType_MMFileSize, FILE_SIZE_64KB, 0);
    msAPI_Music_StartDecode();
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_DURING_LIMITED_TIME_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

    msAPI_Timer_Delayms(30);

    if ((msAPI_Music_CheckInputRequest(&u32ReqAddr, &u32ReqBytes) == TRUE))
    {
        if ( u32FlashStart + u32ReqBytes >= u32FlashEnd )
        {
            msAPI_Music_CleanFileEndData(u32ReqAddr, u32ReqBytes, 0x0UL);
            u32ReqBytes = u32FlashEnd - u32FlashStart;
        }

        if (bDataOnFlash)
        {
            msAPI_Flash_Read(u32FlashStart, u32ReqBytes, (U8 *)_PA2VA(u32ReqAddr));
        }
        else
        {
            msAPI_MIU_Copy(u32FlashStart, u32ReqAddr, u32ReqBytes, MIU_FLASH2SDRAM);
        }

        msAPI_Music_SetInput();
        return TRUE;   //Normal exit path
    }
    else
    {
        return FALSE;    //Check input request fail
    }
#endif
}

BOOLEAN MApp_Music_Decode(void)
{
    static BOOLEAN bDataOnFlash;
    static U32 u32FlashStart, u32FlashEnd;

    U32 u32ReqAddr, u32ReqBytes;
    BININFO BinInfo;

    switch (enMusicState)
    {
        case STATE_MUSIC_INIT:
            bDataOnFlash = FALSE;

#if (ENABLE_MPLAYER_CAPTURE_MUSIC)
            if (stGenSetting.g_SysSetting.UsrPowerOnMusic == POWERON_MUSIC_USER)
            {
                //msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_1);
               //MDrv_SERFLASH_Init();

                u32FlashStart = (U32)USER_MP3_FLASH_START_ADDR;
                u32FlashEnd = (U32)USER_MP3_FLASH_END;

                bDataOnFlash = TRUE;
            }
            else
#endif // #if (ENABLE_MPLAYER_CAPTURE_MUSIC)
            {
                BOOLEAN bResult;

                BinInfo.B_ID = m_u16BinID;
                msAPI_MIU_Get_BinInfo(&BinInfo, &bResult) ;

                if (bResult != PASS)
                {
                    MUSIC_DBG(printf("Audio: could not find MP3 file on flash.\n"));
                    return TRUE;
                }

                u32FlashStart = BinInfo.B_FAddr;
                u32FlashEnd = BinInfo.B_FAddr + BinInfo.B_Len;
            }

            msAPI_Music_Init(MSAPI_AUD_DVB_MP3, INIT_VOLUME);
            msAPI_Music_StartDecode();
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_DURING_LIMITED_TIME_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);

            msAPI_Timer_Delayms(30);

            enMusicState = STATE_MUSIC_INPUT;
            break;

        case STATE_MUSIC_INPUT:
            if ((msAPI_Music_CheckInputRequest(&u32ReqAddr, &u32ReqBytes) == TRUE))
            {
                {
                    int org_size = u32ReqBytes;

                    if ( u32FlashStart + u32ReqBytes >= u32FlashEnd )
                    {
                        msAPI_Music_CleanFileEndData(u32ReqAddr, u32ReqBytes, 0x0UL);
                        u32ReqBytes = u32FlashEnd - u32FlashStart;
                    }

                    if (bDataOnFlash)
                    {
                        msAPI_Flash_Read(u32FlashStart, u32ReqBytes, (U8 *)_PA2VA(u32ReqAddr));
                    }
                    else
                    {
                        msAPI_MIU_Copy(u32FlashStart, u32ReqAddr, u32ReqBytes, MIU_FLASH2SDRAM);
                    }
                    u32ReqBytes = org_size;
                }

                u32FlashStart +=u32ReqBytes;
                msAPI_Music_SetInput();
            }

            if (u32FlashStart >= u32FlashEnd)
            {
                enMusicState = STATE_MUSIC_WAIT_DECODE_DONE;
            }

            if (enMusicState == STATE_MUSIC_WAIT_DECODE_DONE)
            {
#if (ENABLE_MPLAYER_CAPTURE_MUSIC)
                if(stGenSetting.g_SysSetting.UsrPowerOnMusic == POWERON_MUSIC_USER)
                {
                    //msAPI_Flash_ChipSelect(E_FLASH_CHIP_SELECT_0);
                    //MDrv_SERFLASH_Init();
                }
#endif // #if (ENABLE_MPLAYER_CAPTURE_MUSIC)
            }
            break;

        case STATE_MUSIC_WAIT_DECODE_DONE:
            if (msAPI_Music_CheckPlayDone())
            {
                return TRUE;
            }
            break;

        default:
            break;
    }

    return FALSE;
}

void MApp_Music_StopDecode(void)
{
    msAPI_Music_StopDecode();
    enMusicState = STATE_MUSIC_INIT;
}

U32 MApp_Music_GetRecordingTime(void)
{
    if (_u32MusicRecordTotalTime > USER_MP3_CAPTURE_TIMEOUT)
    {
        _u32MusicRecordTotalTime = USER_MP3_CAPTURE_TIMEOUT;
    }

    return _u32MusicRecordTotalTime;
}

#endif

EN_RET MApp_Music_Main(EN_MUSIC_TYPE enMusicType)
{
    static U8 u8LayerDecided;
    EN_MP3_LAYER enLayer;
    E_DATA_STREAM_MODE ePreStreamMode;

    enMp3RetVal = EXIT_MP3_DECODING;

    if (enPreMusicState != enMusicState)
    {
        MUSIC_DBG(printf("mp3s: %u\n", enMusicState));
        enPreMusicState = enMusicState;
    }
    switch(enMusicState)
    {
        case STATE_MUSIC_STANDBY:
            enMp3PlayStatus = MP3_STATUS_STOP;
            enMp3RetVal = EXIT_MP3_TRAN_STANDBY;
            break;
        case STATE_MUSIC_INIT:
            MUSIC_DBG(printf("MP3_INIT\n"););
            enMp3PlayStatus = MP3_STATUS_PLAYING;
//            MApp_Music_DrawStatus();

            enTimeoutCheck_Mp3PrevState = STATE_MUSIC_NONE;
            u32TimeoutCheck_PreFilePosition = -1;
            u32TimeoutCheck_TimeMarker = 0;
#if (ENABLE_AAC)
            u32MaxCurrentTimeTemp=0;
#endif
            enCurrentMusicType = enMusicType;

            _bMusicRecording = FALSE;
            _u32MusicRecordTotalTime = 0;
            ePreStreamMode = msAPI_DataStreamIO_GetStreamMode();
#if (ENABLE_MUSIC_BUFFER_MANAGEMENT)
            msAPI_DataStreamIO_SetStreamMode(E_DATA_STREAM_MODE_BUFFER_MANAGEMENT);
#endif
            if (MApp_Music_Initial() == FALSE)
            {
                msAPI_DataStreamIO_SetStreamMode(ePreStreamMode);
                enMusicState = STATE_MUSIC_EXIT;
                break;
            }
            msAPI_DataStreamIO_SetStreamMode(ePreStreamMode);
#if (ENABLE_LYRICS3)
            MApp_Music_Lyrics3_Parser();
#endif  // #if (ENABLE_LYRICS3)
            enMusicState = STATE_MUSIC_OPEN_FILE;
            u8MusicFFFWMode = MP3_NORMAL_MODE;
            enMp3PlaySpeed = EN_MP3_SPEED_X1;

#ifdef M4APARSER
#if (ENABLE_AAC)
            _u32M4aCurrentFrameIndex = 0;
#endif
#endif
            enMp3RetVal = EXIT_MP3_INIT; //for display MP3 info
            MApi_AUDIO_SPDIF_SetMode(MSAPI_AUD_SPDIF_PCM);
            break;

        case STATE_MUSIC_OPEN_FILE:
            MUSIC_DBG(printf("STATE_MUSIC_OPEN_FILE\n"));
            ePreStreamMode = msAPI_DataStreamIO_GetStreamMode();
#if (ENABLE_MUSIC_BUFFER_MANAGEMENT)
            msAPI_DataStreamIO_SetStreamMode(E_DATA_STREAM_MODE_BUFFER_MANAGEMENT);
#endif
            if (MApp_Music_OpenFile() == FALSE)
            {
                msAPI_DataStreamIO_SetStreamMode(ePreStreamMode);
                enMusicState = STATE_MUSIC_EXIT;
                _enMusic_ErrCode = E_MUSIC_ERR_DATA_OPERATION_FAILURE;
                break;
            }
            msAPI_DataStreamIO_SetStreamMode(ePreStreamMode);
#if MUSIC_INPUT_DUMP
            if(m_u8FileHandleMusicInput!=INVALID_FILE_HANDLE)
            {
                 msAPI_FCtrl_FileClose(m_u8FileHandleMusicInput);
            }
            m_u8FileHandleMusicInput = INVALID_FILE_HANDLE;
            U16 u16MusicFileName[14] = {'d', 'e', 'b', 'u', 'g', 'f', 'i', 'l', 'e', '.', 'm', 'p', '3',0};
            m_u8FileHandleMusicInput = MApp_FileBrowser_OpenNewFileForWrite(u16MusicFileName, 14);
            if(m_u8FileHandleMusicInput==INVALID_FILE_HANDLE)
            {
                printf("open debug file fail\n");
            }
#endif
            msAPI_Music_StartDecode();
            enMusicState = STATE_MUSIC_INPUT;
            u8LayerDecided = 0;
            u32FfRewTimer = msAPI_Timer_GetTime0();
#if 0//(ENABLE_LAST_MEMORY==1)&&ENABLE_LAST_MEMORY_ENABLE_MUSIC
            if ((m_u8LastMemoryCheck==TRUE) && (m_u8LastMemorySearchHit==TRUE))
            {
                U32 u32ResumeTimeMs;
                MApp_MPlayer_LastMemory_GetResumePos(&u32ResumeTimeMs, NULL, NULL);
                MApp_Music_ProcessTimeOffset(u32ResumeTimeMs);
                MUSIC_DBG(printf("MApp_Music_Main, LastMemory, idx=%d, time=%dms\n", m_u32LastMemoryCurIdx, u32ResumeTimeMs););
            }
#endif
            break;

        case STATE_MUSIC_INPUT:
            //MUSIC_DBG(printf("STATE_MUSIC_INPUT\n"));
            if ((msAPI_Timer_DiffTimeFromNow(u32FfRewTimer) > (U32)(900 / (1 << (enMp3PlaySpeed - EN_MP3_SPEED_X2))))
                    && ((u8MusicFFFWMode == MP3_FF_Mode)
                        || (u8MusicFFFWMode == MP3_FW_Mode)))
            {
                MApp_Music_ProcessFfRew();
                u32FfRewTimer = msAPI_Timer_GetTime0();

                if(u8MusicFFFWMode == MP3_FF_Mode && m_bCheckFftoEnd == TRUE)
                {
                    m_bCheckFftoEnd = FALSE;
                    msAPI_Music_StopDecode();
                    enMusicState = STATE_MUSIC_WAIT;
                    u8MusicFFFWMode = MP3_NORMAL_MODE;
                }
            }
            else
            {
                MApp_Music_Input();
            }

            if(enCurrentMusicType == EN_MUSIC_MP3) //MP3
            {
                MApp_Music_UpdatePlayTime();
                // check if the dsp code match file
                //enLayer = msAPI_Music_GetLayer();
            }
            else
            {
                enLayer = EN_MP3_LAYER_NOT_DETERMINE_YET;
            }
#if 0
            switch (enLayer)
            {
                case EN_MP3_LAYER_1:
                case EN_MP3_LAYER_2:
                    if (enCurrentDecSystem == MSAPI_AUD_DVB_MP3) // DSP tells us the file is layer 1/2 but we load layer 3 before
                    {
                        if (u8LayerDecided >= MP3_LAYER_CHECK_COUNT) // we have been told loading wrong code MP3_LAYER_CHECK_COUNT times
                        {
                            if (MApp_Music_LoadDspCodec(MSAPI_AUD_DVB_MPEG) == FALSE)
                            {
                                enMusicState = STATE_MUSIC_SKIP_PLAY_NEXT;
                            }
                            else
                            {
                                enMusicState = STATE_MUSIC_OPEN_FILE;
                            }
                        }
                        else
                        {
                            u8LayerDecided++;
                        }
                    }
                    else
                    {
                        // if we reset u8LayerDecided here, we will reload the DSP code if the DSP tells us the file isn't match the DSP code
                        // MP3_LAYER_CHECK_COUNT times continuously.
                        // if we don't reset u8LayerDecided here, we will reload the DSP code if the DSP tells us the file isn't match the DSP code
                        // MP3_LAYER_CHECK_COUNT times when the whole file is played
                        u8LayerDecided = 0;
                    }
                    break;

                case EN_MP3_LAYER_3:
                    if (enCurrentDecSystem == MSAPI_AUD_DVB_MPEG) // DSP tells us the file is layer 3 but we load layer 1/2 before
                    {
                        if (u8LayerDecided >= MP3_LAYER_CHECK_COUNT) // we have been told loading wrong code MP3_LAYER_CHECK_COUNT times
                        {
                            if (MApp_Music_LoadDspCodec(MSAPI_AUD_DVB_MP3) == FALSE)
                            {
                                enMusicState = STATE_MUSIC_SKIP_PLAY_NEXT;
                            }
                            else
                            {
                                enMusicState = STATE_MUSIC_OPEN_FILE;
                            }
                        }
                        else
                        {
                        // if we reset u8LayerDecided here, we will reload the DSP code if the DSP tells us the file isn't match the DSP code
                        // MP3_LAYER_CHECK_COUNT times continuously.
                        // if we don't reset u8LayerDecided here, we will reload the DSP code if the DSP tells us the file isn't match the DSP code
                        // MP3_LAYER_CHECK_COUNT times when the whole file is played
                            u8LayerDecided++;
                        }
                    }
                    else
                    {
                        u8LayerDecided = 0;
                    }
                    break;

                default:
                    u8LayerDecided = 0;
                    break;

            }
#endif
//            if (MApp_Music_ProcessKey() == TRUE)
//               break;
            break;

        case STATE_MUSIC_WAIT_DECODE_DONE:
            MUSIC_DBG(printf("STATE_MUSIC_WAIT_DECODE_DONE\n");)

            if (MApi_AUDIO_CheckPlayDone())
                {
                    MUSIC_DBG(printf("audio, CheckPlayDone\n"));
                    enMusicState = STATE_MUSIC_WAIT;
                    u32Mp3ShowTimer = msAPI_Timer_GetTime0();
                }

//            if (MApp_Music_ProcessKey() == TRUE)
//                break;
            break;

        case STATE_MUSIC_WAIT:
            MUSIC_DBG(printf("STATE_MUSIC_WAIT\n");)
#if 0
            if(enMp3PlayStatus == MP3_STATUS_PLAYING)
            {
                if(g_u8MP3PlayMode == EN_MP3_PLAY_ALL || g_u8MP3PlayMode == EN_MP3_PLAY_ALL_DISK)
                {
                    MApp_Music_PlayNext();
                }
                enMp3PlayStatus = MP3_STATUS_STOP;
                break;
            }
            if (MApp_Music_ProcessKey() == TRUE)
                break;
#endif
//         if (MApp_Music_ProcessKey() == TRUE)
//             break;
//         else
            {
                //MApp_Music_PlayNext();
                if (enMp3PlayStatus != MP3_STATUS_PAUSE
                &&  msAPI_Timer_DiffTimeFromNow(u32Mp3ShowTimer) > u32Mp3TimeOutDefault)
                {
                    MUSIC_DBG(printf("STATE_MUSIC_WAIT, timeout\n");)
                    MApp_Music_CloseFile();
#if MUSIC_INPUT_DUMP
                    if(m_u8FileHandleMusicInput!=INVALID_FILE_HANDLE)
                    {
                        msAPI_FCtrl_FileClose(m_u8FileHandleMusicInput);
                    }
                    m_u8FileHandleMusicInput = INVALID_FILE_HANDLE;
#endif
                    enMusicState = STATE_MUSIC_STANDBY;
                    enMp3RetVal = EXIT_MP3_WAIT;
                }
            }

            break;

        case STATE_MUSIC_SKIP_PLAY_NEXT:
            msAPI_Music_StopDecode();
            MApp_Music_CloseFile();
            //MApp_Music_DrawStatus();
            enMp3PlayStatus = MP3_STATUS_STOP;

            enMusicState = STATE_MUSIC_INIT;
            enMp3RetVal = EXIT_MP3_WAIT;

            break;

        case STATE_MUSIC_SKIP_PLAY_PREV:
            msAPI_Music_StopDecode();
            MApp_Music_CloseFile();
            //MApp_Music_DrawStatus();
            enMp3PlayStatus = MP3_STATUS_STOP;

            enMusicState = STATE_MUSIC_INIT;
            enMp3RetVal = EXIT_MP3_WAIT_PLAY_PREV;

            break;

        case STATE_MUSIC_EXIT:
            MUSIC_DBG(printf("STATE_MUSIC_EXIT\n");)
            // A patch to fix the problem that key value isn't cleared
            u8KeyCode = KEY_NULL;

            enMp3PlayStatus = MP3_STATUS_STOP;

            enMusicState = STATE_MUSIC_STANDBY;
            enMp3RetVal = EXIT_MP3_EXIT;
            MApp_Music_CloseFile();
            //MApp_Music_DrawStatus();

            break;

        default:
            // A patch to fix the problem that key value isn't cleared
            u8KeyCode = KEY_NULL;

            enMusicState = STATE_MUSIC_STANDBY;
            enMp3RetVal = EXIT_MP3_EXIT;
            //MApp_Music_DrawStatus();
            break;
    }

    if (MApp_Music_TimeOutCheck() == TRUE && enMusicState != STATE_MUSIC_STANDBY)
    {
        msAPI_Music_StopDecode();
        //ported from Kingwok to fix music playback abnormal after played "bad file"
        if(enMusicState == STATE_MUSIC_INIT)
        {
            msAPI_AUD_SW_Reset();
        }
        enMusicState = STATE_MUSIC_EXIT;
        MUSIC_DBG(printf("MP3: Abnormal\n"));
        _enMusic_ErrCode = E_MUSIC_ERR_DECODE_FAILURE;
    }

    return enMp3RetVal;
}

BOOLEAN MApp_Music_Pause(void)
{
    u8MusicFFFWMode = MP3_NORMAL_MODE;

    MUSIC_DBG(printf("MApp_Music_Pause, enMp3PlayStatus=%d\n", enMp3PlayStatus));
    if ((enMp3PlayStatus == MP3_STATUS_PLAYING)||(enMp3PlayStatus == MP3_STATUS_SCAN))
    {
        msAPI_Music_PauseDecode();
        enMp3PlayStatus = MP3_STATUS_PAUSE;
        return TRUE;
//        MApp_Music_DrawStatus();
    }
    return FALSE;
}

void MApp_Music_Resume(void)
{
    MUSIC_DBG(printf("MApp_Music_Resume, enMp3PlayStatus=%d\n", enMp3PlayStatus));
    if ((enMp3PlayStatus == MP3_STATUS_PAUSE)||(enMp3PlayStatus == MP3_STATUS_SCAN))
    {
        msAPI_Music_StartDecode();
        enMp3PlayStatus = MP3_STATUS_PLAYING;
//        MApp_Music_DrawStatus();
        if (msAPI_AUD_IsAudioMutedByUser())
        {
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        }
        else
        {
            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_BYUSER_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
        }
    }
    u8MusicFFFWMode = MP3_NORMAL_MODE;
}

#if (ENABLE_LYRICS3) || (ENABLE_LRC_LYRIC)
void MApp_Music_LyricInit(void)
{
    u16LyricTagCount = 0;
}

BOOLEAN MApp_Music_GetLyricTag(Music_Lyric_Tag *pLyricTag, U32 u32Time)
{
    // Find the lyric which time is less or equal to u32Time.
    Music_Lyric_Tag *pLyricTagBase;
    S16 i;
    BOOLEAN bRet = FALSE;

    pLyricTagBase = (Music_Lyric_Tag *)_PA2VA(MUSIC_LYRIC_TAG_ADR);

    for(i=u16LyricTagCount-1;i>=0;i--)
    {
        if(pLyricTagBase[i].u32Time <= u32Time)
        {
            pLyricTag->u32Time = pLyricTagBase[i].u32Time;
            pLyricTag->u16LyricPos = pLyricTagBase[i].u16LyricPos;
            bRet = TRUE;
            break;
        }
    }

    return bRet;
}
#endif  // #if (ENABLE_LYRICS3) || (ENABLE_LRC_LYRIC)

#if (ENABLE_AAC)
BOOLEAN MApp_Music_IsAAC(void)
{
    if(stM4aInfo.bFoundmdat)
    {  //M4A type
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


U64 DIV64(U64 u64X, U64 u64Y)
{
    if (u64Y)
    {
        return ((u64X) / (u64Y));
    }
    else
    {
        // throw exception or signal or abort?
        printf("[%d]division by zero !\n", __LINE__);
        return 0;
    }
}

U64 MUL64(U64 u64X, U64 u64Y)
{
    return ((u64X) * (u64Y));
}


// slee: function added to get the AAC bitrate, samplerate and duration info
// Since AAC uses VBR in order to get the precise info all file need to be parsed
// but it will require too much time so only first 5 seconds of file is parsed.
// The result is not precise but it is enough.
BOOLEAN M4AParser_Get_AAC_Info(ST_MP3_INFO *pMp3Info)
{
    U8 *pFileBufPtr;
    U16 u16skip_size=0;
    U8 u8Idx=0;
    U16 u16Frame_i=0;
    U16 u16Data_i=0;
    float frames_per_sec = 0;
    U16 u16FrameLength = 0;
    U32 u32TotalFrameLength = 0;
    U32 u32FilePosition = 0;
    U32 u32FileLength = 0;
    BOOLEAN bRet = FALSE;

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        AAC_DBG(printf("Open file failed\n"));
        return FALSE;
    }

    //Eric-PH Lee:20080918 Jump ID3 Tag for AAC
    u32FileLength=msAPI_DataStreamIO_Length(u32Mp3FileHandle);
    u32FileLength-=AACID3Jump;
    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, AACID3Jump, E_DATA_STREAM_SEEK_SET);
    u32FilePosition = AACID3Jump;
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), 0x1000); // 4k is xdata window size

    // MP3_INFO_READ_ADR must be 4K alignment
    pFileBufPtr = (U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));
    if((pFileBufPtr[0] == 'A') && (pFileBufPtr[1] == 'D') && (pFileBufPtr[2] == 'I') && (pFileBufPtr[3] == 'F'))
    {
        MUSIC_DBG(printf("   - ADIF File\n"));
        /* copyright string */
        if(pFileBufPtr[4] & 0x80)
        {
            u16skip_size += 13; /* skip 9 bytes */
        }
        else
        {
            u16skip_size += 4;
        }

        pMp3Info->u16BitRate = ((unsigned int)(pFileBufPtr[0 + u16skip_size] & 0x0F)<<19)|
        ((unsigned int)pFileBufPtr[1 + u16skip_size]<<11)|
        ((unsigned int)pFileBufPtr[2 + u16skip_size]<<3)|
        ((unsigned int)pFileBufPtr[3 + u16skip_size] & 0xE0);

        if( (pFileBufPtr[0 + u16skip_size] & 0x10) )
        {
            u8Idx = ((pFileBufPtr[4 + u16skip_size] & 0x07)<<1)|((pFileBufPtr[5 + u16skip_size] & 0x80)>>7);
        }
        else
        {
            u8Idx = (pFileBufPtr[7 + u16skip_size]&0x78)>>3;
        }

        pMp3Info->u16SampleRate= samplerate_table[u8Idx+1];
        bRet = TRUE;
    }
    else /* No ADIF, check for ADTS header */
    {
        if (( (pFileBufPtr[0] == 0xFF)&&((pFileBufPtr[1] & 0xF6) == 0xF0)) )
        {
            MUSIC_DBG(printf("   - ADTS File\n"));

            U8 u8Profile = 0xFF;

            u8Idx = (pFileBufPtr[2]&0x3C)>>2;

            /* fixed ADTS header is the same for every frame, so we read it only once */
            /* Syncword found, proceed to read in the fixed ADTS header */
            frames_per_sec = samplerate_table[u8Idx+1] / 1024.f;

            u16Data_i = 0;
            /* Read first 215 frames to ensure correct time and bitrate */
            for(u16Frame_i=0; u16Frame_i<215; u16Frame_i++)
            {
                if( !((pFileBufPtr[u16Data_i] == 0xFF) && ((pFileBufPtr[u16Data_i+1] >> 4) == 0x0F)) )
                {
                    MUSIC_DBG(printf("Frame Header Error!\n"));
                    break;
                }
                u8Profile = ((pFileBufPtr[u16Data_i+2] >> 6) & 3);
                u16FrameLength = ((((U16)pFileBufPtr[u16Data_i+3] & 0x3)) << 11) | (((U16)pFileBufPtr[u16Data_i+4]) << 3) | (pFileBufPtr[u16Data_i+5] >> 5);
                AAC_DBG(printf("(%u) position:0x%lX frame_length:0x%x [%BX] [%BX]\n",u16Frame_i,(u16Data_i+u32FilePosition),u16FrameLength,pFileBufPtr[u16Data_i],pFileBufPtr[u16Data_i+1]));
                u32TotalFrameLength += u16FrameLength;

                if((u16Data_i+u16FrameLength)>=(0x1000-0x10))  //0x10: Protect boundary
                {
                    u32FilePosition += (u16Data_i+u16FrameLength);
                    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32FilePosition, E_DATA_STREAM_SEEK_SET);
                    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), 0x1000); // 4k is xdata window size
                    u16Data_i=0;
                }
                else
                {
                    u16Data_i += u16FrameLength;
                }

            }

            if (u16Frame_i > 0)
            {
                pMp3Info->u16SampleRate = (U16)samplerate_table[u8Idx+1];
                // bitrate is calculated only fot the first 215 frames, so it is not precise but near
                pMp3Info->u16BitRate = (U16)(DIV64((MUL64(u32TotalFrameLength, pMp3Info->u16SampleRate) * 8), ((U32)u16Frame_i * 1000 * 1024)));

                /* Since we only use 5 seconds of aac data to get a rough bitrate, we must use a different
                method of calculating the overall length */
                //For some stream mode (ex. DLNA), maybe not support file length.
                if(msAPI_DataStreamIO_Length(u32Mp3FileHandle) == 0xFFFFFFFF)
                {
                    pMp3Info->u32Duration = 0xFFFFFFFF;
                }
                else
                {
                    pMp3Info->u32Duration= (U32)((U32)u32FileLength/(U32)(pMp3Info->u16BitRate*125));//((float)(msAPI_DataStreamIO_Length(u32Mp3FileHandle)/((float)( (pMp3Info->u16BitRate*8*1000)/1024)*16))/**1000*/);
                }
                AAC_DBG(printf("t_framelength:%lu SR:%u BR:%u u16Duration:%u\n",u32TotalFrameLength,pMp3Info->u16SampleRate,pMp3Info->u16BitRate,pMp3Info->u32Duration));
                if(u8Profile != AAC_LC_PROFILE)
                {
                    bRet = FALSE;
                    _enMusic_ErrCode = E_MUSIC_ERR_NOT_SUPPORT_AAC_PROFILE;
                    MUSIC_DBG(printf("It is not aac LC profile , unsupported!\n"));
                }
                else
                {
                    bRet = TRUE;
                }
            }
            else
            {
                bRet = FALSE;
                MUSIC_DBG(printf("Frame id is Zero!\n"));
            }
        }
    }

    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;

    return bRet;
}
#endif

#ifdef M4APARSER
#if (ENABLE_AAC)

BOOLEAN parseM4AChunkHeader(const char* str, U8* pu8Buffer, U32* pu32ChunkSize)
{
    U32 u32ChunkSize = 0;
    U32 u32ChunkName = 0;
    U32 u32ChunkIndex = 0;
    BOOLEAN bRet = FALSE;

    u32ChunkIndex = 0;
    memcpy(&u32ChunkSize, pu8Buffer + u32ChunkIndex, 4);
    u32ChunkSize = Swap32(u32ChunkSize);

    u32ChunkIndex += 4; //skip u32ChunkSize

    memcpy(&u32ChunkName, pu8Buffer + u32ChunkIndex, 4);
    u32ChunkIndex += 4; //skip u32ChunkName

    if((memcmp(&u32ChunkName, str, 4) == 0) || (memcmp("skip", str, 4) == 0))
        {
        bRet = TRUE;
    }

    *pu32ChunkSize = u32ChunkSize;

    return bRet;
}


U8 parseM4A_ReadDescrLength(U8* pu8Buffer, U8* pu8Length)
                {
    U8 u8Data;
    U8 u8ByteCount = 0;

    *pu8Length = 0;
    do
                    {
        u8Data = pu8Buffer[u8ByteCount];
        u8ByteCount++;
        *pu8Length = (*pu8Length << 7) | (u8Data & 0x7F);
                }
    while((u8Data & 0x80) && (u8ByteCount < 4));

    return u8ByteCount;
            }



BOOLEAN M4AParser_Get_M4A_Info(ST_M4A_INFO *pstM4A)
            {
    BOOLEAN bRet = FALSE;
    U32 u32CurrentFilePosition = 0;

    memset(pstM4A, 0, sizeof(ST_M4A_INFO));

    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
                    {
        AAC_DBG(printf("M4A Open file failed\n"));
        return FALSE;
                    }

    U32 u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);

    pstM4A->u32FileSize = u32FileSize;

    U8 *pu8Buffer = (U8 *)_PA2VA(((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)));

    pstM4A->u8object_type = AUDIO_OT_AAC_LC;

    //skip ID3v2
    msAPI_Stream_Seek(u32Mp3FileHandle, 0);
    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), M4A_BUFFER_LEN);
    U32 u32TagSize = msAPI_Music_Parse_ID3v2(u32Mp3FileHandle, ((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), M4A_BUFFER_LEN, &stMp3Info.stID3v2, FALSE);

    if (u32TagSize > 0)
            {
        u32CurrentFilePosition += u32TagSize;
        stMp3Info.bID3TagV2 = TRUE;
            }

    U32 u32TimerLimitaion = msAPI_Timer_GetTime0();
    U32 u32ChunkSize = 0;
    U32 u32NextTrackPosition = 0;
    while(u32CurrentFilePosition < u32FileSize  && (msAPI_Timer_DiffTimeFromNow(u32TimerLimitaion)< M4A_COLLECT_TIME_OUT))
        {
         AAC_DBG(printf("currentFilePosition:0x%x\n",u32CurrentFilePosition));
         msAPI_Stream_Seek(u32Mp3FileHandle, u32CurrentFilePosition);
         msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), M4A_CHUNK_HEADER_SIZE);

         //find ftyp
        if(!pstM4A->bFoundftyp)
            {
            if(parseM4AChunkHeader("ftyp", pu8Buffer, &u32ChunkSize))
            {
                AAC_DBG(printf("Found ftyp\n"));
                pstM4A->bFoundftyp = TRUE;
            }
            else
            {
                break; //Break while
        }

            //Note: different from SuperNova
            msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), 4);
            if(memcpy(pu8Buffer,"qt  ",4)==0)
                    {
                        m_IsQtFormat = TRUE;
                    }
            u32CurrentFilePosition += u32ChunkSize;
                    continue;
                }

        //Parsing "moov"
        if(!pstM4A->bFoundmoov)
            {
            if(parseM4AChunkHeader("moov", pu8Buffer, &u32ChunkSize))
                {
                AAC_DBG(printf("Found moov\n"));
                pstM4A->bFoundmoov = TRUE;
                u32CurrentFilePosition += M4A_CHUNK_ENTRY_OFFSET;  //skip to sub-entry
                continue;
                }
                }


        //Parsing "mvhd"
        if(!pstM4A->bFoundmvhd)
                {
            if(parseM4AChunkHeader("mvhd", pu8Buffer, &u32ChunkSize))
                {
                AAC_DBG(printf("Found mvhd\n"));
                pstM4A->bFoundmvhd = TRUE;

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MVHD_VERSION_TYPE_SIZE);

                if((*pu8Buffer) == 1) //version 1
            {
                    U32 u32TimeScale = 0;
                    U64 u64Duration = 0;

                    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MVHD_DURATION_VERSION1_OFFSET + 8);
                    memcpy(&u32TimeScale, (pu8Buffer + MVHD_TIMESCALE_VERSION1_OFFSET), 4);
                    u32TimeScale = Swap32(u32TimeScale);
                    memcpy(&u64Duration, (pu8Buffer + MVHD_DURATION_VERSION1_OFFSET), 8);
                    u64Duration = Swap64(u64Duration);
                    AAC_DBG(printf("u64Duration: %llu, u32TimeScale: %lu\n", u64Duration, u32TimeScale));

                    if((u64Duration > 0) && (u32TimeScale > 0))
            {
                        pstM4A->u32Duration = (u64Duration + (u32TimeScale / 2)) / u32TimeScale;
                    }

                    u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                    u32ChunkSize -= (M4A_CHUNK_HEADER_SIZE + MVHD_VERSION_TYPE_SIZE + MVHD_DURATION_VERSION1_OFFSET + 8);
                }
                else //version 0
                {
                    U32 u32Duration = 0;
                    U32 u32TimeScale = 0;

                    msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MVHD_DURATION_VERSION0_OFFSET + 4);

                    memcpy(&u32TimeScale, (pu8Buffer + MVHD_TIMESCALE_VERSION0_OFFSET), 4);
                    u32TimeScale = Swap32(u32TimeScale);
                    memcpy(&u32Duration, (pu8Buffer + MVHD_DURATION_VERSION0_OFFSET), 4);
                    u32Duration = Swap32(u32Duration);
                    AAC_DBG(printf("u32Duration: %lu, u32TimeScale: %lu\n", u32Duration, u32TimeScale));

                    if((u32Duration > 0) && (u32TimeScale > 0))
                    {
                        pstM4A->u32Duration = (u32Duration + (u32TimeScale / 2)) / u32TimeScale;
                    }

                    u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                }
                AAC_DBG(printf("@m4a u32Duration: %lu\n", pstM4A->u32Duration));
                continue;
            }
                }

        //Parsing "trak"
        //if(!pstM4A->bFoundtrak)
                    {
            if(parseM4AChunkHeader("trak", pu8Buffer, &u32ChunkSize))
                        {
                AAC_DBG(printf("Found trak\n"));
                pstM4A->bFoundtrak = TRUE;
                pstM4A->bFoundmdia = FALSE;
                u32NextTrackPosition = u32CurrentFilePosition + u32ChunkSize;
                u32CurrentFilePosition += M4A_CHUNK_ENTRY_OFFSET;  //skip to sub-entry
                continue;
                    }
                }

        //Parsing "mdia"
        if(!pstM4A->bFoundmdia)
                {
            if(parseM4AChunkHeader("mdia", pu8Buffer, &u32ChunkSize))
            {
                AAC_DBG(printf("Found mdia\n"));
                pstM4A->bFoundmdia = TRUE;
                u32CurrentFilePosition += M4A_CHUNK_ENTRY_OFFSET;  //skip to sub-entry
                continue;
                }
            }

            //Parsing "mdhd"
        if (!pstM4A->bFoundmdhd)
        {
            if(parseM4AChunkHeader("mdhd", pu8Buffer, &u32ChunkSize))
            {
                U32 u32Duration = 0, u32TimeScale = 0;

                AAC_DBG(printf("Found mdhd\n"));
                pstM4A->bFoundmdhd = TRUE;

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MDHD_DURATION_OFFSET + 4);

                memcpy(&u32TimeScale, (pu8Buffer + MDHD_TIMESCALE_OFFSET), 4);
                u32TimeScale = Swap32(u32TimeScale);
                memcpy(&u32Duration, (pu8Buffer + MDHD_DURATION_OFFSET), 4);
                u32Duration = Swap32(u32Duration);
                AAC_DBG(printf("u32Duration:%d   u32TimeScale:%d\n",u32Duration, u32TimeScale));
                AAC_DBG(printf("m4a mdhd orig u32DurationFromTrack: %lu\n", pstM4A->u32DurationFromTrack));

                if((u32Duration > 0) && (u32TimeScale > 0))
                {
                    pstM4A->u32DurationFromTrack = (u32Duration + (u32TimeScale / 2)) / u32TimeScale;
                }

                AAC_DBG(printf("m4a mdhd u32DurationFromTrack: %lu\n", pstM4A->u32DurationFromTrack));
                u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                continue;
            }
        }


        //Parsing "hdlr_vide"
        if(!pstM4A->bFoundhdlr_vide)
        {
            if(parseM4AChunkHeader("hdlr", pu8Buffer, &u32ChunkSize))
            {
                U32 u32MediaSubtype = 0;

                AAC_DBG(printf("Found hdlr_vide\n"));

                msAPI_Stream_Seek(u32Mp3FileHandle, u32CurrentFilePosition);
                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), u32ChunkSize);

                memcpy(&u32MediaSubtype, (pu8Buffer + HDLR_MEDIA_SUBTYPE + 4), 4);
                printf("@mp4 u32MediaSubtype:%lx\n",u32MediaSubtype);//MSG_DBG
                if(memcmp(&u32MediaSubtype, "vide", 4) == 0)
                {
                    AAC_DBG(printf("It's mp4 with video.\n"));
                    pstM4A->bFoundhdlr_vide = TRUE;
                    pstM4A->bFoundminf = FALSE;
                    pstM4A->bFoundstbl = FALSE;
                    pstM4A->bFoundstsd = FALSE;
                    pstM4A->bFoundesds = FALSE;
                    pstM4A->bFoundstsz = FALSE;
                    pstM4A->bFoundstsc = FALSE;
                    pstM4A->bFoundstco = FALSE;
                    pstM4A->bFoundco64 = FALSE;
                    return FALSE;
                }
                else if(memcmp(&u32MediaSubtype, "soun", 4) == 0)
                {
                    AAC_DBG(printf("It's mp4 audio track.\n"));
                    pstM4A->bFoundminf = FALSE;
                    pstM4A->bFoundstbl = FALSE;
                    pstM4A->bFoundstsd = FALSE;
                    pstM4A->bFoundesds = FALSE;
                    pstM4A->bFoundstsz = FALSE;
                    pstM4A->bFoundstsc = FALSE;
                    pstM4A->bFoundstco = FALSE;
                    pstM4A->bFoundco64 = FALSE;
                    u32CurrentFilePosition += u32ChunkSize;//skip to next-entry

                    if(pstM4A->u32DurationFromTrack)
                    {
                        pstM4A->u32Duration = pstM4A->u32DurationFromTrack;
                        AAC_DBG(printf("m4a hdlr set u32Duration to u32DurationFromTrack : %lu\n", pstM4A->u32DurationFromTrack));
                }

                continue;
            }
                else if(memcmp(&u32MediaSubtype, "alis", 4) == 0)
            {
                    AAC_DBG(printf("It's alis handle.\n"));
                    u32CurrentFilePosition += u32ChunkSize;//skip to next-entry
                    continue;
                }
                else
                {
                    AAC_ERR(printf("u32MediaSubtype:%lx is not video or audio, skip it.\n",u32MediaSubtype));
                    u32CurrentFilePosition = u32NextTrackPosition;//skip to next-track
                    continue;
                }
                }
                }

        //Parsing "udta"
        if(!pstM4A->bFoundudta)
                {
            if(parseM4AChunkHeader("udta", pu8Buffer, &u32ChunkSize))
                {
                AAC_DBG(printf("Found udta\n"));
                pstM4A->bFoundudta = TRUE;
                pstM4A->bFoundmeta_hdlr = TRUE;
                u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                continue;
            }
                }

        //Parsing "minf"
        if(!pstM4A->bFoundminf)
                {
            if(parseM4AChunkHeader("minf", pu8Buffer, &u32ChunkSize))
                    {
                AAC_DBG(printf("Found minf\n"));
                pstM4A->bFoundminf = TRUE;
                u32CurrentFilePosition += M4A_CHUNK_ENTRY_OFFSET;  //skip to sub-entry
                continue;
                    }
                }

        //Parsing "stbl"
        if(!pstM4A->bFoundstbl)
                {
            if(parseM4AChunkHeader("stbl", pu8Buffer, &u32ChunkSize))
                {
                AAC_DBG(printf("Found stbl\n"));
                pstM4A->bFoundstbl = TRUE;
                u32CurrentFilePosition += M4A_CHUNK_ENTRY_OFFSET;  //skip to sub-entry
                continue;
                }
            }

        //Parsing "stsd"
        if(!pstM4A->bFoundstsd)
                {
            //Note: different from SuperNova
            if(parseM4AChunkHeader("stsd", pu8Buffer, &u32ChunkSize))
            {
                U16 u16Temp;
                U32 u32DataFormatName;

                AAC_DBG(printf("Found stsd\n"));
                pstM4A->bFoundstsd = TRUE;

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), M4A_PARSER_BUFFER_SIZE);

                memcpy(&u32DataFormatName, pu8Buffer + STSD_DATAFORMAT_OFFSET, 4);
                if(memcmp(&u32DataFormatName, ".mp3", 4) == 0)
                {
                    AAC_DBG(printf("data format is mp3.\n"));
                    pstM4A->enCodec = EN_MUSIC_MP3;
                }
                else if(memcmp(&u32DataFormatName, "mp4a", 4) == 0)
                {
                    AAC_DBG(printf("data format is mp4a.\n"));
                    pstM4A->enCodec = EN_MUSIC_AAC;
                }
                else if(memcmp(&u32DataFormatName, "ec-3", 4) == 0)
            {
                    AAC_DBG(printf("data format is ec-3.\n"));
                    pstM4A->enCodec = EN_MUSIC_AC3;
                }
                else if(memcmp(&u32DataFormatName, "ac-3", 4) == 0)
                {
                    AAC_DBG(printf("data format is ac-3.\n"));
                    pstM4A->enCodec = EN_MUSIC_AC3;
                }
                else
                {
                    AAC_DBG(printf("data format is not m4a or mp3, no supported.\n"));
                    return FALSE;
                }
                memcpy(&u16Temp, (pu8Buffer + STSD_SAMPLERATE_OFFSET), 2);
                u16Temp = Swap16(u16Temp);
                pstM4A->u32StsdSampleRate = u16Temp;
                AAC_DBG(printf("@m4a u32StsdSampleRate: %lu\n", pstM4A->u32StsdSampleRate));

                if(!pstM4A->bFoundesds)
            {
                    U32 u32Sub_I_ChunkIndex = ESDS_ENTRY_OFFSET;
                    U32 u32Sub_I_ChunkSize = 0;
                    BOOLEAN bPass = TRUE;

                    if(parseM4AChunkHeader("esds", pu8Buffer + u32Sub_I_ChunkIndex, &u32Sub_I_ChunkSize))
            {
                U8 tag, length = 0;
                        U8 *esdsBufferBase = pu8Buffer + u32Sub_I_ChunkIndex;

                        AAC_DBG(printf("Found esds\n"));
                        pstM4A->bFoundesds = TRUE;

                        esdsBufferBase += 12;    //size + esds + version + flag
                tag = *esdsBufferBase;
                esdsBufferBase ++;
                if (tag == 0x03)
                {
                    /* read length */
                            //esdsBufferBase += M4AParser_ReadDescrLength(esdsBufferBase, &length);
                            esdsBufferBase += parseM4A_ReadDescrLength(esdsBufferBase, &length);
                            if(length < (5 + 15))
                    {
                        AAC_ERR(printf("[esds] ERROR 1, length(%u)\n", length));
                                bPass = FALSE;
                    }
                    /* skip 3 bytes */
                    esdsBufferBase += 3;
                }
                else
                {
                    /* skip 2 bytes */
                    esdsBufferBase += 2;
                }
                /* get and verify DecoderConfigDescrTab */
                if(*esdsBufferBase != 0x04)
                {
                    AAC_ERR(printf("[esds] ERROR 2\n"));
                            bPass = FALSE;
                }
                esdsBufferBase ++;
                /* read length */
                        //esdsBufferBase += M4AParser_ReadDescrLength(esdsBufferBase, &length);
                        esdsBufferBase += parseM4A_ReadDescrLength(esdsBufferBase, &length);
                if (length < 13)
                {
                    AAC_ERR(printf("[esds] ERROR 3, length(%u)\n", length));
                            bPass = FALSE;
                }
                /* audioType: 1 byte */
                esdsBufferBase += 1;
                /* skip 4 bytes */
                esdsBufferBase += 4;
                /* maxBitrate: 4 byte, avgBitrate: 4 byte */
                esdsBufferBase += 8;
                /* get and verify DecSpecificInfoTag */
                if (*esdsBufferBase != 0x05)
                {
                    AAC_ERR(printf("[esds] ERROR 4, byte(%u)\n", *esdsBufferBase));
                            bPass = FALSE;
                }

                        if(bPass)
                        {
                            esdsBufferBase ++;
                            esdsBufferBase += parseM4A_ReadDescrLength(esdsBufferBase, &length);
                            pstM4A->u8object_type = ((U32)esdsBufferBase[0]) >> 3;//5 bits: object type
                            if(pstM4A->u8object_type != AUDIO_OT_AAC_LC)
                {
                                AAC_ERR(printf("[esds] object type is :%d, not supported, we only support LC profile\n", pstM4A->u8object_type));
                }
                else
                {
                                AAC_DBG(printf("[esds] object type is :%d, LC profile.\n", pstM4A->u8object_type));
                }
                            pstM4A->u8SampleRateIndex = ((((U32)esdsBufferBase[0] & 0x07) << 1) | (((U32)esdsBufferBase[1] & 0x80) >> 7));

                            if(pstM4A->u8SampleRateIndex == 0xf)
                {
                                pstM4A->u8channelConfiguration = (((U32)esdsBufferBase[4] & 0x78) >> 3);
                }
                            else
                {
                                pstM4A->u8SampleRateIndex++;
                                pstM4A->u8channelConfiguration = (((U32)esdsBufferBase[1] & 0x78) >> 3);
                }

                            if(pstM4A->u8channelConfiguration >= 8)
                    {
                                pstM4A->u8channelConfiguration = 2;
                                AAC_ERR(printf("Channel configuration ERROR!\n"));
                            }
                        }

                        }
                    }

                u32CurrentFilePosition += u32ChunkSize; //skip to next-entry
                continue;
                }
            }

        //Parsing "stsz"
        if(!pstM4A->bFoundstsz)
        {
            if(parseM4AChunkHeader("stsz", pu8Buffer, &u32ChunkSize))
            {
                AAC_DBG(printf("Found stsz\n"));
                pstM4A->bFoundstsz = TRUE;

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), STSZ_ENTRY_OFFSET + 4);
                memcpy(&pstM4A->u32stszSize, (pu8Buffer + STSZ_ENTRY_OFFSET), 4);
                pstM4A->u32stszSize = Swap32(pstM4A->u32stszSize) * STSZ_ENTRY_SIZE;
                pstM4A->u32stszLocation = (u32CurrentFilePosition + M4A_CHUNK_ENTRY_OFFSET + STSZ_FRAME_LOCATION_OFFSET);

                AAC_DBG(printf("@M4a stsz addr:0x%lx, length:0x%lx\n", pstM4A->u32stszLocation, pstM4A->u32stszSize));

                u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                continue;
        }
        }


        //Parsing "stsc"
        if(!pstM4A->bFoundstsc)
        {
            //Note: different from SuperNova
            if(parseM4AChunkHeader("stsc", pu8Buffer, &u32ChunkSize))
        {
                AAC_DBG(printf("Found stsc\n"));
                pstM4A->bFoundstsc = TRUE;
                pstM4A->u32stscLocation = (u32CurrentFilePosition + M4A_CHUNK_ENTRY_OFFSET + STSC_ENTRY_OFFSET);

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), STSC_ENTRY_OFFSET + 4);

                memcpy(&pstM4A->u32stscSize, (pu8Buffer + STSC_ENTRY_OFFSET), 4);
                pstM4A->u32stscSize = Swap32(pstM4A->u32stscSize);
                AAC_DBG(printf("@M4a stsc length:0x%lx u32stscLocation:0x%lx\n", pstM4A->u32stscSize, pstM4A->u32stscLocation));
                u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                continue;
    }
}


        //Parsing "stco"
        if(!pstM4A->bFoundstco)
        {
            //Note: different from SuperNova
            if(parseM4AChunkHeader("stco", pu8Buffer, &u32ChunkSize))
{
                AAC_DBG(printf("Found stco\n"));
                pstM4A->bFoundstco = TRUE;

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), STSC_ENTRY_OFFSET + 4);

                memcpy(&pstM4A->u32stcoEntry, (pu8Buffer + STCO_ENTRY_OFFSET), 4);
                pstM4A->u32stcoEntry = Swap32(pstM4A->u32stcoEntry);
                AAC_DBG(printf("@M4a u32stcoEntry Number: 0x%lx\n", pstM4A->u32stcoEntry));

                pstM4A->u32stcoFrameLocation = (u32CurrentFilePosition + M4A_CHUNK_ENTRY_OFFSET + STCO_FRAME_LOCATION_OFFSET);
                AAC_DBG(printf("u32stcoEntry Location: 0x%lx\n", pstM4A->u32stcoFrameLocation));

                u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry

                continue;
    }
}


        //Parsing "co64"
        if(!pstM4A->bFoundco64)
{
            if(parseM4AChunkHeader("co64", pu8Buffer, &u32ChunkSize))
    {
                AAC_DBG(printf("Found co64\n"));
                pstM4A->bFoundco64 = TRUE;

                msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), CO64_ENTRY_OFFSET + 4);

                memcpy(&pstM4A->u32co64Entry, (pu8Buffer + CO64_ENTRY_OFFSET), 4);
                pstM4A->u32co64Entry = Swap32(pstM4A->u32co64Entry);
                AAC_DBG(printf("@M4a u32co64Entry Number: 0x%lx\n", pstM4A->u32co64Entry));

                pstM4A->u32co64FrameLocation = (u32CurrentFilePosition + M4A_CHUNK_ENTRY_OFFSET + CO64_FRAME_LOCATION_OFFSET);
                AAC_DBG(printf("u32co64Entry Location: 0x%lx\n", pstM4A->u32co64FrameLocation));

                u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                continue;
}
}



        //Parsing "mdat",  first tag!
        if(!pstM4A->bFoundmdat)
{
            if(parseM4AChunkHeader("mdat", pu8Buffer, &u32ChunkSize))
    {
                AAC_DBG(printf("Found mdat\n"));

                if((u32ChunkSize - 8) > 0)
    {
                    pstM4A->bFoundmdat = TRUE;
                    pstM4A->u32MdatLocation = (u32CurrentFilePosition + MDAT_LOCATION_OFFEST);
                    AAC_DBG(printf("@M4a mdat location:0x%lx\n", pstM4A->u32MdatLocation));

                    pstM4A->u32MdatSize = (u32ChunkSize - M4A_CHUNK_ENTRY_OFFSET);
                    AAC_DBG(printf("@M4a mdat size: 0x%lx\n", pstM4A->u32MdatSize));
    }
                else
    {
                    AAC_DBG(printf("@M4a  mdat size is too small, try to find another valid mdat.\n"));
    }

                u32CurrentFilePosition += u32ChunkSize;
                continue;
    }
    }


        if(pstM4A->bFoundmdat &&
                        pstM4A->bFoundstsd &&
                        pstM4A->bFoundesds &&
                        pstM4A->bFoundstsc &&
                        pstM4A->bFoundstsz &&
                        (pstM4A->bFoundstco || pstM4A->bFoundco64))
    {
            bRet = TRUE;
            break;
    }

        //No useful tag found, skip it!
        if(parseM4AChunkHeader("skip", pu8Buffer, &u32ChunkSize)) //Use the "skip" to skip tag
    {
            u32CurrentFilePosition += u32ChunkSize;
            continue;
    }
    }//while end

    MApp_Music_CloseFile();

    AAC_DBG(printf("M4A parsing done.\n"));

    if(pstM4A->bFoundmdat && pstM4A->bFoundstsd && (pstM4A->u32MdatSize > 0) && (pstM4A->u32StsdSampleRate > 0))
    {
        if(!pstM4A->u8SampleRateIndex)
    {
            U8 k;
            pstM4A->u8SampleRateIndex = 255;
            for(k = 0; k < 15; k++)
    {
                if(pstM4A->u32StsdSampleRate == M4ASamplerateTable[k])
    {
                    pstM4A->u8SampleRateIndex = k;
    }
    }
    }
        else
    {
            pstM4A->u32StsdSampleRate = M4ASamplerateTable[pstM4A->u8SampleRateIndex];
}
        AAC_DBG(printf("[M4A] SR Index: %u\n", pstM4A->u8SampleRateIndex));

        //Update information
        pstM4A->bM4aHeader = TRUE;
        stMp3Info.u16SampleRate = (U16) pstM4A->u32StsdSampleRate;
        stMp3Info.u32Duration = pstM4A->u32Duration;

        if(pstM4A->u32Duration == 0)
    {
           goto  IoError;
        }

        stMp3Info.u16BitRate = (U16)(((u32FileSize * 8) / pstM4A->u32Duration) / 1000);

        AAC_DBG(printf("\nTitle: %s", stMp3Info.stID3v2.title+1));
        AAC_DBG(printf("\nArtist: %s", stMp3Info.stID3v2.artist+1));
        AAC_DBG(printf("\nAlbum: %s", stMp3Info.stID3v2.album+1));
        AAC_DBG(printf("\nyear: %s", stMp3Info.stID3v2.year+1));
        AAC_DBG(printf("\nComment: %s", stMp3Info.stID3v2.comment+1));

        bRet =  TRUE;
    }

IoError:
    return bRet;
}
#endif

//mapp_videoplayer.c will call this function
U8 M4AParser_GetSampleRateIndex(U32 dwValue)
{
    U8 i;

    AAC_DBG(printf("@M4AParser_GetSampleRateIndex In \n"));
    for (i=0;i< 15;i++)
    {
        if (samplerate_table[i] == dwValue)
        {
            return i;
        }
    }

    return 255;
}

#if (ENABLE_AAC)
BOOLEAN M4AParser_WriteDSPNoHead(U32 dwReqAddress, U32 u32ReqBytes)
{
    static U32 dwMdatRemain;// = boxM4a.dwmdatSize;
    U32 u32readLeft =0;
    U32 u32FilePosition,u32FileLength;

    AAC_ERR2(printf("@M4A no head to dsp\n"));

    u32FilePosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
    u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);

    //init when every m4a is opened
    if (_bM4aJustOpened)
    {
        // use dwMdatRemain to save FileSize remaining
        dwMdatRemain = (u32FileLength-AACID3Jump);
        AAC_ERR2(printf("@M4A nohead size:%lu\n",dwMdatRemain));
        _bM4aJustOpened = FALSE;
    }

    //Maintain dwMdatRemain
    if(u32FilePosition==0 ||u32FilePosition<AACID3Jump)
    {
        dwMdatRemain = (u32FileLength-AACID3Jump);
    }
    else if(u32FileLength-u32FilePosition!=dwMdatRemain)
    {
        dwMdatRemain=u32FileLength-u32FilePosition;
    }

    if (dwMdatRemain >=  u32ReqBytes)
    {
        u32readLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32ReqBytes);

        if (u32readLeft!=0)
        {
            AAC_ERR(printf("@M4a fileread not read3:%lu\n",u32readLeft));
            msAPI_Music_FileEndDataHandle(u32readLeft);
            dwMdatRemain =0;
        }
        else
        {
            dwMdatRemain -= u32ReqBytes;
        }
    }
    else if (dwMdatRemain > 0)
    {//do the final round
        u32readLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, dwMdatRemain);

        if (u32readLeft!=0)
        {
            AAC_ERR(printf("@M4a fileread not read4:%lu\n",u32readLeft));
            msAPI_Music_FileEndDataHandle((u32ReqBytes-dwMdatRemain+u32readLeft));
        }
        else
        {
            //inform DSP it's the last time and the padding number...
            msAPI_Music_FileEndDataHandle((u32ReqBytes-dwMdatRemain));
        }

        dwMdatRemain =0;
    }

    //inform mp3 state
    u32Mp3FileBytesLeft = dwMdatRemain;

    return TRUE;
}

static U32 M4AParser_ReCalculateChunkIndex(U32 u32StszCurrentIndex,U32 *pu32SampleIndex)
{
    U32 u32ChunkIndex = 0;

    *pu32SampleIndex = u32StszCurrentIndex;
    stM4aInfo.stscInfo.u32CurrentEntry=0;    //current Entry may be larger than 255, use U32 instead

    //boxM4a.stscInfo.pu32EntryInfo[0]:first_chunk      [1]:samples_per_chunk   [2]:Total samples

    while((u32StszCurrentIndex>0) && (u32StszCurrentIndex >= stM4aInfo.stscInfo.pu32EntryInfo[(stM4aInfo.stscInfo.u32CurrentEntry) * STSC_INFO_ENTRY_INFO_COUNT +2]))   //boxM4a.stscInfo.pu32EntryInfo[(boxM4a.stscInfo.u32CurrentEntry)][2]
    {
        stM4aInfo.stscInfo.u32CurrentEntry++;

    }

    stM4aInfo.u32stscSize = stM4aInfo.stscInfo.pu32EntryInfo[stM4aInfo.stscInfo.u32CurrentEntry * STSC_INFO_ENTRY_INFO_COUNT + 1];   //boxM4a.stscInfo.pu32EntryInfo[(boxM4a.stscInfo.u32CurrentEntry)][1]

    if(stM4aInfo.stscInfo.u32CurrentEntry>0)
    {
        *pu32SampleIndex -=  stM4aInfo.stscInfo.pu32EntryInfo[(stM4aInfo.stscInfo.u32CurrentEntry-1)* STSC_INFO_ENTRY_INFO_COUNT+2];  //boxM4a.stscInfo.pu32EntryInfo[(boxM4a.stscInfo.u32CurrentEntry)-1][2]
    }

    u32ChunkIndex = (stM4aInfo.stscInfo.pu32EntryInfo[stM4aInfo.stscInfo.u32CurrentEntry * STSC_INFO_ENTRY_INFO_COUNT]-1) + *pu32SampleIndex/stM4aInfo.u32stscSize;   //boxM4a.stscInfo.pu32EntryInfo[(boxM4a.stscInfo.u32CurrentEntry)][0] - 1
    *pu32SampleIndex = *pu32SampleIndex%stM4aInfo.u32stscSize;

    if(*pu32SampleIndex>0)
    {
        u32ChunkIndex++;
    }
    AAC_ERR2(printf("u32StszCurrentIndex:%lu u32ChunkIndex:%lu *pu32SampleIndex:%lu\n",u32StszCurrentIndex,u32ChunkIndex,*pu32SampleIndex));

    return u32ChunkIndex;
}

static U32 M4AParser_AddADTSHeaderForDSP(U32 dwReqAddress,U32 u32ReqBytes)
{
    U32 u32CurrentFrameSize = 0;
    U32 u32readLeft = 0;
    U32 u32WriteSize = 0;
    U8 u8HeaderLeftSize = 0;
    U32 u32SampleIndex = 0;

    while(u32ReqBytes>0)
    {
        u8HeaderLeftSize = _pu8ADTSHeader[7];
        if(u8HeaderLeftSize > 0)
        {
            //msAPI_MIU_Copy((U32)(&_pu8ADTSHeader[MP4_PARSER_ADTS_HEADER_SIZE-u8HeaderLeftSize]), dwReqAddress, u8HeaderLeftSize, MIU_SDRAM2SDRAM);
            memcpy((U8 *)_PA2VA(dwReqAddress), &_pu8ADTSHeader[MP4_PARSER_ADTS_HEADER_SIZE-u8HeaderLeftSize], u8HeaderLeftSize);

            dwReqAddress += u8HeaderLeftSize;
            u32ReqBytes -= u8HeaderLeftSize;
            _pu8ADTSHeader[7]=0;
        }

        if(_u32ADTSWriteLeft!=0)
        {
            if(_u32ADTSWriteLeft>u32ReqBytes)
            {
                u32WriteSize = u32ReqBytes;
            }
            else
            {
                u32WriteSize = _u32ADTSWriteLeft;
            }
            u32readLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32WriteSize);
            if(u32readLeft!=0)
            {
                __ASSERT(0);
            }

            _u32ADTSWriteLeft -= u32WriteSize;
            u32ReqBytes -= u32WriteSize;
            dwReqAddress += u32WriteSize;
        }
        else
        {
            if(_u32StszCurrentFrame>=_u32StszTotalFrame)
            {
                AAC_ERR(printf("Add ADTS Error!\n"));
                return u32ReqBytes;
            }

            //boxM4a.stscInfo.pu32EntryInfo[0]:first_chunk      [1]:samples_per_chunk   [2]:Total samples
            if(stM4aInfo.stscInfo.u32CurrentEntry > 0)
            {
                u32SampleIndex = _u32StszCurrentFrame-stM4aInfo.stscInfo.pu32EntryInfo[(stM4aInfo.stscInfo.u32CurrentEntry-1)* STSC_INFO_ENTRY_INFO_COUNT+2];  //boxM4a.stscInfo.pu32EntryInfo[(boxM4a.stscInfo.u32CurrentEntry-1)][2]
            }
            else
            {
                u32SampleIndex = _u32StszCurrentFrame;
            }

            if((stM4aInfo.u32stscSize > 0) && (u32SampleIndex%stM4aInfo.u32stscSize == 0))
            {
                if(stM4aInfo.bFoundstco==TRUE)
                {
                    msAPI_Stream_Seek(u32Mp3FileHandle, M4aParser_GetOneStcoEntryFromDRAM(_u32M4aCurrentFrameIndex));
                    AAC_ERR2(printf("CurrentEntry:%lu StszFrame:%lu Current chunk:%lu stco_addr:0x%lx filePosition:0x%lx\n",stM4aInfo.stscInfo.u32CurrentEntry, _u32StszCurrentFrame,_u32M4aCurrentFrameIndex,M4aParser_GetOneStcoEntryFromDRAM(_u32M4aCurrentFrameIndex),msAPI_DataStreamIO_Tell(u32Mp3FileHandle)));
                }
                else
                {
                    msAPI_Stream_Seek(u32Mp3FileHandle, M4aParser_GetOneCo64EntryFromDRAM(_u32M4aCurrentFrameIndex));
                    AAC_ERR2(printf("CurrentEntry:%lu StszFrame:%lu Current chunk:%lu   co64_addr:0x%lx filePosition:0x%lx\n",stM4aInfo.stscInfo.u32CurrentEntry, _u32StszCurrentFrame,_u32M4aCurrentFrameIndex,M4aParser_GetOneCo64EntryFromDRAM(_u32M4aCurrentFrameIndex),msAPI_DataStreamIO_Tell(u32Mp3FileHandle)));
                }
                _u32M4aCurrentFrameIndex++;
            }


            if(_u32StszCurrentFrame>0 && _u32StszCurrentFrame == stM4aInfo.stscInfo.pu32EntryInfo[stM4aInfo.stscInfo.u32CurrentEntry * STSC_INFO_ENTRY_INFO_COUNT+2])
            {
                stM4aInfo.stscInfo.u32CurrentEntry++;
                stM4aInfo.u32stscSize = stM4aInfo.stscInfo.pu32EntryInfo[stM4aInfo.stscInfo.u32CurrentEntry* STSC_INFO_ENTRY_INFO_COUNT+1]; //boxM4a.stscInfo.pu32EntryInfo[(boxM4a.stscInfo.u32CurrentEntry)][1]
                AAC_ERR2(printf("Entry:%bu Size:%lu\n",stM4aInfo.stscInfo.u32CurrentEntry,stM4aInfo.u32stscSize));
            }

            u32CurrentFrameSize = M4aParser_GetOneStszEntryFromDRAM(_u32StszCurrentFrame);

            _u32StszCurrentFrame++;
            if(u32CurrentFrameSize == 0)
            {
                AAC_ERR(printf("ADTS Size Error!\n"));
                return u32ReqBytes;
            }

            _u32ADTSWriteLeft = u32CurrentFrameSize;
            AAC_ERR2(printf("u32NextPosition:0x%lx\n",u32CurrentFrameSize+msAPI_DataStreamIO_Tell(u32Mp3FileHandle)));

            u32CurrentFrameSize += MP4_PARSER_ADTS_HEADER_SIZE;
            _pu8ADTSHeader[0] = 0xFF;
            _pu8ADTSHeader[1] = 0xF1;
            _pu8ADTSHeader[2] = (U8)(stM4aInfo.u8SampleRateIndex-1);
            _pu8ADTSHeader[2] = 0x40 | (_pu8ADTSHeader[2] << 2) | ((stM4aInfo.u8channelConfiguration & 0x04) >> 2);
            _pu8ADTSHeader[3] = ((stM4aInfo.u8channelConfiguration & 0x03) << 6) | (U8)(u32CurrentFrameSize >> 11);
            _pu8ADTSHeader[4] = (U8)((u32CurrentFrameSize >> 3) & 0x000000FF);
            _pu8ADTSHeader[5] = 0x1F | (U8)((u32CurrentFrameSize << 5) & 0x000000E0);
            _pu8ADTSHeader[6] = 0xFC;

            //printf("2:%bx 3:%bx 4:%bx 5:%bx size:0x%lx\n",_pu8ADTSHeader[2],_pu8ADTSHeader[3],_pu8ADTSHeader[4],_pu8ADTSHeader[5],(U32)((((U16)_pu8ADTSHeader[3] & 0x3)) << 11)| (((U16)_pu8ADTSHeader[4]) << 3) | (_pu8ADTSHeader[5] >> 5));

            if(u32ReqBytes >= MP4_PARSER_ADTS_HEADER_SIZE)
            {
                //msAPI_MIU_Copy((U32)(_pu8ADTSHeader), dwReqAddress, MP4_PARSER_ADTS_HEADER_SIZE, MIU_SDRAM2SDRAM);
                memcpy((U8 *)_PA2VA(dwReqAddress), _pu8ADTSHeader,  MP4_PARSER_ADTS_HEADER_SIZE);

                _pu8ADTSHeader[7]=0;
                dwReqAddress += MP4_PARSER_ADTS_HEADER_SIZE;
                u32ReqBytes -= MP4_PARSER_ADTS_HEADER_SIZE;
            }
            else //u32ReqBytes < MP4_PARSER_ADTS_HEADER_SIZE
            {
                //msAPI_MIU_Copy((U32)(_pu8ADTSHeader), dwReqAddress, u32ReqBytes, MIU_SDRAM2SDRAM);
                memcpy((U8 *)_PA2VA(dwReqAddress), _pu8ADTSHeader, u32ReqBytes);

                _pu8ADTSHeader[7]=MP4_PARSER_ADTS_HEADER_SIZE-u32ReqBytes;
                dwReqAddress += u32ReqBytes;
                u32ReqBytes = 0;
            }
        }
    }
    return u32readLeft;
}

BOOLEAN M4AParser_WriteDSP(U32 dwReqAddress, U32 u32ReqBytes)
{
    U32 dwBypassSize=0;
    U32 u32CurrentFileLocation = 0; //save the file pointer we read
    U32 u32Diff= 0;
    U32 u32ReadLeft =0;

    //init when every m4a is opened
    if (_bM4aJustOpened)
    {
        u32M4aReadLeft= stM4aInfo.u32FileSize;
        AAC_ERR2(printf("@M4a file size:%lu\n",u32M4aReadLeft));

        //init frame index for FF/FB
        u32M4aTimeTemp = 0;
        _u32StszCurrentFrame = 0;
        _u32ADTSWriteLeft=0;
        memset(_pu8ADTSHeader,0,8);
        _u32M4aCurrentFrameIndex = 0;
        u32M4aPreviousFrameIndex = 0;
        if(stM4aInfo.bFoundstco==TRUE)
        {
            dwBypassSize  = M4aParser_GetOneStcoEntryFromDRAM(0);
        }
        else
        {
            dwBypassSize = M4aParser_GetOneCo64EntryFromDRAM(0);
        }

        M4aParser_GetOneStszEntryFromDRAM(0);

        //locate to mdae at first round
        if (stM4aInfo.u32MdatLocation < stM4aInfo.u32FileSize && stM4aInfo.u32MdatLocation > 0)
        {
            // 1023 use first frame location, instead of mdae loaction
            if (dwBypassSize < stM4aInfo.u32FileSize && dwBypassSize > stM4aInfo.u32MdatLocation)
            {
                msAPI_Stream_Seek(u32Mp3FileHandle, dwBypassSize );
                AAC_ERR(printf("@M4a bypass to 1st frame:%lu\n",dwBypassSize));
            }
            else
            {
                msAPI_Stream_Seek(u32Mp3FileHandle, stM4aInfo.u32MdatLocation );
                AAC_ERR(printf("@M4a bypass to mdat:0x%x\n",stM4aInfo.u32MdatLocation));
            }

            u32M4aReadLeft = stM4aInfo.u32MdatSize;
        }

        _bM4aJustOpened = FALSE;
        _bM4aTimerbyDSP = TRUE;
    }

    //FF/FB is  pressed
    if(stM4aInfo.bFoundstsz && stM4aInfo.bFoundstsc && stM4aInfo.u32stscSize>0)
    {
        U32 i;
        U32 u32Offset;
        if(bM4aRelocateFilePosition)
        {
            if(_u32StszCurrentFrame==0 && _u32M4aCurrentFrameIndex==0)//FB to File Begin
            {
                u32Offset = stM4aInfo.u32MdatLocation;
                stMp3Info.u32CurrentPlayTime = 0;
                u32M4aTimeTemp = 0;
                //init Entry
                stM4aInfo.stscInfo.u32CurrentEntry = 0;
                stM4aInfo.u32stscSize = stM4aInfo.stscInfo.pu32EntryInfo[1];   //boxM4a.stscInfo.pu32EntryInfo[0][1]
            }
            else if(_u32StszCurrentFrame==_u32StszTotalFrame)//FF to File End
            {
                u32M4aReadLeft = 0;
                u32Mp3FileBytesLeft = u32M4aReadLeft;
                return TRUE;
            }
            else//normal FF/FB case
            {
                U32 u32SampleIndex;
                _u32M4aCurrentFrameIndex = M4AParser_ReCalculateChunkIndex(_u32StszCurrentFrame,&u32SampleIndex);
                if(_u32M4aCurrentFrameIndex == 0)
                {
                    u32Offset = stM4aInfo.u32MdatLocation;
                }
                else
                {
                    if(stM4aInfo.bFoundstco==TRUE)
                    {
                        u32Offset = M4aParser_GetOneStcoEntryFromDRAM(_u32M4aCurrentFrameIndex-1);   //Check last Frame index offset!!
                    }
                    else
                    {
                        u32Offset = M4aParser_GetOneCo64EntryFromDRAM(_u32M4aCurrentFrameIndex-1);   //Check last Frame index offset!!
                    }
                }

                for(i=_u32StszCurrentFrame-u32SampleIndex;i<_u32StszCurrentFrame;i++)
                {
                    u32Offset += M4aParser_GetOneStszEntryFromDRAM(i);
                }
            }
            msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
            u32M4aReadLeft  = stM4aInfo.u32MdatSize -(u32Offset-stM4aInfo.u32MdatLocation);
            bM4aRelocateFilePosition = FALSE;
        }
    }
    else
    {
        //FF/FB is  pressed
        if (u32M4aPreviousFrameIndex != _u32M4aCurrentFrameIndex)
        {
            if (_u32M4aCurrentFrameIndex == 0)
            {
                _bM4aTimerbyDSP = TRUE;
            }
            else //FFREW pressed, 51 takes over the timing
            {
                _bM4aTimerbyDSP = FALSE;
            }

            if (_u32M4aCurrentFrameIndex < _u32FrameArrayIndex)
            {
                if(stM4aInfo.bFoundstco==TRUE)
                {
                    dwBypassSize = M4aParser_GetOneStcoEntryFromDRAM(_u32M4aCurrentFrameIndex);
                }
                else
                {
                    dwBypassSize = M4aParser_GetOneCo64EntryFromDRAM(_u32M4aCurrentFrameIndex);
                }

                if (dwBypassSize < stM4aInfo.u32FileSize)
                {
                    msAPI_Stream_Seek(u32Mp3FileHandle, dwBypassSize );

                    u32M4aReadLeft = stM4aInfo.u32FileSize - dwBypassSize;
                    AAC_ERR2(printf("@bypass:%lu, index:%lu\n",dwBypassSize,_u32M4aCurrentFrameIndex));
                }
                else
                {
                    AAC_ERR(printf("@loc error, no bypass to:%lu, index:%lu\n",dwBypassSize,_u32M4aCurrentFrameIndex ));
                    // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
                    msAPI_Music_CleanFileEndData(dwReqAddress, u32ReqBytes, 0x0UL);
                    msAPI_Music_FileEndDataHandle(u32ReqBytes);
                    msAPI_Stream_Seek(u32Mp3FileHandle, stM4aInfo.u32FileSize);
                    u32M4aReadLeft = 0;
                }
            }
            else
            {
                // FF at last frame, stop
                // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
                msAPI_Music_CleanFileEndData(dwReqAddress, u32ReqBytes, 0x0UL);
                msAPI_Music_FileEndDataHandle(u32ReqBytes);
                msAPI_Stream_Seek(u32Mp3FileHandle, stM4aInfo.u32FileSize);
                u32M4aReadLeft = 0;
            }
        }
        AAC_ERR2(printf("@M4a FFREW, u32CurrentFileLocation:%lu, u32readLeft:%lu, u32ReqBytes:%lu\n",u32CurrentFileLocation,u32M4aReadLeft,u32ReqBytes));
    }

    u32CurrentFileLocation = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
    u32Diff = u32CurrentFileLocation + u32ReqBytes;

    //just keep playing...
    if(stM4aInfo.u32FileSize > u32Diff && u32M4aReadLeft > 0 )
    {
        if(stM4aInfo.bFoundstsz && stM4aInfo.bFoundstsc && stM4aInfo.u32stscSize >0)
        {
            //Handle ADTS header
            u32ReadLeft = M4AParser_AddADTSHeaderForDSP(dwReqAddress, u32ReqBytes);
        }
        else //Just output raw data to dram
        {
            u32ReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32ReqBytes);

            //Set frame index here....
            if (u32M4aReadLeft > 0 &&_bM4aEnableFFFB)
            {
                _u32M4aCurrentFrameIndex = M4AParser_SetCurrentFrameIndex();
                //printf("fileposition:0x%lx  _u32M4aCurrentFrameIndex:%lu addr:0x%lx\n",msAPI_DataStreamIO_Tell(u32Mp3FileHandle),_u32M4aCurrentFrameIndex,M4aParser_GetOneStcoEntryFromDRAM(_u32M4aCurrentFrameIndex));
                u32M4aPreviousFrameIndex = _u32M4aCurrentFrameIndex;
            }
        }

        if(u32ReadLeft==u32ReqBytes)
        {
            // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
            msAPI_Music_CleanFileEndData(dwReqAddress, u32ReqBytes, 0x0UL);
            msAPI_Music_FileEndDataHandle(u32ReqBytes);
            u32Mp3FileBytesLeft=0;
            u32M4aReadLeft=0;
            return TRUE;
        }
        else if(u32ReadLeft>0)
        {   //already finished reading
            AAC_ERR2(printf("@M4a fileread not read 5:%lu\n",u32ReadLeft));
            // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
            msAPI_Music_CleanFileEndData(dwReqAddress+(u32ReqBytes-u32ReadLeft), u32ReadLeft, 0x0UL);
            msAPI_Music_FileEndDataHandle(u32ReadLeft);
            //u32Diff = u32CurrentFileLocation + (u32ReqBytes-u32ReadLeft);
            u32M4aReadLeft = 0;
        }
        else
        {
            u32M4aReadLeft  = stM4aInfo.u32FileSize -u32Diff;
        }

        AAC_ERR2(printf("@M4a round I, u32CurrentFileLocation:%lu, u32readLeft:%lu, u32ReqBytes:%lu\n",u32CurrentFileLocation,u32M4aReadLeft,u32ReqBytes));
    }
    else
    {
        // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
        msAPI_Music_CleanFileEndData(dwReqAddress, u32ReqBytes, 0x0UL);

        //do the final round
        u32Diff = stM4aInfo.u32FileSize - u32CurrentFileLocation;
        AAC_ERR2(printf("@M4a do the final round II, u32CurrentFileLocation:%lu, u32readLeft:%lu, u32ReqBytes:%lu, u32Diff:%lu\n",u32CurrentFileLocation,u32M4aReadLeft,u32ReqBytes,u32Diff));

        if(stM4aInfo.bFoundstsz && stM4aInfo.bFoundstsc && stM4aInfo.u32stscSize >0)
        {
            //Handle ADTS header
            u32M4aReadLeft = M4AParser_AddADTSHeaderForDSP(dwReqAddress, u32Diff);
        }
        else
        {
            u32M4aReadLeft = msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)dwReqAddress, u32Diff);
        }

        if(u32M4aReadLeft!=0)
        {
            //already finished reading
            AAC_ERR2(printf("@M4a fileread not read 5:%lu\n",u32M4aReadLeft));
            msAPI_Music_FileEndDataHandle(u32ReqBytes - (u32Diff - u32M4aReadLeft));
        }
        else //happy ending
        {
            AAC_ERR2(printf("@M4a end to DSP:%lu\n",u32M4aReadLeft));
            msAPI_Music_FileEndDataHandle(u32ReqBytes-u32Diff);
        }

        AAC_ERR2(printf("@M4a do the final round III, u32CurrentFileLocation:%lu, u32readLeft:%lu, u32ReqBytes:%lu\n",u32CurrentFileLocation,u32M4aReadLeft,u32ReqBytes));
        u32M4aReadLeft =0;
    }

    //inform mp3 state
    u32Mp3FileBytesLeft = u32M4aReadLeft;

    return TRUE;
}

//-------------------------------------------------------------------------------------------------
/// To set frame index by reading status
/// @param none
/// @return u32Index : the array index of frame size

/// @note
//-------------------------------------------------------------------------------------------------

U32 M4AParser_SetCurrentFrameIndex(void)
{
    U32 u32FileLocation=0, u32Index=0;
//    U32 i=0;
    U32 u32Temp = 0;

    u32FileLocation = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);

    if (u32FileLocation == 0xFFFFFFFF)
    {
        AAC_ERR(printf("@M4a FileTell Error\n"));
        return 0;
    }

    //compare with the frame array
    //u32Diff = * ( _u32pFrameLocArray + _u32M4aCurrentFrameIndex) - * ( _u32pFrameLocArray + 0);

    //_u32pFrameLocArray = (U32 xdata *) msAPI_XdataExt_Use( (U16) _u32pFrameLocArray);

#define AAC_USE_BINARY_SEARCH
#ifndef AAC_USE_BINARY_SEARCH
    for (i=0;i<_u32FrameArrayIndex;i++)
    {
        //if (u32FileLocation > _u32FrameArray[i])
        if (u32FileLocation > * ( _u32pFrameLocArray + i))
        {
            u32Index = i;
        }
        else //Filelocation may bigger than the last frame location
        {
            break;
        }
    }
 #else
    {     //binary search the frame of the nearest value
        U32 u32Above, u32Below, u32Middle;
        BOOLEAN bFound = FALSE;
        u32Above = _u32FrameArrayIndex+1;
        u32Below = 0;

        while(u32Above-u32Below > 1)
        {
            u32Middle = (u32Above+u32Below)/2;

            if(stM4aInfo.bFoundstco==TRUE)
            {
                u32Temp = M4aParser_GetOneStcoEntryFromDRAM(u32Middle-1);
            }
            else
            {
                u32Temp = M4aParser_GetOneCo64EntryFromDRAM(u32Middle-1);
            }


            if (u32FileLocation ==u32Temp)
            //  if (u32FileLocation == * ( _u32pFrameLocArray + u32Middle-1))
            {
                u32Index = u32Middle-1;
                bFound = TRUE;

                break;
            }

            if (u32FileLocation < u32Temp)
            {
                u32Above = u32Middle;
            }
            else
            {
                u32Below = u32Middle;
            }
        }

        if (!bFound)
        {
            if(u32Below > 0)
            {
                u32Index = u32Below-1;
            }
        }
        if(stM4aInfo.bFoundstco==TRUE)
        {
            u32Temp = M4aParser_GetOneStcoEntryFromDRAM(u32Index);
        }
        else
        {
            u32Temp = M4aParser_GetOneCo64EntryFromDRAM(u32Index);
        }
        AAC_ERR2(printf("@BS: FileLoc:%lu, Index:%lu, FrameLoc:%lu\n",u32FileLocation,u32Index,u32Temp));
    }
 #endif

    //_u32pFrameLocArray = (U32 xdata *) msAPI_XdataExt_Unuse( (U16) _u32pFrameLocArray);

    return u32Index;
}

//-------------------------------------------------------------------------------------------------
/// Set frame index by FF/FB
/// @param u8Btn: the pressed button
/// @return TRUE : succeed
/// @return FALSE : fail
/// @note
//-------------------------------------------------------------------------------------------------
BOOLEAN M4AParser_SetFrameIndexbyBtn(U8 u8Mode)
{
    if (u8Mode == MP3_FF_Mode)
    {
        AAC_ERR2(printf("FF Index:%lu\n",_u32M4aCurrentFrameIndex));

        if (_u32M4aCurrentFrameIndex + M4A_FFREW_FRAME < _u32FrameArrayIndex)
        {
            _u32M4aCurrentFrameIndex +=M4A_FFREW_FRAME;
        }
        else
        {
            _u32M4aCurrentFrameIndex= _u32FrameArrayIndex;
            m_bCheckFftoEnd = TRUE;
        }
    }
    else // FB
    {
        AAC_ERR2(printf("REW Index:%lu\n",_u32M4aCurrentFrameIndex));

        if (_u32M4aCurrentFrameIndex > M4A_FFREW_FRAME)
        {
            _u32M4aCurrentFrameIndex -=M4A_FFREW_FRAME;
        }
        else
        {
            _u32M4aCurrentFrameIndex = 0;
            u8MusicFFFWMode = MP3_NORMAL_MODE;
            MApp_Music_Resume();
        }
    }

    AAC_ERR2(printf("Btn:%u, Index:%lu\n",u8Mode,_u32M4aCurrentFrameIndex));
    //msAPI_Timer_Delayms(AAC_FFREW_DELAY);

    return TRUE;
}

//-------------------------------------------------------------------------------------------------
/// Get one stco entry from DRAM
/// @param : u32Index
/// @return TRUE : succeed
/// @return FALSE : fail
/// @note: 1025, SAVE ALL ENTRIES INTO DRAM
//-------------------------------------------------------------------------------------------------
U32 M4aParser_GetOneStcoEntryFromDRAM(U32 u32Index)
{

    U32 u32TempLoc=0, u32TempPosition=0, u32IndexOffset;
    static U32 u32StartPointer=0;

    if(_bM4aJustOpened || (u32StartPointer > u32Index)
                       || (u32Index >= (u32StartPointer + (M4A_STCO_ENTRY_BUFFER_LEN/M4A_STCO_ENTRY_SIZE))))
    {
        u32TempPosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
        msAPI_Stream_Seek(u32Mp3FileHandle, (stM4aInfo.u32stcoFrameLocation + (u32Index*M4A_STCO_ENTRY_SIZE)));
        msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)M4A_STCO_ENTRY_BUFFER, M4A_STCO_ENTRY_BUFFER_LEN);
        msAPI_Stream_Seek(u32Mp3FileHandle, u32TempPosition);
        u32StartPointer = u32Index;
    }
    u32IndexOffset = u32Index - u32StartPointer;

    memcpy(&u32TempLoc,(U8 *)_PA2VA(M4A_STCO_ENTRY_BUFFER + (u32IndexOffset*M4A_STCO_ENTRY_SIZE)),4);
    u32TempLoc=Swap32(u32TempLoc);

    AAC_ERR2(printf("@Stco i:%lu, frameloc:0x%lx\n",u32Index, u32TempLoc));

    return u32TempLoc;

}

//-------------------------------------------------------------------------------------------------
/// Get one co64 entry from DRAM
/// @param : u32Index
/// @return TRUE : succeed
/// @return FALSE : fail
/// @note: 1025, SAVE ALL ENTRIES INTO DRAM
//-------------------------------------------------------------------------------------------------
U32 M4aParser_GetOneCo64EntryFromDRAM(U32 u32Index)
{
    U32 u32TempLoc=0, u32TempPosition=0, u32IndexOffset;

    #define M4A_CO64_ENTRY_HALF_SIZE  (M4A_CO64_ENTRY_SIZE/2)

    static U32 u32StartPointer=0;

    if(_bM4aJustOpened || (u32StartPointer > u32Index)
                       || (u32Index >= (u32StartPointer + (M4A_CO64_ENTRY_BUFFER_LEN/M4A_CO64_ENTRY_SIZE))))
    {
        u32TempPosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
        msAPI_Stream_Seek(u32Mp3FileHandle, (stM4aInfo.u32co64FrameLocation + (u32Index*M4A_CO64_ENTRY_SIZE)));
        msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)M4A_CO64_ENTRY_BUFFER, M4A_CO64_ENTRY_BUFFER_LEN);
        msAPI_Stream_Seek(u32Mp3FileHandle, u32TempPosition);
        u32StartPointer = u32Index;
    }
    u32IndexOffset = u32Index - u32StartPointer;

    //deal with low part only, ignore high part because we only support U32 file offset
    memcpy(&u32TempLoc,(U8 *)_PA2VA(M4A_CO64_ENTRY_BUFFER + (u32IndexOffset*M4A_CO64_ENTRY_SIZE + M4A_CO64_ENTRY_HALF_SIZE)),M4A_CO64_ENTRY_HALF_SIZE);
    u32TempLoc=Swap32(u32TempLoc);

    AAC_ERR2(printf("@co64 i:%lu, frameloc:0x%lx\n",u32Index, u32TempLoc));

    return u32TempLoc;
}

//-------------------------------------------------------------------------------------------------
/// Get one stsz entry from DRAM
/// @param : u32Index
/// @return TRUE : succeed
/// @return FALSE : fail
/// @note: 1025, SAVE ALL ENTRIES INTO DRAM
//-------------------------------------------------------------------------------------------------
U32 M4aParser_GetOneStszEntryFromDRAM(U32 u32Index)
{

    U32 u32TempLoc=0, u32TempPosition=0, u32IndexOffset;
    static U32 u32StartPointer=0;

    if(_bM4aJustOpened || (u32StartPointer > u32Index)
                       || (u32Index >= (u32StartPointer + (M4A_STSZ_ENTRY_BUFFER_LEN/M4A_STCO_ENTRY_SIZE))))
    {
        u32TempPosition = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);
        msAPI_Stream_Seek(u32Mp3FileHandle, ((stM4aInfo.u32stszLocation) + (u32Index*M4A_STCO_ENTRY_SIZE)));
        msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)M4A_STSZ_ENTRY_BUFFER, M4A_STSZ_ENTRY_BUFFER_LEN);
        msAPI_Stream_Seek(u32Mp3FileHandle, u32TempPosition);
        u32StartPointer = u32Index;
    }
    u32IndexOffset = u32Index - u32StartPointer;

    memcpy(&u32TempLoc,(U8 *)_PA2VA(M4A_STSZ_ENTRY_BUFFER + (u32IndexOffset*M4A_STCO_ENTRY_SIZE)),4);
    u32TempLoc=Swap32(u32TempLoc);

    AAC_ERR2(printf("@Stsz i:%lu, frameloc:0x%lx\n",u32Index, u32TempLoc));

    return u32TempLoc;

}

//-------------------------------------------------------------------------------------------------
/// Save all frame into DRAM, instead of Xdata
/// @param void:
/// @return TRUE : succeed
/// @return FALSE : fail
/// @note: 1025, SAVE ALL ENTRIES INTO DRAM
//-------------------------------------------------------------------------------------------------
BOOLEAN M4AParser_SaveFrameLocation(void)
{
    if(stM4aInfo.bFoundstco &&  stM4aInfo.u32stcoFrameLocation < stM4aInfo.u32FileSize && stM4aInfo.u32stcoEntry > 0)
    {
        _u32FrameArrayIndex = stM4aInfo.u32stcoEntry;
    }
    else if(stM4aInfo.bFoundco64 &&  stM4aInfo.u32co64FrameLocation < stM4aInfo.u32FileSize && stM4aInfo.u32co64Entry > 0)
    {
        _u32FrameArrayIndex = stM4aInfo.u32co64Entry;
    }
    else
    {
        _u32FrameArrayIndex=0;
    }

    _u32StszCurrentFrame=0;
    _u32StszTotalFrame = 0;

    //save stsz info
    if(stM4aInfo.bFoundstsz &&  stM4aInfo.u32stszLocation < stM4aInfo.u32FileSize && stM4aInfo.u32stszSize > 0)
    {
        _u32StszTotalFrame = stM4aInfo.u32stszSize/STSZ_ENTRY_SIZE;
    }

    //save stsc info
    //boxM4a.stscInfo.pu32EntryInfo[0]:first_chunk      [1]:samples_per_chunk   [2]:Total samples
    if(stM4aInfo.bFoundstsc)
    {
        U8 *pu8StscData;
        U32 i;    //u32EntryInfo can be larger than 255, use U32 instead
        U32 u32ReadCounter=0;
        U32 u32MemoryAlign=0;

        memset(&stM4aInfo.stscInfo,0,sizeof(stM4aInfo.stscInfo));
        u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);

        if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
        {
            AAC_ERR(printf("@M4A Open file failed\n"));
            return FALSE;
        }

        AAC_ERR2(printf("u32stscLocation:0x%x\n",stM4aInfo.u32stscLocation));
        msAPI_Stream_Seek(u32Mp3FileHandle, stM4aInfo.u32stscLocation);
        msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)M4A_STSC_ENTRY_BUFFER,2048);
        pu8StscData = (U8 *)_PA2VA(M4A_STSC_ENTRY_BUFFER);

        memcpy(&stM4aInfo.stscInfo.u32TotalEntry,pu8StscData,4);
        pu8StscData += 4;
        stM4aInfo.stscInfo.u32TotalEntry = Swap32(stM4aInfo.stscInfo.u32TotalEntry);


        //if boxM4a.stscInfo.u32TotalEntry<= STSC_ENTRY_LIMIT, don't allocate memory
        //else allocate enough memory
        if(stM4aInfo.stscInfo.u32TotalEntry<= STSC_ENTRY_LIMIT)
        {
            stM4aInfo.stscInfo.pu32EntryInfo = u32EntryInfoSmaller;
            AAC_ERR(printf("u32TotalEntry <= STSC_ENTRY_LIMIT, don't malloc boxM4a.stscInfo.pu32EntryInfo\n"));
            AAC_ERR(printf("u32EntryInfoSmaller address is: %lu\n",(U32) u32EntryInfoSmaller));
        }
        else
        {
            //allocate another 4 more bytes to make sure the address is a mutilple of 4
            stM4aInfo.stscInfo.pu32EntryInfo = (U32 *)msAPI_Memory_Allocate(sizeof(U32) * STSC_INFO_ENTRY_INFO_COUNT * stM4aInfo.stscInfo.u32TotalEntry + 4,BUF_ID_FILEBROWER );

            AAC_ERR(printf("u32TotalEntry > STSC_ENTRY_LIMIT, malloc boxM4a.stscInfo.pu32EntryInfo\n"));

            if(stM4aInfo.stscInfo.pu32EntryInfo==NULL)
            {
                MApp_Music_CloseFile();
                AAC_ERR(printf("malloc for stscInfo.pu32EntryInfo fail\n"));
                return FALSE;
            }

            u32MemoryAlign = (U32)&stM4aInfo.stscInfo.pu32EntryInfo;

            if( (u32MemoryAlign & 3) !=0)
            {
                stM4aInfo.stscInfo.pu32EntryInfo = stM4aInfo.stscInfo.pu32EntryInfo + (4 - (u32MemoryAlign & 3)); //make sure the address is a mutiple of 4
            }

            AAC_ERR(printf("boxM4a.stscInfo.pu32EntryInfo memory address is: 0x%x\n",(U32) &stM4aInfo.stscInfo.pu32EntryInfo));
        }
        AAC_ERR(printf("boxM4a.stscInfo.pu32EntryInfo is pointing to address: 0x%x\n",(U32) stM4aInfo.stscInfo.pu32EntryInfo));

        stM4aInfo.u32stscLocation = stM4aInfo.u32stscLocation + 4;  //move index to stsc first chunk

        msAPI_Stream_Seek(u32Mp3FileHandle, stM4aInfo.u32stscLocation);
        msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)M4A_STSC_ENTRY_BUFFER,2048);

        pu8StscData = (U8 *)_PA2VA(M4A_STSC_ENTRY_BUFFER);


        for(i=0;i<stM4aInfo.stscInfo.u32TotalEntry;i++)
        {

            memcpy(&stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT],pu8StscData,4); //[0]:first_chunk,  boxM4a.stscInfo.pu32EntryInfo[i][0]
            stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT] = Swap32(stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT]);

            pu8StscData += 4;
            u32ReadCounter = u32ReadCounter+4;

            memcpy(&stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT + 1],pu8StscData,4); //[1]:samples_per_chunk,  boxM4a.stscInfo.pu32EntryInfo[i][1]
            stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT +1] = Swap32(stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT +1]);

            AAC_ERR2(printf("STSC Entry:%lu, num:%lx\n",i, stM4aInfo.stscInfo.pu32EntryInfo[i* STSC_INFO_ENTRY_INFO_COUNT +1]));

            pu8StscData += 4;
            u32ReadCounter = u32ReadCounter +4;

            pu8StscData += 4;   //non-used: sample_description_index
            u32ReadCounter = u32ReadCounter +4;


            //the for loop reads 12 bytes (each stsc entry is 12 bytes)every time,
            //when the counter is 2040 (2040%12=0)
            //we need to read from file again (we read 2048 bytes to buffer only)
            //to get the rest of u32EntryInfo
            if(u32ReadCounter + 12 >= 2048)    //next round will exceed
            {
                stM4aInfo.u32stscLocation = stM4aInfo.u32stscLocation + u32ReadCounter;
                msAPI_Stream_Seek(u32Mp3FileHandle, stM4aInfo.u32stscLocation);

                AAC_ERR(printf("boxM4a.u32stscLocation: 0x%x\n",stM4aInfo.u32stscLocation));

                msAPI_DataStreamIO_Read(u32Mp3FileHandle,(void*)M4A_STSC_ENTRY_BUFFER,2048);
                pu8StscData = (U8 *)_PA2VA(M4A_STSC_ENTRY_BUFFER);
                u32ReadCounter = 0;
            }
        }

        if(stM4aInfo.stscInfo.u32TotalEntry>0)
        {
            U32 u32TotalSamples=0;
            for(i=0;i<(stM4aInfo.stscInfo.u32TotalEntry -1);i++)
            {
                u32TotalSamples += (stM4aInfo.stscInfo.pu32EntryInfo[(i+1) * STSC_INFO_ENTRY_INFO_COUNT]-stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT])*stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT + 1];  //[2]:Total samples
                stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT + 2] = u32TotalSamples;   //boxM4a.stscInfo.pu32EntryInfo[i][2]
            }
            //last Entry
            // i == (boxM4a.stscInfo.u32TotalEntry -1)
           stM4aInfo.stscInfo.pu32EntryInfo[i * STSC_INFO_ENTRY_INFO_COUNT + 2] = _u32StszTotalFrame;
        }

        //init Entry
        stM4aInfo.stscInfo.u32CurrentEntry = 0;
        stM4aInfo.u32stscSize = stM4aInfo.stscInfo.pu32EntryInfo[1];   //boxM4a.stscInfo.pu32EntryInfo[0][1]

        AAC_ERR2(printf("Stsc total entry:0x%x\n",stM4aInfo.stscInfo.u32TotalEntry));
        AAC_ERR2(printf("Stsc 1: first_chunk:0x%x samples_per_chunk:0x%lx u32TotalSamples:0x%x\n",stM4aInfo.stscInfo.pu32EntryInfo[0* STSC_INFO_ENTRY_INFO_COUNT],stM4aInfo.stscInfo.pu32EntryInfo[0 * STSC_INFO_ENTRY_INFO_COUNT + 1],stM4aInfo.stscInfo.pu32EntryInfo[0 * STSC_INFO_ENTRY_INFO_COUNT+2]));
        AAC_ERR2(printf("Stsc 2: first_chunk:0x%x samples_per_chunk:0x%lx u32TotalSamples:0x%x\n",stM4aInfo.stscInfo.pu32EntryInfo[1* STSC_INFO_ENTRY_INFO_COUNT],stM4aInfo.stscInfo.pu32EntryInfo[1 * STSC_INFO_ENTRY_INFO_COUNT +1],stM4aInfo.stscInfo.pu32EntryInfo[1*STSC_INFO_ENTRY_INFO_COUNT+2]));
        AAC_ERR2(printf("Stsc 3: first_chunk:0x%x samples_per_chunk:0x%lx u32TotalSamples:0x%x\n",stM4aInfo.stscInfo.pu32EntryInfo[2*STSC_INFO_ENTRY_INFO_COUNT],stM4aInfo.stscInfo.pu32EntryInfo[2*STSC_INFO_ENTRY_INFO_COUNT+1],stM4aInfo.stscInfo.pu32EntryInfo[2*STSC_INFO_ENTRY_INFO_COUNT+2]));
        MApp_Music_CloseFile();
    }

    AAC_ERR2(printf("@M4A _u32StszTotalFrame: %lu\n",_u32StszTotalFrame));
    AAC_ERR2(printf("@M4A total frame(+1): %lu\n",_u32FrameArrayIndex));

    return TRUE;
}

#endif
#endif

#ifdef OGG_PARSER
#if OGG_PRINTDATA
static void _MApp_Music_OggPrintfData(U32 addr, U32 size)
{

    U32 i;
    U8* p = (U8*)_PA2VA(addr);
    for(i=0;i<size;i++)
    {
        if(i%16==0)
        {
            OGG_DBG(printf("\n"));
        }
        OGG_DBG(printf("%02x ", p[i]));

    }
    OGG_DBG(printf("\n\n"));

}
#endif
#if (ENABLE_OGG)
static BOOLEAN _MApp_Music_OggGetPacketStartInPage(Ogg_Page *pOggPage, U32 *pu32PacketStartAddr, U32 *pu32SkipSize)
{
    U8* pSegmentTable = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)) + 27);
    U8 i = 0, u8SegmentNum = pOggPage->u8SegmentNum;
    U32 u32Offset = 0;
    BOOLEAN bFindPacketEnd = FALSE;

    if (!(pOggPage->u8HeaderType&OGG_PAGE_CONT))
    {
        g_OggInfo.bInputFromPacketStart = FALSE;
        *pu32PacketStartAddr = pOggPage->u32PageBodyOffset;
        *pu32SkipSize = 0;
        OGG_DBG(printf("[OGG]: find packet start. Current Page start.\n"));
        return TRUE;
    }
    else
    {
        while(i < u8SegmentNum)
        {
            u32Offset += pSegmentTable[i];
            if(pSegmentTable[i] < 0xFF)
            {
                bFindPacketEnd = TRUE;
                break;
            }
            i++;
        }
        if(bFindPacketEnd && (i < (u8SegmentNum-1)))
        {
            g_OggInfo.bInputFromPacketStart = FALSE;
            *pu32PacketStartAddr = pOggPage->u32PageBodyOffset + u32Offset;
            *pu32SkipSize = u32Offset;
            OGG_DBG(printf("[OGG]: find packet start. Offset: 0x%x\n", u32Offset));
            return TRUE;
        }
        else if(bFindPacketEnd && (i == (u8SegmentNum-1)))
        {
            //next page is start from packet header.
            g_OggInfo.bInputFromPacketStart = FALSE;
            *pu32SkipSize = 0;
            *pu32PacketStartAddr = 0;
            OGG_DBG(printf("[OGG]: find packet start, it begin from next page.\n"));
            return FALSE;
        }
        else
        {
            *pu32PacketStartAddr = 0;
            *pu32SkipSize = 0;
            return FALSE;
        }
    }
}

//get next ogg page and seek to body offset
static S32 _MApp_Music_OggGetNextPage(Ogg_Page *pOggPage)
{
    U32 u32PageHeaderBuf = ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));
    U8 *pu8PageHeaderBuf;
    U32 i, u32BodyLen = 0;
    LongLong u64Granulepos;
    S32 ret = -1;
    U32 u32Offset = 0;

TryToFindNextOggHeader:
    if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)(u32PageHeaderBuf + u32Offset), 27 - u32Offset) > 0)
    {
         OGG_DBG(printf("[OGG]: no data to read.\n"));
         ret = 0;
         goto GetPageFail;
    }

    pu8PageHeaderBuf = (U8 *)_PA2VA(u32PageHeaderBuf);
    if(memcmp(pu8PageHeaderBuf,"OggS",4))
    {
        BOOLEAN bFindNext = FALSE;
        //try to find next "OggS"
        OGG_DBG(printf("[OGG]: Page header wrong, try to find next.\n"));

        for(i = 1; i< 27; i++)
        {
            if(pu8PageHeaderBuf[i] == 'O')
            {
                bFindNext = TRUE;
                OGG_DBG(printf("[OGG]: find next OggS\n"));
                break;
            }
        }

        if(bFindNext)
        {
            memmove(pu8PageHeaderBuf, &pu8PageHeaderBuf[i], 27 - i);
            u32Offset = 27 - i;
        }
        else
        {
            u32Offset = 0;
        }
        goto TryToFindNextOggHeader;
    }

    OGG_DBG(printf("[OGG]: find a page.\n"));
    u64Granulepos.Hi= (U32)pu8PageHeaderBuf[13];
    u64Granulepos.Hi = (u64Granulepos.Hi<<8)|(pu8PageHeaderBuf[12]);
    u64Granulepos.Hi = (u64Granulepos.Hi<<8)|(pu8PageHeaderBuf[11]);
    u64Granulepos.Hi = (u64Granulepos.Hi<<8)|(pu8PageHeaderBuf[10]);
    u64Granulepos.Lo= (U32)(pu8PageHeaderBuf[9]);
    u64Granulepos.Lo = (u64Granulepos.Lo<<8)|(pu8PageHeaderBuf[8]);
    u64Granulepos.Lo = (u64Granulepos.Lo<<8)|(pu8PageHeaderBuf[7]);
    u64Granulepos.Lo = (u64Granulepos.Lo<<8)|(pu8PageHeaderBuf[6]);
    pOggPage->u64Granulepos = u64Granulepos;
    pOggPage->u32SerialNo = pu8PageHeaderBuf[14]|pu8PageHeaderBuf[15]<< 8|pu8PageHeaderBuf[16] << 16|pu8PageHeaderBuf[17]<<24;
    pOggPage->u32PageNo = pu8PageHeaderBuf[18]|pu8PageHeaderBuf[19]<< 8|pu8PageHeaderBuf[20] << 16|pu8PageHeaderBuf[21]<<24;
    pOggPage->u8SegmentNum = pu8PageHeaderBuf[26];
    pOggPage->u8HeaderType = pu8PageHeaderBuf[5];
    pOggPage->u32HeaderLen = 27 + pOggPage->u8SegmentNum;
    pOggPage->u32PageHeaderOffset = msAPI_DataStreamIO_Tell(u32Mp3FileHandle) - 27;

    if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)(u32PageHeaderBuf + 27), pOggPage->u8SegmentNum) > 0)
    {
         OGG_INFO(printf("[OGG]: no data to read.\n"));
         ret = 0;
         goto GetPageFail;
    }

    for(i = 0; i < pOggPage->u8SegmentNum; i++)
    {
        u32BodyLen += pu8PageHeaderBuf[27 + i];
    }
    pOggPage->u32BodyLen = u32BodyLen;
    pOggPage->u32PageBodyOffset = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);

    OGG_DBG(printf("[OGG]: Get page success.\n"));
    OGG_DBG(printf("[OGG]: page NO: 0x%lx, Header len: 0x%lx, Header offset:0x%lx\n",
        pOggPage->u32PageNo, pOggPage->u32HeaderLen, pOggPage->u32PageHeaderOffset));
    OGG_DBG(printf("[OGG]: body len: 0x%lx, body offset:0x%lx, GranulePos: 0x%lx %lx\n\n",
        pOggPage->u32BodyLen, pOggPage->u32PageBodyOffset, (U32)(pOggPage->u64Granulepos.Hi), (U32)pOggPage->u64Granulepos.Lo));
    return (1);

GetPageFail:
    OGG_ERR(printf("[OGG]: Get page fail.\n"));
    return (ret);
}


//find last ogg page with valid granupos before u32EndOffset
static BOOLEAN _MApp_Music_OggGetPrePageValidGranuPos(LongLong *pu64GranuPos, U32 u32EndOffset)
{
    Ogg_Page OggPage;
    U32 u32ScanSize = 2048;
    U32 u32BeginOffset = 0;
    LongLong u64PreGranuPos;
    BOOLEAN bFindValidGranuPos = FALSE;

    OGG_DBG(printf("[OGG]: enter _MApp_Music_OggGetPrePageValidGranuPos.\n"));

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        OGG_ERR(printf("[OGG]: file is not opened\n"));
        return FALSE;
    }

    if(u32EndOffset <= 27)
    {
        memset(pu64GranuPos, 0, sizeof(LongLong));
        return TRUE;
    }

    if(u32EndOffset < u32ScanSize)
    {
        u32BeginOffset = 0;
    }
    else
    {
        u32BeginOffset = u32EndOffset - u32ScanSize;
    }
    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32BeginOffset, E_DATA_STREAM_SEEK_SET);

    memset(&OggPage, 0, sizeof(Ogg_Page));
    u64PreGranuPos.Lo = 0xFFFFFFFF;
    u64PreGranuPos.Hi = 0xFFFFFFFF;

    while(1)
    {
        if(_MApp_Music_OggGetNextPage(&OggPage) > 0)
        {
            if(OggPage.u32PageHeaderOffset < u32EndOffset)
            {
                if((U32)OggPage.u64Granulepos.Lo != 0xFFFFFFFF)
                {
                    memcpy(&u64PreGranuPos, &OggPage.u64Granulepos, sizeof(LongLong));
                    bFindValidGranuPos = TRUE;
                    g_OggInfo.u32VorbisLastAudioPageOffset = OggPage.u32PageHeaderOffset;
                    OGG_DBG(printf("[OGG]: u32VorbisLastAudioPageStart: 0x%x\n", g_OggInfo.u32VorbisLastAudioPageOffset));
                    OGG_DBG(printf("[OGG]:Find valid granupos:0x%x\n", (U32)u64PreGranuPos.Lo));
                }
            }
            else
            {
                break;
            }
            msAPI_DataStreamIO_Seek(u32Mp3FileHandle, OggPage.u32PageBodyOffset + OggPage.u32BodyLen, E_DATA_STREAM_SEEK_SET);
        }
        else
        {
            break;
        }
    }

    if(bFindValidGranuPos)
    {
        memcpy(pu64GranuPos, &u64PreGranuPos, sizeof(LongLong));
        return TRUE;
    }
    else
    {
        return _MApp_Music_OggGetPrePageValidGranuPos(pu64GranuPos, u32BeginOffset);
    }
}

static void  _MApp_Music_OggSetComment(U8* pCommentStr, U32 u32Size)
{
    U32 i, u32CopyLen = 0;
    OGG_COMMENTID id = OGG_NONE;
    U8* pDst = NULL;
    U8* pSrc = NULL;

    U8 *pCommentStrTemp = msAPI_Memory_Allocate(sizeof(U8) * u32Size,BUF_ID_FILEBROWER );

    if(pCommentStrTemp==NULL)
    {
        OGG_DBG(printf("pCommentStrTemp is NULL\n"));
        return;
    }
    memcpy(pCommentStrTemp, pCommentStr, u32Size);

    OGG_DBG(printf("\n[OGG]: set commentstr, size: 0x%x\n", u32Size));
    for(i = 0; i < u32Size; i++)
    {
        if(pCommentStrTemp[i] >= 'a' && pCommentStrTemp[i] <= 'z')
        {
            pCommentStrTemp[i] = pCommentStrTemp[i] - 'a' + 'A';   //to upper case, ex: Artist -> ARTIST
        }
        OGG_DBG(printf("%c", pCommentStr[i]));
    }
    OGG_DBG(printf("\n"));

    for(i = 0; i < 7; i++)
    {
        if(u32Size >= strlen(CommentFields[i].CommentField) &&
            memcmp(pCommentStrTemp, CommentFields[i].CommentField, strlen(CommentFields[i].CommentField)) == 0)
        {
            id = CommentFields[i].Ogg_CommentId;
            break;
        }
    }

    if(pCommentStrTemp!=NULL)
    {
        msAPI_Memory_Free(pCommentStrTemp,BUF_ID_FILEBROWER);
        pCommentStrTemp = NULL;
    }

    switch(id)
    {
        case OGG_TITLE:
            u32CopyLen = u32Size - strlen(CommentFields[i].CommentField) - 1;
            if(u32CopyLen > 0)
            {
                pSrc = pCommentStr + strlen(CommentFields[i].CommentField) + 1;
                pDst = stMp3Info.stID3v2.title;
                if(u32CopyLen > sizeof(stMp3Info.stID3v2.title) - 2) //include first 0x3 and end null
                {
                    u32CopyLen = sizeof(stMp3Info.stID3v2.title) - 2;
                }
                stMp3Info.stID3v2.u8TitleLength = u32CopyLen + 2; //include first 0x3 and end null
                OGG_DBG(printf("[OGG]: Title:\n"));
            }
            break;

        case OGG_VERSION:
            OGG_DBG(printf("[OGG]: Version\n"));
            break;

        case OGG_ALBUM:
            u32CopyLen = u32Size - strlen(CommentFields[i].CommentField) - 1;
            if(u32CopyLen > 0)
            {
                pSrc = pCommentStr + strlen(CommentFields[i].CommentField) + 1;
                pDst = stMp3Info.stID3v2.album;
                if(u32CopyLen > sizeof(stMp3Info.stID3v2.album) - 2) //include first 0x3 and end null
                {
                    u32CopyLen = sizeof(stMp3Info.stID3v2.album) - 2;
                }
                stMp3Info.stID3v2.u8AlbumLength = u32CopyLen + 2; //include first 0x3 and end null
                OGG_DBG(printf("[OGG]: Album:\n"));
            }
            break;

        case OGG_ARTIST:
            u32CopyLen = u32Size - strlen(CommentFields[i].CommentField) - 1;
            if(u32CopyLen > 0)
            {
                pSrc = pCommentStr + strlen(CommentFields[i].CommentField) + 1;
                pDst = stMp3Info.stID3v2.artist;
                if(u32CopyLen > sizeof(stMp3Info.stID3v2.artist) - 2) //include first 0x3 and end null
                {
                    u32CopyLen = sizeof(stMp3Info.stID3v2.artist) - 2;
                }
                stMp3Info.stID3v2.u8ArtistLength = u32CopyLen + 2; //include first 0x3 and end null
                OGG_DBG(printf("[OGG]: Artist:\n"));
            }
            break;

        case OGG_GENRE:
            OGG_DBG(printf("[OGG]: Genre:\n"));
            break;

        case OGG_DATE:
            u32CopyLen = u32Size - strlen(CommentFields[i].CommentField) - 1;
            if(u32CopyLen > 0)
            {
                pSrc = pCommentStr + strlen(CommentFields[i].CommentField) + 1;
                pDst = stMp3Info.stID3v2.year;
                if(u32CopyLen > sizeof(stMp3Info.stID3v2.year) - 2) //include first 0x3 and end null
                {
                    u32CopyLen = sizeof(stMp3Info.stID3v2.year) - 2;
                }
                OGG_DBG(printf("[OGG]: Year:\n"));
            }
            break;
        default:
            OGG_DBG(printf("[OGG]: not find matched comment field.\n"));
            break;
    }

    if (u32CopyLen != 0)
    {
        //UTF-8
        memset(pDst, 0, u32CopyLen + 2);
        pDst[0] = 0x3;
        memcpy(pDst + 1, pSrc, u32CopyLen);
        OGG_DBG(printf("[OGG]: %s\n", pDst+1));
    }
}

static BOOLEAN _MApp_Music_OggGetVorbisHeaders(void)
{
    U8 u8PacketNum = 0;
    Ogg_Page OggPage;
    U32 u32Offset = 0;
    U8* pVorbisHeader;
    U32 u32VorbisHeaderAddr = M4A_BUFFER_ADR;
    U32 u32VorbisHeaderBuffMaxSize = M4A_BUFFER_LEN + M4A_STCO_LEN;
    U32 u32tmp;

    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        OGG_ERR(printf("[OGG]: file is not opened\n"));
        return FALSE;
    }

    if(g_OggInfo.u32VorbisHeaderAddr[0] == 0)
    {
        g_OggInfo.u32VorbisHeaderAddr[0] = u32VorbisHeaderAddr;
    }

    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, 0, E_DATA_STREAM_SEEK_SET);
    while(u8PacketNum < 3)
    {
        if(_MApp_Music_OggGetNextPage(&OggPage) > 0)
        {
            U8* pSegmentTable = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)) + 27);
            U8 i = 0, u8SegmentNum = OggPage.u8SegmentNum;


            while(i < u8SegmentNum)
            {
                if((g_OggInfo.u32VorbisHeaderAddr[u8PacketNum] + u32Offset + pSegmentTable[i] -g_OggInfo.u32VorbisHeaderAddr[0]) > u32VorbisHeaderBuffMaxSize)
                {
                    OGG_ERR(printf("[OGG]: vorbis header buffer is not enough.\n"));
                    return FALSE;
                }

                if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)(g_OggInfo.u32VorbisHeaderAddr[u8PacketNum] + u32Offset), pSegmentTable[i]) > 0)
                {
                     OGG_ERR(printf("[OGG]: no data to read.\n"));
                     return FALSE;
                }
                u32Offset += pSegmentTable[i];
                if(pSegmentTable[i] < 0xFF)
                {
                    g_OggInfo.u32VorbisHeaderSize[u8PacketNum] = u32Offset;
                    OGG_DBG(printf("[OGG]: Get a Packet.\n"));
                    u8PacketNum++;
                    if(u8PacketNum >= 3)
                    {
                        break;
                    }
                    g_OggInfo.u32VorbisHeaderAddr[u8PacketNum] = g_OggInfo.u32VorbisHeaderAddr[u8PacketNum - 1]  + g_OggInfo.u32VorbisHeaderSize[u8PacketNum -1];
                    u32Offset = 0;
                }

                i++;
            }
        }
        else
        {
            return FALSE;
        }
    }

    g_OggInfo.u32VorbisFirstAudioPageOffset = msAPI_DataStreamIO_Tell(u32Mp3FileHandle);

    //check Identification header
    pVorbisHeader = (U8*)_PA2VA(g_OggInfo.u32VorbisHeaderAddr[0]);
    if(pVorbisHeader[0] != 1 || memcmp(&pVorbisHeader[1], "vorbis", 6) != 0)
    {
        OGG_ERR(printf("[OGG]: Identification header wrong.\n"));
        return FALSE;
    }

    stMp3Info.u16Channel = pVorbisHeader[11];
    u32tmp = (pVorbisHeader[20] |pVorbisHeader[21] << 8 |pVorbisHeader[22] << 16 |pVorbisHeader[23] << 24);
    if (u32tmp!=0)
        stMp3Info.u16BitRate = (U16)(u32tmp/1000);
    stMp3Info.u16SampleRate = (U16)(pVorbisHeader[12] |pVorbisHeader[13] << 8 |pVorbisHeader[14] << 16 |pVorbisHeader[15] << 24);
    OGG_INFO(printf("[OGG]: channel: 0x%x, bitrate: 0x%x, sample rate:0x%x.\n", stMp3Info.u16Channel, stMp3Info.u16BitRate, stMp3Info.u16SampleRate));

    //check Comment header
    pVorbisHeader = (U8*)_PA2VA(g_OggInfo.u32VorbisHeaderAddr[1]);
    if(pVorbisHeader[0] != 3 || memcmp(&pVorbisHeader[1], "vorbis", 6) != 0)
    {
        OGG_ERR(printf("[OGG]: Comment header wrong.\n"));
        return FALSE;
    }
    else
    {
        U32 u32Len, u32CommentListNum;
        U8* pCurrBuff = pVorbisHeader + 7;

        stMp3Info.bID3TagV2 = TRUE;

        //vendor length
        memcpy(&u32Len, pCurrBuff, 4);
        //skip vendor string
        pCurrBuff += (4 + u32Len);
        //get comment list num
        memcpy(&u32CommentListNum, pCurrBuff, 4);
        OGG_INFO(printf("[OGG]: find comment NO:%d.\n", u32CommentListNum));
        pCurrBuff += 4;
        while(u32CommentListNum-- && pCurrBuff < (pVorbisHeader + g_OggInfo.u32VorbisHeaderSize[1]))
        {
            memcpy(&u32Len, pCurrBuff, 4);
            pCurrBuff += 4;
            _MApp_Music_OggSetComment(pCurrBuff, u32Len);
            pCurrBuff += u32Len;
        }
        if(pCurrBuff[0] != 1 || pCurrBuff > (pVorbisHeader + g_OggInfo.u32VorbisHeaderSize[1]))
        {
            OGG_ERR(printf("[OGG]: parser comment error.\n"));
            //still go on
        }
    }
    //check Setup header
    pVorbisHeader = (U8*)_PA2VA(g_OggInfo.u32VorbisHeaderAddr[2]);
    if(pVorbisHeader[0] != 5 || memcmp(&pVorbisHeader[1], "vorbis", 6) != 0)
    {
        OGG_ERR(printf("[OGG]: Setup header wrong.\n"));
        return FALSE;
    }

    g_OggInfo.u32VorbisHeaderTotalSize = g_OggInfo.u32VorbisHeaderSize[0] + g_OggInfo.u32VorbisHeaderSize[1] + g_OggInfo.u32VorbisHeaderSize[2];

    OGG_DBG(printf("[OGG]: u32VorbisHeaderAddr[0], [1], [2]: %d, %d, %d\n", g_OggInfo.u32VorbisHeaderAddr[0], g_OggInfo.u32VorbisHeaderAddr[1], g_OggInfo.u32VorbisHeaderAddr[2]));
    OGG_DBG(printf("[OGG]: VorbisHeaderSize[0], [1], [2]: %d, %d, %d\n", g_OggInfo.u32VorbisHeaderSize[0], g_OggInfo.u32VorbisHeaderSize[1], g_OggInfo.u32VorbisHeaderSize[2]));
    OGG_DBG(printf("[OGG]: u32VorbisHeaderTotalSize: %d\n", g_OggInfo.u32VorbisHeaderTotalSize));
    OGG_DBG(printf("[OGG]: u32VorbisAudioPageStart: 0x%x\n", g_OggInfo.u32VorbisFirstAudioPageOffset));

    return TRUE;
}

static BOOLEAN _MApp_Music_Ogg_CollectInfo(void)
{
    BOOLEAN ret = FALSE;
    Ogg_Page OggPage;
    LongLong u64GranuPos;
    memset(&u64GranuPos,0,sizeof(LongLong));

    U32 u32Buf = ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));

    memset(&g_OggInfo, 0, sizeof(OggInfo));
    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC2);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        OGG_ERR(printf("[OGG]: Open file failed\n"));
        return FALSE;
    }

    stMp3Info.u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
    if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)u32Buf, 4) > 0)
    {
        ret = FALSE;
        goto _MApp_Music_Ogg_CollectInfo_End;
    }

    if(memcmp((void*)_PA2VA(u32Buf),"OggS",4))
    {
        ret = FALSE;
        OGG_ERR(printf("[OGG]: Not ogg file\n"));
        goto _MApp_Music_Ogg_CollectInfo_End;
    }

    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, 0, E_DATA_STREAM_SEEK_SET);
    if(_MApp_Music_OggGetNextPage(&OggPage) > 0)
    {
        g_OggInfo.u32SerialNo = OggPage.u32SerialNo;
    }
    else
    {
        ret = FALSE;
        goto _MApp_Music_Ogg_CollectInfo_End;
    }

    if(!_MApp_Music_OggGetVorbisHeaders())
    {
        ret = FALSE;
        goto _MApp_Music_Ogg_CollectInfo_End;
    }

    if ((stMp3Info.u16Channel > 2)||(stMp3Info.u16SampleRate>48000)||(stMp3Info.u16SampleRate<8000))
    {
        //not support Ogg
        //from audio team, now, ogg can support up to 2 channel and sample rate <= 48k
        ret = FALSE;
        OGG_ERR(printf("[OGG]: not support\n"));
        goto _MApp_Music_Ogg_CollectInfo_End;
    }

    if(!_MApp_Music_OggGetPrePageValidGranuPos(&u64GranuPos, msAPI_DataStreamIO_Length(u32Mp3FileHandle)))
    {
        ret = FALSE;
        OGG_DBG(printf("[OGG]: get valid granulpos fail\n"));
        goto _MApp_Music_Ogg_CollectInfo_End;
    }

    if(stMp3Info.u16SampleRate)
    {
        stMp3Info.u32Duration = (U32)u64GranuPos.Lo/stMp3Info.u16SampleRate;
    }
    OGG_INFO(printf("[OGG]: Duration:0x%x\n", stMp3Info.u32Duration));

    if ( (stMp3Info.u16BitRate==0) && (stMp3Info.u32Duration>0) )
    {
        stMp3Info.u16BitRate = (U16)stMp3Info.u32FileSize*8/stMp3Info.u32Duration/1000;
        OGG_INFO(printf("[OGG]: BitRate:0x%x\n", stMp3Info.u16BitRate));
    }

    ret = TRUE;

_MApp_Music_Ogg_CollectInfo_End:
    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
    return ret;
}

static BOOLEAN MApp_Music_OggParser_WriteDSP(U32 dwReqAddress, U32 u32ReqBytes)
{
    S32 ret = 0;
    U32 u32NeedFillDataSize = 0, u32FillAddr;
    U32 u32PacketStartAddr, u32SkipSize;

    U32 u32SeekOffset=0;
    U32 u32CurrentTime=0; //sec


    //Step 1: check if there are left bytes not written to DSP yet from previous page.
    //for goto time and FF/FB, g_OggInfo.u32LeftSizeInPage=0

    if(g_OggInfo.u32LeftSizeInPage >= u32ReqBytes)
    {
        if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)dwReqAddress, u32ReqBytes) > 0)
        {
             goto Ogg_Parser_Fail;
        }
        g_OggInfo.u32LeftSizeInPage= g_OggInfo.u32LeftSizeInPage - u32ReqBytes;
        #if OGG_PRINTDATA
        _MApp_Music_OggPrintfData( dwReqAddress, u32ReqBytes);
        #endif
        return TRUE;
    }
    else if(g_OggInfo.u32LeftSizeInPage  != 0)
    {
        if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)dwReqAddress, g_OggInfo.u32LeftSizeInPage) > 0)
        {
             goto Ogg_Parser_Fail;
        }
        u32NeedFillDataSize = u32ReqBytes - g_OggInfo.u32LeftSizeInPage;
        u32FillAddr = dwReqAddress + g_OggInfo.u32LeftSizeInPage;
        g_OggInfo.u32LeftSizeInPage = 0;
    }
    else
    {
        u32NeedFillDataSize = u32ReqBytes;
        u32FillAddr = dwReqAddress;
    }


    //Step 2 (normal play doesn't enter this part) to fix current time is not correct after FF/FB/seek
    //our goal is to find the correct(closest) page to play.
    //we search right page at least once, then search previous page.
    OggInfo g_OggTemp;
    memcpy(&g_OggTemp,&g_OggInfo,sizeof(OggInfo));

    U32 u32SeekOffsetNew = 0;
    U32 u32SeekPointA = g_OggTemp.u32VorbisFirstAudioPageOffset;
    U32 u32SeekPointB = g_OggTemp.u32VorbisLastAudioPageOffset;

    if (g_OggInfo.bSeekToCurrentTime==TRUE)
    {
        if(stMp3Info.u32CurrentPlayTime==0)
        {
            u32SeekOffset = g_OggInfo.u32VorbisFirstAudioPageOffset;
        }
        else if(stMp3Info.u32CurrentPlayTime>=(stMp3Info.u32Duration*1000))
        {
            u32SeekOffset = g_OggInfo.u32VorbisLastAudioPageOffset;
        }
        else if(stMp3Info.u16SampleRate>0)
        {
            while(1)   //use binary search to find closest page
            {
                u32CurrentTime = g_OggTemp.CurrentPage.u64Granulepos.Lo/stMp3Info.u16SampleRate;
                u32SeekOffset = g_OggTemp.CurrentPage.u32PageHeaderOffset;

                if(u32CurrentTime > (stMp3Info.u32CurrentPlayTime/1000))
                {
                    u32SeekPointB = u32SeekOffset;
                }
                else if(u32CurrentTime < (stMp3Info.u32CurrentPlayTime/1000))
                {
                    u32SeekPointA = u32SeekOffset;
                }
                else
                {
                    OGG_DBG2(printf("found correct page   u32SeekOffset:0x%x\n",u32SeekOffset));
                    break;
                }

                if(u32SeekPointA==u32SeekPointB)
                {
                    u32SeekOffset = u32SeekPointA;
                    OGG_DBG2(printf("u32SeekPointA equals u32SeekPointB, u32SeekPointA:0x%x\n",u32SeekPointA));
                    break;
                }

                u32SeekOffsetNew = (u32SeekPointA + u32SeekPointB)/2;
                if(u32SeekOffsetNew > g_OggInfo.u32VorbisLastAudioPageOffset)
                {
                    u32SeekOffsetNew = g_OggInfo.u32VorbisLastAudioPageOffset;
                }
                else if(u32SeekOffsetNew < g_OggInfo.u32VorbisFirstAudioPageOffset)
                {
                    u32SeekOffsetNew = g_OggInfo.u32VorbisFirstAudioPageOffset;
                }

                OGG_DBG2(printf("u32SeekOffset:0x%x  u32SeekPointA:0x%x  u32SeekPointB:0x%x u32SeekOffsetNew:0x%x  u32CurrentTime:%d  stMp3Info.u32CurrentPlayTime:%d\n",u32SeekOffset,u32SeekPointA,u32SeekPointB,u32SeekOffsetNew,u32CurrentTime,stMp3Info.u32CurrentPlayTime));
                msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32SeekOffsetNew, E_DATA_STREAM_SEEK_SET);
                _MApp_Music_OggGetNextPage(&g_OggTemp.CurrentPage);

                //we don't have such test patterns yet. but we write this code anyway to avoid endless while loop.
                if(g_OggTemp.CurrentPage.u32PageHeaderOffset == u32SeekPointB)
                {
                    OGG_DBG2(printf("u32SeekOffsetNew next page is u32SeekPointB, start search from pointA. u32SeekPointA:0x%x  u32SeekPointB:0x%x\n",u32SeekPointA,u32SeekPointB));

                    u32SeekOffset = u32SeekPointA;

                    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32SeekOffset, E_DATA_STREAM_SEEK_SET);

                    while(u32SeekOffset<u32SeekOffsetNew)
                    {
                        //_MApp_Music_OggGetNextPage will read OGG page header.
                        //The file position will change after _MApp_Music_OggGetNextPage
                        //Thus, we do not use to seek to u32SeekOffset again, or it will cause infinite loop
                        _MApp_Music_OggGetNextPage(&g_OggTemp.CurrentPage);

                        u32CurrentTime = g_OggTemp.CurrentPage.u64Granulepos.Lo/stMp3Info.u16SampleRate;
                        u32SeekOffset = g_OggTemp.CurrentPage.u32PageHeaderOffset;

                        if(u32CurrentTime >= (stMp3Info.u32CurrentPlayTime/1000))
                        {
                           OGG_DBG2(printf("stop search at forloop. u32SeekOffset:0x%x\n",u32SeekOffset));
                           break;    //break for loop
                        }
                    }
                    OGG_DBG2(printf("final u32SeekOffset:0x%x\n",u32SeekOffset));
                    break;  //break while(1)
                }
            }//end of while (1)
        }
        else
        {
           OGG_DBG2(printf("[OGG]: sample rate error: %lu\n",stMp3Info.u16SampleRate));
           goto Ogg_Parser_Fail;
        }

        g_OggInfo.bEndofFile = FALSE;   //Fix bug:  FB at file end will goto file end and not FB.
        g_OggInfo.bSeekToCurrentTime=FALSE;
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32SeekOffset, E_DATA_STREAM_SEEK_SET);
    }


    //Step 3: if DSP buffer is not full, try to make it full
    while(u32NeedFillDataSize)
    {
        u32PacketStartAddr = 0;
        u32SkipSize = 0;
        ret = _MApp_Music_OggGetNextPage(&g_OggInfo.CurrentPage);

        if(ret < 0)
        {
            OGG_ERR(printf("[OGG]: get next page fail.\n"));
            goto Ogg_Parser_Fail;
        }
        else if(ret == 0)
        {
            OGG_INFO(printf("[OGG]: end of file.\n"));
            g_OggInfo.bEndofFile = TRUE;
            g_OggInfo.u32LeftDataToFill = u32NeedFillDataSize;
            // if we don't have enough data asked by DSP, we have to clear the buffer first or garbage will be left
            msAPI_Music_CleanFileEndData(u32FillAddr, u32NeedFillDataSize, 0x1UL);   //audio team suggest fill it with 0x1
            //memset((void*)_PA2VA(u32FillAddr), 0, u32NeedFillDataSize);
            return(TRUE);
        }
        else if(ret > 0)
        {
            OGG_DBG(printf("[OGG]: Get a page.\n"));
            if(g_OggInfo.CurrentPage.u32PageNo < g_OggInfo.u32CurrPageIndex)
            {
                OGG_DBG(printf("[OGG]: Page NO wrong.\n"));
                //goto Ogg_Parser_Fail;
                //still send to dsp?
                g_OggInfo.u32CurrPageIndex = g_OggInfo.CurrentPage.u32PageNo;
            }

            g_OggInfo.u32CurrPageIndex++;
            if(g_OggInfo.CurrentPage.u32SerialNo != g_OggInfo.u32SerialNo)
            {
                OGG_ERR(printf("[OGG]: Serialno is not matched. Skip this page\n"));
                msAPI_DataStreamIO_Seek(u32Mp3FileHandle, g_OggInfo.CurrentPage.u32PageBodyOffset + g_OggInfo.CurrentPage.u32BodyLen, E_DATA_STREAM_SEEK_SET);
                continue;
            }
                    }

        if(g_OggInfo.bInputFromPacketStart)
        {
            if(_MApp_Music_OggGetPacketStartInPage(&g_OggInfo.CurrentPage, &u32PacketStartAddr, &u32SkipSize) == TRUE)
            {
                msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32PacketStartAddr, E_DATA_STREAM_SEEK_SET);
            }
            else
            {
                msAPI_DataStreamIO_Seek(u32Mp3FileHandle, g_OggInfo.CurrentPage.u32PageBodyOffset + g_OggInfo.CurrentPage.u32BodyLen, E_DATA_STREAM_SEEK_SET);
                continue;
            }
        }
        if((g_OggInfo.CurrentPage.u32BodyLen - u32SkipSize) <= u32NeedFillDataSize)
        {
            //data is not enough, need parser more page.
            if(msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)u32FillAddr, (g_OggInfo.CurrentPage.u32BodyLen - u32SkipSize)) > 0)
            {
                 goto Ogg_Parser_Fail;
            }
            u32NeedFillDataSize -= (g_OggInfo.CurrentPage.u32BodyLen - u32SkipSize);
            u32FillAddr += (g_OggInfo.CurrentPage.u32BodyLen - u32SkipSize);
            g_OggInfo.u32LeftSizeInPage = 0;
        }
        else
        {
            //data is enough, finish input data.
            if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)u32FillAddr, u32NeedFillDataSize) > 0)
            {
                 goto Ogg_Parser_Fail;
            }
            g_OggInfo.u32LeftSizeInPage = g_OggInfo.CurrentPage.u32BodyLen  - u32SkipSize - u32NeedFillDataSize;
            u32NeedFillDataSize = 0;
        }

    }
    #if OGG_PRINTDATA
    _MApp_Music_OggPrintfData( dwReqAddress, u32ReqBytes);
    #endif
    return TRUE;

Ogg_Parser_Fail:

    return FALSE;
}

static BOOLEAN _MApp_Music_OggTimeOffset(U32 u32GotoTimeMs)
{
    U32 u32AudioLength = 0;
    U32 u32Offset = 0;

#if 0
    u32AudioLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle) - g_OggInfo.u32VorbisHeaderTotalSize;
    u32Offset = ((u32AudioLength/stMp3Info.u32Duration)*u32GotoTimeMs)/1000 + g_OggInfo.u32VorbisHeaderTotalSize;
#else
    u32AudioLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle) - g_OggInfo.u32VorbisFirstAudioPageOffset;
    u32Offset = ((u32AudioLength/stMp3Info.u32Duration)*u32GotoTimeMs)/1000 + g_OggInfo.u32VorbisFirstAudioPageOffset;
#endif
    g_OggInfo.bNeedAddHeader = TRUE;
    g_OggInfo.u32VorbisHeaderLeftSizeToWrite = g_OggInfo.u32VorbisHeaderTotalSize;
    g_OggInfo.u32LeftSizeInPage = 0;
    g_OggInfo.bInputFromPacketStart = TRUE;
    g_OggInfo.bSeekToCurrentTime = TRUE;

    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    return TRUE;
}
#endif

#endif
#if 0
void MApp_Music_DrawEQ(void)
{
    U8 i, j;
    U8 u8Threshold;
    U8 u8PrevGwinID;
    U16 u16Height;
    static U8 u8Cntr=0;

    u8Cntr++;
    if(u8Cntr%5)
        return;

    if(enMp3PlayStatus != MP3_STATUS_PLAYING)
        return;

    u8PrevGwinID = MApi_GOP_GWIN_GetCurrentWinId();
    MApi_GOP_GWIN_Switch2Gwin(u8MainOSDWinId);

    MApp_UiMenu_DrawMusicEQ_DblBufOn();
    MApp_UiMenu_DrawMusicEQ(UI_MEDIA_PLAYER_MP3_EQ_BAR_X,
                            UI_MEDIA_PLAYER_MP3_EQ_BAR_Y,
                            ((UI_MEDIA_PLAYER_MP3_EQ_BAR_W+10)*UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM),
                            UI_MEDIA_PLAYER_MP3_EQ_BAR_H*3/2, EN_COLOR_BLACK);

    for(i=0;i<UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM;i++)
    {
        if(i<UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM/3)
        {
            u8Threshold = 40 + i*10;
        }
        else if(i > UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM*2/3)
        {
            u8Threshold = 30+(UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM-i)*10;
        }
        else
        {
            u8Threshold = 120;
        }

        srand(msAPI_Timer_GetTime0());
        u16Height = (U16)((U16)rand() % u8Threshold);

        if((i<(UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM/3)) || (i>(UI_MEDIA_PLAYER_MP3_EQ_BAR_NUM*2/3)))
        {
            u16Height = (U16)UI_MEDIA_PLAYER_MP3_EQ_BAR_H*3/4 - u16Height - 45;
        }
        else
        {
            u16Height = (U16)UI_MEDIA_PLAYER_MP3_EQ_BAR_H*3/4 - u16Height + 30;
        }

        u16Height = u16Height/15;

        for(j=0;j<u16Height;j++)
        {
            MApp_UiMenu_DrawMusicEQ(UI_MEDIA_PLAYER_MP3_EQ_BAR_X+i*(UI_MEDIA_PLAYER_MP3_EQ_BAR_W+10),
                UI_MEDIA_PLAYER_MP3_EQ_BAR_Y+UI_MEDIA_PLAYER_MP3_EQ_BAR_H-j*15,
                UI_MEDIA_PLAYER_MP3_EQ_BAR_W, 10, EN_COLOR_RED);
        }
    }
    MApp_UiMenu_DblBufOff();
    MApi_GOP_GWIN_Switch2Gwin(u8PrevGwinID);

}
#endif

#if (ENABLE_AMR)

//A table of contents(ToC) entry takes the following format in octet-aligned mode:
//
//0 1 2 3 4 5 6 7
//+-+-+-+-+-+-+-+-+
//|F|  FT   |Q|P|P|
//+-+-+-+-+-+-+-+-+
//
//F (1 bit): If set to 1, indicates that this frame is followed by
//another speech frame in this payload; if set to 0, indicates that
//this frame is the last frame in this payload.
//
//FT (4 bits unsigned integer): Frame type index, indicating either the AMR or AMR-WB
//speech coding mode or comfort noise (SID) mode of the
//corresponding frame carried in this payload.
//
//Q (1 bit): Frame quality indicator.  If set to 0, indicates the
//corresponding frame is severely damaged and the receiver should
//set the RX_TYPE (see [6]) to either SPEECH_BAD or SID_BAD
//depending on the frame type (FT).
//
// P bits: padding bits, MUST be set to zero.

//******************************************************************************
/// Count AMR file total frame numbers and save every second frame address to create a lookup table in the memory.
/// @param  u32Buf \b IN  file read buffer address.
/// @param  u32BufLen  \b IN file read buffer size.
/// @return u32Duration: file duration in second unit
//******************************************************************************
static U32 _MApp_Music_AMRGetDurationAndFrameIdxTable(U32 u32Buf , U32 u32BufLen)
{
    U32 u32Duration = 0;
    U32 u32FileReadPosition = 0, u32FileBufIdx = 0, u32FileProcessIdx = 0;
    U8 u8ToC = '\0';
    U32 u32FrameCount = 0, u32FrameSave_Count = 0, u32FrameIdxSave = 0;
    U8 u8ft = 0;
    BOOLEAN bReadFile = FALSE, bDispOverflowMsg = TRUE;
    U32 u32TimeLimit = 0;

    U32 *pu32AMRFrame = (U32 *)(_PA2VA(u32AMRFrameAddr));

    if ( m_AMRInfo.bAMR_NB )
    {
        pu8AMRPackedSize = NBpacked_size;
    }
    else
    {
        pu8AMRPackedSize = WBpacked_size;
    }

    u32FileReadPosition += m_AMRInfo.u8HeaderSize;
    u32FileProcessIdx = u32FileReadPosition;

    pu32AMRFrame[u32FrameIdxSave++] = u32FileProcessIdx;

#if 1
// Complex algorithm, handle buffer by itself, but better execution performance
    msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32FileReadPosition, E_DATA_STREAM_SEEK_SET);
    bReadFile = TRUE;

    u32AMR_Frame_Buf_Total_Count = (M4A_STCO_LEN/sizeof(unsigned long));
    u32TimeLimit = msAPI_Timer_GetTime0();

    while(u32FileProcessIdx < stMp3Info.u32FileSize)
    {
        if (msAPI_Timer_DiffTimeFromNow(u32TimeLimit) > AMR_CREATE_INDEX_TABLE_TIME_OUT) // total sequence can't exceed 5 sec
        {
            //This is time out case
            //For remain frames, we will use previous frame size (the last known frame size) as remain frame sizes.
            //This is because some AMR converter tools only create AMR streams with all the same frame size. The value will not vary in the whole stream.
            //Base on the above assumption, we calculate total frame numbers with below formula.
            u32AMR_Frame_Buf_Total_Count = u32FrameIdxSave;
            u32FrameCount += ( (stMp3Info.u32FileSize - u32FileProcessIdx) / (pu8AMRPackedSize[u8ft]+AMR_TOC_LEN) );
            printf("AMR Create Index Table Time Out\n");
            break;
        }

#if ( WATCH_DOG == ENABLE )
        msAPI_Timer_ResetWDT();
#endif

        if ( bReadFile )
        {
            if ((u32FileReadPosition+u32BufLen) < stMp3Info.u32FileSize)
            {
                if ( msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void *)u32Buf, u32BufLen) > 0 )
                {
                    break;
                }
                else
                {
                    u32FileReadPosition += u32BufLen;
                }
            }
            else
            {
                if ( msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void *)u32Buf, (stMp3Info.u32FileSize-u32FileReadPosition)) > 0 )
                {
                    break;
                }
                u32FileReadPosition = stMp3Info.u32FileSize;
            }
            bReadFile = FALSE;
        }

        u8ToC = *((U8 *)_PA2VA(u32Buf)+u32FileBufIdx);

        u8ft = (u8ToC >> 3) & 0x0F;

        u32FileBufIdx += (pu8AMRPackedSize[u8ft] + AMR_TOC_LEN);
        u32FileProcessIdx += (pu8AMRPackedSize[u8ft] + AMR_TOC_LEN);

        u32FrameSave_Count++;
        //One second one index in AMR frame index buffer
        if ( u32FrameSave_Count > AMR_FRAME_NUMBER_PER_SEC )
        {
            if ( (u32FrameIdxSave+1) <= u32AMR_Frame_Buf_Total_Count )
            {
                //save frame position
                pu32AMRFrame[u32FrameIdxSave++] = u32FileProcessIdx;
            }
            else
            {
                if ( bDispOverflowMsg )
                {
                    printf("AMR Index buffer overflow\n");
                    bDispOverflowMsg = FALSE;
                }
            }
            u32FrameSave_Count -= AMR_FRAME_NUMBER_PER_SEC;
        }

        u32FrameCount++;

        if ( u32FileBufIdx >= u32BufLen )
        {
            bReadFile = TRUE;
            u32FileBufIdx -= u32BufLen;
        }
    }
#else
//Simple algorithm, direct file content operation, but lower performance without file cache architecture
    while (u32FileReadPosition < stMp3Info.u32FileSize)
    {
        msAPI_DataStreamIO_Seek(u32Mp3FileHandle, u32FileReadPosition, E_DATA_STREAM_SEEK_SET);
        if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void *)u32Buf, 1) > 0)
        {
            break;
        }
        u8ToC = *((U8 *)_PA2VA(u32Buf));

        u8ft = (u8ToC >> 3) & 0x0F;

        u32FileReadPosition += (pu8AMRPackedSize[u8ft] + AMR_TOC_LEN);

        u32FrameCount++;
    }
#endif

    u32Duration = u32FrameCount * AMR_ONE_FRAME_DURATION_IN_MS / 1000;

    return u32Duration;
}

//******************************************************************************
/// Collect AMR file various information.
/// @param  void
/// @return TRUE: Success , FALSE: FAIL
//******************************************************************************
static BOOLEAN _MApp_Music_AMR_CollectInfo(void)
{
    BOOLEAN bRet = FALSE;
    U32 u32Buf = ((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR));

    memset(&m_AMRInfo, 0, sizeof(ST_AMR_INFO));
    u32Mp3FileHandle = msAPI_DataStreamIO_Open(m_pMp3FileEntry, OPEN_MODE_FOR_READ,E_DATA_STREAM_TYPE_MUSIC);
    if(u32Mp3FileHandle == INVALID_DATA_STREAM_HDL)
    {
        AMR_ERR(printf("[AMR]: Open file failed\n"));
        return FALSE;
    }

    stMp3Info.u32FileSize = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
    stMp3Info.u32MusicDataBytesLeft = stMp3Info.u32FileSize;
    stMp3Info.u16BitRate = 0;
    stMp3Info.u16SampleRate = 0;
    stMp3Info.bID3TagV1 = FALSE;
    stMp3Info.bID3TagV2 = FALSE;

    m_AMRInfo.u8HeaderSize = 0;

    memset((void *)_PA2VA(u32Buf), 0, AMR_WB_HEADER_LEN);
    //NB and WB condition
    if(msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void*)u32Buf, AMR_WB_HEADER_LEN) > 0)
    {
        AMR_ERR(printf("[AMR]: AMR File Read Err\n"));
    }

    //WB condiition
    if(memcmp((void*)_PA2VA(u32Buf),"#!AMR-WB\n", AMR_WB_HEADER_LEN) == 0)
    {
        m_AMRInfo.bAMR_NB = FALSE;
        m_AMRInfo.u8HeaderSize = AMR_WB_HEADER_LEN;
        stMp3Info.u16SampleRate = 16000;
    }
    //NB condition
    else if(memcmp((void*)_PA2VA(u32Buf),"#!AMR\n", AMR_NB_HEADER_LEN) == 0)
    {
        m_AMRInfo.bAMR_NB = TRUE;
        m_AMRInfo.u8HeaderSize = AMR_NB_HEADER_LEN;
        stMp3Info.u16SampleRate = 8000;
    }
    else
    {
        bRet = FALSE;
        AMR_ERR(printf("[AMR]: Not AMR file\n"));
        goto _MApp_Music_AMR_CollectInfo_End;
    }

    stMp3Info.u32Duration = _MApp_Music_AMRGetDurationAndFrameIdxTable(u32Buf, AMR_FILEREAD_BUF_LEN);

    stMp3Info.u16BitRate = (stMp3Info.u32FileSize - m_AMRInfo.u8HeaderSize)*8 / (stMp3Info.u32Duration*1000);

    bRet = TRUE;

_MApp_Music_AMR_CollectInfo_End:
    msAPI_DataStreamIO_Close(u32Mp3FileHandle);
    u32Mp3FileHandle = INVALID_DATA_STREAM_HDL;
    return bRet;
}
#endif

static U8 u8String[6];
U8 *MApp_Music_GetInfoString(EN_MP3_INFO enInfo)
{
    U16 u16Tmp;
    U8* u8Ptr = u8String;

    memset(u8Ptr,0,2);
    switch(enInfo)
    {
        case MP3_INFO_LAYER:
        case MP3_INFO_BITRATE:
            u16Tmp = (U16)(stMp3Info.u16BitRate);
            snprintf((char*)u8String, 5, "%dK", u16Tmp);
            u8Ptr = (U8*)u8String;
            break;
        case MP3_INFO_SAMPLINGRATE:
            u16Tmp = (U16)(stMp3Info.u16SampleRate/1000);
            snprintf((char*)u8String, 5, "%dK", u16Tmp);
            u8Ptr = (U8*)u8String;
            break;
        case MP3_INFO_ALBUM:
            if((stMp3Info.bID3TagV2 == TRUE) && (stMp3Info.stID3v2.u8AlbumLength >= stMp3Info.stID3v1.u8AlbumLength))
            {
                u8Ptr = (U8*)stMp3Info.stID3v2.album;
            }
            else if(stMp3Info.bID3TagV1 == TRUE)
            {
                u8Ptr = (U8*)stMp3Info.stID3v1.album;
            }
            break;
        case MP3_INFO_TITLE:
            if((stMp3Info.bID3TagV2 == TRUE) && (stMp3Info.stID3v2.u8TitleLength >= stMp3Info.stID3v1.u8TitleLength))
            {
                u8Ptr = (U8*)stMp3Info.stID3v2.title;
            }
            else if(stMp3Info.bID3TagV1 == TRUE)
            {
                u8Ptr = (U8*)stMp3Info.stID3v1.title;
            }
            break;
        case MP3_INFO_ARTIST:
            if((stMp3Info.bID3TagV2 == TRUE) && (stMp3Info.stID3v2.u8ArtistLength >= stMp3Info.stID3v1.u8ArtistLength))
            {
                u8Ptr = (U8*)stMp3Info.stID3v2.artist;
            }
            else if(stMp3Info.bID3TagV1 == TRUE)
            {
                u8Ptr = (U8*)stMp3Info.stID3v1.artist;
            }
            break;
        case MP3_INFO_YEAR:
            if(stMp3Info.bID3TagV2 == TRUE)
            {
                u8Ptr = (U8*)stMp3Info.stID3v2.year;
            }
            else if(stMp3Info.bID3TagV1 == TRUE)
            {
                u8Ptr = (U8*)stMp3Info.stID3v1.year;
            }
            break;
        case MP3_INFO_GENRE:
            if((stMp3Info.bID3TagV2 == TRUE) && (stMp3Info.stID3v2.u8GenreLength > 0))
            {
                //Detect if there is special string in GenreStr.
                //If we find it, replace it to predefined Genre string.
                msAPI_Music_ReMapGenreStr(stMp3Info.stID3v2.GenreStr, &stMp3Info.stID3v2.u8GenreLength);
                u8Ptr = (U8*)stMp3Info.stID3v2.GenreStr;
            }
            else if((stMp3Info.bID3TagV1 == TRUE) && (stMp3Info.stID3v1.u8GenreLength > 0))
            {
                //Detect if there is special string in GenreStr.
                //If we find it, replace it to predefined Genre string.
                msAPI_Music_ReMapGenreStr(stMp3Info.stID3v1.GenreStr, &stMp3Info.stID3v1.u8GenreLength);
                u8Ptr = (U8*)stMp3Info.stID3v1.GenreStr;
            }
            break;
        case MP3_INFO_COMMENT:
        case MP3_INFO_CHECK_FF_FB:
            u8Ptr = (U8*)&stMp3Info.bCheckFfFb;
        default:
            break;
    }

    return u8Ptr;
}

U8 MApp_Music_GetInfoStringLength(EN_MP3_INFO enInfo)
{
    switch(enInfo)
    {
        case MP3_INFO_ALBUM:
            if(stMp3Info.stID3v2.u8AlbumLength > MP3_TAG_ID3v1_LENGTH)
            {
                return stMp3Info.stID3v2.u8AlbumLength;
            }
            else
            {
                return 32;
            }
            break;
        case MP3_INFO_TITLE:
            if(stMp3Info.stID3v2.u8TitleLength > MP3_TAG_ID3v1_LENGTH)
            {
                return stMp3Info.stID3v2.u8TitleLength;
            }
            else
            {
                return 32;
            }
            break;
        case MP3_INFO_COMMENT:
            if(stMp3Info.bID3TagV2)
            {
                return MP3_INFO_LENGTH;
            }
            else
            {
                return 32;
            }
            break;
        case MP3_INFO_ARTIST:
            if(stMp3Info.stID3v2.u8ArtistLength > MP3_TAG_ID3v1_LENGTH)
            {
                return stMp3Info.stID3v2.u8ArtistLength;
            }
            else
            {
                return 32;
            }
            break;
        case MP3_INFO_YEAR:
            if(stMp3Info.bID3TagV2)
            {
                return MP3_INFO_YEAR_LENGTH;
            }
            else
            {
                return 6;
            }
            break;
        case MP3_INFO_GENRE:
            if((stMp3Info.bID3TagV2 == TRUE) && (stMp3Info.stID3v2.u8GenreLength > 0))
            {
                //Detect if there is special string in GenreStr.
                //If we find it, replace it to predefined Genre string.
                msAPI_Music_ReMapGenreStr(stMp3Info.stID3v2.GenreStr, &stMp3Info.stID3v2.u8GenreLength);
                return stMp3Info.stID3v2.u8GenreLength;
            }
            else if((stMp3Info.bID3TagV1 == TRUE) && (stMp3Info.stID3v1.u8GenreLength > 0))
            {
                //Detect if there is special string in GenreStr.
                //If we find it, replace it to predefined Genre string.
                msAPI_Music_ReMapGenreStr(stMp3Info.stID3v1.GenreStr, &stMp3Info.stID3v1.u8GenreLength);
                return stMp3Info.stID3v1.u8GenreLength;
            }
            break;

        default:
            return 0;
            break;
    }

    return 0;
}

#if 0
void MApp_Music_KeySoundEffect_Initial(void)
{
//    MS_SYS_INFO mp3SystemInfo;
    BOOLEAN bResult;

    msAPI_Music_Init(MSAPI_AUD_DVB_MP3);

    KeySoundBinInfo.B_ID = BIN_ID_OSDCP_SOUND;

    msAPI_MIU_Get_BinInfo(&KeySoundBinInfo, &bResult);
    if (bResult != PASS )
    {
        MUSIC_DBG(printf("Audio: could not find MP3 file on flash.\n");)
        return;
    }
    msAPI_Music_StopDecode();

    if(stSystemInfo.enInputSourceType!=INPUT_SOURCE_STORAGE)
    {
//        mp3SystemInfo.enInputSourceType=INPUT_SOURCE_STORAGE;
//        msAPI_Scaler_SetInputSoundSource(&mp3SystemInfo);
        MApp_InputSource_ChangeAudioSource( INPUT_SOURCE_STORAGE );
    }

}

void MApp_Music_KeySoundEffect_Play(void)
{
    U32 u32FlashStart,u32ReqAddr,u32ReqBytes;
    U8 *nonData;

    msAPI_Music_StartDecode();
    //After msAPI_Music_StartDecode() , set 20 ms delay to be sure "msAPI_Music_CheckInputRequest()" works.
    msAPI_Timer_Delayms(20);

    u32FlashStart=KeySoundBinInfo.B_FAddr;
    while(1)
    {
        if ((msAPI_Music_CheckInputRequest(&u32ReqAddr, &u32ReqBytes) == FALSE))
        {
            MUSIC_DBG(printf("msAPI_Music_CheckInputRequest error.\n");)
            MApp_Music_KeySoundEffect_Initial();
            return;
        }
        else
        {
            if(KeySoundBinInfo.B_Len<u32ReqBytes)
            {
                nonData=msAPI_Memory_Allocate(u32ReqBytes, BUF_ID_FILEBROWER);
                memset(nonData,0,u32ReqBytes);
                msAPI_MIU_Copy(u32FlashStart, (U32)nonData, MemAlign(KeySoundBinInfo.B_Len,1024), MIU_FLASH2SDRAM);
                msAPI_MIU_Copy((U32)nonData, u32ReqAddr, u32ReqBytes, MIU_SDRAM2SDRAM);
                msAPI_Memory_Free(nonData, BUF_ID_FILEBROWER);
            }
            else
            {
                msAPI_MIU_Copy(u32FlashStart, u32ReqAddr, u32ReqBytes, MIU_FLASH2SDRAM);
            }
            MUSIC_DBG(printf("\naddr=0x%08LX , len=0x%08LX , u32FlashStart=0x%08LX \n", u32ReqAddr, u32ReqBytes, u32FlashStart);)
            msAPI_Music_SetInput();
            u32FlashStart +=u32ReqBytes;
            if(u32FlashStart-KeySoundBinInfo.B_FAddr>=KeySoundBinInfo.B_Len)
            {
                break;
            }
        }
    }

    while(!msAPI_Music_CheckPlayDone())
    {
        msAPI_Music_FileEndNotification();
    }

}

void MApp_Music_KeySoundEffect_Exit(void)
{

    if(stSystemInfo.enInputSourceType!=INPUT_SOURCE_STORAGE)
    {
//        if(stSystemInfo.enInputSourceType!=INPUT_SOURCE_STORAGE)
//        {
//            MApi_AUDIO_SifSetSystem( GetSoundSystemFlag(AUDIO_STD_MASK) | AU_SYS_HI_DEV);
//        }
//        msAPI_Scaler_SetInputSoundSource(&stSystemInfo);
        MApp_InputSource_ChangeAudioSource( stSystemInfo.enInputSourceType );
    }
}
#endif

static BOOLEAN _MApp_Music_MP3TimeOffset(U32 u32GotoTimeMs)
{
    U32 u32AudioLength = 0;
    U32 u32Offset = 0;
    U16 u16ReadSize;
    U16 u16Mp3HeaderOffset=0;
    U8 *pFileBufPtr;

    u32AudioLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle) - stMp3Info.u32ID3TagV2Size - stMp3Info.u16ID3TagV1Size;
    if((stMp3Info.u8Flag & MP3_FLAG_VBR_XING) && (stMp3Info.u16TOCLength>0))
    {
        U32 u32TOCIdx = u32GotoTimeMs / stMp3Info.u32Duration;
        if(u32TOCIdx >= 1000)
        {
            u32Offset = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        }
        else
        {
            u32Offset = stMp3Info.u32ID3TagV2Size + ((unsigned long long)u32AudioLength * stMp3Info.u8TOC[u32TOCIdx/10] / 256);
        }

    }
    else
    {
        //u32Offset = stMp3Info.u32ID3TagV2Size + (((u32AudioLength/stMp3Info.u32Duration)*(u32GotoTimeMs))/1000);
        u32Offset = stMp3Info.u32ID3TagV2Size + ((u32AudioLength/stMp3Info.u32Duration)*(u32GotoTimeMs/1000));
    }

    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    u16ReadSize = MP3_INFO_READ_LEN - msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);
    pFileBufPtr = (U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));


    u16Mp3HeaderOffset = 0;
    while((!(pFileBufPtr[u16Mp3HeaderOffset] == 0xff &&
            (pFileBufPtr[u16Mp3HeaderOffset+1] & 0xe0) == 0xe0))
        &&((u16Mp3HeaderOffset) < (u16ReadSize-1)))
    {
        u16Mp3HeaderOffset++;
    }
    u32Offset += u16Mp3HeaderOffset;
    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    return TRUE;
}

#if (ENABLE_AAC)
static BOOLEAN _MApp_Music_AACTimeOffset(U32 u32GotoTimeMs)
{
    U32 u32FileLength = 0;
    U32 u32Offset = 0;
    U16 u16ReadSize;
    U8 *pFileBufPtr;
    U16 i;

    //AAC
    if(MApp_Music_IsAAC() && !stM4aInfo.bFoundmdat)
    {
        u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
        u32Offset = (u32FileLength-AACID3Jump)/stMp3Info.u32Duration;
        if (u32Offset == 0)
        {
            u32Offset = AACID3Jump + (((u32FileLength-AACID3Jump)*u32GotoTimeMs)/(stMp3Info.u32Duration*1000));
        }
        else if (u32GotoTimeMs > ((0xFFFFFFFFUL)/u32Offset))
        {
            u32Offset = AACID3Jump + (u32Offset*(u32GotoTimeMs/1000));
        }
        else
        {
            u32Offset = AACID3Jump + ((u32Offset*u32GotoTimeMs)/1000);
        }

        if (u32Offset > u32FileLength)
        {
            u32Offset = u32FileLength;
        }

        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);

        MUSIC_DBG(printf("AAC u32FileSize=%lx u32FilePosition=%lx\n",u32FileLength,u32Offset));

        //AP level AAC header pasing!
        u16ReadSize = MP3_INFO_READ_LEN - msAPI_DataStreamIO_Read(u32Mp3FileHandle, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);

        pFileBufPtr = (U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

        for(i=0;i<(u16ReadSize - 1);i++)
        {
            if( (pFileBufPtr[i] == 0xff) &&
                 ((pFileBufPtr[i+1] & 0xf0) == 0xf0) &&
                 (((pFileBufPtr[i+1]>>1) & 0x03) == 0x00))
            {
                MUSIC_DBG(printf("%bX %bX %bX %bX %bX %bX %bX \n",pFileBufPtr[i],pFileBufPtr[i+1],pFileBufPtr[i+2],pFileBufPtr[i+3],pFileBufPtr[i+4],pFileBufPtr[i+5],pFileBufPtr[i+6]));
                break;
            }
        }

        u32Offset += i;
        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);

    }
    else   //M4A
    {
        if(_bM4aEnableFFFB)
        {
            if(stM4aInfo.bFoundstsz && stM4aInfo.bFoundstsc && stM4aInfo.u32stscSize>0)
            {
                bM4aRelocateFilePosition = TRUE;
                _u32ADTSWriteLeft=0;
                memset(_pu8ADTSHeader,0,8);
                //printf("Go to time:%lu total time:%lu\n",u32GotoTimeMs,stMp3Info.u32Duration);

                _u32StszCurrentFrame = ((u32GotoTimeMs/1000)*(U32)stMp3Info.u16SampleRate)/1024;   //ADTS: 1024 samples per frame.
                //printf("StszCurrentFrame:%lu\n",_u32StszCurrentFrame);

                stMp3Info.u32CurrentPlayTime =(U32)((U64)_u32StszCurrentFrame*1024* 1000/((U64)stMp3Info.u16SampleRate)) ;  //ADTS: 1024 samples per frame.
                u32M4aTimeTemp = stMp3Info.u32CurrentPlayTime;
                u32MaxCurrentTimeTemp = u32M4aTimeTemp;
            }
        }
    }

    return TRUE;
}
#endif

#if (ENABLE_WAV)
static BOOLEAN _MApp_Music_WAVTimeOffset(U32 u32GotoTimeMs)
{
    U32 u32FileLength = 0;
    U32 u32Offset = 0;

    u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);

    u32Offset = ((u32GotoTimeMs/1000) * stWavChunk.u32AvgBytesPerSec);

    if((stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM) || (stWavChunk.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM))
    {
        u32Offset = (u32Offset/stWavChunk.u16BlockSize)*stWavChunk.u16BlockSize;
    }
    u32Offset += (U32)stWavChunk.u32HeaderSize;

    if(u32Offset > u32FileLength)
    {
        u32Offset = u32FileLength;
    }
    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    stMp3Info.u32MusicDataBytesLeft = (u32FileLength - u32Offset);
    //printf("WAVTimeOffset u32FileLength:0x%lx u32Offset:0x%lx\n",u32FileLength,u32Offset);

    return TRUE;
}
#endif

#if (ENABLE_FLAC)
U64 MApp_Music_GetFlacSampleIndex(U32 u32KeyIndex)
{

    ST_FLAC_SEEK_TABLE *pstEntry;

    if(u32KeyIndex < m_stFlacInfo.u32SeekEntryCount)
    {
        pstEntry = m_stFlacInfo.pstSeekTable + u32KeyIndex;
        return pstEntry->u64SampleNum;
    }
    else
    {
        FLAC_ERR(printf("u32KeyIndex is wrong.\n "));
        return 0;
    }
}



//******************************************************************************
/// Calculate FLAC time offset in file position.
/// @param  u32GotoTimeMs \b IN  time offset in ms unit.
/// @return TRUE: Success , FALSE: FAIL
//******************************************************************************
static BOOLEAN _MApp_Music_FLACTimeOffset(U32 u32GotoTimeMs)
{
#ifndef S64
    typedef long long S64;
#endif

    U32 u32Top;
    U32 u32Bottom, u32DiffTop,u32DiffBottom;
    U32 u32EndIdx;
    U32 u32Curr;
    U64 u64SampleNum;
    U64 u64SeekToSample;

    U32 u32FileLength = 0;
    U32 u32Offset = 0;

    FLAC_DBG(printf("\nu32GotoTimeMs: %lu\n",u32GotoTimeMs));

    u64SeekToSample = (U64)(u32GotoTimeMs/1000* m_stFlacInfo.u32SampleRate);
    u32FileLength = stMp3Info.u32FileSize;

    FLAC_DBG(printf("u32FileLength: %lu   stMp3Info.u32FileSize:%lu\n",u32FileLength,stMp3Info.u32FileSize));

    FLAC_DBG(printf("u64SeekToSample: %llu\n",u64SeekToSample));

    if (m_stFlacInfo.u32SeekEntryCount == 0)
    {
        FLAC_DBG(printf("stFlacInfo.u32SeekEntryCount is 0\n"));
        return FALSE;
    }
    u32EndIdx = m_stFlacInfo.u32SeekEntryCount - 1;

    u32Top = 0;
    u32Bottom = u32EndIdx;

    if (MApp_Music_GetFlacSampleIndex(u32Bottom) <= u64SeekToSample)
    {
        u32Curr = u32Bottom;
    }
    else if (MApp_Music_GetFlacSampleIndex(u32Top) > u64SeekToSample)
    {
        msAPI_Stream_Seek(u32Mp3FileHandle, 0);
        stMp3Info.u32MusicDataBytesLeft = m_stFlacInfo.u32DataOffset;

        FLAC_DBG(printf("larger than u64SeekToSample"));
        return TRUE;
    }
    else
    {
        do
        {
            u32Curr = u32Top + ((u32Bottom - u32Top) >> 1);
            u64SampleNum = MApp_Music_GetFlacSampleIndex(u32Curr);
            if (u64SeekToSample < u64SampleNum)
            {
                if (u32Bottom == u32Curr)
                {
                    u32Curr = u32Top;
                    break;
                }
                u32Bottom = u32Curr;
            }
            else if (u64SampleNum < u64SeekToSample)
            {
                if (u32Top == u32Curr)
                {
                    U64 u64SampleNumBot;
                    u64SampleNumBot = MApp_Music_GetFlacSampleIndex(u32Bottom);
                    u32DiffTop = u64SeekToSample - u64SampleNum;
                    if(u64SampleNumBot > u64SeekToSample)
                    {
                        u32DiffBottom = u64SampleNumBot - u64SeekToSample;
                    }
                    else
                    {
                        u32DiffBottom = u64SeekToSample - u64SampleNumBot;
                    }

                    if(u32DiffTop > u32DiffBottom)
                    {
                        u32Curr = u32Bottom;
                    }
                    break;
                }
                u32Top = u32Curr;
            }
            else
            {
                break;
            }
        } while(1);
    }

    if (u32Curr <= u32EndIdx)
    {
        S64 s64DifSampleNum;
        u32Offset = (U32)(m_stFlacInfo.pstSeekTable[u32Curr].u64FrameOffset) + m_stFlacInfo.u32DataOffset;

        s64DifSampleNum = u64SeekToSample - m_stFlacInfo.pstSeekTable[u32Curr].u64SampleNum;

        FLAC_ERR(printf("stFlacInfo.pSeekTable[%lu].u64SampleNum:%llu\n",u32Curr,m_stFlacInfo.pstSeekTable[u32Curr].u64SampleNum));
        FLAC_ERR(printf("Diff sample num:%lld, first calculate pos:%lu\n",s64DifSampleNum, u32Offset));
        if(s64DifSampleNum != 0)
        {
            if (u32Curr < u32EndIdx)
            {
                if(s64DifSampleNum > 0)
                {
                    u32Offset += ((m_stFlacInfo.pstSeekTable[u32Curr + 1].u64FrameOffset - m_stFlacInfo.pstSeekTable[u32Curr].u64FrameOffset)*s64DifSampleNum/(m_stFlacInfo.pstSeekTable[u32Curr + 1].u64SampleNum- m_stFlacInfo.pstSeekTable[u32Curr].u64SampleNum));
                }
                else
                {
                    u32Offset -= ((m_stFlacInfo.pstSeekTable[u32Curr + 1].u64FrameOffset - m_stFlacInfo.pstSeekTable[u32Curr].u64FrameOffset)*(-s64DifSampleNum)/(m_stFlacInfo.pstSeekTable[u32Curr + 1].u64SampleNum- m_stFlacInfo.pstSeekTable[u32Curr].u64SampleNum));
                }
            }
            else //(u32Curr == u32EndIdx)
            {
                if(s64DifSampleNum > 0)
                {
                    u32Offset += ((stMp3Info.u32FileSize - m_stFlacInfo.u32DataOffset - m_stFlacInfo.pstSeekTable[u32Curr].u64FrameOffset)*s64DifSampleNum / (m_stFlacInfo.u64TotalSamples - m_stFlacInfo.pstSeekTable[u32Curr].u64SampleNum));
                }
                else
                {
                    u32Offset -= ((stMp3Info.u32FileSize - m_stFlacInfo.u32DataOffset - m_stFlacInfo.pstSeekTable[u32Curr].u64FrameOffset)*(-s64DifSampleNum) / (m_stFlacInfo.u64TotalSamples - m_stFlacInfo.pstSeekTable[u32Curr].u64SampleNum));
                }
            }
        }
        FLAC_DBG(printf("find index: %ld, sample num:%lld, file pos:%lu\n", u32Curr, MApp_Music_GetFlacSampleIndex(u32Curr), u32Offset));

        if(u32Offset > u32FileLength)
        {
            u32Offset = u32FileLength;
        }

        FLAC_DBG(printf("u32Offset: %lu\n",u32Offset));
        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
        stMp3Info.u32MusicDataBytesLeft = (u32FileLength - u32Offset);

        return TRUE;
    }

    FLAC_DBG(printf("FLACTimeOffset false\n"));
    return FALSE;

}

//******************************************************************************
/// Calculate FLAC time offset in file position.
/// @param  u32GotoTimeMs \b IN  time offset in ms unit.
/// @return TRUE: Success , FALSE: FAIL
//******************************************************************************
static BOOLEAN _MApp_Music_FLACTimeOffsetNoTable(U32 u32GotoTimeMs)
{

    U32 u32FileLength = 0;
    U32 u32Offset = 0;

    FLAC_DBG(printf("u32GotoTimeMs: %lu\n",u32GotoTimeMs));

    u32FileLength = stMp3Info.u32FileSize;


    u32Offset = ((u32FileLength - m_stFlacInfo.u32DataOffset) /(m_stFlacInfo.u32Duration * 1000) * u32GotoTimeMs);

    FLAC_DBG(printf("u32FileLength:%lu   stFlacInfo.u32Duration:%lu\n",u32FileLength,m_stFlacInfo.u32Duration));

    u32Offset = u32Offset + m_stFlacInfo.u32DataOffset;

    if(u32Offset > u32FileLength)
    {
        u32Offset = u32FileLength;
    }

    FLAC_DBG(printf("=============u32Offset: %lu\n",u32Offset));
    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    stMp3Info.u32MusicDataBytesLeft = (u32FileLength - u32Offset);

    return TRUE;

}


#endif


#if (ENABLE_AC3)
static BOOLEAN _MApp_Music_Ac3TimeOffset(U32 u32GotoTimeMs)
{
    U32 u32FileLength = 0;
    U32 u32Offset = 0;

    AC3_DBG(printf("u32GotoTimeMs: %lu\n",u32GotoTimeMs));

    u32FileLength = stMp3Info.u32FileSize;

    if(u32GotoTimeMs ==0)
    {
        u32Offset = m_stAc3Info.u32FileStart;
    }
    else
    {
        u32Offset = (( (u32GotoTimeMs * (stMp3Info.u16BitRate) ) / 8 ) / ( m_stAc3Info.u32FrameSize ) ) * ( m_stAc3Info.u32FrameSize );
        u32Offset = u32Offset + m_stAc3Info.u32FileStart;
        if(u32Offset > u32FileLength)
        {
            u32Offset = u32FileLength;
        }
    }
    AC3_DBG(printf("=============u32Offset: %lu\n",u32Offset));

    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    stMp3Info.u32MusicDataBytesLeft = (u32FileLength - u32Offset);

    return TRUE;
}
#endif

#if (ENABLE_AMR)
//******************************************************************************
/// Calculate AMR time offset in file position.
/// @param  u32GotoTimeMs \b IN  time offset in ms unit.
/// @return TRUE: Success , FALSE: FAIL
//******************************************************************************
static BOOLEAN _MApp_Music_AMRTimeOffset(U32 u32GotoTimeMs)
{
    U32 u32FileLength = 0;
    U32 u32Offset = 0;
    U32 *pu32AMRFrame = (U32 *)(_PA2VA(u32AMRFrameAddr));
    U32 u32CurrentFrameIdx = (U32)(u32GotoTimeMs / 1000);   //One second one index in AMR frame index buffer
    U32 u32SearchFrameCount, i, u32ReadFileSize, u32FileBufIdx = 0;
    U32 u32Buf = ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));
    U8 u8ToC = '\0';
    U8 u8ft = 0;

    //u32FileLength = msAPI_DataStreamIO_Length(u32Mp3FileHandle);
    u32FileLength = stMp3Info.u32FileSize;

    if ( u32CurrentFrameIdx < u32AMR_Frame_Buf_Total_Count )
    {
        u32Offset = pu32AMRFrame[u32CurrentFrameIdx];
        u32SearchFrameCount = ( u32GotoTimeMs % 1000 ) / AMR_ONE_FRAME_DURATION_IN_MS;

        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);

        if ( u32SearchFrameCount )
        {
            if ( ( u32FileLength - u32Offset ) >= AMR_FILEREAD_BUF_LEN )
                u32ReadFileSize = AMR_FILEREAD_BUF_LEN;
            else
                u32ReadFileSize = u32FileLength - u32Offset;

            //Read one time is enough, because we only search maximum 50 frames
            if ( msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void *)u32Buf, u32ReadFileSize) > 0 )
            {
                return FALSE;
            }

            for(i=0;i<u32SearchFrameCount;i++)
            {
                u8ToC = *((U8 *)_PA2VA(u32Buf)+u32FileBufIdx);

                u8ft = (u8ToC >> 3) & 0x0F;

                u32FileBufIdx += (pu8AMRPackedSize[u8ft] + AMR_TOC_LEN);
            }

            if ( u32FileBufIdx >= u32ReadFileSize )
            {
                return FALSE;
            }

            msAPI_Stream_Seek(u32Mp3FileHandle, (u32Offset+u32FileBufIdx));
        }
    }
    else
    {
        printf("AMR Index buffer overflow\n");
        //Direct Search, search from last record in the array
        u32Offset = pu32AMRFrame[u32AMR_Frame_Buf_Total_Count-1];
        u32SearchFrameCount = (u32GotoTimeMs - u32AMR_Frame_Buf_Total_Count*AMR_ONE_FRAME_DURATION_IN_MS) / AMR_ONE_FRAME_DURATION_IN_MS;

        msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);

        if ( u32SearchFrameCount )
        {
            U32 u32FileReadPosition = 0, u32FileProcessIdx = 0;
            BOOLEAN bReadFile = TRUE;

            u32FileProcessIdx = u32Offset;
            u32FileReadPosition = u32FileProcessIdx;

            while(1)
            {
                if ( u32FileProcessIdx >= u32FileLength )
                {
                    u32Offset = u32FileLength;
                    break;
                }

                if ( bReadFile )
                {
                    if ((u32FileReadPosition+AMR_FILEREAD_BUF_LEN) < u32FileLength)
                    {
                        if ( msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void *)u32Buf, AMR_FILEREAD_BUF_LEN) > 0 )
                        {
                            return FALSE;
                        }
                        else
                        {
                            u32FileReadPosition += AMR_FILEREAD_BUF_LEN;
                        }
                    }
                    else
                    {
                        if ( msAPI_DataStreamIO_Read(u32Mp3FileHandle,  (void *)u32Buf, (u32FileLength-u32FileReadPosition)) > 0 )
                        {
                            return FALSE;
                        }
                        u32FileReadPosition = stMp3Info.u32FileSize;
                    }
                    bReadFile = FALSE;
                }

                u8ToC = *((U8 *)_PA2VA(u32Buf)+u32FileBufIdx);

                u8ft = (u8ToC >> 3) & 0x0F;

                u32FileBufIdx += (pu8AMRPackedSize[u8ft] + AMR_TOC_LEN);
                u32FileProcessIdx += (pu8AMRPackedSize[u8ft] + AMR_TOC_LEN);

                u32SearchFrameCount--;
                if ( u32SearchFrameCount == 0 )
                {
                    u32Offset = u32FileProcessIdx;
                    break;
                }

                if ( u32FileBufIdx >= AMR_FILEREAD_BUF_LEN )
                {
                    bReadFile = TRUE;
                    u32FileBufIdx -= AMR_FILEREAD_BUF_LEN;
                }
            }
        }
    }

    if(u32Offset > u32FileLength)
    {
        u32Offset = u32FileLength;
    }
    msAPI_Stream_Seek(u32Mp3FileHandle, u32Offset);
    stMp3Info.u32MusicDataBytesLeft = (u32FileLength - u32Offset);
    //printf("AMRTimeOffset u32FileLength:0x%lx u32Offset:0x%lx\n",u32FileLength,u32Offset);

    return TRUE;
}
#endif

BOOLEAN MApp_Music_ProcessTimeOffset(U32 u32GotoTimeMs)
{
    BOOLEAN bRet = FALSE;

    if(enMusicState == STATE_MUSIC_WAIT_DECODE_DONE)
    {
        enMusicState = STATE_MUSIC_INPUT;
    }
    else if(enMusicState != STATE_MUSIC_INPUT)
    {
        return FALSE;
    }

    if(stMp3Info.u32Duration == 0 || (u32GotoTimeMs > stMp3Info.u32Duration*1000))
    {
        return FALSE;
    }

    //printf("Total Time:%lu , Go to time:%lu\n",stMp3Info.u32Duration,u32GotoTimeMs);

    msAPI_Music_StopDecode();
    if (msAPI_Music_GetResidualBufferSize() != 0)
    {
        // clear audio variables
        msAPI_Timer_Delayms(50);
        msAPI_Music_StartDecode();
        msAPI_Timer_Delayms(50);
        msAPI_Music_StopDecode();
    }
    msAPI_Timer_Delayms(50); // this delay is critical, can't be too small

    switch(enCurrentMusicType)
    {
        case EN_MUSIC_MP3:
            bRet = _MApp_Music_MP3TimeOffset(u32GotoTimeMs);
            break;
#if (ENABLE_AAC)
        case EN_MUSIC_AAC:
            bRet = _MApp_Music_AACTimeOffset(u32GotoTimeMs);
            break;
#endif
#if (ENABLE_WAV)
        case EN_MUSIC_WAV:
            bRet = _MApp_Music_WAVTimeOffset(u32GotoTimeMs);
            break;
#endif
#ifdef OGG_PARSER
#if (ENABLE_OGG)
        case EN_MUSIC_OGG:
            bRet = _MApp_Music_OggTimeOffset(u32GotoTimeMs);
            break;
#endif
#endif
#if (ENABLE_AMR)
        case EN_MUSIC_AMR:
        case EN_MUSIC_AWB:
            bRet = _MApp_Music_AMRTimeOffset(u32GotoTimeMs);
            break;
#endif
#if (ENABLE_FLAC)
        case EN_MUSIC_FLAC:

            if(_MApp_Music_FLACTimeOffset(u32GotoTimeMs)==FALSE)
            {
                bRet=_MApp_Music_FLACTimeOffsetNoTable(u32GotoTimeMs);
            }
            else
            {
                bRet = TRUE;

            }
            break;
#endif
#if (ENABLE_AC3)
        case EN_MUSIC_AC3:
            bRet=_MApp_Music_Ac3TimeOffset(u32GotoTimeMs);
            break;
#endif


        default:
            break;
    }

    msAPI_Music_StartDecode();

    if(bRet)
    {
        stMp3Info.u32CurrentPlayTime = u32GotoTimeMs;
        stMp3Info.u32PlayTimer = msAPI_Timer_GetTime0();
    }

    return bRet;
}

BOOLEAN MApp_Music_FastForwardBackward(BOOLEAN bForward, EN_MP3_SPEED eSpeed)
{
    MUSIC_DBG(printf("MApp_Music_FastForwardBackward, bForward=%d, eSpeed=%d, enMusicState=%d, u8MusicFFFWMode=%d, enMp3PlayStatus=%d\n",
        bForward, eSpeed, enMusicState, u8MusicFFFWMode, enMp3PlayStatus));

    if(enMusicState == STATE_MUSIC_WAIT_DECODE_DONE)
    {
        enMusicState = STATE_MUSIC_INPUT;
    }
    else if(enMusicState != STATE_MUSIC_INPUT)
    {
        return FALSE;
    }

    if(bForward && eSpeed == EN_MP3_SPEED_X1)
    {
        msAPI_Music_StartDecode();
        u8MusicFFFWMode = MP3_NORMAL_MODE;
        enMp3PlaySpeed = EN_MP3_SPEED_X1;
        enMp3PlayStatus = MP3_STATUS_PLAYING;
        return TRUE;
    }

    if (((u8MusicFFFWMode == MP3_FF_Mode) && (bForward))
            || ((u8MusicFFFWMode == MP3_FW_Mode) && (!bForward)))
    {
        if (eSpeed <=EN_MP3_SPEED_MAX)
     	{
		    enMp3PlaySpeed = eSpeed;
			return TRUE;
     	}
		else
		{
		    return false;

		}


    }

    //enMp3PlayStatus = MP3_STATUS_SCAN;
    if (enMp3PlayStatus == MP3_STATUS_PLAYING)
    {
        msAPI_Music_PauseDecode();
    }

    enMp3PlayStatus = MP3_STATUS_SCAN;

    if (bForward)
    {
        u8MusicFFFWMode = MP3_FF_Mode;
    }
    else
    {
        u8MusicFFFWMode = MP3_FW_Mode;
    }
    enMp3PlaySpeed = EN_MP3_SPEED_X2;

    return TRUE;
}

EN_MUSIC_ERRCODE MApp_Music_GetErrCode(void)
{
    return _enMusic_ErrCode;
}

void MApp_Music_StopAfterFBBegin(BOOLEAN bEnabled)
{
   bStop_After_FB_To_Begin = bEnabled;
}

void MApp_Music_GetRIFFTag(U8* buf, U32* ptag, U32* ptagsize)
{
    U32 tag;
    memcpy((U8*)&tag, buf, 4);
    *ptag=Swap32(tag);
    memcpy((U8*)ptagsize, buf+4, 4);
}

//******************************************************************************
/// Input the music data to ES buffer.
/// @param  N/A.
/// @return N/A
//******************************************************************************
void MApp_Music_InputBackGroundMusicData(void)
{
    if(enMusicState == STATE_MUSIC_INPUT)
    {
        MApp_Music_Input();
    }
}

#if (ENABLE_AAC)
void MApp_Music_SetPlayQtFormat(BOOLEAN bPlayQTFormat)
{
    m_bPlayQtFormat = bPlayQTFormat;
}
#endif
#if (ENABLE_AAC)
BOOLEAN MApp_Music_AAC_Probe(U32 u32Hdl, ST_MUSIC_PROBE_INFO *pstMusicProbeInfo, U32 u32InfoAttr)
{

    BOOLEAN bRet = FALSE;

    if(pstMusicProbeInfo==NULL)
    {
        AAC_DBG(printf("pProbeInfo is NULL!\n"));
        return FALSE;

    }

    if(u32Hdl == INVALID_DATA_STREAM_HDL)
    {
        AAC_DBG(printf("Open file failed\n"));
        return FALSE;
    }

    MP3_INFO stMp3InfoLocal;
    U32 u32TagSize = 0;
    U8 *pFileBufPtr;
    U16 u16skip_size=0;
    U8 u8Idx=0;
    U16 u16Frame_i=0;
    U16 u16Data_i=0;
    float frames_per_sec = 0;
    U16 u16FrameLength = 0;
    U32 u32TotalFrameLength = 0;
    U32 u32FilePosition = 0;
    U32 u32FileLength = 0;

    memset(&stMp3InfoLocal,0,sizeof(MP3_INFO));
    memset(pstMusicProbeInfo,0,sizeof(ST_MUSIC_PROBE_INFO));
    u32TagSize = msAPI_Music_Parse_ID3v2(u32Hdl, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN, &stMp3InfoLocal, TRUE);

    //Eric-PH Lee:20080918 Jump ID3 Tag for AAC
    u32FileLength=msAPI_DataStreamIO_Length(u32Hdl);
    u32FileLength-=u32TagSize;
    msAPI_DataStreamIO_Seek(u32Hdl, u32TagSize, E_DATA_STREAM_SEEK_SET);
    u32FilePosition = u32TagSize;
    msAPI_DataStreamIO_Read(u32Hdl, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), 0x1000); // 4k is xdata window size

    // MP3_INFO_READ_ADR must be 4K alignment
    pFileBufPtr = (U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));
    if((pFileBufPtr[0] == 'A') && (pFileBufPtr[1] == 'D') && (pFileBufPtr[2] == 'I') && (pFileBufPtr[3] == 'F'))
    {
        AAC_DBG(printf("   - ADIF File\n"));
        /* copyright string */
        if(pFileBufPtr[4] & 0x80)
        {
            u16skip_size += 13; /* skip 9 bytes */
        }
        else
        {
            u16skip_size += 4;
        }

        pstMusicProbeInfo->u16BitRate = ((unsigned int)(pFileBufPtr[0 + u16skip_size] & 0x0F)<<19)|
        ((unsigned int)pFileBufPtr[1 + u16skip_size]<<11)|
        ((unsigned int)pFileBufPtr[2 + u16skip_size]<<3)|
        ((unsigned int)pFileBufPtr[3 + u16skip_size] & 0xE0);

        if( (pFileBufPtr[0 + u16skip_size] & 0x10) )
        {
            u8Idx = ((pFileBufPtr[4 + u16skip_size] & 0x07)<<1)|((pFileBufPtr[5 + u16skip_size] & 0x80)>>7);
        }
        else
        {
            u8Idx = (pFileBufPtr[7 + u16skip_size]&0x78)>>3;
        }

        pstMusicProbeInfo->u16SampleRate= samplerate_table[u8Idx+1];
        bRet = TRUE;
    }
    else /* No ADIF, check for ADTS header */
    {
        if (( (pFileBufPtr[0] == 0xFF)&&((pFileBufPtr[1] & 0xF6) == 0xF0)) )
        {
            AAC_DBG(printf("   - ADTS File\n"));

            u8Idx = (pFileBufPtr[2]&0x3C)>>2;

            /* fixed ADTS header is the same for every frame, so we read it only once */
            /* Syncword found, proceed to read in the fixed ADTS header */
            frames_per_sec = samplerate_table[u8Idx+1] / 1024.f;

            u16Data_i = 0;
            /* Read first 215 frames to ensure correct time and bitrate */
            for(u16Frame_i=0; u16Frame_i<215; u16Frame_i++)
            {
                if( !((pFileBufPtr[u16Data_i] == 0xFF) && ((pFileBufPtr[u16Data_i+1] >> 4) == 0x0F)) )
                {
                    AAC_DBG(printf("Frame Header Error!\n"));
                    break;
                }

                u16FrameLength = ((((U16)pFileBufPtr[u16Data_i+3] & 0x3)) << 11) | (((U16)pFileBufPtr[u16Data_i+4]) << 3) | (pFileBufPtr[u16Data_i+5] >> 5);
                AAC_DBG(printf("(%u) position:0x%lX frame_length:0x%x [%BX] [%BX]\n",u16Frame_i,(u16Data_i+u32FilePosition),u16FrameLength,pFileBufPtr[u16Data_i],pFileBufPtr[u16Data_i+1]));
                u32TotalFrameLength += u16FrameLength;

                if((u16Data_i+u16FrameLength)>=(0x1000-0x10))  //0x10: Protect boundary
                {
                    u32FilePosition += (u16Data_i+u16FrameLength);
                    msAPI_DataStreamIO_Seek(u32Hdl, u32FilePosition, E_DATA_STREAM_SEEK_SET);
                    msAPI_DataStreamIO_Read(u32Hdl, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), 0x1000); // 4k is xdata window size
                    u16Data_i=0;
                }
                else
                {
                    u16Data_i += u16FrameLength;
                }

            }

            if (u16Frame_i > 0)
            {
                pstMusicProbeInfo->u16SampleRate = (U16)samplerate_table[u8Idx+1];
                // bitrate is calculated only fot the first 215 frames, so it is not precise but near
                pstMusicProbeInfo->u16BitRate = ((float)((float)((float)(u32TotalFrameLength /u16Frame_i) * (float)(pstMusicProbeInfo->u16SampleRate/1024)))*8)/1000;

                /* Since we only use 5 seconds of aac data to get a rough bitrate, we must use a different
                method of calculating the overall length */
                //For some stream mode (ex. DLNA), maybe not support file length.

                if(u32InfoAttr & E_MUSIC_INFO_DURATION)
                {
                    if(msAPI_DataStreamIO_Length(u32Hdl) == 0xFFFFFFFF)
                    {
                        pstMusicProbeInfo->u32Duration = 0xFFFFFFFF;
                    }
                    else
                    {
                        pstMusicProbeInfo->u32Duration= (U32)((U32)u32FileLength/(U32)(pstMusicProbeInfo->u16BitRate*125));
                    }
                    AAC_DBG(printf("t_framelength:%lu SR:%u BR:%u u16Duration:%u\n",u32TotalFrameLength,pstMusicProbeInfo->u16SampleRate,pstMusicProbeInfo->u16BitRate,pstMusicProbeInfo->u32Duration));
                }
                bRet = TRUE;
            }
            else
            {
                bRet = FALSE;
                AAC_DBG(printf("Frame id is Zero!\n"));
            }
        }
    }
    return bRet;
}

BOOLEAN MApp_Music_M4A_Probe(U32 u32Hdl, ST_MUSIC_PROBE_INFO *pstMusicProbeInfo, U32 u32InfoAttr)
{

    if(u32Hdl==INVALID_DATA_STREAM_HDL)
    {
        AAC_DBG(printf("u32Hdl is INVALID\n"));
        return FALSE;
    }

    if(pstMusicProbeInfo==NULL)
    {
        AAC_DBG(printf("pProbeInfo is NULL\n"));
        return FALSE;
    }

    U32 u32CurrentFilePosition = 0;
    U32 u32FileSize = 0;
    ST_M4A_INFO stM4AInfoInfoLocal;

    memset(&stM4AInfoInfoLocal, 0, sizeof(ST_M4A_INFO));
    memset(pstMusicProbeInfo,0,sizeof(ST_MUSIC_PROBE_INFO));

    u32FileSize = msAPI_DataStreamIO_Length(u32Hdl);

    stM4AInfoInfoLocal.u32FileSize = u32FileSize;

    AAC_DBG(printf("@m4a size:0x%lx\n",stM4AInfoInfoLocal.u32FileSize));

    //skip ID3v2
    msAPI_Stream_Seek(u32Hdl, 0);
    MP3_INFO stMp3InfoLocal;
    memset(&stMp3InfoLocal,0,sizeof(MP3_INFO));
    U32 u32TagSize = msAPI_Music_Parse_ID3v2(u32Hdl, ((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), M4A_BUFFER_LEN, &stMp3InfoLocal, FALSE);

    if (u32TagSize > 0)
                    {
        u32CurrentFilePosition += u32TagSize;
            }

    U32 u32TimerLimitaion = msAPI_Timer_GetTime0();

    U8 *pu8Buffer = (U8 *)_PA2VA(((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)));
    U32 u32ChunkSize = 0;
    while(u32CurrentFilePosition < u32FileSize)
        {
        AAC_DBG(printf("currentFilePosition:0x%x\n",u32CurrentFilePosition));
        msAPI_Stream_Seek(u32Hdl, u32CurrentFilePosition);
        msAPI_DataStreamIO_Read(u32Hdl, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), M4A_CHUNK_HEADER_SIZE);


         //find ftyp
        if(!stM4AInfoInfoLocal.bFoundftyp)
            {
            if(parseM4AChunkHeader("ftyp", pu8Buffer, &u32ChunkSize))
                {
                AAC_DBG(printf("Found ftyp\n"));
                stM4AInfoInfoLocal.bFoundftyp = TRUE;
                }
                else
                {
                break; //Break while
                }
            u32CurrentFilePosition += u32ChunkSize;
            continue;
            }

        //Parsing "moov"
        if(!stM4AInfoInfoLocal.bFoundmoov)
                        {
            if(parseM4AChunkHeader("moov", pu8Buffer, &u32ChunkSize))
                            {
                AAC_DBG(printf("Found moov\n"));
                stM4AInfoInfoLocal.bFoundmoov = TRUE;
                u32CurrentFilePosition += M4A_CHUNK_ENTRY_OFFSET;  //skip to sub-entry
                continue;
                            }
                        }

        if((u32InfoAttr & E_MUSIC_INFO_DURATION) && (!stM4AInfoInfoLocal.bFoundmvhd))
                    {
            //Parsing "mvhd"
            if(parseM4AChunkHeader("mvhd", pu8Buffer, &u32ChunkSize))
                        {
                AAC_DBG(printf("Found mvhd\n"));
                stM4AInfoInfoLocal.bFoundmvhd = TRUE;

                msAPI_DataStreamIO_Read(u32Hdl, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MVHD_VERSION_TYPE_SIZE);

                if((*pu8Buffer) == 1) //version 1
                {
                    U32 u32TimeScale = 0;
                    U64 u64Duration = 0;

                    msAPI_DataStreamIO_Read(u32Hdl, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MVHD_DURATION_VERSION1_OFFSET + 8);
                    memcpy(&u32TimeScale, (pu8Buffer + MVHD_TIMESCALE_VERSION1_OFFSET), 4);
                    u32TimeScale = Swap32(u32TimeScale);
                    memcpy(&u64Duration, (pu8Buffer + MVHD_DURATION_VERSION1_OFFSET), 8);
                    u64Duration = Swap64(u64Duration);
                    AAC_DBG(printf("u64Duration: %llu, u32TimeScale: %lu\n", u64Duration, u32TimeScale));

                    if((u64Duration > 0) && (u32TimeScale > 0))
                    {
                        stM4AInfoInfoLocal.u32Duration = (u64Duration + (u32TimeScale / 2)) / u32TimeScale;
                    }

                    u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                    u32ChunkSize -= (M4A_CHUNK_HEADER_SIZE + MVHD_VERSION_TYPE_SIZE + MVHD_DURATION_VERSION1_OFFSET + 8);
                }
                else //version 0
            {
                    U32 u32Duration = 0;
                    U32 u32TimeScale = 0;

                    msAPI_DataStreamIO_Read(u32Hdl, (void*)((M4A_BUFFER_MEMORY_TYPE & MIU1) ? (M4A_BUFFER_ADR | MIU_INTERVAL) : (M4A_BUFFER_ADR)), MVHD_DURATION_VERSION0_OFFSET + 4);

                    memcpy(&u32TimeScale, (pu8Buffer + MVHD_TIMESCALE_VERSION0_OFFSET), 4);
                    u32TimeScale = Swap32(u32TimeScale);
                    memcpy(&u32Duration, (pu8Buffer + MVHD_DURATION_VERSION0_OFFSET), 4);
                    u32Duration = Swap32(u32Duration);
                    AAC_DBG(printf("u32Duration: %lu, u32TimeScale: %lu\n", u32Duration, u32TimeScale));

                    if((u32Duration > 0) && (u32TimeScale > 0))
                {
                        stM4AInfoInfoLocal.u32Duration = (u32Duration + (u32TimeScale / 2)) / u32TimeScale;
                }

                    u32CurrentFilePosition += u32ChunkSize;  //skip to next-entry
                }
                AAC_DBG(printf("@m4a u32Duration: %lu\n", stM4AInfoInfoLocal.u32Duration));
                printf("@m4a u32Duration: %lu\n", stM4AInfoInfoLocal.u32Duration);
                continue;
                }
            }

        if(msAPI_Timer_DiffTimeFromNow(u32TimerLimitaion)>M4A_PROBE_TIME_OUT)
        {
            MUSIC_DBG(printf("more than 5 seconds, break\n"));
            return FALSE;
        }

        if((u32InfoAttr & E_MUSIC_INFO_DURATION) && (stM4AInfoInfoLocal.bFoundmvhd==TRUE))
        {
            pstMusicProbeInfo->u32Duration = stM4AInfoInfoLocal.u32Duration;
            return TRUE;
        }

        //No useful tag found, skip it!
        if(parseM4AChunkHeader("skip", pu8Buffer, &u32ChunkSize)) //Use the "skip" to skip tag
        {
            u32CurrentFilePosition += u32ChunkSize;
            continue;
}

    } //while end

    return FALSE;
}
#endif

#if (ENABLE_FLAC)
BOOLEAN MApp_Music_FLAC_Probe(U32 u32Hdl, ST_MUSIC_PROBE_INFO *pstMusicProbeInfo, U32 u32InfoAttr)
{
    if(pstMusicProbeInfo == NULL)
    {
        FLAC_DBG(printf(" ---> MApp_Music_FLAC_Probe() Error  !!!  ( pstMusicProbeInfo == NULL ) \n"));
        return FALSE;
    }

    if(u32Hdl == INVALID_DATA_STREAM_HDL)
    {
        FLAC_DBG(printf("u32Hdl is INVALID\n"));
        return FALSE;
    }

    ST_FLAC_INFO stFlacInfoLocal;
    memset(&stFlacInfoLocal,0,sizeof(ST_FLAC_INFO));

    U32 u32FileSize = 0;
    u32FileSize = msAPI_DataStreamIO_Length(u32Hdl);

    if (u32FileSize < 42)  //FileSize too small, no StreamInfo Block
    {
       FLAC_ERR(printf("File size smaller than 42, no streamInfo Block\n"));
       return FALSE;
    }

    U32 u32Idx = 4;   //skip fLaC
    /*flac need skip the ID3 TAG*/
    U32 u32TagSize = msAPI_Music_Parse_ID3v2(u32Hdl, ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN, &stMp3Info.stID3v2, TRUE);
    if (u32TagSize > 0)
    {
	    u32Idx += u32TagSize;
    }
    FLAC_DBG(printf("flac u32TagSize is %ld,u32Idx is %ld \n",u32TagSize,u32Idx));

    BOOLEAN bBlockStreamInfo = FALSE;
    U8 *pu8Data = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

    while(u32Idx < u32FileSize)
    {
        msAPI_DataStreamIO_Seek(u32Hdl,u32Idx,E_DATA_STREAM_SEEK_SET);
        U32 u32Remain = msAPI_DataStreamIO_Read(u32Hdl,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),0x4);
        U32 u32BufferIdx = 0;

        if(u32Remain!=0)
        {
            FLAC_ERR(printf("not enough byte to read at line:%d\n",__LINE__));
            return FALSE;
        }

        U8 u8LastMetaDataFlag = (pu8Data[u32BufferIdx] & 0x80) >> 7;
        U8 u8BlockType = pu8Data[u32BufferIdx] & 0x7F;
        U32 u32MetaDataSize = COMB_U32(0, pu8Data[u32BufferIdx+1], pu8Data[u32BufferIdx+2], pu8Data[u32BufferIdx+3]);
        u32Idx += 4;

        FLAC_DBG(printf("%d %d 0x%lx\n", u8LastMetaDataFlag, u8BlockType, u32MetaDataSize));

        if( (bBlockStreamInfo==FALSE) && (u8BlockType ==0))   //Stream info
        {
            bBlockStreamInfo = TRUE;

            msAPI_DataStreamIO_Seek(u32Hdl,u32Idx,E_DATA_STREAM_SEEK_SET);
            u32Remain = msAPI_DataStreamIO_Read(u32Hdl,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),0x22);
            U32 u32BufferIndex2 = 0;

            if(u32Remain!=0)
            {
               FLAC_ERR(printf("not enough byte to read at line:%d\n",__LINE__));
               return FALSE;
            }

            // Flush mininum/maxinum block size, minimum/maximum frame size
            u32BufferIndex2 += 10;

            // sample rate
            stFlacInfoLocal.u32SampleRate =  COMB_U32(0, (pu8Data[u32BufferIndex2]>>4), ((pu8Data[u32BufferIndex2]&0xF)<<4)|(pu8Data[u32BufferIndex2+1]>>4), ((pu8Data[u32BufferIndex2+1]&0xF)<<4)|(pu8Data[u32BufferIndex2+2]>>4));
            FLAC_DBG(printf("sample rate: %ld\n", stFlacInfoLocal.u32SampleRate));

            // Channel
            stFlacInfoLocal.u8Channel = (pu8Data[u32BufferIndex2+2]>>1)&0x7;
            FLAC_DBG(printf("channel :%d\n ", stFlacInfoLocal.u8Channel));

            // Bits/Sample
            stFlacInfoLocal.u8BitsPerSample = ((pu8Data[u32BufferIndex2+2] & 0x1)<<4) | (pu8Data[u32BufferIndex2+3]>>4);
            FLAC_DBG(printf("bits/sample : %d\n", stFlacInfoLocal.u8BitsPerSample));

            // Total Sample
            stFlacInfoLocal.u64TotalSamples = (U64)(pu8Data[u32BufferIndex2+3] & 0xF)<<32 | COMB_U32(pu8Data[u32BufferIndex2+4], pu8Data[u32BufferIndex2+5], pu8Data[u32BufferIndex2+6], pu8Data[u32BufferIndex2+7]);
            FLAC_DBG(printf("total sample: %lld\n", stFlacInfoLocal.u64TotalSamples));

            // duration
            if(u32InfoAttr & E_MUSIC_INFO_DURATION)
            {
                if ((stFlacInfoLocal.u64TotalSamples != 0) && (stFlacInfoLocal.u32SampleRate != 0))
                {
                    stFlacInfoLocal.u32Duration = (U32)stFlacInfoLocal.u64TotalSamples/stFlacInfoLocal.u32SampleRate;
                    FLAC_DBG(printf("duration: %ld\n", stFlacInfoLocal.u32Duration));
                    pstMusicProbeInfo->u32Duration = stFlacInfoLocal.u32Duration;
                }
                else
                {
                    FLAC_ERR("duration calculation error\n");
                    return FALSE;
                }
            }
        }//end of streaminfo block

        if(u8LastMetaDataFlag==1)  //ready to leave this loop
        {
            if( bBlockStreamInfo == FALSE)   //no Stream Block, illegal
            {
                return FALSE;
            }
            break;  //end of while loop
        }
        u32Idx += u32MetaDataSize;

    }//end of whileloop

    pstMusicProbeInfo->u16SampleRate = (U16)stFlacInfoLocal.u32SampleRate;

    return TRUE;

}
#endif


#if (ENABLE_AC3)
BOOLEAN MApp_Music_AC3_Probe(U32 u32Hdl, ST_MUSIC_PROBE_INFO *pstMusicProbeInfo, U32 u32InfoAttr)
{
    if(pstMusicProbeInfo == NULL)
    {
        AC3_ERR(printf(" ---> MApp_Music_AC3_Probe() Error  !!!  ( pstMusicProbeInfo == NULL ) \n"));
        return FALSE;
    }

    if(u32Hdl == INVALID_DATA_STREAM_HDL)
    {
        AC3_ERR(printf("u32Hdl is INVALID\n"));
        return FALSE;
    }


    ST_AC3_INFO stAc3InfoLocal;
    memset(&stAc3InfoLocal,0,sizeof(stAc3InfoLocal));

    U32 u32FileSize = 0;
    u32FileSize = msAPI_DataStreamIO_Length(u32Hdl);


    U8* pu8Data = NULL;
    pu8Data = (U8*)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));

    U32 u32Remain = 0;
    u32Remain = msAPI_DataStreamIO_Read(u32Hdl,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),AC3_PARSE_BUFFER_SIZE);

    if(u32Remain!=0)
    {
       AC3_ERR(printf("First frame too short\n"));
       goto Lable_CollectAC3Info_Probe_Error;
    }

    U16 u16SyncWord  = 0;
    u16SyncWord = COMB_U16(pu8Data[0],pu8Data[1]);

    U32 u32count = 0;
    U8 u8tmp = 0;


    //search first frame
    if( u16SyncWord == AC3_SYNC_WORD_BE )
    {
        AC3_DBG(printf("detect the Big endian sync word."));
        for( u32count = 0 ; u32count < AC3_PARSE_BUFFER_SIZE ; u32count += 2 )
        {
            u8tmp = pu8Data[u32count];
            pu8Data[u32count]   = pu8Data[u32count+1];
            pu8Data[u32count+1] = u8tmp;
        }
        u16SyncWord = AC3_SYNC_WORD;
    }


    U32 u32BitRate = 0;
    U32 u32SampleRate = 0;

    if( u16SyncWord == AC3_SYNC_WORD )
    {
        stAc3InfoLocal.u8Bsid = pu8Data[5]>>3;
        if( 0x10 != ( stAc3InfoLocal.u8Bsid ) ) //ac3 format
        {
            stAc3InfoLocal.bIsEAC3 = FALSE;
            stAc3InfoLocal.u16Crc  = COMB_U16(pu8Data[2],pu8Data[3]);
            stAc3InfoLocal.u8Fscod = pu8Data[4]>>6;
            if( ( stAc3InfoLocal.u8Fscod ) == 0x11 )
            {
                AC3_ERR(printf("AC3 find Fscod error.\n"));

                goto Lable_CollectAC3Info_Probe_Error;
            }
            stAc3InfoLocal.u8FrmsizeCod = pu8Data[4] & 0x3F;
            if( ( stAc3InfoLocal.u8FrmsizeCod ) > 37)
            {
                AC3_ERR(printf("AC3 find FrameSizeCode error.\n"));
                goto Lable_CollectAC3Info_Probe_Error;
            }
            stAc3InfoLocal.u8Acmod      = ( pu8Data[6] & 0xE0 ) >> 5;
            stAc3InfoLocal.u32FrameSize = u32Ac3FramesizeTable[stAc3InfoLocal.u8Fscod][stAc3InfoLocal.u8FrmsizeCod] * 2;

            u32SampleRate  = u32Ac3SampleRateTable[stAc3InfoLocal.u8Fscod];
            u32BitRate     = u32Ac3BitrateTable[stAc3InfoLocal.u8FrmsizeCod] / 1000;


        }
        else //ac3+ format
        {
            stAc3InfoLocal.bIsEAC3 = TRUE;
            stAc3InfoLocal.u32FrameSize = (U32) ( ( ( ( pu8Data[2] & 0x03 ) << 8 ) | pu8Data[3] ) + 1) * 2;//in WORD, so we have to transfer the value to bytes..
            stAc3InfoLocal.u8Fscod = pu8Data[4]>>6;

            if( ( stAc3InfoLocal.u8Fscod ) == 0x3 )
            {
                U8 u8fscod2 = ( pu8Data[4] & 0x3f ) >> 4;
                if( u8fscod2 == 0x3 )
                {
                    AC3_ERR(printf("Ac3 find sampleRate error.\n"));
                    goto Lable_CollectAC3Info_Probe_Error;

                }
                u32SampleRate  =  u32Ac3SampleRateTable[u8fscod2] / 2;
                stAc3InfoLocal.u8NumBlk = (U8) u32Ac3NumBlkTable[0x3];
            }
            else
            {
                u32SampleRate =  u32Ac3SampleRateTable[ stAc3InfoLocal.u8Fscod ];
                stAc3InfoLocal.u8NumBlk = (U8) u32Ac3NumBlkTable[ ( pu8Data[4] & 0x3f ) >> 4 ];
            }

            stAc3InfoLocal.u8Acmod = ( pu8Data[4] & 0x0F ) >> 1;
            stAc3InfoLocal.u8Lfeon = pu8Data[4] & 0x01;
            u32BitRate = ( ( ( ( 8 * ( stAc3InfoLocal.u32FrameSize ) )*( u32SampleRate) ) / ( stAc3InfoLocal.u8NumBlk ) ) / 256 ) / 1000;
        }

        if(u32BitRate==0)
        {
            AC3_ERR(printf("Bitrate is 0\n"));
            goto Lable_CollectAC3Info_Probe_Error;

        }

        pstMusicProbeInfo->u16SampleRate = (U16) u32SampleRate;
        pstMusicProbeInfo->u16BitRate = (U16) u32BitRate;

        AC3_DBG(printf("AC3 u32FrameSize: %lu\n", stAc3InfoLocal.u32FrameSize));
        AC3_DBG(printf("AC3 u32SampleRate: %lu\n",u32SampleRate));
        AC3_DBG(printf("AC3 u32BitRate: %lu\n",   u32BitRate));

    }//end of search first frame


    //search second frame
    msAPI_Stream_Seek(u32Hdl, stAc3InfoLocal.u32FrameSize);

    u32Remain = msAPI_DataStreamIO_Read(u32Hdl,(void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)),AC3_PARSE_BUFFER_SIZE);

    if(u32Remain!=0)
    {
        AC3_ERR(printf("File length too short\n"));
        goto Lable_CollectAC3Info_Probe_Error;
    }

    u16SyncWord = COMB_U16( pu8Data[0] , pu8Data[1] );
    if(( u16SyncWord != AC3_SYNC_WORD) &&
       ( u16SyncWord != AC3_SYNC_WORD_BE))
    {
        AC3_ERR(printf("Second frame too short!\n"));
        goto Lable_CollectAC3Info_Probe_Error;
    }//end search second frame


    // duration
    if((u32InfoAttr & E_MUSIC_INFO_DURATION) && (u32BitRate>0))
    {
        pstMusicProbeInfo->u32Duration = ( 8 * u32FileSize ) / u32BitRate / 1000;
        AC3_DBG(printf("AC3 u32Duration: %lu\n",  pstMusicProbeInfo->u32Duration));

    }

    return TRUE;


Lable_CollectAC3Info_Probe_Error:
    return FALSE;

}
#endif



#if (ENABLE_WAV)
BOOLEAN MApp_Music_WAV_Probe(U32 u32Hdl, ST_MUSIC_PROBE_INFO *pstMusicProbeInfo, U32 u32InfoAttr)
{

    BOOLEAN bRet = FALSE;

    //Check pProbeInfo is valid or not
    if(pstMusicProbeInfo == NULL)
    {
        WAV_DBG(printf(" ---> MApp_Music_WAV_Probe() Error  !!!  ( pstMusicProbeInfo == NULL ) \n"));
        return FALSE;
    }

    if(u32Hdl == INVALID_DATA_STREAM_HDL)
    {
        WAV_DBG(printf("u32Hdl is INVALID\n"));
        return FALSE;
    }


    ST_WAV_CHUNK stWavChunkLocal;
    U8 *pu8Data = (U8 *)_PA2VA(((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)));
    U32 offset=0;
    U32 tag;
    U32 tagsize;


    memset(pstMusicProbeInfo, 0, sizeof(ST_MUSIC_PROBE_INFO));
    memset(&stWavChunkLocal,0,sizeof(ST_WAV_CHUNK));

    msAPI_DataStreamIO_Read(u32Hdl, (void*)((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR)), MP3_INFO_READ_LEN);


    MApp_Music_GetRIFFTag(&pu8Data[offset], &tag, &tagsize);

    WAV_DBG(printf("%x %x %x %x\n",pu8Data[offset],pu8Data[offset+1],pu8Data[offset+2],pu8Data[offset+3]));
    WAV_DBG(printf("tag: %lu\n",tag));
    WAV_DBG(printf("tagsize: %lu\n",tagsize));


    if (tag==RIFF_TAG_RIFF)
    {
        memcpy(&stWavChunkLocal.u32RIFFChunkSize, &tagsize,4);
        offset+=8;
        MApp_Music_GetRIFFTag(&pu8Data[offset], &tag, &tagsize);
        offset+=4;

        if (tag==RIFF_TAG_WAVE)
        {
            while (1)
            {
                if ((offset+8) > MP3_INFO_READ_LEN)
                {
                    stWavChunkLocal.u16FormatTag=0;
                    break;
                }
                MApp_Music_GetRIFFTag(&pu8Data[offset], &tag, &tagsize);
                if (tag==RIFF_TAG_fmt)
                {
                    WAV_DBG(printf("wave fmt found\n"));

                    memcpy(&stWavChunkLocal.u32SamplesPerSec,(&pu8Data[offset])+12,4);
                    memcpy(&stWavChunkLocal.u32AvgBytesPerSec,(&pu8Data[offset])+16,4);
                }
                else if (tag==RIFF_TAG_data)
                {
                    WAV_DBG(printf("wave data found\n"));
                    memcpy(&stWavChunkLocal.u32DataChunkSize,(&pu8Data[offset])+4,4);
                    stWavChunkLocal.u32HeaderSize = (offset+8);
                    WAV_DBG(printf("offset: %lu\n",offset));
                    break;
                }
                offset+=(tagsize+8);

            }

            WAV_DBG(printf("u32DataChunkSize:0x%lx\n",stWavChunkLocal.u32DataChunkSize));
            WAV_DBG(printf("u32SamplesPerSec:%lu\n",stWavChunkLocal.u32SamplesPerSec));
            WAV_DBG(printf("u32AvgBytesPerSec:0x%lx\n",stWavChunkLocal.u32AvgBytesPerSec));

            pstMusicProbeInfo->u16SampleRate = (U16)(stWavChunkLocal.u32SamplesPerSec);
            pstMusicProbeInfo->u16BitRate = (U16)((stWavChunkLocal.u32AvgBytesPerSec<<3)/1000);

            if(u32InfoAttr & E_MUSIC_INFO_DURATION)
            {
                pstMusicProbeInfo->u32Duration =  (U16)(stWavChunkLocal.u32DataChunkSize/stWavChunkLocal.u32AvgBytesPerSec);
                WAV_DBG(printf("u32Duration:0x%lx\n",pstMusicProbeInfo->u32Duration));
                bRet = TRUE;
            }


            if(stWavChunkLocal.u32SamplesPerSec <= 48*1000 && stWavChunkLocal.u32SamplesPerSec >= 8*1000)
            {
                if( (stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_PCM) ||
                (stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_M_ADPCM) ||
                (stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_EXTENSIBLE) ||
                (stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_IMA_ADPCM) ||
                (stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_ALAW) ||
                (stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_MULAW))
                {
                    bRet = TRUE;
                    stWavChunkLocal.bIsDTS = FALSE;
                    //check whether it is CD-DTS
                    if(stWavChunkLocal.u16FormatTag == (U16)WAVE_FORMAT_PCM)
                    {
                        U32 u32FrameSize;
                        U32 u32SampleRateIndex, u32BitRateIndex;

                        offset = stWavChunkLocal.u32HeaderSize;

                        while (1)
                        {
                            if (offset >= MP3_INFO_READ_LEN)
                            {
                                break;
                            }
                            //14bit sync header 0x1FFFE800+0x07F
                            //little endian case
                            if(pu8Data[offset] == 0xFF && pu8Data[offset+1] == 0x1F &&
                            pu8Data[offset+2] == 0x00 && pu8Data[offset+3] == 0xE8 &&
                            (pu8Data[offset+4]&0xF0) == 0xF0 && pu8Data[offset+5] == 0x07)
                            {
                                //get fsize
                                U16 u16FrameHdr[4];

                                u16FrameHdr[0] = (U16)(pu8Data[offset+4] | pu8Data[offset+5] << 8) & 0x3FFF;
                                u16FrameHdr[1] = (U16)(pu8Data[offset+6] | pu8Data[offset+7] << 8) & 0x3FFF;
                                u16FrameHdr[2] = (U16)(pu8Data[offset+8] | pu8Data[offset+9] << 8) & 0x3FFF;
                                u16FrameHdr[3] = (U16)(pu8Data[offset+10] | pu8Data[offset+11] << 8) & 0x3FFF;

                                u32FrameSize = (U32)((u16FrameHdr[1] & 0x3FF) << 4 |(u16FrameHdr[2] & 0x3C00) >> 10) + 1;
                                u32SampleRateIndex = (U32)(u16FrameHdr[2] & 0xF);
                                u32BitRateIndex = (U32)((u16FrameHdr[3] & 0x3E00)>> 9);
                                WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                WAV_DBG(printf("find DTS sync header (14bit little endian) and frame size is :0x%lx\n",u32FrameSize));
                                if(u32SampleRateIndex > 15)
                                {
                                    WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }

                                if(u32BitRateIndex > 31)
                                {
                                    WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }
                                stWavChunkLocal.bIsDTS = TRUE;
                                break;
                            }
                            //14bit sync header 0x1FFFE800+0x07F
                            //big endian case
                            else if(pu8Data[offset] == 0x1F && pu8Data[offset+1] == 0xFF &&
                            pu8Data[offset+2] == 0xE8 && pu8Data[offset+3] == 0x00 &&
                            pu8Data[offset+4] == 0x07 && (pu8Data[offset+5]&0xF0) == 0xF0)
                            {
                                //get fsize
                                U16 u16FrameHdr[4];

                                u16FrameHdr[0] = (U16)(pu8Data[offset+4] << 8 | pu8Data[offset+5]) & 0x3FFF;
                                u16FrameHdr[1] = (U16)(pu8Data[offset+6] << 8 | pu8Data[offset+7]) & 0x3FFF;
                                u16FrameHdr[2] = (U16)(pu8Data[offset+8] << 8 | pu8Data[offset+9]) & 0x3FFF;
                                u16FrameHdr[3] = (U16)(pu8Data[offset+10] << 8 | pu8Data[offset+11]) & 0x3FFF;

                                u32FrameSize = (U32)((u16FrameHdr[1] & 0x3FF) << 4 |(u16FrameHdr[2] & 0x3C00) >> 10) + 1;
                                u32SampleRateIndex = (U32)(u16FrameHdr[2] & 0xF);
                                u32BitRateIndex = (U32)((u16FrameHdr[3] & 0x3E00)>> 9);
                                WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                WAV_DBG(printf("find DTS sync header (14bit big endian)and frame size is :0x%lx\n",u32FrameSize));
                                if(u32SampleRateIndex > 15)
                                {
                                    WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }

                                if(u32BitRateIndex > 31)
                                {
                                    WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }
                                stWavChunkLocal.bIsDTS = TRUE;
                                break;
                            }
                            //16bit sync header 0x7FFE8001+0x3F
                            //little endian case
                            else if(pu8Data[offset] == 0xFE && pu8Data[offset+1] == 0x7F &&
                            pu8Data[offset+2] == 0x01 && pu8Data[offset+3] == 0x80 && pu8Data[offset+5]>>2 == 0x3F)
                            {
                                //get fsize
                                U16 u16FrameHdr[3];

                                u16FrameHdr[0] = (U16)(pu8Data[offset+4] | pu8Data[offset+5] << 8);
                                u16FrameHdr[1] = (U16)(pu8Data[offset+6] | pu8Data[offset+7] << 8);
                                u16FrameHdr[2] = (U16)(pu8Data[offset+8] | pu8Data[offset+9] << 8);

                                u32FrameSize = (U32)((u16FrameHdr[0] & 3) << 12 |(u16FrameHdr[1] & 0xFFF0) >> 4) + 1;
                                u32SampleRateIndex = (U32)((u16FrameHdr[2] & 0x3C00)>> 10);
                                u32BitRateIndex = (U32)((u16FrameHdr[2] & 0x3E0)>> 5);
                                WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                WAV_DBG(printf("find DTS sync header (16bit little endian) and frame size is :0x%lx\n",u32FrameSize));
                                if(u32SampleRateIndex > 15)
                                {
                                    WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }

                                if(u32BitRateIndex > 31)
                                {
                                    WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }
                                stWavChunkLocal.bIsDTS = TRUE;
                                break;
                            }
                            //16bit sync header 0x7FFE8001+0x3F
                            //big endian case
                            else if(pu8Data[offset] == 0x7F && pu8Data[offset+1] == 0xFE &&
                            pu8Data[offset+2] == 0x80 && pu8Data[offset+3] == 0x01 && pu8Data[offset+4]>>2 == 0x3F)
                            {
                                //get fsize
                                U16 u16FrameHdr[3];

                                u16FrameHdr[0] = (U16)(pu8Data[offset+4] << 8 | pu8Data[offset+5]);
                                u16FrameHdr[1] = (U16)(pu8Data[offset+6] << 8 | pu8Data[offset+7]);
                                u16FrameHdr[2] = (U16)(pu8Data[offset+8] << 8 | pu8Data[offset+9]);

                                u32FrameSize = (U32)((u16FrameHdr[0] & 3) << 12 |(u16FrameHdr[1] & 0xFFF0) >> 4) + 1;
                                u32SampleRateIndex = (U32)((u16FrameHdr[2] & 0x3C00)>> 10);
                                u32BitRateIndex = (U32)((u16FrameHdr[2] & 0x3E0)>> 5);
                                WAV_DBG(printf("u16FrameHdr[0]:%lx ,u16FrameHdr[1]:%lx,u16FrameHdr[2]:%lx,sampleidx:%lx,bitidx:%lx \n",
                                u16FrameHdr[0] ,u16FrameHdr[1],u16FrameHdr[2] ,u32SampleRateIndex, u32BitRateIndex));
                                WAV_DBG(printf("find DTS sync header(16bit big endian) and frame size is :0x%lx\n",u32FrameSize));
                                if(u32SampleRateIndex > 15)
                                {
                                    WAV_DBG(printf("Invalid DTS sample rate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }

                                if(u32BitRateIndex > 31)
                                {
                                    WAV_DBG(printf("Invalid DTS bitrate index:0x%lx\n",u32SampleRateIndex));
                                    stWavChunkLocal.bIsDTS = FALSE;
                                    break;
                                }
                                stWavChunkLocal.bIsDTS = TRUE;
                                break;
                            }
                            offset++;
                        }

                        if(stWavChunkLocal.bIsDTS)
                        {
                            stWavChunkLocal.u32SamplesPerSec = DTS_Sample_Rates[u32SampleRateIndex];
                            stWavChunkLocal.u32AvgBytesPerSec = DTS_Bit_Rates[u32BitRateIndex]>>3;
                            pstMusicProbeInfo->u16SampleRate = (U16)(stWavChunkLocal.u32SamplesPerSec);
                            pstMusicProbeInfo->u16BitRate = (U16)((stWavChunkLocal.u32AvgBytesPerSec<<3)/1000);

                            if(u32InfoAttr & E_MUSIC_INFO_DURATION)
                            {
                                pstMusicProbeInfo->u32Duration =  (U16)(stWavChunkLocal.u32DataChunkSize/stWavChunkLocal.u32AvgBytesPerSec);
                                WAV_DBG(printf("DTS u32Duration:0x%lx\n",pstMusicProbeInfo->u32Duration));

                            }
                            WAV_DBG(printf("DTS u32SamplesPerSec:%lu\n",stWavChunkLocal.u32SamplesPerSec));
                            WAV_DBG(printf("DTS u32AvgBytesPerSec:0x%lx\n",stWavChunkLocal.u32AvgBytesPerSec));
                        }
                    }
                }
            }
            else
            {
                WAV_DBG(printf("sample rate is not supported!n"));
            }
        }
    }
    return bRet;
}
#endif

#ifndef min
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

BOOLEAN MApp_Music_MP3_Probe(U32 u32Hdl, ST_MUSIC_PROBE_INFO *pstMusicProbeInfo, U32 u32InfoAttr)
{
    U32 u32Offset;
    U32 u32FileHandle = u32Hdl;
    U32 u32Addr;
    U32 u32FirstFrameOffset;

    //Check pProbeInfo is valid or not
    if(pstMusicProbeInfo == NULL)
    {
        MUSIC_DBG(printf(" ---> MApp_Music_MP3_Probe() Error  !!!  ( pstMusicProbeInfo == NULL ) \n"));
        return FALSE;
    }

    if(u32Hdl == INVALID_DATA_STREAM_HDL)
    {
        MUSIC_DBG(printf("u32Hdl is INVALID\n"));
        return FALSE;
    }
    //#define BUFFERSIZE  MUSIC_LYRIC_TAG_LEN
    //u32Addr = ((MUSIC_LYRIC_BUFFER_MEMORY_TYPE & MIU1) ? (MUSIC_LYRIC_BUFFER_ADR | MIU_INTERVAL) : (MUSIC_LYRIC_BUFFER_ADR));
    //#define BUFFERSIZE  M4A_STCO_LEN
    //u32Addr = ((M4A_STCO_MEMORY_TYPE & MIU1) ? (M4A_STCO_ADR | MIU_INTERVAL) : (M4A_STCO_ADR));
    #define BUFFERSIZE  MP3_INFO_READ_LEN
    u32Addr = ((MP3_INFO_READ_MEMORY_TYPE & MIU1) ? (MP3_INFO_READ_ADR | MIU_INTERVAL) : (MP3_INFO_READ_ADR));

    ST_MP3_INFO stMp3InfoLocal;
    memset(pstMusicProbeInfo, 0, sizeof(ST_MUSIC_PROBE_INFO));
    memset(&stMp3InfoLocal, 0, sizeof(ST_MP3_INFO));

    // get MP3 ID3 v1 information
    stMp3InfoLocal.u16ID3TagV1Size = MP3_ID3_V1_LEN;
    stMp3InfoLocal.u32FileSize = msAPI_DataStreamIO_Length(u32FileHandle);

    if(stMp3InfoLocal.u32FileSize > MP3_ID3_V1_LEN)
    {
        u32Offset = (stMp3InfoLocal.u32FileSize - MP3_ID3_V1_LEN);
        if(msAPI_DataStreamIO_Seek(u32FileHandle, u32Offset, E_DATA_STREAM_SEEK_SET) == FALSE)
        {
            printf("MApp_Music_MP3_Probe() ---> File seek Fail-1 \n");
            return FALSE;
        }

        msAPI_DataStreamIO_Read(u32FileHandle, (void*)u32Addr, MP3_ID3_V1_LEN);
        stMp3InfoLocal.bID3TagV1= msAPI_Music_Parse_ID3v1(u32Addr, &stMp3InfoLocal.stID3v1);
    }
    // get MP3 ID3 v2 information
    if(msAPI_DataStreamIO_Seek(u32FileHandle, 0, E_DATA_STREAM_SEEK_SET) == FALSE)
    {
        printf("MApp_Music_MP3_Probe() ---> File seek Fail-2 \n");
        return FALSE;
    }

    msAPI_DataStreamIO_Read(u32FileHandle, (void*)u32Addr, BUFFERSIZE);
    u32Offset = msAPI_Music_Parse_ID3v2(u32FileHandle,u32Addr, BUFFERSIZE, &stMp3InfoLocal.stID3v2, FALSE);

    if(u32Offset != 0) //Fix double ID3 tag ex:h-.mp3
    {
        stMp3InfoLocal.bID3TagV2 = TRUE;
        if(msAPI_DataStreamIO_Seek(u32FileHandle, u32Offset, E_DATA_STREAM_SEEK_SET) == FALSE)
        {
            printf("MApp_Music_MP3_Probe() ---> File seek Fail-3 \n");
            return FALSE;
        }

        msAPI_DataStreamIO_Read(u32FileHandle, (void*)u32Addr, BUFFERSIZE);
        u32Offset += msAPI_Music_Parse_ID3v2(u32FileHandle,u32Addr, BUFFERSIZE, &stMp3InfoLocal.stID3v2, TRUE);
    }
    stMp3InfoLocal.u32ID3TagV2Size = u32Offset;

    if ( u32InfoAttr & E_MUSIC_INFO_DURATION )
    {
        //Skip Garbage.
        MUSIC_DBG(printf("1 pMp3Info->u32ID3TagV2Size=0x%ld\n",stMp3InfoLocal.u32ID3TagV2Size));
        u32FirstFrameOffset = MApp_Music_SearchFirstFrame(u32FileHandle, stMp3InfoLocal.u32ID3TagV2Size);
        if(u32FirstFrameOffset == MUSIC_CANNOT_FIND_1ST_FRAME)
        {
            MUSIC_DBG(printf("!!!! Fail: Can not search 1st Frame!!!!\n"));
            _enMusic_ErrCode = E_MUSIC_ERR_DECODE_HEADER_FAILURE;
            return FALSE;
        }
        else
        {
            stMp3InfoLocal.u32ID3TagV2Size += u32FirstFrameOffset;
        }
        MUSIC_DBG(printf("2 pMp3Info->u32ID3TagV2Size=0x%ld\n",stMp3InfoLocal.u32ID3TagV2Size));

        // get MP3 layer, bitrate, etc.
        msAPI_Stream_Seek(u32FileHandle, stMp3InfoLocal.u32ID3TagV2Size);

        msAPI_DataStreamIO_Read(u32FileHandle, (void*)(u32Addr), MP3_INFO_READ_LEN);
        stMp3InfoLocal.u32Duration = msAPI_Music_GetFileTime(
                                    u32Addr,
                                    stMp3InfoLocal.u32FileSize,
                                    &stMp3InfoLocal.enVersion,
                                    &stMp3InfoLocal.enLayer,
                                    &stMp3InfoLocal.u16BitRate,
                                    &stMp3InfoLocal.u16SampleRate,
                                    &stMp3InfoLocal.u8Flag,
                                    &stMp3InfoLocal.u16TOCLength,
                                    &stMp3InfoLocal.u8TOC[0]);

        if(stMp3InfoLocal.u32Duration == 0)
        {
            stMp3InfoLocal.u32Duration = MApp_Music_CalculateMP3CBRDuration(&stMp3InfoLocal, u32FileHandle);
        }
    }

    if(stMp3InfoLocal.bID3TagV2 == TRUE)
    {
        MUSIC_DBG(printf("stMp3InfoLocal.bID3TagV2 is TURE\n"));
            memcpy(pstMusicProbeInfo->u8Album,&stMp3InfoLocal.stID3v2.album,min(sizeof(pstMusicProbeInfo->u8Album),sizeof(stMp3InfoLocal.stID3v2.album)));
            memcpy(pstMusicProbeInfo->u8Artist,&stMp3InfoLocal.stID3v2.artist,min(sizeof(stMp3InfoLocal.stID3v2.artist),sizeof(pstMusicProbeInfo->u8Artist)));
            memcpy(pstMusicProbeInfo->u8Year,&stMp3InfoLocal.stID3v2.year,min(sizeof(stMp3InfoLocal.stID3v2.year),sizeof(pstMusicProbeInfo->u8Year)));
            memcpy(pstMusicProbeInfo->u8Title,&stMp3InfoLocal.stID3v2.title,min(sizeof(stMp3InfoLocal.stID3v2.title),sizeof(pstMusicProbeInfo->u8Title)));
        pstMusicProbeInfo->u32PicOffset= stMp3InfoLocal.stID3v2.jpgOffset;
        pstMusicProbeInfo->u32PicSize= stMp3InfoLocal.stID3v2.jpgSize;
    }
    else if(stMp3InfoLocal.bID3TagV1 == TRUE)
    {
        MUSIC_DBG(printf("stMp3InfoLocal.bID3TagV1 is TURE\n"));
        memcpy(pstMusicProbeInfo->u8Album,&stMp3InfoLocal.stID3v1.album,min(sizeof(stMp3InfoLocal.stID3v1.album),sizeof(pstMusicProbeInfo->u8Album)));
        memcpy(pstMusicProbeInfo->u8Artist,&stMp3InfoLocal.stID3v1.artist,min(sizeof(stMp3InfoLocal.stID3v1.artist),sizeof(pstMusicProbeInfo->u8Artist)));
        memcpy(pstMusicProbeInfo->u8Year,&stMp3InfoLocal.stID3v1.year,min(sizeof(stMp3InfoLocal.stID3v1.year),sizeof(pstMusicProbeInfo->u8Year)));
        memcpy(pstMusicProbeInfo->u8Title,&stMp3InfoLocal.stID3v1.title,min(sizeof(stMp3InfoLocal.stID3v1.title),sizeof(pstMusicProbeInfo->u8Title)));
        pstMusicProbeInfo->u32PicOffset= stMp3InfoLocal.stID3v1.jpgOffset;
        pstMusicProbeInfo->u32PicSize= stMp3InfoLocal.stID3v1.jpgSize;
    }
    pstMusicProbeInfo->u16BitRate  = stMp3InfoLocal.u16BitRate;
    pstMusicProbeInfo->u16SampleRate= stMp3InfoLocal.u16SampleRate;
    if ( u32InfoAttr & E_MUSIC_INFO_DURATION )
    {
        pstMusicProbeInfo->u32Duration= stMp3InfoLocal.u32Duration;
    }
    return TRUE;
}
#endif  // #if ENABLE_MPLAYER_MUSIC
#endif  // #if (ENABLE_DMP)
#undef MAPP_MUSIC_C

