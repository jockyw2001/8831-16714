CC_TVOPTS += \
    -DOBA2=0                                                        \
    -DMSOS_TYPE_NOS                                                 \
    -DS4LITE_ENHANCE                                                \
    -DENABLE_DMP=0                                                  \
    -DENABLE_DTV=1                                                  \
    -DENABLE_CAPE=0                                                 \
    -DENABLE_VE=0                                                   \
    -DENABLE_PIP=0                                                  \
    -DFOR_BENCH_CODE=0                                              \
    -DENCODE_AUDIO_AP=0                                             \
    -DENABLE_DEMO_FINE_TUNE=0                                       \
    -DATSC_CC=0                                                     \
    -DATSC_VCHIP=0                                                  \
    -DENABLE_3D=0                                                   \
    -DENABLE_FORCE_MM_HD_FB=0                                       \
    -DENABLE_MIRROR=0                                               \
    -DENABLE_NTSC_SYSTEM=0                                          \
    -DENABLE_BOOTING_MUSIC=0                                        \
    -DENABLE_S2=0                                                   \
#   -DENABLE_MHEG5                                                  \
#   -DENABLE_PVR=0                                                  \
#   -DAP_COWORK
#   -DENABLE_BT                                                     \
#   -DNETWORK_CONFIG                                                \
#   -DMAC_ADDRESS                                                   \
#   -DENABLE_KTV                                                    \
#   -DENABLE_RSS                                                    \
#   -DENABLE_YOUTUBE                                                \
#   -DENABLE_GYM                                                    \
#   -DENABLE_YOUTUBE
#aeon1/aeonR2/aeon2
AEON_TYPE=aeonR2

#ENABLE_DTV flag is use for ATV_MM model that no need the DTV input source, but need MVD for MM
##################################################################
# Bootloader
##################################################################
BL_SRC_FILE = \
				$(ROOT)/boot/euler/init_euler.c \
##################################################################
# Driver / API
##################################################################
DRV_FILES += \
        $(ROOT)/core/driver/sys/euler/drvUartDebug.c                  \
        $(ROOT)/core/driver/sys/euler/drvI2C.c                        \
        $(ROOT)/core/driver/sys/euler/SysInit.c                       \
        $(ROOT)/core/driver/sys/euler/drvISR.c                        \
        $(ROOT)/core/driver/sys/euler/drvPadConf.c                    \
        $(ROOT)/core/driver/sys/euler/drvInit.c                       \
        $(ROOT)/core/driver/usb/euler/drvUsbHostLib.c                 \

        #$(ROOT)/core/driver/miu/euler/drvmiu.c                       \


API_FILES += \
        $(ROOT)/core/api/msAPI_MMap.c                               \
        $(ROOT)/core/api/msAPI_RAM.c                                \
        $(ROOT)/core/api/msAPI_Timer.c                              \
        $(ROOT)/core/api/msAPI_MIU.c                                \
        $(ROOT)/core/api/msAPI_Tuner.c                              \
        $(ROOT)/core/api/msAPI_BDMA.c                               \
        $(ROOT)/core/api/msAPI_Memory.c                             \
        $(ROOT)/core/api/msAPI_DrvInit.c                            \
        $(ROOT)/core/api/msAPI_Power.c                              \
        $(ROOT)/core/api/msAPI_Global.c                             \
        $(ROOT)/core/api/IOUtil.c                                   \
        $(ROOT)/core/api/msAPI_BulkFileSystem.c                     \
        $(ROOT)/core/api/msAPI_PVRFileSystem.c                      \
        $(ROOT)/core/api/msAPI_Bootloader.c                         \
        $(ROOT)/core/api/msAPI_Font.c                               \
        $(ROOT)/core/api/msAPI_OSD_Resource.c                       \
        $(ROOT)/core/api/msAPI_OSD.c                                \
        $(ROOT)/core/api/scaler_front/apiXC_Sys.c                   \
        $(ROOT)/core/api/scaler_front/msAPI_Mode.c                  \
        $(ROOT)/core/api/msAPI_DTVSystem.c                          \
        $(ROOT)/core/api/msAPI_FreqTableDTV.c                       \
        $(ROOT)/core/api/msAPI_Flash.c                              \
        $(ROOT)/core/api/msAPI_MHL.c                                \

FS_FILES += \
        $(ROOT)/core/api/n51fs/msAPI_FCtrl.c                        \
        $(ROOT)/core/api/n51fs/msAPI_FAT.c                          \
        $(ROOT)/core/api/n51fs/FAT_Cache.c                          \
        $(ROOT)/core/api/n51fs/FSUtil.c                             \
        $(ROOT)/core/api/n51fs/msAPI_MSDCtrl.c                      \
        $(ROOT)/core/api/n51fs/msAPI_FSEnv.c                        \
        $(ROOT)/core/api/n51fs/msAPI_N51FS.c                         \
        $(ROOT)/core/api/n51fs/N51FS_File.c                          \
        $(ROOT)/core/api/n51fs/N51FS_Index.c                         \
        $(ROOT)/core/api/n51fs/N51FS_Bitmap.c                        \
        $(ROOT)/core/api/msAPI_FS_SysInfo.c                         \

SI_FILES += \
        $(ROOT)/core/middleware/si/dvb/mapp_si_if.c                 \
        $(ROOT)/core/middleware/si/dvb/mapp_si_util.c                 \
        $(ROOT)/core/middleware/demux/msAPI_demux.c                 \
        $(ROOT)/core/middleware/si/dvb/mapp_demux_if.c                 \

OAD_FILES += \
        $(ROOT)/core/middleware/oad/dvb/msAPI_oad_parser.c              \

USB_UPGRADE += \
        $(ROOT)/core/middleware/usbupgrade/mw_usbdownload.c             \
        $(ROOT)/core/middleware/usbupgrade/mapp_swupdate.c             \

UTIL_FILES += \
        $(ROOT)/core/middleware/mwutil/mw_debug.c                   \
        $(ROOT)/core/util/util_minidump.c                           \
        $(ROOT)/core/util/util_symbol.c                             \
        $(ROOT)/core/util/autotest.c                                \
        $(ROOT)/core/util/mstar_debug.c                             \
        $(ROOT)/core/util/uartdebug.c                               \
        $(ROOT)/core/util/util_checkversion.c                       \


SRC_FILE += \
        $(DRV_FILES)                                                \
        $(FS_FILES)                                                 \
        $(SI_FILES)                                                 \
        $(API_FILES)                                                \
        $(OAD_FILES)                                                \
        $(USB_UPGRADE)                                              \
        $(UTIL_FILES)                                               \


INC_DIR  += \
        -I$(ROOT)/project/image                                     \
        -I$(ROOT)/project/mmap                                      \
        -I$(ROOT)/core/driver/interface                             \
        -I$(ROOT)/core/driver/sys/euler/include                       \
        -I$(ROOT)/core/driver/sc/euler/include                        \
        -I$(ROOT)/core/bin/euler/audio                                \
        -I$(ROOT)/core/util/include                                 \
        -I$(ROOT)/core/api/include                                  \
        -I$(ROOT)/core/middleware/teletext/include                  \
        -I$(ROOT)/core/middleware/teletext/core/include                  \
        -I$(ROOT)/core/middleware/cni/include                       \
        -I$(ROOT)/core/api/n51fs/include                            \
        -I$(ROOT)/core/api/audio/include                            \
        -I$(ROOT)/core/api/utl                                      \
        -I$(ROOT)/core/middleware/ci/include                        \
        -I$(ROOT)/core/middleware/mwutil/include                    \
        -I$(ROOT)/core/middleware/mheg5/include                     \
        -I$(ROOT)/core/middleware/huffman/dvb/include               \
        -I$(ROOT)/core/middleware/si/dvb/include                    \
        -I$(ROOT)/core/middleware/epg/dvb/include                   \
        -I$(ROOT)/core/middleware/subtitle/include                  \
        -I$(ROOT)/core/middleware/oad/dvb/include                   \
        -I$(ROOT)/core/middleware/demux/include                     \
        -I$(ROOT)/core/middleware/multimedia/include                \
        -I$(ROOT)/core/middleware/include                           \
        -I$(ROOT)/core/middleware/usbupgrade/include                \
        -I$(ROOT)/include/std                                       \

LINT_INC  += \
        $(ROOT)/project/image                                       \
        $(ROOT)/core/bin/euler/audio                                  \
        $(ROOT)/core/util/include                                   \
        $(ROOT)/core/api/include                                    \
        $(ROOT)/core/middleware/teletext/include                    \
        $(ROOT)/core/middleware/cni/include                         \
        $(ROOT)/core/api/n51fs/include                              \
        $(ROOT)/core/api/audio/include                              \
        $(ROOT)/core/middleware/mheg5/include                       \
        $(ROOT)/core/middleware/huffman/dvb/include                 \
        $(ROOT)/core/middleware/si/dvb/include                      \
        $(ROOT)/core/middleware/demux/include                       \
        $(ROOT)/core/middleware/multimedia/include                  \
        $(ROOT)/core/middleware/subtitle/include          \

##################################################################
# TV-AP
##################################################################
TVAP = $(ROOT)/tv-ap

APP_FILES += \
        $(TVAP)/dvb/app/MApp_USBDownload.c                         \
        $(TVAP)/dvb/app/MApp_MassStorage.c                         \
        $(TVAP)/common/bootloader/MApp_BL_Init.c                \
        $(TVAP)/common/bootloader/MApp_BL_Main.c                           \
        $(TVAP)/common/bootloader/MApp_BL_Demux.c                \
        $(TVAP)/common/bootloader/MApp_BL_SI.c                           \
        $(TVAP)/dvb/app/MApp_OAD.c                                 \
        $(TVAP)/dvb/app/MApp_Scan.c                                \
        $(TVAP)/dvb/app/MApp_EpgTimer.c                            \
        $(TVAP)/dvb/app/MApp_DataBase.c                            \
        $(TVAP)/dvb/app/MApp_SI_Parse.c                            \
        $(TVAP)/dvb/app/MApp_GlobalFunction.c                      \

PROJS_FILES += \
        $(ROOT)/project/image/dvbt/InfoBlock.c                     \
        $(ROOT)/project/image/imginfo.c                            \

CHIP_FILES += \
        $(ROOT)/chip/euler/device/gpio/GPIO.c                         \
        $(ROOT)/core/driver/power/euler/drvPower_cus.c                \
        $(ROOT)/core/driver/power/euler/drvPower.c                    \
        $(ROOT)/chip/euler/color/color.c                              \

DEVICES_FILES += \
        $(ROOT)/device/ir/euler/msIR.c                                \
        $(ROOT)/device/flash/msFlash.c                              \
        $(ROOT)/device/if_demodulator/IF_Demodulator.c              \
        $(ROOT)/device/cofdm/COFDM_Demodulator.c                    \
        $(ROOT)/device/tuner/Tuner.c                                \
        $(ROOT)/device/panel/Panel.c                                \
        $(ROOT)/device/panel_dft/DemoFineTune.c                     \
        $(ROOT)/device/mhl/Mhl.c                                    \

# Source files
SRC_FILE += \
        $(APP_FILES)                                               \
        $(PROJS_FILES)                                             \
        $(CHIP_FILES)                                              \
        $(DEVICES_FILES)                                           \

# Add "Header (include) file" directories here ...
INC_DIR  += \
        -I$(ROOT)/project/boarddef                                 \
        -I$(ROOT)/project/swdef                                    \
        -I$(ROOT)/project/image/dvbt                               \
        -I$(ROOT)/project/image/bininfo/euler                       \
        -I$(ROOT)/project/mmap                                     \
        -I$(ROOT)/chip/euler/color/include                          \
        -I$(ROOT)/chip/euler/device/gpio                            \
        -I$(ROOT)/chip/euler/image                                  \
        -I$(ROOT)/device/panel                                     \
        -I$(ROOT)/device/panel/include                             \
        -I$(ROOT)/device/panel_dft                                  \
        -I$(ROOT)/device/flash                                     \
        -I$(ROOT)/device/keypad/euler                                 \
        -I$(ROOT)/device/ir/euler                                     \
        -I$(ROOT)/device/hdmiswitch                                \
        -I$(ROOT)/device/cofdm                                     \
        -I$(ROOT)/device/qam                                       \
        -I$(ROOT)/device/tuner                                     \
        -I$(ROOT)/device/if_demodulator                            \
        -I$(ROOT)/device/include                                   \
        -I$(ROOT)/device/audioamp                                  \
        -I$(ROOT)/core/drv_bsp/include                             \
        -I$(TVAP)/common/app/include                               \
        -I$(TVAP)/common/zui/include                               \
	    -I$(TVAP)/common/dmp/include                               \
        -I$(TVAP)/common/bootloader/include                        \
        -I$(TVAP)/dvb/app/include                                  \
        -I$(TVAP)/dvb/ui2/include                                  \
        -I$(TVAP)/dvb/ui2/osdcomposer/include                      \
        -I$(TVAP)/dvb/ui2/res1366x768x565/osdcomposer/include      \
        -I$(ROOT)/device/mhl                                       \


LINT_INC  += \
        $(ROOT)/project/boarddef                                   \
        $(ROOT)/project/swdef                                      \
        $(ROOT)/project/image/dvbt                                 \
        $(ROOT)/project/image/bininfo/euler                           \
        $(ROOT)/project/mmap                                       \
        $(ROOT)/chip/euler/device/gpio                                \
        $(ROOT)/chip/euler/image                                    \
        $(ROOT)/chip/euler/color/include                            \
        $(ROOT)/device/panel                                       \
        $(ROOT)/device/panel/include                               \
        $(ROOT)/device/flash                                       \
        $(ROOT)/device/keypad/euler                                   \
        $(ROOT)/device/ir/euler                                       \
        $(ROOT)/device/hdmiswitch                                  \
        $(ROOT)/device/cofdm                                       \
        $(ROOT)/device/qam                                         \
        $(ROOT)/device/tuner                                       \
        $(ROOT)/device/if_demodulator                              \
        $(ROOT)/device/include                                     \
        $(ROOT)/device/audioamp                                    \
        $(TVAP)/dvb/app/include                                    \
        $(TVAP)/dvb/ui2/include                                    \
        $(TVAP)/dvb/ui2/osdcomposer/include                        \
        $(TVAP)/dvb/ui2/res1366x768x565/osdcomposer/include        \
        $(ROOT)/device/mhl                                         \

ifeq ($(AEON_TYPE),aeonR2)
LDLIB += -Wl,--whole-archive $(ROOT)/core/lib/euler/libprana_euler_aeonR2.a -Wl,--no-whole-archive
else
LDLIB += -Wl,--whole-archive $(ROOT)/core/lib/euler/libprana_euler_a.a -Wl,--no-whole-archive
endif

DRV_LIB_PATH   = $(ROOT)/core/driver
API_LIB_PATH   = $(ROOT)/core/api
ifeq ($(AEON_TYPE),aeonR2)
DRV_BSP_PATH   = $(ROOT)/core/drv_bsp/euler_nos_r2m/lib
else
DRV_BSP_PATH   = $(ROOT)/core/drv_bsp/euler_nos/lib
endif
MIDDLE_LIB_PATH   = $(ROOT)/core/middleware

DTV_LIB += \
    $(DRV_BSP_PATH)/libdrvIR.a                                          \
    $(DRV_BSP_PATH)/libapiGFX.a                                         \
    $(DRV_BSP_PATH)/libapiGOP.a                                         \
    $(DRV_BSP_PATH)/libdrvSEM.a                                         \
    $(DRV_BSP_PATH)/libdrvGPIO.a                                        \
    $(DRV_BSP_PATH)/libdrvSERFLASH.a                                    \
    $(DRV_BSP_PATH)/libdrvCPU.a                                         \
    $(DRV_BSP_PATH)/libdrvPWM.a                                         \
    $(DRV_BSP_PATH)/libdrvBDMA.a                                        \
    $(DRV_BSP_PATH)/libdrvPM.a                                          \
    $(DRV_BSP_PATH)/libdrvMMIO.a                                        \
    $(DRV_BSP_PATH)/libdrvUART.a                                        \
    $(DRV_BSP_PATH)/libdrvMIU.a                                         \
    $(DRV_BSP_PATH)/libdrvUSB_HOST_P1.a                                 \
    $(DRV_BSP_PATH)/libdrvUSB_HOST_P2.a                                 \
    $(DRV_BSP_PATH)/libdrvUSB_HID_P1.a                                  \
    $(DRV_BSP_PATH)/libdrvUSB_HID_P2.a                                  \
    $(DRV_BSP_PATH)/libdrvSYS.a                                         \
    $(DRV_BSP_PATH)/libdrvIRQ.a                \
    $(DRV_BSP_PATH)/libMsOS.a                  \
    $(DRV_BSP_PATH)/libapiDMX.a                \
    $(DRV_BSP_PATH)/libapiPNL.a                \
    $(DRV_BSP_PATH)/libapiXC.a                 \
    $(DRV_BSP_PATH)/libapiSWI2C.a              \
    $(DRV_BSP_PATH)/libdrvMSPI.a               \


#$(DRV_BSP_PATH)/libdrvPCMCIA.a --unsupported in this project--         \

#Middleware libraries
DTV_LIB += \
    $(MIDDLE_LIB_PATH)/si/dvb/libdvbsi_aeonR2.a                   \
    $(MIDDLE_LIB_PATH)/epg/dvb/libdvbepgdb_aeonR2.a               \
    $(MIDDLE_LIB_PATH)/oad/dvb/libdvboad_aeonR2.a                 \




ENABLE_HK_MP4=0
ENABLE_HK_DRM_GENCODE=0

BIN_INFO = $(ROOT)/project/image/bininfo/euler/BinInfo.h

REBUILD_FILES=$(TVAP)/dvb/ui2/MApp_ZUI_ACTmenufunc.c

include project/build/FILES_COMMON_EULER.mk

#DTV_LIB += \
#    $(COMMON_DTV_LIB)

