// Modern UI Theme System for ShootingAssistant_V2
// Creates a premium, consumer-grade appearance

#ifndef UI_MODERN_THEME_H
#define UI_MODERN_THEME_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

    // Modern Color Palette - Dark Theme with Premium Accents
    typedef struct
    {
        // Primary Colors
        lv_color_t primary_dark;   // Deep charcoal (#1E1E1E)
        lv_color_t primary_medium; // Medium gray (#2D2D2D)
        lv_color_t primary_light;  // Light gray (#3A3A3A)

        // Accent Colors
        lv_color_t accent_orange; // Premium orange (#FF6B35)
        lv_color_t accent_blue;   // Tech blue (#0066CC)
        lv_color_t accent_green;  // Success green (#00CC66)
        lv_color_t accent_red;    // Alert red (#FF3333)
        lv_color_t accent_purple; // Settings purple (#9966CC)

        // Text Colors
        lv_color_t text_primary;   // Primary white (#FFFFFF)
        lv_color_t text_secondary; // Secondary gray (#CCCCCC)
        lv_color_t text_muted;     // Muted gray (#999999)

        // Special Colors
        lv_color_t glass_overlay; // Glass effect (#333333 with opacity)
        lv_color_t neon_glow;     // Neon glow effect (#00FFFF)
        lv_color_t warning_amber; // Warning amber (#FFAA00)
    } ui_modern_colors_t;

    // Modern Design System
    typedef struct
    {
        // Border Radius
        uint8_t radius_small;  // 4px
        uint8_t radius_medium; // 8px
        uint8_t radius_large;  // 16px
        uint8_t radius_pill;   // 25px

        // Shadows
        uint8_t shadow_small;  // 2px
        uint8_t shadow_medium; // 4px
        uint8_t shadow_large;  // 8px

        // Spacing
        uint8_t spacing_xs; // 4px
        uint8_t spacing_sm; // 8px
        uint8_t spacing_md; // 16px
        uint8_t spacing_lg; // 24px
        uint8_t spacing_xl; // 32px

        // Animation
        uint16_t anim_fast;   // 200ms
        uint16_t anim_medium; // 300ms
        uint16_t anim_slow;   // 500ms
    } ui_modern_design_t;

    // Global theme instances
    extern ui_modern_colors_t ui_modern_colors;
    extern ui_modern_design_t ui_modern_design;

    // Theme initialization
    void ui_modern_theme_init(void);

    // Modern styling functions
    void ui_modern_style_page(lv_obj_t *page);
    void ui_modern_style_button_primary(lv_obj_t *btn);
    void ui_modern_style_button_secondary(lv_obj_t *btn);
    void ui_modern_style_button_icon(lv_obj_t *btn);
    void ui_modern_style_card(lv_obj_t *card);
    void ui_modern_style_slider(lv_obj_t *slider);
    void ui_modern_style_label_title(lv_obj_t *label);
    void ui_modern_style_label_heading(lv_obj_t *label);
    void ui_modern_style_label_body(lv_obj_t *label);
    void ui_modern_style_label_caption(lv_obj_t *label);
    void ui_modern_style_container_glass(lv_obj_t *cont);
    void ui_modern_style_nav_bar(lv_obj_t *nav);

    // Advanced effects
    void ui_modern_add_glow_effect(lv_obj_t *obj, lv_color_t glow_color);
    void ui_modern_add_gradient_bg(lv_obj_t *obj, lv_color_t color1, lv_color_t color2);
    void ui_modern_add_glass_effect(lv_obj_t *obj);
    void ui_modern_add_button_hover_effect(lv_obj_t *btn);

    // Animation helpers
    void ui_modern_fade_in(lv_obj_t *obj, uint16_t duration);
    void ui_modern_slide_in(lv_obj_t *obj, lv_dir_t direction, uint16_t duration);
    void ui_modern_scale_bounce(lv_obj_t *obj);

// Icon and symbol definitions
#define UI_MODERN_SYMBOL_SETTINGS "\xEF\x80\x93"    // Gear icon
#define UI_MODERN_SYMBOL_BUBBLE "\xEF\x81\x85"      // Level icon
#define UI_MODERN_SYMBOL_CROSSHAIR "\xEF\x81\x89"   // Crosshair icon
#define UI_MODERN_SYMBOL_TIMER "\xEF\x81\x92"       // Clock icon
#define UI_MODERN_SYMBOL_COUNTER "\xEF\x81\x9C"     // Counter icon
#define UI_MODERN_SYMBOL_COMPETITION "\xEF\x82\x84" // Trophy icon
#define UI_MODERN_SYMBOL_HORIZON "\xEF\x82\x8B"     // Horizon icon
#define UI_MODERN_SYMBOL_BACK "\xEF\x81\x80"        // Back arrow
#define UI_MODERN_SYMBOL_HOME "\xEF\x80\x95"        // Home icon
#define UI_MODERN_SYMBOL_PLAY "\xEF\x81\x8B"        // Play icon
#define UI_MODERN_SYMBOL_PAUSE "\xEF\x81\x8C"       // Pause icon
#define UI_MODERN_SYMBOL_STOP "\xEF\x81\x8D"        // Stop icon
#define UI_MODERN_SYMBOL_RESET "\xEF\x82\x9A"       // Reset icon

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_MODERN_THEME_H*/
