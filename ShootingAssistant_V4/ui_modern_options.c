// Enhanced Options Page with Modern UI Design
// Creates a premium, consumer-grade main menu

#include "ui.h"
#include "ui_modern_theme.h"
#include <stdio.h>

// Enhanced Options Page Objects
lv_obj_t *ui_OptionsPage_Modern;
lv_obj_t *ui_OptionsPage_NavBar;
lv_obj_t *ui_OptionsPage_Title;
lv_obj_t *ui_OptionsPage_Subtitle;
lv_obj_t *ui_OptionsPage_GridContainer;
lv_obj_t *ui_OptionsPage_StatusBar;
lv_obj_t *ui_OptionsPage_StatusTime;
lv_obj_t *ui_OptionsPage_StatusBattery;

// Grid Button Objects
lv_obj_t *ui_OptionsPage_BubbleCard;
lv_obj_t *ui_OptionsPage_BubbleIcon;
lv_obj_t *ui_OptionsPage_BubbleLabel;
lv_obj_t *ui_OptionsPage_BubbleDesc;

lv_obj_t *ui_OptionsPage_HorizonCard;
lv_obj_t *ui_OptionsPage_HorizonIcon;
lv_obj_t *ui_OptionsPage_HorizonLabel;
lv_obj_t *ui_OptionsPage_HorizonDesc;

lv_obj_t *ui_OptionsPage_ShotCard;
lv_obj_t *ui_OptionsPage_ShotIcon;
lv_obj_t *ui_OptionsPage_ShotLabel;
lv_obj_t *ui_OptionsPage_ShotDesc;

lv_obj_t *ui_OptionsPage_TimerCard;
lv_obj_t *ui_OptionsPage_TimerIcon;
lv_obj_t *ui_OptionsPage_TimerLabel;
lv_obj_t *ui_OptionsPage_TimerDesc;

lv_obj_t *ui_OptionsPage_CompCard;
lv_obj_t *ui_OptionsPage_CompIcon;
lv_obj_t *ui_OptionsPage_CompLabel;
lv_obj_t *ui_OptionsPage_CompDesc;

lv_obj_t *ui_OptionsPage_SettingsCard;
lv_obj_t *ui_OptionsPage_SettingsIcon;
lv_obj_t *ui_OptionsPage_SettingsLabel;
lv_obj_t *ui_OptionsPage_SettingsDesc;

// Enhanced event handlers
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
                                lv_color_t accent_color, lv_event_cb_t event_cb);
static void update_status_bar(void);

// Modern Options Page Implementation
void ui_modern_options_page_init(void)
{
    // Create main page
    ui_OptionsPage_Modern = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_OptionsPage_Modern, LV_OBJ_FLAG_SCROLLABLE);
    ui_modern_style_page(ui_OptionsPage_Modern);

    // Create status bar at top
    ui_OptionsPage_StatusBar = lv_obj_create(ui_OptionsPage_Modern);
    lv_obj_set_size(ui_OptionsPage_StatusBar, LV_PCT(100), 30);
    lv_obj_set_pos(ui_OptionsPage_StatusBar, 0, 0);
    lv_obj_set_style_bg_color(ui_OptionsPage_StatusBar, ui_modern_colors.primary_dark, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_OptionsPage_StatusBar, LV_OPA_80, LV_PART_MAIN);
    lv_obj_set_style_border_width(ui_OptionsPage_StatusBar, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(ui_OptionsPage_StatusBar, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(ui_OptionsPage_StatusBar, 8, LV_PART_MAIN);

    // Status time
    ui_OptionsPage_StatusTime = lv_label_create(ui_OptionsPage_StatusBar);
    lv_label_set_text(ui_OptionsPage_StatusTime, "12:34");
    lv_obj_set_pos(ui_OptionsPage_StatusTime, 10, 0);
    ui_modern_style_label_caption(ui_OptionsPage_StatusTime);

    // Status battery
    ui_OptionsPage_StatusBattery = lv_label_create(ui_OptionsPage_StatusBar);
    lv_label_set_text(ui_OptionsPage_StatusBattery, "100%");
    lv_obj_set_pos(ui_OptionsPage_StatusBattery, -10, 0);
    lv_obj_set_style_text_align(ui_OptionsPage_StatusBattery, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN);
    ui_modern_style_label_caption(ui_OptionsPage_StatusBattery);

    // Create title section
    ui_OptionsPage_Title = lv_label_create(ui_OptionsPage_Modern);
    lv_label_set_text(ui_OptionsPage_Title, "SHOOTING ASSISTANT");
    lv_obj_set_pos(ui_OptionsPage_Title, 0, 50);
    lv_obj_set_style_text_align(ui_OptionsPage_Title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_width(ui_OptionsPage_Title, LV_PCT(100));
    ui_modern_style_label_title(ui_OptionsPage_Title);

    // Create subtitle
    ui_OptionsPage_Subtitle = lv_label_create(ui_OptionsPage_Modern);
    lv_label_set_text(ui_OptionsPage_Subtitle, "Professional Precision Tools");
    lv_obj_set_pos(ui_OptionsPage_Subtitle, 0, 85);
    lv_obj_set_style_text_align(ui_OptionsPage_Subtitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_width(ui_OptionsPage_Subtitle, LV_PCT(100));
    ui_modern_style_label_body(ui_OptionsPage_Subtitle);
    lv_obj_set_style_text_color(ui_OptionsPage_Subtitle, ui_modern_colors.accent_orange, LV_PART_MAIN);

    // Create grid container
    ui_OptionsPage_GridContainer = lv_obj_create(ui_OptionsPage_Modern);
    lv_obj_set_size(ui_OptionsPage_GridContainer, LV_PCT(95), LV_PCT(70));
    lv_obj_set_pos(ui_OptionsPage_GridContainer, 0, 120);
    lv_obj_set_style_bg_opa(ui_OptionsPage_GridContainer, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_border_width(ui_OptionsPage_GridContainer, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(ui_OptionsPage_GridContainer, 10, LV_PART_MAIN);
    lv_obj_set_style_pad_gap(ui_OptionsPage_GridContainer, 15, LV_PART_MAIN);
    lv_obj_set_layout(ui_OptionsPage_GridContainer, LV_LAYOUT_GRID);

    // Configure grid: 2 columns, 3 rows
    static int32_t col_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t row_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(ui_OptionsPage_GridContainer, col_dsc, row_dsc);

    // Create feature cards
    create_feature_card(ui_OptionsPage_GridContainer, &ui_OptionsPage_BubbleCard, &ui_OptionsPage_BubbleIcon,
                        &ui_OptionsPage_BubbleLabel, &ui_OptionsPage_BubbleDesc,
                        UI_MODERN_SYMBOL_BUBBLE, \"Bubble Level\", \"Precision leveling tool\",
                                                 ui_modern_colors.accent_green,
                        ui_modern_event_bubble_level);
    lv_obj_set_grid_cell(ui_OptionsPage_BubbleCard, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    create_feature_card(ui_OptionsPage_GridContainer, &ui_OptionsPage_HorizonCard, &ui_OptionsPage_HorizonIcon,
                        &ui_OptionsPage_HorizonLabel, &ui_OptionsPage_HorizonDesc,
                        UI_MODERN_SYMBOL_HORIZON, \"Horizon\", \"Artificial horizon display\",
                                                  ui_modern_colors.accent_blue,
                        ui_modern_event_horizon);
    lv_obj_set_grid_cell(ui_OptionsPage_HorizonCard, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    create_feature_card(ui_OptionsPage_GridContainer, &ui_OptionsPage_ShotCard, &ui_OptionsPage_ShotIcon,
                        &ui_OptionsPage_ShotLabel, &ui_OptionsPage_ShotDesc,
                        UI_MODERN_SYMBOL_COUNTER, \"Shot Counter\", \"Track your shots\",
                                                  ui_modern_colors.accent_orange,
                        ui_modern_event_shot_counter);
    lv_obj_set_grid_cell(ui_OptionsPage_ShotCard, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    create_feature_card(ui_OptionsPage_GridContainer, &ui_OptionsPage_TimerCard, &ui_OptionsPage_TimerIcon,
                        &ui_OptionsPage_TimerLabel, &ui_OptionsPage_TimerDesc,
                        UI_MODERN_SYMBOL_TIMER, \"Stage Timer\", \"Competition timing\",
                                                ui_modern_colors.accent_purple,
                        ui_modern_event_timer);
    lv_obj_set_grid_cell(ui_OptionsPage_TimerCard, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    create_feature_card(ui_OptionsPage_GridContainer, &ui_OptionsPage_CompCard, &ui_OptionsPage_CompIcon,
                        &ui_OptionsPage_CompLabel, &ui_OptionsPage_CompDesc,
                        UI_MODERN_SYMBOL_COMPETITION, \"Competition\", \"Full competition mode\",
                                                      ui_modern_colors.accent_red,
                        ui_modern_event_competition);
    lv_obj_set_grid_cell(ui_OptionsPage_CompCard, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    create_feature_card(ui_OptionsPage_GridContainer, &ui_OptionsPage_SettingsCard, &ui_OptionsPage_SettingsIcon,
                        &ui_OptionsPage_SettingsLabel, &ui_OptionsPage_SettingsDesc,
                        UI_MODERN_SYMBOL_SETTINGS, \"Settings\", \"Configure system\",
                                                   ui_modern_colors.text_muted,
                        ui_modern_event_settings);
    lv_obj_set_grid_cell(ui_OptionsPage_SettingsCard, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    // Add entrance animations
    ui_modern_fade_in(ui_OptionsPage_Title, 300);
    ui_modern_fade_in(ui_OptionsPage_Subtitle, 400);
    ui_modern_fade_in(ui_OptionsPage_GridContainer, 500);

    // Update status bar
    update_status_bar();
}

// Helper function to create feature cards
static void create_feature_card(lv_obj_t *parent, lv_obj_t **card, lv_obj_t **icon,
                                lv_obj_t **label, lv_obj_t **desc,
                                const char *symbol, const char *title, const char *description,
                                lv_color_t accent_color, lv_event_cb_t event_cb)
{

    // Create card
    *card = lv_obj_create(parent);
    lv_obj_clear_flag(*card, LV_OBJ_FLAG_SCROLLABLE);
    ui_modern_style_card(*card);
    lv_obj_add_event_cb(*card, event_cb, LV_EVENT_PRESSED, NULL);

    // Add hover effect
    lv_obj_set_style_transform_width(*card, 4, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(*card, 4, LV_PART_MAIN | LV_STATE_PRESSED);

    // Create icon
    *icon = lv_label_create(*card);
    lv_label_set_text(*icon, symbol);
    lv_obj_set_pos(*icon, 0, 10);
    lv_obj_set_style_text_align(*icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_width(*icon, LV_PCT(100));
    lv_obj_set_style_text_color(*icon, accent_color, LV_PART_MAIN);
    lv_obj_set_style_text_font(*icon, &lv_font_montserrat_24, LV_PART_MAIN);

    // Create title label
    *label = lv_label_create(*card);
    lv_label_set_text(*label, title);
    lv_obj_set_pos(*label, 0, 45);
    lv_obj_set_style_text_align(*label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_width(*label, LV_PCT(100));
    ui_modern_style_label_heading(*label);

    // Create description
    *desc = lv_label_create(*card);
    lv_label_set_text(*desc, description);
    lv_obj_set_pos(*desc, 0, 75);
    lv_obj_set_style_text_align(*desc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_set_width(*desc, LV_PCT(100));
    ui_modern_style_label_caption(*desc);
}

// Update status bar information
static void update_status_bar(void)
{
    // Update time (placeholder - integrate with RTC)
    lv_label_set_text(ui_OptionsPage_StatusTime, "12:34");

    // Update battery (placeholder - integrate with battery monitoring)
    lv_label_set_text(ui_OptionsPage_StatusBattery, "95%");
}

// Timer callbacks for delayed navigation
static void bubble_level_nav_timer_cb(lv_timer_t *timer)
{
    _ui_screen_change(&ui_Bubble_Level_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_Bubble_Level_Page_screen_init);
    lv_timer_del(timer);
}

static void horizon_nav_timer_cb(lv_timer_t *timer)
{
    _ui_screen_change(&ui_Artificial_Horizon_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_Artificial_Horizon_Page_screen_init);
    lv_timer_del(timer);
}

static void shot_counter_nav_timer_cb(lv_timer_t *timer)
{
    _ui_screen_change(&ui_Shot_Counter_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_Shot_Counter_Page_screen_init);
    lv_timer_del(timer);
}

static void timer_nav_timer_cb(lv_timer_t *timer)
{
    _ui_screen_change(&ui_Stage_Timer_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_Stage_Timer_Page_screen_init);
    lv_timer_del(timer);
}

static void competition_nav_timer_cb(lv_timer_t *timer)
{
    _ui_screen_change(&ui_Competition_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_Competition_Page_screen_init);
    lv_timer_del(timer);
}

static void settings_nav_timer_cb(lv_timer_t *timer)
{
    _ui_screen_change(&ui_Settings_Page, LV_SCR_LOAD_ANIM_MOVE_LEFT, 300, 0, &ui_Settings_Page_screen_init);
    lv_timer_del(timer);
}

// Enhanced event handlers with animations
void ui_modern_event_bubble_level(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_modern_scale_bounce(ui_OptionsPage_BubbleCard);
        lv_timer_create(bubble_level_nav_timer_cb, 200, NULL);
    }
}

void ui_modern_event_horizon(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_modern_scale_bounce(ui_OptionsPage_HorizonCard);
        lv_timer_create(horizon_nav_timer_cb, 200, NULL);
    }
}

void ui_modern_event_shot_counter(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_modern_scale_bounce(ui_OptionsPage_ShotCard);
        lv_timer_create(shot_counter_nav_timer_cb, 200, NULL);
    }
}

void ui_modern_event_timer(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_modern_scale_bounce(ui_OptionsPage_TimerCard);
        lv_timer_create(timer_nav_timer_cb, 200, NULL);
    }
}

void ui_modern_event_competition(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_modern_scale_bounce(ui_OptionsPage_CompCard);
        lv_timer_create(competition_nav_timer_cb, 200, NULL);
    }
}

void ui_modern_event_settings(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_modern_scale_bounce(ui_OptionsPage_SettingsCard);
        lv_timer_create(settings_nav_timer_cb, 200, NULL);
    }
}

void ui_modern_options_page_destroy(void)
{
    lv_obj_del(ui_OptionsPage_Modern);
}
