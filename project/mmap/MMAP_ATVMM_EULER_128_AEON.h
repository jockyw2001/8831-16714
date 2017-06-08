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

#define SCA_TOOL_VERSION            "Chakra SCA V1.0.0 "

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
#define MIU_DRAM_LEN                0x0008000000
#define MIU_DRAM_LEN0               0x0008000000

#define ENABLE_MIU_1                0
#define MIU_INTERVAL                0x0000000000

#define MIU0_MMAP_BOUNDARY                0x0000000000
#define MIU1_MMAP_BOUNDARY                0x0000000000
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

#define CO_BUF_OFFSET               (6)
#define CO_BUF_L0                   (0x0000 << CO_BUF_OFFSET)
#define CO_BUF_L1                   (0x0001 << CO_BUF_OFFSET)
#define CO_BUF_L2                   (0x0002 << CO_BUF_OFFSET)
#define CO_BUF_L3                   (0x0003 << CO_BUF_OFFSET)
#define CO_BUF_L4                   (0x0004 << CO_BUF_OFFSET)
#define CO_BUF_L5                   (0x0005 << CO_BUF_OFFSET)
#define CO_BUF_L6                   (0x0006 << CO_BUF_OFFSET)
#define CO_BUF_L7                   (0x0007 << CO_BUF_OFFSET)
#define CO_BUF_L8                   (0x0008 << CO_BUF_OFFSET)
#define CO_BUF_L9                   (0x0009 << CO_BUF_OFFSET)
#define CO_BUF_L10                  (0x000A << CO_BUF_OFFSET)
#define CO_BUF_L11                  (0x000B << CO_BUF_OFFSET)
#define MIU0_LAYER_COUNT            (9)
#define MIU1_LAYER_COUNT            (0)

//MIU_0_START
/* AEON_MEM   */
//co_buffer L0
#define AEON_MEM_AVAILABLE                                     0x0000000000
#define AEON_MEM_ADR                                           0x0000000000  //Alignment 0
#define AEON_MEM_GAP_CHK                                       0x0000000000
#define AEON_MEM_LEN                                           0x0000400000
#define AEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* AEON_MM_MEM   */
//co_buffer L1
#define AEON_MM_MEM_AVAILABLE                                  0x0000000000
#define AEON_MM_MEM_ADR                                        0x0000000000  //Alignment 0
#define AEON_MM_MEM_GAP_CHK                                    0x0000000000
#define AEON_MM_MEM_LEN                                        0x0000200000
#define AEON_MM_MEM_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* BEON_MEM   */
//co_buffer L0
#define BEON_MEM_AVAILABLE                                     0x0000400000
#define BEON_MEM_ADR                                           0x0000400000  //Alignment 0x10000
#define BEON_MEM_GAP_CHK                                       0x0000000000
#define BEON_MEM_LEN                                           0x0000330000
#define BEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* SECBUF_START   */
//co_buffer L0
#define SECBUF_START_AVAILABLE                                 0x0000730000
#define SECBUF_START_ADR                                       0x0000730000  //Alignment 0x10000
#define SECBUF_START_GAP_CHK                                   0x0000000000
#define SECBUF_START_LEN                                       0x0000023000
#define SECBUF_START_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* USB_BUFFER_START   */
//co_buffer L0
#define USB_BUFFER_START_AVAILABLE                             0x0000753000
#define USB_BUFFER_START_ADR                                   0x0000753000  //Alignment 0x01000
#define USB_BUFFER_START_GAP_CHK                               0x0000000000
#define USB_BUFFER_START_LEN                                   0x0000001000
#define USB_BUFFER_START_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* USB_BUFFER2_START   */
//co_buffer L0
#define USB_BUFFER2_START_AVAILABLE                            0x0000754000
#define USB_BUFFER2_START_ADR                                  0x0000754000  //Alignment 0x01000
#define USB_BUFFER2_START_GAP_CHK                              0x0000000000
#define USB_BUFFER2_START_LEN                                  0x0000001000
#define USB_BUFFER2_START_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* FILE_OPERATION_INFO_BUFFER   */
//co_buffer L0
#define FILE_OPERATION_INFO_BUFFER_AVAILABLE                   0x0000755000
#define FILE_OPERATION_INFO_BUFFER_ADR                         0x0000755000  //Alignment 0x01000
#define FILE_OPERATION_INFO_BUFFER_GAP_CHK                     0x0000000000
#define FILE_OPERATION_INFO_BUFFER_LEN                         0x0000000C00
#define FILE_OPERATION_INFO_BUFFER_MEMORY_TYPE                 (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PATH_INFO_BUFFER   */
//co_buffer L0
#define PATH_INFO_BUFFER_AVAILABLE                             0x0000755C00
#define PATH_INFO_BUFFER_ADR                                   0x0000755C00  //Alignment 0
#define PATH_INFO_BUFFER_GAP_CHK                               0x0000000000
#define PATH_INFO_BUFFER_LEN                                   0x0000000400
#define PATH_INFO_BUFFER_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE   */
//co_buffer L0
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_AVAILABLE      0x0000756000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_ADR            0x0000758000  //Alignment 0x04000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_GAP_CHK        0x0000002000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_LEN            0x0000004000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_MEMORY_TYPE    (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* TSP_VQ_BUFFER   */
//co_buffer L0
#define TSP_VQ_BUFFER_AVAILABLE                                0x000075C000
#define TSP_VQ_BUFFER_ADR                                      0x000075C000  //Alignment 0x00004
#define TSP_VQ_BUFFER_GAP_CHK                                  0x0000000000
#define TSP_VQ_BUFFER_LEN                                      0x0000000C00
#define TSP_VQ_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PHOTO_SHARE_MEM   */
//co_buffer L0
#define PHOTO_SHARE_MEM_AVAILABLE                              0x000075CC00
#define PHOTO_SHARE_MEM_ADR                                    0x000075CC00  //Alignment 0x00004
#define PHOTO_SHARE_MEM_GAP_CHK                                0x0000000000
#define PHOTO_SHARE_MEM_LEN                                    0x0000000400
#define PHOTO_SHARE_MEM_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* FILE_SYSTEM_POOL   */
//co_buffer L0
#define FILE_SYSTEM_POOL_AVAILABLE                             0x000075D000
#define FILE_SYSTEM_POOL_ADR                                   0x000075D000  //Alignment 0x01000
#define FILE_SYSTEM_POOL_GAP_CHK                               0x0000000000
#define FILE_SYSTEM_POOL_LEN                                   0x0000060000
#define FILE_SYSTEM_POOL_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_BASE_BUFFER   */
//co_buffer L0
#define MAD_BASE_BUFFER_AVAILABLE                              0x00007BD000
#define MAD_BASE_BUFFER_ADR                                    0x00007BD000  //Alignment 0x01000
#define MAD_BASE_BUFFER_GAP_CHK                                0x0000000000
#define MAD_BASE_BUFFER_LEN                                    0x000029C000
#define MAD_BASE_BUFFER_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DATABASE_START   */
//co_buffer L0
#define DATABASE_START_AVAILABLE                               0x0000A59000
#define DATABASE_START_ADR                                     0x0000A59000  //Alignment 0x00008
#define DATABASE_START_GAP_CHK                                 0x0000000000
#define DATABASE_START_LEN                                     0x0000021000
#define DATABASE_START_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DATABASE_BK_START   */
//co_buffer L0
#define DATABASE_BK_START_AVAILABLE                            0x0000A7A000
#define DATABASE_BK_START_ADR                                  0x0000A7A000  //Alignment 0x00008
#define DATABASE_BK_START_GAP_CHK                              0x0000000000
#define DATABASE_BK_START_LEN                                  0x0000021000
#define DATABASE_BK_START_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* FONT_START   */
//co_buffer L0
#define FONT_START_AVAILABLE                                   0x0000A9B000
#define FONT_START_ADR                                         0x0000A9B000  //Alignment 0x00008
#define FONT_START_GAP_CHK                                     0x0000000000
#define FONT_START_LEN                                         0x000012C000
#define FONT_START_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* GE_FRAMEBUFFER   */
//co_buffer L0
#define GE_FRAMEBUFFER_AVAILABLE                               0x0000BC7000
#define GE_FRAMEBUFFER_ADR                                     0x0000BC7000  //Alignment 0x00008
#define GE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define GE_FRAMEBUFFER_LEN                                     0x0000A23000
#define GE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* CAPTURE_VIDEO_BUFFER   */
//co_buffer L2
#define CAPTURE_VIDEO_BUFFER_AVAILABLE                         0x0000BC7000
#define CAPTURE_VIDEO_BUFFER_ADR                               0x0000BC7000  //Alignment 0x00020
#define CAPTURE_VIDEO_BUFFER_GAP_CHK                           0x0000000000
#define CAPTURE_VIDEO_BUFFER_LEN                               0x0000180000
#define CAPTURE_VIDEO_BUFFER_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* GOP_GWIN_RB   */
//co_buffer L1
#define GOP_GWIN_RB_AVAILABLE                                  0x0000BC7000
#define GOP_GWIN_RB_ADR                                        0x0000BC7000  //Alignment 0x00008
#define GOP_GWIN_RB_GAP_CHK                                    0x0000000000
#define GOP_GWIN_RB_LEN                                        0x0000A23000
#define GOP_GWIN_RB_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* SCALER_DNR_BUF   */
//co_buffer L0
#define SCALER_DNR_BUF_AVAILABLE                               0x00015EA000
#define SCALER_DNR_BUF_ADR                                     0x00015EA000  //Alignment 0x00010
#define SCALER_DNR_BUF_GAP_CHK                                 0x0000000000
#define SCALER_DNR_BUF_LEN                                     0x0001200000
#define SCALER_DNR_BUF_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DOWNLOAD_BUFFER   */
//co_buffer L1
#define DOWNLOAD_BUFFER_AVAILABLE                              0x00015EA000
#define DOWNLOAD_BUFFER_ADR                                    0x00015EA000  //Alignment 0x01000
#define DOWNLOAD_BUFFER_GAP_CHK                                0x0000000000
#define DOWNLOAD_BUFFER_LEN                                    0x0000832000
#define DOWNLOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* POOL_BUFFER   */
//co_buffer L0
#define POOL_BUFFER_AVAILABLE                                  0x00027EA000
#define POOL_BUFFER_ADR                                        0x00027F0000  //Alignment 0x10000
#define POOL_BUFFER_GAP_CHK                                    0x0000006000
#define POOL_BUFFER_LEN                                        0x0001600000
#define POOL_BUFFER_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MHEG5_BUFFER   */
//co_buffer L1
#define MHEG5_BUFFER_AVAILABLE                                 0x00027F0000
#define MHEG5_BUFFER_ADR                                       0x00027F0000  //Alignment 0x00100
#define MHEG5_BUFFER_GAP_CHK                                   0x0000000000
#define MHEG5_BUFFER_LEN                                       0x0000880000
#define MHEG5_BUFFER_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MHEG5_JPEG   */
//co_buffer L1
#define MHEG5_JPEG_AVAILABLE                                   0x0003070000
#define MHEG5_JPEG_ADR                                         0x0003070000  //Alignment 0x00100
#define MHEG5_JPEG_GAP_CHK                                     0x0000000000
#define MHEG5_JPEG_LEN                                         0x0000500000
#define MHEG5_JPEG_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* NONE_0   */
//co_buffer L2
#define NONE_0_AVAILABLE                                       0x00027F0000
#define NONE_0_ADR                                             0x00027F0000  //Alignment 0x00008
#define NONE_0_GAP_CHK                                         0x0000000000
#define NONE_0_LEN                                             0x00003A0000
#define NONE_0_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_TRICK_MODE   */
//co_buffer L2
#define PVR_TRICK_MODE_AVAILABLE                               0x0002B90000
#define PVR_TRICK_MODE_ADR                                     0x0002B90000  //Alignment 0x01000
#define PVR_TRICK_MODE_GAP_CHK                                 0x0000000000
#define PVR_TRICK_MODE_LEN                                     0x0000300000
#define PVR_TRICK_MODE_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_READ_SDRAM   */
//co_buffer L2
#define PVR_READ_SDRAM_AVAILABLE                               0x0002E90000
#define PVR_READ_SDRAM_ADR                                     0x0002E90000  //Alignment 0
#define PVR_READ_SDRAM_GAP_CHK                                 0x0000000000
#define PVR_READ_SDRAM_LEN                                     0x00001B0000
#define PVR_READ_SDRAM_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_BROWSER_BUFFER   */
//co_buffer L2
#define PVR_BROWSER_BUFFER_AVAILABLE                           0x0003040000
#define PVR_BROWSER_BUFFER_ADR                                 0x0003040000  //Alignment 0x01000
#define PVR_BROWSER_BUFFER_GAP_CHK                             0x0000000000
#define PVR_BROWSER_BUFFER_LEN                                 0x0000200000
#define PVR_BROWSER_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_IO_BUFFER   */
//co_buffer L2
#define PVR_IO_BUFFER_AVAILABLE                                0x0003240000
#define PVR_IO_BUFFER_ADR                                      0x0003240000  //Alignment 0
#define PVR_IO_BUFFER_GAP_CHK                                  0x0000000000
#define PVR_IO_BUFFER_LEN                                      0x0000010000
#define PVR_IO_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* NAND_COPY_BUFFER   */
//co_buffer L2
#define NAND_COPY_BUFFER_AVAILABLE                             0x0003250000
#define NAND_COPY_BUFFER_ADR                                   0x0003250000  //Alignment 0x00008
#define NAND_COPY_BUFFER_GAP_CHK                               0x0000000000
#define NAND_COPY_BUFFER_LEN                                   0x0000001000
#define NAND_COPY_BUFFER_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* NONE6   */
//co_buffer L8
#define NONE6_AVAILABLE                                        0x00027F0000
#define NONE6_ADR                                              0x00027F0000  //Alignment 0x00008
#define NONE6_GAP_CHK                                          0x0000000000
#define NONE6_LEN                                              0x00003A0000
#define NONE6_MEMORY_TYPE                                      (MIU0 | SW | CO_BUF_L8 | WRITE_BACK)

/* COMB_3D_BUF   */
//co_buffer L8
#define COMB_3D_BUF_AVAILABLE                                  0x0002B90000
#define COMB_3D_BUF_ADR                                        0x0002B90000  //Alignment 0x00010
#define COMB_3D_BUF_GAP_CHK                                    0x0000000000
#define COMB_3D_BUF_LEN                                        0x0000700000
#define COMB_3D_BUF_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L8 | WRITE_BACK)

/* SUBTITLE   */
//co_buffer L4
#define SUBTITLE_AVAILABLE                                     0x00027F0000
#define SUBTITLE_ADR                                           0x00027F0000  //Alignment 0x10000
#define SUBTITLE_GAP_CHK                                       0x0000000000
#define SUBTITLE_LEN                                           0x00003A0000
#define SUBTITLE_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* DOWNLOAD_ZIPBUFFER   */
//co_buffer L4
#define DOWNLOAD_ZIPBUFFER_AVAILABLE                           0x0002B90000
#define DOWNLOAD_ZIPBUFFER_ADR                                 0x0002B90000  //Alignment 0
#define DOWNLOAD_ZIPBUFFER_GAP_CHK                             0x0000000000
#define DOWNLOAD_ZIPBUFFER_LEN                                 0x0000400000
#define DOWNLOAD_ZIPBUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* BIN_DESCOM_SRC_BUF   */
//co_buffer L4
#define BIN_DESCOM_SRC_BUF_AVAILABLE                           0x0002F90000
#define BIN_DESCOM_SRC_BUF_ADR                                 0x0002F90000  //Alignment 0
#define BIN_DESCOM_SRC_BUF_GAP_CHK                             0x0000000000
#define BIN_DESCOM_SRC_BUF_LEN                                 0x0000300000
#define BIN_DESCOM_SRC_BUF_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* BIN_DESCOM_TMP_BUF   */
//co_buffer L4
#define BIN_DESCOM_TMP_BUF_AVAILABLE                           0x0003290000
#define BIN_DESCOM_TMP_BUF_ADR                                 0x0003290000  //Alignment 0
#define BIN_DESCOM_TMP_BUF_GAP_CHK                             0x0000000000
#define BIN_DESCOM_TMP_BUF_LEN                                 0x0000300000
#define BIN_DESCOM_TMP_BUF_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* NONE2   */
//co_buffer L5
#define NONE2_AVAILABLE                                        0x00027F0000
#define NONE2_ADR                                              0x00027F0000  //Alignment 0x00008
#define NONE2_GAP_CHK                                          0x0000000000
#define NONE2_LEN                                              0x00003A0000
#define NONE2_MEMORY_TYPE                                      (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* MPEG2_FILE   */
//co_buffer L5
#define MPEG2_FILE_AVAILABLE                                   0x0002B90000
#define MPEG2_FILE_ADR                                         0x0002B90000  //Alignment 0x00200
#define MPEG2_FILE_GAP_CHK                                     0x0000000000
#define MPEG2_FILE_LEN                                         0x0000500000
#define MPEG2_FILE_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* MPEG2_SBTL_BUFFER   */
//co_buffer L5
#define MPEG2_SBTL_BUFFER_AVAILABLE                            0x0003090000
#define MPEG2_SBTL_BUFFER_ADR                                  0x0003090000  //Alignment 0
#define MPEG2_SBTL_BUFFER_GAP_CHK                              0x0000000000
#define MPEG2_SBTL_BUFFER_LEN                                  0x0000200000
#define MPEG2_SBTL_BUFFER_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* OD_BUFFER   */
//co_buffer L5
#define OD_BUFFER_AVAILABLE                                    0x0003290000
#define OD_BUFFER_ADR                                          0x0003290000  //Alignment 0x00010
#define OD_BUFFER_GAP_CHK                                      0x0000000000
#define OD_BUFFER_LEN                                          0x00003F6800
#define OD_BUFFER_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* OD_LSB_BUFFER   */
//co_buffer L5
#define OD_LSB_BUFFER_AVAILABLE                                0x0003686800
#define OD_LSB_BUFFER_ADR                                      0x0003686800  //Alignment 0x00010
#define OD_LSB_BUFFER_GAP_CHK                                  0x0000000000
#define OD_LSB_BUFFER_LEN                                      0x00001FC400
#define OD_LSB_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* NONE3   */
//co_buffer L6
#define NONE3_AVAILABLE                                        0x00027F0000
#define NONE3_ADR                                              0x00027F0000  //Alignment 0x00008
#define NONE3_GAP_CHK                                          0x0000000000
#define NONE3_LEN                                              0x00003A0000
#define NONE3_MEMORY_TYPE                                      (MIU0 | SW | CO_BUF_L6 | WRITE_BACK)

/* TEXT_FILE   */
//co_buffer L6
#define TEXT_FILE_AVAILABLE                                    0x0002B90000
#define TEXT_FILE_ADR                                          0x0002B90000  //Alignment 0x00200
#define TEXT_FILE_GAP_CHK                                      0x0000000000
#define TEXT_FILE_LEN                                          0x0000002000
#define TEXT_FILE_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L6 | WRITE_BACK)

/* NONE5   */
//co_buffer L7
#define NONE5_AVAILABLE                                        0x00027F0000
#define NONE5_ADR                                              0x00027F0000  //Alignment 0x00008
#define NONE5_GAP_CHK                                          0x0000000000
#define NONE5_LEN                                              0x00003A0000
#define NONE5_MEMORY_TYPE                                      (MIU0 | SW | CO_BUF_L7 | WRITE_BACK)

/* SW_STRING_BUFFER   */
//co_buffer L7
#define SW_STRING_BUFFER_AVAILABLE                             0x0002B90000
#define SW_STRING_BUFFER_ADR                                   0x0002B90000  //Alignment 0
#define SW_STRING_BUFFER_GAP_CHK                               0x0000000000
#define SW_STRING_BUFFER_LEN                                   0x0000080000
#define SW_STRING_BUFFER_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L7 | WRITE_BACK)

/* NONE   */
//co_buffer L7
#define NONE_AVAILABLE                                         0x0002C10000
#define NONE_ADR                                               0x0002C10000  //Alignment 0x00008
#define NONE_GAP_CHK                                           0x0000000000
#define NONE_LEN                                               0x000037C000
#define NONE_MEMORY_TYPE                                       (MIU0 | SW | CO_BUF_L7 | WRITE_BACK)

/* TEXT_DATA_READ   */
//co_buffer L7
#define TEXT_DATA_READ_AVAILABLE                               0x0002F8C000
#define TEXT_DATA_READ_ADR                                     0x0002F8C000  //Alignment 0x01000
#define TEXT_DATA_READ_GAP_CHK                                 0x0000000000
#define TEXT_DATA_READ_LEN                                     0x0000010000
#define TEXT_DATA_READ_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L7 | WRITE_BACK)

/* NONE1   */
//co_buffer L3
#define NONE1_AVAILABLE                                        0x00027F0000
#define NONE1_ADR                                              0x00027F0000  //Alignment 0x00008
#define NONE1_GAP_CHK                                          0x0000000000
#define NONE1_LEN                                              0x00003A0000
#define NONE1_MEMORY_TYPE                                      (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* VDPLAYER_SUBTITLE_BITSTREAM_BUFF   */
//co_buffer L3
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_AVAILABLE             0x0002B90000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR                   0x0002B90000  //Alignment 0x01000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_GAP_CHK               0x0000000000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_LEN                   0x0000200000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_MEMORY_TYPE           (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MP4_SUBTITLE_BUFFER   */
//co_buffer L3
#define MP4_SUBTITLE_BUFFER_AVAILABLE                          0x0002D90000
#define MP4_SUBTITLE_BUFFER_ADR                                0x0002D90000  //Alignment 0x01000
#define MP4_SUBTITLE_BUFFER_GAP_CHK                            0x0000000000
#define MP4_SUBTITLE_BUFFER_LEN                                0x0000080000
#define MP4_SUBTITLE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MP4_SUBTITLE_TAG   */
//co_buffer L3
#define MP4_SUBTITLE_TAG_AVAILABLE                             0x0002E10000
#define MP4_SUBTITLE_TAG_ADR                                   0x0002E10000  //Alignment 0x01000
#define MP4_SUBTITLE_TAG_GAP_CHK                               0x0000000000
#define MP4_SUBTITLE_TAG_LEN                                   0x0000080000
#define MP4_SUBTITLE_TAG_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* VDPLAYER_DATA   */
//co_buffer L3
#define VDPLAYER_DATA_AVAILABLE                                0x0002E90000
#define VDPLAYER_DATA_ADR                                      0x0002E90000  //Alignment 0x01000
#define VDPLAYER_DATA_GAP_CHK                                  0x0000000000
#define VDPLAYER_DATA_LEN                                      0x000036C000
#define VDPLAYER_DATA_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF   */
//co_buffer L3
#define VDPLAYER_BITSTREAM_BUFF_AVAILABLE                      0x00031FC000
#define VDPLAYER_BITSTREAM_BUFF_ADR                            0x00031FC000  //Alignment 0
#define VDPLAYER_BITSTREAM_BUFF_GAP_CHK                        0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_LEN                            0x0000400000
#define VDPLAYER_BITSTREAM_BUFF_MEMORY_TYPE                    (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF_EXT   */
//co_buffer L3
#define VDPLAYER_BITSTREAM_BUFF_EXT_AVAILABLE                  0x00035FC000
#define VDPLAYER_BITSTREAM_BUFF_EXT_ADR                        0x00035FC000  //Alignment 0
#define VDPLAYER_BITSTREAM_BUFF_EXT_GAP_CHK                    0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_EXT_LEN                        0x0000500000
#define VDPLAYER_BITSTREAM_BUFF_EXT_MEMORY_TYPE                (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_FILE_BUFFER   */
//co_buffer L3
#define MPLAYER_FILE_BUFFER_AVAILABLE                          0x0003AFC000
#define MPLAYER_FILE_BUFFER_ADR                                0x0003AFC000  //Alignment 0x01000
#define MPLAYER_FILE_BUFFER_GAP_CHK                            0x0000000000
#define MPLAYER_FILE_BUFFER_LEN                                0x0000100000
#define MPLAYER_FILE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_MUSIC_FILE_BUFFER   */
//co_buffer L3
#define MPLAYER_MUSIC_FILE_BUFFER_AVAILABLE                    0x0003BFC000
#define MPLAYER_MUSIC_FILE_BUFFER_ADR                          0x0003BFC000  //Alignment 0x01000
#define MPLAYER_MUSIC_FILE_BUFFER_GAP_CHK                      0x0000000000
#define MPLAYER_MUSIC_FILE_BUFFER_LEN                          0x0000080000
#define MPLAYER_MUSIC_FILE_BUFFER_MEMORY_TYPE                  (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_PHOTO_PLAYLIST   */
//co_buffer L3
#define MPLAYER_PHOTO_PLAYLIST_AVAILABLE                       0x0003C7C000
#define MPLAYER_PHOTO_PLAYLIST_ADR                             0x0003C7C000  //Alignment 0x01000
#define MPLAYER_PHOTO_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_PHOTO_PLAYLIST_LEN                             0x0000014000
#define MPLAYER_PHOTO_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_MUSIC_PLAYLIST   */
//co_buffer L3
#define MPLAYER_MUSIC_PLAYLIST_AVAILABLE                       0x0003C90000
#define MPLAYER_MUSIC_PLAYLIST_ADR                             0x0003C90000  //Alignment 0x01000
#define MPLAYER_MUSIC_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MUSIC_PLAYLIST_LEN                             0x0000014000
#define MPLAYER_MUSIC_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_MOVIE_PLAYLIST   */
//co_buffer L3
#define MPLAYER_MOVIE_PLAYLIST_AVAILABLE                       0x0003CA4000
#define MPLAYER_MOVIE_PLAYLIST_ADR                             0x0003CA4000  //Alignment 0x01000
#define MPLAYER_MOVIE_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MOVIE_PLAYLIST_LEN                             0x0000014000
#define MPLAYER_MOVIE_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_TEXT_PLAYLIST   */
//co_buffer L3
#define MPLAYER_TEXT_PLAYLIST_AVAILABLE                        0x0003CB8000
#define MPLAYER_TEXT_PLAYLIST_ADR                              0x0003CB8000  //Alignment 0x01000
#define MPLAYER_TEXT_PLAYLIST_GAP_CHK                          0x0000000000
#define MPLAYER_TEXT_PLAYLIST_LEN                              0x0000014000
#define MPLAYER_TEXT_PLAYLIST_MEMORY_TYPE                      (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_EMU_PLAYLIST   */
//co_buffer L3
#define MPLAYER_EMU_PLAYLIST_AVAILABLE                         0x0003CCC000
#define MPLAYER_EMU_PLAYLIST_ADR                               0x0003CCC000  //Alignment 0x01000
#define MPLAYER_EMU_PLAYLIST_GAP_CHK                           0x0000000000
#define MPLAYER_EMU_PLAYLIST_LEN                               0x0000014000
#define MPLAYER_EMU_PLAYLIST_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MUSIC_LYRIC_BUFFER   */
//co_buffer L3
#define MUSIC_LYRIC_BUFFER_AVAILABLE                           0x0003CE0000
#define MUSIC_LYRIC_BUFFER_ADR                                 0x0003CE0000  //Alignment 0x01000
#define MUSIC_LYRIC_BUFFER_GAP_CHK                             0x0000000000
#define MUSIC_LYRIC_BUFFER_LEN                                 0x0000010000
#define MUSIC_LYRIC_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MUSIC_LYRIC_TAG   */
//co_buffer L3
#define MUSIC_LYRIC_TAG_AVAILABLE                              0x0003CF0000
#define MUSIC_LYRIC_TAG_ADR                                    0x0003CF0000  //Alignment 0x01000
#define MUSIC_LYRIC_TAG_GAP_CHK                                0x0000000000
#define MUSIC_LYRIC_TAG_LEN                                    0x0000001000
#define MUSIC_LYRIC_TAG_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MP3_INFO_READ   */
//co_buffer L3
#define MP3_INFO_READ_AVAILABLE                                0x0003CF1000
#define MP3_INFO_READ_ADR                                      0x0003CF1000  //Alignment 0x01000
#define MP3_INFO_READ_GAP_CHK                                  0x0000000000
#define MP3_INFO_READ_LEN                                      0x0000001000
#define MP3_INFO_READ_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* M4A_BUFFER   */
//co_buffer L3
#define M4A_BUFFER_AVAILABLE                                   0x0003CF2000
#define M4A_BUFFER_ADR                                         0x0003CF2000  //Alignment 0x01000
#define M4A_BUFFER_GAP_CHK                                     0x0000000000
#define M4A_BUFFER_LEN                                         0x0000004000
#define M4A_BUFFER_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* M4A_STCO   */
//co_buffer L3
#define M4A_STCO_AVAILABLE                                     0x0003CF6000
#define M4A_STCO_ADR                                           0x0003CF6000  //Alignment 0x01000
#define M4A_STCO_GAP_CHK                                       0x0000000000
#define M4A_STCO_LEN                                           0x0000018000
#define M4A_STCO_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* PVR_WRITE_SDRAM   */
//co_buffer L2
#define PVR_WRITE_SDRAM_AVAILABLE                              0x0003251000
#define PVR_WRITE_SDRAM_ADR                                    0x0003251000  //Alignment 0x01000
#define PVR_WRITE_SDRAM_GAP_CHK                                0x0000000000
#define PVR_WRITE_SDRAM_LEN                                    0x0000360000
#define PVR_WRITE_SDRAM_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_WRITE_METADATA_BUFFER   */
//co_buffer L2
#define PVR_WRITE_METADATA_BUFFER_AVAILABLE                    0x00035B1000
#define PVR_WRITE_METADATA_BUFFER_ADR                          0x00035B1000  //Alignment 0x01000
#define PVR_WRITE_METADATA_BUFFER_GAP_CHK                      0x0000000000
#define PVR_WRITE_METADATA_BUFFER_LEN                          0x0000060000
#define PVR_WRITE_METADATA_BUFFER_MEMORY_TYPE                  (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_READ_METADATA_BUFFER   */
//co_buffer L2
#define PVR_READ_METADATA_BUFFER_AVAILABLE                     0x0003611000
#define PVR_READ_METADATA_BUFFER_ADR                           0x0003611000  //Alignment 0x01000
#define PVR_READ_METADATA_BUFFER_GAP_CHK                       0x0000000000
#define PVR_READ_METADATA_BUFFER_LEN                           0x0000000C00
#define PVR_READ_METADATA_BUFFER_MEMORY_TYPE                   (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* BULK_FILE_SYSTEM   */
//co_buffer L2
#define BULK_FILE_SYSTEM_AVAILABLE                             0x0003611C00
#define BULK_FILE_SYSTEM_ADR                                   0x0003612000  //Alignment 0x01000
#define BULK_FILE_SYSTEM_GAP_CHK                               0x0000000400
#define BULK_FILE_SYSTEM_LEN                                   0x0000006000
#define BULK_FILE_SYSTEM_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* SI_MONITOR_DB   */
//co_buffer L2
#define SI_MONITOR_DB_AVAILABLE                                0x0003618000
#define SI_MONITOR_DB_ADR                                      0x0003618000  //Alignment 0x00008
#define SI_MONITOR_DB_GAP_CHK                                  0x0000000000
#define SI_MONITOR_DB_LEN                                      0x000000E000
#define SI_MONITOR_DB_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* SRV_NAME_BUF   */
//co_buffer L2
#define SRV_NAME_BUF_AVAILABLE                                 0x0003626000
#define SRV_NAME_BUF_ADR                                       0x0003626000  //Alignment 0x01000
#define SRV_NAME_BUF_GAP_CHK                                   0x0000000000
#define SRV_NAME_BUF_LEN                                       0x0000002000
#define SRV_NAME_BUF_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* MMI_TEXTSTRING   */
//co_buffer L2
#define MMI_TEXTSTRING_AVAILABLE                               0x0003628000
#define MMI_TEXTSTRING_ADR                                     0x0003628000  //Alignment 0x01000
#define MMI_TEXTSTRING_GAP_CHK                                 0x0000000000
#define MMI_TEXTSTRING_LEN                                     0x0000001000
#define MMI_TEXTSTRING_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* CI_PMT_BUFFER   */
//co_buffer L2
#define CI_PMT_BUFFER_AVAILABLE                                0x0003629000
#define CI_PMT_BUFFER_ADR                                      0x0003629000  //Alignment 0
#define CI_PMT_BUFFER_GAP_CHK                                  0x0000000000
#define CI_PMT_BUFFER_LEN                                      0x0000001000
#define CI_PMT_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* DEMOD_MEM   */
//co_buffer L2
#define DEMOD_MEM_AVAILABLE                                    0x000362A000
#define DEMOD_MEM_ADR                                          0x000362A000  //Alignment 0x00010
#define DEMOD_MEM_GAP_CHK                                      0x0000000000
#define DEMOD_MEM_LEN                                          0x0000008000
#define DEMOD_MEM_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* EIT_PF_STRING_BUF   */
//co_buffer L2
#define EIT_PF_STRING_BUF_AVAILABLE                            0x0003632000
#define EIT_PF_STRING_BUF_ADR                                  0x0003632000  //Alignment 0x00008
#define EIT_PF_STRING_BUF_GAP_CHK                              0x0000000000
#define EIT_PF_STRING_BUF_LEN                                  0x0000004000
#define EIT_PF_STRING_BUF_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* TTXBUF_START   */
//co_buffer L2
#define TTXBUF_START_AVAILABLE                                 0x0003636000
#define TTXBUF_START_ADR                                       0x0003636000  //Alignment 0x00008
#define TTXBUF_START_GAP_CHK                                   0x0000000000
#define TTXBUF_START_LEN                                       0x0000240000
#define TTXBUF_START_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* VE_FRAMEBUFFER   */
//co_buffer L2
#define VE_FRAMEBUFFER_AVAILABLE                               0x0003876000
#define VE_FRAMEBUFFER_ADR                                     0x0003876000  //Alignment 0x00008
#define VE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define VE_FRAMEBUFFER_LEN                                     0x0000195400
#define VE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* SCHEDULE_LIST   */
//co_buffer L0
#define SCHEDULE_LIST_AVAILABLE                                0x0003DF0000
#define SCHEDULE_LIST_ADR                                      0x0003DF0000  //Alignment 0x00010
#define SCHEDULE_LIST_GAP_CHK                                  0x0000000000
#define SCHEDULE_LIST_LEN                                      0x0000001000
#define SCHEDULE_LIST_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* STRING_START Not Using Buffer */
//co_buffer L0
#define STRING_START_AVAILABLE                                 0x0003DF1000
#define STRING_START_ADR                                       0x0003DF1000  //Alignment 0x00800
#define STRING_START_GAP_CHK                                   0x0000000000
#define STRING_START_LEN                                       0x000005C000
#define STRING_START_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PM51_MEM   */
//co_buffer L0
#define PM51_MEM_AVAILABLE                                     0x0003E4D000
#define PM51_MEM_ADR                                           0x0003E50000  //Alignment 0x10000
#define PM51_MEM_GAP_CHK                                       0x0000003000
#define PM51_MEM_LEN                                           0x0000005000
#define PM51_MEM_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* OADSEC_BUFFER   */
//co_buffer L0
#define OADSEC_BUFFER_AVAILABLE                                0x0003E55000
#define OADSEC_BUFFER_ADR                                      0x0003E55000  //Alignment 0x00010
#define OADSEC_BUFFER_GAP_CHK                                  0x0000000000
#define OADSEC_BUFFER_LEN                                      0x0000014000
#define OADSEC_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DUMP_BUFFER   */
//co_buffer L0
#define DUMP_BUFFER_AVAILABLE                                  0x0003E69000
#define DUMP_BUFFER_ADR                                        0x0003E69000  //Alignment 0x00010
#define DUMP_BUFFER_GAP_CHK                                    0x0000000000
#define DUMP_BUFFER_LEN                                        0x0000001000
#define DUMP_BUFFER_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* VDEC_AEON   */
//co_buffer L0
#define VDEC_AEON_AVAILABLE                                    0x0003E6A000
#define VDEC_AEON_ADR                                          0x0003E6A000  //Alignment 0x01000
#define VDEC_AEON_GAP_CHK                                      0x0000000000
#define VDEC_AEON_LEN                                          0x0000100000
#define VDEC_AEON_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* BMP_START   */
//co_buffer L0
#define BMP_START_AVAILABLE                                    0x0003F6A000
#define BMP_START_ADR                                          0x0003F6A000  //Alignment 0x00800
#define BMP_START_GAP_CHK                                      0x0000000000
#define BMP_START_LEN                                          0x0000280000
#define BMP_START_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DUMMY   */
//co_buffer L0
#define DUMMY_AVAILABLE                                        0x00041EA000
#define DUMMY_ADR                                              0x00041EA000  //Alignment 0
#define DUMMY_GAP_CHK                                          0x0000000000
#define DUMMY_LEN                                              0x0000000000
#define DUMMY_MEMORY_TYPE                                      (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* VDEC_FRAMEBUFFER   */
//co_buffer L0
#define VDEC_FRAMEBUFFER_AVAILABLE                             0x00041EA000
#define VDEC_FRAMEBUFFER_ADR                                   0x00041EA000  //Alignment 0x00200
#define VDEC_FRAMEBUFFER_GAP_CHK                               0x0000000000
#define VDEC_FRAMEBUFFER_LEN                                   0x0001B00000
#define VDEC_FRAMEBUFFER_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_JPEG_OUT   */
//co_buffer L1
#define MAD_JPEG_OUT_AVAILABLE                                 0x00041EA000
#define MAD_JPEG_OUT_ADR                                       0x00041EA000  //Alignment 0x00008
#define MAD_JPEG_OUT_GAP_CHK                                   0x0000000000
#define MAD_JPEG_OUT_LEN                                       0x0000809000
#define MAD_JPEG_OUT_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MAD_JPEG_READBUFF   */
//co_buffer L1
#define MAD_JPEG_READBUFF_AVAILABLE                            0x00049F3000
#define MAD_JPEG_READBUFF_ADR                                  0x00049F3000  //Alignment 0x01000
#define MAD_JPEG_READBUFF_GAP_CHK                              0x0000000000
#define MAD_JPEG_READBUFF_LEN                                  0x0000050080
#define MAD_JPEG_READBUFF_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MAD_JPEG_INTERBUFF   */
//co_buffer L1
#define MAD_JPEG_INTERBUFF_AVAILABLE                           0x0004A43080
#define MAD_JPEG_INTERBUFF_ADR                                 0x0004A50000  //Alignment 0x10000
#define MAD_JPEG_INTERBUFF_GAP_CHK                             0x000000CF80
#define MAD_JPEG_INTERBUFF_LEN                                 0x0000650000
#define MAD_JPEG_INTERBUFF_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MAD_JPEG_DISPLAY   */
//co_buffer L1
#define MAD_JPEG_DISPLAY_AVAILABLE                             0x00050A0000
#define MAD_JPEG_DISPLAY_ADR                                   0x00050A0000  //Alignment 0
#define MAD_JPEG_DISPLAY_GAP_CHK                               0x0000000000
#define MAD_JPEG_DISPLAY_LEN                                   0x0000400000
#define MAD_JPEG_DISPLAY_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDEC_BITSTREAM Must the same MIU with VDEC_AEON */
//co_buffer L0
#define VDEC_BITSTREAM_AVAILABLE                               0x0005CEA000
#define VDEC_BITSTREAM_ADR                                     0x0005CEA000  //Alignment 0x00008
#define VDEC_BITSTREAM_GAP_CHK                                 0x0000000000
#define VDEC_BITSTREAM_LEN                                     0x0000400000
#define VDEC_BITSTREAM_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MENULOAD_BUFFER Must the same MIU with VDEC_AEON */
//co_buffer L0
#define MENULOAD_BUFFER_AVAILABLE                              0x00060EA000
#define MENULOAD_BUFFER_ADR                                    0x00060EA000  //Alignment 0x00010
#define MENULOAD_BUFFER_GAP_CHK                                0x0000000000
#define MENULOAD_BUFFER_LEN                                    0x0000004000
#define MENULOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* EVENTDB_SDRAM   */
//co_buffer L0
#define EVENTDB_SDRAM_AVAILABLE                                0x00060EE000
#define EVENTDB_SDRAM_ADR                                      0x00060EE000  //Alignment 0x00008
#define EVENTDB_SDRAM_GAP_CHK                                  0x0000000000
#define EVENTDB_SDRAM_LEN                                      0x0000840000
#define EVENTDB_SDRAM_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* EPGEXTDB_SDRAM   */
//co_buffer L0
#define EPGEXTDB_SDRAM_AVAILABLE                               0x000692E000
#define EPGEXTDB_SDRAM_ADR                                     0x000692E000  //Alignment 0x00008
#define EPGEXTDB_SDRAM_GAP_CHK                                 0x0000000000
#define EPGEXTDB_SDRAM_LEN                                     0x0000A00000
#define EPGEXTDB_SDRAM_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MPO_DISPLAY_BUFFER   */
//co_buffer L1
#define MPO_DISPLAY_BUFFER_AVAILABLE                           0x000692E000
#define MPO_DISPLAY_BUFFER_ADR                                 0x000692E000  //Alignment 0
#define MPO_DISPLAY_BUFFER_GAP_CHK                             0x0000000000
#define MPO_DISPLAY_BUFFER_LEN                                 0x0000900000
#define MPO_DISPLAY_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* GOP_GWIN_RB2_TEST   */
//co_buffer L0
#define GOP_GWIN_RB2_TEST_AVAILABLE                            0x000732E000
#define GOP_GWIN_RB2_TEST_ADR                                  0x000732E000  //Alignment 0x00008
#define GOP_GWIN_RB2_TEST_GAP_CHK                              0x0000000000
#define GOP_GWIN_RB2_TEST_LEN                                  0x0000000000
#define GOP_GWIN_RB2_TEST_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* GOP_REGDMABASE   */
//co_buffer L0
#define GOP_REGDMABASE_AVAILABLE                               0x000732E000
#define GOP_REGDMABASE_ADR                                     0x000732E000  //Alignment 0x02000
#define GOP_REGDMABASE_GAP_CHK                                 0x0000000000
#define GOP_REGDMABASE_LEN                                     0x0000001000
#define GOP_REGDMABASE_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* SCALER_2DTO3D_DD_BUF Not Using Buffer */
//co_buffer L0
#define SCALER_2DTO3D_DD_BUF_AVAILABLE                         0x000732F000
#define SCALER_2DTO3D_DD_BUF_ADR                               0x000732F000  //Alignment 0x00008
#define SCALER_2DTO3D_DD_BUF_GAP_CHK                           0x0000000000
#define SCALER_2DTO3D_DD_BUF_LEN                               0x0000100000
#define SCALER_2DTO3D_DD_BUF_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* CIPLUST_KEY_BUFFER   */
//co_buffer L1
#define CIPLUST_KEY_BUFFER_AVAILABLE                           0x000732F000
#define CIPLUST_KEY_BUFFER_ADR                                 0x000732F000  //Alignment 0x00008
#define CIPLUST_KEY_BUFFER_GAP_CHK                             0x0000000000
#define CIPLUST_KEY_BUFFER_LEN                                 0x0000002800
#define CIPLUST_KEY_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* SCALER_2DTO3D_DR_BUF Not Using Buffer */
//co_buffer L0
#define SCALER_2DTO3D_DR_BUF_AVAILABLE                         0x000742F000
#define SCALER_2DTO3D_DR_BUF_ADR                               0x000742F000  //Alignment 0x00008
#define SCALER_2DTO3D_DR_BUF_GAP_CHK                           0x0000000000
#define SCALER_2DTO3D_DR_BUF_LEN                               0x0000100000
#define SCALER_2DTO3D_DR_BUF_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* HDCP_KEY_BUF Not Using Buffer */
//co_buffer L1
#define HDCP_KEY_BUF_AVAILABLE                                 0x000742F000
#define HDCP_KEY_BUF_ADR                                       0x000742F000  //Alignment 0x00008
#define HDCP_KEY_BUF_GAP_CHK                                   0x0000000000
#define HDCP_KEY_BUF_LEN                                       0x0000100000
#define HDCP_KEY_BUF_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* OPCACHE_BUF Not Using Buffer */
//co_buffer L0
#define OPCACHE_BUF_AVAILABLE                                  0x000752F000
#define OPCACHE_BUF_ADR                                        0x000752F000  //Alignment 0x00100
#define OPCACHE_BUF_GAP_CHK                                    0x0000000000
#define OPCACHE_BUF_LEN                                        0x0000010000
#define OPCACHE_BUF_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DUMMY1 Not Using Buffer */
//co_buffer L0
#define DUMMY1_AVAILABLE                                       0x000753F000
#define DUMMY1_ADR                                             0x000753F000  //Alignment 0x00100
#define DUMMY1_GAP_CHK                                         0x0000000000
#define DUMMY1_LEN                                             0x0000001000
#define DUMMY1_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

//MIU_1_START
//MIU_END
#define MIU0_END_ADR                                           0x0007540000
