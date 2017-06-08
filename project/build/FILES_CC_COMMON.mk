

##################################################################
# CC - Compile option
##################################################################
ifeq ($(ATSC_CC),DTV_CC)
CC_TVOPTS += -DATSC_CC=DTV_CC
else ifeq ($(ATSC_CC),BRA_CC)
CC_TVOPTS += -DATSC_CC=BRA_CC
else
CC_TVOPTS += -DATSC_CC=ATV_CC
endif

##################################################################
# LIB
##################################################################
DTV_LIB += \
    $(MIDDLE_LIB_PATH)/closedcaption/lib/libcc_decode_english_hf_aeonr2_nos.a \
    $(MIDDLE_LIB_PATH)/closedcaption/lib/libcc_monitor_hf_aeonr2_nos.a \
    $(MIDDLE_LIB_PATH)/closedcaption/lib/libcc_render_gegop_hf_aeonr2_nos.a
ifeq ($(ATSC_CC),BRA_CC)
DTV_LIB += \
    $(MIDDLE_LIB_PATH)/closedcaption/lib/libcc_decode_brazil_hf_aeonr2_nos.a
endif

##################################################################
# CC - FILES
##################################################################
ifneq ($(ATSC_CC),BRA_CC)
CC_FILES += \
        $(ROOT)/core/middleware/closedcaption/atsc/mapp_closedcaption.c
else
CC_FILES += \
        $(ROOT)/core/middleware/closedcaption/brazil/mapp_closedcaption_brazil.c
endif
CC_FILES += \
        $(ROOT)/core/middleware/closedcaption/lib/msAPI_cc_sysinfo.c   \
        $(ROOT)/core/middleware/closedcaption/lib/msAPI_cc_parser.c    \

INC_DIR  += \
        -I$(ROOT)/core/middleware/closedcaption/lib/include     \
        -I$(ROOT)/core/middleware/closedcaption/atsc			\

LINT_INC  += \
        $(ROOT)/core/middleware/closedcaption/lib/include     \
        $(ROOT)/core/middleware/closedcaption/atsc			\

