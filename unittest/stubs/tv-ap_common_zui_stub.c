#include "cpptest.h"

/** 
 * This file contains auto-generated stub definitions.
 *
 * Available C++test API functions (see C++test Users Guide for details):
 *     void CppTest_Assert(bool test, const char * message)
 *     void CppTest_Break()
 *     const char* CppTest_GetCurrentTestCaseName()
 *     const char* CppTest_GetCurrentTestSuiteName()
 *     bool CppTest_IsCurrentTestCase(const char* testCaseName)
 */

/** 
 * Header files where the stubbed functions are originally declared.
 * Verify #include directives and add any additional header files as necessary.
 */
#define _ZUI_INTERNAL_INSIDE_ //NOTE: for ZUI internal
#include "MApp_Audio.h"
#include "MApp_CIMMI.h"
#include "MApp_ChannelChange.h"
#include "MApp_GlobalSettingSt.h"
#include "MApp_GlobalSettingSt_Common.h"
#include "MApp_GlobalVar.h"
#include "MApp_MHEG5_Main.h"
#include "MApp_MVDMode.h"
#include "MApp_MultiTasks.h"
#include "MApp_SignalMonitor.h"
#include "MApp_Sleep.h"
#include "MApp_Subtitle.h"
#include "MApp_TV.h"
#include "MApp_UiPvr.h"
#include "MApp_ZUI_ACTcoexistWin.h"
#include "MApp_ZUI_ACTepg.h"
#include "MApp_ZUI_APIalphatables.h"
#include "MApp_ZUI_APIcontrols.h"
#include "MApp_ZUI_APIdraw.h"
#include "MApp_ZUI_APIgdi.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_ZUI_APIstyletables.h"
#include "MApp_ZUI_APItables.h"
#include "MApp_ZUI_APIwindow.h"
#include "MApp_ZUI_APIcomponent.h"
#include "SysInit.h"
#include "apiXC_Sys.h"
#include "mapp_mplayer.h"
#include "mapp_videoplayer.h"
#include "msAPI_FSEnv.h"
#include "msAPI_Flash.h"
#include "msAPI_Global.h"
#include "msAPI_MHEG5.h"
#include "msAPI_PVR.h"
#include "msAPI_Thai_Shaping.h"
#include "msIR.h"
#include "mw_debug.h"
#include "stdio.h"


/** Auto-generated stub definition for function: U8 MApp_ZUI_API_GetFocusAlpha(HWND) */
EXTERN_C_LINKAGE U8 MApp_ZUI_API_GetFocusAlpha (HWND hWnd) ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_ZUI_API_GetFocusAlpha (HWND hWnd) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_ReleaseWithoutUpdateDC(void) */
EXTERN_C_LINKAGE void MApp_ZUI_API_ReleaseWithoutUpdateDC () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_ReleaseWithoutUpdateDC (void) 
{
}

/** Auto-generated stub definition for function: HWND MApp_ZUI_API_GetParent(HWND) */
EXTERN_C_LINKAGE HWND MApp_ZUI_API_GetParent (HWND hwnd) ;
EXTERN_C_LINKAGE HWND CppTest_Auto_Stub_MApp_ZUI_API_GetParent (HWND hwnd) 
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: HWND MApp_ZUI_API_GetFocus(void) */
EXTERN_C_LINKAGE HWND MApp_ZUI_API_GetFocus () ;
EXTERN_C_LINKAGE HWND CppTest_Auto_Stub_MApp_ZUI_API_GetFocus (void) 
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_IsAllowFullScreenRelease(void) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_IsAllowFullScreenRelease () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_IsAllowFullScreenRelease (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_UnionRect(RECT *, const RECT *) */
EXTERN_C_LINKAGE void MApp_ZUI_API_UnionRect (RECT * pdrc, const RECT * psrc1) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_UnionRect (RECT * pdrc, const RECT * psrc1) 
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_SetFocusByNav(HWND, U8) */
EXTERN_C_LINKAGE void MApp_ZUI_API_SetFocusByNav (HWND hwnd, U8 nav) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_SetFocusByNav (HWND hwnd, U8 nav) 
{
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_API_DefaultWindowProc(HWND, PMSG) */
EXTERN_C_LINKAGE S32 MApp_ZUI_API_DefaultWindowProc (HWND hWnd, PMSG pMsg) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_API_DefaultWindowProc (HWND hWnd, PMSG pMsg) 
{
    return 0L;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_InvalidateWindow(HWND) */
EXTERN_C_LINKAGE void MApp_ZUI_API_InvalidateWindow (HWND hWnd) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_InvalidateWindow (HWND hWnd) 
{
}

/** Auto-generated stub definition for function: void _MApp_ZUI_API_DrawStyleList(const GRAPHIC_DC *, const RECT *, const DRAWSTYLE *) */
EXTERN_C_LINKAGE void _MApp_ZUI_API_DrawStyleList (const GRAPHIC_DC * pdc, const RECT * rect, const DRAWSTYLE * style_list) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_API_DrawStyleList (const GRAPHIC_DC * pdc, const RECT * rect, const DRAWSTYLE * style_list) 
{
}

/** Auto-generated stub definition for function: U32 MApp_ZUI_API_GetWindowData(HWND) */
EXTERN_C_LINKAGE U32 MApp_ZUI_API_GetWindowData (HWND hwnd) ;
EXTERN_C_LINKAGE U32 CppTest_Auto_Stub_MApp_ZUI_API_GetWindowData (HWND hwnd) 
{
    return 0UL;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_IsWindowVisible(HWND) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_IsWindowVisible (HWND hWnd) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_IsWindowVisible (HWND hWnd) 
{
	if(CppTest_IsCurrentTestCase("TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_if") && hWnd==HWND_EPG_REMINDER_PANEL)
	{
		return TRUE;
	}
	else if(CppTest_IsCurrentTestCase("TestSuite_MApp_EpgTimer_test_MApp_EpgTimer_SetTimerAsNew_else_if") && hWnd==HWND_EPG_RECORDER_PANEL)
	{
		return TRUE;
	}
	else
	{
		return (unsigned char)0;
	}
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_ReleaseDC(const RECT *) */
EXTERN_C_LINKAGE void MApp_ZUI_API_ReleaseDC (const RECT * rect_invalidate) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_ReleaseDC (const RECT * rect_invalidate) 
{
}

/** Auto-generated stub definition for function: LPTSTR MApp_ZUI_API_StringBuffU8toU16(LPTSTR, U8 *, U16) */
EXTERN_C_LINKAGE LPTSTR MApp_ZUI_API_StringBuffU8toU16 (LPTSTR pStrDest, U8 * pStrSource, U16 u16Length) ;
EXTERN_C_LINKAGE LPTSTR CppTest_Auto_Stub_MApp_ZUI_API_StringBuffU8toU16 (LPTSTR pStrDest, U8 * pStrSource, U16 u16Length) 
{
    return pStrDest;
}

/** Auto-generated stub definition for function: GRAPHIC_DC * MApp_ZUI_API_GetBufferDC(void) */
EXTERN_C_LINKAGE GRAPHIC_DC * MApp_ZUI_API_GetBufferDC () ;
EXTERN_C_LINKAGE GRAPHIC_DC * CppTest_Auto_Stub_MApp_ZUI_API_GetBufferDC (void) 
{
    return (GRAPHIC_DC *)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_PrepareBufferDC(GRAPHIC_DC *) */
EXTERN_C_LINKAGE void MApp_ZUI_API_PrepareBufferDC (GRAPHIC_DC * pDC) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_PrepareBufferDC (GRAPHIC_DC * pDC) 
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_IsWindowEnabled(HWND) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_IsWindowEnabled (HWND hWnd) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_IsWindowEnabled (HWND hWnd) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_InvalidateAllSuccessors(HWND) */
EXTERN_C_LINKAGE void MApp_ZUI_API_InvalidateAllSuccessors (HWND hwnd) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_InvalidateAllSuccessors (HWND hwnd) 
{
}

/** Auto-generated stub definition for function: void _MApp_ZUI_API_DrawDynamicComponent(DRAWCOMPONENT, const void *, const GRAPHIC_DC *, const RECT *) */
EXTERN_C_LINKAGE void _MApp_ZUI_API_DrawDynamicComponent (DRAWCOMPONENT component, const void * param, const GRAPHIC_DC * pdc, const RECT * rect) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_API_DrawDynamicComponent (DRAWCOMPONENT component, const void * param, const GRAPHIC_DC * pdc, const RECT * rect) 
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_KillTimer(HWND, U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_KillTimer (HWND hWnd, U32 id) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_KillTimer (HWND hWnd, U32 id) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: GRAPHIC_DC * MApp_ZUI_API_GetScreenDC(void) */
EXTERN_C_LINKAGE GRAPHIC_DC * MApp_ZUI_API_GetScreenDC () ;
EXTERN_C_LINKAGE GRAPHIC_DC * CppTest_Auto_Stub_MApp_ZUI_API_GetScreenDC (void) 
{
    return (GRAPHIC_DC *)0;
}

/** Auto-generated stub definition for function: GRAPHIC_DC MApp_ZUI_API_CreateDC(U16, U16) */
EXTERN_C_LINKAGE GRAPHIC_DC MApp_ZUI_API_CreateDC (U16 w, U16 h) ;
EXTERN_C_LINKAGE GRAPHIC_DC CppTest_Auto_Stub_MApp_ZUI_API_CreateDC (U16 w, U16 h) 
{
    static GRAPHIC_DC _MT_svar1;    return _MT_svar1;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_GetWindowRect(HWND, RECT *) */
EXTERN_C_LINKAGE void MApp_ZUI_API_GetWindowRect (HWND hwnd, RECT * rect) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_GetWindowRect (HWND hwnd, RECT * rect) 
{
}

/** Auto-generated stub definition for function: U8 MApp_ZUI_API_GetDisableAlpha(HWND) */
EXTERN_C_LINKAGE U8 MApp_ZUI_API_GetDisableAlpha (HWND hWnd) ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_ZUI_API_GetDisableAlpha (HWND hWnd) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U16 _MApp_ZUI_API_FindFirstComponentIndex(HWND, DRAWSTYLE_TYPE, DRAWCOMPONENT) */
EXTERN_C_LINKAGE U16 _MApp_ZUI_API_FindFirstComponentIndex (HWND hWnd, DRAWSTYLE_TYPE type, DRAWCOMPONENT comp) ;
EXTERN_C_LINKAGE U16 CppTest_Auto_Stub__MApp_ZUI_API_FindFirstComponentIndex (HWND hWnd, DRAWSTYLE_TYPE type, DRAWCOMPONENT comp) 
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: void _MApp_ZUI_API_ConvertTextComponentToPunctuated(U16, DRAW_PUNCTUATED_DYNAMIC *) */
EXTERN_C_LINKAGE void _MApp_ZUI_API_ConvertTextComponentToPunctuated (U16 u16TextOutIndex, DRAW_PUNCTUATED_DYNAMIC * pComp) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_API_ConvertTextComponentToPunctuated (U16 u16TextOutIndex, DRAW_PUNCTUATED_DYNAMIC * pComp) 
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_SetFocus(HWND) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_SetFocus (HWND hwnd) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_SetFocus (HWND hwnd) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_ReleaseFullScreenDC(void) */
EXTERN_C_LINKAGE void MApp_ZUI_API_ReleaseFullScreenDC () ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_ReleaseFullScreenDC (void) 
{
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_DeleteDC(GRAPHIC_DC) */
EXTERN_C_LINKAGE void MApp_ZUI_API_DeleteDC (GRAPHIC_DC dc) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_DeleteDC (GRAPHIC_DC dc) 
{
}

/** Auto-generated stub definition for function: void _MApp_ZUI_API_DrawStyleListNoText(const GRAPHIC_DC *, const RECT *, const DRAWSTYLE *) */
EXTERN_C_LINKAGE void _MApp_ZUI_API_DrawStyleListNoText (const GRAPHIC_DC * pdc, const RECT * rect, const DRAWSTYLE * style_list) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_API_DrawStyleListNoText (const GRAPHIC_DC * pdc, const RECT * rect, const DRAWSTYLE * style_list) 
{
}

/** Auto-generated stub definition for function: BOOLEAN _MApp_ZUI_API_WindowProcOnIdle(void) */
EXTERN_C_LINKAGE BOOLEAN _MApp_ZUI_API_WindowProcOnIdle () ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub__MApp_ZUI_API_WindowProcOnIdle (void) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_IsSuccessor(HWND, HWND) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_IsSuccessor (HWND parent, HWND child) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_IsSuccessor (HWND parent, HWND child) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void _MApp_ZUI_API_DefaultOnPaint(HWND, PAINT_PARAM *, BOOLEAN) */
EXTERN_C_LINKAGE void _MApp_ZUI_API_DefaultOnPaint (HWND hWnd, PAINT_PARAM * param, BOOLEAN bDrawText) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_API_DefaultOnPaint (HWND hWnd, PAINT_PARAM * param, BOOLEAN bDrawText) 
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_DoesIntersect(const RECT *, const RECT *) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_DoesIntersect (const RECT * psrc1, const RECT * psrc2) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_DoesIntersect (const RECT * psrc1, const RECT * psrc2) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_MoveWindow(HWND, const RECT *) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_MoveWindow (HWND hWnd, const RECT * prc) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_MoveWindow (HWND hWnd, const RECT * prc) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: U8 MApp_ZUI_API_GetNormalAlpha(HWND) */
EXTERN_C_LINKAGE U8 MApp_ZUI_API_GetNormalAlpha (HWND hWnd) ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_ZUI_API_GetNormalAlpha (HWND hWnd) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: HWND MApp_ZUI_API_GetLastSuccessor(HWND) */
EXTERN_C_LINKAGE HWND MApp_ZUI_API_GetLastSuccessor (HWND hwnd) ;
EXTERN_C_LINKAGE HWND CppTest_Auto_Stub_MApp_ZUI_API_GetLastSuccessor (HWND hwnd) 
{
    return (unsigned short)0;
}

/** Auto-generated stub definition for function: U8 MApp_ZUI_API_CountChildren(HWND) */
EXTERN_C_LINKAGE U8 MApp_ZUI_API_CountChildren (HWND hParent) ;
EXTERN_C_LINKAGE U8 CppTest_Auto_Stub_MApp_ZUI_API_CountChildren (HWND hParent) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_SetTimer(HWND, U32, U32) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_SetTimer (HWND hWnd, U32 u32Id, U32 period) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_SetTimer (HWND hWnd, U32 u32Id, U32 period) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: void MApp_ZUI_API_GetWindowInitialRect(HWND, RECT *) */
EXTERN_C_LINKAGE void MApp_ZUI_API_GetWindowInitialRect (HWND hwnd, RECT * rect) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub_MApp_ZUI_API_GetWindowInitialRect (HWND hwnd, RECT * rect) 
{
}

/** Auto-generated stub definition for function: void _MApp_ZUI_API_ConvertTextComponentToDynamic(U16, DRAW_TEXT_OUT_DYNAMIC *) */
EXTERN_C_LINKAGE void _MApp_ZUI_API_ConvertTextComponentToDynamic (U16 u16TextOutIndex, DRAW_TEXT_OUT_DYNAMIC * pComp) ;
EXTERN_C_LINKAGE void CppTest_Auto_Stub__MApp_ZUI_API_ConvertTextComponentToDynamic (U16 u16TextOutIndex, DRAW_TEXT_OUT_DYNAMIC * pComp) 
{
}

/** Auto-generated stub definition for function: BOOLEAN MApp_ZUI_API_IsParentFocused(HWND) */
EXTERN_C_LINKAGE BOOLEAN MApp_ZUI_API_IsParentFocused (HWND hwnd) ;
EXTERN_C_LINKAGE BOOLEAN CppTest_Auto_Stub_MApp_ZUI_API_IsParentFocused (HWND hwnd) 
{
    return (unsigned char)0;
}

/** Auto-generated stub definition for function: S32 MApp_ZUI_API_SendMessage(HWND, MESSAGE_ENUM, WPARAM) */
EXTERN_C_LINKAGE S32 MApp_ZUI_API_SendMessage (HWND hWnd, MESSAGE_ENUM iMsg, WPARAM wParam) ;
EXTERN_C_LINKAGE S32 CppTest_Auto_Stub_MApp_ZUI_API_SendMessage (HWND hWnd, MESSAGE_ENUM iMsg, WPARAM wParam) 
{
    return 0L;
}
