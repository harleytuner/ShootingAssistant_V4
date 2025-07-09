#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ui_Settings_Page.h"
// Settings Page for ShootingAssistant_V2
// Allows adjustment of key parameters for testing and customization

#ifndef UI_SETTINGS_PAGE_H
#define UI_SETTINGS_PAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

    // SCREEN: ui_Settings_Page
    extern void ui_Settings_Page_screen_init(void);
    extern void ui_Settings_Page_screen_destroy(void);
    extern lv_obj_t *ui_Settings_Page;

    // Navigation buttons
    extern void ui_event_SettingsHomeBTN(lv_event_t *e);
    extern lv_obj_t *ui_SettingsHomeBTN;
    extern lv_obj_t *ui_SettingsHomeBTN1;

    // Settings structure to hold all adjustable parameters
    typedef struct
    {
        // Calibration Settings
        float roll_calibration_offset;
        float pitch_calibration_offset;

        // Recoil Detection Settings
        float recoil_z_threshold_negative;
        uint32_t recoil_cooldown_ms;

        // Bubble Level Settings
        float bubble_level_green_threshold;
        float bubble_level_yellow_threshold;
        float max_roll_angle;

        // Timer Settings
        uint32_t default_stage_time_seconds;
        uint32_t time_adjust_increment_seconds;
        uint32_t time_warning_threshold_seconds;

        // Shot Counter Settings
        int default_shot_count;

        // Timer Update Rates (milliseconds)
        uint32_t bubble_level_update_rate;
        uint32_t competition_page_update_rate;
        uint32_t stage_timer_update_rate;
    } ui_settings_t;

    // Global settings instance
    extern ui_settings_t ui_settings;

    // Settings management functions
    void ui_settings_load_defaults(void);
    void ui_settings_save_to_storage(void);
    void ui_settings_load_from_storage(void);

    // Getter functions for other modules to access settings
    float ui_settings_get_roll_calibration_offset(void);
    float ui_settings_get_pitch_calibration_offset(void);
    float ui_settings_get_recoil_z_threshold_negative(void);
    uint32_t ui_settings_get_recoil_cooldown_ms(void);
    float ui_settings_get_bubble_green_threshold(void);
    float ui_settings_get_bubble_yellow_threshold(void);
    float ui_settings_get_max_roll_angle(void);
    uint32_t ui_settings_get_default_stage_time(void);
    uint32_t ui_settings_get_time_adjust_increment(void);
    uint32_t ui_settings_get_time_warning_threshold(void);
    int ui_settings_get_default_shot_count(void);
    uint32_t ui_settings_get_bubble_level_update_rate(void);
    uint32_t ui_settings_get_competition_page_update_rate(void);
    uint32_t ui_settings_get_stage_timer_update_rate(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_SETTINGS_PAGE_H*/
