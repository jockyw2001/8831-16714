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
#define MIU_DRAM_LEN                0x0004000000
#define MIU_DRAM_LEN0               0x0004000000

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
#define MIU0_LAYER_COUNT            (7)
#define MIU1_LAYER_COUNT            (0)

//MIU_0_START
/* AEON_MEM   */
//co_buffer L0
#define AEON_MEM_AVAILABLE                                     0x0000000000
#define AEON_MEM_ADR                                           0x0000000000  //Alignment 0
#define AEON_MEM_GAP_CHK                                       0x0000000000
#define AEON_MEM_LEN                                           0x0000200000
#define AEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* AEON_MM_MEM   */
//co_buffer L1
#define AEON_MM_MEM_AVAILABLE                                  0x0000000000
#define AEON_MM_MEM_ADR                                        0x0000000000  //Alignment 0
#define AEON_MM_MEM_GAP_CHK                                    0x0000000000
#define AEON_MM_MEM_LEN                                        0x0000200000
#define AEON_MM_MEM_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* PVR_WRITE_SDRAM   */
//co_buffer L2
#define PVR_WRITE_SDRAM_AVAILABLE                              0x0000000000
#define PVR_WRITE_SDRAM_ADR                                    0x0000000000  //Alignment 0x01000
#define PVR_WRITE_SDRAM_GAP_CHK                                0x0000000000
#define PVR_WRITE_SDRAM_LEN                                    0x00001B0000
#define PVR_WRITE_SDRAM_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_IO_BUFFER   */
//co_buffer L2
#define PVR_IO_BUFFER_AVAILABLE                                0x00001B0000
#define PVR_IO_BUFFER_ADR                                      0x00001B0000  //Alignment 0x01000
#define PVR_IO_BUFFER_GAP_CHK                                  0x0000000000
#define PVR_IO_BUFFER_LEN                                      0x0000010000
#define PVR_IO_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* BULK_FILE_SYSTEM   */
//co_buffer L2
#define BULK_FILE_SYSTEM_AVAILABLE                             0x00001C0000
#define BULK_FILE_SYSTEM_ADR                                   0x00001C0000  //Alignment 0x01000
#define BULK_FILE_SYSTEM_GAP_CHK                               0x0000000000
#define BULK_FILE_SYSTEM_LEN                                   0x0000006000
#define BULK_FILE_SYSTEM_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* PVR_TRICK_MODE   */
//co_buffer L3
#define PVR_TRICK_MODE_AVAILABLE                               0x0000000000
#define PVR_TRICK_MODE_ADR                                     0x0000000000  //Alignment 0x01000
#define PVR_TRICK_MODE_GAP_CHK                                 0x0000000000
#define PVR_TRICK_MODE_LEN                                     0x00001B0000
#define PVR_TRICK_MODE_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* BEON_MEM   */
//co_buffer L0
#define BEON_MEM_AVAILABLE                                     0x0000200000
#define BEON_MEM_ADR                                           0x0000200000  //Alignment 0x10000
#define BEON_MEM_GAP_CHK                                       0x0000000000
#define BEON_MEM_LEN                                           0x00004B0000
#define BEON_MEM_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* SECBUF_START   */
//co_buffer L0
#define SECBUF_START_AVAILABLE                                 0x00006B0000
#define SECBUF_START_ADR                                       0x00006B0000  //Alignment 0x10000
#define SECBUF_START_GAP_CHK                                   0x0000000000
#define SECBUF_START_LEN                                       0x0000023000
#define SECBUF_START_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* SCHEDULE_LIST   */
//co_buffer L0
#define SCHEDULE_LIST_AVAILABLE                                0x00006D3000
#define SCHEDULE_LIST_ADR                                      0x00006D3000  //Alignment 0x01000
#define SCHEDULE_LIST_GAP_CHK                                  0x0000000000
#define SCHEDULE_LIST_LEN                                      0x0000001000
#define SCHEDULE_LIST_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* USB_BUFFER_START   */
//co_buffer L0
#define USB_BUFFER_START_AVAILABLE                             0x00006D4000
#define USB_BUFFER_START_ADR                                   0x00006D4000  //Alignment 0x01000
#define USB_BUFFER_START_GAP_CHK                               0x0000000000
#define USB_BUFFER_START_LEN                                   0x0000001000
#define USB_BUFFER_START_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* USB_BUFFER2_START   */
//co_buffer L0
#define USB_BUFFER2_START_AVAILABLE                            0x00006D5000
#define USB_BUFFER2_START_ADR                                  0x00006D5000  //Alignment 0x01000
#define USB_BUFFER2_START_GAP_CHK                              0x0000000000
#define USB_BUFFER2_START_LEN                                  0x0000001000
#define USB_BUFFER2_START_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PM51_MEM   */
//co_buffer L0
#define PM51_MEM_AVAILABLE                                     0x00006D6000
#define PM51_MEM_ADR                                           0x00006D6000  //Alignment 0x01000
#define PM51_MEM_GAP_CHK                                       0x0000000000
#define PM51_MEM_LEN                                           0x0000000400
#define PM51_MEM_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* TSP_VQ_BUFFER   */
//co_buffer L0
#define TSP_VQ_BUFFER_AVAILABLE                                0x00006D6400
#define TSP_VQ_BUFFER_ADR                                      0x00006D6400  //Alignment 0x00010
#define TSP_VQ_BUFFER_GAP_CHK                                  0x0000000000
#define TSP_VQ_BUFFER_LEN                                      0x0000000C00
#define TSP_VQ_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE   */
//co_buffer L0
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_AVAILABLE      0x00006D7000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_ADR            0x00006D7000  //Alignment 0x01000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_GAP_CHK        0x0000000000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_LEN            0x0000001000
#define MAPP_FILEBROWSER_CURRENT_DIR_NAME_CACHE_MEMORY_TYPE    (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* FILE_SYSTEM_POOL   */
//co_buffer L0
#define FILE_SYSTEM_POOL_AVAILABLE                             0x00006D8000
#define FILE_SYSTEM_POOL_ADR                                   0x00006D8000  //Alignment 0x01000
#define FILE_SYSTEM_POOL_GAP_CHK                               0x0000000000
#define FILE_SYSTEM_POOL_LEN                                   0x0000060000
#define FILE_SYSTEM_POOL_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* GOP_REGDMABASE   */
//co_buffer L0
#define GOP_REGDMABASE_AVAILABLE                               0x0000738000
#define GOP_REGDMABASE_ADR                                     0x0000738000  //Alignment 0x01000
#define GOP_REGDMABASE_GAP_CHK                                 0x0000000000
#define GOP_REGDMABASE_LEN                                     0x0000000800
#define GOP_REGDMABASE_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_DSP_DEC_BUFFER   */
//co_buffer L0
#define MAD_DSP_DEC_BUFFER_AVAILABLE                           0x0000738800
#define MAD_DSP_DEC_BUFFER_ADR                                 0x0000738800  //Alignment 0x00020
#define MAD_DSP_DEC_BUFFER_GAP_CHK                             0x0000000000
#define MAD_DSP_DEC_BUFFER_LEN                                 0x0000000000
#define MAD_DSP_DEC_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_DSP_SE_BUFFER   */
//co_buffer L0
#define MAD_DSP_SE_BUFFER_AVAILABLE                            0x0000738800
#define MAD_DSP_SE_BUFFER_ADR                                  0x0000738800  //Alignment 0x00020
#define MAD_DSP_SE_BUFFER_GAP_CHK                              0x0000000000
#define MAD_DSP_SE_BUFFER_LEN                                  0x0000000000
#define MAD_DSP_SE_BUFFER_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_DSP_ADV_BUFFER   */
//co_buffer L0
#define MAD_DSP_ADV_BUFFER_AVAILABLE                           0x0000738800
#define MAD_DSP_ADV_BUFFER_ADR                                 0x0000738800  //Alignment 0x00020
#define MAD_DSP_ADV_BUFFER_GAP_CHK                             0x0000000000
#define MAD_DSP_ADV_BUFFER_LEN                                 0x0000002800
#define MAD_DSP_ADV_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_BASE_BUFFER   */
//co_buffer L0
#define MAD_BASE_BUFFER_AVAILABLE                              0x000073B000
#define MAD_BASE_BUFFER_ADR                                    0x000073B000  //Alignment 0x01000
#define MAD_BASE_BUFFER_GAP_CHK                                0x0000000000
#define MAD_BASE_BUFFER_LEN                                    0x0000180000
#define MAD_BASE_BUFFER_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MAD_SE_BUFFER   */
//co_buffer L1
#define MAD_SE_BUFFER_AVAILABLE                                0x000073B000
#define MAD_SE_BUFFER_ADR                                      0x000073B000  //Alignment 0x00020
#define MAD_SE_BUFFER_GAP_CHK                                  0x0000000000
#define MAD_SE_BUFFER_LEN                                      0x0000000000
#define MAD_SE_BUFFER_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MAD_DEC_BUFFER   */
//co_buffer L1
#define MAD_DEC_BUFFER_AVAILABLE                               0x000073B000
#define MAD_DEC_BUFFER_ADR                                     0x000073B000  //Alignment 0x00020
#define MAD_DEC_BUFFER_GAP_CHK                                 0x0000000000
#define MAD_DEC_BUFFER_LEN                                     0x0000180000
#define MAD_DEC_BUFFER_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* GE_FRAMEBUFFER   */
//co_buffer L0
#define GE_FRAMEBUFFER_AVAILABLE                               0x00008BB000
#define GE_FRAMEBUFFER_ADR                                     0x00008BB000  //Alignment 0x00020
#define GE_FRAMEBUFFER_GAP_CHK                                 0x0000000000
#define GE_FRAMEBUFFER_LEN                                     0x0000460000
#define GE_FRAMEBUFFER_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* GOP_GWIN_RB   */
//co_buffer L1
#define GOP_GWIN_RB_AVAILABLE                                  0x00008BB000
#define GOP_GWIN_RB_ADR                                        0x00008BB000  //Alignment 0x00020
#define GOP_GWIN_RB_GAP_CHK                                    0x0000000000
#define GOP_GWIN_RB_LEN                                        0x0000460000
#define GOP_GWIN_RB_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* CAPTURE_VIDEO_BUFFER   */
//co_buffer L2
#define CAPTURE_VIDEO_BUFFER_AVAILABLE                         0x00008BB000
#define CAPTURE_VIDEO_BUFFER_ADR                               0x00008BB000  //Alignment 0x00020
#define CAPTURE_VIDEO_BUFFER_GAP_CHK                           0x0000000000
#define CAPTURE_VIDEO_BUFFER_LEN                               0x0000180000
#define CAPTURE_VIDEO_BUFFER_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* DATABASE_START   */
//co_buffer L0
#define DATABASE_START_AVAILABLE                               0x0000D1B000
#define DATABASE_START_ADR                                     0x0000D1B000  //Alignment 0x00008
#define DATABASE_START_GAP_CHK                                 0x0000000000
#define DATABASE_START_LEN                                     0x00000C1000
#define DATABASE_START_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* RRT5_DIM_START   */
//co_buffer L0
#define RRT5_DIM_START_AVAILABLE                               0x0000DDC000
#define RRT5_DIM_START_ADR                                     0x0000DDC000  //Alignment 0x00008
#define RRT5_DIM_START_GAP_CHK                                 0x0000000000
#define RRT5_DIM_START_LEN                                     0x0000010000
#define RRT5_DIM_START_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* BMP_START   */
//co_buffer L0
#define BMP_START_AVAILABLE                                    0x0000DEC000
#define BMP_START_ADR                                          0x0000DEC000  //Alignment 0x00020
#define BMP_START_GAP_CHK                                      0x0000000000
#define BMP_START_LEN                                          0x0000100000
#define BMP_START_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* STRING_START   */
//co_buffer L0
#define STRING_START_AVAILABLE                                 0x0000EEC000
#define STRING_START_ADR                                       0x0000EEC000  //Alignment 0x00800
#define STRING_START_GAP_CHK                                   0x0000000000
#define STRING_START_LEN                                       0x0000078000
#define STRING_START_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* FONT_START   */
//co_buffer L0
#define FONT_START_AVAILABLE                                   0x0000F64000
#define FONT_START_ADR                                         0x0000F64000  //Alignment 0x00020
#define FONT_START_GAP_CHK                                     0x0000000000
#define FONT_START_LEN                                         0x000018F800
#define FONT_START_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* MENULOAD_BUFFER Must the same MIU with VDEC_AEON */
//co_buffer L0
#define MENULOAD_BUFFER_AVAILABLE                              0x00010F3800
#define MENULOAD_BUFFER_ADR                                    0x00010F3800  //Alignment 0x00008
#define MENULOAD_BUFFER_GAP_CHK                                0x0000000000
#define MENULOAD_BUFFER_LEN                                    0x0000004000
#define MENULOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PQ_MAIN Must the same MIU with VDEC_AEON */
//co_buffer L0
#define PQ_MAIN_AVAILABLE                                      0x00010F7800
#define PQ_MAIN_ADR                                            0x00010F7800  //Alignment 0x00008
#define PQ_MAIN_GAP_CHK                                        0x0000000000
#define PQ_MAIN_LEN                                            0x0000000000
#define PQ_MAIN_MEMORY_TYPE                                    (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PQ_MAIN_EX Must the same MIU with VDEC_AEON */
//co_buffer L0
#define PQ_MAIN_EX_AVAILABLE                                   0x00010F7800
#define PQ_MAIN_EX_ADR                                         0x00010F7800  //Alignment 0x00008
#define PQ_MAIN_EX_GAP_CHK                                     0x0000000000
#define PQ_MAIN_EX_LEN                                         0x0000000000
#define PQ_MAIN_EX_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* PQ_TEXT_MAIN Must the same MIU with VDEC_AEON */
//co_buffer L0
#define PQ_TEXT_MAIN_AVAILABLE                                 0x00010F7800
#define PQ_TEXT_MAIN_ADR                                       0x00010F7800  //Alignment 0x00008
#define PQ_TEXT_MAIN_GAP_CHK                                   0x0000000000
#define PQ_TEXT_MAIN_LEN                                       0x0000000000
#define PQ_TEXT_MAIN_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* DEMOD_MEM Must the same MIU with VDEC_AEON */
//co_buffer L0
#define DEMOD_MEM_AVAILABLE                                    0x00010F7800
#define DEMOD_MEM_ADR                                          0x00010F7800  //Alignment 0x00020
#define DEMOD_MEM_GAP_CHK                                      0x0000000000
#define DEMOD_MEM_LEN                                          0x0000000000
#define DEMOD_MEM_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* CAPE_BUFFER Must the same MIU with VDEC_AEON */
//co_buffer L0
#define CAPE_BUFFER_AVAILABLE                                  0x00010F7800
#define CAPE_BUFFER_ADR                                        0x00010F7800  //Alignment 0x00008
#define CAPE_BUFFER_GAP_CHK                                    0x0000000000
#define CAPE_BUFFER_LEN                                        0x0000000000
#define CAPE_BUFFER_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* POOL_BUFFER   */
//co_buffer L0
#define POOL_BUFFER_AVAILABLE                                  0x00010F7800
#define POOL_BUFFER_ADR                                        0x0001100000  //Alignment 0x10000
#define POOL_BUFFER_GAP_CHK                                    0x0000008800
#define POOL_BUFFER_LEN                                        0x0002E80000
#define POOL_BUFFER_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L0 | WRITE_BACK)

/* NONE40   */
//co_buffer L4
#define NONE40_AVAILABLE                                       0x0001100000
#define NONE40_ADR                                             0x0001100000  //Alignment 0x00200
#define NONE40_GAP_CHK                                         0x0000000000
#define NONE40_LEN                                             0x0000100000
#define NONE40_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* NONE41   */
//co_buffer L4
#define NONE41_AVAILABLE                                       0x0001200000
#define NONE41_ADR                                             0x0001200000  //Alignment 0x10000
#define NONE41_GAP_CHK                                         0x0000000000
#define NONE41_LEN                                             0x0000200000
#define NONE41_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* DOWNLOAD_BUFFER   */
//co_buffer L4
#define DOWNLOAD_BUFFER_AVAILABLE                              0x0001400000
#define DOWNLOAD_BUFFER_ADR                                    0x0001400000  //Alignment 0x01000
#define DOWNLOAD_BUFFER_GAP_CHK                                0x0000000000
#define DOWNLOAD_BUFFER_LEN                                    0x0000800000
#define DOWNLOAD_BUFFER_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* NONE42   */
//co_buffer L4
#define NONE42_AVAILABLE                                       0x0001C00000
#define NONE42_ADR                                             0x0001C00000  //Alignment 0x10000
#define NONE42_GAP_CHK                                         0x0000000000
#define NONE42_LEN                                             0x0001500000
#define NONE42_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* MPO_DISPLAY_BUFFER   */
//co_buffer L4
#define MPO_DISPLAY_BUFFER_AVAILABLE                           0x0003100000
#define MPO_DISPLAY_BUFFER_ADR                                 0x0003100000  //Alignment 0
#define MPO_DISPLAY_BUFFER_GAP_CHK                             0x0000000000
#define MPO_DISPLAY_BUFFER_LEN                                 0x0000900000
#define MPO_DISPLAY_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L4 | WRITE_BACK)

/* NONE50   */
//co_buffer L5
#define NONE50_AVAILABLE                                       0x0001100000
#define NONE50_ADR                                             0x0001100000  //Alignment 0x00200
#define NONE50_GAP_CHK                                         0x0000000000
#define NONE50_LEN                                             0x0000300000
#define NONE50_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* COMB_3D_BUF   */
//co_buffer L5
#define COMB_3D_BUF_AVAILABLE                                  0x0001400000
#define COMB_3D_BUF_ADR                                        0x0001400000  //Alignment 0x00020
#define COMB_3D_BUF_GAP_CHK                                    0x0000000000
#define COMB_3D_BUF_LEN                                        0x0000400000
#define COMB_3D_BUF_MEMORY_TYPE                                (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* SCALER_FB_NO_VDEC   */
//co_buffer L5
#define SCALER_FB_NO_VDEC_AVAILABLE                            0x0001800000
#define SCALER_FB_NO_VDEC_ADR                                  0x0001800000  //Alignment 0x00010
#define SCALER_FB_NO_VDEC_GAP_CHK                              0x0000000000
#define SCALER_FB_NO_VDEC_LEN                                  0x0001200000
#define SCALER_FB_NO_VDEC_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L5 | WRITE_BACK)

/* MAD_JPEG_READBUFF   */
//co_buffer L2
#define MAD_JPEG_READBUFF_AVAILABLE                            0x0001100000
#define MAD_JPEG_READBUFF_ADR                                  0x0001100000  //Alignment 0x01000
#define MAD_JPEG_READBUFF_GAP_CHK                              0x0000000000
#define MAD_JPEG_READBUFF_LEN                                  0x0000100000
#define MAD_JPEG_READBUFF_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* MAD_THUMBNAIL_FB_BUF   */
//co_buffer L2
#define MAD_THUMBNAIL_FB_BUF_AVAILABLE                         0x0001200000
#define MAD_THUMBNAIL_FB_BUF_ADR                               0x0001200000  //Alignment 0x10000
#define MAD_THUMBNAIL_FB_BUF_GAP_CHK                           0x0000000000
#define MAD_THUMBNAIL_FB_BUF_LEN                               0x0000200000
#define MAD_THUMBNAIL_FB_BUF_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* NONE20   */
//co_buffer L2
#define NONE20_AVAILABLE                                       0x0001400000
#define NONE20_ADR                                             0x0001400000  //Alignment 0x10000
#define NONE20_GAP_CHK                                         0x0000000000
#define NONE20_LEN                                             0x0000400000
#define NONE20_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* MAD_JPEG_INTERBUFF   */
//co_buffer L2
#define MAD_JPEG_INTERBUFF_AVAILABLE                           0x0001800000
#define MAD_JPEG_INTERBUFF_ADR                                 0x0001800000  //Alignment 0x10000
#define MAD_JPEG_INTERBUFF_GAP_CHK                             0x0000000000
#define MAD_JPEG_INTERBUFF_LEN                                 0x0000D00000
#define MAD_JPEG_INTERBUFF_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* NONE21   */
//co_buffer L2
#define NONE21_AVAILABLE                                       0x0002500000
#define NONE21_ADR                                             0x0002500000  //Alignment 0x10000
#define NONE21_GAP_CHK                                         0x0000000000
#define NONE21_LEN                                             0x0000C00000
#define NONE21_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* MAD_JPEG_OUT   */
//co_buffer L2
#define MAD_JPEG_OUT_AVAILABLE                                 0x0003100000
#define MAD_JPEG_OUT_ADR                                       0x0003100000  //Alignment 0x00008
#define MAD_JPEG_OUT_GAP_CHK                                   0x0000000000
#define MAD_JPEG_OUT_LEN                                       0x0000400000
#define MAD_JPEG_OUT_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* MAD_JPEG_DISPLAY   */
//co_buffer L2
#define MAD_JPEG_DISPLAY_AVAILABLE                             0x0003500000
#define MAD_JPEG_DISPLAY_ADR                                   0x0003500000  //Alignment 0
#define MAD_JPEG_DISPLAY_GAP_CHK                               0x0000000000
#define MAD_JPEG_DISPLAY_LEN                                   0x0000400000
#define MAD_JPEG_DISPLAY_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* TEXT_DATA_READ   */
//co_buffer L2
#define TEXT_DATA_READ_AVAILABLE                              0x0003900000
#define TEXT_DATA_READ_ADR                                    0x0003900000  //Alignment 0x01000
#define TEXT_DATA_READ_GAP_CHK                                0x0000000000
#define TEXT_DATA_READ_LEN                                    0x0000010000
#define TEXT_DATA_READ_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L2 | WRITE_BACK)

/* VDEC_AEON   */
//co_buffer L1
#define VDEC_AEON_AVAILABLE                                    0x0001100000
#define VDEC_AEON_ADR                                          0x0001100000  //Alignment 0x00200
#define VDEC_AEON_GAP_CHK                                      0x0000000000
#define VDEC_AEON_LEN                                          0x0000100000
#define VDEC_AEON_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* SUBTITLE   */
//co_buffer L1
#define SUBTITLE_AVAILABLE                                     0x0001200000
#define SUBTITLE_ADR                                           0x0001200000  //Alignment 0x10000
#define SUBTITLE_GAP_CHK                                       0x0000000000
#define SUBTITLE_LEN                                           0x0000200000
#define SUBTITLE_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDEC_BITSTREAM   */
//co_buffer L1
#define VDEC_BITSTREAM_AVAILABLE                               0x0001400000
#define VDEC_BITSTREAM_ADR                                     0x0001400000  //Alignment 0x10000
#define VDEC_BITSTREAM_GAP_CHK                                 0x0000000000
#define VDEC_BITSTREAM_LEN                                     0x0000400000
#define VDEC_BITSTREAM_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDEC_FRAMEBUFFER   */
//co_buffer L1
#define VDEC_FRAMEBUFFER_AVAILABLE                             0x0001800000
#define VDEC_FRAMEBUFFER_ADR                                   0x0001800000  //Alignment 0x00200
#define VDEC_FRAMEBUFFER_GAP_CHK                               0x0000000000
#define VDEC_FRAMEBUFFER_LEN                                   0x0001900000
#define VDEC_FRAMEBUFFER_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF   */
//co_buffer L1
#define VDPLAYER_BITSTREAM_BUFF_AVAILABLE                      0x0003100000
#define VDPLAYER_BITSTREAM_BUFF_ADR                            0x0003100000  //Alignment 0x10000
#define VDPLAYER_BITSTREAM_BUFF_GAP_CHK                        0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_LEN                            0x0000400000
#define VDPLAYER_BITSTREAM_BUFF_MEMORY_TYPE                    (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDPLAYER_BITSTREAM_BUFF_EXT   */
//co_buffer L1
#define VDPLAYER_BITSTREAM_BUFF_EXT_AVAILABLE                  0x0003500000
#define VDPLAYER_BITSTREAM_BUFF_EXT_ADR                        0x0003500000  //Alignment 0x10000
#define VDPLAYER_BITSTREAM_BUFF_EXT_GAP_CHK                    0x0000000000
#define VDPLAYER_BITSTREAM_BUFF_EXT_LEN                        0x0000400000
#define VDPLAYER_BITSTREAM_BUFF_EXT_MEMORY_TYPE                (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDPLAYER_DATA   */
//co_buffer L1
#define VDPLAYER_DATA_AVAILABLE                                0x0003900000
#define VDPLAYER_DATA_ADR                                      0x0003900000  //Alignment 0x10000
#define VDPLAYER_DATA_GAP_CHK                                  0x0000000000
#define VDPLAYER_DATA_LEN                                      0x0000400000
#define VDPLAYER_DATA_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MPLAYER_MUSIC_FILE_BUFFER   */
//co_buffer L1
#define MPLAYER_MUSIC_FILE_BUFFER_AVAILABLE                    0x0003D00000
#define MPLAYER_MUSIC_FILE_BUFFER_ADR                          0x0003D00000  //Alignment 0
#define MPLAYER_MUSIC_FILE_BUFFER_GAP_CHK                      0x0000000000
#define MPLAYER_MUSIC_FILE_BUFFER_LEN                          0x000004B000
#define MPLAYER_MUSIC_FILE_BUFFER_MEMORY_TYPE                  (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MPLAYER_PHOTO_PLAYLIST   */
//co_buffer L1
#define MPLAYER_PHOTO_PLAYLIST_AVAILABLE                       0x0003D4B000
#define MPLAYER_PHOTO_PLAYLIST_ADR                             0x0003D4B000  //Alignment 0
#define MPLAYER_PHOTO_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_PHOTO_PLAYLIST_LEN                             0x0000006400
#define MPLAYER_PHOTO_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MPLAYER_MUSIC_PLAYLIST   */
//co_buffer L1
#define MPLAYER_MUSIC_PLAYLIST_AVAILABLE                       0x0003D51400
#define MPLAYER_MUSIC_PLAYLIST_ADR                             0x0003D51400  //Alignment 0
#define MPLAYER_MUSIC_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MUSIC_PLAYLIST_LEN                             0x0000006400
#define MPLAYER_MUSIC_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MPLAYER_MOVIE_PLAYLIST   */
//co_buffer L1
#define MPLAYER_MOVIE_PLAYLIST_AVAILABLE                       0x0003D57800
#define MPLAYER_MOVIE_PLAYLIST_ADR                             0x0003D57800  //Alignment 0
#define MPLAYER_MOVIE_PLAYLIST_GAP_CHK                         0x0000000000
#define MPLAYER_MOVIE_PLAYLIST_LEN                             0x0000006400
#define MPLAYER_MOVIE_PLAYLIST_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MPLAYER_TEXT_PLAYLIST   */
//co_buffer L1
#define MPLAYER_TEXT_PLAYLIST_AVAILABLE                        0x0003D5DC00
#define MPLAYER_TEXT_PLAYLIST_ADR                              0x0003D5DC00  //Alignment 0
#define MPLAYER_TEXT_PLAYLIST_GAP_CHK                          0x0000000000
#define MPLAYER_TEXT_PLAYLIST_LEN                              0x0000006400
#define MPLAYER_TEXT_PLAYLIST_MEMORY_TYPE                      (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MPLAYER_EMU_PLAYLIST   */
//co_buffer L1
#define MPLAYER_EMU_PLAYLIST_AVAILABLE                         0x0003D64000
#define MPLAYER_EMU_PLAYLIST_ADR                               0x0003D64000  //Alignment 0
#define MPLAYER_EMU_PLAYLIST_GAP_CHK                           0x0000000000
#define MPLAYER_EMU_PLAYLIST_LEN                               0x0000006400
#define MPLAYER_EMU_PLAYLIST_MEMORY_TYPE                       (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MUSIC_LYRIC_BUFFER   */
//co_buffer L1
#define MUSIC_LYRIC_BUFFER_AVAILABLE                           0x0003D6A400
#define MUSIC_LYRIC_BUFFER_ADR                                 0x0003D6A400  //Alignment 0
#define MUSIC_LYRIC_BUFFER_GAP_CHK                             0x0000000000
#define MUSIC_LYRIC_BUFFER_LEN                                 0x0000010000
#define MUSIC_LYRIC_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MUSIC_LYRIC_TAG   */
//co_buffer L1
#define MUSIC_LYRIC_TAG_AVAILABLE                              0x0003D7A400
#define MUSIC_LYRIC_TAG_ADR                                    0x0003D7A400  //Alignment 0
#define MUSIC_LYRIC_TAG_GAP_CHK                                0x0000000000
#define MUSIC_LYRIC_TAG_LEN                                    0x0000001000
#define MUSIC_LYRIC_TAG_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MP3_INFO_READ   */
//co_buffer L1
#define MP3_INFO_READ_AVAILABLE                                0x0003D7B400
#define MP3_INFO_READ_ADR                                      0x0003D7B400  //Alignment 0
#define MP3_INFO_READ_GAP_CHK                                  0x0000000000
#define MP3_INFO_READ_LEN                                      0x0000001000
#define MP3_INFO_READ_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* M4A_BUFFER   */
//co_buffer L1
#define M4A_BUFFER_AVAILABLE                                   0x0003D7C400
#define M4A_BUFFER_ADR                                         0x0003D7C400  //Alignment 0
#define M4A_BUFFER_GAP_CHK                                     0x0000000000
#define M4A_BUFFER_LEN                                         0x0000004000
#define M4A_BUFFER_MEMORY_TYPE                                 (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* M4A_STCO   */
//co_buffer L1
#define M4A_STCO_AVAILABLE                                     0x0003D80400
#define M4A_STCO_ADR                                           0x0003D80400  //Alignment 0
#define M4A_STCO_GAP_CHK                                       0x0000000000
#define M4A_STCO_LEN                                           0x0000018000
#define M4A_STCO_MEMORY_TYPE                                   (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* TEXT_FILE   */
//co_buffer L1
#define TEXT_FILE_AVAILABLE                                    0x0003D98400
#define TEXT_FILE_ADR                                          0x0003D98400  //Alignment 0
#define TEXT_FILE_GAP_CHK                                      0x0000000000
#define TEXT_FILE_LEN                                          0x0000002000
#define TEXT_FILE_MEMORY_TYPE                                  (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* FILE_OPERATION_INFO_BUFFER   */
//co_buffer L1
#define FILE_OPERATION_INFO_BUFFER_AVAILABLE                   0x0003D9A400
#define FILE_OPERATION_INFO_BUFFER_ADR                         0x0003D9A400  //Alignment 0
#define FILE_OPERATION_INFO_BUFFER_GAP_CHK                     0x0000000000
#define FILE_OPERATION_INFO_BUFFER_LEN                         0x0000000C00
#define FILE_OPERATION_INFO_BUFFER_MEMORY_TYPE                 (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* VDPLAYER_SUBTITLE_BITSTREAM_BUFF   */
//co_buffer L1
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_AVAILABLE             0x0003D9B000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_ADR                   0x0003D9B000  //Alignment 0x01000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_GAP_CHK               0x0000000000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_LEN                   0x0000080000
#define VDPLAYER_SUBTITLE_BITSTREAM_BUFF_MEMORY_TYPE           (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MP4_SUBTITLE_BUFFER   */
//co_buffer L1
#define MP4_SUBTITLE_BUFFER_AVAILABLE                          0x0003E1B000
#define MP4_SUBTITLE_BUFFER_ADR                                0x0003E1B000  //Alignment 0x01000
#define MP4_SUBTITLE_BUFFER_GAP_CHK                            0x0000000000
#define MP4_SUBTITLE_BUFFER_LEN                                0x000000A000
#define MP4_SUBTITLE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* MP4_SUBTITLE_TAG   */
//co_buffer L1
#define MP4_SUBTITLE_TAG_AVAILABLE                             0x0003E25000
#define MP4_SUBTITLE_TAG_ADR                                   0x0003E25000  //Alignment 0x01000
#define MP4_SUBTITLE_TAG_GAP_CHK                               0x0000000000
#define MP4_SUBTITLE_TAG_LEN                                   0x0000000000
#define MP4_SUBTITLE_TAG_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* PATH_INFO_BUFFER   */
//co_buffer L1
#define PATH_INFO_BUFFER_AVAILABLE                             0x0003E25000
#define PATH_INFO_BUFFER_ADR                                   0x0003E25000  //Alignment 0
#define PATH_INFO_BUFFER_GAP_CHK                               0x0000000000
#define PATH_INFO_BUFFER_LEN                                   0x0000000400
#define PATH_INFO_BUFFER_MEMORY_TYPE                           (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* NONE30   */
//co_buffer L3
#define NONE30_AVAILABLE                                       0x0001100000
#define NONE30_ADR                                             0x0001100000  //Alignment 0x00200
#define NONE30_GAP_CHK                                         0x0000000000
#define NONE30_LEN                                             0x0000100000
#define NONE30_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* PHOTO_SHARE_MEM   */
//co_buffer L1
#define PHOTO_SHARE_MEM_AVAILABLE                              0x0003E25400
#define PHOTO_SHARE_MEM_ADR                                    0x0003E25400  //Alignment 0
#define PHOTO_SHARE_MEM_GAP_CHK                                0x0000000000
#define PHOTO_SHARE_MEM_LEN                                    0x0000000400
#define PHOTO_SHARE_MEM_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* SCALER_DNR_BUF_PREV   */
//co_buffer L3
#define SCALER_DNR_BUF_PREV_AVAILABLE                          0x0001200000
#define SCALER_DNR_BUF_PREV_ADR                                0x0001200000  //Alignment 0x10000
#define SCALER_DNR_BUF_PREV_GAP_CHK                            0x0000000000
#define SCALER_DNR_BUF_PREV_LEN                                0x0000200000
#define SCALER_DNR_BUF_PREV_MEMORY_TYPE                        (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* VDEC_BITSTREAM_SD   */
//co_buffer L3
#define VDEC_BITSTREAM_SD_AVAILABLE                            0x0001400000
#define VDEC_BITSTREAM_SD_ADR                                  0x0001400000  //Alignment 0x00008
#define VDEC_BITSTREAM_SD_GAP_CHK                              0x0000000000
#define VDEC_BITSTREAM_SD_LEN                                  0x0000400000
#define VDEC_BITSTREAM_SD_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* VDEC_FRAMEBUFFER_SD   */
//co_buffer L3
#define VDEC_FRAMEBUFFER_SD_AVAILABLE                          0x0001800000
#define VDEC_FRAMEBUFFER_SD_ADR                                0x0001800000  //Alignment 0x00200
#define VDEC_FRAMEBUFFER_SD_GAP_CHK                            0x0000000000
#define VDEC_FRAMEBUFFER_SD_LEN                                0x0000D00000
#define VDEC_FRAMEBUFFER_SD_MEMORY_TYPE                        (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* SCALER_DNR_BUF   */
//co_buffer L3
#define SCALER_DNR_BUF_AVAILABLE                               0x0002500000
#define SCALER_DNR_BUF_ADR                                     0x0002500000  //Alignment 0x00010
#define SCALER_DNR_BUF_GAP_CHK                                 0x0000000000
#define SCALER_DNR_BUF_LEN                                     0x0000C00000
#define SCALER_DNR_BUF_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* MPLAYER_FILE_BUFFER   */
//co_buffer L1
#define MPLAYER_FILE_BUFFER_AVAILABLE                          0x0003E25800
#define MPLAYER_FILE_BUFFER_ADR                                0x0003E25800  //Alignment 0
#define MPLAYER_FILE_BUFFER_GAP_CHK                            0x0000000000
#define MPLAYER_FILE_BUFFER_LEN                                0x0000096000
#define MPLAYER_FILE_BUFFER_MEMORY_TYPE                        (MIU0 | SW | CO_BUF_L1 | WRITE_BACK)

/* NONE60   */
//co_buffer L6
#define NONE60_AVAILABLE                                       0x0001100000
#define NONE60_ADR                                             0x0001100000  //Alignment 0x00200
#define NONE60_GAP_CHK                                         0x0000000000
#define NONE60_LEN                                             0x0001200000
#define NONE60_MEMORY_TYPE                                     (MIU0 | SW | CO_BUF_L6 | WRITE_BACK)

/* SCALER_DNR_BUF_DTV_TEST   */
//co_buffer L3
#define SCALER_DNR_BUF_DTV_TEST_AVAILABLE                      0x0003100000
#define SCALER_DNR_BUF_DTV_TEST_ADR                            0x0003100000  //Alignment 0x00010
#define SCALER_DNR_BUF_DTV_TEST_GAP_CHK                        0x0000000000
#define SCALER_DNR_BUF_DTV_TEST_LEN                            0x0000600000
#define SCALER_DNR_BUF_DTV_TEST_MEMORY_TYPE                    (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* TTXBUF_START   */
//co_buffer L3
#define TTXBUF_START_AVAILABLE                                 0x0003700000
#define TTXBUF_START_ADR                                       0x0003700000  //Alignment 0x00010
#define TTXBUF_START_GAP_CHK                                   0x0000000000
#define TTXBUF_START_LEN                                       0x00000D4800
#define TTXBUF_START_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* CCVBI_RINGBUFFER_START   */
//co_buffer L3
#define CCVBI_RINGBUFFER_START_AVAILABLE                       0x00037D4800
#define CCVBI_RINGBUFFER_START_ADR                             0x00037D4800  //Alignment 0x00008
#define CCVBI_RINGBUFFER_START_GAP_CHK                         0x0000000000
#define CCVBI_RINGBUFFER_START_LEN                             0x0000000100
#define CCVBI_RINGBUFFER_START_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* DTVCC_BLOCK0_START   */
//co_buffer L3
#define DTVCC_BLOCK0_START_AVAILABLE                           0x00037D4900
#define DTVCC_BLOCK0_START_ADR                                 0x00037D4900  //Alignment 0x00008
#define DTVCC_BLOCK0_START_GAP_CHK                             0x0000000000
#define DTVCC_BLOCK0_START_LEN                                 0x000000C000
#define DTVCC_BLOCK0_START_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* DTVCC_BLOCK1_START   */
//co_buffer L3
#define DTVCC_BLOCK1_START_AVAILABLE                           0x00037E0900
#define DTVCC_BLOCK1_START_ADR                                 0x00037E0900  //Alignment 0x00008
#define DTVCC_BLOCK1_START_GAP_CHK                             0x0000000000
#define DTVCC_BLOCK1_START_LEN                                 0x0000001000
#define DTVCC_BLOCK1_START_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* DTVCC_PES_START   */
//co_buffer L3
#define DTVCC_PES_START_AVAILABLE                              0x00037E1900
#define DTVCC_PES_START_ADR                                    0x00037E1900  //Alignment 0x00008
#define DTVCC_PES_START_GAP_CHK                                0x0000000000
#define DTVCC_PES_START_LEN                                    0x0000001000
#define DTVCC_PES_START_MEMORY_TYPE                            (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* DTVCC_QUEUE_START   */
//co_buffer L3
#define DTVCC_QUEUE_START_AVAILABLE                            0x00037E2900
#define DTVCC_QUEUE_START_ADR                                  0x00037E2900  //Alignment 0x00008
#define DTVCC_QUEUE_START_GAP_CHK                              0x0000000000
#define DTVCC_QUEUE_START_LEN                                  0x00000A0000
#define DTVCC_QUEUE_START_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* CC608MVD_RINGBUFFER_START   */
//co_buffer L3
#define CC608MVD_RINGBUFFER_START_AVAILABLE                    0x0003882900
#define CC608MVD_RINGBUFFER_START_ADR                          0x0003882900  //Alignment 0x00020
#define CC608MVD_RINGBUFFER_START_GAP_CHK                      0x0000000000
#define CC608MVD_RINGBUFFER_START_LEN                          0x0000004000
#define CC608MVD_RINGBUFFER_START_MEMORY_TYPE                  (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* CC708MVD_RINGBUFFER_START   */
//co_buffer L3
#define CC708MVD_RINGBUFFER_START_AVAILABLE                    0x0003886900
#define CC708MVD_RINGBUFFER_START_ADR                          0x0003886900  //Alignment 0x00020
#define CC708MVD_RINGBUFFER_START_GAP_CHK                      0x0000000000
#define CC708MVD_RINGBUFFER_START_LEN                          0x0000004800
#define CC708MVD_RINGBUFFER_START_MEMORY_TYPE                  (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* CCMVD_CACHE_BUFFER   */
//co_buffer L3
#define CCMVD_CACHE_BUFFER_AVAILABLE                           0x000388B100
#define CCMVD_CACHE_BUFFER_ADR                                 0x000388B100  //Alignment 0x00008
#define CCMVD_CACHE_BUFFER_GAP_CHK                             0x0000000000
#define CCMVD_CACHE_BUFFER_LEN                                 0x0000002000
#define CCMVD_CACHE_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* CC608_DISPBUFFER_START   */
//co_buffer L3
#define CC608_DISPBUFFER_START_AVAILABLE                       0x000388D100
#define CC608_DISPBUFFER_START_ADR                             0x000388D100  //Alignment 0x00008
#define CC608_DISPBUFFER_START_GAP_CHK                         0x0000000000
#define CC608_DISPBUFFER_START_LEN                             0x0000002000
#define CC608_DISPBUFFER_START_MEMORY_TYPE                     (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* TCVT_BUFFER_START   */
//co_buffer L3
#define TCVT_BUFFER_START_AVAILABLE                            0x000388F100
#define TCVT_BUFFER_START_ADR                                  0x000388F100  //Alignment 0x00020
#define TCVT_BUFFER_START_GAP_CHK                              0x0000000000
#define TCVT_BUFFER_START_LEN                                  0x0000001000
#define TCVT_BUFFER_START_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* CVCT_BUFFER_START   */
//co_buffer L3
#define CVCT_BUFFER_START_AVAILABLE                            0x0003890100
#define CVCT_BUFFER_START_ADR                                  0x0003890100  //Alignment 0x00020
#define CVCT_BUFFER_START_GAP_CHK                              0x0000000000
#define CVCT_BUFFER_START_LEN                                  0x0000001000
#define CVCT_BUFFER_START_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* EVENTDB_SDRAM   */
//co_buffer L3
#define EVENTDB_SDRAM_AVAILABLE                                0x0003891100
#define EVENTDB_SDRAM_ADR                                      0x0003891100  //Alignment 0x00020
#define EVENTDB_SDRAM_GAP_CHK                                  0x0000000000
#define EVENTDB_SDRAM_LEN                                      0x0000500000
#define EVENTDB_SDRAM_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* EPGEXTDB_SDRAM   */
//co_buffer L3
#define EPGEXTDB_SDRAM_AVAILABLE                               0x0003D91100
#define EPGEXTDB_SDRAM_ADR                                     0x0003D91100  //Alignment 0x00008
#define EPGEXTDB_SDRAM_GAP_CHK                                 0x0000000000
#define EPGEXTDB_SDRAM_LEN                                     0x0000000000
#define EPGEXTDB_SDRAM_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* SI_MONITOR_DB   */
//co_buffer L3
#define SI_MONITOR_DB_AVAILABLE                                0x0003D91100
#define SI_MONITOR_DB_ADR                                      0x0003D91100  //Alignment 0x00008
#define SI_MONITOR_DB_GAP_CHK                                  0x0000000000
#define SI_MONITOR_DB_LEN                                      0x000000E000
#define SI_MONITOR_DB_MEMORY_TYPE                              (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* SRV_NAME_BUF   */
//co_buffer L3
#define SRV_NAME_BUF_AVAILABLE                                 0x0003D9F100
#define SRV_NAME_BUF_ADR                                       0x0003D9F100  //Alignment 0x00008
#define SRV_NAME_BUF_GAP_CHK                                   0x0000000000
#define SRV_NAME_BUF_LEN                                       0x0000002000
#define SRV_NAME_BUF_MEMORY_TYPE                               (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* EIT_PF_STRING_BUF   */
//co_buffer L3
#define EIT_PF_STRING_BUF_AVAILABLE                            0x0003DA1100
#define EIT_PF_STRING_BUF_ADR                                  0x0003DA1100  //Alignment 0x00010
#define EIT_PF_STRING_BUF_GAP_CHK                              0x0000000000
#define EIT_PF_STRING_BUF_LEN                                  0x0000004000
#define EIT_PF_STRING_BUF_MEMORY_TYPE                          (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* PVR_READ_SDRAM   */
//co_buffer L3
#define PVR_READ_SDRAM_AVAILABLE                               0x0003DA5100
#define PVR_READ_SDRAM_ADR                                     0x0003DA5100  //Alignment 0x00010
#define PVR_READ_SDRAM_GAP_CHK                                 0x0000000000
#define PVR_READ_SDRAM_LEN                                     0x0000000000
#define PVR_READ_SDRAM_MEMORY_TYPE                             (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* PVR_READ_METADATA_BUFFER   */
//co_buffer L3
#define PVR_READ_METADATA_BUFFER_AVAILABLE                     0x0003DA5100
#define PVR_READ_METADATA_BUFFER_ADR                           0x0003DA5100  //Alignment 0x00010
#define PVR_READ_METADATA_BUFFER_GAP_CHK                       0x0000000000
#define PVR_READ_METADATA_BUFFER_LEN                           0x0000000000
#define PVR_READ_METADATA_BUFFER_MEMORY_TYPE                   (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* PVR_WRITE_METADATA_BUFFER   */
//co_buffer L3
#define PVR_WRITE_METADATA_BUFFER_AVAILABLE                    0x0003DA5100
#define PVR_WRITE_METADATA_BUFFER_ADR                          0x0003DA5100  //Alignment 0x00010
#define PVR_WRITE_METADATA_BUFFER_GAP_CHK                      0x0000000000
#define PVR_WRITE_METADATA_BUFFER_LEN                          0x0000000000
#define PVR_WRITE_METADATA_BUFFER_MEMORY_TYPE                  (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

/* PVR_BROWSER_BUFFER   */
//co_buffer L3
#define PVR_BROWSER_BUFFER_AVAILABLE                           0x0003DA5100
#define PVR_BROWSER_BUFFER_ADR                                 0x0003DA5100  //Alignment 0x00010
#define PVR_BROWSER_BUFFER_GAP_CHK                             0x0000000000
#define PVR_BROWSER_BUFFER_LEN                                 0x0000000000
#define PVR_BROWSER_BUFFER_MEMORY_TYPE                         (MIU0 | SW | CO_BUF_L3 | WRITE_BACK)

//MIU_1_START
//MIU_END
#define MIU0_END_ADR                                           0x0003F80000
