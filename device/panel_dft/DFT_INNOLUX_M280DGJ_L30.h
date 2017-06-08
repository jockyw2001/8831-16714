//******************************************************************************
// COPYRIGHT (C) Digital View Limited 2017.
//
// All rights reserved. This document contains proprietary and
// confidential information of the Digital View Limited. This
// document is not to be copied in whole or part. Digital View
// assumes no responsibility for the consequences of use of such
// information nor for any infringement of patents or other rights of
// third parties which may result from its use. No license is granted by
// implication or otherwise under any patent or patent rights of
// Digital View.
//==============================================================================
//
// MODULE:      DFT_INNOLUX_M280DGJ_L30.h
//
// USAGE:       Definition of Innolux M280DGJ-L30 panel color temperature and other parameters
//
//******************************************************************************

#define FINE_TUNE      "DFT_INNOLUX_M280DGJ_L30"

//*************************************************************************
//              Local Definition
//*************************************************************************
//#ifdef sTriviewColorFineTune  //Default Color Temperature Select
#define DYNAMIC_BACKLIGHT           100
#define DYNAMIC_CONTRAST            70
#define DYNAMIC_BRIGHTNESS          60
#define DYNAMIC_SATURATION          50
#define DYNAMIC_SHARPNESS           50//60
#define DYNAMIC_HUE                 50//60
#define DYNAMIC_COLOR_TEMP          MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

#define STANDARD_BACKLIGHT          100//80 // 100
#define STANDARD_CONTRAST           50
#define STANDARD_BRIGHTNESS         50//48
#define STANDARD_SATURATION         50
#define STANDARD_SHARPNESS          50
#define STANDARD_HUE                50
#define STANDARD_COLOR_TEMP         MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

//HDMI STANARD
#define STANDARD_HDMI_BACKLIGHT     100
#define STANDARD_HDMI_CONTRAST      50
#define STANDARD_HDMI_BRIGHTNESS    50//48
#define STANDARD_HDMI_SATURATION    50//48
#define STANDARD_HDMI_SHARPNESS     50
#define STANDARD_HDMI_HUE           50
#define STANDARD_COLOR_HDMI_TEMP    MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

//AV STANDARD
#define STANDARD_AV_BACKLIGHT       100
#define STANDARD_AV_CONTRAST        50
#define STANDARD_AV_BRIGHTNESS      50//48
#define STANDARD_AV_SATURATION      50//48
#define STANDARD_AV_SHARPNESS       50//50//60
#define STANDARD_AV_HUE             50
#define STANDARD_COLOR_AV_TEMP      MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

//YPBPR STANDARD
#define STANDARD_YPBPR_BACKLIGHT    100
#define STANDARD_YPBPR_CONTRAST     50
#define STANDARD_YPBPR_BRIGHTNESS   50//48
#define STANDARD_YPBPR_SATURATION   50
#define STANDARD_YPBPR_SHARPNESS    50
#define STANDARD_YPBPR_HUE          50
#define STANDARD_COLOR_YPBPR_TEMP   MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

//ATV PAL STANDARD
#define STANDARD_ATV_BACKLIGHT      100
#if (FRONTEND_IF_DEMODE_TYPE == MSTAR_VIF_MSB1210)        // GEM_SYNC_0815
#define STANDARD_ATV_CONTRAST       50//PQ for Gemini
#define STANDARD_ATV_BRIGHTNESS     50//48//PQ for Gemini
#define STANDARD_ATV_SATURATION     50//PQ for Gemini
#else
#define STANDARD_ATV_CONTRAST       50
#define STANDARD_ATV_BRIGHTNESS     50//48
#define STANDARD_ATV_SATURATION     50
#endif
#define STANDARD_ATV_SHARPNESS      50
#define STANDARD_ATV_HUE            50
#define STANDARD_COLOR_ATV_TEMP     MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

//SV STANDARD
#define STANDARD_SV_BACKLIGHT       100
#define STANDARD_SV_CONTRAST        50
#define STANDARD_SV_BRIGHTNESS      50//48
#define STANDARD_SV_SATURATION      50
#define STANDARD_SV_SHARPNESS       50
#define STANDARD_SV_HUE             50
#define STANDARD_COLOR_SV_TEMP      MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM

#define MILD_BACKLIGHT              100//50 // 100
#define MILD_CONTRAST               45//50
#define MILD_BRIGHTNESS             40//50
#define MILD_SATURATION             50//40 // 50
#define MILD_SHARPNESS              50
#define MILD_HUE                    50
#define MILD_COLOR_TEMP             MS_COLOR_TEMP_USER//MS_COLOR_TEMP_MEDIUM//XX_COLOR_TEMP_WARM

//------------------------------------------------------------------------------
// Color Temperature
//------------------------------------------------------------------------------
//x : 283 , y : 297
#define INIT_VIDEO_COLOR_TEMP_COOL_R            128	//MingYuan Color Temperature
#define INIT_VIDEO_COLOR_TEMP_COOL_G            122
#define INIT_VIDEO_COLOR_TEMP_COOL_B            128
//x : 299 , y : 315
#define INIT_VIDEO_COLOR_TEMP_NORMAL_R          128
#define INIT_VIDEO_COLOR_TEMP_NORMAL_G          117
#define INIT_VIDEO_COLOR_TEMP_NORMAL_B          115
//x : 313 , y : 329
#define INIT_VIDEO_COLOR_TEMP_WARM_R            128
#define INIT_VIDEO_COLOR_TEMP_WARM_G            113
#define INIT_VIDEO_COLOR_TEMP_WARM_B            105

#define INIT_VIDEO_COLOR_TEMP_USER_R            0x80
#define INIT_VIDEO_COLOR_TEMP_USER_G            0x80
#define INIT_VIDEO_COLOR_TEMP_USER_B            0x80

//Ray CTP 2017.05.18: Define default color temperature for 5000K, 6500K,7500K and 9300K
//Define value = display value + 28
#define INIT_VIDEO_COLOR_TEMP_5000K_R            127
#define INIT_VIDEO_COLOR_TEMP_5000K_G            110
#define INIT_VIDEO_COLOR_TEMP_5000K_B            98

#define INIT_VIDEO_COLOR_TEMP_6500K_R            123
#define INIT_VIDEO_COLOR_TEMP_6500K_G            120
#define INIT_VIDEO_COLOR_TEMP_6500K_B            119

#define INIT_VIDEO_COLOR_TEMP_7500K_R            123
#define INIT_VIDEO_COLOR_TEMP_7500K_G            123
#define INIT_VIDEO_COLOR_TEMP_7500K_B            127

#define INIT_VIDEO_COLOR_TEMP_9300K_R            113
#define INIT_VIDEO_COLOR_TEMP_9300K_G            114
#define INIT_VIDEO_COLOR_TEMP_9300K_B            128



#define INIT_VIDEO_COLOR_TEMP_USER_R_SCALE      0x80 //must refer INIT_VIDEO_COLOR_TEMP_USER_R, for example: 0x80 -> 0x32
#define INIT_VIDEO_COLOR_TEMP_USER_G_SCALE      0x80 //must refer INIT_VIDEO_COLOR_TEMP_USER_G, for example: 0x80 -> 0x32
#define INIT_VIDEO_COLOR_TEMP_USER_B_SCALE      0x80 //must refer INIT_VIDEO_COLOR_TEMP_USER_B, for example: 0x80 -> 0x32


#if ENABLE_DLC

#define DLC_ALGORITHM_OLD                 0
#define DLC_ALGORITHM_NEW                 1

#define DLC_PARAMETER_ALGORITHM_MODE       DLC_ALGORITHM_NEW //DLC_ALGORITHM_OLD

#if DLC_PARAMETER_ALGORITHM_MODE   //for NEW DLC ALGORITHM
#include "New_NoOS_DLC.h"


#else  //for OLD DLC ALGORITHM
#define DLC_PARAMETER_L_L_U                5 // default value: 10
#define DLC_PARAMETER_L_L_D                5 // default value: 10
#define DLC_PARAMETER_L_H_U                5 // default value: 10
#define DLC_PARAMETER_L_H_D                5 // default value: 10
#define DLC_PARAMETER_S_L_U                128 // default value: 128 (0x80)
#define DLC_PARAMETER_S_L_D                128 // default value: 128 (0x80)
#define DLC_PARAMETER_S_H_U                128 // default value: 128 (0x80)
#define DLC_PARAMETER_S_H_D                128 // default value: 128 (0x80)
#define DLC_PARAMETER_PURE_IMAGE_MODE      E_XC_DLC_PURE_IMAGE_LINEAR_CURVE // Compare difference of max and min bright
#define DLC_PARAMETER_LEVEL_LIMIT          0 // n = 0 ~ 4 => Limit n levels => ex. n=2, limit 2 level 0xF7, 0xE7
#define DLC_PARAMETER_AVG_DELTA            0 // n = 0 ~ 50, default value: 12
#define DLC_PARAMETER_AVG_DELTA_STILL      0 // n = 0 ~ 15 => 0: disable still curve, 1 ~ 15: enable still curve
#define DLC_PARAMETER_FAST_ALPHA_BLENDING  31 // min 17 ~ max 32
#define DLC_PARAMETER_Y_AVG_THRESHOLD_L    32  // default value: 0
#define DLC_PARAMETER_Y_AVG_THRESHOLD_H    150 // default value: 128
#define DLC_PARAMETER_BLE_POINT            48 // n = 24 ~ 64, default value: 48
#define DLC_PARAMETER_WLE_POINT            48 // n = 24 ~ 64, default value: 48
#define DLC_PARAMETER_ENABLE_BLE           0 // 1: enable; 0: disable
#define DLC_PARAMETER_ENABLE_WLE           0 // 1: enable; 0: disable

#define DLC_CGC_ENABLE                      0 // 1: enable; 0: disable
#define DLC_CGC_CGAIN_OFFSET                0 // -31 ~ 31 (bit7 = minus, ex. 0x88 => -8)
#define DLC_CGC_CGAIN_LIMIT_H               0x00 // 0x00~0x6F
#define DLC_CGC_CGAIN_LIMIT_L               0x00 // 0x00~0x10
#define DLC_CGC_YC_SLOPE                    0x01 // 0x01~0x20
#define DLC_CGC_Y_TH                        0x08 // 0x01~0x0A


#define DLC_PARAMETER_CURVE_MODE           E_XC_DLC_CURVE_MODE_BY_MIX//E_XC_DLC_PURE_IMAGE_DO_NOTHING
#define DLC_PARAMETER_Y_AVG_THRESHOLD_M    70 //99//64 // 180 // 128
#define DLC_PARAMETER_CURVE_MIXALPHA       90//72 //55//38 // 180 // 128

#define DLC_PARAMETER_SepPoint_H           200//188
#define DLC_PARAMETER_SepPoint_L           80
#define DLC_PARAMETER_BLEStartPointTH      640 //768
#define DLC_PARAMETER_BLEEndPointTH        320 //420
#define DLC_PARAMETER_DLC_CurveDiff_L_TH   56
#define DLC_PARAMETER_DLC_CurveDiff_H_TH   148
#define DLC_PARAMETER_BLE_Slop_Point1      1032 //1032
#define DLC_PARAMETER_BLE_Slop_Point2      1172 //1196
#define DLC_PARAMETER_BLE_Slop_Point3      1242 //1312
#define DLC_PARAMETER_BLE_Slop_Point4      1324 //1460
#define DLC_PARAMETER_BLE_Slop_Point5      1396 //1630
#define DLC_PARAMETER_BLE_Dark_Slop_Min    1172//1200
#define DLC_PARAMETER_DLC_CurveDiff_Coring_TH 2
#define DLC_PARAMETER_DLC_FAST_ALPHA_BLENDING_MIN 1
#define DLC_PARAMETER_DLC_FAST_ALPHA_BLENDING_MAX 128
#define DLC_PARAMETER_DLC_FlICKER_ALPHA    96
#define DLC_PARAMETER_DLC_YAVG_L_TH        56
#define DLC_PARAMETER_DLC_YAVG_H_TH        136

#define DLC_PARAMETER_DLC_DiffBase_L        4
#define DLC_PARAMETER_DLC_DiffBase_M        14
#define DLC_PARAMETER_DLC_DiffBase_H        20

#endif


extern MS_U8 mApi_DLC_GetLumaCurve(MS_U8 u8Index);
extern MS_U8 mApi_DLC_GetLumaCurve2_a(MS_U8 u8Index);
extern MS_U8 mApi_DLC_GetLumaCurve2_b(MS_U8 u8Index);
extern MS_U8 mApi_DLC_GetDlcHistogramLimitCurve(MS_U8 u8Index);
#endif // #if ENABLE_DLC


