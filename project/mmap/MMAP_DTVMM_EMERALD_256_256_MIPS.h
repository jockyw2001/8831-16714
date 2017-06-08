////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// ("MStar Confidential Information") by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// DRAM memory map
//
// Every Module Memory Mapping need 4 define,
// and check code in "msAPI_Memory_DumpMemoryMap"
// 1. XXX_AVAILABLE : For get avaialble memory start address
// 2. XXX_ADR       : Real Address with Alignment
// 3. XXX_GAP_CHK   : For Check Memory Gap, for avoid memory waste
// 4. XXX_LEN       : For the Memory size of this Module usage
////////////////////////////////////////////////////////////////////////////////
#define MIU_DRAM_LEN                0x0020000000
#define MIU_DRAM_LEN0               0x0010000000
#define MIU_DRAM_LEN1               0x0010000000

#define ENABLE_MIU_1                1
#define MIU_INTERVAL                0x0020000000

////////////////////////////////////////////////////////////////////////////////
//MEMORY TYPE
////////////////////////////////////////////////////////////////////////////////
#define MIU0                        (0x0000)
#define MIU1                        (0x0001)

#define SW                          (0x0000 << 1)
#define HW                          (0x0001 << 1)
#define SW_HW                       (0x0002 << 1)

#define UNCACHED                    (0x0000 << 3)
#define WRITE_THROUGH               (0x0001 << 3)
#define WRITE_COMBINING             (0x0002 << 3)
#define WRITE_PROTECT               (0x0003 << 3)
#define WRITE_BACK                  (0x0004 << 3)


//MIU_0_START
/* AEON_MEM   */
//co_buffer L0
#define AEON_MEM_AVAILABLE                                     0x0000000000
#define AEON_MEM_ADR                                           0x0000000000  //Alignment 0
#define AEON_MEM_GAP_CHK                                       0x0000000000
#define AEON_MEM_LEN                                           0x0000A00000
#define AEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* AEON_MM_MEM   */
//co_buffer L1
#define AEON_MM_MEM_AVAILABLE                                  0x0000000000
#define AEON_MM_MEM_ADR                                        0x0000000000  //Alignment 0
#define AEON_MM_MEM_GAP_CHK                                    0x0000000000
#define AEON_MM_MEM_LEN                                        0x00003B0000
#define AEON_MM_MEM_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* BEON_MEM   */
//co_buffer L0
#define BEON_MEM_AVAILABLE                                     0x0000A00000
#define BEON_MEM_ADR                                           0x0000A00000  //Alignment 0x10000
#define BEON_MEM_GAP_CHK                                       0x0000000000
#define BEON_MEM_LEN                                           0x00006D46D8
#define BEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* SECBUF_START   */
//co_buffer L0
#define SECBUF_START_AVAILABLE                                 0x00010D46D8
#define SECBUF_START_ADR                                       0x00010E0000  //Alignment 0x10000
#define SECBUF_START_GAP_CHK                                   0x000000B928
#define SECBUF_START_LEN                                       0x0000023000
#define SECBUF_START_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* TSP_VQ_BUFFER   */
//co_buffer L0
#define TSP_VQ_BUFFER_AVAILABLE                                0x0001103000
#define TSP_VQ_BUFFER_ADR                                      0x0001103000  //Alignment 0x00010
#define TSP_VQ_BUFFER_GAP_CHK                                  0x0000000000
#define TSP_VQ_BUFFER_LEN                                      0x0000000C00
#define TSP_VQ_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* MPLAYER_APP_POOL   */
//co_buffer L0
#define MPLAYER_APP_POOL_AVAILABLE                             0x0001103C00
#define MPLAYER_APP_POOL_ADR                                   0x0001104000  //Alignment 0x01000
#define MPLAYER_APP_POOL_GAP_CHK                               0x0000000400
#define MPLAYER_APP_POOL_LEN                                   0x0000220000
#define MPLAYER_APP_POOL_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* MPLAYER_FILE_BUFFER   */
//co_buffer L1
#define MPLAYER_FILE_BUFFER_AVAILABLE                          0x0001104000
#define MPLAYER_FILE_BUFFER_ADR                                0x0001104000  //Alignment 0x01000
#define MPLAYER_FILE_BUFFER_GAP_CHK                            0x0000000000
#define MPLAYER_FILE_BUFFER_LEN                                0x0000100000
#define MPLAYER_FILE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* MPLAYER_MUSIC_FILE_BUFFER   */
//co_buffer L1
#define MPLAYER_MUSIC_FILE_BUFFER_AVAILABLE                    0x0001204000
#define MPLAYER_MUSIC_FILE_BUFFER_ADR                          0x0001204000  //Alignment 0x01000
#define MPLAYER_MUSIC_FILE_BUFFER_GAP_CHK                      0x0000000000
#define MPLAYER_MUSIC_FILE_BUFFER_LEN                          0x0000080000
#define MPLAYER_MUSIC_FILE_BUFFER_MEMORY_TYPE                  (MIU0 | SW | WRITE_BACK)

/* MPLAYER_PHOTO_PLAYLIST   */
//co_buffer L1
#define MPLAYER_PHOTO_PLAYLIST_AVAILABLE                       0x0001284000
#define MPLAYER_PHOTO_PLAYLIST_ADR                             0x0001284000  //Alignment 0x01000
#define MPLAYER_PHOTO_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_PHOTO_PLAYLIST_LEN                             0x0000014000
#define MPLAYER_PHOTO_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* MPLAYER_MUSIC_PLAYLIST   */
//co_buffer L1
#define MPLAYER_MUSIC_PLAYLIST_AVAILABLE                       0x0001298000
#define MPLAYER_MUSIC_PLAYLIST_ADR                             0x0001298000  //Alignment 0x01000
#define MPLAYER_MUSIC_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MUSIC_PLAYLIST_LEN                             0x0000014000
#define MPLAYER_MUSIC_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* MPLAYER_MOVIE_PLAYLIST   */
//co_buffer L1
#define MPLAYER_MOVIE_PLAYLIST_AVAILABLE                       0x00012AC000
#define MPLAYER_MOVIE_PLAYLIST_ADR                             0x00012AC000  //Alignment 0x01000
#define MPLAYER_MOVIE_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MOVIE_PLAYLIST_LEN                             0x0000014000
#define MPLAYER_MOVIE_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* MPLAYER_TEXT_PLAYLIST   */
//co_buffer L1
#define MPLAYER_TEXT_PLAYLIST_AVAILABLE                        0x00012C0000
#define MPLAYER_TEXT_PLAYLIST_ADR                              0x00012C0000  //Alignment 0x01000
#define MPLAYER_TEXT_PLAYLIST_GAP_CHK                          0x0000000000
#define MPLAYER_TEXT_PLAYLIST_LEN                              0x0000014000
#define MPLAYER_TEXT_PLAYLIST_MEMORY_TYPE                      (MIU0 | SW | WRITE_BACK)

/* MPLAYER_EMU_PLAYLIST   */
//co_buffer L1
#define MPLAYER_EMU_PLAYLIST_AVAILABLE                         0x00012D4000
#define MPLAYER_EMU_PLAYLIST_ADR                               0x00012D4000  //Alignment 0x01000
#define MPLAYER_EMU_PLAYLIST_GAP_CHK                           0x0000000000
#define MPLAYER_EMU_PLAYLIST_LEN                               0x0000014000
#define MPLAYER_EMU_PLAYLIST_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* MUSIC_LYRIC_BUFFER   */
//co_buffer L1
#define MUSIC_LYRIC_BUFFER_AVAILABLE                           0x00012E8000
#define MUSIC_LYRIC_BUFFER_ADR                                 0x00012E8000  //Alignment 0x01000
#define MUSIC_LYRIC_BUFFER_GAP_CHK                             0x0000000000
#define MUSIC_LYRIC_BUFFER_LEN                                 0x0000010000
#define MUSIC_LYRIC_BUFFER_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* MUSIC_LYRIC_TAG   */
//co_buffer L1
#define MUSIC_LYRIC_TAG_AVAILABLE                              0x00012F8000
#define MUSIC_LYRIC_TAG_ADR                                    0x00012F8000  //Alignment 0x01000
#define MUSIC_LYRIC_TAG_GAP_CHK                                0x0000000000
#define MUSIC_LYRIC_TAG_LEN                                    0x0000001000
#define MUSIC_LYRIC_TAG_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* MP3_INFO_READ   */
//co_buffer L1
#define MP3_INFO_READ_AVAILABLE                                0x00012F9000
#define MP3_INFO_READ_ADR                                      0x00012F9000  //Alignment 0x01000
#define MP3_INFO_READ_GAP_CHK                                  0x0000000000
#define MP3_INFO_READ_LEN                                      0x0000001000
#define MP3_INFO_READ_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* M4A_BUFFER   */
//co_buffer L1
#define M4A_BUFFER_AVAILABLE                                   0x00012FA000
#define M4A_BUFFER_ADR                                         0x00012FA000  //Alignment 0x01000
#define M4A_BUFFER_GAP_CHK                                     0x0000000000
#define M4A_BUFFER_LEN                                         0x0000004000
#define M4A_BUFFER_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* M4A_STCO   */
//co_buffer L1
#define M4A_STCO_AVAILABLE                                     0x00012FE000
#define M4A_STCO_ADR                                           0x00012FE000  //Alignment 0x01000
#define M4A_STCO_GAP_CHK                                       0x0000000000
#define M4A_STCO_LEN                                           0x0000018000
#define M4A_STCO_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* USB_BUFFER_START   */
//co_buffer L0
#define USB_BUFFER_START_AVAILABLE                             0x0001324000
#define USB_BUFFER_START_ADR                                   0x0001324000  //Alignment 0x01000
#define USB_BUFFER_START_GAP_CHK                               0x0000000000
#define USB_BUFFER_START_LEN                                   0x0000001000
#define USB_BUFFER_START_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* USB_BUFFER2_START   */
//co_buffer L0
#define USB_BUFFER2_START_AVAILABLE                            0x0001325000
#define USB_BUFFER2_START_ADR                                  0x0001325000  //Alignment 0x01000
#define USB_BUFFER2_START_GAP_CHK                              0x0000000000
#define USB_BUFFER2_START_LEN                                  0x0000001000
#define USB_BUFFER2_START_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* FILE_OPERATION_INFO_BUFFER   */
//co_buffer L0
#define FILE_OPERATION_INFO_BUFFER_AVAILABLE                   0x0001326000
#define FILE_OPERATION_INFO_BUFFER_ADR                         0x0001326000  //Alignment 0x01000
#define FILE_OPERATION_INFO_BUFFER_GAP_CHK                     0x0000000000
#define FILE_OPERATION_INFO_BUFFER_LEN                         0x0000000C00
#define FILE_OPERATION_INFO_BUFFER_MEMORY_TYPE                 (MIU0 | SW | WRITE_BACK)

/* PATH_INFO_BUFFER   */
//co_buffer L0
#define PATH_INFO_BUFFER_AVAILABLE                             0x0001326C00
#define PATH_INFO_BUFFER_ADR                                   0x0001326C00  //Alignment 0
#define PATH_INFO_BUFFER_GAP_CHK                               0x0000000000
#define PATH_INFO_BUFFER_LEN                                   0x0000000400
#define PATH_INFO_BUFFER_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE   */
//co_buffer L0
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_AVAILABLE      0x0001327000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_ADR            0x0001328000  //Alignment 0x04000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_GAP_CHK        0x0000001000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_LEN            0x0000004000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_MEMORY_TYPE    (MIU0 | SW | WRITE_BACK)

/* FILE_SYSTEM_POOL   */
//co_buffer L0
#define FILE_SYSTEM_POOL_AVAILABLE                             0x000132C000
#define FILE_SYSTEM_POOL_ADR                                   0x000132C000  //Alignment 0x01000
#define FILE_SYSTEM_POOL_GAP_CHK                               0x0000000000
#define FILE_SYSTEM_POOL_LEN                                   0x0000060000
#define FILE_SYSTEM_POOL_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* PHOTO_SHARE_MEM   */
//co_buffer L0
#define PHOTO_SHARE_MEM_AVAILABLE                              0x000138C000
#define PHOTO_SHARE_MEM_ADR                                    0x000138C000  //Alignment 0x00004
#define PHOTO_SHARE_MEM_GAP_CHK                                0x0000000000
#define PHOTO_SHARE_MEM_LEN                                    0x0000000400
#define PHOTO_SHARE_MEM_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* MAD_BASE_BUFFER   */
//co_buffer L0
#define MAD_BASE_BUFFER_AVAILABLE                              0x000138C400
#define MAD_BASE_BUFFER_ADR                                    0x000138D000  //Alignment 0x01000
#define MAD_BASE_BUFFER_GAP_CHK                                0x0000000C00
#define MAD_BASE_BUFFER_LEN                                    0x0000300000
#define MAD_BASE_BUFFER_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* GOP_REGDMABASE   */
//co_buffer L0
#define GOP_REGDMABASE_AVAILABLE                               0x000168D000
#define GOP_REGDMABASE_ADR                                     0x000168E000  //Alignment 0x02000
#define GOP_REGDMABASE_GAP_CHK                                 0x0000001000
#define GOP_REGDMABASE_LEN                                     0x0000001000
#define GOP_REGDMABASE_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* BMP_INFO_POOL   */
//co_buffer L0
#define BMP_INFO_POOL_AVAILABLE                                0x000168F000
#define BMP_INFO_POOL_ADR                                      0x000168F000  //Alignment 0x00008
#define BMP_INFO_POOL_GAP_CHK                                  0x0000000000
#define BMP_INFO_POOL_LEN                                      0x0000002000
#define BMP_INFO_POOL_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* DATABASE_START   */
//co_buffer L0
#define DATABASE_START_AVAILABLE                               0x0001691000
#define DATABASE_START_ADR                                     0x0001691000  //Alignment 0x00008
#define DATABASE_START_GAP_CHK                                 0x0000000000
#define DATABASE_START_LEN                                     0x0000011000
#define DATABASE_START_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* FONT_START   */
//co_buffer L0
#define FONT_START_AVAILABLE                                   0x00016A2000
#define FONT_START_ADR                                         0x00016A2000  //Alignment 0x00008
#define FONT_START_GAP_CHK                                     0x0000000000
#define FONT_START_LEN                                         0x000012C000
#define FONT_START_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* GE_FRAMEBUFFER   */
//co_buffer L0
#define GE_FRAMEBUFFER_AVAILABLE                               0x00017CE000
#define GE_FRAMEBUFFER_ADR                                     0x00017CE000  //Alignment 0x00008
#define GE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define GE_FRAMEBUFFER_LEN                                     0x00008A0800
#define GE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* GOP_GWIN_RB   */
//co_buffer L1
#define GOP_GWIN_RB_AVAILABLE                                  0x00017CE000
#define GOP_GWIN_RB_ADR                                        0x00017CE000  //Alignment 0x00008
#define GOP_GWIN_RB_GAP_CHK                                    0x0000000000
#define GOP_GWIN_RB_LEN                                        0x00008A0800
#define GOP_GWIN_RB_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* MHEG5_FRAMEBUFFER   */
//co_buffer L0
#define MHEG5_FRAMEBUFFER_AVAILABLE                            0x000206E800
#define MHEG5_FRAMEBUFFER_ADR                                  0x000206E800  //Alignment 0x00008
#define MHEG5_FRAMEBUFFER_GAP_CHK                              0x0000000000
#define MHEG5_FRAMEBUFFER_LEN                                  0x000025F800
#define MHEG5_FRAMEBUFFER_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* SUBTITLE   */
//co_buffer L0
#define SUBTITLE_AVAILABLE                                     0x00022CE000
#define SUBTITLE_ADR                                           0x00022D0000  //Alignment 0x10000
#define SUBTITLE_GAP_CHK                                       0x0000002000
#define SUBTITLE_LEN                                           0x0000380000
#define SUBTITLE_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* SI_MONITOR_DB   */
//co_buffer L0
#define SI_MONITOR_DB_AVAILABLE                                0x0002650000
#define SI_MONITOR_DB_ADR                                      0x0002650000  //Alignment 0x00008
#define SI_MONITOR_DB_GAP_CHK                                  0x0000000000
#define SI_MONITOR_DB_LEN                                      0x000000E000
#define SI_MONITOR_DB_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* SRV_NAME_BUF   */
//co_buffer L0
#define SRV_NAME_BUF_AVAILABLE                                 0x000265E000
#define SRV_NAME_BUF_ADR                                       0x000265E000  //Alignment 0x01000
#define SRV_NAME_BUF_GAP_CHK                                   0x0000000000
#define SRV_NAME_BUF_LEN                                       0x0000001000
#define SRV_NAME_BUF_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* FONT_INFO_POOL   */
//co_buffer L0
#define FONT_INFO_POOL_AVAILABLE                               0x000265F000
#define FONT_INFO_POOL_ADR                                     0x000265F000  //Alignment 0x00008
#define FONT_INFO_POOL_GAP_CHK                                 0x0000000000
#define FONT_INFO_POOL_LEN                                     0x0000000800
#define FONT_INFO_POOL_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* MMI_TEXTSTRING   */
//co_buffer L0
#define MMI_TEXTSTRING_AVAILABLE                               0x000265F800
#define MMI_TEXTSTRING_ADR                                     0x0002660000  //Alignment 0x01000
#define MMI_TEXTSTRING_GAP_CHK                                 0x0000000800
#define MMI_TEXTSTRING_LEN                                     0x0000001000
#define MMI_TEXTSTRING_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* CI_PMT_BUFFER   */
//co_buffer L0
#define CI_PMT_BUFFER_AVAILABLE                                0x0002661000
#define CI_PMT_BUFFER_ADR                                      0x0002661000  //Alignment 0
#define CI_PMT_BUFFER_GAP_CHK                                  0x0000000000
#define CI_PMT_BUFFER_LEN                                      0x0000001000
#define CI_PMT_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* PMT_FILTER   */
//co_buffer L0
#define PMT_FILTER_AVAILABLE                                   0x0002662000
#define PMT_FILTER_ADR                                         0x0002662000  //Alignment 0
#define PMT_FILTER_GAP_CHK                                     0x0000000000
#define PMT_FILTER_LEN                                         0x0000000800
#define PMT_FILTER_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* VE_FRAMEBUFFER   */
//co_buffer L0
#define VE_FRAMEBUFFER_AVAILABLE                               0x0002662800
#define VE_FRAMEBUFFER_ADR                                     0x0002662800  //Alignment 0x00008
#define VE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define VE_FRAMEBUFFER_LEN                                     0x000032A000
#define VE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* KTV_DATABASE_BUFFER   */
//co_buffer L1
#define KTV_DATABASE_BUFFER_AVAILABLE                          0x0002662800
#define KTV_DATABASE_BUFFER_ADR                                0x0002663000  //Alignment 0x01000
#define KTV_DATABASE_BUFFER_GAP_CHK                            0x0000000800
#define KTV_DATABASE_BUFFER_LEN                                0x0000195000
#define KTV_DATABASE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* BT_HK_TO_BEON_SHAER_BUFFER   */
//co_buffer L2
#define BT_HK_TO_BEON_SHAER_BUFFER_AVAILABLE                   0x0002662800
#define BT_HK_TO_BEON_SHAER_BUFFER_ADR                         0x0002663000  //Alignment 0x01000
#define BT_HK_TO_BEON_SHAER_BUFFER_GAP_CHK                     0x0000000800
#define BT_HK_TO_BEON_SHAER_BUFFER_LEN                         0x0000000400
#define BT_HK_TO_BEON_SHAER_BUFFER_MEMORY_TYPE                 (MIU0 | SW | WRITE_BACK)

/* BT_BEON_TO_HK_SHAER_BUFFER   */
//co_buffer L2
#define BT_BEON_TO_HK_SHAER_BUFFER_AVAILABLE                   0x0002663400
#define BT_BEON_TO_HK_SHAER_BUFFER_ADR                         0x0002663400  //Alignment 0x00100
#define BT_BEON_TO_HK_SHAER_BUFFER_GAP_CHK                     0x0000000000
#define BT_BEON_TO_HK_SHAER_BUFFER_LEN                         0x0000100000
#define BT_BEON_TO_HK_SHAER_BUFFER_MEMORY_TYPE                 (MIU0 | SW | WRITE_BACK)

/* BT_HK_DESCRIP_DATA_BUFFER   */
//co_buffer L2
#define BT_HK_DESCRIP_DATA_BUFFER_AVAILABLE                    0x0002763400
#define BT_HK_DESCRIP_DATA_BUFFER_ADR                          0x0002763400  //Alignment 0x00100
#define BT_HK_DESCRIP_DATA_BUFFER_GAP_CHK                      0x0000000000
#define BT_HK_DESCRIP_DATA_BUFFER_LEN                          0x0000000800
#define BT_HK_DESCRIP_DATA_BUFFER_MEMORY_TYPE                  (MIU0 | SW | WRITE_BACK)

/* BT_HK_IMAGE_DATA_BUFFER   */
//co_buffer L2
#define BT_HK_IMAGE_DATA_BUFFER_AVAILABLE                      0x0002763C00
#define BT_HK_IMAGE_DATA_BUFFER_ADR                            0x0002763C00  //Alignment 0x00100
#define BT_HK_IMAGE_DATA_BUFFER_GAP_CHK                        0x0000000000
#define BT_HK_IMAGE_DATA_BUFFER_LEN                            0x0000100000
#define BT_HK_IMAGE_DATA_BUFFER_MEMORY_TYPE                    (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_BUF   */
//co_buffer L0
#define SCALER_DNR_BUF_AVAILABLE                               0x000298C800
#define SCALER_DNR_BUF_ADR                                     0x000298C800  //Alignment 0x00010
#define SCALER_DNR_BUF_GAP_CHK                                 0x0000000000
#define SCALER_DNR_BUF_LEN                                     0x0001800000
#define SCALER_DNR_BUF_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* DOWNLOAD_BUFFER   */
//co_buffer L1
#define DOWNLOAD_BUFFER_AVAILABLE                              0x000298C800
#define DOWNLOAD_BUFFER_ADR                                    0x000298D000  //Alignment 0x01000
#define DOWNLOAD_BUFFER_GAP_CHK                                0x0000000800
#define DOWNLOAD_BUFFER_LEN                                    0x0000832000
#define DOWNLOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_W_BARRIER   */
//co_buffer L0
#define SCALER_DNR_W_BARRIER_AVAILABLE                         0x000418C800
#define SCALER_DNR_W_BARRIER_ADR                               0x000418C800  //Alignment 0
#define SCALER_DNR_W_BARRIER_GAP_CHK                           0x0000000000
#define SCALER_DNR_W_BARRIER_LEN                               0x0000000050
#define SCALER_DNR_W_BARRIER_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* POOL_BUFFER   */
//co_buffer L0
#define POOL_BUFFER_AVAILABLE                                  0x000418C850
#define POOL_BUFFER_ADR                                        0x000418C860  //Alignment 0x00020
#define POOL_BUFFER_GAP_CHK                                    0x0000000010
#define POOL_BUFFER_LEN                                        0x0001226C00
#define POOL_BUFFER_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* MHEG5_BUFFER   */
//co_buffer L1
#define MHEG5_BUFFER_AVAILABLE                                 0x000418C860
#define MHEG5_BUFFER_ADR                                       0x000418C900  //Alignment 0x00100
#define MHEG5_BUFFER_GAP_CHK                                   0x00000000A0
#define MHEG5_BUFFER_LEN                                       0x0000880000
#define MHEG5_BUFFER_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* PVR_TRICK_MODE   */
//co_buffer L1
#define PVR_TRICK_MODE_AVAILABLE                               0x0004A0C900
#define PVR_TRICK_MODE_ADR                                     0x0004A0D000  //Alignment 0x01000
#define PVR_TRICK_MODE_GAP_CHK                                 0x0000000700
#define PVR_TRICK_MODE_LEN                                     0x0000300000
#define PVR_TRICK_MODE_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* TTXBUF_START   */
//co_buffer L1
#define TTXBUF_START_AVAILABLE                                 0x0004D0D000
#define TTXBUF_START_ADR                                       0x0004D0D000  //Alignment 0x00008
#define TTXBUF_START_GAP_CHK                                   0x0000000000
#define TTXBUF_START_LEN                                       0x0000240000
#define TTXBUF_START_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* TTX_VE_BUFFER   */
//co_buffer L1
#define TTX_VE_BUFFER_AVAILABLE                                0x0004F4D000
#define TTX_VE_BUFFER_ADR                                      0x0004F4D000  //Alignment 0x00008
#define TTX_VE_BUFFER_GAP_CHK                                  0x0000000000
#define TTX_VE_BUFFER_LEN                                      0x0000002000
#define TTX_VE_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* TTX_FONT_START   */
//co_buffer L1
#define TTX_FONT_START_AVAILABLE                               0x0004F4F000
#define TTX_FONT_START_ADR                                     0x0004F4F000  //Alignment 0x00008
#define TTX_FONT_START_GAP_CHK                                 0x0000000000
#define TTX_FONT_START_LEN                                     0x0000040000
#define TTX_FONT_START_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* NAND_COPY_BUFFER   */
//co_buffer L1
#define NAND_COPY_BUFFER_AVAILABLE                             0x0004F8F000
#define NAND_COPY_BUFFER_ADR                                   0x0004F8F000  //Alignment 0x00008
#define NAND_COPY_BUFFER_GAP_CHK                               0x0000000000
#define NAND_COPY_BUFFER_LEN                                   0x0000001000
#define NAND_COPY_BUFFER_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* DECOMPRESS_DATA_BUFFER   */
//co_buffer L2
#define DECOMPRESS_DATA_BUFFER_AVAILABLE                       0x000418C860
#define DECOMPRESS_DATA_BUFFER_ADR                             0x0004200000  //Alignment 0x80000
#define DECOMPRESS_DATA_BUFFER_GAP_CHK                         0x00000737A0
#define DECOMPRESS_DATA_BUFFER_LEN                             0x0000100000
#define DECOMPRESS_DATA_BUFFER_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* DECOMPRESS_READ_BUFFER   */
//co_buffer L2
#define DECOMPRESS_READ_BUFFER_AVAILABLE                       0x0004300000
#define DECOMPRESS_READ_BUFFER_ADR                             0x0004300000  //Alignment 0x80000
#define DECOMPRESS_READ_BUFFER_GAP_CHK                         0x0000000000
#define DECOMPRESS_READ_BUFFER_LEN                             0x0000080000
#define DECOMPRESS_READ_BUFFER_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* COMB_3D_BUF   */
//co_buffer L2
#define COMB_3D_BUF_AVAILABLE                                  0x0004380000
#define COMB_3D_BUF_ADR                                        0x0004380000  //Alignment 0x00010
#define COMB_3D_BUF_GAP_CHK                                    0x0000000000
#define COMB_3D_BUF_LEN                                        0x0000700000
#define COMB_3D_BUF_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* PVR_READ_SDRAM   */
//co_buffer L2
#define PVR_READ_SDRAM_AVAILABLE                               0x0004A80000
#define PVR_READ_SDRAM_ADR                                     0x0004A80000  //Alignment 0
#define PVR_READ_SDRAM_GAP_CHK                                 0x0000000000
#define PVR_READ_SDRAM_LEN                                     0x00000D8000
#define PVR_READ_SDRAM_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* PVR_IO_BUFFER   */
//co_buffer L2
#define PVR_IO_BUFFER_AVAILABLE                                0x0004B58000
#define PVR_IO_BUFFER_ADR                                      0x0004B58000  //Alignment 0
#define PVR_IO_BUFFER_GAP_CHK                                  0x0000000000
#define PVR_IO_BUFFER_LEN                                      0x0000010000
#define PVR_IO_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* DOWNLOAD_ZIPBUFFER   */
//co_buffer L3
#define DOWNLOAD_ZIPBUFFER_AVAILABLE                           0x000418C860
#define DOWNLOAD_ZIPBUFFER_ADR                                 0x000418C860  //Alignment 0
#define DOWNLOAD_ZIPBUFFER_GAP_CHK                             0x0000000000
#define DOWNLOAD_ZIPBUFFER_LEN                                 0x0000400000
#define DOWNLOAD_ZIPBUFFER_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* MPEG2_FILE   */
//co_buffer L4
#define MPEG2_FILE_AVAILABLE                                   0x000418C860
#define MPEG2_FILE_ADR                                         0x000418CA00  //Alignment 0x00200
#define MPEG2_FILE_GAP_CHK                                     0x00000001A0
#define MPEG2_FILE_LEN                                         0x0000500000
#define MPEG2_FILE_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* MPEG2_SBTL_BUFFER   */
//co_buffer L4
#define MPEG2_SBTL_BUFFER_AVAILABLE                            0x000468CA00
#define MPEG2_SBTL_BUFFER_ADR                                  0x000468CA00  //Alignment 0
#define MPEG2_SBTL_BUFFER_GAP_CHK                              0x0000000000
#define MPEG2_SBTL_BUFFER_LEN                                  0x0000200000
#define MPEG2_SBTL_BUFFER_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* OD_BUFFER   */
//co_buffer L4
#define OD_BUFFER_AVAILABLE                                    0x000488CA00
#define OD_BUFFER_ADR                                          0x000488CA00  //Alignment 0x00010
#define OD_BUFFER_GAP_CHK                                      0x0000000000
#define OD_BUFFER_LEN                                          0x00003F6800
#define OD_BUFFER_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* OD_LSB_BUFFER   */
//co_buffer L4
#define OD_LSB_BUFFER_AVAILABLE                                0x0004C83200
#define OD_LSB_BUFFER_ADR                                      0x0004C83200  //Alignment 0x00010
#define OD_LSB_BUFFER_GAP_CHK                                  0x0000000000
#define OD_LSB_BUFFER_LEN                                      0x00001FC400
#define OD_LSB_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* TEXT_FILE   */
//co_buffer L5
#define TEXT_FILE_AVAILABLE                                    0x000418C860
#define TEXT_FILE_ADR                                          0x000418CA00  //Alignment 0x00200
#define TEXT_FILE_GAP_CHK                                      0x00000001A0
#define TEXT_FILE_LEN                                          0x0000002000
#define TEXT_FILE_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_OUT   */
//co_buffer L6
#define MAD_JPEG_OUT_AVAILABLE                                 0x000418C860
#define MAD_JPEG_OUT_ADR                                       0x000418C860  //Alignment 0x00008
#define MAD_JPEG_OUT_GAP_CHK                                   0x0000000000
#define MAD_JPEG_OUT_LEN                                       0x00003FC000
#define MAD_JPEG_OUT_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_READBUFF   */
//co_buffer L6
#define MAD_JPEG_READBUFF_AVAILABLE                            0x0004588860
#define MAD_JPEG_READBUFF_ADR                                  0x0004589000  //Alignment 0x01000
#define MAD_JPEG_READBUFF_GAP_CHK                              0x00000007A0
#define MAD_JPEG_READBUFF_LEN                                  0x0000050080
#define MAD_JPEG_READBUFF_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_INTERBUFF   */
//co_buffer L6
#define MAD_JPEG_INTERBUFF_AVAILABLE                           0x00045D9080
#define MAD_JPEG_INTERBUFF_ADR                                 0x00045E0000  //Alignment 0x10000
#define MAD_JPEG_INTERBUFF_GAP_CHK                             0x0000006F80
#define MAD_JPEG_INTERBUFF_LEN                                 0x0000650000
#define MAD_JPEG_INTERBUFF_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_DISPLAY   */
//co_buffer L6
#define MAD_JPEG_DISPLAY_AVAILABLE                             0x0004C30000
#define MAD_JPEG_DISPLAY_ADR                                   0x0004C30000  //Alignment 0
#define MAD_JPEG_DISPLAY_GAP_CHK                               0x0000000000
#define MAD_JPEG_DISPLAY_LEN                                   0x00003F4800
#define MAD_JPEG_DISPLAY_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* SW_STRING_BUFFER   */
//co_buffer L7
#define SW_STRING_BUFFER_AVAILABLE                             0x000418C860
#define SW_STRING_BUFFER_ADR                                   0x000418C860  //Alignment 0
#define SW_STRING_BUFFER_GAP_CHK                               0x0000000000
#define SW_STRING_BUFFER_LEN                                   0x0000080000
#define SW_STRING_BUFFER_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* NONE   */
//co_buffer L7
#define NONE_AVAILABLE                                         0x000420C860
#define NONE_ADR                                               0x000420C860  //Alignment 0x00008
#define NONE_GAP_CHK                                           0x0000000000
#define NONE_LEN                                               0x000037C000
#define NONE_MEMORY_TYPE                                       (MIU0 | SW | WRITE_BACK)

/* TEXT_DATA_READ   */
//co_buffer L7
#define TEXT_DATA_READ_AVAILABLE                               0x0004588860
#define TEXT_DATA_READ_ADR                                     0x0004589000  //Alignment 0x01000
#define TEXT_DATA_READ_GAP_CHK                                 0x00000007A0
#define TEXT_DATA_READ_LEN                                     0x0000010000
#define TEXT_DATA_READ_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* BMP_DEC_BUFFER   */
//co_buffer L8
#define BMP_DEC_BUFFER_AVAILABLE                               0x000418C860
#define BMP_DEC_BUFFER_ADR                                     0x000418C860  //Alignment 0
#define BMP_DEC_BUFFER_GAP_CHK                                 0x0000000000
#define BMP_DEC_BUFFER_LEN                                     0x0000EA0000
#define BMP_DEC_BUFFER_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_DATA   */
//co_buffer L9
#define VDPLAYER_DATA_AVAILABLE                                0x000418C860
#define VDPLAYER_DATA_ADR                                      0x000418D000  //Alignment 0x01000
#define VDPLAYER_DATA_GAP_CHK                                  0x00000007A0
#define VDPLAYER_DATA_LEN                                      0x0000380000
#define VDPLAYER_DATA_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF   */
//co_buffer L9
#define VDPLAYER_BITSTREAM_BUFF_AVAILABLE                      0x000450D000
#define VDPLAYER_BITSTREAM_BUFF_ADR                            0x000450D000  //Alignment 0
#define VDPLAYER_BITSTREAM_BUFF_GAP_CHK                        0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_LEN                            0x0000400000
#define VDPLAYER_BITSTREAM_BUFF_MEMORY_TYPE                    (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF_EXT   */
//co_buffer L9
#define VDPLAYER_BITSTREAM_BUFF_EXT_AVAILABLE                  0x000490D000
#define VDPLAYER_BITSTREAM_BUFF_EXT_ADR                        0x000490D000  //Alignment 0
#define VDPLAYER_BITSTREAM_BUFF_EXT_GAP_CHK                    0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_EXT_LEN                        0x000059C000
#define VDPLAYER_BITSTREAM_BUFF_EXT_MEMORY_TYPE                (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_SUBTITLE_BITSTREAM_BUFF   */
//co_buffer L9
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_AVAILABLE             0x0004EA9000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR                   0x0004EA9000  //Alignment 0
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_GAP_CHK               0x0000000000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_LEN                   0x0000200000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_MEMORY_TYPE           (MIU0 | SW | WRITE_BACK)

/* MP4_SUBTITLE_BUFFER   */
//co_buffer L9
#define MP4_SUBTITLE_BUFFER_AVAILABLE                          0x00050A9000
#define MP4_SUBTITLE_BUFFER_ADR                                0x00050A9000  //Alignment 0x01000
#define MP4_SUBTITLE_BUFFER_GAP_CHK                            0x0000000000
#define MP4_SUBTITLE_BUFFER_LEN                                0x0000080000
#define MP4_SUBTITLE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* MP4_SUBTITLE_BUFFER2   */
//co_buffer L9
#define MP4_SUBTITLE_BUFFER2_AVAILABLE                         0x0005129000
#define MP4_SUBTITLE_BUFFER2_ADR                               0x0005129000  //Alignment 0x01000
#define MP4_SUBTITLE_BUFFER2_GAP_CHK                           0x0000000000
#define MP4_SUBTITLE_BUFFER2_LEN                               0x0000080000
#define MP4_SUBTITLE_BUFFER2_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* MP4_SUBTITLE_TAG   */
//co_buffer L9
#define MP4_SUBTITLE_TAG_AVAILABLE                             0x00051A9000
#define MP4_SUBTITLE_TAG_ADR                                   0x00051A9000  //Alignment 0x01000
#define MP4_SUBTITLE_TAG_GAP_CHK                               0x0000000000
#define MP4_SUBTITLE_TAG_LEN                                   0x0000080000
#define MP4_SUBTITLE_TAG_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* CAPTURE_VIDEO_BUFFER   */
//co_buffer L9
#define CAPTURE_VIDEO_BUFFER_AVAILABLE                         0x0005229000
#define CAPTURE_VIDEO_BUFFER_ADR                               0x0005229000  //Alignment 0x00020
#define CAPTURE_VIDEO_BUFFER_GAP_CHK                           0x0000000000
#define CAPTURE_VIDEO_BUFFER_LEN                               0x0000180000
#define CAPTURE_VIDEO_BUFFER_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* CAPE_BUFFER   */
//co_buffer L10
#define CAPE_BUFFER_AVAILABLE                                  0x000418C860
#define CAPE_BUFFER_ADR                                        0x000418C860  //Alignment 0
#define CAPE_BUFFER_GAP_CHK                                    0x0000000000
#define CAPE_BUFFER_LEN                                        0x0000000000
#define CAPE_BUFFER_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* CAPE_JPG   */
//co_buffer L10
#define CAPE_JPG_AVAILABLE                                     0x000418C860
#define CAPE_JPG_ADR                                           0x000418C860  //Alignment 0
#define CAPE_JPG_GAP_CHK                                       0x0000000000
#define CAPE_JPG_LEN                                           0x0000D90CC0
#define CAPE_JPG_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* PVR_WRITE_SDRAM   */
//co_buffer L1
#define PVR_WRITE_SDRAM_AVAILABLE                              0x0004F90000
#define PVR_WRITE_SDRAM_ADR                                    0x0004F90000  //Alignment 0x01000
#define PVR_WRITE_SDRAM_GAP_CHK                                0x0000000000
#define PVR_WRITE_SDRAM_LEN                                    0x00001B0000
#define PVR_WRITE_SDRAM_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* PVR_WRITE_METADATA_BUFFER   */
//co_buffer L1
#define PVR_WRITE_METADATA_BUFFER_AVAILABLE                    0x0005140000
#define PVR_WRITE_METADATA_BUFFER_ADR                          0x0005140000  //Alignment 0x01000
#define PVR_WRITE_METADATA_BUFFER_GAP_CHK                      0x0000000000
#define PVR_WRITE_METADATA_BUFFER_LEN                          0x0000060000
#define PVR_WRITE_METADATA_BUFFER_MEMORY_TYPE                  (MIU0 | SW | WRITE_BACK)

/* PVR_READ_METADATA_BUFFER   */
//co_buffer L1
#define PVR_READ_METADATA_BUFFER_AVAILABLE                     0x00051A0000
#define PVR_READ_METADATA_BUFFER_ADR                           0x00051A0000  //Alignment 0x01000
#define PVR_READ_METADATA_BUFFER_GAP_CHK                       0x0000000000
#define PVR_READ_METADATA_BUFFER_LEN                           0x0000000C00
#define PVR_READ_METADATA_BUFFER_MEMORY_TYPE                   (MIU0 | SW | WRITE_BACK)

/* BULK_FILE_SYSTEM   */
//co_buffer L1
#define BULK_FILE_SYSTEM_AVAILABLE                             0x00051A0C00
#define BULK_FILE_SYSTEM_ADR                                   0x00051A1000  //Alignment 0x01000
#define BULK_FILE_SYSTEM_GAP_CHK                               0x0000000400
#define BULK_FILE_SYSTEM_LEN                                   0x0000006000
#define BULK_FILE_SYSTEM_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* PVR_BROWSER_BUFFER   */
//co_buffer L1
#define PVR_BROWSER_BUFFER_AVAILABLE                           0x00051A7000
#define PVR_BROWSER_BUFFER_ADR                                 0x00051A7000  //Alignment 0x01000
#define PVR_BROWSER_BUFFER_GAP_CHK                             0x0000000000
#define PVR_BROWSER_BUFFER_LEN                                 0x0000200000
#define PVR_BROWSER_BUFFER_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* SCHEDULE_LIST   */
//co_buffer L0
#define SCHEDULE_LIST_AVAILABLE                                0x00053B3460
#define SCHEDULE_LIST_ADR                                      0x00053B3460  //Alignment 0x00008
#define SCHEDULE_LIST_GAP_CHK                                  0x0000000000
#define SCHEDULE_LIST_LEN                                      0x0000001000
#define SCHEDULE_LIST_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* EIT_PF_STRING_BUF   */
//co_buffer L0
#define EIT_PF_STRING_BUF_AVAILABLE                            0x00053B4460
#define EIT_PF_STRING_BUF_ADR                                  0x00053B4460  //Alignment 0x00008
#define EIT_PF_STRING_BUF_GAP_CHK                              0x0000000000
#define EIT_PF_STRING_BUF_LEN                                  0x0000004000
#define EIT_PF_STRING_BUF_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* DEMOD_MEM   */
//co_buffer L0
#define DEMOD_MEM_AVAILABLE                                    0x00053B8460
#define DEMOD_MEM_ADR                                          0x00053B8460  //Alignment 0x00010
#define DEMOD_MEM_GAP_CHK                                      0x0000000000
#define DEMOD_MEM_LEN                                          0x0000008000
#define DEMOD_MEM_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* PM51_MEM   */
//co_buffer L0
#define PM51_MEM_AVAILABLE                                     0x00053C0460
#define PM51_MEM_ADR                                           0x00053D0000  //Alignment 0x10000
#define PM51_MEM_GAP_CHK                                       0x000000FBA0
#define PM51_MEM_LEN                                           0x0000005000
#define PM51_MEM_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* OADSEC_BUFFER   */
//co_buffer L0
#define OADSEC_BUFFER_AVAILABLE                                0x00053D5000
#define OADSEC_BUFFER_ADR                                      0x00053D5000  //Alignment 0x00010
#define OADSEC_BUFFER_GAP_CHK                                  0x0000000000
#define OADSEC_BUFFER_LEN                                      0x0000014000
#define OADSEC_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* DUMMY   */
//co_buffer L0
#define DUMMY_AVAILABLE                                        0x00053E9000
#define DUMMY_ADR                                              0x00053E9000  //Alignment 0x00008
#define DUMMY_GAP_CHK                                          0x0000000000
#define DUMMY_LEN                                              0x0000000008
#define DUMMY_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* DUMP_BUFFER   */
//co_buffer L0
#define DUMP_BUFFER_AVAILABLE                                  0x00053E9008
#define DUMP_BUFFER_ADR                                        0x0007FFE000  //Alignment 0x3FFF000
#define DUMP_BUFFER_GAP_CHK                                    0x0002C14FF8
#define DUMP_BUFFER_LEN                                        0x0000001000
#define DUMP_BUFFER_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* BMP_START   */
//co_buffer L0
#define BMP_START_AVAILABLE                                    0x0007FFF000
#define BMP_START_ADR                                          0x0007FFF000  //Alignment 0x00800
#define BMP_START_GAP_CHK                                      0x0000000000
#define BMP_START_LEN                                          0x00002A3000
#define BMP_START_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* STRING_START   */
//co_buffer L0
#define STRING_START_AVAILABLE                                 0x00082A2000
#define STRING_START_ADR                                       0x00082A2000  //Alignment 0x00800
#define STRING_START_GAP_CHK                                   0x0000000000
#define STRING_START_LEN                                       0x000004B000
#define STRING_START_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_SUB_BUF   */
//co_buffer L0
#define SCALER_DNR_SUB_BUF_AVAILABLE                           0x00082ED000
#define SCALER_DNR_SUB_BUF_ADR                                 0x00082ED000  //Alignment 0x00008
#define SCALER_DNR_SUB_BUF_GAP_CHK                             0x0000000000
#define SCALER_DNR_SUB_BUF_LEN                                 0x000060DD70
#define SCALER_DNR_SUB_BUF_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

//MIU_1_START
/* VDEC_AEON   */
//co_buffer L0
#define VDEC_AEON_AVAILABLE                                    0x0000000000
#define VDEC_AEON_ADR                                          0x0000000000  //Alignment 0x01000
#define VDEC_AEON_GAP_CHK                                      0x0000000000
#define VDEC_AEON_LEN                                          0x0000100000
#define VDEC_AEON_MEMORY_TYPE                                  (MIU1 | SW | WRITE_BACK)

/* VDEC_FRAMEBUFFER   */
//co_buffer L0
#define VDEC_FRAMEBUFFER_AVAILABLE                             0x0000100000
#define VDEC_FRAMEBUFFER_ADR                                   0x0000100000  //Alignment 0x00200
#define VDEC_FRAMEBUFFER_GAP_CHK                               0x0000000000
#define VDEC_FRAMEBUFFER_LEN                                   0x0001B00000
#define VDEC_FRAMEBUFFER_MEMORY_TYPE                           (MIU1 | SW | WRITE_BACK)

/* VDEC_BITSTREAM   */
//co_buffer L0
#define VDEC_BITSTREAM_AVAILABLE                               0x0001C00000
#define VDEC_BITSTREAM_ADR                                     0x0001C00000  //Alignment 0x00008
#define VDEC_BITSTREAM_GAP_CHK                                 0x0000000000
#define VDEC_BITSTREAM_LEN                                     0x0000400000
#define VDEC_BITSTREAM_MEMORY_TYPE                             (MIU1 | SW | WRITE_BACK)

/* MENULOAD_BUFFER Must the same MIU with VDEC_AEON */
//co_buffer L0
#define MENULOAD_BUFFER_AVAILABLE                              0x0002000000
#define MENULOAD_BUFFER_ADR                                    0x0002000000  //Alignment 0x00010
#define MENULOAD_BUFFER_GAP_CHK                                0x0000000000
#define MENULOAD_BUFFER_LEN                                    0x0000004000
#define MENULOAD_BUFFER_MEMORY_TYPE                            (MIU1 | SW | WRITE_BACK)

/* EVENTDB_SDRAM   */
//co_buffer L0
#define EVENTDB_SDRAM_AVAILABLE                                0x0002004000
#define EVENTDB_SDRAM_ADR                                      0x0002004000  //Alignment 0x00008
#define EVENTDB_SDRAM_GAP_CHK                                  0x0000000000
#define EVENTDB_SDRAM_LEN                                      0x0000840000
#define EVENTDB_SDRAM_MEMORY_TYPE                              (MIU1 | SW | WRITE_BACK)

/* EPGEXTDB_SDRAM   */
//co_buffer L0
#define EPGEXTDB_SDRAM_AVAILABLE                               0x0002844000
#define EPGEXTDB_SDRAM_ADR                                     0x0002844000  //Alignment 0x00008
#define EPGEXTDB_SDRAM_GAP_CHK                                 0x0000000000
#define EPGEXTDB_SDRAM_LEN                                     0x0000A00000
#define EPGEXTDB_SDRAM_MEMORY_TYPE                             (MIU1 | SW | WRITE_BACK)

/* CAPE_FB   */
//co_buffer L0
#define CAPE_FB_AVAILABLE                                      0x0003244000
#define CAPE_FB_ADR                                            0x0003244000  //Alignment 0x00010
#define CAPE_FB_GAP_CHK                                        0x0000000000
#define CAPE_FB_LEN                                            0x0000400000
#define CAPE_FB_MEMORY_TYPE                                    (MIU1 | SW | WRITE_BACK)

/* DUMMY1 Not Using Buffer */
//co_buffer L0
#define DUMMY1_AVAILABLE                                       0x0003644000
#define DUMMY1_ADR                                             0x0003644000  //Alignment 0x00008
#define DUMMY1_GAP_CHK                                         0x0000000000
#define DUMMY1_LEN                                             0x0000000008
#define DUMMY1_MEMORY_TYPE                                     (MIU1 | SW | WRITE_BACK)

/* FLUSH_MEM_TEMP_BUF For MIU1 flush memory temp buffer */
//co_buffer L0
#define FLUSH_MEM_TEMP_BUF_AVAILABLE                           0x0003644008
#define FLUSH_MEM_TEMP_BUF_ADR                                 0x0003FFF000  //Alignment 0x3FFF000
#define FLUSH_MEM_TEMP_BUF_GAP_CHK                             0x00009BAFF8
#define FLUSH_MEM_TEMP_BUF_LEN                                 0x0000001000
#define FLUSH_MEM_TEMP_BUF_MEMORY_TYPE                         (MIU1 | SW | WRITE_BACK)

//MIU_END
#define MIU0_END_ADR                                           0x00088FAD70
#define MIU1_END_ADR                                           0x0004000000

