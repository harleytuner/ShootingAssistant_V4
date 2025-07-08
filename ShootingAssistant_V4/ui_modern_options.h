// Enhanced Options Page Header - Modern UI Design
// Creates a premium, consumer-grade main menu

#ifndef UI_MODERN_OPTIONS_H
#define UI_MODERN_OPTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

    // Enhanced Options Page Objects
    extern lv_obj_t *ui_OptionsPage_Modern;

    // Initialization and cleanup
    void ui_modern_options_page_init(void);
    void ui_modern_options_page_destroy(void);

    // Event handlers
    void ui_modern_event_bubble_level(lv_event_t *e);
    void ui_modern_event_horizon(lv_event_t *e);
    void ui_modern_event_shot_counter(lv_event_t *e);
    void ui_modern_event_timer(lv_event_t *e);
    void ui_modern_event_competition(lv_event_t *e);
    void ui_modern_event_settings(lv_event_t *e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_MODERN_OPTIONS_H*/
