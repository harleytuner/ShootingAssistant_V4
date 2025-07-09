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
}

// Button styling functions
void ui_modern_style_button_primary(lv_obj_t *btn)
{
    lv_obj_set_style_bg_color(btn, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn, ui_modern_colors.accent_blue, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(btn, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, ui_modern_design.radius_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_button_secondary(lv_obj_t *btn)
{
    lv_obj_set_style_bg_color(btn, ui_modern_colors.primary_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn, ui_modern_colors.primary_light, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(btn, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, ui_modern_design.radius_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(btn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_button_icon(lv_obj_t *btn)
{
    lv_obj_set_style_bg_color(btn, ui_modern_colors.primary_light, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(btn, ui_modern_colors.text_secondary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, ui_modern_design.radius_small, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Label styling functions
void ui_modern_style_label_title(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.accent_orange, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_label_heading(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_label_body(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_primary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_label_caption(lv_obj_t *label)
{
    lv_obj_set_style_text_color(label, ui_modern_colors.text_secondary, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Additional styling functions
void ui_modern_style_card(lv_obj_t *card)
{
    lv_obj_set_style_bg_color(card, ui_modern_colors.primary_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(card, ui_modern_design.radius_large, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(card, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(card, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_slider(lv_obj_t *slider)
{
    lv_obj_set_style_bg_color(slider, ui_modern_colors.primary_light, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(slider, ui_modern_colors.accent_orange, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(slider, ui_modern_colors.accent_orange, LV_PART_KNOB | LV_STATE_DEFAULT);
}

void ui_modern_style_container_glass(lv_obj_t *cont)
{
    lv_obj_set_style_bg_color(cont, ui_modern_colors.glass_overlay, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cont, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(cont, ui_modern_design.radius_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_style_nav_bar(lv_obj_t *nav)
{
    lv_obj_set_style_bg_color(nav, ui_modern_colors.primary_medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(nav, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(nav, ui_modern_colors.text_muted, LV_PART_MAIN | LV_STATE_DEFAULT);
}

// Advanced effects (stub implementations)
void ui_modern_add_glow_effect(lv_obj_t *obj, lv_color_t glow_color)
{
    // Stub implementation - could add shadow or border effects
    lv_obj_set_style_border_color(obj, glow_color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_modern_add_gradient_bg(lv_obj_t *obj, lv_color_t color1, lv_color_t color2)
{
    lv_obj_set_style_bg_color(obj, color1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, color2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
}
