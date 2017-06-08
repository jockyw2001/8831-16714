

##################################################################
# ATSC - Compile option
##################################################################
#CC_TVOPTS += -DATSC_CC=DTV_CC

##################################################################
# LIB
##################################################################

ifneq ($(BUILD_TARGET),BLOADER_SYSTEM)
ifneq ($(MEMORY_SIZE),MEMORY_32MB)	
DTV_LIB += \
	$(ROOT)/core/middleware/tts/libtts.a 	
endif
endif

##################################################################
# APP - FILES
##################################################################

APP_FILES +=        \
        $(ROOT)/core/api/dtv_atsc/msAPI_Tuner_ATSC.c              \
        $(ROOT)/core/api/msAPI_Scan_ATSC.c                        \
        $(TVAP)/atsc/app/MAPP_ChannelChange_ATSC.c               \
        $(TVAP)/atsc/app/MApp_ChannelProc_ATSC.c                \
        $(TVAP)/atsc/app/MApp_DataBase_ATSC.c                   \
        $(TVAP)/atsc/app/MApp_EpgDB_ATSC.c                         \
	    $(TVAP)/atsc/app/MApp_HuffmanDecode.c                     \
        $(TVAP)/atsc/app/MApp_MultiTasks_ATSC.c			        \
        $(TVAP)/atsc/app/MApp_Psip.c                              \
        $(TVAP)/atsc/app/MApp_SaveData_ATSC.c                      \
        $(TVAP)/atsc/app/MApp_Scan_ATSC.c                          \
        $(TVAP)/atsc/app/MApp_ScanMenu_ATSC.c                      \
        $(TVAP)/atsc/app/MApp_VChip.c                              \
        $(TVAP)/dvb/ui2/MApp_ZUI_ACTchannelinfo_ATSC.c                   \
        $(TVAP)/dvb/ui2/MApp_UiMenuFunc_ATSC.c                            \
        $(TVAP)/dvb/ui2/MApp_UiMenuStr_ATSC.c                            \
        $(TVAP)/dvb/ui2/MApp_ZUI_ACTepg_ATSC.c                         \
		$(TVAP)/dvb/ui2/MApp_ZUI_ACTinstall_ATSC.c                     \
		$(TVAP)/dvb/ui2/MApp_Install_Main_ATSC.c                       \

		
ifneq ($(MEMORY_SIZE),MEMORY_32MB)		
APP_FILES +=        \
		$(ROOT)/core/middleware/tts/tts_wrapper.c                  \
		$(TVAP)/atsc/app/MApp_TTSControlHandler.c                  
endif		

INC_DIR  += \
        -I$(ROOT)/core/api/dtv_atsc/                            \
        -I$(TVAP)/atsc/app/                                 \
        -I$(TVAP)/atsc/app/include                          \

ifneq ($(MEMORY_SIZE),MEMORY_32MB)		  
INC_DIR  += \
        -I$(ROOT)/core/middleware/tts/include                
endif		

LINT_INC  += \
        $(TVAP)/atsc/app/                                   \
        $(TVAP)/atsc/app/include                            \

