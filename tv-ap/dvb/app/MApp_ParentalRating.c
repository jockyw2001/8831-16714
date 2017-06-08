#include "Board.h"


#include "MApp_GlobalSettingSt.h"

#include "MApp_BlockSys.h"
#include "MApp_UiMenuDef.h"

#if (ENABLE_DTV_EPG)
#include "mapp_eit.h"
#endif
#if (ENABLE_PVR)
#include "MApp_PVR.h"
#include "MApp_UiPvr.h"
//#include "MApp_TimeShift.h"
#include "MApp_Playback.h"
#include "MApp_Record.h"
#endif

#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_ACTmsgbox.h"

#include "ZUI_tables_h.inl"
#include "ZUI_exefunc.h"



#if(ENABLE_DTV)
extern BOOLEAN bCheckParentalPW;

static BOOLEAN _bParentalBlock = FALSE;
#endif

void MApp_Set_MonitorParental(BOOLEAN bEnable)
{
    stGenSetting.g_BlockSysSetting.u8MonitorParental=bEnable;
}

BOOLEAN MApp_Get_MonitorParental(void)
{
    return stGenSetting.g_BlockSysSetting.u8MonitorParental;
}

#if(ENABLE_DTV)
BOOLEAN MApp_Get_ParentalBlock_state(void)
{
    return _bParentalBlock;
}

void MApp_Set_ParentalBlock_state(BOOLEAN bEnable)
{
    _bParentalBlock = bEnable;
}

void MApp_ParentalRating_PasswordInputMessageHandle(BOOL ActOnOff)
{
    if( _bParentalBlock
      && MApp_ParentalControl_GetBlockStatus()
      && IsDVBInUse()/*IsDTVInUse()*/
      )
    {
       ;
    }
    else
    {
       return;
    }

    if(ActOnOff)
    {
        MApp_ZUI_ACT_StartupOSD(E_OSD_MESSAGE_BOX);
        MApp_ZUI_ACT_ExecuteWndAction(EN_EXE_SHOW_PASSWORD_INPUT_MSGBOX);
        SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_BLOCKRATING;
    }
    else
    {
        if(MApp_ZUI_API_IsSuccessor(HWND_MSGBOX_PASSWORD_PANE, MApp_ZUI_API_GetFocus()))
        {
            SYS_SCREEN_SAVER_TYPE(MAIN_WINDOW) = EN_SCREENSAVER_NOSIGNAL;
            MApp_ZUI_ACT_ExecuteMessageBoxAction(EN_EXE_CLOSE_CURRENT_OSD);
        }
    }
}
#if ENABLE_DVB
void MApp_ParentalRating_BlockStatus_Monitor(void)
{
  #if (ENABLE_DTV_EPG)
    U8 u8Parental_Control;
#if ENABLE_PVR
            if (E_PVR_STATE_PLAYBACK == MApp_PVR_StateMachineGet() &&  E_PLAYBACK_STATE_PLAYBACKING== MApp_Playback_StateMachineGet())
            {
                u8Parental_Control = MApp_Playback_GetParentRating();
            }
            else
#endif
            {
                u8Parental_Control = MApp_EIT_GetCurParentControl();
           }
  #endif

 #if  ENABLE_SBTVD_BRAZIL_APP
   // U8 u8Parental_ObjectiveContent = MApp_EIT_GetCurParentObjectiveContent();
 #endif

    if (FALSE == MApp_Get_MonitorParental())
    {
        return;
    }

#if ENABLE_CI_PLUS
        if(msAPI_CI_CardDetect())
        {
            if(MApp_SI_CheckCurProgScramble()&&msAPI_CI_CC_GetCicamRating()!=0&& msAPI_CI_CC_GetCicamRating() < u8Parental_Control)
            {
                  switch(msAPI_CI_CC_GetCicamPinCapability())
                  {
                    case EN_CC_CICAM_PIN_CAPABILITIES_CICAM_PIN_ONLY:
                    case EN_CC_CICAM_PIN_CAPABILITIES_BOTH_PIN :
                    case EN_CC_CICAM_PIN_CAPABILITIES_CICAM_PIN_ONLY_CACHED:
                    case EN_CC_CICAM_PIN_CAPABILITIES_BOTH_PIN_CACHED:
                    {
                        MApp_ParentalControl_SetBlockStatus(FALSE);
                        _bParentalBlock = FALSE;
                        bCheckParentalPW = TRUE;

                    #if ENABLE_PVR
                        if(MApp_PVR_StateMachineGet() == E_PVR_STATE_TIMESHIFT||MApp_PVR_StateMachineGet() == E_PVR_STATE_RECORDnPLAYBACK)
                         {
                             MApp_UiPvr_PlaybackStop();
                             MApp_UiPvr_RecordStop();
                         }
                         else if(MApp_PVR_StateMachineGet() == E_PVR_STATE_RECORD)
                         {
                              MApp_UiPvr_RecordStop();
                         }
                    #endif
                         return;
                    }
                    default:
                         break;
                    }
             }
        }
#endif

    if ((stGenSetting.g_BlockSysSetting.u8ParentalControl<=EN_F4_LockSystem_Min) ||
        (stGenSetting.g_BlockSysSetting.u8ParentalControl>EN_F4_LockSystem_Max))
    {
        //if (TRUE == _bParentalBlock)
        {
            MApp_ParentalControl_SetBlockStatus(FALSE);
            _bParentalBlock =FALSE;
            bCheckParentalPW = FALSE;
        }
    }
  #if (ENABLE_DTV_EPG)
    else if (stGenSetting.g_BlockSysSetting.u8ParentalControl < u8Parental_Control)
    {
        if (FALSE == _bParentalBlock)
        {
            MApp_ParentalControl_SetBlockStatus(TRUE);
            _bParentalBlock = TRUE;
            bCheckParentalPW = FALSE;
           #if ENABLE_PVR
           if(MApp_PVR_StateMachineGet() == E_PVR_STATE_TIMESHIFT||MApp_PVR_StateMachineGet() == E_PVR_STATE_RECORDnPLAYBACK)
            {
                MApp_UiPvr_PlaybackStop();
                MApp_UiPvr_RecordStop();
            }
            else if(MApp_PVR_StateMachineGet() == E_PVR_STATE_RECORD)
            {
                 MApp_UiPvr_RecordStop();
            }
            else if(E_PVR_STATE_PLAYBACK == MApp_PVR_StateMachineGet() &&  E_PLAYBACK_STATE_PLAYBACKING== MApp_Playback_StateMachineGet())
            {
                 MApp_ParentalControl_SetBlockStatus(TRUE);
            }
           #endif
        }
    }
#if  ENABLE_SBTVD_BRAZIL_APP//@@-- Lock age include the same age as the use set.
    else if(stGenSetting.g_BlockSysSetting.u8ParentalControl == u8Parental_Control)// && u8Parental_ObjectiveContent != 0x00)
    {
        if(FALSE==_bParentalBlock)
        {
            MApp_ParentalControl_SetBlockStatus(TRUE);
            _bParentalBlock = TRUE;
            bCheckParentalPW = FALSE;
        }
    }
#endif
  #endif  //#if (ENABLE_DTV_EPG)
    else
    {
        //if (TRUE == _bParentalBlock)
        {
            MApp_ParentalControl_SetBlockStatus(FALSE);
            _bParentalBlock= FALSE;
            bCheckParentalPW = FALSE;
        }
    }
}
#endif
#endif

