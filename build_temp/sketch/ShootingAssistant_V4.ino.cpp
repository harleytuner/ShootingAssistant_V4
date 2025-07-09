#include <Arduino.h>
#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ShootingAssistant_V4.ino"
// ... (keep all your existing includes and initializations) ...
#include "Display_ST7789.h"
// #include "Audio_PCM5101.h"
// #include "RTC_PCF85063.h"
#include "Gyro_QMI8658.h" // Your QMI8658 library
#include "LVGL_Driver.h"
#include "PWR_Key.h"
// #include "SD_Card.h"
// #include "LVGL_Example.h"
#include "BAT_Driver.h"
// #include "Wireless.h"
#include "ui.h" // Your main UI header from SquareLine Studio
                // This should make ui_competition_page_handle_recoil_event() available

#include <math.h> // For atan2f, sqrtf and M_PI

// Define M_PI if not already defined (some Arduino environments)
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

// --- Calibration Offsets and Recoil Parameters ---
// These values are now managed through the Settings Page UI
// The settings system is initialized in ui_init()
unsigned long last_recoil_detection_time = 0; // Timestamp of the last recoil detection

// Performance monitoring (optional)
// #define ENABLE_PERFORMANCE_MONITORING
#ifdef ENABLE_PERFORMANCE_MONITORING
unsigned long last_performance_report = 0;
unsigned long loop_count = 0;
#endif

// Forward declarations for C++ functions
float get_roll_from_sensor_impl();
float get_pitch_from_sensor_impl();
bool checkForRecoil();

// C-compatible wrapper functions for LVGL
#line 40 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ShootingAssistant_V4.ino"
 extern "C" float get_qmi8658_roll_degrees();
#line 45 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ShootingAssistant_V4.ino"
 extern "C" float get_qmi8658_pitch_degrees();
#line 54 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ShootingAssistant_V4.ino"
void setup();
#line 170 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ShootingAssistant_V4.ino"
void loop();
#line 40 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ShootingAssistant_V4.ino"
extern "C" float get_qmi8658_roll_degrees()
{
    return get_roll_from_sensor_impl();
}

extern "C" float get_qmi8658_pitch_degrees()
{
    return get_pitch_from_sensor_impl();
}

// Note: ui_competition_page_handle_recoil_event() and ui_external_decrement_shot_count()
// should be declared in your UI header files (e.g., ui_Competition_Page.h, ui_Shot_Counter_Page.h)
// and made available through ui.h.

void setup()
{

    PWR_Init();

    Serial.begin(115200);
    Serial.println("Setup: Starting system initialization...");

    I2C_Init();
    Serial.println("Setup: I2C Initialized");

    Backlight_Init();
    Serial.println("Setup: Backlight Initialized.");

    LCD_Init();
    Serial.println("Setup: LCD Initialized.");

    Lvgl_Init();
    Serial.println("Setup: LVGL Initialized.");

    QMI8658_Init();
    Serial.println("Setup: QMI8658_Init called.");

    // Validate sensor initialization
    QMI8658_sensor_update(); // Get initial sensor reading
    float test_acc_x = getAccX();
    if (test_acc_x == 0.0f && getAccY() == 0.0f && getAccZ() == 0.0f)
    {
        Serial.println("WARNING: QMI8658 sensor may not be responding correctly!");
    }
    else
    {
        Serial.println("Setup: QMI8658 sensor validated - readings detected.");
    }

    setAccScale(ACC_RANGE_4G); // Or your preferred range. Ensure this range is suitable for recoil G's.
                               // If recoil exceeds 4G, you might need ACC_RANGE_8G or higher,
                               // and adjust the recoil threshold in Settings Page accordingly.
    Serial.println("Setup: QMI8658 Accelerometer scale set.");

    ui_init();
    Serial.println("Setup: ui_init (LVGL UI) called.");

    // Validate settings system
    float roll_offset = ui_settings_get_roll_calibration_offset();
    float pitch_offset = ui_settings_get_pitch_calibration_offset();
    Serial.print("Setup: Settings initialized - Roll offset: ");
    Serial.print(roll_offset);
    Serial.print(", Pitch offset: ");
    Serial.println(pitch_offset);

    Serial.println("Setup: System initialization complete.");
    Serial.println("Setup: Calibration and recoil settings can now be adjusted in the Settings Page.");
}

// C++ function for roll calculation
float get_roll_from_sensor_impl()
{
    float acc_y = getAccY();
    float acc_x = getAccX();
    // float acc_z = getAccZ(); // Not strictly needed for this roll definition

    // User's existing roll formula
    float raw_roll_radians = atan2f(-acc_y, -acc_x);
    float raw_roll_degrees = raw_roll_radians * (180.0f / M_PI);
    float calibrated_roll_degrees = raw_roll_degrees - ui_settings_get_roll_calibration_offset();

    return calibrated_roll_degrees;
}

// C++ function for pitch calculation
float get_pitch_from_sensor_impl()
{
    float acc_x = getAccX();
    float acc_y = getAccY();
    float acc_z = getAccZ(); // Z-axis accelerometer reading

    // Pitch calculation: angle of Z-axis relative to gravity vector in XY plane
    // Assumes Z-axis of sensor points along the rifle barrel
    float xy_magnitude = sqrtf(acc_x * acc_x + acc_y * acc_y);

    // Safety check to prevent division by zero
    if (xy_magnitude < 0.001f)
    {
        xy_magnitude = 0.001f; // Minimum threshold
    }

    float raw_pitch_radians = atan2f(acc_z, xy_magnitude);
    float raw_pitch_degrees = raw_pitch_radians * (180.0f / M_PI);

    float calibrated_pitch_degrees = raw_pitch_degrees - ui_settings_get_pitch_calibration_offset();

    return calibrated_pitch_degrees;
}

// --- Recoil Detection Function ---
bool checkForRecoil()
{
    // Ensure we have fresh sensor data for recoil detection
    QMI8658_sensor_update(); // Force sensor data update

    float az = getAccZ(); // Read Z-axis acceleration

    // Debugging: Print Z acceleration to help tune the threshold
    // Comment this out for normal operation to avoid flooding serial
    // Serial.print("Current az: "); Serial.println(az);

    // Check if Z acceleration exceeds the negative threshold (using settings)
    if (az < ui_settings_get_recoil_z_threshold_negative())
    {
        // Serial.print("checkForRecoil: Recoil detected! Z-acceleration: "); Serial.println(az); // Debug
        return true;
    }
    return false;
}

void loop()
{
    QMI8658_Loop(); // Make sure this reads new sensor data if it's not automatic

#ifdef ENABLE_PERFORMANCE_MONITORING
    loop_count++;
    unsigned long perf_current_time = millis();

    // Report performance every 10 seconds
    if (perf_current_time - last_performance_report > 10000)
    {
        Serial.print("Performance: Loop frequency: ");
        Serial.print(loop_count / 10.0f);
        Serial.println(" Hz");
        loop_count = 0;
        last_performance_report = perf_current_time;
    }
#endif

    // --- Recoil Detection Logic ---
    unsigned long current_time = millis();
    if (current_time - last_recoil_detection_time > ui_settings_get_recoil_cooldown_ms())
    { // Check if cooldown has passed
        if (checkForRecoil())
        {
            Serial.println("Main.ino: Physical recoil DETECTED!");

            // Call the Competition Page's recoil handler.
            // This function internally checks if the timer is running.
            ui_competition_page_handle_recoil_event();

            // If you also want the Shot Counter Page to react to recoil when it's active,
            // you could add a check here:
            // if (lv_scr_act() == ui_Shot_Counter_Page) {
            //    ui_external_decrement_shot_count(); // This is for the Shot_Counter_Page itself
            // }
            // However, ui_competition_page_handle_recoil_event() already handles the competition scenario.
            // ui_external_decrement_shot_count() is primarily for when the Shot Counter Page is active and you want to test shots there.

            last_recoil_detection_time = current_time; // Update timestamp for cooldown
            // The printf calls inside ui_competition_page_handle_recoil_event will provide more details.
        }
    }
    // --- End of Recoil Detection Logic ---

    Lvgl_Loop(); // LVGL's main loop handler
    delay(5);    // Keep your LVGL loop responsive
}

