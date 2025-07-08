// Settings Page Implementation for ShootingAssistant_V2
// Allows adjustment of key parameters for testing and customization

#include "ui.h"
#include "ui_Settings_Page.h"
#include "ui_modern_theme.h"
#include <cstdio>
#include <cstring>

// Global settings instance
ui_settings_t ui_settings;

// UI Objects for Settings Page
lv_obj_t *ui_Settings_Page = nullptr;
lv_obj_t *ui_SettingsPageLabel = nullptr;
lv_obj_t *ui_SettingsHomeBTN = nullptr;
lv_obj_t *ui_SettingsHomeBTN1 = nullptr;

// Settings UI Objects
lv_obj_t *ui_SettingsScrollContainer = nullptr;

// Calibration Settings
lv_obj_t *ui_CalibrationLabel = nullptr;
lv_obj_t *ui_RollCalibrationLabel = nullptr;
lv_obj_t *ui_RollCalibrationSlider = nullptr;
lv_obj_t *ui_RollCalibrationValue = nullptr;
lv_obj_t *ui_PitchCalibrationLabel = nullptr;
lv_obj_t *ui_PitchCalibrationSlider = nullptr;
lv_obj_t *ui_PitchCalibrationValue = nullptr;

// Recoil Detection Settings
lv_obj_t *ui_RecoilLabel = nullptr;
lv_obj_t *ui_RecoilThresholdLabel = nullptr;
lv_obj_t *ui_RecoilThresholdSlider = nullptr;
lv_obj_t *ui_RecoilThresholdValue = nullptr;
lv_obj_t *ui_RecoilCooldownLabel = nullptr;
lv_obj_t *ui_RecoilCooldownSlider = nullptr;
lv_obj_t *ui_RecoilCooldownValue = nullptr;

// Bubble Level Settings
lv_obj_t *ui_BubbleLevelLabel = nullptr;
lv_obj_t *ui_GreenThresholdLabel = nullptr;
lv_obj_t *ui_GreenThresholdSlider = nullptr;
lv_obj_t *ui_GreenThresholdValue = nullptr;
lv_obj_t *ui_YellowThresholdLabel = nullptr;
lv_obj_t *ui_YellowThresholdSlider = nullptr;
lv_obj_t *ui_YellowThresholdValue = nullptr;
lv_obj_t *ui_MaxRollAngleLabel = nullptr;
lv_obj_t *ui_MaxRollAngleSlider = nullptr;
lv_obj_t *ui_MaxRollAngleValue = nullptr;

// Timer Settings
lv_obj_t *ui_TimerLabel = nullptr;
lv_obj_t *ui_DefaultStageTimeLabel = nullptr;
lv_obj_t *ui_DefaultStageTimeSlider = nullptr;
lv_obj_t *ui_DefaultStageTimeValue = nullptr;
lv_obj_t *ui_TimeIncrementLabel = nullptr;
lv_obj_t *ui_TimeIncrementSlider = nullptr;
lv_obj_t *ui_TimeIncrementValue = nullptr;
lv_obj_t *ui_TimeWarningLabel = nullptr;
// ...existing code for the rest of the file...
