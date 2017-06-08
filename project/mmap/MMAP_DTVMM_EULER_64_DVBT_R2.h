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
#define MIU_DRAM_LEN                0x0004000000
#define MIU_DRAM_LEN0               0x0004000000

#define ENABLE_MIU_1                0
#define MIU_INTERVAL                0x0000000000

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
#define AEON_MEM_LEN                                           0x0000200000
#define AEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* AEON_MM_MEM   */
//co_buffer L1
#define AEON_MM_MEM_AVAILABLE                                  0x0000000000
#define AEON_MM_MEM_ADR                                        0x0000000000  //Alignment 0x00008
#define AEON_MM_MEM_GAP_CHK                                    0x0000000000
#define AEON_MM_MEM_LEN                                        0x0000200000
#define AEON_MM_MEM_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* BEON_MEM   */
//co_buffer L0
#define BEON_MEM_AVAILABLE                                     0x0000200000
#define BEON_MEM_ADR                                           0x0000200000  //Alignment 0x10000
#define BEON_MEM_GAP_CHK                                       0x0000000000
#define BEON_MEM_LEN                                           0x0000400000
#define BEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* SECBUF_START   */
//co_buffer L0
#define SECBUF_START_AVAILABLE                                 0x0000600000
#define SECBUF_START_ADR                                       0x0000600000  //Alignment 0x10000
#define SECBUF_START_GAP_CHK                                   0x0000000000
#define SECBUF_START_LEN                                       0x0000023000
#define SECBUF_START_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* SCHEDULE_LIST   */
//co_buffer L0
#define SCHEDULE_LIST_AVAILABLE                                0x0000623000
#define SCHEDULE_LIST_ADR                                      0x0000623000  //Alignment 0x00010
#define SCHEDULE_LIST_GAP_CHK                                  0x0000000000
#define SCHEDULE_LIST_LEN                                      0x0000001000
#define SCHEDULE_LIST_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* USB_BUFFER_START   */
//co_buffer L0
#define USB_BUFFER_START_AVAILABLE                             0x0000624000
#define USB_BUFFER_START_ADR                                   0x0000624000  //Alignment 0x01000
#define USB_BUFFER_START_GAP_CHK                               0x0000000000
#define USB_BUFFER_START_LEN                                   0x0000001000
#define USB_BUFFER_START_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* USB_BUFFER2_START   */
//co_buffer L0
#define USB_BUFFER2_START_AVAILABLE                            0x0000625000
#define USB_BUFFER2_START_ADR                                  0x0000625000  //Alignment 0x01000
#define USB_BUFFER2_START_GAP_CHK                              0x0000000000
#define USB_BUFFER2_START_LEN                                  0x0000001000
#define USB_BUFFER2_START_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* TSP_VQ_BUFFER   */
//co_buffer L0
#define TSP_VQ_BUFFER_AVAILABLE                                0x0000626000
#define TSP_VQ_BUFFER_ADR                                      0x0000626000  //Alignment 0x00010
#define TSP_VQ_BUFFER_GAP_CHK                                  0x0000000000
#define TSP_VQ_BUFFER_LEN                                      0x0000001000
#define TSP_VQ_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE   */
//co_buffer L0
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_AVAILABLE      0x0000627000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_ADR            0x0000627000  //Alignment 0x01000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_GAP_CHK        0x0000000000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_LEN            0x0000001000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_MEMORY_TYPE    (MIU0 | SW | WRITE_BACK)

/* FILE_SYSTEM_POOL   */
//co_buffer L0
#define FILE_SYSTEM_POOL_AVAILABLE                             0x0000628000
#define FILE_SYSTEM_POOL_ADR                                   0x0000628000  //Alignment 0x01000
#define FILE_SYSTEM_POOL_GAP_CHK                               0x0000000000
#define FILE_SYSTEM_POOL_LEN                                   0x0000060000
#define FILE_SYSTEM_POOL_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* MAD_BASE_BUFFER   */
//co_buffer L0
#define MAD_BASE_BUFFER_AVAILABLE                              0x0000688000
#define MAD_BASE_BUFFER_ADR                                    0x0000688000  //Alignment 0x01000
#define MAD_BASE_BUFFER_GAP_CHK                                0x0000000000
#define MAD_BASE_BUFFER_LEN                                    0x0000180000
#define MAD_BASE_BUFFER_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* GE_FRAMEBUFFER   */
//co_buffer L0
#define GE_FRAMEBUFFER_AVAILABLE                               0x0000808000
#define GE_FRAMEBUFFER_ADR                                     0x0000808000  //Alignment 0x00020
#define GE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define GE_FRAMEBUFFER_LEN                                     0x0000460000
#define GE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* GOP_GWIN_RB   */
//co_buffer L1
#define GOP_GWIN_RB_AVAILABLE                                  0x0000808000
#define GOP_GWIN_RB_ADR                                        0x0000808000  //Alignment 0x00020
#define GOP_GWIN_RB_GAP_CHK                                    0x0000000000
#define GOP_GWIN_RB_LEN                                        0x0000460000
#define GOP_GWIN_RB_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* CAPTURE_VIDEO_BUFFER   */
//co_buffer L2
#define CAPTURE_VIDEO_BUFFER_AVAILABLE                         0x0000808000
#define CAPTURE_VIDEO_BUFFER_ADR                               0x0000808000  //Alignment 0x00020
#define CAPTURE_VIDEO_BUFFER_GAP_CHK                           0x0000000000
#define CAPTURE_VIDEO_BUFFER_LEN                               0x0000180000
#define CAPTURE_VIDEO_BUFFER_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* GOP_REGDMABASE   */
//co_buffer L0
#define GOP_REGDMABASE_AVAILABLE                               0x0000C68000
#define GOP_REGDMABASE_ADR                                     0x0000C68000  //Alignment 0x00020
#define GOP_REGDMABASE_GAP_CHK                                 0x0000000000
#define GOP_REGDMABASE_LEN                                     0x0000001000
#define GOP_REGDMABASE_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* DATABASE_START   */
//co_buffer L0
#define DATABASE_START_AVAILABLE                               0x0000C69000
#define DATABASE_START_ADR                                     0x0000C69000  //Alignment 0x00020
#define DATABASE_START_GAP_CHK                                 0x0000000000
#define DATABASE_START_LEN                                     0x0000011000
#define DATABASE_START_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* BMP_START   */
//co_buffer L0
#define BMP_START_AVAILABLE                                    0x0000C7A000
#define BMP_START_ADR                                          0x0000C7A000  //Alignment 0x00020
#define BMP_START_GAP_CHK                                      0x0000000000
#define BMP_START_LEN                                          0x0000200000
#define BMP_START_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* STRING_START   */
//co_buffer L0
#define STRING_START_AVAILABLE                                 0x0000E7A000
#define STRING_START_ADR                                       0x0000E7A000  //Alignment 0x00020
#define STRING_START_GAP_CHK                                   0x0000000000
#define STRING_START_LEN                                       0x000005C000
#define STRING_START_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* FONT_START   */
//co_buffer L0
#define FONT_START_AVAILABLE                                   0x0000ED6000
#define FONT_START_ADR                                         0x0000ED6000  //Alignment 0x00008
#define FONT_START_GAP_CHK                                     0x0000000000
#define FONT_START_LEN                                         0x00000E1000
#define FONT_START_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* MENULOAD_BUFFER   */
//co_buffer L0
#define MENULOAD_BUFFER_AVAILABLE                              0x0000FB7000
#define MENULOAD_BUFFER_ADR                                    0x0000FB7000  //Alignment 0x00008
#define MENULOAD_BUFFER_GAP_CHK                                0x0000000000
#define MENULOAD_BUFFER_LEN                                    0x0000004000
#define MENULOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* PQ_MAIN   */
//co_buffer L0
#define PQ_MAIN_AVAILABLE                                      0x0000FBB000
#define PQ_MAIN_ADR                                            0x0000FBB000  //Alignment 0x00008
#define PQ_MAIN_GAP_CHK                                        0x0000000000
#define PQ_MAIN_LEN                                            0x0000000000
#define PQ_MAIN_MEMORY_TYPE                                    (MIU0 | SW | WRITE_BACK)

/* PQ_MAIN_EX   */
//co_buffer L0
#define PQ_MAIN_EX_AVAILABLE                                   0x0000FBB000
#define PQ_MAIN_EX_ADR                                         0x0000FBB000  //Alignment 0x00008
#define PQ_MAIN_EX_GAP_CHK                                     0x0000000000
#define PQ_MAIN_EX_LEN                                         0x0000000000
#define PQ_MAIN_EX_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* PQ_TEXT_MAIN   */
//co_buffer L0
#define PQ_TEXT_MAIN_AVAILABLE                                 0x0000FBB000
#define PQ_TEXT_MAIN_ADR                                       0x0000FBB000  //Alignment 0x00008
#define PQ_TEXT_MAIN_GAP_CHK                                   0x0000000000
#define PQ_TEXT_MAIN_LEN                                       0x0000000000
#define PQ_TEXT_MAIN_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* POOL_BUFFER   */
//co_buffer L0
#define POOL_BUFFER_AVAILABLE                                  0x0000FBB000
#define POOL_BUFFER_ADR                                        0x0000FBB000  //Alignment 0x00020
#define POOL_BUFFER_GAP_CHK                                    0x0000000000
#define POOL_BUFFER_LEN                                        0x000303E000
#define POOL_BUFFER_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* NONE9   */
//co_buffer L3
#define NONE9_AVAILABLE                                        0x0000FBB000
#define NONE9_ADR                                              0x0000FBB000  //Alignment 0x00200
#define NONE9_GAP_CHK                                          0x0000000000
#define NONE9_LEN                                              0x0000100000
#define NONE9_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* NONE10   */
//co_buffer L3
#define NONE10_AVAILABLE                                       0x00010BB000
#define NONE10_ADR                                             0x00010BB000  //Alignment 0x00020
#define NONE10_GAP_CHK                                         0x0000000000
#define NONE10_LEN                                             0x00003A0000
#define NONE10_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* DOWNLOAD_BUFFER   */
//co_buffer L3
#define DOWNLOAD_BUFFER_AVAILABLE                              0x000145B000
#define DOWNLOAD_BUFFER_ADR                                    0x000145B000  //Alignment 0x00020
#define DOWNLOAD_BUFFER_GAP_CHK                                0x0000000000
#define DOWNLOAD_BUFFER_LEN                                    0x0000800000
#define DOWNLOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* NONE5   */
//co_buffer L3
#define NONE5_AVAILABLE                                        0x0001C5B000
#define NONE5_ADR                                              0x0001C5B000  //Alignment 0
#define NONE5_GAP_CHK                                          0x0000000000
#define NONE5_LEN                                              0x0001500000
#define NONE5_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* MPO_DISPLAY_BUFFER   */
//co_buffer L3
#define MPO_DISPLAY_BUFFER_AVAILABLE                           0x000315B000
#define MPO_DISPLAY_BUFFER_ADR                                 0x000315B000  //Alignment 0
#define MPO_DISPLAY_BUFFER_GAP_CHK                             0x0000000000
#define MPO_DISPLAY_BUFFER_LEN                                 0x0000900000
#define MPO_DISPLAY_BUFFER_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* SCALER_2DTO3D_DD_BUF   */
//co_buffer L3
#define SCALER_2DTO3D_DD_BUF_AVAILABLE                         0x0003A5B000
#define SCALER_2DTO3D_DD_BUF_ADR                               0x0003A5B000  //Alignment 0x00008
#define SCALER_2DTO3D_DD_BUF_GAP_CHK                           0x0000000000
#define SCALER_2DTO3D_DD_BUF_LEN                               0x0000000000
#define SCALER_2DTO3D_DD_BUF_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* SCALER_2DTO3D_DR_BUF   */
//co_buffer L3
#define SCALER_2DTO3D_DR_BUF_AVAILABLE                         0x0003A5B000
#define SCALER_2DTO3D_DR_BUF_ADR                               0x0003A5B000  //Alignment 0x00008
#define SCALER_2DTO3D_DR_BUF_GAP_CHK                           0x0000000000
#define SCALER_2DTO3D_DR_BUF_LEN                               0x0000000000
#define SCALER_2DTO3D_DR_BUF_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* NONE11   */
//co_buffer L6
#define NONE11_AVAILABLE                                       0x0000FBB000
#define NONE11_ADR                                             0x0000FBB000  //Alignment 0x00200
#define NONE11_GAP_CHK                                         0x0000000000
#define NONE11_LEN                                             0x0000100000
#define NONE11_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* NONE12   */
//co_buffer L6
#define NONE12_AVAILABLE                                       0x00010BB000
#define NONE12_ADR                                             0x00010BB000  //Alignment 0x00020
#define NONE12_GAP_CHK                                         0x0000000000
#define NONE12_LEN                                             0x00003A0000
#define NONE12_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* NONE14   */
//co_buffer L6
#define NONE14_AVAILABLE                                       0x000145B000
#define NONE14_ADR                                             0x000145B000  //Alignment 0x00008
#define NONE14_GAP_CHK                                         0x0000000000
#define NONE14_LEN                                             0x0000900000
#define NONE14_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* BIN_DESCOM_SRC_BUF   */
//co_buffer L6
#define BIN_DESCOM_SRC_BUF_AVAILABLE                           0x0001D5B000
#define BIN_DESCOM_SRC_BUF_ADR                                 0x0001D5B000  //Alignment 0
#define BIN_DESCOM_SRC_BUF_GAP_CHK                             0x0000000000
#define BIN_DESCOM_SRC_BUF_LEN                                 0x0000400000
#define BIN_DESCOM_SRC_BUF_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* BIN_DESCOM_TMP_BUF   */
//co_buffer L6
#define BIN_DESCOM_TMP_BUF_AVAILABLE                           0x000215B000
#define BIN_DESCOM_TMP_BUF_ADR                                 0x000215B000  //Alignment 0
#define BIN_DESCOM_TMP_BUF_GAP_CHK                             0x0000000000
#define BIN_DESCOM_TMP_BUF_LEN                                 0x0000400000
#define BIN_DESCOM_TMP_BUF_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* NONE15   */
//co_buffer L6
#define NONE15_AVAILABLE                                       0x000255B000
#define NONE15_ADR                                             0x000255B000  //Alignment 0x00020
#define NONE15_GAP_CHK                                         0x0000000000
#define NONE15_LEN                                             0x0000800000
#define NONE15_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* COMB_3D_BUF   */
//co_buffer L6
#define COMB_3D_BUF_AVAILABLE                                  0x0002D5B000
#define COMB_3D_BUF_ADR                                        0x0002D5B000  //Alignment 0x00008
#define COMB_3D_BUF_GAP_CHK                                    0x0000000000
#define COMB_3D_BUF_LEN                                        0x0000400000
#define COMB_3D_BUF_MEMORY_TYPE                                (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_READBUFF   */
//co_buffer L5
#define MAD_JPEG_READBUFF_AVAILABLE                            0x0000FBB000
#define MAD_JPEG_READBUFF_ADR                                  0x0000FBB000  //Alignment 0x00020
#define MAD_JPEG_READBUFF_GAP_CHK                              0x0000000000
#define MAD_JPEG_READBUFF_LEN                                  0x0000100000
#define MAD_JPEG_READBUFF_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* MAD_THUMBNAIL_FB_BUF   */
//co_buffer L5
#define MAD_THUMBNAIL_FB_BUF_AVAILABLE                         0x00010BB000
#define MAD_THUMBNAIL_FB_BUF_ADR                               0x00010BB000  //Alignment 0x00020
#define MAD_THUMBNAIL_FB_BUF_GAP_CHK                           0x0000000000
#define MAD_THUMBNAIL_FB_BUF_LEN                               0x00003A0000
#define MAD_THUMBNAIL_FB_BUF_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_INTERBUFF   */
//co_buffer L5
#define MAD_JPEG_INTERBUFF_AVAILABLE                           0x000145B000
#define MAD_JPEG_INTERBUFF_ADR                                 0x000145B000  //Alignment 0x00020
#define MAD_JPEG_INTERBUFF_GAP_CHK                             0x0000000000
#define MAD_JPEG_INTERBUFF_LEN                                 0x0000D00000
#define MAD_JPEG_INTERBUFF_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* NONE8   */
//co_buffer L5
#define NONE8_AVAILABLE                                        0x000215B000
#define NONE8_ADR                                              0x000215B000  //Alignment 0
#define NONE8_GAP_CHK                                          0x0000000000
#define NONE8_LEN                                              0x0000C00000
#define NONE8_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_OUT   */
//co_buffer L5
#define MAD_JPEG_OUT_AVAILABLE                                 0x0002D5B000
#define MAD_JPEG_OUT_ADR                                       0x0002D5B000  //Alignment 0x00020
#define MAD_JPEG_OUT_GAP_CHK                                   0x0000000000
#define MAD_JPEG_OUT_LEN                                       0x0000400000
#define MAD_JPEG_OUT_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* MAD_JPEG_DISPLAY   */
//co_buffer L5
#define MAD_JPEG_DISPLAY_AVAILABLE                             0x000315B000
#define MAD_JPEG_DISPLAY_ADR                                   0x000315B000  //Alignment 0
#define MAD_JPEG_DISPLAY_GAP_CHK                               0x0000000000
#define MAD_JPEG_DISPLAY_LEN                                   0x0000400000
#define MAD_JPEG_DISPLAY_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* TEXT_DATA_READ   */
//co_buffer L5
#define TEXT_DATA_READ_AVAILABLE                               0x000355B000
#define TEXT_DATA_READ_ADR                                     0x000355B000  //Alignment 0x00020
#define TEXT_DATA_READ_GAP_CHK                                 0x0000000000
#define TEXT_DATA_READ_LEN                                     0x0000010000
#define TEXT_DATA_READ_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* VDEC_AEON   */
//co_buffer L1
#define VDEC_AEON_AVAILABLE                                    0x0000FBB000
#define VDEC_AEON_ADR                                          0x0000FBB000  //Alignment 0x00200
#define VDEC_AEON_GAP_CHK                                      0x0000000000
#define VDEC_AEON_LEN                                          0x0000100000
#define VDEC_AEON_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* SUBTITLE   */
//co_buffer L1
#define SUBTITLE_AVAILABLE                                     0x00010BB000
#define SUBTITLE_ADR                                           0x00010BB000  //Alignment 0x00020
#define SUBTITLE_GAP_CHK                                       0x0000000000
#define SUBTITLE_LEN                                           0x00003A0000
#define SUBTITLE_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* VDEC_FRAMEBUFFER   */
//co_buffer L1
#define VDEC_FRAMEBUFFER_AVAILABLE                             0x000145B000
#define VDEC_FRAMEBUFFER_ADR                                   0x000145B000  //Alignment 0x00200
#define VDEC_FRAMEBUFFER_GAP_CHK                               0x0000000000
#define VDEC_FRAMEBUFFER_LEN                                   0x0001900000
#define VDEC_FRAMEBUFFER_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* VDEC_BITSTREAM   */
//co_buffer L1
#define VDEC_BITSTREAM_AVAILABLE                               0x0002D5B000
#define VDEC_BITSTREAM_ADR                                     0x0002D5B000  //Alignment 0x00020
#define VDEC_BITSTREAM_GAP_CHK                                 0x0000000000
#define VDEC_BITSTREAM_LEN                                     0x0000400000
#define VDEC_BITSTREAM_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF   */
//co_buffer L1
#define VDPLAYER_BITSTREAM_BUFF_AVAILABLE                      0x000315B000
#define VDPLAYER_BITSTREAM_BUFF_ADR                            0x000315B000  //Alignment 0x00020
#define VDPLAYER_BITSTREAM_BUFF_GAP_CHK                        0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_LEN                            0x0000400000
#define VDPLAYER_BITSTREAM_BUFF_MEMORY_TYPE                    (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF_EXT   */
//co_buffer L1
#define VDPLAYER_BITSTREAM_BUFF_EXT_AVAILABLE                  0x000355B000
#define VDPLAYER_BITSTREAM_BUFF_EXT_ADR                        0x000355B000  //Alignment 0x00020
#define VDPLAYER_BITSTREAM_BUFF_EXT_GAP_CHK                    0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_EXT_LEN                        0x0000400000
#define VDPLAYER_BITSTREAM_BUFF_EXT_MEMORY_TYPE                (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_DATA   */
//co_buffer L1
#define VDPLAYER_DATA_AVAILABLE                                0x000395B000
#define VDPLAYER_DATA_ADR                                      0x000395B000  //Alignment 0x00040
#define VDPLAYER_DATA_GAP_CHK                                  0x0000000000
#define VDPLAYER_DATA_LEN                                      0x0000380000
#define VDPLAYER_DATA_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* MP4_SUBTITLE_BUFFER   */
//co_buffer L1
#define MP4_SUBTITLE_BUFFER_AVAILABLE                          0x0003CDB000
#define MP4_SUBTITLE_BUFFER_ADR                                0x0003CDB000  //Alignment 0x00020
#define MP4_SUBTITLE_BUFFER_GAP_CHK                            0x0000000000
#define MP4_SUBTITLE_BUFFER_LEN                                0x0000100000
#define MP4_SUBTITLE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* MP4_SUBTITLE_TAG   */
//co_buffer L1
#define MP4_SUBTITLE_TAG_AVAILABLE                             0x0003DDB000
#define MP4_SUBTITLE_TAG_ADR                                   0x0003DDB000  //Alignment 0x01000
#define MP4_SUBTITLE_TAG_GAP_CHK                               0x0000000000
#define MP4_SUBTITLE_TAG_LEN                                   0x0000080000
#define MP4_SUBTITLE_TAG_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* MPLAYER_MUSIC_FILE_BUFFER   */
//co_buffer L1
#define MPLAYER_MUSIC_FILE_BUFFER_AVAILABLE                    0x0003E5B000
#define MPLAYER_MUSIC_FILE_BUFFER_ADR                          0x0003E5B000  //Alignment 0
#define MPLAYER_MUSIC_FILE_BUFFER_GAP_CHK                      0x0000000000
#define MPLAYER_MUSIC_FILE_BUFFER_LEN                          0x000000C800
#define MPLAYER_MUSIC_FILE_BUFFER_MEMORY_TYPE                  (MIU0 | SW | WRITE_BACK)

/* MPLAYER_PHOTO_PLAYLIST   */
//co_buffer L1
#define MPLAYER_PHOTO_PLAYLIST_AVAILABLE                       0x0003E67800
#define MPLAYER_PHOTO_PLAYLIST_ADR                             0x0003E67800  //Alignment 0
#define MPLAYER_PHOTO_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_PHOTO_PLAYLIST_LEN                             0x0000006400
#define MPLAYER_PHOTO_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* MPLAYER_MUSIC_PLAYLIST   */
//co_buffer L1
#define MPLAYER_MUSIC_PLAYLIST_AVAILABLE                       0x0003E6DC00
#define MPLAYER_MUSIC_PLAYLIST_ADR                             0x0003E6DC00  //Alignment 0
#define MPLAYER_MUSIC_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MUSIC_PLAYLIST_LEN                             0x0000006400
#define MPLAYER_MUSIC_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* MPLAYER_MOVIE_PLAYLIST   */
//co_buffer L1
#define MPLAYER_MOVIE_PLAYLIST_AVAILABLE                       0x0003E74000
#define MPLAYER_MOVIE_PLAYLIST_ADR                             0x0003E74000  //Alignment 0
#define MPLAYER_MOVIE_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MOVIE_PLAYLIST_LEN                             0x0000006400
#define MPLAYER_MOVIE_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | WRITE_BACK)

/* MPLAYER_TEXT_PLAYLIST   */
//co_buffer L1
#define MPLAYER_TEXT_PLAYLIST_AVAILABLE                        0x0003E7A400
#define MPLAYER_TEXT_PLAYLIST_ADR                              0x0003E7A400  //Alignment 0
#define MPLAYER_TEXT_PLAYLIST_GAP_CHK                          0x0000000000
#define MPLAYER_TEXT_PLAYLIST_LEN                              0x0000006400
#define MPLAYER_TEXT_PLAYLIST_MEMORY_TYPE                      (MIU0 | SW | WRITE_BACK)

/* MPLAYER_EMU_PLAYLIST   */
//co_buffer L1
#define MPLAYER_EMU_PLAYLIST_AVAILABLE                         0x0003E80800
#define MPLAYER_EMU_PLAYLIST_ADR                               0x0003E80800  //Alignment 0
#define MPLAYER_EMU_PLAYLIST_GAP_CHK                           0x0000000000
#define MPLAYER_EMU_PLAYLIST_LEN                               0x0000000000
#define MPLAYER_EMU_PLAYLIST_MEMORY_TYPE                       (MIU0 | SW | WRITE_BACK)

/* MUSIC_LYRIC_BUFFER   */
//co_buffer L1
#define MUSIC_LYRIC_BUFFER_AVAILABLE                           0x0003E80800
#define MUSIC_LYRIC_BUFFER_ADR                                 0x0003E80800  //Alignment 0
#define MUSIC_LYRIC_BUFFER_GAP_CHK                             0x0000000000
#define MUSIC_LYRIC_BUFFER_LEN                                 0x0000010000
#define MUSIC_LYRIC_BUFFER_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* MUSIC_LYRIC_TAG   */
//co_buffer L1
#define MUSIC_LYRIC_TAG_AVAILABLE                              0x0003E90800
#define MUSIC_LYRIC_TAG_ADR                                    0x0003E90800  //Alignment 0
#define MUSIC_LYRIC_TAG_GAP_CHK                                0x0000000000
#define MUSIC_LYRIC_TAG_LEN                                    0x0000001000
#define MUSIC_LYRIC_TAG_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* MP3_INFO_READ   */
//co_buffer L1
#define MP3_INFO_READ_AVAILABLE                                0x0003E91800
#define MP3_INFO_READ_ADR                                      0x0003E91800  //Alignment 0
#define MP3_INFO_READ_GAP_CHK                                  0x0000000000
#define MP3_INFO_READ_LEN                                      0x0000001000
#define MP3_INFO_READ_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* M4A_BUFFER   */
//co_buffer L1
#define M4A_BUFFER_AVAILABLE                                   0x0003E92800
#define M4A_BUFFER_ADR                                         0x0003E92800  //Alignment 0
#define M4A_BUFFER_GAP_CHK                                     0x0000000000
#define M4A_BUFFER_LEN                                         0x0000004000
#define M4A_BUFFER_MEMORY_TYPE                                 (MIU0 | SW | WRITE_BACK)

/* M4A_STCO   */
//co_buffer L1
#define M4A_STCO_AVAILABLE                                     0x0003E96800
#define M4A_STCO_ADR                                           0x0003E96800  //Alignment 0
#define M4A_STCO_GAP_CHK                                       0x0000000000
#define M4A_STCO_LEN                                           0x0000018000
#define M4A_STCO_MEMORY_TYPE                                   (MIU0 | SW | WRITE_BACK)

/* TEXT_FILE   */
//co_buffer L1
#define TEXT_FILE_AVAILABLE                                    0x0003EAE800
#define TEXT_FILE_ADR                                          0x0003EAE800  //Alignment 0
#define TEXT_FILE_GAP_CHK                                      0x0000000000
#define TEXT_FILE_LEN                                          0x0000002000
#define TEXT_FILE_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* FILE_OPERATION_INFO_BUFFER   */
//co_buffer L1
#define FILE_OPERATION_INFO_BUFFER_AVAILABLE                   0x0003EB0800
#define FILE_OPERATION_INFO_BUFFER_ADR                         0x0003EB0800  //Alignment 0
#define FILE_OPERATION_INFO_BUFFER_GAP_CHK                     0x0000000000
#define FILE_OPERATION_INFO_BUFFER_LEN                         0x0000000C00
#define FILE_OPERATION_INFO_BUFFER_MEMORY_TYPE                 (MIU0 | SW | WRITE_BACK)

/* VDPLAYER_SUBTITLE_BITSTREAM_BUFF   */
//co_buffer L1
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_AVAILABLE             0x0003EB1400
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR                   0x0003EB1400  //Alignment 0x00020
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_GAP_CHK               0x0000000000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_LEN                   0x0000080000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_MEMORY_TYPE           (MIU0 | SW | WRITE_BACK)

/* PATH_INFO_BUFFER   */
//co_buffer L1
#define PATH_INFO_BUFFER_AVAILABLE                             0x0003F31400
#define PATH_INFO_BUFFER_ADR                                   0x0003F31400  //Alignment 0
#define PATH_INFO_BUFFER_GAP_CHK                               0x0000000000
#define PATH_INFO_BUFFER_LEN                                   0x0000000400
#define PATH_INFO_BUFFER_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* PHOTO_SHARE_MEM   */
//co_buffer L1
#define PHOTO_SHARE_MEM_AVAILABLE                              0x0003F31800
#define PHOTO_SHARE_MEM_ADR                                    0x0003F31800  //Alignment 0
#define PHOTO_SHARE_MEM_GAP_CHK                                0x0000000000
#define PHOTO_SHARE_MEM_LEN                                    0x0000000400
#define PHOTO_SHARE_MEM_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* MPLAYER_FILE_BUFFER   */
//co_buffer L1
#define MPLAYER_FILE_BUFFER_AVAILABLE                          0x0003F31C00
#define MPLAYER_FILE_BUFFER_ADR                                0x0003F31C00  //Alignment 0
#define MPLAYER_FILE_BUFFER_GAP_CHK                            0x0000000000
#define MPLAYER_FILE_BUFFER_LEN                                0x0000019000
#define MPLAYER_FILE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* NONE3   */
//co_buffer L4
#define NONE3_AVAILABLE                                        0x0000FBB000
#define NONE3_ADR                                              0x0000FBB000  //Alignment 0x00200
#define NONE3_GAP_CHK                                          0x0000000000
#define NONE3_LEN                                              0x0000100000
#define NONE3_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_BUF_PREV   */
//co_buffer L4
#define SCALER_DNR_BUF_PREV_AVAILABLE                          0x00010BB000
#define SCALER_DNR_BUF_PREV_ADR                                0x00010BB000  //Alignment 0x00020
#define SCALER_DNR_BUF_PREV_GAP_CHK                            0x0000000000
#define SCALER_DNR_BUF_PREV_LEN                                0x00003A0000
#define SCALER_DNR_BUF_PREV_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* VDEC_FRAMEBUFFER_SD   */
//co_buffer L4
#define VDEC_FRAMEBUFFER_SD_AVAILABLE                          0x000145B000
#define VDEC_FRAMEBUFFER_SD_ADR                                0x000145B000  //Alignment 0x00200
#define VDEC_FRAMEBUFFER_SD_GAP_CHK                            0x0000000000
#define VDEC_FRAMEBUFFER_SD_LEN                                0x0000D00000
#define VDEC_FRAMEBUFFER_SD_MEMORY_TYPE                        (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_BUF   */
//co_buffer L4
#define SCALER_DNR_BUF_AVAILABLE                               0x000215B000
#define SCALER_DNR_BUF_ADR                                     0x000215B000  //Alignment 0x00020
#define SCALER_DNR_BUF_GAP_CHK                                 0x0000000000
#define SCALER_DNR_BUF_LEN                                     0x0000C00000
#define SCALER_DNR_BUF_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* VDEC_BITSTREAM_SD   */
//co_buffer L4
#define VDEC_BITSTREAM_SD_AVAILABLE                            0x0002D5B000
#define VDEC_BITSTREAM_SD_ADR                                  0x0002D5B000  //Alignment 0x00008
#define VDEC_BITSTREAM_SD_GAP_CHK                              0x0000000000
#define VDEC_BITSTREAM_SD_LEN                                  0x0000400000
#define VDEC_BITSTREAM_SD_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* NONE6   */
//co_buffer L4
#define NONE6_AVAILABLE                                        0x000315B000
#define NONE6_ADR                                              0x000315B000  //Alignment 0
#define NONE6_GAP_CHK                                          0x0000000000
#define NONE6_LEN                                              0x0000500000
#define NONE6_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* NONE1   */
//co_buffer L2
#define NONE1_AVAILABLE                                        0x0000FBB000
#define NONE1_ADR                                              0x0000FBB000  //Alignment 0x00200
#define NONE1_GAP_CHK                                          0x0000000000
#define NONE1_LEN                                              0x0000100000
#define NONE1_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* NONE2   */
//co_buffer L2
#define NONE2_AVAILABLE                                        0x00010BB000
#define NONE2_ADR                                              0x00010BB000  //Alignment 0x00020
#define NONE2_GAP_CHK                                          0x0000000000
#define NONE2_LEN                                              0x00003A0000
#define NONE2_MEMORY_TYPE                                      (MIU0 | SW | WRITE_BACK)

/* NONE24   */
//co_buffer L2
#define NONE24_AVAILABLE                                       0x000145B000
#define NONE24_ADR                                             0x000145B000  //Alignment 0x00200
#define NONE24_GAP_CHK                                         0x0000000000
#define NONE24_LEN                                             0x0001900000
#define NONE24_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* NONE25   */
//co_buffer L2
#define NONE25_AVAILABLE                                       0x0002D5B000
#define NONE25_ADR                                             0x0002D5B000  //Alignment 0x00008
#define NONE25_GAP_CHK                                         0x0000000000
#define NONE25_LEN                                             0x0000400000
#define NONE25_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* EVENTDB_SDRAM   */
//co_buffer L2
#define EVENTDB_SDRAM_AVAILABLE                                0x000315B000
#define EVENTDB_SDRAM_ADR                                      0x000315B000  //Alignment 0x00010
#define EVENTDB_SDRAM_GAP_CHK                                  0x0000000000
#define EVENTDB_SDRAM_LEN                                      0x0000500000
#define EVENTDB_SDRAM_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_BUF_DTV   */
//co_buffer L2
#define SCALER_DNR_BUF_DTV_AVAILABLE                           0x000365B000
#define SCALER_DNR_BUF_DTV_ADR                                 0x000365B000  //Alignment 0
#define SCALER_DNR_BUF_DTV_GAP_CHK                             0x0000000000
#define SCALER_DNR_BUF_DTV_LEN                                 0x0000000000
#define SCALER_DNR_BUF_DTV_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* PVR_WRITE_SDRAM   */
//co_buffer L2
#define PVR_WRITE_SDRAM_AVAILABLE                              0x000365B000
#define PVR_WRITE_SDRAM_ADR                                    0x000365B000  //Alignment 0x01000
#define PVR_WRITE_SDRAM_GAP_CHK                                0x0000000000
#define PVR_WRITE_SDRAM_LEN                                    0x00001B0000
#define PVR_WRITE_SDRAM_MEMORY_TYPE                            (MIU0 | SW | WRITE_BACK)

/* TTXBUF_START   */
//co_buffer L2
#define TTXBUF_START_AVAILABLE                                 0x000380B000
#define TTXBUF_START_ADR                                       0x000380B000  //Alignment 0x00020
#define TTXBUF_START_GAP_CHK                                   0x0000000000
#define TTXBUF_START_LEN                                       0x0000240800
#define TTXBUF_START_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* BULK_FILE_SYSTEM   */
//co_buffer L2
#define BULK_FILE_SYSTEM_AVAILABLE                             0x0003A4B800
#define BULK_FILE_SYSTEM_ADR                                   0x0003A4C000  //Alignment 0x01000
#define BULK_FILE_SYSTEM_GAP_CHK                               0x0000000800
#define BULK_FILE_SYSTEM_LEN                                   0x0000006000
#define BULK_FILE_SYSTEM_MEMORY_TYPE                           (MIU0 | SW | WRITE_BACK)

/* SI_MONITOR_DB   */
//co_buffer L2
#define SI_MONITOR_DB_AVAILABLE                                0x0003A52000
#define SI_MONITOR_DB_ADR                                      0x0003A52000  //Alignment 0x00008
#define SI_MONITOR_DB_GAP_CHK                                  0x0000000000
#define SI_MONITOR_DB_LEN                                      0x000000E000
#define SI_MONITOR_DB_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* SRV_NAME_BUF   */
//co_buffer L2
#define SRV_NAME_BUF_AVAILABLE                                 0x0003A60000
#define SRV_NAME_BUF_ADR                                       0x0003A60000  //Alignment 0x00008
#define SRV_NAME_BUF_GAP_CHK                                   0x0000000000
#define SRV_NAME_BUF_LEN                                       0x0000001000
#define SRV_NAME_BUF_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* MMI_TEXTSTRING   */
//co_buffer L2
#define MMI_TEXTSTRING_AVAILABLE                               0x0003A61000
#define MMI_TEXTSTRING_ADR                                     0x0003A61000  //Alignment 0x00008
#define MMI_TEXTSTRING_GAP_CHK                                 0x0000000000
#define MMI_TEXTSTRING_LEN                                     0x0000001000
#define MMI_TEXTSTRING_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* CI_PMT_BUFFER   */
//co_buffer L2
#define CI_PMT_BUFFER_AVAILABLE                                0x0003A62000
#define CI_PMT_BUFFER_ADR                                      0x0003A62000  //Alignment 0x00008
#define CI_PMT_BUFFER_GAP_CHK                                  0x0000000000
#define CI_PMT_BUFFER_LEN                                      0x0000001000
#define CI_PMT_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* DEMOD_MEM   */
//co_buffer L2
#define DEMOD_MEM_AVAILABLE                                    0x0003A63000
#define DEMOD_MEM_ADR                                          0x0003A63000  //Alignment 0x00010
#define DEMOD_MEM_GAP_CHK                                      0x0000000000
#define DEMOD_MEM_LEN                                          0x0000008000
#define DEMOD_MEM_MEMORY_TYPE                                  (MIU0 | SW | WRITE_BACK)

/* EIT_PF_STRING_BUF   */
//co_buffer L2
#define EIT_PF_STRING_BUF_AVAILABLE                            0x0003A6B000
#define EIT_PF_STRING_BUF_ADR                                  0x0003A6B000  //Alignment 0x00010
#define EIT_PF_STRING_BUF_GAP_CHK                              0x0000000000
#define EIT_PF_STRING_BUF_LEN                                  0x0000004000
#define EIT_PF_STRING_BUF_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* VE_FRAMEBUFFER   */
//co_buffer L2
#define VE_FRAMEBUFFER_AVAILABLE                               0x0003A6F000
#define VE_FRAMEBUFFER_ADR                                     0x0003A6F000  //Alignment 0x00008
#define VE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define VE_FRAMEBUFFER_LEN                                     0x0000000000
#define VE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* PVR_IO_BUFFER   */
//co_buffer L2
#define PVR_IO_BUFFER_AVAILABLE                                0x0003A6F000
#define PVR_IO_BUFFER_ADR                                      0x0003A6F000  //Alignment 0x00010
#define PVR_IO_BUFFER_GAP_CHK                                  0x0000000000
#define PVR_IO_BUFFER_LEN                                      0x0000010000
#define PVR_IO_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* EPGEXTDB_SDRAM   */
//co_buffer L2
#define EPGEXTDB_SDRAM_AVAILABLE                               0x0003A7F000
#define EPGEXTDB_SDRAM_ADR                                     0x0003A7F000  //Alignment 0x00010
#define EPGEXTDB_SDRAM_GAP_CHK                                 0x0000000000
#define EPGEXTDB_SDRAM_LEN                                     0x000000D000
#define EPGEXTDB_SDRAM_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* PVR_WRITE_METADATA_BUFFER   */
//co_buffer L2
#define PVR_WRITE_METADATA_BUFFER_AVAILABLE                    0x0003A8C000
#define PVR_WRITE_METADATA_BUFFER_ADR                          0x0003A8C000  //Alignment 0x01000
#define PVR_WRITE_METADATA_BUFFER_GAP_CHK                      0x0000000000
#define PVR_WRITE_METADATA_BUFFER_LEN                          0x0000060000
#define PVR_WRITE_METADATA_BUFFER_MEMORY_TYPE                  (MIU0 | SW | WRITE_BACK)

/* PVR_READ_METADATA_BUFFER   */
//co_buffer L2
#define PVR_READ_METADATA_BUFFER_AVAILABLE                     0x0003AEC000
#define PVR_READ_METADATA_BUFFER_ADR                           0x0003AEC000  //Alignment 0x01000
#define PVR_READ_METADATA_BUFFER_GAP_CHK                       0x0000000000
#define PVR_READ_METADATA_BUFFER_LEN                           0x0000000C00
#define PVR_READ_METADATA_BUFFER_MEMORY_TYPE                   (MIU0 | SW | WRITE_BACK)

/* PVR_READ_SDRAM   */
//co_buffer L2
#define PVR_READ_SDRAM_AVAILABLE                               0x0003AECC00
#define PVR_READ_SDRAM_ADR                                     0x0003AECC00  //Alignment 0
#define PVR_READ_SDRAM_GAP_CHK                                 0x0000000000
#define PVR_READ_SDRAM_LEN                                     0x00001B0000
#define PVR_READ_SDRAM_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* PVR_BROWSER_BUFFER   */
//co_buffer L2
#define PVR_BROWSER_BUFFER_AVAILABLE                           0x0003C9CC00
#define PVR_BROWSER_BUFFER_ADR                                 0x0003C9CC00  //Alignment 0
#define PVR_BROWSER_BUFFER_GAP_CHK                             0x0000000000
#define PVR_BROWSER_BUFFER_LEN                                 0x0000000000
#define PVR_BROWSER_BUFFER_MEMORY_TYPE                         (MIU0 | SW | WRITE_BACK)

/* OADSEC_BUFFER   */
//co_buffer L2
#define OADSEC_BUFFER_AVAILABLE                                0x0003C9CC00
#define OADSEC_BUFFER_ADR                                      0x0003C9CC00  //Alignment 0x00010
#define OADSEC_BUFFER_GAP_CHK                                  0x0000000000
#define OADSEC_BUFFER_LEN                                      0x0000014000
#define OADSEC_BUFFER_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

/* GOP_GWIN_TTX   */
//co_buffer L2
#define GOP_GWIN_TTX_AVAILABLE                                 0x0003CB0C00
#define GOP_GWIN_TTX_ADR                                       0x0003CB0C00  //Alignment 0x00020
#define GOP_GWIN_TTX_GAP_CHK                                   0x0000000000
#define GOP_GWIN_TTX_LEN                                       0x0000219800
#define GOP_GWIN_TTX_MEMORY_TYPE                               (MIU0 | SW | WRITE_BACK)

/* PVR_TRICK_MODE   */
//co_buffer L4
#define PVR_TRICK_MODE_AVAILABLE                               0x000365B000
#define PVR_TRICK_MODE_ADR                                     0x000365B000  //Alignment 0x01000
#define PVR_TRICK_MODE_GAP_CHK                                 0x0000000000
#define PVR_TRICK_MODE_LEN                                     0x00001B0000
#define PVR_TRICK_MODE_MEMORY_TYPE                             (MIU0 | SW | WRITE_BACK)

/* NONE13   */
//co_buffer L7
#define NONE13_AVAILABLE                                       0x0000FBB000
#define NONE13_ADR                                             0x0000FBB000  //Alignment 0x00200
#define NONE13_GAP_CHK                                         0x0000000000
#define NONE13_LEN                                             0x0000100000
#define NONE13_MEMORY_TYPE                                     (MIU0 | SW | WRITE_BACK)

/* SCALER_DNR_BUF_UC   */
//co_buffer L7
#define SCALER_DNR_BUF_UC_AVAILABLE                            0x00010BB000
#define SCALER_DNR_BUF_UC_ADR                                  0x00010BB000  //Alignment 0x00200
#define SCALER_DNR_BUF_UC_GAP_CHK                              0x0000000000
#define SCALER_DNR_BUF_UC_LEN                                  0x0001800000
#define SCALER_DNR_BUF_UC_MEMORY_TYPE                          (MIU0 | SW | WRITE_BACK)

/* WMA_INFO_READ   */
//co_buffer L3
#define WMA_INFO_READ_AVAILABLE                                0x0003A5B000
#define WMA_INFO_READ_ADR                                      0x0003A5B000  //Alignment 0x00008
#define WMA_INFO_READ_GAP_CHK                                  0x0000000000
#define WMA_INFO_READ_LEN                                      0x0000100000
#define WMA_INFO_READ_MEMORY_TYPE                              (MIU0 | SW | WRITE_BACK)

//MIU_1_START
//MIU_END
#define MIU0_END_ADR                                           0x0003FF9000
