#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ui_splash_screen.h"
#ifndef UI_SPLASH_SCREEN_H
#define UI_SPLASH_SCREEN_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

// DEADEYE Color Definitions
#define DEADEYE_OLIVE_GREEN lv_color_hex(0x6B6B47)
#define DEADEYE_DARK_OLIVE lv_color_hex(0x5A5A3D)
#define DEADEYE_CROSSHAIR_BROWN lv_color_hex(0x2C2C1E)
#define DEADEYE_ACCENT_BRONZE lv_color_hex(0x8B7355)
#define DEADEYE_TEXT_CREAM lv_color_hex(0xF5F5DC)

    // Splash Screen Objects
    extern lv_obj_t *ui_SplashScreen;
    extern lv_obj_t *ui_SplashBackground;
    extern lv_obj_t *ui_CrosshairContainer;
    extern lv_obj_t *ui_CrosshairCircle;
    extern lv_obj_t *ui_CrosshairVertical;
    extern lv_obj_t *ui_CrosshairHorizontal;
    extern lv_obj_t *ui_BubbleLevelIcon;
    extern lv_obj_t *ui_BubbleBall;
    extern lv_obj_t *ui_SplashTitle;
    extern lv_obj_t *ui_SplashSubtitle;
    extern lv_obj_t *ui_SplashProgressBar;
    extern lv_obj_t *ui_SplashProgressTrack;
    extern lv_obj_t *ui_SplashVersion;

    // Function declarations
    void ui_splash_screen_init(void);
    void ui_splash_screen_destroy(void);
    void ui_splash_start_animation(void);
    void ui_splash_hide_callback(lv_timer_t *timer);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
