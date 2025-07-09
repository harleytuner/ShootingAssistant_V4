// Enhanced Options Page with Modern UI Design
// Creates a premium, consumer-grade main menu

#include "ui.h"
#include "ui_modern_theme.h"
#include <cstdio>

// Enhanced Options Page Objects
lv_obj_t *ui_OptionsPage_Modern = nullptr;
lv_obj_t *ui_OptionsPage_NavBar = nullptr;
lv_obj_t *ui_OptionsPage_Title = nullptr;
lv_obj_t *ui_OptionsPage_Subtitle = nullptr;
lv_obj_t *ui_OptionsPage_GridContainer = nullptr;
lv_obj_t *ui_OptionsPage_StatusBar = nullptr;
lv_obj_t *ui_OptionsPage_StatusTime = nullptr;
lv_obj_t *ui_OptionsPage_StatusBattery = nullptr;

// Grid Button Objects
lv_obj_t *ui_OptionsPage_BubbleCard = nullptr;
lv_obj_t *ui_OptionsPage_BubbleIcon = nullptr;
lv_obj_t *ui_OptionsPage_BubbleLabel = nullptr;
lv_obj_t *ui_OptionsPage_BubbleDesc = nullptr;

lv_obj_t *ui_OptionsPage_HorizonCard = nullptr;
lv_obj_t *ui_OptionsPage_HorizonIcon = nullptr;
lv_obj_t *ui_OptionsPage_HorizonLabel = nullptr;
lv_obj_t *ui_OptionsPage_HorizonDesc = nullptr;

lv_obj_t *ui_OptionsPage_ShotCard = nullptr;
lv_obj_t *ui_OptionsPage_ShotIcon = nullptr;
lv_obj_t *ui_OptionsPage_ShotLabel = nullptr;
lv_obj_t *ui_OptionsPage_ShotDesc = nullptr;

lv_obj_t *ui_OptionsPage_TimerCard = nullptr;
lv_obj_t *ui_OptionsPage_TimerIcon = nullptr;
lv_obj_t *ui_OptionsPage_TimerLabel = nullptr;
lv_obj_t *ui_OptionsPage_TimerDesc = nullptr;

lv_obj_t *ui_OptionsPage_CompCard = nullptr;
lv_obj_t *ui_OptionsPage_CompIcon = nullptr;
lv_obj_t *ui_OptionsPage_CompLabel = nullptr;
lv_obj_t *ui_OptionsPage_CompDesc = nullptr;

lv_obj_t *ui_OptionsPage_SettingsCard = nullptr;
lv_obj_t *ui_OptionsPage_SettingsIcon = nullptr;
lv_obj_t *ui_OptionsPage_SettingsLabel = nullptr;
lv_obj_t *ui_OptionsPage_SettingsDesc = nullptr;

// Enhanced event handlers
typedef void (*event_handler_t)(lv_event_t *e);
void ui_modern_event_bubble_level(lv_event_t *e);
void ui_modern_event_horizon(lv_event_t *e);
void ui_modern_event_shot_counter(lv_event_t *e);
void ui_modern_event_timer(lv_event_t *e);
void ui_modern_event_competition(lv_event_t *e);
void ui_modern_event_settings(lv_event_t *e);

// Helper functions
static void create_feature_card(lv_obj_t *parent, lv_obj_t **card, lv_obj_t **icon,
                                lv_obj_t **label, lv_obj_t **desc,
                                const char *symbol, const char *title, const char *description,
                                event_handler_t handler);
// ...existing code for the rest of the file...
