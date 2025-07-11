#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ui.h"
// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.2
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_comp.h"
#include "ui_comp_hook.h"
#include "ui_events.h"
#include "ui_battery_indicator.h"

    ///////////////////// SCREENS ////////////////////

#include "ui_Options_Page.h"
#include "ui_Bubble_Level_Page.h"
#include "ui_Artificial_Horizon_Page.h"
#include "ui_Shot_Counter_Page.h"
#include "ui_Stage_Timer_Page.h"
#include "ui_Competition_Page.h"
#include "ui_Settings_Page.h"
#include "ui_modern_theme.h"
#include "ui_modern_options.h"

    float get_qmi8658_roll_degrees(void); // <--- ADD THIS LINE

    ///////////////////// VARIABLES ////////////////////

    // EVENTS

    extern lv_obj_t *ui____initial_actions0;

    // UI INIT
    void ui_init(void);
    void ui_destroy(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
