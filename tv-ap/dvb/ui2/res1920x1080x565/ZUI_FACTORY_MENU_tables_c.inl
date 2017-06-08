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

static KEYEVENT _ZUI_TBLSEG _Factory_Menu_Items_Keymap[] =
{
{VK_SELECT, EN_EXE_FACTORY_MENU_NEXT_PAGE},
//{VK_MENU, EN_EXE_FACTORY_MENU_PREV_PAGE},
{VK_EXIT, EN_EXE_FACTORY_MENU_PREV_PAGE},
{VK_KEYPAD_INPUT_SOURCE, EN_EXE_FACTORY_MENU_PREV_PAGE},
{VK_LEFT, EN_EXE_FACTORY_MENU_GOTO_BAR_ADJUST},
{VK_RIGHT, EN_EXE_FACTORY_MENU_GOTO_BAR_ADJUST},
//{VK_INPUT_SOURCE, EN_EXE_NAV_KEY_DOWN},
{VK_DOWN, EN_EXE_QMAP_NEXT_PAGE},
{VK_UP, EN_EXE_QMAP_PREV_PAGE},
//{VK_PAGE_DOWN, EN_EXE_QMAP_PAGE_DOWN},
//{VK_PAGE_UP, EN_EXE_QMAP_PAGE_UP},
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _Factory_Menu_MODE_Keymap[] =
{
{VK_SELECT, EN_EXE_FACTORY_MENU_NEXT_PAGE},
{VK_SELECT, EN_EXE_BIST_TEST},
//{VK_MENU, EN_EXE_FACTORY_MENU_PREV_PAGE},
{VK_KEYPAD_INPUT_SOURCE, EN_EXE_FACTORY_MENU_PREV_PAGE},
{VK_EXIT, EN_EXE_FACTORY_MENU_PREV_PAGE},
{VK_LEFT, EN_EXE_FACTORY_MENU_GOTO_BAR_ADJUST},
{VK_RIGHT, EN_EXE_FACTORY_MENU_GOTO_BAR_ADJUST},
{VK_LEFT, EN_EXE_FACTORY_MENU_ADJ_DEC},
{VK_RIGHT, EN_EXE_FACTORY_MENU_ADJ_INC},
//{VK_INPUT_SOURCE, EN_EXE_NAV_KEY_DOWN},
{VK_DOWN, EN_EXE_QMAP_NEXT_PAGE},
{VK_UP, EN_EXE_QMAP_PREV_PAGE},
//{VK_PAGE_DOWN, EN_EXE_QMAP_PAGE_DOWN},
//{VK_PAGE_UP, EN_EXE_QMAP_PAGE_UP},
{VK_NULL, 0},
};
static KEYEVENT _ZUI_TBLSEG _Factory_Menu_BAR_ITEM_Keymap[] =
{
{VK_LEFT, EN_EXE_FACTORY_MENU_ADJ_DEC},
{VK_RIGHT, EN_EXE_FACTORY_MENU_ADJ_INC},
//{VK_MENU, EN_EXE_FACTORY_MENU_EXIT_BAR_ADJUST},
{VK_EXIT, EN_EXE_FACTORY_MENU_EXIT_BAR_ADJUST},
{VK_KEYPAD_INPUT_SOURCE, EN_EXE_FACTORY_MENU_EXIT_BAR_ADJUST},
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _Factory_Menu_QMAP_Keymap[] =
{
{VK_SELECT, EN_EXE_FACTORY_MENU_NEXT_PAGE},
{VK_NULL, 0},
};

/// @Keymap_Table_End

/////////////////////////////////////////////////////

// Navigation Table

/////////////////////////////////////////////////////

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM0_Navigation[] = {HWND_FACTORY_MENU_ITEM0, HWND_FACTORY_MENU_ITEM1, HWND_FACTORY_MENU_ITEM0, HWND_FACTORY_MENU_ITEM0};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM1_Navigation[] = {HWND_FACTORY_MENU_ITEM0, HWND_FACTORY_MENU_ITEM2, HWND_FACTORY_MENU_ITEM1, HWND_FACTORY_MENU_ITEM1};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM2_Navigation[] = {HWND_FACTORY_MENU_ITEM1, HWND_FACTORY_MENU_ITEM3, HWND_FACTORY_MENU_ITEM2, HWND_FACTORY_MENU_ITEM2};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM3_Navigation[] = {HWND_FACTORY_MENU_ITEM2, HWND_FACTORY_MENU_ITEM4, HWND_FACTORY_MENU_ITEM3, HWND_FACTORY_MENU_ITEM3};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM4_Navigation[] = {HWND_FACTORY_MENU_ITEM3, HWND_FACTORY_MENU_ITEM5, HWND_FACTORY_MENU_ITEM4, HWND_FACTORY_MENU_ITEM4};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM5_Navigation[] = {HWND_FACTORY_MENU_ITEM4, HWND_FACTORY_MENU_ITEM6, HWND_FACTORY_MENU_ITEM5, HWND_FACTORY_MENU_ITEM5};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM6_Navigation[] = {HWND_FACTORY_MENU_ITEM5, HWND_FACTORY_MENU_ITEM7, HWND_FACTORY_MENU_ITEM6, HWND_FACTORY_MENU_ITEM6};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM7_Navigation[] = {HWND_FACTORY_MENU_ITEM6, HWND_FACTORY_MENU_ITEM8, HWND_FACTORY_MENU_ITEM7, HWND_FACTORY_MENU_ITEM7};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM8_Navigation[] = {HWND_FACTORY_MENU_ITEM7, HWND_FACTORY_MENU_ITEM9, HWND_FACTORY_MENU_ITEM8, HWND_FACTORY_MENU_ITEM8};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM9_Navigation[] = {HWND_FACTORY_MENU_ITEM8, HWND_FACTORY_MENU_ITEM10, HWND_FACTORY_MENU_ITEM9, HWND_FACTORY_MENU_ITEM9};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM10_Navigation[] = {HWND_FACTORY_MENU_ITEM9, HWND_FACTORY_MENU_ITEM11, HWND_FACTORY_MENU_ITEM10, HWND_FACTORY_MENU_ITEM10};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM11_Navigation[] = {HWND_FACTORY_MENU_ITEM10, HWND_FACTORY_MENU_ITEM12, HWND_FACTORY_MENU_ITEM11, HWND_FACTORY_MENU_ITEM11};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM12_Navigation[] = {HWND_FACTORY_MENU_ITEM11, HWND_FACTORY_MENU_ITEM13, HWND_FACTORY_MENU_ITEM12, HWND_FACTORY_MENU_ITEM12};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM13_Navigation[] = {HWND_FACTORY_MENU_ITEM12, HWND_FACTORY_MENU_ITEM14, HWND_FACTORY_MENU_ITEM13, HWND_FACTORY_MENU_ITEM13};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM14_Navigation[] = {HWND_FACTORY_MENU_ITEM13, HWND_FACTORY_MENU_ITEM15, HWND_FACTORY_MENU_ITEM14, HWND_FACTORY_MENU_ITEM14};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM15_Navigation[] = {HWND_FACTORY_MENU_ITEM14, HWND_FACTORY_MENU_ITEM16, HWND_FACTORY_MENU_ITEM15, HWND_FACTORY_MENU_ITEM15};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM16_Navigation[] = {HWND_FACTORY_MENU_ITEM15, HWND_FACTORY_MENU_ITEM17, HWND_FACTORY_MENU_ITEM16, HWND_FACTORY_MENU_ITEM16};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM17_Navigation[] = {HWND_FACTORY_MENU_ITEM16, HWND_FACTORY_MENU_ITEM18, HWND_FACTORY_MENU_ITEM17, HWND_FACTORY_MENU_ITEM17};

static HWND _MP_TBLSEG _FACTORY_MENU_ITEM18_Navigation[] = {HWND_FACTORY_MENU_ITEM17, HWND_FACTORY_MENU_ITEM18, HWND_FACTORY_MENU_ITEM18, HWND_FACTORY_MENU_ITEM18};

//////////////////////////////////////////////////////
// Window List

WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Factory_Menu[] =
{
    // 0 = HWND_MAINFRAME
    {
        EN_ZUI_MAINFRAMEWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 1 = HWND_FACTORY_MENU_BG_TRANSPARENT
    {
        EN_ZUI_BGTANSPARENT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _Factory_Menu_QMAP_Keymap,
    },

    // 2 = HWND_FACTORY_MENU_BAR_TRANS
    {
        EN_ZUI_BGTANSPARENT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 3 = HWND_FACTORY_MENU_BAR
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _Factory_Menu_BAR_ITEM_Keymap,
    },

    // 4 = HWND_FACTORY_MENU_BAR_TEXT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 5 = HWND_FACTORY_MENU_BAR_OPTION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 6 = HWND_FACTORY_MENU_BAR_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 7 = HWND_FACTORY_MENU_BAR_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 8 = HWND_FACTORY_MENU_BG_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 9 = HWND_FACTORY_MENU_BG_RECT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 10 = HWND_FACTORY_MENU_TITLE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 11 = HWND_FACTORY_MENU_INPUT_INFO
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 12 = HWND_FACTORY_MENU_INPUT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 13 = HWND_FACTORY_MENU_INPUT_TYPE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // 14 = HWND_FACTORY_MENU_LIST
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 15 = HWND_FACTORY_MENU_ITEM0
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM0_Navigation,
        _Factory_Menu_MODE_Keymap,
    },

    // 16 = HWND_FACTORY_MENU_ITEM0_NAME
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 17 = HWND_FACTORY_MENU_ITEM0_VALUE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 18 = HWND_FACTORY_MENU_ITEM1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM1_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 19 = HWND_FACTORY_MENU_ITEM1_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 20 = HWND_FACTORY_MENU_ITEM1_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 21 = HWND_FACTORY_MENU_ITEM2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM2_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 22 = HWND_FACTORY_MENU_ITEM2_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 23 = HWND_FACTORY_MENU_ITEM2_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 24 = HWND_FACTORY_MENU_ITEM3
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM3_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 25 = HWND_FACTORY_MENU_ITEM3_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 26 = HWND_FACTORY_MENU_ITEM3_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 27 = HWND_FACTORY_MENU_ITEM4
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM4_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 28 = HWND_FACTORY_MENU_ITEM4_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 29 = HWND_FACTORY_MENU_ITEM4_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 30 = HWND_FACTORY_MENU_ITEM5
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM5_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 31 = HWND_FACTORY_MENU_ITEM5_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 32 = HWND_FACTORY_MENU_ITEM5_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 33 = HWND_FACTORY_MENU_ITEM6
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM6_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 34 = HWND_FACTORY_MENU_ITEM6_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 35 = HWND_FACTORY_MENU_ITEM6_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 36 = HWND_FACTORY_MENU_ITEM7
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM7_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 37 = HWND_FACTORY_MENU_ITEM7_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 38 = HWND_FACTORY_MENU_ITEM7_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 39 = HWND_FACTORY_MENU_ITEM8
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM8_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 40 = HWND_FACTORY_MENU_ITEM8_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 41 = HWND_FACTORY_MENU_ITEM8_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 42 = HWND_FACTORY_MENU_ITEM9
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM9_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 43 = HWND_FACTORY_MENU_ITEM9_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 44 = HWND_FACTORY_MENU_ITEM9_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 45 = HWND_FACTORY_MENU_ITEM10
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM10_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 46 = HWND_FACTORY_MENU_ITEM10_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 47 = HWND_FACTORY_MENU_ITEM10_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 48 = HWND_FACTORY_MENU_ITEM11
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM11_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 49 = HWND_FACTORY_MENU_ITEM11_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 50 = HWND_FACTORY_MENU_ITEM11_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 51 = HWND_FACTORY_MENU_ITEM12
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM12_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 52 = HWND_FACTORY_MENU_ITEM12_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 53 = HWND_FACTORY_MENU_ITEM12_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 54 = HWND_FACTORY_MENU_ITEM13
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM13_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 55 = HWND_FACTORY_MENU_ITEM13_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 56 = HWND_FACTORY_MENU_ITEM13_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 57 = HWND_FACTORY_MENU_ITEM14
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM14_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 58 = HWND_FACTORY_MENU_ITEM14_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 59 = HWND_FACTORY_MENU_ITEM14_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 60 = HWND_FACTORY_MENU_ITEM15
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM15_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 61 = HWND_FACTORY_MENU_ITEM15_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 62 = HWND_FACTORY_MENU_ITEM15_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 63 = HWND_FACTORY_MENU_ITEM16
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM16_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 64 = HWND_FACTORY_MENU_ITEM16_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 65 = HWND_FACTORY_MENU_ITEM16_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 66 = HWND_FACTORY_MENU_ITEM17
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_DISABLED|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM17_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 67 = HWND_FACTORY_MENU_ITEM17_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 68 = HWND_FACTORY_MENU_ITEM17_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 69 = HWND_FACTORY_MENU_ITEM18
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_DISABLED|WS_SRCALPHAREPLACEDSTALPHA,
        _FACTORY_MENU_ITEM18_Navigation,
        _Factory_Menu_Items_Keymap,
    },

    // 70 = HWND_FACTORY_MENU_ITEM18_NAME
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 71 = HWND_FACTORY_MENU_ITEM18_VALUE
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // 72 = HWND_FACTORY_MENU_HOT_KEY_HELP1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 73 = HWND_FACTORY_MENU_HOT_KEY_HELP2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 74 = HWND_FACTORY_SW_INFO
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 75 = HWND_FACTORY_SW_INFO_VERSION
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 76 = HWND_FACTORY_SW_INFO_TEXT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // 77 = HWND_FACTORY_MENU_BOARD_INFO
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

};
