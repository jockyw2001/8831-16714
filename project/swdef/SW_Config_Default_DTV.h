#ifndef _SW_CONFIG_DEFAULT_DTV_H_
#define _SW_CONFIG_DEFAULT_DTV_H_


//******************************************************************************
// DTV option...

#include "SW_Config_Default_DTV_SYSTEM.h"


#if( !ENABLE_DVBT )
    #undef ENABLE_DVB_T2
    #define ENABLE_DVB_T2       0
#endif

#ifndef ENABLE_DVB_T2
    #define ENABLE_DVB_T2       DISABLE
#endif


#ifndef ENABLE_T_C_COMBO
  #if 1 // NEW
    #define ENABLE_T_C_COMBO    ((ENABLE_DVBT||ENABLE_DTMB)&&ENABLE_DVBC)
  #else
      #if ENABLE_DVBC_PLUS_DTMB_CHINA_APP
        #define ENABLE_T_C_COMBO    ENABLE
      #else
        //#define ENABLE_T_C_COMBO    ((FRONTEND_SECOND_DEMOD_TYPE==EMBEDDED_DVBC_DEMOD)&&(FRONTEND_DEMOD_TYPE==EMBEDDED_DVBT_DEMOD))
        #define ENABLE_T_C_COMBO    ( (DTV_SYSTEM_SEL== DTV_SYSTEM_DVBT_Plus_DVBC)\
                                    ||(DTV_SYSTEM_SEL== DTV_SYSTEM_DVBC_Plus_DTMB)\
                                    )
      #endif

  #endif
#endif


//========================================================
#define ENABLE_DEMOD_DVBT   ENABLE_DVBT
#define ENABLE_DEMOD_DVBT2  ENABLE_DVB_T2
#define ENABLE_DEMOD_DTMB   ENABLE_DTMB
#define ENABLE_DEMOD_DVBC   ENABLE_DVBC
#define ENABLE_DEMOD_DVBS   ENABLE_S2
#define ENABLE_DEMOD_ATSC   ENABLE_ATSC
#define ENABLE_DEMOD_ISDBT  ENABLE_ISDBT

/*
#ifndef DEMOD_DVBT_USE_UTOPIA
    #define DEMOD_DVBT_USE_UTOPIA   1
#endif
*/

#ifndef DEMOD_ATSC_USE_UTOPIA
  #if(ENABLE_ATSC)
    #define DEMOD_ATSC_USE_UTOPIA   1
  #else
    #define DEMOD_ATSC_USE_UTOPIA   0
  #endif
#endif

#ifndef DEMOD_USE_UTOPIA
    #define DEMOD_USE_UTOPIA    (  DEMOD_ATSC_USE_UTOPIA    \
                                || DEMOD_DVBT_USE_UTOPIA    \
                                || DEMOD_DVBC_USE_UTOPIA    \
                                || DEMOD_DTMB_USE_UTOPIA    \
                                || DEMOD_ISDBT_USE_UTOPIA )
#endif

//----------------------------------------------------------------------------

#ifndef ENABLE_ASTRA_HD
    #define ENABLE_ASTRA_HD   0
#endif

#define ASTRA_HD_ENABLE ENABLE_ASTRA_HD

#ifndef ENABLE_MHEG5_SIINFO
    #define ENABLE_MHEG5_SIINFO    0
#endif
#define MHEG5_SIINFO_ENABLE   ENABLE_MHEG5_SIINFO

//----------------------------------------------------------------------------

#ifndef ENABLE_CI
    #define ENABLE_CI                   DISABLE
#endif

#ifndef ENABLE_CI_PLUS
    #define ENABLE_CI_PLUS              DISABLE
#endif

#ifndef MHEG5_ENABLE
    #define MHEG5_ENABLE                DISABLE
#endif

#ifndef NORDIG_FUNC
    #if(ENABLE_DVB)
        #define NORDIG_FUNC ENABLE
    #else
        #define NORDIG_FUNC DISABLE
    #endif
#endif

#ifndef ENABLE_DVBC_USE_INDEPENDENT_UI_INPUT_SOURCE
    #define ENABLE_DVBC_USE_INDEPENDENT_UI_INPUT_SOURCE    DISABLE
#endif

#ifndef DVB_T_C_DIFF_DB
    #if( ENABLE_DVBC_USE_INDEPENDENT_UI_INPUT_SOURCE )
        #define DVB_T_C_DIFF_DB    ENABLE
    #else
        #define DVB_T_C_DIFF_DB    DISABLE
    #endif
#endif

#ifndef ENABLE_T_C_CHANNEL_MIX
    #define ENABLE_T_C_CHANNEL_MIX  0
#endif

#ifndef ENABLE_API_DTV_SYSTEM
    #define ENABLE_API_DTV_SYSTEM   ENABLE_DVB
#endif

#ifndef ENABLE_API_DTV_SYSTEM_2015
    #define ENABLE_API_DTV_SYSTEM_2015  1//DISABLE
#endif

#ifndef ENABLE_DTV_DB_DUMP
    #define ENABLE_DTV_DB_DUMP      DISABLE
#endif

#ifndef ENABLE_DVBT_1000_LCN
    #define ENABLE_DVBT_1000_LCN        0
#endif
//----------------------------------------------------------------------------


#endif // _SW_CONFIG_DEFAULT_DTV_H_

