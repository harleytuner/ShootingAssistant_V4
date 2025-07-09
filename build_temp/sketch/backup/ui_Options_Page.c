#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\backup\\ui_Options_Page.c"
// DEADEYE Options Page - Military-grade shooting assistant
// Modern UI implementation with DEADEYE branding

#include "ui.h"
#include "ui_modern_theme.h"
// Explicitly include headers for pages it navigates to, ensuring declarations are seen
#include "ui_Bubble_Level_Page.h"
#include "ui_Artificial_Horizon_Page.h"
#include "ui_Shot_Counter_Page.h"
#include "ui_Stage_Timer_Page.h"
#include "ui_Competition_Page.h"

lv_obj_t *uic_Page1;
lv_obj_t *ui_Options_Page;
lv_obj_t *ui_OptionsPageLabel;
lv_obj_t *ui_Page_1;
lv_obj_t *ui_BubbleLevelBTN;
lv_obj_t *ui_Page2;
lv_obj_t *ui_HorizonBTN;
lv_obj_t *ui_Page3;
lv_obj_t *ui_ShotCounterBTN;
lv_obj_t *ui_Page4;
lv_obj_t *ui_StageTimerBTN1;
lv_obj_t *ui_Page5;
lv_obj_t *ui_CompetitionBTN1;
lv_obj_t *ui_Page6;
lv_obj_t *ui_SettingsBTN;

// event funtions
void ui_event_Page_1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Bubble_Level_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Bubble_Level_Page_screen_init);
    }
}

void ui_event_Page2(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Artificial_Horizon_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0,
                          &ui_Artificial_Horizon_Page_screen_init);
    }
}

void ui_event_Page3(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Shot_Counter_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Shot_Counter_Page_screen_init);
    }
}

void ui_event_Page4(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Stage_Timer_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Stage_Timer_Page_screen_init);
    }
}

void ui_event_Page5(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Competition_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Competition_Page_screen_init);
    }
}

void ui_event_Page6(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Settings_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_Settings_Page_screen_init);
    }
}

// build funtions

void ui_Options_Page_screen_init(void)
{
    ui_Options_Page = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Options_Page, LV_OBJ_FLAG_SCROLLABLE);

    // Apply DEADEYE modern theme
    ui_modern_style_page(ui_Options_Page);

    // DEADEYE Title
    ui_OptionsPageLabel = lv_label_create(ui_Options_Page);
    lv_obj_set_width(ui_OptionsPageLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_OptionsPageLabel, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_OptionsPageLabel, 0);
    lv_obj_set_y(ui_OptionsPageLabel, 25);
    lv_obj_set_align(ui_OptionsPageLabel, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_OptionsPageLabel, "DEADEYE");
    ui_modern_style_label_title(ui_OptionsPageLabel);

    // Subtitle
    lv_obj_t *subtitle = lv_label_create(ui_Options_Page);
    lv_obj_set_width(subtitle, LV_SIZE_CONTENT);
    lv_obj_set_height(subtitle, LV_SIZE_CONTENT);
    lv_obj_set_x(subtitle, 0);
    lv_obj_set_y(subtitle, 55);
    lv_obj_set_align(subtitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(subtitle, "PRECISION TOOLS");
    ui_modern_style_label_body(subtitle);
    lv_obj_set_style_text_color(subtitle, ui_modern_colors.accent_orange, LV_PART_MAIN);

    ui_Page_1 = lv_btn_create(ui_Options_Page);
    lv_obj_set_width(ui_Page_1, 100);
    lv_obj_set_height(ui_Page_1, 25);
    lv_obj_set_x(ui_Page_1, 0);
    lv_obj_set_y(ui_Page_1, -70);
    lv_obj_set_align(ui_Page_1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Page_1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Page_1, LV_OBJ_FLAG_SCROLLABLE);

    ui_BubbleLevelBTN = lv_label_create(ui_Page_1);
    lv_obj_set_width(ui_BubbleLevelBTN, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BubbleLevelBTN, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_BubbleLevelBTN, LV_ALIGN_CENTER);
    lv_label_set_text(ui_BubbleLevelBTN, "Bubble Level");

    ui_Page2 = lv_btn_create(ui_Options_Page);
    lv_obj_set_width(ui_Page2, 100);
    lv_obj_set_height(ui_Page2, 25);
    lv_obj_set_x(ui_Page2, 0);
    lv_obj_set_y(ui_Page2, -30);
    lv_obj_set_align(ui_Page2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Page2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Page2, LV_OBJ_FLAG_SCROLLABLE);

    ui_HorizonBTN = lv_label_create(ui_Page2);
    lv_obj_set_width(ui_HorizonBTN, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_HorizonBTN, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_HorizonBTN, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HorizonBTN, "Horizon");

    ui_Page3 = lv_btn_create(ui_Options_Page);
    lv_obj_set_width(ui_Page3, 100);
    lv_obj_set_height(ui_Page3, 25);
    lv_obj_set_x(ui_Page3, 0);
    lv_obj_set_y(ui_Page3, 10);
    lv_obj_set_align(ui_Page3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Page3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Page3, LV_OBJ_FLAG_SCROLLABLE);

    ui_ShotCounterBTN = lv_label_create(ui_Page3);
    lv_obj_set_width(ui_ShotCounterBTN, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ShotCounterBTN, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_ShotCounterBTN, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ShotCounterBTN, "Shot Counter");

    ui_Page4 = lv_btn_create(ui_Options_Page);
    lv_obj_set_width(ui_Page4, 100);
    lv_obj_set_height(ui_Page4, 25);
    lv_obj_set_x(ui_Page4, 0);
    lv_obj_set_y(ui_Page4, 50);
    lv_obj_set_align(ui_Page4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Page4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Page4, LV_OBJ_FLAG_SCROLLABLE);

    ui_StageTimerBTN1 = lv_label_create(ui_Page4);
    lv_obj_set_width(ui_StageTimerBTN1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_StageTimerBTN1, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_StageTimerBTN1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_StageTimerBTN1, "Stage Timer");

    ui_Page5 = lv_btn_create(ui_Options_Page);
    lv_obj_set_width(ui_Page5, 100);
    lv_obj_set_height(ui_Page5, 25);
    lv_obj_set_x(ui_Page5, 0);
    lv_obj_set_y(ui_Page5, 90);
    lv_obj_set_align(ui_Page5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Page5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Page5, LV_OBJ_FLAG_SCROLLABLE);

    ui_CompetitionBTN1 = lv_label_create(ui_Page5);
    lv_obj_set_width(ui_CompetitionBTN1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CompetitionBTN1, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_CompetitionBTN1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CompetitionBTN1, "Competition");

    ui_Page6 = lv_btn_create(ui_Options_Page);
    lv_obj_set_width(ui_Page6, 100);
    lv_obj_set_height(ui_Page6, 25);
    lv_obj_set_x(ui_Page6, 0);
    lv_obj_set_y(ui_Page6, 120);
    lv_obj_set_align(ui_Page6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Page6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_Page6, LV_OBJ_FLAG_SCROLLABLE);

    ui_SettingsBTN = lv_label_create(ui_Page6);
    lv_obj_set_width(ui_SettingsBTN, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsBTN, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_SettingsBTN, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsBTN, "Settings");

    lv_obj_add_event_cb(ui_Page_1, ui_event_Page_1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Page2, ui_event_Page2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Page3, ui_event_Page3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Page4, ui_event_Page4, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Page5, ui_event_Page5, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Page6, ui_event_Page6, LV_EVENT_ALL, NULL);

    uic_Page1 = ui_Page_1;
}

void ui_Options_Page_screen_destroy(void)
{
    if (ui_Options_Page)
        lv_obj_del(ui_Options_Page);

    ui_Options_Page = NULL;
    ui_OptionsPageLabel = NULL;
    uic_Page1 = NULL;
    ui_Page_1 = NULL;
    ui_BubbleLevelBTN = NULL;
    ui_Page2 = NULL;
    ui_HorizonBTN = NULL;
    ui_Page3 = NULL;
    ui_ShotCounterBTN = NULL;
    ui_Page4 = NULL;
    ui_StageTimerBTN1 = NULL;
    ui_Page5 = NULL;
    ui_CompetitionBTN1 = NULL;
    ui_Page6 = NULL;
    ui_SettingsBTN = NULL;
}
