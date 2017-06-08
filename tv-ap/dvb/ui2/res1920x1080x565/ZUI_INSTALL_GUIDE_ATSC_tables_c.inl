////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2010 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (''MStar Confidential Information'') by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// This file is automatically generated by SkinTool [Version:0.2.3][Build:Jun 14 2013 10:00:02]
/////////////////////////////////////////////////////////////////////////////


/// @Keymap_Table_Begin

static KEYEVENT _ZUI_TBLSEG _INSTALL_GUILD_INCDEC_KEY[] =
{
{ VK_MENU, EN_EXE_GOTO_PARENTPAGE},
{ VK_LEFT, EN_EXE_DEC_VALUE},
{ VK_RIGHT, EN_EXE_INC_VALUE},
{ VK_SELECT, EN_EXE_NAV_KEY_DOWN},
{ VK_NULL, 0 },
};

static KEYEVENT _ZUI_TBLSEG _INSTALL_GUILD_GOTOSUBPAGE_KEY[] =
{
{ VK_MENU, EN_EXE_GOTO_PARENTPAGE},
{ VK_SELECT, EN_EXE_GOTO_SUBPAGE},
{ VK_RIGHT, EN_EXE_GOTO_SUBPAGE},
{ VK_NULL, 0 },
};

static KEYEVENT _ZUI_TBLSEG _INSTALL_TUNE_SCAN_PROGRESS_BAR[] =
{
{ VK_SELECT, EN_EXE_ACTION_NULL},
{ VK_NULL, 0 },
};

/// @Keymap_Table_End

/////////////////////////////////////////////////////

// Navigation Table

/////////////////////////////////////////////////////

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_LANGUAGE_TITLE_TEXT_Navigation[] = {HWND_INSTALL_MAIN_OSD_LANGUAGE_TEXT, HWND_INSTALL_MAIN_OSD_LANGUAGE_TEXT, HWND_INSTALL_MAIN_OSD_LANGUAGE_TEXT, HWND_INSTALL_MAIN_OSD_LANGUAGE_TEXT};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_LANGUAGE_Navigation[] = {HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT, HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT, HWND_INSTALL_MAIN_OSD_LANGUAGE, HWND_INSTALL_MAIN_OSD_LANGUAGE};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_LANGUAGE_LEFT_ARROW_Navigation[] = {HWND_INSTALL_MAIN_OSD_LANGUAGE_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_LANGUAGE_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_LANGUAGE_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_LANGUAGE_RIGHT_ARROW};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_LANGUAGE_NEXT_Navigation[] = {HWND_INSTALL_MAIN_OSD_LANGUAGE, HWND_INSTALL_MAIN_OSD_LANGUAGE, HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT, HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT};

static HWND _MP_TBLSEG _INSTALL_MAIN_PAGE_TIME_Navigation[] = {HWND_INSTALL_MAIN_PAGE_LANGUAGE, HWND_INSTALL_MAIN_PAGE_LANGUAGE, HWND_INSTALL_MAIN_PAGE_LANGUAGE, HWND_INSTALL_MAIN_PAGE_LANGUAGE};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_TITLE_Navigation[] = {HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE, HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE, HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE, HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME_NEXT, HWND_INSTALL_MAIN_OSD_DST, HWND_INSTALL_MAIN_OSD_TIME, HWND_INSTALL_MAIN_OSD_TIME};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_LEFT_ARROW_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_TIME_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_TIME_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_TIME_RIGHT_ARROW};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_RIGHT_ARROW_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME_LEFT_ARROW, HWND_INSTALL_MAIN_OSD_TIME_LEFT_ARROW, HWND_INSTALL_MAIN_OSD_TIME_LEFT_ARROW, HWND_INSTALL_MAIN_OSD_TIME_LEFT_ARROW};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_NEXT_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME_FORMAT, HWND_INSTALL_MAIN_OSD_TIME, HWND_INSTALL_MAIN_OSD_TIME_NEXT, HWND_INSTALL_MAIN_OSD_TIME_NEXT};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_DST_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME, HWND_INSTALL_MAIN_OSD_TIME_FORMAT, HWND_INSTALL_MAIN_OSD_DST, HWND_INSTALL_MAIN_OSD_DST};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_DST_OPTION_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME_OPTION, HWND_INSTALL_MAIN_OSD_TIME_OPTION, HWND_INSTALL_MAIN_OSD_TIME_OPTION, HWND_INSTALL_MAIN_OSD_TIME_OPTION};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_FORMAT_Navigation[] = {HWND_INSTALL_MAIN_OSD_DST, HWND_INSTALL_MAIN_OSD_TIME_NEXT, HWND_INSTALL_MAIN_OSD_TIME_FORMAT, HWND_INSTALL_MAIN_OSD_TIME_FORMAT};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_TIME_FORMAT_OPTION_Navigation[] = {HWND_INSTALL_MAIN_OSD_TIME_OPTION, HWND_INSTALL_MAIN_OSD_TIME_OPTION, HWND_INSTALL_MAIN_OSD_TIME_OPTION, HWND_INSTALL_MAIN_OSD_TIME_OPTION};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_ANT_TITLE_TEXT_Navigation[] = {HWND_INSTALL_MAIN_OSD_ANT_TEXT, HWND_INSTALL_MAIN_OSD_ANT_TEXT, HWND_INSTALL_MAIN_OSD_ANT_TEXT, HWND_INSTALL_MAIN_OSD_ANT_TEXT};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_ANT_Navigation[] = {HWND_INSTALL_MAIN_OSD_ANT_NEXT, HWND_INSTALL_MAIN_OSD_ANT_NEXT, HWND_INSTALL_MAIN_OSD_ANT, HWND_INSTALL_MAIN_OSD_ANT};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_ANT_LEFT_ARROW_Navigation[] = {HWND_INSTALL_MAIN_OSD_ANT_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_ANT_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_ANT_RIGHT_ARROW, HWND_INSTALL_MAIN_OSD_ANT_RIGHT_ARROW};

static HWND _MP_TBLSEG _INSTALL_MAIN_OSD_ANT_NEXT_Navigation[] = {HWND_INSTALL_MAIN_OSD_ANT, HWND_INSTALL_MAIN_OSD_ANT, HWND_INSTALL_MAIN_OSD_ANT_NEXT, HWND_INSTALL_MAIN_OSD_ANT_NEXT};

static HWND _MP_TBLSEG _INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_Navigation[] = {HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH};

static HWND _MP_TBLSEG _INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_Navigation[] = {HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH};

static HWND _MP_TBLSEG _INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_Navigation[] = {HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH, HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH};

//////////////////////////////////////////////////////
// Window List

WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Install_Guide_Atsc[] =
{
    // 0 = HWND_MAINFRAME
    {
        EN_ZUI_MAINFRAMEWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 1 = HWND_INSTALL_BACKGROUND_ATSC
    {
        EN_ZUI_INSTALL_GUIDE_WINPROC_ATSC, (void *)INSTALL_GUIDE_TIME_OUT_MS, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 2 = HWND_INSTALL_BACKGROUND_BG_L
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 3 = HWND_INSTALL_BACKGROUND_BG_C
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 4 = HWND_INSTALL_BACKGROUND_BG_R
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 5 = HWND_INSTALL_BACKGROUND_MENU
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 6 = HWND_INSTALL_BACKGROUND_OK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 7 = HWND_INSTALL_MAIN_PAGE_ATSC
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 8 = HWND_INSTALL_MAIN_TITLE_ATSC
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 9 = HWND_INSTALL_MAIN_PAGE_LANGUAGE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 10 = HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 11 = HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_LANGUAGE_TITLE_TEXT_Navigation,
        NULL,
    },

    // 12 = HWND_INSTALL_MAIN_OSD_LANGUAGE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_LANGUAGE_Navigation,
        _INSTALL_GUILD_INCDEC_KEY,
    },

    // 13 = HWND_INSTALL_MAIN_OSD_LANGUAGE_FOCUS_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 14 = HWND_INSTALL_MAIN_OSD_LANGUAGE_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 15 = HWND_INSTALL_MAIN_OSD_LANGUAGE_OPTION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 16 = HWND_INSTALL_MAIN_OSD_LANGUAGE_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_LANGUAGE_LEFT_ARROW_Navigation,
        NULL,
    },

    // 17 = HWND_INSTALL_MAIN_OSD_LANGUAGE_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 18 = HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_LANGUAGE_NEXT_Navigation,
        _INSTALL_GUILD_GOTOSUBPAGE_KEY,
    },

    // 19 = HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 20 = HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 21 = HWND_INSTALL_MAIN_PAGE_TIME
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_PAGE_TIME_Navigation,
        NULL,
    },

    // 22 = HWND_INSTALL_MAIN_OSD_TIME_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_TITLE_Navigation,
        NULL,
    },

    // 23 = HWND_INSTALL_MAIN_OSD_TIME_TITLE_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 24 = HWND_INSTALL_MAIN_OSD_TIME
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_Navigation,
        _INSTALL_GUILD_INCDEC_KEY,
    },

    // 25 = HWND_INSTALL_MAIN_OSD_TIME_FOCUS_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 26 = HWND_INSTALL_MAIN_OSD_TIME_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 27 = HWND_INSTALL_MAIN_OSD_TIME_OPTION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 28 = HWND_INSTALL_MAIN_OSD_TIME_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_LEFT_ARROW_Navigation,
        NULL,
    },

    // 29 = HWND_INSTALL_MAIN_OSD_TIME_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_RIGHT_ARROW_Navigation,
        NULL,
    },

    // 30 = HWND_INSTALL_MAIN_OSD_TIME_NEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_NEXT_Navigation,
        _INSTALL_GUILD_GOTOSUBPAGE_KEY,
    },

    // 31 = HWND_INSTALL_MAIN_OSD_TIME_NEXT_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 32 = HWND_INSTALL_MAIN_OSD_TIME_NEXT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 33 = HWND_INSTALL_MAIN_OSD_DST
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_DST_Navigation,
        _INSTALL_GUILD_INCDEC_KEY,
    },

    // 34 = HWND_INSTALL_MAIN_OSD_DST_FOCUS_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 35 = HWND_INSTALL_MAIN_OSD_DST_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 36 = HWND_INSTALL_MAIN_OSD_DST_OPTION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_DST_OPTION_Navigation,
        NULL,
    },

    // 37 = HWND_INSTALL_MAIN_OSD_DST_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 38 = HWND_INSTALL_MAIN_OSD_DST_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 39 = HWND_INSTALL_MAIN_OSD_TIME_FORMAT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_FORMAT_Navigation,
        _INSTALL_GUILD_INCDEC_KEY,
    },

    // 40 = HWND_INSTALL_MAIN_OSD_TIME_FORMAT_FOCUS_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 41 = HWND_INSTALL_MAIN_OSD_TIME_FORMAT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 42 = HWND_INSTALL_MAIN_OSD_TIME_FORMAT_OPTION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_TIME_FORMAT_OPTION_Navigation,
        NULL,
    },

    // 43 = HWND_INSTALL_MAIN_OSD_TIME_FORMAT_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 44 = HWND_INSTALL_MAIN_OSD_TIME_FORMAT_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 45 = HWND_INSTALL_MAIN_PAGE_ANT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 46 = HWND_INSTALL_MAIN_OSD_ANT_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 47 = HWND_INSTALL_MAIN_OSD_ANT_TITLE_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_ANT_TITLE_TEXT_Navigation,
        NULL,
    },

    // 48 = HWND_INSTALL_MAIN_OSD_ANT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_ANT_Navigation,
        _INSTALL_GUILD_INCDEC_KEY,
    },

    // 49 = HWND_INSTALL_MAIN_OSD_ANT_FOCUS_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 50 = HWND_INSTALL_MAIN_OSD_ANT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 51 = HWND_INSTALL_MAIN_OSD_ANT_OPTION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 52 = HWND_INSTALL_MAIN_OSD_ANT_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_ANT_LEFT_ARROW_Navigation,
        NULL,
    },

    // 53 = HWND_INSTALL_MAIN_OSD_ANT_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 54 = HWND_INSTALL_MAIN_OSD_ANT_NEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_MAIN_OSD_ANT_NEXT_Navigation,
        _INSTALL_GUILD_GOTOSUBPAGE_KEY,
    },

    // 55 = HWND_INSTALL_MAIN_OSD_ANT_NEXT_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 56 = HWND_INSTALL_MAIN_OSD_ANT_NEXT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 57 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 58 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_Navigation,
        NULL,
    },

    // 59 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 60 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_VALUE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 61 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_PROGRAM
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 62 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_Navigation,
        NULL,
    },

    // 63 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 64 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_VALUE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 65 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_PROGRAM
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 66 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_Navigation,
        NULL,
    },

    // 67 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 68 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_VALUE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 69 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_PROGRAM
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 70 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 71 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_PERCENT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 72 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_PERCENT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 73 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 74 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH_VALUE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 75 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_CH_TYPE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 76 = HWND_INSTALL_SCAN_RESULT_SUB_PAGE_PROGRESSBAR
    {
        EN_ZUI_RECTPROGRESSBAR_2_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        (void*)_INSTALL_TUNE_SCAN_PROGRESS_BAR,
    },

};
