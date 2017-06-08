//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (¡§MStar Confidential Information¡¨) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_CIMMI_C

/********************************************************************************/
/*                            Header Files                                      */
/********************************************************************************/
#include <string.h>
#include <stdio.h>

#include "debug.h"

#include "sysinfo.h"
#include "msAPI_Global.h"
#include "msAPI_Flash.h"

#include "MApp_UiMenuDef.h"
#include "MApp_Subtitle.h"
#if MHEG5_ENABLE
#include "MApp_MHEG5_Main.h"
#endif
#include "MApp_Main.h"
#include "MApp_AnalogInputs.h"
#include "MApp_CIMMI.h"
#include "MApp_CIMMI_Private.h"
#include "MApp_TopStateMachine.h"
#include "MApp_ZUI_Main.h"
#include "ZUI_tables_h.inl"
#include "ZUI_exefunc.h"
#include "msAPI_MIU.h"
#include "msAPI_Timer.h"
#include "MApp_ChannelChange.h"
#include "MApp_ZUI_ACTeffect.h"
#include "MApp_SaveData.h"
#if ENABLE_PVR
#include "MApp_PVR.h"
#endif
#if (ENABLE_CI_PLUS)
#include "msAPI_OpCache.h"
#include "MApp_CharTable.h"
#include "mapp_si_util.h"
#include "MApp_TV.h"
#include "MApp_ZUI_ACTchlist.h"
#include "mapp_demux.h"
#include "MApp_Scan.h"
#include "MApp_ZUI_ACTinputsource.h"
#include "MApp_CADTV_Proc.h"
#include "MApp_MVDMode.h"
#include "MApp_Standby.h"
#include "MApp_ZUI_ACTcimmi.h"
#include "demodulator_T2.h"

#include "msAPI_DTVSystem.h"
#include "msAPI_FreqTableDTV.h"
#include "MApp_GlobalFunction.h"
#include "MApp_ChannelList.h"
#include "msAPI_ChProc.h"
#include "msAPI_Video.h"
#endif

#if(ENABLE_S2)
#include "apiDigiTuner.h"
#endif

#if (ENABLE_DTV)
/********************************************************************************/
/*                                 Macro                                        */
/********************************************************************************/
#define CIMMI_DEG_EN    0

#if CIMMI_DEG_EN
#define CIMMI_DBG(x)    x
#else
#define CIMMI_DBG(x)
#endif

#if (ENABLE_CI_PLUS)
#define CI_INVALID_OP_INFO_VERSION                  0xFF
#define CI_INVALID_OP_NIT_VERSION                   0xFF
#define SI_PMT_SECTION_MAX_LEN                      (1024)
#define CI_TUNING_MAX_TIME                          3000 //3s

#define CI_MEMORY_ALLOCATE( x )             msAPI_Memory_Allocate( x, BUF_ID_ITC )
#define CI_MEMORY_FREE( x )                 { msAPI_Memory_Free( x, BUF_ID_ITC ); x = NULL; }
#define MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(x)     {\
                                                        if (NULL != x.pu8TuneDescriptors)\
                                                        {\
                                                            CI_MEMORY_FREE(x.pu8TuneDescriptors);\
                                                        }\
                                                        memset(&(x), 0x00, sizeof(x));\
                                                    }
#endif

#if ENABLE_CI
/********************************************************************************/
/*                                 function                                        */
/********************************************************************************/
/******************************************************************************/
/*                                 External                                   */
/******************************************************************************/
#if MHEG5_ENABLE
    extern EN_MHEG5_STATE enMHEG5State;
#endif

//ZUI_TODO: extern void MApp_UiMenu_DrawMuteWin(void);
extern WORD CI_Cur_ServiceID;
extern WORD CI_PMT_ServiceID;
extern unsigned char g_activeMMI;
#if ENABLE_AUTOTEST
extern BOOLEAN g_bAutobuildDebug;
#endif
BOOL bIsMoreOpTune = FALSE;

#if( CHAKRA3_AUTO_TEST )
CIMMI_INFO *pMMIdup = 0;
#endif

/********************************************************************************/
/*                                 Local                                        */
/********************************************************************************/
//static U8 bCleanOsdBeforeMmi=1;
static U8 u8CardDetectCnt = 0;
static U8 u8CI_Channel_change = FALSE;
static U8 u8CI_Event = 0x00;
#if (ENABLE_CI_PLUS)
static U32 g_u32CurrentCicamId = INVALID_CICAMID;
static U32 g_u32OpCicamIdentifier = INVALID_CICAMID;
static BOOL g_bOpStatusHandlingSuspended = FALSE;
static U8 g_u8OpInfoVersion = CI_INVALID_OP_INFO_VERSION;
static U8 g_u8OpNitVersion = CI_INVALID_OP_NIT_VERSION;
static BOOL g_bOpEntitlementChange = FALSE;
static EN_DVB_TYPE g_u8OpTuneOriginalDtvRoute = EN_DVB_T_TYPE;
#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
static BOOL g_bIsHCNotifyServiceAndDoHss = FALSE;
#endif
static MS_TP_SETTING g_stCiTuneOriginalProgInfo;

static BOOL MApp_CI_EnterCIOpServiceMode(U8 u8Index);
static BOOL MApp_CI_ExitCIOpServiceMode(void);
#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
static void MApp_CI_CiEventCommandHcTune(void);
static void MApp_CI_CiEventCommandHcTuneBroadcastReq( void );
static void MApp_CI_CiEventCommandHcCicamPmtParse( void );
static void MApp_CI_CiEventCommandHcStreamPmtParse( void );
static void MApp_CI_CiEventCommandHcSiWakeUp( void );
static void MApp_CI_CiEventCommandCcPinReply( void );
static void MApp_CI_CiEventCallbackOpStatus( void );
static void MApp_CI_CiEventCallbackOpInfo( void );
static void MApp_CI_CiEventCommandOpNit( void );
static void MApp_CI_CiEventCommandOpSearchStatus( void );
static void MApp_CI_CiEventCommandOpNitCheck( void );
static void MApp_CI_HandleCiOpStatus( void );
static BOOL MApp_CI_UpdateCIOpInfo( CI_OP_INFO* stCiOpInfo );
static BOOL MApp_CI_GetOpCicamIdByIndex(U8 u8Index , U32* u32CicamId);
static BOOL MApp_CI_UpdateCICamNIT(U32 u32CicamId, U8 *pu8NitSection, U16 u16SecLen, U16 u16SecCount);
#endif
static BOOL MApp_CI_CiTuneProcess( void );
static BOOL MApp_CI_CiTuneInitialize( void );
static BOOL MApp_CI_CiTuneFilter( void );
static BOOL MApp_CI_CiTuneParsing( void );
static BOOL MApp_CI_CiTuneEnableFrontend( void );
#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
static void MApp_CI_DoCiTuneBackToOriginalProgram( void );
#endif
static BOOL MApp_CI_CiTuneParameterInvalidReply( void );
static BOOL MApp_CI_CiTuneUnsupportReply( void );
static BOOL MApp_CI_CiTuneSetMuxDVBT(const DESC_TERR_DEL_SYS* ustDesciptor);
#if(ENABLE_DVB_T2 == ENABLE)
static BOOL MApp_CI_CiTuneSetMuxDVBT2(const DESC_T2_DEL_SYS* ustDesciptor);
#endif
BOOL MApp_CI_CiTuneSetMuxDVBC(const DESC_CABLE_DEL_SYS* ustDesciptor);
#if (ENABLE_S2)
BOOL MApp_CI_CiTuneSetMuxDVBS(const DESC_SATELLITE_DEL_SYS *ustDesciptor);
BOOL MApp_CI_CiTuneSetMuxDVBS2(const DESC_SATELLITE_DEL_SYS *ustDesciptor);
#endif
#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
static void MApp_CI_DoCITuneParsePMTStartAVMonitor(BOOL bNotifyPMTUpdated);
static void MApp_CI_PMTSectionNotify(U8* pu8SectionData);
#endif
static BOOL MApp_CI_CiTuneSignalMonitor( void );
static BOOL MApp_CI_CiHcTuneSignalMonitor( BOOLEAN bLocked );
static BOOL MApp_CI_CiOpTuneSignalMonitor( BOOLEAN bLocked );
static void MApp_CI_InitCiVariables( void );
static void MApp_CI_CiEventCallbackSystemTimeUpdate( void );
#endif //(ENABLE_CI_PLUS)
/******************************************************************************/
/// DumpBuffer
/// Dump input buffer
/******************************************************************************/
#if 0
void DumpMMIBuffer(U8 *pBuf, U16 nBufSize)
{
    U16 i;
    CIMMI_DBG(printf("-------- pBuf:0x%08LX, Size:%04u--------------\n", (U32)pBuf, nBufSize));
    for(i=0; i<nBufSize; i++)
    {
        CIMMI_DBG(printf(" %02bX", *(pBuf+i)));
        if((i&0xF)==0xF)
        {
            CIMMI_DBG(putchar('\n'));
        }
    }
    CIMMI_DBG(putchar('\n'));
    for(i=0; i<20; i++)
    {
        CIMMI_DBG(putchar('\n'));
    }
    CIMMI_DBG(putchar('\n'));
}
#endif

BOOLEAN MMI_PrepareActiveMMI( void )
{
#if (MHEG5_ENABLE )
    if ( enMHEG5State == STATE_MHEG5_WAIT )
        return TRUE;
#endif

    if ( MApp_TopStateMachine_GetTopState()!=STATE_TOP_MENU //&& //ZUI: (enMenuFlowState != FS_MAIN_MENU)
         //ZUI_TODO: && (enMenuFlowState != FS_FACTORY_MENU)
         //(CI_Cur_ServiceID == CI_PMT_ServiceID)
       )
    {
        /*/ZUI_TODO:
        enUiMainMenuState = STATE_UIMENU_INIT;

        if ( enMenuMode == MENU_MODE )*/
        {
            if ( IsAnyTVSourceInUse() )
            {
                MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS);
                //ZUI_TODO: enMenuMode = IDLE_MODE;
            }
            else
            {
                MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS);
                //ZUI_TODO: enMenuMode = ANALOGINPUTS_MODE;
            }
        }
        /*/ZUI_TODO: else if ( enMenuMode == ANALOGINPUTS_MODE )
        {
            MApp_TopStateMachine_SetTopState(STATE_TOP_ANALOGINPUTS);
        }
        else
        */
        {
            MApp_TopStateMachine_SetTopState(STATE_TOP_DIGITALINPUTS);
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//////////////////////////////////////////////////////////
//2008/3/10: refine CI/MMI flow to independent MMI state...
//#include ".\..\..\..\Kernel\S3P\Driver\CI\include\drvCI_MMI.h"
EN_CIMMI_STATE enCIEvtState = STATE_CIMMI_EVENT_HANDLE;
EN_CIMMI_STATE enCIMMIState = STATE_CIMMI_INIT;

void MApp_CIMMI_ProcessUserInput(void)
{
#if ENABLE_CI_PLUS
    /* For item 24 of CI+ DTVL Certification, user can't change channel through P+/P-, EPG List, and etc. */
    if (TRUE == msAPI_CI_CU_GetState())
    {
        u8KeyCode = KEY_NULL;
    }
#endif
    switch ( u8KeyCode )
    {
        case KEY_CHANNEL_PLUS:
        case KEY_CHANNEL_MINUS:
#if ENABLE_HOTEL_MODE_FUNCTION
            if (HOTEL_INPUTMODE_FIX_IS_ON && (HOTEL_INPUTMODE_IS_TUNER == false))
            {
                u8KeyCode = KEY_NULL;
                break;
            }
#endif // ENABLE_HOTEL_MODE_FUNCTION

            if( IsSrcTypeDTV(SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW)) )
            {
                U16 u16TotalProNum;

                #if NORDIG_FUNC //for Nordig Spec v2.0
                u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)
                                            + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY)
                                            + msAPI_CM_CountProgram(E_SERVICETYPE_DATA, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                #else
                u16TotalProNum = msAPI_CM_CountProgram(E_SERVICETYPE_DTV, E_PROGACESS_INCLUDE_VISIBLE_ONLY)
                                            + msAPI_CM_CountProgram(E_SERVICETYPE_RADIO, E_PROGACESS_INCLUDE_VISIBLE_ONLY);
                #endif

                if(u16TotalProNum)
                {
                    enCIEvtState = STATE_CIMMI_CLEAN_UP;
                    u8CI_Channel_change=TRUE;
                }
                else
                {
                    enCIEvtState = STATE_CIMMI_CLEAN_UP;
                    u8KeyCode = KEY_NULL;
                }
            }
            else
            {
                    enCIEvtState = STATE_CIMMI_CLEAN_UP;
                    u8CI_Channel_change=TRUE;
            }

#if 0   // clean current MMI event; Move to Mapp_Tv.c
            if( (CI_EVENT_MMI_CLOSEMMI == u8CI_Event)||(CI_EVENT_MMI_MENU == u8CI_Event)
                ||(CI_EVENT_MMI_ENQ== u8CI_Event)||(CI_EVENT_MMI_LIST== u8CI_Event))
            {
                msAPI_CI_MMIDoneEvent(CIEvt);
            }
#endif
            msAPI_CI_MMIClose();//Send Close_CIMMI to CAM

            break;

        default:
            MApp_ZUI_ProcessKey(u8KeyCode);
            u8KeyCode = KEY_NULL;
            break;
    }
}

EN_RET MApp_CIMMI_Main(void)
{
    u8CI_Event = msAPI_CI_MMICheckEvent();
    EN_RET enRetVal = EXIT_NULL;

    //printf("MApp_CIMMI_Main %d %d\n", enCIEvtState, u8CI_Event);

    if(!msAPI_CI_CardDetect())
    {
        msAPI_CI_MMIDoneEvent(u8CI_Event);
        enCIEvtState = STATE_CIMMI_CLEAN_UP;
    }

    switch(enCIEvtState)
    {
        //Dispatch CI events
        case STATE_CIMMI_EVENT_HANDLE:
            switch(u8CI_Event)
            {
                //Draw CI MMI MSG box
                case CI_EVENT_MMI_ENQ:
                case CI_EVENT_MMI_MENU:
                case CI_EVENT_MMI_LIST:
                    enCIEvtState = enCIMMIState;
                    break;

                //If ZUI is running=> process key
                //If ZUI is not running => exit STATE_TOP_MMI in TopStateMachine
                case CI_EVENT_NONE:
                    if(MApp_ZUI_GetActiveOSD()!=E_OSD_CIMMI)
                        enRetVal = EXIT_CLOSE;
                    else
                    {
                        MApp_CIMMI_ProcessUserInput();
                    }
                    break;

                 //No need ZUI, process the CI events
                default:
                    enCIEvtState = STATE_CIMMI_WAIT;
                    break;
            }
            break;

        //Init ZUI
        case STATE_CIMMI_INIT:
            //_prev_type = EN_CIMMI_TYPE_NONE;

            MApp_ZUI_ACT_StartupOSD(E_OSD_CIMMI);
            if( msAPI_CI_GetCardState()==EN_NO_MODULE )
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CI_NO_MODULE_MSGBOX);
            else
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CI_LOAD_INFO_MSGBOX);

            enCIMMIState = STATE_CIMMI_INIT;
            break;

        //Wait ZUI MSG Box
        case STATE_CIMMI_MESSAGE_BOX:
            //note: don't polling CI status when message is shown...
            MApp_CIMMI_ProcessUserInput();
            break;

        //Process CI events
        case STATE_CIMMI_WAIT:
            {
                switch(u8CI_Event)
                {
                    case CI_EVENT_MMI_ENQ:
                    case CI_EVENT_MMI_MENU:
                    case CI_EVENT_MMI_LIST:
                        {
                            enCIMMIState = STATE_CIMMI_WAIT;
                            if (FALSE == MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_REPAINT_CIMMI_PAGE))
                            {
                                msAPI_CI_MMIDoneEvent(u8CI_Event);
                                enCIEvtState = STATE_CIMMI_CLEAN_UP;
                            }
                        }
                        break;
                    case CI_EVENT_MMI_CLOSE:
                        msAPI_CI_MMIDoneEvent(u8CI_Event);
                        enCIEvtState = STATE_CIMMI_CLEAN_UP;
                    case CI_EVENT_NONE:
                        MApp_CIMMI_ProcessUserInput();
                        break;

                    default:
                        msAPI_CI_MMIDoneEvent(u8CI_Event);
                        enCIEvtState = STATE_CIMMI_EVENT_HANDLE;
                        break;
                }
            }

            break;

        //Clean ZUI
        case STATE_CIMMI_CLEAN_UP:
            if(MApp_ZUI_GetActiveOSD()==E_OSD_CIMMI)
            {
                if( u8CI_Channel_change)
                {
                    MApp_ZUI_ACT_TransitionEffectBegin(EN_EFFMODE_PAGE_FADE_OUT, E_ZUI_STATE_TERMINATE);
                    u8CI_Channel_change=FALSE;
#if 0
                    msAPI_CI_MMIDoneEvent(u8CI_Event);  //if the previous state is not STATE_CIMMI_WAIT; Clean MMI event
#else
                    if( (CI_EVENT_MMI_CLOSE == u8CI_Event)||(CI_EVENT_MMI_MENU == u8CI_Event)
                                    ||(CI_EVENT_MMI_ENQ== u8CI_Event)||(CI_EVENT_MMI_LIST== u8CI_Event))
                    {
                        msAPI_CI_MMIDoneEvent(u8CI_Event);
                    }
#endif
                }
                else
                {
                    MApp_ZUI_ACT_ShutdownOSD();
                }
            }

            enCIEvtState = STATE_CIMMI_EVENT_HANDLE;
            enCIMMIState = STATE_CIMMI_INIT;
            enRetVal = EXIT_CLOSE;
            break;

        case STATE_CIMMI_GOTO_STANDBY:
            MApp_ZUI_ACT_ShutdownOSD();
            u8KeyCode = KEY_POWER;
            enRetVal = EXIT_GOTO_STANDBY;
            break;

        default:
            enCIEvtState = STATE_CIMMI_EVENT_HANDLE;
            break;
    }
    return enRetVal;
}

//2008/3/11: refine CI/MMI interfaces...
// NOTE: use fake data for simulation...
//     0=init
//     1=enq
//            <=  wait for user enq
//     2=menu
//            <=  wait for user select
//     3=title
//            <=  timeout, goto 0

BOOLEAN MMI_ParseInformaton(CIMMI_INFO * pInfo) //[out] pInfo for current displaying infomation.
{
    MMI_INFO *pMMI = msAPI_CI_MMIGetData();
#if( CHAKRA3_AUTO_TEST )
    pMMIdup = pInfo;
#endif
    U16 u16Len = 0, u16TmpLen = 0;
    U8 i, *pBuf = NULL;
    U8 u8Event = msAPI_CI_MMICheckEvent();

    if (NULL == pMMI)
        return TRUE;

    memset(pInfo,0,sizeof(CIMMI_INFO));

    //Use pMMI->enType to switch, not u8Event
    //CI lib only stores the last MMI event's MMI data
    //only the last MMI event's pMMI->enType is valid, others are EN_MMI_TYPE_NONE
    switch(pMMI->enType)
    {
        case EN_MMI_TYPE_ENQ:
            CIMMI_DBG(printf("ENQ\n"));
            pInfo->enType = EN_CIMMI_TYPE_ENQ;
            pInfo->content.enq_data.bBlindAns = pMMI->content.enq.bBlindAns;
            pInfo->content.enq_data.u8AnsLen = pMMI->content.enq.u8AnsLen;
            memcpy(pInfo->aTitleContent,pMMI->content.enq.pu8Enq,pMMI->content.enq.u8EnqLen);
            pInfo->aTitleContent[pMMI->content.enq.u8EnqLen] = '\0';
            msAPI_CI_RemoveControlByte(pInfo->aTitleContent,pMMI->content.enq.u8EnqLen + 1);
            CIMMI_DBG(printf("ENQ Str %s\n",pInfo->aTitleContent));
            break;
        case EN_MMI_TYPE_MENU:
            CIMMI_DBG(printf("MENU\n"));
            pInfo->enType = EN_CIMMI_TYPE_MENU;
            if (pMMI->content.menu.u16TitleLen)
            {
                //memcpy(pInfo->aTitleContent,pMMI->content.menu.pu8Title,pMMI->content.menu.u8TitleLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(pInfo->aTitleContent, pMMI->content.menu.u16TitleLen, pMMI->content.menu.pu8Title, pMMI->content.menu.u16TitleLen, pMMI->content.menu.pu8Title[0]);

                pInfo->aTitleContent[u8TmpLen] = '\0';
                //msAPI_CI_RemoveControlByte(pInfo->aTitleContent,pMMI->content.menu.u8TitleLen + 1);
                CIMMI_DBG(printf("Title: %s\n",pInfo->aTitleContent));
            }
            if (pMMI->content.menu.u16SubtitleLen)
            {
                //memcpy(pInfo->content.menu_data.au8Subtitle, pMMI->content.menu.pu8Subtitle,pMMI->content.menu.u8SubtitleLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(pInfo->content.menu_data.au8Subtitle, pMMI->content.menu.u16SubtitleLen, pMMI->content.menu.pu8Subtitle, pMMI->content.menu.u16SubtitleLen, pMMI->content.menu.pu8Subtitle[0]);
                pInfo->content.menu_data.au8Subtitle[u8TmpLen] = '\0';
                //msAPI_CI_RemoveControlByte(pInfo->content.menu_data.au8Subtitle,++pMMI->content.menu.u8SubtitleLen);
                CIMMI_DBG(printf("Subtitle: %s\n",pInfo->content.menu_data.au8Subtitle));
            }
            if (pMMI->content.menu.u16BottomLen)
            {
                //memcpy(pInfo->content.menu_data.au8Bottom, pMMI->content.menu.pu8Bottom, pMMI->content.menu.u8BottomLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(pInfo->content.menu_data.au8Bottom, pMMI->content.menu.u16BottomLen, pMMI->content.menu.pu8Bottom, pMMI->content.menu.u16BottomLen, pMMI->content.menu.pu8Bottom[0]);
                pInfo->content.menu_data.au8Bottom[u8TmpLen] = '\0';
                //msAPI_CI_RemoveControlByte(pInfo->content.menu_data.au8Bottom,++pMMI->content.menu.u8BottomLen);
                CIMMI_DBG(printf("Bottom: %s\n",pInfo->content.menu_data.au8Bottom));
            }
            pBuf = pInfo->content.menu_data.aStringContent;
            for (i = 0; i < pMMI->content.menu.u8Choice_nb; i++)
            {
                U16 u16StringLen;

                if (i == pMMI->content.menu.u8Choice_nb - 1)
                    u16StringLen =  pMMI->content.menu.pStringEnd - pMMI->content.menu.pString[i];
                else
                    u16StringLen = pMMI->content.menu.pString[i+1] - pMMI->content.menu.pString[i];

                //memcpy(&pBuf[u16Len],pMMI->content.menu.pString[i],u16StringLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(&pBuf[u16Len], u16StringLen, pMMI->content.menu.pString[i], u16StringLen, pMMI->content.menu.pString[i][0]);
                pBuf[u16Len+u8TmpLen] = '\0';

                u16TmpLen = u8TmpLen+1;
                pInfo->content.menu_data.pString[i] = &pBuf[u16Len];
                {
                    U16 j;
                    for(j = 0; j < u16StringLen; j++)
                    {
                        CIMMI_DBG(printf("%c",pInfo->content.menu_data.pString[i][j]));
                    }
                    CIMMI_DBG(printf("\n"));
                }
                u16Len += u16TmpLen;
            }
            pInfo->content.menu_data.ListCnt = pMMI->content.menu.u8Choice_nb; //adam test
            break;
        case EN_MMI_TYPE_LIST:
            CIMMI_DBG(printf("LIST\n"));
            pInfo->enType = EN_CIMMI_TYPE_LIST;
            if (pMMI->content.list.u16TitleLen)
            {
                //memcpy(pInfo->aTitleContent,pMMI->content.list.pu8Title,pMMI->content.list.u8TitleLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(pInfo->aTitleContent, pMMI->content.list.u16TitleLen, pMMI->content.list.pu8Title, pMMI->content.list.u16TitleLen, pMMI->content.list.pu8Title[0]);
                pInfo->aTitleContent[u8TmpLen] = '\0';
                //msAPI_CI_RemoveControlByte(pInfo->aTitleContent,pMMI->content.list.u8TitleLen + 1);
            }

            if (pMMI->content.list.u16SubtitleLen)
            {
                //memcpy(pInfo->content.list_data.au8Subtitle, pMMI->content.list.pu8Subtitle,pMMI->content.list.u8SubtitleLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(pInfo->content.list_data.au8Subtitle, pMMI->content.list.u16SubtitleLen, pMMI->content.list.pu8Subtitle, pMMI->content.list.u16SubtitleLen, pMMI->content.list.pu8Subtitle[0]);
                pInfo->content.list_data.au8Subtitle[u8TmpLen] = '\0';
                //msAPI_CI_RemoveControlByte(pInfo->content.list_data.au8Subtitle,++pMMI->content.list.u8SubtitleLen);
                CIMMI_DBG(printf("Subtitle %s\n",pInfo->content.list_data.au8Subtitle));
            }

            if (pMMI->content.list.u16BottomLen)
            {
                //memcpy(pInfo->content.list_data.au8Bottom, pMMI->content.list.pu8Bottom, pMMI->content.list.u8BottomLen);
                //We should follow SI character table, to translate various character.
                U8 u8TmpLen;
                u8TmpLen = MApp_SI_GetString(pInfo->content.list_data.au8Bottom, pMMI->content.list.u16BottomLen, pMMI->content.list.pu8Bottom, pMMI->content.list.u16BottomLen, pMMI->content.list.pu8Bottom[0]);
                pInfo->content.list_data.au8Bottom[u8TmpLen] = '\0';
                //msAPI_CI_RemoveControlByte(pInfo->content.list_data.au8Bottom,++pMMI->content.list.u8BottomLen);
                CIMMI_DBG(printf("Bottom %s\n",pInfo->content.list_data.au8Bottom));
            }
            pBuf = pInfo->content.list_data.aStringContent;

         if((pMMI->content.list.pStringEnd - pMMI->content.list.pString[0]) < MAX_CIMMI_TEXT_SIZE)
            {
                     for (i = 0; i < pMMI->content.list.u8Choice_nb; i++)
                {
                    U16 u16StringLen;

                    if (i == pMMI->content.list.u8Choice_nb - 1)
                        u16StringLen =  pMMI->content.list.pStringEnd - pMMI->content.list.pString[i];
                    else
                        u16StringLen = pMMI->content.list.pString[i+1] - pMMI->content.list.pString[i];

                    //memcpy(&pBuf[u16Len],pMMI->content.menu.pString[i],u16StringLen);
                    //We should follow SI character table, to translate various character.
                    U8 u8TmpLen;
                    u8TmpLen = MApp_SI_GetString(&pBuf[u16Len], u16StringLen, pMMI->content.list.pString[i], u16StringLen, pMMI->content.list.pString[i][0]);
                    pBuf[u16Len+u8TmpLen] = '\0';

                    u16TmpLen = u8TmpLen+1;
                    pInfo->content.list_data.pString[i] = &pBuf[u16Len];
                    {
                        U16 j;
                        for(j = 0; j < u16StringLen; j++)
                        {
                            CIMMI_DBG(printf("%c",pInfo->content.list_data.pString[i][j]));
                        }
                        CIMMI_DBG(printf("\n"));
                    }
                    u16Len += u16TmpLen;
                }
                     pInfo->content.list_data.ListCnt = pMMI->content.list.u8Choice_nb; //adam test
         }
         else
         {
             printf("[file:%s][line:%d]CIMMI content is too large, skip!!!\n", __FILE__, __LINE__);
          pInfo->content.list_data.ListCnt = 0; //adam test
         }

            break;
        default:
            break;
    }
    msAPI_CI_MMIDoneEvent(u8Event);
    msAPI_CI_MMIFreeData(pMMI);

    #if ENABLE_AUTOTEST
    if(g_bAutobuildDebug)
    {
        printf("CI Information display finish\n");
    }
    #endif

    return TRUE;
}

BOOLEAN Mapp_MMI_ParseInformaton(U16* DstName, U8 *pu8Src,U16 u16MaxNameLen)
{
	U8 u8TmpLen;

	if (NULL == pu8Src)
		return FALSE;

	for(u8TmpLen=0;u8TmpLen<255;u8TmpLen++)
	{
		if(pu8Src[u8TmpLen] == '\0')break;
	}

	if (!u8TmpLen)
		return FALSE;

	MApp_CharTable_MappingDVBTextToUCS2(pu8Src, DstName, u8TmpLen, u16MaxNameLen, REMOVE_00AD_SOFT_HYPHEN);

	return TRUE;
}

BOOLEAN MMI_SelectItem(S8 s8ItemIndex) //[in] s8ItemIndex for menu item index, -1 for back to prev menu
{
    //printf("[]select=%bd\n", s8ItemIndex);
    msAPI_CI_MMIAnswerMenu(s8ItemIndex+1);
    return TRUE;
}

BOOLEAN MMI_BackENQ( void )
{
    msAPI_CI_MMICancelEnq();
    return TRUE;
}
BOOLEAN MMI_InputENQ(U8 * pu8Code) //[in] pu8Code for user input PIN code, NULL for cancel
{
    //U8 u8Code[MAX_ENQ_LENGTH+1];
    //printf("[]enq=%u\n", u16Code);

    if(pu8Code == NULL) // User press exit
    {
        msAPI_CI_MMIAnswerEnq(NULL,0);
        MMI_SelectItem(-1);
    }
    else
    {
        /*
        sprintf(&u8Code[0],"%bu",(((U8)(u16Code >> 12))&0xF));
        sprintf(&u8Code[1],"%bu",(((U8)(u16Code >> 8))&0xF));
        sprintf(&u8Code[2],"%bu",(((U8)(u16Code >> 4))&0xF));
        sprintf(&u8Code[3],"%bu",(((U8)(u16Code >> 0))&0xF));
        */
        //sprintf(u8Code,"%04x", u16Code);
        //printf("Code: %s\n",pu8Code);
        msAPI_CI_MMIAnswerEnq(pu8Code,(U8)strlen((char*)pu8Code));
    }
    return TRUE;
}

void MMI_MessageHandle(void)
{
    // Marked it by coverity_0315
    //unsigned char   bCleanFlag = FALSE;
    E_CIMSG_TYPE CIMsgType = msAPI_CI_GetCIMessageType();

    if(
#if ENABLE_PVR
        (MApp_PVR_IsPlaybacking() || MApp_PVR_IsRecording())||MApp_TopStateMachine_GetTopState() == STATE_TOP_PVR||
#endif
	#if ENABLE_S2
		(MApp_ZUI_GetActiveOSD() == E_OSD_MENU_DISHSETUP) ||
	#endif
        (MApp_ZUI_GetActiveOSD() == E_OSD_DTV_MANUAL_TUNING) || (STATE_TOP_DTV_SCAN == MApp_TopStateMachine_GetTopState())||(STATE_TOP_ATV_SCAN == MApp_TopStateMachine_GetTopState())
       )
    {
        return;
    }

    if ( CIMsgType != EN_CIMSG_NONE )
    {
        if(EN_CIMSG_DETECTED == CIMsgType)
        {
            u8CardDetectCnt ++;
            if(u8CardDetectCnt > 1)
            {
                MApp_ZUI_ACT_StartupOSD(E_OSD_CIMMI);
                u8CardDetectCnt = 0;
            }
            else
                return;
        }
        else
            MApp_ZUI_ACT_StartupOSD(E_OSD_CIMMI);
    }
    switch ( CIMsgType )
    {
        case EN_CIMSG_REMOVED:
        case EN_CIMSG_DETECTED:
        case EN_CIMSG_INVALID:
            if (CIMsgType == EN_CIMSG_REMOVED)
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CI_REMOVED_MSGBOX);
            }
            else if(CIMsgType == EN_CIMSG_DETECTED)
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CI_DETECTED_MSGBOX);
            }

            //MMI_DBG( printf( "Draw Message Type:%bu\n", CIMsgType) );

            //if (MApp_TTX_IsTeletextOn())
                //MApp_TTX_TeletextCommand(TTX_TV);

        #if (MHEG5_ENABLE && CIPLUS_MHEG)
            if (msAPI_CI_GetCIMessageType() == EN_CIMSG_REMOVED && msAPI_IsCIMHEGRun() == E_MHEG_CI_RUNNING)
            {
                MApp_MHEG5_Force_Exit();
                enCheckMHEGLoadingStatus = EN_MHEG5_MONITOR;
            }
        #endif
            msAPI_CI_SetCIMessageType(EN_CIMSG_NONE);
            break;

        case EN_CIMSG_NOMODULE:
        case EN_CIMSG_TRYAGAIN:
            if (CIMsgType == EN_CIMSG_NOMODULE)
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CI_NO_MODULE_MSGBOX);
            }
            else if(CIMsgType==EN_CIMSG_TRYAGAIN)
            {
                MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_CI_TRY_AGAIN_MSGBOX);
            }

            msAPI_CI_SetCIMessageType(EN_CIMSG_NONE);
            break;

        //case EN_CIMSG_LOADINFO:
            //MMI_DBG( printf( "Draw Message Type:%bu\n", CIMsgType) );
            //MMI_DrawBitmapMessage( CIMsgType );
            //msAPI_CI_SetCIMessageType(EN_CIMSG_LOAD_NONE);
            //break;

        //case EN_CIMSG_LOAD_NONE:
       //    msAPI_CI_SetCIMessageType(EN_CIMSG_TRYAGAIN);

       //     break;
        default:
        case EN_CIMSG_NONE:
            break;
    }
}

BOOL MApp_CI_Date_SendDateTime(void)
{
    U32 u32CurrentSysime = MApp_GetLocalSystemTime();
    U8 au8CurrentUTCTime[5] = { 0x00 };
    MApp_Seconds2MJDUTC(u32CurrentSysime, au8CurrentUTCTime);

#if (!ENABLE_CI_PLUS)
    return msAPI_CI_DT_SendUTC(au8CurrentUTCTime);
#else
    static U16 u16HostInitUTCTime = 0xACCF;    // valid from 1980/01/01(0xAC, 0xCF).
    U16 u16UTCTime = 0;
    U16 u16CachedUTCTime = 0;
    ST_TIME CI_DT_Time;

    u16UTCTime = ((U16)au8CurrentUTCTime[0] << 8) | (U16)au8CurrentUTCTime[1];
    u16CachedUTCTime = ((U16)(DB_CI_PLUS_SETTING.u8SystemMJDUTC[0]) << 8) | (U16)(DB_CI_PLUS_SETTING.u8SystemMJDUTC[1]);

    //Fake time for testing key: 2009/12/19 00:00:00
    static U8 u8FakeUTC[5] = { 0xD7, 0x90, 0x00, 0x00, 0x00 };

    // Fake time for production key: 2010/12/31 00:00:00
    if(msAPI_CI_CC_GetCredentialsType())
    {
        u8FakeUTC[0] = 0xD9;
        u8FakeUTC[1] = 0x09;
    }

    //If current system time <= valid time.
    if(u16UTCTime <= u16HostInitUTCTime)
    {
        //If cached time <= valid time, use fake time.
        if(u16CachedUTCTime <= u16HostInitUTCTime)
        {
            MApp_ConvertSeconds2StTime(MApp_MJDUTC2Seconds(u8FakeUTC), &CI_DT_Time);
            //printf("Fake Time=>DATE : %d/%d/%d \n", CI_DT_Time.u16Year, CI_DT_Time.u8Month, CI_DT_Time.u8Day);

            return msAPI_CI_DT_SendUTC(u8FakeUTC);
        }
        //Else, use cached time.
        else
        {
            MApp_ConvertSeconds2StTime(MApp_MJDUTC2Seconds(DB_CI_PLUS_SETTING.u8SystemMJDUTC), &CI_DT_Time);
            //printf("Cached Time=>DATE : %d/%d/%d \n", CI_DT_Time.u16Year, CI_DT_Time.u8Month, CI_DT_Time.u8Day);

            return msAPI_CI_DT_SendUTC(DB_CI_PLUS_SETTING.u8SystemMJDUTC);
        }
    }
    //Otherwise, use system time.
    else
    {
        MApp_ConvertSeconds2StTime(MApp_MJDUTC2Seconds(au8CurrentUTCTime), &CI_DT_Time);
        printf("System Time=>DATE : %d/%d/%d \n", CI_DT_Time.u16Year, CI_DT_Time.u8Month, CI_DT_Time.u8Day);

        if (u16UTCTime != u16CachedUTCTime)
        {
            printf("Update Cached Date\n");
            memcpy(DB_CI_PLUS_SETTING.u8SystemMJDUTC, au8CurrentUTCTime, 5);
        }

        return msAPI_CI_DT_SendUTC(au8CurrentUTCTime);
    }
#endif
}

#if ENABLE_CI_PLUS
static BOOLEAN g_CIMMI_bCIByPass = FALSE;
void MApp_CI_HSS_Active_Cb( BOOL bActive )
{
    g_CIMMI_bCIByPass = bActive;

#if ENABLE_PVR
    BOOLEAN bPVRMode = FALSE;
    if ((MApp_PVR_IsPlaybacking() || MApp_PVR_IsRecording()))
    {
        bPVRMode = TRUE;
        printf("\nWarning: PVR is working! Should not change TSP path\n");
        return;
    }
#endif


#if 1//(!TS_SERIAL_OUTPUT_IF_CI_REMOVED)

    if (msAPI_CI_CardDetect())
    {
        if (FALSE == bActive)
        {
            /* Pass-Through Mode */
            // CI card to TSP
            //msAPI_Tuner_SetByPassMode(FALSE, bPVRMode);
            msAPI_Demod_SetupTSPath(E_DEMOD_TSP_PATH_CASE_CI_IN_USE);
        }
        else
        {
            /* By-Pass Mode */
            // Demod to TSP
            //msAPI_Tuner_SetByPassMode(TRUE, bPVRMode);
            msAPI_Demod_SetupTSPath(E_DEMOD_TSP_PATH_CASE_CI_BY_PASS);
        }
    }

#else

    if (msAPI_CI_CardDetect())
    {
        if (FALSE == bActive)
        {
            /* Pass-Through Mode */
            // CI card to TSP
            //msAPI_Tuner_Serial_Control(TRUE,bPVRMode);
            msAPI_Demod_SetupTSPath(E_DEMOD_TSP_PATH_CASE_CI_IN_USE);
        }
        else
        {
            /* By-Pass Mode */
            // Demod to TSP
            //msAPI_Tuner_Serial_Control(FALSE,bPVRMode);
            msAPI_Demod_SetupTSPath(E_DEMOD_TSP_PATH_CASE_CI_BY_PASS);
        }
    }
#endif
}

BOOLEAN MApp_CI_Is_CIByPassMode(void)
{
    if( g_CIMMI_bCIByPass )
        return TRUE;

    return FALSE;
}
#endif  // #if ENABLE_CI_PLUS

#if 0//(ENABLE_DTV)
void MApp_CI_PMT_Parse(U8 *pu8Section)
{
    // Neotion NP4 transcode issue
    #define CIINFO_LENGTH 10
    U8 manufacturer[CIINFO_LENGTH];
    U8 product[CIINFO_LENGTH];
    U8 Info1[CIINFO_LENGTH];


    // Neotion NP4 transcode issue
    // Don't send PMT if it is neotion and content is clear.
    u32ChkTry2ChgMpeg2Time = msAPI_Timer_GetTime0();
    msAPI_CI_GetCIS( manufacturer, CIINFO_LENGTH, product, CIINFO_LENGTH, Info1, CIINFO_LENGTH );
    if(msAPI_CI_GetCardType()               == EN_SMARTCARD_TYPE_NEOTNT &&
       strcmp((char*)manufacturer,"NEOTION")== 0                        &&
       strcmp((char*)product,"NP4")         == 0)
    {
        if(MApp_SI_CheckCurProgScramble() == TRUE)
        {
            //printf("Send PMT\n");
            msAPI_CI_NotifyPMTUpdate(pu8Section,(3 + TSGetBitsFromU16(&pu8Section[1], 0, 0x0FFF)));
        }
    }
    else
    {
        msAPI_CI_NotifyPMTUpdate(pu8Section,(3 + TSGetBitsFromU16(&pu8Section[1], 0, 0x0FFF)));
    }

}
#endif

#if (ENABLE_UPGRADE_CIPLUSKEY_BY_USB)
code U8 Default_CIPlus_KEY[4978] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

unsigned long crc32_encode(const unsigned char *octets, int len)
{
  unsigned long crc = 0xFFFFFFFF;
  unsigned long temp;
  int j;

  while (len--)
  {
    temp = (unsigned long)((crc & 0xFF) ^ *octets++);
    for (j = 0; j < 8; j++)
    {
      if (temp & 0x1)
        temp = (temp >> 1) ^ 0xEDB88320;
      else
        temp >>= 1;
    }
    crc = (crc >> 8) ^ temp;
  }
  return crc ^ 0xFFFFFFFF;
}

BOOLEAN Mapp_check_valid_key(void)
{
    BOOLEAN bValidkey = FALSE;
    U8 u8keybuf[6000] = {0};
    U8 u8aTempBuf[4] = { 0x00 };
    U16 u16CredentialsLength = 0;
    U32 u32keyCRC = 0;
    U32 u32keyCRCFalsh = 0;

    msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12, 2, u8aTempBuf );
    u16CredentialsLength = (U16)u8aTempBuf[0] << 8 | (U16)u8aTempBuf[1];
    //printf("\n## u16CredentialsLength=%x",u16CredentialsLength);
    msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE, 4, u8aTempBuf );
    if(u8aTempBuf[2] != 0x04 || u8aTempBuf[3] != 0xD7)
    {
        bValidkey = FALSE;
    }
    else if((12 + u16CredentialsLength) < 6000)
    {
        msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE, 12 + u16CredentialsLength, u8keybuf );//david ci+
        u32keyCRC = ~crc32_encode( u8keybuf, 12 + u16CredentialsLength );//david ci+
        //printf("~CRC32 cal: 0x%X\r\n", u32keyCRC);
        msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12 +u16CredentialsLength, 4, u8aTempBuf);//david ci+
        u32keyCRCFalsh = ( (U32)u8aTempBuf[0] << 24 );
        u32keyCRCFalsh = u32keyCRCFalsh | ( (U32)u8aTempBuf[1] << 16 );
        u32keyCRCFalsh = u32keyCRCFalsh | ( (U32)u8aTempBuf[2] <<  8 );
        u32keyCRCFalsh = u32keyCRCFalsh | ( (U32)u8aTempBuf[3]);
        //printf("~CRC32 flash: 0x%X\r\n", u32keyCRCFalsh);
        if(u32keyCRCFalsh == u32keyCRC)
        {
            bValidkey = TRUE;
        }
    }
    //printf("\n ## CI KEY valid?:[%u]",bValidkey);
    return bValidkey;
}
#endif

void MApp_CI_Event_Cb(EN_CI_EVENT etype)
{
    switch(etype)
    {
#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
        case CI_EVENT_APPMMI_REQ_START:    // Wake MHEG5 engine up.
            {
                U32 u32Len = 0;
                U8 *pu8AppMmi = NULL;

                #if CIPLUS_MHEG_1_3

                U8 u8SSM = msAPI_CI_AppMmi_Get_SSM();
                msAPI_MHEG5_SetCIPLUSSSM(u8SSM);    //  0/1/2 - if not available, set 2 as default
                msAPI_MHEG5_SetCIPLUSSMG(FALSE);
                // wake mheg5 engine up
                msAPI_MHEG5_SetCIMHEGRun(E_MHEG_CI_TRIGGER);
                if (msAPI_MHEG5_GoMHEGWhenSubtitleOn() == 0)
                {
                    msAPI_MHEG5_SetCIMHEGRun(E_MHEG_CI_OFF);
                    // skip the RequestStart
                    break;
                }
                #endif

                if (msAPI_MHEG5_GetBinStatus() == FALSE)
                {
                    msAPI_MHEG5_Bean_Init();
                }

                // if broadcast mheg is running, insert CI+ will make broadcast mheg leave and run CIMHEG
                if ((msAPI_IsCIMHEGRun() == E_MHEG_CI_OFF) && (msAPI_MHEG5_checkGoBackMHEG5()==true || MApp_MHEG5_CheckGoMHEG5Process()==TRUE))
                {
                    MApi_MHEG5_Disable(EN_MHEG5_DM_DISABLE_AND_WAIT);
                    //msAPI_Timer_Delayms(500);
                }

                enCheckMHEGLoadingStatus = EN_MHEG5_MONITOR;

                pu8AppMmi = msAPI_CI_AppMmiGetBufPtr();
                if(pu8AppMmi != NULL)
                {
                    // allocate buffer for CIMHEG
                    msAPI_MHEG5_AllocateCIMHEGBuffer();

                    u32Len = (U32)pu8AppMmi[0] << 24 |
                        (U32)pu8AppMmi[1] << 16 |
                        (U32)pu8AppMmi[2] << 8 |
                        (U32)pu8AppMmi[3];

               {
                   printf("u32Len = %lu\n", u32Len);
                   printf("APPMMI Buffer: %c%c%c%c%c%c%c%c%c%c%c%c\n", pu8AppMmi[4], pu8AppMmi[5], pu8AppMmi[6], pu8AppMmi[7], pu8AppMmi[8]
                         , pu8AppMmi[9], pu8AppMmi[10], pu8AppMmi[11], pu8AppMmi[12], pu8AppMmi[13], pu8AppMmi[14], pu8AppMmi[15]);
               }
                    if (u32Len)
                    {
                        U32 u32BufferAddr = msAPI_MHEG5_GetDLAFBAddress();

                    #ifdef GOP_GWIN_RB2_ADR
                        if (GOP_GWIN_RB2_MEMORY_TYPE & MIU1)
                        {
                            if (MMI_TEXTSTRING_MEMORY_TYPE & MIU1)  // 1 -> 1
                            {
                                msAPI_MIU_Copy((MMI_TEXTSTRING_ADR | MIU_INTERVAL)+0x800, u32BufferAddr, u32Len+4, MIU_SDRAM12SDRAM1);
                            }
                            else    // 0 -> 1
                            {
                                msAPI_MIU_Copy(MMI_TEXTSTRING_ADR+0x800, u32BufferAddr, u32Len+4, MIU_SDRAM02SDRAM1);
                            }
                        }
                        else
                    #endif
                        {
                            #if (MMI_TEXTSTRING_MEMORY_TYPE & MIU1)  // 1->0
                            {
                                msAPI_MIU_Copy((MMI_TEXTSTRING_ADR | MIU_INTERVAL)+0x800, u32BufferAddr, u32Len+4, MIU_SDRAM12SDRAM0);
                            }
                            #else    // 0->0
                            {
                                msAPI_MIU_Copy(MMI_TEXTSTRING_ADR+0x800, u32BufferAddr, u32Len+4, MIU_SDRAM2SDRAM);
                            }
                            #endif
                        }

                    #if 0
                        // fEnableSignalMonior will be false when 1st setup (after "Factory Reset")
                        if (u32DSMCC_Start_Timer == 0 && fEnableSignalMonitor == false)
                        {
                            u32DSMCC_Start_Timer = msAPI_Timer_GetTime0();
                        }
                    #endif

                        // wake mheg5 engine up
                        msAPI_MHEG5_SetCIMHEGRun(E_MHEG_CI_TRIGGER);

                    #if CIMHEG_DBG
                        printf("CI+ Request Start ....\n");
                    #endif
                    }
                }
            }
            break;

        case CI_EVENT_APPMMI_FILE:
        case CI_EVENT_APPMMI_DATA:
            {
            #if CIMHEG_DBG
                printf("file ready...\n");
            #endif
                msAPI_MHEG5_SendCIMHEGFileReady();
            }
            break;

        case CI_EVENT_APPMMI_FILE_INQUIRE_OK:
            msAPI_MHEG5_SendCIMHEGFileExistence(TRUE);
            break;

        case CI_EVENT_APPMMI_FILE_INQUIRE_NG:
            msAPI_MHEG5_SendCIMHEGFileExistence(FALSE);
            break;

        case CI_EVENT_APPMMI_REQ_NG:
        #if 0
            msAPI_MHEG5_SendCIMHEGFileReady();  // tell data is ready to make engine exit the busy waiting
            msAPI_MHEG5_CIMHEGNG();             // tell cimheg data is NG
            MApp_MHEG5_Force_Exit();            // force exit mheg to do cleaning in housekeeping
        #else
            msAPI_MHEG5_SendCIMHEGFileNG();
        #endif
            break;

        case CI_EVENT_APPMMI_REQ_ABORT:
            {
                if (msAPI_IsCIMHEGRun() == E_MHEG_CI_RUNNING)
                {
                    MApp_MHEG5_Force_Exit();
                    enCheckMHEGLoadingStatus = EN_MHEG5_MONITOR;
                }
            }
            break;

        case CI_EVENT_DT_ENQ:
            MApp_CI_Date_SendDateTime();
            break;

        case CI_EVENT_HC_TUNE:
            MApp_CI_CiEventCommandHcTune();
            break;

#if (ENABLE_CI_PLUS)
        case CI_EVENT_HC_TUNE_BROADCAST_REQ:
            MApp_CI_CiEventCommandHcTuneBroadcastReq();
            break;

        case CI_EVENT_HC_CICAM_PMT_PARSE:
            MApp_CI_CiEventCommandHcCicamPmtParse();
            break;

        case CI_EVENT_HC_STREAM_PMT_PARSE:
            MApp_CI_CiEventCommandHcStreamPmtParse();
            break;

        case CI_EVENT_HC_SI_WAKE_UP:
            MApp_CI_CiEventCommandHcSiWakeUp();
            break;

        case CI_EVENT_CC_PIN_REPLY:
            MApp_CI_CiEventCommandCcPinReply();
            break;

        case CI_EVENT_OP_STATUS:
            MApp_CI_CiEventCallbackOpStatus();
            break;

        case CI_EVENT_OP_INFO:
            MApp_CI_CiEventCallbackOpInfo();
            break;

        case CI_EVENT_OP_TUNE:
            MApp_CI_CiEventCommandOpTune();
            break;

        case CI_EVENT_OP_NIT:
            MApp_CI_CiEventCommandOpNit();
            break;

        case CI_EVENT_OP_SEARCH_STATUS:
            MApp_CI_CiEventCommandOpSearchStatus();
            break;

        case CI_EVENT_OP_NIT_CHECK:
            MApp_CI_CiEventCommandOpNitCheck();
            break;
#endif //(ENABLE_CI_PLUS)

        case CI_EVENT_HSS:
            MApp_CI_HSS_Active_Cb(msAPI_CI_HSS_Get());
            break;

        case CI_EVENT_CC_CREDENTIALS_LOAD:
            {
			#if (ENABLE_UPGRADE_CIPLUSKEY_BY_USB)
				BOOLEAN bValidkey = FALSE;

				bValidkey = Mapp_check_valid_key();
				if(bValidkey == TRUE)
				{
					U16 u16CredentialsLength = 0;
					U8 u8aTempBuf[2] = { 0x00 };
					msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12, 2, u8aTempBuf );
					u16CredentialsLength = (U16)u8aTempBuf[0] << 8 | (U16)u8aTempBuf[1];
					printf("\n## Valid ci+ key len=%x",u16CredentialsLength);
					msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12, (U32)u16CredentialsLength, msAPI_CI_CC_GetCredentialsBufferAddr() );
				}
				else
				{
					U8* ciBuf;
					U16 i;
					printf("\n## invalid ci+ key!");
					ciBuf = msAPI_CI_CC_GetCredentialsBufferAddr();
					for(i=0;i<0x1362;i++)
					{
						ciBuf[i] = Default_CIPlus_KEY[12+i];
					}
				}
			#else
                U8 u8aTempBuf[2] = { 0x00 };
                U16 u16CredentialsLength = 0;

                msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12, 2, u8aTempBuf );
                u16CredentialsLength = (U16)u8aTempBuf[0] << 8 | (U16)u8aTempBuf[1];

                msAPI_Flash_Read( CIPLUS_KEY_BANK*FLASH_BLOCK_SIZE + 12, (U32)u16CredentialsLength, msAPI_CI_CC_GetCredentialsBufferAddr() );
			#endif
			}
            break;

        case CI_EVENT_CC_AUTH_KEY_SAVE:
            msAPI_CI_CC_SaveKeyToFlash(DB_CI_PLUS_SETTING.stKeySetting, TRUE);
            DB_CI_PLUS_SETTING.CIKeyCS = 0;
            break;

        case CI_EVENT_CC_AUTH_KEY_LOAD:
            msAPI_CI_CC_LoadKeyFromFlash(DB_CI_PLUS_SETTING.stKeySetting, TRUE);
            break;

        case CI_EVENT_CC_URI:
        {
            U8 u8URI_RCT = 0, u8URI_EMI = 0, u8URI_APS = 0, u8URI_ICT = 0, u8URI_RL = 0;
            static BOOLEAN bMuteEnable = FALSE;

            msAPI_CI_CC_GetURI(&u8URI_RCT, &u8URI_EMI, &u8URI_APS, &u8URI_ICT, &u8URI_RL);
            //printf("RCT|EMI|APS|ICT|RL\n");
            //printf("%02bX|%02bX|%02bX|%02bX|%02bX\n", u8URI_RCT, u8URI_EMI, u8URI_APS, u8URI_ICT, u8URI_RL);
            if (msAPI_CI_CardDetect() && (EN_CI_VERSION_CI_PLUS == msAPI_CI_CC_CAM_Mode()))
            {
                MEMBER_SERVICETYPE bServiceType;
                U16 u16ProgramPosition;

                EN_MACROVISION enMacrovisionMode;
                enMacrovisionMode = EN_MACROVISION_INVALID;
                if (CC_URI_EMI_COPY_FREELY == u8URI_EMI)
                {
                    if (CC_URI_RCT_NO_REDISTRIBUTION_CONTROL_ASSERTED == u8URI_RCT)
                    {
                        enMacrovisionMode = EN_MACROVISION_COPY_PROTECTION_ENCODING_OFF;
                    }
                }
                else if (CC_URI_EMI_COPY_ONCE == u8URI_EMI)
                {
                    enMacrovisionMode = EN_MACROVISION_COPY_PROTECTION_ENCODING_OFF;
                }
                /* Macrovision. */
                u16ProgramPosition = msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType());
                bServiceType = msAPI_CM_GetCurrentServiceType();
                if (msAPI_CM_GetProgramAttribute(bServiceType, u16ProgramPosition, E_ATTRIBUTE_IS_SCRAMBLED))
                {
                    if ( (0x00 != u8URI_EMI) && (EN_MACROVISION_COPY_PROTECTION_ENCODING_OFF != enMacrovisionMode))
                    {
                        /* non Copy Freely */
                        //printf("[CI+] Blocking....");
                        if ( TRUE != bMuteEnable )
                        {
                            msAPI_Scaler_SetCVBSMute(ENABLE, E_VE_MUTE_CI_PLUS, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), OUTPUT_CVBS1);
                            msAPI_Scaler_SetCVBSMute(ENABLE, E_VE_MUTE_CI_PLUS, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), OUTPUT_CVBS2);
                            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_CI_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                            bMuteEnable = TRUE;
                        }
                    }
                    else
                    {
                        /* Copy Freely */
                        //printf("[CI+] None Blocking....");
                        if ( TRUE == bMuteEnable )
                        {
                            msAPI_Scaler_SetCVBSMute(DISABLE, E_VE_MUTE_CI_PLUS, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), OUTPUT_CVBS1);
                            msAPI_Scaler_SetCVBSMute(DISABLE, E_VE_MUTE_CI_PLUS, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), OUTPUT_CVBS2);
                            msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_CI_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                            bMuteEnable = FALSE;
                        }
                    }
                }
                else
                {
                    //printf("[CI+] None Blocking....");
                    if ( TRUE == bMuteEnable )
                    {
                        msAPI_Scaler_SetCVBSMute(DISABLE, E_VE_MUTE_CI_PLUS, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), OUTPUT_CVBS1);
                        msAPI_Scaler_SetCVBSMute(DISABLE, E_VE_MUTE_CI_PLUS, SYS_INPUT_SOURCE_TYPE(MAIN_WINDOW), OUTPUT_CVBS2);
                        msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_CI_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
                        bMuteEnable = FALSE;
                    }
                }
            }

            /* SPDIF - SCMS */
            if ((0x00 == u8URI_RCT && 0x00 == u8URI_EMI) || (0x01 == u8URI_RCT && 0x00 == u8URI_EMI))
            {
                /* Copy Freely */
                printf("[CI+] URI Copy Freely....\n");
				msAPI_AUD_SPDIF_SetSCMS(SPDIF_SCMS_CopyFreely_);
				if (SPDIF_SCMS_CopyFreely != msAPI_AUD_SPDIF_GetSCMS())
                {
                    printf("[Fatal Error!][CI+] SPDIF is out of control!\n");
                }
            }
            else if (0x00 == u8URI_RCT && 0x01 == u8URI_EMI)
            {
                /* Copy No More */
                printf("[CI+] URI Copy No More....\n");
				msAPI_AUD_SPDIF_SetSCMS(SPDIF_SCMS_CopyNoMore_);
				if (SPDIF_SCMS_CopyNoMore != msAPI_AUD_SPDIF_GetSCMS())
                {
                    printf("[Fatal Error!][CI+] SPDIF is out of control!\n");
                }
            }
            else if (0x00 == u8URI_RCT && 0x02 == u8URI_EMI)
            {
                /* Copy Once */
                printf("[CI+] URI Copy Once....\n");
				msAPI_AUD_SPDIF_SetSCMS(SPDIF_SCMS_CopyOnce_);
				if (SPDIF_SCMS_CopyOnce != msAPI_AUD_SPDIF_GetSCMS())
                {
                    printf("[Fatal Error!][CI+] SPDIF is out of control!\n");
                }
            }
            else if (0x00 == u8URI_RCT && 0x03 == u8URI_EMI)
            {
                /* Copy Never */
                printf("[CI+] URI Copy Never....\n");
				msAPI_AUD_SPDIF_SetSCMS(SPDIF_SCMS_CopyNever_);
				if (SPDIF_SCMS_CopyNever != msAPI_AUD_SPDIF_GetSCMS())
                {
                    printf("[Fatal Error!][CI+] SPDIF is out of control!\n");
                }
            }
            else
            {
                printf("[Warning!] Abnormal URI!\n");
            }
        }
        break;
#endif

        case CI_EVENT_CAM_DETECT:
        case CI_EVENT_CAM_RESET:
#if ENABLE_CI_PLUS
            MApp_CI_InitCiVariables();
#if MHEG5_ENABLE
#if CIPLUS_MHEG  // reset MHEG5
            if (msAPI_IsCIMHEGRun() == E_MHEG_CI_RUNNING)
            {
                MApp_MHEG5_Force_Exit();
                enCheckMHEGLoadingStatus = EN_MHEG5_MONITOR;
            }
#endif
#endif
#endif
            break;
#if ENABLE_CI_PLUS
		case CI_EVENT_SYSTEM_TIME_UPDATE:
			MApp_CI_CiEventCallbackSystemTimeUpdate();
			break;
#endif//ENABLE_CI_PLUS
        default:
            printf( "[%s:%d][Warning!] Unknow CI event %d !!!\n", __FILE__, __LINE__,  etype);
            break;
    }
}

#if (ENABLE_CI_PLUS)
BOOLEAN MApp_CI_SetCharCodeTableToSrvName(const U8 *pu8SrcName, U8 u8SrcLen, U8 *pu8DstName, U8 u8DstMaxLen, U32 u32CicamId)
{
    U8 u8CharacterCodeTable;
    U8 u8EncodingTypeID;
    U8 u8SecondByteValue;
    U8 u8ThirdByteValue;
    U8 au8Buf[MAX_SERVICE_NAME];
    MW_OPCACHE_INFO stOpCacheInfo;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    memset(&stOpCacheInfo, 0, sizeof(MW_OPCACHE_INFO));
    if(FALSE == msAPI_OP_GetOpCacheInfoByCicamId(u32CicamId, &stOpCacheInfo))
    {
        return FALSE;
    }
    if((pu8SrcName == NULL) || (pu8DstName == NULL))
    {
        return FALSE;
    }
    memset(au8Buf, 0, MAX_SERVICE_NAME);

    u8CharacterCodeTable = stOpCacheInfo.stCiOpInfo.u8CharacterCodeTable;
    u8EncodingTypeID = stOpCacheInfo.stCiOpInfo.u8EncodingTypeID;
    u8SecondByteValue = stOpCacheInfo.stCiOpInfo.u8SecondByteValue;
    u8ThirdByteValue = stOpCacheInfo.stCiOpInfo.u8ThirdByteValue;

    if(TRUE == msAPI_OP_SetCharCodeTable(pu8SrcName, u8SrcLen, au8Buf, MAX_SERVICE_NAME,u8CharacterCodeTable, u8EncodingTypeID, u8SecondByteValue, u8ThirdByteValue))
    {
        memcpy(pu8DstName, au8Buf, (u8DstMaxLen > MAX_SERVICE_NAME) ? MAX_SERVICE_NAME : u8DstMaxLen);
    }
    else
    {
        memcpy(pu8DstName, pu8SrcName, (u8SrcLen > u8DstMaxLen) ? u8DstMaxLen : u8SrcLen);
    }

    return TRUE;

}

BOOL MApp_CI_GetOpProfileNameByIndex( U8 u8Index, WORD* ProfileName , U16 u16MaxNameLen)
{
    U8 au8Buff[MAX_PROFILE_NAME];
    U8 au8Buff2[MAX_PROFILE_NAME];
    U16 u16Len;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(ProfileName == NULL)
    {
        return FALSE;
    }
    memset(au8Buff, 0, MAX_PROFILE_NAME);
    memset(au8Buff2, 0, MAX_PROFILE_NAME);

    if(TRUE == msAPI_OP_GetOpProfileNameByIndex(u8Index, au8Buff, MAX_PROFILE_NAME))
    {
        u16Len = MApp_SI_GetString(au8Buff2, MAX_PROFILE_NAME, au8Buff, MAX_PROFILE_NAME, KEEP_CONTROL_CODE_ALL);
        MApp_CharTable_MappingDVBTextToUCS2(au8Buff2, ProfileName, u16Len, u16MaxNameLen, REMOVE_00AD_SOFT_HYPHEN);
        return TRUE;

    }
    return FALSE;
}

BOOL MApp_CI_GetOpDtvSysTypeByIndex( U8 u8Index, EN_DELIVERY_SYS_TYPE* eDtvSysType )
{
    BOOL bRet = FALSE;

    bRet = msAPI_OP_GetOpDtvSysTypeByIndex(u8Index, eDtvSysType);
    return bRet;
}

BOOL MApp_CI_GetOpIso639LangCodeByCicamId( U32 u32CicamId, U8* pu8Iso639LangCode )
{
    BOOL bRet = FALSE;

    bRet = msAPI_OP_GetOpIso639LangCodeByCicamId(u32CicamId, pu8Iso639LangCode);
    return bRet;

}

U32 MApp_CI_GetCurrentOpCicamId( void )
{
    return MApp_CI_GetCurrentCicamId();
}

U8 MApp_CI_GetOpCacheCount( void )
{
    return msAPI_OP_GetOpCacheCount();
}

U8 MApp_CI_GetValidOpCacheCount(void)
{
    U8 i = 0,j = 0;
    EN_DELIVERY_SYS_TYPE eProfileDtvSysType = E_DELIVERY_SYS_NONE;

    //MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    for(i = 0; i < MApp_CI_GetOpCacheCount(); i++)
    {
	  MApp_CI_GetOpDtvSysTypeByIndex(i, &eProfileDtvSysType);
        if(eProfileDtvSysType != E_DELIVERY_SYS_NONE)
        {
            j++;
        }
    }
    return j;
}

//BOOL MApp_CI_IsOpCountReachMaxNum(void)

BOOL MApp_CI_DeleteOpCacheByIndex( U8 u8Index )
{
    BOOL bRet = FALSE;

    bRet = msAPI_OP_DeleteByIndex(u8Index);
    return bRet;
}

BOOL MApp_CI_DeleteOpCacheByCicamId( U32 u32CicamId )
{
    BOOL bRet = FALSE;

    bRet = msAPI_OP_DeleteByCicamId(u32CicamId);
    return bRet;

}

void MApp_CI_SetCurrentCicamId(U32 u32CicamId)
{
    g_u32CurrentCicamId = u32CicamId;
}
U32 MApp_CI_GetCurrentCicamId(void)
{
    return g_u32CurrentCicamId;
}

void MApp_CI_SetOpMode(BOOLEAN bOpMpde)
{
    msAPI_CM_SetOpMode(bOpMpde);
}

BOOL MApp_CI_IsOpMode( void )
{
    return msAPI_CM_GetOpMode();
}

BOOL MApp_CI_ResetOPCacheDB( BOOL bDisableChannel )
{
    BOOL bRst = FALSE;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(bDisableChannel == TRUE)
    {
        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
    }

    bRst = msAPI_OP_Reset();

    return bRst;
}

BOOL MApp_CI_CompareCIContentByte( U8 u8ContentByte, WORD* pLabelChar, U16 u16LaelLen)
{
    U8 u8Buff[MAX_CIPLUS_LABEL_CHAR];

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(pLabelChar == NULL)
    {
        return FALSE;
    }
    memset(u8Buff, 0, MAX_CIPLUS_LABEL_CHAR);
    if(TRUE == MApp_SI_CompareCIContentByte(u8ContentByte, u8Buff, MAX_CIPLUS_LABEL_CHAR))
    {
        U8 u8Buff2[MAX_CIPLUS_LABEL_CHAR];
        U16 u16TempLen;

        memset(u8Buff2, 0, MAX_CIPLUS_LABEL_CHAR);
        u16TempLen = MApp_SI_GetString(u8Buff2, MAX_CIPLUS_LABEL_CHAR, u8Buff, MAX_CIPLUS_LABEL_CHAR, KEEP_CONTROL_CODE_NONE);
        MApp_CharTable_MappingDVBTextToUCS2(u8Buff, pLabelChar, u16TempLen, u16LaelLen, REMOVE_00AD_SOFT_HYPHEN);

        return TRUE;
    }

    return FALSE;

}

static BOOL MApp_CI_EnterCIOpServiceMode(U8 u8Index)
{
    MW_OPCACHE_INFO stOpCacheInfo;
    BOOL bDeliverySystemMatched = FALSE;
    MW_OPCACHE_CAMNIT *stOpCacheCamNIT;
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);
	WORD wNewPosition;

    memset(&stOpCacheInfo, 0, sizeof(MW_OPCACHE_INFO));
    if(FALSE == msAPI_OP_GetOpCacheInfoByIndex(u8Index, &stOpCacheInfo))
    {
        printf("EnterCIOpServiceMode : GetOpCacheInfoByIndex fail");
        return FALSE;
    }
    // Check is Delivery System matched?
//#if (DVB_T_C_DIFF_DB || ENABLE_T_C_COMBO)

    if(IsDVBCInUse() && (E_DELIVERY_SYS_CDSD == stOpCacheInfo.eDtvSystemType))
    {
        bDeliverySystemMatched = TRUE;
    }
    else if(!IsDVBCInUse() && (E_DELIVERY_SYS_TDSD == stOpCacheInfo.eDtvSystemType))
    {
        bDeliverySystemMatched = TRUE;
    }
    else
    {
        printf("[%s:%d][Warning!][CI+][OP] Delivery System is not Matched!\r\n", __FILE__, __LINE__);
        return FALSE;
    }
//#else
//    if((E_DELIVERY_SYS_TDSD == stOpCacheInfo.eDtvSystemType))
//    {
//        bDeliverySystemMatched = TRUE;
//    }
//    else
//    {
//        printf("[%s:%d][Warning!][CI+][OP] Delivery System is not Matched!\r\n", __FILE__, __LINE__);
//        return FALSE;
//    }
//#endif

    if(MApp_CI_IsOpMode())
    {
        if(stOpCacheInfo.stCiOpInfo.u32CicamIdentifier == MApp_CI_GetCurrentCicamId())
        {
            printf("EnterCIOpServiceMode : select same OP Cache");
            return FALSE;
        }
        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
    }
    else
    {
        DB_CI_PLUS_SETTING.u16NormalChannelIndex = msAPI_CM_GetCurrentPosition(msAPI_CM_GetCurrentServiceType());
        MApp_CI_SetOpMode(TRUE);
        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);
        MApp_CI_SetCurrentCicamId(stOpCacheInfo.stCiOpInfo.u32CicamIdentifier);
	#if 0
        if(TRUE == MApp_CI_GetOpIso639LangCodeByCicamId(MApp_CI_GetCurrentOpCicamId(), au8IsoLang))
        {
            eLangcode = msAPI_SI_GetLanguageByISO639LangCode(au8IsoLang);
            MApp_SI_SetDefaultLanguage(eLangcode);
        }
	#endif
        msAPI_CM_SwitchCMDB(TRUE);
#if (ENABLE_DTV_EPG)
		/* init epg database */
		MApp_EIT_All_Sche_ResetFilter();
		MApp_Epg_Init();
#endif
    }
    stOpCacheCamNIT = (MW_OPCACHE_CAMNIT *)CI_MEMORY_ALLOCATE(sizeof(MW_OPCACHE_CAMNIT));
    if(stOpCacheCamNIT != NULL)
    {
        memset(stOpCacheCamNIT, 0x00, sizeof( MW_OPCACHE_CAMNIT ));
        if(FALSE == msAPI_OP_GetStorageCacheCamNIT(stOpCacheInfo.u32ID, stOpCacheCamNIT))
        {
            printf("Get Storage Cache data fail");
            CI_MEMORY_FREE(stOpCacheCamNIT);
            stOpCacheCamNIT = NULL;
            return FALSE;
        }
        MApp_SI_CICAM_NIT_Parse(stOpCacheCamNIT->au8CamNIT, stOpCacheCamNIT->u16SecCount);
    }

    g_u32OpCicamIdentifier = MApp_CI_GetCurrentCicamId();

    /* Notify CI+ CAM that Host enters OP through operator_status_req() if the OP belongs to the CI+ CAM. */
    if( TRUE == msAPI_CI_CardDetect() )
    {
        CI_OP_STATUS stCiOpStatus;
        CI_OP_INFO stCiOpInfo;

        memset(&stCiOpStatus, 0x00, sizeof(CI_OP_STATUS));
        memset(&stCiOpInfo, 0x00, sizeof(CI_OP_INFO));

        if( ( TRUE == msAPI_CI_OP_GetStatus( &stCiOpStatus ) ) && ( TRUE == msAPI_CI_OP_GetInfo(&stCiOpInfo ) ) )
        {
            /* Checking conditions:
                1. initialised_flag of OP Status shall be 1.
                2. cicam_identifier of OP Info shall be matched.
            */
            if ((1 == stCiOpStatus.u8InitializedFlag) &&
                    (MApp_CI_GetCurrentCicamId() == stCiOpInfo.u32CicamIdentifier))
            {
                printf("[CI+][OP] Send operator_status_req()!\r\n");
                msAPI_CI_OP_SendStatusReq();
            }
            else
            {
                printf("[CI+][OP] The OP(%02X) doesn't belong to the CI+ CAM: 0x%08lX | 0x%08lX!\n", stCiOpStatus.u8InitializedFlag,
                                      MApp_CI_GetCurrentCicamId(), stCiOpInfo.u32CicamIdentifier);
            }
        }
    }
    if(stOpCacheCamNIT)
    {
        CI_MEMORY_FREE(stOpCacheCamNIT);
        stOpCacheCamNIT = NULL;
    }
	wNewPosition = DB_CI_PLUS_SETTING.u16OpChannelIdex;
	msAPI_CM_SetCurrentPosition(msAPI_CM_GetCurrentServiceType(),wNewPosition);
    MApp_ChannelChange_EnableChannel(MAIN_WINDOW);

    return TRUE;
}

static BOOL MApp_CI_ExitCIOpServiceMode(void)
{
    CI_OP_STATUS stCiOpStatus;
    CI_OP_INFO stCiOpInfo;
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(MApp_CI_IsOpMode())
    {
        MApp_ChannelChange_DisableChannel(TRUE,MAIN_WINDOW);

        //msAPI_CM_ResetAllProgram();
        MApp_CI_SetOpMode(FALSE);
        MApp_SetSILanguage(MApp_GetMenuLanguage());
        msAPI_CM_SwitchCMDB(FALSE);
#if (ENABLE_DTV_EPG)
		/* init epg database */
		MApp_EIT_All_Sche_ResetFilter();
		MApp_Epg_Init();
#endif
        /* Notify CI+ CAM that Host exits OP through operator_exit() if the OP belongs to the CI+ CAM. */
        if( TRUE == msAPI_CI_CardDetect() )
        {
            memset(&stCiOpStatus, 0x00, sizeof(CI_OP_STATUS));
            memset(&stCiOpInfo, 0x00, sizeof(CI_OP_INFO));

            if( ( TRUE == msAPI_CI_OP_GetStatus( &stCiOpStatus ) ) && ( TRUE == msAPI_CI_OP_GetInfo( &stCiOpInfo ) ) )
            {
                /* Checking conditions:
                    1. initialised_flag of OP Status shall be 1.
                    2. cicam_identifier of OP Info shall be matched.
                */
                if ((1 == stCiOpStatus.u8InitializedFlag) &&
                    (MApp_CI_GetCurrentCicamId() == stCiOpInfo.u32CicamIdentifier))
                {
                    // Send operator_exit()
                    printf("[CI+][OP] Send operator_exit()!\r\n");
                    msAPI_CI_OP_SendExit();
                }
                else
                {
                    printf("[CI+][OP] The OP(%02X) doesn't belong to the CI+ CAM: 0x%08lX | 0x%08lX!\n", stCiOpStatus.u8InitializedFlag,
                                          MApp_CI_GetCurrentCicamId(), stCiOpInfo.u32CicamIdentifier);
                }
            }
        }

        MApp_CI_SetCurrentCicamId(INVALID_CICAMID);
        g_u32OpCicamIdentifier = 0;
        msAPI_CM_SetCurrentPosition(msAPI_CM_GetCurrentServiceType(), DB_CI_PLUS_SETTING.u16NormalChannelIndex);
        MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
    }

    return TRUE;
}

//BOOL MApp_CI_GetSatInfoByAngle( MW_SI_SAT_PARAM *pstSatParam )

void MApp_CI_EnterCiOperatorProfile( U8 u8Index )
{
    MApp_CI_EnterCIOpServiceMode(u8Index);
}

void MApp_CI_ExitCiOperatorProfile( void )
{
    MApp_CI_ExitCIOpServiceMode();
}

void MApp_CI_CIClearOPSearchSuspended( void )
{
    g_bOpSearchSuspended = FALSE;
    g_u32OpSearchQueryPostEventTimer = 0;
}

#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
static void MApp_CI_CiEventCommandHcTune( void )
{
    U16 u16NetworkID         = 0;
    U16 u16OriginalNetworkID = 0;
    U16 u16TransportStreamID = 0;
    U16 u16ServiceID         = 0;
    if (FALSE == msAPI_CI_HC_GetTuneInfo(&u16NetworkID, &u16OriginalNetworkID, &u16TransportStreamID, &u16ServiceID))
    {
        printf( "[%s:%d][Warning!] Fails to get CI HC Tune info!\n", __FILE__, __LINE__ );
        msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS_ERROR_UNDEFINED);
    }
    else
    {
        if(0 == u16ServiceID)
        {
            U8 u8PhNum=msAPI_CM_GetPhysicalChannelNumberByID(u16OriginalNetworkID,u16TransportStreamID);
            if(INVALID_PHYSICAL_CHANNEL_NUMBER != u8PhNum)
            {
                #if ENABLE_DVBC
                DTVPROGRAMID_M stDPI;
                #endif
                MS_TP_SETTING stTempTP;
                BOOLEAN bFrontEndMuxFound = FALSE;

                memset(&stTempTP, 0x00, sizeof(MS_TP_SETTING)); // fix coverity 207480
                #if ENABLE_DVBC
                if((IsDVBCInUse())
                &&(msAPI_CM_GetIDTable(u8PhNum,(BYTE *)&stDPI,E_DATA_ID_TABLE)))//for DVB-C
                {
                    stTempTP.u32Symbol_rate = stDPI.u32SymbRate;
                    stTempTP.u8Modulation = stDPI.QamMode;
                    stTempTP.u32Frequency = stDPI.u32Frequency;
                    bFrontEndMuxFound = TRUE;
                }
                else
                #endif
                {
                    if((msAPI_DFT_GetTSSetting(u8PhNum, &stTempTP))//for DVB-T
                        &&(msAPI_CM_GetPLPID_WithID(u16TransportStreamID,u16OriginalNetworkID,&(stTempTP.u8PLPID)))
                        &&(msAPI_CM_GetHpLP_WithID(u16TransportStreamID,u16OriginalNetworkID,&(stTempTP.u8HpLp))))

                    {
                        bFrontEndMuxFound = TRUE;
                    }
                }

                if(bFrontEndMuxFound)
                {
                    printf("CI HC Tune chn freq 0x%lx\n",stTempTP.u32Frequency);
                    printf("CI HC Tune chn u8PhNum %bu\n",u8PhNum);
                    MApp_ChannelChange_DisableChannel( TRUE, MAIN_WINDOW );
                    msAPI_Tuner_Tune2RfCh(&stTempTP);
                    MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
                    g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_HC;
                    MApp_CI_CiTuneSignalMonitor();
                    return;
                }
            }
        }
        else
        {
            MEMBER_SERVICETYPE eGotServiceType;
            U16 u16GotPosition;
            BOOLEAN bResult = msAPI_CM_GetServiceTypeAndPositionWithIDs(u16TransportStreamID, u16OriginalNetworkID, u16ServiceID, 1,&eGotServiceType, &u16GotPosition, TRUE);

            if(TRUE == bResult)
            {
                MApp_ChannelChange_ChangeSpeciChannel(u16ServiceID, u16OriginalNetworkID, u16TransportStreamID, TYPE_CHANNEL_CHANGE_SER_ID, TRUE);
                printf( "[%s:%d] CI HC Tune Started!\n", __FILE__, __LINE__ );
                MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
                g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_HC;
                MApp_CI_CiTuneSignalMonitor();
                return;
            }
        }
    }
    printf( "[%s:%d][Warning!] Fails to get CI HC Tune info from Host CMBD!\n", __FILE__, __LINE__ );
    msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS_ERROR_SERVICE_NOT_FOUND);
}
static void MApp_CI_CiEventCommandHcTuneBroadcastReq( void )
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
    g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_HC;
    g_u8OpTuneOriginalDtvRoute = MApp_DVBType_GetCurrentType();
    MApp_CI_CiTuneProcess();
}

static void MApp_CI_CiEventCommandHcCicamPmtParse( void )
{
    MApp_CI_DoCITuneParsePMTStartAVMonitor(TRUE);
}

void MApp_CI_CiEventCommandHcStreamPmtParse( void )
{
    MApp_CI_DoCITuneParsePMTStartAVMonitor(FALSE);
}

void MApp_CI_CiEventCommandHcSiWakeUp( void )
{
    U16 u16ServiceId;
    if(FALSE == msAPI_CI_CardDetect())
    {
        return;
    }

    printf("[CI+][HCv2] Wake up SI monitor...\n");
    u16ServiceId = msAPI_CI_HC_GetBroadcastServiceId();
    if(u16ServiceId != INVALID_SERVICE_ID)
    {
        MApp_Dmx_SetCITuneServiceId(u16ServiceId);
        printf("msAPI_CI_HC_GetBroadcastServiceId:> 0x%x\n",u16ServiceId);
#if 0
        MApp_SI_Reset(SI_RESET_CHNCHANGE);
        MApp_Dmx_EnableTableMonitor();
#else
        MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_TABLE_ALL);
        MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_PAT);
        MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_PMT);
        MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_SDT);
        MApp_Dmx_SetMonitorStatus(TRUE, EN_MONITOR_CI_TUNE);
#endif
        MApp_SI_Force_PAT_Parse();
        MApp_SI_Force_PMT_Parse();
        MApp_SI_Force_SDT_Parse();

        fEnableSignalMonitor = TRUE;

        g_bIsHCNotifyServiceAndDoHss = TRUE;
    }
}

void MApp_CI_CiEventCommandCcPinReply( void )
{
//This function does NOT need to be implemented by NON-PVR host.
}

void MApp_CI_CiEventCallbackOpStatus( void )
{
    CI_OP_STATUS stCiOpStatus;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    memset(&stCiOpStatus, 0x00, sizeof(CI_OP_STATUS));

    if( TRUE == msAPI_CI_OP_GetStatus( &stCiOpStatus ) )
    {
        if (EN_OP_ERROR_FLAG_NO_ERROR != stCiOpStatus.u8ErrorFlag)
        {
            CI_OP_INFO stCiOpInfo;

            printf("[%s:%d][Warning!][CI+][OP] Profile error!\r\n", __FILE__, __LINE__);

            if( TRUE == msAPI_CI_OP_GetInfo( &stCiOpInfo ) )
            {
                // Delete this OP Cache.
                MApp_CI_DeleteOpCacheByCicamId(stCiOpInfo.u32CicamIdentifier);
            }

            return;
        }

        /* CI+ Spec v1.3.1 Chapter 14.7.4.2 Moving between profiles
            The Host may leave an operator profile for another profile or any of its private channel lists. When the Host
            leaves the profile then the following behaviour is required:
            * The CICAM shall not assume that transport streams passing through the CICAM are part of the operator profile environment.
            * The CICAM shall continue to handle the ca_pmt() and descramble content when it is able to.
         => * The Host is not required to maintain the profile environment or process the operator_status() APDU.
        */
        if( 1 == stCiOpStatus.u8InitializedFlag )
        {   // initialised_flag = 1
            CI_OP_INFO stCiOpInfo;

            memset(&stCiOpInfo, 0x00, sizeof(CI_OP_INFO));

            if( TRUE == msAPI_CI_OP_GetInfo( &stCiOpInfo ) )
            { // OP Info is existed!
                MApp_CI_HandleCiOpStatus();
            }
            else
            { // OP Info is not existed!
                msAPI_CI_OP_SendInfoReq();
                g_bOpStatusHandlingSuspended = TRUE;
            }
        }
        else
        {   // initialised_flag = 0 & OP Info is not existed!
            msAPI_CI_OP_SendInfoReq();
            g_bOpStatusHandlingSuspended = TRUE;
        }
    }
    else
    {
        printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Status!\r\n", __FILE__, __LINE__);
    }
}

void MApp_CI_CiEventCallbackOpInfo( void )
{
    CI_OP_INFO stCiOpInfo;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    memset(&stCiOpInfo, 0x00, sizeof(CI_OP_INFO));

    if( TRUE == msAPI_CI_OP_GetInfo( &stCiOpInfo ) )
    {
        CI_OP_STATUS stCiOpStatus;
        memset(&stCiOpStatus, 0x00, sizeof(CI_OP_STATUS));

        if( TRUE == msAPI_CI_OP_GetStatus( &stCiOpStatus ) )
        {
            g_u8OpInfoVersion = stCiOpInfo.u8InfoVersion;

            if( TRUE == g_bOpStatusHandlingSuspended )
            {
                MApp_CI_HandleCiOpStatus();
            }

            if (TRUE == stCiOpStatus.u8ProfileType)
            {
                printf("[CI+][OP] SI updates OP Info.\n");
                MApp_CI_UpdateCIOpInfo( &stCiOpInfo );
            }
        }
        else
        {
            printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Status!\r\n", __FILE__, __LINE__);
        }
    }
    else
    {
        printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Info!\r\n", __FILE__, __LINE__);
    }
}
#endif

void MApp_CI_CiEventCommandOpTune( void )
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if ((E_CI_TUNE_APPLICANT_OP == g_stCiTuneInfo.eCiTuneApplicant) &&
        (0 == g_stCiTuneInfo.u8TuneDescriptorNumber))
    {
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
    }
    g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_OP;
    MApp_CI_CiTuneProcess();
}

#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
void MApp_CI_CiEventCommandOpNit( void )
{
    U16 u16OP_NitLen = OP_MAX_NIT_LEN;
    U8* pu8OP_Nit = NULL;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if( FALSE == msAPI_CI_CardDetect() )
    {
        return;
    }

    pu8OP_Nit = (U8 *)CI_MEMORY_ALLOCATE(OP_MAX_NIT_LEN);

    if(!pu8OP_Nit)
    {
        printf("[%s:%d][Warning][CI+][OP] No Memory!\r\n", __FILE__, __LINE__);
    }

    if(TRUE == msAPI_CI_OP_GetNIT(pu8OP_Nit, &u16OP_NitLen))
    {
        U16 u16NitLastSectionNumber = (U16)pu8OP_Nit[7];
        CI_OP_INFO stCiOpInfo;

        printf("[CI+][OP] Parse NIT Section...\n");
        memset(&stCiOpInfo, 0x00, sizeof(CI_OP_INFO));

        if (TRUE == msAPI_CI_OP_GetInfo(&stCiOpInfo))
        {
            MApp_CI_UpdateCICamNIT(stCiOpInfo.u32CicamIdentifier, pu8OP_Nit, u16OP_NitLen, u16NitLastSectionNumber + 1);
            g_u8OpNitVersion = ( pu8OP_Nit[5] >> 1 ) & 0x1F;
        }

        if (TRUE == g_bOpEntitlementChange)
        {
            // Send operator_entitlement_ack()
            printf("[CI+][OP] Send operator_entitlement_ack()!\r\n");
            msAPI_CI_OP_SendEntitlementAck();
        }
    }
    else
    {
        printf("[%s:%d][Warning!][CI+][OP] Fails to Get NIT!\r\n", __FILE__, __LINE__);
    }

    CI_MEMORY_FREE(pu8OP_Nit);
    pu8OP_Nit = NULL;

    if(TRUE == MApp_GetActiveStandbyMode() && (FALSE == g_bOpEntitlementChange))
    {
        U8 u8RecorderNumInList = 0;
        MApp_EpgTimer_IsRecorderListFull(&u8RecorderNumInList);

        if(0 == u8RecorderNumInList)
        {
            MApp_Standby_Init();
        }
    }
}

void MApp_CI_CiEventCommandOpSearchStatus( void )
{
    CI_OP_STATUS stCiOpSearchStatus;
    BOOL bOPNitReqSent = FALSE;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(g_u8OpTuneOriginalDtvRoute != MApp_DVBType_GetCurrentType())
    {
        printf("[CI+][OP] Switch back to Original DTV Route!\n");

    #if ENABLE_DVBC
        if( EN_DVB_C_TYPE == g_u8OpTuneOriginalDtvRoute )
        {
            MApp_ZUI_ACT_InputSourceSwitch( DTV_DVBC_USE_UI_INPUTSOURCE );
        }
        else
    #endif
        //if(EN_DVB_T_TYPE == g_u8OpTuneOriginalDtvRoute)
        {
        #if 0
            MApp_ZUI_ACT_InputSourceSwitch( UI_INPUT_SOURCE_DTV );
        #else
          #if ENABLE_DVBT
            if( EN_DVB_T_TYPE == g_u8OpTuneOriginalDtvRoute )
            {
                MApp_ZUI_ACT_InputSourceSwitch( DTV_DVBT_USE_UI_INPUTSOURCE );
            }
          #endif
        #endif
        }

        MApp_CI_DoCiTuneBackToOriginalProgram();
    }
    else
    {
        printf("[CI+][OP] Switch back to Original DTV Service!\n");
        MApp_CI_DoCiTuneBackToOriginalProgram();
    }

    memset(&stCiOpSearchStatus, 0x00, sizeof(CI_OP_STATUS));

    if (TRUE == msAPI_CI_OP_GetStatus(&stCiOpSearchStatus))
    {
        if (EN_OP_ERROR_FLAG_NO_ERROR != stCiOpSearchStatus.u8ErrorFlag)
        {
            CI_OP_INFO stCiOpInfo;
            printf("[%s:%d][Warning!][CI+][OP] Profile error!\r\n", __FILE__, __LINE__);

            if (TRUE == msAPI_CI_OP_GetInfo(&stCiOpInfo))
            {
                // Delete this OP Cache.
                MApp_CI_DeleteOpCacheByCicamId(stCiOpInfo.u32CicamIdentifier);
            }

            return;
        }

        g_bOpEntitlementChange = stCiOpSearchStatus.u8EntitlementChangeFlag;

        /* CI+ Spec v1.3.1 Chapter 14.7.5.3 operator_status APDU
            A value of "0" indicates that the profile has not been determined by the CICAM and the Host shall initiate an
            operator_search_start(). A value of "1" indicates that the profile has been determined by the CICAM. When this
            flag is clear other flags of the operator status body shall not be interpreted by the Host.
        */
        printf("[CI+][OP] Operator Status::NIT Version = %u | %u\r\n", g_u8OpNitVersion, stCiOpSearchStatus.u8NitVersion);

        if (1 == stCiOpSearchStatus.u8InitializedFlag)
        {   // initialised_flag = 1
            // Check refresh_request_flag
            switch (stCiOpSearchStatus.u8RefreshRequestFlag)
            {
                case EN_OP_REFRESH_REQUEST_FLAG_DEFAULT:
                {
                    /* CI+ Spec v1.3.1 Chapter 14.7.5.3 operator_status APDU
                        nit_version: The Host shall monitor this field and shall respond to any
                        change in the same manner as a NIT table update in a conventional broadcast network.
                        If the CICAM is not delivering a NIT then the field shall be zero and shall not be interpreted by the Host.
                    */
                    if ((EN_OP_TYPE_1 == stCiOpSearchStatus.u8ProfileType)
                        && (g_u8OpNitVersion != stCiOpSearchStatus.u8NitVersion))
                    {
                        // Send operator_nit_req()
                        printf("[CI+][OP] Send operator_nit_req()!\r\n");
                        msAPI_CI_OP_SendNitReq();
                        bOPNitReqSent = TRUE;
                    }
                }
                break;
                case EN_OP_REFRESH_REQUEST_FLAG_ADVANCE_WARNING:
                case EN_OP_REFRESH_REQUEST_FLAG_URGENT_REQUEST:
                {
                    if (EN_OP_REFRESH_REQUEST_FLAG_ADVANCE_WARNING == stCiOpSearchStatus.u8RefreshRequestFlag)
                    {
                        printf("[CI+][OP] Operator Status::refresh_request_flag is ADVANCE WARNING of OP Refresh!\n");
                    }
                    else if (EN_OP_REFRESH_REQUEST_FLAG_URGENT_REQUEST == stCiOpSearchStatus.u8RefreshRequestFlag)
                    {
                        printf("[CI+][OP] Operator Status::refresh_request_flag is URGENT REQUEST of OP Refresh!\n");
                    }

                    /* Different handling for FTA and CA services. */
                    {
                        DTV_CHANNEL_INFO stDtvProgInfo;
                        MEMBER_SERVICETYPE nCurServiceType = msAPI_CM_GetCurrentServiceType();
                        WORD u16CurPosition = msAPI_CM_GetCurrentPosition( nCurServiceType );

                        if( TRUE == msAPI_CM_GetProgramInfo( nCurServiceType, u16CurPosition, &stDtvProgInfo ) )
                        {
                            if (FALSE == stDtvProgInfo.stCHAttribute.bIsScramble)
                            {
                                /* CI+ Spec v1.3.1 14.7.5.3 operator_status APDU
                                    A Free-to-air service.
                                */
                                printf("[%s:%d][Warning!][CI+][OP] Reject URGENT REQUEST of OP Refresh for FTA Service!\r\n", __FILE__, __LINE__);
                                return;
                            }
                            else
                            {
                                if( FALSE == MApp_TV_IsProgramRunning() )
                                {
                                    /* CI+ Spec v1.3.1 14.7.5.3 operator_status APDU
                                        A CA Service not owned by the operator profile CICAM - As Free-to-air service.
                                    */
                                    printf("[%s:%d][Warning!][CI+][OP] Reject URGENT REQUEST of OP Refresh for Scrambled Service!\r\n", __FILE__, __LINE__);
                                }
                                else
                                {
                                    /* CI+ Spec v1.3.1 14.7.5.3 operator_status APDU
                                        A CA Service owned by the operator profile CICAM.
                                    */
                                    printf("[CI+][OP] Accept OP Refresh Request for Scrambled Service!\r\n");
                                    g_u32OpSearchQueryPostEventTimer = msAPI_Timer_GetTime0();
                                    g_bOpSearchSuspended = TRUE;
                                    MApp_ZUI_ACT_OPRefreshQueryUI();
                                }
                            }
                        }
                        else
                        {
                            /* Assume that Host has no service! */
                            printf("[%s:%d][Warning!][CI+][OP] Accept URGENT REQUEST of OP Refresh for No Service!\r\n", __FILE__, __LINE__);
                        }
                    }
                }
                break;
                case EN_OP_REFRESH_REQUEST_FLAG_SCHEDULED_REQUEST:
                {
                    printf("[CI+][OP] Operator Status::refresh_request_flag is SCHEDULED REQUEST\n");
                    // FIXME: Need System Handling

                }
                break;
                default:
                {
                    printf("[%s:%d][Warning!][CI+][OP] Error refresh_request_flag: %02X!\r\n", __FILE__, __LINE__, stCiOpSearchStatus.u8RefreshRequestFlag);
                }
                return;
            }

            // Check entitlement_change_flag
            if ((EN_OP_REFRESH_REQUEST_FLAG_DEFAULT == stCiOpSearchStatus.u8RefreshRequestFlag) && (FALSE == bOPNitReqSent) && (1 == stCiOpSearchStatus.u8EntitlementChangeFlag))
            {
                // Send operator_entitlement_ack()
                printf("[CI+][OP] Send operator_entitlement_ack()!\r\n");
                msAPI_CI_OP_SendEntitlementAck();
            }
        }
    }
    else
    {
        printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Status!\r\n", __FILE__, __LINE__);
    }

    if(FALSE == bOPNitReqSent)
    {
        if(TRUE == MApp_GetActiveStandbyMode() && (FALSE == g_bOpEntitlementChange))
        {
            U8 u8RecorderNumInList = 0;
            MApp_EpgTimer_IsRecorderListFull(&u8RecorderNumInList);

            if(0 == u8RecorderNumInList)
            {
                MApp_Standby_Init();
            }
        }
    }
}

void MApp_CI_CiEventCommandOpNitCheck( void )
{
    U32 u32OpCicamIdentifier = 0;
    U8 u8OpCacheCount = 0;
    U8 i, j;
    MS_CI_PLUS_SETTING CI_Setting;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    msAPI_CI_CC_SaveKeyToFlash(CI_Setting.stKeySetting, FALSE);
    u8OpCacheCount = MApp_CI_GetOpCacheCount();

    for (i = 0; i < u8OpCacheCount; i++)
    {
        j = 0;

        MApp_CI_GetOpCicamIdByIndex(i, &u32OpCicamIdentifier);

        for (j = 0; j < CI_CC_KEY_NUM; j++)
        {
            if (u32OpCicamIdentifier == CI_Setting.stKeySetting[j].u32OpCicamIdentifier)
            {
                break;
            }
        }

        if (CI_CC_KEY_NUM == j)
        {
            MApp_CI_DeleteOpCacheByCicamId(u32OpCicamIdentifier);
        }
    }
}

void MApp_CI_HandleCiOpStatus( void )
{
    CI_OP_STATUS stCiOpStatus;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    memset(&stCiOpStatus, 0x00, sizeof(CI_OP_STATUS));
    g_bOpStatusHandlingSuspended = FALSE;

    if (TRUE == msAPI_CI_OP_GetStatus(&stCiOpStatus))
    {
        g_bOpEntitlementChange = stCiOpStatus.u8EntitlementChangeFlag;

        /* CI+ Spec v1.3.1 Chapter 14.7.5.3 operator_status APDU
            A value of "0" indicates that the profile has not been determined by the CICAM and the Host shall initiate an
            operator_search_start(). A value of "1" indicates that the profile has been determined by the CICAM. When this
            flag is clear other flags of the operator status body shall not be interpreted by the Host.
        */
        printf("[CI+][OP] Operator Status::NIT Version = %u | %u\r\n", g_u8OpNitVersion, stCiOpStatus.u8NitVersion);

        if (0 == stCiOpStatus.u8InitializedFlag)
        {   // initialised_flag = 0
            /* CI+ Spec v1.3.1 Chapter 14.7.4.1.3 Profile Discovery Figure 14.14: Profile Discovery APDU sequence
                Host initiates a search if the operator status is un-initialised.
            */
            printf("[CI+][OP] Accept OP Refresh Request for un-initialised OP CICAM!\r\n");
            g_u32OpSearchQueryPostEventTimer = msAPI_Timer_GetTime0();
            g_bOpSearchSuspended = TRUE;
            MApp_ZUI_ACT_OPRefreshQueryUI();
        }
        else
        {   // initialised_flag = 1
            BOOL bOPNitReqSent = FALSE;
            CI_OP_INFO stCiOpInfo;
            memset(&stCiOpInfo, 0x00, sizeof(CI_OP_INFO));

            if (TRUE == msAPI_CI_OP_GetInfo(&stCiOpInfo))
            { // OP Info is existed!
                /* CI+ Spec v1.3.1 Chapter 14.7.4.2 Moving between profiles
                    The Host may leave an operator profile for another profile or any of its private channel lists. When the Host
                    leaves the profile then the following behaviour is required:
                    * The CICAM shall not assume that transport streams passing through the CICAM are part of the operator profile environment.
                    * The CICAM shall continue to handle the ca_pmt() and descramble content when it is able to.
                 => * The Host is not required to maintain the profile environment or process the operator_status() APDU.
                */
                //FIXME_CI
                //if ((TRUE == GetCiOperatorProfileStatus()) && (stCiOpInfo.u32CicamIdentifier == m_u32OpCicamIdentifier))
                { // In Profile
                    if (stCiOpStatus.u8InfoVersion != g_u8OpInfoVersion)
                    {
                        msAPI_CI_OP_SendInfoReq();
                    }
                }
            }
            else
            { // OP Info is not existed!
                printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Info!\r\n", __FILE__, __LINE__);
            }

            // Check refresh_request_flag
            switch (stCiOpStatus.u8RefreshRequestFlag)
            {
                case EN_OP_REFRESH_REQUEST_FLAG_DEFAULT:
                {
                    /* CI+ Spec v1.3.1 Chapter 14.7.5.3 operator_status APDU
                        nit_version: The Host shall monitor this field and shall respond to any
                        change in the same manner as a NIT table update in a conventional broadcast network.
                        If the CICAM is not delivering a NIT then the field shall be zero and shall not be interpreted by the Host.
                    */
                    if ((EN_OP_TYPE_1 == stCiOpStatus.u8ProfileType)
                        && (g_u8OpNitVersion != stCiOpStatus.u8NitVersion))
                    {
                        // Send operator_nit_req()
                        printf("[CI+][OP] Send operator_nit_req()!\r\n");
                        msAPI_CI_OP_SendNitReq();
                        bOPNitReqSent = TRUE;
                    }
                }
                break;
                case EN_OP_REFRESH_REQUEST_FLAG_ADVANCE_WARNING:
                case EN_OP_REFRESH_REQUEST_FLAG_URGENT_REQUEST:
                {
                    if (EN_OP_REFRESH_REQUEST_FLAG_ADVANCE_WARNING == stCiOpStatus.u8RefreshRequestFlag)
                    {
                        printf("[CI+][OP] Operator Status::refresh_request_flag is ADVANCE WARNING of OP Refresh!\n");
                    }
                    else if (EN_OP_REFRESH_REQUEST_FLAG_URGENT_REQUEST == stCiOpStatus.u8RefreshRequestFlag)
                    {
                        printf("[CI+][OP] Operator Status::refresh_request_flag is URGENT REQUEST of OP Refresh!\n");
                    }

                    /* Different handling for FTA and CA services. */
                    {
                        DTV_CHANNEL_INFO stDtvProgInfo;
                        MEMBER_SERVICETYPE nCurServiceType = msAPI_CM_GetCurrentServiceType();
                        WORD u16CurPosition = msAPI_CM_GetCurrentPosition( nCurServiceType );

                        if( TRUE == msAPI_CM_GetProgramInfo( nCurServiceType, u16CurPosition, &stDtvProgInfo ) )
                        {
                            if (FALSE == stDtvProgInfo.stCHAttribute.bIsScramble)
                            {
                                /* CI+ Spec v1.3.1 14.7.5.3 operator_status APDU
                                    A Free-to-air service.
                                */
                                printf("[%s:%d][Warning!][CI+][OP] Reject URGENT REQUEST of OP Refresh for FTA Service!\r\n", __FILE__, __LINE__);
                                return;
                            }
                            else
                            {
                                /* CI+ Spec v1.3.1 14.7.5.3 operator_status APDU
                                    A CA Service owned by the operator profile CICAM.
                                */
                                printf("[CI+][OP] Accept OP Refresh Request for Scrambled Service!\r\n");
                                g_u32OpSearchQueryPostEventTimer = msAPI_Timer_GetTime0();
                                g_bOpSearchSuspended = TRUE;
                                MApp_ZUI_ACT_OPRefreshQueryUI();
                            }
                        }
                        else
                        {
                            /* Assume that Host has no service! */
                            printf("[CI+][OP] Accept OP Refresh Request for No Service!\r\n");
                            g_u32OpSearchQueryPostEventTimer = msAPI_Timer_GetTime0();
                            g_bOpSearchSuspended = TRUE;
                            MApp_ZUI_ACT_OPRefreshQueryUI();
                        }
                    }
                }
                break;
                case EN_OP_REFRESH_REQUEST_FLAG_SCHEDULED_REQUEST:
                {
                    printf("[CI+][OP] Operator Status::refresh_request_flag is SCHEDULED REQUEST of OP Refresh!\n");

                    if (0 != stCiOpStatus.u16RefreshRequestDate)
                    {
                        // [System]FIXME: Need more effort for CI+ OP system
                        U16 u16OpRefreshRequestTime = (stCiOpStatus.u8RefreshRequestTime * 6 + MApp_GetTimeZoneOffset(stGenSetting.g_Time.en_Clock_TimeZone)/60);
                        MS_EPG_TIMER stTimerInfo;
                        U8 u8aMJDUTC[5] = {0x00};

                        memset(&stTimerInfo, 0, sizeof(MS_EPG_TIMER));

                        /* CI+ Spec v1.3.1 14.7.5.3 operator_status APDU
                            refresh_request_date: This 16-bit field indicates the date of the next scheduled refresh cycle requested by the
                                CICAM. The date is specified as UTC Modified Julian Date (MJD) as defined in EN 300 468 [10], Annex C. A
                                value of 0x0000 indicates that no schedule refresh is requested.
                            refresh_request_time: This 8-bit field indicates the time of a scheduled refresh cycle requested by the CICAM.
                                The time is specified in UTC as an integer value in 6 minute intervals from midnight and is valid in the range
                                0..239. This field is only interpreted when the refresh_request_date is non-zero. When the refresh_request_flag
                                is zero then this field shall also be zero.
                                EXAMPLE:    0      00:00 - Midnight
                                            44     04:24 - 24 minutes past 4 in the morning.
                                            239    23:54 - 6 minutes to midnight.
                        */
                        u8aMJDUTC[0] = (U8)(stCiOpStatus.u16RefreshRequestDate >> 8);
                        u8aMJDUTC[1] = (U8)(stCiOpStatus.u16RefreshRequestDate);
                        // UTC is 0:0:0.

                        MApp_ConvertSeconds2StTime(MApp_MJDUTC2Seconds(u8aMJDUTC), &(stTimerInfo.stStartDate));
                        stTimerInfo.stStartDate.u8Hour = u16OpRefreshRequestTime / 60;
                        stTimerInfo.stStartDate.u8Min = u16OpRefreshRequestTime % 60;
                        stTimerInfo.stStartDate.u8Sec = 0;
                        printf("[CI+][OP] SCHEDULED Time of OP Refresh: %u/%u/%u %u:%u:%u\n",
                                              stTimerInfo.stStartDate.u16Year, stTimerInfo.stStartDate.u8Month, stTimerInfo.stStartDate.u8Day,
                                              stTimerInfo.stStartDate.u8Hour, stTimerInfo.stStartDate.u8Min, stTimerInfo.stStartDate.u8Sec);
                        stTimerInfo.stEndDate = stTimerInfo.stStartDate;
                        stTimerInfo.enRepeatMode = EN_EPGRM_ONCE;
                        stTimerInfo.enTimerType = EN_EPGUI_TIMER_CI_OP_REFRESH;
                        stTimerInfo.u16SrvID = 0;
//                        stTimerInfo.u8ServiceType = 0;
//                        stTimerInfo.u32DurationTime = 0; //not useful in reminder
//                        stTimerInfo.bIsEndTimeBeforeStart = FALSE; //not useful in reminder

                        if(TRUE == MApp_EpgTimer_AddEpgEvent(&stTimerInfo))
                        {
                            printf("[CI+][OP] Succeed in installing Scheduled OP Refresh!\r\n");
                        }
                        else
                        {
                            printf("[%s:%d][Warning!][CI+][OP] Fails to install Scheduled OP Refresh!\r\n", __FILE__, __LINE__);
                        }
                    }
                }
                break;
                default:
                {
                    printf("[%s:%d][Warning!][CI+][OP] Error refresh_request_flag: %02X!\r\n", __FILE__, __LINE__, stCiOpStatus.u8RefreshRequestFlag);
                }
                return;
            }

            // Check entitlement_change_flag
            if ((EN_OP_REFRESH_REQUEST_FLAG_DEFAULT == stCiOpStatus.u8RefreshRequestFlag) && (FALSE == bOPNitReqSent))
            {
                if (TRUE == g_bOpEntitlementChange)
                {
                    // Send operator_entitlement_ack()
                    printf("[CI+][OP] Send operator_entitlement_ack()!\r\n");
                    msAPI_CI_OP_SendEntitlementAck();
                }
                else
                {
                    /* If Host system is In-Profile but the CI+ CAM which owns the profile is Out-Profile, Host shall notify CI+ CAM through operator_status_req(). */
                    if ((FALSE == msAPI_CI_OP_IsCicamInProfile()) && (TRUE == MApp_CI_IsOpMode()))
                    {
                        CI_OP_INFO stLocalCiOpInfo;

                        memset(&stLocalCiOpInfo, 0x00, sizeof(CI_OP_INFO));
                        if (TRUE == msAPI_CI_OP_GetInfo(&stLocalCiOpInfo))
                        {
                            if (g_u32OpCicamIdentifier == stLocalCiOpInfo.u32CicamIdentifier)
                            {
                                // Send operator_status_req()
                                printf("[CI+][OP] Send operator_status_req()!\r\n");
                                msAPI_CI_OP_SendStatusReq();
                            }
                            else
                            {
                                printf("[CI+][OP] The OP doesn't belong to the CI+ CAM: %08lX | %08lX!\n",
                                                      g_u32OpCicamIdentifier, stLocalCiOpInfo.u32CicamIdentifier);
                            }
                        }
                        else
                        {
                            printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Info!\r\n", __FILE__, __LINE__);
                        }
                    }
                    if(TRUE == MApp_GetActiveStandbyMode() && (FALSE == g_bOpEntitlementChange))
                    {
                        MApp_Standby_Init();
                    }
                }
            }
        }
    }
    else
    {
        printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Status!\r\n", __FILE__, __LINE__);
    }
}

static BOOL MApp_CI_UpdateCIOpInfo(CI_OP_INFO* stCiOpInfo)
{
    return msAPI_OP_UpdateCIOpInfo(stCiOpInfo);
}
static BOOL MApp_CI_GetOpCicamIdByIndex(U8 u8Index , U32* u32CicamId)
{
    MW_OPCACHE_INFO stOpCacheInfo;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(TRUE == msAPI_OP_GetOpCacheInfoByIndex(u8Index, &stOpCacheInfo))
    {
        *u32CicamId = stOpCacheInfo.stCiOpInfo.u32CicamIdentifier;
        return TRUE;
    }

    return FALSE;
}

static BOOL MApp_CI_UpdateCICamNIT(U32 u32CicamId, U8 *pu8NitSection, U16 u16SecLen, U16 u16SecCount)
{
    BOOL bRet = FALSE;
    EN_DELIVERY_SYS_TYPE eDtvSystemType = E_DELIVERY_SYS_NONE;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if((pu8NitSection == NULL) || (u16SecLen == 0) ||(u16SecCount == 0))
    {
        return FALSE;
    }

    EN_SI_DELIVERY_SYS_TYPE eTmpType = MApp_SI_GetDeliveryTypeFromNIT(pu8NitSection, u16SecCount);
    eDtvSystemType = msAPI_SI_ToCM_Delivery_Type(eTmpType);

    printf("[CI+][OP] DTV System Type = %d!\n", eDtvSystemType);
    bRet = msAPI_OP_UpdateCICamNIT(u32CicamId, pu8NitSection, u16SecLen, u16SecCount,eDtvSystemType);

    if((bRet == TRUE) && (TRUE == MApp_CI_IsOpMode()) && (u32CicamId == MApp_CI_GetCurrentOpCicamId()))
    {
        //msAPI_CM_ResetDTVDataManager(FALSE);
        MApp_SI_CICAM_NIT_Parse(pu8NitSection, u16SecCount);
    }

    return bRet;
}
#endif

BOOL MApp_CI_CiTuneProcess( void )
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);
    printf("[CI+] m_stCiTuneInfo.eCiTuneApplicant: %u\n", g_stCiTuneInfo.eCiTuneApplicant);

    if(FALSE == MApp_CI_CiTuneInitialize())
    {
        printf("[%s:%d][CI+] %s Fails!\n", __FILE__, __LINE__, __FUNCTION__);
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        return FALSE;
    }

    if(FALSE == MApp_CI_CiTuneFilter())
    {
        printf("[%s:%d][CI+] %s Fails!\n", __FILE__, __LINE__, __FUNCTION__);
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        return FALSE;
    }

    if(FALSE == MApp_CI_CiTuneParsing())
    {
        printf("[%s:%d][CI+] %s Fails!\n", __FILE__, __LINE__, __FUNCTION__);
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        return FALSE;
    }

    if(FALSE == MApp_CI_CiTuneEnableFrontend())
    {
        printf("[%s:%d][CI+] %s Fails!\n", __FILE__, __LINE__, __FUNCTION__);
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        return FALSE;
    }
    return TRUE;
}

BOOL MApp_CI_CiTuneInitialize( void )
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if( FALSE == msAPI_CI_CardDetect() )
    {
        printf("\x1b[37;41m [%s:%s:%d] CICAM not exist \x1b[0m\n",__FILE__,__FUNCTION__,__LINE__);
        return FALSE;
    }

    if (0 == g_stCiTuneInfo.u8TuneDescriptorNumber)
    {
        // Initial OP Tune - Initialize OP Tune Info
        if (NULL != g_stCiTuneInfo.pu8TuneDescriptors)
        {
            CI_MEMORY_FREE(g_stCiTuneInfo.pu8TuneDescriptors);
            g_stCiTuneInfo.pu8TuneDescriptors = NULL;
        }
        g_stCiTuneInfo.u16TuneDescriptorsLen = CI_TUNE_DESCRIPTORS_MAX_LEN;
        g_stCiTuneInfo.pu8TuneDescriptors = (U8 *)CI_MEMORY_ALLOCATE(CI_TUNE_DESCRIPTORS_MAX_LEN);
        if (NULL == g_stCiTuneInfo.pu8TuneDescriptors)
        {
            printf("[%s:%d][CI+][Tune][Warning!] No Memory: %u bytes!\n", __FILE__, __LINE__,  CI_TUNE_DESCRIPTORS_MAX_LEN);
            return FALSE;
        }
        memset(g_stCiTuneInfo.pu8TuneDescriptors, 0x00, CI_TUNE_DESCRIPTORS_MAX_LEN);
        // Get Tune Descriptor from CI library.
        switch(g_stCiTuneInfo.eCiTuneApplicant)
        {
            case E_CI_TUNE_APPLICANT_HC:
                if( FALSE == msAPI_CI_HC_GetTuneDescriptor(g_stCiTuneInfo.pu8TuneDescriptors, &(g_stCiTuneInfo.u16TuneDescriptorsLen) ) )
                {
                    printf("[%s:%d][CI+][HC][Warning!] Fails to get HC Tune Descriptor!\n", __FILE__, __LINE__);
                    return FALSE;
                }
                break;
            case E_CI_TUNE_APPLICANT_OP:
                if( FALSE == msAPI_CI_OP_GetTuneDescriptor(g_stCiTuneInfo.pu8TuneDescriptors, &(g_stCiTuneInfo.u16TuneDescriptorsLen) ) )
                {
                    printf("[%s:%d][CI+][OP][Warning!] Fails to get OP Tune Descriptor!\n", __FILE__, __LINE__);
                    return FALSE;
                }
                break;
             default:
                printf("[%s:%d][CI+][ERROR!] Unknown tag %d!\n", __FILE__, __LINE__, g_stCiTuneInfo.eCiTuneApplicant);
                return FALSE;

        }
    }

    if ((NULL == g_stCiTuneInfo.pu8TuneDescriptors) || (0 == g_stCiTuneInfo.u16TuneDescriptorsLen))
    {
        switch(g_stCiTuneInfo.eCiTuneApplicant)
        {
            case E_CI_TUNE_APPLICANT_HC:
                printf("[%s:%d][CI+][HCv2][Warning!] The Host has reached the end of Descriptors!\n", __FILE__, __LINE__);
                /* CI+ Spec v1.3 Figure 14.10: Tuning process with Host Control Version 2 (informative)
                    (11) Host sends tune_reply() with Error 01 (unsupported delivery system)
                */
                printf("[CI+][HCv2] (XX) Host sends tune_reply() with Error 06 \n");
                msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS_ERROR_UNDEFINED);
                break;
            case E_CI_TUNE_APPLICANT_OP:
                printf("[%s:%d][CI+][OP][Warning!] The Host has reached the end of OP Tune!\n", __FILE__, __LINE__);
                msAPI_CI_OP_SendTuneStatus(OP_INVALID_DESCRIPTOR_NUMBER, 0, 0, EN_OP_TUNE_STATUS_NG_OPERATION_FAILED, NULL, 0);
                break;
             default:
                printf("[%s:%d][CI+][ERROR!] Unknown tag %d!\n", __FILE__, __LINE__, g_stCiTuneInfo.eCiTuneApplicant);
                return FALSE;
        }
        return FALSE;
    }

    return TRUE;
}

BOOL MApp_CI_CiTuneFilter( void )
{
    /* CI+ Spec v1.3 Chapter 14.7.5.11 operator_tune APDU
        Loop over all of the descriptors in the APDU.
    */
    U8 u8HandlingDesciptorLength = g_stCiTuneInfo.pu8TuneDescriptors[1]; // 1 byte desciptor_tag + 1 byte desciptor_length
    S32 s32OpTuneDescriptorsLen = g_stCiTuneInfo.u16TuneDescriptorsLen;
    U8* pu8NextLocationInfo = NULL;
    BOOL bUnsupportedTuneDescriptor = FALSE;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    g_stCiTuneInfo.u8TuneDescriptorNumber++;
    if ((s32OpTuneDescriptorsLen - (1 + 1 + u8HandlingDesciptorLength)) > 0)  // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body
    {
        // There are more OP Tune Descriptors. Need to check and remove duplicated OP Tune Descriptors.
        pu8NextLocationInfo = g_stCiTuneInfo.pu8TuneDescriptors + (1 + 1 + u8HandlingDesciptorLength); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body
        while (NULL != pu8NextLocationInfo)
        {
            if(0 == memcmp(g_stCiTuneInfo.pu8TuneDescriptors, pu8NextLocationInfo, (1 + 1 + u8HandlingDesciptorLength)))
            {
                printf("[CI+][Tune]Skip duplicated Tune Descriptor: %02X!\n", g_stCiTuneInfo.u8TuneDescriptorNumber);
            }
            else
            {
                switch((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]))
                {
                    case TAG_TDSD:
                    case TAG_SDSD:
                    case TAG_S2DSD:
                    case TAG_CDSD:
                        return TRUE;
                    case TAG_ED:
                        switch((EN_DESCRIPTOR_TAG_EXT)(g_stCiTuneInfo.pu8TuneDescriptors[2]))
                        {
                            case TAG_T2DSD:
                            case TAG_C2DSD:
                                return TRUE;
                            default:
                                printf("[CI+][Tune]Skip Non-Tune Descriptor: %02X!\n", g_stCiTuneInfo.u8TuneDescriptorNumber);
                                break;
                        }
                        break;
                    default:
                        printf("[CI+][Tune]Skip Non-Tune Descriptor: %02X!\n", g_stCiTuneInfo.u8TuneDescriptorNumber);
                        break;
                }
            }
            g_stCiTuneInfo.u16TuneDescriptorsLen -= (1 + 1 + u8HandlingDesciptorLength);

            {
                int i;

                for(i = 0; i < g_stCiTuneInfo.u16TuneDescriptorsLen; ++i)
                {
                    g_stCiTuneInfo.pu8TuneDescriptors[i] = pu8NextLocationInfo[i];
                }
            }

            g_stCiTuneInfo.u8TuneDescriptorNumber++;
            u8HandlingDesciptorLength = g_stCiTuneInfo.pu8TuneDescriptors[1]; // 1 byte desciptor_tag + 1 byte desciptor_length
            s32OpTuneDescriptorsLen = g_stCiTuneInfo.u16TuneDescriptorsLen;
            if ((s32OpTuneDescriptorsLen - (1 + 1 + u8HandlingDesciptorLength)) > 0)
            {
                pu8NextLocationInfo = g_stCiTuneInfo.pu8TuneDescriptors + (1 + 1 + u8HandlingDesciptorLength); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body
            }
            else
            {
                pu8NextLocationInfo = NULL;
            }
        }
    }

    if (NULL == pu8NextLocationInfo)
    {
        g_stCiTuneInfo.u8TuneDescriptorNumber = OP_INVALID_DESCRIPTOR_NUMBER;
    }

    switch((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]))
    {
        case TAG_TDSD:
        case TAG_SDSD:
        case TAG_S2DSD:
        case TAG_CDSD:
            break;
        case TAG_ED:
            switch((EN_DESCRIPTOR_TAG_EXT)(g_stCiTuneInfo.pu8TuneDescriptors[2]))
            {
                case TAG_T2DSD:
                //case TAG_C2DSD:
                    break;
                default:
                    bUnsupportedTuneDescriptor = TRUE;
                    break;
            }
            break;
        default:
            bUnsupportedTuneDescriptor = TRUE;
            break;
    }

    if (TRUE == bUnsupportedTuneDescriptor)
    {
        MApp_CI_CiTuneUnsupportReply();
        return FALSE;
    }
    else
        return TRUE;
}

BOOL MApp_CI_CiTuneParsing( void )
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(FALSE == msAPI_CI_CardDetect())
    {
        printf("\x1b[37;41m [%s:%s:%d] CICAM not exist \x1b[0m\n",__FILE__,__FUNCTION__,__LINE__);
        return FALSE;
    }

    // Parsing descriptor.
    switch((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]))
    {
        // terrestrial_delivery_system_descriptor (DVB-T)
        case TAG_TDSD:
        {
            DESC_TERR_DEL_SYS ustDesciptor;

            if (FALSE == MApp_Dmx_GetDeliveryDescriptorData((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]), &ustDesciptor, &(g_stCiTuneInfo.pu8TuneDescriptors[0])))
            {
                MApp_CI_CiTuneParameterInvalidReply();
                return FALSE;
            }

            return MApp_CI_CiTuneSetMuxDVBT(&ustDesciptor);
        }

        // cable_delivery_system_descriptor (DVB-C)
    #if (ENABLE_DVBC)
        case TAG_CDSD:
        {
            DESC_CABLE_DEL_SYS ustDesciptor;

            if (FALSE == MApp_Dmx_GetDeliveryDescriptorData((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]), &ustDesciptor, &(g_stCiTuneInfo.pu8TuneDescriptors[0])))
            {
                MApp_CI_CiTuneParameterInvalidReply();
                return FALSE;
            }

            return MApp_CI_CiTuneSetMuxDVBC(&ustDesciptor);
        }
    #endif

	#if (ENABLE_DVB_T2)
        case TAG_ED:
        {
            // T2_delivery_system_descriptor (DVB-T2)
            if(TAG_T2DSD == (EN_DESCRIPTOR_TAG_EXT)(g_stCiTuneInfo.pu8TuneDescriptors[2]))
            {
                DESC_T2_DEL_SYS ustDesciptor;

                if (FALSE == MApp_Dmx_GetDeliveryDescriptorData((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]), &ustDesciptor, &(g_stCiTuneInfo.pu8TuneDescriptors[0])))
                {
                    MApp_CI_CiTuneParameterInvalidReply();
                    return FALSE;
                }

                return MApp_CI_CiTuneSetMuxDVBT2(&ustDesciptor);
            }
            break;
        }
	#endif

    #if (ENABLE_S2)
        // satellite_delivery_system_descriptor (DVB-S)
        case TAG_SDSD:
        {
            DESC_SATELLITE_DEL_SYS ustDesciptor;

            if (FALSE == MApp_Dmx_GetDeliveryDescriptorData((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]), &ustDesciptor, &(g_stCiTuneInfo.pu8TuneDescriptors[0])))
            {
                MApp_CI_CiTuneParameterInvalidReply();
                return FALSE;
            }

            return MApp_CI_CiTuneSetMuxDVBS(&ustDesciptor);
        }
        break;

        // S2_satellite_delivery_system_descriptor (DVB-S2)
        case TAG_S2DSD:
        {
            DESC_SATELLITE_DEL_SYS ustDesciptor;

            if (FALSE == MApp_Dmx_GetDeliveryDescriptorData((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]), &ustDesciptor, &(g_stCiTuneInfo.pu8TuneDescriptors[0])))
            {
                MApp_CI_CiTuneParameterInvalidReply();
                return FALSE;
            }

            return MApp_CI_CiTuneSetMuxDVBS(&ustDesciptor);
        }
        break;
    #endif

        default:
            printf("[%s:%d][CI+][ERROR!] Unknown tag %d!\n", __FILE__, __LINE__, g_stCiTuneInfo.pu8TuneDescriptors[0]);
            break;
    }
    MApp_CI_CiTuneUnsupportReply();
    return FALSE;
}

BOOL MApp_CI_CiTuneEnableFrontend( void )
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    // DisableChannel (disable SI parser)
    MApp_ChannelChange_DisableChannel( TRUE, MAIN_WINDOW );

    MS_TP_SETTING stTPSetting;
    stTPSetting.u32Frequency = g_stCiTuneInfo.stCiTuneMux.u32Frequency; ///< Frequency, 50,000 ~ 860,000 Khz
    stTPSetting.enBandWidth = (RF_CHANNEL_BANDWIDTH)g_stCiTuneInfo.stCiTuneMux.u8Bandwidth;   ///< Bandwidth
    stTPSetting.u8PLPID = g_stCiTuneInfo.stCiTuneMux.u16PlpID;
    stTPSetting.u8HpLp = 0;
#if ENABLE_DVBC
    stTPSetting.u8Modulation = g_stCiTuneInfo.stCiTuneMux.u8ModulationMode;
    stTPSetting.u32Symbol_rate = g_stCiTuneInfo.stCiTuneMux.u32SymbRate;
    stTPSetting.bAutoSRFlag = FALSE;
    stTPSetting.bAutoQamFlag = FALSE;
#else
    stTPSetting.u32Symbol_rate = 0;
#endif

    // Reset variable
    msAPI_Tuner_InitCurrentTPSetting();

    // Set CI tune to off
    msAPI_DTV_Comm_SetCiTuneStatus(FALSE);

    // Switch Demod type ...
#if ENABLE_S2
    if( IsS2InUse() ) // DVBS
    {
        msAPI_Tuner_SwitchSource(EN_DVB_T_TYPE, TRUE);
    }
    else
#endif

#if ENABLE_DVBC
    if(stTPSetting.u32Symbol_rate > 0)
    {
        msAPI_Tuner_SwitchSource(EN_DVB_C_TYPE, TRUE);
    }
    else
#endif
    {
        msAPI_DTV_Comm_SetCiTuneStatus(TRUE);
        msAPI_DTV_Comm_SetPLPID(stTPSetting.u8PLPID);

		msAPI_Tuner_SwitchSource(EN_DVB_T_TYPE, TRUE);
	#if ENABLE_DVB_T2
        if (mdev_Cofdm_MSB123X_Ready() && (stTPSetting.u8PLPID != 0xFF))
        {
            MApp_DTV_Scan_T2_SetForceMonitorT2Signal(TRUE);
            mdev_CofdmSetPlpGroupID(stTPSetting.u8PLPID,0);
            MAPP_DTV_Scan_T2_DoScan(DVB_T2_DEMOD,FALSE);
            MAPP_DTV_Scan_T2_SetServiceType(DVBT2_SERVICE);
        }
        else
        {
            MApp_DTV_Scan_T2_SetForceMonitorT2Signal(FALSE);
            MAPP_DTV_Scan_T2_DoScan(DVB_T_DEMOD,FALSE);
            MAPP_DTV_Scan_T2_SetServiceType(DVBT_SERVICE);
        }
	#endif//ENABLE_DVB_T2
    }

#if ENABLE_S2
    if( IsS2InUse() ) // DVBS
    {
        MS_SAT_PARAM stMS_SAT_PARAM;
        DTVPROGRAMID_M stDTVPROGRAMID_M;

        memset(&stMS_SAT_PARAM, 0x00, sizeof(stMS_SAT_PARAM)); // fix coverity 207476
        memset(&stDTVPROGRAMID_M, 0x00, sizeof(stDTVPROGRAMID_M));

        MApi_DigiTuner_Get_CurSATInfo(&stMS_SAT_PARAM);

        stDTVPROGRAMID_M.u32S2Frequency = g_stCiTuneInfo.stCiTuneMux.u32Frequency;
        stDTVPROGRAMID_M.u8Polarity = g_stCiTuneInfo.stCiTuneMux.bPolarity;
        stDTVPROGRAMID_M.u16SymbolRate = g_stCiTuneInfo.stCiTuneMux.u32SymbRate;

        MApi_DigiTuner_Tune2RfCh(stMS_SAT_PARAM, &stDTVPROGRAMID_M, FE_TUNE_AUTO);
    }
    else
#endif
    {
        msAPI_Tuner_Tune2RfCh(&stTPSetting);
    }

    MApp_CI_CiTuneSignalMonitor();

    return TRUE;
}

#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
void MApp_CI_DoCiTuneBackToOriginalProgram( void )
{
//    printf("[CI+][OP] After finish CI Tune, system should tune back to original program (%d).\n", g_stCiTuneOriginalProgInfo.u16Number);
	msAPI_Tuner_Initialization_BySource();
    msAPI_Tuner_Tune2RfCh(&g_stCiTuneOriginalProgInfo);
    MApp_ChannelChange_EnableChannel(MAIN_WINDOW);
}
#endif

BOOL MApp_CI_CiTuneParameterInvalidReply( void )
{
    U8 u8HandlingDesciptorLength = g_stCiTuneInfo.pu8TuneDescriptors[1];

    if( FALSE == msAPI_CI_CardDetect() )
    {
        printf("\x1b[37;41m [%s:%s:%d] CICAM not exist \x1b[0m\n",__FILE__,__FUNCTION__,__LINE__);
        return FALSE;
    }

    printf("[CI+][Tune][Warning!] Invalid Parameter!\n");

    switch(g_stCiTuneInfo.eCiTuneApplicant)
    {
        case E_CI_TUNE_APPLICANT_HC:
        {
            /* CI+ Spec v1.3 Figure 14.10: Tuning process with Host Control Version 2 (informative)
                    (10) Host sends tune_reply() with Error 04 (Bad or missing parameters)
                */
            printf("[CI+][HC] (10) Host sends tune_reply() with Error 04 (Bad or missing parameters)\r\n");
            msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS_ERROR_BAD_OR_MISSING_PARAMETERS);
            MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        }
        break;
        case E_CI_TUNE_APPLICANT_OP:
        {
            /* CI+ Spec v1.3 Chapter 14.7.5.11 operator_tune APDU
                    Check the tuning parameters quit if these descriptors are not supported and
                    the CICAM may then re-build the list excluding this delivery location.
                if (current_location_info has bad parameters OR is invalid OR is not supported) {
                        current_location_info = descriptor information + error codes.
                        break;
                }
                */
            printf("[CI+][OP][Warning!] The OP Tune has bad parameters OR is invalid!\n");
            if ((TAG_SDSD == g_stCiTuneInfo.pu8TuneDescriptors[0]) &&
                (g_stCiTuneInfo.pu8TuneDescriptors[1] > 0) &&
                ((g_stCiTuneInfo.pu8TuneDescriptors[8] >> 2 & 0x01) == 0x01) &&// check modulation system : 0x00 : DVB-S , 0x01 : DVB-S2
                (g_stCiTuneInfo.u16TuneDescriptorsLen > (1 + 1 + u8HandlingDesciptorLength)) &&
                (TAG_S2DSD == g_stCiTuneInfo.pu8TuneDescriptors[1 + 1 + u8HandlingDesciptorLength]))
            {
                U8 u8S2DescriptorsLen = g_stCiTuneInfo.pu8TuneDescriptors[1 + 1 + u8HandlingDesciptorLength + 1]; // S2 desciptor_length
                msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, 0, 0, EN_OP_TUNE_STATUS_NG_PARAMETERS_INVALID, g_stCiTuneInfo.pu8TuneDescriptors, 1 + 1 + u8HandlingDesciptorLength + u8S2DescriptorsLen); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body + 1 byte desciptor_tag + 1 byte desciptor_length + u8S2DescriptorsLen bytes S2 desciptor
            }
            else
            {
            msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, 0, 0, EN_OP_TUNE_STATUS_NG_PARAMETERS_INVALID, g_stCiTuneInfo.pu8TuneDescriptors, 1 + 1 + u8HandlingDesciptorLength); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body
            }
            MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        }
        break;
        default:
            printf("[%s:%d][CI+][ERROR!] Unknown tag %d!\n", __FILE__, __LINE__, g_stCiTuneInfo.eCiTuneApplicant);
            return FALSE;
    }

    return TRUE;
}

BOOL MApp_CI_CiTuneUnsupportReply( void )
{
    U8 u8HandlingDesciptorLength = g_stCiTuneInfo.pu8TuneDescriptors[1];
    if( FALSE == msAPI_CI_CardDetect() )
    {
        printf("\x1b[37;41m [%s:%s:%d] CICAM not exist \x1b[0m\n",__FILE__,__FUNCTION__,__LINE__);
        return FALSE;
    }

    printf("[CI+][Tune][Warning!] Unsupported Delivery System!\n");

    switch (g_stCiTuneInfo.eCiTuneApplicant)
    {
        case E_CI_TUNE_APPLICANT_HC:
            printf("[CI+][HC] UNSUPPORTED Descriptor: %02X!\r\n", g_stCiTuneInfo.u8TuneDescriptorNumber);
            msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS_ERROR_UNSUPPORTED_DELIVERY_SYSTEM);
            break;
        case E_CI_TUNE_APPLICANT_OP:
            /* CI+ Spec v1.3 Chapter 14.7.5.11 operator_tune APDU
                Check the tuning parameters quit if these descriptors are not supported and
                the CICAM may then re-build the list excluding this delivery location.
                if (current_location_info has bad parameters OR is invalid OR is not supported) {
                    current_location_info = descriptor information + error codes.
                    break;
                }
                EX: 7.2.8.2.  Unsupported Delivery Descriptors: op-prof_op-tune_803_signal.c
                    <<< [CI+][OP] Operator Tune
                            [CI+][OP] descriptor(): 15 bytes
                            7F 0D 7F 01 00 01 00 08 00 00 02 D3 44 40 00
            */
			switch((EN_DESCRIPTOR_TAG)(g_stCiTuneInfo.pu8TuneDescriptors[0]))
			{
				case TAG_SDSD:
				case TAG_S2DSD:
					g_stCiTuneInfo.u8TuneDescriptorNumber = 0xFF;
					break;
				default:
					break;
			}
            printf("[CI+][OP][Warning!] The OP Tune is not supported: %02X!\r\n", g_stCiTuneInfo.u8TuneDescriptorNumber);
			if ((TAG_SDSD == g_stCiTuneInfo.pu8TuneDescriptors[0]) &&
				(g_stCiTuneInfo.pu8TuneDescriptors[1] > 0) &&
				((g_stCiTuneInfo.pu8TuneDescriptors[8] >> 2 & 0x01) == 0x01) &&// check modulation system : 0x00 : DVB-S , 0x01 : DVB-S2
				(g_stCiTuneInfo.u16TuneDescriptorsLen > (1 + 1 + u8HandlingDesciptorLength)) &&
				(TAG_S2DSD == g_stCiTuneInfo.pu8TuneDescriptors[1 + 1 + u8HandlingDesciptorLength]))
			{
				U8 u8S2DescriptorsLen = g_stCiTuneInfo.pu8TuneDescriptors[1 + 1 + u8HandlingDesciptorLength + 1]; // S2 desciptor_length
				msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, 0, 0, EN_OP_TUNE_STATUS_NG_NOT_SUPPORTED, g_stCiTuneInfo.pu8TuneDescriptors, 1 + 1 + u8HandlingDesciptorLength + 1 + 1 + u8S2DescriptorsLen); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body + 1 byte desciptor_tag + 1 byte desciptor_length + u8S2DescriptorsLen bytes S2 desciptor
			}
			else
			{
				msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, 0, 0, EN_OP_TUNE_STATUS_NG_NOT_SUPPORTED, g_stCiTuneInfo.pu8TuneDescriptors, 1 + 1 + u8HandlingDesciptorLength); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body
			}
            break;
        default:
            printf("[%s:%d][CI+][ERROR!] Unknown tag %d!\n", __FILE__, __LINE__, g_stCiTuneInfo.eCiTuneApplicant);
    }
    return FALSE;
}

BOOL MApp_CI_CiTuneSetMuxDVBT(const DESC_TERR_DEL_SYS* ustDesciptor)
{
    U32 u32TuneFreq;
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    printf("[CI+][Tune] Trying to tune to DVB-T(%lu KHz)...\n", (ustDesciptor->u32CentreFreq *10)/1000);

    u32TuneFreq = (U32)g_stCiTuneInfo.pu8TuneDescriptors[2] << 24 |
                           (U32)g_stCiTuneInfo.pu8TuneDescriptors[3] << 16 |
                           (U32)g_stCiTuneInfo.pu8TuneDescriptors[4] <<  8 |
                           (U32)g_stCiTuneInfo.pu8TuneDescriptors[5];
    if ((0 == u32TuneFreq) || (0xFFFFFFFF == u32TuneFreq))
    {
        MApp_CI_CiTuneParameterInvalidReply();
        return FALSE;
    }

    g_stCiTuneInfo.stCiTuneMux.u32Frequency = ustDesciptor->u32CentreFreq/100;

    if (0 == ustDesciptor->u8fPriority)
    {
        g_stCiTuneInfo.stCiTuneMux.bLPCoding = TRUE;
    }
    else
    {
        g_stCiTuneInfo.stCiTuneMux.bLPCoding = FALSE;
    }

    g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_INVALID;
    g_stCiTuneInfo.stCiTuneMux.u16PlpID = DVB_T2_PLP_ID_INVALID;

    if (0 == ustDesciptor->u8BW)
    {
        g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_8MHz;
    }

    if (1 == ustDesciptor->u8BW)
    {
        g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_7MHz;
    }

    if (2 == ustDesciptor->u8BW)
    {
        g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_6MHz;
    }

    return TRUE;
}
#if(ENABLE_DVB_T2 == ENABLE)
BOOL MApp_CI_CiTuneSetMuxDVBT2(const DESC_T2_DEL_SYS* ustDesciptor)
{
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    printf("[CI+][Tune] Trying to tune to DVB-T2(%lu KHz)...\n", (ustDesciptor->stT2CellCentreFreq[0].u32CentreFreq[0]  *10)/1000);

    if((ustDesciptor->stT2CellCentreFreq[0].u32CentreFreq[0] == 0) || (ustDesciptor->stT2CellCentreFreq[0].u32CentreFreq[0] == 0xFFFFFFFF))
    {
        MApp_CI_CiTuneParameterInvalidReply();
        return FALSE;
    }

    g_stCiTuneInfo.stCiTuneMux.u32Frequency = ustDesciptor->stT2CellCentreFreq[0].u32CentreFreq[0]/100;
    g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_INVALID;
    g_stCiTuneInfo.stCiTuneMux.u16PlpID = ustDesciptor->u8PLD;

    if (0 == ustDesciptor->u8BW)
    {
        g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_8MHz;
    }

    if (1 == ustDesciptor->u8BW)
    {
        g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_7MHz;
    }

    if (2 == ustDesciptor->u8BW)
    {
        g_stCiTuneInfo.stCiTuneMux.u8Bandwidth = E_RF_CH_BAND_6MHz;
    }

    return TRUE;
}
#endif

BOOL MApp_CI_CiTuneSetMuxDVBC(const DESC_CABLE_DEL_SYS* ustDesciptor)
{
    U32 u32TuneFreq = 0;
    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    printf("[CI+][HC] Trying to tune to DVB-C(%lu KHz)...\n", ustDesciptor->u32CentreFreq/10);

    u32TuneFreq = (U32)g_stCiTuneInfo.pu8TuneDescriptors[2] << 24 |
                           (U32)g_stCiTuneInfo.pu8TuneDescriptors[3] << 16 |
                           (U32)g_stCiTuneInfo.pu8TuneDescriptors[4] <<  8 |
                           (U32)g_stCiTuneInfo.pu8TuneDescriptors[5];
    if ((0 == u32TuneFreq) || (0xFFFFFFFF == u32TuneFreq))
    {
        MApp_CI_CiTuneParameterInvalidReply();
        return FALSE;
    }

    g_stCiTuneInfo.stCiTuneMux.u32Frequency = ustDesciptor->u32CentreFreq/10;
    g_stCiTuneInfo.stCiTuneMux.u32SymbRate = ustDesciptor->u32Symbol_rate/10;
    g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (U8)CAB_QAM256;

    switch (ustDesciptor->u8Modulation)
    {
        case 1:
            printf("[CI+][Tune] modulation = 16-QAM\r\n");
            g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (U8)CAB_QAM16;
            break;
        case 2:
            printf("[CI+][Tune] modulation = 32-QAM\r\n");
            g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (U8)CAB_QAM32;
            break;
        case 3:
            printf("[CI+][Tune] modulation = 64-QAM\r\n");
            g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (U8)CAB_QAM64;
            break;
        case 4:
            printf("[CI+][Tune] modulation = 128-QAM\r\n");
            g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (U8)CAB_QAM128;
            break;
        case 5:
            printf("[CI+][Tune] modulation = 256-QAM\r\n");
            g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (U8)CAB_QAM256;
            break;
        case 0:
        default:
            printf("[CI+][Tune] Error modulation = 0x%02X\r\n", ustDesciptor->u8Modulation);
            break;
    }

    return TRUE;
}

#if (ENABLE_S2)
BOOL MApp_CI_CiTuneSetMuxDVBS(const DESC_SATELLITE_DEL_SYS *ustDesciptor)
{
    U32 u32TuneFreq = 0;

    if (0 == ustDesciptor->u8Modulation_system)
    {
        printf("[CI+][%s] Trying to tune to DVB-S(%lu KHz)...\n", __FUNCTION__, ((ustDesciptor->u32CentreFreq*10)/1000));
    }
    else if (1 == ustDesciptor->u8Modulation_system)
    {
        printf("[CI+][%s] Trying to tune to DVB-S2(%lu KHz)...\n", __FUNCTION__, ((ustDesciptor->u32CentreFreq*10)/1000));
    }

    u32TuneFreq = (U32)g_stCiTuneInfo.pu8TuneDescriptors[2] << 24 |
                  (U32)g_stCiTuneInfo.pu8TuneDescriptors[3] << 16 |
                  (U32)g_stCiTuneInfo.pu8TuneDescriptors[4] <<  8 |
                  (U32)g_stCiTuneInfo.pu8TuneDescriptors[5];
    if ((0 == u32TuneFreq) || (0xFFFFFFFF == u32TuneFreq))
    {
        MApp_CI_CiTuneParameterInvalidReply();
        return FALSE;
    }

    g_stCiTuneInfo.stCiTuneMux.u32Frequency = ((ustDesciptor->u32CentreFreq*10)/1000);
    g_stCiTuneInfo.stCiTuneMux.u32SymbRate = ustDesciptor->u32Symbol_rate/10;
    g_stCiTuneInfo.stCiTuneMux.bPolarity = ustDesciptor->u8Polarization;
    g_stCiTuneInfo.stCiTuneMux.u8ModulationMode = (ustDesciptor->u8Modulation_type&0x03);
    ///store Sat Orbital position in parsing stage, transfer into Sat ID in tuning stage
    //g_stCiTuneInfo.stCiTuneMux.u16Orbital_position = ustDesciptor->u16Orbital_position;
    return TRUE;
}
#endif

#if (MHEG5_ENABLE && CIPLUS_MHEG && ENABLE_CI_PLUS)
void MApp_CI_DoCITuneParsePMTStartAVMonitor(BOOL bNotifyPMTUpdated)
{
    U8* pu8PMTSection = NULL;
    U16 u16PMTLength = SI_PMT_SECTION_MAX_LEN;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    if(FALSE == msAPI_CI_CardDetect())
    {
        return;
    }

    pu8PMTSection = (U8 *)CI_MEMORY_ALLOCATE(SI_PMT_SECTION_MAX_LEN);

    if(!pu8PMTSection)
    {
        printf("[CI+][HCv2][Warning] Fails to malloc memory!\n");
        return;
    }

    if (FALSE == bNotifyPMTUpdated)
    {
        if (TRUE == msAPI_CI_GetCurrentPMTSection(pu8PMTSection, &u16PMTLength))
        {
            MApp_CI_PMTSectionNotify(pu8PMTSection);
        }
        else
        {
            printf("[%s:%d][CI+][HCv2][Warning!] Fails to get Current PMT Section!\n", __FILE__, __LINE__);
        }
    }
    else
    {
        // Get PMT Section of HC Tune from CI library.
        if (FALSE == msAPI_CI_HC_GetTunePMTSection(pu8PMTSection, &u16PMTLength))
        {
            printf("[%s:%d][CI+][HCv2][Warning!] Fails to get HC Tune PMT Section!\n", __FILE__, __LINE__);
        }
        else
        {
            printf("[CI+][HCv2] Parsing PMT...\n");
            MApp_CI_PMTSectionNotify(pu8PMTSection);

            /* CI+ Spec v1.3 Figure 14.10: Tuning process with Host Control Version 2 (informative)
                (9) Host sends ca_pmt()
            */
            printf("[CI+][HCv2] (9) Host sends ca_pmt()\n");
            msAPI_CI_NotifyCurrentPMTUpdate(pu8PMTSection, u16PMTLength);
        }
    }

    CI_MEMORY_FREE(pu8PMTSection);
    pu8PMTSection = NULL;
}

void MApp_CI_PMTSectionNotify(U8* pu8SectionData)
{
    WORD u16CurVideoPID, u16CurAudioPID, u16CurPCRPID, u16CurPmtPID;
    AUD_INFO stCurAudioInfo;
    MEMBER_SERVICETYPE nCurServiceType = msAPI_CM_GetCurrentServiceType();
    WORD u16CurPosition = msAPI_CM_GetCurrentPosition( nCurServiceType );
    FileIn_SERVICE_INFO stFileInSrvInfo;

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    MApp_Dmx_PMT_FileIn_Parse(pu8SectionData);
    MApp_SI_GetFileInPIDS(&stFileInSrvInfo);

    u16CurVideoPID = msAPI_CM_GetVideoPID(nCurServiceType, u16CurPosition);
    msAPI_CM_GetAudioStreamInfo(nCurServiceType, u16CurPosition, &stCurAudioInfo, 0);
    u16CurAudioPID = stCurAudioInfo.wAudPID;
    u16CurPCRPID = msAPI_CM_GetPCR_PID(nCurServiceType, u16CurPosition);
    u16CurPmtPID = msAPI_CM_GetPmtPID(nCurServiceType, u16CurPosition);

    if((stFileInSrvInfo.wVideo_PID != u16CurVideoPID)
        || (stFileInSrvInfo.stAudInfo[0].wAudPID != u16CurAudioPID)
        || (stFileInSrvInfo.wPCR_PID != u16CurPCRPID)
        || (stFileInSrvInfo.wPMT_PID != u16CurPmtPID))
    {
        MApp_CI_TuneServicePlayAV(stFileInSrvInfo.wVideo_PID, stFileInSrvInfo.wVideoType, stFileInSrvInfo.stAudInfo[0].wAudPID, stFileInSrvInfo.stAudInfo[0].wAudType, stFileInSrvInfo.wPCR_PID);
        fEnableSignalMonitor = TRUE;
	}
}
#endif

BOOL MApp_CI_SendCiOpSearchStart(void)
{
    CI_OP_STATUS stCiOpStatus;
    U8 u8aServiceType[6] = {0x01, 0x02, 0x03, 0x0A, 0x16, 0x19};    // MPEG-2 television (0x01), MPEG-1, Layer-II radio (0x02),
                                                                    // Teletext (0x03), Advanced codec radio (0x0A),
                                                                    // Advanced codec SD (0x16) and HD (0x19) video services supported.
    U8 u8aDeliveryCapability[8] = {0x00};                           // DVB-T(0x5A); DVB-T2(0x7F04); DVB-C(0x44); DVB-S(0x43); DVB-S2(0x79).
    U8 u8DeliveryCapabilityIndex = 0;
    U8 u8aApplicationCapability[2] = {0x01, 0x06};                  // Host supports broadcast MHEG-5 profile0x0106).
                                                                    // EX: HbbTV(0x0123); Open TV(0x0107)
	BOOL bUnattendedFlag = MApp_GetActiveStandbyMode();

    MW_DTV_CI_OPCACHE_DB_FUNCTION("%s:%d\n",__PRETTY_FUNCTION__,__LINE__);

    memset(&stCiOpStatus, 0x00, sizeof(CI_OP_STATUS));

    if (FALSE == msAPI_CI_OP_GetStatus(&stCiOpStatus))
    {
        printf("[%s:%d][Warning!][CI+][OP] Fails to Get OP Status!\r\n", __FILE__, __LINE__);
        return FALSE;
    }

    BOOL bDeliverySystemSupported = FALSE;

    /* CI+ Spec v1.3.1 Chapter 14.7.5.3 operator_status APDU
        The CICAM may support multiple delivery systems which shall result in multiple bits of this field being set. If
        the Host does not support any of the reported delivery systems then the profile may be ignored by the Host.
    */
    /* CI+ Spec v1.3.1 Chapter 14.7.5.8 operator_search_start APDU
         A Host may choose to advertise all supported delivery system descriptors or
        the delivery system descriptors applicable to the current operational mode of the Host.
    */
    // 1: TThis is a cable network and may be DVB-C(0x44) and/or DVB-C2
    if (stCiOpStatus.u8DeliverySystemHint & EN_OP_DELIVERY_SYSTEM_HINT_DVB_C)
    {
        printf("[CI+][OP] Operator Status::delivery_system_hint is DVB-C(0x44) and/or DVB-C2\n");
#if(ENABLE_DVBC)
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_CDSD;
        bDeliverySystemSupported = TRUE;
#else
        printf("[%s:%d][Warning!][CI+][OP] Host can't support Operator Status::delivery_system_hint DVB-C(0x44) and/or DVB-C2!\r\n", __FILE__, __LINE__);
#endif
    }
    else
    {
#if(ENABLE_DVBC)
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_CDSD;
#endif
    }
    // 2: This is a satellite network and may be DVB-S(0x43) and/or DVB-S2(0x79)

    // 3: This is a terrestrial network and may be DVB-T(0x5A) and/or DVB-T2(0x7F04)
    if (stCiOpStatus.u8DeliverySystemHint & EN_OP_DELIVERY_SYSTEM_HINT_DVB_T)
    {
        printf("[CI+][OP] Operator Status::delivery_system_hint is DVB-T(0x5A) and/or DVB-T2(0x7F04)\n");
#if(ENABLE_DVBC || ENABLE_DVBT)
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_TDSD;
        bDeliverySystemSupported = TRUE;
#else
        printf("[%s:%d][Warning!][CI+][OP] Host can't support Operator Status::delivery_system_hint DVB-T(0x5A) and/or DVB-T2(0x7F04)!\r\n", __FILE__, __LINE__);
#endif

#if(ENABLE_DVB_T2 == ENABLE)
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_ED;
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_T2DSD;
        bDeliverySystemSupported = TRUE;
#endif
    }
    else
    {
#if(ENABLE_DVBC || ENABLE_DVBT)
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_TDSD;
#endif

#if(ENABLE_DVB_T2 == ENABLE)
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_ED;
        u8aDeliveryCapability[u8DeliveryCapabilityIndex++] = TAG_T2DSD;
#endif
    }

    if (TRUE == bDeliverySystemSupported)
    {
        g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_OP;
        // Send operator_search_start()
        printf("[CI+][OP] Send operator_search_start()!\r\n");
        msAPI_CI_OP_SendSearchStart(bUnattendedFlag,
                               u8aServiceType, 6,
                               u8aDeliveryCapability, u8DeliveryCapabilityIndex,
                               u8aApplicationCapability, 2);
        // Record current Program enviroment.
        g_u8OpTuneOriginalDtvRoute = MApp_DVBType_GetCurrentType();
        memset(&g_stCiTuneOriginalProgInfo, 0x00, sizeof(MS_TP_SETTING));
        msAPI_Tuner_GetCurTPSetting(&g_stCiTuneOriginalProgInfo);
//        printf("[CI+][OP] Service Type %d Service No %d\r\n", g_stCiTuneOriginalProgInfo.stCHAttribute.u8ServiceType, g_stCiTuneOriginalProgInfo.u16Number);
        g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_OP;

    }
    else
    {
        g_stCiTuneInfo.eCiTuneApplicant = E_CI_TUNE_APPLICANT_NONE;
        printf("[%s:%d][Warning!][CI+][OP] No Delivery System Supported!\r\n", __FILE__, __LINE__);
        CI_OP_INFO stCiOpInfo;

        if (TRUE == msAPI_CI_OP_GetInfo(&stCiOpInfo))
        {
            // Delete this OP Cache.
            MApp_CI_DeleteOpCacheByCicamId(stCiOpInfo.u32CicamIdentifier);
        }
    }

    return TRUE;
}

BOOL MApp_CI_CiTuneSignalMonitor( void )
{
    BOOLEAN bLocked = FE_NOT_LOCK;
    int i, nLockedNumber = 0;

    for(i = 0; i < 300; ++i)
    {
#if (WATCH_DOG == ENABLE)
        msAPI_Timer_ResetWDT();
#endif


        msAPI_Timer_Delayms(15);
        msAPI_Tuner_CheckLock(&bLocked, FALSE);

        if(FE_LOCK == bLocked)
        {
            ++nLockedNumber;

            if(5 == nLockedNumber)
            {
                printf("[%lu ms]@@@@@@@@@ Tuner Check Locked @@@@@@@@@\n", msAPI_Timer_GetTime0());
                break;
            }
        }
    }

    switch(g_stCiTuneInfo.eCiTuneApplicant)
    {
        case E_CI_TUNE_APPLICANT_NONE:
            break;

        case E_CI_TUNE_APPLICANT_HC:
            if(FALSE == MApp_CI_CiHcTuneSignalMonitor(bLocked))
            {
                printf("\x1b[37;41m [%s:%s:%d] CiHcTuneSignalMonitor FAIL \x1b[0m\n",__FILE__,__FUNCTION__,__LINE__);
                return FALSE;
            }
            break;

        case E_CI_TUNE_APPLICANT_OP:
            if(FALSE == MApp_CI_CiOpTuneSignalMonitor(bLocked))
            {
                printf("\x1b[37;41m [%s:%s:%d] CiHcTuneSignalMonitor FAIL \x1b[0m\n",__FILE__,__FUNCTION__,__LINE__);
                return FALSE;
            }
            break;

        default:
            return FALSE;
    }

    return TRUE;
}

BOOL MApp_CI_CiHcTuneSignalMonitor( BOOLEAN bLocked )
{
    if(FALSE == msAPI_CI_CardDetect())
    {
        return FALSE;
    }

    /* CI+ Spec v1.3 Figure 14.10: Tuning process with Host Control Version 2 (informative)
        (5) Tune successful?
    */
    printf("[CI+][HCv2] (5) Tune successful?\n");

    if(FE_LOCK == bLocked)
    {
        printf("[CI+][HCv2] Tune OK!\n");
        msAPI_CI_HC_NotifyTuneDone();
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
    }
    else
    {
        printf("[%lu ms][%s:%d][CI+][HC][Warning!] Signal is not Locked for HC Tune!\n", msAPI_Timer_GetTime0(), __FILE__, __LINE__);

        /* CI+ Spec v1.3 Figure 14.10: Tuning process with Host Control Version 2 (informative)
            (12) Host sends tune_reply() with Error 02(tuner not locking)
        */
        printf("[CI+][HCv2] (12) Host sends tune_reply() with Error 02(tuner not locking)\n");
        msAPI_CI_HC_ReplyTune(EN_HC_TUNE_REPLY_STATUS_ERROR_TUNER_NOT_LOCKING);
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
    }

    return TRUE;
}

BOOL MApp_CI_CiOpTuneSignalMonitor( BOOLEAN bLocked )
{
    if(FALSE == msAPI_CI_CardDetect())
    {
        return FALSE;
    }

    printf("[%lu ms][CI+][OP] Tuning ...\n", msAPI_Timer_GetTime0());
    WORD wSignalStrength = 0, wSignalQuality = 0;
    if(FE_LOCK == bLocked)
    {
        msAPI_Tuner_CheckSignalStrength(&wSignalStrength);
        wSignalQuality = msAPI_Tuner_GetSignalQualityPercentage();
    }
	if(0 != (U16)wSignalStrength && 0 != (U16)wSignalQuality)
	{
        U8 u8HandlingDesciptorLength = g_stCiTuneInfo.pu8TuneDescriptors[1];

        printf("[CI+][OP] Tune OK: %u | %u!\n", (U16)wSignalStrength, (U16)wSignalQuality);
		if ((TAG_SDSD == g_stCiTuneInfo.pu8TuneDescriptors[0]) &&
			(g_stCiTuneInfo.pu8TuneDescriptors[1] > 0) &&
			((g_stCiTuneInfo.pu8TuneDescriptors[8] >> 2 & 0x01) == 0x01) &&// check modulation system : 0x00 : DVB-S , 0x01 : DVB-S2
			(g_stCiTuneInfo.u16TuneDescriptorsLen > (1 + 1 + u8HandlingDesciptorLength)) &&
			(TAG_S2DSD == g_stCiTuneInfo.pu8TuneDescriptors[1 + 1 + u8HandlingDesciptorLength]))
		{
			U8 u8S2DescriptorsLen = g_stCiTuneInfo.pu8TuneDescriptors[1 + 1 + u8HandlingDesciptorLength + 1]; // S2 desciptor_length
			msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, (U8)wSignalStrength, (U8)wSignalQuality, EN_OP_TUNE_STATUS_OK, g_stCiTuneInfo.pu8TuneDescriptors, 1 + 1 + u8HandlingDesciptorLength + u8S2DescriptorsLen); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body + 1 byte desciptor_tag + 1 byte desciptor_length + u8S2DescriptorsLen bytes S2 desciptor
		}
		else
		{
        msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, (U8)wSignalStrength, (U8)wSignalQuality, EN_OP_TUNE_STATUS_OK, g_stCiTuneInfo.pu8TuneDescriptors, 1 + 1 + u8HandlingDesciptorLength); // 1 byte desciptor_tag + 1 byte desciptor_length + desciptor_body
		}
        MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        bIsMoreOpTune = FALSE;
    }
    else
    {
        printf("[%lu ms][%s:%d][CI+][OP][Warning!] Signal is not Locked for OP Tune!\n", msAPI_Timer_GetTime0(), __FILE__, __LINE__);

        U8 u8HandledDesciptorLength = g_stCiTuneInfo.pu8TuneDescriptors[1]; // 1 byte desciptor_tag + 1 byte desciptor_length

        if (OP_INVALID_DESCRIPTOR_NUMBER == g_stCiTuneInfo.u8TuneDescriptorNumber)
        {
            printf("[%s:%d][CI+][OP][Warning!] No following OP Tune!\n", __FILE__, __LINE__);
            msAPI_CI_OP_SendTuneStatus(g_stCiTuneInfo.u8TuneDescriptorNumber, 0, 0, EN_OP_TUNE_STATUS_NG_OPERATION_FAILED, NULL, 0);
            bIsMoreOpTune = FALSE;

            MSRV_DVB_PLAYER_CI_FREE_TUNE_INFO(g_stCiTuneInfo);
        }
        else
        {
            g_stCiTuneInfo.u16TuneDescriptorsLen -= (1 + 1 + u8HandledDesciptorLength);

            {
                // Remove handled OP Tune Descriptor
                int i;

                for(i = 0; i < g_stCiTuneInfo.u16TuneDescriptorsLen; ++i)
                {
                    g_stCiTuneInfo.pu8TuneDescriptors[i] = g_stCiTuneInfo.pu8TuneDescriptors[i + 1 + 1 + u8HandledDesciptorLength];
                }
                g_stCiTuneInfo.u32TuningTimer = 0;

                printf("[CI+][OP] There is still more OP tune to be done, wait for next loop.\n");
                bIsMoreOpTune = TRUE;
            }
        }
    }

    return TRUE;
}

void MApp_CI_InitCiVariables( void )
{
    //MApp_CI_SetOpMode(FALSE);
    g_bOpStatusHandlingSuspended = FALSE;
    g_bOpSearchSuspended = FALSE;
    g_u32OpSearchQueryPostEventTimer = 0;
    g_u8OpInfoVersion = CI_INVALID_OP_INFO_VERSION;
    g_u32OpCicamIdentifier = 0;
    g_u8OpNitVersion = CI_INVALID_OP_NIT_VERSION;
    g_bOpEntitlementChange = FALSE;
    memset(&g_stCiTuneInfo, 0x00, sizeof(ST_DTV_CI_TUNE_INFO));

    g_stCiTuneInfo.stCiTuneMux.u16PlpID = 0xFF;
    msAPI_DTV_Comm_SetPLPID(g_stCiTuneInfo.stCiTuneMux.u16PlpID);
}

void MApp_CI_TuneServicePlayAV( U16 u16VideoPID, U16 u16VideoType, U16 u16AudioPID, U16 u16AudioType, U16 u16PCRPID)
{
    VDEC_CodecType eCodecType=E_VDEC_CODEC_TYPE_MPEG2;
    VIDEO_TYPE  eVideoType = (VIDEO_TYPE)u16VideoType;
    DMX_FILTER_STATUS eStatus;
    printf("MApp_CI_TuneServicePlayAV 0x%x, 0x%x, 0x%x,0x%x,0x%x\n",u16VideoPID,u16VideoType,u16AudioPID,u16AudioType,u16PCRPID);
    //pcr
    msAPI_DMX_StartFilter(u16PCRPID, MSAPI_DMX_FILTER_TYPE_PCR, MApp_Dmx_GetFid(EN_PCR_FID));

    //play video
    if(eVideoType == E_VIDEOTYPE_MPEG)
    {
        eCodecType=E_VDEC_CODEC_TYPE_MPEG2;
    }
    else if(eVideoType == E_VIDEOTYPE_H264)
    {
        eCodecType=E_VDEC_CODEC_TYPE_H264;
    }
    else if(eVideoType == E_VIDEOTYPE_AVS)
    {
        eCodecType=E_VDEC_CODEC_TYPE_AVS;
    }
    else if(eVideoType == E_VIDEOTYPE_VC1)
    {
        eCodecType=E_VDEC_CODEC_TYPE_VC1_ADV;
    }
  #if ( CHIP_SUPPORT_HEVC )//IMPLEMENT_DTV_H265
    else if(eVideoType == E_VIDEOTYPE_H265)
    {
        eCodecType = E_VDEC_CODEC_TYPE_HEVC;
    }
  #endif
    msAPI_VID_Command(MSAPI_VID_STOP);
    msAPI_VID_SetMappingAVCParameter(eCodecType);
    msAPI_DMX_StartFilter(u16VideoPID, MSAPI_DMX_FILTER_TYPE_VIDEO, MApp_Dmx_GetFid(EN_VIDEO_FID));
    eStatus = msAPI_DMX_StartFilter(u16VideoPID, MSAPI_DMX_FILTER_TYPE_VIDEO, MApp_Dmx_GetFid(EN_VIDEO_FID));
    if(eStatus == DMX_FILTER_STATUS_ERROR)
    {
        printf("Video filter fail \n");
    }
    MApp_VID_VariableInit();
    msAPI_VID_Init(FALSE, E_VDEC_SRC_MODE_DTV);
    msAPI_VID_Command(MSAPI_VID_PLAY);
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_MOMENT_MUTEON, E_AUDIOMUTESOURCE_ACTIVESOURCE);
    MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_STOP);
    msAPI_DMX_Stop( *MApp_Dmx_GetFid(EN_AUDIO_FID));
    eStatus = msAPI_DMX_StartFilter(u16AudioPID, MSAPI_DMX_FILTER_TYPE_AUDIO, MApp_Dmx_GetFid(EN_AUDIO_FID));
    if(eStatus == DMX_FILTER_STATUS_ERROR)
    {
        printf("audio filter fail \n");
    }
    MApp_ChannelChange_Set_Audio_Decoder_System(u16AudioType);
    MApi_AUDIO_SetCommand(MSAPI_AUD_DVB_DECCMD_PLAY);
    msAPI_AUD_AdjustAudioFactor(E_ADJUST_AUDIOMUTE, E_AUDIO_MOMENT_MUTEOFF, E_AUDIOMUTESOURCE_ACTIVESOURCE);
}

void MApp_CI_CiEventCallbackSystemTimeUpdate( void )
{
    U32 u32CurrentSysime = MApp_GetLocalSystemTime();
    U8 au8CurrentUTCTime[5] = { 0x00 };
    MApp_Seconds2MJDUTC(u32CurrentSysime, au8CurrentUTCTime);
    msAPI_CI_NotifySystemUTCtime(au8CurrentUTCTime);
}
#endif //(ENABLE_CI_PLUS)
#endif  //ENABLE_CI
#endif // (ENABLE_DTV)
#undef MAPP_CIMMI_C

