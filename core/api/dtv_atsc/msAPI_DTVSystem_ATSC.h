#ifndef _MSAPI_DTVSYSTEM_ATSC_H_
#define _MSAPI_DTVSYSTEM_ATSC_H_


#include "Board.h"

#if( ENABLE_ATSC )

//#include "msAPI_DTVSystem.h"

typedef struct
{
    U8 u8Test;

    U8 _u8CurrentRRT_Dimension;
    U8 _u8CurrentRRT_Option;

    U8 fEnableSignalCheck;

} StuDtvAtscInfo;

//=======================================================

extern StuDtvAtscInfo g_stDtvAtscInfo;

// todo: rename
//extern MS_U8 fEnableSignalCheck;
#define fEnableSignalCheck  (g_stDtvAtscInfo.fEnableSignalCheck)

#ifdef sTriviewSupportOSDLanguage
														 //LANGUAGE_ENGLISH
														 //LANGUAGE_FRENCH
														 //LANGUAGE_SPANISH
                             //LANGUAGE_GERMAN
                             //LANGUAGE_ITALIAN
                             //LANGUAGE_PORTUGUESE
                             //LANGUAGE_RUSSIAN
                             //LANGUAGE_CHINESE
                             //LANGUAGE_CHINESE_TRAD                             
                             //LANGUAGE_JAPAN                             
#define MENU_LANGUAGE       (((stGenSetting.g_SysSetting.Language == LANGUAGE_ENGLISH) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_FRENCH) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_SPANISH) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_GERMAN) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_ITALIAN) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_PORTUGUESE) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_RUSSIAN) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_CHINESE)) ? stGenSetting.g_SysSetting.Language : LANGUAGE_ENGLISH)//current menu language
#else
#define MENU_LANGUAGE       (((stGenSetting.g_SysSetting.Language == LANGUAGE_ENGLISH) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_FRENCH) \
                             || (stGenSetting.g_SysSetting.Language == LANGUAGE_SPANISH)) ? stGenSetting.g_SysSetting.Language : LANGUAGE_ENGLISH)//current menu language
#endif
//=======================================================


void msAPI_DTVSystem_ATSC_Init(void);


#endif // ENABLE_ATSC

#endif // _MSAPI_DTVSYSTEM_ATSC_H_

