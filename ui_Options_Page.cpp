// DEADEYE Options Page - Military-grade shooting assistant
// Modern UI implementation with DEADEYE branding

#include "ui.h"
#include "ui_modern_theme.h"
#include "ui_Bubble_Level_Page.h"
#include "ui_Artificial_Horizon_Page.h"
#include "ui_Shot_Counter_Page.h"
#include "ui_Stage_Timer_Page.h"
#include "ui_Competition_Page.h"

// Use nullptr for pointer initialization in C++
lv_obj_t *uic_Page1 = nullptr;
lv_obj_t *ui_Options_Page = nullptr;
lv_obj_t *ui_OptionsPageLabel = nullptr;
lv_obj_t *ui_Page_1 = nullptr;
lv_obj_t *ui_BubbleLevelBTN = nullptr;
lv_obj_t *ui_Page2 = nullptr;
lv_obj_t *ui_HorizonBTN = nullptr;
lv_obj_t *ui_Page3 = nullptr;
lv_obj_t *ui_ShotCounterBTN = nullptr;
lv_obj_t *ui_Page4 = nullptr;
lv_obj_t *ui_StageTimerBTN1 = nullptr;
lv_obj_t *ui_Page5 = nullptr;
lv_obj_t *ui_CompetitionBTN1 = nullptr;
lv_obj_t *ui_Page6 = nullptr;
lv_obj_t *ui_SettingsBTN = nullptr;

// event functions
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

// ...existing code for the rest of the file...
