ifeq ($(_FILES_DVB_COMMON_),)
_FILES_DVB_COMMON_=ENABLE

#=============================================================================================

SI_FILES += \
        $(ROOT)/core/middleware/si/dvb/mapp_demux_if.c                 \
        $(ROOT)/core/middleware/si/dvb/mapp_si_if.c                     \
        $(ROOT)/core/middleware/si/dvb/mapp_si_util.c                   \


INC_DIR  += \
        -I$(ROOT)/core/middleware/si/dvb/include                    \
        -I$(ROOT)/core/middleware/epg/dvb/include                   \


LINT_INC  += \
        $(ROOT)/core/middleware/si/dvb/include                      \


#=============================================================================================

ifeq ($(AEON_TYPE),aeonR2)
DTV_LIB += \
    $(MIDDLE_LIB_PATH)/si/dvb/libdvbsi_aeonR2.a                   \
    $(MIDDLE_LIB_PATH)/epg/dvb/libdvbepgdb_aeonR2.a               \

else

DTV_LIB += \
    $(MIDDLE_LIB_PATH)/si/dvb/libdvbsi_mips.a                       \
    $(MIDDLE_LIB_PATH)/epg/dvb/libdvbepgdb_mips.a                   \

endif

#=============================================================================================

endif # _FILES_DVB_COMMON_