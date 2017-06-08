#include "cpptest.h"

/**
 * This file contains user stub definitions.
 *
 * To create a user stub:
 * 1. Open stub template list:
 *    - Eclipse IDE: type 'stub' and press <Ctrl> <Space>
 *    - Microsoft Visual Studio IDE: use context menu C++test->Insert Snippet...
 * 2. Choose the stub template from the list.
 * 3. #include the header file where the function you want to stub is originally
 *    declared as well as any supporting header files as necessary.
 * 4. Fill out the stub signature to match that of the original function,
 *    while keeping the CppTest_Stub prefix when it applies.
 *    Note: for C++ operators, use appropriate stub names - e.g.:
 *        CppTest_Stub_operator_new    for operator new
 *        CppTest_Stub_operator_delete for operator delete
 *        CppTest_Stub_operator_plus   for operator +
 *    Refer to C++test User's Guide for a complete list of stub names for operators.
 * 5. Fill out the body of the stub according to intent.
 *
 * Available C++test API functions (see C++test Users Guide for details):
 *     void CppTest_Assert(bool test, const char * message)
 *     void CppTest_Break()
 *     const char* CppTest_GetCurrentTestCaseName()
 *     const char* CppTest_GetCurrentTestSuiteName()
 *     bool CppTest_IsCurrentTestCase(const char* testCaseName)
 */

/**
 * Header files where the stubbed functions are originally declared.
 * Verify #include directives and add any additional header files as necessary.
 */

//-------------------------------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "sysinfo.h"
#include "datatype.h"
#include "ctype.h"
#include "SysInit.h"
#include "msAPI_DataStreamIO.h"
#include "msAPI_Music.h"
#include "mapp_music.h"
#include "msAPI_MIU.h"
#include "msAPI_Memory.h"
#include "msAPI_Flash.h"
#include "msAPI_WMA.h"
#include "mapp_wma.h"
#include "msAPI_MailBox.h"
#include "MApp_Scaler.h"
#include "apiXC_Sys.h"
#include "MApp_XC_PQ.h"
#include "mapp_photo.h"
#include "msAPI_OSD.h"
#include "mapp_mplayer_subtitle.h"
#include "mapp_videoplayer.h"
#include "apiAUDIO.h"
#include <stdlib.h>
#include "msAPI_FCtrl.h"
#include "MApp_FileBrowser.h"
#include "mapp_mplayer.h"
#include "MApp_SaveData.h"
#ifdef MSOS_TYPE_LINUX
#include "MsIRQ.h"
#include "MsOS.h"
#endif
#include "msAPI_Memory.h"
#include "msAPI_MIU.h"
#include "msAPI_MPEG_Subtitle.h"
#include "msAPI_FCtrl.h"
#include "msAPI_Timer.h"
#include "apiPNL.h"
#include "MApp_UiMediaPlayer_Define.h"
#include "mapp_mplayer.h"
#include "mapp_mplayer_subtitle.h"
#include "mapp_videoplayer.h"
#include "apiGOP.h"
#include "msAPI_DataStreamIO.h"
#include "MApp_ZUI_ACTdmp.h"
#include "mapp_digitalmedia.h"

#ifndef U64
typedef unsigned long long U64;
#endif


typedef struct
{
    U16 u16FormatTag;
    U8 u8Version;
    U16 u16Channels;
    U16 u16BlockAlign;
    U16 u16BitsSample;
    U32 u32ChannelMask;
    U16 u16Encopt;
    U32 u32BitRate;
    U32 u32ByteRate;
    U32 u32SampleRate;
    U32 u32HeaderSize;
    U32 u32PacketSize;             //Packet = Error Correction Data + Payload Parsing Information + Payload Data + Padding
    U16 u16PacketOffset;
    U16 u16PayloadOffset;
    U32 u32TotalPacket;
#if ENABLE_WMA_INDEX_TABLE
    U32 u32SkipPayload;
#else
    U32 u32SkipPacket;
#endif
    U32 u32FileSize;
    U32 u32Duration;
#if ENABLE_WMA_INDEX_TABLE
    U32 u32PreRoll;
#endif
    U32 u32CurrentPlayTime;
    U32 u32PlayTimer;
    U8 u8Title[128];
    U8 u8Author[128];
    U8 u8Year[32];
    U8 u8Album[128];
#if ENABLE_ASF_PARSING
    //--  WMA DRC Info -- //
    U32 u32WMADRCPeakReference;
    U32 u32WMADRCPeakTarget;
    U32 u32WMADRCAverageReference;
    U32 u32WMADRCAverageTarget;
    //------------------//
    //--  Error correction data (Property Flag) --//
    U32 u32ErrorCLength;                  //Error Correction Length
    //------------------------------------//
    //--  Payload parsing information (Length Type Flags) --//
    BOOLEAN bIsMultiPayloads;
    U8 u8SequenceLType;            //Sequence Length Type
    U8 u8PaddingLType;               //Padding Length Type
    U8 u8PacketLType;                //Packet Length Type
    U32 u32SequenceLength;            //Sequence Length
    U32 u32PaddingLength;               //Padding Length
    //----------------------------------------------//
    //--  Payload parsing information (Property Flag) --//
    U8 u8ReplicatedDLType;         //Replicated Data Length Type                  00:0  01:1  10:2  11:3
    U8 u8OffseIMOLType;             //Offset Into Media Object Length Type       0      8     16     32   (bits)
    U8 u8MediaONLType;             //Media Object Number Length Type
    U8 u8StreamNLType;             //Stream Number Length Type
    U32 u32ReplicatedDLength;         //Replicated Data Length
    U32 u32OffseIMOLength;             //Offset Into Media Object Length
    U32 u32MediaONLengthe;            //Media Object Number Length
    U32 u32StreamNLength;             //Stream Number Length
    //-----------------------------------------//
    //--  Payload information  --//
    U8 u8NumPayloads;                  //Number of Payloads
    U8 u8PayloadLType;                  //Payload Length Type
    U32 u32PayloadLength;                  //Payload Length
    U8 u8PresentationTimeDelta;        //Presentation Time Delta
#if ENABLE_WMA_INDEX_TABLE
    U8 u8FirstNumPayloads;               //Number of Payloads in 1st Packet
    U32 u32TotalPayloads;               //Number of Total Payloads in this file
#endif
    //-----------------------//
#endif
    BOOLEAN bCheckFfFb;
    BOOLEAN bHeaderFound;
    BOOLEAN bHeaderExtensionFound;
    BOOLEAN bHE_MetadataObjectFound;
    BOOLEAN bWMADRCFound;
    BOOLEAN bStreamFound;
    BOOLEAN bContentFound;
    BOOLEAN bExContentFound;             // Extended Content Description Object, it is optional
    BOOLEAN bDataObjectFound;
    BOOLEAN bExContentEObjectFound; //Extended Content Encryption Object
    U32 u32ExContentEObjectLocation;
    U32 u32ExContentEObjectSize;
    BOOLEAN bContentEObjectFound; //Content Encryption Object
    U32 u32ContentEObjectLocation;
    U32 u32ContentEObjectSize;
    BOOLEAN bFilePropertiesFound;
    BOOLEAN bAdvancedMutualExclusionObject;
    U8 u8StreamNumber;
    U8 u8CurrentStreamIndex;
    U16 u16StreamID[128];
    U16 u16CurrentStreamId;
} ST_WMA_INFO;

typedef struct
{
    U32 u32WMAPayloadPTime;
    U32 u32WMAPayloadFilePos;
} ST_WMA_INDEX_TABLE;

typedef enum
{
    E_PHOTO_DECODE     = 0,
    E_PHOTO_ENCODE,
} EN_PHOTO_CMD;

typedef enum
{
    E_UART_SWITCH_HK,
    E_UART_SWITCH_CP,
    E_UART_SWITCH_NUM,
} EN_PHOTO_UART_SWITCH;


#define E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_DATASIZE  (64)
#define E_STILLIMAGE_SHAREMEM_SIZE                                     (255)

typedef enum
{
    /****************************************
        General parameters
    ****************************************/
    E_STILLIMAGE_SHAREMEM_VERSION_NUM,
    E_STILLIMAGE_SHAREMEM_MIU,
    E_STILLIMAGE_SHAREMEM_CMD,
    E_STILLIMAGE_SHAREMEM_WDT_LOOP,

    /****************************************
        Decoder related
    ****************************************/
    /****************************************
        Decoder input options
    ****************************************/
    // general min supported width/height
    E_STILLIMAGE_SHAREMEM_MIN_WIDTH,
    E_STILLIMAGE_SHAREMEM_MIN_HEIGHT,

    // max supported width/height for baseline JPEG
    E_STILLIMAGE_SHAREMEM_JPEG_BASELINE_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_JPEG_BASELINE_MAX_HEIGHT,

    // max supported width/height of progressive jpeg
    E_STILLIMAGE_SHAREMEM_JPEG_PROGRESSIVE_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_JPEG_PROGRESSIVE_MAX_HEIGHT,

    // max supported width/height for BMP
    E_STILLIMAGE_SHAREMEM_BMP_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_BMP_MAX_HEIGHT,

    // max supported width/height for PNG
    E_STILLIMAGE_SHAREMEM_PNG_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_PNG_MAX_HEIGHT,

    // max supported width/height for TIFF
    E_STILLIMAGE_SHAREMEM_TIFF_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_TIFF_MAX_HEIGHT,

    // max supported width/height for TIFF
    E_STILLIMAGE_SHAREMEM_GIF_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_GIF_MAX_HEIGHT,

    // max supported width/height for MPO with subjpeg is baseline
    E_STILLIMAGE_SHAREMEM_MPO_BASELINE_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_MPO_BASELINE_MAX_HEIGHT,

    // max supported width/height for MPO with subjpeg is progressive
    E_STILLIMAGE_SHAREMEM_MPO_PROGRESSIVE_MAX_WIDTH,
    E_STILLIMAGE_SHAREMEM_MPO_PROGRESSIVE_MAX_HEIGHT,

    // if decode thumbnail
    E_STILLIMAGE_SHAREMEM_DECODE_THUMBNAIL,

    // buffer for input data
    E_STILLIMAGE_SHAREMEM_INPUT_DATA_BUFF_ADDR,
    E_STILLIMAGE_SHAREMEM_INPUT_DATA_BUFF_LEN,

    // buffer for output data
    E_STILLIMAGE_SHAREMEM_OUTPUT_DATA_BUFF_ADDR,
    E_STILLIMAGE_SHAREMEM_OUTPUT_DATA_BUFF_LEN,

    // buffer for progressive jpeg
    E_STILLIMAGE_SHAREMEM_PROGRESSIVE_BUFF_ADDR,
    E_STILLIMAGE_SHAREMEM_PROGRESSIVE_BUFF_LEN,

    // buffer for memory pool
    E_STILLIMAGE_SHAREMEM_MEM_POOL_BUFF_ADDR,
    E_STILLIMAGE_SHAREMEM_MEM_POOL_BUFF_LEN,

    // how input data is accessed, eg, mailbox, network or storage direct access
    E_STILLIMAGE_SHAREMEM_DATA_ACCESS_METHOD,


    /****************************************
        Decoder output results
    ****************************************/
    // the error code
    E_STILLIMAGE_SHAREMEM_ERROR,

    // the progress of current job, 0 ~ 1000
    E_STILLIMAGE_SHAREMEM_PROGRESS,

    // input data format, JPEG/BMP/PNG or something else
    E_STILLIMAGE_SHAREMEM_INPUT_DATA_FORMAT,

    // output image width/height/pitch/size
    E_STILLIMAGE_SHAREMEM_OUTPUT_PITCH,
    E_STILLIMAGE_SHAREMEM_OUTPUT_WIDTH,
    E_STILLIMAGE_SHAREMEM_OUTPUT_HEIGHT,
    E_STILLIMAGE_SHAREMEM_OUTPUT_SIZE,

    // original image width/height
    E_STILLIMAGE_SHAREMEM_IMAGE_WIDTH,
    E_STILLIMAGE_SHAREMEM_IMAGE_HEIGHT,

    // output image format, YUV422/ARGB8888 or something else
    E_STILLIMAGE_SHAREMEM_OUTPUT_IMAGE_FORMAT,

    // if input data contains thumbnail
    E_STILLIMAGE_SHAREMEM_HAS_THUMBNAIL,

    // the scale down factor performed by decoder
    E_STILLIMAGE_SHAREMEM_SCALE_DOWN_FACTOR,

    // the orientation specified in image info
    E_STILLIMAGE_SHAREMEM_OIRENTATION,

    // the date time in image info
    E_STILLIMAGE_SHAREMEM_HAS_DATE_TIME,
    E_STILLIMAGE_SHAREMEM_DATE_TIME_YEAR,
    E_STILLIMAGE_SHAREMEM_DATE_TIME_MONTH,
    E_STILLIMAGE_SHAREMEM_DATE_TIME_DAY,
    E_STILLIMAGE_SHAREMEM_DATE_TIME_HOUR,
    E_STILLIMAGE_SHAREMEM_DATE_TIME_MINUTE,
    E_STILLIMAGE_SHAREMEM_DATE_TIME_SECOND,

    //if it is stream mode
    E_STILLIMAGE_SHAREMEM_IS_STREAM_MODE,
    E_STILLIMAGE_SHAREMEM_STREAM_MODE_READ_TIME_OUT,    // milli-second

    //gif relate
    E_STILLIMAGE_SHAREMEM_DECODED_FRAME_INDEX,
    E_STILLIMAGE_SHAREMEM_DISPLAYED_FRAME_INDEX,
    E_STILLIMAGE_SHAREMEM_FRAME_INFO_ARRAY_ADDR,
    E_STILLIMAGE_SHAREMEM_FRAME_INFO_ARRAY_SIZE,
    E_STILLIMAGE_SHAREMEM_SLOT_NUM,
    E_STILLIMAGE_SHAREMEM_FRAME_SIZE,
    E_STILLIMAGE_SHAREMEM_ONLY_DECODE_FIRST_FRAME,
    E_STILLIMAGE_SHAREMEM_ONLY_PLAY_FIRST_LOOP_FOR_ANIMATION,
    E_STILLIMAGE_SHAREMEM_GIF_ANIMATION_LOOP_TIMES,

    //Jpeg exif width and height
    E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_WIDTH,
    E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_HEIGHT,
    //jpeg exif data, ref ST_STILLIMAGE_JPEG_EXIF
    E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_DATA,
    E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_DATA_END = E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_DATA + E_STILLIMAGE_SHAREMEM_OUTPUT_JPEG_EXIF_DATASIZE,

    /****************************************
        Encoder related
    ****************************************/

    /****************************************
        Functionality control
    ****************************************/
    E_STILLIMAGE_SHAREMEM_CONTORL_FLAGS,

    /****************************************
        max
    ****************************************/
    E_STILLIMAGE_SHAREMEM_NUM = E_STILLIMAGE_SHAREMEM_SIZE,
} EN_STILLIMAGE_SHAREMEMORY;

typedef enum
{
    E_PHOTO_TIMER_INIT = 0,
    E_PHOTO_TIMER_START,
    E_PHOTO_TIMER_STOP,
    E_PHOTO_TIMER_DECODE,

    E_PHOTO_TIMER_WDT,      // watch dog timer
    E_PHOTO_TIMER_PROGRESS, // timer used to check progress

    E_PHOTO_TIMER_MBX_MSG,

    E_PHOTO_TIMER_NUM,
} EN_PHOTO_TIMER;

typedef enum
{
    E_PARSE_ONE_SUBTITLE_DONE=0,
    E_PARSE_ONE_SUBTITLE_FAIL,
    E_PARSE_ONE_SUBTITLE_FILE_END,
    E_PARSE_ONE_SUBTITLE_TIME_OUT,
} EN_PARSE_ONE_SUBTITLE_RET;

typedef enum
{
    E_MPLAYER_FOREGROUND_PLAYER           = 0,
#if ENABLE_BGM
    E_MPLAYER_BACKGROUND_PLAYER,
#else
    E_MPLAYER_BACKGROUND_PLAYER           = E_MPLAYER_FOREGROUND_PLAYER,
#endif // #if ENABLE_BGM
    E_MPLAYER_MAX_CONCURRENT_PLAYER_NUM,
} enumMPlayerIdx;

#define MAX_VIDEO_TRACKS            (1)
#define MAX_AUDIO_TRACKS            (10)

typedef struct
{
    U64 u64IdxOffset;
    U32 u32Size;
} ST_OPEN_DML_IDX_INFO, *PST_OPEN_DML_IDX_INFO;

typedef struct
{
    ST_OPEN_DML_IDX_INFO *pstOpenDmlIdxInfo;
    U32 u32Cnt;
} ST_OPEN_DML_IDX_HEADER_INFO, *PST_OPEN_DML_IDX_HEADER_INFO;

typedef union
{
    struct
    {
        U32 u32Scale;               // AVI                      : MP2/ MP3
        U32 u32Rate;                // AVI                      : MP3
        U32 u32SampleSize;          // AVI/ RM                  : MP2/ MP3
        U32 u32BlockAlign;          // AVI                      : MP2/ MP3/ ADPCM
        U32 u32BitRate;             // AVI/ RM/ MPG             : MP2
        U32 u32Channel;
        U32 u32SamplesPerBlock;
        U32 u32SampleRate;
    } stMPEG;

    struct
    {
        U32 u32SampleRate;          // AVI/ MOV/ MKV/ RM/ MPG   : AAC/ PCM/ ADPCM
        U32 u32ObjectTypeID;        // AVI/ MOV/ MKV            : AAC
        U32 u32ChannelConfig;       // AVI/ MOV/ MKV            : AAC
        U32 u32BitRate;
    } stAAC;

    struct
    {
        U32 u32Channel;             // AVI/ MOV/ MKV/ RM/ MPG   : PCM/ ADPCM
        U32 u32SampleRate;          // AVI/ MOV/ MKV/ RM/ MPG   : AAC/ PCM/ ADPCM
        U32 u32BitsPerSample;       // AVI/ MOV/ MKV/ MPG       : PCM/ ADPCM
        U32 u32BitRate;
    } stPCM;

    struct
    {
        U32 u32Channel;             // AVI/ MOV/ MKV/ RM/ MPG   : PCM/ ADPCM
        U32 u32SampleRate;          // AVI/ MOV/ MKV/ RM/ MPG   : AAC/ PCM/ ADPCM
        U32 u32BlockAlign;          // AVI                      : MP2/ MP3/ ADPCM
        U32 u32BitsPerSample;       // AVI/ MOV/ MKV/ MPG       : PCM/ ADPCM
        U32 u32SamplesPerBlock;     // AVI/ MPG                 : ADPCM
    } stADPCM;

    struct
    {
        U32 u32Audio_Frame_Time;    //                          : AC3/ EAC3
        U16 u16Audio_Frame_TimeBase;//                          : AC3/ EAC3
        U16 u16Frame_Size;          //                          : AC3/ EAC3
        U32 u32BitRate;
        U32 u32SampleRate;
        U32 u32Channel;
        U8  u8ParsingCnt;
    } stAC3;

    struct
    {
        U32 u32Channel;
        U32 u32SampleRate;
    } stCOOK;

    struct
    {
        U32 u32Audio_Frame_Time;    //                          : DTS
        U16 u16Audio_Frame_TimeBase;//                          : DTS
        U16 u16Frame_Size;          //                          : DTS
    } stDTS;

    struct
    {
        U32 u8Version;
        U32 u32Channel;
        U32 u32SampleRate;
        U32 u32ByteRate;
        U32 u32BlockAlign;
        U16 u16EncodeOpt;
        U16 u16AdvanceEncodeOpt;
        U32 u32BitsPerSample;
        U32 u32ChannelMask;
        //--  WMA DRC Info -- //
        BOOL bWMADRCExist;
        U32 u32WMADRCPeakReference;
        U32 u32WMADRCPeakTarget;
        U32 u32WMADRCAverageReference;
        U32 u32WMADRCAverageTarget;
    } stWMA;

    struct
    {
        U16 u16HeaderSize;
        U32 u32HeaderAddr;
    } stVorbis;

    struct
    {
        U32 u32Channel;
        U32 u32SampleRate;
        U32 u32BitsPerSample;
        U32 u32BitRate;
        U32 u32FramePerSample;
        U32 u32BitsPerSec;
    } stAMR;
} UN_VDP_AUDIO_PARAM;

typedef struct
{
    UN_VDP_AUDIO_PARAM unAudioParam[MAX_AUDIO_TRACKS];
    EN_VDP_CODECID enAudioCodecID[MAX_AUDIO_TRACKS];
    PST_OPEN_DML_IDX_HEADER_INFO pstOpenDmlIdxHeaderInfo;
    U64 u64FileSize;
    U32 u32FirstMoviStartPos;
    U32 u32FirstMoviEndPos;
    U32 u32FirstRiffEndPos;
    U32 u32BitstreamAddr;
    U32 u32BitstreamSize;
    U32 u32IndexBuffAddr;
    U32 u32IndexBuffSize;
    U32 u32KeyIdxPeriod;
    U32 u32FrameRate;
    U32 u32FrameRateBase;
    U32 u32Video_IdxSize;
    U32 u32FirstVideoKeyFramePTS;
    U32 u32lastVideoKeyFramePTS;
    S8  s8Video_StreamId;
    S8  s8Audio_StreamId;
    U8  u8Nb_VideoTracks;
    U8  u8Nb_AudioTracks;
    U8  u8AudioTrackIDMap[MAX_AUDIO_TRACKS];
    U8  u8KeyIdxSize;
    U8  u8ThumbNailMode;
    /// Audio key frame buffer address
    U32 u32AudioKeyBufAddr[MAX_AUDIO_TRACKS];
    /// Audio key frame buffer size
    U32 u32AudioKeyBufSize[MAX_AUDIO_TRACKS];
    /// Audio key frame index size
    U32 u32Audio_IdxSize[MAX_AUDIO_TRACKS];
    /// Audio key index period
    U32 u32AudioKeyIdxPeriod;
    /// Audio key index size
    U8  u8AudioKeyIdxSize;
    /// has enable to use BitRate to calculate PTS
    BOOL bEnableCalcByBitRate;
    /// has enable Audio Handler or not
    BOOL bEnableAudioHandler;
} ST_HK_AVI_SCAN, *PST_HK_AVI_SCAN;

typedef enum
{
    E_AVI_DEMUX_SUCCESS = 0,
    E_AVI_DEMUX_ERR_FILE_OPEN_FAILED,
    E_AVI_DEMUX_ERR_UNSUPPORT,
    E_AVI_DEMUX_ERR_INIT_TIMEOUT,
    E_AVI_DEMUX_ERR_DEMUX_HEADER,
    E_AVI_DEMUX_ERR_DEMUX,
    E_AVI_DEMUX_ERR_INDEX,
} EN_AVI_DEMUX_RETURN;

/** User stub definition for function: U16 _MApp_MPlayer_ScanHex(U8 *, U32 *) */
EXTERN_C_LINKAGE U16 _MApp_MPlayer_ScanHex (U8 * pu8Data, U32 * pu32Val) ;
EXTERN_C_LINKAGE U16 CppTest_Stub__MApp_MPlayer_ScanHex (U8 * pu8Data, U32 * pu32Val)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_Input_String_0x1234"))
  {
    *pu32Val=0x1234;
    return 4;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_ScanfIdxPos_return_FALSE"))
  {
        return 0xFFFF;
  }

}

/** User stub definition for function: BOOLEAN msAPI_DataStreamIO_Close(U32) */
EXTERN_C_LINKAGE BOOLEAN msAPI_DataStreamIO_Close (U32 u32Hdl) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_DataStreamIO_Close (U32 u32Hdl)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_CloseFile"))
  {
        return (unsigned char)0;
  }

  return (unsigned char)0;
}

/** User stub definition for function: U32 msAPI_DataStreamIO_Open(void *, U8, E_DATA_STREAM_TYPE) */
EXTERN_C_LINKAGE U32 msAPI_DataStreamIO_Open (void * pPrivate, U8 u8Mode, E_DATA_STREAM_TYPE eType) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_DataStreamIO_Open (void * pPrivate, U8 u8Mode, E_DATA_STREAM_TYPE eType)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseInvalid"))
  {
        return INVALID_DATA_STREAM_HDL;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid"))
  {
    return 0;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_OpenFile_enCurrentMusicType_MP3_FAIL"))
  {
    return INVALID_DATA_STREAM_HDL;
  }
  return 0;

}

/** User stub definition for function: BOOLEAN msAPI_DataStreamIO_Seek(U32, U32, E_DATA_STREAM_SEEK_OPTION) */
EXTERN_C_LINKAGE BOOLEAN msAPI_DataStreamIO_Seek (U32 u32Hdl, U32 u32Pos, E_DATA_STREAM_SEEK_OPTION eOption) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_DataStreamIO_Seek (U32 u32Hdl, U32 u32Pos, E_DATA_STREAM_SEEK_OPTION eOption)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid"))
  {
        return (unsigned char)0;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1"))
  {
        return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_PushMovieSubtitleSUB"))
  {
        return (unsigned char)1;
  }
}

/** User stub definition for function: U32 msAPI_DataStreamIO_Read(U32, void *, U32) */
EXTERN_C_LINKAGE U32 msAPI_DataStreamIO_Read (U32 u32Hdl, void * pBuffAddr, U32 u32Length) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_DataStreamIO_Read (U32 u32Hdl, void * pBuffAddr, U32 u32Length)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid"))
    {
        return 0UL;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_MP3"))
  {
      return 2UL;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_LOAS"))
  {
      return 2UL;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ParseFlac_SeekTable_case1"))
    {
        return 4078UL;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Flac_DataInput_case1"))
    {
        return 2UL;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Wav_DataInput"))
    {
        return 2UL;
    }
    else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_PCM_DataInput"))
    {
        return 2UL;
    }


   return 0UL;
}

/** User stub definition for function: U32 msAPI_Music_Parse_ID3v2(U32, U32, U32, MP3_INFO *, BOOLEAN) */
EXTERN_C_LINKAGE U32 msAPI_Music_Parse_ID3v2 (U32 u32FileHandle, U32 u32FileBuffAddr, U32 u32FileBuffLen, MP3_INFO * pMp3InfoPtr, BOOLEAN bGetMp3OffsetOnly) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Music_Parse_ID3v2 (U32 u32FileHandle, U32 u32FileBuffAddr, U32 u32FileBuffLen, MP3_INFO * pMp3InfoPtr, BOOLEAN bGetMp3OffsetOnly)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_AAC_Frame_Parsing_u32Mp3FileHandle_caseValid"))
    {
        return 1UL;
    }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_CollectInfo_case1"))
  {
    return 2UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1"))
  {
    return 2UL;
  }
}

/** User stub definition for function: BOOLEAN MApp_Music_CollectInfo(ST_MP3_INFO *) */
EXTERN_C_LINKAGE BOOLEAN MApp_Music_CollectInfo (ST_MP3_INFO * pMp3Info) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Music_CollectInfo (ST_MP3_INFO * pMp3Info)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_LAYER3"))
  {
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_MP3_FAIL"))
    {
        return (unsigned char)0;
    }

}

/** User stub definition for function: BOOLEAN MApp_AAC_Frame_Parsing(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_AAC_Frame_Parsing (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_AAC_Frame_Parsing (void)
{
    return (unsigned char)1;
}

/** User stub definition for function: void msAPI_Music_FileEndDataHandle(U32) */
EXTERN_C_LINKAGE void msAPI_Music_FileEndDataHandle (U32 u32DataLeft) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_FileEndDataHandle (U32 u32DataLeft)
{
}

/** User stub definition for function: BOOLEAN M4AParser_Get_M4A_Info(BoxInfo *) */
EXTERN_C_LINKAGE BOOLEAN M4AParser_Get_M4A_Info (BoxInfo * boxInfo) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_M4AParser_Get_M4A_Info (BoxInfo * boxInfo)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a"))
  {
    boxInfo->bFoundstco  = 1;
    return (unsigned char)1;
  }

  return (unsigned char)0;
}

/** User stub definition for function: void msAPI_Music_SetSampleRateIndex(U16) */
EXTERN_C_LINKAGE void msAPI_Music_SetSampleRateIndex (U16 u16Index) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_SetSampleRateIndex (U16 u16Index)
{
}

/** User stub definition for function: void msAPI_MIU_Clear(U8, U32, U32, U8) */
EXTERN_C_LINKAGE void msAPI_MIU_Clear (U8 miu, U32 addr, U32 len, U8 clear_value) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_MIU_Clear (U8 miu, U32 addr, U32 len, U8 clear_value)
{
}

/** User stub definition for function: BOOLEAN M4AParser_SaveFrameLocation(void) */
EXTERN_C_LINKAGE BOOLEAN M4AParser_SaveFrameLocation (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_M4AParser_SaveFrameLocation (void)
{
	  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusicType_AAC_m4a"))
	  {
		  return (unsigned char)1;
	  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN M4AParser_Get_AAC_Info(ST_MP3_INFO *) */
EXTERN_C_LINKAGE BOOLEAN M4AParser_Get_AAC_Info (ST_MP3_INFO * pMp3Info) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_M4AParser_Get_AAC_Info (ST_MP3_INFO * pMp3Info)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_AAC_AAC_TRUE"))
  {
    return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_Flac_CollectInfo(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_Flac_CollectInfo (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_Flac_CollectInfo (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Initial_enCurrentMusic_FLAC_TRUE"))
  {
    return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: U8 msAPI_Memory_Free(void *, EN_BUFFER_ID) */
EXTERN_C_LINKAGE U8 msAPI_Memory_Free (void * pFree, EN_BUFFER_ID enBufID) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_Memory_Free (void * pFree, EN_BUFFER_ID enBufID)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_Wav_CollectInfo(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_Wav_CollectInfo (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_Wav_CollectInfo (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_PCM_CollectInfo(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_PCM_CollectInfo (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_PCM_CollectInfo (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_Music_Init(En_DVB_decSystemType, U16) */
EXTERN_C_LINKAGE void msAPI_Music_Init (En_DVB_decSystemType enDecSystem, U16 u16InitVolume) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_Init (En_DVB_decSystemType enDecSystem, U16 u16InitVolume)
{

}

/** User stub definition for function: void msAPI_Music_SetXPCMParam(XPCM_TYPE, U8, U16, U8, U16, U16) */
EXTERN_C_LINKAGE void msAPI_Music_SetXPCMParam (XPCM_TYPE audioType, U8 channels, U16 sampleRate, U8 bitsPerSample, U16 blockSize, U16 samplePerBlock) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_SetXPCMParam (XPCM_TYPE audioType, U8 channels, U16 sampleRate, U8 bitsPerSample, U16 blockSize, U16 samplePerBlock)
{
}

/** User stub definition for function: void MApp_Music_UpdatePlayTime(void) */
EXTERN_C_LINKAGE void MApp_Music_UpdatePlayTime (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Music_UpdatePlayTime (void)
{

}

/** User stub definition for function: U32 msAPI_DataStreamIO_Length(U32) */
EXTERN_C_LINKAGE U32 msAPI_DataStreamIO_Length (U32 u32Hdl) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_DataStreamIO_Length (U32 u32Hdl)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_SearchFirstFrame_case1"))
  {
    return 4500UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Flac_CollectInfo_case2"))
  {
    return 43UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Flac_CollectInfo_case2"))
  {
      return 1024UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_M4AParser_Get_M4A_Info_case1"))
  {
      return 50000UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_WAVTimeOffset"))
  {
      return 1024UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_M4A_Probe_case1"))
  {
      return 10UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_FLAC_Probe_case1"))
  {
      return 50UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1"))
  {
      return 5000UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_CollectInfo_case1"))
  {
      return 5000UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_Probe_case1"))
  {
      return 5000UL;
  }


    return 0UL;
}

/** User stub definition for function: void msAPI_MIU_Copy(U32, U32, U32, MEMCOPYTYPE) */
EXTERN_C_LINKAGE void msAPI_MIU_Copy (U32 u32srcaddr, U32 u32dstaddr, U32 u32len, MEMCOPYTYPE type) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_MIU_Copy (U32 u32srcaddr, U32 u32dstaddr, U32 u32len, MEMCOPYTYPE type)
{
}

/** User stub definition for function: BOOLEAN msAPI_Flash_Write(U32, U32, U8 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Flash_Write (U32 u32StartAddr, U32 u32WriteSize, U8 * user_buffer) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Flash_Write (U32 u32StartAddr, U32 u32WriteSize, U8 * user_buffer)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_SaveMp3_WriteFlash_TRUE"))
  {
        return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_Music_StopDecode(void) */
EXTERN_C_LINKAGE void msAPI_Music_StopDecode (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_StopDecode (void)
{
}

/** User stub definition for function: void MApp_Music_CloseFile(void) */
EXTERN_C_LINKAGE void MApp_Music_CloseFile (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Music_CloseFile (void)
{
}

/** User stub definition for function: U32 msAPI_DataStreamIO_Tell(U32) */
EXTERN_C_LINKAGE U32 msAPI_DataStreamIO_Tell (U32 u32Hdl) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_DataStreamIO_Tell (U32 u32Hdl)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_UpdatePlayTime_case1"))
  {
      return 2UL;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case4"))
  {
      return 20UL;
  }



    return 0UL;
}

/** User stub definition for function: void msAPI_Music_CleanFileEndData(U32, U32, U32) */
EXTERN_C_LINKAGE void msAPI_Music_CleanFileEndData (U32 StrAddr, U32 length, U32 ClearValue) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_CleanFileEndData (U32 StrAddr, U32 length, U32 ClearValue)
{
}

/** User stub definition for function: BOOLEAN M4AParser_WriteDSP(U32, U32) */
EXTERN_C_LINKAGE BOOLEAN M4AParser_WriteDSP (U32 dwReqAddress, U32 u32ReqBytes) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_M4AParser_WriteDSP (U32 dwReqAddress, U32 u32ReqBytes)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusic_AAC"))
  {
      return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_Flac_DataInput(U32, U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_Flac_DataInput (U32 dwReqAddress, U32 u32ReqBytes) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_Flac_DataInput (U32 dwReqAddress, U32 u32ReqBytes)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_FLAC"))
  {
      return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_Wav_DataInput(U32, U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_Wav_DataInput (U32 dwReqAddress, U32 u32ReqBytes) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_Wav_DataInput (U32 dwReqAddress, U32 u32ReqBytes)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_WAV"))
  {
      return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_PCM_DataInput(U32, U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_PCM_DataInput (U32 dwReqAddress, U32 u32ReqBytes) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_PCM_DataInput (U32 dwReqAddress, U32 u32ReqBytes)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_PCM"))
  {
      return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_Music_SetInput(void) */
EXTERN_C_LINKAGE void msAPI_Music_SetInput () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_SetInput (void)
{
}

/** User stub definition for function: BOOLEAN msAPI_Flash_AddressToBlock(U32, U32 *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Flash_AddressToBlock (U32 u32FlashAddr, U32 * pu32BlockIndex) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Flash_AddressToBlock (U32 u32FlashAddr, U32 * pu32BlockIndex)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_FAIL"))
  {
      return (unsigned char)0;
  }
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_SaveMp3_EraseFlash_TRUE"))
  {
      return (unsigned char)1;
  }

    return (unsigned char)0;
}

/** User stub definition for function: U8 msAPI_Music_CheckInputRequest(U32 *, U32 *) */
EXTERN_C_LINKAGE U8 msAPI_Music_CheckInputRequest (U32 * pU32WrtAddr, U32 * pU32WrtBytes) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_Music_CheckInputRequest (U32 * pU32WrtAddr, U32 * pU32WrtBytes)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_MP3"))
  {
    *pU32WrtBytes = 2;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusic_AAC"))
  {
    *pU32WrtBytes = 2;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_FLAC"))
  {
    *pU32WrtBytes = 2;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_WAV"))
  {
    *pU32WrtBytes = 2;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_PCM"))
  {
    *pU32WrtBytes = 2;
    return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Input_enCurrentMusicType_LOAS"))
  {
    *pU32WrtBytes = 2;
    return (unsigned char)1;
  }


    return (unsigned char)0;
}

/** User stub definition for function: S16 _MApp_Music_ScanDigit(U8 *, U32 *, BOOLEAN) */
EXTERN_C_LINKAGE S16 _MApp_Music_ScanDigit (U8 * pu8Data, U32 * pu32Val, BOOLEAN bIsUnicode) ;
EXTERN_C_LINKAGE S16 CppTest_Stub__MApp_Music_ScanDigit (U8 * pu8Data, U32 * pu32Val, BOOLEAN bIsUnicode)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_ScanfLrCTime_case3"))
  {
    return (short)1;
  }

    return (short)0;
}
//global variable
U8 g_au8Buff_for_msAPI_Memory_Allocate[128] = {0};

/** User stub definition for function: void * msAPI_Memory_Allocate(U16, EN_BUFFER_ID) */
EXTERN_C_LINKAGE void * msAPI_Memory_Allocate (U16 u16Number_of_bytes, EN_BUFFER_ID enBufID) ;
EXTERN_C_LINKAGE void * CppTest_Stub_msAPI_Memory_Allocate (U16 u16Number_of_bytes, EN_BUFFER_ID enBufID)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_LRC_Lyrics_Parser_case1"))
  {
    U8 u8Temp[5] = {']','1','2','3','4'};
    return (void *)&u8Temp;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ParseFlac_SeekTable_case1"))
  {
    typedef unsigned long long                  U64;
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

        ST_FLAC_SEEK_TABLE stSeekTableTemp;

      return (void *)&stSeekTableTemp;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test__MApp_MPlayer_SubtitleTask_External_Text"))
  {
    return (void *)&g_au8Buff_for_msAPI_Memory_Allocate[0];
  }
//  else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_msAPI_MIU_QuickGenSettingWrite_NONg_bGenSettingStoreUseNewMethod"))
  //{
  	//  U8 u8Temp[5] = {']','1','2','3','4'};
  	  //  return (void *)&u8Temp;
  //}
  //else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_msAPI_MIU_QuickGenSettingLoad_g_bGenSettingStoreUseNewMethodTRUE"))
//  {
//  	  U8 u8Temp[5] = {']','1','2','3','4'};
//  	    return (void *)&u8Temp;
//  }
 // else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_msAPI_MIU_QuickGenSettingWrite_g_u16QuickGenSettingIdxEVEN"))
//  {
  //	  U8 u8Temp[5] = {']','1','2','3','4'};
//  	    return (void *)&u8Temp;
  //}
  //else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_msAPI_MIU_QuickGenSettingWrite_flash_buf_fail"))
  //{
//	    return (void *) 0 ;
  //}
//  else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_msAPI_MIU_QuickGenSettingLoad_NONg_bGenSettingStoreUseNewMethod"))
  //{
//	  U8 u8Temp[5] = {']','1','2','3','4'};
//	   	    return (void *)&u8Temp;
  //}
//  else if(CppTest_IsCurrentTestCase("msAPI_Flash_Test_test_msAPI_MIU_QuickGenSettingLoad_flash_buf20_ail"))
//  {
//	  return (void *)0;
  //}
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII"))
  {

	  return (void *)&g_au8Buff_for_msAPI_Memory_Allocate;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE"))
  {

	  return (void *)&g_au8Buff_for_msAPI_Memory_Allocate;
  }

    return (void *)0;
}

/** User stub definition for function: U8 _MApp_Music_ScanfLrCTime(U8 *, U32 *, U32 *, U32 *, U32 *, BOOLEAN) */
EXTERN_C_LINKAGE U8 _MApp_Music_ScanfLrCTime (U8 * pu8Data, U32 * pu32Min, U32 * pu32Sec, U32 * pu32Ms, U32 * pu32MsLen, BOOLEAN bIsUnicode) ;
EXTERN_C_LINKAGE U8 CppTest_Stub__MApp_Music_ScanfLrCTime (U8 * pu8Data, U32 * pu32Min, U32 * pu32Sec, U32 * pu32Ms, U32 * pu32MsLen, BOOLEAN bIsUnicode)
{
    return (unsigned char)0;
}


/** User stub definition for function: U32 MApp_Music_SearchFirstFrame(U32, U32) */
EXTERN_C_LINKAGE U32 MApp_Music_SearchFirstFrame (U32 u32FileHandle, U32 u32ID3v2Offset) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_Music_SearchFirstFrame (U32 u32FileHandle, U32 u32ID3v2Offset)
{
    return 0UL;
}

/** User stub definition for function: U32 msAPI_Music_GetFileTime(U32, U32, EN_MP3_VERSION *, EN_MP3_LAYER *, U16 *, U16 *, U8 *, U16 *, U8 *) */
EXTERN_C_LINKAGE U32 msAPI_Music_GetFileTime (U32 u32FileBuffAddr, U32 u32FileSize, EN_MP3_VERSION * penVersion, EN_MP3_LAYER * penLayer, U16 * u16BitRate, U16 * pu16SampleRate, U8 * bFlag, U16 * pu16TOCLength, U8 * pu8TOC) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Music_GetFileTime (U32 u32FileBuffAddr, U32 u32FileSize, EN_MP3_VERSION * penVersion, EN_MP3_LAYER * penLayer, U16 * u16BitRate, U16 * pu16SampleRate, U8 * bFlag, U16 * pu16TOCLength, U8 * pu8TOC)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_MP3_Probe_case1"))
  {
    return 200UL;

  }
    return 0UL;
}

/** User stub definition for function: U32 msAPI_Music_GetCurrentFrameNumber(void) */
EXTERN_C_LINKAGE U32 msAPI_Music_GetCurrentFrameNumber () ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_Music_GetCurrentFrameNumber (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_CollectInfo_case1"))
  {
    return 2UL;

  }
    return 0UL;
}



/** User stub definition for function: U16 msAPI_Music_GetBitRate(void) */
EXTERN_C_LINKAGE U16 msAPI_Music_GetBitRate () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_Music_GetBitRate (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_CollectInfo_case1"))
  {
    return (unsigned short)128;

  }
    return (unsigned short)0;
}

/** User stub definition for function: void MApp_Music_GetRIFFTag(U8 *, U32 *, U32 *) */
EXTERN_C_LINKAGE void MApp_Music_GetRIFFTag (U8 * buf, U32 * ptag, U32 * ptagsize) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Music_GetRIFFTag (U8 * buf, U32 * ptag, U32 * ptagsize)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_Wav_CollectInfo_case1"))
  {

    if(*ptagsize == 20)
    {
      *ptagsize = 21;
        *ptag = RIFF_TAG_WAVE;

    }
    else if(*ptagsize == 21)
    {
      *ptagsize = 22;
        *ptag = RIFF_TAG_fmt;
    }
    else if(*ptagsize == 22)
    {
      *ptagsize = 23;
        *ptag = RIFF_TAG_data;
    }
    else
    {
      *ptagsize = 20;
      *ptag = RIFF_TAG_RIFF;
    }

  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_WAV_Probe_case1"))
  {

    if(*ptagsize == 20)
    {
      *ptagsize = 21;
        *ptag = RIFF_TAG_WAVE;

    }
    else if(*ptagsize == 21)
    {
      *ptagsize = 22;
        *ptag = RIFF_TAG_fmt;
    }
    else if(*ptagsize == 22)
    {
      *ptagsize = 23;
        *ptag = RIFF_TAG_data;
    }
    else
    {
      *ptagsize = 20;
      *ptag = RIFF_TAG_RIFF;
    }

  }

}

/** User stub definition for function: BOOLEAN MApp_Music_IsAAC(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_Music_IsAAC (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Music_IsAAC (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_GetCurrentTime_case1"))
  {
      return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessFfRew_case4"))
  {
      return (unsigned char)1;
  }
  else if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_AACTimeOffset_case1"))
  {
      return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_Music_Initial(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_Music_Initial (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Music_Initial (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Main_case1"))
  {
        return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_Music_OpenFile(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_Music_OpenFile (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Music_OpenFile (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Main_case1"))
  {
        return (unsigned char)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_Music_StartDecode(void) */
EXTERN_C_LINKAGE void msAPI_Music_StartDecode () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Music_StartDecode (void)
{
}

/** User stub definition for function: void MApp_Music_ProcessFfRew(void) */
EXTERN_C_LINKAGE void MApp_Music_ProcessFfRew (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Music_ProcessFfRew (void)
{
}

/** User stub definition for function: void MApp_Music_Input(void) */
EXTERN_C_LINKAGE void MApp_Music_Input (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Music_Input (void)
{
}

/** User stub definition for function: BOOLEAN MApp_Music_TimeOutCheck(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_Music_TimeOutCheck (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Music_TimeOutCheck (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_Main_case1"))
  {
        return (unsigned char)1;
  }
    return (unsigned char)0;
}


/** User stub definition for function: U32 M4aParser_GetOneStszEntryFromDRAM(U32) */
EXTERN_C_LINKAGE U32 M4aParser_GetOneStszEntryFromDRAM (U32 u32Index) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_M4aParser_GetOneStszEntryFromDRAM (U32 u32Index)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_M4AParser_AddADTSHeaderForDSP_case1"))
  {
        return 5UL;
  }
    return 0UL;
}

/** User stub definition for function: U64 MApp_Music_GetFlacSampleIndex(U32) */
EXTERN_C_LINKAGE U64 MApp_Music_GetFlacSampleIndex (U32 u32KeyIndex) ;
EXTERN_C_LINKAGE U64 CppTest_Stub_MApp_Music_GetFlacSampleIndex (U32 u32KeyIndex)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test__MApp_Music_FLACTimeOffset_case1"))
  {
    switch(u32KeyIndex)
    {
        case 0:
          return (unsigned long long)0;
        case 1:
          return (unsigned long long)10000;
        case 2:
            return (unsigned long long)20000;
        case 3:
        return (unsigned long long)21000;
      case 4:
        return (unsigned long long)223000;
      case 5:
        return (unsigned long long)300000;
      case 6:
        return (unsigned long long)324000;
      case 7:
        return (unsigned long long)350000;
      case 8:
        return (unsigned long long)374000;
      case 9:
        return (unsigned long long)400000;
      case 10:
        return (unsigned long long)420000;
      default:
        return (unsigned long long)0;
    };
  }
    return (unsigned long long)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_MP3TimeOffset(U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_MP3TimeOffset (U32 u32GotoTimeMs) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_MP3TimeOffset (U32 u32GotoTimeMs)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset"))
  {
      return (unsigned short)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_AACTimeOffset(U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_AACTimeOffset (U32 u32GotoTimeMs) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_AACTimeOffset (U32 u32GotoTimeMs)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset"))
  {
      return (unsigned short)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_WAVTimeOffset(U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_WAVTimeOffset (U32 u32GotoTimeMs) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_WAVTimeOffset (U32 u32GotoTimeMs)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset"))
  {
      return (unsigned short)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_Music_FLACTimeOffset(U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Music_FLACTimeOffset (U32 u32GotoTimeMs) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Music_FLACTimeOffset (U32 u32GotoTimeMs)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset"))
  {
      return (unsigned short)1;
  }
    return (unsigned char)0;
}

/** User stub definition for function: U16 msAPI_Music_GetResidualBufferSize(void) */
EXTERN_C_LINKAGE U16 msAPI_Music_GetResidualBufferSize () ;
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_Music_GetResidualBufferSize (void)
{
  if(CppTest_IsCurrentTestCase("TestSuite_mapp_music_test_MApp_Music_ProcessTimeOffset"))
  {
      return (unsigned short)1;
  }
    return (unsigned short)0;
}

/** User stub definition for function: BOOLEAN msAPI_Music_Parse_ID3v1(U32, MP3_INFO *) */
EXTERN_C_LINKAGE BOOLEAN msAPI_Music_Parse_ID3v1 (U32 u32FileBuffAddr, MP3_INFO * pMp3InfoPtr) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_msAPI_Music_Parse_ID3v1 (U32 u32FileBuffAddr, MP3_INFO * pMp3InfoPtr)
{
    return (unsigned char)0;
}


/** User stub definition for function: U32 msAPI_DataStreamIO_MID_FS_Read(U32, U32, U32 *) */
EXTERN_C_LINKAGE U32 msAPI_DataStreamIO_MID_FS_Read (U32 u32Hdl, U32 u32Length, U32 * pu32DestAddr) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_DataStreamIO_MID_FS_Read (U32 u32Hdl, U32 u32Length, U32 * pu32DestAddr)
{
    if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_CollectInfo_case1"))
    {
		U8 u8FileBufPtrTemp[5000];
		*pu32DestAddr = &u8FileBufPtrTemp;
	    return 0UL;
    }
    return 0UL;
}


/** User stub definition for function: U32 MApp_WMA_ParsingASFPacketHeader(U32, ST_WMA_INFO *) */
EXTERN_C_LINKAGE U32 MApp_WMA_ParsingASFPacketHeader (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_WMA_ParsingASFPacketHeader (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo)
{
    return 12UL;
}

/** User stub definition for function: U32 MApp_WMA_ParsingASFPayloadHeader(U32, ST_WMA_INFO *) */
EXTERN_C_LINKAGE U32 MApp_WMA_ParsingASFPayloadHeader (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_WMA_ParsingASFPayloadHeader (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo)
{
    return 16UL;
}

/** User stub definition for function: U32 MApp_WMA_ParsingASFPacketSCR(U32, ST_WMA_INFO *) */
EXTERN_C_LINKAGE U32 MApp_WMA_ParsingASFPacketSCR (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_WMA_ParsingASFPacketSCR (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo)
{
    return 0UL;
}

/** User stub definition for function: U32 MApp_WMA_ParsingASFPayloadPTime(U32, ST_WMA_INFO *, U32, U32) */
EXTERN_C_LINKAGE U32 MApp_WMA_ParsingASFPayloadPTime (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo, U32 u32IndexNum, U32 u32PayloadPosInFile) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_WMA_ParsingASFPayloadPTime (U32 dwReqAddress, ST_WMA_INFO * pWmaInfo, U32 u32IndexNum, U32 u32PayloadPosInFile)
{
    return 0UL;
}

/** User stub definition for function: BOOLEAN MApp_WMA_CollectInfo(ST_WMA_INFO *) */
EXTERN_C_LINKAGE BOOLEAN MApp_WMA_CollectInfo (ST_WMA_INFO * pWmaInfo) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_WMA_CollectInfo (ST_WMA_INFO * pWmaInfo)
{
    return (unsigned char)1;
}

/** User stub definition for function: U8 msAPI_WMA_CheckInputRequest(U32 *, U32 *) */
EXTERN_C_LINKAGE U8 msAPI_WMA_CheckInputRequest (U32 * pU32WrtAddr, U32 * pU32WrtBytes) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_WMA_CheckInputRequest (U32 * pU32WrtAddr, U32 * pU32WrtBytes)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_Input"))
	{
		*pU32WrtBytes = 4096;
	    return (unsigned short)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: U32 MApp_WMA_AddASFPacketForDSP(U32, U32) */
EXTERN_C_LINKAGE U32 MApp_WMA_AddASFPacketForDSP (U32 dwReqAddress, U32 u32ReqBytes) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_WMA_AddASFPacketForDSP (U32 dwReqAddress, U32 u32ReqBytes)
{
    return 0UL;
}

/** User stub definition for function: U32 MApp_WMA_GetPayloadIndexFromIndexTable(U32, U32, ST_WMA_INDEX_TABLE *) */
EXTERN_C_LINKAGE U32 MApp_WMA_GetPayloadIndexFromIndexTable (U32 u32CurrentPayload, U32 u32GotoTimeMs, ST_WMA_INDEX_TABLE * pstWMAIndexTableReturn) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_WMA_GetPayloadIndexFromIndexTable (U32 u32CurrentPayload, U32 u32GotoTimeMs, ST_WMA_INDEX_TABLE * pstWMAIndexTableReturn)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_wma_test_MApp_WMA_Input"))
	{

		if(u32GotoTimeMs==2000)
		{
			pstWMAIndexTableReturn->u32WMAPayloadFilePos = 0xFFFFFFFF;
		    pstWMAIndexTableReturn->u32WMAPayloadPTime = 5000;
		    return 5UL;
		}

		pstWMAIndexTableReturn->u32WMAPayloadFilePos = 200;
		pstWMAIndexTableReturn->u32WMAPayloadPTime = 5000;

	    return 10UL;
	}
    return 0UL;
}

/** User stub definition for function: U8 msAPI_WMA_CheckPlayDone(void) */
EXTERN_C_LINKAGE U8 msAPI_WMA_CheckPlayDone () ;
EXTERN_C_LINKAGE U8 CppTest_Stub_msAPI_WMA_CheckPlayDone (void)
{
    return (unsigned char)1;
}

/** User stub definition for function: U16 msAPI_WMA_GetPCMBufferSize(U32, U32) */
EXTERN_C_LINKAGE U16 msAPI_WMA_GetPCMBufferSize (U32 u32BitRate, U32 u32SampleRate) ;
EXTERN_C_LINKAGE U16 CppTest_Stub_msAPI_WMA_GetPCMBufferSize (U32 u32BitRate, U32 u32SampleRate)
{
    return (unsigned short)0;
}

/** User stub definition for function: BOOLEAN MApp_WMA_TimeOutCheck(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_WMA_TimeOutCheck (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_WMA_TimeOutCheck (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_WMA_Initial(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_WMA_Initial (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_WMA_Initial (void)
{
    return (unsigned char)1;
}

/** User stub definition for function: void MApp_WMA_Input(void) */
EXTERN_C_LINKAGE void MApp_WMA_Input (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_WMA_Input (void)
{
}

/** User stub definition for function: void msAPI_DataStreamIO_MID_FS_RegisterBuffer(U8 *) */
EXTERN_C_LINKAGE void msAPI_DataStreamIO_MID_FS_RegisterBuffer (U8 * pu8MidFSBuf) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_DataStreamIO_MID_FS_RegisterBuffer (U8 * pu8MidFSBuf)
{
}

/** User stub definition for function: BOOLEAN MApp_WMA_OpenFile(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_WMA_OpenFile (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_WMA_OpenFile (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void msAPI_WMA_StartDecode(void) */
EXTERN_C_LINKAGE void msAPI_WMA_StartDecode () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_WMA_StartDecode (void)
{
}


/** User stub definition for function: void msAPI_WMA_StopDecode(void) */
/*
EXTERN_C_LINKAGE void msAPI_WMA_StopDecode () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_WMA_StopDecode (void)
{
}
*/

/** User stub definition for function: BOOLEAN _MApp_WMA_TimeOffset(U32) */
EXTERN_C_LINKAGE BOOLEAN _MApp_WMA_TimeOffset (U32 u32GotoTimeMs) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_WMA_TimeOffset (U32 u32GotoTimeMs)
{
    return (unsigned char)1;
}

/** User stub definition for function: BOOLEAN MApp_WMA_Probe(U32, ST_WMA_PROBE_INFO *, U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_WMA_Probe (U32 u32Hdl, ST_WMA_PROBE_INFO * pstWmaProbeInfo, U32 u32InfoAttr) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_WMA_Probe (U32 u32Hdl, ST_WMA_PROBE_INFO * pstWmaProbeInfo, U32 u32InfoAttr)
{
    return (unsigned char)0;
}

/** User stub definition for function: MBX_Result MSApi_MBX_SendMsg(MBX_Msg *) */
EXTERN_C_LINKAGE MBX_Result MSApi_MBX_SendMsg (MBX_Msg * pMsg) ;
EXTERN_C_LINKAGE MBX_Result CppTest_Stub_MSApi_MBX_SendMsg (MBX_Msg * pMsg)
{
    return E_MBX_SUCCESS;
}

/** User stub definition for function: void MApp_Scaler_SetWindow(MS_WINDOW_TYPE *, MS_WINDOW_TYPE *, MS_WINDOW_TYPE *, EN_ASPECT_RATIO_TYPE, INPUT_SOURCE_TYPE_t, SCALER_WIN) */
EXTERN_C_LINKAGE void MApp_Scaler_SetWindow (MS_WINDOW_TYPE * ptSrcWin, MS_WINDOW_TYPE * ptCropWin, MS_WINDOW_TYPE * ptDstWin, EN_ASPECT_RATIO_TYPE enVideoScreen, INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Scaler_SetWindow (MS_WINDOW_TYPE * ptSrcWin, MS_WINDOW_TYPE * ptCropWin, MS_WINDOW_TYPE * ptDstWin, EN_ASPECT_RATIO_TYPE enVideoScreen, INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void msAPI_Scaler_SetBlueScreen(BOOLEAN, U8, U16, SCALER_WIN) */
EXTERN_C_LINKAGE void msAPI_Scaler_SetBlueScreen (BOOLEAN bEnable, U8 u8Color, U16 u16ScreenUnmuteTime, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Scaler_SetBlueScreen (BOOLEAN bEnable, U8 u8Color, U16 u16ScreenUnmuteTime, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApp_Scaler_EnableOverScan(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_Scaler_EnableOverScan (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Scaler_EnableOverScan (BOOLEAN bEnable)
{
}

/** User stub definition for function: void MApp_Scaler_EnableManualDetectTiming(BOOLEAN) */
EXTERN_C_LINKAGE void MApp_Scaler_EnableManualDetectTiming (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Scaler_EnableManualDetectTiming (BOOLEAN bEnable)
{
}

/** User stub definition for function: BOOLEAN MApp_Scaler_SetVideo3DMode(U16) */
EXTERN_C_LINKAGE BOOLEAN MApp_Scaler_SetVideo3DMode (U16 u16_Video3Dmode) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_Scaler_SetVideo3DMode (U16 u16_Video3Dmode)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_Picture_Setting_SetColor(INPUT_SOURCE_TYPE_t, SCALER_WIN) */
EXTERN_C_LINKAGE void MApp_Picture_Setting_SetColor (INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Picture_Setting_SetColor (INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow)
{
}

/** User stub definition for function: void MApp_Scaler_SetTiming(INPUT_SOURCE_TYPE_t, SCALER_WIN) */
EXTERN_C_LINKAGE void MApp_Scaler_SetTiming (INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_Scaler_SetTiming (INPUT_SOURCE_TYPE_t enInputSourceType, SCALER_WIN eWindow)
{
}

/** User stub definition for function: U32 MApp_Photo_GetInfo(EN_PHOTO_INFO) */
EXTERN_C_LINKAGE U32 MApp_Photo_GetInfo (EN_PHOTO_INFO enInfo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_Photo_GetInfo (EN_PHOTO_INFO enInfo)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_photo_test_MApp_Photo_Main_case1"))
	{
		return 1UL;
	}
    return 0UL;
}

/** User stub definition for function: void msAPI_OSD_SetClipWindow(U16, U16, U16, U16) */
EXTERN_C_LINKAGE void msAPI_OSD_SetClipWindow (U16 U16x0, U16 U16y0, U16 U16x1, U16 U16y1) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_OSD_SetClipWindow (U16 U16x0, U16 U16y0, U16 U16x1, U16 U16y1)
{
}

/** User stub definition for function: BOOLEAN _MApp_Photo_MailBox_Init(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Photo_MailBox_Init (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Photo_MailBox_Init (void)
{
    return (unsigned char)1;
}

/** User stub definition for function: void _MApp_Photo_ShareMem_SetInfo(EN_STILLIMAGE_SHAREMEMORY, U32) */
EXTERN_C_LINKAGE void _MApp_Photo_ShareMem_SetInfo (EN_STILLIMAGE_SHAREMEMORY enInfo, U32 u32Value) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_ShareMem_SetInfo (EN_STILLIMAGE_SHAREMEMORY enInfo, U32 u32Value)
{
}

/** User stub definition for function: void _MApp_Photo_Stop(void) */
EXTERN_C_LINKAGE void _MApp_Photo_Stop (void) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_Stop (void)
{
}

/** User stub definition for function: void _MApp_Photo_Reset(BOOLEAN) */
EXTERN_C_LINKAGE void _MApp_Photo_Reset (BOOLEAN bForceResetMem) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_Reset (BOOLEAN bForceResetMem)
{
}

/** User stub definition for function: BOOLEAN _MApp_Photo_Decode_MemoryValidation(EN_PHOTO_CMD) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Photo_Decode_MemoryValidation (EN_PHOTO_CMD enCmd) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Photo_Decode_MemoryValidation (EN_PHOTO_CMD enCmd)
{
    return (unsigned char)1;
}

/** User stub definition for function: void _MApp_Photo_MailBox_Clear(void) */
EXTERN_C_LINKAGE void _MApp_Photo_MailBox_Clear (void) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_MailBox_Clear (void)
{
}

/** User stub definition for function: void _MApp_Photo_UartSwitch(EN_PHOTO_UART_SWITCH) */
EXTERN_C_LINKAGE void _MApp_Photo_UartSwitch (EN_PHOTO_UART_SWITCH enUartSwitch) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_UartSwitch (EN_PHOTO_UART_SWITCH enUartSwitch)
{
}

/** User stub definition for function: void _MApp_Photo_Timer_Disable(EN_PHOTO_TIMER) */
EXTERN_C_LINKAGE void _MApp_Photo_Timer_Disable (EN_PHOTO_TIMER enTimer) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_Timer_Disable (EN_PHOTO_TIMER enTimer)
{
}

/** User stub definition for function: BOOLEAN _MApp_Photo_FileOpen(FileEntry *) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Photo_FileOpen (FileEntry * pFileEntry) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Photo_FileOpen (FileEntry * pFileEntry)
{
    return (unsigned char)1;
}

/** User stub definition for function: void _MApp_Photo_SendCmd_Init(void) */
EXTERN_C_LINKAGE void _MApp_Photo_SendCmd_Init (void) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_SendCmd_Init (void)
{
}

/** User stub definition for function: void _MApp_Photo_Timer_Init(EN_PHOTO_TIMER, U32) */
EXTERN_C_LINKAGE void _MApp_Photo_Timer_Init (EN_PHOTO_TIMER enTimer, U32 u32TimeOut) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_Timer_Init (EN_PHOTO_TIMER enTimer, U32 u32TimeOut)
{
}

/** User stub definition for function: void msAPI_Timer_ResetWDT(void) */
EXTERN_C_LINKAGE void msAPI_Timer_ResetWDT () ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_Timer_ResetWDT (void)
{
}

/** User stub definition for function: void _MApp_Photo_FileReadHandler(U32, U32) */
EXTERN_C_LINKAGE void _MApp_Photo_FileReadHandler (U32 u32Addr, U32 u32Size) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_FileReadHandler (U32 u32Addr, U32 u32Size)
{
}

/** User stub definition for function: void _MApp_Photo_MailBox_Handler(void) */
EXTERN_C_LINKAGE void _MApp_Photo_MailBox_Handler (void) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_MailBox_Handler (void)
{
}

/** User stub definition for function: BOOLEAN _MApp_Photo_Timer_IsTimeOut(EN_PHOTO_TIMER) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Photo_Timer_IsTimeOut (EN_PHOTO_TIMER enTimer) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Photo_Timer_IsTimeOut (EN_PHOTO_TIMER enTimer)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_photo_test_MApp_Photo_DecodeMemory_Init_case1"))
	{
		if(enTimer==0)
		{
			return (unsigned char)1;
		}

	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_photo_test_MApp_Photo_EncodeMemory_Init"))
	{
		if(enTimer==0)
		{
			return (unsigned char)1;
		}

	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_photo_test_MApp_Photo_Main_case1"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_photo_test__MApp_Photo_CheckCPAlive"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_photo_test_MApp_Photo_Stop_case0"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: void _MApp_Photo_Decode_ShowImageInfo(void) */
EXTERN_C_LINKAGE void _MApp_Photo_Decode_ShowImageInfo (void) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_Decode_ShowImageInfo (void)
{
}

/** User stub definition for function: U32 _MApp_Photo_FileLength(void) */
EXTERN_C_LINKAGE U32 _MApp_Photo_FileLength (void) ;
EXTERN_C_LINKAGE U32 CppTest_Stub__MApp_Photo_FileLength (void)
{
    return 0UL;
}

/** User stub definition for function: BOOLEAN _MApp_Photo_CheckCPAlive(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_Photo_CheckCPAlive (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_Photo_CheckCPAlive (void)
{
    return (unsigned char)1;
}

/** User stub definition for function: void _MApp_Photo_SendCmd_Start(void) */
EXTERN_C_LINKAGE void _MApp_Photo_SendCmd_Start (void) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_Photo_SendCmd_Start (void)
{
}

/** User stub definition for function: EN_PHOTO_ERRCODE MApp_Photo_GetErrCode(void) */
EXTERN_C_LINKAGE EN_PHOTO_ERRCODE MApp_Photo_GetErrCode () ;
EXTERN_C_LINKAGE EN_PHOTO_ERRCODE CppTest_Stub_MApp_Photo_GetErrCode (void)
{
    return E_PHOTO_ERR_NONE;
}

/** User stub definition for function: U32 _MApp_Photo_ShareMem_GetInfo(EN_STILLIMAGE_SHAREMEMORY) */
EXTERN_C_LINKAGE U32 _MApp_Photo_ShareMem_GetInfo (EN_STILLIMAGE_SHAREMEMORY enInfo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub__MApp_Photo_ShareMem_GetInfo (EN_STILLIMAGE_SHAREMEMORY enInfo)
{
    return 0UL;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_SetSubtitleTrackID(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_SetSubtitleTrackID (U8 u8TrackId) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_SetSubtitleTrackID (U8 u8TrackId)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case1"))
	{
		return (unsigned char)1;
	}
}

/** User stub definition for function: U32 MApp_VDPlayer_GetInfo(EN_VDPLAYER_INFO) */
EXTERN_C_LINKAGE U32 MApp_VDPlayer_GetInfo (EN_VDPLAYER_INFO enInfo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_VDPlayer_GetInfo (EN_VDPLAYER_INFO enInfo)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case2"))
	{
		return (unsigned char)2;

	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieAudioLanguage_en"))
	{
		if(enInfo == E_VDPLAYER_INFO_AUDIO_LANGUAGE)
		{
			return (U32)0x00476E65;
		}

	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_Interal"))
	{
			return (U32)0x00476E65;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetSubtitleTrackID_return_TRUE"))
	{
			return (U32)1;
	}
    return 0UL;
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_SetSubtitleTrackID(U8) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_SetSubtitleTrackID (U8 u8TrackId) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_SetSubtitleTrackID (U8 u8TrackId)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_ChangeSubtitleTrack_case2"))
	{
		return (unsigned char)1;
	}
}

/** User stub definition for function: void MApi_AUDIO_FileEndDataHandle(MS_U32) */
EXTERN_C_LINKAGE void MApi_AUDIO_FileEndDataHandle (MS_U32 u32DataLeft) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_FileEndDataHandle (MS_U32 u32DataLeft)
{
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_SetMovieMpegSubtitle(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_SetMovieMpegSubtitle (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_SetMovieMpegSubtitle (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_GetSubtitleTag(MPlayer_Subtitle_Tag *, U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_GetSubtitleTag (MPlayer_Subtitle_Tag * pTag, U32 u32Time) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_GetSubtitleTag (MPlayer_Subtitle_Tag * pTag, U32 u32Time)
{
    return (unsigned char)0;
}

/** User stub definition for function: U32 MApp_MPlayer_Subtitle_GetSubtitle(U8 *, U32, U32) */
EXTERN_C_LINKAGE U32 MApp_MPlayer_Subtitle_GetSubtitle (U8 * pu8Dst, U32 u32BufSize, U32 u32SubtitlePos) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_MPlayer_Subtitle_GetSubtitle (U8 * pu8Dst, U32 u32BufSize, U32 u32SubtitlePos)
{
    return 0UL;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_OpenSubtitleFileHandle(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_OpenSubtitleFileHandle (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_OpenSubtitleFileHandle (void)
{
    return (unsigned char)1;
}

/** User stub definition for function: U32 msAPI_FCtrl_FileLength(U8) */
EXTERN_C_LINKAGE U32 msAPI_FCtrl_FileLength (U8 u8HandleNo) ;
EXTERN_C_LINKAGE U32 CppTest_Stub_msAPI_FCtrl_FileLength (U8 u8HandleNo)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_ASCII"))
	{
		return (unsigned char)37;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SRT_ParseOneSubtitle_UNICODE"))
	{
		return (unsigned char)78;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_ASCII"))
	{
		return (unsigned char)72;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SSA_ParseOneSubtitle_UNICODE"))
	{
		return 144;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_ASCII"))
	{
		return 25;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_MicroDVD_ParseOneSubtitle_UNICODE"))
	{
		return 52;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_ASCII"))
	{
		return 181;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SMI_ParseOneSubtitle_UNICODE"))
	{
		return 364;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII"))
	{
		return 216;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE"))
	{
		return 434;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_ASCII_Ver10"))
	{
		return 215;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TTXT_ParseOneSubtitle_UNICODE_Ver10"))
	{
		return 432;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_ASCII"))
	{
		return 97;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_TMPlayer_ParseOneSubtitle_UNICODE"))
	{
		return 196;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_ASCII"))
	{
		return 54;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_DvdSubtitleSystem_ParseOneSubtitle_UNICODE"))
	{
		return 110;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_ASCII"))
	{
		return 263;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test__MApp_MPlayer_SUBIDX_ParseOneSubtitle_UNICODE"))
	{
		return 528;
	}
	else if(CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Length_Logic0"))
	{
		return 100;
	}
    return 1UL;
}

/** User stub definition for function: void MApp_MPlayer_CloseSubtitleFileHandle(void) */
EXTERN_C_LINKAGE void MApp_MPlayer_CloseSubtitleFileHandle (void) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_MPlayer_CloseSubtitleFileHandle (void)
{
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_SRT_Parser(U32, enumMplayerSubtitleCoding *) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_SRT_Parser (U32 u32FileSize, enumMplayerSubtitleCoding * pCodingType) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_SRT_Parser (U32 u32FileSize, enumMplayerSubtitleCoding * pCodingType)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_subtitle_test_MApp_MPlayer_Subtitle_Parser_TRUE"))
	{
		return (unsigned char)1;
	}
}

/** User stub definition for function: EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SRT_ParseOneSubtitle(MPlayer_Subtitle_Tag *, U32) */
EXTERN_C_LINKAGE EN_PARSE_ONE_SUBTITLE_RET _MApp_MPlayer_SRT_ParseOneSubtitle (MPlayer_Subtitle_Tag * pSubtitleTag, U32 u32SubtitlePhyAddr) ;
EXTERN_C_LINKAGE EN_PARSE_ONE_SUBTITLE_RET CppTest_Stub__MApp_MPlayer_SRT_ParseOneSubtitle (MPlayer_Subtitle_Tag * pSubtitleTag, U32 u32SubtitlePhyAddr)
{
    return E_PARSE_ONE_SUBTITLE_DONE;
}

/** User stub definition for function: void MApi_AUDIO_SetInput(void) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetInput () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetInput (void)
{
}

/** User stub definition for function: void MApi_AUDIO_SetSampleRateIndex(MS_U16) */
EXTERN_C_LINKAGE void MApi_AUDIO_SetSampleRateIndex (MS_U16 u16Index) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_SetSampleRateIndex (MS_U16 u16Index)
{
}

/** User stub definition for function: void MApi_AUDIO_FileEndNotification(void) */
EXTERN_C_LINKAGE void MApi_AUDIO_FileEndNotification () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApi_AUDIO_FileEndNotification (void)
{
}
/** User stub definition for function: U32 MApp_MPlayer_GetCurExternalSubtitleLanguage(void) */
EXTERN_C_LINKAGE U32 MApp_MPlayer_GetCurExternalSubtitleLanguage () ;
EXTERN_C_LINKAGE U32 CppTest_Stub_MApp_MPlayer_GetCurExternalSubtitleLanguage (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_QueryCurMovieSubtitleLanguage_External"))
	{
		return (U32)0x00476E65;
	}
    return 0UL;
}

/** User stub definition for function: void MApp_MPlayer_SubtitleParser_Main(U32) */
EXTERN_C_LINKAGE void MApp_MPlayer_SubtitleParser_Main (U32 u32Time) ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_MPlayer_SubtitleParser_Main (U32 u32Time)
{
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_GetAliveTextSubtitleTag(U32, U8 *, MPlayer_Subtitle_Tag *, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_GetAliveTextSubtitleTag (U32 u32Time, U8 * pu8AliveSubtitleNum, MPlayer_Subtitle_Tag * pAliveSubtitles, BOOLEAN bSubtitleShownFLG) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_GetAliveTextSubtitleTag (U32 u32Time, U8 * pu8AliveSubtitleNum, MPlayer_Subtitle_Tag * pAliveSubtitles, BOOLEAN bSubtitleShownFLG)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test__MApp_MPlayer_SubtitleTask_External_Text"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: U16 _MApp_MPlayer_GetSubtitle(U8 *, U32, U32) */
EXTERN_C_LINKAGE U16 _MApp_MPlayer_GetSubtitle (U8 * pu8Dst, U32 u32BufSize, U32 u32SubtitlePos) ;
EXTERN_C_LINKAGE U16 CppTest_Stub__MApp_MPlayer_GetSubtitle (U8 * pu8Dst, U32 u32BufSize, U32 u32SubtitlePos)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test__MApp_MPlayer_SubtitleTask_External_Text"))
	{
		return (unsigned short)1;
	}
    return (unsigned short)0;
}

/** User stub definition for function: U8 MApp_FileBrowser_Create(U16) */
EXTERN_C_LINKAGE U8 MApp_FileBrowser_Create (U16 driveIndex) ;
EXTERN_C_LINKAGE U8 CppTest_Stub_MApp_FileBrowser_Create (U16 driveIndex)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_GetPlayListFileInfo_Music"))
	{
		return (unsigned char)1;
	}
	return (unsigned char)0;
}

/** User stub definition for function: enumMPlayerRet MApp_MPlayer_StopMusic(void) */
EXTERN_C_LINKAGE enumMPlayerRet MApp_MPlayer_StopMusic (void) ;
EXTERN_C_LINKAGE enumMPlayerRet CppTest_Stub_MApp_MPlayer_StopMusic (void)
{
    return E_MPLAYER_RET_OK;
}

/** User stub definition for function: void MApp_VDPlayer_Stop(void) */
EXTERN_C_LINKAGE void MApp_VDPlayer_Stop () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_VDPlayer_Stop (void)
{
}

/** User stub definition for function: EN_FILE_CLOSE_RESULT msAPI_FCtrl_FileClose(U8) */
EXTERN_C_LINKAGE_START
extern BOOLEAN bTest_msAPI_DataStreamIO_Close_CallmsAPI_FCtrl_FileClose = FALSE;
EXTERN_C_LINKAGE_END
EXTERN_C_LINKAGE EN_FILE_CLOSE_RESULT msAPI_FCtrl_FileClose (U8 u8HandleNo) ;
EXTERN_C_LINKAGE EN_FILE_CLOSE_RESULT CppTest_Stub_msAPI_FCtrl_FileClose (U8 u8HandleNo)
{
	if (CppTest_IsCurrentTestCase("TestSuit_msAPI_DataStreamIO_test_msAPI_DataStreamIO_Close_Logic0"))
	{
		if (u8HandleNo == INVALID_FILE_HANDLE)
		{
			bTest_msAPI_DataStreamIO_Close_CallmsAPI_FCtrl_FileClose = TRUE;
		}
	}
    return FILE_CLOSE_RESULT_ERROR;
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_EnableInternalSubtitle(BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_EnableInternalSubtitle (BOOLEAN bEnable) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_EnableInternalSubtitle (BOOLEAN bEnable)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_PlayPrev(enumMPlayerIdx) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_PlayPrev (enumMPlayerIdx eMPlayerIdx) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_PlayPrev (enumMPlayerIdx eMPlayerIdx)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Music_E_MPLAYER_RET_OK"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayPrevFile_Movie_E_MPLAYER_RET_OK"))
	{
		return (unsigned char)1;
	}
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_GetPlayListAddressByMediaType(enumMPlayerMediaType, U32 *) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_GetPlayListAddressByMediaType (enumMPlayerMediaType eMediaType, U32 * pu32XdataWindowBase) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_GetPlayListAddressByMediaType (enumMPlayerMediaType eMediaType, U32 * pu32XdataWindowBase)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_GetFileSizeByPlaylistIndex_TRUE"))
	{
		return (unsigned char)0;
	}
    return (unsigned char)1;
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_PlayDirectory(enumMPlayerIdx) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_PlayDirectory (enumMPlayerIdx eMPlayerIdx) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_PlayDirectory (enumMPlayerIdx eMPlayerIdx)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_PlayerInit(enumMPlayerIdx, enumMPlayerMediaType, BOOLEAN) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_PlayerInit (enumMPlayerIdx eMPlayerIdx, enumMPlayerMediaType eMediaType, BOOLEAN bPreview) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_PlayerInit (enumMPlayerIdx eMPlayerIdx, enumMPlayerMediaType eMediaType, BOOLEAN bPreview)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_E_MPLAYER_PLAY_ONE_DIRECTORY_E_MPLAYER_RET_OK"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_0_E_MPLAYER_RET_FAIL"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_mplayer_test_MApp_MPlayer_PlayMusic_NotMusic_m_u16SelectedFileNum_1_E_MPLAYER_RET_FAIL"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_MPlayer_PlayList(enumMPlayerIdx) */
EXTERN_C_LINKAGE BOOLEAN _MApp_MPlayer_PlayList (enumMPlayerIdx eMPlayerIdx) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_MPlayer_PlayList (enumMPlayerIdx eMPlayerIdx)
{
    return (unsigned char)0;
}

/** User stub definition for function: void _MApp_VDPlayer_ScaleScalerWindows(VDPLAYER_ZOOM_FACT, BOOLEAN) */
EXTERN_C_LINKAGE void _MApp_VDPlayer_ScaleScalerWindows (VDPLAYER_ZOOM_FACT eZoom, BOOLEAN bIsFirstTimeSetup) ;
EXTERN_C_LINKAGE void CppTest_Stub__MApp_VDPlayer_ScaleScalerWindows (VDPLAYER_ZOOM_FACT eZoom, BOOLEAN bIsFirstTimeSetup)
{
}

/** User stub definition for function: U32 _MApp_VDPlayer_GetShareMemData(U16) */
EXTERN_C_LINKAGE U32 _MApp_VDPlayer_GetShareMemData (U16 idx_ptr) ;
EXTERN_C_LINKAGE U32 CppTest_Stub__MApp_VDPlayer_GetShareMemData (U16 idx_ptr)
{
    return 0UL;
}

/** User stub definition for function: void msAPI_VDPlayer_GetShareMemoryDataAVIScan(PST_HK_AVI_SCAN) */
EXTERN_C_LINKAGE void msAPI_VDPlayer_GetShareMemoryDataAVIScan (PST_HK_AVI_SCAN pstInfo) ;
EXTERN_C_LINKAGE void CppTest_Stub_msAPI_VDPlayer_GetShareMemoryDataAVIScan (PST_HK_AVI_SCAN pstInfo)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_AVIScanIndex_return_TRUE"))
	{
		pstInfo->bEnableCalcByBitRate = TRUE;
		pstInfo->bEnableAudioHandler = TRUE;

		return;
	}

}

/** User stub definition for function: EN_AVI_DEMUX_RETURN msAPI_VDPlayer_DemuxAVI_ScanIndex_OpenDML(void) */
EXTERN_C_LINKAGE EN_AVI_DEMUX_RETURN msAPI_VDPlayer_DemuxAVI_ScanIndex_OpenDML (void) ;
EXTERN_C_LINKAGE EN_AVI_DEMUX_RETURN CppTest_Stub_msAPI_VDPlayer_DemuxAVI_ScanIndex_OpenDML (void)
{
    return E_AVI_DEMUX_SUCCESS;
}

/** User stub definition for function: EN_AVI_DEMUX_RETURN msAPI_VDPlayer_DemuxAVI_ScanIndex_OldStyle(void) */
EXTERN_C_LINKAGE EN_AVI_DEMUX_RETURN msAPI_VDPlayer_DemuxAVI_ScanIndex_OldStyle (void) ;
EXTERN_C_LINKAGE EN_AVI_DEMUX_RETURN CppTest_Stub_msAPI_VDPlayer_DemuxAVI_ScanIndex_OldStyle (void)
{
    return E_AVI_DEMUX_SUCCESS;
}

/** User stub definition for function: void MApp_VDPlayer_MailBoxHandler(void);*/
EXTERN_C_LINKAGE void MApp_VDPlayer_MailBoxHandler () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_VDPlayer_MailBoxHandler (void)
{
	CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_ClearVDPlayerAckFlags");

	if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_QueryDRMRentalStatus_TRUE"))
	{
		CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmRentalStatus");
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMAutuorization_TRUE"))
	{
		CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmAuthorization");
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckDRMActivationFile_TRUE"))
	{
		CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetbDrmActivationFile");

	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_TRUE"))
	{
		CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_msAPI_VDPlayer_Setu8VDPlayerInitResult");
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetAudioTrackID_TRUE"))
	{
		CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerSetAudioTrackResult");
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetStep_return_TRUE"))
	{
		CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Setu8VDPlayerStepPlayResult");
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_SetTrickMode_return_TRUE"))
	{
		//Setu8VDPlayerSetTrickModeResult();
	}

	return;
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_CheckDRMAutuorization(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_CheckDRMAutuorization (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_CheckDRMAutuorization (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Play_return_TRUE"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_LoadDrmSetting(void) */
EXTERN_C_LINKAGE void MApp_LoadDrmSetting () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_LoadDrmSetting (void)
{
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_tmp_init(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_tmp_init (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_tmp_init (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_GetDRMRegistrationCode(U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_GetDRMRegistrationCode (U32 drmCodeAddr) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_GetDRMRegistrationCode (U32 drmCodeAddr)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_CheckAndGenDRMData_TRUE"))
	{
		return (unsigned char)1;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Deactivate_TRUE"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: BOOL MApp_WriteDatabase(U32, U8 *, U16) */
EXTERN_C_LINKAGE BOOL MApp_WriteDatabase (U32 dstIndex, U8 * srcAddr, U16 size) ;
EXTERN_C_LINKAGE BOOL CppTest_Stub_MApp_WriteDatabase (U32 dstIndex, U8 * srcAddr, U16 size)
{
}

/** User stub definition for function: void MApp_VDPlayer_LoadBinToCrop(void) */
EXTERN_C_LINKAGE void MApp_VDPlayer_LoadBinToCrop () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_VDPlayer_LoadBinToCrop (void)
{
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_LoadDRMMemory(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_LoadDRMMemory (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_LoadDRMMemory (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_SaveDRMMemory(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_SaveDRMMemory (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_SaveDRMMemory (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN MApp_VDPlayer_GetDRMDeactivationCode(U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_VDPlayer_GetDRMDeactivationCode (U32 drmCodeAddr) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_VDPlayer_GetDRMDeactivationCode (U32 drmCodeAddr)
{
    return (unsigned char)0;
}

/** User stub definition for function: void _Mapp_VDPlayer_SetShareMemData(U16, U32) */
EXTERN_C_LINKAGE void _Mapp_VDPlayer_SetShareMemData (U16 idx_ptr, U32 idx_data) ;
EXTERN_C_LINKAGE void CppTest_Stub__Mapp_VDPlayer_SetShareMemData (U16 idx_ptr, U32 idx_data)
{
}

/** User stub definition for function: BOOLEAN MApp_MPlayer_QueryCurrentDeviceIsConnected(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_MPlayer_QueryCurrentDeviceIsConnected () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub_MApp_MPlayer_QueryCurrentDeviceIsConnected (void)
{
	if(CppTest_IsCurrentTestCase("TestSuite_mapp_videoplayer_test_MApp_VDPlayer_Init_TRUE"))
	{
		return (unsigned char)1;
	}
    return (unsigned char)0;
}

/** User stub definition for function: BOOLEAN _MApp_VDPlayer_CheckPreviewAbortKey(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_VDPlayer_CheckPreviewAbortKey (void) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Stub__MApp_VDPlayer_CheckPreviewAbortKey (void)
{
    return (unsigned char)0;
}

/** User stub definition for function: void MApp_MPlayer_MicroDVD_Subtitle_ReCalceTime(void) */
EXTERN_C_LINKAGE void MApp_MPlayer_MicroDVD_Subtitle_ReCalceTime () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_MPlayer_MicroDVD_Subtitle_ReCalceTime (void)
{
}

/** User stub definition for function: void MApp_SaveGenSetting(void) */
EXTERN_C_LINKAGE void MApp_SaveGenSetting () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_SaveGenSetting (void)
{
}

/** User stub definition for function: void MApp_ProcessUserInput(void) */
EXTERN_C_LINKAGE void MApp_ProcessUserInput () ;
EXTERN_C_LINKAGE void CppTest_Stub_MApp_ProcessUserInput (void)
{
}

/** User stub definition for function: U16 _MApp_MPlayer_SubtitleDataFilter(U8 *, U16, const char *, U8, const char *, U8, BOOLEAN) */
EXTERN_C_LINKAGE U16 _MApp_MPlayer_SubtitleDataFilter (U8 * pu8Data, U16 u16Len, const char * pu8FilterStartData, U8 u8FilterStartLen, const char * pu8FilterEndData, U8 u8FilterEndLen, BOOLEAN bUniCode) ;
EXTERN_C_LINKAGE U16 CppTest_Stub__MApp_MPlayer_SubtitleDataFilter (U8 * pu8Data, U16 u16Len, const char * pu8FilterStartData, U8 u8FilterStartLen, const char * pu8FilterEndData, U8 u8FilterEndLen, BOOLEAN bUniCode)
{
    return (unsigned short)0;
}
