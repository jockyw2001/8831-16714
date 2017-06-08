
##################################################################
# Driver - Common
##################################################################
DRV_FILES +=    \
        $(ROOT)/core/driver/hal/hal_misc.c              \
		$(ROOT)/core/driver/r2/drvAeonR2.c				\           

INC_DIR  += \
        -I$(ROOT)/core/driver/hal                       \
		-I$(ROOT)/core/driver/r2                        \
        -I$(ROOT)/core/driver/sys                       \
	    
LINT_INC  += \
            $(ROOT)/core/driver/hal                     \
			$(ROOT)/core/driver/r2                      \
			$(ROOT)/core/driver/sys                   	\
            
ifneq ($(BUILD_TARGET),BLOADER_SYSTEM)

DRV_FILES +=    \
        $(ROOT)/core/driver/r2/r2_backtrace.c           \

INC_DIR  += \
        
		    
LINT_INC  += \


endif

##################################################################
# API - Common
##################################################################
ifneq ($(BUILD_TARGET),BLOADER_SYSTEM)
API_FILES += \
        $(ROOT)/core/api/database/msAPI_DB_Factory.c                \
        $(ROOT)/core/api/database/msAPI_DB_GEN.c                \
        $(ROOT)/core/api/panel_misc/msAPI_OverDrive.c               \
        $(ROOT)/core/api/panel_misc/msAPI_PnlBin.c                  \
        $(ROOT)/core/api/panel_misc/msAPI_TCON.c                    \
        $(ROOT)/core/api/TestPattern/msAPI_TestPattern.c            \
        $(ROOT)/core/api/dtv_dvbs/msAPI_DTVSystem_DVBS.c            \
        
endif

API_FILES += \
        $(ROOT)/core/api/database/msAPI_DB_CH.c                \
        $(ROOT)/core/api/demod/msAPI_Demod.c                    \
        $(ROOT)/core/api/dtv_common/msAPI_DTV_Common.c            \
		$(ROOT)/core/api/dtv_db/msAPI_DTV_DB.c              \
		$(ROOT)/core/api/dtv_db/msAPI_DTV_DB_Dump.c            \
        $(ROOT)/core/api/dtv_atsc/msAPI_DTVSystem_ATSC.c            \
        $(ROOT)/core/api/msAPI_Dynamic_EDID.c               \


UTIL_FILES += \
        $(ROOT)/core/util/Mstar_USBScript.c                             \
        
INC_DIR  += \
            -I$(ROOT)/core/api/database                         \
		    -I$(ROOT)/core/api/panel_misc                       \
		    -I$(ROOT)/core/api/scaler_back                      \
		    -I$(ROOT)/core/api/TestPattern                      \
		    -I$(ROOT)/core/api/demod                            \
		    -I$(ROOT)/device/cofdm/Dish                         \
		    -I$(ROOT)/core/api/dtv_common                        \
		    -I$(ROOT)/core/api/dtv_atsc                        \
		    -I$(ROOT)/core/api/dtv_dvbs                        \
			-I$(ROOT)/core/api/dtv_db                        \
			-I$(ROOT)/core/middleware/si                        \


LINT_INC  += \
            $(ROOT)/core/api/database                           \
            $(ROOT)/core/api/panel_misc                         \
            $(ROOT)/core/api/scaler_back                        \
            $(ROOT)/core/api/TestPattern                        \
            $(ROOT)/core/api/demod                              \
            $(ROOT)/device/cofdm/Dish                         \
		    $(ROOT)/core/api/dtv_common                        \
		    $(ROOT)/core/api/dtv_atsc                        \
		    $(ROOT)/core/api/dtv_dvbs                        \
			$(ROOT)/core/api/dtv_db                        \

##################################################################
# APP - Common
##################################################################

ifneq ($(BUILD_TARGET),BLOADER_SYSTEM)
APP_FILES +=        \
        $(TVAP)/common/app/MApp_AutoTest.c						\
        $(TVAP)/common/app/MApp_AutoTest_Utility.c						\
        $(TVAP)/common/app/MApp_AutoTest_Subtitle_Cmd.c						\
        $(TVAP)/common/app/MApp_AutoTest_OSD_Dump_Cmd.c						\
        $(TVAP)/common/app/MApp_AutoTest_SI_Cmd.c						\
        $(TVAP)/common/app/MApp_AutoTest_Audio_Cmd.c						\
        $(TVAP)/common/app/MApp_AutoTest_EPG_Cmd.c						\
        $(TVAP)/common/app/MApp_AutoTest_CI_Cmd.c						\
        $(TVAP)/common/app/MApp_AutoTest_Cus.c						    \
        $(TVAP)/common/app/MApp_MenuFunc.c						    \
        $(TVAP)/common/ui/MApp_UI_EventHandler.c				\
        $(TVAP)/common/app/MApp_KeyLogger.c								\
        $(TVAP)/dvb/app/MApp_DataBase_CH.c						\
        $(TVAP)/dvb/app/MApp_MenuFunc_DVB.c						\
        $(TVAP)/common/app/MApp_DataBase_Gen.c						\
        $(TVAP)/common/app/MApp_DataBase_Factory.c						\
        $(TVAP)/common/app/MApp_NoSignal_AutoSleep.c						\
        $(TVAP)/common/app/MApp_NoOperate_AutoSleep.c						\
        $(TVAP)/dvb/app/MApp_ParentalRating.c						\

endif

APP_FILES +=        \
        $(TVAP)/common/app/MApp_GlobalSetting.c						    \
        $(TVAP)/dvb/func/MApp_Func_Inputsource.c              \
        $(TVAP)/dvb/func/MApp_Func_Mainpage.c              \
        $(TVAP)/dvb/func/MApp_Func_AtvManualTuning.c              \
        $(TVAP)/dvb/func/MApp_Func_AudioVolume.c              \

INC_DIR  += \
            -I$(TVAP)/customer                       \
            -I$(TVAP)/dvb/func                       \
            -I$(TVAP)/dvb/func/include               \

LINT_INC  += \
        $(TVAP)/customer                            \
        $(TVAP)/dvb/func                            \
        $(TVAP)/dvb/func/include                    \

#==============================================================================
ifneq (, $(filter $(ATSC_CC),DTV_CC BRA_CC ATV_CC))
    include project/build/FILES_CC_COMMON.mk
endif

# Add file for ATSC
ifeq ($(ENABLE_ATSC),ENABLE)
    include project/build/FILES_ATSC_COMMON.mk
endif
