#ifndef _CONFIG_DEPEND_ON_CHIP_H_
#define _CONFIG_DEPEND_ON_CHIP_H_


// This file is used to config the option depend on chip

//------------------------------------------------------------------------------

#define PM_RUNS_IN_FLASH        0x01    // PM runs in SPI Flash
#define PM_RUNS_IN_51           0x02    // PM runs in PM51
#define PM_RUNS_IN_CACHE        0x03    // PM runs in MIPS L1 Cache

#if ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)   \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EDEN)    \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)    \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)    \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)  \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)  \
    )
    #define PM_RUNS_IN      PM_RUNS_IN_FLASH

#elif ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD)   \
      ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NIKON)   \
      ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
      ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NUGGET)   \
      )
    #define PM_RUNS_IN      PM_RUNS_IN_51

#elif ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)   \
      ||0                                           \
      )
    #define PM_RUNS_IN      PM_RUNS_IN_CACHE

#else

    //#define PM_RUNS_IN      PM_RUNS_IN_51

#endif

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)  \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)  \
   )
    #define ENABLE_PM_WAKEUP_DVI_PORT_SEPERATE  1
#else
    #define ENABLE_PM_WAKEUP_DVI_PORT_SEPERATE  0
#endif

//-------------------------------------------------------------------------

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)     \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)   \
   )
    #define AUDIO_CPU_IS_R2         1
#else
    #define AUDIO_CPU_IS_R2         0
#endif

//-------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)\
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)\
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)\
   )
    #define SUPPORT_VDEC_2_0        1
#else
    #define SUPPORT_VDEC_2_0        0
#endif

    #define ENABLE_VDEC_2_0         SUPPORT_VDEC_2_0
    #define VDEC_BIN_IS_FW_VPU      SUPPORT_VDEC_2_0

//-------------------------------------------------------------------------

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)     \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)     \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)   \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)   \
   ) // HEVC ==> H265
    #define CHIP_SUPPORT_HEVC       1
#else
    #define CHIP_SUPPORT_HEVC       0
#endif

    #define ENABLE_H265             CHIP_SUPPORT_HEVC

//------------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD)  \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NIKON)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NUGGET)   \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)     \
   )
    #define STC64_SUPPORT           1
#else
    #define STC64_SUPPORT           0
#endif

//-------------------------------------------------------------------------
#ifdef VQ_ENABLE
    #define ENABLE_DMX_VQ_BUF       1

#else
  #if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)      \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)      \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)      \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD)    \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NIKON)      \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NUGGET)     \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)       \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EDEN)       \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)     \
     )
    #define ENABLE_DMX_VQ_BUF   1

  #elif( (CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA ) \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)     \
     )
    #define ENABLE_DMX_VQ_BUF   0

  #else
    #error
  #endif
#endif

//----------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)        \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)        \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)         \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EDEN)         \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)       \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)       \
   )
    #define CONTROL_DNR_BUF_RULE_2015       1

#elif( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)      \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD)    \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA)       \
       )
    #define CONTROL_DNR_BUF_RULE_2015       0

#else
    #error
#endif

//----------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)     \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)   \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)   \
   )
    #define HDMI_HPD_INVERT_FLAG_SEPERATE   1
#else
    #define HDMI_HPD_INVERT_FLAG_SEPERATE   0
#endif

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER) )
    #define CEC_VERSION_USING   CEC_OLD_VERSION
#else
    #define CEC_VERSION_USING   CEC_NEW_VERSION
#endif

//----------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)     \
   )
    #define SUPPORT_HDMI_COLOR_YUV_420      1
#else
    #define SUPPORT_HDMI_COLOR_YUV_420      0
#endif

//----------------------------------------------------------------------------
#if( (MEMORY_MAP > MMAP_32MB)&&(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY))
    #define ENABLE_VDEC_USE_DIFFERENT_BUFFER_IN_DTV   1
#else
    #define ENABLE_VDEC_USE_DIFFERENT_BUFFER_IN_DTV   0
#endif

//----------------------------------------------------------------------------

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) )
    #define MAYA_PATCH_04   0 // Flash write protect range => full range
#else
    #define MAYA_PATCH_04   0 // Flash write protect range => full range
#endif

//----------------------------------------------------------------------------

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) )
 #ifdef _MSD91H0JN2_H_   //vx1 case1 in APN
    #define _VX1_LANE_ORDER_1BLK_   0xDCBA, 0x3210, 0x7654, 0x98
    #define _VX1_LANE_ORDER_2BLK_   0xDCBA, 0x6420, 0x7531, 0x98
 #else
  #ifdef _MSD91H1BN2_H_   //vx1 case3 in APN
    #define _VX1_LANE_ORDER_1BLK_   0x2108, 0x493A, 0xB765, 0xDC
    #define _VX1_LANE_ORDER_2BLK_   0x4208, 0x196A, 0xB753, 0xDC
  #else
    #define _VX1_LANE_ORDER_1BLK_   #error "Package doesn't Support Vx1"
    #define _VX1_LANE_ORDER_2BLK_   #error "Package doesn't Support Vx1"
  #endif
 #endif
#endif

//----------------------------------------------------------------------------
#if (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)
    #define SUPPORT_VX1_OUTPUT          (1) //Chip capability that support vx1 output or not  1: support 0: not support
#else
    #define SUPPORT_VX1_OUTPUT          (0) //Chip capability that support vx1 output or not  1: support 0: not support
#endif

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) )
    #define SUPPORT_4K2K_OUTPUT         1
#else
    #define SUPPORT_4K2K_OUTPUT         0
#endif


#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)   \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)   \
   )
    #define SUPPORT_4K_TO_2K_CONVERT    1
#else
    #define SUPPORT_4K_TO_2K_CONVERT    0
#endif

//----------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) )
    #define HDMI_NEED_SET_PACKAGE_TYPE  1
    #define SUPPORT_HDMI_2_0            1
#else
    #define HDMI_NEED_SET_PACKAGE_TYPE  0
    #define SUPPORT_HDMI_2_0            0
#endif

//----------------------------------------------------------------------------

#if (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)
    #define ENABLE_EDID_SWITCH      ENABLE
#else
    #define ENABLE_EDID_SWITCH      DISABLE
#endif

//----------------------------------------------------------------------------
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) )
    #define SUPPORT_MM_PHOTO_4K     1
#else
    #define SUPPORT_MM_PHOTO_4K     0
#endif

//----------------------------------------------------------------------------

#define INTERN_DVBT_LOAD_CODE_FROM_ARRAY    0 // File xxx.dat
#define INTERN_DVBT_LOAD_CODE_FROM_BIN      1
#define INTERN_DVBT_LOAD_CODE_FROM_DRIVER   2 // Utopia

#if ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_EULER)   \
    ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_EMERALD) \
    )
    #define INTERN_DVBT_LOAD_CODE_FROM_SEL  INTERN_DVBT_LOAD_CODE_FROM_ARRAY

#elif( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)  \
     ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)  \
     )
    #define INTERN_DVBT_LOAD_CODE_FROM_SEL  INTERN_DVBT_LOAD_CODE_FROM_DRIVER

#else
    #define INTERN_DVBT_LOAD_CODE_FROM_SEL  INTERN_DVBT_LOAD_CODE_FROM_BIN
#endif

//----------------------------------------------------------------------------

//#define INTERN_DVBC_LOAD_CODE_FROM_ARRAY    0 // File xxx.dat
#define INTERN_DVBC_LOAD_CODE_FROM_BIN      1
#define INTERN_DVBC_LOAD_CODE_FROM_DRIVER   2 // Utopia

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MILAN)    \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MULAN)    \
   )
    #define INTERN_DVBC_LOAD_CODE_FROM_SEL  INTERN_DVBC_LOAD_CODE_FROM_DRIVER
#else
    #define INTERN_DVBC_LOAD_CODE_FROM_SEL  INTERN_DVBC_LOAD_CODE_FROM_BIN
#endif

//----------------------------------------------------------------------------
// bing.zhao
/*******************************
PATCH  for NASA  DTMB  steps
[step 0/4] Create global var "g_Ext_Sync" and "u8Change_ExtSync_Count"
[step 1/4]  When get program timeout ,then DMX_Flowset(Ext_sync = FALSE) , repeat search RF
[step 2/4]  When search next RF ,DMX_Flowset(Ext_sync = TRUE)
[step 3/4]  Save g_Ext_Sync to DataBase
[step 4/4]  When channelChange ,loda Ext_Sync , DMX_Flowset(Ext_sync )
*********************************/
#if ( (CHIP_FAMILY_TYPE == CHIP_FAMILY_NASA) )
    #define PATCH_FOR_HW_LIMIT_EXT_SYNC     1
#else
    #define PATCH_FOR_HW_LIMIT_EXT_SYNC     0
#endif

//----------------------------------------------------------------------------

#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA)     \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY)   \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_MELODY)   \
   )
    #define VIF_SCOPE_1M            1
#else
    #define VIF_SCOPE_1M            0
#endif


//----------------------------------------------------------------------------

// Check if can enable ENABLE_SECURITY_R2
#if( (CHIP_FAMILY_TYPE == CHIP_FAMILY_MAYA) \
   ||(CHIP_FAMILY_TYPE == CHIP_FAMILY_WHISKY) )

#else
    #if( ENABLE_SECURITY_R2 )
        #error "This chip unsupport SECURITY_R2"
    #endif
#endif

//----------------------------------------------------------------------------

#endif // _CONFIG_DEPEND_ON_CHIP_H_

