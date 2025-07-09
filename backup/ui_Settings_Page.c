// Settings Page Implementation for ShootingAssistant_V2
// Allows adjustment of key parameters for testing and customization

#include "ui.h"
#include "ui_Settings_Page.h"
#include "ui_modern_theme.h"
#include <stdio.h>
#include <string.h>

// Global settings instance
ui_settings_t ui_settings;

// UI Objects for Settings Page
lv_obj_t *ui_Settings_Page;
lv_obj_t *ui_SettingsPageLabel;
lv_obj_t *ui_SettingsHomeBTN;
lv_obj_t *ui_SettingsHomeBTN1;

// Settings UI Objects
lv_obj_t *ui_SettingsScrollContainer;

// Calibration Settings
lv_obj_t *ui_CalibrationLabel;
lv_obj_t *ui_RollCalibrationLabel;
lv_obj_t *ui_RollCalibrationSlider;
lv_obj_t *ui_RollCalibrationValue;
lv_obj_t *ui_PitchCalibrationLabel;
lv_obj_t *ui_PitchCalibrationSlider;
lv_obj_t *ui_PitchCalibrationValue;

// Recoil Detection Settings
lv_obj_t *ui_RecoilLabel;
lv_obj_t *ui_RecoilThresholdLabel;
lv_obj_t *ui_RecoilThresholdSlider;
lv_obj_t *ui_RecoilThresholdValue;
lv_obj_t *ui_RecoilCooldownLabel;
lv_obj_t *ui_RecoilCooldownSlider;
lv_obj_t *ui_RecoilCooldownValue;

// Bubble Level Settings
lv_obj_t *ui_BubbleLevelLabel;
lv_obj_t *ui_GreenThresholdLabel;
lv_obj_t *ui_GreenThresholdSlider;
lv_obj_t *ui_GreenThresholdValue;
lv_obj_t *ui_YellowThresholdLabel;
lv_obj_t *ui_YellowThresholdSlider;
lv_obj_t *ui_YellowThresholdValue;
lv_obj_t *ui_MaxRollAngleLabel;
lv_obj_t *ui_MaxRollAngleSlider;
lv_obj_t *ui_MaxRollAngleValue;

// Timer Settings
lv_obj_t *ui_TimerLabel;
lv_obj_t *ui_DefaultStageTimeLabel;
lv_obj_t *ui_DefaultStageTimeSlider;
lv_obj_t *ui_DefaultStageTimeValue;
lv_obj_t *ui_TimeIncrementLabel;
lv_obj_t *ui_TimeIncrementSlider;
lv_obj_t *ui_TimeIncrementValue;
lv_obj_t *ui_TimeWarningLabel;
lv_obj_t *ui_TimeWarningSlider;
lv_obj_t *ui_TimeWarningValue;

// Shot Counter Settings
lv_obj_t *ui_ShotCounterLabel;
lv_obj_t *ui_DefaultShotCountLabel;
lv_obj_t *ui_DefaultShotCountSlider;
lv_obj_t *ui_DefaultShotCountValue;

// Action Buttons
lv_obj_t *ui_ResetDefaultsBtn;
lv_obj_t *ui_ResetDefaultsLabel;
lv_obj_t *ui_SaveSettingsBtn;
lv_obj_t *ui_SaveSettingsLabel;

// Helper functions
static void update_setting_value_label(lv_obj_t *label, float value, const char *unit);
static void update_setting_value_label_int(lv_obj_t *label, int value, const char *unit);

// Settings management functions
void ui_settings_load_defaults(void)
{
    // Calibration Settings
    ui_settings.roll_calibration_offset = -5.0f;
    ui_settings.pitch_calibration_offset = 3.0f;

    // Recoil Detection Settings
    ui_settings.recoil_z_threshold_negative = -1.0f;
    ui_settings.recoil_cooldown_ms = 1500;

    // Bubble Level Settings
    ui_settings.bubble_level_green_threshold = 3.0f;
    ui_settings.bubble_level_yellow_threshold = 8.0f;
    ui_settings.max_roll_angle = 30.0f;

    // Timer Settings
    ui_settings.default_stage_time_seconds = 5 * 60; // 5 minutes
    ui_settings.time_adjust_increment_seconds = 60;  // 1 minute
    ui_settings.time_warning_threshold_seconds = 30; // 30 seconds

    // Shot Counter Settings
    ui_settings.default_shot_count = 5;

    // Timer Update Rates (milliseconds)
    ui_settings.bubble_level_update_rate = 250;
    ui_settings.competition_page_update_rate = 330;
    ui_settings.stage_timer_update_rate = 1000;
}

void ui_settings_save_to_storage(void)
{
    // TODO: Implement storage to SD card or EEPROM
    // For now, just keep in memory
}

void ui_settings_load_from_storage(void)
{
    // TODO: Implement loading from SD card or EEPROM
    // For now, just use defaults
    ui_settings_load_defaults();
}

// Getter functions
float ui_settings_get_roll_calibration_offset(void) { return ui_settings.roll_calibration_offset; }
float ui_settings_get_pitch_calibration_offset(void) { return ui_settings.pitch_calibration_offset; }
float ui_settings_get_recoil_z_threshold_negative(void) { return ui_settings.recoil_z_threshold_negative; }
uint32_t ui_settings_get_recoil_cooldown_ms(void) { return ui_settings.recoil_cooldown_ms; }
float ui_settings_get_bubble_green_threshold(void) { return ui_settings.bubble_level_green_threshold; }
float ui_settings_get_bubble_yellow_threshold(void) { return ui_settings.bubble_level_yellow_threshold; }
float ui_settings_get_max_roll_angle(void) { return ui_settings.max_roll_angle; }
uint32_t ui_settings_get_default_stage_time(void) { return ui_settings.default_stage_time_seconds; }
uint32_t ui_settings_get_time_adjust_increment(void) { return ui_settings.time_adjust_increment_seconds; }
uint32_t ui_settings_get_time_warning_threshold(void) { return ui_settings.time_warning_threshold_seconds; }
int ui_settings_get_default_shot_count(void) { return ui_settings.default_shot_count; }
uint32_t ui_settings_get_bubble_level_update_rate(void) { return ui_settings.bubble_level_update_rate; }
uint32_t ui_settings_get_competition_page_update_rate(void) { return ui_settings.competition_page_update_rate; }
uint32_t ui_settings_get_stage_timer_update_rate(void) { return ui_settings.stage_timer_update_rate; }

// Event handlers for sliders
void ui_event_GreenThresholdSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_GreenThresholdSlider);
        ui_settings.bubble_level_green_threshold = (float)value / 10.0f; // 0.1 degree precision
        update_setting_value_label(ui_GreenThresholdValue, ui_settings.bubble_level_green_threshold, "°");
    }
}

void ui_event_YellowThresholdSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_YellowThresholdSlider);
        ui_settings.bubble_level_yellow_threshold = (float)value / 10.0f; // 0.1 degree precision
        update_setting_value_label(ui_YellowThresholdValue, ui_settings.bubble_level_yellow_threshold, "°");
    }
}

void ui_event_MaxRollAngleSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_MaxRollAngleSlider);
        ui_settings.max_roll_angle = (float)value;
        update_setting_value_label(ui_MaxRollAngleValue, ui_settings.max_roll_angle, "°");
    }
}

void ui_event_DefaultStageTimeSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_DefaultStageTimeSlider);
        ui_settings.default_stage_time_seconds = (uint32_t)value * 60; // Convert minutes to seconds
        update_setting_value_label_int(ui_DefaultStageTimeValue, value, "min");
    }
}

void ui_event_TimeIncrementSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_TimeIncrementSlider);
        ui_settings.time_adjust_increment_seconds = (uint32_t)value;
        update_setting_value_label_int(ui_TimeIncrementValue, value, "sec");
    }
}

void ui_event_TimeWarningSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_TimeWarningSlider);
        ui_settings.time_warning_threshold_seconds = (uint32_t)value;
        update_setting_value_label_int(ui_TimeWarningValue, value, "sec");
    }
}

void ui_event_DefaultShotCountSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_DefaultShotCountSlider);
        ui_settings.default_shot_count = (int)value;
        update_setting_value_label_int(ui_DefaultShotCountValue, value, "shots");
    }
}

void ui_event_ResetDefaultsBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_settings_load_defaults();
        // Update all sliders and labels
        lv_slider_set_value(ui_RollCalibrationSlider, (int32_t)(ui_settings.roll_calibration_offset * 10), LV_ANIM_ON);
        lv_slider_set_value(ui_PitchCalibrationSlider, (int32_t)(ui_settings.pitch_calibration_offset * 10), LV_ANIM_ON);
        lv_slider_set_value(ui_RecoilThresholdSlider, (int32_t)(ui_settings.recoil_z_threshold_negative * 10), LV_ANIM_ON);
        lv_slider_set_value(ui_RecoilCooldownSlider, ui_settings.recoil_cooldown_ms / 100, LV_ANIM_ON);
        lv_slider_set_value(ui_GreenThresholdSlider, (int32_t)(ui_settings.bubble_level_green_threshold * 10), LV_ANIM_ON);
        lv_slider_set_value(ui_YellowThresholdSlider, (int32_t)(ui_settings.bubble_level_yellow_threshold * 10), LV_ANIM_ON);
        lv_slider_set_value(ui_MaxRollAngleSlider, (int32_t)ui_settings.max_roll_angle, LV_ANIM_ON);
        lv_slider_set_value(ui_DefaultStageTimeSlider, ui_settings.default_stage_time_seconds / 60, LV_ANIM_ON);
        lv_slider_set_value(ui_TimeIncrementSlider, ui_settings.time_adjust_increment_seconds, LV_ANIM_ON);
        lv_slider_set_value(ui_TimeWarningSlider, ui_settings.time_warning_threshold_seconds, LV_ANIM_ON);
        lv_slider_set_value(ui_DefaultShotCountSlider, ui_settings.default_shot_count, LV_ANIM_ON);

        // Update all value labels
        update_setting_value_label(ui_RollCalibrationValue, ui_settings.roll_calibration_offset, "°");
        update_setting_value_label(ui_PitchCalibrationValue, ui_settings.pitch_calibration_offset, "°");
        update_setting_value_label(ui_RecoilThresholdValue, ui_settings.recoil_z_threshold_negative, "G");
        update_setting_value_label_int(ui_RecoilCooldownValue, ui_settings.recoil_cooldown_ms / 1000, "sec");
        update_setting_value_label(ui_GreenThresholdValue, ui_settings.bubble_level_green_threshold, "°");
        update_setting_value_label(ui_YellowThresholdValue, ui_settings.bubble_level_yellow_threshold, "°");
        update_setting_value_label(ui_MaxRollAngleValue, ui_settings.max_roll_angle, "°");
        update_setting_value_label_int(ui_DefaultStageTimeValue, ui_settings.default_stage_time_seconds / 60, "min");
        update_setting_value_label_int(ui_TimeIncrementValue, ui_settings.time_adjust_increment_seconds, "sec");
        update_setting_value_label_int(ui_TimeWarningValue, ui_settings.time_warning_threshold_seconds, "sec");
        update_setting_value_label_int(ui_DefaultShotCountValue, ui_settings.default_shot_count, "shots");
    }
}

void ui_event_SaveSettingsBtn(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        ui_settings_save_to_storage();
        // Visual feedback - briefly change button color
        lv_obj_set_style_bg_color(ui_SaveSettingsBtn, lv_color_hex(0x4CAF50), LV_PART_MAIN | LV_STATE_DEFAULT);
        // TODO: Add timer to reset color after 500ms
    }
}

void ui_event_SettingsHomeBTN(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_PRESSED)
    {
        _ui_screen_change(&ui_Options_Page, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_Options_Page_screen_init);
    }
}

// Event handlers for calibration sliders
void ui_event_RollCalibrationSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_RollCalibrationSlider);
        ui_settings.roll_calibration_offset = (float)value / 10.0f; // 0.1 degree precision
        update_setting_value_label(ui_RollCalibrationValue, ui_settings.roll_calibration_offset, "°");
    }
}

void ui_event_PitchCalibrationSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_PitchCalibrationSlider);
        ui_settings.pitch_calibration_offset = (float)value / 10.0f; // 0.1 degree precision
        update_setting_value_label(ui_PitchCalibrationValue, ui_settings.pitch_calibration_offset, "°");
    }
}

void ui_event_RecoilThresholdSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_RecoilThresholdSlider);
        ui_settings.recoil_z_threshold_negative = (float)value / 10.0f; // 0.1 G precision
        update_setting_value_label(ui_RecoilThresholdValue, ui_settings.recoil_z_threshold_negative, "G");
    }
}

void ui_event_RecoilCooldownSlider(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if (event_code == LV_EVENT_VALUE_CHANGED)
    {
        int32_t value = lv_slider_get_value(ui_RecoilCooldownSlider);
        ui_settings.recoil_cooldown_ms = (uint32_t)value * 100; // 100ms increments
        update_setting_value_label_int(ui_RecoilCooldownValue, value / 10, "sec");
    }
}

// Helper functions
static void update_setting_value_label(lv_obj_t *label, float value, const char *unit)
{
    if (label)
    {
        char buf[16];
        int result = lv_snprintf(buf, sizeof(buf), "%.1f%s", value, unit);
        if (result >= 0 && result < sizeof(buf))
        {
            lv_label_set_text(label, buf);
        }
    }
}

static void update_setting_value_label_int(lv_obj_t *label, int value, const char *unit)
{
    if (label)
    {
        char buf[16];
        int result = lv_snprintf(buf, sizeof(buf), "%d%s", value, unit);
        if (result >= 0 && result < sizeof(buf))
        {
            lv_label_set_text(label, buf);
        }
    }
}

// Screen initialization
void ui_Settings_Page_screen_init(void)
{
    ui_Settings_Page = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Settings_Page, LV_OBJ_FLAG_SCROLLABLE);

    // Apply modern page styling
    ui_modern_style_page(ui_Settings_Page);

    // Title with modern styling
    ui_SettingsPageLabel = lv_label_create(ui_Settings_Page);
    lv_obj_set_width(ui_SettingsPageLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SettingsPageLabel, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_SettingsPageLabel, 0);
    lv_obj_set_y(ui_SettingsPageLabel, -125);
    lv_obj_set_align(ui_SettingsPageLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsPageLabel, "⚙ SETTINGS");
    ui_modern_style_label_title(ui_SettingsPageLabel);

    // Create modern scrollable container for settings
    ui_SettingsScrollContainer = lv_obj_create(ui_Settings_Page);
    lv_obj_set_width(ui_SettingsScrollContainer, 320);
    lv_obj_set_height(ui_SettingsScrollContainer, 200);
    lv_obj_set_x(ui_SettingsScrollContainer, 0);
    lv_obj_set_y(ui_SettingsScrollContainer, -20);
    lv_obj_set_align(ui_SettingsScrollContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SettingsScrollContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_SettingsScrollContainer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    ui_modern_style_container_glass(ui_SettingsScrollContainer);

    // Calibration Settings Section
    ui_CalibrationLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_CalibrationLabel, "🎯 CALIBRATION SETTINGS");
    ui_modern_style_label_heading(ui_CalibrationLabel);
    lv_obj_set_style_text_color(ui_CalibrationLabel, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Roll Calibration
    ui_RollCalibrationLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_RollCalibrationLabel, "Roll Calibration:");
    ui_modern_style_label_body(ui_RollCalibrationLabel);

    ui_RollCalibrationSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_RollCalibrationSlider, 240);
    lv_slider_set_range(ui_RollCalibrationSlider, -200, 200); // -20.0 to 20.0 degrees
    lv_slider_set_value(ui_RollCalibrationSlider, (int32_t)(ui_settings.roll_calibration_offset * 10), LV_ANIM_OFF);
    ui_modern_style_slider(ui_RollCalibrationSlider);

    ui_RollCalibrationValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label(ui_RollCalibrationValue, ui_settings.roll_calibration_offset, "°");
    ui_modern_style_label_caption(ui_RollCalibrationValue);

    // Pitch Calibration
    ui_PitchCalibrationLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_PitchCalibrationLabel, "Pitch Calibration:");
    ui_modern_style_label_body(ui_PitchCalibrationLabel);

    ui_PitchCalibrationSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_PitchCalibrationSlider, 240);
    lv_slider_set_range(ui_PitchCalibrationSlider, -200, 200); // -20.0 to 20.0 degrees
    lv_slider_set_value(ui_PitchCalibrationSlider, (int32_t)(ui_settings.pitch_calibration_offset * 10), LV_ANIM_OFF);
    ui_modern_style_slider(ui_PitchCalibrationSlider);

    ui_PitchCalibrationValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label(ui_PitchCalibrationValue, ui_settings.pitch_calibration_offset, "°");
    ui_modern_style_label_caption(ui_PitchCalibrationValue);

    // Recoil Detection Settings Section
    ui_RecoilLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_RecoilLabel, "Recoil Detection Settings");
    lv_obj_set_style_text_font(ui_RecoilLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_RecoilLabel, lv_color_hex(0x9C27B0), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Recoil Threshold
    ui_RecoilThresholdLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_RecoilThresholdLabel, "Recoil Threshold:");

    ui_RecoilThresholdSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_RecoilThresholdSlider, 200);
    lv_slider_set_range(ui_RecoilThresholdSlider, -50, -5); // -5.0 to -0.5 G
    lv_slider_set_value(ui_RecoilThresholdSlider, (int32_t)(ui_settings.recoil_z_threshold_negative * 10), LV_ANIM_OFF);

    ui_RecoilThresholdValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label(ui_RecoilThresholdValue, ui_settings.recoil_z_threshold_negative, "G");

    // Recoil Cooldown
    ui_RecoilCooldownLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_RecoilCooldownLabel, "Recoil Cooldown:");

    ui_RecoilCooldownSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_RecoilCooldownSlider, 200);
    lv_slider_set_range(ui_RecoilCooldownSlider, 5, 50); // 0.5 to 5.0 seconds (in 100ms increments)
    lv_slider_set_value(ui_RecoilCooldownSlider, ui_settings.recoil_cooldown_ms / 100, LV_ANIM_OFF);

    ui_RecoilCooldownValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label_int(ui_RecoilCooldownValue, ui_settings.recoil_cooldown_ms / 1000, "sec");

    // Bubble Level Settings Section
    ui_BubbleLevelLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_BubbleLevelLabel, "Bubble Level Settings");
    lv_obj_set_style_text_font(ui_BubbleLevelLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_BubbleLevelLabel, lv_color_hex(0x4CAF50), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Green Threshold
    ui_GreenThresholdLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_GreenThresholdLabel, "Green Threshold:");

    ui_GreenThresholdSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_GreenThresholdSlider, 200);
    lv_slider_set_range(ui_GreenThresholdSlider, 5, 100); // 0.5 to 10.0 degrees
    lv_slider_set_value(ui_GreenThresholdSlider, (int32_t)(ui_settings.bubble_level_green_threshold * 10), LV_ANIM_OFF);

    ui_GreenThresholdValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label(ui_GreenThresholdValue, ui_settings.bubble_level_green_threshold, "°");

    // Yellow Threshold
    ui_YellowThresholdLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_YellowThresholdLabel, "Yellow Threshold:");

    ui_YellowThresholdSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_YellowThresholdSlider, 200);
    lv_slider_set_range(ui_YellowThresholdSlider, 10, 200); // 1.0 to 20.0 degrees
    lv_slider_set_value(ui_YellowThresholdSlider, (int32_t)(ui_settings.bubble_level_yellow_threshold * 10), LV_ANIM_OFF);

    ui_YellowThresholdValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label(ui_YellowThresholdValue, ui_settings.bubble_level_yellow_threshold, "°");

    // Max Roll Angle
    ui_MaxRollAngleLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_MaxRollAngleLabel, "Max Roll Angle:");

    ui_MaxRollAngleSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_MaxRollAngleSlider, 200);
    lv_slider_set_range(ui_MaxRollAngleSlider, 10, 90); // 10 to 90 degrees
    lv_slider_set_value(ui_MaxRollAngleSlider, (int32_t)ui_settings.max_roll_angle, LV_ANIM_OFF);

    ui_MaxRollAngleValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label(ui_MaxRollAngleValue, ui_settings.max_roll_angle, "°");

    // Timer Settings Section
    ui_TimerLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_TimerLabel, "Timer Settings");
    lv_obj_set_style_text_font(ui_TimerLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_TimerLabel, lv_color_hex(0x2196F3), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Default Stage Time
    ui_DefaultStageTimeLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_DefaultStageTimeLabel, "Default Stage Time:");

    ui_DefaultStageTimeSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_DefaultStageTimeSlider, 200);
    lv_slider_set_range(ui_DefaultStageTimeSlider, 1, 60); // 1 to 60 minutes
    lv_slider_set_value(ui_DefaultStageTimeSlider, ui_settings.default_stage_time_seconds / 60, LV_ANIM_OFF);

    ui_DefaultStageTimeValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label_int(ui_DefaultStageTimeValue, ui_settings.default_stage_time_seconds / 60, "min");

    // Time Increment
    ui_TimeIncrementLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_TimeIncrementLabel, "Time Increment:");

    ui_TimeIncrementSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_TimeIncrementSlider, 200);
    lv_slider_set_range(ui_TimeIncrementSlider, 5, 300); // 5 to 300 seconds
    lv_slider_set_value(ui_TimeIncrementSlider, ui_settings.time_adjust_increment_seconds, LV_ANIM_OFF);

    ui_TimeIncrementValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label_int(ui_TimeIncrementValue, ui_settings.time_adjust_increment_seconds, "sec");

    // Time Warning Threshold
    ui_TimeWarningLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_TimeWarningLabel, "Time Warning:");

    ui_TimeWarningSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_TimeWarningSlider, 200);
    lv_slider_set_range(ui_TimeWarningSlider, 10, 120); // 10 to 120 seconds
    lv_slider_set_value(ui_TimeWarningSlider, ui_settings.time_warning_threshold_seconds, LV_ANIM_OFF);

    ui_TimeWarningValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label_int(ui_TimeWarningValue, ui_settings.time_warning_threshold_seconds, "sec");

    // Shot Counter Settings Section
    ui_ShotCounterLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_ShotCounterLabel, "Shot Counter Settings");
    lv_obj_set_style_text_font(ui_ShotCounterLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ShotCounterLabel, lv_color_hex(0xFF9800), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Default Shot Count
    ui_DefaultShotCountLabel = lv_label_create(ui_SettingsScrollContainer);
    lv_label_set_text(ui_DefaultShotCountLabel, "Default Shot Count:");

    ui_DefaultShotCountSlider = lv_slider_create(ui_SettingsScrollContainer);
    lv_obj_set_width(ui_DefaultShotCountSlider, 200);
    lv_slider_set_range(ui_DefaultShotCountSlider, 1, 50); // 1 to 50 shots
    lv_slider_set_value(ui_DefaultShotCountSlider, ui_settings.default_shot_count, LV_ANIM_OFF);

    ui_DefaultShotCountValue = lv_label_create(ui_SettingsScrollContainer);
    update_setting_value_label_int(ui_DefaultShotCountValue, ui_settings.default_shot_count, "shots");

    // Modern Action Buttons
    ui_ResetDefaultsBtn = lv_btn_create(ui_Settings_Page);
    lv_obj_set_width(ui_ResetDefaultsBtn, 100);
    lv_obj_set_height(ui_ResetDefaultsBtn, 35);
    lv_obj_set_x(ui_ResetDefaultsBtn, -60);
    lv_obj_set_y(ui_ResetDefaultsBtn, 100);
    lv_obj_set_align(ui_ResetDefaultsBtn, LV_ALIGN_CENTER);
    ui_modern_style_button_secondary(ui_ResetDefaultsBtn);

    ui_ResetDefaultsLabel = lv_label_create(ui_ResetDefaultsBtn);
    lv_label_set_text(ui_ResetDefaultsLabel, "🔄 Reset");
    lv_obj_set_align(ui_ResetDefaultsLabel, LV_ALIGN_CENTER);
    ui_modern_style_label_body(ui_ResetDefaultsLabel);

    ui_SaveSettingsBtn = lv_btn_create(ui_Settings_Page);
    lv_obj_set_width(ui_SaveSettingsBtn, 100);
    lv_obj_set_height(ui_SaveSettingsBtn, 35);
    lv_obj_set_x(ui_SaveSettingsBtn, 60);
    lv_obj_set_y(ui_SaveSettingsBtn, 100);
    lv_obj_set_align(ui_SaveSettingsBtn, LV_ALIGN_CENTER);
    ui_modern_style_button_primary(ui_SaveSettingsBtn);

    ui_SaveSettingsLabel = lv_label_create(ui_SaveSettingsBtn);
    lv_label_set_text(ui_SaveSettingsLabel, "💾 Save");
    lv_obj_set_align(ui_SaveSettingsLabel, LV_ALIGN_CENTER);
    ui_modern_style_label_body(ui_SaveSettingsLabel);

    // Modern Home Button
    ui_SettingsHomeBTN = lv_btn_create(ui_Settings_Page);
    lv_obj_set_width(ui_SettingsHomeBTN, 60);
    lv_obj_set_height(ui_SettingsHomeBTN, 30);
    lv_obj_set_x(ui_SettingsHomeBTN, 0);
    lv_obj_set_y(ui_SettingsHomeBTN, 125);
    lv_obj_set_align(ui_SettingsHomeBTN, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingsHomeBTN, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SettingsHomeBTN, LV_OBJ_FLAG_SCROLLABLE);
    ui_modern_style_button_icon(ui_SettingsHomeBTN);

    ui_SettingsHomeBTN1 = lv_label_create(ui_SettingsHomeBTN);
    lv_obj_set_align(ui_SettingsHomeBTN1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsHomeBTN1, "🏠 HOME");
    ui_modern_style_label_caption(ui_SettingsHomeBTN1);

    // Add event callbacks
    lv_obj_add_event_cb(ui_GreenThresholdSlider, ui_event_GreenThresholdSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_YellowThresholdSlider, ui_event_YellowThresholdSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_MaxRollAngleSlider, ui_event_MaxRollAngleSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_DefaultStageTimeSlider, ui_event_DefaultStageTimeSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_TimeIncrementSlider, ui_event_TimeIncrementSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_TimeWarningSlider, ui_event_TimeWarningSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_DefaultShotCountSlider, ui_event_DefaultShotCountSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_ResetDefaultsBtn, ui_event_ResetDefaultsBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SaveSettingsBtn, ui_event_SaveSettingsBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SettingsHomeBTN, ui_event_SettingsHomeBTN, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_RollCalibrationSlider, ui_event_RollCalibrationSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_PitchCalibrationSlider, ui_event_PitchCalibrationSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_RecoilThresholdSlider, ui_event_RecoilThresholdSlider, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_RecoilCooldownSlider, ui_event_RecoilCooldownSlider, LV_EVENT_VALUE_CHANGED, NULL);
}

void ui_Settings_Page_screen_destroy(void)
{
    if (ui_Settings_Page)
    {
        lv_obj_del(ui_Settings_Page);
    }

    // Reset all object pointers
    ui_Settings_Page = NULL;
    ui_SettingsPageLabel = NULL;
    ui_SettingsHomeBTN = NULL;
    ui_SettingsHomeBTN1 = NULL;
    ui_SettingsScrollContainer = NULL;
    ui_BubbleLevelLabel = NULL;
    ui_GreenThresholdLabel = NULL;
    ui_GreenThresholdSlider = NULL;
    ui_GreenThresholdValue = NULL;
    ui_YellowThresholdLabel = NULL;
    ui_YellowThresholdSlider = NULL;
    ui_YellowThresholdValue = NULL;
    ui_MaxRollAngleLabel = NULL;
    ui_MaxRollAngleSlider = NULL;
    ui_MaxRollAngleValue = NULL;
    ui_TimerLabel = NULL;
    ui_DefaultStageTimeLabel = NULL;
    ui_DefaultStageTimeSlider = NULL;
    ui_DefaultStageTimeValue = NULL;
    ui_TimeIncrementLabel = NULL;
    ui_TimeIncrementSlider = NULL;
    ui_TimeIncrementValue = NULL;
    ui_TimeWarningLabel = NULL;
    ui_TimeWarningSlider = NULL;
    ui_TimeWarningValue = NULL;
    ui_ShotCounterLabel = NULL;
    ui_DefaultShotCountLabel = NULL;
    ui_DefaultShotCountSlider = NULL;
    ui_DefaultShotCountValue = NULL;
    ui_ResetDefaultsBtn = NULL;
    ui_ResetDefaultsLabel = NULL;
    ui_SaveSettingsBtn = NULL;
    ui_SaveSettingsLabel = NULL;
}
