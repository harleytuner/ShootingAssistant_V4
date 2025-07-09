#line 1 "C:\\Users\\chadgroves\\OneDrive - Simventions, Inc\\Desktop\\ShootingAssistant_V4\\ui_modern_theme.cpp"
// Modern UI Theme System Implementation
// Creates a premium, consumer-grade appearance

#include "ui_modern_theme.h"
#include <cstring>

// Global theme instances
ui_modern_colors_t ui_modern_colors;
ui_modern_design_t ui_modern_design;

// Theme initialization
void ui_modern_theme_init(void)
{
    // Initialize DEADEYE military olive color palette
    ui_modern_colors.primary_dark = lv_color_hex(0x1A1B0F);   // Deep olive dark
    ui_modern_colors.primary_medium = lv_color_hex(0x2D2E1F); // Military olive medium
    ui_modern_colors.primary_light = lv_color_hex(0x3F4133);  // Olive light

    ui_modern_colors.accent_orange = lv_color_hex(0xD4AF37); // Military gold
    ui_modern_colors.accent_blue = lv_color_hex(0x4A5D23);   // Dark olive green
    ui_modern_colors.accent_green = lv_color_hex(0x8B7355);  // Tactical brown
    ui_modern_colors.accent_red = lv_color_hex(0x8B0000);    // Dark red
    ui_modern_colors.accent_purple = lv_color_hex(0x5D4037); // Brown accent

    ui_modern_colors.text_primary = lv_color_hex(0xE8E6E3);   // Light sand
    ui_modern_colors.text_secondary = lv_color_hex(0xCDCAAA); // Muted sand
    ui_modern_colors.text_muted = lv_color_hex(0x9C9A7A);     // Olive muted

    ui_modern_colors.glass_overlay = lv_color_hex(0x2A2B1C); // Dark olive overlay
    ui_modern_colors.neon_glow = lv_color_hex(0xD4AF37);     // Gold glow
    ui_modern_colors.warning_amber = lv_color_hex(0xDAA520); // Golden amber

    // Initialize design system
    ui_modern_design.radius_small = 4;
    ui_modern_design.radius_medium = 8;
    ui_modern_design.radius_large = 16;
    ui_modern_design.radius_pill = 25;

    ui_modern_design.shadow_small = 2;
    ui_modern_design.shadow_medium = 4;
    ui_modern_design.shadow_large = 8;

    ui_modern_design.spacing_xs = 4;
    ui_modern_design.spacing_sm = 8;
    ui_modern_design.spacing_md = 16;
    ui_modern_design.spacing_lg = 24;
    ui_modern_design.spacing_xl = 32;

    ui_modern_design.anim_fast = 200;
    ui_modern_design.anim_medium = 300;
    ui_modern_design.anim_slow = 500;
}

// Modern page styling
void ui_modern_style_page(lv_obj_t *page)
{
    // Dark gradient background
    lv_obj_set_style_bg_color(page, ui_modern_colors.primary_dark, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(page, ui_modern_colors.primary_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(page, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // ...existing code for the rest of the file...
}
